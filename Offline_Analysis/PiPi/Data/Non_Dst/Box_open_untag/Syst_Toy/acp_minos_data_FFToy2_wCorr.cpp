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
#include <fstream>

using namespace RooFit;
void DoFit(int ii);
double result[4][10000];
TVectorD X_sig(5), Y_sig(5), X_bkg(2), Y_bkg(2);

double low_lim=1.68;
int count=-1;
int i,j;

double widthFF;
double al_sig;
double n_sig;
double f_CBgaus;
double width_CBgaus;
double mean_CBgaus;
double al_bkg;
double n_bkgd;

//---------------------------------------------------------------------
TMatrixD A_sig(5,5);
TMatrixD C_sig(5,5);
TMatrixD D_sig(5,5);
//---------------------------------------------------------------------
TMatrixD A_bkg(2,2);
TMatrixD C_bkg(2,2);
TMatrixD D_bkg(2,2);
//---------------------------------------------------------------------




  RooRealVar dzero("dzero","M_{D}  ",low_lim,2.06,"GeV");

TH1D* data_p=new TH1D("pdat", "pdat", 100, low_lim, 2.06);
TH1D* data_n=new TH1D("ndat", "ndat", 100, low_lim, 2.06);

//  TH1D* Araw_res=new TH1D("Araw_res", "Araw_res", 50, 3.0, 4.5);
  TH1D* Araw_res=new TH1D("Araw_res", "Araw_res", 50, 2.0, 6.0);

void acp_minos_data_FFToy2_wCorr(void)
{
  //LOAD DATA FILE
//  TChain* chain=new TChain("h2");
  TChain* chain=new TChain("h2");


//  chain->Add("pipi_mc.root");

chain->Add("../pipi_d4s.root");    
chain->Add("../pipi_d5s.root");    
chain->Add("../pipi_dcont.root");



//---------------------------------------------------------------------
//------------------CHOLESKY DECOMPOSITION-----------------------------
//---------------------------------------------------------------------

ifstream fin;
fin.open("TmarixTrials/Corr_untag_sig.txt");//dim=5;

while(!fin.eof())
{count++;i=count/5;j=count%5;
fin>>A_sig[i][j];
if(count==(5*5)-1)){break;}
}
fin.close();
//A_sig.Print();
TDecompChol B_sig(A_sig);
B_sig.Decompose();
C_sig=B_sig.GetU();//U
D_sig.Transpose(C_sig);//U^T
//D_sig.Print();
//---------------------------------------------------------------------
fin.open("TmarixTrials/Corr_untag_bkg.txt");//dim=2;
count=-1;
while(!fin.eof())
{count++;i=count/2;j=count%2;
fin>>A_bkg[i][j];
if(count==(2*2)-1)){break;}
}
fin.close();
//A_bkg.Print();
TDecompChol B_bkg(A_bkg);
B_bkg.Decompose();
C_bkg=B_bkg.GetU();//U
D_bkg.Transpose(C_bkg);//U^T
//D_bkg.Print();

//---------------------------------------------------------------------


  Int_t nevt=(int)chain->GetEntries();
  cout<<"nevt\t"<<nevt <<endl;

 Float_t Deltam, f_PD, f_dzero, f_Pizsmass, f_Dstf, f_Egam1s, f_Egam2s, f_Egamma1, f_Egamma2, f_Categ, f_Pizmom, f_Pimom, f_Gam1thet, f_Gam2thet, f_Pizmass, f_Df; 
    Float_t   f_Dcharge;


//  h2->SetBranchAddress("Deltam",&Deltam);
  h2->SetBranchAddress("Pstd",&f_PD);
  h2->SetBranchAddress("Dmass",&f_dzero);
//  h2->SetBranchAddress("Pizsmass",&f_Pizsmass);
  h2->SetBranchAddress("Pizmass",&f_Pizmass);
//  h2->SetBranchAddress("Dstf",&f_Dstf);
  h2->SetBranchAddress("Df",&f_Df);
//  h2->SetBranchAddress("Egam1s",&f_Egam1s);
//  h2->SetBranchAddress("Egam2s",&f_Egam2s);
  h2->SetBranchAddress("Egamma1",&f_Egamma1);
  h2->SetBranchAddress("Egamma2",&f_Egamma2);
//  h2->SetBranchAddress("Categ",&f_Categ);
  h2->SetBranchAddress("Pizmom",&f_Pizmom);
  h2->SetBranchAddress("Pimom",&f_Pimom);
//  h2->SetBranchAddress("Gam1hthe",&f_Gam1thet);
//  h2->SetBranchAddress("Gam2hthe",&f_Gam2thet);
  h2->SetBranchAddress("Dcharge",&f_Dcharge);


int photon1cutflag=0, photon2cutflag=0, sphoton1cutflag=0, sphoton2cutflag=0;

  Int_t nevt_ac_p(0);
  Int_t nevt_ac_n(0);
  float bin;int bin1; 

int num_pass=0;


  for(int i=0;i<nevt;i++)  
//  for(int i=0;i<100000;i++)
//  for(int i=0;i<1;i++)
    {
photon1cutflag=0, photon2cutflag=0;

      chain->GetEntry(i);
		  dzero.setVal(f_dzero);



if(f_dzero >low_lim && f_dzero < 2.06){       //~3sigma range to estimate F.O.M.
if(f_Pizmom > 1.06 ){
if(f_Pimom > 0.84 ){
if(f_PD > 2.65){


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

//Photon cuts
if(photon1cutflag == 1 && photon2cutflag == 1){
 

num_pass++;
if(f_Dcharge == 1){data_p->Fill(f_dzero);}
if(f_Dcharge == -1){data_n->Fill(f_dzero);}

//}//for MC


}//Photon cuts


}}}}//}
    }
 
cout<<"num_pass"<<num_pass<<endl;


RooDataHist("data_P","data_P",dzero,data_p) ; 
RooDataHist("data_N","data_N",dzero,data_n) ;



TRandom *ran = new TRandom(450);
TRandom *ran1 = new TRandom(50);
TRandom *ran2 = new TRandom(150);
TRandom *ran3 = new TRandom(250);
TRandom *ran4 = new TRandom(350);
TRandom *ran5 = new TRandom(550);
TRandom *ran6 = new TRandom(650);
TRandom *ran7 = new TRandom(750);


for(int ii=0;ii<5000;ii++){

 widthFF=ran->Gaus(1.069,0.039);

X_sig[0]=ran1->Gaus(0.0,1.0);
X_sig[1]=ran2->Gaus(0.0,1.0);
X_sig[2]=ran3->Gaus(0.0,1.0);
X_sig[3]=ran4->Gaus(0.0,1.0);
X_sig[4]=ran5->Gaus(0.0,1.0);

X_bkg[0]=ran6->Gaus(0.0,1.0);
X_bkg[1]=ran7->Gaus(0.0,1.0);

Y_sig=X_sig;
Y_sig *= D_sig;

Y_bkg=X_bkg;
Y_bkg *= D_bkg;


 al_sig=(Y_sig[0] * 0.013) + 0.905;
 mean_CBgaus=(Y_sig[1] * 0.0035) + 0.0313;
 width_CBgaus=(Y_sig[2] * 0.099) + 3.747;
 f_CBgaus=(Y_sig[3] * 0.0022) + 0.9619;
 n_sig=(Y_sig[4] * 0.055) + 2.469;

 al_bkg=(Y_bkg[0] * 0.018) - 1.9750;
 n_bkgd=(Y_bkg[1] * 0.020) + 1.167;


DoFit(ii);
Araw_res->Fill(result[0][ii]);
}


//    TF1 *func = new TF1("myGauss","([0]*exp(-0.5*((x-[2])/[3])**2)) +( [1]*exp(-0.5*((x-[2])/[4])**2))",3.4,4.2);
    TF1 *func = new TF1("myGauss","([0]*exp(-0.5*((x-[2])/[3])**2)) +( [1]*exp(-0.5*((x-[2])/[4])**2))",3.0,4.5);
    // parameter names
    func->SetParNames("Factor1","Factor2","Mean","Sigma1","Sigma2");
    //Set Parameters:
    func->SetParameter(0,90000);
    func->SetParLimits(0,0,100000);
    func->SetParameter(1,40000);
    func->SetParLimits(1,0,50000);
    func->SetParameter(2,3.78);//mean
    func->SetParLimits(2,3.7,3.9);//mean
    func->SetParameter(3,0.1);//mean
    func->SetParLimits(3,0.01,0.5);//Sigma1
    func->SetParameter(4,0.1);
    func->SetParLimits(4,0.01,2.0);


TCanvas* can = new TCanvas("can","can") ;
Araw_res->SetMarkerStyle(20);
//Araw_res->SetMarkerColor(kBlue);

Araw_res->Fit(func,"R");// use option "R" to restrict to a certain region for fitting
//Araw_res->Fit("gaus");
can->cd();
Araw_res->Draw("EP");


}



void DoFit(int ii)
{
 
  //DEFINE PDF
//Common
  //____________________________________________________
  RooRealVar Araw("A_{Raw}","Araw",0,-1,1);
  RooRealVar N_t("N_{Sig}","N_t",107000,60000,185000);
  RooFormulaVar N_n("N_n","(0.5)*(1-A_{Raw})*N_{Sig}",RooArgList(Araw,N_t));
  RooFormulaVar N_p("N_p","(0.5)*(1+A_{Raw})*N_{Sig}",RooArgList(Araw,N_t));

  //____________________________________________________
  RooRealVar Abkg("A_{Bkg}","ABkg",0,-1,1);
  RooRealVar N_tb("N_{Bkg}","N_tb",7000000,4500000,22000000);
  RooFormulaVar N_nb("N_nb","(0.5)*(1-A_{Bkg})*N_{Bkg}",RooArgList(Abkg,N_tb));
  RooFormulaVar N_pb("N_pb","(0.5)*(1+A_{Bkg})*N_{Bkg}",RooArgList(Abkg,N_tb));

  //_____________________________________________________

//Common Pars
//Fudge Factors
  RooRealVar m_fudge("#mu_{fudge}","m_fudge",0.0,-0.005,0.005);
  RooRealVar s_fudge("#sigma_{fudge}","s_fudge",widthFF);
  RooRealVar m_diff("#mu_{diff}","m_diff",mean_CBgaus);
  RooRealVar s_ratio("#sigma_{ratio}","s_ratio",width_CBgaus);

  RooRealVar m_fudgeBkg("#mu_{fudgeBkg}","m_fudgeBkg",0.0,-0.05,0.05);
  RooRealVar s_fudgeBkg("#sigma_{fudgeBkg}","s_fudgeBkg",1.28,0.5,2.0);



//Signal
  RooFormulaVar m("m_sig","1.86786+#mu_{fudge}",RooArgList(m_fudge));
  RooFormulaVar s("s","0.015835*#sigma_{fudge}",RooArgList(s_fudge));
  RooRealVar a("#alpha","a",al_sig);
  RooRealVar n("n","n",n_sig);

  RooFormulaVar m_g("#mu_{G}","1.86786+#mu_{fudge}+#mu_{diff}",RooArgList(m_fudge,m_diff));
  RooFormulaVar s_g("#sigma_{G}","0.015835*#sigma_{fudge}*#sigma_{ratio}",RooArgList(s_fudge,s_ratio));
  RooRealVar f_sig("f_sig","f_sig",f_CBgaus); 




//Combinatorial
  RooRealVar p1("p1","p1",0.0,-1,1);
  RooRealVar p2("p2","p2",0.0,-1,1);



//Misreconstructed D's
  RooFormulaVar m_b("#mu_bkg","1.6625+#mu_{fudgeBkg}",RooArgList(m_fudgeBkg));
  RooFormulaVar s_b("#sigma_bkg","0.04198*#sigma_{fudgeBkg}",RooArgList(s_fudgeBkg));
  RooRealVar a_b("#alpha_bkg","a_bkg",al_bkg);
  RooRealVar n_b("n_bkg","n_bkg",n_bkgd); 
  RooRealVar f_bkg("f_bkg","f_bkg",0.95681,0.88,1.0);



//Signal - P
  RooCBShape Sig1_p("Sig1_p", "Cystal Ball Function_p", dzero, m, s, a, n);
  RooGaussian Sig2_p("Sig2_p", "Sig2_p",dzero,m_g,s_g);
  RooAddPdf Sig_p("Sig_p","Sig_p",RooArgList(Sig1_p,Sig2_p),RooArgList(f_sig));


//Background - P
  RooChebychev Bkg1_p("Bkg1_p", "Bkg1_p", dzero, RooArgList(p1,p2));
  RooCBShape Bkg2_p("Bkg2_p", "Bkg2_p", dzero, m_b, s_b, a_b, n_b); 
  RooAddPdf Bkg_p("Bkg_p","Bkg_p",RooArgList(Bkg1_p,Bkg2_p),RooArgList(f_bkg));

//Full Model - P
  RooAddPdf Model_p("Model_p","Model_p",RooArgList(Sig_p,Bkg_p),RooArgList(N_p,N_pb));

//Signal - N
  RooCBShape Sig1_n("Sig1_n", "Cystal Ball Function_n", dzero, m, s, a, n); 
  RooGaussian Sig2_n("Sig2_n", "Sig2_n",dzero,m_g,s_g);
  RooAddPdf Sig_n("Sig_n","Sig_n",RooArgList(Sig1_n,Sig2_n),RooArgList(f_sig));


//Background - N  
//Data 
  RooChebychev Bkg1_n("Bkg1_n", "Bkg1_n", dzero, RooArgList(p1,p2));
  RooCBShape Bkg2_n("Bkg2_n", "Bkg2_n", dzero, m_b, s_b, a_b, n_b); 
  RooAddPdf Bkg_n("Bkg_n","Bkg_n",RooArgList(Bkg1_n,Bkg2_n),RooArgList(f_bkg));

//Full Model - N
  RooAddPdf Model_n("Model_n","Model_n",RooArgList(Sig_n,Bkg_n),RooArgList(N_n,N_nb));



  //CREATE INDEX CATEGORY AND JOIN  SAMPLEs
  //_____________________________________________________
  RooCategory sample("sample","sample");
  sample.defineType("pos");
  sample.defineType("neg");
    RooDataHist* combData =new RooDataHist("combData","combData",RooArgSet(dzero),Index(sample),Import("pos",*data_P),Import("neg",*data_N));


  RooSimultaneous simPdf("simPdf","simPdf",sample);
  simPdf.addPdf(Model_p,"pos");
  simPdf.addPdf(Model_n,"neg");
  //_____________________________________________________


 // Construct unbinned likelihood of model w.r.t. data
  RooAbsReal* nll = simPdf.createNLL(*combData) ;

  // I n t e r a c t i v e   m i n i m i z a t i o n ,   e r r o r   a n a l y s i s
  // -------------------------------------------------------------------------------

  // Create MINUIT interface object
  RooMinuit minu(*nll) ;

  // Activate verbose logging of MINUIT parameter space stepping
  minu.setVerbose(kTRUE) ;

  // Call MIGRAD to minimize the likelihood
  minu.migrad() ;

  // Print values of all paramaters, that reflect values (and error estimates)
  // that are back propagated from MINUIT
  simPdf.getParameters(dzero)->Print("s") ;

  // Disable verbose logging
  minu.setVerbose(kFALSE) ;

  // Run HESSE to calculate errors from d2L/dp2
  minu.hesse() ;

  // Print value (and error) of sigma_g2 parameter, that reflects
  // value and error back propagated from MINUIT
  Araw.Print() ;

  // Run MINOS on sigma_g2 parameter only
  minu.minos(Araw) ;

//Fit
//   RooFitResult* fitRes = simPdf.fitTo(*combData,Save(),Minos(kTRUE));


/*
  TLine *line = new TLine(1.68,0.0,2.06,0.0);

  //DeltaM PLOTING
  RooPlot *xframe_1 =dzero.frame(Bins(100),Title("D^{+} #rightarrow #pi^{0} #pi^{+}"));
//  RooPlot *xframe_1 =dzero.frame(Bins(38),Title("D^{+} #rightarrow #pi^{0} #pi^{+}"));
  combData->plotOn(xframe_1,Cut("sample==sample::pos"));
  simPdf.plotOn(xframe_1,Slice(sample,"pos"),ProjWData(sample,*combData));
    RooHist* hpull1 = xframe_1->pullHist() ;
    RooPlot* frame1 = dzero.frame(Title("Pull Distribution")) ;
    frame1->addPlotable(hpull1,"P") ;
    frame1->SetMaximum(6);
    frame1->SetMinimum(-6);
  cout<<" signalchi-2 xframe_1= "<<xframe_1->chiSquare()<<endl;
  simPdf.plotOn(xframe_1,Slice(sample,"pos"),Components("Sig_p"),ProjWData(sample,*combData),LineStyle(kDashed),LineColor(kRed));
  simPdf.plotOn(xframe_1,Slice(sample,"pos"),Components("Bkg_p"),ProjWData(sample,*combData),LineStyle(kDashed));
//  simPdf.plotOn(xframe_1,Slice(sample,"pos"),Components("Bkg2_p"),ProjWData(sample,*combData),LineStyle(kDashed),LineColor(kGreen));
    RooHist* hres1 = xframe_1->residHist() ;
    RooPlot* dframe1 = dzero.frame(Bins(100),Title(" ")) ;
    dframe1->addPlotable(hres1,"P") ;
    Sig_p.plotOn(dframe1);
    dframe1->SetMaximum(3900) ;
    dframe1->SetMinimum(-1000) ;
   Model_p.paramOn(xframe_1,data_P);

  RooPlot *xframe_2 = dzero.frame(Bins(100),Title("D^{-} #rightarrow #pi^{0} #pi^{-}"));
//  RooPlot *xframe_2 = dzero.frame(Bins(38),Title("D^{-} #rightarrow #pi^{0} #pi^{-}"));
  combData->plotOn(xframe_2,Cut("sample==sample::neg"));
  simPdf.plotOn(xframe_2,Slice(sample,"neg"),ProjWData(sample,*combData));
    RooHist* hpull2 = xframe_2->pullHist() ;
    RooPlot* frame2 = dzero.frame(Title("Pull Distribution")) ;
    frame2->addPlotable(hpull2,"P") ;
    frame2->SetMaximum(6);
    frame2->SetMinimum(-6);
  cout<<" signalchi-2 xframe_2= "<<xframe_2->chiSquare()<<endl;
  simPdf.plotOn(xframe_2,Slice(sample,"neg"),Components("Sig_n"),ProjWData(sample,*combData),LineStyle(kDashed),LineColor(kRed));
  simPdf.plotOn(xframe_2,Slice(sample,"neg"),Components("Bkg_n"),ProjWData(sample,*combData),LineStyle(kDashed));
//  simPdf.plotOn(xframe_2,Slice(sample,"neg"),Components("Bkg2_n"),ProjWData(sample,*combData),LineStyle(kDashed),LineColor(kGreen));
    RooHist* hres2 = xframe_2->residHist() ;
    RooPlot* dframe2 = dzero.frame(Bins(100),Title(" ")) ;
    dframe2->addPlotable(hres2,"P") ;
    Sig_n.plotOn(dframe2);
    dframe2->SetMaximum(3900) ;
    dframe2->SetMinimum(-1000) ;
     Model_n.paramOn(xframe_2,data_N); 


  TCanvas* can3 = new TCanvas("c3","c3") ;
  TPad *pad31 = new TPad("pad31", "The pad 80% of the height",0.0,0.0,0.5,1.0,0);
  TPad *pad32 = new TPad("pad32", "The pad 20% of the height",0.5,0.0,1.0,1.0,0);
    pad31->Draw();
    pad32->Draw();


pad31->cd();
TPad *pad31_m = new TPad("pad31_m", "The pad 80% of the height",0.0,0.2,1.0,1.0,0);
TPad *pad31_p = new TPad("pad31_p", "The pad 20% of the height",0.0,0.0,1.0,0.2,0);
    pad31_m->Draw();
    pad31_p->Draw();
pad32->cd();
TPad *pad32_m = new TPad("pad32_m", "The pad 80% of the height",0.0,0.2,1.0,1.0,0);
TPad *pad32_p = new TPad("pad32_p", "The pad 20% of the height",0.0,0.0,1.0,0.2,0);
    pad32_m->Draw();
    pad32_p->Draw();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas* can4 = new TCanvas("c4","c4",700,465) ;
  TPad *mad31 = new TPad("mad31", "The mad 80% of the height",0.0,0.0,0.5,1.0,0);
  TPad *mad32 = new TPad("mad32", "The mad 20% of the height",0.5,0.0,1.0,1.0,0);
    mad31->Draw();
    mad32->Draw();


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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

  pad31_m->cd() ; gPad->SetLeftMargin(0.15) ; TGaxis::SetMaxDigits(3); gPad->SetBottomMargin(0.15); xframe_1->Draw() ;
//  pad22->cd() ; gPad->SetLeftMargin(0.25) ; TGaxis::SetMaxDigits(2); xframe_4->GetYaxis()->SetTitleOffset(1.4) ; xframe_4->Draw() ;
  pad31_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame1->Draw() ;

  pad32_m->cd() ; gPad->SetLeftMargin(0.15) ; TGaxis::SetMaxDigits(3); gPad->SetBottomMargin(0.15); xframe_2->Draw() ;
  pad32_p->cd() ; gPad->SetLeftMargin(0.15) ; gPad->SetBottomMargin(0.15); frame2->Draw() ;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 mad31_m->cd() ; gPad->SetLeftMargin(0.15) ;gPad->SetRightMargin(0.01) ; TGaxis::SetMaxDigits(3); gPad->SetBottomMargin(0.15);gPad->SetTopMargin(0.05); dframe1->Draw() ;  line->Draw();
  mad31_p->cd() ; gPad->SetLeftMargin(0.15) ;gPad->SetRightMargin(0.01) ; gPad->SetBottomMargin(0.02); frame1->Draw() ;  line->Draw();

  mad32_m->cd() ; gPad->SetLeftMargin(0.01) ;gPad->SetRightMargin(0.15) ;  TGaxis::SetMaxDigits(3); gPad->SetBottomMargin(0.15);gPad->SetTopMargin(0.05); dframe2->Draw() ;  line->Draw();
  mad32_p->cd() ; gPad->SetLeftMargin(0.01) ;gPad->SetRightMargin(0.15) ;  gPad->SetBottomMargin(0.02); frame2->Draw() ;  line->Draw();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

//Float_t Asy, e_Asy, Nt e_Nt;
//Asy=Araw.getVal();
//e_Asy=Araw.getError();

//Nt=N_t.getVal();
//e_Nt=N_t.getError();

 result[0][ii]=Araw.getVal()*100;
 result[1][ii]=Araw.getError()*100;
 result[2][ii]=N_t.getVal();
 result[3][ii]=N_t.getError();

//cout<<"Araw = "<<Asy<<" +/- "<<e_Asy<<endl;

//cout<<"N_t = "<<Nt<<" +/- "<<e_Nt<<endl;



}




