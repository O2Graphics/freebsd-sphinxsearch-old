--- src/sphinxrt.cpp.orig	2018-09-23 00:54:09.700693000 +0200
+++ src/sphinxrt.cpp	2018-09-23 01:00:42.009413000 +0200
@@ -1280,7 +1280,7 @@
 	Verify ( m_tRwlock.Unlock() );
 
 	tmSave = sphMicroTimer() - tmSave;
-	sphInfo ( "rt: index %s: ramchunk saved ok (mode=%s, last TID="INT64_FMT", current TID="INT64_FMT", "
+	sphInfo ( "rt: index %s: ramchunk saved ok (mode=%s, last TID=" INT64_FMT ", current TID=" INT64_FMT ", "
 		"last ram=%d.%03d Mb, current ram=%d.%03d Mb, time delta=%d sec, took=%d.%03d sec)"
 		, m_sIndexName.cstr(), bPeriodic ? "periodic" : "forced"
 		, iWasTID, m_iTID, (int)(iWasRam/1024/1024), (int)((iWasRam/1024)%1000)
@@ -1377,7 +1377,7 @@
 				&& !m_pSegments[i]->m_dKlist.BinarySearch ( tDoc.m_iDocID ) )
 		{
 			m_tRwlock.Unlock ();
-			sError.SetSprintf ( "duplicate id '"UINT64_FMT"'", (uint64_t)tDoc.m_iDocID );
+			sError.SetSprintf ( "duplicate id '" UINT64_FMT "'", (uint64_t)tDoc.m_iDocID );
 			return false; // already exists and not deleted; INSERT fails
 		}
 		m_tRwlock.Unlock ();
@@ -4327,7 +4327,7 @@
 		LOC_FAIL(( fp, "wrong attribute stride (current=%d, should_be=%d)", m_iStride, DOCINFO_IDSIZE+m_tSchema.GetRowSize() ));
 
 	if ( m_iSoftRamLimit<=0 )
-		LOC_FAIL(( fp, "wrong RAM limit (current="INT64_FMT")", m_iSoftRamLimit ));
+		LOC_FAIL(( fp, "wrong RAM limit (current=" INT64_FMT ")", m_iSoftRamLimit ));
 
 	if ( m_iLockFD<0 )
 		LOC_FAIL(( fp, "index lock file id < 0" ));
@@ -4336,13 +4336,13 @@
 		LOC_FAIL(( fp, "disk chunk base < 0" ));
 
 	if ( m_iTID<0 )
-		LOC_FAIL(( fp, "index TID < 0 (current="INT64_FMT")", m_iTID ));
+		LOC_FAIL(( fp, "index TID < 0 (current=" INT64_FMT ")", m_iTID ));
 
 	if ( m_iSavedTID<0 )
-		LOC_FAIL(( fp, "index saved TID < 0 (current="INT64_FMT")", m_iSavedTID ));
+		LOC_FAIL(( fp, "index saved TID < 0 (current=" INT64_FMT ")", m_iSavedTID ));
 
 	if ( m_iTID<m_iSavedTID )
-		LOC_FAIL(( fp, "index TID < index saved TID (current="INT64_FMT", saved="INT64_FMT")", m_iTID, m_iSavedTID ));
+		LOC_FAIL(( fp, "index TID < index saved TID (current=" INT64_FMT ", saved=" INT64_FMT ")", m_iTID, m_iSavedTID ));
 
 	if ( m_iWordsCheckpoint!=RTDICT_CHECKPOINT_V3 && m_iWordsCheckpoint!=RTDICT_CHECKPOINT_V5 )
 		LOC_FAIL(( fp, "unexpected number of words per checkpoint (expected 1024 or 48, got %d)", m_iWordsCheckpoint ));
@@ -4513,7 +4513,7 @@
 
 				if ( tWord.m_uWordID<=uPrevWordID )
 				{
-					LOC_FAIL(( fp, "wordid decreased (segment=%d, word=%d, wordid="UINT64_FMT", previd="UINT64_FMT")",
+					LOC_FAIL(( fp, "wordid decreased (segment=%d, word=%d, wordid=" UINT64_FMT ", previd=" UINT64_FMT ")",
 						iSegment, nWordsRead, (uint64_t)tWord.m_uWordID, (uint64_t)uPrevWordID ));
 				}
 
@@ -4542,7 +4542,7 @@
 			if ( !tWord.m_uDocs || !tWord.m_uHits || tWord.m_uHits<tWord.m_uDocs )
 			{
 				sWord[sizeof(sWord)-1] = '\0';
-				LOC_FAIL(( fp, "invalid docs/hits (segment=%d, word=%d, read_wordid="UINT64_FMT
+				LOC_FAIL(( fp, "invalid docs/hits (segment=%d, word=%d, read_wordid=" UINT64_FMT
 					", read_word=%s, docs=%u, hits=%u)",
 					iSegment, nWordsRead, (uint64_t)tWord.m_uWordID,
 					sWord+1, tWord.m_uDocs, tWord.m_uHits ));
@@ -4565,7 +4565,7 @@
 
 			if ( uPrevDocOffset && tWord.m_uDoc<=uPrevDocOffset )
 				LOC_FAIL(( fp, "doclist offset decreased (segment=%d, word=%d, "
-					"read_wordid="UINT64_FMT", read_word=%s, doclist_offset=%u, prev_doclist_offset=%u)",
+					"read_wordid=" UINT64_FMT ", read_word=%s, doclist_offset=%u, prev_doclist_offset=%u)",
 					iSegment, nWordsRead,
 					(uint64_t)tWord.m_uWordID, sWord+1, tWord.m_uDoc, uPrevDocOffset ));
 
@@ -4573,7 +4573,7 @@
 			DWORD uDocOffset = pCurDoc-tSegment.m_dDocs.Begin();
 			if ( tWord.m_uDoc!=uDocOffset )
 			{
-				LOC_FAIL(( fp, "unexpected doclist offset (wordid="UINT64_FMT"(%s)(%d), "
+				LOC_FAIL(( fp, "unexpected doclist offset (wordid=" UINT64_FMT "(%s)(%d), "
 					"doclist_offset=%u, expected_offset=%u)",
 					(uint64_t)tWord.m_uWordID, sWord+1, nWordsRead,
 					tWord.m_uDoc, uDocOffset ));
@@ -4606,7 +4606,7 @@
 				if ( pIn>=pMaxDoc )
 				{
 					LOC_FAIL(( fp, "reading past doclist end (segment=%d, word=%d, "
-						"read_wordid="UINT64_FMT", read_word=%s, doclist_offset=%u, doclist_size=%d)",
+						"read_wordid=" UINT64_FMT ", read_word=%s, doclist_offset=%u, doclist_size=%d)",
 						iSegment, nWordsRead,
 						(uint64_t)tWord.m_uWordID, sWord+1, uDocOffset, tSegment.m_dDocs.GetLength() ));
 					break;
@@ -4618,7 +4618,7 @@
 				if ( pIn>=pMaxDoc )
 				{
 					LOC_FAIL(( fp, "reading past doclist end (segment=%d, word=%d, "
-						"read_wordid="UINT64_FMT", read_word=%s, doclist_offset=%u, doclist_size=%d)",
+						"read_wordid=" UINT64_FMT ", read_word=%s, doclist_offset=%u, doclist_size=%d)",
 						iSegment, nWordsRead,
 						(uint64_t)tWord.m_uWordID, sWord+1, uDocOffset, tSegment.m_dDocs.GetLength() ));
 					break;
@@ -4629,7 +4629,7 @@
 				if ( pIn>=pMaxDoc )
 				{
 					LOC_FAIL(( fp, "reading past doclist end (segment=%d, word=%d, "
-						"read_wordid="UINT64_FMT", read_word=%s, doclist_offset=%u, doclist_size=%d)",
+						"read_wordid=" UINT64_FMT ", read_word=%s, doclist_offset=%u, doclist_size=%d)",
 						iSegment, nWordsRead,
 						(uint64_t)tWord.m_uWordID, sWord+1, uDocOffset, tSegment.m_dDocs.GetLength() ));
 					break;
@@ -4644,7 +4644,7 @@
 					if ( pIn>=pMaxDoc )
 					{
 						LOC_FAIL(( fp, "reading past doclist end (segment=%d, word=%d, "
-							"read_wordid="UINT64_FMT", read_word=%s, doclist_offset=%u, doclist_size=%d)",
+							"read_wordid=" UINT64_FMT ", read_word=%s, doclist_offset=%u, doclist_size=%d)",
 							iSegment, nWordsRead,
 							(uint64_t)tWord.m_uWordID, sWord+1, uDocOffset, tSegment.m_dDocs.GetLength() ));
 						break;
@@ -4654,7 +4654,7 @@
 					if ( pIn>pMaxDoc )
 					{
 						LOC_FAIL(( fp, "reading past doclist end (segment=%d, word=%d, "
-							"read_wordid="UINT64_FMT", read_word=%s, doclist_offset=%u, doclist_size=%d)",
+							"read_wordid=" UINT64_FMT ", read_word=%s, doclist_offset=%u, doclist_size=%d)",
 							iSegment, nWordsRead,
 							(uint64_t)tWord.m_uWordID, sWord+1, uDocOffset, tSegment.m_dDocs.GetLength() ));
 						break;
@@ -4667,7 +4667,7 @@
 					if ( pIn>pMaxDoc )
 					{
 						LOC_FAIL(( fp, "reading past doclist end (segment=%d, word=%d, "
-							"read_wordid="UINT64_FMT", read_word=%s, doclist_offset=%u, doclist_size=%d)",
+							"read_wordid=" UINT64_FMT ", read_word=%s, doclist_offset=%u, doclist_size=%d)",
 							iSegment, nWordsRead,
 							(uint64_t)tWord.m_uWordID, sWord+1, uDocOffset, tSegment.m_dDocs.GetLength() ));
 						break;
@@ -4678,14 +4678,14 @@
 				if ( tDoc.m_uDocID<=uPrevDocID )
 				{
 					LOC_FAIL(( fp, "docid decreased (segment=%d, word=%d, "
-						"read_wordid="UINT64_FMT", read_word=%s, docid="UINT64_FMT", prev_docid="UINT64_FMT")",
+						"read_wordid=" UINT64_FMT ", read_word=%s, docid=" UINT64_FMT ", prev_docid=" UINT64_FMT ")",
 						iSegment, nWordsRead,
 						(uint64_t)tWord.m_uWordID, sWord+1, (uint64_t)tDoc.m_uDocID, (uint64_t)uPrevDocID ));
 				}
 
 				if ( !tSegment.FindRow ( tDoc.m_uDocID ) )
 					LOC_FAIL(( fp, "no attributes found (segment=%d, word=%d, "
-						"wordid="UINT64_FMT", docid="UINT64_FMT")",
+						"wordid=" UINT64_FMT ", docid=" UINT64_FMT ")",
 						iSegment, nWordsRead,
 						(uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID ));
 
@@ -4700,14 +4700,14 @@
 					if ( iCounter!=1 || tDoc.m_uHits!=1 )
 					{
 						LOC_FAIL(( fp, "embedded hit with multiple occurences in a document found "
-							"(segment=%d, word=%d, wordid="UINT64_FMT", docid="UINT64_FMT")",
+							"(segment=%d, word=%d, wordid=" UINT64_FMT ", docid=" UINT64_FMT ")",
 							iSegment, nWordsRead, (uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID ));
 					}
 
 					if ( (int)uFieldId>m_tSchema.m_dFields.GetLength() || uFieldId>SPH_MAX_FIELDS )
 					{
 						LOC_FAIL(( fp, "invalid field id in an embedded hit (segment=%d, word=%d, "
-							"wordid="UINT64_FMT", docid="UINT64_FMT", field_id=%u, total_fields=%d)",
+							"wordid=" UINT64_FMT ", docid=" UINT64_FMT ", field_id=%u, total_fields=%d)",
 							iSegment, nWordsRead,
 							(uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID, uFieldId, m_tSchema.m_dFields.GetLength() ));
 					}
@@ -4715,7 +4715,7 @@
 					if ( !( tDoc.m_uDocFields & ( 1 << uFieldId ) ) )
 					{
 						LOC_FAIL(( fp, "invalid field id: not in doclist mask (segment=%d, word=%d, "
-							"wordid="UINT64_FMT", docid="UINT64_FMT", field_id=%u, field_mask=%u)",
+							"wordid=" UINT64_FMT ", docid=" UINT64_FMT ", field_id=%u, field_mask=%u)",
 							iSegment, nWordsRead,
 							(uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID, uFieldId, tDoc.m_uDocFields ));
 					}
@@ -4725,14 +4725,14 @@
 					if ( tDoc.m_uHit!=uExpectedHitOffset )
 					{
 						LOC_FAIL(( fp, "unexpected hitlist offset (segment=%d, word=%d, "
-							"wordid="UINT64_FMT", docid="UINT64_FMT", offset=%u, expected_offset=%u",
+							"wordid=" UINT64_FMT ", docid=" UINT64_FMT ", offset=%u, expected_offset=%u",
 							iSegment, nWordsRead,
 							(uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID, tDoc.m_uHit, uExpectedHitOffset ));
 					}
 
 					if ( tDoc.m_uHit && tDoc.m_uHit<=uPrevHitOffset )
 					{
-						LOC_FAIL(( fp, "hitlist offset decreased (segment=%d, word=%d, wordid="UINT64_FMT", docid="UINT64_FMT", offset=%u, prev_offset=%u",
+						LOC_FAIL(( fp, "hitlist offset decreased (segment=%d, word=%d, wordid=" UINT64_FMT ", docid=" UINT64_FMT ", offset=%u, prev_offset=%u",
 							iSegment, nWordsRead, (uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID, tDoc.m_uHit, uPrevHitOffset ));
 					}
 
@@ -4748,7 +4748,7 @@
 						pCurHit = UnzipDword ( &uValue, pCurHit );
 						if ( pCurHit>pMaxHit )
 						{
-							LOC_FAIL(( fp, "reading past hitlist end (segment=%d, word=%d, wordid="UINT64_FMT", docid="UINT64_FMT")",
+							LOC_FAIL(( fp, "reading past hitlist end (segment=%d, word=%d, wordid=" UINT64_FMT ", docid=" UINT64_FMT ")",
 								iSegment, nWordsRead, (uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID ));
 							break;
 						}
@@ -4762,7 +4762,7 @@
 						if ( (int)uFieldId>m_tSchema.m_dFields.GetLength() || uFieldId>SPH_MAX_FIELDS )
 						{
 							LOC_FAIL(( fp, "invalid field id in a hitlist (segment=%d, word=%d, "
-								"wordid="UINT64_FMT", docid="UINT64_FMT", field_id=%u, total_fields=%d)",
+								"wordid=" UINT64_FMT ", docid=" UINT64_FMT ", field_id=%u, total_fields=%d)",
 								iSegment, nWordsRead,
 								(uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID, uFieldId, m_tSchema.m_dFields.GetLength() ));
 						}
@@ -4770,7 +4770,7 @@
 						if ( !( tDoc.m_uDocFields & ( 1 << uFieldId ) ) )
 						{
 							LOC_FAIL(( fp, "invalid field id: not in doclist mask (segment=%d, word=%d, "
-								"wordid="UINT64_FMT", docid="UINT64_FMT", field_id=%u, field_mask=%u)",
+								"wordid=" UINT64_FMT ", docid=" UINT64_FMT ", field_id=%u, field_mask=%u)",
 								iSegment, nWordsRead,
 								(uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID, uFieldId, tDoc.m_uDocFields ));
 						}
@@ -4783,13 +4783,13 @@
 
 						if ( uLastPosInField && uPosInField<=uLastPosInField )
 						{
-							LOC_FAIL(( fp, "hit position in field decreased (segment=%d, word=%d, wordid="UINT64_FMT", docid="UINT64_FMT", pos=%u, last_pos=%u)",
+							LOC_FAIL(( fp, "hit position in field decreased (segment=%d, word=%d, wordid=" UINT64_FMT ", docid=" UINT64_FMT ", pos=%u, last_pos=%u)",
 								iSegment, nWordsRead, (uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID, uPosInField, uLastPosInField ));
 						}
 
 						if ( bLastInField && bLastInFieldFound )
 						{
-							LOC_FAIL(( fp, "duplicate last-in-field hit found (segment=%d, word=%d, wordid="UINT64_FMT", docid="UINT64_FMT")",
+							LOC_FAIL(( fp, "duplicate last-in-field hit found (segment=%d, word=%d, wordid=" UINT64_FMT ", docid=" UINT64_FMT ")",
 								iSegment, nWordsRead, (uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID ));
 						}
 
@@ -4804,7 +4804,7 @@
 				DWORD uAvailFieldMask = ( 1 << m_tSchema.m_dFields.GetLength() ) - 1;
 				if ( tDoc.m_uDocFields & ~uAvailFieldMask )
 				{
-					LOC_FAIL(( fp, "wrong document field mask (segment=%d, word=%d, wordid="UINT64_FMT", docid="UINT64_FMT", mask=%u, total_fields=%d",
+					LOC_FAIL(( fp, "wrong document field mask (segment=%d, word=%d, wordid=" UINT64_FMT ", docid=" UINT64_FMT ", mask=%u, total_fields=%d",
 						iSegment, nWordsRead, (uint64_t)tWord.m_uWordID, (uint64_t)tDoc.m_uDocID, tDoc.m_uDocFields, m_tSchema.m_dFields.GetLength() ));
 				}
 
@@ -4849,7 +4849,7 @@
 						i, iSegment, tCP.m_sWord, tCP.m_iOffset, tRefCP.m_sWord, tRefCP.m_iOffset ));
 				} else
 				{
-					LOC_FAIL(( fp, "word checkpoint %d differs (segment=%d, readid="UINT64_FMT", readpos=%d, calcid="UINT64_FMT", calcpos=%d)",
+					LOC_FAIL(( fp, "word checkpoint %d differs (segment=%d, readid=" UINT64_FMT ", readpos=%d, calcid=" UINT64_FMT ", calcpos=%d)",
 						i, iSegment, (uint64_t)tCP.m_iWordID, tCP.m_iOffset, (int64_t)tRefCP.m_iWordID, tRefCP.m_iOffset ));
 				}
 			}
@@ -4876,7 +4876,7 @@
 		for ( int iKListEntry = 1; iKListEntry<tSegment.m_dKlist.GetLength(); iKListEntry++ )
 		{
 			if ( tSegment.m_dKlist[iKListEntry-1]>=tSegment.m_dKlist[iKListEntry] )
-				LOC_FAIL(( fp, "unsorted kill-list values (segment=%d, val[%d]="DOCID_FMT", val[%d]="DOCID_FMT")",
+				LOC_FAIL(( fp, "unsorted kill-list values (segment=%d, val[%d]=" DOCID_FMT ", val[%d]=" DOCID_FMT ")",
 					iSegment, iKListEntry-1, tSegment.m_dKlist[iKListEntry-1], iKListEntry, tSegment.m_dKlist[iKListEntry] ));
 		}
 
@@ -4968,7 +4968,7 @@
 		for ( DWORD uRow=0; pRow<pRowMax; uRow++, pRow+=m_iStride )
 		{
 			if ( uLastID>=DOCINFO2ID(pRow) )
-				LOC_FAIL(( fp, "docid decreased in attributes (segment=%d, row=%u, docid="DOCID_FMT", lastid="DOCID_FMT")",
+				LOC_FAIL(( fp, "docid decreased in attributes (segment=%d, row=%u, docid=" DOCID_FMT ", lastid=" DOCID_FMT ")",
 					iSegment, uRow, DOCINFO2ID(pRow), uLastID ));
 
 			uLastID = DOCINFO2ID(pRow);
@@ -4989,14 +4989,14 @@
 
 					if ( pMvaBase+uOffset>=pMvaMax )
 					{
-						LOC_FAIL(( fp, "MVA index out of bounds (segment=%d, row=%u, mvaattr=%d, docid="DOCID_FMT", index=%u)",
+						LOC_FAIL(( fp, "MVA index out of bounds (segment=%d, row=%u, mvaattr=%d, docid=" DOCID_FMT ", index=%u)",
 							iSegment, uRow, iItem, uLastID, uOffset ));
 						continue;
 					}
 
 					if ( pMvaCur!=pMvaBase+uOffset )
 					{
-						LOC_FAIL(( fp, "wrong MVA offset (segment=%d, row=%u, mvaattr=%d, docid="DOCID_FMT", expected=%u, got=%u)",
+						LOC_FAIL(( fp, "wrong MVA offset (segment=%d, row=%u, mvaattr=%d, docid=" DOCID_FMT ", expected=%u, got=%u)",
 							iSegment, uRow, iItem, uLastID, (DWORD)(pMvaCur-pMvaBase), uOffset ));
 
 						pMvaCur = pMvaBase+uOffset;
@@ -5007,7 +5007,7 @@
 
 					if ( pMvaCur+uValues-1>=pMvaMax )
 					{
-						LOC_FAIL(( fp, "MVA count out of bounds (segment=%d, row=%u, mvaattr=%d, docid="DOCID_FMT", count=%u)",
+						LOC_FAIL(( fp, "MVA count out of bounds (segment=%d, row=%u, mvaattr=%d, docid=" DOCID_FMT ", count=%u)",
 							iSegment, uRow, iItem, uLastID, uValues ));
 						pMvaCur += uValues;
 						continue;
@@ -5031,7 +5031,7 @@
 
 						if ( iCur<=iPrev )
 						{
-							LOC_FAIL(( fp, "unsorted MVA values (segment=%d, row=%u, mvaattr=%d, docid="DOCID_FMT", val[%u]="INT64_FMT", val[%u]="INT64_FMT")",
+							LOC_FAIL(( fp, "unsorted MVA values (segment=%d, row=%u, mvaattr=%d, docid=" DOCID_FMT ", val[%u]=" INT64_FMT ", val[%u]=" INT64_FMT ")",
 								iSegment, uRow, iItem, uLastID, ( iItem>=iMva64 ? uVal-2 : uVal-1 ), iPrev, uVal, iCur ));
 						}
 
@@ -5055,12 +5055,12 @@
 
 				// check normalized
 				if ( uExp==0 && uMantissa!=0 )
-					LOC_FAIL(( fp, "float attribute value is unnormalized (segment=%d, row=%u, attr=%d, id="DOCID_FMT", raw=0x%x, value=%f)",
+					LOC_FAIL(( fp, "float attribute value is unnormalized (segment=%d, row=%u, attr=%d, id=" DOCID_FMT ", raw=0x%x, value=%f)",
 						iSegment, uRow, iItem, uLastID, uValue, sphDW2F ( uValue ) ));
 
 				// check +-inf
 				if ( uExp==0xff && uMantissa==0 )
-					LOC_FAIL(( fp, "float attribute is infinity (segment=%d, row=%u, attr=%d, id="DOCID_FMT", raw=0x%x, value=%f)",
+					LOC_FAIL(( fp, "float attribute is infinity (segment=%d, row=%u, attr=%d, id=" DOCID_FMT ", raw=0x%x, value=%f)",
 						iSegment, uRow, iItem, uLastID, uValue, sphDW2F ( uValue ) ));
 			}
 
@@ -5075,7 +5075,7 @@
 				const DWORD uOffset = (DWORD)sphGetRowAttr ( pAttrs, dStrItems[iItem] );
 				if ( uOffset>=(DWORD)tSegment.m_dStrings.GetLength() )
 				{
-					LOC_FAIL(( fp, "string offset out of bounds (segment=%d, row=%u, stringattr=%d, docid="DOCID_FMT", index=%u)",
+					LOC_FAIL(( fp, "string offset out of bounds (segment=%d, row=%u, stringattr=%d, docid=" DOCID_FMT ", index=%u)",
 						iSegment, uRow, iItem, uLastID, uOffset ));
 					continue;
 				}
@@ -5084,12 +5084,12 @@
 					continue;
 
 				if ( uLastStrOffset>=uOffset )
-					LOC_FAIL(( fp, "string offset decreased (segment=%d, row=%u, stringattr=%d, docid="DOCID_FMT", offset=%u, last_offset=%u)",
+					LOC_FAIL(( fp, "string offset decreased (segment=%d, row=%u, stringattr=%d, docid=" DOCID_FMT ", offset=%u, last_offset=%u)",
 						iSegment, uRow, iItem, uLastID, uOffset, uLastStrOffset ));
 
 				if ( !dStringOffsets.BinarySearch ( uOffset ) )
 				{
-					LOC_FAIL(( fp, "string offset is not a string start (segment=%d, row=%u, stringattr=%d, docid="DOCID_FMT", offset=%u)",
+					LOC_FAIL(( fp, "string offset is not a string start (segment=%d, row=%u, stringattr=%d, docid=" DOCID_FMT ", offset=%u)",
 						iSegment, uRow, iItem, uLastID, uOffset ));
 				} else
 					nUsedStrings++;
@@ -5124,7 +5124,7 @@
 				const DWORD uOffset = (DWORD)sphGetRowAttr ( pAttrs, dJsonItems[iItem] );
 				if ( uOffset>=(DWORD)tSegment.m_dStrings.GetLength() )
 				{
-					LOC_FAIL(( fp, "string(JSON) offset out of bounds (segment=%d, row=%u, stringattr=%d, docid="DOCID_FMT", index=%u)",
+					LOC_FAIL(( fp, "string(JSON) offset out of bounds (segment=%d, row=%u, stringattr=%d, docid=" DOCID_FMT ", index=%u)",
 						iSegment, uRow, iItem, uLastID, uOffset ));
 					continue;
 				}
@@ -5133,12 +5133,12 @@
 					continue;
 
 				if ( uLastStrOffset>=uOffset )
-					LOC_FAIL(( fp, "string(JSON) offset decreased (segment=%d, row=%u, stringattr=%d, docid="DOCID_FMT", offset=%u, last_offset=%u)",
+					LOC_FAIL(( fp, "string(JSON) offset decreased (segment=%d, row=%u, stringattr=%d, docid=" DOCID_FMT ", offset=%u, last_offset=%u)",
 						iSegment, uRow, iItem, uLastID, uOffset, uLastStrOffset ));
 
 				if ( !dStringOffsets.BinarySearch ( uOffset ) )
 				{
-					LOC_FAIL(( fp, "string(JSON) offset is not a string start (segment=%d, row=%u, stringattr=%d, docid="DOCID_FMT", offset=%u)",
+					LOC_FAIL(( fp, "string(JSON) offset is not a string start (segment=%d, row=%u, stringattr=%d, docid=" DOCID_FMT ", offset=%u)",
 						iSegment, uRow, iItem, uLastID, uOffset ));
 				} else
 					nUsedJsons++;
@@ -7460,7 +7460,7 @@
 	DWORD uRef = CSphAutoreader::GetDword();
 	m_uCRC = ~m_uCRC;
 	if ( uRef!=m_uCRC )
-		sphWarning ( "binlog: %s: CRC mismatch (index=%s, tid="INT64_FMT", pos="INT64_FMT")", sOp, sIndexName ? sIndexName : "", iTid, iTxnPos );
+		sphWarning ( "binlog: %s: CRC mismatch (index=%s, tid=" INT64_FMT ", pos=" INT64_FMT ")", sOp, sIndexName ? sIndexName : "", iTid, iTxnPos );
 	return uRef==m_uCRC;
 }
 
@@ -7625,7 +7625,7 @@
 void RtBinlog_c::NotifyIndexFlush ( const char * sIndexName, int64_t iTID, bool bShutdown )
 {
 	if ( m_bReplayMode )
-		sphInfo ( "index '%s': ramchunk saved. TID="INT64_FMT"", sIndexName, iTID );
+		sphInfo ( "index '%s': ramchunk saved. TID=" INT64_FMT "", sIndexName, iTID );
 
 	if ( m_bReplayMode || m_bDisabled )
 		return;
@@ -8099,7 +8099,7 @@
 		iPos = tReader.GetPos();
 		if ( tReader.GetDword()!=BLOP_MAGIC )
 		{
-			sphDie ( "binlog: log missing txn marker at pos="INT64_FMT" (corrupted?)", iPos );
+			sphDie ( "binlog: log missing txn marker at pos=" INT64_FMT " (corrupted?)", iPos );
 			break;
 		}
 
@@ -8107,7 +8107,7 @@
 		const uint64_t uOp = tReader.UnzipValue ();
 
 		if ( uOp<=0 || uOp>=BLOP_TOTAL )
-			sphDie ( "binlog: unexpected entry (blop="UINT64_FMT", pos="INT64_FMT")", uOp, iPos );
+			sphDie ( "binlog: unexpected entry (blop=" UINT64_FMT ", pos=" INT64_FMT ")", uOp, iPos );
 
 		// FIXME! blop might be OK but skipped (eg. index that is no longer)
 		switch ( uOp )
@@ -8142,10 +8142,10 @@
 	tmReplay = sphMicroTimer() - tmReplay;
 
 	if ( tReader.GetErrorFlag() )
-		sphWarning ( "binlog: log io error at pos="INT64_FMT": %s", iPos, sError.cstr() );
+		sphWarning ( "binlog: log io error at pos=" INT64_FMT ": %s", iPos, sError.cstr() );
 
 	if ( !bReplayOK )
-		sphWarning ( "binlog: replay error at pos="INT64_FMT")", iPos );
+		sphWarning ( "binlog: replay error at pos=" INT64_FMT ")", iPos );
 
 	// show additional replay statistics
 	ARRAY_FOREACH ( i, tLog.m_dIndexInfos )
@@ -8153,17 +8153,17 @@
 		const BinlogIndexInfo_t & tIndex = tLog.m_dIndexInfos[i];
 		if ( !hIndexes ( tIndex.m_sName.cstr() ) )
 		{
-			sphWarning ( "binlog: index %s: missing; tids "INT64_FMT" to "INT64_FMT" skipped!",
+			sphWarning ( "binlog: index %s: missing; tids " INT64_FMT " to " INT64_FMT " skipped!",
 				tIndex.m_sName.cstr(), tIndex.m_iMinTID, tIndex.m_iMaxTID );
 
 		} else if ( tIndex.m_iPreReplayTID < tIndex.m_iMaxTID )
 		{
-			sphInfo ( "binlog: index %s: recovered from tid "INT64_FMT" to tid "INT64_FMT,
+			sphInfo ( "binlog: index %s: recovered from tid " INT64_FMT " to tid " INT64_FMT,
 				tIndex.m_sName.cstr(), tIndex.m_iPreReplayTID, tIndex.m_iMaxTID );
 
 		} else
 		{
-			sphInfo ( "binlog: index %s: skipped at tid "INT64_FMT" and max binlog tid "INT64_FMT,
+			sphInfo ( "binlog: index %s: skipped at tid " INT64_FMT " and max binlog tid " INT64_FMT,
 				tIndex.m_sName.cstr(), tIndex.m_iPreReplayTID, tIndex.m_iMaxTID );
 		}
 	}
@@ -8188,7 +8188,7 @@
 	const int iVal = (int)tReader.UnzipValue();
 
 	if ( iVal<0 || iVal>=tLog.m_dIndexInfos.GetLength() )
-		sphDie ( "binlog: %s: unexpected index id (id=%d, max=%d, pos="INT64_FMT")",
+		sphDie ( "binlog: %s: unexpected index id (id=%d, max=%d, pos=" INT64_FMT ")",
 			sPlace, iVal, tLog.m_dIndexInfos.GetLength(), iTxnPos );
 
 	return tLog.m_dIndexInfos[iVal];
@@ -8238,18 +8238,18 @@
 
 	// check TID
 	if ( iTID<tIndex.m_iMaxTID )
-		sphDie ( "binlog: commit: descending tid (index=%s, lasttid="INT64_FMT", logtid="INT64_FMT", pos="INT64_FMT")",
+		sphDie ( "binlog: commit: descending tid (index=%s, lasttid=" INT64_FMT ", logtid=" INT64_FMT ", pos=" INT64_FMT ")",
 			tIndex.m_sName.cstr(), tIndex.m_iMaxTID, iTID, iTxnPos );
 
 	// check timestamp
 	if ( tmStamp<tIndex.m_tmMax )
 	{
 		if (!( uReplayFlags & SPH_REPLAY_ACCEPT_DESC_TIMESTAMP ))
-			sphDie ( "binlog: commit: descending time (index=%s, lasttime="INT64_FMT", logtime="INT64_FMT", pos="INT64_FMT")",
+			sphDie ( "binlog: commit: descending time (index=%s, lasttime=" INT64_FMT ", logtime=" INT64_FMT ", pos=" INT64_FMT ")",
 				tIndex.m_sName.cstr(), tIndex.m_tmMax, tmStamp, iTxnPos );
 
 		sphWarning ( "binlog: commit: replaying txn despite descending time "
-			"(index=%s, logtid="INT64_FMT", lasttime="INT64_FMT", logtime="INT64_FMT", pos="INT64_FMT")",
+			"(index=%s, logtid=" INT64_FMT ", lasttime=" INT64_FMT ", logtime=" INT64_FMT ", pos=" INT64_FMT ")",
 			tIndex.m_sName.cstr(), iTID, tIndex.m_tmMax, tmStamp, iTxnPos );
 		tIndex.m_tmMax = tmStamp;
 	}
@@ -8260,7 +8260,7 @@
 		// we normally expect per-index TIDs to be sequential
 		// but let's be graceful about that
 		if ( iTID!=tIndex.m_pRT->m_iTID+1 )
-			sphWarning ( "binlog: commit: unexpected tid (index=%s, indextid="INT64_FMT", logtid="INT64_FMT", pos="INT64_FMT")",
+			sphWarning ( "binlog: commit: unexpected tid (index=%s, indextid=" INT64_FMT ", logtid=" INT64_FMT ", pos=" INT64_FMT ")",
 				tIndex.m_sName.cstr(), tIndex.m_pRT->m_iTID, iTID, iTxnPos );
 
 		// in case dict=keywords
@@ -8295,7 +8295,7 @@
 
 	uint64_t uVal = tReader.UnzipValue();
 	if ( (int)uVal!=tLog.m_dIndexInfos.GetLength() )
-		sphDie ( "binlog: indexadd: unexpected index id (id="UINT64_FMT", expected=%d, pos="INT64_FMT")",
+		sphDie ( "binlog: indexadd: unexpected index id (id=" UINT64_FMT ", expected=%d, pos=" INT64_FMT ")",
 			uVal, tLog.m_dIndexInfos.GetLength(), iTxnPos );
 
 	// load data
@@ -8311,7 +8311,7 @@
 	// check for index name dupes
 	ARRAY_FOREACH ( i, tLog.m_dIndexInfos )
 		if ( tLog.m_dIndexInfos[i].m_sName==sName )
-			sphDie ( "binlog: duplicate index name (name=%s, dupeid=%d, pos="INT64_FMT")",
+			sphDie ( "binlog: duplicate index name (name=%s, dupeid=%d, pos=" INT64_FMT ")",
 				sName.cstr(), i, iTxnPos );
 
 	// not a dupe, lets add
@@ -8366,10 +8366,10 @@
 
 	// check TID, time order in log
 	if ( iTID<tIndex.m_iMaxTID )
-		sphDie ( "binlog: update: descending tid (index=%s, lasttid="INT64_FMT", logtid="INT64_FMT", pos="INT64_FMT")",
+		sphDie ( "binlog: update: descending tid (index=%s, lasttid=" INT64_FMT ", logtid=" INT64_FMT ", pos=" INT64_FMT ")",
 			tIndex.m_sName.cstr(), tIndex.m_iMaxTID, iTID, iTxnPos );
 	if ( tmStamp<tIndex.m_tmMax )
-		sphDie ( "binlog: update: descending time (index=%s, lasttime="INT64_FMT", logtime="INT64_FMT", pos="INT64_FMT")",
+		sphDie ( "binlog: update: descending time (index=%s, lasttime=" INT64_FMT ", logtime=" INT64_FMT ", pos=" INT64_FMT ")",
 			tIndex.m_sName.cstr(), tIndex.m_tmMax, tmStamp, iTxnPos );
 
 	if ( tIndex.m_pIndex && iTID > tIndex.m_pIndex->m_iTID )
@@ -8377,7 +8377,7 @@
 		// we normally expect per-index TIDs to be sequential
 		// but let's be graceful about that
 		if ( iTID!=tIndex.m_pIndex->m_iTID+1 )
-			sphWarning ( "binlog: update: unexpected tid (index=%s, indextid="INT64_FMT", logtid="INT64_FMT", pos="INT64_FMT")",
+			sphWarning ( "binlog: update: unexpected tid (index=%s, indextid=" INT64_FMT ", logtid=" INT64_FMT ", pos=" INT64_FMT ")",
 				tIndex.m_sName.cstr(), tIndex.m_pIndex->m_iTID, iTID, iTxnPos );
 
 		tUpd.m_dRows.Resize ( tUpd.m_dDocids.GetLength() );
@@ -8445,7 +8445,7 @@
 		if ( tCache.m_iMinTID!=tIndex.m_iMinTID || tCache.m_iMaxTID!=tIndex.m_iMaxTID )
 		{
 			sphWarning ( "binlog: cache mismatch: index %s tid ranges mismatch "
-				"(cached "INT64_FMT" to "INT64_FMT", replayed "INT64_FMT" to "INT64_FMT")",
+				"(cached " INT64_FMT " to " INT64_FMT ", replayed " INT64_FMT " to " INT64_FMT ")",
 				tCache.m_sName.cstr(),
 				tCache.m_iMinTID, tCache.m_iMaxTID, tIndex.m_iMinTID, tIndex.m_iMaxTID );
 		}
