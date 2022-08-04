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
void quick2d_draw(TString file = "./Ratio_apply.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *h_Top_JetPt_bjet_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_bjet_CR"));
    TH1D *h_Top_JetPt_cjet_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_cjet_CR"));
    TH1D *h_Top_JetPt_ljet_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_ljet_CR"));
    TH1D *h_Top_JetPt_bjet_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_bjet_SR"));
    TH1D *h_Top_JetPt_cjet_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_cjet_SR"));
    TH1D *h_Top_JetPt_ljet_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_ljet_SR"));
    TH1D *h_Top_nTrk_bjet_CR = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_CR"));
    TH1D *h_Top_nTrk_cjet_CR = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_CR"));
    TH1D *h_Top_nTrk_ljet_CR = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_CR"));
    TH1D *h_Top_nTrk_bjet_SR = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_SR"));
    TH1D *h_Top_nTrk_cjet_SR = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_SR"));
    TH1D *h_Top_nTrk_ljet_SR = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_SR"));

    h_Top_JetPt_bjet_CR->SetLineWidth(2);
    h_Top_JetPt_cjet_CR->SetLineWidth(2);
    h_Top_JetPt_ljet_CR->SetLineWidth(2);
    h_Top_JetPt_bjet_SR->SetLineWidth(2);
    h_Top_JetPt_cjet_SR->SetLineWidth(2);
    h_Top_JetPt_ljet_SR->SetLineWidth(2);
    h_Top_nTrk_bjet_CR->SetLineWidth(2);
    h_Top_nTrk_cjet_CR->SetLineWidth(2);
    h_Top_nTrk_ljet_CR->SetLineWidth(2);
    h_Top_nTrk_bjet_SR->SetLineWidth(2);
    h_Top_nTrk_cjet_SR->SetLineWidth(2);
    h_Top_nTrk_ljet_SR->SetLineWidth(2);

    h_Top_JetPt_bjet_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_cjet_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_ljet_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_bjet_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_cjet_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_ljet_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_bjet_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_cjet_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_ljet_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_bjet_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_cjet_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_ljet_SR->GetXaxis()->SetNdivisions(6, 5, 0);

    h_Top_JetPt_bjet_CR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_cjet_CR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_ljet_CR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_bjet_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_cjet_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_ljet_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_bjet_CR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_cjet_CR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_ljet_CR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_bjet_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_cjet_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_nTrk_ljet_SR->GetYaxis()->SetNdivisions(6, 5, 0);

    h_Top_JetPt_bjet_CR->SetLineColor(kGreen + 3);
    h_Top_JetPt_cjet_CR->SetLineColor(kGreen + 3);
    h_Top_JetPt_ljet_CR->SetLineColor(kGreen + 3);
    h_Top_nTrk_bjet_CR->SetLineColor(kGreen + 3);
    h_Top_nTrk_cjet_CR->SetLineColor(kGreen + 3);
    h_Top_nTrk_ljet_CR->SetLineColor(kGreen + 3);

    int W = 800;
    int H = 600;

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
    c1->SetLeftMargin(L / W);
    c1->SetRightMargin(R / W);
    c1->SetTopMargin(T / H);
    c1->SetBottomMargin(B / H);
    c1->SetTickx(0);
    c1->SetTicky(0);

    c1->Divide(3, 1);
    c1->cd(1);

    h_Top_JetPt_bjet_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_JetPt_bjet_CR->GetYaxis()->SetTitle("nJet");

    h_Top_JetPt_bjet_CR->Draw();
    h_Top_JetPt_bjet_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(h_Top_JetPt_bjet_CR, "CR", "l");
    l0->AddEntry(h_Top_JetPt_bjet_SR, "SR", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_JetPt_cjet_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_JetPt_cjet_SR->GetYaxis()->SetTitle("nJet");

    h_Top_JetPt_cjet_SR->Draw("h ");
    h_Top_JetPt_cjet_CR->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("c flavor");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_Top_JetPt_cjet_CR, "CR", "l");
    l1->AddEntry(h_Top_JetPt_cjet_SR, "SR", "l");
    l1->Draw();

    c1->cd(3);

    h_Top_JetPt_ljet_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_JetPt_ljet_SR->GetYaxis()->SetTitle("nJet");

    h_Top_JetPt_ljet_SR->Draw("h ");
    h_Top_JetPt_ljet_CR->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(h_Top_JetPt_ljet_CR, "CR", "l");
    l2->AddEntry(h_Top_JetPt_ljet_SR, "SR", "l");
    l2->Draw();

    gStyle->SetOptStat(0);
}