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
#include "./../../lib/Cross_section.h"
#include "./../../lib/setNCUStyle.C"
#include "tdrstyle.C"
#include "CMS_lumi.C"
using namespace std;
void ee_var(TString inputfile = "./DY/ee_DY_Met.root")
{
    setTDRStyle();
    TFile *ee_DYprocess = TFile::Open(inputfile);
    TFile *ee_Sigfile = new TFile("./sig/ee_Sig_Met.root");
    TFile *ee_Topprocess = new TFile("./top/ee_Top_Met.root");
    TFile *ee_Dibosonprocess = new TFile("./diboson/ee_Diboson_Met.root");
    TFile *ee_Tribosonprocess = new TFile("./triboson/ee_Triboson_Met.root");

    TFile *uu_DYprocess = new TFile("./DY/uu_DY_Met.root");
    TFile *uu_Sigfile = new TFile("./sig/uu_Sig_Met.root");
    TFile *uu_Topprocess = new TFile("./top/uu_Top_Met.root");
    TFile *uu_Dibosonprocess = new TFile("./diboson/uu_Diboson_Met.root");
    TFile *uu_Tribosonprocess = new TFile("./triboson/uu_Triboson_Met.root");

    //-----------
    // For Met
    //-----------
    TH1D *ee_HT_Met = ((TH1D *)ee_DYprocess->Get("h_DY_Met"));
    TH1D *ee_Top_Met = ((TH1D *)ee_Topprocess->Get("h_Top_Met"));
    TH1D *ee_Diboson_Met = ((TH1D *)ee_Dibosonprocess->Get("h_Diboson_Met"));
    TH1D *ee_Triboson_Met = ((TH1D *)ee_Tribosonprocess->Get("h_Triboson_Met"));
    TH1D *ee_Sig1_Met = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_Met"));
    TH1D *ee_Sig50_Met = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_Met"));
    TH1D *ee_Sig150_Met = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_Met"));

    TH1D *ee_Sig1_Met_cut = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_Met_cut"));
    TH1D *ee_Sig50_Met_cut = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_Met_cut"));
    TH1D *ee_Sig150_Met_cut = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_Met_cut"));

    TH1D *uu_HT_Met = ((TH1D *)uu_DYprocess->Get("h_DY_Met"));
    TH1D *uu_Top_Met = ((TH1D *)uu_Topprocess->Get("h_Top_Met"));
    TH1D *uu_Diboson_Met = ((TH1D *)uu_Dibosonprocess->Get("h_Diboson_Met"));
    TH1D *uu_Triboson_Met = ((TH1D *)uu_Tribosonprocess->Get("h_Triboson_Met"));
    TH1D *uu_Sig1_Met = ((TH1D *)uu_Sigfile->Get("h_Mx2_1_Met"));
    TH1D *uu_Sig50_Met = ((TH1D *)uu_Sigfile->Get("h_Mx2_50_Met"));
    TH1D *uu_Sig150_Met = ((TH1D *)uu_Sigfile->Get("h_Mx2_150_Met"));

    TH1D *ee_HT_Met_cut = ((TH1D *)ee_DYprocess->Get("h_DY_Met_cut"));
    TH1D *ee_Top_Met_cut = ((TH1D *)ee_Topprocess->Get("h_Top_Met_cut"));
    TH1D *ee_Diboson_Met_cut = ((TH1D *)ee_Dibosonprocess->Get("h_Diboson_Met_cut"));
    TH1D *ee_Triboson_Met_cut = ((TH1D *)ee_Tribosonprocess->Get("h_Triboson_Met_cut"));

    TH1D *uu_HT_Met_cut = ((TH1D *)uu_DYprocess->Get("h_DY_Met_cut"));
    TH1D *uu_Top_Met_cut = ((TH1D *)uu_Topprocess->Get("h_Top_Met_cut"));
    TH1D *uu_Diboson_Met_cut = ((TH1D *)uu_Dibosonprocess->Get("h_Diboson_Met_cut"));
    TH1D *uu_Triboson_Met_cut = ((TH1D *)uu_Tribosonprocess->Get("h_Triboson_Met_cut"));

    TH1D *ee_HT_dilepPT = ((TH1D *)ee_DYprocess->Get("h_DY_dilepPT"));
    TH1D *ee_Top_dilepPT = ((TH1D *)ee_Topprocess->Get("h_Top_dilepPT"));
    TH1D *ee_Diboson_dilepPT = ((TH1D *)ee_Dibosonprocess->Get("h_Diboson_dilepPT"));
    TH1D *ee_Triboson_dilepPT = ((TH1D *)ee_Tribosonprocess->Get("h_Triboson_dilepPT"));
    TH1D *ee_Sig1_dilepPT = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_dilepPT"));
    TH1D *ee_Sig50_dilepPT = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_dilepPT"));
    TH1D *ee_Sig150_dilepPT = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_dilepPT"));

    // Jet CSV
    TH1D *ee_HT_bJetcsv = ((TH1D *)ee_DYprocess->Get("h_DY_bjetcsv"));
    TH1D *ee_HT_lJetcsv = ((TH1D *)ee_DYprocess->Get("h_DY_ljetcsv"));

    TH1D *ee_Top_bJetcsv = ((TH1D *)ee_Topprocess->Get("h_Top_bjetcsv"));
    TH1D *ee_Top_lJetcsv = ((TH1D *)ee_Topprocess->Get("h_Top_ljetcsv"));

    TH1D *ee_Diboson_bJetcsv = ((TH1D *)ee_Dibosonprocess->Get("h_diboson_bjetcsv"));
    TH1D *ee_Diboson_lJetcsv = ((TH1D *)ee_Dibosonprocess->Get("h_diboson_ljetcsv"));

    TH1D *ee_Triboson_bJetcsv = ((TH1D *)ee_Tribosonprocess->Get("h_Triboson_bjetcsv"));
    TH1D *ee_Triboson_lJetcsv = ((TH1D *)ee_Tribosonprocess->Get("h_Triboson_ljetcsv"));

    TH1D *ee_HT_Jetcsv = ((TH1D *)ee_DYprocess->Get("h_DY_jetcsv"));
    TH1D *ee_Top_Jetcsv = ((TH1D *)ee_Topprocess->Get("h_Top_jetcsv"));
    TH1D *ee_Diboson_Jetcsv = ((TH1D *)ee_Dibosonprocess->Get("h_diboson_jetcsv"));
    TH1D *ee_Triboson_Jetcsv = ((TH1D *)ee_Tribosonprocess->Get("h_Triboson_jetcsv"));

    TH1D *ee_HT_Jetcsv_cutalpha = ((TH1D *)ee_DYprocess->Get("h_DY_jetcsv_cutalpha"));
    TH1D *ee_Top_Jetcsv_cutalpha = ((TH1D *)ee_Topprocess->Get("h_Top_jetcsv_cutalpha"));
    TH1D *ee_Diboson_Jetcsv_cutalpha = ((TH1D *)ee_Dibosonprocess->Get("h_diboson_jetcsv_cutalpha"));
    TH1D *ee_Triboson_Jetcsv_cutalpha = ((TH1D *)ee_Tribosonprocess->Get("h_Triboson_jetcsv_cutalpha"));

    // Jet Mass
    TH1D *ee_HT_bJetMass = ((TH1D *)ee_DYprocess->Get("h_DY_bJetMass"));
    TH1D *ee_HT_lJetMass = ((TH1D *)ee_DYprocess->Get("h_DY_lJetMass"));

    TH1D *ee_Top_bJetMass = ((TH1D *)ee_Topprocess->Get("h_Top_bJetMass"));
    TH1D *ee_Top_lJetMass = ((TH1D *)ee_Topprocess->Get("h_Top_lJetMass"));

    TH1D *ee_Diboson_bJetMass = ((TH1D *)ee_Dibosonprocess->Get("h_diboson_bJetMass"));
    TH1D *ee_Diboson_lJetMass = ((TH1D *)ee_Dibosonprocess->Get("h_diboson_lJetMass"));

    TH1D *ee_Triboson_bJetMass = ((TH1D *)ee_Tribosonprocess->Get("h_Triboson_bJetMass"));
    TH1D *ee_Triboson_lJetMass = ((TH1D *)ee_Tribosonprocess->Get("h_Triboson_lJetMass"));

    //-------------------------
    // Add all 2016 BG
    //-------------------------
    TH1D *h_2016Jetcsv = ((TH1D *)ee_HT_Jetcsv->Clone("h_2016Jetcsv"));
    h_2016Jetcsv->Add(ee_Top_Jetcsv);
    h_2016Jetcsv->Add(ee_Diboson_Jetcsv);
    h_2016Jetcsv->Add(ee_Triboson_Jetcsv);

    TH1D *h_2016bJetcsv = ((TH1D *)ee_HT_bJetcsv->Clone("h_2016bJetcsv"));
    h_2016bJetcsv->Add(ee_Top_bJetcsv);
    h_2016bJetcsv->Add(ee_Diboson_bJetcsv);
    h_2016bJetcsv->Add(ee_Triboson_bJetcsv);

    TH1D *h_2016lJetcsv = ((TH1D *)ee_HT_lJetcsv->Clone("h_2016lJetcsv"));
    h_2016lJetcsv->Add(ee_Top_lJetcsv);
    h_2016lJetcsv->Add(ee_Diboson_lJetcsv);
    h_2016lJetcsv->Add(ee_Triboson_lJetcsv);

    TH1D *h_2016Jetcsv_cutalpha = ((TH1D *)ee_HT_Jetcsv_cutalpha->Clone("h_2016Jetcsv_cutalpha"));
    h_2016Jetcsv_cutalpha->Add(ee_Top_Jetcsv_cutalpha);
    h_2016Jetcsv_cutalpha->Add(ee_Diboson_Jetcsv_cutalpha);
    h_2016Jetcsv_cutalpha->Add(ee_Triboson_Jetcsv_cutalpha);

    TH1D *h_2016bJetMass = ((TH1D *)ee_HT_bJetMass->Clone("h_2016bJetMass"));
    h_2016bJetMass->Add(ee_Top_bJetMass);
    h_2016bJetMass->Add(ee_Diboson_bJetMass);
    h_2016bJetMass->Add(ee_Triboson_bJetMass);

    TH1D *h_2016lJetMass = ((TH1D *)ee_HT_lJetMass->Clone("h_2016lJetMass"));
    h_2016lJetMass->Add(ee_Top_lJetMass);
    h_2016lJetMass->Add(ee_Diboson_lJetMass);
    h_2016lJetMass->Add(ee_Triboson_lJetMass);

    TH1D *h_2016dileppt = ((TH1D *)ee_HT_dilepPT->Clone("h_2016dileppt"));
    h_2016dileppt->Add(ee_Top_dilepPT);
    h_2016dileppt->Add(ee_Diboson_dilepPT);
    h_2016dileppt->Add(ee_Triboson_dilepPT);

    //-------------------------
    // CMS style
    //-------------------------
    writeExtraText = true;
    extraText = "Simulation";
    lumi_sqrtS = "13 TeV";

    ee_HT_Met->SetLineColor(kOrange - 3);
    ee_Top_Met->SetLineColor(kGreen + 3);
    ee_Diboson_Met->SetLineColor(kAzure + 7);
    ee_Triboson_Met->SetLineColor(kMagenta - 3);

    ee_HT_Met->SetFillColor(kOrange - 3);
    ee_Top_Met->SetFillColor(kGreen + 3);
    ee_Diboson_Met->SetFillColor(kAzure + 7);
    ee_Triboson_Met->SetFillColor(kMagenta - 3);

    ee_HT_dilepPT->SetFillColor(kOrange - 3);
    ee_Top_dilepPT->SetFillColor(kGreen + 3);
    ee_Diboson_dilepPT->SetFillColor(kAzure + 7);
    ee_Triboson_dilepPT->SetFillColor(kMagenta - 3);

    ee_HT_Met_cut->SetLineColor(kOrange - 3);
    ee_Top_Met_cut->SetLineColor(kGreen + 3);
    ee_Diboson_Met_cut->SetLineColor(kAzure + 7);
    ee_Triboson_Met_cut->SetLineColor(kMagenta - 3);

    ee_HT_Met_cut->SetFillColor(kOrange - 3);
    ee_Top_Met_cut->SetFillColor(kGreen + 3);
    ee_Diboson_Met_cut->SetFillColor(kAzure + 7);
    ee_Triboson_Met_cut->SetFillColor(kMagenta - 3);

    uu_HT_Met->SetLineColor(kOrange - 3);
    uu_Top_Met->SetLineColor(kGreen + 3);
    uu_Diboson_Met->SetLineColor(kAzure + 7);
    uu_Triboson_Met->SetLineColor(kMagenta - 3);

    ee_HT_dilepPT->SetLineColor(kOrange - 3);
    ee_Top_dilepPT->SetLineColor(kGreen + 3);
    ee_Diboson_dilepPT->SetLineColor(kAzure + 7);
    ee_Triboson_dilepPT->SetLineColor(kMagenta - 3);

    uu_HT_Met->SetFillColor(kOrange - 3);
    uu_Top_Met->SetFillColor(kGreen + 3);
    uu_Diboson_Met->SetFillColor(kAzure + 7);
    uu_Triboson_Met->SetFillColor(kMagenta - 3);

    uu_HT_Met_cut->SetLineColor(kOrange - 3);
    uu_Top_Met_cut->SetLineColor(kGreen + 3);
    uu_Diboson_Met_cut->SetLineColor(kAzure + 7);
    uu_Triboson_Met_cut->SetLineColor(kMagenta - 3);

    uu_HT_Met_cut->SetFillColor(kOrange - 3);
    uu_Top_Met_cut->SetFillColor(kGreen + 3);
    uu_Diboson_Met_cut->SetFillColor(kAzure + 7);
    uu_Triboson_Met_cut->SetFillColor(kMagenta - 3);

    h_2016bJetcsv->SetLineColor(kRed);
    h_2016lJetcsv->SetLineColor(kGreen + 3);
    h_2016Jetcsv->SetLineColor(kAzure + 7);

    h_2016Jetcsv_cutalpha->SetLineColor(kRed);

    h_2016bJetMass->SetLineColor(kRed);
    h_2016lJetMass->SetLineColor(kGreen + 3);

    h_2016dileppt->SetLineColor(kGreen + 3);

    h_2016lJetMass->SetFillColor(kGreen + 3);

    h_2016lJetMass->SetFillStyle(3001);

    h_2016dileppt->SetFillColor(kGreen + 3);
    h_2016dileppt->SetFillStyle(3001);

    ee_Sig1_Met->SetLineColor(kRed);
    ee_Sig50_Met->SetLineColor(kGray + 2);
    ee_Sig150_Met->SetLineColor(kBlue);

    ee_Sig1_Met_cut->SetLineColor(kRed);
    ee_Sig50_Met_cut->SetLineColor(kGray + 2);
    ee_Sig150_Met_cut->SetLineColor(kBlue);

    uu_Sig1_Met->SetLineColor(kRed);
    uu_Sig50_Met->SetLineColor(kGray + 2);
    uu_Sig150_Met->SetLineColor(kBlue);

    ee_Sig1_dilepPT->SetLineColor(kRed);
    ee_Sig50_dilepPT->SetLineColor(kGray + 2);
    ee_Sig150_dilepPT->SetLineColor(kBlue);

    ee_HT_Met->SetLineWidth(2);
    ee_Top_Met->SetLineWidth(2);
    ee_Diboson_Met->SetLineWidth(2);
    ee_Triboson_Met->SetLineWidth(2);
    ee_Sig1_Met->SetLineWidth(2);
    ee_Sig50_Met->SetLineWidth(2);
    ee_Sig150_Met->SetLineWidth(2);

    ee_Sig1_Met_cut->SetLineWidth(2);
    ee_Sig50_Met_cut->SetLineWidth(2);
    ee_Sig150_Met_cut->SetLineWidth(2);

    ee_HT_dilepPT->SetLineWidth(2);
    ee_Top_dilepPT->SetLineWidth(2);
    ee_Diboson_dilepPT->SetLineWidth(2);
    ee_Triboson_dilepPT->SetLineWidth(2);

    ee_Sig1_dilepPT->SetLineWidth(2);
    ee_Sig50_dilepPT->SetLineWidth(2);
    ee_Sig150_dilepPT->SetLineWidth(2);

    uu_HT_Met->SetLineWidth(2);
    uu_Top_Met->SetLineWidth(2);
    uu_Diboson_Met->SetLineWidth(2);
    uu_Triboson_Met->SetLineWidth(2);

    uu_Sig1_Met->SetLineWidth(2);
    uu_Sig50_Met->SetLineWidth(2);
    uu_Sig150_Met->SetLineWidth(2);

    ee_HT_Met_cut->SetLineWidth(2);
    ee_Top_Met_cut->SetLineWidth(2);
    ee_Diboson_Met_cut->SetLineWidth(2);
    ee_Triboson_Met_cut->SetLineWidth(2);

    uu_HT_Met_cut->SetLineWidth(2);
    uu_Top_Met_cut->SetLineWidth(2);
    uu_Diboson_Met_cut->SetLineWidth(2);
    uu_Triboson_Met_cut->SetLineWidth(2);

    h_2016bJetcsv->SetLineWidth(2);
    h_2016lJetcsv->SetLineWidth(2);
    h_2016Jetcsv->SetLineWidth(2);
    h_2016Jetcsv_cutalpha->SetLineWidth(2);

    h_2016bJetMass->SetLineWidth(2);
    h_2016lJetMass->SetLineWidth(2);

    h_2016dileppt->SetLineWidth(2);

    ee_Diboson_dilepPT->GetXaxis()->SetNdivisions(6, 5, 0);
    ee_Diboson_dilepPT->GetXaxis()->SetTitleOffset(1.5);
    ee_Diboson_dilepPT->GetXaxis()->SetTitle("dileptom PT");
    ee_Diboson_dilepPT->GetYaxis()->SetNdivisions(6, 5, 0);
    ee_Diboson_dilepPT->GetYaxis()->SetTitleOffset(1.5);
    ee_Diboson_dilepPT->GetYaxis()->SetTitle("nEvents");

    ee_HT_dilepPT->GetXaxis()->SetNdivisions(6, 5, 0);
    ee_HT_dilepPT->GetXaxis()->SetTitleOffset(1.5);
    ee_HT_dilepPT->GetXaxis()->SetTitle("dileptom PT");
    ee_HT_dilepPT->GetYaxis()->SetNdivisions(6, 5, 0);
    ee_HT_dilepPT->GetYaxis()->SetTitleOffset(1.5);
    ee_HT_dilepPT->GetYaxis()->SetTitle("nEvents");

    ee_Top_dilepPT->GetXaxis()->SetNdivisions(6, 5, 0);
    ee_Top_dilepPT->GetXaxis()->SetTitleOffset(1.5);
    ee_Top_dilepPT->GetXaxis()->SetTitle("dileptom PT");
    ee_Top_dilepPT->GetYaxis()->SetNdivisions(6, 5, 0);
    ee_Top_dilepPT->GetYaxis()->SetTitleOffset(1.5);
    ee_Top_dilepPT->GetYaxis()->SetTitle("nEvents");

    ee_Triboson_dilepPT->GetXaxis()->SetNdivisions(6, 5, 0);
    ee_Triboson_dilepPT->GetXaxis()->SetTitleOffset(1.5);
    ee_Triboson_dilepPT->GetXaxis()->SetTitle("dileptom PT");
    ee_Triboson_dilepPT->GetYaxis()->SetNdivisions(6, 5, 0);
    ee_Triboson_dilepPT->GetYaxis()->SetTitleOffset(1.5);
    ee_Triboson_dilepPT->GetYaxis()->SetTitle("nEvents");

    h_2016bJetcsv->GetXaxis()->SetNdivisions(6, 5, 0);
    h_2016bJetcsv->GetXaxis()->SetTitleOffset(1.5);
    h_2016bJetcsv->GetXaxis()->SetTitle("JetCsV");
    h_2016bJetcsv->GetYaxis()->SetNdivisions(6, 5, 0);
    h_2016bJetcsv->GetYaxis()->SetTitleOffset(1.5);
    h_2016bJetcsv->GetYaxis()->SetTitle("nJet ");

    h_2016Jetcsv->GetXaxis()->SetNdivisions(6, 5, 0);
    h_2016Jetcsv->GetXaxis()->SetTitleOffset(1.5);
    h_2016Jetcsv->GetXaxis()->SetTitle("Jetcsv");
    h_2016Jetcsv->GetYaxis()->SetNdivisions(6, 5, 0);
    h_2016Jetcsv->GetYaxis()->SetTitleOffset(1.5);
    h_2016Jetcsv->GetYaxis()->SetTitle("nJet");

    h_2016lJetMass->GetXaxis()->SetNdivisions(6, 5, 0);
    h_2016lJetMass->GetXaxis()->SetTitleOffset(1.5);
    h_2016lJetMass->GetXaxis()->SetTitle("Jet Mass");
    h_2016lJetMass->GetYaxis()->SetNdivisions(6, 5, 0);
    h_2016lJetMass->GetYaxis()->SetTitleOffset(1.5);
    h_2016lJetMass->GetYaxis()->SetTitle("nJet");

    h_2016dileppt->GetXaxis()->SetNdivisions(6, 5, 0);
    h_2016dileppt->GetXaxis()->SetTitleOffset(1.5);
    h_2016dileppt->GetXaxis()->SetTitle("delepton PT");
    h_2016dileppt->GetYaxis()->SetNdivisions(6, 5, 0);
    h_2016dileppt->GetYaxis()->SetTitleOffset(1.5);
    h_2016dileppt->GetYaxis()->SetTitle("nEvents / Normalized");

    /*
    THStack *hs = new THStack("hs", "");
    hs->Add(uu_HT_Met);
    hs->Add(uu_Diboson_Met);
    hs->Add(uu_Top_Met);
    hs->Add(uu_Triboson_Met);
    */

    /*
    THStack *hs = new THStack("hs", "");
    hs->Add(ee_Diboson_dilepPT);
    hs->Add(ee_Top_dilepPT);
    hs->Add(ee_Triboson_dilepPT);
    hs->Add(ee_HT_dilepPT);
    */

    THStack *hs = new THStack("hs", "");
    // hs->Add(ee_HT_Met_cut);
    // hs->Add(ee_Diboson_Met_cut);
    // hs->Add(ee_Top_Met_cut);
    // hs->Add(ee_Triboson_Met_cut);

    int W = 800;
    int H = 600;

    int H_ref = 600;
    int W_ref = 800;

    float T = 0.08 * H_ref;
    float B = 0.12 * H_ref;
    float L = 0.12 * W_ref;
    float R = 0.04 * W_ref;

    TCanvas *canv = new TCanvas("canv", "", 50, 50, W, H);
    canv->SetFillColor(0);
    canv->SetBorderMode(0);
    canv->SetFrameFillStyle(0);
    canv->SetFrameBorderMode(0);
    canv->SetLeftMargin(L / W);
    canv->SetRightMargin(R / W);
    canv->SetTopMargin(T / H);
    canv->SetBottomMargin(B / H);
    canv->SetTickx(0);
    canv->SetTicky(0);

    /*
    canv->Divide(2, 2);
    canv->cd(1);
    ee_Diboson_dilepPT->Draw();
    TLegend *l1 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(ee_Diboson_dilepPT, "Diboson process", "lE");
    l1->Draw();
    canv->cd(2);
    ee_HT_dilepPT->Draw();
    TLegend *l2 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(ee_HT_dilepPT, "Drell-Yan process", "lE");
    l2->Draw();
    canv->cd(3);
    ee_Top_dilepPT->Draw();
    TLegend *l3 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l3->SetBorderSize(0);
    l3->SetTextSize(0.03);
    l3->AddEntry(ee_Top_dilepPT, "Top process", "lE");
    l3->Draw();
    canv->cd(4);
    ee_Triboson_dilepPT->Draw();
    TLegend *l4 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l4->SetBorderSize(0);
    l4->SetTextSize(0.03);
    l4->AddEntry(ee_Triboson_dilepPT, "Triboson process", "lE");
    l4->Draw();
    */

    /*
    hs->Draw("hist");
    hs->GetXaxis()->SetNdivisions(6, 5, 0);
    hs->GetXaxis()->SetTitle("MET");
    // hs->GetXaxis()->SetTitleOffset(1.5);
    hs->GetXaxis()->SetTitleSize(0.04);
    hs->GetXaxis()->SetLabelSize(0.04);
    hs->GetYaxis()->SetNdivisions(6, 5, 0);
    hs->GetYaxis()->SetTitleOffset(1);
    hs->GetYaxis()->SetTitle("nEvents");
    hs->GetYaxis()->SetTitleSize(0.04);
    hs->GetYaxis()->SetTitleOffset(1.5);
    hs->GetYaxis()->SetLabelSize(0.04);
    cout << "number of Events with DY without Met cut = " << ee_HT_Met->Integral() << "\n";
    cout << "number of Events with DY = " << ee_HT_Met_cut->Integral() << "\n";
    cout << "number of Events with Top = " << ee_Top_Met_cut->Integral() << "\n";
    cout << "number of Events with Diboson = " << ee_Diboson_Met_cut->Integral() << "\n";
    cout << "number of Events with Triboson = " << ee_Triboson_Met_cut->Integral() << "\n";
    TLegend *l0 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->SetHeader("2016MC Background");
    l0->AddEntry(uu_HT_Met, "Drell-Yan process", "l");
    l0->AddEntry(uu_Top_Met, "Top process", "l");
    l0->AddEntry(uu_Diboson_Met, "Diboson process", "l");
    l0->AddEntry(uu_Triboson_Met, "Triboson process", "l");
    l0->Draw();
    */

    /*
    ee_Sig150_Met_cut->GetXaxis()->SetNdivisions(6, 5, 0);
    ee_Sig150_Met_cut->GetXaxis()->SetTitleOffset(1.5);
    ee_Sig150_Met_cut->GetXaxis()->SetTitle("Met");
    ee_Sig150_Met_cut->GetYaxis()->SetNdivisions(6, 5, 0);
    ee_Sig150_Met_cut->GetYaxis()->SetTitleOffset(1.5);
    ee_Sig150_Met_cut->GetYaxis()->SetTitle("nEvents");

    ee_Sig150_Met_cut->Draw("h same");
    ee_Sig50_Met_cut->Draw("h same");
    ee_Sig1_Met_cut->Draw("h same");

    TLegend *l1 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(ee_Sig1_Met_cut, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(ee_Sig50_Met_cut, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(ee_Sig150_Met_cut, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */

    // canv->cd(2);
    /*
    ee_Sig50_Met->GetXaxis()->SetNdivisions(6, 5, 0);
    ee_Sig50_Met->GetXaxis()->SetTitleOffset(1.5);
    ee_Sig50_Met->GetXaxis()->SetTitle("Met");
    ee_Sig50_Met->GetYaxis()->SetNdivisions(6, 5, 0);
    ee_Sig50_Met->GetYaxis()->SetTitleOffset(1.5);
    ee_Sig50_Met->GetYaxis()->SetTitle("nEvents");
    */

    /*
    ee_Sig50_dilepPT->GetXaxis()->SetNdivisions(6, 5, 0);
    ee_Sig50_dilepPT->GetXaxis()->SetTitleOffset(1.5);
    ee_Sig50_dilepPT->GetXaxis()->SetTitle("dilepton PT");
    ee_Sig50_dilepPT->GetYaxis()->SetNdivisions(6, 5, 0);
    ee_Sig50_dilepPT->GetYaxis()->SetTitleOffset(1.5);
    ee_Sig50_dilepPT->GetYaxis()->SetTitle("nEvents");

    ee_Sig50_dilepPT->Draw("h same");
    ee_Sig1_dilepPT->Draw("h same");
    ee_Sig150_dilepPT->Draw("h same");



    TLegend *l1 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(uu_Sig1_Met, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(uu_Sig50_Met, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(uu_Sig150_Met, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */
    // h_2016bJetcsv->DrawNormalized("e");
    // h_2016lJetcsv->DrawNormalized("e same");

    // h_2016lJetMass->Draw("h e ");
    // h_2016bJetMass->Draw("e same ");

    h_2016Jetcsv->Draw("h e");
    h_2016Jetcsv_cutalpha->Draw("e same ");

    // h_2016dileppt->DrawNormalized("h e ");
    // ee_Sig1_dilepPT->DrawNormalized("h e same ");
    // ee_Sig50_dilepPT->DrawNormalized("h e same ");
    // ee_Sig150_dilepPT->DrawNormalized("h e same ");
    //  cout << "number of Events with DY without Met cut = " << h_2016lJetMass->Integral() << "\n";
    //  cout << "number of Events with DY = " << h_2016bJetMass->Integral() << "\n";

    /*
    TLegend *l1 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_2016bJetcsv, "b flavor", "lE");
    l1->AddEntry(h_2016lJetcsv, "light flavor", "lE");
    l1->Draw();
    */
    
    TLegend *l1 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_2016Jetcsv, "2016 MC background", "lE");
    l1->AddEntry(h_2016Jetcsv_cutalpha, "2016 MC background (SR)", "lE");
    l1->Draw();
    
    /*
    TLegend *l1 = new TLegend(0.6, 0.4, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_2016dileppt, "2016 MC background", "lE");
    l1->AddEntry(ee_Sig1_dilepPT, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(ee_Sig50_dilepPT, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(ee_Sig150_dilepPT, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */

    gPad->SetLogy();

    int iPeriod = 0;
    int iPos = 33;
    CMS_lumi(canv, iPeriod, iPos);
    // canv->Update();
    canv->RedrawAxis();
    TString canvName = "2016MCbg_Met";
    // canv->Print(canvName + ".pdf", ".pdf");
    //   canv->GetFrame()->Draw();

    // HT_Met->GetXaxis()->SetTitle("Met");
    // HT_Met->GetYaxis()->SetTitle("nEvents");
    // HT_Met->DrawNormalized("h ");
    // Top_Met->DrawNormalized("h same");
    // Diboson_Met->DrawNormalized("h same");
    // Triboson_Met->DrawNormalized("h same");

    // c1->cd(2);
    // Sig1_Met->GetXaxis()->SetTitleOffset(1.5);
    // Sig1_Met->GetXaxis()->SetTitle("Met");
    // Sig1_Met->GetYaxis()->SetTitle("nEvents");
    // Sig1_Met->DrawNormalized("h same");
    // Sig50_Met->DrawNormalized("h same");
    // Sig150_Met->DrawNormalized("h same");
    // TLegend *l1 = new TLegend(0.4, 0.4, 0.90, 0.80);
    // l1->SetBorderSize(0);
    // l1->SetTextSize(0.03);
    // l1->AddEntry(Sig1_Met, "x2 = 1 GeV, ctau = 1 mm", "l");
    // l1->AddEntry(Sig50_Met, "x2 = 50 GeV, ctau = 10 mm", "l");
    // l1->AddEntry(Sig150_Met, "x2 = 150 GeV, ctau = 1 mm", "l");
    // l1->Draw();
    // c1->Modified();
}
