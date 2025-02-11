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
#include "TChain.h"
using namespace RooFit;
  RooRealVar dzero("dzero","dzero",1.70,2.00,"GeV");
  RooDataSet* data_p=new RooDataSet("data_p","data_p",RooArgSet(dzero));
  RooDataSet* data_n=new RooDataSet("data_n","data_n",RooArgSet(dzero));


void acp_MD(void)
{

/*
  //LOAD DATA FILE
  TChain* chain=new TChain("h1");
  chain->Add("pipi_data.root");
//  TFile *f = new TFile("pipi_data.root");
//  TTree *t1 = (TTree*)f->Get("h1");
//  Int_t nevt=(int)->GetEntries();
  cout<<"nevt\t"<<nevt <<endl;

*/
//  TFile *file = new TFile("pipi_data.root");
  TFile *file = new TFile("pipi_MC6.root");
  TTree *t1 = (TTree*)file->Get("h1");
  Int_t nevt = (Int_t)t1->GetEntries();


 Float_t Deltam, f_PD, f_dzero, f_Pizsmass, f_Dstf, f_Egam1s, f_Egam2s, f_Egamma1, f_Egamma2, f_Categ, f_Pizmom, f_Pimom, f_Gam1thet, f_Gam2thet, f_Dcharge, f_Pizmass, f_Df;

cout<<"done 1"<<endl;

  t1->SetBranchAddress("Deltam",&Deltam);
  t1->SetBranchAddress("Pstdst",&f_PD);
  t1->SetBranchAddress("Dmass",&f_dzero);
  t1->SetBranchAddress("Pizsmass",&f_Pizsmass);
  t1->SetBranchAddress("Pizmass",&f_Pizmass);
  t1->SetBranchAddress("Egam1s",&f_Egam1s);
  t1->SetBranchAddress("Egam2s",&f_Egam2s);
  t1->SetBranchAddress("Egamma1",&f_Egamma1);
  t1->SetBranchAddress("Egamma2",&f_Egamma2);
  t1->SetBranchAddress("Categ",&f_Categ);
  t1->SetBranchAddress("Pizmom",&f_Pizmom);
  t1->SetBranchAddress("Pimom",&f_Pimom);
  t1->SetBranchAddress("Gam1hthe",&f_Gam1thet);
  t1->SetBranchAddress("Gam2hthe",&f_Gam2thet);
  t1->SetBranchAddress("Dcharge",&f_Dcharge);


/*
  h1->SetBranchAddress("Deltam",&Deltam);
  h1->SetBranchAddress("Pstdst",&f_PD);
  h1->SetBranchAddress("Dmass",&f_dzero);
  h1->SetBranchAddress("Pizsmass",&f_Pizsmass);
  h1->SetBranchAddress("Pizmass",&f_Pizmass);
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
*/


int photon1cutflag=0, photon2cutflag=0, sphoton1cutflag=0, sphoton2cutflag=0;

  Int_t nevt_ac_p(0);
  Int_t nevt_ac_n(0);
  float bin;int bin1; 

int num_pass=0;


//for(int i=0;i<numbins;i++){cout<<"cut["<<i<<"] = "<<cut[i]<<endl;}




  for(int i=0;i<nevt;i++) 
//  for(int i=0;i<10000;i++)
//  for(int i=0;i<10;i++)
    {


//      chain->GetEntry(i);
      t1->GetEntry(i);
		  dzero.setVal(f_dzero);

if(Deltam > 0.139 && Deltam < 0.142){       //optimized for M_D fitting
if(f_dzero >1.70  && f_dzero < 2.0){       //~3sigma range to estimate F.O.M.
//if(f_Pizsmass > 0.11  && f_Pizsmass < 0.16){
if(f_Pizsmass > 0.125  && f_Pizsmass < 0.143){
if(f_Pizmass > 0.119  && f_Pizmass < 0.151){
if(f_Pizmom > 1.06 ){
if(f_Pimom > 0.84 ){
if(f_PD > 2.95){
//if(f_PD > 2.17 && f_PD <= 2.9){
//if(f_PD > 2.5 && f_PD <= 2.9){
//if(f_PD > 2.9 && f_PD <= 3.3){
//if(f_PD > 3.3 && f_PD <= 3.7){
//if(f_PD > 3.7){

//if(f_Categ == 5){
//if(f_Categ == 1 || f_Categ == 2 || f_Categ == 6 ){
if(f_Categ == 1 || f_Categ == 2 || f_Categ == 5 || f_Categ == 6 ){

//if(f_Categ != 1 && f_Categ != 2 && f_Categ != 6 && f_Categ != 5){

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




if(f_Dcharge == 1){data_p->add(RooArgSet(dzero));}
if(f_Dcharge == -1){data_n->add(RooArgSet(dzero));}

//cout<<"fabs(f_Pizmass - 0.135) = "<<fabs(f_Pizmass - 0.135)<<endl;
//cout<<"fabs(f_Pizsmass - 0.135) = "<<fabs(f_Pizsmass - 0.135)<<endl;
//cout<<"---------------------------"<<endl;


}}//Photon cuts

}}}}}}}}
    }
 




  //DEFINE PDF
//Common
  //____________________________________________________
  RooRealVar Araw("A_{Raw}","Araw",0,-1,1);
  RooRealVar N_t("N_{Sig}","N_t",100,0,1000000);
  RooFormulaVar N_n("N_n","(0.5)*(1-A_{Raw})*N_{Sig}",RooArgList(Araw,N_t));
  RooFormulaVar N_p("N_p","(0.5)*(1+A_{Raw})*N_{Sig}",RooArgList(Araw,N_t));

  //____________________________________________________
  RooRealVar Abkg("A_{Bkg}","ABkg",0,-1,1);
  RooRealVar N_tb("N_{Bkg}","N_tb",100,0,1000000);
  RooFormulaVar N_nb("N_nb","(0.5)*(1-A_{Bkg})*N_{Bkg}",RooArgList(Abkg,N_tb));
  RooFormulaVar N_pb("N_pb","(0.5)*(1+A_{Bkg})*N_{Bkg}",RooArgList(Abkg,N_tb));

  //_____________________________________________________


//Common Pars
  RooRealVar m("#mu","m",1.86937);//,1.80,1.90);//
  RooRealVar s("#sigma","s",0.01752);//,0,0.04);//
  RooRealVar a("#alpha","a",0.76);//,0.5,0,2);
  RooRealVar n("n","n",99);//2,0,150);

  RooRealVar p("p","p",0.0,-1.0,1.0); 
  RooRealVar c("c","c",-9,-30,10);
  RooRealVar f("frac_{Bkg1/Bkg2}","f",0.5,0,1); 
  RooRealVar f2("frac2_{Bkg1/Bkg2}","f2",0.5,0,1); 

//Signal - P
  RooCBShape Sig_p("Sig_p", "Cystal Ball Function", dzero, m, s, a, n); 
//Background - P  
  RooChebychev bkg1_p("bkg1_p", "bkg1_p", dzero, RooArgList(p));
  RooExponential bkg2_p("bkg2_p", "bkg2_p", dzero, c);
  RooAddPdf Bkg_p("Bkg_p","Bkg_p",RooArgList(bkg1_p,bkg2_p),RooArgList(f));
//Full Model - P
  RooAddPdf Model_p("Model_p","Model_p",RooArgList(Sig_p,Bkg_p),RooArgList(N_p,N_pb));

//Signal - N
  RooCBShape Sig_n("Sig_n", "Cystal Ball Function", dzero, m, s, a, n); 
//Background - N  
  RooChebychev bkg1_n("bkg1_n", "bkg1_n", dzero, RooArgList(p));
  RooExponential bkg2_n("bkg2_n", "bkg2_n", dzero, c);
  RooAddPdf Bkg_n("Bkg_n","Bkg_n",RooArgList(bkg1_n,bkg2_n),RooArgList(f2));
//Full Model - N
  RooAddPdf Model_n("Model_n","Model_n",RooArgList(Sig_n,Bkg_n),RooArgList(N_n,N_nb));


  //CREATE INDEX CATEGORY AND JOIN  SAMPLEs
  //_____________________________________________________
  RooCategory sample("sample","sample");
  sample.defineType("pos");
  sample.defineType("neg");
  RooDataSet* combData =new RooDataSet("combData","combData",RooArgSet(dzero),Index(sample),Import("pos",*data_p),Import("neg",*data_n));
  


  RooSimultaneous simPdf("simPdf","simPdf",sample);
  simPdf.addPdf(Model_p,"pos");
  simPdf.addPdf(Model_n,"neg");
  //_____________________________________________________




//Fit
   RooFitResult* fitRes = simPdf.fitTo(*combData,Save());



  TCanvas* can = new TCanvas("c","c") ;
  can->Divide(2,1) ;

  //DeltaM PLOTING
  RooPlot *xframe_1 =dzero.frame(Bins(30),Title("D^{+} #rightarrow #pi^{0} #pi^{+}"));
  combData->plotOn(xframe_1,Cut("sample==sample::pos"));
  simPdf.plotOn(xframe_1,Slice(sample,"pos"),ProjWData(sample,*combData));
  simPdf.plotOn(xframe_1,Slice(sample,"pos"),Components("Bkg_p"),ProjWData(sample,*combData),LineStyle(kDashed));
   Model_p.paramOn(xframe_1,data_p);

  RooPlot *xframe_2 = dzero.frame(Bins(30),Title("D^{-} #rightarrow #pi^{0} #pi^{-}"));
  combData->plotOn(xframe_2,Cut("sample==sample::neg"));
  simPdf.plotOn(xframe_2,Slice(sample,"neg"),ProjWData(sample,*combData));
  simPdf.plotOn(xframe_2,Slice(sample,"neg"),Components("Bkg_n"),ProjWData(sample,*combData),LineStyle(kDashed));
 //    Model_n.paramOn(xframe_2,data_n); 

  can->cd(1) ; gPad->SetLeftMargin(0.15) ; xframe_1->GetYaxis()->SetTitleOffset(1.4) ; xframe_1->Draw() ;
  can->cd(2) ; gPad->SetLeftMargin(0.15) ; xframe_2->GetYaxis()->SetTitleOffset(1.4) ; xframe_2->Draw() ;

Float_t Asy, e_Asy;
Asy=Araw.getVal();
e_Asy=Araw.getError();

cout<<"A_raw = "<<Asy<<" +/- "<<e_Asy<<endl;

}

