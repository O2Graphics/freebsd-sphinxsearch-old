--- src/search.cpp.orig	2018-09-23 01:03:54.532690000 +0200
+++ src/search.cpp	2018-09-23 01:04:29.990701000 +0200
@@ -354,7 +354,7 @@
 			return 1;
 		}
 
-		fprintf ( stdout, "index '%s': query '%s': returned %d matches of "INT64_FMT" total in %d.%03d sec\n",
+		fprintf ( stdout, "index '%s': query '%s': returned %d matches of " INT64_FMT " total in %d.%03d sec\n",
 			sIndexName, sQuery, pResult->m_dMatches.GetLength(), pResult->m_iTotalMatches,
 			pResult->m_iQueryTime/1000, pResult->m_iQueryTime%1000 );
 
@@ -390,7 +390,7 @@
 								for ( int k=0; k<iValues; k+=2, pValues+=2 )
 								{
 									uint64_t uMva = MVA_UPSIZE ( pValues );
-									fprintf ( stdout, k ? ","UINT64_FMT : UINT64_FMT, uMva );
+									fprintf ( stdout, k ? "," UINT64_FMT : UINT64_FMT, uMva );
 								}
 							} else
 							{
@@ -467,7 +467,7 @@
 		while ( pResult->m_hWordStats.IterateNext() )
 		{
 			const CSphQueryResultMeta::WordStat_t & tStat = pResult->m_hWordStats.IterateGet();
-			fprintf ( stdout, "%d. '%s': "INT64_FMT" documents, "INT64_FMT" hits\n",
+			fprintf ( stdout, "%d. '%s': " INT64_FMT " documents, " INT64_FMT " hits\n",
 				iWord,
 				pResult->m_hWordStats.IterateGetKey().cstr(),
 				tStat.m_iDocs,
