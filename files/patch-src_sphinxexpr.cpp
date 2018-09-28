--- src/sphinxexpr.cpp.orig	2018-09-23 01:05:08.245400000 +0200
+++ src/sphinxexpr.cpp	2018-09-23 01:05:30.109596000 +0200
@@ -712,7 +712,7 @@
 						for ( ; nValues; nValues-=2, pValues+=2 )
 						{
 							if ( sBuf.cstr() )
-								sBuf.SetSprintf ( "%s,"INT64_FMT, sBuf.cstr(), MVA_UPSIZE ( pValues ) );
+								sBuf.SetSprintf ( "%s," INT64_FMT, sBuf.cstr(), MVA_UPSIZE ( pValues ) );
 							else
 								sBuf.SetSprintf ( INT64_FMT, MVA_UPSIZE ( pValues ) );
 						}
