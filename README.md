# Phonegap Lucene Plugin
This plugin allows to search on Lucene index in Android / iOS / Windows 10 platforms (Windows 10 with limitations).

## Installation
To use this plugin in a project, you have to do:

	cordova plugin add https://github.com/sqli/sqli-cordova-lucene-plugin.git

Add your platforms targeted:

	cordova platform add android
	cordova platform add ios
	cordova platform add windows

## Usage

1- You have to initialise the Lucene Plugin by executing the init function:

	LucenePlugin.init(
		"/storage/sdcard/full_text_index",
		"documentUnitBridge", 
		10);

> First parameter is your index folder.<br/>
> Second parameter is the field searched.<br/>
> Third parameter is the max result.
 
2- You can execute a search by executing the search function:

	LucenePlugin.search(textValue, successCallback, errorCallback);

The result object is like that:

	{
		"nbHits": 2, // Total of documents
		"docs": [
			{
				"field1": "value1",
				"field2": "value2",
				...
			},
			{...
		]
	}

Example:

	function search() {
	    var textValue = document.getElementById("myText").value;
	    LucenePlugin.init("/storage/sdcard/full_text_index", "documentUnitBridge", 10);
	    LucenePlugin.search(textValue, function (result) {
	        $('#searchNb').html(result.nbHits + ' docs');
	        $('#searchResult').html('');
	        $('#searchResult').append('<ul>');
	        result.docs.forEach(function (doc) {
	            $('#searchResult').append('<li>' + doc.commonDmcId + '</li>');
	        });
	    });
	    $('#searchResult').append('</ul>');
	}

## Limitations
Under Windows 10 platform, there is no way to execute Lucene search. Indeed, all libraries that allow it are compiled for desktop platform, not for mobile platform (Windows Universal App). To do that, a specific tool has to be installed on Windows device. This tool is "[https://github.com/sqli/lucene-proxy-tool.git](https://github.com/sqli/lucene-proxy-tool.git "Lucene Proxy Tool") " developped by SQLI. This tool allows to communicate the mobile environment with desktop environment.
