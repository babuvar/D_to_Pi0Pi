/////////////////////////////////////////////////////////////////////////
//
// 'VALIDATION AND MC STUDIES' RooFit tutorial macro #801
// 
// A Toy Monte Carlo study that perform cycles of
// event generation and fittting
//
// 
/////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooMCStudy.h"
#include "RooPlot.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH2.h"
#include "RooFitResult.h"
#include "TStyle.h"
#include "TDirectory.h"

using namespace RooFit ;


void root_eg()
{
  // C r e a t e   m o d e l
  // -----------------------

  // Declare observable x
  RooRealVar x("x","x",0,10) ;
  x.setBins(40) ;

  // Create two Gaussian PDFs g1(x,mean1,sigma) anf g2(x,mean2,sigma) and their parameters
  RooRealVar mean("mean","mean of gaussians",5,0,10) ;
  RooRealVar sigma1("sigma1","width of gaussians",0.5,0,1.0);
  RooRealVar sigma2("sigma2","width of gaussians",1,0,2) ;

  RooGaussian sig1("sig1","Signal component 1",x,mean,sigma1) ;  
  RooGaussian sig2("sig2","Signal component 2",x,mean,sigma2) ;  
  
  // Build Chebychev polynomial p.d.f.  
  RooRealVar a0("a0","a0",0.5,0.,1.) ;
  RooRealVar a1("a1","a1",-0.2,-1,1.) ;
  RooChebychev bkg("bkg","Background",x,RooArgSet(a0,a1)) ;

  // Sum the signal components into a composite signal p.d.f.
  RooRealVar sig1frac("sig1frac","fraction of component 1 in signal",0.8,0.,1.) ;
  RooAddPdf sig("sig","Signal",RooArgList(sig1,sig2),sig1frac) ;

  // Sum the composite signal and background 
  RooRealVar nbkg("nbkg","number of background events,",150,0,1000) ;
  RooRealVar nsig("nsig","number of signal events",150,0,1000) ;
  RooAddPdf  model("model","g1+g2+a",RooArgList(bkg,sig),RooArgList(nbkg,nsig)) ;



  // C r e a t e   m a n a g e r
  // ---------------------------

  // Instantiate RooMCStudy manager on model with x as observable and given choice of fit options
  //
  // The Silence() option kills all messages below the PROGRESS level, leaving only a single message
  // per sample executed, and any error message that occur during fitting
  //
  // The Extended() option has two effects: 
  //    1) The extended ML term is included in the likelihood and 
  //    2) A poisson fluctuation is introduced on the number of generated events 
  //
  // The FitOptions() given here are passed to the fitting stage of each toy experiment.
  // If Save() is specified, the fit result of each experiment is saved by the manager  
  //
  // A Binned() option is added in this example to bin the data between generation and fitting
  // to speed up the study at the expemse of some precision

  RooMCStudy* mcstudy = new RooMCStudy(model,x,Binned(kTRUE),Silence(),Extended(),
				       FitOptions(Save(kTRUE),PrintEvalErrors(0))) ;
  

  // G e n e r a t e   a n d   f i t   e v e n t s
  // ---------------------------------------------

  // Generate and fit 1000 samples of Poisson(nExpected) events
  mcstudy->generateAndFit(500) ;



  // E x p l o r e   r e s u l t s   o f   s t u d y 
  // ------------------------------------------------

  // Make plots of the distributions of mean, the error on mean and the pull of mean
  RooPlot* frame3 = mcstudy->plotPull(mean,-4,4,40,kTRUE) ;
  RooPlot* frame1 = mcstudy->plotParam(mean,Bins(40)) ;
  RooPlot* frame2 = mcstudy->plotError(mean,Bins(40)) ;




//  RooPlot* frame4 = mcstudy->plotParam(sigma1,Bins(40)) ;
//  RooPlot* frame5 = mcstudy->plotError(sigma1,Bins(40)) ;
//  RooPlot* frame6 = mcstudy->plotPull(sigma1,Bins(40),FitGauss(kTRUE)) ;

//  RooPlot* frame7 = mcstudy->plotParam(sigma2,Bins(40)) ;
//  RooPlot* frame8 = mcstudy->plotError(sigma2,Bins(40)) ;
//  RooPlot* frame9 = mcstudy->plotPull(sigma2,Bins(40),FitGauss(kTRUE)) ;


  // Plot distribution of minimized likelihood
//  RooPlot* frame4 = mcstudy->plotNLL(Bins(40)) ;

  // Make some histograms from the parameter dataset
//  TH1* hh_cor_a0_s1f = mcstudy->fitParDataSet().createHistogram("hh",a1,YVar(sig1frac)) ;
//  TH1* hh_cor_a0_a1  = mcstudy->fitParDataSet().createHistogram("hh",a0,YVar(a1)) ;

  // Access some of the saved fit results from individual toys
//  TH2* corrHist000 = mcstudy->fitResult(0)->correlationHist("c000") ;
//  TH2* corrHist127 = mcstudy->fitResult(127)->correlationHist("c127") ;
//  TH2* corrHist953 = mcstudy->fitResult(953)->correlationHist("c953") ;



  // Draw all plots on a canvas
  gStyle->SetPalette(1) ;
  gStyle->SetOptStat(0) ;
  TCanvas* c = new TCanvas("rf801_mcstudy","rf801_mcstudy",900,900) ;
  c->Divide(2,2) ;
  c->cd(1) ; gPad->SetLeftMargin(0.15) ; frame1->GetYaxis()->SetTitleOffset(1.4) ; frame1->Draw() ;
  c->cd(2) ; gPad->SetLeftMargin(0.15) ; frame2->GetYaxis()->SetTitleOffset(1.4) ; frame2->Draw() ;
  c->cd(3) ; gPad->SetLeftMargin(0.15) ; frame3->GetYaxis()->SetTitleOffset(1.4) ; frame3->Draw() ;
//  c->cd(4) ; gPad->SetLeftMargin(0.15) ; frame4->GetYaxis()->SetTitleOffset(1.4) ; frame4->Draw() ;
//  c->cd(5) ; gPad->SetLeftMargin(0.15) ; frame5->GetYaxis()->SetTitleOffset(1.4) ; frame5->Draw() ;
//  c->cd(6) ; gPad->SetLeftMargin(0.15) ; frame6->GetYaxis()->SetTitleOffset(1.4) ; frame6->Draw() ;
//  c->cd(7) ; gPad->SetLeftMargin(0.15) ; frame7->GetYaxis()->SetTitleOffset(1.4) ; frame7->Draw() ;
//  c->cd(8) ; gPad->SetLeftMargin(0.15) ; frame8->GetYaxis()->SetTitleOffset(1.4) ; frame8->Draw() ;
//  c->cd(9) ; gPad->SetLeftMargin(0.15) ; frame9->GetYaxis()->SetTitleOffset(1.4) ; frame9->Draw() ;


/*
  c->cd(4) ; gPad->SetLeftMargin(0.15) ; frame4->GetYaxis()->SetTitleOffset(1.4) ; frame4->Draw() ;
  c->cd(5) ; gPad->SetLeftMargin(0.15) ; hh_cor_a0_s1f->GetYaxis()->SetTitleOffset(1.4) ; hh_cor_a0_s1f->Draw("box") ;
  c->cd(6) ; gPad->SetLeftMargin(0.15) ; hh_cor_a0_a1->GetYaxis()->SetTitleOffset(1.4) ; hh_cor_a0_a1->Draw("box") ;
  c->cd(7) ; gPad->SetLeftMargin(0.15) ; corrHist000->GetYaxis()->SetTitleOffset(1.4) ; corrHist000->Draw("colz") ;
  c->cd(8) ; gPad->SetLeftMargin(0.15) ; corrHist127->GetYaxis()->SetTitleOffset(1.4) ; corrHist127->Draw("colz") ;
  c->cd(9) ; gPad->SetLeftMargin(0.15) ; corrHist953->GetYaxis()->SetTitleOffset(1.4) ; corrHist953->Draw("colz") ;
*/
  // Make RooMCStudy object available on command line after
  // macro finishes
//  gDirectory->Add(mcstudy);
}












