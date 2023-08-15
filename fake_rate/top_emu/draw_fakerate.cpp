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
#include "./../../lib/Cross_section.h"
#include "./../../lib/tdrstyle.C"
#include "./../../lib/CMS_lumi.h"
using namespace std;
void draw_fakerate()
{

    TFile *Top_half_file = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_fakerate.root");
    TFile *Top_all_file = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_all_fakerate.root");

    TH1D *Top_half_nTrk_fakeRate_lowDilepPt = Top_half_file->Get<TH1D>("Top_nTrk_fakeRate_lowDilepPt");
    TH1D *Top_half_JetPt_fakeRate_lowDilepPt = Top_half_file->Get<TH1D>("Top_JetPt_fakeRate_lowDilepPt");
    TH1D *Top_half_JetEta_fakeRate_lowDilepPt = Top_half_file->Get<TH1D>("Top_JetEta_fakeRate_lowDilepPt");

    TH1D *Top_half_nTrk_fakeRate_highDilepPt = Top_half_file->Get<TH1D>("Top_nTrk_fakeRate_highDilepPt");
    TH1D *Top_half_JetPt_fakeRate_highDilepPt = Top_half_file->Get<TH1D>("Top_JetPt_fakeRate_highDilepPt");
    TH1D *Top_half_JetEta_fakeRate_highDilepPt = Top_half_file->Get<TH1D>("Top_JetEta_fakeRate_highDilepPt");

    TH1D *Top_all_nTrk_fakeRate_lowDilepPt = Top_all_file->Get<TH1D>("Top_nTrk_fakeRate_lowDilepPt");
    TH1D *Top_all_JetPt_fakeRate_lowDilepPt = Top_all_file->Get<TH1D>("Top_JetPt_fakeRate_lowDilepPt");
    TH1D *Top_all_JetEta_fakeRate_lowDilepPt = Top_all_file->Get<TH1D>("Top_JetEta_fakeRate_lowDilepPt");

    TH1D *Top_all_nTrk_fakeRate_highDilepPt = Top_all_file->Get<TH1D>("Top_nTrk_fakeRate_highDilepPt");
    TH1D *Top_all_JetPt_fakeRate_highDilepPt = Top_all_file->Get<TH1D>("Top_JetPt_fakeRate_highDilepPt");
    TH1D *Top_all_JetEta_fakeRate_highDilepPt = Top_all_file->Get<TH1D>("Top_JetEta_fakeRate_highDilepPt");

    /*For single Flavor*/
    TH1D *Top_all_nTrk_bfakeRate_lowDilepPt = Top_all_file->Get<TH1D>("Top_nTrk_bfakeRate_lowDilepPt");
    TH1D *Top_all_nTrk_bfakeRate_highDilepPt = Top_all_file->Get<TH1D>("Top_nTrk_bfakeRate_highDilepPt");
    TH1D *Top_all_nTrk_lfakeRate_lowDilepPt = Top_all_file->Get<TH1D>("Top_nTrk_lfakeRate_lowDilepPt");
    TH1D *Top_all_nTrk_lfakeRate_highDilepPt = Top_all_file->Get<TH1D>("Top_nTrk_lfakeRate_highDilepPt");

    Top_half_nTrk_fakeRate_lowDilepPt->SetLineWidth(2);
    Top_half_JetPt_fakeRate_lowDilepPt->SetLineWidth(2);
    Top_half_JetEta_fakeRate_lowDilepPt->SetLineWidth(2);

    Top_all_nTrk_bfakeRate_lowDilepPt->SetLineWidth(2);
    Top_all_nTrk_bfakeRate_highDilepPt->SetLineWidth(2);
    Top_all_nTrk_lfakeRate_lowDilepPt->SetLineWidth(2);
    Top_all_nTrk_lfakeRate_highDilepPt->SetLineWidth(2);

    Top_half_nTrk_fakeRate_highDilepPt->SetLineWidth(2);
    Top_half_JetPt_fakeRate_highDilepPt->SetLineWidth(2);
    Top_half_JetEta_fakeRate_highDilepPt->SetLineWidth(2);

    Top_half_nTrk_fakeRate_highDilepPt->SetLineColor(kRed);
    Top_half_JetEta_fakeRate_highDilepPt->SetLineColor(kRed);
    Top_half_JetPt_fakeRate_highDilepPt->SetLineColor(kRed);

    Top_all_nTrk_fakeRate_lowDilepPt->SetLineWidth(2);
    Top_all_JetPt_fakeRate_lowDilepPt->SetLineWidth(2);
    Top_all_JetEta_fakeRate_lowDilepPt->SetLineWidth(2);

    Top_all_nTrk_fakeRate_highDilepPt->SetLineWidth(2);
    Top_all_JetPt_fakeRate_highDilepPt->SetLineWidth(2);
    Top_all_JetEta_fakeRate_highDilepPt->SetLineWidth(2);

    Top_all_nTrk_fakeRate_highDilepPt->SetLineColor(kRed);
    Top_all_nTrk_fakeRate_highDilepPt->SetMarkerColor(kRed);
    Top_all_nTrk_fakeRate_highDilepPt->SetMarkerStyle(23);

    Top_all_nTrk_bfakeRate_highDilepPt->SetLineColor(kGray + 2);
    Top_all_nTrk_bfakeRate_highDilepPt->SetMarkerColor(kGray + 2);
    Top_all_nTrk_bfakeRate_highDilepPt->SetMarkerStyle(21);

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
    auto c1 = new TCanvas("c", "c", 800, 700);
    c1->cd();
    c1->SetRightMargin(0.08);
    c1->SetBottomMargin(0.12);
    c1->SetTopMargin(0.07);
    c1->SetLeftMargin(0.12);

    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);

    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetGridx();         // Vertical grid
    pad1->Draw();             // Draw the upper pad: pad1

    // c1->Divide(3, 1);
    // c1->cd(1);
    Top_half_nTrk_fakeRate_lowDilepPt->SetLineColor(kRed);
    Top_half_nTrk_fakeRate_lowDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_half_nTrk_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Track multiplicity");

    Top_half_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.045);
    Top_half_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelSize(0.045);
    Top_half_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelOffset(0.02);
    Top_half_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleOffset(1.3);
    Top_half_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.045);
    Top_half_nTrk_fakeRate_highDilepPt->GetYaxis()->SetLabelSize(0.045);
    Top_half_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleOffset(1.4);
    Top_half_nTrk_fakeRate_highDilepPt->SetLineColor(kRed);
    Top_half_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_half_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitle("Track multiplicity");
    Top_half_nTrk_fakeRate_highDilepPt->SetMarkerColor(kRed);
    Top_half_nTrk_fakeRate_highDilepPt->SetMarkerStyle(21);

    Top_all_nTrk_fakeRate_lowDilepPt->SetLineColor(kRed);
    Top_all_nTrk_fakeRate_lowDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_all_nTrk_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Track multiplicity");

    Top_half_JetEta_fakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.045);
    Top_half_JetEta_fakeRate_highDilepPt->GetXaxis()->SetLabelSize(0.045);
    Top_half_JetEta_fakeRate_highDilepPt->GetXaxis()->SetLabelOffset(0.02);
    Top_half_JetEta_fakeRate_highDilepPt->GetXaxis()->SetTitleOffset(1.3);
    Top_half_JetEta_fakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.045);
    Top_half_JetEta_fakeRate_highDilepPt->GetYaxis()->SetLabelSize(0.045);
    Top_half_JetEta_fakeRate_highDilepPt->GetYaxis()->SetTitleOffset(1.4);
    Top_half_JetEta_fakeRate_highDilepPt->SetLineColor(kRed);
    Top_half_JetEta_fakeRate_highDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_half_JetEta_fakeRate_highDilepPt->GetXaxis()->SetTitle("Jet #eta");
    Top_half_JetEta_fakeRate_highDilepPt->SetMarkerColor(kRed);
    Top_half_JetEta_fakeRate_highDilepPt->SetMarkerStyle(23);

    Top_half_JetPt_fakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.045);
    Top_half_JetPt_fakeRate_highDilepPt->GetXaxis()->SetLabelSize(0.045);
    Top_half_JetPt_fakeRate_highDilepPt->GetXaxis()->SetLabelOffset(0.02);
    Top_half_JetPt_fakeRate_highDilepPt->GetXaxis()->SetTitleOffset(1.3);
    Top_half_JetPt_fakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.045);
    Top_half_JetPt_fakeRate_highDilepPt->GetYaxis()->SetLabelSize(0.045);
    Top_half_JetPt_fakeRate_highDilepPt->GetYaxis()->SetTitleOffset(1.4);
    Top_half_JetPt_fakeRate_highDilepPt->SetLineColor(kRed);
    Top_half_JetPt_fakeRate_highDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_half_JetPt_fakeRate_highDilepPt->GetXaxis()->SetTitle("Jet P_{T} [GeV]");
    Top_half_JetPt_fakeRate_highDilepPt->SetMarkerColor(kRed);
    

    // Top_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitle("Fake Rate");
    // Top_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitle("Track multiplicity");
    // Top_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.05);
    // Top_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.05);
    Top_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.045);
    Top_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelSize(0.045);
    Top_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelOffset(0.02);
    Top_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleOffset(1.3);
    Top_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitle("Track multiplicity");

    // gNLL->GetYaxis()->SetRangeUser(-1, gNLL->GetMaximum());
    Top_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.045);
    Top_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetLabelSize(0.045);
    Top_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleOffset(1.4);
    // Top_nTrk_fakeRate_lowDilepPt->Draw();

    Top_half_JetPt_fakeRate_lowDilepPt->SetLineColor(kRed);
    Top_half_JetPt_fakeRate_lowDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_half_JetPt_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet PT");

    Top_half_JetEta_fakeRate_lowDilepPt->SetLineColor(kRed);
    Top_half_JetEta_fakeRate_lowDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_half_JetEta_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet #eta");

    Top_all_JetPt_fakeRate_lowDilepPt->SetLineColor(kRed);
    Top_all_JetPt_fakeRate_lowDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_all_JetPt_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet PT");

    Top_all_JetEta_fakeRate_lowDilepPt->SetLineColor(kRed);
    Top_all_JetEta_fakeRate_lowDilepPt->GetYaxis()->SetTitle("Fake Rate");
    Top_all_JetEta_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet #eta");

    // Top_JetPt_fakeRate_lowDilepPt->SetLineColor(kGreen + 3);
    // Top_JetPt_fakeRate_lowDilepPt->GetYaxis()->SetTitle("fake rate");
    // Top_JetPt_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet PT");
    //  Top_JetPt_fakeRate_lowDilepPt->Draw();

    // Top_JetEta_fakeRate_lowDilepPt->GetYaxis()->SetTitle("fake rate");
    // Top_JetEta_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet #eta");
    // Top_JetEta_fakeRate_lowDilepPt->Draw();

    /*
    Top_JetPt_fakeRate_highDilepPt->SetLineColor(kRed);
    Top_JetPt_fakeRate_highDilepPt->GetYaxis()->SetTitle("fake rate");
    Top_JetPt_fakeRate_highDilepPt->GetXaxis()->SetTitle("Track multiplicity");

    Top_JetPt_fakeRate_lowDilepPt->Draw("h");
    Top_JetPt_fakeRate_highDilepPt->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.6, 0.80, 0.80);
    l0->SetHeader("Top to emu");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Top_JetPt_fakeRate_lowDilepPt, "low dilepton PT region", "El");
    l0->AddEntry(Top_JetPt_fakeRate_highDilepPt, "high dilepton PT region", "El");
    l0->Draw();
    */
    // Top_half_nTrk_fakeRate_highDilepPt->Draw();
    // Top_half_JetEta_fakeRate_highDilepPt->Draw();
    Top_half_JetPt_fakeRate_highDilepPt->Draw();

    // Top_all_JetEta_fakeRate_lowDilepPt->Draw("same");
    TLegend *l0 = new TLegend(0.55, 0.7, 0.80, 0.90);
    l0->SetHeader("Top to e#mu process");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    // l0->AddEntry(Top_half_nTrk_fakeRate_highDilepPt, "All jets", "Elp");
    // l0->AddEntry(Top_half_JetEta_fakeRate_highDilepPt, "All jets", "Elp");
    l0->AddEntry(Top_half_JetPt_fakeRate_highDilepPt, "All jets", "Elp");
    l0->Draw();

    /*
    TLegend *l0 = new TLegend(0.55, 0.7, 0.80, 0.90);
    l0->SetHeader("Top to e#mu process");
    l0->SetTextSize(0.03);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Top_all_nTrk_fakeRate_lowDilepPt, "Low dilepton PT region", "El");
    l0->Draw();
    */

    gPad->SetLogy();

    // c1->cd(2);
    // Top_JetPt_fakeRate_lowDilepPt->Draw();
    // c1->cd(3);
    // Top_JetEta_fakeRate_lowDilepPt->Draw();
    /*
    Top_all_nTrk_fakeRate_highDilepPt->Draw();
    Top_all_nTrk_bfakeRate_highDilepPt->Draw("same");
    Top_all_nTrk_lfakeRate_highDilepPt->Draw("same");

    TLegend *l0 = new TLegend(0.55, 0.6, 0.80, 0.90);
    l0->SetHeader("Top to e#mu process");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Top_all_nTrk_fakeRate_highDilepPt, "all Jet", "Elp");
    l0->AddEntry(Top_all_nTrk_bfakeRate_highDilepPt, "True b Jet", "Elp");
    l0->AddEntry(Top_all_nTrk_lfakeRate_highDilepPt, "True Light Jet", "Elp");

    l0->Draw();

    gPad->SetLogy();
    */
    gStyle->SetOptStat(0);

    // CMS_lumi(c1, iPeriod, iPos);
    CMS_lumi((TPad *)c1, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");

    // gStyle->SetTextFont(42);
}