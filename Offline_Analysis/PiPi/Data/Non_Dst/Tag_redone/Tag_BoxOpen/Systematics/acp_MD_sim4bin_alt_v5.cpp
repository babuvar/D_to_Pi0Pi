//Tagged 4-Sim fitting for tagged pipi with new model
// + weights for signal and background

 
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooSimultaneous.h"
#include "RooCategory.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h" 
#include "TPaveLabel.h"
using namespace RooFit;

double low_lim=1.68;
//double low_lim=1.69;
//double low_lim=1.70;
//double low_lim=1.71;
//double low_lim=1.72;

  RooRealVar dzero("dzero","M_{D}  ",low_lim,2.06,"GeV");
  RooDataSet* data_p=new RooDataSet("data_p","data_p",RooArgSet(dzero));
  RooDataSet* data_n=new RooDataSet("data_n","data_n",RooArgSet(dzero));
  RooDataSet* data_p2=new RooDataSet("data_p2","data_p2",RooArgSet(dzero));
  RooDataSet* data_n2=new RooDataSet("data_n2","data_n2",RooArgSet(dzero));



float nsig1=0,nsig2=0,psig1=0,psig2=0;

void acp_MD_sim4bin_alt_v5(void)
{
  //LOAD DATA FILE
  TChain* chain=new TChain("h1");
//  TChain* chain=new TChain("h2");

   chain->Add("../../Root_Files/pipi_dcont.root"); 
  chain->Add("../../Root_Files/pipi_d4s.root"); 
  chain->Add("../../Root_Files/pipi_d5s.root"); 


  Int_t nevt=(int)chain->GetEntries();
  cout<<"nevt\t"<<nevt <<endl;

 Float_t Deltam, f_PD, f_dzero, f_Pizsmass, f_Dstf, f_Egam1s, f_Egam2s, f_Egamma1, f_Egamma2, f_Categ, f_Pizmom, f_Pimom, f_Gam1thet, f_Gam2thet, f_Dcharge, f_Pizmass, f_Df;


  h1->SetBranchAddress("Deltam",&Deltam);
  h1->SetBranchAddress("Pstdst",&f_PD);
  h1->SetBranchAddress("Dmass",&f_dzero);
  h1->SetBranchAddress("Pizsmass",&f_Pizsmass);
  h1->SetBranchAddress("Pizmass",&f_Pizmass);
//  h1->SetBranchAddress("Dstf",&f_Dstf);
  h1->SetBranchAddress("Df",&f_Df);
  h1->SetBranchAddress("Egam1s",&f_Egam1s);
  h1->SetBranchAddress("Egam2s",&f_Egam2s);
  h1->SetBranchAddress("Egamma1",&f_Egamma1);
  h1->SetBranchAddress("Egamma2",&f_Egamma2);
  h1->SetBranchAddress("Categ",&f_Categ);
  h1->SetBranchAddress("Pizmom",&f_Pizmom);
  h1->SetBranchAddress("Pimom",&f_Pimom);
  h1->SetBranchAddress("Gam1hthe",&f_Gam1thet);
  h1->SetBranchAddress("Gam2hthe",&f_Gam2thet);
  h1->SetBranchAddress("Dcharge",&f_Dcharge);



int photon1cutflag=0, photon2cutflag=0, sphoton1cutflag=0, sphoton2cutflag=0;

  Int_t nevt_ac_p(0);
  Int_t nevt_ac_n(0);
  float bin;int bin1; 

int num_pass=0;


//for(int i=0;i<numbins;i++){cout<<"cut["<<i<<"] = "<<cut[i]<<endl;}




  for(int i=0;i<nevt;i++) 
//  for(int i=0;i<5000;i++)
//  for(int i=0;i<10;i++)
    {


      chain->GetEntry(i);
		  dzero.setVal(f_dzero);

if(Deltam > 0.139 && Deltam < 0.142){       //optimized for M_D fitting
if(f_dzero >low_lim  && f_dzero < 2.06){       //~3sigma range to estimate F.O.M.
//if(f_Pizsmass > 0.11  && f_Pizsmass < 0.16){
if(f_Pizsmass > 0.125  && f_Pizsmass < 0.143){
if(f_Pizmass > 0.119  && f_Pizmass < 0.151){
if(f_Pizmom > 1.06 ){
if(f_Pimom > 0.84 ){
//if(f_PD > 2.95){
//if(f_PD > 2.5 && f_PD <= 2.95){
//if(f_PD > 2.1 && f_PD <= 2.5){
//if(f_PD > 2.1 && f_PD <= 2.95){
//if(f_PD > 2.1){

//if(f_Categ == 5){
//if(f_Categ != 5){


//Hard Photon 1
if(f_Gam1thet < -60 && f_Egamma1 > 0.150){photon1cutflag=1;}  //BWD
else if(f_Gam1thet > 73 && f_Egamma1 > 0.100){photon1cutflag=1;}  //FWD
else if(f_Gam1thet > -60 && f_Gam1thet < 73 && f_Egamma1 > 0.050){photon1cutflag=1;}  //BARREL
else{photon1cutflag=0;}

//Hard Photon 2
if(f_Gam2thet < -60 && f_Egamma2 > 0.150){photon2cutflag=1;}  //BWD
else if(f_Gam2thet > 73 && f_Egamma2 > 0.100){photon2cutflag=1;}  //FWD
else if(f_Gam2thet > -60 && f_Gam2thet < 73 && f_Egamma2 > 0.050){photon2cutflag=1;}  //BARREL
else{photon2cutflag=0;}

//Soft Photon 1 
if(f_Categ == 5 && f_Egam1s > 0.046){sphoton1cutflag=1;}
else if(f_Categ == 2 && f_Egam1s > 0.068){sphoton1cutflag=1;}
else if(f_Categ == 6 && f_Egam1s > 0.030){sphoton1cutflag=1;}
else{sphoton1cutflag=0;}

//Soft Photon 2 
if(f_Categ == 5 && f_Egam2s > 0.046){sphoton2cutflag=1;}
else if(f_Categ == 2 && f_Egam2s > 0.036){sphoton2cutflag=1;}
else if(f_Categ == 6 && f_Egam2s > 0.044){sphoton2cutflag=1;}
else{sphoton2cutflag=0;}


//Photon cuts
if(photon1cutflag == 1 && photon2cutflag == 1){
if(sphoton1cutflag == 1 && sphoton2cutflag == 1){



//Optimized P*D* bin
if(f_PD > 2.95){


if(f_Dcharge == 1){data_p->add(RooArgSet(dzero));   }
if(f_Dcharge == -1){data_n->add(RooArgSet(dzero));  }


}


//2nd P*D* bin
if(f_PD > 2.5 && f_PD <= 2.95){

if(f_Dcharge == 1){data_p2->add(RooArgSet(dzero));  }
if(f_Dcharge == -1){data_n2->add(RooArgSet(dzero)); }


}



//cout<<"fabs(f_Pizmass - 0.135) = "<<fabs(f_Pizmass - 0.135)<<endl;
//cout<<"fabs(f_Pizsmass - 0.135) = "<<fabs(f_Pizsmass - 0.135)<<endl;
//cout<<"---------------------------"<<endl;


}}//Photon cuts

}}}}}}//}//}
    }
 




  //DEFINE PDF
//Common
  //____________________________________________________
  RooRealVar Araw("A_{Raw}","Araw",0,-1,1);
  RooRealVar N_t1("N_{Sig1}","N_t1",100,0,150000);
  RooFormulaVar N_n("N_n","(0.5)*(1-A_{Raw})*N_{Sig1}",RooArgList(Araw,N_t1));
  RooFormulaVar N_p("N_p","(0.5)*(1+A_{Raw})*N_{Sig1}",RooArgList(Araw,N_t1));


  RooRealVar N_t2("N_{Sig2}","N_t2",100,0,60000);
  RooFormulaVar N_n2("N_n2","(0.5)*(1-A_{Raw})*N_{Sig2}",RooArgList(Araw,N_t2));
  RooFormulaVar N_p2("N_p2","(0.5)*(1+A_{Raw})*N_{Sig2}",RooArgList(Araw,N_t2));



  RooRealVar Abkg1("A_{Bkg1}","ABkg1",0,-1,1);
  RooRealVar N_tb1("N_{Bkg1}","N_tb1",100,0,10000000);
  RooFormulaVar N_nb("N_nb","(0.5)*(1-A_{Bkg1})*N_{Bkg1}",RooArgList(Abkg1,N_tb1));
  RooFormulaVar N_pb("N_pb","(0.5)*(1+A_{Bkg1})*N_{Bkg1}",RooArgList(Abkg1,N_tb1));

  RooRealVar Abkg2("A_{Bkg2}","ABkg2",0,-1,1);
  RooRealVar N_tb2("N_{Bkg2}","N_tb2",100,0,10000000);
  RooFormulaVar N_nb2("N_nb2","(0.5)*(1-A_{Bkg2})*N_{Bkg2}",RooArgList(Abkg2,N_tb2));
  RooFormulaVar N_pb2("N_pb2","(0.5)*(1+A_{Bkg2})*N_{Bkg2}",RooArgList(Abkg2,N_tb2));



  //_____________________________________________________


//Common Pars
 
  RooRealVar m_dif1("m_{shift(CB2,CB1)}","m_dif1",0.00073);
//  RooRealVar m_dif1("m_{shift(CB2,CB1)}","m_dif1",0.00073+0.00028);
//  RooRealVar m_dif1("m_{shift(CB2,CB1)}","m_dif1",0.00073-0.00028);
  RooRealVar m_dif2("m_{shift(Gaus1,CB1)}","m_dif2",0.0188);
//  RooRealVar m_dif2("m_{shift(Gaus1,CB1)}","m_dif2",0.0188+0.0086);
//  RooRealVar m_dif2("m_{shift(Gaus1,CB1)}","m_dif2",0.0188-0.0086);
  RooRealVar m_dif3("m_{shift(Gaus2,CB1)}","m_dif3",0.022);
//  RooRealVar m_dif3("m_{shift(Gaus2,CB1)}","m_dif3",0.022+0.011);
//  RooRealVar m_dif3("m_{shift(Gaus2,CB1)}","m_dif3",0.022-0.011);
  RooRealVar s_rat1("s_{ratio(CB2,CB1)}","s_rat1",0.975);
//  RooRealVar s_rat1("s_{ratio(CB2,CB1)}","s_rat1",0.975+0.015);
//  RooRealVar s_rat1("s_{ratio(CB2,CB1)}","s_rat1",0.975-0.015);
  RooRealVar s_rat2("s_{ratio(Gaus1,CB1)}","s_rat2",3.79);
//  RooRealVar s_rat2("s_{ratio(Gaus1,CB1)}","s_rat2",3.79+0.23);
//  RooRealVar s_rat2("s_{ratio(Gaus1,CB1)}","s_rat2",3.79-0.23);
  RooRealVar s_rat3("s_{ratio(Gaus2,CB1)}","s_rat3",3.65);
//  RooRealVar s_rat3("s_{ratio(Gaus2,CB1)}","s_rat3",3.65+0.3);
//  RooRealVar s_rat3("s_{ratio(Gaus2,CB1)}","s_rat3",3.65-0.3);
  RooRealVar m_difBkg("m_{shiftBkg}","m_difBkg",-0.00135);
//  RooRealVar m_difBkg("m_{shiftBkg}","m_difBkg",-0.00135+0.0022);
//  RooRealVar m_difBkg("m_{shiftBkg}","m_difBkg",-0.00135-0.0022);
  RooRealVar s_ratBkg("s_{ratioBkg}","s_ratBkg",0.999);
//  RooRealVar s_ratBkg("s_{ratioBkg}","s_ratBkg",0.999+0.032);
//  RooRealVar s_ratBkg("s_{ratioBkg}","s_ratBkg",0.999-0.032);
  RooRealVar a("#alpha","a",0.805);
//  RooRealVar a("#alpha","a",0.805+0.014);
//  RooRealVar a("#alpha","a",0.805-0.014);
  RooRealVar n("n","n",4.92);
//  RooRealVar n("n","n",4.92+0.20);
//  RooRealVar n("n","n",4.92-0.20);
  RooRealVar f_sig("f_sig","f_sig",0.9799);
//  RooRealVar f_sig("f_sig","f_sig",0.9799+0.003);
//  RooRealVar f_sig("f_sig","f_sig",0.9799-0.003);
  RooRealVar a2("#alpha2","a2",0.781);
//  RooRealVar a2("#alpha2","a2",0.781+0.026);
//  RooRealVar a2("#alpha2","a2",0.781-0.026);
  RooRealVar n2("n2","n2",3.77);
//  RooRealVar n2("n2","n2",3.77+0.23);
//  RooRealVar n2("n2","n2",3.77-0.23);
  RooRealVar f_sig2("f_sig2","f_sig2",0.9746);
//  RooRealVar f_sig2("f_sig2","f_sig2",0.9746+0.0051);
//  RooRealVar f_sig2("f_sig2","f_sig2",0.9746-0.0051);
  RooRealVar a_bkg("#alpha_bkg","a_bkg",-1.9014);
//  RooRealVar a_bkg("#alpha_bkg","a_bkg",-1.9014+0.031);
//  RooRealVar a_bkg("#alpha_bkg","a_bkg",-1.9014-0.031);
//  RooRealVar n_bkg("n_bkg","n_bkg",1.604);
  RooRealVar n_bkg("n_bkg","n_bkg",1.604+0.064);
//  RooRealVar n_bkg("n_bkg","n_bkg",1.604-0.064);
  RooRealVar a_bkg2("#alpha_bkg2","a_bkg2",-1.9129);
//  RooRealVar a_bkg2("#alpha_bkg2","a_bkg2",-1.9129+0.038);
//  RooRealVar a_bkg2("#alpha_bkg2","a_bkg2",-1.9129-0.038);
  RooRealVar n_bkg2("n_bkg2","n_bkg2",1.328);
//  RooRealVar n_bkg2("n_bkg2","n_bkg2",1.328+0.067);
//  RooRealVar n_bkg2("n_bkg2","n_bkg2",1.328-0.067);




//Signal
  RooRealVar m_fudge("#mu_{fudge}","m_fudge",-0.000635,-0.005,0.005);
  RooRealVar m_fudgeBkg("#mu_{fudgeBkg}","m_fudgeBkg",-0.0,-0.04,0.04);
  RooRealVar s_fudge("#sigma_{fudge}","s_fudge",1.000,0.5,2.5);
  RooRealVar s_fudgeBkg("#sigma_{fudgeBkg}","s_fudgeBkg",1.000,0.5,2.5);
//  RooRealVar s_fudgeBkg("#sigma_{fudgeBkg}","s_fudgeBkg",1.280,1.0,2.5);

//Bin-1
  RooFormulaVar m("m_sig","1.86805+#mu_{fudge}",RooArgList(m_fudge));
  RooFormulaVar s("s","0.01530*#sigma_{fudge}",RooArgList(s_fudge));


  RooFormulaVar m_g("m_g","1.86805+#mu_{fudge}+(m_{shift(Gaus1,CB1)}*#sigma_{fudge})",RooArgList(m_fudge,s_fudge,m_dif2));
  RooFormulaVar s_g("s_g","0.01530*#sigma_{fudge}*s_{ratio(Gaus1,CB1)}",RooArgList(s_fudge,s_rat2));


//Bin-2
  RooFormulaVar m2("m_sig2","1.86805+#mu_{fudge}+m_{shift(CB2,CB1)}",RooArgList(m_fudge,m_dif1));
  RooFormulaVar s2("s2","0.01530*#sigma_{fudge}*s_{ratio(CB2,CB1)}",RooArgList(s_fudge,s_rat1));


  RooFormulaVar m_g2("m_g2","1.86805+#mu_{fudge}+(m_{shift(Gaus2,CB1)}*#sigma_{fudge})",RooArgList(m_fudge,s_fudge,m_dif3));
  RooFormulaVar s_g2("s_g2","0.0558*#sigma_{fudge}*s_{ratio(Gaus2,CB1)}",RooArgList(s_fudge,s_rat3));


//Combinatorial
//Bin-1
  RooRealVar p1("p1","p1",-0.4,-0.8,0.01);
  RooRealVar p1_2("p1_2","p1_2",-0.4,-0.8,0.01);

//Bin-2
  RooRealVar p2("p2","p2",-0.3,-0.8,0.01);
  RooRealVar p2_2("p2_2","p2_2",-0.3,-0.8,0.01);



//Peaking Background
//Bin-1
  RooFormulaVar m_bkg("#mu_{bkg}","1.6802+#mu_{fudgeBkg}",RooArgList(m_fudgeBkg));
  RooFormulaVar s_bkg("#sigma_{bkg}","0.03656*#sigma_{fudgeBkg}",RooArgList(s_fudgeBkg));



//Bin-2
  RooFormulaVar m_bkg2("#mu_{bkg2}","1.6802+#mu_{fudgeBkg}+m_{shiftBkg}",RooArgList(m_fudgeBkg,m_difBkg));
  RooFormulaVar s_bkg2("#sigma_{bkg2}","0.03656*#sigma_{fudgeBkg}*s_{ratioBkg}",RooArgList(s_fudgeBkg,s_ratBkg));



//Background fraction
//Bin-1
RooRealVar f_bkg("f_bkg","f_bkg",0.5,0.0,1.0);


//Bin-2
RooRealVar f_bkg2("f_bkg2","f_bkg2",0.5,0.0,1.0);



//_____________________________________________________________________________________
//			BIN - 1
//_____________________________________________________________________________________

//Signal - P
  RooCBShape Sig1_p("Sig1_p", "Cystal Ball Function_p", dzero, m, s, a, n); 
  RooGaussian Sig2_p("Sig2_p", "Sig2_p",dzero,m_g,s_g);
  RooAddPdf Sig_p("Sig_p","Sig_p",RooArgList(Sig1_p,Sig2_p),RooArgList(f_sig));


//Background - P
  RooChebychev Bkg1_p("Bkg1_p", "Bkg1_p", dzero, RooArgList(p1));
  RooCBShape Bkg2_p("Bkg2_p", "Bkg2_p", dzero, m_bkg, s_bkg, a_bkg, n_bkg); 
  RooAddPdf Bkg_p("Bkg_p","Bkg_p",RooArgList(Bkg1_p,Bkg2_p),RooArgList(f_bkg));

//Full Model - P
  RooAddPdf Model_p("Model_p","Model_p",RooArgList(Sig_p,Bkg_p),RooArgList(N_p,N_pb));

//Signal - N
  RooCBShape Sig1_n("Sig1_n", "Cystal Ball Function_n", dzero, m, s, a, n); 
  RooGaussian Sig2_n("Sig2_n", "Sig2_n",dzero,m_g,s_g);
  RooAddPdf Sig_n("Sig_n","Sig_n",RooArgList(Sig1_n,Sig2_n),RooArgList(f_sig));


//Background - N  
//Data 
  RooChebychev Bkg1_n("Bkg1_n", "Bkg1_n", dzero, RooArgList(p1));
  RooCBShape Bkg2_n("Bkg2_n", "Bkg2_n", dzero, m_bkg, s_bkg, a_bkg, n_bkg); 
  RooAddPdf Bkg_n("Bkg_n","Bkg_n",RooArgList(Bkg1_n,Bkg2_n),RooArgList(f_bkg));

//Full Model - N
  RooAddPdf Model_n("Model_n","Model_n",RooArgList(Sig_n,Bkg_n),RooArgList(N_n,N_nb));


//_____________________________________________________________________________________
//			BIN - 2
//_____________________________________________________________________________________


//Signal - P
  RooCBShape Sig1_p2("Sig1_p2", "Cystal Ball Function_p2", dzero, m2, s2, a2, n2); 
  RooGaussian Sig2_p2("Sig2_p2", "Sig2_p2",dzero,m_g2,s_g2);
  RooAddPdf Sig_p2("Sig_p2","Sig_p2",RooArgList(Sig1_p2,Sig2_p2),RooArgList(f_sig2));


//Background - P
  RooChebychev Bkg1_p2("Bkg1_p2", "Bkg1_p2", dzero, RooArgList(p2));
  RooCBShape Bkg2_p2("Bkg2_p2", "Bkg2_p2", dzero, m_bkg2, s_bkg2, a_bkg2, n_bkg2); 
  RooAddPdf Bkg_p2("Bkg_p2","Bkg_p2",RooArgList(Bkg1_p2,Bkg2_p2),RooArgList(f_bkg2));

//Full Model - P
  RooAddPdf Model_p2("Model_p2","Model_p2",RooArgList(Sig_p2,Bkg_p2),RooArgList(N_p2,N_pb2));

//Signal - N
  RooCBShape Sig1_n2("Sig1_n2", "Cystal Ball Function_n2", dzero, m2, s2, a2, n2); 
  RooGaussian Sig2_n2("Sig2_n2", "Sig2_n2",dzero,m_g2,s_g2);
  RooAddPdf Sig_n2("Sig_n2","Sig_n2",RooArgList(Sig1_n2,Sig2_n2),RooArgList(f_sig2));


//Background - N  
//Data 
  RooChebychev Bkg1_n2("Bkg1_n2", "Bkg1_n2", dzero, RooArgList(p2));
  RooCBShape Bkg2_n2("Bkg2_n2", "Bkg2_n2", dzero, m_bkg2, s_bkg2, a_bkg2, n_bkg2); 
  RooAddPdf Bkg_n2("Bkg_n2","Bkg_n2",RooArgList(Bkg1_n2,Bkg2_n2),RooArgList(f_bkg2));

//Full Model - N
  RooAddPdf Model_n2("Model_n2","Model_n2",RooArgList(Sig_n2,Bkg_n2),RooArgList(N_n2,N_nb2));






  //CREATE INDEX CATEGORY AND JOIN  SAMPLEs
  //_____________________________________________________
  RooCategory sample("sample","sample");
  sample.defineType("pos");
  sample.defineType("neg");
  sample.defineType("pos2");
  sample.defineType("neg2");

  RooDataSet* combData =new RooDataSet("combData","combData",RooArgSet(dzero),Index(sample),Import("pos",*data_p),Import("neg",*data_n),Import("pos2",*data_p2),Import("neg2",*data_n2));
  

  RooSimultaneous simPdf("simPdf","simPdf",sample);
  simPdf.addPdf(Model_p,"pos");
  simPdf.addPdf(Model_n,"neg");
  simPdf.addPdf(Model_p2,"pos2");
  simPdf.addPdf(Model_n2,"neg2");

  //_____________________________________________________

cout<<"Things are done"<<endl;


//Fit
   RooFitResult* fitRes = simPdf.fitTo(*combData,Save());



  TLine *line = new TLine(1.68,0.0,2.06,0.0);

  //DeltaM PLOTING
  RooPlot *xframe_1 =dzero.frame(Bins(38),Title("D^{+} #rightarrow #pi^{0} #pi^{+}"));
  combData->plotOn(xframe_1,Cut("sample==sample::pos"));
  simPdf.plotOn(xframe_1,Slice(sample,"pos"),ProjWData(sample,*combData));
  xframe_1->SetMaximum(1400) ;
    RooHist* hpull1 = xframe_1->pullHist() ;
    RooPlot* frame1 = dzero.frame() ;
    frame1->addPlotable(hpull1,"P") ;
    frame1->SetMaximum(4);
    frame1->SetMinimum(-4);
  cout<<" signalchi-1 = "<<xframe_1->chiSquare()<<endl;
  simPdf.plotOn(xframe_1,Slice(sample,"pos"),Components("Sig_p"),ProjWData(sample,*combData),LineStyle(kDashed),LineColor(kRed));
  simPdf.plotOn(xframe_1,Slice(sample,"pos"),Components("Bkg_p"),ProjWData(sample,*combData),LineStyle(kDashed));
    RooHist* hres1 = xframe_1->residHist() ;
    RooPlot* dframe1 = dzero.frame(Bins(38),Title(" ")) ;
    dframe1->addPlotable(hres1,"P") ;
    Sig_p.plotOn(dframe1);
    dframe1->SetMaximum(600) ;
    dframe1->SetMinimum(-40) ;
  Model_p.paramOn(xframe_1);



  RooPlot *xframe_2 = dzero.frame(Bins(38),Title("D^{-} #rightarrow #pi^{0} #pi^{-}"));
  combData->plotOn(xframe_2,Cut("sample==sample::neg"));
  simPdf.plotOn(xframe_2,Slice(sample,"neg"),ProjWData(sample,*combData));
  xframe_2->SetMaximum(1400) ;
    RooHist* hpull2 = xframe_2->pullHist() ;
    RooPlot* frame2 = dzero.frame(Title("Pull Distribution")) ;
    frame2->addPlotable(hpull2,"P") ;
    frame2->SetMaximum(4);
    frame2->SetMinimum(-4);
  cout<<" signalchi-2 = "<<xframe_2->chiSquare()<<endl;
  simPdf.plotOn(xframe_2,Slice(sample,"neg"),Components("Sig_n"),ProjWData(sample,*combData),LineStyle(kDashed),LineColor(kRed));
  simPdf.plotOn(xframe_2,Slice(sample,"neg"),Components("Bkg_n"),ProjWData(sample,*combData),LineStyle(kDashed));
    RooHist* hres2 = xframe_2->residHist() ;
    RooPlot* dframe2 = dzero.frame(Bins(38),Title(" ")) ;
    dframe2->addPlotable(hres2,"P") ;
    Sig_n.plotOn(dframe2);
    dframe2->SetMaximum(600) ;
    dframe2->SetMinimum(-40) ;
  Model_n.paramOn(xframe_2);


  RooPlot *xframe_3 =dzero.frame(Bins(38),Title("D^{+} #rightarrow #pi^{0} #pi^{+}"));
  combData->plotOn(xframe_3,Cut("sample==sample::pos2"));
  simPdf.plotOn(xframe_3,Slice(sample,"pos2"),ProjWData(sample,*combData));
  xframe_3->SetMaximum(1200) ;
    RooHist* hpull3 = xframe_3->pullHist() ;
    RooPlot* frame3 = dzero.frame(Title("Pull Distribution")) ;
    frame3->addPlotable(hpull3,"P") ;
    frame3->SetMaximum(4);
    frame3->SetMinimum(-4);
  cout<<" signalchi-3 = "<<xframe_3->chiSquare()<<endl;
  simPdf.plotOn(xframe_3,Slice(sample,"pos2"),Components("Sig_p2"),ProjWData(sample,*combData),LineStyle(kDashed),LineColor(kRed));
  simPdf.plotOn(xframe_3,Slice(sample,"pos2"),Components("Bkg_p2"),ProjWData(sample,*combData),LineStyle(kDashed));
    RooHist* hres3 = xframe_3->residHist() ;
    RooPlot* dframe3 = dzero.frame(Bins(38),Title(" ")) ;
    dframe3->addPlotable(hres3,"P") ;
    Sig_p2.plotOn(dframe3);
    dframe3->SetMaximum(170) ;
    dframe3->SetMinimum(-75) ;
  Model_p2.paramOn(xframe_3);


  RooPlot *xframe_4 = dzero.frame(Bins(38),Title("D^{-} #rightarrow #pi^{0} #pi^{-}"));
  combData->plotOn(xframe_4,Cut("sample==sample::neg2"));
  simPdf.plotOn(xframe_4,Slice(sample,"neg2"),ProjWData(sample,*combData));
  xframe_4->SetMaximum(1200);
    RooHist* hpull4 = xframe_4->pullHist() ;
    RooPlot* frame4 = dzero.frame(Title("Pull Distribution")) ;
    frame4->addPlotable(hpull4,"P") ;
    frame4->SetMaximum(4);
    frame4->SetMinimum(-4);
  cout<<" signalchi-4 = "<<xframe_4->chiSquare()<<endl;
  simPdf.plotOn(xframe_4,Slice(sample,"neg2"),Components("Sig_n2"),ProjWData(sample,*combData),LineStyle(kDashed),LineColor(kRed));
  simPdf.plotOn(xframe_4,Slice(sample,"neg2"),Components("Bkg_n2"),ProjWData(sample,*combData),LineStyle(kDashed));
    RooHist* hres4 = xframe_4->residHist() ;
    RooPlot* dframe4 = dzero.frame(Bins(38),Title(" ")) ;
    dframe4->addPlotable(hres4,"P") ;
    Sig_n2.plotOn(dframe4);
    dframe4->SetMaximum(170) ;
    dframe4->SetMinimum(-75) ;
  Model_n2.paramOn(xframe_4);


  TCanvas* can = new TCanvas("c","c") ;
  TPad *pad11 = new TPad("pad11", "The pad 80% of the height",0.0,0.0,0.5,1.0,0);
  TPad *pad12 = new TPad("pad12", "The pad 20% of the height",0.5,0.0,1.0,1.0,0);
    pad11->Draw();
    pad12->Draw();
  TCanvas* can2 = new TCanvas("c2","c2") ;
  TPad *pad21 = new TPad("pad21", "The pad 80% of the height",0.0,0.0,0.5,1.0,0);
  TPad *pad22 = new TPad("pad22", "The pad 20% of the height",0.5,0.0,1.0,1.0,0);
    pad21->Draw();
    pad22->Draw();
  TCanvas* can3 = new TCanvas("c3","c3",700,930) ;
  TPad *pad31 = new TPad("pad31", "The pad 80% of the height",0.0,0.5,0.5,1.0,0);
  TPad *pad32 = new TPad("pad32", "The pad 20% of the height",0.5,0.5,1.0,1.0,0);
  TPad *pad33 = new TPad("pad33", "The pad 80% of the height",0.0,0.0,0.5,0.5,0);
  TPad *pad34 = new TPad("pad34", "The pad 20% of the height",0.5,0.0,1.0,0.5,0);
    pad31->Draw();
    pad32->Draw();
    pad33->Draw();
    pad34->Draw();

  TCanvas* can4 = new TCanvas("c4","c4",700,930) ;
  TPad *mad31 = new TPad("mad31", "The mad 80% of the height",0.0,0.5,0.5,1.0,0);
  TPad *mad32 = new TPad("mad32", "The mad 20% of the height",0.5,0.5,1.0,1.0,0);
  TPad *mad33 = new TPad("mad33", "The mad 80% of the height",0.0,0.0,0.5,0.5,0);
  TPad *mad34 = new TPad("mad34", "The mad 20% of the height",0.5,0.0,1.0,0.5,0);
    mad31->Draw(); 
    mad32->Draw();
    mad33->Draw();
    mad34->Draw();
//-------------------------------------------------------------------------------------
pad11->cd();
TPad *pad11_m = new TPad("pad31_m", "The pad 80% of the height",0.0,0.25,1.0,1.0,0);
TPad *pad11_p = new TPad("pad31_p", "The pad 20% of the height",0.0,0.0,1.0,0.25,0);
    pad11_m->Draw();
    pad11_p->Draw();
pad12->cd();
TPad *pad12_m = new TPad("pad32_m", "The pad 80% of the height",0.0,0.25,1.0,1.0,0);
TPad *pad12_p = new TPad("pad32_p", "The pad 20% of the height",0.0,0.0,1.0,0.25,0);
    pad12_m->Draw();
    pad12_p->Draw();
pad21->cd();
TPad *pad21_m = new TPad("pad33_m", "The pad 80% of the height",0.0,0.25,1.0,1.0,0);
TPad *pad21_p = new TPad("pad33_p", "The pad 20% of the height",0.0,0.0,1.0,0.25,0);
    pad21_m->Draw();
    pad21_p->Draw();
pad22->cd();
TPad *pad22_m = new TPad("pad34_m", "The pad 80% of the height",0.0,0.25,1.0,1.0,0);
TPad *pad22_p = new TPad("pad34_p", "The pad 20% of the height",0.0,0.0,1.0,0.25,0);
    pad22_m->Draw();
    pad22_p->Draw();
//-------------------------------------------------------------------------------------
pad31->cd();
TPad *pad31_m = new TPad("pad31_m", "The pad 80% of the height",0.0,0.25,1.0,1.0,0);
TPad *pad31_p = new TPad("pad31_p", "The pad 20% of the height",0.0,0.0,1.0,0.25,0);
    pad31_m->Draw();
    pad31_p->Draw();
pad32->cd();
TPad *pad32_m = new TPad("pad32_m", "The pad 80% of the height",0.0,0.25,1.0,1.0,0);
TPad *pad32_p = new TPad("pad32_p", "The pad 20% of the height",0.0,0.0,1.0,0.25,0);
    pad32_m->Draw();
    pad32_p->Draw();
pad33->cd();
TPad *pad33_m = new TPad("pad33_m", "The pad 80% of the height",0.0,0.25,1.0,1.0,0);
TPad *pad33_p = new TPad("pad33_p", "The pad 20% of the height",0.0,0.0,1.0,0.25,0);
    pad33_m->Draw();
    pad33_p->Draw();
pad34->cd();
TPad *pad34_m = new TPad("pad34_m", "The pad 80% of the height",0.0,0.25,1.0,1.0,0);
TPad *pad34_p = new TPad("pad34_p", "The pad 20% of the height",0.0,0.0,1.0,0.25,0);
    pad34_m->Draw();
    pad34_p->Draw();
//-------------------------------------------------------------------------------------
    mad31->cd();
TPad *mad31_m = new TPad("mad31_m", "The mad 80% of the height",0.0,0.2,1.0,1.0,0);
TPad *mad31_p = new TPad("mad31_p", "The mad 20% of the height",0.0,0.0,1.0,0.2,0);
    mad31_m->Draw();
    mad31_p->Draw();
mad32->cd();
TPad *mad32_m = new TPad("mad32_m", "The mad 80% of the height",0.0,0.2,1.0,1.0,0);
TPad *mad32_p = new TPad("mad32_p", "The mad 20% of the height",0.0,0.0,1.0,0.2,0);
    mad32_m->Draw();
    mad32_p->Draw();
mad33->cd();
TPad *mad33_m = new TPad("mad33_m", "The mad 80% of the height",0.0,0.2,1.0,1.0,0);
TPad *mad33_p = new TPad("mad33_p", "The mad 20% of the height",0.0,0.0,1.0,0.2,0);
    mad33_m->Draw();
    mad33_p->Draw();
mad34->cd();
TPad *mad34_m = new TPad("mad34_m", "The mad 80% of the height",0.0,0.2,1.0,1.0,0);
TPad *mad34_p = new TPad("mad34_p", "The mad 20% of the height",0.0,0.0,1.0,0.2,0);
    mad34_m->Draw();
    mad34_p->Draw();
//-------------------------------------------------------------------------------------

  pad11_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); xframe_1->Draw() ;  line->Draw();
  pad11_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame1->Draw() ;  line->Draw();

  pad12_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); xframe_2->Draw() ;  line->Draw();
  pad12_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame2->Draw() ;  line->Draw();

  pad21_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); xframe_3->Draw() ;  line->Draw();
  pad21_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame3->Draw() ;  line->Draw();

  pad22_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); xframe_4->Draw() ;  line->Draw();
  pad22_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame4->Draw() ;  line->Draw();
//-------------------------------------------------------------------------------------

  pad31_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); xframe_1->Draw() ;  line->Draw();
  pad31_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame1->Draw() ;  line->Draw();

  pad32_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); xframe_2->Draw() ;  line->Draw();
  pad32_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame2->Draw() ;  line->Draw();

  pad33_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); xframe_3->Draw() ;  line->Draw();
  pad33_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame3->Draw() ;  line->Draw();

  pad34_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); xframe_4->Draw() ;  line->Draw();
  pad34_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame4->Draw() ;  line->Draw();
//-------------------------------------------------------------------------------------
  mad31_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetRightMargin(0.01) ;   gPad->SetBottomMargin(0.15); gPad->SetTopMargin(0.01);  dframe1->Draw() ;  line->Draw();
  mad31_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetRightMargin(0.01) ;   gPad->SetBottomMargin(0.02); frame1->Draw() ;  line->Draw();

  mad32_m->cd() ; gPad->SetLeftMargin(0.01) ; gPad->SetRightMargin(0.15) ;   gPad->SetBottomMargin(0.15); gPad->SetTopMargin(0.01);  dframe2->Draw() ;  line->Draw();
  mad32_p->cd() ; gPad->SetLeftMargin(0.01) ; gPad->SetRightMargin(0.15) ;   gPad->SetBottomMargin(0.02); frame2->Draw() ;  line->Draw();

  mad33_m->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetRightMargin(0.01) ;   gPad->SetBottomMargin(0.15); gPad->SetTopMargin(0.01);  dframe3->Draw() ;  line->Draw();
  mad33_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetRightMargin(0.01) ;   gPad->SetBottomMargin(0.02); frame3->Draw() ;  line->Draw();

  mad34_m->cd() ; gPad->SetLeftMargin(0.01) ; gPad->SetRightMargin(0.15) ;  gPad->SetBottomMargin(0.15); gPad->SetTopMargin(0.01);  dframe4->Draw() ;  line->Draw();
  mad34_p->cd() ; gPad->SetLeftMargin(0.01) ; gPad->SetRightMargin(0.15) ;  gPad->SetBottomMargin(0.02); frame4->Draw() ;  line->Draw();
//-------------------------------------------------------------------------------------


Float_t Asy, e_Asy, Nt1, Nt2, e_Nt1, e_Nt2;
Asy=Araw.getVal();
e_Asy=Araw.getError();

Nt1=N_t1.getVal();
e_Nt1=N_t1.getError();

Nt2=N_t2.getVal();
e_Nt2=N_t2.getError();


cout<<"Araw = "<<Asy<<" +/- "<<e_Asy<<endl;

cout<<"N_t1 = "<<Nt1<<" +/- "<<e_Nt1<<endl;

cout<<"N_t2 = "<<Nt2<<" +/- "<<e_Nt2<<endl;



}












