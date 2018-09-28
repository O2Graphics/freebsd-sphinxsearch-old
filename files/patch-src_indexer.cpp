--- src/indexer.cpp.orig	2018-09-23 01:05:57.070000000 +0200
+++ src/indexer.cpp	2018-09-23 01:06:16.716819000 +0200
@@ -1248,7 +1248,7 @@
 			iTotalBytes += tSource.m_iTotalBytes;
 		}
 
-		fprintf ( stdout, "total "INT64_FMT" docs, "INT64_FMT" bytes\n", iTotalDocs, iTotalBytes );
+		fprintf ( stdout, "total " INT64_FMT " docs, " INT64_FMT " bytes\n", iTotalDocs, iTotalBytes );
 
 		fprintf ( stdout, "total %d.%03d sec, %d bytes/sec, %d.%02d docs/sec\n",
 			(int)(tmTime/1000000), (int)(tmTime%1000000)/1000, // sec
