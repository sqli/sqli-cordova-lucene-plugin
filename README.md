# Phonegap Lucene Plugin
This plugin allows to search on Lucene index in Android / iOS platforms (Windows 10 is in roadmap).

## Installation
To use this plugin in a project, you have to do:

	cordova plugin add git@gitlab-toulouse.sqli.com:ah-techpub/phonegap-lucene-plugin.git

Add your platforms targeted:

	cordova platform add android
	cordova platform add ios

## Usage

1- You have to load the plugin in your index.html file:

	<script type="text/javascript" src="lucene.js"></script>

2- You have to initialise the Lucene Plugin by executing the init function:

	LucenePlugin.init(
		"/storage/sdcard/full_text_index",
		"documentUnitBridge", 
		10);

> First parameter is your index folder.<br/>
> Second parameter is the field searched.<br/>
> Third parameter is the max result.
 
3- You can execute a search by executing the search function:

	LucenePlugin.search(textValue, successCallback);

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

