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
    TFile *Topemu_all_file = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_all_fakerate.root");
    TFile *Topee_all_file = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top/top_ee_all_fakerate.root");
    TFile *DY_all_file = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/dy/DY_fakerate.root");

    /*Single flavor*/
    TH1D *DY_all_nTrk_bfakeRate_lowDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_bfakeRate_lowDilepPt");
    TH1D *DY_all_nTrk_bfakeRate_highDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_bfakeRate_highDilepPt");
    TH1D *DY_all_nTrk_lfakeRate_lowDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_lfakeRate_lowDilepPt");
    TH1D *DY_all_nTrk_lfakeRate_highDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_lfakeRate_highDilepPt");

    TH1D *Topemu_all_nTrk_bfakeRate_lowDilepPt = Topemu_all_file->Get<TH1D>("Top_nTrk_bfakeRate_lowDilepPt");
    TH1D *Topemu_all_nTrk_bfakeRate_highDilepPt = Topemu_all_file->Get<TH1D>("Top_nTrk_bfakeRate_highDilepPt");
    TH1D *Topemu_all_nTrk_lfakeRate_lowDilepPt = Topemu_all_file->Get<TH1D>("Top_nTrk_lfakeRate_lowDilepPt");
    TH1D *Topemu_all_nTrk_lfakeRate_highDilepPt = Topemu_all_file->Get<TH1D>("Top_nTrk_lfakeRate_highDilepPt");

    DY_all_nTrk_bfakeRate_lowDilepPt->SetLineWidth(2);
    DY_all_nTrk_bfakeRate_highDilepPt->SetLineWidth(2);
    DY_all_nTrk_lfakeRate_lowDilepPt->SetLineWidth(2);
    DY_all_nTrk_lfakeRate_highDilepPt->SetLineWidth(2);

    Topemu_all_nTrk_bfakeRate_lowDilepPt->SetLineWidth(2);
    Topemu_all_nTrk_bfakeRate_highDilepPt->SetLineWidth(2);
    Topemu_all_nTrk_lfakeRate_lowDilepPt->SetLineWidth(2);
    Topemu_all_nTrk_lfakeRate_highDilepPt->SetLineWidth(2);

    DY_all_nTrk_bfakeRate_highDilepPt->SetLineColor(kRed);
    DY_all_nTrk_bfakeRate_highDilepPt->SetMarkerColor(kRed);
    DY_all_nTrk_bfakeRate_highDilepPt->SetMarkerStyle(23);

    DY_all_nTrk_bfakeRate_highDilepPt->GetYaxis()->SetTitle("Fake Rate");
    DY_all_nTrk_bfakeRate_highDilepPt->GetXaxis()->SetTitle("Track multiplicity");
    DY_all_nTrk_bfakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.05);
    DY_all_nTrk_bfakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.05);

    int W = 600;
    int H = 600;

    int H_ref = 600;
    int W_ref = 600;

    float T = 0.08 * H_ref;
    float B = 0.12 * H_ref;
    float L = 0.12 * W_ref;
    float R = 0.04 * W_ref;

    auto c1 = new TCanvas("c1", "c1", 50, 50, W, H);

    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);

    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetGridx();         // Vertical grid
    pad1->Draw();
    pad1->cd();    

    DY_all_nTrk_bfakeRate_highDilepPt->Draw();
    Topemu_all_nTrk_bfakeRate_highDilepPt->Draw("same");

    gPad->SetLogy();

    TLegend *l0 = new TLegend(0.55, 0.6, 0.80, 0.90);
    l0->SetHeader("True b Jet");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(DY_all_nTrk_bfakeRate_highDilepPt, "Drell-Yan", "Elp");
    l0->AddEntry(Topemu_all_nTrk_bfakeRate_highDilepPt, "Top to e#mu", "Elp");

    l0->Draw();

    gStyle->SetOptStat(0);

    c1->cd(); // Go back to the main canvas before defining pad2
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.2);
    pad2->SetGridx(); // vertical grid
    pad2->Draw();
    pad2->cd(); // pad2 becomes the current pad

    TH1D *h3 = (TH1D *)Topemu_all_nTrk_bfakeRate_highDilepPt->Clone("h3");
    h3->SetLineColor(kBlack);

    h3->SetStats(0); // No statistics on lower plot
    h3->Divide(DY_all_nTrk_bfakeRate_highDilepPt);
    // h3->SetMarkerStyle(21);
    h3->Draw("ep"); // Draw the ratio plot

    h3->GetYaxis()->SetTitle("Top to e#mu/Drell Yan");
    h3->GetYaxis()->SetTitleSize(18);
    h3->GetYaxis()->SetNdivisions(505);

    h3->GetYaxis()->SetTitleFont(43);
    h3->GetYaxis()->SetTitleOffset(1.55);
    h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetYaxis()->SetLabelSize(15);

    // X axis ratio plot settings
    h3->GetXaxis()->SetTitle("Track multiplicity");

    h3->GetXaxis()->SetTitleSize(18);
    h3->GetXaxis()->SetTitleFont(43);
    h3->GetXaxis()->SetTitleOffset(1.);
    h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetXaxis()->SetLabelSize(15);
}