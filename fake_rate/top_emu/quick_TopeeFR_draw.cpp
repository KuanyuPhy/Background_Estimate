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
void quick_TopeeFR_draw(TString file = "./Ratio_apply.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *h_Top_btrk_LMet = ((TH1D *)Topfile->Get("h_Top_btrk_LMet"));
    TH1D *h_Top_ltrk_LMet = ((TH1D *)Topfile->Get("h_Top_ltrk_LMet"));
    TH1D *h_Top_bJetPt_LMet = ((TH1D *)Topfile->Get("h_Top_bJetPt_LMet"));
    TH1D *h_Top_lJetPt_LMet = ((TH1D *)Topfile->Get("h_Top_lJetPt_LMet"));
    TH1D *h_Top_bJetEta_noeta_LMet = ((TH1D *)Topfile->Get("h_Top_bJetEta_noeta_LMet"));
    TH1D *h_Top_lJetEta_noeta_LMet = ((TH1D *)Topfile->Get("h_Top_lJetEta_noeta_LMet"));
    TH1D *h_Topee_btrk_HMet = ((TH1D *)Topfile->Get("h_Topee_btrk_HMet"));
    TH1D *h_Topee_ltrk_HMet = ((TH1D *)Topfile->Get("h_Topee_ltrk_HMet"));
    TH1D *h_Topee_bJetPt_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetPt_HMet"));
    TH1D *h_Topee_lJetPt_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetPt_HMet"));
    TH1D *h_Topee_bJetEta_noeta_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetEta_noeta_HMet"));
    TH1D *h_Topee_lJetEta_noeta_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetEta_noeta_HMet"));
    TH1D *h_Topemu_btrk_HMet = ((TH1D *)Topfile->Get("h_Topemu_btrk_HMet"));
    TH1D *h_Topemu_ltrk_HMet = ((TH1D *)Topfile->Get("h_Topemu_ltrk_HMet"));
    TH1D *h_Topemu_bJetPt_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetPt_HMet"));
    TH1D *h_Topemu_lJetPt_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetPt_HMet"));
    TH1D *h_Topemu_bJetEta_noeta_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetEta_noeta_HMet"));
    TH1D *h_Topemu_lJetEta_noeta_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetEta_noeta_HMet"));

    TH1D *h_Top_btrk_region1_LMet = ((TH1D *)Topfile->Get("h_Top_btrk_region1_LMet"));
    TH1D *h_Top_btrk_region2_LMet = ((TH1D *)Topfile->Get("h_Top_btrk_region2_LMet"));
    TH1D *h_Top_btrk_region3_LMet = ((TH1D *)Topfile->Get("h_Top_btrk_region3_LMet"));
    TH1D *h_Top_ltrk_region1_LMet = ((TH1D *)Topfile->Get("h_Top_ltrk_region1_LMet"));
    TH1D *h_Top_ltrk_region2_LMet = ((TH1D *)Topfile->Get("h_Top_ltrk_region2_LMet"));
    TH1D *h_Top_ltrk_region3_LMet = ((TH1D *)Topfile->Get("h_Top_ltrk_region3_LMet"));
    TH1D *h_Topee_btrk_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_btrk_region1_HMet"));
    TH1D *h_Topee_btrk_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_btrk_region2_HMet"));
    TH1D *h_Topee_btrk_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_btrk_region3_HMet"));
    TH1D *h_Topee_ltrk_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_ltrk_region1_HMet"));
    TH1D *h_Topee_ltrk_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_ltrk_region2_HMet"));
    TH1D *h_Topee_ltrk_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_ltrk_region3_HMet"));
    TH1D *h_Topemu_btrk_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_btrk_region1_HMet"));
    TH1D *h_Topemu_btrk_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_btrk_region2_HMet"));
    TH1D *h_Topemu_btrk_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_btrk_region3_HMet"));
    TH1D *h_Topemu_ltrk_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_ltrk_region1_HMet"));
    TH1D *h_Topemu_ltrk_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_ltrk_region2_HMet"));
    TH1D *h_Topemu_ltrk_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_ltrk_region3_HMet"));
    TH1D *h_Top_bJetPt_region1_LMet = ((TH1D *)Topfile->Get("h_Top_bJetPt_region1_LMet"));
    TH1D *h_Top_bJetPt_region2_LMet = ((TH1D *)Topfile->Get("h_Top_bJetPt_region2_LMet"));
    TH1D *h_Top_bJetPt_region3_LMet = ((TH1D *)Topfile->Get("h_Top_bJetPt_region3_LMet"));
    TH1D *h_Top_lJetPt_region1_LMet = ((TH1D *)Topfile->Get("h_Top_lJetPt_region1_LMet"));

    TH1D *h_Top_lJetPt_region2_LMet = ((TH1D *)Topfile->Get("h_Top_lJetPt_region2_LMet"));
    TH1D *h_Top_lJetPt_region3_LMet = ((TH1D *)Topfile->Get("h_Top_lJetPt_region3_LMet"));
    TH1D *h_Topee_bJetPt_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetPt_region1_HMet"));
    TH1D *h_Topee_bJetPt_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetPt_region2_HMet"));
    TH1D *h_Topee_bJetPt_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetPt_region3_HMet"));
    TH1D *h_Topee_lJetPt_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetPt_region1_HMet"));
    TH1D *h_Topee_lJetPt_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetPt_region2_HMet"));
    TH1D *h_Topee_lJetPt_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetPt_region3_HMet"));

    TH1D *h_Topemu_bJetPt_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetPt_region1_HMet"));
    TH1D *h_Topemu_bJetPt_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetPt_region2_HMet"));
    TH1D *h_Topemu_bJetPt_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetPt_region3_HMet"));
    TH1D *h_Topemu_lJetPt_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetPt_region1_HMet"));
    TH1D *h_Topemu_lJetPt_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetPt_region2_HMet"));
    TH1D *h_Topemu_lJetPt_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetPt_region3_HMet"));

    TH1D *h_Top_bJetEta_LMet = ((TH1D *)Topfile->Get("h_Top_bJetEta_LMet"));
    TH1D *h_Top_lJetEta_LMet = ((TH1D *)Topfile->Get("h_Top_lJetEta_LMet"));
    TH1D *h_Topee_bJetEta_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetEta_HMet"));
    TH1D *h_Topee_lJetEta_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetEta_HMet"));
    TH1D *h_Topemu_bJetEta_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetEta_HMet"));
    TH1D *h_Topemu_lJetEta_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetEta_HMet"));

    h_Top_btrk_LMet->SetLineWidth(2);
    h_Top_ltrk_LMet->SetLineWidth(2);
    h_Top_bJetPt_LMet->SetLineWidth(2);
    h_Top_lJetPt_LMet->SetLineWidth(2);
    h_Top_bJetEta_noeta_LMet->SetLineWidth(2);
    h_Top_lJetEta_noeta_LMet->SetLineWidth(2);
    h_Topee_btrk_HMet->SetLineWidth(2);
    h_Topee_ltrk_HMet->SetLineWidth(2);
    h_Topee_bJetPt_HMet->SetLineWidth(2);
    h_Topee_lJetPt_HMet->SetLineWidth(2);
    h_Topee_bJetEta_noeta_HMet->SetLineWidth(2);
    h_Topee_lJetEta_noeta_HMet->SetLineWidth(2);
    h_Topemu_btrk_HMet->SetLineWidth(2);
    h_Topemu_ltrk_HMet->SetLineWidth(2);
    h_Topemu_bJetPt_HMet->SetLineWidth(2);
    h_Topemu_lJetPt_HMet->SetLineWidth(2);
    h_Topemu_bJetEta_noeta_HMet->SetLineWidth(2);
    h_Topemu_lJetEta_noeta_HMet->SetLineWidth(2);

    h_Top_btrk_region1_LMet->SetLineWidth(2);
    h_Top_btrk_region2_LMet->SetLineWidth(2);
    h_Top_btrk_region3_LMet->SetLineWidth(2);
    h_Top_ltrk_region1_LMet->SetLineWidth(2);
    h_Top_ltrk_region2_LMet->SetLineWidth(2);
    h_Top_ltrk_region3_LMet->SetLineWidth(2);
    h_Topee_btrk_region1_HMet->SetLineWidth(2);
    h_Topee_btrk_region2_HMet->SetLineWidth(2);
    h_Topee_btrk_region3_HMet->SetLineWidth(2);
    h_Topee_ltrk_region1_HMet->SetLineWidth(2);
    h_Topee_ltrk_region2_HMet->SetLineWidth(2);
    h_Topee_ltrk_region3_HMet->SetLineWidth(2);
    h_Top_bJetPt_region1_LMet->SetLineWidth(2);
    h_Top_bJetPt_region2_LMet->SetLineWidth(2);
    h_Top_bJetPt_region3_LMet->SetLineWidth(2);
    h_Top_lJetPt_region1_LMet->SetLineWidth(2);
    h_Top_lJetPt_region2_LMet->SetLineWidth(2);
    h_Top_lJetPt_region3_LMet->SetLineWidth(2);
    h_Topee_bJetPt_region1_HMet->SetLineWidth(2);
    h_Topee_bJetPt_region2_HMet->SetLineWidth(2);
    h_Topee_bJetPt_region3_HMet->SetLineWidth(2);
    h_Topee_lJetPt_region1_HMet->SetLineWidth(2);
    h_Topee_lJetPt_region2_HMet->SetLineWidth(2);
    h_Topee_lJetPt_region3_HMet->SetLineWidth(2);
    h_Top_bJetEta_LMet->SetLineWidth(2);
    h_Top_lJetEta_LMet->SetLineWidth(2);
    h_Topee_bJetEta_HMet->SetLineWidth(2);
    h_Topee_lJetEta_HMet->SetLineWidth(2);

    h_Topemu_btrk_region1_HMet->SetLineWidth(2);
    h_Topemu_btrk_region2_HMet->SetLineWidth(2);
    h_Topemu_btrk_region3_HMet->SetLineWidth(2);
    h_Topemu_ltrk_region1_HMet->SetLineWidth(2);
    h_Topemu_ltrk_region2_HMet->SetLineWidth(2);
    h_Topemu_ltrk_region3_HMet->SetLineWidth(2);
    h_Topemu_bJetPt_region1_HMet->SetLineWidth(2);
    h_Topemu_bJetPt_region2_HMet->SetLineWidth(2);
    h_Topemu_bJetPt_region3_HMet->SetLineWidth(2);
    h_Topemu_lJetPt_region1_HMet->SetLineWidth(2);
    h_Topemu_lJetPt_region2_HMet->SetLineWidth(2);
    h_Topemu_lJetPt_region3_HMet->SetLineWidth(2);
    h_Topemu_bJetEta_HMet->SetLineWidth(2);
    h_Topemu_lJetEta_HMet->SetLineWidth(2);

    h_Topee_btrk_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_btrk_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_btrk_region3_HMet->SetLineColor(kGreen + 3);
    h_Topee_ltrk_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_ltrk_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_ltrk_region3_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetPt_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetPt_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetPt_region3_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetPt_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetPt_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetPt_region3_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetEta_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetEta_HMet->SetLineColor(kGreen + 3);

    h_Topemu_btrk_HMet->SetLineColor(kOrange + 7);
    h_Topemu_ltrk_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetPt_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetPt_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetEta_noeta_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetEta_noeta_HMet->SetLineColor(kOrange + 7);

    h_Topemu_btrk_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_btrk_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_btrk_region3_HMet->SetLineColor(kOrange + 7);
    h_Topemu_ltrk_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_ltrk_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_ltrk_region3_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetPt_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetPt_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetPt_region3_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetPt_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetPt_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetPt_region3_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetEta_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetEta_HMet->SetLineColor(kOrange + 7);

    auto c1 = new TCanvas("c1", "");
    // c1->Divide(3, 1);
    // c1->Divide(2, 1);
    // c1->cd(1);

    /*
    h_Topee_btrk_region1_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_btrk_region1_HMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_btrk_region1_HMet->Draw();
    h_Topemu_btrk_region1_HMet->Draw("same");
    h_Top_btrk_region1_LMet->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->AddEntry(h_Top_btrk_region1_LMet, "HM cut alpha", "l");
    l0->AddEntry(h_Topee_btrk_region1_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_btrk_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_btrk_region2_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_region2_LMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Top_btrk_region2_LMet->Draw("h ");
    h_Topee_btrk_region2_HMet->Draw("same");
    h_Topemu_btrk_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->AddEntry(h_Top_btrk_region2_LMet, "HM cut alpha", "l");
    l1->AddEntry(h_Topee_btrk_region2_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_btrk_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    c1->cd(3);

    h_Topee_btrk_region3_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_btrk_region3_HMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_btrk_region3_HMet->Draw();
    h_Top_btrk_region3_LMet->Draw("h same");
    h_Topemu_btrk_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->AddEntry(h_Top_btrk_region3_LMet, "HM cut alpha", "l");
    l2->AddEntry(h_Topee_btrk_region3_HMet, "HM apply fakerate (Top ee)", "l");
    l2->AddEntry(h_Topemu_btrk_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();

    */

    /*
    h_Topee_ltrk_region1_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_ltrk_region1_HMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_ltrk_region1_HMet->Draw();
    h_Topemu_ltrk_region1_HMet->Draw("same");
    h_Top_ltrk_region1_LMet->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->AddEntry(h_Top_ltrk_region1_LMet, "HM cut alpha", "l");
    l0->AddEntry(h_Topee_ltrk_region1_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_ltrk_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_ltrk_region2_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_region2_LMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Top_ltrk_region2_LMet->Draw("h ");
    h_Topee_ltrk_region2_HMet->Draw("same");
    h_Topemu_ltrk_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->AddEntry(h_Top_ltrk_region2_LMet, "HM cut alpha", "l");
    l1->AddEntry(h_Topee_ltrk_region2_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_ltrk_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    c1->cd(3);

    h_Topee_ltrk_region3_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_ltrk_region3_HMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_ltrk_region3_HMet->Draw();
    h_Top_ltrk_region3_LMet->Draw("h same");
    h_Topemu_ltrk_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->AddEntry(h_Top_ltrk_region3_LMet, "HM cut alpha", "l");
    l2->AddEntry(h_Topee_ltrk_region3_HMet, "HM apply fakerate (Top ee)", "l");
    l2->AddEntry(h_Topemu_ltrk_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();

    */
    /*
    h_Topee_bJetPt_region1_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_bJetPt_region1_HMet->GetXaxis()->SetTitle("Jet PT");

    h_Topee_bJetPt_region1_HMet->Draw();
    h_Topemu_bJetPt_region1_HMet->Draw("same");
    h_Top_bJetPt_region1_LMet->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->AddEntry(h_Top_bJetPt_region1_LMet, "HM cut alpha", "l");
    l0->AddEntry(h_Topee_bJetPt_region1_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_bJetPt_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Topee_bJetPt_region2_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_bJetPt_region2_HMet->GetXaxis()->SetTitle("Jet PT");

    h_Topee_bJetPt_region2_HMet->Draw("");
    h_Top_bJetPt_region2_LMet->Draw("h same");

    h_Topemu_bJetPt_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->AddEntry(h_Top_bJetPt_region2_LMet, "HM cut alpha", "l");
    l1->AddEntry(h_Topee_bJetPt_region2_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_bJetPt_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    c1->cd(3);

    h_Topee_bJetPt_region3_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_bJetPt_region3_HMet->GetXaxis()->SetTitle("Jet PT");

    h_Topee_bJetPt_region3_HMet->Draw();
    h_Top_bJetPt_region3_LMet->Draw("h same");
    h_Topemu_bJetPt_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->AddEntry(h_Top_bJetPt_region3_LMet, "HM cut alpha", "l");
    l2->AddEntry(h_Topee_bJetPt_region3_HMet, "HM apply fakerate (Top ee)", "l");
    l2->AddEntry(h_Topemu_bJetPt_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();
    */

    /*
    h_Top_lJetPt_region1_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region1_LMet->GetXaxis()->SetTitle("Jet PT");

    h_Top_lJetPt_region1_LMet->Draw("h ");
    h_Topee_lJetPt_region1_HMet->Draw("same");
    h_Topemu_lJetPt_region1_HMet->Draw("same");


    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->AddEntry(h_Top_lJetPt_region1_LMet, "HM cut alpha", "l");
    l0->AddEntry(h_Topee_lJetPt_region1_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_lJetPt_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_lJetPt_region2_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region2_LMet->GetXaxis()->SetTitle("Jet PT");


    h_Top_lJetPt_region2_LMet->Draw("h ");
    h_Topee_lJetPt_region2_HMet->Draw("same");


    h_Topemu_lJetPt_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->AddEntry(h_Top_lJetPt_region2_LMet, "HM cut alpha", "l");
    l1->AddEntry(h_Topee_lJetPt_region2_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_lJetPt_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    c1->cd(3);

    h_Top_lJetPt_region3_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region3_LMet->GetXaxis()->SetTitle("Jet PT");

    h_Top_lJetPt_region3_LMet->Draw("h ");
    h_Topee_lJetPt_region3_HMet->Draw("same");

    h_Topemu_lJetPt_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->AddEntry(h_Top_lJetPt_region3_LMet, "HM cut alpha", "l");
    l2->AddEntry(h_Topee_lJetPt_region3_HMet, "HM apply fakerate (Top ee)", "l");
    l2->AddEntry(h_Topemu_lJetPt_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();
    */

    /*
    c1->cd(1);

    h_Top_bJetEta_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_bJetEta_LMet->GetXaxis()->SetTitle("Jet #eta");

    h_Top_bJetEta_LMet->Draw("h ");
    h_Topemu_bJetEta_HMet->Draw("same");
    h_Topee_bJetEta_HMet->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_bJetEta_LMet, "HM cut alpha", "l");
    l0->AddEntry(h_Topee_bJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_bJetEta_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_lJetEta_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_LMet->GetXaxis()->SetTitle("Jet #eta");

    h_Top_lJetEta_LMet->Draw("h ");
    h_Topemu_lJetEta_HMet->Draw("same");
    h_Topee_lJetEta_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetEta_LMet, "HM cut alpha", "l");
    l1->AddEntry(h_Topee_lJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_lJetEta_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    h_Top_btrk_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_LMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Top_btrk_LMet->Draw("h ");
    h_Topemu_btrk_HMet->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_btrk_LMet, "HM cut alpha", "l");
    //l0->AddEntry(h_Topee_bJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_btrk_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_ltrk_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_LMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Top_ltrk_LMet->Draw("h ");
    h_Topemu_ltrk_HMet->Draw("same");


    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetEta_LMet, "HM cut alpha", "l");
    //l1->AddEntry(h_Topee_lJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_ltrk_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    h_Topemu_bJetPt_HMet->GetYaxis()->SetTitle("nJet");
    h_Topemu_bJetPt_HMet->GetXaxis()->SetTitle("Jet PT");

    h_Topemu_bJetPt_HMet->Draw("");
    h_Top_bJetPt_LMet->Draw("h same");


    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_bJetPt_LMet, "HM cut alpha", "l");
    // l0->AddEntry(h_Topee_bJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_bJetPt_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_lJetPt_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_LMet->GetXaxis()->SetTitle("Jet PT");

    h_Top_lJetPt_LMet->Draw("h ");
    h_Topemu_lJetPt_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetPt_LMet, "HM cut alpha", "l");
    // l1->AddEntry(h_Topee_lJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_lJetPt_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    h_Topemu_bJetEta_noeta_HMet->GetYaxis()->SetTitle("nJet");
    h_Topemu_bJetEta_noeta_HMet->GetXaxis()->SetTitle("Jet #eta");

    h_Topemu_bJetEta_noeta_HMet->Draw("");
    h_Top_bJetEta_noeta_LMet->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_bJetEta_noeta_LMet, "HM cut alpha", "l");
    // l0->AddEntry(h_Topee_bJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_bJetEta_noeta_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_lJetEta_noeta_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_noeta_LMet->GetXaxis()->SetTitle("Jet #eta");

    h_Top_lJetEta_noeta_LMet->Draw("h ");
    h_Topemu_lJetEta_noeta_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetEta_noeta_LMet, "HM cut alpha", "l");
    // l1->AddEntry(h_Topee_lJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_lJetEta_noeta_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    */
    c1->Divide(2, 2);

    /*
    // Plot Ratio
    TH1F *h_cutalpha_applyfr_Ratio;
    h_cutalpha_applyfr_Ratio = (TH1F *)h_Top_bJetEta_noeta_LMet->Clone("h_cutalpha_applyfr_Ratio");
    h_cutalpha_applyfr_Ratio->Divide(h_Top_bJetEta_noeta_LMet, h_Topemu_bJetEta_noeta_HMet, 1, 1, "b");

    const double LABELSIZE = 20.0;
    c1->cd(1);

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Topemu_bJetEta_noeta_HMet->SetTitle("without consider eta");

    h_Topemu_bJetEta_noeta_HMet->GetYaxis()->SetTitle("nJet");
    h_Topemu_bJetEta_noeta_HMet->GetXaxis()->SetTitle("Jet #eta");
    h_Topemu_bJetEta_noeta_HMet->GetXaxis()->SetTitleSize(0);
    h_Topemu_bJetEta_noeta_HMet->GetXaxis()->SetLabelSize(0);

    h_Topemu_bJetEta_noeta_HMet->Draw("");
    h_Top_bJetEta_noeta_LMet->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_bJetEta_noeta_LMet, "HM cut alpha", "l");
    l0->AddEntry(h_Topemu_bJetEta_noeta_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(3);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_cutalpha_applyfr_Ratio->GetYaxis()->SetTitle("cut alpha / apply FR");
    h_cutalpha_applyfr_Ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cutalpha_applyfr_Ratio->Draw("e1");

    c1->cd(2);
    TH1F *h_cutalpha_applyfr_diffeta_Ratio;
    h_cutalpha_applyfr_diffeta_Ratio = (TH1F *)h_Top_bJetEta_LMet->Clone("h_cutalpha_applyfr_diffeta_Ratio");
    h_cutalpha_applyfr_diffeta_Ratio->Divide(h_Top_bJetEta_LMet, h_Topemu_bJetEta_HMet, 1, 1, "b");

    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);


    h_Top_bJetEta_LMet->SetTitle("consider eta");

    h_Top_bJetEta_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_bJetEta_LMet->GetXaxis()->SetTitle("Jet #eta");
    h_Top_bJetEta_LMet->GetXaxis()->SetTitleSize(0);
    h_Top_bJetEta_LMet->GetXaxis()->SetLabelSize(0);

    h_Top_bJetEta_LMet->Draw("h ");
    h_Topemu_bJetEta_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("b flavor");
    l1->AddEntry(h_Top_bJetEta_LMet, "HM cut alpha", "l");
    l1->AddEntry(h_Topemu_bJetEta_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    c1->cd(4);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_cutalpha_applyfr_diffeta_Ratio->GetYaxis()->SetTitle("cut alpha / apply FR");
    h_cutalpha_applyfr_diffeta_Ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cutalpha_applyfr_diffeta_Ratio->Draw("e1");

    */
// Plot Ratio
    TH1F *h_cutalpha_applyfr_Ratio;
    h_cutalpha_applyfr_Ratio = (TH1F *)h_Top_lJetEta_noeta_LMet->Clone("h_cutalpha_applyfr_Ratio");
    h_cutalpha_applyfr_Ratio->Divide(h_Top_lJetEta_noeta_LMet, h_Topemu_lJetEta_noeta_HMet, 1, 1, "b");

    const double LABELSIZE = 20.0;
    c1->cd(1);

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_lJetEta_noeta_LMet->SetTitle("without consider eta");

    h_Top_lJetEta_noeta_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_noeta_LMet->GetXaxis()->SetTitle("Jet #eta");
    h_Top_lJetEta_noeta_LMet->GetXaxis()->SetTitleSize(0);
    h_Top_lJetEta_noeta_LMet->GetXaxis()->SetLabelSize(0); 

    h_Top_lJetEta_noeta_LMet->Draw("h ");
    h_Topemu_lJetEta_noeta_HMet->Draw("same");
    

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("light flavor");
    l0->AddEntry(h_Top_lJetEta_noeta_LMet, "HM cut alpha", "l");
    l0->AddEntry(h_Topemu_lJetEta_noeta_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(3);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_cutalpha_applyfr_Ratio->GetYaxis()->SetTitle("cut alpha / apply FR");
    h_cutalpha_applyfr_Ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cutalpha_applyfr_Ratio->Draw("e1");

    c1->cd(2);
    TH1F *h_cutalpha_applyfr_diffeta_Ratio;
    h_cutalpha_applyfr_diffeta_Ratio = (TH1F *)h_Top_lJetEta_LMet->Clone("h_cutalpha_applyfr_diffeta_Ratio");
    h_cutalpha_applyfr_diffeta_Ratio->Divide(h_Top_lJetEta_LMet, h_Topemu_lJetEta_HMet, 1, 1, "b");

    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);


    h_Top_lJetEta_LMet->SetTitle("consider eta");

    h_Top_lJetEta_LMet->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_LMet->GetXaxis()->SetTitle("Jet #eta");
    h_Top_lJetEta_LMet->GetXaxis()->SetTitleSize(0);
    h_Top_lJetEta_LMet->GetXaxis()->SetLabelSize(0);

    h_Top_lJetEta_LMet->Draw("h ");
    h_Topemu_lJetEta_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetEta_LMet, "HM cut alpha", "l");
    l1->AddEntry(h_Topemu_lJetEta_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    c1->cd(4);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_cutalpha_applyfr_diffeta_Ratio->GetYaxis()->SetTitle("cut alpha / apply FR");
    h_cutalpha_applyfr_diffeta_Ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cutalpha_applyfr_diffeta_Ratio->Draw("e1");
    gStyle->SetOptStat(0);
}