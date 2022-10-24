#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
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

void h_Style_Setting(TH1D *h_tmp, const int h_Style)
{
    h_tmp->SetLineWidth(2);
    h_tmp->SetLineColor(h_Style);
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

    // 3. JetEta
    //  not consider eta fake rate
    h_Style_Setting(h_Top_JetEta_SR, kRed);
    h_Style_Setting(h_Top_bJetEta_SR, kRed);
    h_Style_Setting(h_Top_lJetEta_SR, kRed);

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

    // 3. Jet Eta
    h_Style_Setting(h_Top_bJetEta_diffFR_CR, kAzure + 4);
    h_Style_Setting(h_Top_lJetEta_diffFR_CR, kAzure + 4);

    h_Top_btrk_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_ltrk_bybin_CR->GetXaxis()->SetTitle("nTrk");

    h_Top_ltrk_region1_SR->GetXaxis()->SetTitle("nTrk");
    h_Top_ltrk_region1_SR->GetYaxis()->SetTitle("nJet");

    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_btrk_region1_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_btrk_region2_SR->GetXaxis()->SetTitle("nTrk");
    h_Top_btrk_region2_SR->GetYaxis()->SetTitle("nJet");

    h_Top_btrk_region3_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_btrk_region3_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_ltrk_region2_SR->GetXaxis()->SetTitle("nTrk");
    h_Top_ltrk_region2_SR->GetYaxis()->SetTitle("nJet");

    h_Top_ltrk_region3_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_ltrk_region3_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_bJetPt_bybin_CR->GetXaxis()->SetTitle("JetPt");

    h_Top_bJetPt_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_SR->GetXaxis()->SetTitle("JetPt");

    h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_bJetPt_region3_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetTitle("JetPt");

    h_Top_lJetPt_region1_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_region2_SR->GetXaxis()->SetTitle("JetPt");


    h_Top_lJetPt_region1_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_region2_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_region3_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetTitle("JetPt");

    h_Top_bJetPt_region1_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_bJetPt_region2_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitle("nJets");
    h_Top_bJetPt_region3_bybin_CR->GetYaxis()->SetTitle("nJets");

    h_Top_lJetPt_region1_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region2_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region3_bybin_CR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetPt_bybin_CR->GetYaxis()->SetTitle("nJets");

    h_Top_btrk_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_ltrk_bybin_CR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetPt_SR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_SR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetEta_diffFR_CR->GetXaxis()->SetTitle("Jet #eta");
    h_Top_lJetEta_diffFR_CR->GetXaxis()->SetTitle("Jet #eta");
    h_Top_bJetEta_diffFR_CR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetEta_diffFR_CR->GetYaxis()->SetTitle("nJets");

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
    /*
    c1->Divide(3, 1);
    c1->cd(1);
    h_Top_btrk_bybin_CR->Draw();
    h_Top_btrk_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_btrk_bybin_CR, "CR", "l");
    l0->AddEntry(h_Top_btrk_SR, "SR", "l");
    l0->Draw();

    c1->cd(2);
    h_Top_ctrk_bybin_CR->Draw("h");
    h_Top_ctrk_SR->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("c flavor");
    l1->AddEntry(h_Top_ctrk_bybin_CR, "CR", "l");
    l1->AddEntry(h_Top_ctrk_SR, "SR", "l");
    l1->Draw();

    c1->cd(3);
    h_Top_ltrk_bybin_CR->Draw("h");
    h_Top_ltrk_SR->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor");
    l2->AddEntry(h_Top_ltrk_bybin_CR, "CR", "l");
    l2->AddEntry(h_Top_ltrk_SR, "SR", "l");
    l2->Draw();
    */

    c1->Divide(1, 2);

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg1_CR_SR_ratio = (TH1D *)h_Top_btrk_region1_bybin_CR->Clone("h_btrk_rg1_CR_SR_ratio");
    h_btrk_rg1_CR_SR_ratio->Divide(h_Top_btrk_region1_bybin_CR, h_Top_btrk_region1_SR, 1, 1);

    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region1_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_btrk_region1_SR->GetYaxis()->SetTitle("nJet");

        h_Top_btrk_region1_SR->GetXaxis()->SetRangeUser(0, 25);
    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetRangeUser(0, 25);

    h_Top_btrk_region1_SR->Draw("h ");
    h_Top_btrk_region1_bybin_CR->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , |#eta| < 1.");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region1_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
    l0->AddEntry(h_Top_btrk_region1_SR, "True Background", "El");
    l0->Draw();

    c1->cd(2);

    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 25);

    h_btrk_rg1_CR_SR_ratio->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg1_CR_SR_ratio = (TH1D *)h_Top_btrk_region3_bybin_CR->Clone("h_btrk_rg1_CR_SR_ratio");
    h_btrk_rg1_CR_SR_ratio->Divide(h_Top_btrk_region3_bybin_CR, h_Top_btrk_region3_SR, 1, 1);

    h_Top_btrk_region3_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region3_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_btrk_region3_SR->GetYaxis()->SetTitle("nJet");

    h_Top_btrk_region3_SR->GetXaxis()->SetRangeUser(0, 25);
    h_Top_btrk_region3_bybin_CR->GetXaxis()->SetRangeUser(0, 25);

    h_Top_btrk_region3_SR->Draw("h ");
    h_Top_btrk_region3_bybin_CR->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 2 < |#eta| < 2.5.");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region3_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
    l0->AddEntry(h_Top_btrk_region3_SR, "True Background", "El");
    l0->Draw();

    c1->cd(2);

    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 25);

    h_btrk_rg1_CR_SR_ratio->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg1_CR_SR_ratio = (TH1D *)h_Top_ltrk_region1_bybin_CR->Clone("h_ltrk_rg1_CR_SR_ratio");
    h_ltrk_rg1_CR_SR_ratio->Divide(h_Top_ltrk_region1_bybin_CR, h_Top_ltrk_region1_SR, 1, 1);

    h_Top_ltrk_region1_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region1_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_ltrk_region1_SR->GetYaxis()->SetTitle("nJet");

        h_Top_ltrk_region1_SR->GetXaxis()->SetRangeUser(0, 25);
    h_Top_ltrk_region1_bybin_CR->GetXaxis()->SetRangeUser(0, 25);

    h_Top_ltrk_region1_SR->Draw("h ");
    h_Top_ltrk_region1_bybin_CR->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| < 1.");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region1_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
    l0->AddEntry(h_Top_ltrk_region1_SR, "True Background", "El");
    l0->Draw();

    c1->cd(2);

    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
    h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

    h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 25);

    h_ltrk_rg1_CR_SR_ratio->Draw();
    */
    /*
        c1->cd(1);

     gPad->SetTopMargin(0.01);
     gPad->SetBottomMargin(0);
     gPad->SetRightMargin(0.04);

     TH1D *h_ltrk_rg1_CR_SR_ratio = (TH1D *)h_Top_ltrk_region2_bybin_CR->Clone("h_ltrk_rg1_CR_SR_ratio");
     h_ltrk_rg1_CR_SR_ratio->Divide(h_Top_ltrk_region2_bybin_CR, h_Top_ltrk_region2_SR, 1, 1);

     h_Top_ltrk_region2_bybin_CR->GetXaxis()->SetLabelSize(0);
     h_Top_ltrk_region2_SR->GetYaxis()->SetTitleSize(0.06);
     h_Top_ltrk_region2_SR->GetYaxis()->SetTitle("nJet");

     h_Top_ltrk_region2_SR->GetXaxis()->SetRangeUser(0, 25);
     h_Top_ltrk_region2_bybin_CR->GetXaxis()->SetRangeUser(0, 25);

     h_Top_ltrk_region2_SR->Draw("h ");
     h_Top_ltrk_region2_bybin_CR->Draw("same ");

     TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l0->SetHeader("light flavor , 1 < |#eta| < 2");
     l0->SetTextSize(0.04);
     l0->SetBorderSize(0);
     l0->SetFillStyle(0);
     l0->AddEntry(h_Top_ltrk_region2_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
     l0->AddEntry(h_Top_ltrk_region2_SR, "True Background", "El");
     l0->Draw();

     c1->cd(2);

     gPad->SetRightMargin(0.04);
     gPad->SetTopMargin(0);
     gPad->SetBottomMargin(0.2);
     gPad->SetTickx();

     h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
     h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
     h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Track multiplicity");
     h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
     h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

     h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 25);

     h_ltrk_rg1_CR_SR_ratio->Draw();
     */
    /*
           c1->cd(1);

     gPad->SetTopMargin(0.01);
     gPad->SetBottomMargin(0);
     gPad->SetRightMargin(0.04);

     TH1D *h_lJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_lJetPt_region2_bybin_CR->Clone("h_lJetPt_rg1_CR_SR_ratio");
     h_lJetPt_rg1_CR_SR_ratio->Divide(h_Top_lJetPt_region2_bybin_CR, h_Top_lJetPt_region2_SR, 1, 1);

     h_Top_lJetPt_region2_bybin_CR->GetXaxis()->SetLabelSize(0);
     h_Top_lJetPt_region2_SR->GetYaxis()->SetTitleSize(0.06);
     h_Top_lJetPt_region2_SR->GetYaxis()->SetTitle("nJet");

     //h_Top_lJetPt_region2_SR->GetXaxis()->SetRangeUser(0, 25);
     //h_Top_lJetPt_region2_bybin_CR->GetXaxis()->SetRangeUser(0, 25);

     h_Top_lJetPt_region2_SR->Draw("h ");
     h_Top_lJetPt_region2_bybin_CR->Draw("same ");

     TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l0->SetHeader("light flavor , 1 < |#eta| < 2");
     l0->SetTextSize(0.04);
     l0->SetBorderSize(0);
     l0->SetFillStyle(0);
     l0->AddEntry(h_Top_lJetPt_region2_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
     l0->AddEntry(h_Top_lJetPt_region2_SR, "True Background", "El");
     l0->Draw();

     c1->cd(2);

     gPad->SetRightMargin(0.04);
     gPad->SetTopMargin(0);
     gPad->SetBottomMargin(0.2);
     gPad->SetTickx();

     h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
     h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
     h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");
     h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
     h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

     //h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 25);

     h_lJetPt_rg1_CR_SR_ratio->Draw();
     */
    /*
     c1->cd(1);

     gPad->SetTopMargin(0.01);
     gPad->SetBottomMargin(0);
     gPad->SetRightMargin(0.04);

     TH1D *h_lJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_lJetPt_region1_bybin_CR->Clone("h_lJetPt_rg1_CR_SR_ratio");
     h_lJetPt_rg1_CR_SR_ratio->Divide(h_Top_lJetPt_region1_bybin_CR, h_Top_lJetPt_region1_SR, 1, 1);

     h_Top_lJetPt_region1_bybin_CR->GetXaxis()->SetLabelSize(0);
     h_Top_lJetPt_region1_SR->GetYaxis()->SetTitleSize(0.06);
     h_Top_lJetPt_region1_SR->GetYaxis()->SetTitle("nJet");

     //h_Top_lJetPt_region1_SR->GetXaxis()->SetRangeUser(0, 25);
     //h_Top_lJetPt_region1_bybin_CR->GetXaxis()->SetRangeUser(0, 25);

     h_Top_lJetPt_region1_SR->Draw("h ");
     h_Top_lJetPt_region1_bybin_CR->Draw("same ");

     TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l0->SetHeader("light flavor , |#eta| < 1");
     l0->SetTextSize(0.04);
     l0->SetBorderSize(0);
     l0->SetFillStyle(0);
     l0->AddEntry(h_Top_lJetPt_region1_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
     l0->AddEntry(h_Top_lJetPt_region1_SR, "True Background", "El");
     l0->Draw();

     c1->cd(2);

     gPad->SetRightMargin(0.04);
     gPad->SetTopMargin(0);
     gPad->SetBottomMargin(0.2);
     gPad->SetTickx();

     h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
     h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
     h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");
     h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
     h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

     //h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 25);

     h_lJetPt_rg1_CR_SR_ratio->Draw();
     */
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_lJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_lJetPt_region3_bybin_CR->Clone("h_lJetPt_rg1_CR_SR_ratio");
    h_lJetPt_rg1_CR_SR_ratio->Divide(h_Top_lJetPt_region3_bybin_CR, h_Top_lJetPt_region3_SR, 1, 1);

    h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitle("nJet");

    // h_Top_lJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 25);
    // h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(0, 25);

    h_Top_lJetPt_region3_SR->Draw("h ");
    // h_Top_lJetPt_region3_bybin_CR->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 2< |#eta| < 2.5");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_lJetPt_region3_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
    l0->AddEntry(h_Top_lJetPt_region3_SR, "True Background", "El");
    l0->Draw();

    c1->cd(2);

    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
    h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");
    h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
    h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

    // h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 25);

    h_lJetPt_rg1_CR_SR_ratio->Draw();
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg1_CR_SR_ratio = (TH1D *)h_Top_ltrk_region3_bybin_CR->Clone("h_ltrk_rg1_CR_SR_ratio");
    h_ltrk_rg1_CR_SR_ratio->Divide(h_Top_ltrk_region3_bybin_CR, h_Top_ltrk_region3_SR, 1, 1);

    h_Top_ltrk_region3_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region3_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_ltrk_region3_SR->GetYaxis()->SetTitle("nJet");

    h_Top_ltrk_region3_SR->GetXaxis()->SetRangeUser(0, 25);
    h_Top_ltrk_region3_bybin_CR->GetXaxis()->SetRangeUser(0, 25);

    h_Top_ltrk_region3_SR->Draw("h ");
    h_Top_ltrk_region3_bybin_CR->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 2 < |#eta| < 2.5.");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region3_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
    l0->AddEntry(h_Top_ltrk_region3_SR, "True Background", "El");
    l0->Draw();

    c1->cd(2);

    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
    h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

    h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 25);

    h_ltrk_rg1_CR_SR_ratio->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_bJetPt_region3_bybin_CR->Clone("h_bJetPt_rg1_CR_SR_ratio");
    h_bJetPt_rg1_CR_SR_ratio->Divide(h_Top_bJetPt_region3_bybin_CR, h_Top_bJetPt_region3_SR, 1, 1);

    h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitle("nJet");

    h_Top_bJetPt_region3_SR->GetXaxis()->SetRangeUser(0, 500);
    h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetRangeUser(0, 500);

    h_Top_bJetPt_region3_SR->Draw("h ");
    h_Top_bJetPt_region3_bybin_CR->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 2 < |#eta| < 2.5.");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_region3_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
    l0->AddEntry(h_Top_bJetPt_region3_SR, "True Background", "El");
    l0->Draw();

    c1->cd(2);

    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 500);

    h_bJetPt_rg1_CR_SR_ratio->Draw();
    */
    /*
   c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_bJetPt_region2_bybin_CR->Clone("h_bJetPt_rg1_CR_SR_ratio");
    h_bJetPt_rg1_CR_SR_ratio->Divide(h_Top_bJetPt_region2_bybin_CR, h_Top_bJetPt_region2_SR, 1, 1);

    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitle("nJet");

    h_Top_bJetPt_region2_SR->GetXaxis()->SetRangeUser(0, 800);
    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetRangeUser(0, 800);

    h_Top_bJetPt_region2_SR->Draw("h ");
    h_Top_bJetPt_region2_bybin_CR->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_region2_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
    l0->AddEntry(h_Top_bJetPt_region2_SR, "True Background", "El");
    l0->Draw();

    c1->cd(2);

    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 800);

    h_bJetPt_rg1_CR_SR_ratio->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_bJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_bJetPt_region1_bybin_CR->Clone("h_bJetPt_rg1_CR_SR_ratio");
    h_bJetPt_rg1_CR_SR_ratio->Divide(h_Top_bJetPt_region1_bybin_CR, h_Top_bJetPt_region1_SR, 1, 1);

    h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitle("nJet");

    //h_Top_bJetPt_region1_SR->GetXaxis()->SetRangeUser(0, 800);
    //h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetRangeUser(0, 800);

    h_Top_bJetPt_region1_SR->Draw("h ");
    h_Top_bJetPt_region1_bybin_CR->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor ,  |#eta| < 1");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetPt_region1_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
    l0->AddEntry(h_Top_bJetPt_region1_SR, "True Background", "El");
    l0->Draw();

    c1->cd(2);

    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");
    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

    //h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 800);

    h_bJetPt_rg1_CR_SR_ratio->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg1_CR_SR_ratio = (TH1D *)h_Top_btrk_region2_bybin_CR->Clone("h_btrk_rg1_CR_SR_ratio");
    h_btrk_rg1_CR_SR_ratio->Divide(h_Top_btrk_region2_bybin_CR, h_Top_btrk_region2_SR, 1, 1);

    h_Top_btrk_region2_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region2_SR->GetYaxis()->SetTitleSize(0.06);
    h_Top_btrk_region2_SR->GetYaxis()->SetTitle("nJet");

    h_Top_btrk_region2_SR->GetXaxis()->SetRangeUser(0, 15);
    h_Top_btrk_region2_bybin_CR->GetXaxis()->SetRangeUser(0, 15);

    h_Top_btrk_region2_SR->Draw("h ");
    h_Top_btrk_region2_bybin_CR->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region2_bybin_CR, "predict (Top to emu apply emu low fake rate)", "El");
    l0->AddEntry(h_Top_btrk_region2_SR, "True Background", "El");
    l0->Draw();

    c1->cd(2);

    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetTitle("predict / True Background");
    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetTitleSize(0.06);

    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetRangeUser(0, 15);

    h_btrk_rg1_CR_SR_ratio->Draw();
    */
    /*
    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_btrk_region2_SR->GetXaxis()->SetLabelSize(0);

    h_Top_btrk_region2_SR->Draw("h");
    h_Top_btrk_region2_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor , 1 < |#eta| < 2.");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_btrk_region2_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_btrk_region2_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);

    gPad->SetTopMargin(1);

    TH1D *h_btrk_rg2_CR_SR_ratio = (TH1D *)h_Top_btrk_region2_bybin_CR->Clone("h_btrk_rg2_CR_SR_ratio");
    h_btrk_rg2_CR_SR_ratio->Divide(h_Top_btrk_region2_bybin_CR, h_Top_btrk_region2_SR, 1, 1);

    h_btrk_rg2_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_btrk_rg2_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_btrk_rg2_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_btrk_rg2_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_btrk_region3_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_btrk_region3_bybin_CR->Draw(" ");
    h_Top_btrk_region3_SR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor , 2 < |#eta| < 2.5");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_btrk_region3_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_btrk_region3_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);

    gPad->SetTopMargin(1);

    TH1D *h_btrk_rg3_CR_SR_ratio = (TH1D *)h_Top_btrk_region3_bybin_CR->Clone("h_btrk_rg3_CR_SR_ratio");
    h_btrk_rg3_CR_SR_ratio->Divide(h_Top_btrk_region3_bybin_CR, h_Top_btrk_region3_SR, 1, 1);

    h_btrk_rg3_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_btrk_rg3_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_btrk_rg3_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_btrk_rg3_CR_SR_ratio->Draw();
    */

    /*
    c1->Divide(3, 2);
    c1->cd(1);

    gPad->SetBottomMargin(0.02);

    h_Top_ltrk_region1_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region1_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_ltrk_region1_bybin_CR->Draw("");
    h_Top_ltrk_region1_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| < 1.");
    l0->SetTextSize(0.03);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region1_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l0->AddEntry(h_Top_ltrk_region1_SR, "SR", "El");
    l0->Draw();

    c1->cd(4);

    gPad->SetTopMargin(1);

    TH1D *h_ltrk_rg1_CR_SR_ratio = (TH1D *)h_Top_ltrk_region1_bybin_CR->Clone("h_ltrk_rg1_CR_SR_ratio");
    h_ltrk_rg1_CR_SR_ratio->Divide(h_Top_ltrk_region1_bybin_CR, h_Top_ltrk_region1_SR, 1, 1);

    h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_ltrk_rg1_CR_SR_ratio->Draw();

    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_ltrk_region2_SR->GetXaxis()->SetLabelSize(0);

    h_Top_ltrk_region2_SR->Draw("h");
    h_Top_ltrk_region2_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor , 1 < |#eta| < 2.");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_ltrk_region2_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_ltrk_region2_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);

    gPad->SetTopMargin(1);

    TH1D *h_ltrk_rg2_CR_SR_ratio = (TH1D *)h_Top_ltrk_region2_bybin_CR->Clone("h_ltrk_rg2_CR_SR_ratio");
    h_ltrk_rg2_CR_SR_ratio->Divide(h_Top_ltrk_region2_bybin_CR, h_Top_ltrk_region2_SR, 1, 1);

    h_ltrk_rg2_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_ltrk_rg2_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_ltrk_rg2_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_ltrk_rg2_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_ltrk_region3_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_ltrk_region3_bybin_CR->Draw(" ");
    h_Top_ltrk_region3_SR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor , 2 < |#eta| < 2.5");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_ltrk_region3_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_ltrk_region3_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);

    gPad->SetTopMargin(1);

    TH1D *h_ltrk_rg3_CR_SR_ratio = (TH1D *)h_Top_ltrk_region3_bybin_CR->Clone("h_ltrk_rg3_CR_SR_ratio");
    h_ltrk_rg3_CR_SR_ratio->Divide(h_Top_ltrk_region3_bybin_CR, h_Top_ltrk_region3_SR, 1, 1);

    h_ltrk_rg3_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_ltrk_rg3_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_ltrk_rg3_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_ltrk_rg3_CR_SR_ratio->Draw();

    */

    /*
     c1->Divide(3, 1);
     c1->cd(1);
     h_Top_bJetPt_bybin_CR->Draw();
     h_Top_bJetPt_SR->Draw("h same");

     TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l0->SetHeader("b flavor");
     l0->AddEntry(h_Top_bJetPt_bybin_CR, "CR", "l");
     l0->AddEntry(h_Top_bJetPt_SR, "SR", "l");
     l0->Draw();

     c1->cd(2);
     h_Top_cJetPt_SR->Draw("");
     h_Top_cJetPt_bybin_CR->Draw("h same");

     TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l1->SetHeader("c flavor");
     l1->AddEntry(h_Top_cJetPt_bybin_CR, "CR", "l");
     l1->AddEntry(h_Top_cJetPt_SR, "SR", "l");
     l1->Draw();

     c1->cd(3);
     h_Top_lJetPt_SR->Draw("");
     h_Top_lJetPt_bybin_CR->Draw("h same");

     TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l2->SetHeader("light flavor");
     l2->AddEntry(h_Top_lJetPt_bybin_CR, "CR", "l");
     l2->AddEntry(h_Top_lJetPt_SR, "SR", "l");
     l2->Draw();
     */
    /*
    c1->Divide(3, 2);
    c1->cd(1);

    gPad->SetBottomMargin(0.02);

    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetPt_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region1_SR->GetYaxis()->SetRangeUser(-0.2, 35);

    h_Top_bJetPt_region1_SR->Draw("h ");
    h_Top_bJetPt_region1_bybin_CR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetTextSize(0.03);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->AddEntry(h_Top_bJetPt_region1_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l0->AddEntry(h_Top_bJetPt_region1_SR, "SR", "El");
    l0->Draw();

    c1->cd(4);

    gPad->SetTopMargin(1);

    TH1D *h_bJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_bJetPt_region1_bybin_CR->Clone("h_bJetPt_rg1_CR_SR_ratio");
    h_bJetPt_rg1_CR_SR_ratio->Divide(h_Top_bJetPt_region1_bybin_CR, h_Top_bJetPt_region1_SR, 1, 1);

    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    //h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_bJetPt_rg1_CR_SR_ratio->Draw();

    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetPt_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region2_SR->GetYaxis()->SetRangeUser(-0.2, 35);

    h_Top_bJetPt_region2_SR->Draw("h ");
    h_Top_bJetPt_region2_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_lJetPt_region2_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_lJetPt_region2_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);

    gPad->SetTopMargin(1);

    TH1D *h_bJetPt_rg2_CR_SR_ratio = (TH1D *)h_Top_bJetPt_region2_bybin_CR->Clone("h_bJetPt_rg2_CR_SR_ratio");
    h_bJetPt_rg2_CR_SR_ratio->Divide(h_Top_bJetPt_region2_bybin_CR, h_Top_bJetPt_region2_SR, 1, 1);

    h_bJetPt_rg2_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    //h_bJetPt_rg2_CR_SR_ratio->GetYaxis()->SetRangeUser(-20, 10);
    h_bJetPt_rg2_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_bJetPt_rg2_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_bJetPt_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region3_SR->GetYaxis()->SetRangeUser(-0.2, 10);

    h_Top_bJetPt_region3_SR->Draw("h ");
    h_Top_bJetPt_region3_bybin_CR->Draw(" same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_lJetPt_region3_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_lJetPt_region3_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);

    gPad->SetTopMargin(1);

    TH1D *h_bJetPt_rg3_CR_SR_ratio = (TH1D *)h_Top_bJetPt_region3_bybin_CR->Clone("h_bJetPt_rg3_CR_SR_ratio");
    h_bJetPt_rg3_CR_SR_ratio->Divide(h_Top_bJetPt_region3_bybin_CR, h_Top_bJetPt_region3_SR, 1, 1);

    h_bJetPt_rg3_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    //h_bJetPt_rg3_CR_SR_ratio->GetYaxis()->SetRangeUser(-20, 20);
    h_bJetPt_rg3_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_bJetPt_rg3_CR_SR_ratio->Draw();
    */

    /*
    c1->Divide(3, 2);
    c1->cd(1);

    gPad->SetBottomMargin(0.02);

    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitle("nJets");

    h_Top_lJetPt_region1_SR->GetXaxis()->SetLabelSize(0);
    //h_Top_lJetPt_region1_SR->GetYaxis()->SetRangeUser(-0.2, 35);

    h_Top_lJetPt_region1_SR->Draw("h ");
    h_Top_lJetPt_region1_bybin_CR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetTextSize(0.03);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->AddEntry(h_Top_lJetPt_region1_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l0->AddEntry(h_Top_lJetPt_region1_SR, "SR", "El");
    l0->Draw();

    c1->cd(4);

    gPad->SetTopMargin(1);

    TH1D *h_lJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_lJetPt_region1_bybin_CR->Clone("h_lJetPt_rg1_CR_SR_ratio");
    h_lJetPt_rg1_CR_SR_ratio->Divide(h_Top_lJetPt_region1_bybin_CR, h_Top_lJetPt_region1_SR, 1, 1);

    h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_lJetPt_rg1_CR_SR_ratio->Draw();

    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitle("nJets");

    h_Top_lJetPt_region2_SR->GetXaxis()->SetLabelSize(0);
    //h_Top_lJetPt_region2_SR->GetYaxis()->SetRangeUser(-0.2, 35);

    h_Top_lJetPt_region2_SR->Draw("h ");
    h_Top_lJetPt_region2_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_lJetPt_region2_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_lJetPt_region2_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);

    gPad->SetTopMargin(1);

    TH1D *h_lJetPt_rg2_CR_SR_ratio = (TH1D *)h_Top_lJetPt_region2_bybin_CR->Clone("h_lJetPt_rg2_CR_SR_ratio");
    h_lJetPt_rg2_CR_SR_ratio->Divide(h_Top_lJetPt_region2_bybin_CR, h_Top_lJetPt_region2_SR, 1, 1);

    h_lJetPt_rg2_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_bJetPt_rg2_CR_SR_ratio->GetYaxis()->SetRangeUser(-20, 10);
    h_lJetPt_rg2_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_lJetPt_rg2_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_lJetPt_region3_SR->GetXaxis()->SetLabelSize(0);
    //h_Top_lJetPt_region3_SR->GetYaxis()->SetRangeUser(-0.2, 10);

    h_Top_lJetPt_region3_SR->Draw("h ");
    h_Top_lJetPt_region3_bybin_CR->Draw(" same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_lJetPt_region3_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_lJetPt_region3_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);

    gPad->SetTopMargin(1);

    TH1D *h_lJetPt_rg3_CR_SR_ratio = (TH1D *)h_Top_lJetPt_region3_bybin_CR->Clone("h_lJetPt_rg3_CR_SR_ratio");
    h_lJetPt_rg3_CR_SR_ratio->Divide(h_Top_lJetPt_region3_bybin_CR, h_Top_lJetPt_region3_SR, 1, 1);

    h_lJetPt_rg3_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_bJetPt_rg3_CR_SR_ratio->GetYaxis()->SetRangeUser(-20, 20);
    h_lJetPt_rg3_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_lJetPt_rg3_CR_SR_ratio->Draw();

    */
    /*
    c1->Divide(3, 2);
    c1->cd(1);

    gPad->SetBottomMargin(0.02);

    h_Top_bJetEta_diffFR_CR->GetXaxis()->SetLabelSize(0);

    h_Top_bJetEta_diffFR_CR->Draw("");

    h_Top_bJetEta_diffregion_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor");
    l0->SetTextSize(0.03);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetEta_diffFR_CR, "CR (Top to emu apply ee fake rate)", "El");
    l0->AddEntry(h_Top_bJetEta_diffregion_SR, "SR", "El");
    l0->Draw();

    TH1D *h_bJetEta_CR_SR_ratio = (TH1D *)h_Top_bJetEta_diffFR_CR->Clone("h_bJetEta_CR_SR_ratio");
    h_bJetEta_CR_SR_ratio->Divide(h_Top_bJetEta_diffFR_CR, h_Top_bJetEta_diffregion_SR, 1, 1);

    c1->cd(4);
    gPad->SetTopMargin(1);
    h_bJetEta_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    h_bJetEta_CR_SR_ratio->Draw();

    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_cJetEta_diffregion_SR->GetXaxis()->SetLabelSize(0);

    h_Top_cJetEta_diffregion_SR->Draw("h");
    h_Top_cJetEta_diffregion_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("c flavor");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_cJetEta_diffregion_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_cJetEta_diffregion_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);
    gPad->SetTopMargin(1);

    TH1D *h_cJetEta_CR_SR_ratio = (TH1D *)h_Top_cJetEta_diffregion_bybin_CR->Clone("h_cJetEta_CR_SR_ratio");
    h_cJetEta_CR_SR_ratio->Divide(h_Top_cJetEta_diffregion_bybin_CR, h_Top_cJetEta_diffregion_SR, 1, 1);

    h_cJetEta_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    h_cJetEta_CR_SR_ratio->GetYaxis()->SetRangeUser(-2, 50);
    h_cJetEta_CR_SR_ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cJetEta_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_lJetEta_diffFR_CR->GetXaxis()->SetLabelSize(0);
    //h_Top_lJetEta_diffFR_CR->GetXaxis()->SetTitleSize(0);

    h_Top_lJetEta_diffFR_CR->Draw(" ");
    h_Top_lJetEta_diffregion_SR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_lJetEta_diffFR_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_lJetEta_diffregion_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);
    gPad->SetTopMargin(1);

    TH1D *h_lJetEta_CR_SR_ratio = (TH1D *)h_Top_lJetEta_diffFR_CR->Clone("h_lJetEta_CR_SR_ratio");
    h_lJetEta_CR_SR_ratio->Divide(h_Top_lJetEta_diffFR_CR, h_Top_lJetEta_diffregion_SR, 1, 1);

    h_lJetEta_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_lJetEta_CR_SR_ratio->GetYaxis()->SetRangeUser(-2, 50);
    h_lJetEta_CR_SR_ratio->GetXaxis()->SetTitle("Jet #eta");

    h_lJetEta_CR_SR_ratio->Draw();
    */
    const double LABELSIZE = 20.0;

    /*
    c1->Divide(2, 2);
    c1->cd(1);

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_bJetPt_bybin_CR->SetTitle("without consider eta");

    h_Top_bJetPt_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_bJetPt_bybin_CR->GetXaxis()->SetTitleSize(0);
    h_Top_bJetPt_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_bJetPt_bybin_CR->Draw("h ");
    h_Top_bJetPt_SR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_bJetPt_SR, "True Background", "le");
    l0->AddEntry(h_Top_bJetPt_bybin_CR, "Predicted", "le");
    l0->Draw();

    c1->cd(3);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_cutalpha_applyfr_bRatio;
    h_cutalpha_applyfr_bRatio = (TH1F *)h_Top_bJetPt_SR->Clone("h_cutalpha_applyfr_bRatio");
    h_cutalpha_applyfr_bRatio->Divide(h_Top_bJetPt_SR, h_Top_bJetPt_bybin_CR, 1, 1, "b");

    h_cutalpha_applyfr_bRatio->GetYaxis()->SetTitle("True Background / Predicted");
    h_cutalpha_applyfr_bRatio->GetXaxis()->SetTitle("Jet PT");

    h_cutalpha_applyfr_bRatio->GetYaxis()->SetRangeUser(0., 2.);

    h_cutalpha_applyfr_bRatio->Draw("e1");

    c1->cd(2);

    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_lJetPt_bybin_CR->SetTitle("without consider eta");

    h_Top_lJetPt_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_lJetPt_bybin_CR->GetXaxis()->SetTitleSize(0);
    h_Top_lJetPt_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_lJetPt_SR->Draw("");
    h_Top_lJetPt_bybin_CR->Draw("h same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetPt_SR, "True Background", "le");
    l1->AddEntry(h_Top_lJetPt_bybin_CR, "Predicted", "le");
    l1->Draw();

    c1->cd(4);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_cutalpha_applyfr_lRatio;
    h_cutalpha_applyfr_lRatio = (TH1F *)h_Top_lJetPt_SR->Clone("h_cutalpha_applyfr_lRatio");
    h_cutalpha_applyfr_lRatio->Divide(h_Top_lJetPt_SR, h_Top_lJetPt_bybin_CR, 1, 1, "b");

    h_cutalpha_applyfr_lRatio->GetYaxis()->SetTitle("True Background / Predicted");
    h_cutalpha_applyfr_lRatio->GetXaxis()->SetTitle("Jet PT");

    h_cutalpha_applyfr_lRatio->GetYaxis()->SetRangeUser(0., 2.);

    h_cutalpha_applyfr_lRatio->Draw("e1");
    */

    /*
    c1->Divide(2, 2);
    c1->cd(1);

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_btrk_bybin_CR->SetTitle("without consider eta");

    h_Top_btrk_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_btrk_bybin_CR->GetXaxis()->SetTitleSize(0);
    h_Top_btrk_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_btrk_bybin_CR->Draw("h ");
    h_Top_btrk_SR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_btrk_SR, "True Background", "le");
    l0->AddEntry(h_Top_btrk_bybin_CR, "Predicted", "le");
    l0->Draw();

    c1->cd(3);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_cutalpha_applyfr_bRatio;
    h_cutalpha_applyfr_bRatio = (TH1F *)h_Top_btrk_SR->Clone("h_cutalpha_applyfr_bRatio");
    h_cutalpha_applyfr_bRatio->Divide(h_Top_btrk_SR, h_Top_btrk_bybin_CR, 1, 1, "b");

    h_cutalpha_applyfr_bRatio->GetYaxis()->SetTitle("True Background / Predicted");
    h_cutalpha_applyfr_bRatio->GetXaxis()->SetTitle("Jet PT");

    h_cutalpha_applyfr_bRatio->GetYaxis()->SetRangeUser(0., 2.);

    h_cutalpha_applyfr_bRatio->Draw("e1");

    c1->cd(2);

    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_ltrk_bybin_CR->SetTitle("without consider eta");

    h_Top_ltrk_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_ltrk_bybin_CR->GetXaxis()->SetTitleSize(0);
    h_Top_ltrk_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_ltrk_SR->Draw("");
    h_Top_ltrk_bybin_CR->Draw("h same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_ltrk_SR, "True Background", "le");
    l1->AddEntry(h_Top_ltrk_bybin_CR, "Predicted", "le");
    l1->Draw();

    c1->cd(4);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_cutalpha_applyfr_lRatio;
    h_cutalpha_applyfr_lRatio = (TH1F *)h_Top_ltrk_SR->Clone("h_cutalpha_applyfr_lRatio");
    h_cutalpha_applyfr_lRatio->Divide(h_Top_ltrk_SR, h_Top_ltrk_bybin_CR, 1, 1, "b");

    h_cutalpha_applyfr_lRatio->GetYaxis()->SetTitle("True Background / Predicted");
    h_cutalpha_applyfr_lRatio->GetXaxis()->SetTitle("Jet PT");

    h_cutalpha_applyfr_lRatio->GetYaxis()->SetRangeUser(0., 2.);

    h_cutalpha_applyfr_lRatio->Draw("e1");

    */
    /*
    c1->Divide(3, 2);
    c1->cd(1);
    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_JetPt_bybin_CR->SetTitle("without consider eta");

    h_Top_JetPt_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_JetPt_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_JetPt_bybin_CR->GetXaxis()->SetTitleSize(0);
    h_Top_JetPt_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_JetPt_bybin_CR->Draw("h ");
    h_Top_JetPt_SR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_JetPt_SR, "True Background", "le");
    l0->AddEntry(h_Top_JetPt_bybin_CR, "Predicted", "le");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(4);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_cutalpha_applyfr_Ratio;
    h_cutalpha_applyfr_Ratio = (TH1F *)h_Top_JetPt_SR->Clone("h_cutalpha_applyfr_Ratio");
    h_cutalpha_applyfr_Ratio->Divide(h_Top_JetPt_bybin_CR);

    h_cutalpha_applyfr_Ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_cutalpha_applyfr_Ratio->GetXaxis()->SetTitle("Jet PT");

    // h_cutalpha_applyfr_Ratio->GetYaxis()->SetRangeUser(0., 2.);

    h_cutalpha_applyfr_Ratio->Draw("e1");

    c1->cd(2);

    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_trk_bybin_CR->SetTitle("without consider eta");

    h_Top_trk_SR->GetYaxis()->SetTitle("nJet");
    h_Top_trk_SR->GetXaxis()->SetTitle("trk");
    h_Top_trk_SR->GetXaxis()->SetTitleSize(0);
    h_Top_trk_SR->GetXaxis()->SetLabelSize(0);

    h_Top_trk_SR->Draw("");
    h_Top_trk_bybin_CR->Draw("h same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_trk_SR, "True Background", "le");
    l1->AddEntry(h_Top_trk_bybin_CR, "Predicted", "le");
    l1->Draw();

    c1->cd(5);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_cutalpha_applyfr_Ratio_trk;
    h_cutalpha_applyfr_Ratio_trk = (TH1F *)h_Top_trk_SR->Clone("h_cutalpha_applyfr_Ratio_trk");
    h_cutalpha_applyfr_Ratio_trk->Divide(h_Top_trk_bybin_CR);

    h_cutalpha_applyfr_Ratio_trk->GetYaxis()->SetTitle("True Background / Predicted");
    h_cutalpha_applyfr_Ratio_trk->GetXaxis()->SetTitle("trk");

    h_cutalpha_applyfr_Ratio_trk->GetXaxis()->SetLabelSize(0.04);
    h_cutalpha_applyfr_Ratio_trk->GetXaxis()->SetTitleSize(0.04);

    // h_cutalpha_applyfr_Ratio->GetYaxis()->SetRangeUser(0., 2.);

    h_cutalpha_applyfr_Ratio_trk->Draw("e1");

    c1->cd(3);

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_JetEta_bybin_CR->SetTitle("without consider eta");

    h_Top_JetEta_SR->GetYaxis()->SetTitle("nJet");
    h_Top_JetEta_SR->GetXaxis()->SetTitle("trk");
    h_Top_JetEta_SR->GetXaxis()->SetTitleSize(0);
    h_Top_JetEta_SR->GetXaxis()->SetLabelSize(0);

    h_Top_JetEta_SR->Draw("");
    h_Top_JetEta_bybin_CR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("light flavor");
    l2->AddEntry(h_Top_JetEta_SR, "True Background", "le");
    l2->AddEntry(h_Top_JetEta_bybin_CR, "Predicted", "le");
    l2->Draw();

    */
    /*
   c1->Divide(3, 2);
    c1->cd(1);
    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_btrk_region1_bybin_CR->SetTitle("without consider eta");

    h_Top_btrk_region1_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetTitleSize(0);
    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_btrk_region1_bybin_CR->Draw("h ");
    h_Top_btrk_region1_SR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->AddEntry(h_Top_btrk_region1_SR, "True Background", "le");
    l0->AddEntry(h_Top_btrk_region1_bybin_CR, "Predicted", "le");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(4);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_cutalpha_applyfr_Ratio;
    h_cutalpha_applyfr_Ratio = (TH1F *)h_Top_JetPt_SR->Clone("h_cutalpha_applyfr_Ratio");
    h_cutalpha_applyfr_Ratio->Divide(h_Top_JetPt_bybin_CR);

    h_cutalpha_applyfr_Ratio->GetYaxis()->SetTitle("True Background / Predicted");
    h_cutalpha_applyfr_Ratio->GetXaxis()->SetTitle("Jet PT");

    // h_cutalpha_applyfr_Ratio->GetYaxis()->SetRangeUser(0., 2.);

    h_cutalpha_applyfr_Ratio->Draw("e1");

    c1->cd(2);

    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_trk_bybin_CR->SetTitle("without consider eta");

    h_Top_trk_SR->GetYaxis()->SetTitle("nJet");
    h_Top_trk_SR->GetXaxis()->SetTitle("trk");
    h_Top_trk_SR->GetXaxis()->SetTitleSize(0);
    h_Top_trk_SR->GetXaxis()->SetLabelSize(0);

    h_Top_trk_SR->Draw("");
    h_Top_trk_bybin_CR->Draw("h same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_trk_SR, "True Background", "le");
    l1->AddEntry(h_Top_trk_bybin_CR, "Predicted", "le");
    l1->Draw();

    c1->cd(5);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_cutalpha_applyfr_Ratio_trk;
    h_cutalpha_applyfr_Ratio_trk = (TH1F *)h_Top_trk_SR->Clone("h_cutalpha_applyfr_Ratio_trk");
    h_cutalpha_applyfr_Ratio_trk->Divide(h_Top_trk_bybin_CR);

    h_cutalpha_applyfr_Ratio_trk->GetYaxis()->SetTitle("True Background / Predicted");
    h_cutalpha_applyfr_Ratio_trk->GetXaxis()->SetTitle("trk");

    h_cutalpha_applyfr_Ratio_trk->GetXaxis()->SetLabelSize(0.04);
    h_cutalpha_applyfr_Ratio_trk->GetXaxis()->SetTitleSize(0.04);

    // h_cutalpha_applyfr_Ratio->GetYaxis()->SetRangeUser(0., 2.);

    h_cutalpha_applyfr_Ratio_trk->Draw("e1");

    c1->cd(3);

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_JetEta_bybin_CR->SetTitle("without consider eta");

    h_Top_JetEta_SR->GetYaxis()->SetTitle("nJet");
    h_Top_JetEta_SR->GetXaxis()->SetTitle("trk");
    h_Top_JetEta_SR->GetXaxis()->SetTitleSize(0);
    h_Top_JetEta_SR->GetXaxis()->SetLabelSize(0);

    h_Top_JetEta_SR->Draw("");
    h_Top_JetEta_bybin_CR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("light flavor");
    l2->AddEntry(h_Top_JetEta_SR, "True Background", "le");
    l2->AddEntry(h_Top_JetEta_bybin_CR, "Predicted", "le");
    l2->Draw();
    */
    /*
    c1->cd(4);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_cutalpha_applyfr_Ratio;
    h_cutalpha_applyfr_Ratio = (TH1F *)h_Top_lJetPt_SR->Clone("h_cutalpha_applyfr_lRatio");
    h_cutalpha_applyfr_Ratio->Divide(h_Top_lJetPt_SR, h_Top_lJetPt_bybin_CR, 1, 1, "b");

    h_cutalpha_applyfr_lRatio->GetYaxis()->SetTitle("True Background / Predicted");
    h_cutalpha_applyfr_lRatio->GetXaxis()->SetTitle("Jet PT");

    h_cutalpha_applyfr_lRatio->GetYaxis()->SetRangeUser(0., 2.);

    h_cutalpha_applyfr_lRatio->Draw("e1");
    */

    gStyle->SetOptStat(0);
}