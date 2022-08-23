#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <TF1.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TPad.h>
#include <TLine.h>
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooExponential.h"
#include "RooWorkspace.h"
#include "RooAddPdf.h"
#include "RooProdPdf.h"
#include "RooChebychev.h"
#include "TMinuit.h"
#include "./../../../../lib/setNCUStyle.C"
using namespace std;

const Int_t npars = 6.;

Double_t rootfitcPDF(double *x, double *par)
{
    // Double_t fit_val = (TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0])) + par[3] + par[4] * x[0] + par[5] * x[0];
    Double_t fit_val = (TMath::Exp(par[0] + par[1] * x[0] + par[2] * x[0] * x[0] + par[3] * x[0] * x[0] * x[0])) + par[4] + par[5] * x[0];
    return fit_val;
}

void FR_fit()
{

    //TVirtualFitter::SetDefaultFitter("Minuit");

    TFile *Top_fakerate_topfile = new TFile("./top_fakerate.root");

    TH1D *Top_nTrk_fakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_difeta_1"));
    TH1D *Top_nTrk_bfakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_1"));
    TH1D *Top_nTrk_cfakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_cfakeRate_difeta_1"));
    TH1D *Top_nTrk_lfakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_1"));
    TH1D *Top_nTrk_hfakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_hfakeRate_difeta_1"));

    TH1D *Top_nTrk_fakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_difeta_2"));
    TH1D *Top_nTrk_bfakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_2"));
    TH1D *Top_nTrk_cfakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_cfakeRate_difeta_2"));
    TH1D *Top_nTrk_lfakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_2"));
    TH1D *Top_nTrk_hfakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_hfakeRate_difeta_2"));

    TH1D *Top_nTrk_fakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_difeta_3"));
    TH1D *Top_nTrk_bfakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_3"));
    TH1D *Top_nTrk_cfakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_cfakeRate_difeta_3"));
    TH1D *Top_nTrk_lfakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_3"));
    TH1D *Top_nTrk_hfakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_hfakeRate_difeta_3"));

    // C r e a t e   m o d e l   a n d   d a t a s e t
    // -----------------------------------------------
    //TF1 *f1 = new TF1("f1", rootfitcPDF, 1., 20, npars);
    TF1 *f1 = new TF1("f1", rootfitcPDF, 1., 20, npars);

    //Top_nTrk_bfakeRate_difeta_1->Fit("f1", "MFR+");

    Top_nTrk_bfakeRate_difeta_2->Fit("pol5", "MF");


    Top_nTrk_bfakeRate_difeta_2->Draw();
    //cout << "chi value: " << f1->GetChisquare() << endl;
    //cout << "NDF : " << f1->GetNDF() << endl;
    // cout << "NDF : " << h_fake_rate->GetNbinsX() << endl;
    //cout << "chi square: " << f1->GetChisquare() / f1->GetNDF() << endl;
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1111);
}