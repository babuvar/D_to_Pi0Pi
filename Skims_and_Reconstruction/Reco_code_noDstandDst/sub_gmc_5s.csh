#! /bin/tcsh -f

#setenv Stream 0
#setenv Stream 1
#foreach Stream (0 1 2 3 4 5)
#foreach Stream (0 1)

#foreach Type (charm uds bsbs nonbsbs)
foreach Stream (0)
foreach Type (charm) 


bsub -q s ./script_MC_5s.csh 	1013	1026	43	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1028	1034	43	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1	22	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	23	33	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	34	41	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	45	61	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	62	68	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	69	81	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	82	97	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	98	110	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	113	127	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	128	141	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	142	161	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	162	169	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	170	187	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	190	198	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	199	206	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	208	212	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	213	220	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	221	235	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	241	272	53	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	98	115	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	117	148	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	149	167	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	168	190	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	191	224	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	225	251	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	252	272	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	273	299	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	300	321	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	322	340	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	341	371	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	372	391	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	394	408	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	409	419	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	420	431	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	432	441	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	456	483	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	484	488	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	493	507	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	508	571	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	572	591	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	592	602	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	603	663	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	664	678	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	679	686	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	688	696	67	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	12	122	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	124	189	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	191	234	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	236	274	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	275	305	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	308	333	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	334	356	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	358	385	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	387	405	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	407	424	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	425	440	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	442	466	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	467	494	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	496	507	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	509	531	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	532	541	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	542	554	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	556	599	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	600	621	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	623	636	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	637	649	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	652	683	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	684	697	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	698	710	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	711	733	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	734	756	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	757	790	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	791	819	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	892	909	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	913	933	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	934	964	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	965	980	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	981	988	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	989	1004	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1005	1020	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1022	1039	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1040	1083	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1085	1109	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1116	1122	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1125	1130	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1131	1156	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1157	1191	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1193	1211	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1212	1221	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1222	1283	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	1289	1309	69	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	27	49	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	50	68	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	69	94	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	95	113	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	114	137	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	138	171	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	172	204	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	205	221	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2001	2028	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2029	2041	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2042	2050	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2051	2065	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2076	2083	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2086	2099	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2100	2113	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2114	2126	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2127	2143	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2144	2161	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2162	2194	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2195	2207	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2211	2232	71	$Type 	 $Stream
bsub -q s ./script_MC_5s.csh 	2233	2244	71	$Type 	 $Stream

end

end
