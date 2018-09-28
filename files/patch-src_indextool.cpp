--- src/indextool.cpp.orig	2018-09-23 01:02:34.915419000 +0200
+++ src/indextool.cpp	2018-09-23 01:03:24.018961000 +0200
@@ -496,7 +496,7 @@
 			break;
 	}
 
-	fprintf ( stdout, INT64_FMT" documents, "INT64_FMT" words ("INT64_FMT" read, "INT64_FMT" merged, "INT64_FMT" skipped)\n",
+	fprintf ( stdout, INT64_FMT" documents, " INT64_FMT " words (" INT64_FMT " read, " INT64_FMT " merged, " INT64_FMT " skipped)\n",
 		iTotalDocuments, iTotalWords, iReadWords, iMergedWords, iSkippedWords );
 
 	// write to disk
@@ -649,7 +649,7 @@
 	ARRAY_FOREACH ( i, dFiles )
 		SafeDeleteArray ( dBuffers[i] );
 
-	fprintf ( stdout, INT64_FMT" documents, "INT64_FMT" words ("INT64_FMT" read, "INT64_FMT" merged, "INT64_FMT" skipped)\n",
+	fprintf ( stdout, INT64_FMT" documents, " INT64_FMT " words (" INT64_FMT " read, " INT64_FMT " merged, " INT64_FMT " skipped)\n",
 		iTotalDocuments, iTotalWords, iReadWords, iMergedWords, iSkippedWords );
 
 	int tmWallMsec = (int)( ( sphMicroTimer() - tmStart )/1000 );
@@ -1159,7 +1159,7 @@
 				fprintf ( stdout, "dumping dictionary for index '%s'...\n", sIndex.cstr() );
 
 			if ( bStats )
-				fprintf ( stdout, "total-documents: "INT64_FMT"\n", pIndex->GetStats().m_iTotalDocuments );
+				fprintf ( stdout, "total-documents: " INT64_FMT "\n", pIndex->GetStats().m_iTotalDocuments );
 			pIndex->DebugDumpDict ( stdout );
 			break;
 		}
