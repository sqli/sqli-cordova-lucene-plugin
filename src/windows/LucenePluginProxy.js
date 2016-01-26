var commandFile = 'command.lptf';
var commandResult = 'command.out';

module.exports = {
    searchIndex: function (successCallback, errorCallback, data) {
        var parameters = data[0];

        Windows.Storage.ApplicationData.current.localFolder.createFileAsync(commandFile, Windows.Storage.CreationCollisionOption.replaceExisting).then(function (file) {
            Windows.Storage.FileIO.writeTextAsync(file, parameters.indexFolder + "\n" + parameters.field + "\n" + parameters.token + "\n" + parameters.maxResult + "\n" + Windows.Storage.ApplicationData.current.localFolder.path + "/" + commandResult).done(function () {
                var options = new Windows.System.LauncherOptions();
                options.treatAsUntrusted = false;
                options.displayApplicationPicker = false;

                Windows.System.Launcher.launchFileAsync(file).done(function () {
                    var interval = setInterval(function () {
                        Windows.Storage.ApplicationData.current.localFolder.getFileAsync(commandResult).then(function (file) {
                            clearInterval(interval);
                            Windows.Storage.FileIO.readTextAsync(file).done(function (content) {
                                var result = JSON.parse(content);
                                if (result.errorMessage) {
                                    errorCallback(result);
                                } else {
                                    successCallback(result);
                                }
                                file.deleteAsync();
                            });
                        });
                    }, 100);
                    setTimeout(function () {
                        clearInterval(interval);
                        var error = {
                            errorMessage: 'Lucene Proxy Tool is not installed!'
                        }
                        errorCallback(error);
                    }, 10000);
                    
                }, function () {
                    var error = {
                        errorMessage: 'Lucene Proxy Tool is not installed!'
                    }
                    errorCallback(error);
                });
            });
        });
    }
};

require("cordova/exec/proxy").add("LucenePlugin", module.exports);
