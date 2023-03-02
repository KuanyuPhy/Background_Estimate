#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TF1.h>
#include <TH3D.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TH2.h>
#include <TAxis.h>
#include <TLine.h>
#include <TError.h>
#include "TLegend.h"
#include <cstring>

using namespace std;

void h_Style_Setting(TH1D *h_tmp, const int h_Style)
{
    h_tmp->SetLineWidth(2);
    h_tmp->SetLineColor(h_Style);
}

void quick_draw_csv(TString file = "./ee_Sig_jetcsv.root")
{
    TFile *Sigfile = TFile::Open(file);
    TH1D *h_Mx2_1_jetcsv = ((TH1D *)Sigfile->Get("h_Mx2_1_jetcsv"));
    TH1D *h_Mx2_50_jetcsv = ((TH1D *)Sigfile->Get("h_Mx2_50_jetcsv"));
    TH1D *h_Mx2_150_jetcsv = ((TH1D *)Sigfile->Get("h_Mx2_150_jetcsv"));

    h_Style_Setting(h_Mx2_1_jetcsv, kRed);
    h_Style_Setting(h_Mx2_50_jetcsv, kGray + 2);
    h_Style_Setting(h_Mx2_150_jetcsv, kBlue);

    h_Mx2_1_jetcsv->GetXaxis()->SetTitle("jetcsv");
    h_Mx2_50_jetcsv->GetXaxis()->SetTitle("jetcsv");
    h_Mx2_150_jetcsv->GetXaxis()->SetTitle("jetcsv");

    h_Mx2_1_jetcsv->GetYaxis()->SetTitle("nJet");
    h_Mx2_50_jetcsv->GetYaxis()->SetTitle("nJet");
    h_Mx2_150_jetcsv->GetYaxis()->SetTitle("nJet");

    h_Mx2_150_jetcsv->Draw("h");

    cout << "Totel jet = "<< h_Mx2_150_jetcsv->Integral() << endl;

    TLegend *l1 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.03);
    //l1->AddEntry(h_Mx2_1_jetcsv, "x2 = 1 GeV, ctau = 1 mm", "l");
    //l1->AddEntry(h_Mx2_50_jetcsv, "x2 = 50 GeV, ctau = 10 mm", "l");
    l1->AddEntry(h_Mx2_150_jetcsv, "x2 = 150 GeV, ctau = 1 mm", "l");
    l1->Draw();

    gStyle->SetOptStat(0);
}