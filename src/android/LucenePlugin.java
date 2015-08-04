package com.sqli.phonegap.lucene;

import java.io.File;
import java.io.IOException;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;
import org.apache.cordova.PluginResult;
import org.apache.cordova.PluginResult.Status;
import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.queryParser.ParseException;
import org.apache.lucene.queryParser.QueryParser;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.store.FSDirectory;
import org.apache.lucene.util.Version;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.util.Log;
import android.widget.Toast;

public class LucenePlugin extends CordovaPlugin {
	public static final String TAG = "Lucene Plugin";

	/**
	 * Constructor.
	 */
	public LucenePlugin() {
	}

	/**
	 * Sets the context of the Command. This can then be used to do things like
	 * get file paths associated with the Activity.
	 *
	 * @param cordova
	 *            The context of the main Activity.
	 * @param webView
	 *            The CordovaWebView Cordova is running in.
	 */
	public void initialize(CordovaInterface cordova, CordovaWebView webView) {
		super.initialize(cordova, webView);
		Log.v(TAG, "Initialisation LucenePlugin");
	}

	public boolean execute(final String action, JSONArray args,
			CallbackContext callbackContext) throws JSONException {
		final int duration = Toast.LENGTH_SHORT;
		// Shows a toast
		Log.v(TAG, "LucenePlugin action received:" + action);

		final String token = args.getJSONObject(0).getString("token");
		final String indexFolder = args.getJSONObject(0).getString(
				"indexFolder");
		final String field = args.getJSONObject(0).getString("field");
		
		final int maxResult = args.getJSONObject(0).getInt("maxResult");

		if ("searchIndex".equals(action)) {
			try {
				callbackContext.success(searchIndex(token, indexFolder, field, maxResult));
			} catch (IOException e) {
				callbackContext.error(e.getMessage());
				return false;
			} catch (ParseException e) {
				callbackContext.error(e.getMessage());
				return false;
			}
		}

		return true;
	}

	public JSONObject searchIndex(String searchString, String indexFolder,
			String field, int maxResult) throws IOException, ParseException,
			JSONException {

		JSONObject objRes = new JSONObject();

		IndexReader indexReader = IndexReader.open(
				FSDirectory.open(new File(indexFolder)), true);

		IndexSearcher indexSearcher = new IndexSearcher(indexReader);

		Analyzer analyzer = new StandardAnalyzer(Version.LUCENE_CURRENT);
		QueryParser queryParser = new QueryParser(Version.LUCENE_CURRENT,
				field, analyzer);
		Query query = queryParser.parse(searchString);
		TopDocs results = indexSearcher.search(query, maxResult);
		Log.v(TAG, "Number of hits: " + results.totalHits);

		objRes.put("nbHits", results.totalHits);

		JSONArray docs = new JSONArray();
		for (int i = 0; i < results.scoreDocs.length; i++) {
			Document doc = indexSearcher.doc(results.scoreDocs[i].doc);
			JSONObject docsObj = new JSONObject();
			for (Object fieldObj : doc.getFields()) {
				String fieldName = ((Field) fieldObj).name();
				Log.v(TAG, "fieldName: " + fieldName);
				docsObj.put(fieldName, doc.get(fieldName));
			}
			docs.put(docsObj);
		}
		indexSearcher.close();

		objRes.put("docs", docs);
		return objRes;
	}

}