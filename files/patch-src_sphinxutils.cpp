--- src/sphinxutils.cpp.orig	2018-09-23 00:36:42.687646000 +0200
+++ src/sphinxutils.cpp	2018-09-23 00:37:38.038395000 +0200
@@ -243,7 +243,7 @@
 	if ( iSize>INT_MAX )
 	{
 		iSize = INT_MAX;
-		sphWarning ( "'%s = "INT64_FMT"' clamped to %d(INT_MAX)", sKey, iSize, INT_MAX );
+		sphWarning ( "'%s = " INT64_FMT "' clamped to %d(INT_MAX)", sKey, iSize, INT_MAX );
 	}
 	return (int)iSize;
 }
@@ -1850,11 +1850,11 @@
 #endif
 
 #ifdef CONFIGURE_FLAGS
-	sphSafeInfo ( iFD, "Configured with flags: "CONFIGURE_FLAGS );
+	sphSafeInfo ( iFD, "Configured with flags: " CONFIGURE_FLAGS );
 #endif
 
 #ifdef OS_UNAME
-	sphSafeInfo ( iFD, "Host OS is "OS_UNAME );
+	sphSafeInfo ( iFD, "Host OS is " OS_UNAME );
 #endif
 
 	bool bOk = true;
