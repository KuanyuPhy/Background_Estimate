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

void draw_all_fake_rate()
{
    TFile *DYfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/dy/DY_fakerate.root");
    TFile *Topfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top/diffeta/new_macro/top_fakerate.root");
    TFile *Top_emufile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_fakerate.root");

    // For DYfile
    TH1D *DY_nTrk_bfakeRate_difeta_lowMET_1 = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate_difeta_lowMET_1"));
    TH1D *DY_nTrk_cfakeRate_difeta_lowMET_1 = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate_difeta_lowMET_1"));
    TH1D *DY_nTrk_lfakeRate_difeta_lowMET_1 = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate_difeta_lowMET_1"));

    TH1D *DY_nTrk_bfakeRate_difeta_lowMET_2 = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate_difeta_lowMET_2"));
    TH1D *DY_nTrk_cfakeRate_difeta_lowMET_2 = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate_difeta_lowMET_2"));
    TH1D *DY_nTrk_lfakeRate_difeta_lowMET_2 = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate_difeta_lowMET_2"));

    TH1D *DY_nTrk_bfakeRate_difeta_lowMET_3 = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate_difeta_lowMET_3"));
    TH1D *DY_nTrk_cfakeRate_difeta_lowMET_3 = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate_difeta_lowMET_3"));
    TH1D *DY_nTrk_lfakeRate_difeta_lowMET_3 = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate_difeta_lowMET_3"));

    TH1D *DY_nTrk_bfakeRate_difeta_highMET_1 = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate_difeta_highMET_1"));
    TH1D *DY_nTrk_cfakeRate_difeta_highMET_1 = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate_difeta_highMET_1"));
    TH1D *DY_nTrk_lfakeRate_difeta_highMET_1 = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate_difeta_highMET_1"));

    TH1D *DY_nTrk_bfakeRate_difeta_highMET_2 = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate_difeta_highMET_2"));
    TH1D *DY_nTrk_cfakeRate_difeta_highMET_2 = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate_difeta_highMET_2"));
    TH1D *DY_nTrk_lfakeRate_difeta_highMET_2 = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate_difeta_highMET_2"));

    TH1D *DY_nTrk_bfakeRate_difeta_highMET_3 = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate_difeta_highMET_3"));
    TH1D *DY_nTrk_cfakeRate_difeta_highMET_3 = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate_difeta_highMET_3"));
    TH1D *DY_nTrk_lfakeRate_difeta_highMET_3 = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate_difeta_highMET_3"));

    // For Topfile
    TH1D *Top_ee_nTrk_bfakeRate_difeta_lowMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_1"));
    TH1D *Top_ee_nTrk_cfakeRate_difeta_lowMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_lowMET_1"));
    TH1D *Top_ee_nTrk_lfakeRate_difeta_lowMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_1"));

    TH1D *Top_ee_nTrk_bfakeRate_difeta_lowMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_2"));
    TH1D *Top_ee_nTrk_cfakeRate_difeta_lowMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_lowMET_2"));
    TH1D *Top_ee_nTrk_lfakeRate_difeta_lowMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_2"));

    TH1D *Top_ee_nTrk_bfakeRate_difeta_lowMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_3"));
    TH1D *Top_ee_nTrk_cfakeRate_difeta_lowMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_lowMET_3"));
    TH1D *Top_ee_nTrk_lfakeRate_difeta_lowMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_3"));

    TH1D *Top_ee_nTrk_bfakeRate_difeta_highMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_highMET_1"));
    TH1D *Top_ee_nTrk_cfakeRate_difeta_highMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_highMET_1"));
    TH1D *Top_ee_nTrk_lfakeRate_difeta_highMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_highMET_1"));

    TH1D *Top_ee_nTrk_bfakeRate_difeta_highMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_highMET_2"));
    TH1D *Top_ee_nTrk_cfakeRate_difeta_highMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_highMET_2"));
    TH1D *Top_ee_nTrk_lfakeRate_difeta_highMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_highMET_2"));

    TH1D *Top_ee_nTrk_bfakeRate_difeta_highMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_highMET_3"));
    TH1D *Top_ee_nTrk_cfakeRate_difeta_highMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_highMET_3"));
    TH1D *Top_ee_nTrk_lfakeRate_difeta_highMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_highMET_3"));

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

    DY_nTrk_bfakeRate_difeta_lowMET_1->SetLineWidth(2);
    DY_nTrk_cfakeRate_difeta_lowMET_1->SetLineWidth(2);
    DY_nTrk_lfakeRate_difeta_lowMET_1->SetLineWidth(2);

    DY_nTrk_bfakeRate_difeta_lowMET_2->SetLineWidth(2);
    DY_nTrk_cfakeRate_difeta_lowMET_2->SetLineWidth(2);
    DY_nTrk_lfakeRate_difeta_lowMET_2->SetLineWidth(2);

    DY_nTrk_bfakeRate_difeta_lowMET_3->SetLineWidth(2);
    DY_nTrk_cfakeRate_difeta_lowMET_3->SetLineWidth(2);
    DY_nTrk_lfakeRate_difeta_lowMET_3->SetLineWidth(2);

    DY_nTrk_bfakeRate_difeta_highMET_1->SetLineWidth(2);
    DY_nTrk_cfakeRate_difeta_highMET_1->SetLineWidth(2);
    DY_nTrk_lfakeRate_difeta_highMET_1->SetLineWidth(2);

    DY_nTrk_bfakeRate_difeta_highMET_2->SetLineWidth(2);
    DY_nTrk_cfakeRate_difeta_highMET_2->SetLineWidth(2);
    DY_nTrk_lfakeRate_difeta_highMET_2->SetLineWidth(2);

    DY_nTrk_bfakeRate_difeta_highMET_3->SetLineWidth(2);
    DY_nTrk_cfakeRate_difeta_highMET_3->SetLineWidth(2);
    DY_nTrk_lfakeRate_difeta_highMET_3->SetLineWidth(2);

    // For Topfile
    Top_ee_nTrk_bfakeRate_difeta_lowMET_1->SetLineWidth(2);
    Top_ee_nTrk_cfakeRate_difeta_lowMET_1->SetLineWidth(2);
    Top_ee_nTrk_lfakeRate_difeta_lowMET_1->SetLineWidth(2);

    Top_ee_nTrk_bfakeRate_difeta_lowMET_2->SetLineWidth(2);
    Top_ee_nTrk_cfakeRate_difeta_lowMET_2->SetLineWidth(2);
    Top_ee_nTrk_lfakeRate_difeta_lowMET_2->SetLineWidth(2);

    Top_ee_nTrk_bfakeRate_difeta_lowMET_3->SetLineWidth(2);
    Top_ee_nTrk_cfakeRate_difeta_lowMET_3->SetLineWidth(2);
    Top_ee_nTrk_lfakeRate_difeta_lowMET_3->SetLineWidth(2);

    Top_ee_nTrk_bfakeRate_difeta_highMET_1->SetLineWidth(2);
    Top_ee_nTrk_cfakeRate_difeta_highMET_1->SetLineWidth(2);
    Top_ee_nTrk_lfakeRate_difeta_highMET_1->SetLineWidth(2);

    Top_ee_nTrk_bfakeRate_difeta_highMET_2->SetLineWidth(2);
    Top_ee_nTrk_cfakeRate_difeta_highMET_2->SetLineWidth(2);
    Top_ee_nTrk_lfakeRate_difeta_highMET_2->SetLineWidth(2);

    Top_ee_nTrk_bfakeRate_difeta_highMET_3->SetLineWidth(2);
    Top_ee_nTrk_cfakeRate_difeta_highMET_3->SetLineWidth(2);
    Top_ee_nTrk_lfakeRate_difeta_highMET_3->SetLineWidth(2);

    // For Top emu file
    Top_eu_nTrk_bfakeRate_difeta_lowMET_1->SetLineWidth(2);
    Top_eu_nTrk_cfakeRate_difeta_lowMET_1->SetLineWidth(2);
    Top_eu_nTrk_lfakeRate_difeta_lowMET_1->SetLineWidth(2);

    Top_eu_nTrk_bfakeRate_difeta_lowMET_2->SetLineWidth(2);
    Top_eu_nTrk_cfakeRate_difeta_lowMET_2->SetLineWidth(2);
    Top_eu_nTrk_lfakeRate_difeta_lowMET_2->SetLineWidth(2);

    Top_eu_nTrk_bfakeRate_difeta_lowMET_3->SetLineWidth(2);
    Top_eu_nTrk_cfakeRate_difeta_lowMET_3->SetLineWidth(2);
    Top_eu_nTrk_lfakeRate_difeta_lowMET_3->SetLineWidth(2);

    Top_eu_nTrk_bfakeRate_difeta_highMET_1->SetLineWidth(2);
    Top_eu_nTrk_cfakeRate_difeta_highMET_1->SetLineWidth(2);
    Top_eu_nTrk_lfakeRate_difeta_highMET_1->SetLineWidth(2);

    Top_eu_nTrk_bfakeRate_difeta_highMET_2->SetLineWidth(2);
    Top_eu_nTrk_cfakeRate_difeta_highMET_2->SetLineWidth(2);
    Top_eu_nTrk_lfakeRate_difeta_highMET_2->SetLineWidth(2);

    Top_eu_nTrk_bfakeRate_difeta_highMET_3->SetLineWidth(2);
    Top_eu_nTrk_cfakeRate_difeta_highMET_3->SetLineWidth(2);
    Top_eu_nTrk_lfakeRate_difeta_highMET_3->SetLineWidth(2);

    DY_nTrk_bfakeRate_difeta_lowMET_1->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate_difeta_lowMET_1->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate_difeta_lowMET_1->SetLineColor(kOrange - 3);

    DY_nTrk_bfakeRate_difeta_lowMET_2->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate_difeta_lowMET_2->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate_difeta_lowMET_2->SetLineColor(kOrange - 3);

    DY_nTrk_bfakeRate_difeta_lowMET_3->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate_difeta_lowMET_3->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate_difeta_lowMET_3->SetLineColor(kOrange - 3);

    DY_nTrk_bfakeRate_difeta_highMET_1->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate_difeta_highMET_1->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate_difeta_highMET_1->SetLineColor(kOrange - 3);

    DY_nTrk_bfakeRate_difeta_highMET_2->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate_difeta_highMET_2->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate_difeta_highMET_2->SetLineColor(kOrange - 3);

    DY_nTrk_bfakeRate_difeta_highMET_3->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate_difeta_highMET_3->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate_difeta_highMET_3->SetLineColor(kOrange - 3);

    Top_ee_nTrk_bfakeRate_difeta_lowMET_1->SetLineColor(kGreen + 3);
    Top_ee_nTrk_cfakeRate_difeta_lowMET_1->SetLineColor(kGreen + 3);
    Top_ee_nTrk_lfakeRate_difeta_lowMET_1->SetLineColor(kGreen + 3);

    Top_ee_nTrk_bfakeRate_difeta_lowMET_2->SetLineColor(kGreen + 3);
    Top_ee_nTrk_cfakeRate_difeta_lowMET_2->SetLineColor(kGreen + 3);
    Top_ee_nTrk_lfakeRate_difeta_lowMET_2->SetLineColor(kGreen + 3);

    Top_ee_nTrk_bfakeRate_difeta_lowMET_3->SetLineColor(kGreen + 3);
    Top_ee_nTrk_cfakeRate_difeta_lowMET_3->SetLineColor(kGreen + 3);
    Top_ee_nTrk_lfakeRate_difeta_lowMET_3->SetLineColor(kGreen + 3);

    Top_ee_nTrk_bfakeRate_difeta_highMET_1->SetLineColor(kGreen + 3);
    Top_ee_nTrk_cfakeRate_difeta_highMET_1->SetLineColor(kGreen + 3);
    Top_ee_nTrk_lfakeRate_difeta_highMET_1->SetLineColor(kGreen + 3);

    Top_ee_nTrk_bfakeRate_difeta_highMET_2->SetLineColor(kGreen + 3);
    Top_ee_nTrk_cfakeRate_difeta_highMET_2->SetLineColor(kGreen + 3);
    Top_ee_nTrk_lfakeRate_difeta_highMET_2->SetLineColor(kGreen + 3);

    Top_ee_nTrk_bfakeRate_difeta_highMET_3->SetLineColor(kGreen + 3);
    Top_ee_nTrk_cfakeRate_difeta_highMET_3->SetLineColor(kGreen + 3);
    Top_ee_nTrk_lfakeRate_difeta_highMET_3->SetLineColor(kGreen + 3);

    int W = 1000;
    int H = 800;

    int H_ref = 600;
    int W_ref = 800;

    float T = 0.08 * H_ref;
    float B = 0.12 * H_ref;
    float L = 0.12 * W_ref;
    float R = 0.04 * W_ref;

    auto c1 = new TCanvas("c1", "c1", 50, 50, W, H);

    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    // c1->SetLeftMargin(L / W);
    // c1->SetRightMargin(R / W);
    // c1->SetTopMargin(T / H);
    // c1->SetBottomMargin(B / H);
    c1->SetTickx(0);
    c1->SetTicky(0);

    c1->Divide(3, 2, 0.01, 0.01);

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_eu_nTrk_bfakeRate_difeta_highMET_1->SetLineColor(kRed);

    Top_eu_nTrk_bfakeRate_difeta_highMET_1->GetXaxis()->SetTitleSize(0);
    Top_eu_nTrk_bfakeRate_difeta_highMET_1->GetXaxis()->SetLabelSize(0);

    Top_eu_nTrk_bfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_eu_nTrk_bfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_bfakeRate_difeta_highMET_1->Draw("h");
    Top_eu_nTrk_bfakeRate_difeta_lowMET_1->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_lowMET_1, "Low MET", "El");
    l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_highMET_1, "High MET", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_eu_nTrk_bfakeRate_difeta_highMET_2->SetLineColor(kRed);

    Top_eu_nTrk_bfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_eu_nTrk_bfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_bfakeRate_difeta_highMET_2->Draw("h  ");
    Top_eu_nTrk_bfakeRate_difeta_lowMET_2->Draw("h same ");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_eu_nTrk_bfakeRate_difeta_lowMET_2, "Low MET", "El");
    l1->AddEntry(Top_eu_nTrk_bfakeRate_difeta_highMET_2, "High MET", "El");
    l1->Draw();

    gPad->SetLogy();

    c1->cd(3);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_eu_nTrk_bfakeRate_difeta_highMET_3->SetLineColor(kRed);

    Top_eu_nTrk_bfakeRate_difeta_lowMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_eu_nTrk_bfakeRate_difeta_lowMET_3->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_bfakeRate_difeta_lowMET_3->Draw("h ");
    Top_eu_nTrk_bfakeRate_difeta_highMET_3->Draw("h same ");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_eu_nTrk_bfakeRate_difeta_lowMET_3, "Low MET", "El");
    l2->AddEntry(Top_eu_nTrk_bfakeRate_difeta_highMET_3, "High MET", "El");
    l2->Draw();

    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_bRatio_1 = (TH1F *)Top_eu_nTrk_bfakeRate_difeta_highMET_1->Clone("h_High_Low_bRatio_1");
    h_High_Low_bRatio_1->Divide(Top_eu_nTrk_bfakeRate_difeta_lowMET_1);
    h_High_Low_bRatio_1->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_bRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_bRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_bRatio_1->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_bRatio_1->GetYaxis()->SetRangeUser(0.5, 1.5);
    h_High_Low_bRatio_1->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_High_Low_bRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_bRatio_2 = (TH1F *)Top_eu_nTrk_bfakeRate_difeta_highMET_2->Clone("h_High_Low_bRatio_2");
    h_High_Low_bRatio_2->Divide(Top_eu_nTrk_bfakeRate_difeta_lowMET_2);
    h_High_Low_bRatio_2->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_bRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_bRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_bRatio_2->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_bRatio_2->GetYaxis()->SetRangeUser(0.5, 2.);
    h_High_Low_bRatio_2->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_bRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_bRatio_3 = (TH1F *)Top_eu_nTrk_bfakeRate_difeta_highMET_3->Clone("h_High_Low_bRatio_3");
    h_High_Low_bRatio_3->Divide(Top_eu_nTrk_bfakeRate_difeta_lowMET_3);
    h_High_Low_bRatio_3->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_bRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_bRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_bRatio_3->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_bRatio_3->GetYaxis()->SetRangeUser(0.5, 2.);
    h_High_Low_bRatio_3->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_bRatio_3->Draw("e");

    c1->SaveAs("Top_eu_H_L_bRatio.png");

    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_eu_nTrk_lfakeRate_difeta_highMET_1->SetLineColor(kRed);

    Top_eu_nTrk_lfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_eu_nTrk_lfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_lfakeRate_difeta_highMET_1->Draw("h  ");
    Top_eu_nTrk_lfakeRate_difeta_lowMET_1->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_lowMET_1, "Low MET", "El");
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_highMET_1, "High MET", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_eu_nTrk_lfakeRate_difeta_highMET_2->SetLineColor(kRed);

    Top_eu_nTrk_lfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_eu_nTrk_lfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_lfakeRate_difeta_highMET_2->Draw("h  ");
    Top_eu_nTrk_lfakeRate_difeta_lowMET_2->Draw("h same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_eu_nTrk_lfakeRate_difeta_lowMET_2, "Low MET", "El");
    l1->AddEntry(Top_eu_nTrk_lfakeRate_difeta_highMET_2, "High MET", "El");
    l1->Draw();
    gPad->SetLogy();

    c1->cd(3);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_eu_nTrk_lfakeRate_difeta_highMET_3->SetLineColor(kRed);

    Top_eu_nTrk_lfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_eu_nTrk_lfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_lfakeRate_difeta_highMET_3->Draw("h  ");
    Top_eu_nTrk_lfakeRate_difeta_lowMET_3->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_eu_nTrk_lfakeRate_difeta_lowMET_3, "Low MET", "El");
    l2->AddEntry(Top_eu_nTrk_lfakeRate_difeta_highMET_3, "High MET", "El");
    l2->Draw();
    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_1 = (TH1F *)Top_eu_nTrk_lfakeRate_difeta_highMET_1->Clone("h_High_Low_lRatio_1");
    h_High_Low_lRatio_1->Divide(Top_eu_nTrk_lfakeRate_difeta_lowMET_1);
    h_High_Low_lRatio_1->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_1->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_1->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_High_Low_lRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_2 = (TH1F *)Top_eu_nTrk_lfakeRate_difeta_highMET_2->Clone("h_High_Low_lRatio_2");
    h_High_Low_lRatio_2->Divide(Top_eu_nTrk_lfakeRate_difeta_lowMET_2);
    h_High_Low_lRatio_2->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_2->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_2->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_3 = (TH1F *)Top_eu_nTrk_lfakeRate_difeta_highMET_3->Clone("h_High_Low_lRatio_3");
    h_High_Low_lRatio_3->Divide(Top_eu_nTrk_lfakeRate_difeta_lowMET_3);
    h_High_Low_lRatio_3->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_3->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_3->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_3->Draw("e");

    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_bfakeRate_difeta_highMET_1->SetLineColor(kRed);

    Top_ee_nTrk_bfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_bfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_bfakeRate_difeta_highMET_1->Draw("h ");
    Top_ee_nTrk_bfakeRate_difeta_lowMET_1->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_bfakeRate_difeta_lowMET_1, "Low MET", "El");
    l0->AddEntry(Top_ee_nTrk_bfakeRate_difeta_highMET_1, "High MET", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_bfakeRate_difeta_highMET_2->SetLineColor(kRed);

    Top_ee_nTrk_bfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_bfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_bfakeRate_difeta_highMET_2->Draw("h  ");
    Top_ee_nTrk_bfakeRate_difeta_lowMET_2->Draw("h same ");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_bfakeRate_difeta_lowMET_2, "Low MET", "El");
    l1->AddEntry(Top_ee_nTrk_bfakeRate_difeta_highMET_2, "High MET", "El");
    l1->Draw();
    gPad->SetLogy();

    c1->cd(3);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_bfakeRate_difeta_highMET_3->SetLineColor(kRed);

    Top_ee_nTrk_bfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_bfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_bfakeRate_difeta_highMET_3->Draw("h ");
    Top_ee_nTrk_bfakeRate_difeta_lowMET_3->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_bfakeRate_difeta_lowMET_3, "Low MET", "El");
    l2->AddEntry(Top_ee_nTrk_bfakeRate_difeta_highMET_3, "High MET", "El");
    l2->Draw();
    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_bRatio_1 = (TH1F *)Top_ee_nTrk_bfakeRate_difeta_highMET_1->Clone("h_High_Low_bRatio_1");
    h_High_Low_bRatio_1->Divide(Top_ee_nTrk_bfakeRate_difeta_lowMET_1);
    h_High_Low_bRatio_1->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_bRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_bRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_bRatio_1->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_bRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_bRatio_1->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_bRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_bRatio_2 = (TH1F *)Top_ee_nTrk_bfakeRate_difeta_highMET_2->Clone("h_High_Low_bRatio_2");
    h_High_Low_bRatio_2->Divide(Top_ee_nTrk_bfakeRate_difeta_lowMET_2);
    h_High_Low_bRatio_2->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_bRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_bRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_bRatio_2->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_bRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_bRatio_2->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_bRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_bRatio_3 = (TH1F *)Top_ee_nTrk_bfakeRate_difeta_highMET_3->Clone("h_High_Low_bRatio_3");
    h_High_Low_bRatio_3->Divide(Top_ee_nTrk_bfakeRate_difeta_lowMET_3);
    h_High_Low_bRatio_3->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_bRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_bRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_bRatio_3->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_bRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_bRatio_3->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_bRatio_3->Draw("e");
    */
    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_lfakeRate_difeta_highMET_1->SetLineColor(kRed);

    Top_ee_nTrk_lfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_lfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_lfakeRate_difeta_highMET_1->Draw("h  ");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_1->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_1, "Low MET", "El");
    l0->AddEntry(Top_ee_nTrk_lfakeRate_difeta_highMET_1, "High MET", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_lfakeRate_difeta_highMET_2->SetLineColor(kRed);

    Top_ee_nTrk_lfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_lfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_lfakeRate_difeta_highMET_2->Draw("h  ");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_2->Draw("h same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_2, "Low MET", "El");
    l1->AddEntry(Top_ee_nTrk_lfakeRate_difeta_highMET_2, "High MET", "El");
    l1->Draw();
    gPad->SetLogy();

    c1->cd(3);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_lfakeRate_difeta_highMET_3->SetLineColor(kRed);

    Top_ee_nTrk_lfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_lfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_lfakeRate_difeta_highMET_3->Draw("h  ");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_3->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_3, "Low MET", "El");
    l2->AddEntry(Top_ee_nTrk_lfakeRate_difeta_highMET_3, "High MET", "El");
    l2->Draw();
    gPad->SetLogy();

     c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_1 = (TH1F *)Top_ee_nTrk_lfakeRate_difeta_highMET_1->Clone("h_High_Low_lRatio_1");
    h_High_Low_lRatio_1->Divide(Top_ee_nTrk_lfakeRate_difeta_lowMET_1);
    h_High_Low_lRatio_1->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_1->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_1->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_2 = (TH1F *)Top_ee_nTrk_lfakeRate_difeta_highMET_2->Clone("h_High_Low_lRatio_2");
    h_High_Low_lRatio_2->Divide(Top_ee_nTrk_lfakeRate_difeta_lowMET_2);
    h_High_Low_lRatio_2->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_2->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_2->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_3 = (TH1F *)Top_ee_nTrk_lfakeRate_difeta_highMET_3->Clone("h_High_Low_lRatio_3");
    h_High_Low_lRatio_3->Divide(Top_ee_nTrk_lfakeRate_difeta_lowMET_3);
    h_High_Low_lRatio_3->GetYaxis()->SetTitle("High / Low");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_3->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_3->SetLineColor(kBlack);
    // h_High_Lw_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_3->Draw("e");
    */
    /*
     c1->cd(1);
     gPad->SetTopMargin(0.01);
     gPad->SetBottomMargin(0);
     gPad->SetRightMargin(0.04);

     Top_ee_nTrk_bfakeRate_difeta_lowMET_1->GetXaxis()->SetTitle("Track multiplicity");
     Top_ee_nTrk_bfakeRate_difeta_lowMET_1->GetYaxis()->SetTitle("fake rate");

     Top_ee_nTrk_bfakeRate_difeta_lowMET_1->Draw("h ");
     Top_eu_nTrk_bfakeRate_difeta_lowMET_1->Draw("h same ");

     TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l0->SetHeader("b flavor, |#eta| < 1");
     l0->SetBorderSize(0);
     l0->SetFillStyle(0);
     l0->SetTextSize(0.04);
     l0->AddEntry(Top_ee_nTrk_bfakeRate_difeta_lowMET_1, "Top to e e", "El");
     l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_lowMET_1, "Top to e mu", "El");
     l0->Draw();
     gPad->SetLogy();

     c1->cd(2);
     gPad->SetTopMargin(0.01);
     gPad->SetBottomMargin(0);
     gPad->SetRightMargin(0.04);

     Top_ee_nTrk_bfakeRate_difeta_lowMET_2->GetXaxis()->SetTitle("Track multiplicity");
     Top_ee_nTrk_bfakeRate_difeta_lowMET_2->GetYaxis()->SetTitle("fake rate");

     Top_ee_nTrk_bfakeRate_difeta_lowMET_2->Draw("h ");
     Top_eu_nTrk_bfakeRate_difeta_lowMET_2->Draw("h same ");

     TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l1->SetHeader("b flavor, 1 < |#eta| < 2");
     l1->SetBorderSize(0);
     l1->SetFillStyle(0);
     l1->SetTextSize(0.04);
     l1->AddEntry(Top_ee_nTrk_bfakeRate_difeta_lowMET_2, "Top to e e", "El");
     l1->AddEntry(Top_eu_nTrk_bfakeRate_difeta_lowMET_2, "Top to e mu", "El");
     l1->Draw();
     gPad->SetLogy();

     c1->cd(3);
     gPad->SetTopMargin(0.01);
     gPad->SetBottomMargin(0);
     gPad->SetRightMargin(0.04);

     Top_ee_nTrk_bfakeRate_difeta_lowMET_3->GetXaxis()->SetTitle("Track multiplicity");
     Top_ee_nTrk_bfakeRate_difeta_lowMET_3->GetYaxis()->SetTitle("fake rate");

     Top_ee_nTrk_bfakeRate_difeta_lowMET_3->Draw("h  ");
     Top_eu_nTrk_bfakeRate_difeta_lowMET_3->Draw("h same");

     TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
     l2->SetBorderSize(0);
     l2->SetFillStyle(0);
     l2->SetTextSize(0.04);
     l2->AddEntry(Top_ee_nTrk_bfakeRate_difeta_lowMET_3, "Top to e e", "El");
     l2->AddEntry(Top_eu_nTrk_bfakeRate_difeta_lowMET_3, "Top to e mu", "El");
     l2->Draw();
     gPad->SetLogy();

     c1->cd(4);
     gPad->SetRightMargin(0.04);
     gPad->SetTopMargin(0);
     gPad->SetBottomMargin(0.2);
     gPad->SetTickx();

     TH1F *h_High_Low_bRatio_1 = (TH1F *)Top_ee_nTrk_bfakeRate_difeta_lowMET_1->Clone("h_High_Low_bRatio_1");
     h_High_Low_bRatio_1->Divide(Top_eu_nTrk_bfakeRate_difeta_lowMET_1);
     h_High_Low_bRatio_1->GetYaxis()->SetTitle("ee / emu");
     // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

     h_High_Low_bRatio_1->GetXaxis()->SetTitleSize(0.04);
     h_High_Low_bRatio_1->GetXaxis()->SetLabelSize(0.04);

     h_High_Low_bRatio_1->GetXaxis()->SetTitle("Track multiplicity");
     h_High_Low_bRatio_1->GetYaxis()->SetRangeUser(0., 2.);
     h_High_Low_bRatio_1->SetLineColor(kBlack);
     // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
     h_High_Low_bRatio_1->Draw("e");

     c1->cd(5);
     gPad->SetRightMargin(0.04);
     gPad->SetTopMargin(0);
     gPad->SetBottomMargin(0.2);
     gPad->SetTickx();

     TH1F *h_High_Low_bRatio_2 = (TH1F *)Top_ee_nTrk_bfakeRate_difeta_lowMET_2->Clone("h_High_Low_bRatio_2");
     h_High_Low_bRatio_2->Divide(Top_eu_nTrk_bfakeRate_difeta_lowMET_2);
     h_High_Low_bRatio_2->GetYaxis()->SetTitle("ee / emu");
     // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

     h_High_Low_bRatio_2->GetXaxis()->SetTitleSize(0.04);
     h_High_Low_bRatio_2->GetXaxis()->SetLabelSize(0.04);

     h_High_Low_bRatio_2->GetXaxis()->SetTitle("Track multiplicity");
     h_High_Low_bRatio_2->GetYaxis()->SetRangeUser(0., 2.);
     h_High_Low_bRatio_2->SetLineColor(kBlack);
     // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
     h_High_Low_bRatio_2->Draw("e");

     c1->cd(6);
     gPad->SetRightMargin(0.04);
     gPad->SetTopMargin(0);
     gPad->SetBottomMargin(0.2);
     gPad->SetTickx();

     TH1F *h_High_Low_bRatio_3 = (TH1F *)Top_ee_nTrk_bfakeRate_difeta_lowMET_3->Clone("h_High_Low_bRatio_3");
     h_High_Low_bRatio_3->Divide(Top_eu_nTrk_bfakeRate_difeta_lowMET_3);
     h_High_Low_bRatio_3->GetYaxis()->SetTitle("ee / emu");
     // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

     h_High_Low_bRatio_3->GetXaxis()->SetTitleSize(0.04);
     h_High_Low_bRatio_3->GetXaxis()->SetLabelSize(0.04);

     h_High_Low_bRatio_3->GetXaxis()->SetTitle("Track multiplicity");
     h_High_Low_bRatio_3->GetYaxis()->SetRangeUser(0., 2.);
     h_High_Low_bRatio_3->SetLineColor(kBlack);
     // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
     h_High_Low_bRatio_3->Draw("e");
     */

    /*

    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_bfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_bfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_bfakeRate_difeta_highMET_1->Draw("h ");
    Top_eu_nTrk_bfakeRate_difeta_highMET_1->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_bfakeRate_difeta_highMET_1, "Top to e e", "El");
    l0->AddEntry(Top_eu_nTrk_bfakeRate_difeta_highMET_1, "Top to e mu", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_bfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_bfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_bfakeRate_difeta_highMET_2->Draw("h ");
    Top_eu_nTrk_bfakeRate_difeta_highMET_2->Draw("h same ");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_bfakeRate_difeta_highMET_2, "Top to e e", "El");
    l1->AddEntry(Top_eu_nTrk_bfakeRate_difeta_highMET_2, "Top to e mu", "El");
    l1->Draw();
    gPad->SetLogy();

    c1->cd(3);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_bfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_bfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_bfakeRate_difeta_highMET_3->Draw("h  ");
    Top_eu_nTrk_bfakeRate_difeta_highMET_3->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_bfakeRate_difeta_highMET_3, "Top to e e", "El");
    l2->AddEntry(Top_eu_nTrk_bfakeRate_difeta_highMET_3, "Top to e mu", "El");
    l2->Draw();
    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_bRatio_1 = (TH1F *)Top_ee_nTrk_bfakeRate_difeta_highMET_1->Clone("h_High_Low_bRatio_1");
    h_High_Low_bRatio_1->Divide(Top_eu_nTrk_bfakeRate_difeta_highMET_1);
    h_High_Low_bRatio_1->GetYaxis()->SetTitle("ee / emu");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_bRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_bRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_bRatio_1->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_bRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_bRatio_1->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_bRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_bRatio_2 = (TH1F *)Top_ee_nTrk_bfakeRate_difeta_highMET_2->Clone("h_High_Low_bRatio_2");
    h_High_Low_bRatio_2->Divide(Top_eu_nTrk_bfakeRate_difeta_highMET_2);
    h_High_Low_bRatio_2->GetYaxis()->SetTitle("ee / emu");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_bRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_bRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_bRatio_2->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_bRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_bRatio_2->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_bRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_bRatio_3 = (TH1F *)Top_ee_nTrk_bfakeRate_difeta_highMET_3->Clone("h_High_Low_bRatio_3");
    h_High_Low_bRatio_3->Divide(Top_eu_nTrk_bfakeRate_difeta_highMET_3);
    h_High_Low_bRatio_3->GetYaxis()->SetTitle("ee / emu");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_bRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_bRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_bRatio_3->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_bRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_bRatio_3->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_bRatio_3->Draw("e");
    */

    /*
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_eu_nTrk_lfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_eu_nTrk_lfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_lfakeRate_difeta_highMET_1->Draw("h  ");
    Top_ee_nTrk_lfakeRate_difeta_highMET_1->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_lfakeRate_difeta_highMET_1, "Top to e e", "El");
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_highMET_1, "Top to e mu", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_lfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_lfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_lfakeRate_difeta_highMET_2->Draw("h ");
    Top_eu_nTrk_lfakeRate_difeta_highMET_2->Draw("h same ");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_lfakeRate_difeta_highMET_2, "Top to e e", "El");
    l1->AddEntry(Top_eu_nTrk_lfakeRate_difeta_highMET_2, "Top to e mu", "El");
    l1->Draw();
    gPad->SetLogy();

    c1->cd(3);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_eu_nTrk_lfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_eu_nTrk_lfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");

    Top_eu_nTrk_lfakeRate_difeta_highMET_3->Draw("h ");
    Top_ee_nTrk_lfakeRate_difeta_highMET_3->Draw("h same ");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_lfakeRate_difeta_highMET_3, "Top to e e", "El");
    l2->AddEntry(Top_eu_nTrk_lfakeRate_difeta_highMET_3, "Top to e mu", "El");
    l2->Draw();
    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_1 = (TH1F *)Top_ee_nTrk_lfakeRate_difeta_highMET_1->Clone("h_High_Low_lRatio_1");
    h_High_Low_lRatio_1->Divide(Top_eu_nTrk_lfakeRate_difeta_highMET_1);
    h_High_Low_lRatio_1->GetYaxis()->SetTitle("ee / emu");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_1->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_1->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_2 = (TH1F *)Top_ee_nTrk_lfakeRate_difeta_highMET_2->Clone("h_High_Low_lRatio_2");
    h_High_Low_lRatio_2->Divide(Top_eu_nTrk_lfakeRate_difeta_highMET_2);
    h_High_Low_lRatio_2->GetYaxis()->SetTitle("ee / emu");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_2->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_2->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_3 = (TH1F *)Top_ee_nTrk_lfakeRate_difeta_highMET_3->Clone("h_High_Low_lRatio_3");
    h_High_Low_lRatio_3->Divide(Top_eu_nTrk_lfakeRate_difeta_highMET_3);
    h_High_Low_lRatio_3->GetYaxis()->SetTitle("ee / emu");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_3->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_3->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_3->Draw("e");
    */
    c1->cd(1);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_lfakeRate_difeta_lowMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_1->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_lfakeRate_difeta_lowMET_1->Draw("h ");
    Top_eu_nTrk_lfakeRate_difeta_lowMET_1->Draw("h same ");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_1, "Top to e e", "El");
    l0->AddEntry(Top_eu_nTrk_lfakeRate_difeta_lowMET_1, "Top to e mu", "El");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_lfakeRate_difeta_lowMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_2->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_lfakeRate_difeta_lowMET_2->Draw("h ");
    Top_eu_nTrk_lfakeRate_difeta_lowMET_2->Draw("h same ");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_2, "Top to e e", "El");
    l1->AddEntry(Top_eu_nTrk_lfakeRate_difeta_lowMET_2, "Top to e mu", "El");
    l1->Draw();
    gPad->SetLogy();

    c1->cd(3);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0);
    gPad->SetRightMargin(0.04);

    Top_ee_nTrk_lfakeRate_difeta_lowMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_3->GetYaxis()->SetTitle("fake rate");

    Top_ee_nTrk_lfakeRate_difeta_lowMET_3->Draw("h  ");
    Top_eu_nTrk_lfakeRate_difeta_lowMET_3->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_3, "Top to e e", "El");
    l2->AddEntry(Top_eu_nTrk_lfakeRate_difeta_lowMET_3, "Top to e mu", "El");
    l2->Draw();
    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_1 = (TH1F *)Top_ee_nTrk_lfakeRate_difeta_lowMET_1->Clone("h_High_Low_lRatio_1");
    h_High_Low_lRatio_1->Divide(Top_eu_nTrk_lfakeRate_difeta_lowMET_1);
    h_High_Low_lRatio_1->GetYaxis()->SetTitle("ee / emu");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_1->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_1->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_2 = (TH1F *)Top_ee_nTrk_lfakeRate_difeta_lowMET_2->Clone("h_High_Low_lRatio_2");
    h_High_Low_lRatio_2->Divide(Top_eu_nTrk_lfakeRate_difeta_lowMET_2);
    h_High_Low_lRatio_2->GetYaxis()->SetTitle("ee / emu");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_2->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_2->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_High_Low_lRatio_3 = (TH1F *)Top_ee_nTrk_lfakeRate_difeta_lowMET_3->Clone("h_High_Low_lRatio_3");
    h_High_Low_lRatio_3->Divide(Top_eu_nTrk_lfakeRate_difeta_lowMET_3);
    h_High_Low_lRatio_3->GetYaxis()->SetTitle("ee / emu");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_High_Low_lRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_High_Low_lRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_High_Low_lRatio_3->GetXaxis()->SetTitle("Track multiplicity");
    h_High_Low_lRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_High_Low_lRatio_3->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);
    h_High_Low_lRatio_3->Draw("e");

    /*
    DY_nTrk_lfakeRate_difeta_lowMET_1->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_lfakeRate_difeta_lowMET_1->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_lfakeRate_difeta_lowMET_1->Draw("h  ");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_1->Draw("h same");


    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_1, "Top to e e", "El");
    l0->AddEntry(DY_nTrk_lfakeRate_difeta_lowMET_1, "Drell-Yan", "El");
    l0->Draw();

    c1->cd(2);

    DY_nTrk_lfakeRate_difeta_lowMET_2->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_lfakeRate_difeta_lowMET_2->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_lfakeRate_difeta_lowMET_2->Draw("h  ");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_2->Draw("h same");


    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_2, "Top to e e", "El");
    l1->AddEntry(DY_nTrk_lfakeRate_difeta_lowMET_2, "Drell-Yan", "El");
    l1->Draw();

    c1->cd(3);

    DY_nTrk_lfakeRate_difeta_lowMET_3->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_lfakeRate_difeta_lowMET_3->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_lfakeRate_difeta_lowMET_3->Draw("h ");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_3->Draw("h same ");


    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_3, "Top to e e", "El");
    l2->AddEntry(DY_nTrk_lfakeRate_difeta_lowMET_3, "Drell-Yan", "El");
    l2->Draw();
    */
    /*
    DY_nTrk_bfakeRate_difeta_lowMET_1->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_bfakeRate_difeta_lowMET_1->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_bfakeRate_difeta_lowMET_1->Draw("h  ");
    Top_ee_nTrk_bfakeRate_difeta_lowMET_1->Draw("h same");


    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_bfakeRate_difeta_lowMET_1, "Top to e e", "El");
    l0->AddEntry(DY_nTrk_bfakeRate_difeta_lowMET_1, "Drell-Yan", "El");
    l0->Draw();

    c1->cd(2);

    DY_nTrk_bfakeRate_difeta_lowMET_2->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_bfakeRate_difeta_lowMET_2->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_bfakeRate_difeta_lowMET_2->Draw("h  ");
    Top_ee_nTrk_bfakeRate_difeta_lowMET_2->Draw("h same");


    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_bfakeRate_difeta_lowMET_2, "Top to e e", "El");
    l1->AddEntry(DY_nTrk_bfakeRate_difeta_lowMET_2, "Drell-Yan", "El");
    l1->Draw();

    c1->cd(3);

    DY_nTrk_bfakeRate_difeta_lowMET_3->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_bfakeRate_difeta_lowMET_3->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_bfakeRate_difeta_lowMET_3->Draw("h ");
    Top_ee_nTrk_bfakeRate_difeta_lowMET_3->Draw("h same ");


    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_bfakeRate_difeta_lowMET_3, "Top to e e", "El");
    l2->AddEntry(DY_nTrk_bfakeRate_difeta_lowMET_3, "Drell-Yan", "El");
    l2->Draw();
    */

    /*
    DY_nTrk_bfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_bfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_bfakeRate_difeta_highMET_1->Draw("h  ");
    Top_ee_nTrk_bfakeRate_difeta_highMET_1->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_bfakeRate_difeta_highMET_1, "Top to e e", "El");
    l0->AddEntry(DY_nTrk_bfakeRate_difeta_highMET_1, "Drell-Yan", "El");
    l0->Draw();

    c1->cd(2);

    DY_nTrk_bfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_bfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");


    DY_nTrk_bfakeRate_difeta_highMET_2->Draw("h  ");
    Top_ee_nTrk_bfakeRate_difeta_highMET_2->Draw("h same");


    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_bfakeRate_difeta_highMET_2, "Top to e e", "El");
    l1->AddEntry(DY_nTrk_bfakeRate_difeta_highMET_2, "Drell-Yan", "El");
    l1->Draw();

    c1->cd(3);

    DY_nTrk_bfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_bfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_bfakeRate_difeta_highMET_3->Draw("h ");
    Top_ee_nTrk_bfakeRate_difeta_highMET_3->Draw("h same ");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_bfakeRate_difeta_highMET_3, "Top to e e", "El");
    l2->AddEntry(DY_nTrk_bfakeRate_difeta_highMET_3, "Drell-Yan", "El");
    l2->Draw();
    */

    /*
    DY_nTrk_lfakeRate_difeta_lowMET_1->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_lfakeRate_difeta_lowMET_1->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_lfakeRate_difeta_lowMET_1->Draw("h  ");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_1->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_1, "Top to e e", "El");
    l0->AddEntry(DY_nTrk_lfakeRate_difeta_lowMET_1, "Drell-Yan", "El");
    l0->Draw();

    c1->cd(2);

    DY_nTrk_lfakeRate_difeta_lowMET_2->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_lfakeRate_difeta_lowMET_2->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_lfakeRate_difeta_lowMET_2->Draw("h ");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_2->Draw("h same");


    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_2, "Top to e e", "El");
    l1->AddEntry(DY_nTrk_lfakeRate_difeta_lowMET_2, "Drell-Yan", "El");
    l1->Draw();

    c1->cd(3);

    DY_nTrk_lfakeRate_difeta_lowMET_3->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_lfakeRate_difeta_lowMET_3->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_lfakeRate_difeta_lowMET_3->Draw("h ");
    Top_ee_nTrk_lfakeRate_difeta_lowMET_3->Draw("h same ");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_lfakeRate_difeta_lowMET_3, "Top to e e", "El");
    l2->AddEntry(DY_nTrk_lfakeRate_difeta_lowMET_3, "Drell-Yan", "El");
    l2->Draw();
    */

    /*
    DY_nTrk_lfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_lfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_lfakeRate_difeta_highMET_1->Draw("h  ");
    Top_ee_nTrk_lfakeRate_difeta_highMET_1->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(Top_ee_nTrk_lfakeRate_difeta_highMET_1, "Top to e e", "El");
    l0->AddEntry(DY_nTrk_lfakeRate_difeta_highMET_1, "Drell-Yan", "El");
    l0->Draw();

    c1->cd(2);

    DY_nTrk_lfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_lfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_lfakeRate_difeta_highMET_2->Draw("h ");
    Top_ee_nTrk_lfakeRate_difeta_highMET_2->Draw("h same");


    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(Top_ee_nTrk_lfakeRate_difeta_highMET_2, "Top to e e", "El");
    l1->AddEntry(DY_nTrk_lfakeRate_difeta_highMET_2, "Drell-Yan", "El");
    l1->Draw();

    c1->cd(3);

    DY_nTrk_lfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");
    DY_nTrk_lfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");

    DY_nTrk_lfakeRate_difeta_highMET_3->Draw("h ");
    Top_ee_nTrk_lfakeRate_difeta_highMET_3->Draw("h same ");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(Top_ee_nTrk_lfakeRate_difeta_highMET_3, "Top to e e", "El");
    l2->AddEntry(DY_nTrk_lfakeRate_difeta_highMET_3, "Drell-Yan", "El");
    l2->Draw();
    */

    gStyle->SetOptStat(0);
}