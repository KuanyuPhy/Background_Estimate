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
#include "./../../../lib/Cross_section.h"
#include "./../../../lib/tdrstyle.C"
#include "./../../../lib/CMS_lumi.h"
using namespace std;
void draw_comp_pred_TrueBG()
{
    TFile *Top_true_BGfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top/0620_macro/top_all.root");
    TFile *Top_pred_BGfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top/0620_macro/BG_pred.root");

    TH1D *h_Top_nTrk_HighDilepPt_trueBG = Top_true_BGfile->Get<TH1D>("h_Top_nTrk_cut_highDilepPt");
    TH1D *h_Top_JetPt_HighDilepPt_trueBG = Top_true_BGfile->Get<TH1D>("h_Top_JetPt_cut_highDilepPt");
    TH1D *h_Top_JetEta_HighDilepPt_trueBG = Top_true_BGfile->Get<TH1D>("h_Top_JetEta_cut_highDilepPt");

    // TH1D *h_Top_nTrk_HighDilepPt_true = Topfile->Get<TH1D>("h_Top_nTrk_HighDilepPt_true");
    // TH1D *h_Top_JetPt_HighDilepPt_true = Topfile->Get<TH1D>("h_Top_JetPt_HighDilepPt_true");
    // TH1D *h_Top_JetEta_HighDilepPt_true = Topfile->Get<TH1D>("h_Top_JetEta_HighDilepPt_true");

    TH1D *h_Top_nTrk_HighDilepPt_predBG = Top_pred_BGfile->Get<TH1D>("h_Top_nTrk_HighDilepPt_predict");
    TH1D *h_Top_JetPt_HighDilepPt_predBG = Top_pred_BGfile->Get<TH1D>("h_Top_JetPt_HighDilepPt_predict");
    TH1D *h_Top_JetEta_HighDilepPt_predBG = Top_pred_BGfile->Get<TH1D>("h_Top_JetEta_HighDilepPt_predict");

    setTDRStyle();

    h_Top_nTrk_HighDilepPt_trueBG->SetLineWidth(2);
    h_Top_JetPt_HighDilepPt_trueBG->SetLineWidth(2);
    h_Top_JetEta_HighDilepPt_trueBG->SetLineWidth(2);
    h_Top_nTrk_HighDilepPt_predBG->SetLineWidth(2);
    h_Top_JetPt_HighDilepPt_predBG->SetLineWidth(2);
    h_Top_JetEta_HighDilepPt_predBG->SetLineWidth(2);

    h_Top_nTrk_HighDilepPt_trueBG->SetLineColor(kRed);
    h_Top_JetPt_HighDilepPt_trueBG->SetLineColor(kRed);
    h_Top_JetEta_HighDilepPt_trueBG->SetLineColor(kRed);
    h_Top_nTrk_HighDilepPt_predBG->SetLineColor(kBlue);
    h_Top_JetPt_HighDilepPt_predBG->SetLineColor(kBlue);
    h_Top_JetEta_HighDilepPt_predBG->SetLineColor(kBlue);

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

    
    h_Top_nTrk_HighDilepPt_trueBG->GetXaxis()->SetTitle("");
    h_Top_nTrk_HighDilepPt_trueBG->GetYaxis()->SetTitle("nJets");
    h_Top_nTrk_HighDilepPt_trueBG->GetYaxis()->SetTitleSize(0.06);
    h_Top_nTrk_HighDilepPt_trueBG->GetYaxis()->SetLabelSize(0.06);
    h_Top_nTrk_HighDilepPt_trueBG->GetYaxis()->SetTitleOffset(1.1);

    h_Top_nTrk_HighDilepPt_trueBG->GetXaxis()->SetTitleSize(0.06);
    h_Top_nTrk_HighDilepPt_trueBG->GetXaxis()->SetLabelSize(0.05);
    h_Top_nTrk_HighDilepPt_trueBG->GetXaxis()->SetLabelOffset(0.1);
    h_Top_nTrk_HighDilepPt_trueBG->GetXaxis()->SetTitleOffset(1);

    h_Top_nTrk_HighDilepPt_trueBG->Draw("EP");

    h_Top_nTrk_HighDilepPt_trueBG->Draw();
    h_Top_nTrk_HighDilepPt_predBG->Draw("same");

    auto leg1 = new TLegend(0.62, 0.70, 0.92, 0.88);
    leg1->SetTextFont(42);
    leg1->SetTextSize(0.05);
    leg1->SetFillColor(0);
    leg1->SetLineColor(0);
    leg1->AddEntry(h_Top_nTrk_HighDilepPt_trueBG, "True BG", "le");
    leg1->AddEntry(h_Top_nTrk_HighDilepPt_predBG, "predict", "le");
    leg1->Draw("same");

    CMS_lumi(pad1, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");

    pad1->RedrawAxis();


    gPad->SetLogy();

    c1->cd();
    auto pad2 = new TPad("pad2", "", 0, 0, 1, 0.3);
    pad2->SetGridy();
    pad2->SetRightMargin(0.05);
    pad2->SetLeftMargin(0.13);
    pad2->SetTopMargin(0.06);
    pad2->SetBottomMargin(0.4);
    pad2->Draw();
    pad2->cd();

    TH1D *h_Top_nTrk_HighDilepPt_ratio = (TH1D *)h_Top_nTrk_HighDilepPt_predBG->Clone("h_Top_nTrk_HighDilepPt_ratio");
    h_Top_nTrk_HighDilepPt_ratio->Divide(h_Top_nTrk_HighDilepPt_trueBG);

    h_Top_nTrk_HighDilepPt_ratio->SetTitle("");
    h_Top_nTrk_HighDilepPt_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_Top_nTrk_HighDilepPt_ratio->GetYaxis()->SetTitle("predict/True BG");
    h_Top_nTrk_HighDilepPt_ratio->SetMarkerStyle(20);

    h_Top_nTrk_HighDilepPt_ratio->SetMarkerColor(TColor::GetColor("#202020"));
    h_Top_nTrk_HighDilepPt_ratio->SetMarkerSize(1.2);
    h_Top_nTrk_HighDilepPt_ratio->SetMarkerStyle(20);
    h_Top_nTrk_HighDilepPt_ratio->SetLineColor(TColor::GetColor("#202020"));
    h_Top_nTrk_HighDilepPt_ratio->SetLineWidth(2);

    h_Top_nTrk_HighDilepPt_ratio->GetXaxis()->SetTitleSize(0.16);
    h_Top_nTrk_HighDilepPt_ratio->GetXaxis()->SetTitleOffset(1.2);
    h_Top_nTrk_HighDilepPt_ratio->GetXaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_Top_nTrk_HighDilepPt_ratio->GetXaxis()->SetLabelOffset(0.05);
    h_Top_nTrk_HighDilepPt_ratio->GetYaxis()->SetTitleSize(0.13);
    h_Top_nTrk_HighDilepPt_ratio->GetYaxis()->SetTitleOffset(0.2 * (7 / 3.));
    h_Top_nTrk_HighDilepPt_ratio->GetYaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_Top_nTrk_HighDilepPt_ratio->GetYaxis()->SetNdivisions(505);

    h_Top_nTrk_HighDilepPt_ratio->Draw("ep");

    
    /*
    h_Top_JetPt_HighDilepPt_trueBG->GetXaxis()->SetTitle("");
    h_Top_JetPt_HighDilepPt_trueBG->GetYaxis()->SetTitle("nJets");
    h_Top_JetPt_HighDilepPt_trueBG->GetYaxis()->SetTitleSize(0.06);
    h_Top_JetPt_HighDilepPt_trueBG->GetYaxis()->SetLabelSize(0.06);
    h_Top_JetPt_HighDilepPt_trueBG->GetYaxis()->SetTitleOffset(1.1);

    h_Top_JetPt_HighDilepPt_trueBG->GetXaxis()->SetTitleSize(0.06);
    h_Top_JetPt_HighDilepPt_trueBG->GetXaxis()->SetLabelSize(0.05);
    h_Top_JetPt_HighDilepPt_trueBG->GetXaxis()->SetLabelOffset(0.1);
    h_Top_JetPt_HighDilepPt_trueBG->GetXaxis()->SetTitleOffset(1);

    h_Top_JetPt_HighDilepPt_trueBG->Draw("EP");

    h_Top_JetPt_HighDilepPt_trueBG->Draw();
    h_Top_JetPt_HighDilepPt_predBG->Draw("same");

    auto leg1 = new TLegend(0.62, 0.70, 0.92, 0.88);
    leg1->SetTextFont(42);
    leg1->SetTextSize(0.05);
    leg1->SetFillColor(0);
    leg1->SetLineColor(0);
    leg1->AddEntry(h_Top_JetPt_HighDilepPt_trueBG, "True BG", "le");
    leg1->AddEntry(h_Top_JetPt_HighDilepPt_predBG, "predict", "le");
    leg1->Draw("same");

    CMS_lumi(pad1, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");

    pad1->RedrawAxis();

    gPad->SetLogy();

    c1->cd();
    auto pad2 = new TPad("pad2", "", 0, 0, 1, 0.3);
    pad2->SetGridy();
    pad2->SetRightMargin(0.05);
    pad2->SetLeftMargin(0.13);
    pad2->SetTopMargin(0.06);
    pad2->SetBottomMargin(0.4);
    pad2->Draw();
    pad2->cd();

    TH1D *h_Top_JetPt_HighDilepPt_ratio = (TH1D *)h_Top_JetPt_HighDilepPt_predBG->Clone("h_Top_JetPt_HighDilepPt_ratio");
    h_Top_JetPt_HighDilepPt_ratio->Divide(h_Top_JetPt_HighDilepPt_trueBG);

    h_Top_JetPt_HighDilepPt_ratio->SetTitle("");
    h_Top_JetPt_HighDilepPt_ratio->GetXaxis()->SetTitle("Jet P_{T} [GeV]");
    h_Top_JetPt_HighDilepPt_ratio->GetYaxis()->SetTitle("predict/True BG");
    h_Top_JetPt_HighDilepPt_ratio->SetMarkerStyle(20);

    h_Top_JetPt_HighDilepPt_ratio->SetMarkerColor(TColor::GetColor("#202020"));
    h_Top_JetPt_HighDilepPt_ratio->SetMarkerSize(1.2);
    h_Top_JetPt_HighDilepPt_ratio->SetMarkerStyle(20);
    h_Top_JetPt_HighDilepPt_ratio->SetLineColor(TColor::GetColor("#202020"));
    h_Top_JetPt_HighDilepPt_ratio->SetLineWidth(2);

    h_Top_JetPt_HighDilepPt_ratio->GetXaxis()->SetTitleSize(0.16);
    h_Top_JetPt_HighDilepPt_ratio->GetXaxis()->SetTitleOffset(1.2);
    h_Top_JetPt_HighDilepPt_ratio->GetXaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_Top_JetPt_HighDilepPt_ratio->GetXaxis()->SetLabelOffset(0.05);
    h_Top_JetPt_HighDilepPt_ratio->GetYaxis()->SetTitleSize(0.13);
    h_Top_JetPt_HighDilepPt_ratio->GetYaxis()->SetTitleOffset(0.2 * (7 / 3.));
    h_Top_JetPt_HighDilepPt_ratio->GetYaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_Top_JetPt_HighDilepPt_ratio->GetYaxis()->SetNdivisions(505);

    h_Top_JetPt_HighDilepPt_ratio->Draw("ep");
    */
    /*
    h_Top_JetEta_HighDilepPt_trueBG->GetXaxis()->SetTitle("");
    h_Top_JetEta_HighDilepPt_trueBG->GetYaxis()->SetTitle("nJets");
    h_Top_JetEta_HighDilepPt_trueBG->GetYaxis()->SetTitleSize(0.06);
    h_Top_JetEta_HighDilepPt_trueBG->GetYaxis()->SetLabelSize(0.06);
    h_Top_JetEta_HighDilepPt_trueBG->GetYaxis()->SetTitleOffset(1.1);

    h_Top_JetEta_HighDilepPt_trueBG->GetXaxis()->SetTitleSize(0.06);
    h_Top_JetEta_HighDilepPt_trueBG->GetXaxis()->SetLabelSize(0.05);
    h_Top_JetEta_HighDilepPt_trueBG->GetXaxis()->SetLabelOffset(0.1);
    h_Top_JetEta_HighDilepPt_trueBG->GetXaxis()->SetTitleOffset(1);

    h_Top_JetEta_HighDilepPt_trueBG->Draw("EP");

    h_Top_JetEta_HighDilepPt_trueBG->Draw();
    h_Top_JetEta_HighDilepPt_predBG->Draw("same");

    auto leg1 = new TLegend(0.62, 0.70, 0.92, 0.88);
    leg1->SetTextFont(42);
    leg1->SetTextSize(0.05);
    leg1->SetFillColor(0);
    leg1->SetLineColor(0);
    leg1->AddEntry(h_Top_JetEta_HighDilepPt_trueBG, "True BG", "le");
    leg1->AddEntry(h_Top_JetEta_HighDilepPt_predBG, "predict", "le");
    leg1->Draw("same");

    CMS_lumi(pad1, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");

    pad1->RedrawAxis();

    gPad->SetLogy();

    c1->cd();
    auto pad2 = new TPad("pad2", "", 0, 0, 1, 0.3);
    pad2->SetGridy();
    pad2->SetRightMargin(0.05);
    pad2->SetLeftMargin(0.13);
    pad2->SetTopMargin(0.06);
    pad2->SetBottomMargin(0.4);
    pad2->Draw();
    pad2->cd();

    TH1D *h_Top_JetEta_HighDilepPt_ratio = (TH1D *)h_Top_JetEta_HighDilepPt_predBG->Clone("h_Top_JetEta_HighDilepPt_ratio");
    h_Top_JetEta_HighDilepPt_ratio->Divide(h_Top_JetEta_HighDilepPt_trueBG);

    h_Top_JetEta_HighDilepPt_ratio->SetTitle("");
    h_Top_JetEta_HighDilepPt_ratio->GetXaxis()->SetTitle("Jet #eta");
    h_Top_JetEta_HighDilepPt_ratio->GetYaxis()->SetTitle("predict/True BG");
    h_Top_JetEta_HighDilepPt_ratio->SetMarkerStyle(20);

    h_Top_JetEta_HighDilepPt_ratio->SetMarkerColor(TColor::GetColor("#202020"));
    h_Top_JetEta_HighDilepPt_ratio->SetMarkerSize(1.2);
    h_Top_JetEta_HighDilepPt_ratio->SetMarkerStyle(20);
    h_Top_JetEta_HighDilepPt_ratio->SetLineColor(TColor::GetColor("#202020"));
    h_Top_JetEta_HighDilepPt_ratio->SetLineWidth(2);

    h_Top_JetEta_HighDilepPt_ratio->GetXaxis()->SetTitleSize(0.16);
    h_Top_JetEta_HighDilepPt_ratio->GetXaxis()->SetTitleOffset(1.2);
    h_Top_JetEta_HighDilepPt_ratio->GetXaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_Top_JetEta_HighDilepPt_ratio->GetXaxis()->SetLabelOffset(0.05);
    h_Top_JetEta_HighDilepPt_ratio->GetYaxis()->SetTitleSize(0.13);
    h_Top_JetEta_HighDilepPt_ratio->GetYaxis()->SetTitleOffset(0.2 * (7 / 3.));
    h_Top_JetEta_HighDilepPt_ratio->GetYaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_Top_JetEta_HighDilepPt_ratio->GetYaxis()->SetNdivisions(505);

    h_Top_JetEta_HighDilepPt_ratio->Draw("ep");
    */
}   