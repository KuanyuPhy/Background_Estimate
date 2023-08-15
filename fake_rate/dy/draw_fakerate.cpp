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

    TFile *Topemu_all_file = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_all_fakerate.root");
    TFile *Topee_all_file = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top/top_ee_all_fakerate.root");
    TFile *DY_all_file = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/dy/DY_fakerate.root");

    TH1D *Topee_all_nTrk_fakeRate_lowDilepPt = Topee_all_file->Get<TH1D>("Top_nTrk_fakeRate_lowDilepPt");
    TH1D *Topee_all_nTrk_fakeRate_highDilepPt = Topee_all_file->Get<TH1D>("Top_nTrk_fakeRate_highDilepPt");

    TH1D *Topemu_all_nTrk_fakeRate_lowDilepPt = Topemu_all_file->Get<TH1D>("Top_nTrk_fakeRate_lowDilepPt");
    TH1D *Topemu_all_nTrk_fakeRate_highDilepPt = Topemu_all_file->Get<TH1D>("Top_nTrk_fakeRate_highDilepPt");
    TH1D *Topemu_all_nTrk_bfakeRate_highDilepPt = Topemu_all_file->Get<TH1D>("Top_nTrk_bfakeRate_highDilepPt");
    TH1D *Topemu_all_nTrk_lfakeRate_highDilepPt = Topemu_all_file->Get<TH1D>("Top_nTrk_lfakeRate_highDilepPt");

    TH1D *DY_all_nTrk_fakeRate_lowDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_fakeRate_lowDilepPt");
    TH1D *DY_all_nTrk_fakeRate_highDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_fakeRate_highDilepPt");

    /*Single flavor*/
    TH1D *DY_all_nTrk_bfakeRate_lowDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_bfakeRate_lowDilepPt");
    TH1D *DY_all_nTrk_bfakeRate_highDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_bfakeRate_highDilepPt");
    TH1D *DY_all_nTrk_lfakeRate_lowDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_lfakeRate_lowDilepPt");
    TH1D *DY_all_nTrk_lfakeRate_highDilepPt = DY_all_file->Get<TH1D>("DY_nTrk_lfakeRate_highDilepPt");

    Topemu_all_nTrk_fakeRate_lowDilepPt->SetLineWidth(2);
    Topemu_all_nTrk_fakeRate_highDilepPt->SetLineWidth(2);
    Topemu_all_nTrk_bfakeRate_highDilepPt->SetLineWidth(2);
    Topemu_all_nTrk_lfakeRate_highDilepPt->SetLineWidth(2);
    Topee_all_nTrk_fakeRate_lowDilepPt->SetLineWidth(2);
    Topee_all_nTrk_fakeRate_highDilepPt->SetLineWidth(2);

    DY_all_nTrk_fakeRate_lowDilepPt->SetLineWidth(2);
    DY_all_nTrk_fakeRate_highDilepPt->SetLineWidth(2);
    DY_all_nTrk_bfakeRate_lowDilepPt->SetLineWidth(2);
    DY_all_nTrk_bfakeRate_highDilepPt->SetLineWidth(2);
    DY_all_nTrk_lfakeRate_lowDilepPt->SetLineWidth(2);
    DY_all_nTrk_lfakeRate_highDilepPt->SetLineWidth(2);

    Topemu_all_nTrk_fakeRate_lowDilepPt->SetLineColor(kRed);
    Topemu_all_nTrk_fakeRate_highDilepPt->SetLineColor(kRed);
    Topemu_all_nTrk_fakeRate_highDilepPt->SetMarkerColor(kRed);

    DY_all_nTrk_fakeRate_highDilepPt->SetLineColor(kRed);
    DY_all_nTrk_fakeRate_highDilepPt->SetMarkerColor(kRed);

    DY_all_nTrk_bfakeRate_highDilepPt->SetLineColor(kGray + 2);
    DY_all_nTrk_bfakeRate_highDilepPt->SetMarkerColor(kGray + 2);

    Topemu_all_nTrk_bfakeRate_highDilepPt->SetLineColor(kGray + 2);
    Topemu_all_nTrk_bfakeRate_highDilepPt->SetMarkerColor(kGray + 2);

    DY_all_nTrk_fakeRate_highDilepPt->SetMarkerStyle(23);
    DY_all_nTrk_bfakeRate_highDilepPt->SetMarkerStyle(21);

    Topemu_all_nTrk_fakeRate_highDilepPt->SetMarkerStyle(23);
    Topemu_all_nTrk_bfakeRate_highDilepPt->SetMarkerStyle(21);

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

    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitle("");
    DY_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitle("nJets");
    DY_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.06);
    DY_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetLabelSize(0.06);
    DY_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleOffset(1.1);

    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.06);
    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelSize(0.05);
    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelOffset(0.1);
    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleOffset(1);

    Topemu_all_nTrk_fakeRate_highDilepPt->SetLineColor(kBlue);
    Topemu_all_nTrk_fakeRate_highDilepPt->SetMarkerColor(kBlue);
    Topemu_all_nTrk_fakeRate_highDilepPt->SetMarkerStyle(21);


    DY_all_nTrk_fakeRate_highDilepPt->Draw("EP");
    Topemu_all_nTrk_fakeRate_highDilepPt->Draw("same");

    auto l0 = new TLegend(0.62, 0.70, 0.92, 0.88);
    l0->SetHeader("All Jet");
    l0->SetTextFont(42);
    l0->SetTextSize(0.04);
    l0->SetFillColor(0);
    l0->SetLineColor(0);
    l0->AddEntry(DY_all_nTrk_fakeRate_highDilepPt, "Drell-Yan process", "Elp");
    l0->AddEntry(Topemu_all_nTrk_fakeRate_highDilepPt, "Top to e#mu process", "Elp");
    l0->Draw("same");

    CMS_lumi(pad1, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");

    gPad->SetLogy();

    // lower plot will be in pad
    c1->cd(); // Go back to the main canvas before defining pad2
    auto pad2 = new TPad("pad2", "", 0, 0, 1, 0.3);
    pad2->SetGridy();
    pad2->SetRightMargin(0.05);
    pad2->SetLeftMargin(0.13);
    pad2->SetTopMargin(0.06);
    pad2->SetBottomMargin(0.4);
    pad2->Draw();
    pad2->cd();

    TH1D *h_all_FR_ratio = (TH1D *)Topemu_all_nTrk_fakeRate_highDilepPt->Clone("h_all_FR_ratio");
    h_all_FR_ratio->Divide(DY_all_nTrk_fakeRate_highDilepPt);

    h_all_FR_ratio->SetTitle("");
    h_all_FR_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_all_FR_ratio->GetYaxis()->SetTitle("Top(e#mu)/Drell-Yan");
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
    
    /*
    auto canv = new TCanvas("c", "c", 800, 800);
    canv->cd();
    canv->SetRightMargin(0.08);
    canv->SetBottomMargin(0.12);
    canv->SetTopMargin(0.07);
    canv->SetLeftMargin(0.12);

    auto pad1 = new TPad("pad1", " ", 0, 0.3, 1, 1.0);
    pad1->SetTopMargin(0.08);
    pad1->SetRightMargin(0.05);
    pad1->SetLeftMargin(0.13);
    pad1->SetBottomMargin(0.03);
    pad1->Draw();
    pad1->cd();

    DY_all_nTrk_bfakeRate_highDilepPt->GetXaxis()->SetTitle("");
    DY_all_nTrk_bfakeRate_highDilepPt->GetYaxis()->SetTitle("Fake rate");
    DY_all_nTrk_bfakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.06);
    DY_all_nTrk_bfakeRate_highDilepPt->GetYaxis()->SetLabelSize(0.06);
    DY_all_nTrk_bfakeRate_highDilepPt->GetYaxis()->SetTitleOffset(1.1);

    DY_all_nTrk_bfakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.06);
    DY_all_nTrk_bfakeRate_highDilepPt->GetXaxis()->SetLabelSize(0.05);
    DY_all_nTrk_bfakeRate_highDilepPt->GetXaxis()->SetLabelOffset(0.1);
    DY_all_nTrk_bfakeRate_highDilepPt->GetXaxis()->SetTitleOffset(1);

    DY_all_nTrk_bfakeRate_highDilepPt->SetLineColor(kRed);
    DY_all_nTrk_bfakeRate_highDilepPt->SetMarkerColor(kRed);

    Topemu_all_nTrk_bfakeRate_highDilepPt->SetLineColor(kBlue);
    Topemu_all_nTrk_bfakeRate_highDilepPt->SetMarkerSize();
    Topemu_all_nTrk_bfakeRate_highDilepPt->SetMarkerColor(kBlue);

    DY_all_nTrk_bfakeRate_highDilepPt->Draw("EP");
    Topemu_all_nTrk_bfakeRate_highDilepPt->Draw("same");
    // DY_all_nTrk_bfakeRate_highDilepPt->Draw("same");
    // DY_all_nTrk_lfakeRate_highDilepPt->Draw("same");

    auto l0 = new TLegend(0.62, 0.70, 0.92, 0.88);
    l0->SetHeader("b Jet");
    l0->SetTextFont(42);
    l0->SetTextSize(0.04);
    l0->SetFillColor(0);
    l0->SetLineColor(0);
    l0->AddEntry(DY_all_nTrk_bfakeRate_highDilepPt, "Drell-Yan process", "Elp");
    l0->AddEntry(Topemu_all_nTrk_bfakeRate_highDilepPt, "Top to e#mu process", "Elp");
    l0->Draw("same");

    CMS_lumi(pad1, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");

    gPad->SetLogy();

    // lower plot will be in pad
    canv->cd(); // Go back to the main canvas before defining pad2
    auto pad2 = new TPad("pad2", "", 0, 0, 1, 0.3);
    pad2->SetGridy();
    pad2->SetRightMargin(0.05);
    pad2->SetLeftMargin(0.13);
    pad2->SetTopMargin(0.06);
    pad2->SetBottomMargin(0.4);
    pad2->Draw();
    pad2->cd();

    TH1D *h_all_bFR_ratio = (TH1D *)Topemu_all_nTrk_bfakeRate_highDilepPt->Clone("h_all_FR_ratio");
    h_all_bFR_ratio->Divide(DY_all_nTrk_bfakeRate_highDilepPt);

    h_all_bFR_ratio->SetTitle("");
    h_all_bFR_ratio->GetXaxis()->SetTitle("Track multiplicity");
    h_all_bFR_ratio->GetYaxis()->SetTitle("Top(e#mu)/Drell-Yan");
    h_all_bFR_ratio->SetMarkerStyle(20);

    h_all_bFR_ratio->SetMarkerColor(TColor::GetColor("#202020"));
    h_all_bFR_ratio->SetMarkerSize(1.2);
    h_all_bFR_ratio->SetMarkerStyle(20);
    h_all_bFR_ratio->SetLineColor(TColor::GetColor("#202020"));
    h_all_bFR_ratio->SetLineWidth(2);

    h_all_bFR_ratio->GetXaxis()->SetTitleSize(0.16);
    h_all_bFR_ratio->GetXaxis()->SetTitleOffset(1.2);
    h_all_bFR_ratio->GetXaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_all_bFR_ratio->GetXaxis()->SetLabelOffset(0.05);
    h_all_bFR_ratio->GetYaxis()->SetTitleSize(0.13);
    h_all_bFR_ratio->GetYaxis()->SetTitleOffset(0.2 * (7 / 3.));
    h_all_bFR_ratio->GetYaxis()->SetLabelSize(0.06 * (7 / 3.));
    h_all_bFR_ratio->GetYaxis()->SetNdivisions(505);
    h_all_bFR_ratio->GetYaxis()->SetRangeUser(0.5, 1.5);
    h_all_bFR_ratio->Draw("ep");
    */
    /*
    auto canv = new TCanvas("c", "c", 800, 700);
    canv->cd();
    canv->SetRightMargin(0.08);
    canv->SetBottomMargin(0.12);
    canv->SetTopMargin(0.07);
    canv->SetLeftMargin(0.12);
    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.045);
    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelSize(0.045);
    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelOffset(0.02);
    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleOffset(1.3);
    DY_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.045);
    DY_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetLabelSize(0.045);
    DY_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleOffset(1.4);

    DY_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitle("Fake rate");
    DY_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitle("Track multiplicity");

    DY_all_nTrk_fakeRate_highDilepPt->Draw();
    DY_all_nTrk_bfakeRate_highDilepPt->Draw("same");
    DY_all_nTrk_lfakeRate_highDilepPt->Draw("same");

    TLegend *l0 = new TLegend(0.55, 0.6, 0.80, 0.90);
    l0->SetHeader("Drell-Yan process");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(DY_all_nTrk_fakeRate_highDilepPt, "all Jet", "Elp");
    l0->AddEntry(DY_all_nTrk_bfakeRate_highDilepPt, "True b Jet", "Elp");
    l0->AddEntry(DY_all_nTrk_lfakeRate_highDilepPt, "True Light Jet", "Elp");
    l0->Draw();
    */
    /*
    Topemu_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleSize(0.045);
    Topemu_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelSize(0.045);
    Topemu_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetLabelOffset(0.02);
    Topemu_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitleOffset(1.3);
    Topemu_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleSize(0.045);
    Topemu_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetLabelSize(0.045);
    Topemu_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitleOffset(1.4);

    Topemu_all_nTrk_fakeRate_highDilepPt->GetYaxis()->SetTitle("Fake rate");
    Topemu_all_nTrk_fakeRate_highDilepPt->GetXaxis()->SetTitle("Track multiplicity");

    Topemu_all_nTrk_fakeRate_highDilepPt->Draw();
    Topemu_all_nTrk_bfakeRate_highDilepPt->Draw("same");
    Topemu_all_nTrk_lfakeRate_highDilepPt->Draw("same");

    TLegend *l0 = new TLegend(0.55, 0.6, 0.80, 0.90);
    l0->SetHeader("Top to e#mu process");
    l0->SetTextSize(0.04);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(Topemu_all_nTrk_fakeRate_highDilepPt, "all Jet", "Elp");
    l0->AddEntry(Topemu_all_nTrk_bfakeRate_highDilepPt, "True b Jet", "Elp");
    l0->AddEntry(Topemu_all_nTrk_lfakeRate_highDilepPt, "True Light Jet", "Elp");
    l0->Draw();
    */

    gPad->SetLogy();

    //CMS_lumi((TPad *)canv, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");
}