#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TLine.h>
#include <THStack.h>
#include "/home/kuanyu/Documents/CMS/Background_Estimate/lib/tdrstyle.C"
#include "/home/kuanyu/Documents/CMS/Background_Estimate/lib/CMS_lumi.h"
using namespace std;
void ee_btag(TString inputfile = "./top/ee_Top_Met.root")
{
    TFile *ee_Topprocess = TFile::Open(inputfile);
    TFile *ee_Sigfile = new TFile("./sig/ee_Sig_Met.root");
    TFile *ee_2017Signfile = new TFile("./sig/ee_Sig_Met_2017.root");

    TH1D *ee_Top_jetcsv = ((TH1D *)ee_Topprocess->Get("h_Top_jetcsv"));
    TH1D *ee_Sig1_jetcsv = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_jetcsv"));
    TH1D *ee_Sig50_jetcsv = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_jetcsv"));
    TH1D *ee_Sig150_jetcsv = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_jetcsv"));

    /*For 2017*/
    TH1D *ee_2017Sig1_jetCSVv2 = ((TH1D *)ee_2017Signfile->Get("h_Mx2_1_jetCSVv2"));
    TH1D *ee_2017Sig1_jetDeepCSV = ((TH1D *)ee_2017Signfile->Get("h_Mx2_1_jetDeepCSV"));

    TH1D *ee_Sig1_jetcsv_SR = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_jetcsv_SR"));
    TH1D *ee_Sig50_jetcsv_SR = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_jetcsv_SR"));
    TH1D *ee_Sig150_jetcsv_SR = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_jetcsv_SR"));

    TH1D *ee_Sig1_jetcsv_unweight = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_jetcsv_unweight"));
    TH1D *ee_Sig50_jetcsv_unweight = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_jetcsv_unweight"));
    TH1D *ee_Sig150_jetcsv_unweight = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_jetcsv_unweight"));

    ee_Top_jetcsv->SetLineColor(kGreen + 3);
    ee_Sig1_jetcsv->SetLineColor(kRed);
    ee_Sig50_jetcsv->SetLineColor(kGray + 2);
    ee_Sig150_jetcsv->SetLineColor(kBlue);

    ee_Sig1_jetcsv_SR->SetLineColor(kRed);
    ee_Sig50_jetcsv_SR->SetLineColor(kGray + 2);
    ee_Sig150_jetcsv_SR->SetLineColor(kBlue);

    ee_Sig1_jetcsv_unweight->SetLineColor(kRed);
    ee_Sig50_jetcsv_unweight->SetLineColor(kGray + 2);
    ee_Sig150_jetcsv_unweight->SetLineColor(kBlue);

    ee_2017Sig1_jetCSVv2->SetLineColor(kRed);
    ee_2017Sig1_jetDeepCSV->SetLineColor(kBlue);

    ee_Top_jetcsv->SetLineWidth(2);
    ee_Sig1_jetcsv->SetLineWidth(2);
    ee_Sig50_jetcsv->SetLineWidth(2);
    ee_Sig150_jetcsv->SetLineWidth(2);

    ee_Sig1_jetcsv_SR->SetLineWidth(2);
    ee_Sig50_jetcsv_SR->SetLineWidth(2);
    ee_Sig150_jetcsv_SR->SetLineWidth(2);

    ee_Sig1_jetcsv_unweight->SetLineWidth(2);
    ee_Sig50_jetcsv_unweight->SetLineWidth(2);
    ee_Sig150_jetcsv_unweight->SetLineWidth(2);

    ee_2017Sig1_jetCSVv2->SetLineWidth(2);
    ee_2017Sig1_jetDeepCSV->SetLineWidth(2);

    ee_Top_jetcsv->SetFillColor(kGreen + 3);

    setTDRStyle();

    TCanvas *canv = new TCanvas("canv", "canv", 800, 700);
    canv->cd();
    canv->SetRightMargin(0.08);
    canv->SetBottomMargin(0.12);
    canv->SetTopMargin(0.07);
    canv->SetLeftMargin(0.12);

    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);

    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetGridx();         // Vertical grid
    pad1->Draw();             // Draw the upper pad: pad1

    ee_Top_jetcsv->GetXaxis()->SetTitleSize(0.045);
    ee_Top_jetcsv->GetXaxis()->SetLabelSize(0.045);
    ee_Top_jetcsv->GetXaxis()->SetLabelOffset(0.02);
    ee_Top_jetcsv->GetXaxis()->SetTitleOffset(1.3);
    ee_Top_jetcsv->GetXaxis()->SetTitle("THINjetCISVv2");
    ee_Top_jetcsv->GetYaxis()->SetTitleSize(0.045);
    ee_Top_jetcsv->GetYaxis()->SetLabelSize(0.045);
    ee_Top_jetcsv->GetYaxis()->SetTitleOffset(1.4);
    // ee_Top_jetcsv->GetYaxis()->SetRangeUser(0, 0.5);
    ee_Top_jetcsv->GetYaxis()->SetTitle("nJets/ Normarlized");
    ee_Top_jetcsv->SetFillStyle(3001);

    /*
    ee_Top_jetcsv->DrawNormalized("he");
    ee_Sig1_jetcsv->DrawNormalized("he same");
    ee_Sig50_jetcsv->DrawNormalized("he same");
    ee_Sig150_jetcsv->DrawNormalized("he same");

    TLegend *l0 = new TLegend(0.5, 0.60, 0.92, 0.88);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.02);
    l0->AddEntry(ee_Top_jetcsv, "Top process", "lE");
    l0->AddEntry(ee_Sig1_jetcsv, "m_{#chi_{2}} = 1 GeV, c#tau = 1 mm", "lE");
    l0->AddEntry(ee_Sig50_jetcsv, "m_{#chi_{2}} = 50 GeV, c#tau = 10 mm", "lE");
    l0->AddEntry(ee_Sig150_jetcsv, "m_{#chi_{2}} = 150 GeV, c#tau = 1 mm", "lE");
    l0->Draw();
    */
    /*
    ee_2017Sig1_jetCSVv2->GetXaxis()->SetTitleSize(0.045);
    ee_2017Sig1_jetCSVv2->GetXaxis()->SetLabelSize(0.045);
    ee_2017Sig1_jetCSVv2->GetXaxis()->SetLabelOffset(0.02);
    ee_2017Sig1_jetCSVv2->GetXaxis()->SetTitleOffset(1.3);
    ee_2017Sig1_jetCSVv2->GetXaxis()->SetTitle("THINjetCISVV2");
    ee_2017Sig1_jetCSVv2->GetYaxis()->SetTitleSize(0.045);
    ee_2017Sig1_jetCSVv2->GetYaxis()->SetLabelSize(0.045);
    ee_2017Sig1_jetCSVv2->GetYaxis()->SetTitleOffset(1.4);
    ee_2017Sig1_jetCSVv2->GetYaxis()->SetTitle("nJets");

    ee_2017Sig1_jetCSVv2->Draw("he");

    TLegend *l0 = new TLegend(0.5, 0.60, 0.92, 0.88);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.02);
    l0->SetHeader("2017 MC");
    l0->AddEntry(ee_2017Sig1_jetCSVv2, "m_{#chi_{2}} = 1 GeV, c#tau = 1 mm", "lE");
    l0->Draw();
    */
ee_2017Sig1_jetDeepCSV->GetXaxis()->SetTitleSize(0.045);
    ee_2017Sig1_jetDeepCSV->GetXaxis()->SetLabelSize(0.045);
    ee_2017Sig1_jetDeepCSV->GetXaxis()->SetLabelOffset(0.02);
    ee_2017Sig1_jetDeepCSV->GetXaxis()->SetTitleOffset(1.3);
    ee_2017Sig1_jetDeepCSV->GetXaxis()->SetTitle("DeepCSV");
    ee_2017Sig1_jetDeepCSV->GetYaxis()->SetTitleSize(0.045);
    ee_2017Sig1_jetDeepCSV->GetYaxis()->SetLabelSize(0.045);
    ee_2017Sig1_jetDeepCSV->GetYaxis()->SetTitleOffset(1.4);
    ee_2017Sig1_jetDeepCSV->GetYaxis()->SetTitle("nJets");

    ee_2017Sig1_jetDeepCSV->Draw("he");

    TLegend *l0 = new TLegend(0.5, 0.60, 0.92, 0.88);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.02);
    l0->SetHeader("2017 MC");
    l0->AddEntry(ee_2017Sig1_jetDeepCSV, "m_{#chi_{2}} = 1 GeV, c#tau = 1 mm", "lE");
    l0->Draw();




    ee_Sig150_jetcsv->GetXaxis()->SetTitleSize(0.045);
    ee_Sig150_jetcsv->GetXaxis()->SetLabelSize(0.045);
    ee_Sig150_jetcsv->GetXaxis()->SetLabelOffset(0.02);
    ee_Sig150_jetcsv->GetXaxis()->SetTitleOffset(1.3);
    ee_Sig150_jetcsv->GetXaxis()->SetTitle("THINjetCISVV2");
    ee_Sig150_jetcsv->GetYaxis()->SetTitleSize(0.045);
    ee_Sig150_jetcsv->GetYaxis()->SetLabelSize(0.045);
    ee_Sig150_jetcsv->GetYaxis()->SetTitleOffset(1.4);
    ee_Sig150_jetcsv->GetYaxis()->SetTitle("nJets/Normarlized");

    /*
    ee_Sig150_jetcsv->DrawNormalized("he ");
    ee_Sig1_jetcsv->DrawNormalized("he same");
    ee_Sig50_jetcsv->DrawNormalized("he same");

    TLegend *l0 = new TLegend(0.5, 0.60, 0.92, 0.88);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.02);
    l0->SetHeader("Weighted");
    l0->AddEntry(ee_Sig1_jetcsv, "m_{#chi_{2}} = 1 GeV, c#tau = 1 mm", "lE");
    l0->AddEntry(ee_Sig50_jetcsv, "m_{#chi_{2}} = 50 GeV, c#tau = 10 mm", "lE");
    l0->AddEntry(ee_Sig150_jetcsv, "m_{#chi_{2}} = 150 GeV, c#tau = 1 mm", "lE");
    l0->Draw();*/

    /*
    ee_Sig150_jetcsv_unweight->GetXaxis()->SetTitleSize(0.045);
    ee_Sig150_jetcsv_unweight->GetXaxis()->SetLabelSize(0.045);
    ee_Sig150_jetcsv_unweight->GetXaxis()->SetLabelOffset(0.02);
    ee_Sig150_jetcsv_unweight->GetXaxis()->SetTitleOffset(1.3);
    ee_Sig150_jetcsv_unweight->GetXaxis()->SetTitle("THINjetCISVV2");
    ee_Sig150_jetcsv_unweight->GetYaxis()->SetTitleSize(0.045);
    ee_Sig150_jetcsv_unweight->GetYaxis()->SetLabelSize(0.045);
    ee_Sig150_jetcsv_unweight->GetYaxis()->SetTitleOffset(1.4);
    ee_Sig150_jetcsv_unweight->GetYaxis()->SetTitle("nJets/Normarlized");

    ee_Sig150_jetcsv_unweight->DrawNormalized("he ");
    ee_Sig1_jetcsv_unweight->DrawNormalized("he same");
    ee_Sig50_jetcsv_unweight->DrawNormalized("he same");

    TLegend *l0 = new TLegend(0.5, 0.60, 0.92, 0.88);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.02);
    l0->SetHeader("unweighted");
    l0->AddEntry(ee_Sig1_jetcsv_unweight, "m_{#chi_{2}} = 1 GeV, c#tau = 1 mm", "lE");
    l0->AddEntry(ee_Sig50_jetcsv_unweight, "m_{#chi_{2}} = 50 GeV, c#tau = 10 mm", "lE");
    l0->AddEntry(ee_Sig150_jetcsv_unweight, "m_{#chi_{2}} = 150 GeV, c#tau = 1 mm", "lE");
    l0->Draw();
    */
    /*
    ee_Sig1_jetcsv_SR->GetXaxis()->SetTitleSize(0.045);
    ee_Sig1_jetcsv_SR->GetXaxis()->SetLabelSize(0.045);
    ee_Sig1_jetcsv_SR->GetXaxis()->SetLabelOffset(0.02);
    ee_Sig1_jetcsv_SR->GetXaxis()->SetTitleOffset(1.3);
    ee_Sig1_jetcsv_SR->GetXaxis()->SetTitle("THINjetCISVV2");
    ee_Sig1_jetcsv_SR->GetYaxis()->SetTitleSize(0.045);
    ee_Sig1_jetcsv_SR->GetYaxis()->SetLabelSize(0.045);
    ee_Sig1_jetcsv_SR->GetYaxis()->SetTitleOffset(1.4);
    ee_Sig1_jetcsv_SR->GetYaxis()->SetTitle("nJets/Normarlized");

    ee_Sig1_jetcsv_SR->DrawNormalized("he ");
    ee_Sig150_jetcsv_SR->DrawNormalized("he same");
    ee_Sig50_jetcsv_SR->DrawNormalized("he same");

    TLegend *l0 = new TLegend(0.5, 0.60, 0.92, 0.88);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.02);
    l0->SetHeader("#alpha_{3D} < 0.1");
    l0->AddEntry(ee_Sig1_jetcsv_SR, "m_{#chi_{2}} = 1 GeV, c#tau = 1 mm", "lE");
    l0->AddEntry(ee_Sig50_jetcsv_SR, "m_{#chi_{2}} = 50 GeV, c#tau = 10 mm", "lE");
    l0->AddEntry(ee_Sig150_jetcsv_SR, "m_{#chi_{2}} = 150 GeV, c#tau = 1 mm", "lE");
    l0->Draw();
    */

    CMS_lumi((TPad *)canv, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");
}
