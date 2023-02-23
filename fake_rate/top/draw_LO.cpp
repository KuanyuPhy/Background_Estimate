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
using namespace std;
void draw_LO()
{
    TFile *Topfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top/Ratio_apply.root");

    TH1D *h_Top_nTrk_HighDilepPt_predict = ((TH1D *)Topfile->Get("h_Top_nTrk_HighDilepPt_predict"));
    TH1D *h_Top_JetPt_HighDilepPt_predict = ((TH1D *)Topfile->Get("h_Top_JetPt_HighDilepPt_predict"));
    TH1D *h_Top_JetEta_HighDilepPt_predict = ((TH1D *)Topfile->Get("h_Top_JetEta_HighDilepPt_predict"));

    TH1D *h_Top_nTrk_HighDilepPt_true = ((TH1D *)Topfile->Get("h_Top_nTrk_HighDilepPt_true"));
    TH1D *h_Top_JetPt_HighDilepPt_true = ((TH1D *)Topfile->Get("h_Top_JetPt_HighDilepPt_true"));
    TH1D *h_Top_JetEta_HighDilepPt_true = ((TH1D *)Topfile->Get("h_Top_JetEta_HighDilepPt_true"));

    h_Top_nTrk_HighDilepPt_predict->SetLineWidth(2);
    h_Top_JetPt_HighDilepPt_predict->SetLineWidth(2);
    h_Top_JetEta_HighDilepPt_predict->SetLineWidth(2);

    h_Top_nTrk_HighDilepPt_true->SetLineWidth(2);
    h_Top_JetPt_HighDilepPt_true->SetLineWidth(2);
    h_Top_JetEta_HighDilepPt_true->SetLineWidth(2);

    h_Top_nTrk_HighDilepPt_true->SetLineColor(kRed);
    h_Top_JetPt_HighDilepPt_true->SetLineColor(kRed);
    h_Top_JetEta_HighDilepPt_true->SetLineColor(kRed);

    int W = 600;
    int H = 600;

    int H_ref = 600;
    int W_ref = 600;

    float T = 0.08 * H_ref;
    float B = 0.12 * H_ref;
    float L = 0.12 * W_ref;
    float R = 0.04 * W_ref;

    auto c1 = new TCanvas("c1", "c1", 50, 50, W, H);
    /*
    // Upper plot will be in pad1
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);

    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetGridx();         // Vertical grid
    pad1->Draw(); // Draw the upper pad: pad1
    pad1->cd();   // pad1 becomes the current pad
    h_Top_nTrk_HighDilepPt_true->GetYaxis()->SetTitle("nJet");
    h_Top_nTrk_HighDilepPt_true->GetXaxis()->SetTitle("Track multiplicity");
    h_Top_nTrk_HighDilepPt_true->Draw();
    h_Top_nTrk_HighDilepPt_predict->Draw("same");

    auto *leg = new TLegend(0.5, 0.7, 0.9, 0.9);
    //leg->SetHeader("The Legend Title", "C"); // option "C" allows to center the header
    leg->AddEntry(h_Top_nTrk_HighDilepPt_predict, "Predict", "le");
    leg->AddEntry(h_Top_nTrk_HighDilepPt_true, "True BG", "le");
    leg->Draw();

    // lower plot will be in pad
    c1->cd(); // Go back to the main canvas before defining pad2
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.2);
    pad2->SetGridx(); // vertical grid
    pad2->Draw();
    pad2->cd(); // pad2 becomes the current pad

    TH1D *h3 = (TH1D *)h_Top_nTrk_HighDilepPt_predict->Clone("h3");
    h3->SetLineColor(kBlack);
    h3->Sumw2();
    h3->SetStats(0); // No statistics on lower plot
    h3->Divide(h_Top_nTrk_HighDilepPt_true);
    // h3->SetMarkerStyle(21);
    h3->Draw("ep"); // Draw the ratio plot

    h3->GetYaxis()->SetTitle("predict/True BG");
    h3->GetYaxis()->SetNdivisions(505);
    h3->GetYaxis()->SetTitleSize(15);
    h3->GetYaxis()->SetTitleFont(43);
    h3->GetYaxis()->SetTitleOffset(1.55);
    h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetYaxis()->SetLabelSize(15);

    // X axis ratio plot settings
    h3->GetXaxis()->SetTitle("Track multiplicity");

    h3->GetXaxis()->SetTitleSize(15);
    h3->GetXaxis()->SetTitleFont(43);
    h3->GetXaxis()->SetTitleOffset(1.);
    h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetXaxis()->SetLabelSize(15);

    */
    /*
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);

    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetGridx();         // Vertical grid
    pad1->Draw();             // Draw the upper pad: pad1
    pad1->cd();               // pad1 becomes the current pad
    h_Top_JetPt_HighDilepPt_true->GetYaxis()->SetTitle("nJet");
    //h_Top_JetPt_HighDilepPt_true->GetXaxis()->SetTitle("Track multiplicity");
    h_Top_JetPt_HighDilepPt_true->Draw();
    h_Top_JetPt_HighDilepPt_predict->Draw("same");

    auto *leg = new TLegend(0.5, 0.7, 0.9, 0.9);
    // leg->SetHeader("The Legend Title", "C"); // option "C" allows to center the header
    leg->AddEntry(h_Top_JetPt_HighDilepPt_predict, "Predict", "le");
    leg->AddEntry(h_Top_JetPt_HighDilepPt_true, "True BG", "le");
    leg->Draw();

    gPad->SetLogy();

    // lower plot will be in pad
    c1->cd(); // Go back to the main canvas before defining pad2
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.2);
    pad2->SetGridx(); // vertical grid
    pad2->Draw();
    pad2->cd(); // pad2 becomes the current pad

    TH1D *h3 = (TH1D *)h_Top_JetPt_HighDilepPt_predict->Clone("h3");
    h3->SetLineColor(kBlack);
    h3->Sumw2();
    h3->SetStats(0); // No statistics on lower plot
    h3->Divide(h_Top_JetPt_HighDilepPt_true);
    // h3->SetMarkerStyle(21);
    h3->Draw("ep"); // Draw the ratio plot

    h3->GetYaxis()->SetTitle("predict/True BG");
    h3->GetYaxis()->SetNdivisions(505);
    h3->GetYaxis()->SetTitleSize(15);
    h3->GetYaxis()->SetTitleFont(43);
    h3->GetYaxis()->SetTitleOffset(1.55);
    h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetYaxis()->SetLabelSize(15);

    // X axis ratio plot settings
    h3->GetXaxis()->SetTitle("Jet PT");

    h3->GetXaxis()->SetTitleSize(15);
    h3->GetXaxis()->SetTitleFont(43);
    h3->GetXaxis()->SetTitleOffset(1.);
    h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetXaxis()->SetLabelSize(15);
    */
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);

    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetGridx();         // Vertical grid
    pad1->Draw();             // Draw the upper pad: pad1
    pad1->cd();               // pad1 becomes the current pad
    h_Top_JetEta_HighDilepPt_true->GetYaxis()->SetTitle("nJet");
    // h_Top_JetPt_HighDilepPt_true->GetXaxis()->SetTitle("Track multiplicity");
    h_Top_JetEta_HighDilepPt_true->Draw();
    h_Top_JetEta_HighDilepPt_predict->Draw("same");

    auto *leg = new TLegend(0.5, 0.7, 0.9, 0.9);
    // leg->SetHeader("The Legend Title", "C"); // option "C" allows to center the header
    leg->AddEntry(h_Top_JetEta_HighDilepPt_predict, "Predict", "le");
    leg->AddEntry(h_Top_JetEta_HighDilepPt_true, "True BG", "le");
    leg->Draw();

    gPad->SetLogy();

    // lower plot will be in pad
    c1->cd(); // Go back to the main canvas before defining pad2
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.2);
    pad2->SetGridx(); // vertical grid
    pad2->Draw();
    pad2->cd(); // pad2 becomes the current pad

    TH1D *h3 = (TH1D *)h_Top_JetEta_HighDilepPt_predict->Clone("h3");
    h3->SetLineColor(kBlack);
    h3->Sumw2();
    h3->SetStats(0); // No statistics on lower plot
    h3->Divide(h_Top_JetEta_HighDilepPt_true);
    // h3->SetMarkerStyle(21);
    h3->Draw("ep"); // Draw the ratio plot

    h3->GetYaxis()->SetTitle("predict/True BG");
    h3->GetYaxis()->SetNdivisions(505);
    h3->GetYaxis()->SetTitleSize(15);
    h3->GetYaxis()->SetTitleFont(43);
    h3->GetYaxis()->SetTitleOffset(1.55);
    h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetYaxis()->SetLabelSize(15);

    // X axis ratio plot settings
    h3->GetXaxis()->SetTitle("Jet #eta");

    h3->GetXaxis()->SetTitleSize(15);
    h3->GetXaxis()->SetTitleFont(43);
    h3->GetXaxis()->SetTitleOffset(1.);
    h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetXaxis()->SetLabelSize(15);
    gStyle->SetOptStat(0);
}