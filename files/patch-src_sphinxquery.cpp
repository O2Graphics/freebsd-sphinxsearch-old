--- src/sphinxquery.cpp.orig	2018-09-23 01:06:50.823532000 +0200
+++ src/sphinxquery.cpp	2018-09-23 01:07:13.038217000 +0200
@@ -3728,18 +3728,18 @@
 	m_hSimilar.IterateStart();
 	while ( m_hSimilar.IterateNext() )
 	{
-		printf ( "\nnode: hash 0x"UINT64_FMT"\n", m_hSimilar.IterateGetKey() );
+		printf ( "\nnode: hash 0x" UINT64_FMT "\n", m_hSimilar.IterateGetKey() );
 		m_hSimilar.IterateGet().IterateStart();
 		while ( m_hSimilar.IterateGet().IterateNext() )
 		{
 			CSphVector<XQNode_t *> & dNodes = m_hSimilar.IterateGet().IterateGet();
-			printf ( "\tgrand: hash 0x"UINT64_FMT", children %d\n", m_hSimilar.IterateGet().IterateGetKey(), dNodes.GetLength() );
+			printf ( "\tgrand: hash 0x" UINT64_FMT ", children %d\n", m_hSimilar.IterateGet().IterateGetKey(), dNodes.GetLength() );
 
 			printf ( "\tparents:\n" );
 			ARRAY_FOREACH ( i, dNodes )
 			{
 				uint64_t uParentHash = dNodes[i]->GetHash();
-				printf ( "\t\thash 0x"UINT64_FMT"\n", uParentHash );
+				printf ( "\t\thash 0x" UINT64_FMT "\n", uParentHash );
 			}
 		}
 	}
