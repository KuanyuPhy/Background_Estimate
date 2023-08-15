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
#include <TAxis.h>
#include <TLine.h>
#include <TError.h>
#include "TLegend.h"
#include <cstring>
#include "./../../lib/tdrstyle.C"
#include "./../../lib/CMS_lumi.h"
using namespace std;
void draw_fakerate()
{
    TFile *Topfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top/top_ee_fakerate.root");
    TFile *Topemufile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_fakerate.root");

    TH1D *Top_nTrk_fakeRate_lowDilepPt = ((TH1D *)Topfile->Get("Top_nTrk_fakeRate_lowDilepPt"));
    TH1D *Top_JetPt_fakeRate_lowDilepPt = ((TH1D *)Topfile->Get("Top_JetPt_fakeRate_lowDilepPt"));
    TH1D *Top_JetEta_fakeRate_lowDilepPt = ((TH1D *)Topfile->Get("Top_JetEta_fakeRate_lowDilepPt"));

    TH1D *Top_nTrk_fakeRate_highDilepPt = ((TH1D *)Topfile->Get("Top_nTrk_fakeRate_highDilepPt"));
    TH1D *Top_JetPt_fakeRate_highDilepPt = ((TH1D *)Topfile->Get("Top_JetPt_fakeRate_highDilepPt"));
    TH1D *Top_JetEta_fakeRate_highDilepPt = ((TH1D *)Topfile->Get("Top_JetEta_fakeRate_highDilepPt"));

    TH1D *Topemu_nTrk_fakeRate_highDilepPt = Topemufile->Get<TH1D>("Top_nTrk_fakeRate_highDilepPt");
    TH1D *Topemu_JetPt_fakeRate_highDilepPt = Topemufile->Get<TH1D>("Top_JetPt_fakeRate_highDilepPt");
    TH1D *Topemu_JetEta_fakeRate_highDilepPt = Topemufile->Get<TH1D>("Top_JetEta_fakeRate_highDilepPt");



    Top_nTrk_fakeRate_lowDilepPt->SetLineWidth(2);
    Top_JetPt_fakeRate_lowDilepPt->SetLineWidth(2);
    Top_JetEta_fakeRate_lowDilepPt->SetLineWidth(2);

    Top_nTrk_fakeRate_highDilepPt->SetLineWidth(2);
    Top_JetPt_fakeRate_highDilepPt->SetLineWidth(2);
    Top_JetEta_fakeRate_highDilepPt->SetLineWidth(2);

    Topemu_nTrk_fakeRate_highDilepPt->SetLineWidth(2);
    Topemu_JetPt_fakeRate_highDilepPt->SetLineWidth(2);
    Topemu_JetEta_fakeRate_highDilepPt->SetLineWidth(2);

    Topemu_nTrk_fakeRate_highDilepPt->SetLineColor(kBlue);


    int W = 600;
    int H = 600;

    int H_ref = 600;
    int W_ref = 600;

    float T = 0.08 * H_ref;
    float B = 0.12 * H_ref;
    float L = 0.12 * W_ref;
    float R = 0.04 * W_ref;

    // visualize the fitting result
    setTDRStyle();
    auto c1 = new TCanvas("c", "c", 800, 800);
    c1->cd();
    c1->SetRightMargin(0.08);
    c1->SetBottomMargin(0.12);
    c1->SetTopMargin(0.07);
    c1->SetLeftMargin(0.12);

    auto pad1 = new TPad("pad1", " ", 0, 0.3, 1, 1.0);
    pad1->SetTopMargin(0.08);
    pad1->SetRightMargin(0.05);
    pad1->SetLeftMargin(0.13);
    pad1->SetBottomMargin(0.03);
    pad1->Draw();
    pad1->cd();


    //c1->Divide(3, 1);
    //c1->cd(1);

    Top_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitle("");
    Top_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitle("nJets");
    Top_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.06);
    Top_nTrk_fakeRate_highDilepPt->GetYaxis()->SetLabelSize(0.06);
    Top_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleOffset(1.1);

    Top_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.06);
    Top_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelSize(0.05);
    Top_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelOffset(0.1);
    Top_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleOffset(1);

    Top_nTrk_fakeRate_highDilepPt->SetLineColor(kRed);
    Top_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_fakeRate_highDilepPt->SetMarkerColor(kRed);
    Top_nTrk_fakeRate_highDilepPt->SetMarkerStyle(21);

    Top_nTrk_fakeRate_highDilepPt->Draw();
    Topemu_nTrk_fakeRate_highDilepPt->Draw("same");

    TLegend *l0 = new TLegend(0.55, 0.7, 0.80, 0.90);
    //l0->SetHeader("Top to e#mu process");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    // l0->AddEntry(Top_half_nTrk_fakeRate_highDilepPt, "All jets", "Elp");
    // l0->AddEntry(Top_half_JetEta_fakeRate_highDilepPt, "All jets", "Elp");
    l0->AddEntry(Top_nTrk_fakeRate_highDilepPt, "Top to ee process", "Elp");
    l0->AddEntry(Topemu_nTrk_fakeRate_highDilepPt, "Top to e#mu process", "Elp");
    l0->Draw("same");


    CMS_lumi(pad1, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");

    gPad->SetLogy();

    c1->cd(); // Go back to the main canvas before defining pad2
    auto pad2 = new TPad("pad2", "", 0, 0, 1, 0.3);
    pad2->SetGridy();
    pad2->SetRightMargin(0.05);
    pad2->SetLeftMargin(0.13);
    pad2->SetTopMargin(0.06);
    pad2->SetBottomMargin(0.4);
    pad2->Draw();
    pad2->cd();


    TH1D *h_all_FR_ratio = (TH1D *)Topemu_nTrk_fakeRate_highDilepPt->Clone("h_all_FR_ratio");
    h_all_FR_ratio->Divide(Top_nTrk_fakeRate_highDilepPt);

    h_all_FR_ratio->SetTitle("");
    h_all_FR_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_all_FR_ratio->GetYaxis()->SetTitle("Top(e#mu)/Top(ee)");
    h_all_FR_ratio->SetMarkerStyle(20);

    h_all_FR_ratio->SetMarkerColor(TColor::GetColor("#202020"));
    h_all_FR_ratio->SetMarkerSize(1.2);
    h_all_FR_ratio->SetMarkerStyle(20);
    h_all_FR_ratio->SetLineColor(TColor::GetColor("#202020"));
    h_all_FR_ratio->SetLineWidth(2);

    h_all_FR_ratio->GetXaxis()->SetTitleSize(0.16);
    h_all_FR_ratio->GetXaxis()->SetTitleOffset(1.2);
    h_all_FR_ratio->GetXaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_all_FR_ratio->GetXaxis()->SetLabelOffset(0.05);
    h_all_FR_ratio->GetYaxis()->SetTitleSize(0.13);
    h_all_FR_ratio->GetYaxis()->SetTitleOffset(0.2 * (7 / 3.));
    h_all_FR_ratio->GetYaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_all_FR_ratio->GetYaxis()->SetNdivisions(505);
    h_all_FR_ratio->GetYaxis()->SetRangeUser(0.5, 1.5);
    h_all_FR_ratio->Draw("ep");

    gPad->SetLogy();

    //Top_JetPt_fakeRate_lowDilepPt->SetLineColor(kGreen + 3);
    //Top_JetPt_fakeRate_lowDilepPt->GetYaxis()->SetTitle("fake rate");
    //Top_JetPt_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet PT");
    //Top_JetPt_fakeRate_lowDilepPt->Draw();

    //Top_JetEta_fakeRate_lowDilepPt->GetYaxis()->SetTitle("fake rate");
    //Top_JetEta_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet #eta");
    //Top_JetEta_fakeRate_lowDilepPt->Draw();


    //c1->cd(2);
    //Top_JetPt_fakeRate_lowDilepPt->Draw();
    //c1->cd(3);
    //Top_JetEta_fakeRate_lowDilepPt->Draw();

    gStyle->SetOptStat(0);


}