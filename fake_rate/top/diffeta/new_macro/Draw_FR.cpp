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
#include <TH2.h>
#include "TLegend.h"
#include <cstring>
void Draw_FR(TString file = "./top_fakerate.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *Top_nTrk_bfakeRate_difeta_lowMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_1"));
    TH1D *Top_nTrk_cfakeRate_difeta_lowMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_lowMET_1"));
    TH1D *Top_nTrk_lfakeRate_difeta_lowMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_1"));

    TH1D *Top_nTrk_bfakeRate_difeta_lowMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_2"));
    TH1D *Top_nTrk_cfakeRate_difeta_lowMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_lowMET_2"));
    TH1D *Top_nTrk_lfakeRate_difeta_lowMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_2"));

    TH1D *Top_nTrk_bfakeRate_difeta_lowMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_3"));
    TH1D *Top_nTrk_cfakeRate_difeta_lowMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_lowMET_3"));
    TH1D *Top_nTrk_lfakeRate_difeta_lowMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_3"));

    TH1D *Top_nTrk_bfakeRate_difeta_midMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_midMET_1"));
    TH1D *Top_nTrk_cfakeRate_difeta_midMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_midMET_1"));
    TH1D *Top_nTrk_lfakeRate_difeta_midMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_midMET_1"));

    TH1D *Top_nTrk_bfakeRate_difeta_midMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_midMET_2"));
    TH1D *Top_nTrk_cfakeRate_difeta_midMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_midMET_2"));
    TH1D *Top_nTrk_lfakeRate_difeta_midMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_midMET_2"));

    TH1D *Top_nTrk_bfakeRate_difeta_midMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_midMET_3"));
    TH1D *Top_nTrk_cfakeRate_difeta_midMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_midMET_3"));
    TH1D *Top_nTrk_lfakeRate_difeta_midMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_midMET_3"));

    TH1D *Top_nTrk_bfakeRate_difeta_highMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_highMET_1"));
    TH1D *Top_nTrk_cfakeRate_difeta_highMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_highMET_1"));
    TH1D *Top_nTrk_lfakeRate_difeta_highMET_1 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_highMET_1"));

    TH1D *Top_nTrk_bfakeRate_difeta_highMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_highMET_2"));
    TH1D *Top_nTrk_cfakeRate_difeta_highMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_highMET_2"));
    TH1D *Top_nTrk_lfakeRate_difeta_highMET_2 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_highMET_2"));

    TH1D *Top_nTrk_bfakeRate_difeta_highMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_highMET_3"));
    TH1D *Top_nTrk_cfakeRate_difeta_highMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_highMET_3"));
    TH1D *Top_nTrk_lfakeRate_difeta_highMET_3 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_highMET_3"));

    Top_nTrk_bfakeRate_difeta_lowMET_1->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_lowMET_1->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_lowMET_1->SetLineWidth(2);

    Top_nTrk_bfakeRate_difeta_lowMET_2->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_lowMET_2->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_lowMET_2->SetLineWidth(2);

    Top_nTrk_bfakeRate_difeta_lowMET_3->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_lowMET_3->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_lowMET_3->SetLineWidth(2);

    Top_nTrk_bfakeRate_difeta_midMET_1->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_midMET_1->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_midMET_1->SetLineWidth(2);

    Top_nTrk_bfakeRate_difeta_midMET_2->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_midMET_2->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_midMET_2->SetLineWidth(2);

    Top_nTrk_bfakeRate_difeta_midMET_3->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_midMET_3->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_midMET_3->SetLineWidth(2);

    Top_nTrk_bfakeRate_difeta_highMET_1->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_highMET_1->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_highMET_1->SetLineWidth(2);

    Top_nTrk_bfakeRate_difeta_highMET_2->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_highMET_2->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_highMET_2->SetLineWidth(2);

    Top_nTrk_bfakeRate_difeta_highMET_3->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_highMET_3->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_highMET_3->SetLineWidth(2);

    Top_nTrk_bfakeRate_difeta_midMET_1->SetLineColor(kGreen + 3);
    Top_nTrk_cfakeRate_difeta_midMET_1->SetLineColor(kGreen + 3);
    Top_nTrk_lfakeRate_difeta_midMET_1->SetLineColor(kGreen + 3);

    Top_nTrk_bfakeRate_difeta_midMET_2->SetLineColor(kGreen + 3);
    Top_nTrk_cfakeRate_difeta_midMET_2->SetLineColor(kGreen + 3);
    Top_nTrk_lfakeRate_difeta_midMET_2->SetLineColor(kGreen + 3);

    Top_nTrk_bfakeRate_difeta_midMET_3->SetLineColor(kGreen + 3);
    Top_nTrk_cfakeRate_difeta_midMET_3->SetLineColor(kGreen + 3);
    Top_nTrk_lfakeRate_difeta_midMET_3->SetLineColor(kGreen + 3);

    Top_nTrk_bfakeRate_difeta_highMET_1->SetLineColor(kRed);
    Top_nTrk_cfakeRate_difeta_highMET_1->SetLineColor(kRed);
    Top_nTrk_lfakeRate_difeta_highMET_1->SetLineColor(kRed);

    Top_nTrk_bfakeRate_difeta_highMET_2->SetLineColor(kRed);
    Top_nTrk_cfakeRate_difeta_highMET_2->SetLineColor(kRed);
    Top_nTrk_lfakeRate_difeta_highMET_2->SetLineColor(kRed);

    Top_nTrk_bfakeRate_difeta_highMET_3->SetLineColor(kRed);
    Top_nTrk_cfakeRate_difeta_highMET_3->SetLineColor(kRed);
    Top_nTrk_lfakeRate_difeta_highMET_3->SetLineColor(kRed);

    Top_nTrk_bfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_cfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_lfakeRate_difeta_highMET_1->GetXaxis()->SetTitle("Track multiplicity");

    Top_nTrk_bfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_cfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_lfakeRate_difeta_highMET_2->GetXaxis()->SetTitle("Track multiplicity");

    Top_nTrk_bfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_cfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_lfakeRate_difeta_highMET_3->GetXaxis()->SetTitle("Track multiplicity");

    Top_nTrk_bfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_cfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_lfakeRate_difeta_highMET_1->GetYaxis()->SetTitle("fake rate");

    Top_nTrk_bfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_cfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_lfakeRate_difeta_highMET_2->GetYaxis()->SetTitle("fake rate");

    Top_nTrk_bfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_cfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_lfakeRate_difeta_highMET_3->GetYaxis()->SetTitle("fake rate");

    Top_nTrk_bfakeRate_difeta_lowMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_cfakeRate_difeta_lowMET_1->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_lfakeRate_difeta_lowMET_1->GetXaxis()->SetTitle("Track multiplicity");

    Top_nTrk_bfakeRate_difeta_lowMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_cfakeRate_difeta_lowMET_2->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_lfakeRate_difeta_lowMET_2->GetXaxis()->SetTitle("Track multiplicity");

    Top_nTrk_bfakeRate_difeta_lowMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_cfakeRate_difeta_lowMET_3->GetXaxis()->SetTitle("Track multiplicity");
    Top_nTrk_lfakeRate_difeta_lowMET_3->GetXaxis()->SetTitle("Track multiplicity");

    Top_nTrk_bfakeRate_difeta_lowMET_1->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_cfakeRate_difeta_lowMET_1->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_lfakeRate_difeta_lowMET_1->GetYaxis()->SetTitle("fake rate");

    Top_nTrk_bfakeRate_difeta_lowMET_2->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_cfakeRate_difeta_lowMET_2->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_lfakeRate_difeta_lowMET_2->GetYaxis()->SetTitle("fake rate");

    Top_nTrk_bfakeRate_difeta_lowMET_3->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_cfakeRate_difeta_lowMET_3->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_lfakeRate_difeta_lowMET_3->GetYaxis()->SetTitle("fake rate");

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
    /*
    c1->cd(1);
    Top_nTrk_bfakeRate_difeta_highMET_1->Draw();
    Top_nTrk_bfakeRate_difeta_lowMET_1->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(Top_nTrk_bfakeRate_difeta_highMET_1, "High MET", "El");
    l0->AddEntry(Top_nTrk_bfakeRate_difeta_lowMET_1, "Low MET", "El");
    l0->Draw();

    c1->cd(2);
    Top_nTrk_bfakeRate_difeta_highMET_2->Draw();
    Top_nTrk_bfakeRate_difeta_lowMET_2->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(Top_nTrk_bfakeRate_difeta_highMET_2, "High MET", "El");
    l1->AddEntry(Top_nTrk_bfakeRate_difeta_lowMET_2, "Low MET", "El");
    l1->Draw();

    c1->cd(3);
    Top_nTrk_bfakeRate_difeta_highMET_3->Draw();
    Top_nTrk_bfakeRate_difeta_lowMET_3->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(Top_nTrk_bfakeRate_difeta_highMET_2, "High MET", "El");
    l2->AddEntry(Top_nTrk_bfakeRate_difeta_lowMET_2, "Low MET", "El");
    l2->Draw();
    */

    c1->cd(1);
        Top_nTrk_lfakeRate_difeta_highMET_1->Draw("");
    Top_nTrk_lfakeRate_difeta_lowMET_1->Draw("same");
    Top_nTrk_lfakeRate_difeta_midMET_1->Draw("same");


    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(Top_nTrk_lfakeRate_difeta_highMET_1, "High MET", "El");
    l0->AddEntry(Top_nTrk_lfakeRate_difeta_midMET_1, "mid MET", "El");
    l0->AddEntry(Top_nTrk_lfakeRate_difeta_lowMET_1, "Low MET", "El");
    l0->Draw();

    c1->cd(2);
      Top_nTrk_lfakeRate_difeta_highMET_2->Draw("");
    Top_nTrk_lfakeRate_difeta_lowMET_2->Draw("same");
    Top_nTrk_lfakeRate_difeta_midMET_2->Draw("same");
  

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(Top_nTrk_lfakeRate_difeta_highMET_2, "High MET", "El");
    l1->AddEntry(Top_nTrk_lfakeRate_difeta_midMET_2, "mid MET", "El");
    l1->AddEntry(Top_nTrk_lfakeRate_difeta_lowMET_2, "Low MET", "El");
    l1->Draw();

    c1->cd(3);
    Top_nTrk_lfakeRate_difeta_highMET_3->Draw();
    Top_nTrk_lfakeRate_difeta_midMET_3->Draw("same");
    Top_nTrk_lfakeRate_difeta_lowMET_3->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(Top_nTrk_lfakeRate_difeta_highMET_3, "High MET", "El");
    l2->AddEntry(Top_nTrk_lfakeRate_difeta_midMET_3, "mid MET", "El");
    l2->AddEntry(Top_nTrk_lfakeRate_difeta_lowMET_3, "Low MET", "El");
    l2->Draw();

    gStyle->SetOptStat(0);
}