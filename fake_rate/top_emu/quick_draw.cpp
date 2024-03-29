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
Double_t Ratio(Double_t *x, Double_t *par)
{
    return (par[0] + par[1] * x[0]);
}

void quick_draw(TString file = "./Ratio_apply.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *h_Top_trk_bybin_CR = ((TH1D *)Topfile->Get("h_Top_trk_bybin_CR"));
    TH1D *h_Top_btrk_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_bybin_CR"));
    TH1D *h_Top_ltrk_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_bybin_CR"));
    TH1D *h_Top_trk_SR = ((TH1D *)Topfile->Get("h_Top_trk_SR"));
    TH1D *h_Top_btrk_SR = ((TH1D *)Topfile->Get("h_Top_btrk_SR"));
    TH1D *h_Top_ltrk_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_SR"));
    TH1D *h_Top_trk_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_trk_region1_bybin_CR"));
    TH1D *h_Top_trk_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_trk_region2_bybin_CR"));
    TH1D *h_Top_trk_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_trk_region3_bybin_CR"));
    TH1D *h_Top_btrk_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_region1_bybin_CR"));
    TH1D *h_Top_btrk_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_region2_bybin_CR"));
    TH1D *h_Top_btrk_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_region3_bybin_CR"));
    TH1D *h_Top_ltrk_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_region1_bybin_CR"));
    TH1D *h_Top_ltrk_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_region2_bybin_CR"));
    TH1D *h_Top_ltrk_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_region3_bybin_CR"));

    TH1D *h_Top_trk_region1_SR = ((TH1D *)Topfile->Get("h_Top_trk_region1_SR"));
    TH1D *h_Top_trk_region2_SR = ((TH1D *)Topfile->Get("h_Top_trk_region2_SR"));
    TH1D *h_Top_trk_region3_SR = ((TH1D *)Topfile->Get("h_Top_trk_region3_SR"));
    TH1D *h_Top_btrk_region1_SR = ((TH1D *)Topfile->Get("h_Top_btrk_region1_SR"));
    TH1D *h_Top_btrk_region2_SR = ((TH1D *)Topfile->Get("h_Top_btrk_region2_SR"));
    TH1D *h_Top_btrk_region3_SR = ((TH1D *)Topfile->Get("h_Top_btrk_region3_SR"));
    TH1D *h_Top_ltrk_region1_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_region1_SR"));
    TH1D *h_Top_ltrk_region2_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_region2_SR"));
    TH1D *h_Top_ltrk_region3_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_region3_SR"));

    TH1D *h_Top_JetPt_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_bybin_CR"));
    TH1D *h_Top_bJetPt_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_bybin_CR"));
    TH1D *h_Top_lJetPt_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_bybin_CR"));
    TH1D *h_Top_JetPt_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_SR"));
    TH1D *h_Top_bJetPt_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_SR"));
    TH1D *h_Top_lJetPt_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_SR"));
    TH1D *h_Top_JetPt_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_region1_bybin_CR"));
    TH1D *h_Top_JetPt_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_region2_bybin_CR"));
    TH1D *h_Top_JetPt_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_region3_bybin_CR"));
    TH1D *h_Top_bJetPt_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region1_bybin_CR"));
    TH1D *h_Top_bJetPt_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region2_bybin_CR"));
    TH1D *h_Top_bJetPt_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region3_bybin_CR"));
    TH1D *h_Top_lJetPt_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region1_bybin_CR"));
    TH1D *h_Top_lJetPt_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region2_bybin_CR"));
    TH1D *h_Top_lJetPt_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region3_bybin_CR"));

    TH1D *h_Top_JetPt_region1_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_region1_SR"));
    TH1D *h_Top_JetPt_region2_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_region2_SR"));
    TH1D *h_Top_JetPt_region3_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_region3_SR"));
    TH1D *h_Top_bJetPt_region1_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region1_SR"));
    TH1D *h_Top_bJetPt_region2_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region2_SR"));
    TH1D *h_Top_bJetPt_region3_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region3_SR"));
    TH1D *h_Top_lJetPt_region1_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region1_SR"));
    TH1D *h_Top_lJetPt_region2_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region2_SR"));
    TH1D *h_Top_lJetPt_region3_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region3_SR"));

    //--------------------
    TH1D *h_Top_JetEta_SR = ((TH1D *)Topfile->Get("h_Top_JetEta_SR"));
    TH1D *h_Top_bJetEta_SR = ((TH1D *)Topfile->Get("h_Top_bJetEta_SR"));
    TH1D *h_Top_lJetEta_SR = ((TH1D *)Topfile->Get("h_Top_lJetEta_SR"));

    TH1D *h_Top_bJetEta_diffFR_CR = ((TH1D *)Topfile->Get("h_Top_bJetEta_diffFR_CR"));
    TH1D *h_Top_lJetEta_diffFR_CR = ((TH1D *)Topfile->Get("h_Top_lJetEta_diffFR_CR"));
    //--------------------------
    // For MET fake rate result
    //--------------------------
    TH1D *h_Top_btrk_MET_region1_SR = ((TH1D *)Topfile->Get("h_Top_btrk_MET_region1_SR"));
    TH1D *h_Top_btrk_MET_region2_SR = ((TH1D *)Topfile->Get("h_Top_btrk_MET_region2_SR"));
    TH1D *h_Top_btrk_MET_region3_SR = ((TH1D *)Topfile->Get("h_Top_btrk_MET_region3_SR"));
    TH1D *h_Top_ltrk_MET_region1_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_MET_region1_SR"));
    TH1D *h_Top_ltrk_MET_region2_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_MET_region2_SR"));
    TH1D *h_Top_ltrk_MET_region3_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_MET_region3_SR"));

    TH1D *h_Top_btrk_MET_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_MET_region1_bybin_CR"));
    TH1D *h_Top_btrk_MET_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_MET_region2_bybin_CR"));
    TH1D *h_Top_btrk_MET_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_MET_region3_bybin_CR"));
    TH1D *h_Top_ltrk_MET_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_MET_region1_bybin_CR"));
    TH1D *h_Top_ltrk_MET_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_MET_region2_bybin_CR"));
    TH1D *h_Top_ltrk_MET_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_MET_region3_bybin_CR"));

    TH1D *h_Top_bJetPt_MET_region1_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_MET_region1_SR"));
    TH1D *h_Top_bJetPt_MET_region2_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_MET_region2_SR"));
    TH1D *h_Top_bJetPt_MET_region3_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_MET_region3_SR"));
    TH1D *h_Top_lJetPt_MET_region1_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_MET_region1_SR"));
    TH1D *h_Top_lJetPt_MET_region2_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_MET_region2_SR"));
    TH1D *h_Top_lJetPt_MET_region3_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_MET_region3_SR"));

    TH1D *h_Top_bJetPt_MET_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_MET_region1_bybin_CR"));
    TH1D *h_Top_bJetPt_MET_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_MET_region2_bybin_CR"));
    TH1D *h_Top_bJetPt_MET_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_MET_region3_bybin_CR"));
    TH1D *h_Top_lJetPt_MET_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_MET_region1_bybin_CR"));
    TH1D *h_Top_lJetPt_MET_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_MET_region2_bybin_CR"));
    TH1D *h_Top_lJetPt_MET_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_MET_region3_bybin_CR"));

    TH1D *h_Top_bJetEta_MET_SR = ((TH1D *)Topfile->Get("h_Top_bJetEta_MET_SR"));
    TH1D *h_Top_lJetEta_MET_SR = ((TH1D *)Topfile->Get("h_Top_lJetEta_MET_SR"));

    TH1D *h_Top_bJetEta_MET_diffFR_CR = ((TH1D *)Topfile->Get("h_Top_bJetEta_MET_diffFR_CR"));
    TH1D *h_Top_lJetEta_MET_diffFR_CR = ((TH1D *)Topfile->Get("h_Top_lJetEta_MET_diffFR_CR"));

    //--------------------------
    // For Signal Region
    //--------------------------
    // 1. nTrack
    // not consider eta fake rate
    h_Style_Setting(h_Top_trk_SR, kRed);
    h_Style_Setting(h_Top_btrk_SR, kRed);
    h_Style_Setting(h_Top_ltrk_SR, kRed);
    // consider eta fake rate
    h_Style_Setting(h_Top_trk_region1_SR, kRed);
    h_Style_Setting(h_Top_trk_region2_SR, kRed);
    h_Style_Setting(h_Top_trk_region3_SR, kRed);

    h_Style_Setting(h_Top_btrk_region1_SR, kRed);
    h_Style_Setting(h_Top_btrk_region2_SR, kRed);
    h_Style_Setting(h_Top_btrk_region3_SR, kRed);

    h_Style_Setting(h_Top_ltrk_region1_SR, kRed);
    h_Style_Setting(h_Top_ltrk_region2_SR, kRed);
    h_Style_Setting(h_Top_ltrk_region3_SR, kRed);

    h_Style_Setting(h_Top_btrk_MET_region1_SR, kRed);
    h_Style_Setting(h_Top_btrk_MET_region2_SR, kRed);
    h_Style_Setting(h_Top_btrk_MET_region3_SR, kRed);

    h_Style_Setting(h_Top_ltrk_MET_region1_SR, kRed);
    h_Style_Setting(h_Top_ltrk_MET_region2_SR, kRed);
    h_Style_Setting(h_Top_ltrk_MET_region3_SR, kRed);

    // 2. JetPt
    // not consider eta fake rate
    h_Style_Setting(h_Top_JetPt_SR, kRed);
    h_Style_Setting(h_Top_bJetPt_SR, kRed);
    h_Style_Setting(h_Top_lJetPt_SR, kRed);
    // consider eta fake rate
    h_Style_Setting(h_Top_JetPt_region1_SR, kRed);
    h_Style_Setting(h_Top_JetPt_region2_SR, kRed);
    h_Style_Setting(h_Top_JetPt_region3_SR, kRed);

    h_Style_Setting(h_Top_bJetPt_region1_SR, kRed);
    h_Style_Setting(h_Top_bJetPt_region2_SR, kRed);
    h_Style_Setting(h_Top_bJetPt_region3_SR, kRed);

    h_Style_Setting(h_Top_lJetPt_region1_SR, kRed);
    h_Style_Setting(h_Top_lJetPt_region2_SR, kRed);
    h_Style_Setting(h_Top_lJetPt_region3_SR, kRed);

    h_Style_Setting(h_Top_bJetPt_MET_region1_SR, kRed);
    h_Style_Setting(h_Top_bJetPt_MET_region2_SR, kRed);
    h_Style_Setting(h_Top_bJetPt_MET_region3_SR, kRed);

    h_Style_Setting(h_Top_lJetPt_MET_region1_SR, kRed);
    h_Style_Setting(h_Top_lJetPt_MET_region2_SR, kRed);
    h_Style_Setting(h_Top_lJetPt_MET_region3_SR, kRed);

    // 3. JetEta
    //  not consider eta fake rate
    h_Style_Setting(h_Top_JetEta_SR, kRed);
    h_Style_Setting(h_Top_bJetEta_SR, kRed);
    h_Style_Setting(h_Top_lJetEta_SR, kRed);

    h_Style_Setting(h_Top_bJetEta_MET_SR, kRed);
    h_Style_Setting(h_Top_lJetEta_MET_SR, kRed);
    //--------------------------
    // For Control Region
    //--------------------------
    // 1. nTrack
    // not consider eta fake rate
    h_Style_Setting(h_Top_trk_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_btrk_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_ltrk_bybin_CR, kAzure + 4);

    // consider eta fake rate
    h_Style_Setting(h_Top_trk_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_trk_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_trk_region3_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_btrk_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_btrk_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_btrk_region3_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_ltrk_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_ltrk_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_ltrk_region3_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_btrk_MET_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_btrk_MET_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_btrk_MET_region3_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_ltrk_MET_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_ltrk_MET_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_ltrk_MET_region3_bybin_CR, kAzure + 4);

    // 2. Jet Pt
    // not consider eta fake rate
    h_Style_Setting(h_Top_JetPt_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_bJetPt_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetPt_bybin_CR, kAzure + 4);

    // consider eta fake rate
    h_Style_Setting(h_Top_JetPt_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_JetPt_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_JetPt_region3_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_bJetPt_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_bJetPt_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_bJetPt_region3_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_lJetPt_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetPt_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetPt_region3_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_bJetPt_MET_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_bJetPt_MET_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_bJetPt_MET_region3_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_lJetPt_MET_region1_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetPt_MET_region2_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetPt_MET_region3_bybin_CR, kAzure + 4);

    // 3. Jet Eta
    h_Style_Setting(h_Top_bJetEta_diffFR_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetEta_diffFR_CR, kAzure + 4);

    h_Style_Setting(h_Top_bJetEta_MET_diffFR_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetEta_MET_diffFR_CR, kAzure + 4);

    int W = 600;
    int H = 600;

    int H_ref = 600;
    int W_ref = 600;

    float T = 0.08 * H_ref;
    float B = 0.12 * H_ref;
    float L = 0.12 * W_ref;
    float R = 0.04 * W_ref;

    auto c1 = new TCanvas("c1", "c1", 50, 50, W, H);

    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    c1->SetLeftMargin(L / W);
    c1->SetRightMargin(R / W);
    c1->SetTopMargin(T / H);
    c1->SetBottomMargin(B / H);
    c1->SetTickx(0);
    c1->SetTicky(0);

    c1->Divide(1, 2);

    // For ntrk
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg1_T_P_ratio = (TH1D *)h_Top_btrk_region1_SR->Clone("h_btrk_rg1_T_P_ratio");
    h_btrk_rg1_T_P_ratio->Divide(h_Top_btrk_region1_SR, h_Top_btrk_region1_bybin_CR, 1, 1);

    h_Top_btrk_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region1_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_btrk_region1_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_btrk_region1_SR->Draw();
    h_Top_btrk_region1_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region1_SR, "True Background", "El");
    l0->AddEntry(h_Top_btrk_region1_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg1_T_P_ratio->SetLineColor(kBlack);

    h_btrk_rg1_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg1_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_btrk_rg1_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_btrk_rg1_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg1_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg1_xmin = h_Top_btrk_region1_SR->GetXaxis()->GetXmin();
    Double_t btrk_rg1_xmax = h_Top_btrk_region1_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg1_xmin, btrk_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_btrk_rg1_T_P_ratio->Fit("f1", "MFR");

    h_btrk_rg1_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg2_T_P_ratio = (TH1D *)h_Top_btrk_region2_SR->Clone("h_btrk_rg2_T_P_ratio");
    h_btrk_rg2_T_P_ratio->Divide(h_Top_btrk_region2_SR, h_Top_btrk_region2_bybin_CR, 1, 1);

    h_Top_btrk_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region2_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_btrk_region2_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_btrk_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_btrk_region2_SR->Draw();
    h_Top_btrk_region2_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region2_SR, "True Background", "El");
    l0->AddEntry(h_Top_btrk_region2_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg2_T_P_ratio->SetLineColor(kBlack);

    h_btrk_rg2_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg2_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_btrk_rg2_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_btrk_rg2_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg2_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg2_xmin = h_Top_btrk_region2_SR->GetXaxis()->GetXmin();
    Double_t btrk_rg2_xmax = h_Top_btrk_region2_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg2_xmin, btrk_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_btrk_rg2_T_P_ratio->Fit("f1", "MFR");

    h_btrk_rg2_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg3_T_P_ratio = (TH1D *)h_Top_btrk_region3_SR->Clone("h_btrk_rg3_T_P_ratio");
    h_btrk_rg3_T_P_ratio->Divide(h_Top_btrk_region3_SR, h_Top_btrk_region3_bybin_CR, 1, 1);

    h_Top_btrk_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region3_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_btrk_region3_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_btrk_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_btrk_region3_SR->Draw();
    h_Top_btrk_region3_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region3_SR, "True Background", "El");
    l0->AddEntry(h_Top_btrk_region3_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg3_T_P_ratio->SetLineColor(kBlack);

    h_btrk_rg3_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg3_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_btrk_rg3_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_btrk_rg3_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg3_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_btrk_rg3_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg3_xmin = h_Top_btrk_region3_SR->GetXaxis()->GetXmin();
    Double_t btrk_rg3_xmax = h_Top_btrk_region3_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg3_xmin, btrk_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_btrk_rg3_T_P_ratio->Fit("f1", "MFR");

    h_btrk_rg3_T_P_ratio->Draw();
    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg1_T_P_ratio = (TH1D *)h_Top_ltrk_region1_SR->Clone("h_ltrk_rg1_T_P_ratio");
    h_ltrk_rg1_T_P_ratio->Divide(h_Top_ltrk_region1_SR, h_Top_ltrk_region1_bybin_CR, 1, 1);

    h_Top_ltrk_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region1_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_ltrk_region1_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_ltrk_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_ltrk_region1_SR->Draw();
    h_Top_ltrk_region1_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region1_SR, "True Background", "El");
    l0->AddEntry(h_Top_ltrk_region1_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg1_T_P_ratio->SetLineColor(kBlack);

    h_ltrk_rg1_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg1_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_ltrk_rg1_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ltrk_rg1_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg1_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ltrk_rg1_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg1_xmin = h_Top_ltrk_region1_SR->GetXaxis()->GetXmin();
    Double_t ltrk_rg1_xmax = h_Top_ltrk_region1_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg1_xmin, ltrk_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_ltrk_rg1_T_P_ratio->Fit("f1", "MFR");

    h_ltrk_rg1_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg2_T_P_ratio = (TH1D *)h_Top_ltrk_region2_SR->Clone("h_ltrk_rg2_T_P_ratio");
    h_ltrk_rg2_T_P_ratio->Divide(h_Top_ltrk_region2_SR, h_Top_ltrk_region2_bybin_CR, 1, 1);

    h_Top_ltrk_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region2_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_ltrk_region2_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_ltrk_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_ltrk_region2_SR->Draw();
    h_Top_ltrk_region2_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region2_SR, "True Background", "El");
    l0->AddEntry(h_Top_ltrk_region2_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg2_T_P_ratio->SetLineColor(kBlack);

    h_ltrk_rg2_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg2_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_ltrk_rg2_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ltrk_rg2_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg2_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ltrk_rg2_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg2_xmin = h_Top_ltrk_region2_SR->GetXaxis()->GetXmin();
    Double_t ltrk_rg2_xmax = h_Top_ltrk_region2_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg2_xmin, ltrk_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_ltrk_rg2_T_P_ratio->Fit("f1", "MFR");

    h_ltrk_rg2_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg3_T_P_ratio = (TH1D *)h_Top_ltrk_region3_SR->Clone("h_ltrk_rg3_T_P_ratio");
    h_ltrk_rg3_T_P_ratio->Divide(h_Top_ltrk_region3_SR, h_Top_ltrk_region3_bybin_CR, 1, 1);

    h_Top_ltrk_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region3_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_ltrk_region3_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_ltrk_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_ltrk_region3_SR->Draw();
    h_Top_ltrk_region3_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region3_SR, "True Background", "El");
    l0->AddEntry(h_Top_ltrk_region3_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg3_T_P_ratio->SetLineColor(kBlack);

    h_ltrk_rg3_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg3_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_ltrk_rg3_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ltrk_rg3_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg3_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ltrk_rg3_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg3_xmin = h_Top_ltrk_region3_SR->GetXaxis()->GetXmin();
    Double_t ltrk_rg3_xmax = h_Top_ltrk_region3_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg3_xmin, ltrk_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_ltrk_rg3_T_P_ratio->Fit("f1", "MFR");

    h_ltrk_rg3_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_rg1_T_P_ratio = (TH1D *)h_Top_bJetPt_region1_SR->Clone("h_bJetPt_rg1_T_P_ratio");
    h_bJetPt_rg1_T_P_ratio->Divide(h_Top_bJetPt_region1_SR, h_Top_bJetPt_region1_bybin_CR, 1, 1);

    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitleSize(0.06);

    // h_Top_bJetPt_region1_SR->GetXaxis()->SetRangeUser(1, 25);
    // h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetPt_region1_SR->Draw();
    h_Top_bJetPt_region1_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_region1_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetPt_region1_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_rg1_T_P_ratio->SetLineColor(kBlack);

    h_bJetPt_rg1_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_rg1_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetPt_rg1_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetPt_rg1_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetPt_rg1_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetPt_rg1_xmin = h_Top_bJetPt_region1_SR->GetXaxis()->GetXmin();
    Double_t bJetPt_rg1_xmax = h_Top_bJetPt_region1_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetPt_rg1_xmin, bJetPt_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_bJetPt_rg1_T_P_ratio->Fit("f1", "MFR");

    h_bJetPt_rg1_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_rg2_T_P_ratio = (TH1D *)h_Top_bJetPt_region2_SR->Clone("h_bJetPt_rg2_T_P_ratio");
    h_bJetPt_rg2_T_P_ratio->Divide(h_Top_bJetPt_region2_SR, h_Top_bJetPt_region2_bybin_CR, 1, 1);

    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitleSize(0.06);

    // h_Top_bJetPt_region2_SR->GetXaxis()->SetRangeUser(1, 25);
    // h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetPt_region2_SR->Draw();
    h_Top_bJetPt_region2_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_region2_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetPt_region2_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_rg2_T_P_ratio->SetLineColor(kBlack);

    h_bJetPt_rg2_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_rg2_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetPt_rg2_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetPt_rg2_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetPt_rg2_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetPt_rg2_xmin = h_Top_bJetPt_region2_SR->GetXaxis()->GetXmin();
    Double_t bJetPt_rg2_xmax = h_Top_bJetPt_region2_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetPt_rg2_xmin, bJetPt_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_bJetPt_rg2_T_P_ratio->Fit("f1", "MFR");

    h_bJetPt_rg2_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_rg3_T_P_ratio = (TH1D *)h_Top_bJetPt_region3_SR->Clone("h_bJetPt_rg3_T_P_ratio");
    h_bJetPt_rg3_T_P_ratio->Divide(h_Top_bJetPt_region3_SR, h_Top_bJetPt_region3_bybin_CR, 1, 1);

    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitleSize(0.06);

    // h_Top_bJetPt_region3_SR->GetXaxis()->SetRangeUser(1, 25);
    // h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetPt_region3_SR->Draw();
    h_Top_bJetPt_region3_bybin_CR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_region3_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetPt_region3_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_rg3_T_P_ratio->SetLineColor(kBlack);

    h_bJetPt_rg3_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_rg3_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetPt_rg3_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetPt_rg3_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetPt_rg3_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetPt_rg3_xmin = h_Top_bJetPt_region3_SR->GetXaxis()->GetXmin();
    Double_t bJetPt_rg3_xmax = h_Top_bJetPt_region3_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetPt_rg3_xmin, bJetPt_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_bJetPt_rg3_T_P_ratio->Fit("f1", "MFR");

    h_bJetPt_rg3_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_rg1_T_P_ratio = (TH1D *)h_Top_lJetPt_region1_SR->Clone("h_lJetPt_rg1_T_P_ratio");
    h_lJetPt_rg1_T_P_ratio->Divide(h_Top_lJetPt_region1_SR, h_Top_lJetPt_region1_bybin_CR, 1, 1);

    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitleSize(0.06);
    //h_Top_lJetPt_region1_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetPt_region1_SR->Draw();
    h_Top_lJetPt_region1_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_region1_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetPt_region1_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_rg1_T_P_ratio->SetLineColor(kBlack);

    h_lJetPt_rg1_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_rg1_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetPt_rg1_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetPt_rg1_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetPt_rg1_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    //h_lJetPt_rg1_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetPt_rg1_xmin = h_Top_lJetPt_region1_SR->GetXaxis()->GetXmin();
    Double_t lJetPt_rg1_xmax = h_Top_lJetPt_region1_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetPt_rg1_xmin, lJetPt_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_lJetPt_rg1_T_P_ratio->Fit("f1", "MFR");

    h_lJetPt_rg1_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_rg2_T_P_ratio = (TH1D *)h_Top_lJetPt_region2_SR->Clone("h_lJetPt_rg2_T_P_ratio");
    h_lJetPt_rg2_T_P_ratio->Divide(h_Top_lJetPt_region2_SR, h_Top_lJetPt_region2_bybin_CR, 1, 1);

    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitleSize(0.06);
    //h_Top_lJetPt_region2_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetPt_region2_SR->Draw("");
    h_Top_lJetPt_region2_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_region2_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetPt_region2_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_rg2_T_P_ratio->SetLineColor(kBlack);

    h_lJetPt_rg2_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_rg2_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetPt_rg2_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetPt_rg2_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetPt_rg2_T_P_ratio->GetYaxis()->SetRangeUser(0, 3);
    //h_lJetPt_rg2_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetPt_rg2_xmin = h_Top_lJetPt_region2_SR->GetXaxis()->GetXmin();
    Double_t lJetPt_rg2_xmax = h_Top_lJetPt_region2_SR->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetPt_rg2_xmin, lJetPt_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_lJetPt_rg2_T_P_ratio->Fit("f1", "MFR");

    h_lJetPt_rg2_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_rg3_T_P_ratio = (TH1D *)h_Top_lJetPt_region3_SR->Clone("h_lJetPt_rg3_T_P_ratio");
    h_lJetPt_rg3_T_P_ratio->Divide(h_Top_lJetPt_region3_SR, h_Top_lJetPt_region3_bybin_CR, 1, 1);

    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitleSize(0.06);
    //h_Top_lJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetPt_region3_SR->Draw("");
    h_Top_lJetPt_region3_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_region3_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetPt_region3_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_rg3_T_P_ratio->SetLineColor(kBlack);

    h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_rg3_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetPt_rg3_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetPt_rg3_T_P_ratio->GetYaxis()->SetRangeUser(0, 3);
    //h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetPt_rg3_xmin = h_lJetPt_rg3_T_P_ratio->GetXaxis()->GetXmin();
    Double_t lJetPt_rg3_xmax = h_lJetPt_rg3_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetPt_rg3_xmin, lJetPt_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_lJetPt_rg3_T_P_ratio->Fit("f1", "MFR");

    h_lJetPt_rg3_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetEta_T_P_ratio = (TH1D *)h_Top_bJetEta_SR->Clone("h_bJetEta_T_P_ratio");
    h_bJetEta_T_P_ratio->Divide(h_Top_bJetEta_SR, h_Top_bJetEta_diffFR_CR, 1, 1);

    h_Top_bJetEta_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetEta_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetEta_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_lJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetEta_SR->Draw("");
    h_Top_bJetEta_diffFR_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetEta_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetEta_diffFR_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetEta_T_P_ratio->SetLineColor(kBlack);

    h_bJetEta_T_P_ratio->GetXaxis()->SetTitle("Jet #eta");
    h_bJetEta_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetEta_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetEta_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetEta_T_P_ratio->GetYaxis()->SetRangeUser(0, 3);
    // h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetEta_xmin = h_bJetEta_T_P_ratio->GetXaxis()->GetXmin();
    Double_t bJetEta_xmax = h_bJetEta_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetEta_xmin, bJetEta_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_bJetEta_T_P_ratio->Fit("f1", "MFR");

    h_bJetEta_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();

    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetEta_T_P_ratio = (TH1D *)h_Top_lJetEta_SR->Clone("h_lJetEta_T_P_ratio");
    h_lJetEta_T_P_ratio->Divide(h_Top_lJetEta_SR, h_Top_lJetEta_diffFR_CR, 1, 1);

    h_Top_lJetEta_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetEta_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_lJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetEta_SR->Draw("");
    h_Top_lJetEta_diffFR_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetEta_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetEta_diffFR_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetEta_T_P_ratio->SetLineColor(kBlack);

    h_lJetEta_T_P_ratio->GetXaxis()->SetTitle("Jet #eta");
    h_lJetEta_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetEta_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetEta_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetEta_T_P_ratio->GetYaxis()->SetRangeUser(0, 3);
    // h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetEta_xmin = h_lJetEta_T_P_ratio->GetXaxis()->GetXmin();
    Double_t lJetEta_xmax = h_lJetEta_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetEta_xmin, lJetEta_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_lJetEta_T_P_ratio->Fit("f1", "MFR");

    h_lJetEta_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_MET_rg1_T_P_ratio = (TH1D *)h_Top_btrk_MET_region1_SR->Clone("h_btrk_MET_rg1_T_P_ratio");
    h_btrk_MET_rg1_T_P_ratio->Divide(h_Top_btrk_MET_region1_SR, h_Top_btrk_MET_region1_bybin_CR, 1, 1);

    h_Top_btrk_MET_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_MET_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_MET_region1_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_btrk_MET_region1_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_btrk_MET_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    // h_Top_btrk_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_btrk_MET_region1_SR->Draw("");
    h_Top_btrk_MET_region1_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_MET_region1_SR, "True Background", "El");
    l0->AddEntry(h_Top_btrk_MET_region1_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_MET_rg1_T_P_ratio->SetLineColor(kBlack);

    h_btrk_MET_rg1_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_MET_rg1_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_btrk_MET_rg1_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_btrk_MET_rg1_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_MET_rg1_T_P_ratio->GetYaxis()->SetRangeUser(0, 3);
    h_btrk_MET_rg1_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg1_xmin = h_btrk_MET_rg1_T_P_ratio->GetXaxis()->GetXmin();
    Double_t btrk_rg1_xmax = h_btrk_MET_rg1_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg1_xmin, btrk_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_btrk_MET_rg1_T_P_ratio->Fit("f1", "MFR");

    h_btrk_MET_rg1_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_MET_rg2_T_P_ratio = (TH1D *)h_Top_btrk_MET_region2_SR->Clone("h_btrk_MET_rg2_T_P_ratio");
    h_btrk_MET_rg2_T_P_ratio->Divide(h_Top_btrk_MET_region2_SR, h_Top_btrk_MET_region2_bybin_CR, 1, 1);

    h_Top_btrk_MET_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_MET_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_MET_region2_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_btrk_MET_region2_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_btrk_MET_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    // h_Top_btrk_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_btrk_MET_region2_SR->Draw("");
    h_Top_btrk_MET_region2_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_MET_region2_SR, "True Background", "El");
    l0->AddEntry(h_Top_btrk_MET_region2_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_MET_rg2_T_P_ratio->SetLineColor(kBlack);

    h_btrk_MET_rg2_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_MET_rg2_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_btrk_MET_rg2_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_btrk_MET_rg2_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_MET_rg2_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_btrk_MET_rg2_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg2_xmin = h_btrk_MET_rg2_T_P_ratio->GetXaxis()->GetXmin();
    Double_t btrk_rg2_xmax = h_btrk_MET_rg2_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg2_xmin, btrk_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_btrk_MET_rg2_T_P_ratio->Fit("f1", "MFR");

    h_btrk_MET_rg2_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_MET_rg3_T_P_ratio = (TH1D *)h_Top_btrk_MET_region3_SR->Clone("h_btrk_MET_rg3_T_P_ratio");
    h_btrk_MET_rg3_T_P_ratio->Divide(h_Top_btrk_MET_region3_SR, h_Top_btrk_MET_region3_bybin_CR, 1, 1);

    h_Top_btrk_MET_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_MET_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_MET_region3_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_btrk_MET_region3_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_btrk_MET_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    // h_Top_btrk_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_btrk_MET_region3_SR->Draw("");
    h_Top_btrk_MET_region3_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_MET_region3_SR, "True Background", "El");
    l0->AddEntry(h_Top_btrk_MET_region3_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_MET_rg3_T_P_ratio->SetLineColor(kBlack);

    h_btrk_MET_rg3_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_MET_rg3_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_btrk_MET_rg3_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_btrk_MET_rg3_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_MET_rg3_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_btrk_MET_rg3_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg3_xmin = h_btrk_MET_rg3_T_P_ratio->GetXaxis()->GetXmin();
    Double_t btrk_rg3_xmax = h_btrk_MET_rg3_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg3_xmin, btrk_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_btrk_MET_rg3_T_P_ratio->Fit("f1", "MFR");

    h_btrk_MET_rg3_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_MET_rg1_T_P_ratio = (TH1D *)h_Top_ltrk_MET_region1_SR->Clone("h_ltrk_MET_rg1_T_P_ratio");
    h_ltrk_MET_rg1_T_P_ratio->Divide(h_Top_ltrk_MET_region1_SR, h_Top_ltrk_MET_region1_bybin_CR, 1, 1);

    h_Top_ltrk_MET_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_MET_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_MET_region1_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_ltrk_MET_region1_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_ltrk_MET_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    // h_Top_ltrk_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_ltrk_MET_region1_SR->Draw("");
    h_Top_ltrk_MET_region1_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_MET_region1_SR, "True Background", "El");
    l0->AddEntry(h_Top_ltrk_MET_region1_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_MET_rg1_T_P_ratio->SetLineColor(kBlack);

    h_ltrk_MET_rg1_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_MET_rg1_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_ltrk_MET_rg1_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ltrk_MET_rg1_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_MET_rg1_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ltrk_MET_rg1_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg1_xmin = h_ltrk_MET_rg1_T_P_ratio->GetXaxis()->GetXmin();
    Double_t ltrk_rg1_xmax = h_ltrk_MET_rg1_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg1_xmin, ltrk_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_ltrk_MET_rg1_T_P_ratio->Fit("f1", "MFR");

    h_ltrk_MET_rg1_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_MET_rg2_T_P_ratio = (TH1D *)h_Top_ltrk_MET_region2_SR->Clone("h_ltrk_MET_rg2_T_P_ratio");
    h_ltrk_MET_rg2_T_P_ratio->Divide(h_Top_ltrk_MET_region2_SR, h_Top_ltrk_MET_region2_bybin_CR, 1, 1);

    h_Top_ltrk_MET_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_MET_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_MET_region2_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_ltrk_MET_region2_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_ltrk_MET_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    // h_Top_ltrk_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_ltrk_MET_region2_SR->Draw("");
    h_Top_ltrk_MET_region2_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor ,1 < |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_MET_region2_SR, "True Background", "El");
    l0->AddEntry(h_Top_ltrk_MET_region2_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_MET_rg2_T_P_ratio->SetLineColor(kBlack);

    h_ltrk_MET_rg2_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_MET_rg2_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_ltrk_MET_rg2_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ltrk_MET_rg2_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_MET_rg2_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ltrk_MET_rg2_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg2_xmin = h_ltrk_MET_rg2_T_P_ratio->GetXaxis()->GetXmin();
    Double_t ltrk_rg2_xmax = h_ltrk_MET_rg2_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg2_xmin, ltrk_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_ltrk_MET_rg2_T_P_ratio->Fit("f1", "MFR");

    h_ltrk_MET_rg2_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_MET_rg3_T_P_ratio = (TH1D *)h_Top_ltrk_MET_region3_SR->Clone("h_ltrk_MET_rg3_T_P_ratio");
    h_ltrk_MET_rg3_T_P_ratio->Divide(h_Top_ltrk_MET_region3_SR, h_Top_ltrk_MET_region3_bybin_CR, 1, 1);

    h_Top_ltrk_MET_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_MET_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_MET_region3_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_ltrk_MET_region3_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_ltrk_MET_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    // h_Top_ltrk_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_ltrk_MET_region3_SR->Draw("");
    h_Top_ltrk_MET_region3_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor ,2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_MET_region3_SR, "True Background", "El");
    l0->AddEntry(h_Top_ltrk_MET_region3_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_MET_rg3_T_P_ratio->SetLineColor(kBlack);

    h_ltrk_MET_rg3_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_MET_rg3_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_ltrk_MET_rg3_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ltrk_MET_rg3_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_MET_rg3_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    h_ltrk_MET_rg3_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg3_xmin = h_ltrk_MET_rg3_T_P_ratio->GetXaxis()->GetXmin();
    Double_t ltrk_rg3_xmax = h_ltrk_MET_rg3_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg3_xmin, ltrk_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_ltrk_MET_rg3_T_P_ratio->Fit("f1", "MFR");

    h_ltrk_MET_rg3_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_MET_rg1_T_P_ratio = (TH1D *)h_Top_bJetPt_MET_region1_SR->Clone("h_bJetPt_MET_rg1_T_P_ratio");
    h_bJetPt_MET_rg1_T_P_ratio->Divide(h_Top_bJetPt_MET_region1_SR, h_Top_bJetPt_MET_region1_bybin_CR, 1, 1);

    h_Top_bJetPt_MET_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_MET_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_MET_region1_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_bJetPt_region1_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetPt_MET_region1_SR->Draw("");
    h_Top_bJetPt_MET_region1_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_MET_region1_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetPt_MET_region1_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_MET_rg1_T_P_ratio->SetLineColor(kBlack);

    h_bJetPt_MET_rg1_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_MET_rg1_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetPt_MET_rg1_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetPt_MET_rg1_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetPt_MET_rg1_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    // h_bJetPt_rg1_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetPt_rg1_xmin = h_bJetPt_MET_rg1_T_P_ratio->GetXaxis()->GetXmin();
    Double_t bJetPt_rg1_xmax = h_bJetPt_MET_rg1_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetPt_rg1_xmin, bJetPt_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_bJetPt_MET_rg1_T_P_ratio->Fit("f1", "MFR");
    h_bJetPt_MET_rg1_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_MET_rg2_T_P_ratio = (TH1D *)h_Top_bJetPt_MET_region2_SR->Clone("h_bJetPt_MET_rg2_T_P_ratio");
    h_bJetPt_MET_rg2_T_P_ratio->Divide(h_Top_bJetPt_MET_region2_SR, h_Top_bJetPt_MET_region2_bybin_CR, 1, 1);

    h_Top_bJetPt_MET_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_MET_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_MET_region2_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_bJetPt_region2_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetPt_MET_region2_SR->Draw("");
    h_Top_bJetPt_MET_region2_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_MET_region2_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetPt_MET_region2_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_MET_rg2_T_P_ratio->SetLineColor(kBlack);

    h_bJetPt_MET_rg2_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_MET_rg2_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetPt_MET_rg2_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetPt_MET_rg2_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetPt_MET_rg2_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    // h_bJetPt_rg2_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetPt_rg2_xmin = h_bJetPt_MET_rg2_T_P_ratio->GetXaxis()->GetXmin();
    Double_t bJetPt_rg2_xmax = h_bJetPt_MET_rg2_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetPt_rg2_xmin, bJetPt_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_bJetPt_MET_rg2_T_P_ratio->Fit("f1", "MFR");

    h_bJetPt_MET_rg2_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_MET_rg3_T_P_ratio = (TH1D *)h_Top_bJetPt_MET_region3_SR->Clone("h_bJetPt_MET_rg3_T_P_ratio");
    h_bJetPt_MET_rg3_T_P_ratio->Divide(h_Top_bJetPt_MET_region3_SR, h_Top_bJetPt_MET_region3_bybin_CR, 1, 1);

    h_Top_bJetPt_MET_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_MET_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_MET_region3_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_bJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetPt_MET_region3_SR->Draw("");
    h_Top_bJetPt_MET_region3_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_MET_region3_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetPt_MET_region3_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_MET_rg3_T_P_ratio->SetLineColor(kBlack);

    h_bJetPt_MET_rg3_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_MET_rg3_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetPt_MET_rg3_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetPt_MET_rg3_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetPt_MET_rg3_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    // h_bJetPt_rg3_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetPt_rg3_xmin = h_bJetPt_MET_rg3_T_P_ratio->GetXaxis()->GetXmin();
    Double_t bJetPt_rg3_xmax = h_bJetPt_MET_rg3_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetPt_rg3_xmin, bJetPt_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_bJetPt_MET_rg3_T_P_ratio->Fit("f1", "MFR");

    h_bJetPt_MET_rg3_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_MET_rg1_T_P_ratio = (TH1D *)h_Top_lJetPt_MET_region1_SR->Clone("h_lJetPt_MET_rg1_T_P_ratio");
    h_lJetPt_MET_rg1_T_P_ratio->Divide(h_Top_lJetPt_MET_region1_SR, h_Top_lJetPt_MET_region1_bybin_CR, 1, 1);

    h_Top_lJetPt_MET_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_MET_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_MET_region1_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_lJetPt_region1_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region1_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetPt_MET_region1_SR->Draw("");
    h_Top_lJetPt_MET_region1_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_MET_region1_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetPt_MET_region1_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_MET_rg1_T_P_ratio->SetLineColor(kBlack);

    h_lJetPt_MET_rg1_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_MET_rg1_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetPt_MET_rg1_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetPt_MET_rg1_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetPt_MET_rg1_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    // h_lJetPt_rg1_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetPt_rg1_xmin = h_lJetPt_MET_rg1_T_P_ratio->GetXaxis()->GetXmin();
    Double_t lJetPt_rg1_xmax = h_lJetPt_MET_rg1_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetPt_rg1_xmin, lJetPt_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_lJetPt_MET_rg1_T_P_ratio->Fit("f1", "MFR");

    h_lJetPt_MET_rg1_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_MET_rg2_T_P_ratio = (TH1D *)h_Top_lJetPt_MET_region2_SR->Clone("h_lJetPt_MET_rg2_T_P_ratio");
    h_lJetPt_MET_rg2_T_P_ratio->Divide(h_Top_lJetPt_MET_region2_SR, h_Top_lJetPt_MET_region2_bybin_CR, 1, 1);

    h_Top_lJetPt_MET_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_MET_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_MET_region2_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_lJetPt_region2_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region2_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetPt_MET_region2_SR->Draw("");
    h_Top_lJetPt_MET_region2_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_MET_region2_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetPt_MET_region2_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_MET_rg2_T_P_ratio->SetLineColor(kBlack);

    h_lJetPt_MET_rg2_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_MET_rg2_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetPt_MET_rg2_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetPt_MET_rg2_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetPt_MET_rg2_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    // h_lJetPt_rg2_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetPt_rg2_xmin = h_lJetPt_MET_rg2_T_P_ratio->GetXaxis()->GetXmin();
    Double_t lJetPt_rg2_xmax = h_lJetPt_MET_rg2_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetPt_rg2_xmin, lJetPt_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_lJetPt_MET_rg2_T_P_ratio->Fit("f1", "MFR");

    h_lJetPt_MET_rg2_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_MET_rg3_T_P_ratio = (TH1D *)h_Top_lJetPt_MET_region3_SR->Clone("h_lJetPt_MET_rg3_T_P_ratio");
    h_lJetPt_MET_rg3_T_P_ratio->Divide(h_Top_lJetPt_MET_region3_SR, h_Top_lJetPt_MET_region3_bybin_CR, 1, 1);

    h_Top_lJetPt_MET_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_MET_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_MET_region3_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_lJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetPt_MET_region3_SR->Draw("");
    h_Top_lJetPt_MET_region3_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_MET_region3_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetPt_MET_region3_bybin_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_MET_rg3_T_P_ratio->SetLineColor(kBlack);

    h_lJetPt_MET_rg3_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_MET_rg3_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetPt_MET_rg3_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetPt_MET_rg3_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetPt_MET_rg3_T_P_ratio->GetYaxis()->SetRangeUser(0, 2);
    // h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetPt_rg3_xmin = h_lJetPt_MET_rg3_T_P_ratio->GetXaxis()->GetXmin();
    Double_t lJetPt_rg3_xmax = h_lJetPt_MET_rg3_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetPt_rg3_xmin, lJetPt_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_lJetPt_MET_rg3_T_P_ratio->Fit("f1", "MFR");

    h_lJetPt_MET_rg3_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
     c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetEta_MET_T_P_ratio = (TH1D *)h_Top_bJetEta_MET_SR->Clone("h_bJetEta_MET_T_P_ratio");
    h_bJetEta_MET_T_P_ratio->Divide(h_Top_bJetEta_MET_SR, h_Top_bJetEta_MET_diffFR_CR, 1, 1);

    h_Top_bJetEta_MET_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetEta_MET_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetEta_MET_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_lJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetEta_MET_SR->Draw("");
    h_Top_bJetEta_MET_diffFR_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetEta_MET_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetEta_MET_diffFR_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetEta_MET_T_P_ratio->SetLineColor(kBlack);

    h_bJetEta_MET_T_P_ratio->GetXaxis()->SetTitle("Jet #eta");
    h_bJetEta_MET_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetEta_MET_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetEta_MET_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetEta_MET_T_P_ratio->GetYaxis()->SetRangeUser(0, 3);
    // h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetEta_xmin = h_bJetEta_MET_T_P_ratio->GetXaxis()->GetXmin();
    Double_t bJetEta_xmax = h_bJetEta_MET_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetEta_xmin, bJetEta_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_bJetEta_MET_T_P_ratio->Fit("f1", "MFR");

    h_bJetEta_MET_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetEta_MET_T_P_ratio = (TH1D *)h_Top_lJetEta_MET_SR->Clone("h_lJetEta_MET_T_P_ratio");
    h_lJetEta_MET_T_P_ratio->Divide(h_Top_lJetEta_MET_SR, h_Top_lJetEta_MET_diffFR_CR, 1, 1);

    h_Top_lJetEta_MET_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_MET_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetEta_MET_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_lJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetEta_MET_SR->Draw("");
    h_Top_lJetEta_MET_diffFR_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetEta_MET_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetEta_MET_diffFR_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetEta_MET_T_P_ratio->SetLineColor(kBlack);

    h_lJetEta_MET_T_P_ratio->GetXaxis()->SetTitle("Jet #eta");
    h_lJetEta_MET_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetEta_MET_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetEta_MET_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetEta_MET_T_P_ratio->GetYaxis()->SetRangeUser(0, 3);
    // h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetEta_xmin = h_lJetEta_MET_T_P_ratio->GetXaxis()->GetXmin();
    Double_t lJetEta_xmax = h_lJetEta_MET_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetEta_xmin, lJetEta_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_lJetEta_MET_T_P_ratio->Fit("f1", "MFR");

    h_lJetEta_MET_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    gStyle->SetOptStat(0);
}