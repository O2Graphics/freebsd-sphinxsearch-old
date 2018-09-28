--- src/sphinxstd.cpp.orig	2018-09-23 00:41:40.241753000 +0200
+++ src/sphinxstd.cpp	2018-09-23 00:46:29.995342000 +0200
@@ -98,7 +98,7 @@
 {
 	BYTE * pBlock = (BYTE*) ::malloc ( iSize+sizeof(CSphMemHeader)+sizeof(DWORD) );
 	if ( !pBlock )
-		sphDie ( "out of memory (unable to allocate "UINT64_FMT" bytes)", (uint64_t)iSize ); // FIXME! this may fail with malloc error too
+		sphDie ( "out of memory (unable to allocate " UINT64_FMT " bytes)", (uint64_t)iSize ); // FIXME! this may fail with malloc error too
 
 	*(DWORD*)( pBlock+iSize+sizeof(CSphMemHeader) ) = MEMORY_MAGIC_END;
 	g_tAllocsMutex.Lock();
@@ -276,7 +276,7 @@
 
 void sphAllocsStats ()
 {
-	fprintf ( stdout, "--- total-allocs=%d, peak-allocs=%d, peak-bytes="INT64_FMT"\n",
+	fprintf ( stdout, "--- total-allocs=%d, peak-allocs=%d, peak-bytes=" INT64_FMT "\n",
 		g_iTotalAllocs, g_iPeakAllocs, g_iPeakBytes );
 }
 
@@ -425,7 +425,7 @@
 void sphAllocsStats ()
 {
 	g_tAllocsMutex.Lock ();
-	fprintf ( stdout, "--- total-allocs=%d, peak-allocs=%d, peak-bytes="INT64_FMT"\n",
+	fprintf ( stdout, "--- total-allocs=%d, peak-allocs=%d, peak-bytes=" INT64_FMT "\n",
 		g_iTotalAllocs, g_iPeakAllocs, g_iPeakBytes );
 	g_tAllocsMutex.Unlock ();
 }
@@ -633,7 +633,7 @@
 {
 	void * pResult = ::malloc ( iSize );
 	if ( !pResult )
-		sphDie ( "out of memory (unable to allocate "UINT64_FMT" bytes)", (uint64_t)iSize ); // FIXME! this may fail with malloc error too
+		sphDie ( "out of memory (unable to allocate " UINT64_FMT " bytes)", (uint64_t)iSize ); // FIXME! this may fail with malloc error too
 	return pResult;
 }
 
@@ -642,7 +642,7 @@
 {
 	void * pResult = ::malloc ( iSize );
 	if ( !pResult )
-		sphDie ( "out of memory (unable to allocate "UINT64_FMT" bytes)", (uint64_t)iSize ); // FIXME! this may fail with malloc error too
+		sphDie ( "out of memory (unable to allocate " UINT64_FMT " bytes)", (uint64_t)iSize ); // FIXME! this may fail with malloc error too
 	return pResult;
 }
 
