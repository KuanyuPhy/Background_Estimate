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
#include <TObjString.h>
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

void quick_draw_LO(TString file = "./Ratio_apply.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *h_Top_trk_LO_SR = ((TH1D *)Topfile->Get("h_Top_trk_LO_SR"));
    TH1D *h_Top_btrk_region1_LO_SR = ((TH1D *)Topfile->Get("h_Top_btrk_region1_LO_SR"));
    TH1D *h_Top_btrk_region2_LO_SR = ((TH1D *)Topfile->Get("h_Top_btrk_region2_LO_SR"));
    TH1D *h_Top_btrk_region3_LO_SR = ((TH1D *)Topfile->Get("h_Top_btrk_region3_LO_SR"));
    TH1D *h_Top_ltrk_region1_LO_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_region1_LO_SR"));
    TH1D *h_Top_ltrk_region2_LO_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_region2_LO_SR"));
    TH1D *h_Top_ltrk_region3_LO_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_region3_LO_SR"));
    //--------------------
    TH1D *h_Top_JetPt_LO_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_LO_SR"));
    TH1D *h_Top_bJetPt_region1_LO_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region1_LO_SR"));
    TH1D *h_Top_bJetPt_region2_LO_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region2_LO_SR"));
    TH1D *h_Top_bJetPt_region3_LO_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region3_LO_SR"));
    TH1D *h_Top_lJetPt_region1_LO_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region1_LO_SR"));
    TH1D *h_Top_lJetPt_region2_LO_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region2_LO_SR"));
    TH1D *h_Top_lJetPt_region3_LO_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region3_LO_SR"));
    //--------------------
    TH1D *h_Top_JetEta_LO_SR = ((TH1D *)Topfile->Get("h_Top_JetEta_LO_SR"));
    TH1D *h_Top_bJetEta_LO_SR = ((TH1D *)Topfile->Get("h_Top_bJetEta_LO_SR"));
    TH1D *h_Top_lJetEta_LO_SR = ((TH1D *)Topfile->Get("h_Top_lJetEta_LO_SR"));
    //--------------------
    TH1D *h_Top_trk_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_trk_LO_bybin_CR"));
    TH1D *h_Top_btrk_region1_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_region1_LO_bybin_CR"));
    TH1D *h_Top_btrk_region2_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_region2_LO_bybin_CR"));
    TH1D *h_Top_btrk_region3_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_region3_LO_bybin_CR"));
    TH1D *h_Top_ltrk_region1_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_region1_LO_bybin_CR"));
    TH1D *h_Top_ltrk_region2_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_region2_LO_bybin_CR"));
    TH1D *h_Top_ltrk_region3_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_region3_LO_bybin_CR"));
    //---------------------
    TH1D *h_Top_JetPt_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_LO_bybin_CR"));
    TH1D *h_Top_bJetPt_region1_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region1_LO_bybin_CR"));
    TH1D *h_Top_bJetPt_region2_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region2_LO_bybin_CR"));
    TH1D *h_Top_bJetPt_region3_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region3_LO_bybin_CR"));
    TH1D *h_Top_lJetPt_region1_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region1_LO_bybin_CR"));
    TH1D *h_Top_lJetPt_region2_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region2_LO_bybin_CR"));
    TH1D *h_Top_lJetPt_region3_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region3_LO_bybin_CR"));
    //---------------------
    TH1D *h_Top_JetEta_LO_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetEta_LO_bybin_CR"));
    TH1D *h_Top_bJetEta_diffFR_LO_CR = ((TH1D *)Topfile->Get("h_Top_bJetEta_diffFR_LO_CR"));
    TH1D *h_Top_lJetEta_diffFR_LO_CR = ((TH1D *)Topfile->Get("h_Top_lJetEta_diffFR_LO_CR"));
    //----------------------------
    // for apply fk(jetpt) result
    //----------------------------
    TH1D *h_Top_trk_LO_byjetPTbin_CR = ((TH1D *)Topfile->Get("h_Top_trk_LO_byjetPTbin_CR"));
    TH1D *h_Top_JetPt_LO_byjetPTbin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_LO_byjetPTbin_CR"));
    TH1D *h_Top_JetEta_LO_byjetPTbin_CR = ((TH1D *)Topfile->Get("h_Top_JetEta_LO_byjetPTbin_CR"));

    //--------------------------
    // For Signal Region
    //--------------------------
    // 1. nTrack
    h_Style_Setting(h_Top_trk_LO_SR, kRed);
    // consider eta fake rate
    h_Style_Setting(h_Top_btrk_region1_LO_SR, kRed);
    h_Style_Setting(h_Top_btrk_region2_LO_SR, kRed);
    h_Style_Setting(h_Top_btrk_region3_LO_SR, kRed);

    h_Style_Setting(h_Top_ltrk_region1_LO_SR, kRed);
    h_Style_Setting(h_Top_ltrk_region2_LO_SR, kRed);
    h_Style_Setting(h_Top_ltrk_region3_LO_SR, kRed);

    // 2. JetPt
    h_Style_Setting(h_Top_JetPt_LO_SR, kRed);
    // consider eta fake rate
    h_Style_Setting(h_Top_bJetPt_region1_LO_SR, kRed);
    h_Style_Setting(h_Top_bJetPt_region2_LO_SR, kRed);
    h_Style_Setting(h_Top_bJetPt_region3_LO_SR, kRed);

    h_Style_Setting(h_Top_lJetPt_region1_LO_SR, kRed);
    h_Style_Setting(h_Top_lJetPt_region2_LO_SR, kRed);
    h_Style_Setting(h_Top_lJetPt_region3_LO_SR, kRed);

    // 3. JetEta
    h_Style_Setting(h_Top_JetEta_LO_SR, kRed);
    h_Style_Setting(h_Top_bJetEta_LO_SR, kRed);
    h_Style_Setting(h_Top_lJetEta_LO_SR, kRed);
    //--------------------------
    // For Control Region
    //--------------------------
    // 1. nTrack
    h_Style_Setting(h_Top_trk_LO_bybin_CR, kAzure + 4);
    // consider eta fake rate
    h_Style_Setting(h_Top_btrk_region1_LO_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_btrk_region2_LO_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_btrk_region3_LO_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_ltrk_region1_LO_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_ltrk_region2_LO_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_ltrk_region3_LO_bybin_CR, kAzure + 4);

    // 2. Jet Pt
    h_Style_Setting(h_Top_JetPt_LO_bybin_CR, kAzure + 4);
    // consider eta fake rate
    h_Style_Setting(h_Top_bJetPt_region1_LO_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_bJetPt_region2_LO_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_bJetPt_region3_LO_bybin_CR, kAzure + 4);

    h_Style_Setting(h_Top_lJetPt_region1_LO_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetPt_region2_LO_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetPt_region3_LO_bybin_CR, kAzure + 4);

    // 3. Jet Eta
    h_Style_Setting(h_Top_JetEta_LO_bybin_CR, kAzure + 4);
    h_Style_Setting(h_Top_bJetEta_diffFR_LO_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetEta_diffFR_LO_CR, kAzure + 4);

    //-----------------------
    // for fk(jetpt) result
    //-----------------------
    h_Style_Setting(h_Top_trk_LO_byjetPTbin_CR, kAzure + 4);
    h_Style_Setting(h_Top_JetPt_LO_byjetPTbin_CR, kAzure + 4);
    h_Style_Setting(h_Top_JetEta_LO_byjetPTbin_CR, kAzure + 4);

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
    // Without consider eta and flavor
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_trk_LO_T_P_ratio = (TH1D *)h_Top_trk_LO_SR->Clone("h_trk_LO_T_P_ratio");
    h_trk_LO_T_P_ratio->Divide(h_Top_trk_LO_SR, h_Top_trk_LO_bybin_CR, 1, 1);

    h_Top_trk_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_trk_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_trk_LO_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_trk_LO_SR->Draw();
    h_Top_trk_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    // l0->SetHeader("b flavor , |#eta| <= 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_trk_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_trk_LO_bybin_CR, "Predict", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_trk_LO_T_P_ratio->SetLineColor(kBlack);
    h_trk_LO_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_trk_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_trk_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_trk_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    // h_Top_trk_LO_SR->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------

    Double_t trk_xmin = h_trk_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t trk_xmax = h_trk_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, trk_xmin, trk_xmax, 2);

    f1->SetLineWidth(2);
    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_trk_LO_T_P_ratio->Fit("f1", "MFRS");

    TObjString *par0Name = new TObjString("Value for Par0: ");
    TObjString *par1Name = new TObjString("Value for Par1: ");

    TObjString *par0Error = new TObjString("Error for Par0: ");
    TObjString *par1Error = new TObjString("Error for Par1: ");

    h_trk_LO_T_P_ratio->Draw();

    TLegend *leg_ratio = new TLegend(0.55, 0.6, 0.6, 0.9);
    leg_ratio->SetHeader("Fitting function: par0 + par1*x");
    leg_ratio->SetTextSize(0.06);
    leg_ratio->SetBorderSize(0);
    leg_ratio->SetFillStyle(0);
    leg_ratio->AddEntry(par0Name, Form("par0 : %g +- %g", f1->GetParameter(0), f1->GetParError(0)), " ");
    leg_ratio->AddEntry(par1Name, Form("par1 : %g +- %g", f1->GetParameter(1), f1->GetParError(1)), " ");
    leg_ratio->Draw();
    */
    // For Jet PT
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_JetPt_LO_T_P_ratio = (TH1D *)h_Top_JetPt_LO_SR->Clone("h_JetPt_LO_T_P_ratio");
    h_JetPt_LO_T_P_ratio->Divide(h_Top_JetPt_LO_SR, h_Top_JetPt_LO_bybin_CR, 1, 1);

    h_Top_JetPt_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_JetPt_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_JetPt_LO_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_JetPt_LO_SR->Draw();
    h_Top_JetPt_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    // l0->SetHeader("b flavor , |#eta| <= 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_JetPt_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_JetPt_LO_bybin_CR, "Predict", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_JetPt_LO_T_P_ratio->SetLineColor(kBlack);
    h_JetPt_LO_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_JetPt_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_JetPt_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_JetPt_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    // h_Top_JetPt_LO_SR->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t JetPt_xmin = h_JetPt_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t JetPt_xmax = h_JetPt_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, JetPt_xmin, JetPt_xmax, 2);

    f1->SetLineWidth(2);
    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_JetPt_LO_T_P_ratio->Fit("f1", "MFRS");

    TObjString *par0Name = new TObjString("Value for Par0: ");
    TObjString *par1Name = new TObjString("Value for Par1: ");

    TObjString *par0Error = new TObjString("Error for Par0: ");
    TObjString *par1Error = new TObjString("Error for Par1: ");

    h_JetPt_LO_T_P_ratio->Draw();

    TLegend *leg_ratio = new TLegend(0.5, 0.6, 0.6, 0.9);
    leg_ratio->SetHeader("Fitting function: par0 + par1*x");
    leg_ratio->SetTextSize(0.06);
    leg_ratio->SetBorderSize(0);
    leg_ratio->SetFillStyle(0);
    leg_ratio->AddEntry(par0Name, Form("par0 : %g +- %g", f1->GetParameter(0), f1->GetParError(0)), " ");
    leg_ratio->AddEntry(par1Name, Form("par1 : %g +- %g", f1->GetParameter(1), f1->GetParError(1)), " ");
    leg_ratio->Draw();
    */

    // For Jet Eta
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_JetEta_LO_T_P_ratio = (TH1D *)h_Top_JetEta_LO_SR->Clone("h_JetEta_LO_T_P_ratio");
    h_JetEta_LO_T_P_ratio->Divide(h_Top_JetEta_LO_SR, h_Top_JetEta_LO_bybin_CR, 1, 1);

    h_Top_JetEta_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_JetEta_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_JetEta_LO_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_JetEta_LO_SR->Draw();
    h_Top_JetEta_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    // l0->SetHeader("b flavor , |#eta| <= 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_JetEta_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_JetEta_LO_bybin_CR, "Predict", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_JetEta_LO_T_P_ratio->SetLineColor(kBlack);
    h_JetEta_LO_T_P_ratio->GetXaxis()->SetTitle("Jet #eta");
    h_JetEta_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_JetEta_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_JetEta_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    // h_Top_JetEta_LO_SR->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t JetEta_xmin = h_JetEta_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t JetEta_xmax = h_JetEta_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, JetEta_xmin, JetEta_xmax, 2);

    f1->SetLineWidth(2);
    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_JetEta_LO_T_P_ratio->Fit("f1", "MFRS");

    TObjString *par0Name = new TObjString("Value for Par0: ");
    TObjString *par1Name = new TObjString("Value for Par1: ");

    TObjString *par0Error = new TObjString("Error for Par0: ");
    TObjString *par1Error = new TObjString("Error for Par1: ");

    h_JetEta_LO_T_P_ratio->Draw();

    TLegend *leg_ratio = new TLegend(0.5, 0.6, 0.6, 0.9);
    leg_ratio->SetHeader("Fitting function: par0 + par1*x");
    leg_ratio->SetTextSize(0.06);
    leg_ratio->SetBorderSize(0);
    leg_ratio->SetFillStyle(0);
    leg_ratio->AddEntry(par0Name, Form("par0 : %g +- %g", f1->GetParameter(0), f1->GetParError(0)), " ");
    leg_ratio->AddEntry(par1Name, Form("par1 : %g +- %g", f1->GetParameter(1), f1->GetParError(1)), " ");
    leg_ratio->Draw();
    */

    // For ntrk
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg1_LO_T_P_ratio = (TH1D *)h_Top_btrk_region1_LO_SR->Clone("h_btrk_rg1_LO_T_P_ratio");
    h_btrk_rg1_LO_T_P_ratio->Divide(h_Top_btrk_region1_LO_SR, h_Top_btrk_region1_LO_bybin_CR, 1, 1);

    h_Top_btrk_region1_LO_SR->GetYaxis()->SetTitle("nEvent");
    h_Top_btrk_region1_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region1_LO_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_btrk_region1_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_btrk_region1_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_btrk_region1_LO_SR->Draw();
    h_Top_btrk_region1_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , |#eta| <= 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region1_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_btrk_region1_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg1_LO_T_P_ratio->SetLineColor(kBlack);

    h_btrk_rg1_LO_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg1_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_btrk_rg1_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_btrk_rg1_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg1_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg1_xmin = h_btrk_rg1_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t btrk_rg1_xmax = h_btrk_rg1_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg1_xmin, btrk_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_btrk_rg1_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_btrk_rg1_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg2_LO_T_P_ratio = (TH1D *)h_Top_btrk_region2_LO_SR->Clone("h_btrk_rg2_LO_T_P_ratio");
    h_btrk_rg2_LO_T_P_ratio->Divide(h_Top_btrk_region2_LO_SR, h_Top_btrk_region2_LO_bybin_CR, 1, 1);

    h_Top_btrk_region2_LO_SR->GetYaxis()->SetTitle("nEvent");
    h_Top_btrk_region2_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region2_LO_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_btrk_region2_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_btrk_region2_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_btrk_region2_LO_SR->Draw();
    h_Top_btrk_region2_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 1 < |#eta| <= 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region2_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_btrk_region2_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg2_LO_T_P_ratio->SetLineColor(kBlack);

    h_btrk_rg2_LO_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg2_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_btrk_rg2_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_btrk_rg2_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg2_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg2_xmin = h_btrk_rg2_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t btrk_rg2_xmax = h_btrk_rg2_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg2_xmin, btrk_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_btrk_rg2_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_btrk_rg2_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg3_LO_T_P_ratio = (TH1D *)h_Top_btrk_region3_LO_SR->Clone("h_btrk_rg3_LO_T_P_ratio");
    h_btrk_rg3_LO_T_P_ratio->Divide(h_Top_btrk_region3_LO_SR, h_Top_btrk_region3_LO_bybin_CR, 1, 1);

    h_Top_btrk_region3_LO_SR->GetYaxis()->SetTitle("nEvent");
    h_Top_btrk_region3_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region3_LO_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_btrk_region3_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_btrk_region3_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_btrk_region3_LO_SR->Draw();
    h_Top_btrk_region3_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 2 < |#eta| <= 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region3_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_btrk_region3_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg3_LO_T_P_ratio->SetLineColor(kBlack);

    h_btrk_rg3_LO_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg3_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_btrk_rg3_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_btrk_rg3_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg3_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg3_xmax = h_btrk_rg3_LO_T_P_ratio->GetXaxis()->GetXmax();
    Double_t btrk_rg3_xmin = h_btrk_rg3_LO_T_P_ratio->GetXaxis()->GetXmin();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg3_xmin, btrk_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_btrk_rg3_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_btrk_rg3_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    // c1->SaveAs("CT_Top(emu)_btrk_dileppT_rg3_LO.svg");
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg1_LO_T_P_ratio = (TH1D *)h_Top_ltrk_region1_LO_SR->Clone("h_ltrk_rg1_LO_T_P_ratio");
    h_ltrk_rg1_LO_T_P_ratio->Divide(h_Top_ltrk_region1_LO_SR, h_Top_ltrk_region1_LO_bybin_CR, 1, 1);

    h_Top_ltrk_region1_LO_SR->GetYaxis()->SetTitle("nEvent");
    h_Top_ltrk_region1_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region1_LO_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_ltrk_region1_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_ltrk_region1_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_ltrk_region1_LO_SR->Draw();
    h_Top_ltrk_region1_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| <= 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region1_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_ltrk_region1_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg1_LO_T_P_ratio->SetLineColor(kBlack);

    h_ltrk_rg1_LO_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg1_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_ltrk_rg1_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ltrk_rg1_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg1_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg1_xmin = h_ltrk_rg1_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t ltrk_rg1_xmax = h_ltrk_rg1_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg1_xmin, ltrk_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_ltrk_rg1_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_ltrk_rg1_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg2_LO_T_P_ratio = (TH1D *)h_Top_ltrk_region2_LO_SR->Clone("h_ltrk_rg2_LO_T_P_ratio");
    h_ltrk_rg2_LO_T_P_ratio->Divide(h_Top_ltrk_region2_LO_SR, h_Top_ltrk_region2_LO_bybin_CR, 1, 1);

    h_Top_ltrk_region2_LO_SR->GetYaxis()->SetTitle("nEvent");
    h_Top_ltrk_region2_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region2_LO_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_ltrk_region2_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_ltrk_region2_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_ltrk_region2_LO_SR->Draw();
    h_Top_ltrk_region2_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 1 < |#eta| <= 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region2_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_ltrk_region2_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg2_LO_T_P_ratio->SetLineColor(kBlack);

    h_ltrk_rg2_LO_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg2_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_ltrk_rg2_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ltrk_rg2_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg2_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg2_xmin = h_ltrk_rg2_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t ltrk_rg2_xmax = h_ltrk_rg2_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg2_xmin, ltrk_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_ltrk_rg2_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_ltrk_rg2_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg3_LO_T_P_ratio = (TH1D *)h_Top_ltrk_region3_LO_SR->Clone("h_ltrk_rg3_LO_T_P_ratio");
    h_ltrk_rg3_LO_T_P_ratio->Divide(h_Top_ltrk_region3_LO_SR, h_Top_ltrk_region3_LO_bybin_CR, 1, 1);

    h_Top_ltrk_region3_LO_SR->GetYaxis()->SetTitle("nEvent");
    h_Top_ltrk_region3_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region3_LO_SR->GetYaxis()->SetTitleSize(0.06);

    h_Top_ltrk_region3_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    h_Top_ltrk_region3_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_ltrk_region3_LO_SR->Draw();
    h_Top_ltrk_region3_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 2 < |#eta| <= 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region3_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_ltrk_region3_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg3_LO_T_P_ratio->SetLineColor(kBlack);

    h_ltrk_rg3_LO_T_P_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg3_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_ltrk_rg3_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_ltrk_rg3_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg3_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg3_xmax = h_ltrk_rg3_LO_T_P_ratio->GetXaxis()->GetXmax();
    Double_t ltrk_rg3_xmin = h_ltrk_rg3_LO_T_P_ratio->GetXaxis()->GetXmin();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg3_xmin, ltrk_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_ltrk_rg3_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_ltrk_rg3_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    // For JetPT
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_rg1_LO_T_P_ratio = (TH1D *)h_Top_bJetPt_region1_LO_SR->Clone("h_bJetPt_rg1_LO_T_P_ratio");
    h_bJetPt_rg1_LO_T_P_ratio->Divide(h_Top_bJetPt_region1_LO_SR, h_Top_bJetPt_region1_LO_bybin_CR, 1, 1);

    h_Top_bJetPt_region1_LO_SR->GetYaxis()->SetTitle("nEvent");
    h_Top_bJetPt_region1_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region1_LO_SR->GetYaxis()->SetTitleSize(0.06);

    //h_Top_bJetPt_region1_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    //h_Top_bJetPt_region1_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetPt_region1_LO_SR->Draw();
    h_Top_bJetPt_region1_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , |#eta| <= 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_region1_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetPt_region1_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_rg1_LO_T_P_ratio->SetLineColor(kBlack);

    h_bJetPt_rg1_LO_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_rg1_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetPt_rg1_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetPt_rg1_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    //h_bJetPt_rg1_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetPt_rg1_xmin = h_bJetPt_rg1_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t bJetPt_rg1_xmax = h_bJetPt_rg1_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetPt_rg1_xmin, bJetPt_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_bJetPt_rg1_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_bJetPt_rg1_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_rg2_LO_T_P_ratio = (TH1D *)h_Top_bJetPt_region2_LO_SR->Clone("h_bJetPt_rg2_LO_T_P_ratio");
    h_bJetPt_rg2_LO_T_P_ratio->Divide(h_Top_bJetPt_region2_LO_SR, h_Top_bJetPt_region2_LO_bybin_CR, 1, 1);

    h_Top_bJetPt_region2_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region2_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region2_LO_SR->GetYaxis()->SetTitleSize(0.06);

    //h_Top_bJetPt_region2_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    //h_Top_bJetPt_region2_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetPt_region2_LO_SR->Draw();
    h_Top_bJetPt_region2_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 1 < |#eta| <= 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_region2_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetPt_region2_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_rg2_LO_T_P_ratio->SetLineColor(kBlack);

    h_bJetPt_rg2_LO_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_rg2_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetPt_rg2_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetPt_rg2_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    //h_bJetPt_rg2_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetPt_rg2_xmin = h_bJetPt_rg2_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t bJetPt_rg2_xmax = h_bJetPt_rg2_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetPt_rg2_xmin, bJetPt_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_bJetPt_rg2_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_bJetPt_rg2_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_rg3_LO_T_P_ratio = (TH1D *)h_Top_bJetPt_region3_LO_SR->Clone("h_bJetPt_rg3_LO_T_P_ratio");
    h_bJetPt_rg3_LO_T_P_ratio->Divide(h_Top_bJetPt_region3_LO_SR, h_Top_bJetPt_region3_LO_bybin_CR, 1, 1);

    h_Top_bJetPt_region3_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region3_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region3_LO_SR->GetYaxis()->SetTitleSize(0.06);

    //h_Top_bJetPt_region3_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    //h_Top_bJetPt_region3_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetPt_region3_LO_SR->Draw();
    h_Top_bJetPt_region3_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 2 < |#eta| <= 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_region3_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetPt_region3_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_rg3_LO_T_P_ratio->SetLineColor(kBlack);

    h_bJetPt_rg3_LO_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_rg3_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetPt_rg3_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetPt_rg3_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    //h_bJetPt_rg3_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetPt_rg3_xmax = h_bJetPt_rg3_LO_T_P_ratio->GetXaxis()->GetXmax();
    Double_t bJetPt_rg3_xmin = h_bJetPt_rg3_LO_T_P_ratio->GetXaxis()->GetXmin();

    TF1 *f1 = new TF1("f1", Ratio, bJetPt_rg3_xmin, bJetPt_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_bJetPt_rg3_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_bJetPt_rg3_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_rg1_LO_T_P_ratio = (TH1D *)h_Top_lJetPt_region1_LO_SR->Clone("h_lJetPt_rg1_LO_T_P_ratio");
    h_lJetPt_rg1_LO_T_P_ratio->Divide(h_Top_lJetPt_region1_LO_SR, h_Top_lJetPt_region1_LO_bybin_CR, 1, 1);

    h_Top_lJetPt_region1_LO_SR->GetYaxis()->SetTitle("nEvent");
    h_Top_lJetPt_region1_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_region1_LO_SR->GetYaxis()->SetTitleSize(0.06);

    //h_Top_lJetPt_region1_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    //h_Top_lJetPt_region1_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetPt_region1_LO_SR->Draw();
    h_Top_lJetPt_region1_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| <= 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_region1_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetPt_region1_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_rg1_LO_T_P_ratio->SetLineColor(kBlack);

    h_lJetPt_rg1_LO_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_rg1_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetPt_rg1_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetPt_rg1_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    //h_lJetPt_rg1_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetPt_rg1_xmin = h_lJetPt_rg1_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t lJetPt_rg1_xmax = h_lJetPt_rg1_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetPt_rg1_xmin, lJetPt_rg1_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_lJetPt_rg1_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_lJetPt_rg1_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_rg2_LO_T_P_ratio = (TH1D *)h_Top_lJetPt_region2_LO_SR->Clone("h_lJetPt_rg2_LO_T_P_ratio");
    h_lJetPt_rg2_LO_T_P_ratio->Divide(h_Top_lJetPt_region2_LO_SR, h_Top_lJetPt_region2_LO_bybin_CR, 1, 1);

    h_Top_lJetPt_region2_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region2_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_region2_LO_SR->GetYaxis()->SetTitleSize(0.06);

    //h_Top_lJetPt_region2_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    //h_Top_lJetPt_region2_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetPt_region2_LO_SR->Draw();
    h_Top_lJetPt_region2_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 1 < |#eta| <= 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_region2_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetPt_region2_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_rg2_LO_T_P_ratio->SetLineColor(kBlack);

    h_lJetPt_rg2_LO_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_rg2_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetPt_rg2_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetPt_rg2_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    //h_lJetPt_rg2_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetPt_rg2_xmin = h_lJetPt_rg2_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t lJetPt_rg2_xmax = h_lJetPt_rg2_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetPt_rg2_xmin, lJetPt_rg2_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_lJetPt_rg2_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_lJetPt_rg2_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_rg3_LO_T_P_ratio = (TH1D *)h_Top_lJetPt_region3_LO_SR->Clone("h_lJetPt_rg3_LO_T_P_ratio");
    h_lJetPt_rg3_LO_T_P_ratio->Divide(h_Top_lJetPt_region3_LO_SR, h_Top_lJetPt_region3_LO_bybin_CR, 1, 1);

    h_Top_lJetPt_region3_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region3_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_region3_LO_SR->GetYaxis()->SetTitleSize(0.06);

    //h_Top_lJetPt_region3_LO_SR->GetXaxis()->SetRangeUser(1, 25);
    //h_Top_lJetPt_region3_LO_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetPt_region3_LO_SR->Draw();
    h_Top_lJetPt_region3_LO_bybin_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 2 < |#eta| <= 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_region3_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetPt_region3_LO_bybin_CR, "Predict", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_rg3_LO_T_P_ratio->SetLineColor(kBlack);

    h_lJetPt_rg3_LO_T_P_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_rg3_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetPt_rg3_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetPt_rg3_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    //h_lJetPt_rg3_LO_T_P_ratio->GetXaxis()->SetRangeUser(1, 25);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetPt_rg3_xmax = h_lJetPt_rg3_LO_T_P_ratio->GetXaxis()->GetXmax();
    Double_t lJetPt_rg3_xmin = h_lJetPt_rg3_LO_T_P_ratio->GetXaxis()->GetXmin();

    TF1 *f1 = new TF1("f1", Ratio, lJetPt_rg3_xmin, lJetPt_rg3_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    // Use TFitResult to store fit result
    TFitResultPtr Fit_r = h_lJetPt_rg3_LO_T_P_ratio->Fit("f1", "MFRS");

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    h_lJetPt_rg3_LO_T_P_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.6, 0.6, 0.9);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */

    // Jet Eta
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetEta_LO_T_P_ratio = (TH1D *)h_Top_bJetEta_LO_SR->Clone("h_bJetEta_LO_T_P_ratio");
    h_bJetEta_LO_T_P_ratio->Divide(h_Top_bJetEta_LO_SR, h_Top_bJetEta_diffFR_LO_CR, 1, 1);

    h_Top_bJetEta_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetEta_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetEta_LO_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_lJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_bJetEta_LO_SR->Draw("");
    h_Top_bJetEta_diffFR_LO_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetEta_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_bJetEta_diffFR_LO_CR, "Predict", "El");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetEta_LO_T_P_ratio->SetLineColor(kBlack);

    h_bJetEta_LO_T_P_ratio->GetXaxis()->SetTitle("Jet #eta");
    h_bJetEta_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_bJetEta_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_bJetEta_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetEta_LO_T_P_ratio->GetYaxis()->SetRangeUser(0, 3);
    // h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t bJetEta_xmin = h_bJetEta_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t bJetEta_xmax = h_bJetEta_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, bJetEta_xmin, bJetEta_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    TFitResultPtr Fit_r = h_bJetEta_LO_T_P_ratio->Fit("f1", "MFRS");

    h_bJetEta_LO_T_P_ratio->Draw();

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    TLegend *l1 = new TLegend(0.95, 0.8, 0.6, 0.95);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetEta_LO_T_P_ratio = (TH1D *)h_Top_lJetEta_LO_SR->Clone("h_lJetEta_LO_T_P_ratio");
    h_lJetEta_LO_T_P_ratio->Divide(h_Top_lJetEta_LO_SR, h_Top_lJetEta_diffFR_LO_CR, 1, 1);

    h_Top_lJetEta_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_LO_SR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetEta_LO_SR->GetYaxis()->SetTitleSize(0.06);
    // h_Top_lJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 450);

    // h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(1, 25);

    h_Top_lJetEta_LO_SR->Draw("");
    h_Top_lJetEta_diffFR_LO_CR->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetEta_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_lJetEta_diffFR_LO_CR, "Predict", "El");
    l0->Draw();

    //gPad->SetLogy();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetEta_LO_T_P_ratio->SetLineColor(kBlack);

    h_lJetEta_LO_T_P_ratio->GetXaxis()->SetTitle("Jet #eta");
    h_lJetEta_LO_T_P_ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_lJetEta_LO_T_P_ratio->GetXaxis()->SetTitleSize(0.06);
    h_lJetEta_LO_T_P_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetEta_LO_T_P_ratio->GetYaxis()->SetRangeUser(0, 3);
    // h_lJetPt_rg3_T_P_ratio->GetXaxis()->SetRangeUser(0, 450);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t lJetEta_xmin = h_lJetEta_LO_T_P_ratio->GetXaxis()->GetXmin();
    Double_t lJetEta_xmax = h_lJetEta_LO_T_P_ratio->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, lJetEta_xmin, lJetEta_xmax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    TFitResultPtr Fit_r = h_lJetEta_LO_T_P_ratio->Fit("f1", "MFRS");

    h_lJetEta_LO_T_P_ratio->Draw();

    double par0 = Fit_r->Parameter(0);
    double par1 = Fit_r->Parameter(1);

    TLegend *l1 = new TLegend(0.95, 0.8, 0.6, 0.95);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, Form("%f + %f*x", par0, par1), "l");
    l1->Draw();
    */
    /*
    h_Top_JetPt_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_JetPt_LO_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_JetPt_LO_SR->Draw();
    h_Top_JetPt_LO_byjetPTbin_CR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.6, 0.80, 0.80);
    l0->SetHeader("Top to emu");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_JetPt_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_JetPt_LO_byjetPTbin_CR, "Predict", "El");
    l0->Draw();
    */
    /*
     h_Top_JetEta_LO_SR->GetYaxis()->SetTitle("nJet");
     h_Top_JetEta_LO_SR->GetXaxis()->SetTitle("Jet #eta");
     h_Top_JetEta_LO_SR->Draw();
     h_Top_JetEta_LO_byjetPTbin_CR->Draw("h same");

     TLegend *l0 = new TLegend(0.45, 0.6, 0.80, 0.80);
     l0->SetHeader("Top to emu");
     l0->SetTextSize(0.04);
     l0->SetBorderSize(0);
     l0->SetFillStyle(0);
     l0->AddEntry(h_Top_JetEta_LO_SR, "True Background", "El");
     l0->AddEntry(h_Top_JetEta_LO_byjetPTbin_CR, "Predict", "El");
     l0->Draw();
     */
    h_Top_trk_LO_SR->GetYaxis()->SetTitle("nJet");
    h_Top_trk_LO_SR->GetXaxis()->SetTitle("Track multiplicity");
    h_Top_trk_LO_SR->Draw();
    h_Top_trk_LO_byjetPTbin_CR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.7, 0.80, 0.80);
    l0->SetHeader("Top to emu");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_trk_LO_SR, "True Background", "El");
    l0->AddEntry(h_Top_trk_LO_byjetPTbin_CR, "Predict", "El");
    l0->Draw();
    

    gPad->SetLogy();

    gStyle->SetOptStat(0);
}