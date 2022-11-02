#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TF1.h>
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

Double_t Ratio(Double_t *x, Double_t *par)
{
    return (par[0] + par[1] * x[0]);
}

void draw_fakerate()
{
    TFile *Top_emufile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_fakerate.root");

    // For Top emu file
    TH1D *Top_eu_nTrk_bfakeRate_difeta_lowMET_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_lowMET_1"));
    TH1D *Top_eu_nTrk_cfakeRate_difeta_lowMET_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate_difeta_lowMET_1"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_lowMET_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_lowMET_1"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_lowMET_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_lowMET_2"));
    TH1D *Top_eu_nTrk_cfakeRate_difeta_lowMET_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate_difeta_lowMET_2"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_lowMET_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_lowMET_2"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_lowMET_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_lowMET_3"));
    TH1D *Top_eu_nTrk_cfakeRate_difeta_lowMET_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate_difeta_lowMET_3"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_lowMET_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_lowMET_3"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_highMET_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_highMET_1"));
    TH1D *Top_eu_nTrk_cfakeRate_difeta_highMET_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate_difeta_highMET_1"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_highMET_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_highMET_1"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_highMET_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_highMET_2"));
    TH1D *Top_eu_nTrk_cfakeRate_difeta_highMET_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate_difeta_highMET_2"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_highMET_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_highMET_2"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_highMET_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_highMET_3"));
    TH1D *Top_eu_nTrk_cfakeRate_difeta_highMET_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate_difeta_highMET_3"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_highMET_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_highMET_3"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_lowDilepPt_1"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_lowDilepPt_1"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_lowDilepPt_2"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_lowDilepPt_2"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_lowDilepPt_3"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_lowDilepPt_3"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_highDilepPt_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_highDilepPt_1"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_highDilepPt_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_highDilepPt_1"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_highDilepPt_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_highDilepPt_2"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_highDilepPt_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_highDilepPt_2"));

    TH1D *Top_eu_nTrk_bfakeRate_difeta_highDilepPt_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_highDilepPt_3"));
    TH1D *Top_eu_nTrk_lfakeRate_difeta_highDilepPt_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_highDilepPt_3"));

    //-------------------------------------
    // Set low dilepton PT fake rate style
    //-------------------------------------
    h_Style_Setting(Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1, kAzure + 4);
    h_Style_Setting(Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2, kAzure + 4);
    h_Style_Setting(Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3, kAzure + 4);

    h_Style_Setting(Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1, kAzure + 4);
    h_Style_Setting(Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2, kAzure + 4);
    h_Style_Setting(Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3, kAzure + 4);

    //-------------------------------------
    // Set high dilepton PT fake rate style
    //-------------------------------------
    h_Style_Setting(Top_eu_nTrk_bfakeRate_difeta_highDilepPt_1, kRed);
    h_Style_Setting(Top_eu_nTrk_bfakeRate_difeta_highDilepPt_2, kRed);
    h_Style_Setting(Top_eu_nTrk_bfakeRate_difeta_highDilepPt_3, kRed);

    h_Style_Setting(Top_eu_nTrk_lfakeRate_difeta_highDilepPt_1, kRed);
    h_Style_Setting(Top_eu_nTrk_lfakeRate_difeta_highDilepPt_2, kRed);
    h_Style_Setting(Top_eu_nTrk_lfakeRate_difeta_highDilepPt_3, kRed);

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

    
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg1_H_L_ratio = (TH1D *)Top_eu_nTrk_bfakeRate_difeta_highDilepPt_1->Clone("h_btrk_rg1_H_L_ratio");
    h_btrk_rg1_H_L_ratio->Divide(Top_eu_nTrk_bfakeRate_difeta_highDilepPt_1, Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1, 1, 1);

    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1->GetXaxis()->SetLabelSize(0);
    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1->GetYaxis()->SetTitleSize(0.06);
    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1->GetXaxis()->SetRangeUser(1, 25);
    Top_eu_nTrk_bfakeRate_difeta_highDilepPt_1->GetXaxis()->SetRangeUser(1, 25);

    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1->Draw("h");
    Top_eu_nTrk_bfakeRate_difeta_highDilepPt_1->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1, "Low dilepton PT", "El");
    l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_highDilepPt_1, "High dilepton PT", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg1_H_L_ratio->SetLineColor(kBlack);
    h_btrk_rg1_H_L_ratio->GetYaxis()->SetTitle("High Region / Low Region");
    h_btrk_rg1_H_L_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg1_H_L_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg1_H_L_ratio->GetXaxis()->SetTitleSize(0.06);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg1_xmin = Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1->GetXaxis()->GetXmin();
    Double_t btrk_rg1_xax = Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_1->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg1_xmin, 25, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_btrk_rg1_H_L_ratio->Fit("f1", "MF");

    h_btrk_rg1_H_L_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_btrk_rg1_H_L_ratio->GetXaxis()->SetRangeUser(1, 25);

    h_btrk_rg1_H_L_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    //l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg2_H_L_ratio = (TH1D *)Top_eu_nTrk_bfakeRate_difeta_highDilepPt_2->Clone("h_btrk_rg2_H_L_ratio");
    h_btrk_rg2_H_L_ratio->Divide(Top_eu_nTrk_bfakeRate_difeta_highDilepPt_2, Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2, 1, 1);

    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2->GetXaxis()->SetLabelSize(0);
    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2->GetYaxis()->SetTitleSize(0.06);
    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2->GetXaxis()->SetRangeUser(1, 25);
    Top_eu_nTrk_bfakeRate_difeta_highDilepPt_2->GetXaxis()->SetRangeUser(1, 25);

    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2->Draw("h ");
    Top_eu_nTrk_bfakeRate_difeta_highDilepPt_2->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 1< |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2, "Low dilepton PT", "El");
    l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_highDilepPt_2, "High dilepton PT", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg2_H_L_ratio->SetLineColor(kBlack);
    h_btrk_rg2_H_L_ratio->GetYaxis()->SetTitle("High Region / Low Region");
    h_btrk_rg2_H_L_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg2_H_L_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg2_H_L_ratio->GetXaxis()->SetTitleSize(0.06);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg2_xmin = Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2->GetXaxis()->GetXmin();
    Double_t btrk_rg2_xax = Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_2->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg2_xmin, 25, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_btrk_rg2_H_L_ratio->Fit("f1", "MF");

    h_btrk_rg2_H_L_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_btrk_rg2_H_L_ratio->GetXaxis()->SetRangeUser(1, 25);

    h_btrk_rg2_H_L_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();

    c1->SaveAs("Top(emu)_HL_dileppT_bRatio_2.svg");
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_btrk_rg3_H_L_ratio = (TH1D *)Top_eu_nTrk_bfakeRate_difeta_highDilepPt_3->Clone("h_btrk_rg3_H_L_ratio");
    h_btrk_rg3_H_L_ratio->Divide(Top_eu_nTrk_bfakeRate_difeta_highDilepPt_3, Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3, 1, 1);

    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3->GetXaxis()->SetLabelSize(0);
    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3->GetYaxis()->SetTitleSize(0.06);
    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3->GetXaxis()->SetRangeUser(1, 25);
    Top_eu_nTrk_bfakeRate_difeta_highDilepPt_3->GetXaxis()->SetRangeUser(1, 25);

    Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3->Draw("h ");
    Top_eu_nTrk_bfakeRate_difeta_highDilepPt_3->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , 2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3, "Low dilepton PT", "El");
    l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_highDilepPt_3, "High dilepton PT", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_btrk_rg3_H_L_ratio->SetLineColor(kBlack);
    h_btrk_rg3_H_L_ratio->GetYaxis()->SetTitle("High Region / Low Region");
    h_btrk_rg3_H_L_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_btrk_rg3_H_L_ratio->GetYaxis()->SetTitleSize(0.06);
    h_btrk_rg3_H_L_ratio->GetXaxis()->SetTitleSize(0.06);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t btrk_rg3_xmin = Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3->GetXaxis()->GetXmin();
    Double_t btrk_rg3_xax = Top_eu_nTrk_bfakeRate_difeta_lowDilepPt_3->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, btrk_rg3_xmin, 25, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_btrk_rg3_H_L_ratio->Fit("f1", "MF");

    h_btrk_rg3_H_L_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_btrk_rg3_H_L_ratio->GetXaxis()->SetRangeUser(1, 25);

    h_btrk_rg3_H_L_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    // l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    // c1->SaveAs("Top(emu)_HL_dileppT_bRatio_2.svg");
    
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg1_H_L_ratio = (TH1D *)Top_eu_nTrk_lfakeRate_difeta_highDilepPt_1->Clone("h_ltrk_rg1_H_L_ratio");
    h_ltrk_rg1_H_L_ratio->Divide(Top_eu_nTrk_lfakeRate_difeta_highDilepPt_1, Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1, 1, 1);

    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1->GetXaxis()->SetLabelSize(0);
    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1->GetYaxis()->SetTitleSize(0.06);
    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1->GetXaxis()->SetRangeUser(1, 25);
    Top_eu_nTrk_lfakeRate_difeta_highDilepPt_1->GetXaxis()->SetRangeUser(1, 25);

    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1->Draw("h");
    Top_eu_nTrk_lfakeRate_difeta_highDilepPt_1->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| < 1");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1, "Low dilepton PT", "El");
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_highDilepPt_1, "High dilepton PT", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg1_H_L_ratio->SetLineColor(kBlack);
    h_ltrk_rg1_H_L_ratio->GetYaxis()->SetTitle("High Region / Low Region");
    h_ltrk_rg1_H_L_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg1_H_L_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg1_H_L_ratio->GetXaxis()->SetTitleSize(0.06);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg1_xmin = Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1->GetXaxis()->GetXmin();
    Double_t ltrk_rg1_xax = Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_1->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg1_xmin, ltrk_rg1_xax, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_ltrk_rg1_H_L_ratio->Fit("f1", "MFR");

    //h_ltrk_rg1_H_L_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_ltrk_rg1_H_L_ratio->GetXaxis()->SetRangeUser(1, 25);

    h_ltrk_rg1_H_L_ratio->Draw();

    TLegend *l1 = new TLegend(0.95, 0.3, 0.6, 0.5);
    l1->SetHeader("Fitting function");
    l1->SetTextSize(0.06);
    //l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(f1, "c0+c1*x", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    TH1D *h_ltrk_rg2_H_L_ratio = (TH1D *)Top_eu_nTrk_lfakeRate_difeta_highDilepPt_2->Clone("h_ltrk_rg2_H_L_ratio");
    h_ltrk_rg2_H_L_ratio->Divide(Top_eu_nTrk_lfakeRate_difeta_highDilepPt_2, Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2, 1, 1);

    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2->GetXaxis()->SetLabelSize(0);
    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2->GetYaxis()->SetTitleSize(0.06);
    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2->GetXaxis()->SetRangeUser(1, 25);
    Top_eu_nTrk_lfakeRate_difeta_highDilepPt_2->GetXaxis()->SetRangeUser(1, 25);

    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2->Draw("h ");
    Top_eu_nTrk_lfakeRate_difeta_highDilepPt_2->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 1 < |#eta| < 2");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2, "Low dilepton PT", "El");
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_highDilepPt_2, "High dilepton PT", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg2_H_L_ratio->SetLineColor(kBlack);
    h_ltrk_rg2_H_L_ratio->GetYaxis()->SetTitle("High Region / Low Region");
    h_ltrk_rg2_H_L_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg2_H_L_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg2_H_L_ratio->GetXaxis()->SetTitleSize(0.06);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg2_xmin = Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2->GetXaxis()->GetXmin();
    Double_t ltrk_rg2_xax = Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_2->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg2_xmin, 25, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_ltrk_rg2_H_L_ratio->Fit("f1", "MF");

    //h_ltrk_rg2_H_L_ratio->GetYaxis()->SetRangeUser(0, 2.);
    h_ltrk_rg2_H_L_ratio->GetXaxis()->SetRangeUser(1, 25);

    h_ltrk_rg2_H_L_ratio->Draw();

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

    TH1D *h_ltrk_rg3_H_L_ratio = (TH1D *)Top_eu_nTrk_lfakeRate_difeta_highDilepPt_3->Clone("h_ltrk_rg3_H_L_ratio");
    h_ltrk_rg3_H_L_ratio->Divide(Top_eu_nTrk_lfakeRate_difeta_highDilepPt_3, Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3, 1, 1);

    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3->GetXaxis()->SetLabelSize(0);
    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3->GetYaxis()->SetTitleSize(0.06);
    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3->GetXaxis()->SetRangeUser(1, 25);
    Top_eu_nTrk_lfakeRate_difeta_highDilepPt_3->GetXaxis()->SetRangeUser(1, 25);

    Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3->Draw("h ");
    Top_eu_nTrk_lfakeRate_difeta_highDilepPt_3->Draw("same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , 2 < |#eta| < 2.5");
    l0->SetTextSize(0.06);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3, "Low dilepton PT", "El");
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_highDilepPt_3, "High dilepton PT", "El");
    l0->Draw();

    c1->cd(2);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_ltrk_rg3_H_L_ratio->SetLineColor(kBlack);
    h_ltrk_rg3_H_L_ratio->GetYaxis()->SetTitle("High Region / Low Region");
    h_ltrk_rg3_H_L_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_ltrk_rg3_H_L_ratio->GetYaxis()->SetTitleSize(0.06);
    h_ltrk_rg3_H_L_ratio->GetXaxis()->SetTitleSize(0.06);

    //------------------------
    // Fit Ratio
    //------------------------
    Double_t ltrk_rg3_xmin = Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3->GetXaxis()->GetXmin();
    Double_t ltrk_rg3_xax = Top_eu_nTrk_lfakeRate_difeta_lowDilepPt_3->GetXaxis()->GetXmax();

    TF1 *f1 = new TF1("f1", Ratio, ltrk_rg3_xmin, 25, 2);

    f1->SetLineWidth(2);

    f1->SetLineColor(kTeal - 7);

    h_ltrk_rg3_H_L_ratio->Fit("f1", "MF");

    h_ltrk_rg3_H_L_ratio->GetYaxis()->SetRangeUser(0, 4.);
    h_ltrk_rg3_H_L_ratio->GetXaxis()->SetRangeUser(1, 25);

    h_ltrk_rg3_H_L_ratio->Draw();

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