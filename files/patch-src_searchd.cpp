--- src/searchd.cpp.orig	2018-09-23 00:51:34.714837000 +0200
+++ src/searchd.cpp	2018-09-23 00:53:18.498662000 +0200
@@ -3707,7 +3707,7 @@
 		// only one node with lowest error rating. Return it.
 		if ( !dCandidates.GetLength() )
 		{
-			sphLogDebug ( "HA selected %d node with best num of errors a row ("INT64_FMT")", iBestAgent, iErrARow );
+			sphLogDebug ( "HA selected %d node with best num of errors a row (" INT64_FMT ")", iBestAgent, iErrARow );
 			return &m_dAgents[iBestAgent];
 		}
 
@@ -3720,7 +3720,7 @@
 		{
 			const HostDashboard_t & dDash = GetCommonStat ( iBestAgent );
 			fAge = ( dDash.m_iLastAnswerTime-dDash.m_iLastQueryTime ) / 1000.0f;
-			sLogStr = "HA selected %d node by weighted random, with best EaR ("INT64_FMT"), last answered in %f milliseconds";
+			sLogStr = "HA selected %d node by weighted random, with best EaR (" INT64_FMT "), last answered in %f milliseconds";
 		}
 
 		sphLogDebug ( sLogStr, iBestAgent, iErrARow, fAge );
@@ -6724,7 +6724,7 @@
 	// [matchmode/numfilters/sortmode matches (offset,limit)
 	static const char * sModes [ SPH_MATCH_TOTAL ] = { "all", "any", "phr", "bool", "ext", "scan", "ext2" };
 	static const char * sSort [ SPH_SORT_TOTAL ] = { "rel", "attr-", "attr+", "tsegs", "ext", "expr" };
-	tBuf.Appendf ( " [%s/%d/%s "INT64_FMT" (%d,%d)",
+	tBuf.Appendf ( " [%s/%d/%s " INT64_FMT " (%d,%d)",
 		sModes [ tQuery.m_eMode ], tQuery.m_dFilters.GetLength(), sSort [ tQuery.m_eSort ],
 		tRes.m_iTotalMatches, tQuery.m_iOffset, tQuery.m_iLimit );
 
@@ -6834,10 +6834,10 @@
 	tBuf += sTimeBuf;
 
 	if ( tRes.m_iMultiplier>1 )
-		tBuf.Appendf ( " conn %d real %d.%03d wall %d.%03d x%d found "INT64_FMT" *""/ ",
+		tBuf.Appendf ( " conn %d real %d.%03d wall %d.%03d x%d found " INT64_FMT " *""/ ",
 			iCid, iRealTime/1000, iRealTime%1000, iQueryTime/1000, iQueryTime%1000, tRes.m_iMultiplier, tRes.m_iTotalMatches );
 	else
-		tBuf.Appendf ( " conn %d real %d.%03d wall %d.%03d found "INT64_FMT" *""/ ",
+		tBuf.Appendf ( " conn %d real %d.%03d wall %d.%03d found " INT64_FMT " *""/ ",
 			iCid, iRealTime/1000, iRealTime%1000, iQueryTime/1000, iQueryTime%1000, tRes.m_iTotalMatches );
 
 	///////////////////////////////////
@@ -6878,9 +6878,9 @@
 					if ( f.m_dValues.GetLength()==1 )
 					{
 						if ( f.m_bExclude )
-							tBuf.Appendf ( " %s!="INT64_FMT, f.m_sAttrName.cstr(), (int64_t)f.m_dValues[0] );
+							tBuf.Appendf ( " %s!=" INT64_FMT, f.m_sAttrName.cstr(), (int64_t)f.m_dValues[0] );
 						else
-							tBuf.Appendf ( " %s="INT64_FMT, f.m_sAttrName.cstr(), (int64_t)f.m_dValues[0] );
+							tBuf.Appendf ( " %s=" INT64_FMT, f.m_sAttrName.cstr(), (int64_t)f.m_dValues[0] );
 					} else
 					{
 						if ( f.m_bExclude )
@@ -6891,7 +6891,7 @@
 						ARRAY_FOREACH ( j, f.m_dValues )
 						{
 							if ( j )
-								tBuf.Appendf ( ","INT64_FMT, (int64_t)f.m_dValues[j] );
+								tBuf.Appendf ( "," INT64_FMT, (int64_t)f.m_dValues[j] );
 							else
 								tBuf.Appendf ( INT64_FMT, (int64_t)f.m_dValues[j] );
 						}
@@ -6904,17 +6904,17 @@
 					{
 						// no min, thus (attr<maxval)
 						const char * sOps[2][2] = { { "<", "<=" }, { ">=", ">" } };
-						tBuf.Appendf ( " %s%s"INT64_FMT, f.m_sAttrName.cstr(),
+						tBuf.Appendf ( " %s%s" INT64_FMT, f.m_sAttrName.cstr(),
 							sOps [ f.m_bExclude ][ f.m_bHasEqual ], f.m_iMaxValue );
 					} else if ( f.m_iMaxValue==INT64_MAX || ( f.m_iMaxValue==-1 && f.m_sAttrName=="@id" ) )
 					{
 						// mo max, thus (attr>minval)
 						const char * sOps[2][2] = { { ">", ">=" }, { "<", "<=" } };
-						tBuf.Appendf ( " %s%s"INT64_FMT, f.m_sAttrName.cstr(),
+						tBuf.Appendf ( " %s%s" INT64_FMT, f.m_sAttrName.cstr(),
 							sOps [ f.m_bExclude ][ f.m_bHasEqual ], f.m_iMinValue );
 					} else
 					{
-						tBuf.Appendf ( " %s%s BETWEEN "INT64_FMT" AND "INT64_FMT,
+						tBuf.Appendf ( " %s%s BETWEEN " INT64_FMT " AND " INT64_FMT,
 							f.m_sAttrName.cstr(), f.m_bExclude ? " NOT" : "",
 							f.m_iMinValue + !f.m_bHasEqual, f.m_iMaxValue - !f.m_bHasEqual );
 					}
@@ -13244,7 +13244,7 @@
 	DWORD uServer = htonl ( SPHINX_SEARCHD_PROTO );
 	if ( sphSockSend ( iSock, (char*)&uServer, sizeof(DWORD) )!=sizeof(DWORD) )
 	{
-		sphWarning ( "failed to send server version (client=%s("INT64_FMT"))", sClientIP, iCID );
+		sphWarning ( "failed to send server version (client=%s(" INT64_FMT "))", sClientIP, iCID );
 		return;
 	}
 
@@ -13252,10 +13252,10 @@
 	tBuf.ReadFrom ( 4 ); // FIXME! magic
 	int iMagic = tBuf.GetInt (); // client version is for now unused
 
-	sphLogDebugv ( "conn %s("INT64_FMT"): got handshake, major v.%d, err %d", sClientIP, iCID, iMagic, (int)tBuf.GetError() );
+	sphLogDebugv ( "conn %s(" INT64_FMT "): got handshake, major v.%d, err %d", sClientIP, iCID, iMagic, (int)tBuf.GetError() );
 	if ( tBuf.GetError() )
 	{
-		sphLogDebugv ( "conn %s("INT64_FMT"): exiting on handshake error", sClientIP, iCID );
+		sphLogDebugv ( "conn %s(" INT64_FMT "): exiting on handshake error", sClientIP, iCID );
 		return;
 	}
 
@@ -13274,14 +13274,14 @@
 		// on SIGTERM, bail unconditionally and immediately, at all times
 		if ( !bCommand && g_bGotSigterm )
 		{
-			sphLogDebugv ( "conn %s("INT64_FMT"): bailing on SIGTERM", sClientIP, iCID );
+			sphLogDebugv ( "conn %s(" INT64_FMT "): bailing on SIGTERM", sClientIP, iCID );
 			break;
 		}
 
 		// on SIGHUP vs pconn, bail if a pconn was idle for 1 sec
 		if ( bPersist && !bCommand && g_bGotSighup && sphSockPeekErrno()==ETIMEDOUT )
 		{
-			sphLogDebugv ( "conn %s("INT64_FMT"): bailing idle pconn on SIGHUP", sClientIP, iCID );
+			sphLogDebugv ( "conn %s(" INT64_FMT "): bailing idle pconn on SIGHUP", sClientIP, iCID );
 			break;
 		}
 
@@ -13291,7 +13291,7 @@
 			iPconnIdle += iTimeout;
 			if ( iPconnIdle>=g_iClientTimeout )
 			{
-				sphLogDebugv ( "conn %s("INT64_FMT"): bailing idle pconn on client_timeout", sClientIP, iCID );
+				sphLogDebugv ( "conn %s(" INT64_FMT "): bailing idle pconn on client_timeout", sClientIP, iCID );
 				break;
 			}
 			continue;
@@ -13314,7 +13314,7 @@
 			// lets avoid agent log flood
 			//
 			// sphWarning ( "failed to receive client version and request (client=%s, error=%s)", sClientIP, sphSockError() );
-			sphLogDebugv ( "conn %s("INT64_FMT"): bailing on failed request header (sockerr=%s)", sClientIP, iCID, sphSockError() );
+			sphLogDebugv ( "conn %s(" INT64_FMT "): bailing on failed request header (sockerr=%s)", sClientIP, iCID, sphSockError() );
 			return;
 		}
 
@@ -13343,7 +13343,7 @@
 		assert ( iLength>=0 && iLength<=g_iMaxPacketSize );
 		if ( iLength && !tBuf.ReadFrom ( iLength ) )
 		{
-			sphWarning ( "failed to receive client request body (client=%s("INT64_FMT"), exp=%d, error='%s')",
+			sphWarning ( "failed to receive client request body (client=%s(" INT64_FMT "), exp=%d, error='%s')",
 				sClientIP, iCID, iLength, sphSockError() );
 			return;
 		}
@@ -13364,7 +13364,7 @@
 			pThd->m_sCommand = g_dApiCommands[iCommand];
 		THD_STATE ( THD_QUERY );
 
-		sphLogDebugv ( "conn %s("INT64_FMT"): got command %d, handling", sClientIP, iCID, iCommand );
+		sphLogDebugv ( "conn %s(" INT64_FMT "): got command %d, handling", sClientIP, iCID, iCommand );
 		switch ( iCommand )
 		{
 			case SEARCHD_COMMAND_SEARCH:	HandleCommandSearch ( iSock, iCommandVer, tBuf ); break;
@@ -13374,7 +13374,7 @@
 			case SEARCHD_COMMAND_PERSIST:
 				bPersist = ( tBuf.GetInt()!=0 );
 				iTimeout = 1;
-				sphLogDebugv ( "conn %s("INT64_FMT"): pconn is now %s", sClientIP, iCID, bPersist ? "on" : "off" );
+				sphLogDebugv ( "conn %s(" INT64_FMT "): pconn is now %s", sClientIP, iCID, bPersist ? "on" : "off" );
 				break;
 			case SEARCHD_COMMAND_STATUS:	HandleCommandStatus ( iSock, iCommandVer, tBuf ); break;
 			case SEARCHD_COMMAND_FLUSHATTRS:HandleCommandFlush ( iSock, iCommandVer, tBuf ); break;
@@ -13387,7 +13387,7 @@
 		SphCrashLogger_c::SetLastQuery ( CrashQuery_t() );
 	} while ( bPersist );
 
-	sphLogDebugv ( "conn %s("INT64_FMT"): exiting", sClientIP, iCID );
+	sphLogDebugv ( "conn %s(" INT64_FMT "): exiting", sClientIP, iCID );
 }
 
 //////////////////////////////////////////////////////////////////////////
@@ -16364,7 +16364,7 @@
 	if ( sphSockSend ( iSock, g_sMysqlHandshake, g_iMysqlHandshake )!=g_iMysqlHandshake )
 	{
 		int iErrno = sphSockGetErrno ();
-		sphWarning ( "failed to send server version (client=%s("INT64_FMT"), error: %d '%s')", sClientIP, iCID, iErrno, sphSockError ( iErrno ) );
+		sphWarning ( "failed to send server version (client=%s(" INT64_FMT "), error: %d '%s')", sClientIP, iCID, iErrno, sphSockError ( iErrno ) );
 		return;
 	}
 
@@ -16387,7 +16387,7 @@
 		THD_STATE ( THD_NET_READ );
 		if ( !tIn.ReadFrom ( 4, INTERACTIVE_TIMEOUT, true ) )
 		{
-			sphLogDebugv ( "conn %s("INT64_FMT"): bailing on failed MySQL header (sockerr=%s)", sClientIP, iCID, sphSockError() );
+			sphLogDebugv ( "conn %s(" INT64_FMT "): bailing on failed MySQL header (sockerr=%s)", sClientIP, iCID, sphSockError() );
 			break;
 		}
 
@@ -16406,7 +16406,7 @@
 		int iPacketLen = ( uPacketHeader & MAX_PACKET_LEN );
 		if ( !tIn.ReadFrom ( iPacketLen, INTERACTIVE_TIMEOUT, true ) )
 		{
-			sphWarning ( "failed to receive MySQL request body (client=%s("INT64_FMT"), exp=%d, error='%s')",
+			sphWarning ( "failed to receive MySQL request body (client=%s(" INT64_FMT "), exp=%d, error='%s')",
 				sClientIP, iCID, iPacketLen, sphSockError() );
 			break;
 		}
@@ -16426,7 +16426,7 @@
 			{
 				if ( !tIn2.ReadFrom ( 4, INTERACTIVE_TIMEOUT, true ) )
 				{
-					sphLogDebugv ( "conn %s("INT64_FMT"): bailing on failed MySQL header2 (sockerr=%s)",
+					sphLogDebugv ( "conn %s(" INT64_FMT "): bailing on failed MySQL header2 (sockerr=%s)",
 						sClientIP, iCID, sphSockError() );
 					break;
 				}
@@ -16436,7 +16436,7 @@
 				iAddonLen = ( uAddon & MAX_PACKET_LEN );
 				if ( !tIn.ReadFrom ( iAddonLen, INTERACTIVE_TIMEOUT, true, true ) )
 				{
-					sphWarning ( "failed to receive MySQL request body2 (client=%s("INT64_FMT"), exp=%d, error='%s')",
+					sphWarning ( "failed to receive MySQL request body2 (client=%s(" INT64_FMT "), exp=%d, error='%s')",
 						sClientIP, iCID, iAddonLen, sphSockError() );
 					iAddonLen = -1;
 					break;
@@ -17384,10 +17384,10 @@
 		ARRAY_FOREACH_COND ( i, dUservars, tmLast==g_tmSphinxqlState )
 		{
 			const CSphVector<SphAttr_t> & dVals = *dUservars[i].m_pVal;
-			int iLen = snprintf ( dBuf, sizeof ( dBuf ), "SET GLOBAL %s = ( "INT64_FMT, dUservars[i].m_sName.cstr(), dVals[0] );
+			int iLen = snprintf ( dBuf, sizeof ( dBuf ), "SET GLOBAL %s = ( " INT64_FMT, dUservars[i].m_sName.cstr(), dVals[0] );
 			for ( int j=1; j<dVals.GetLength(); j++ )
 			{
-				iLen += snprintf ( dBuf+iLen, sizeof ( dBuf ), ", "INT64_FMT, dVals[j] );
+				iLen += snprintf ( dBuf+iLen, sizeof ( dBuf ), ", " INT64_FMT, dVals[j] );
 
 				if ( iLen>=iMaxString && j<dVals.GetLength()-1 )
 				{
