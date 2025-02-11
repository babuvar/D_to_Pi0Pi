#! /bin/tcsh -f


setenv Stream 10
#setenv Stream 11

foreach Type (charged mixed charm uds)

#                                  run_start   r_end  exp      
bsub -q s ./script_MC.csh 	6	872	7	$Type 	 $Stream
bsub -q s ./script_MC.csh 	873	1246	7	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1248	1486	7	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1538	1920	7	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1921	2156	7	$Type 	 $Stream
bsub -q s ./script_MC.csh 	2294	2865	7	$Type 	 $Stream
bsub -q s ./script_MC.csh 	17	458	9	$Type 	 $Stream
bsub -q s ./script_MC.csh 	459	686	9	$Type 	 $Stream
bsub -q s ./script_MC.csh 	687	972	9	$Type 	 $Stream
bsub -q s ./script_MC.csh 	973	1220	9	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1	161	11	$Type 	 $Stream
bsub -q s ./script_MC.csh 	261	422	11	$Type 	 $Stream
bsub -q s ./script_MC.csh 	423	575	11	$Type 	 $Stream
bsub -q s ./script_MC.csh 	576	760	11	$Type 	 $Stream
bsub -q s ./script_MC.csh 	761	889	11	$Type 	 $Stream
bsub -q s ./script_MC.csh 	890	1017	11	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1018	1127	11	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1128	1287	11	$Type 	 $Stream
bsub -q s ./script_MC.csh 	4	178	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	179	354	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	355	440	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	551	696	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	697	841	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	842	959	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	960	1107	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1109	1208	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1209	1334	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1335	1444	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1445	1523	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1589	1627	13	$Type 	 $Stream
bsub -q s ./script_MC.csh 	56	307	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	308	428	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	429	536	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	537	623	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	624	710	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	765	840	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	841	925	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	926	1005	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1008	1096	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1098	1181	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1183	1248	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1315	1387	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1388	1437	15	$Type 	 $Stream
bsub -q s ./script_MC.csh 	2	103	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	169	258	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	259	345	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	347	408	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	409	485	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	545	606	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	607	668	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	669	742	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	743	806	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	807	864	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	865	937	17	$Type 	 $Stream
bsub -q s ./script_MC.csh 	64	115	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	117	168	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	169	226	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	227	287	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	288	352	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	353	411	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	412	464	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	465	512	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	513	561	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	562	626	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	627	666	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	763	821	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	822	879	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	880	952	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	953	1008	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1009	1058	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1059	1124	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1125	1205	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1206	1274	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1276	1331	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1332	1406	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1407	1476	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1477	1531	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1532	1596	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1597	1643	19	$Type 	 $Stream
bsub -q s ./script_MC.csh 	2	96	21	$Type 	 $Stream
bsub -q s ./script_MC.csh 	97	163	21	$Type 	 $Stream
bsub -q s ./script_MC.csh 	164	229	21	$Type 	 $Stream
bsub -q s ./script_MC.csh 	230	324	21	$Type 	 $Stream
bsub -q s ./script_MC.csh 	2	81	23	$Type 	 $Stream
bsub -q s ./script_MC.csh 	82	147	23	$Type 	 $Stream
bsub -q s ./script_MC.csh 	148	238	23	$Type 	 $Stream
bsub -q s ./script_MC.csh 	357	440	23	$Type 	 $Stream
bsub -q s ./script_MC.csh 	446	523	23	$Type 	 $Stream
bsub -q s ./script_MC.csh 	524	607	23	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1	165	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	166	261	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	262	350	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	351	463	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	464	568	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	569	667	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	668	743	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	744	825	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	826	905	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	906	971	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	972	1044	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1045	1120	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1121	1188	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1189	1261	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1262	1338	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1340	1413	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1414	1462	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1601	1658	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1659	1714	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1715	1794	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1796	1860	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1861	1917	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1918	1974	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1975	2029	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	2030	2089	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	2090	2122	25	$Type 	 $Stream
bsub -q s ./script_MC.csh 	3	73	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	74	136	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	137	199	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	200	288	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	367	430	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	431	489	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	490	540	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	541	589	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	590	637	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	638	685	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	686	732	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	733	772	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	773	821	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	822	879	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	880	935	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	936	978	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	979	1028	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1029	1079	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1252	1313	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1314	1360	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1361	1411	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1413	1468	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1469	1516	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1517	1575	27	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1577	1632	27	$Type 	 $Stream

end



setenv Stream 0
#setenv Stream 1

foreach Type (charged mixed charm uds)

bsub -q s ./script_MC.csh 	138	383	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	385	493	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	495	589	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	590	680	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	681	748	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	750	818	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	820	874	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	876	936	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1071	1213	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1214	1300	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1301	1362	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1363	1420	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1421	1463	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1464	1522	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1523	1562	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1563	1623	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1625	1715	31	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1	52	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	53	118	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	119	215	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	222	294	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	295	349	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	350	382	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	383	412	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	413	444	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	445	495	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	625	651	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	652	683	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	684	719	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	720	755	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	756	784	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	785	808	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	809	838	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	839	870	33	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1	35	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	36	80	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	81	115	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	117	176	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	177	208	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	209	255	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	256	284	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	285	323	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	324	351	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	352	394	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	395	433	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	434	483	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	484	510	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	512	543	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	544	584	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	650	687	35	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1	24	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	25	58	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	59	89	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	90	132	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	133	219	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	220	269	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	270	334	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	335	397	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	399	420	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	421	446	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	447	475	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	476	507	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	510	529	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	531	570	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	571	587	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	589	620	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	621	642	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	644	654	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	735	765	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	766	790	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	791	810	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	812	846	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	848	865	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	866	903	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	904	926	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	927	959	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	960	987	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	989	1006	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1007	1027	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1029	1044	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1045	1086	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1087	1131	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1132	1156	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1159	1192	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1193	1215	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1216	1239	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1240	1265	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1266	1280	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1281	1319	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1320	1343	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1345	1374	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1375	1424	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1426	1447	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1448	1471	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1474	1499	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1500	1517	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1518	1531	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1533	1559	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1560	1583	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1665	1689	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1690	1720	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1723	1737	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1738	1753	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1754	1782	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1783	1811	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1812	1831	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1832	1849	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1852	1878	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1880	1913	37	$Type 	 $Stream
bsub -q s ./script_MC.csh 	7	44	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	45	141	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	143	181	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	182	209	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	210	250	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	251	279	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	280	321	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	325	358	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	360	391	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	392	478	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	479	501	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	502	538	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	539	566	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	569	585	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	586	610	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	611	634	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	718	733	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	735	766	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	767	794	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	795	815	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	822	864	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	865	878	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	879	902	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	903	933	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	934	954	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	955	966	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	968	981	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	982	1016	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1018	1030	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1031	1051	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1052	1075	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1076	1090	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1091	1106	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1109	1123	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1124	1144	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1204	1251	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1252	1281	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1283	1314	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1315	1357	39	$Type 	 $Stream
bsub -q s ./script_MC.csh 	4	32	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	33	62	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	64	95	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	96	125	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	129	154	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	155	168	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	169	208	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	209	230	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	232	265	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	266	291	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	292	309	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	310	325	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	326	349	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	352	371	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	372	396	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	397	440	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	441	457	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	458	489	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	490	521	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	522	556	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	557	588	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	589	600	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	601	622	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	623	632	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	633	648	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	650	665	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	666	687	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	689	697	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	753	796	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	799	834	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	836	862	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	864	889	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	892	911	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	912	927	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	928	958	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	959	972	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	973	986	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	987	997	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	998	1009	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1010	1020	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1021	1032	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1034	1049	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1051	1065	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1067	1076	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1080	1091	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1092	1106	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1158	1171	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1173	1186	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1188	1199	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1202	1214	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1215	1223	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1224	1232	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1233	1248	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1249	1255	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1256	1261	41	$Type 	 $Stream
bsub -q s ./script_MC.csh 	3	15	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	16	27	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	28	88	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	89	105	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	106	121	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	124	134	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	135	161	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	162	177	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	178	196	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	197	209	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	210	223	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	224	238	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	239	252	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	253	280	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	281	301	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	302	328	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	329	360	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	361	371	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	372	392	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	395	415	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	416	424	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	426	445	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	446	451	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	452	470	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	471	481	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	482	495	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	496	504	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	505	513	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	514	527	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	528	557	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	605	612	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	613	638	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	641	650	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	652	667	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	668	677	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	678	695	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	696	705	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	706	722	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	724	746	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	747	766	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	767	781	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	782	798	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	800	814	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	815	831	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	833	845	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	846	862	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	864	880	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	881	892	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	893	914	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1102	1121	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1122	1134	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1136	1149	43	$Type 	 $Stream
bsub -q s ./script_MC.csh 	32	115	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	116	167	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	168	183	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	184	215	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	216	299	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	301	317	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	318	324	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	336	350	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	351	360	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	362	372	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	427	438	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	439	450	45	$Type 	 $Stream
bsub -q s ./script_MC.csh 	5	41	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	42	74	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	75	108	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	111	171	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	174	189	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	191	217	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	218	233	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	234	258	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	259	264	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	265	279	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	284	292	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	293	304	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	305	351	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	353	377	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	378	390	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	391	400	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	402	406	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	407	421	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	422	448	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	451	485	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	486	494	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	495	516	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	517	521	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	522	536	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	623	630	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	631	642	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	643	657	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	658	690	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	691	720	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	721	749	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	751	773	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	774	811	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	812	857	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	858	881	47	$Type 	 $Stream
bsub -q s ./script_MC.csh 	13	44	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	47	73	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	74	101	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	102	122	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	123	144	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	145	157	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	158	176	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	178	213	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	214	241	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	242	319	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	321	349	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	350	376	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	378	415	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	416	456	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	458	494	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	495	510	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	512	541	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	707	747	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	748	776	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	777	789	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	790	820	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	821	825	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	826	844	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	846	915	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	916	922	49	$Type 	 $Stream
bsub -q s ./script_MC.csh 	5	56	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	59	111	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	112	155	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	156	206	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	207	235	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	237	267	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	268	307	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	310	368	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	371	461	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	462	515	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	516	555	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	558	606	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	610	654	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	658	694	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	696	798	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	800	924	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	925	1024	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1025	1081	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1086	1112	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1115	1138	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1142	1183	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1184	1203	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1204	1231	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1232	1270	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1271	1310	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1399	1441	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1442	1469	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1471	1500	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1501	1547	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1548	1566	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1567	1579	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1580	1692	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1693	1709	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1710	1724	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1725	1756	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1758	1766	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1767	1777	51	$Type 	 $Stream
bsub -q s ./script_MC.csh 	3	40	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	41	66	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	68	123	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	124	137	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	138	154	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	155	168	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	170	189	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	191	206	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	207	227	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	228	261	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	262	313	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	315	346	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	347	371	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	372	421	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	422	464	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	466	491	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	492	508	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	509	525	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	527	564	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	565	584	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	585	599	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	600	612	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	618	642	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	644	656	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	657	669	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	670	682	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	684	695	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	697	720	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	721	752	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	754	784	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	855	869	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	870	881	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	882	900	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	901	912	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	913	935	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	936	955	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	956	968	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	969	976	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	977	988	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	990	1093	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1096	1136	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1137	1155	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1156	1167	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1169	1184	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1185	1190	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1191	1209	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1211	1222	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1223	1239	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1241	1285	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1286	1298	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1299	1311	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1312	1334	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1335	1345	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1346	1355	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1356	1372	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1373	1416	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1417	1431	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1432	1468	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1470	1489	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1490	1512	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1513	1522	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1523	1530	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1533	1578	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1679	1708	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1709	1726	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1727	1742	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1745	1749	55	$Type 	 $Stream
bsub -q s ./script_MC.csh 	24	128	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	129	195	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	196	224	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	226	253	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	255	355	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	356	391	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	392	418	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	426	448	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	449	480	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	482	505	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	506	528	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	529	534	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	535	552	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	554	574	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	575	606	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	607	633	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	634	664	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	740	772	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	773	807	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	808	831	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	832	869	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	871	898	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	900	952	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	953	985	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	986	1027	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1029	1053	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1054	1071	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1072	1089	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1091	1129	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1130	1147	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1148	1162	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1164	1183	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	1184	1207	61	$Type 	 $Stream
bsub -q s ./script_MC.csh 	55	75	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	76	104	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	105	174	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	175	189	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	190	220	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	221	235	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	236	264	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	265	296	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	300	314	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	315	322	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	323	344	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	345	352	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	354	372	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	375	386	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	387	414	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	415	438	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	439	456	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	457	482	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	483	505	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	506	520	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	521	557	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	558	577	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	578	591	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	592	609	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	610	614	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	683	712	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	713	723	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	724	745	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	746	753	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	754	770	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	771	783	63	$Type 	 $Stream
bsub -q s ./script_MC.csh 	20	79	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	80	89	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	91	106	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	107	119	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	120	152	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	153	250	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	251	274	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	275	294	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	295	305	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	306	317	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	318	331	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	332	343	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	344	351	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	354	365	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	366	423	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	424	432	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	434	446	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	447	458	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	468	480	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	481	496	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	497	506	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	507	518	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	523	530	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	531	541	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	542	556	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	557	572	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	573	586	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	587	600	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	601	613	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	691	723	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	725	739	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	740	773	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	774	789	65	$Type 	 $Stream
bsub -q s ./script_MC.csh 	790	801	65	$Type 	 $Stream

end

