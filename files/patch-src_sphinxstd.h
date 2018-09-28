--- src/sphinxstd.h.orig	2018-09-22 22:02:32.321348000 +0200
+++ src/sphinxstd.h	2018-09-22 22:38:57.328275000 +0200
@@ -264,7 +264,7 @@
 	// MIT HACKMEM count
 	// works for 32-bit numbers only
 	// fix last line for 64-bit numbers
-	register DWORD tmp;
+	DWORD tmp;
 	tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
 	return ( (tmp + (tmp >> 3) ) & 030707070707) % 63;
 }
@@ -2188,10 +2188,10 @@
 		if ( m_pData==MAP_FAILED )
 		{
 			if ( m_iLength>0x7fffffffUL )
-				sError.SetSprintf ( "mmap() failed: %s (length="INT64_FMT" is over 2GB, impossible on some 32-bit systems)",
+				sError.SetSprintf ( "mmap() failed: %s (length=" INT64_FMT " is over 2GB, impossible on some 32-bit systems)",
 					strerror(errno), (int64_t)m_iLength );
 			else
-				sError.SetSprintf ( "mmap() failed: %s (length="INT64_FMT")", strerror(errno), (int64_t)m_iLength );
+				sError.SetSprintf ( "mmap() failed: %s (length=" INT64_FMT ")", strerror(errno), (int64_t)m_iLength );
 			m_iLength = 0;
 			return false;
 		}
@@ -2228,9 +2228,9 @@
 			return true;
 
 		if ( sError.IsEmpty() )
-			sError.SetSprintf ( "%s mlock() failed: bytes="INT64_FMT", error=%s", sPrefix, (int64_t)m_iLength, strerror(errno) );
+			sError.SetSprintf ( "%s mlock() failed: bytes=" INT64_FMT ", error=%s", sPrefix, (int64_t)m_iLength, strerror(errno) );
 		else
-			sError.SetSprintf ( "%s; %s mlock() failed: bytes="INT64_FMT", error=%s", sError.cstr(), sPrefix, (int64_t)m_iLength, strerror(errno) );
+			sError.SetSprintf ( "%s; %s mlock() failed: bytes=" INT64_FMT ", error=%s", sError.cstr(), sPrefix, (int64_t)m_iLength, strerror(errno) );
 		return false;
 	}
 #endif
