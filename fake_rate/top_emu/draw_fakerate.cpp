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
void draw_fakerate()
{
    TFile *Topfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_fakerate.root");

    TH1D *Top_nTrk_fakeRate_lowDilepPt = ((TH1D *)Topfile->Get("Top_nTrk_fakeRate_lowDilepPt"));
    TH1D *Top_JetPt_fakeRate_lowDilepPt = ((TH1D *)Topfile->Get("Top_JetPt_fakeRate_lowDilepPt"));
    TH1D *Top_JetEta_fakeRate_lowDilepPt = ((TH1D *)Topfile->Get("Top_JetEta_fakeRate_lowDilepPt"));

    TH1D *Top_nTrk_fakeRate_highDilepPt = ((TH1D *)Topfile->Get("Top_nTrk_fakeRate_highDilepPt"));
    TH1D *Top_JetPt_fakeRate_highDilepPt = ((TH1D *)Topfile->Get("Top_JetPt_fakeRate_highDilepPt"));
    TH1D *Top_JetEta_fakeRate_highDilepPt = ((TH1D *)Topfile->Get("Top_JetEta_fakeRate_highDilepPt"));

    Top_nTrk_fakeRate_lowDilepPt->SetLineWidth(2);
    Top_JetPt_fakeRate_lowDilepPt->SetLineWidth(2);
    Top_JetEta_fakeRate_lowDilepPt->SetLineWidth(2);

    Top_nTrk_fakeRate_highDilepPt->SetLineWidth(2);
    Top_JetPt_fakeRate_highDilepPt->SetLineWidth(2);
    Top_JetEta_fakeRate_highDilepPt->SetLineWidth(2);

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

    // c1->Divide(3, 1);
    // c1->cd(1);
    Top_nTrk_fakeRate_lowDilepPt->SetLineColor(kRed);
    Top_nTrk_fakeRate_lowDilepPt->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Track multiplicity");
    // Top_nTrk_fakeRate_lowDilepPt->Draw();

    Top_JetPt_fakeRate_lowDilepPt->SetLineColor(kGreen + 3);
    Top_JetPt_fakeRate_lowDilepPt->GetYaxis()->SetTitle("fake rate");
    Top_JetPt_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet PT");
    // Top_JetPt_fakeRate_lowDilepPt->Draw();

    // Top_JetEta_fakeRate_lowDilepPt->GetYaxis()->SetTitle("fake rate");
    // Top_JetEta_fakeRate_lowDilepPt->GetXaxis()->SetTitle("Jet #eta");
    // Top_JetEta_fakeRate_lowDilepPt->Draw();

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

    gPad->SetLogy();
    // c1->cd(2);
    // Top_JetPt_fakeRate_lowDilepPt->Draw();
    // c1->cd(3);
    // Top_JetEta_fakeRate_lowDilepPt->Draw();

    gStyle->SetOptStat(0);
}