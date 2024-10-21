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
using namespace RooFit;
  RooRealVar dzero("dzero","dzero",1.68,2.06,"GeV");
  RooDataSet* data=new RooDataSet("data","data",RooArgSet(dzero));
  RooDataSet* data2=new RooDataSet("data2","data2",RooArgSet(dzero));

void fit_MD_simfit(void)
{
  //LOAD DATA FILE
  TChain* chain=new TChain("h1");



  chain->Add("pipi_MC0_Y4s.root");
  chain->Add("pipi_MC0_Y5s.root");

  chain->Add("pipi_MC1_Y4s.root");
  chain->Add("pipi_MC1_Y5s.root");




  Int_t nevt=(int)chain->GetEntries();
  cout<<"nevt\t"<<nevt <<endl;

 Float_t Deltam, f_PD, f_dzero, f_Pizsmass, f_Dstf, f_Egam1s, f_Egam2s, f_Egamma1, f_Egamma2, f_Categ, f_Pizmom, f_Pimom, f_Gam1thet, f_Gam2thet, f_Pizmass, f_Df;


  h1->SetBranchAddress("Deltam",&Deltam);
  h1->SetBranchAddress("Pstdst",&f_PD);
  h1->SetBranchAddress("Dmass",&f_dzero);
  h1->SetBranchAddress("Pizsmass",&f_Pizsmass);
  h1->SetBranchAddress("Pizmass",&f_Pizmass);
  h1->SetBranchAddress("Dstf",&f_Dstf);
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

int photon1cutflag=0, photon2cutflag=0, sphoton1cutflag=0, sphoton2cutflag=0;

  Int_t nevt_ac_p(0);
  Int_t nevt_ac_n(0);
  float bin;int bin1; 

int num_pass=0;


//for(int i=0;i<numbins;i++){cout<<"cut["<<i<<"] = "<<cut[i]<<endl;}




  for(int i=0;i<nevt;i++) 
//  for(int i=0;i<100000;i++)
//  for(int i=0;i<10;i++)
    {


      chain->GetEntry(i);
		  dzero.setVal(f_dzero);

if(Deltam > 0.139 && Deltam < 0.142){       //optimized for M_D fitting
if(f_dzero >1.68  && f_dzero < 2.06){       //~3sigma range to estimate F.O.M.
if(f_Pizsmass > 0.125  && f_Pizsmass < 0.143){
if(f_Pizmass > 0.119  && f_Pizmass < 0.151){
if(f_Pizmom > 1.06 ){
if(f_Pimom > 0.84 ){
//if(f_PD > 2.95){
//if(f_PD > 2.5 && f_PD < 5.0){

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

if(f_PD > 2.95){
if(f_Df==1){data->add(RooArgSet(dzero));}
}


if(f_PD > 2.5 && f_PD < 2.95){
if(f_Df==1){data2->add(RooArgSet(dzero));}
}


num_pass++;
}}//Photon cuts

}}}}}}//}
    }
 
cout<<"num_pass"<<num_pass<<endl;



  //DEFINE PDF
//Common
  RooRealVar N_sig("N_{Sig}","N_sig",100,0,1000000);
  RooRealVar N_bkg("N_{Bkg}","N_bkg",100,0,1000000);
  RooRealVar N_sig2("N_{Sig2}","N_sig2",100,0,1000000);
  RooRealVar N_bkg2("N_{Bkg2}","N_bkg2",100,0,1000000);

//Signal
  RooRealVar m("#mu","m",1.8690531,1.80,1.90);//,1.86,1.80,1.90);//
  RooRealVar s("#sigma","s",0.0160014,0,0.04);//,0.01,0,0.04);//
  RooRealVar a("#alpha","a",0.668437,0,2);
  RooRealVar n("n","n",14.59,0,150);

  RooCBShape Sig("Sig", "Cystal Ball Function", dzero, m, s, a, n); 

//Signal-2
  RooRealVar s_fact("#sigma_{factor}","s_fact",1.0005,0.0,2.0);
  RooFormulaVar s2("#sigma2","#sigma * #sigma_{factor}",RooArgList(s,s_fact));

  RooCBShape Sig2("Sig2", "Cystal Ball Function", dzero, m, s2, a, n); 
//Background
  RooRealVar p("p","p",0.0,-5,5);
  RooChebychev Bkg("Bkg", "Bkg", dzero, RooArgList(p));
//  RooChebychev bkg1_p("bkg1_p", "bkg1_p", dzero, RooArgList(p)); 
//  RooAddPdf Bkg("Bkg","Bkg",RooArgList(bkg1,bkg2),RooArgList(f));

//Background-2
  RooRealVar p2("p2","p2",0.0,-5,5);
  RooChebychev Bkg2("Bkg2", "Bkg2", dzero, RooArgList(p2));


//Full Model
  RooAddPdf Model("Model","Model",RooArgList(Sig,Bkg),RooArgList(N_sig,N_bkg));
  RooAddPdf Model2("Model2","Model2",RooArgList(Sig2,Bkg2),RooArgList(N_sig2,N_bkg2));


  //CREATE INDEX CATEGORY AND JOIN  SAMPLEs
  //_____________________________________________________
  RooCategory sample("sample","sample");
  sample.defineType("bin1");
  sample.defineType("bin2");


  RooDataSet* combData =new RooDataSet("combData","combData",RooArgSet(dzero),Index(sample),Import("bin1",*data),Import("bin2",*data2));
  


  RooSimultaneous simPdf("simPdf","simPdf",sample);
  simPdf.addPdf(Model,"bin1");
  simPdf.addPdf(Model2,"bin2");
//  simPdf.addPdf(Sig,"bin1");
//  simPdf.addPdf(Sig2,"bin2");


//Fit
   RooFitResult* fitRes = simPdf.fitTo(*combData,Save());


  TCanvas* can = new TCanvas("c","c",700,800) ;
           can->cd();
  RooPlot* dzero_frame = dzero.frame(Bins(38),Title("Bin - 1"));
  dzero_frame->SetTitle("Bin - 1");
  data->plotOn(dzero_frame);
  Model.plotOn(dzero_frame, LineColor(kBlue), LineStyle(kSolid),LineWidth(2));
  Model.plotOn(dzero_frame,Components("Bkg"), LineColor(kBlue), LineStyle(kDashed),LineWidth(2));
  Model.paramOn(dzero_frame);

//  Sig.plotOn(dzero_frame, LineColor(kBlue), LineStyle(kSolid),LineWidth(2));
//  Sig.paramOn(dzero_frame);
  dzero_frame->Draw();


  TCanvas* can2 = new TCanvas("c2","c2",700,800) ;
           can2->cd();
  RooPlot* dzero_frame2 = dzero.frame(Bins(38),Title("Bin - 2"));
  dzero_frame2->SetTitle("Bin - 2");
  data2->plotOn(dzero_frame2);
  Model2.plotOn(dzero_frame2, LineColor(kBlue), LineStyle(kSolid),LineWidth(2));
  Model2.plotOn(dzero_frame2,Components("Bkg2"), LineColor(kBlue), LineStyle(kDashed),LineWidth(2));
  Model2.paramOn(dzero_frame2);

//  Sig2.plotOn(dzero_frame2, LineColor(kBlue), LineStyle(kSolid),LineWidth(2));
//  Sig2.paramOn(dzero_frame2);
  dzero_frame2->Draw();


  TCanvas* can3 = new TCanvas("c3","c3",700,800) ;
           can3->Divide(2,1);
           can3->cd(1);  dzero_frame->Draw();
           can3->cd(2);  dzero_frame2->Draw();


}



















