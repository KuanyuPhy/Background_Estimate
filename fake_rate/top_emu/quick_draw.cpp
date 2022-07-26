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
void quick_draw(TString file = "./Ratio_apply.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *h_Top_trk_bybin_CR = ((TH1D *)Topfile->Get("h_Top_trk_bybin_CR"));
    TH1D *h_Top_btrk_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_bybin_CR"));
    TH1D *h_Top_ctrk_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ctrk_bybin_CR"));
    TH1D *h_Top_ltrk_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_bybin_CR"));
    TH1D *h_Top_htrk_bybin_CR = ((TH1D *)Topfile->Get("h_Top_htrk_bybin_CR"));
    TH1D *h_Top_trk_SR = ((TH1D *)Topfile->Get("h_Top_trk_SR"));
    TH1D *h_Top_btrk_SR = ((TH1D *)Topfile->Get("h_Top_btrk_SR"));
    TH1D *h_Top_ctrk_SR = ((TH1D *)Topfile->Get("h_Top_ctrk_SR"));
    TH1D *h_Top_ltrk_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_SR"));
    TH1D *h_Top_htrk_SR = ((TH1D *)Topfile->Get("h_Top_htrk_SR"));
    TH1D *h_Top_trk_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_trk_region1_bybin_CR"));
    TH1D *h_Top_trk_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_trk_region2_bybin_CR"));
    TH1D *h_Top_trk_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_trk_region3_bybin_CR"));
    TH1D *h_Top_btrk_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_region1_bybin_CR"));
    TH1D *h_Top_btrk_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_region2_bybin_CR"));
    TH1D *h_Top_btrk_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_btrk_region3_bybin_CR"));
    TH1D *h_Top_ctrk_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ctrk_region1_bybin_CR"));
    TH1D *h_Top_ctrk_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ctrk_region2_bybin_CR"));
    TH1D *h_Top_ctrk_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ctrk_region3_bybin_CR"));
    TH1D *h_Top_ltrk_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_region1_bybin_CR"));
    TH1D *h_Top_ltrk_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_region2_bybin_CR"));
    TH1D *h_Top_ltrk_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_ltrk_region3_bybin_CR"));
    TH1D *h_Top_htrk_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_htrk_region1_bybin_CR"));
    TH1D *h_Top_htrk_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_htrk_region2_bybin_CR"));
    TH1D *h_Top_htrk_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_htrk_region3_bybin_CR"));

    TH1D *h_Top_trk_region1_SR = ((TH1D *)Topfile->Get("h_Top_trk_region1_SR"));
    TH1D *h_Top_trk_region2_SR = ((TH1D *)Topfile->Get("h_Top_trk_region2_SR"));
    TH1D *h_Top_trk_region3_SR = ((TH1D *)Topfile->Get("h_Top_trk_region3_SR"));
    TH1D *h_Top_btrk_region1_SR = ((TH1D *)Topfile->Get("h_Top_btrk_region1_SR"));
    TH1D *h_Top_btrk_region2_SR = ((TH1D *)Topfile->Get("h_Top_btrk_region2_SR"));
    TH1D *h_Top_btrk_region3_SR = ((TH1D *)Topfile->Get("h_Top_btrk_region3_SR"));
    TH1D *h_Top_ctrk_region1_SR = ((TH1D *)Topfile->Get("h_Top_ctrk_region1_SR"));
    TH1D *h_Top_ctrk_region2_SR = ((TH1D *)Topfile->Get("h_Top_ctrk_region2_SR"));
    TH1D *h_Top_ctrk_region3_SR = ((TH1D *)Topfile->Get("h_Top_ctrk_region3_SR"));
    TH1D *h_Top_ltrk_region1_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_region1_SR"));
    TH1D *h_Top_ltrk_region2_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_region2_SR"));
    TH1D *h_Top_ltrk_region3_SR = ((TH1D *)Topfile->Get("h_Top_ltrk_region3_SR"));
    TH1D *h_Top_htrk_region1_SR = ((TH1D *)Topfile->Get("h_Top_htrk_region1_SR"));
    TH1D *h_Top_htrk_region2_SR = ((TH1D *)Topfile->Get("h_Top_htrk_region2_SR"));
    TH1D *h_Top_htrk_region3_SR = ((TH1D *)Topfile->Get("h_Top_htrk_region3_SR"));

    h_Top_trk_bybin_CR->SetLineWidth(2);
    h_Top_btrk_bybin_CR->SetLineWidth(2);
    h_Top_ctrk_bybin_CR->SetLineWidth(2);
    h_Top_ltrk_bybin_CR->SetLineWidth(2);
    h_Top_htrk_bybin_CR->SetLineWidth(2);
    h_Top_trk_SR->SetLineWidth(2);
    h_Top_btrk_SR->SetLineWidth(2);
    h_Top_ctrk_SR->SetLineWidth(2);
    h_Top_ltrk_SR->SetLineWidth(2);
    h_Top_htrk_SR->SetLineWidth(2);
    h_Top_trk_region1_bybin_CR->SetLineWidth(2);
    h_Top_trk_region2_bybin_CR->SetLineWidth(2);
    h_Top_trk_region3_bybin_CR->SetLineWidth(2);
    h_Top_btrk_region1_bybin_CR->SetLineWidth(2);
    h_Top_btrk_region2_bybin_CR->SetLineWidth(2);
    h_Top_btrk_region3_bybin_CR->SetLineWidth(2);
    h_Top_ctrk_region1_bybin_CR->SetLineWidth(2);
    h_Top_ctrk_region2_bybin_CR->SetLineWidth(2);
    h_Top_ctrk_region3_bybin_CR->SetLineWidth(2);
    h_Top_ltrk_region1_bybin_CR->SetLineWidth(2);
    h_Top_ltrk_region2_bybin_CR->SetLineWidth(2);
    h_Top_ltrk_region3_bybin_CR->SetLineWidth(2);
    h_Top_htrk_region1_bybin_CR->SetLineWidth(2);
    h_Top_htrk_region2_bybin_CR->SetLineWidth(2);
    h_Top_htrk_region3_bybin_CR->SetLineWidth(2);

    h_Top_trk_region1_SR->SetLineWidth(2);
    h_Top_trk_region2_SR->SetLineWidth(2);
    h_Top_trk_region3_SR->SetLineWidth(2);
    h_Top_btrk_region1_SR->SetLineWidth(2);
    h_Top_btrk_region2_SR->SetLineWidth(2);
    h_Top_btrk_region3_SR->SetLineWidth(2);
    h_Top_ctrk_region1_SR->SetLineWidth(2);
    h_Top_ctrk_region2_SR->SetLineWidth(2);
    h_Top_ctrk_region3_SR->SetLineWidth(2);
    h_Top_ltrk_region1_SR->SetLineWidth(2);
    h_Top_ltrk_region2_SR->SetLineWidth(2);
    h_Top_ltrk_region3_SR->SetLineWidth(2);
    h_Top_htrk_region1_SR->SetLineWidth(2);
    h_Top_htrk_region2_SR->SetLineWidth(2);
    h_Top_htrk_region3_SR->SetLineWidth(2);

    h_Top_btrk_SR->SetLineColor(kGreen + 3);
    h_Top_ctrk_SR->SetLineColor(kGreen + 3);
    h_Top_ltrk_SR->SetLineColor(kGreen + 3);

    h_Top_btrk_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_ctrk_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_ltrk_bybin_CR->GetXaxis()->SetTitle("nTrk");

    h_Top_btrk_bybin_CR->GetYaxis()->SetTitle("fake rate");
    h_Top_ctrk_bybin_CR->GetYaxis()->SetTitle("fake rate");
    h_Top_ltrk_bybin_CR->GetYaxis()->SetTitle("fake rate");

    auto c1 = new TCanvas("c1", "");
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

    gStyle->SetOptStat(0);
}