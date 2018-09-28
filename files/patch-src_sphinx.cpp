--- src/sphinx.cpp.orig	2018-09-22 22:06:05.195491000 +0200
+++ src/sphinx.cpp	2018-09-23 00:33:24.485461000 +0200
@@ -462,7 +462,7 @@
 	}
 	if ( st.st_size<iMinSize )
 	{
-		sError.SetSprintf ( "failed to load %s: bad size "INT64_FMT" (at least "INT64_FMT" bytes expected)",
+		sError.SetSprintf ( "failed to load %s: bad size " INT64_FMT " (at least " INT64_FMT " bytes expected)",
 			GetFilename(), (int64_t)st.st_size, (int64_t)iMinSize );
 		return -1;
 	}
@@ -471,7 +471,7 @@
 		size_t sCheck = (size_t)st.st_size;
 		if ( st.st_size!=SphOffset_t(sCheck) )
 		{
-			sError.SetSprintf ( "failed to load %s: bad size "INT64_FMT" (out of size_t; 4 GB limit on 32-bit machine hit?)",
+			sError.SetSprintf ( "failed to load %s: bad size " INT64_FMT " (out of size_t; 4 GB limit on 32-bit machine hit?)",
 				GetFilename(), (int64_t)st.st_size );
 			return -1;
 		}
@@ -512,7 +512,7 @@
 
 	if ( iToRead!=0 )
 	{
-		sError.SetSprintf ( "read error in %s; "INT64_FMT" of "INT64_FMT" bytes read",
+		sError.SetSprintf ( "read error in %s; " INT64_FMT " of " INT64_FMT " bytes read",
 			GetFilename(), iCount-iToRead, iCount );
 		return false;
 	}
@@ -6914,7 +6914,7 @@
 	{
 		m_iBuffUsed = m_iBuffPos = 0;
 		m_bError = true;
-		m_sError.SetSprintf ( "pread error in %s: pos="INT64_FMT", len=%d, code=%d, msg=%s",
+		m_sError.SetSprintf ( "pread error in %s: pos=" INT64_FMT ", len=%d, code=%d, msg=%s",
 			m_sFilename.cstr(), (int64_t)iNewPos, iReadLen, errno, strerror(errno) );
 		if ( m_pProfile )
 			m_pProfile->Switch ( eOld );
@@ -7065,8 +7065,8 @@
 #if PARANOID
 
 #define SPH_VARINT_DECODE(_type,_getexpr) \
-	register DWORD b = 0; \
-	register _type v = 0; \
+	DWORD b = 0; \
+	_type v = 0; \
 	int it = 0; \
 	do { b = _getexpr; v = ( v<<7 ) + ( b&0x7f ); it++; } while ( b&0x80 ); \
 	assert ( (it-1)*7<=sizeof(_type)*8 ); \
@@ -7075,8 +7075,8 @@
 #else
 
 #define SPH_VARINT_DECODE(_type,_getexpr) \
-	register DWORD b = _getexpr; \
-	register _type res = 0; \
+	DWORD b = _getexpr; \
+	_type res = 0; \
 	while ( b & 0x80 ) \
 	{ \
 		res = ( res<<7 ) + ( b & 0x7f ); \
@@ -7442,8 +7442,8 @@
 
 DWORD CSphBin::UnzipInt ()
 {
-	register int b = 0;
-	register DWORD v = 0;
+	int b = 0;
+	DWORD v = 0;
 	do
 	{
 		b = ReadByte();
@@ -7456,8 +7456,8 @@
 
 SphOffset_t CSphBin::UnzipOffset ()
 {
-	register int b = 0;
-	register SphOffset_t v = 0;
+	int b = 0;
+	SphOffset_t v = 0;
 	do
 	{
 		b = ReadByte();
@@ -7496,7 +7496,7 @@
 						// FIXME?! move this under PARANOID or something?
 						// or just introduce an assert() checked release build?
 						if ( uDelta>=sizeof(m_sKeyword) )
-							sphDie ( "INTERNAL ERROR: corrupted keyword length (len="UINT64_FMT", deltapos="UINT64_FMT")",
+							sphDie ( "INTERNAL ERROR: corrupted keyword length (len=" UINT64_FMT ", deltapos=" UINT64_FMT ")",
 								(uint64_t)uDelta, (uint64_t)(m_iFilePos-m_iLeft) );
 #else
 						assert ( uDelta>0 && uDelta<sizeof(m_sKeyword)-1 );
@@ -9836,8 +9836,8 @@
 
 inline int encodeVLB ( BYTE * buf, DWORD v )
 {
-	register BYTE b;
-	register int n = 0;
+	BYTE b;
+	int n = 0;
 
 	do
 	{
@@ -9854,8 +9854,8 @@
 
 inline int encodeVLB8 ( BYTE * buf, uint64_t v )
 {
-	register BYTE b;
-	register int n = 0;
+	BYTE b;
+	int n = 0;
 
 	do {
 		b = (BYTE)(v & 0x7f);
@@ -11988,7 +11988,7 @@
 
 	if ( m_tStats.m_iTotalDocuments>=INT_MAX )
 	{
-		m_sLastError.SetSprintf ( "index over %d documents not supported (got documents count="INT64_FMT")", INT_MAX, m_tStats.m_iTotalDocuments );
+		m_sLastError.SetSprintf ( "index over %d documents not supported (got documents count=" INT64_FMT ")", INT_MAX, m_tStats.m_iTotalDocuments );
 		return 0;
 	}
 
@@ -12259,7 +12259,7 @@
 		int64_t iMinMaxSize = tMinMax.GetExpectedSize ( m_tStats.m_iTotalDocuments );
 		if ( iMinMaxSize>INT_MAX || m_tStats.m_iTotalDocuments>INT_MAX )
 		{
-			m_sLastError.SetSprintf ( "attribute files (.spa) over 128 GB are not supported (min-max approximate="INT64_FMT", documents count="INT64_FMT")",
+			m_sLastError.SetSprintf ( "attribute files (.spa) over 128 GB are not supported (min-max approximate=" INT64_FMT ", documents count=" INT64_FMT ")",
 				iMinMaxSize, m_tStats.m_iTotalDocuments );
 			return 0;
 		}
@@ -12279,7 +12279,7 @@
 
 			if ( DOCINFO2ID ( pEntry )<uLastId )
 			{
-				m_sLastError.SetSprintf ( "descending document prev id="DOCID_FMT", curr="DOCID_FMT" bin=%d", uLastId, DOCINFO2ID ( pEntry ), iBin );
+				m_sLastError.SetSprintf ( "descending document prev id=" DOCID_FMT ", curr=" DOCID_FMT " bin=%d", uLastId, DOCINFO2ID ( pEntry ), iBin );
 				return 0;
 			}
 
@@ -12288,7 +12288,7 @@
 			{
 				// dupe, report it
 				if ( m_tSettings.m_bVerbose && uLastDupe!=uLastId )
-					sphWarn ( "duplicated document id="DOCID_FMT, uLastId );
+					sphWarn ( "duplicated document id=" DOCID_FMT, uLastId );
 
 				uLastDupe = uLastId;
 				iDupes++;
@@ -12720,7 +12720,7 @@
 			size_t iRead = sphReadThrottled ( tSrcFile.GetFD(), dData.Begin(), iSize, pThrottle );
 			if ( iRead!=iSize )
 			{
-				sErrStr.SetSprintf ( "read error in %s; "INT64_FMT" of %d bytes read", sSrc, (int64_t)iRead, iSize );
+				sErrStr.SetSprintf ( "read error in %s; " INT64_FMT " of %d bytes read", sSrc, (int64_t)iRead, iSize );
 				break;
 			}
 
@@ -13004,7 +13004,7 @@
 	if ( iDocs<INT_MAX )
 		return true;
 
-	sError.SetSprintf ( "index over %d documents not supported (got "INT64_FMT" documents)", INT_MAX, iDocs );
+	sError.SetSprintf ( "index over %d documents not supported (got " INT64_FMT " documents)", INT_MAX, iDocs );
 	return false;
 }
 
@@ -13493,7 +13493,7 @@
 		int64_t iMinMaxSize = tMinMax.GetExpectedSize ( iExpectedDocs );
 		if ( iMinMaxSize>INT_MAX || iExpectedDocs>INT_MAX )
 		{
-			sError.SetSprintf ( "attribute files (.spa) over 128 GB are not supported (min-max approximate="INT64_FMT", documents count="INT64_FMT")",
+			sError.SetSprintf ( "attribute files (.spa) over 128 GB are not supported (min-max approximate=" INT64_FMT ", documents count=" INT64_FMT ")",
 				iMinMaxSize, iExpectedDocs );
 			return false;
 		}
@@ -15190,8 +15190,8 @@
 	}
 
 	// skipped min doc, wordlist checkpoints
-	fprintf ( fp, "total-documents: "INT64_FMT"\n", m_tStats.m_iTotalDocuments );
-	fprintf ( fp, "total-bytes: "INT64_FMT"\n", int64_t(m_tStats.m_iTotalBytes) );
+	fprintf ( fp, "total-documents: " INT64_FMT "\n", m_tStats.m_iTotalDocuments );
+	fprintf ( fp, "total-bytes: " INT64_FMT "\n", int64_t(m_tStats.m_iTotalBytes) );
 
 	fprintf ( fp, "min-prefix-len: %d\n", m_tSettings.m_iMinPrefixLen );
 	fprintf ( fp, "min-infix-len: %d\n", m_tSettings.m_iMinInfixLen );
@@ -15228,7 +15228,7 @@
 	}
 
 	fprintf ( fp, "killlist-size: %d\n", m_iKillListSize );
-	fprintf ( fp, "min-max-index: "UINT64_FMT"\n", m_uMinMaxIndex );
+	fprintf ( fp, "min-max-index: " UINT64_FMT "\n", m_uMinMaxIndex );
 
 	if ( m_pFieldFilter )
 	{
@@ -15257,10 +15257,10 @@
 	const int64_t iDocinfoSize = iRowStride*m_iDocinfo*sizeof(DWORD);
 	const int64_t iMinmaxSize = iNumMinMaxRow*sizeof(CSphRowitem);
 
-	fprintf ( fp, "docinfo-bytes: docinfo="INT64_FMT", min-max="INT64_FMT", total="UINT64_FMT"\n"
+	fprintf ( fp, "docinfo-bytes: docinfo=" INT64_FMT ", min-max=" INT64_FMT ", total=" UINT64_FMT "\n"
 		, iDocinfoSize, iMinmaxSize, (uint64_t)m_pDocinfo.GetLength() );
 	fprintf ( fp, "docinfo-stride: %d\n", (int)(iRowStride*sizeof(DWORD)) );
-	fprintf ( fp, "docinfo-rows: "INT64_FMT"\n", iNumRows );
+	fprintf ( fp, "docinfo-rows: " INT64_FMT "\n", iNumRows );
 
 	if ( !m_pDocinfo.GetNumEntries() )
 		return;
@@ -15268,7 +15268,7 @@
 	DWORD * pDocinfo = m_pDocinfo.GetWritePtr();
 	for ( int64_t iRow=0; iRow<iNumRows; iRow++, pDocinfo+=iRowStride )
 		printf ( INT64_FMT". id=" DOCID_FMT "\n", iRow+1, DOCINFO2ID ( pDocinfo ) );
-	printf ( "--- min-max="INT64_FMT" ---\n", iNumMinMaxRow );
+	printf ( "--- min-max=" INT64_FMT " ---\n", iNumMinMaxRow );
 	for ( int64_t iRow=0; iRow<(m_iDocinfoIndex+1)*2; iRow++, pDocinfo+=iRowStride )
 		printf ( "id=" DOCID_FMT "\n", DOCINFO2ID ( pDocinfo ) );
 }
@@ -15300,7 +15300,7 @@
 		if ( !uWordID )
 			sphDie ( "keyword=%s, tok=%s, no wordid (stopped?)", sKeyword, sTok );
 
-		fprintf ( fp, "keyword=%s, tok=%s, wordid="UINT64_FMT"\n", sKeyword, sTok, uint64_t(uWordID) );
+		fprintf ( fp, "keyword=%s, tok=%s, wordid=" UINT64_FMT "\n", sKeyword, sTok, uint64_t(uWordID) );
 
 	} else
 	{
@@ -15308,7 +15308,7 @@
 		if ( !uWordID )
 			sphDie ( "failed to convert keyword=%s to id (must be integer)", sKeyword );
 
-		fprintf ( fp, "wordid="UINT64_FMT"\n", uint64_t(uWordID) );
+		fprintf ( fp, "wordid=" UINT64_FMT "\n", uint64_t(uWordID) );
 	}
 
 	// open files
@@ -15354,14 +15354,14 @@
 		if ( tKeyword.m_bHasHitlist )
 			for ( Hitpos_t uHit = tKeyword.GetNextHit(); uHit!=EMPTY_HIT; uHit = tKeyword.GetNextHit() )
 			{
-				fprintf ( fp, "doc="DOCID_FMT", hit=0x%08x\n", tKeyword.m_tDoc.m_iDocID, uHit ); // FIXME?
+				fprintf ( fp, "doc=" DOCID_FMT ", hit=0x%08x\n", tKeyword.m_tDoc.m_iDocID, uHit ); // FIXME?
 				iHits++;
 			}
 
 		if ( !iHits )
 		{
 			uint64_t uOff = tKeyword.m_iHitlistPos;
-			fprintf ( fp, "doc="DOCID_FMT", NO HITS, inline=%d, off="UINT64_FMT"\n",
+			fprintf ( fp, "doc=" DOCID_FMT ", NO HITS, inline=%d, off=" UINT64_FMT "\n",
 				tKeyword.m_tDoc.m_iDocID, (int)(uOff>>63), (uOff<<1)>>1 );
 		}
 	}
@@ -15473,7 +15473,7 @@
 		m_bIsEmpty = ( m_tWordlist.m_iSize<=1 );
 
 	if ( ( m_tWordlist.m_iSize<=1 )!=( m_tWordlist.m_dCheckpoints.GetLength()==0 ) )
-		sphWarning ( "wordlist size mismatch (size="INT64_FMT", checkpoints=%d)", m_tWordlist.m_iSize, m_tWordlist.m_dCheckpoints.GetLength() );
+		sphWarning ( "wordlist size mismatch (size=" INT64_FMT ", checkpoints=%d)", m_tWordlist.m_iSize, m_tWordlist.m_dCheckpoints.GetLength() );
 
 	// make sure checkpoints are loadable
 	// pre-11 indices use different offset type (this is fixed up later during the loading)
@@ -15550,7 +15550,7 @@
 			if ( iDocinfoSize < iRealDocinfoSize )
 			{
 				m_sLastError.SetSprintf ( "precomputed chunk size check mismatch" );
-				sphLogDebug ( "precomputed chunk size check mismatch (size="INT64_FMT", real="INT64_FMT", min-max="INT64_FMT", count="INT64_FMT")",
+				sphLogDebug ( "precomputed chunk size check mismatch (size=" INT64_FMT ", real=" INT64_FMT ", min-max=" INT64_FMT ", count=" INT64_FMT ")",
 					iDocinfoSize, iRealDocinfoSize, m_uMinMaxIndex, m_iDocinfo );
 				return false;
 			}
@@ -17941,7 +17941,7 @@
 			rdDict.UnzipOffset();
 
 			if ( ( iWordsTotal%iWordPerCP )!=0 && rdDict.GetPos()!=iWordsEnd )
-				LOC_FAIL(( fp, "unexpected checkpoint (pos="INT64_FMT", word=%d, words=%d, expected=%d)",
+				LOC_FAIL(( fp, "unexpected checkpoint (pos=" INT64_FMT ", word=%d, words=%d, expected=%d)",
 					iDictPos, iWordsTotal, ( iWordsTotal%iWordPerCP ), iWordPerCP ));
 
 			uWordid = 0;
@@ -17973,7 +17973,7 @@
 			const int iLastWordLen = strlen(sLastWord);
 			if ( iMatch+iDelta>=(int)sizeof(sLastWord)-1 || iMatch>iLastWordLen )
 			{
-				LOC_FAIL(( fp, "wrong word-delta (pos="INT64_FMT", word=%s, len=%d, begin=%d, delta=%d)",
+				LOC_FAIL(( fp, "wrong word-delta (pos=" INT64_FMT ", word=%s, len=%d, begin=%d, delta=%d)",
 					iDictPos, sLastWord, iLastWordLen, iMatch, iDelta ));
 				rdDict.SkipBytes ( iDelta );
 			} else
@@ -17997,20 +17997,20 @@
 			const int iNewWordLen = strlen(sWord);
 
 			if ( iNewWordLen==0 )
-				LOC_FAIL(( fp, "empty word in dictionary (pos="INT64_FMT")",
+				LOC_FAIL(( fp, "empty word in dictionary (pos=" INT64_FMT ")",
 					iDictPos ));
 
 			if ( iLastWordLen && iNewWordLen )
 				if ( sphDictCmpStrictly ( sWord, iNewWordLen, sLastWord, iLastWordLen )<=0 )
-					LOC_FAIL(( fp, "word order decreased (pos="INT64_FMT", word=%s, prev=%s)",
+					LOC_FAIL(( fp, "word order decreased (pos=" INT64_FMT ", word=%s, prev=%s)",
 						iDictPos, sLastWord, sWord ));
 
 			if ( iHint<0 )
-				LOC_FAIL(( fp, "invalid word hint (pos="INT64_FMT", word=%s, hint=%d)",
+				LOC_FAIL(( fp, "invalid word hint (pos=" INT64_FMT ", word=%s, hint=%d)",
 					iDictPos, sWord, iHint ));
 
 			if ( iDocs<=0 || iHits<=0 || iHits<iDocs )
-				LOC_FAIL(( fp, "invalid docs/hits (pos="INT64_FMT", word=%s, docs="INT64_FMT", hits="INT64_FMT")",
+				LOC_FAIL(( fp, "invalid docs/hits (pos=" INT64_FMT ", word=%s, docs=" INT64_FMT ", hits=" INT64_FMT ")",
 					(int64_t)iDictPos, sWord, (int64_t)iDocs, (int64_t)iHits ));
 
 			memcpy ( sLastWord, sWord, sizeof(sLastWord) );
@@ -18026,15 +18026,15 @@
 				iDocs = ( iDocs & HITLESS_DOC_MASK );
 
 			if ( uNewWordid<=uWordid )
-				LOC_FAIL(( fp, "wordid decreased (pos="INT64_FMT", wordid="UINT64_FMT", previd="UINT64_FMT")",
+				LOC_FAIL(( fp, "wordid decreased (pos=" INT64_FMT ", wordid=" UINT64_FMT ", previd=" UINT64_FMT ")",
 					(int64_t)iDictPos, (uint64_t)uNewWordid, (uint64_t)uWordid ));
 
 			if ( iNewDoclistOffset<=iDoclistOffset )
-				LOC_FAIL(( fp, "doclist offset decreased (pos="INT64_FMT", wordid="UINT64_FMT")",
+				LOC_FAIL(( fp, "doclist offset decreased (pos=" INT64_FMT ", wordid=" UINT64_FMT ")",
 					(int64_t)iDictPos, (uint64_t)uNewWordid ));
 
 			if ( iDocs<=0 || iHits<=0 || iHits<iDocs )
-				LOC_FAIL(( fp, "invalid docs/hits (pos="INT64_FMT", wordid="UINT64_FMT", docs="INT64_FMT", hits="INT64_FMT", hitless=%s)",
+				LOC_FAIL(( fp, "invalid docs/hits (pos=" INT64_FMT ", wordid=" UINT64_FMT ", docs=" INT64_FMT ", hits=" INT64_FMT ", hitless=%s)",
 					(int64_t)iDictPos, (uint64_t)uNewWordid, (int64_t)iDocs, (int64_t)iHits, ( bHitless?"true":"false" ) ));
 		}
 
@@ -18079,7 +18079,7 @@
 
 				if ( !dInfix2CP.BinarySearch ( dCheckpoints.GetLength() ) )
 				{
-					LOC_FAIL(( fp, "infix not found for word '%s' (%d), checkpoint %d, readpos="INT64_FMT,
+					LOC_FAIL(( fp, "infix not found for word '%s' (%d), checkpoint %d, readpos=" INT64_FMT,
 						sWord, iWordsTotal, dCheckpoints.GetLength(), (int64_t)iDictPos ));
 				}
 			}
@@ -18102,7 +18102,7 @@
 		const int iLen = bWordDict ? strlen ( tCP.m_sWord ) : 0;
 		if ( bWordDict && ( strlen ( tRefCP.m_sWord )==0 || strlen ( tCP.m_sWord )==0 ) )
 		{
-			LOC_FAIL(( fp, "empty checkpoint %d (read_word=%s, read_len=%u, readpos="INT64_FMT", calc_word=%s, calc_len=%u, calcpos="INT64_FMT")",
+			LOC_FAIL(( fp, "empty checkpoint %d (read_word=%s, read_len=%u, readpos=" INT64_FMT ", calc_word=%s, calc_len=%u, calcpos=" INT64_FMT ")",
 				i, tCP.m_sWord, (DWORD)strlen ( tCP.m_sWord ), (int64_t)tCP.m_iWordlistOffset,
 					tRefCP.m_sWord, (DWORD)strlen ( tRefCP.m_sWord ), (int64_t)tRefCP.m_iWordlistOffset ));
 
@@ -18111,7 +18111,7 @@
 		{
 			if ( bWordDict )
 			{
-				LOC_FAIL(( fp, "checkpoint %d differs (read_word=%s, readpos="INT64_FMT", calc_word=%s, calcpos="INT64_FMT")",
+				LOC_FAIL(( fp, "checkpoint %d differs (read_word=%s, readpos=" INT64_FMT ", calc_word=%s, calcpos=" INT64_FMT ")",
 					i,
 					tCP.m_sWord,
 					(int64_t)tCP.m_iWordlistOffset,
@@ -18119,7 +18119,7 @@
 					(int64_t)tRefCP.m_iWordlistOffset ));
 			} else
 			{
-				LOC_FAIL(( fp, "checkpoint %d differs (readid="UINT64_FMT", readpos="INT64_FMT", calcid="UINT64_FMT", calcpos="INT64_FMT")",
+				LOC_FAIL(( fp, "checkpoint %d differs (readid=" UINT64_FMT ", readpos=" INT64_FMT ", calcid=" UINT64_FMT ", calcpos=" INT64_FMT ")",
 					i,
 					(uint64_t)tCP.m_iWordID,
 					(int64_t)tCP.m_iWordlistOffset,
@@ -18222,12 +18222,12 @@
 		if ( iDoclistOffset!=rdDocs.GetPos() )
 		{
 			if ( !bWordDict )
-				LOC_FAIL(( fp, "unexpected doclist offset (wordid="UINT64_FMT"(%s)(%d), dictpos="INT64_FMT", doclistpos="INT64_FMT")",
+				LOC_FAIL(( fp, "unexpected doclist offset (wordid=" UINT64_FMT "(%s)(%d), dictpos=" INT64_FMT ", doclistpos=" INT64_FMT ")",
 					(uint64_t)uWordid, sWord, iWordsChecked, iDoclistOffset, (int64_t)rdDocs.GetPos() ));
 
 			if ( iDoclistOffset>=iDocsSize || iDoclistOffset<0 )
 			{
-				LOC_FAIL(( fp, "unexpected doclist offset, off the file (wordid="UINT64_FMT"(%s)(%d), dictpos="INT64_FMT", doclistsize="INT64_FMT")",
+				LOC_FAIL(( fp, "unexpected doclist offset, off the file (wordid=" UINT64_FMT "(%s)(%d), dictpos=" INT64_FMT ", doclistsize=" INT64_FMT ")",
 					(uint64_t)uWordid, sWord, iWordsChecked, iDoclistOffset, iDocsSize ));
 				iWordsChecked++;
 				continue;
@@ -18294,17 +18294,17 @@
 			{
 				const CSphRowitem * pFound = FindDocinfo ( tDoc.m_iDocID );
 				if ( !pFound )
-					LOC_FAIL(( fp, "row not found (wordid="UINT64_FMT"(%s), docid="DOCID_FMT")",
+					LOC_FAIL(( fp, "row not found (wordid=" UINT64_FMT "(%s), docid=" DOCID_FMT ")",
 						uint64_t(uWordid), sWord, tDoc.m_iDocID ));
 
 				if ( pFound )
 					if ( tDoc.m_iDocID!=DOCINFO2ID(pFound) )
-						LOC_FAIL(( fp, "row found but id mismatches (wordid="UINT64_FMT"(%s), docid="DOCID_FMT", found="DOCID_FMT")",
+						LOC_FAIL(( fp, "row found but id mismatches (wordid=" UINT64_FMT "(%s), docid=" DOCID_FMT ", found=" DOCID_FMT ")",
 							uint64_t(uWordid), sWord, tDoc.m_iDocID, DOCINFO2ID(pFound) ));
 			}
 
 			if ( tDoc.m_iDocID<=uLastDocid )
-				LOC_FAIL(( fp, "docid decreased (wordid="UINT64_FMT"(%s), docid="DOCID_FMT", lastid="DOCID_FMT")",
+				LOC_FAIL(( fp, "docid decreased (wordid=" UINT64_FMT "(%s), docid=" DOCID_FMT ", lastid=" DOCID_FMT ")",
 					uint64_t(uWordid), sWord, tDoc.m_iDocID, uLastDocid ));
 
 			uLastDocid = tDoc.m_iDocID;
@@ -18315,7 +18315,7 @@
 			if (!( pQword->m_iHitlistPos>>63 ))
 			{
 				if ( !bWordDict && pQword->m_iHitlistPos!=pQword->m_rdHitlist.GetPos() )
-					LOC_FAIL(( fp, "unexpected hitlist offset (wordid="UINT64_FMT"(%s), docid="DOCID_FMT", expected="INT64_FMT", actual="INT64_FMT")",
+					LOC_FAIL(( fp, "unexpected hitlist offset (wordid=" UINT64_FMT "(%s), docid=" DOCID_FMT ", expected=" INT64_FMT ", actual=" INT64_FMT ")",
 						(uint64_t)uWordid, sWord, pQword->m_tDoc.m_iDocID,
 						(int64_t)pQword->m_iHitlistPos, (int64_t)pQword->m_rdHitlist.GetPos() ));
 			}
@@ -18336,19 +18336,19 @@
 					break;
 
 				if (!( uLastHit<uHit ))
-					LOC_FAIL(( fp, "hit decreased (wordid="UINT64_FMT"(%s), docid="DOCID_FMT", hit=%u, last=%u)",
+					LOC_FAIL(( fp, "hit decreased (wordid=" UINT64_FMT "(%s), docid=" DOCID_FMT ", hit=%u, last=%u)",
 						(uint64_t)uWordid, sWord, pQword->m_tDoc.m_iDocID, uHit, uLastHit ));
 				uLastHit = uHit;
 
 				int iField = HITMAN::GetField ( uHit );
 				if ( iField<0 || iField>=SPH_MAX_FIELDS )
 				{
-					LOC_FAIL(( fp, "hit field out of bounds (wordid="UINT64_FMT"(%s), docid="DOCID_FMT", field=%d)",
+					LOC_FAIL(( fp, "hit field out of bounds (wordid=" UINT64_FMT "(%s), docid=" DOCID_FMT ", field=%d)",
 						(uint64_t)uWordid, sWord, pQword->m_tDoc.m_iDocID, iField ));
 
 				} else if ( iField>=m_tSchema.m_dFields.GetLength() )
 				{
-					LOC_FAIL(( fp, "hit field out of schema (wordid="UINT64_FMT"(%s), docid="DOCID_FMT", field=%d)",
+					LOC_FAIL(( fp, "hit field out of schema (wordid=" UINT64_FMT "(%s), docid=" DOCID_FMT ", field=%d)",
 						(uint64_t)uWordid, sWord, pQword->m_tDoc.m_iDocID, iField ));
 				}
 
@@ -18359,12 +18359,12 @@
 
 			// check hit count
 			if ( iDocHits!=(int)pQword->m_uMatchHits && !bHitless )
-				LOC_FAIL(( fp, "doc hit count mismatch (wordid="UINT64_FMT"(%s), docid="DOCID_FMT", doclist=%d, hitlist=%d)",
+				LOC_FAIL(( fp, "doc hit count mismatch (wordid=" UINT64_FMT "(%s), docid=" DOCID_FMT ", doclist=%d, hitlist=%d)",
 					(uint64_t)uWordid, sWord, pQword->m_tDoc.m_iDocID, pQword->m_uMatchHits, iDocHits ));
 
 			// check the mask
 			if ( dFieldMask!=pQword->m_dQwordFields && !bHitless )
-				LOC_FAIL(( fp, "field mask mismatch (wordid="UINT64_FMT"(%s), docid="DOCID_FMT")",
+				LOC_FAIL(( fp, "field mask mismatch (wordid=" UINT64_FMT "(%s), docid=" DOCID_FMT ")",
 					(uint64_t)uWordid, sWord, pQword->m_tDoc.m_iDocID ));
 
 			// update my hitlist reader
@@ -18373,11 +18373,11 @@
 
 		// do checks
 		if ( iDictDocs!=iDoclistDocs )
-			LOC_FAIL(( fp, "doc count mismatch (wordid="UINT64_FMT"(%s), dict=%d, doclist=%d, hitless=%s)",
+			LOC_FAIL(( fp, "doc count mismatch (wordid=" UINT64_FMT "(%s), dict=%d, doclist=%d, hitless=%s)",
 				uint64_t(uWordid), sWord, iDictDocs, iDoclistDocs, ( bHitless?"true":"false" ) ));
 
 		if ( ( iDictHits!=iDoclistHits || iDictHits!=iHitlistHits ) && !bHitless )
-			LOC_FAIL(( fp, "hit count mismatch (wordid="UINT64_FMT"(%s), dict=%d, doclist=%d, hitlist=%d)",
+			LOC_FAIL(( fp, "hit count mismatch (wordid=" UINT64_FMT "(%s), dict=%d, doclist=%d, hitlist=%d)",
 				uint64_t(uWordid), sWord, iDictHits, iDoclistHits, iHitlistHits ));
 
 		while ( m_bHaveSkips && iDoclistDocs>SPH_SKIPLIST_BLOCK && !bHitless )
@@ -18455,7 +18455,7 @@
 		iAllRowsTotal += (m_iDocinfoIndex+1)*2; // should had been fixed up to v.20 by the loader
 
 		if ( iAllRowsTotal*uStride!=(int64_t)m_pDocinfo.GetNumEntries() )
-			LOC_FAIL(( fp, "rowitems count mismatch (expected="INT64_FMT", loaded="INT64_FMT")",
+			LOC_FAIL(( fp, "rowitems count mismatch (expected=" INT64_FMT ", loaded=" INT64_FMT ")",
 				iAllRowsTotal*uStride, (int64_t)m_pDocinfo.GetNumEntries() ));
 
 		// extract rowitem indexes for MVAs etc
@@ -18534,7 +18534,7 @@
 			// check that ids are ascending
 			bool bIsSpaValid = uLastID < DOCINFO2ID(pRow);
 			if ( !bIsSpaValid )
-				LOC_FAIL(( fp, "docid decreased (row="INT64_FMT", id="DOCID_FMT", lastid="DOCID_FMT")",
+				LOC_FAIL(( fp, "docid decreased (row=" INT64_FMT ", id=" DOCID_FMT ", lastid=" DOCID_FMT ")",
 					iRow, DOCINFO2ID(pRow), uLastID ));
 
 			uLastID = DOCINFO2ID(pRow);
@@ -18556,7 +18556,7 @@
 					if ( uOffset && pMvaBase+uOffset>=pMvaMax )
 					{
 						bIsSpaValid = false;
-						LOC_FAIL(( fp, "MVA index out of bounds (row="INT64_FMT", mvaattr=%d, docid="DOCID_FMT", index=%u)",
+						LOC_FAIL(( fp, "MVA index out of bounds (row=" INT64_FMT ", mvaattr=%d, docid=" DOCID_FMT ", index=%u)",
 							iRow, iItem, uLastID, uOffset ));
 					}
 
@@ -18577,11 +18577,11 @@
 					pMva = DOCINFO2ATTRS(pMva);
 
 					if ( bLastIDChecked && uLastID==uMvaID )
-						LOC_FAIL(( fp, "duplicate docid found (row="INT64_FMT", docid expected="DOCID_FMT", got="DOCID_FMT", index=%u)",
+						LOC_FAIL(( fp, "duplicate docid found (row=" INT64_FMT ", docid expected=" DOCID_FMT ", got=" DOCID_FMT ", index=%u)",
 							iRow, uLastID, uMvaID, (DWORD)(pMva-pMvaBase) ));
 
 					if ( uMvaID<uLastMvaID )
-						LOC_FAIL(( fp, "MVA docid decreased (row="INT64_FMT", spa docid="DOCID_FMT", last MVA docid="DOCID_FMT", MVA docid="DOCID_FMT", index=%u)",
+						LOC_FAIL(( fp, "MVA docid decreased (row=" INT64_FMT ", spa docid=" DOCID_FMT ", last MVA docid=" DOCID_FMT ", MVA docid=" DOCID_FMT ", index=%u)",
 							iRow, uLastID, uLastMvaID, uMvaID, (DWORD)(pMva-pMvaBase) ));
 
 					bool bIsMvaCorrect = uLastMvaID<=uMvaID && uMvaID<=uLastID;
@@ -18599,7 +18599,7 @@
 						// check offset (index)
 						if ( uMvaID==uLastID && bIsSpaValid && pMva!=pMvaBase+uSpaOffset )
 						{
-							LOC_FAIL(( fp, "unexpected MVA docid (row="INT64_FMT", mvaattr=%d, docid expected="DOCID_FMT", got="DOCID_FMT", expected=%u, got=%u)",
+							LOC_FAIL(( fp, "unexpected MVA docid (row=" INT64_FMT ", mvaattr=%d, docid expected=" DOCID_FMT ", got=" DOCID_FMT ", expected=%u, got=%u)",
 								iRow, iItem, uLastID, uMvaID, (DWORD)(pMva-pMvaBase), uSpaOffset ));
 							// it's unexpected but it's our best guess
 							// but do fix up only once, to prevent infinite loop
@@ -18609,7 +18609,7 @@
 
 						if ( pMva>=pMvaMax )
 						{
-							LOC_FAIL(( fp, "MVA index out of bounds (row="INT64_FMT", mvaattr=%d, docid expected="DOCID_FMT", got="DOCID_FMT", index=%u)",
+							LOC_FAIL(( fp, "MVA index out of bounds (row=" INT64_FMT ", mvaattr=%d, docid expected=" DOCID_FMT ", got=" DOCID_FMT ", index=%u)",
 								iRow, iItem, uLastID, uMvaID, (DWORD)(pMva-pMvaBase) ));
 							bIsMvaCorrect = false;
 							continue;
@@ -18620,7 +18620,7 @@
 
 						if ( pMva+uValues-1>=pMvaMax )
 						{
-							LOC_FAIL(( fp, "MVA count out of bounds (row="INT64_FMT", mvaattr=%d, docid expected="DOCID_FMT", got="DOCID_FMT", count=%u)",
+							LOC_FAIL(( fp, "MVA count out of bounds (row=" INT64_FMT ", mvaattr=%d, docid expected=" DOCID_FMT ", got=" DOCID_FMT ", count=%u)",
 								iRow, iItem, uLastID, uMvaID, uValues ));
 							pMva += uValues;
 							bIsMvaCorrect = false;
@@ -18644,7 +18644,7 @@
 
 							if ( iCur<=iPrev )
 							{
-								LOC_FAIL(( fp, "unsorted MVA values (row="INT64_FMT", mvaattr=%d, docid expected="DOCID_FMT", got="DOCID_FMT", val[%u]=%u, val[%u]=%u)",
+								LOC_FAIL(( fp, "unsorted MVA values (row=" INT64_FMT ", mvaattr=%d, docid expected=" DOCID_FMT ", got=" DOCID_FMT ", val[%u]=%u, val[%u]=%u)",
 									iRow, iItem, uLastID, uMvaID, ( iItem>=iMva64 ? uVal-2 : uVal-1 ), (unsigned int)iPrev, uVal, (unsigned int)iCur ));
 								bIsMvaCorrect = false;
 							}
@@ -18665,7 +18665,7 @@
 				}
 
 				if ( !bLastIDChecked && bHasValues )
-					LOC_FAIL(( fp, "missed or damaged MVA (row="INT64_FMT", docid expected="DOCID_FMT")",
+					LOC_FAIL(( fp, "missed or damaged MVA (row=" INT64_FMT ", docid expected=" DOCID_FMT ")",
 						iRow, uLastID ));
 			}
 
@@ -18682,12 +18682,12 @@
 
 				// check normalized
 				if ( uExp==0 && uMantissa!=0 )
-					LOC_FAIL(( fp, "float attribute value is unnormalized (row="INT64_FMT", attr=%d, id="DOCID_FMT", raw=0x%x, value=%f)",
+					LOC_FAIL(( fp, "float attribute value is unnormalized (row=" INT64_FMT ", attr=%d, id=" DOCID_FMT ", raw=0x%x, value=%f)",
 						iRow, iItem, uLastID, uValue, sphDW2F ( uValue ) ));
 
 				// check +-inf
 				if ( uExp==0xff && uMantissa==0 )
-					LOC_FAIL(( fp, "float attribute is infinity (row="INT64_FMT", attr=%d, id="DOCID_FMT", raw=0x%x, value=%f)",
+					LOC_FAIL(( fp, "float attribute is infinity (row=" INT64_FMT ", attr=%d, id=" DOCID_FMT ", raw=0x%x, value=%f)",
 						iRow, iItem, uLastID, uValue, sphDW2F ( uValue ) ));
 			}
 
@@ -18702,7 +18702,7 @@
 				const DWORD uOffset = (DWORD)sphGetRowAttr ( pAttrs, dStrItems[ iItem ] );
 				if ( uOffset>=m_pStrings.GetNumEntries() )
 				{
-					LOC_FAIL(( fp, "string offset out of bounds (row="INT64_FMT", stringattr=%d, docid="DOCID_FMT", index=%u)",
+					LOC_FAIL(( fp, "string offset out of bounds (row=" INT64_FMT ", stringattr=%d, docid=" DOCID_FMT ", index=%u)",
 						iRow, iItem, uLastID, uOffset ));
 					continue;
 				}
@@ -18716,7 +18716,7 @@
 				// check that length is sane
 				if ( pStr+iLen-1>=m_pStrings.GetWritePtr()+m_pStrings.GetLength() )
 				{
-					LOC_FAIL(( fp, "string length out of bounds (row="INT64_FMT", stringattr=%d, docid="DOCID_FMT", index=%u)",
+					LOC_FAIL(( fp, "string length out of bounds (row=" INT64_FMT ", stringattr=%d, docid=" DOCID_FMT ", index=%u)",
 						iRow, iItem, uLastID, (unsigned int)( pStr-m_pStrings.GetWritePtr()+iLen-1 ) ));
 					continue;
 				}
@@ -18725,7 +18725,7 @@
 				// (that is, that we don't point in the middle of some other data)
 				if ( !dStringOffsets.BinarySearch ( uOffset ) )
 				{
-					LOC_FAIL(( fp, "string offset is not a string start (row="INT64_FMT", stringattr=%d, docid="DOCID_FMT", offset=%u)",
+					LOC_FAIL(( fp, "string offset is not a string start (row=" INT64_FMT ", stringattr=%d, docid=" DOCID_FMT ", offset=%u)",
 						iRow, iItem, uLastID, uOffset ));
 				}
 			}
@@ -18733,7 +18733,7 @@
 			// progress bar
 			if ( iRow%1000==0 && bProgress )
 			{
-				fprintf ( fp, INT64_FMT"/"INT64_FMT"\r", iRow, iRowsTotal );
+				fprintf ( fp, INT64_FMT"/" INT64_FMT "\r", iRow, iRowsTotal );
 				fflush ( fp );
 			}
 		}
@@ -18750,7 +18750,7 @@
 		// check size
 		const int64_t iTempDocinfoIndex = ( m_iDocinfo+DOCINFO_INDEX_FREQ-1 ) / DOCINFO_INDEX_FREQ;
 		if ( iTempDocinfoIndex!=m_iDocinfoIndex )
-			LOC_FAIL(( fp, "block count differs (expected="INT64_FMT", got="INT64_FMT")",
+			LOC_FAIL(( fp, "block count differs (expected=" INT64_FMT ", got=" INT64_FMT ")",
 				iTempDocinfoIndex, m_iDocinfoIndex ));
 
 		const DWORD uMinMaxStride = DOCINFO_IDSIZE + m_tSchema.GetRowSize();
@@ -18774,12 +18774,12 @@
 
 			// check docid vs global range
 			if ( pMaxEntry+uMinMaxStride > pDocinfoIndexMax )
-				LOC_FAIL(( fp, "unexpected block index end (row="INT64_FMT", docid="DOCID_FMT", block="INT64_FMT", max="INT64_FMT", cur="INT64_FMT")",
+				LOC_FAIL(( fp, "unexpected block index end (row=" INT64_FMT ", docid=" DOCID_FMT ", block=" INT64_FMT ", max=" INT64_FMT ", cur=" INT64_FMT ")",
 					iIndexEntry, uDocID, iBlock, int64_t ( pDocinfoIndexMax-m_pDocinfoIndex ), int64_t ( pMaxEntry+uMinMaxStride-m_pDocinfoIndex ) ));
 
 			// check attribute location vs global range
 			if ( pMaxAttrs+uMinMaxStride > pDocinfoIndexMax )
-				LOC_FAIL(( fp, "attribute position out of blocks index (row="INT64_FMT", docid="DOCID_FMT", block="INT64_FMT", expected<"INT64_FMT", got="INT64_FMT")",
+				LOC_FAIL(( fp, "attribute position out of blocks index (row=" INT64_FMT ", docid=" DOCID_FMT ", block=" INT64_FMT ", expected<" INT64_FMT ", got=" INT64_FMT ")",
 					iIndexEntry, uDocID, iBlock, int64_t ( pDocinfoIndexMax-m_pDocinfoIndex ), int64_t ( pMaxAttrs+uMinMaxStride-m_pDocinfoIndex ) ));
 
 			const SphDocID_t uMinDocID = DOCINFO2ID ( pMinEntry );
@@ -18787,12 +18787,12 @@
 
 			// checks is docid min max range valid
 			if ( uMinDocID > uMaxDocID && bIsBordersCheckTime )
-				LOC_FAIL(( fp, "invalid docid range (row="INT64_FMT", block="INT64_FMT", min="DOCID_FMT", max="DOCID_FMT")",
+				LOC_FAIL(( fp, "invalid docid range (row=" INT64_FMT ", block=" INT64_FMT ", min=" DOCID_FMT ", max=" DOCID_FMT ")",
 					iIndexEntry, iBlock, uMinDocID, uMaxDocID ));
 
 			// checks docid vs blocks range
 			if ( uDocID < uMinDocID || uDocID > uMaxDocID )
-				LOC_FAIL(( fp, "unexpected docid range (row="INT64_FMT", docid="DOCID_FMT", block="INT64_FMT", min="DOCID_FMT", max="DOCID_FMT")",
+				LOC_FAIL(( fp, "unexpected docid range (row=" INT64_FMT ", docid=" DOCID_FMT ", block=" INT64_FMT ", min=" DOCID_FMT ", max=" DOCID_FMT ")",
 					iIndexEntry, uDocID, iBlock, uMinDocID, uMaxDocID ));
 
 			bool bIsFirstMva = true;
@@ -18816,11 +18816,11 @@
 
 						// checks is attribute min max range valid
 						if ( uMin > uMax && bIsBordersCheckTime )
-							LOC_FAIL(( fp, "invalid attribute range (row="INT64_FMT", block="INT64_FMT", min="INT64_FMT", max="INT64_FMT")",
+							LOC_FAIL(( fp, "invalid attribute range (row=" INT64_FMT ", block=" INT64_FMT ", min=" INT64_FMT ", max=" INT64_FMT ")",
 								iIndexEntry, iBlock, uMin, uMax ));
 
 						if ( uVal < uMin || uVal > uMax )
-							LOC_FAIL(( fp, "unexpected attribute value (row="INT64_FMT", attr=%u, docid="DOCID_FMT", block="INT64_FMT", value=0x"UINT64_FMT", min=0x"UINT64_FMT", max=0x"UINT64_FMT")",
+							LOC_FAIL(( fp, "unexpected attribute value (row=" INT64_FMT ", attr=%u, docid=" DOCID_FMT ", block=" INT64_FMT ", value=0x" UINT64_FMT ", min=0x" UINT64_FMT ", max=0x" UINT64_FMT ")",
 								iIndexEntry, iItem, uDocID, iBlock, uint64_t(uVal), uint64_t(uMin), uint64_t(uMax) ));
 					}
 					break;
@@ -18833,11 +18833,11 @@
 
 						// checks is attribute min max range valid
 						if ( fMin > fMax && bIsBordersCheckTime )
-							LOC_FAIL(( fp, "invalid attribute range (row="INT64_FMT", block="INT64_FMT", min=%f, max=%f)",
+							LOC_FAIL(( fp, "invalid attribute range (row=" INT64_FMT ", block=" INT64_FMT ", min=%f, max=%f)",
 								iIndexEntry, iBlock, fMin, fMax ));
 
 						if ( fVal < fMin || fVal > fMax )
-							LOC_FAIL(( fp, "unexpected attribute value (row="INT64_FMT", attr=%u, docid="DOCID_FMT", block="INT64_FMT", value=%f, min=%f, max=%f)",
+							LOC_FAIL(( fp, "unexpected attribute value (row=" INT64_FMT ", attr=%u, docid=" DOCID_FMT ", block=" INT64_FMT ", value=%f, min=%f, max=%f)",
 								iIndexEntry, iItem, uDocID, iBlock, fVal, fMin, fMax ));
 					}
 					break;
@@ -18849,7 +18849,7 @@
 
 						// checks is MVA attribute min max range valid
 						if ( uMin > uMax && bIsBordersCheckTime && uMin!=0xffffffff && uMax!=0 )
-							LOC_FAIL(( fp, "invalid MVA range (row="INT64_FMT", block="INT64_FMT", min=0x%x, max=0x%x)",
+							LOC_FAIL(( fp, "invalid MVA range (row=" INT64_FMT ", block=" INT64_FMT ", min=0x%x, max=0x%x)",
 							iIndexEntry, iBlock, uMin, uMax ));
 
 						SphAttr_t uOff = sphGetRowAttr ( pSpaRow, tCol.m_tLocator );
@@ -18865,7 +18865,7 @@
 
 						if ( pMvaDocID && DOCINFO2ID ( pMvaDocID )!=uDocID )
 						{
-							LOC_FAIL(( fp, "unexpected MVA docid (row="INT64_FMT", mvaattr=%d, expected="DOCID_FMT", got="DOCID_FMT", block="INT64_FMT", index=%u)",
+							LOC_FAIL(( fp, "unexpected MVA docid (row=" INT64_FMT ", mvaattr=%d, expected=" DOCID_FMT ", got=" DOCID_FMT ", block=" INT64_FMT ", index=%u)",
 								iIndexEntry, iItem, uDocID, DOCINFO2ID ( pMvaDocID ), iBlock, (DWORD)uOff ));
 							break;
 						}
@@ -18879,7 +18879,7 @@
 						{
 							const DWORD uVal = *pMva++;
 							if ( uVal < uMin || uVal > uMax )
-								LOC_FAIL(( fp, "unexpected MVA value (row="INT64_FMT", attr=%u, docid="DOCID_FMT", block="INT64_FMT", index=%u, value=0x%x, min=0x%x, max=0x%x)",
+								LOC_FAIL(( fp, "unexpected MVA value (row=" INT64_FMT ", attr=%u, docid=" DOCID_FMT ", block=" INT64_FMT ", index=%u, value=0x%x, min=0x%x, max=0x%x)",
 									iIndexEntry, iItem, uDocID, iBlock, iVal, (DWORD)uVal, (DWORD)uMin, (DWORD)uMax ));
 						}
 					}
@@ -18893,7 +18893,7 @@
 			// progress bar
 			if ( iIndexEntry%1000==0 && bProgress )
 			{
-				fprintf ( fp, INT64_FMT"/"INT64_FMT"\r", iIndexEntry, m_iDocinfo );
+				fprintf ( fp, INT64_FMT"/" INT64_FMT "\r", iIndexEntry, m_iDocinfo );
 				fflush ( fp );
 			}
 		}
@@ -18907,7 +18907,7 @@
 
 	// check size
 	if ( m_pKillList.GetNumEntries()!=m_iKillListSize )
-		LOC_FAIL(( fp, "kill-list size differs (expected=%d, got="INT64_FMT")",
+		LOC_FAIL(( fp, "kill-list size differs (expected=%d, got=" INT64_FMT ")",
 			m_iKillListSize, (int64_t)m_pKillList.GetNumEntries() ));
 
 	// check that ids are ascending
@@ -21085,7 +21085,7 @@
 		m_dBlocks[i].m_sInfix = pBlockWords+m_dBlocks[i].m_iInfixOffset;
 
 	if ( wrDict.GetPos()>UINT_MAX ) // FIXME!!! change to int64
-		sphDie ( "INTERNAL ERROR: dictionary size "INT64_FMT" overflow at infix save", wrDict.GetPos() );
+		sphDie ( "INTERNAL ERROR: dictionary size " INT64_FMT " overflow at infix save", wrDict.GetPos() );
 }
 
 #if USE_WINDOWS
@@ -21352,9 +21352,9 @@
 		}
 
 		// crc matches, check keyword
-		register int iWordLen = iLen;
-		register const char * a = pEntry->m_pKeyword;
-		register const char * b = sWord;
+		int iWordLen = iLen;
+		const char * a = pEntry->m_pKeyword;
+		const char * b = sWord;
 		while ( *a==*b && iWordLen-- )
 		{
 			if ( !*a || !iWordLen )
@@ -21714,7 +21714,7 @@
 		pHeader->m_iInfixBlocksOffset = pInfixer->SaveEntryBlocks ( m_wrDict );
 		pHeader->m_iInfixBlocksWordsSize = pInfixer->GetBlocksWordsSize();
 		if ( pHeader->m_iInfixBlocksOffset>UINT_MAX ) // FIXME!!! change to int64
-			sphDie ( "INTERNAL ERROR: dictionary size "INT64_FMT" overflow at dictend save", pHeader->m_iInfixBlocksOffset );
+			sphDie ( "INTERNAL ERROR: dictionary size " INT64_FMT " overflow at dictend save", pHeader->m_iInfixBlocksOffset );
 	}
 
 	// flush header
@@ -22081,7 +22081,7 @@
 		if ( m_dExceptions[i].m_pEntry->m_uWordid==uWordID )
 			return m_dExceptions[i].m_pEntry->m_pKeyword;
 
-	sphWarning ( "hash missing value in operator [] (wordid="INT64_FMT", hash=%d)", (int64_t)uWordID, uHash );
+	sphWarning ( "hash missing value in operator [] (wordid=" INT64_FMT ", hash=%d)", (int64_t)uWordID, uHash );
 	assert ( 0 && "hash missing value in operator []" );
 	return "\31oops";
 }
@@ -22648,7 +22648,7 @@
 		421, 421, 421, 421, 421, 421, 421
 	};
 
-	register int hval = len;
+	int hval = len;
 	switch ( hval )
 	{
 		default:	hval += asso_values [ str[4] ];
@@ -23031,11 +23031,11 @@
 
 	if ( len<=MAX_WORD_LENGTH && len>=MIN_WORD_LENGTH )
 	{
-		register int key = HtmlEntityHash ( str, len );
+		int key = HtmlEntityHash ( str, len );
 		if ( key<=MAX_HASH_VALUE && key>=0 )
 			if ( len==lengthtable[key] )
 		{
-			register const char * s = wordlist[key].m_sName;
+			const char * s = wordlist[key].m_sName;
 			if ( *str==*s && !memcmp ( str+1, s+1, len-1 ) )
 				return wordlist[key].m_iCode;
 		}
@@ -24029,7 +24029,7 @@
 	int64_t iFileSize = tFileSource.GetSize();
 	if ( iFileSize+16 > m_iMaxFileBufferSize )
 	{
-		sphWarning ( "docid=" DOCID_FMT ": file '%s' too big for a field (size="INT64_FMT", max_file_field_buffer=%d)",
+		sphWarning ( "docid=" DOCID_FMT ": file '%s' too big for a field (size=" INT64_FMT ", max_file_field_buffer=%d)",
 			m_tDocInfo.m_iDocID, (const char *)sField, iFileSize, m_iMaxFileBufferSize );
 		return false;
 	}
@@ -24054,7 +24054,7 @@
 	int64_t iFileSize = tFileSource.GetSize();
 	if ( iFileSize+16 > m_iMaxFileBufferSize )
 	{
-		sphWarning ( "docid=" DOCID_FMT ": file '%s' too big for a field (size="INT64_FMT", max_file_field_buffer=%d)",
+		sphWarning ( "docid=" DOCID_FMT ": file '%s' too big for a field (size=" INT64_FMT ", max_file_field_buffer=%d)",
 			m_tDocInfo.m_iDocID, (const char *)sField, iFileSize, m_iMaxFileBufferSize );
 		return -1;
 	}
@@ -24918,10 +24918,10 @@
 {
 	// check step
 	if ( m_tParams.m_iRangeStep<=0 )
-		LOC_ERROR ( "sql_range_step="INT64_FMT": must be non-zero positive", m_tParams.m_iRangeStep );
+		LOC_ERROR ( "sql_range_step=" INT64_FMT ": must be non-zero positive", m_tParams.m_iRangeStep );
 
 	if ( m_tParams.m_iRangeStep<128 )
-		sphWarn ( "sql_range_step="INT64_FMT": too small; might hurt indexing performance!", m_tParams.m_iRangeStep );
+		sphWarn ( "sql_range_step=" INT64_FMT ": too small; might hurt indexing performance!", m_tParams.m_iRangeStep );
 
 	// check query for macros
 	for ( int i=0; i<MACRO_COUNT; i++ )
@@ -24977,11 +24977,11 @@
 		if ( !HookQueryRange ( m_tParams.m_sHookQueryRange.cstr(), &m_uMinID, &m_uMaxID ) )
 			LOC_ERROR ( "hook_query_range: runtime error %s when running external hook", strerror(errno) );
 		if ( m_uMinID<=0 )
-			LOC_ERROR ( "hook_query_range: min_id="DOCID_FMT": must be positive 32/64-bit unsigned integer", m_uMinID );
+			LOC_ERROR ( "hook_query_range: min_id=" DOCID_FMT ": must be positive 32/64-bit unsigned integer", m_uMinID );
 		if ( m_uMaxID<=0 )
-			LOC_ERROR ( "hook_query_range: max_id="DOCID_FMT": must be positive 32/64-bit unsigned integer", m_uMaxID );
+			LOC_ERROR ( "hook_query_range: max_id=" DOCID_FMT ": must be positive 32/64-bit unsigned integer", m_uMaxID );
 		if ( m_uMinID>m_uMaxID )
-			LOC_ERROR2 ( "hook_query_range: min_id="DOCID_FMT", max_id="DOCID_FMT": min_id must be less than max_id", m_uMinID, m_uMaxID );
+			LOC_ERROR2 ( "hook_query_range: min_id=" DOCID_FMT ", max_id=" DOCID_FMT ": min_id must be less than max_id", m_uMinID, m_uMaxID );
 	}
 
 	return true;
@@ -25574,7 +25574,7 @@
 				{
 					m_bUnpackFailed = true;
 					sphWarn ( "failed to unpack '%s', invalid column size (size=%d), "
-						"docid="DOCID_FMT, SqlFieldName(iIndex), iPackedLen, m_tDocInfo.m_iDocID );
+						"docid=" DOCID_FMT, SqlFieldName(iIndex), iPackedLen, m_tDocInfo.m_iDocID );
 				}
 				return NULL;
 			}
@@ -25590,7 +25590,7 @@
 				{
 					m_bUnpackOverflow = true;
 					sphWarn ( "failed to unpack '%s', column size limit exceeded (size=%d),"
-						" docid="DOCID_FMT, SqlFieldName(iIndex), (int)uSize, m_tDocInfo.m_iDocID );
+						" docid=" DOCID_FMT, SqlFieldName(iIndex), (int)uSize, m_tDocInfo.m_iDocID );
 				}
 				return NULL;
 			}
@@ -28586,7 +28586,7 @@
 	switch ( m_ePhase )
 	{
 		case PHASE_COLLECT:
-			snprintf ( sBuf, sizeof(sBuf), "collected "INT64_FMT" docs, %.1f MB", m_iDocuments,
+			snprintf ( sBuf, sizeof(sBuf), "collected " INT64_FMT " docs, %.1f MB", m_iDocuments,
 				float(m_iBytes)/1000000.0f );
 			break;
 
@@ -28596,7 +28596,7 @@
 			break;
 
 		case PHASE_COLLECT_MVA:
-			snprintf ( sBuf, sizeof(sBuf), "collected "INT64_FMT" attr values", m_iAttrs );
+			snprintf ( sBuf, sizeof(sBuf), "collected " INT64_FMT " attr values", m_iAttrs );
 			break;
 
 		case PHASE_SORT_MVA:
@@ -29478,7 +29478,7 @@
 	tDictHeader.m_iInfixBlocksOffset = pInfixer->SaveEntryBlocks ( wrDict );
 	tDictHeader.m_iInfixBlocksWordsSize = pInfixer->GetBlocksWordsSize();
 	if ( tDictHeader.m_iInfixBlocksOffset>UINT_MAX ) // FIXME!!! change to int64
-		sphDie ( "INTERNAL ERROR: dictionary size "INT64_FMT" overflow at build infixes save", tDictHeader.m_iInfixBlocksOffset );
+		sphDie ( "INTERNAL ERROR: dictionary size " INT64_FMT " overflow at build infixes save", tDictHeader.m_iInfixBlocksOffset );
 
 
 	// flush header
@@ -29961,7 +29961,7 @@
 		wrDict.PutBytes ( g_sTagInfixBlocks, strlen ( g_sTagInfixBlocks ) );
 		tDictHeader.m_iInfixBlocksOffset = wrDict.GetPos();
 		if ( tDictHeader.m_iInfixBlocksOffset>UINT_MAX ) // FIXME!!! change to int64
-			sphDie ( "INTERNAL ERROR: dictionary size "INT64_FMT" overflow at infix blocks save", wrDict.GetPos() );
+			sphDie ( "INTERNAL ERROR: dictionary size " INT64_FMT " overflow at infix blocks save", wrDict.GetPos() );
 
 		wrDict.ZipInt ( iBlocks );
 		for ( int i=0; i<iBlocks; i++ )
