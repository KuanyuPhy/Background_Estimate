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
#include "./../../../lib/Cross_section.h"
#include "./../../../lib/setNCUStyle.C"
#include "tdrstyle.C"
#include "CMS_lumi.C"
using namespace std;
void ee_met(TString inputfile = "./ee_DY_Met.root")
{
    setTDRStyle();
    TFile *DYprocess = TFile::Open(inputfile);
    TFile *Sigfile = new TFile("./ee_Sig_Met.root");
    TFile *Topprocess = new TFile("./ee_Top_Met.root");
    TFile *Dibosonprocess = new TFile("./ee_Diboson_Met.root");
    TFile *Tribosonprocess = new TFile("./ee_Triboson_Met.root");

    //-----------
    // For Met
    //-----------

    TH1D *HT_Met = ((TH1D *)DYprocess->Get("h_DY_Met"));
    TH1D *Top_Met = ((TH1D *)Topprocess->Get("h_Top_Met"));
    TH1D *Diboson_Met = ((TH1D *)Dibosonprocess->Get("h_Diboson_Met"));
    TH1D *Triboson_Met = ((TH1D *)Tribosonprocess->Get("h_Triboson_Met"));
    TH1D *Sig1_Met = ((TH1D *)Sigfile->Get("h_Mx2_1_Met"));
    TH1D *Sig50_Met = ((TH1D *)Sigfile->Get("h_Mx2_50_Met"));
    TH1D *Sig150_Met = ((TH1D *)Sigfile->Get("h_Mx2_150_Met"));

    TH1D *HT_Met_cut = ((TH1D *)DYprocess->Get("h_DY_Met_cut"));
    TH1D *Top_Met_cut = ((TH1D *)Topprocess->Get("h_Top_Met_cut"));
    TH1D *Diboson_Met_cut = ((TH1D *)Dibosonprocess->Get("h_Diboson_Met_cut"));
    TH1D *Triboson_Met_cut = ((TH1D *)Tribosonprocess->Get("h_Triboson_Met_cut"));

    //-------------------------
    // CMS style
    //-------------------------
    writeExtraText = true;
    extraText = "Simulation";
    lumi_sqrtS = "13 TeV";

    HT_Met->SetLineColor(kOrange - 3);
    Top_Met->SetLineColor(kGreen + 3);
    Diboson_Met->SetLineColor(kAzure + 7);
    Triboson_Met->SetLineColor(kMagenta - 3);

    HT_Met->SetFillColor(kOrange - 3);
    Top_Met->SetFillColor(kGreen + 3);
    Diboson_Met->SetFillColor(kAzure + 7);
    Triboson_Met->SetFillColor(kMagenta - 3);

    HT_Met_cut->SetLineColor(kOrange - 3);
    Top_Met_cut->SetLineColor(kGreen + 3);
    Diboson_Met_cut->SetLineColor(kAzure + 7);
    Triboson_Met_cut->SetLineColor(kMagenta - 3);

    HT_Met_cut->SetFillColor(kOrange - 3);
    Top_Met_cut->SetFillColor(kGreen + 3);
    Diboson_Met_cut->SetFillColor(kAzure + 7);
    Triboson_Met_cut->SetFillColor(kMagenta - 3);

    Sig1_Met->SetLineColor(kRed);
    Sig50_Met->SetLineColor(kBlack);
    Sig150_Met->SetLineColor(kBlue);

    HT_Met->SetLineWidth(2);
    Top_Met->SetLineWidth(2);
    Diboson_Met->SetLineWidth(2);
    Triboson_Met->SetLineWidth(2);
    Sig1_Met->SetLineWidth(2);
    Sig50_Met->SetLineWidth(2);
    Sig150_Met->SetLineWidth(2);

    HT_Met_cut->SetLineWidth(2);
    Top_Met_cut->SetLineWidth(2);
    Diboson_Met_cut->SetLineWidth(2);
    Triboson_Met_cut->SetLineWidth(2);

    THStack *hs = new THStack("hs", "");
    hs->Add(HT_Met_cut);
    hs->Add(Diboson_Met_cut);
    hs->Add(Top_Met_cut);
    hs->Add(Triboson_Met_cut);

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
    // canv->Divide(2, 1);
    // canv->cd(1);

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
    cout << "number of Events with DY = " << HT_Met->Integral() << "\n";
    cout << "number of Events with Top = " << Top_Met_cut->Integral() << "\n";
    cout << "number of Events with Diboson = " << Diboson_Met_cut->Integral() << "\n";
    cout << "number of Events with Triboson = " << Triboson_Met_cut->Integral() << "\n";
    TLegend *l0 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->SetHeader("2016MC Background");
    l0->AddEntry(HT_Met, "Drell-Yan process", "l");
    l0->AddEntry(Top_Met, "Top process", "l");
    l0->AddEntry(Diboson_Met, "Diboson process", "l");
    l0->AddEntry(Triboson_Met, "Triboson process", "l");
    l0->Draw();

    // canv->cd(2);
    /*
    Sig1_Met->GetXaxis()->SetNdivisions(6, 5, 0);
    Sig1_Met->GetXaxis()->SetTitle("Met");
    Sig1_Met->GetYaxis()->SetNdivisions(6, 5, 0);
    Sig1_Met->GetYaxis()->SetTitleOffset(1);
    Sig1_Met->GetYaxis()->SetTitle("nEvents");
    Sig1_Met->GetXaxis()->SetTitle("Met");
    Sig1_Met->GetYaxis()->SetTitle("nEvents");
    Sig1_Met->DrawNormalized("h same");
    Sig50_Met->DrawNormalized("h same");
    Sig150_Met->DrawNormalized("h same");
    TLegend *l1 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(Sig1_Met, "#chi_{2} = 1 GeV, ctau = 1 mm", "l");
    l1->AddEntry(Sig50_Met, "#chi_{2} = 50 GeV, ctau = 10 mm", "l");
    l1->AddEntry(Sig150_Met, "#chi_{2} = 150 GeV, ctau = 1 mm", "l");
    l1->Draw();
    */

    int iPeriod = 0;
    int iPos = 33;
    CMS_lumi(canv, iPeriod, iPos);
    canv->Update();
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
