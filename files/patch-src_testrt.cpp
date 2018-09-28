--- src/testrt.cpp.orig	2018-09-23 01:01:32.913380000 +0200
+++ src/testrt.cpp	2018-09-23 01:01:59.152669000 +0200
@@ -240,11 +240,11 @@
 	int64_t tmShutdown = sphMicroTimer();
 
 #if SPH_ALLOCS_PROFILER
-	printf ( "pre-shutdown allocs=%d, bytes="INT64_FMT"\n", sphAllocsCount(), sphAllocBytes() );
+	printf ( "pre-shutdown allocs=%d, bytes=" INT64_FMT "\n", sphAllocsCount(), sphAllocBytes() );
 #endif
 	SafeDelete ( pIndex );
 #if SPH_ALLOCS_PROFILER
-	printf ( "post-shutdown allocs=%d, bytes="INT64_FMT"\n", sphAllocsCount(), sphAllocBytes() );
+	printf ( "post-shutdown allocs=%d, bytes=" INT64_FMT "\n", sphAllocsCount(), sphAllocBytes() );
 #endif
 
 	int64_t tmEnd = sphMicroTimer();
