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
using namespace std;
void ee_met(TString inputfile = "./DY/ee_DY_Met.root")
{
    setNCUStyle(true);
    TFile *ee_DYprocess = TFile::Open(inputfile);
    TFile *ee_Sigfile = new TFile("./sig/ee_Sig_Met.root");
    TFile *ee_Topprocess = new TFile("./top/ee_Top_Met.root");
    TFile *ee_Dibosonprocess = new TFile("./diboson/ee_Diboson_Met.root");
    TFile *ee_Tribosonprocess = new TFile("./triboson/ee_Triboson_Met.root");

    TFile *uu_Sigfile = new TFile("./sig/uu_Sig_Met.root");
    TFile *uu_DYprocess = new TFile("./DY/uu_DY_Met.root");
    TFile *uu_Topprocess = new TFile("./top/uu_Top_Met.root");
    TFile *uu_Dibosonprocess = new TFile("./diboson/uu_Diboson_Met.root");
    TFile *uu_Tribosonprocess = new TFile("./triboson/uu_Triboson_Met.root");

    //-----------
    // For Met
    //-----------
    TH1D *ee_HT_Met = ((TH1D *)ee_DYprocess->Get("h_DY_Met"));
    TH1D *ee_Top_Met = ((TH1D *)ee_Topprocess->Get("h_Top_Met"));
    TH1D *ee_Diboson_Met = ((TH1D *)ee_Dibosonprocess->Get("h_diboson_Met"));
    TH1D *ee_Triboson_Met = ((TH1D *)ee_Tribosonprocess->Get("h_triboson_Met"));
    TH1D *ee_Sig1_Met = ((TH1D *)ee_Sigfile->Get("h_Sig1_Met"));
    TH1D *ee_Sig50_Met = ((TH1D *)ee_Sigfile->Get("h_Sig50_Met"));
    TH1D *ee_Sig150_Met = ((TH1D *)ee_Sigfile->Get("h_Sig150_Met"));

    TH1D *uu_HT_Met = ((TH1D *)uu_DYprocess->Get("h_DY_Met"));
    TH1D *uu_Top_Met = ((TH1D *)uu_Topprocess->Get("h_Top_Met"));
    TH1D *uu_Diboson_Met = ((TH1D *)uu_Dibosonprocess->Get("h_diboson_Met"));
    TH1D *uu_Triboson_Met = ((TH1D *)uu_Tribosonprocess->Get("h_triboson_Met"));
    TH1D *uu_Sig1_Met = ((TH1D *)uu_Sigfile->Get("h_Sig1_Met"));
    TH1D *uu_Sig50_Met = ((TH1D *)uu_Sigfile->Get("h_Sig50_Met"));
    TH1D *uu_Sig150_Met = ((TH1D *)uu_Sigfile->Get("h_Sig150_Met"));

    ee_HT_Met->SetLineColor(kOrange - 3);
    ee_Top_Met->SetLineColor(kGreen + 3);
    ee_Diboson_Met->SetLineColor(kAzure + 7);
    ee_Triboson_Met->SetLineColor(kMagenta - 3);

    uu_HT_Met->SetLineColor(kOrange - 3);
    uu_Top_Met->SetLineColor(kGreen + 3);
    uu_Diboson_Met->SetLineColor(kAzure + 7);
    uu_Triboson_Met->SetLineColor(kMagenta - 3);

    ee_HT_Met->SetFillColor(kOrange - 3);
    ee_Top_Met->SetFillColor(kGreen + 3);
    ee_Diboson_Met->SetFillColor(kAzure + 7);
    ee_Triboson_Met->SetFillColor(kMagenta - 3);

    uu_HT_Met->SetFillColor(kOrange - 3);
    uu_Top_Met->SetFillColor(kGreen + 3);
    uu_Diboson_Met->SetFillColor(kAzure + 7);
    uu_Triboson_Met->SetFillColor(kMagenta - 3);

    ee_Sig1_Met->SetLineColor(kRed);
    ee_Sig50_Met->SetLineColor(kGray);
    ee_Sig150_Met->SetLineColor(kBlue);

    uu_Sig1_Met->SetLineColor(kRed);
    uu_Sig50_Met->SetLineColor(kGray);
    uu_Sig150_Met->SetLineColor(kBlue);

    ee_HT_Met->SetLineWidth(2);
    ee_Top_Met->SetLineWidth(2);
    ee_Diboson_Met->SetLineWidth(2);
    ee_Triboson_Met->SetLineWidth(2);

    uu_HT_Met->SetLineWidth(2);
    uu_Top_Met->SetLineWidth(2);
    uu_Diboson_Met->SetLineWidth(2);
    uu_Triboson_Met->SetLineWidth(2);
    // Sig1_Met->SetLineWidth(2);
    // Sig50_Met->SetLineWidth(2);
    // Sig150_Met->SetLineWidth(2);

    TCanvas *c1 = new TCanvas();

    THStack *hs = new THStack("hs", "");
    hs->Add(ee_HT_Met);
    hs->Add(ee_Diboson_Met);
    hs->Add(ee_Top_Met);
    hs->Add(ee_Triboson_Met);

    cout << "number of Events with DY = " << ee_HT_Met->Integral() << "\n";
    cout << "number of Events with Top = " << ee_Top_Met->Integral() << "\n";
    cout << "number of Events with Diboson = " << ee_Diboson_Met->Integral() << "\n";
    cout << "number of Events with Triboson = " << ee_Triboson_Met->Integral() << "\n";

    hs->Draw("hist");
    hs->GetXaxis()->SetTitleOffset(1.5);
    hs->GetXaxis()->SetTitle("Met");
    hs->GetYaxis()->SetTitle("nEvents");

    Top_Met->GetXaxis()->SetTitle("Met");
    Top_Met->GetYaxis()->SetTitle("nEvents");

    // Top_Met->Draw("h ");
    // HT_Met->Draw("h same");
    // Diboson_Met->Draw("h same");
    // Triboson_Met->Draw("h same");
    // Sig1_Met->DrawNormalized("h same");
    // Sig50_Met->DrawNormalized("h same");
    // Sig150_Met->DrawNormalized("h same");

    TLegend *l0 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(ee_HT_Met, "Drell-Yan process", "f");
    l0->AddEntry(ee_Top_Met, "Top process", "f");
    l0->AddEntry(ee_Diboson_Met, "Diboson process", "f");
    l0->AddEntry(ee_Triboson_Met, "Triboson process", "f");
    // l0->AddEntry(Sig1_Met, "x2 = 1 GeV, ctau = 1 mm", "f");
    // l0->AddEntry(Sig50_Met, "x2 = 50 GeV, ctau = 10 mm", "f");
    // l0->AddEntry(Sig150_Met, "x2 = 150 GeV, ctau = 1 mm", "f");
    l0->Draw();

    c1->Modified();
}
