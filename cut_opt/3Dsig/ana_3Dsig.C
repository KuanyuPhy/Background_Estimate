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
void ana_3Dsig(TString inputfile = "./DY/ee_DY_alpha.root")
{
    setTDRStyle();
    TFile *ee_DYprocess = TFile::Open(inputfile);
    TFile *ee_Sigfile = new TFile("./sig/ee_Sig_alpha.root");
    TFile *ee_Topprocess = new TFile("./top/ee_Top_alpha.root");
    TFile *ee_Dibosonprocess = new TFile("./diboson/ee_Diboson_alpha.root");
    TFile *ee_Tribosonprocess = new TFile("./triboson/ee_Triboson_alpha.root");

    TFile *uu_DYprocess = new TFile("./DY/uu_DY_alpha.root");
    TFile *uu_Sigfile = new TFile("./sig/uu_Sig_alpha.root");
    TFile *uu_Topprocess = new TFile("./top/uu_Top_alpha.root");
    TFile *uu_Dibosonprocess = new TFile("./diboson/uu_Diboson_alpha.root");
    TFile *uu_Tribosonprocess = new TFile("./triboson/uu_Triboson_alpha.root");

    //-----------
    // For alpha
    //-----------
    TH1D *ee_HT_alpha = ((TH1D *)ee_DYprocess->Get("h_bg_alpha1"));
    TH1D *ee_Top_alpha = ((TH1D *)ee_Topprocess->Get("h_bg_alpha1"));
    TH1D *ee_Diboson_alpha = ((TH1D *)ee_Dibosonprocess->Get("h_bg_alpha1"));
    TH1D *ee_Triboson_alpha = ((TH1D *)ee_Tribosonprocess->Get("h_bg_alpha1"));
    TH1D *ee_Sig1_alpha = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_alpha"));
    TH1D *ee_Sig50_alpha = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_alpha"));
    TH1D *ee_Sig150_alpha = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_alpha"));

    TH1D *ee_HT_alpha2 = ((TH1D *)ee_DYprocess->Get("h_bg_alpha2"));
    TH1D *ee_Top_alpha2 = ((TH1D *)ee_Topprocess->Get("h_bg_alpha2"));
    TH1D *ee_Diboson_alpha2 = ((TH1D *)ee_Dibosonprocess->Get("h_bg_alpha2"));
    TH1D *ee_Triboson_alpha2 = ((TH1D *)ee_Tribosonprocess->Get("h_bg_alpha2"));
    TH1D *ee_Sig1_alpha2 = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_alpha2"));
    TH1D *ee_Sig50_alpha2 = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_alpha2"));
    TH1D *ee_Sig150_alpha2 = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_alpha2"));

    TH1D *ee_HT_alpha3 = ((TH1D *)ee_DYprocess->Get("h_bg_alpha3"));
    TH1D *ee_Top_alpha3 = ((TH1D *)ee_Topprocess->Get("h_bg_alpha3"));
    TH1D *ee_Diboson_alpha3 = ((TH1D *)ee_Dibosonprocess->Get("h_bg_alpha3"));
    TH1D *ee_Triboson_alpha3 = ((TH1D *)ee_Tribosonprocess->Get("h_bg_alpha3"));
    TH1D *ee_Sig1_alpha3 = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_alpha3"));
    TH1D *ee_Sig50_alpha3 = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_alpha3"));
    TH1D *ee_Sig150_alpha3 = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_alpha3"));

    TH1D *ee_HT_alpha4 = ((TH1D *)ee_DYprocess->Get("h_bg_alpha4"));
    TH1D *ee_Top_alpha4 = ((TH1D *)ee_Topprocess->Get("h_bg_alpha4"));
    TH1D *ee_Diboson_alpha4 = ((TH1D *)ee_Dibosonprocess->Get("h_bg_alpha4"));
    TH1D *ee_Triboson_alpha4 = ((TH1D *)ee_Tribosonprocess->Get("h_bg_alpha4"));
    TH1D *ee_Sig1_alpha4 = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_alpha4"));
    TH1D *ee_Sig50_alpha4 = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_alpha4"));
    TH1D *ee_Sig150_alpha4 = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_alpha4"));

    TH1D *uu_HT_alpha = ((TH1D *)uu_DYprocess->Get("h_bg_alpha1"));
    TH1D *uu_Top_alpha = ((TH1D *)uu_Topprocess->Get("h_bg_alpha1"));
    TH1D *uu_Diboson_alpha = ((TH1D *)uu_Dibosonprocess->Get("h_bg_alpha1"));
    TH1D *uu_Triboson_alpha = ((TH1D *)uu_Tribosonprocess->Get("h_bg_alpha1"));
    TH1D *uu_Sig1_alpha = ((TH1D *)uu_Sigfile->Get("h_Mx2_1_alpha"));
    TH1D *uu_Sig50_alpha = ((TH1D *)uu_Sigfile->Get("h_Mx2_50_alpha"));
    TH1D *uu_Sig150_alpha = ((TH1D *)uu_Sigfile->Get("h_Mx2_150_alpha"));

    TH1D *uu_HT_alpha2 = ((TH1D *)uu_DYprocess->Get("h_bg_alpha2"));
    TH1D *uu_Top_alpha2 = ((TH1D *)uu_Topprocess->Get("h_bg_alpha2"));
    TH1D *uu_Diboson_alpha2 = ((TH1D *)uu_Dibosonprocess->Get("h_bg_alpha2"));
    TH1D *uu_Triboson_alpha2 = ((TH1D *)uu_Tribosonprocess->Get("h_bg_alpha2"));
    TH1D *uu_Sig1_alpha2 = ((TH1D *)uu_Sigfile->Get("h_Mx2_1_alpha2"));
    TH1D *uu_Sig50_alpha2 = ((TH1D *)uu_Sigfile->Get("h_Mx2_50_alpha2"));
    TH1D *uu_Sig150_alpha2 = ((TH1D *)uu_Sigfile->Get("h_Mx2_150_alpha2"));

    TH1D *uu_HT_alpha3 = ((TH1D *)uu_DYprocess->Get("h_bg_alpha3"));
    TH1D *uu_Top_alpha3 = ((TH1D *)uu_Topprocess->Get("h_bg_alpha3"));
    TH1D *uu_Diboson_alpha3 = ((TH1D *)uu_Dibosonprocess->Get("h_bg_alpha3"));
    TH1D *uu_Triboson_alpha3 = ((TH1D *)uu_Tribosonprocess->Get("h_bg_alpha3"));
    TH1D *uu_Sig1_alpha3 = ((TH1D *)uu_Sigfile->Get("h_Mx2_1_alpha3"));
    TH1D *uu_Sig50_alpha3 = ((TH1D *)uu_Sigfile->Get("h_Mx2_50_alpha3"));
    TH1D *uu_Sig150_alpha3 = ((TH1D *)uu_Sigfile->Get("h_Mx2_150_alpha3"));

    TH1D *uu_HT_alpha4 = ((TH1D *)uu_DYprocess->Get("h_bg_alpha4"));
    TH1D *uu_Top_alpha4 = ((TH1D *)uu_Topprocess->Get("h_bg_alpha4"));
    TH1D *uu_Diboson_alpha4 = ((TH1D *)uu_Dibosonprocess->Get("h_bg_alpha4"));
    TH1D *uu_Triboson_alpha4 = ((TH1D *)uu_Tribosonprocess->Get("h_bg_alpha4"));
    TH1D *uu_Sig1_alpha4 = ((TH1D *)uu_Sigfile->Get("h_Mx2_1_alpha4"));
    TH1D *uu_Sig50_alpha4 = ((TH1D *)uu_Sigfile->Get("h_Mx2_50_alpha4"));
    TH1D *uu_Sig150_alpha4 = ((TH1D *)uu_Sigfile->Get("h_Mx2_150_alpha4"));

    //-----------
    // For 3Dsig
    //-----------
    TH1D *ee_HT_3Dsig = ((TH1D *)ee_DYprocess->Get("h_bg_3DSig"));
    TH1D *ee_Top_3Dsig = ((TH1D *)ee_Topprocess->Get("h_bg_3DSig"));
    TH1D *ee_Diboson_3Dsig = ((TH1D *)ee_Dibosonprocess->Get("h_bg_3DSig"));
    TH1D *ee_Triboson_3Dsig = ((TH1D *)ee_Tribosonprocess->Get("h_bg_3DSig"));
    TH1D *ee_Sig1_3Dsig = ((TH1D *)ee_Sigfile->Get("h_Mx2_1_3DSig"));
    TH1D *ee_Sig50_3Dsig = ((TH1D *)ee_Sigfile->Get("h_Mx2_50_3DSig"));
    TH1D *ee_Sig150_3Dsig = ((TH1D *)ee_Sigfile->Get("h_Mx2_150_3DSig"));

    TH1D *uu_HT_3Dsig = ((TH1D *)uu_DYprocess->Get("h_bg_3DSig"));
    TH1D *uu_Top_3Dsig = ((TH1D *)uu_Topprocess->Get("h_bg_3DSig"));
    TH1D *uu_Diboson_3Dsig = ((TH1D *)uu_Dibosonprocess->Get("h_bg_3DSig"));
    TH1D *uu_Triboson_3Dsig = ((TH1D *)uu_Tribosonprocess->Get("h_bg_3DSig"));
    TH1D *uu_Sig1_3Dsig = ((TH1D *)uu_Sigfile->Get("h_Mx2_1_3DSig"));
    TH1D *uu_Sig50_3Dsig = ((TH1D *)uu_Sigfile->Get("h_Mx2_50_3DSig"));
    TH1D *uu_Sig150_3Dsig = ((TH1D *)uu_Sigfile->Get("h_Mx2_150_3DSig"));

    //-------------------------
    // CMS style
    //-------------------------
    writeExtraText = true;
    extraText = "Simulation";
    lumi_sqrtS = "13 TeV";

    ee_HT_alpha->Add(ee_Top_alpha);
    ee_HT_alpha->Add(ee_Diboson_alpha);
    ee_HT_alpha->Add(ee_Triboson_alpha);

    ee_HT_alpha2->Add(ee_Top_alpha2);
    ee_HT_alpha2->Add(ee_Diboson_alpha2);
    ee_HT_alpha2->Add(ee_Triboson_alpha2);

    ee_HT_alpha3->Add(ee_Top_alpha3);
    ee_HT_alpha3->Add(ee_Diboson_alpha3);
    ee_HT_alpha3->Add(ee_Triboson_alpha3);

    ee_HT_alpha4->Add(ee_Top_alpha4);
    ee_HT_alpha4->Add(ee_Diboson_alpha4);
    ee_HT_alpha4->Add(ee_Triboson_alpha4);

    ee_HT_3Dsig->Add(ee_Top_3Dsig);
    ee_HT_3Dsig->Add(ee_Diboson_3Dsig);
    ee_HT_3Dsig->Add(ee_Triboson_3Dsig);

    uu_HT_alpha->Add(uu_Top_alpha);
    uu_HT_alpha->Add(uu_Diboson_alpha);
    uu_HT_alpha->Add(uu_Triboson_alpha);

    uu_HT_alpha2->Add(uu_Top_alpha2);
    uu_HT_alpha2->Add(uu_Diboson_alpha2);
    uu_HT_alpha2->Add(uu_Triboson_alpha2);

    uu_HT_alpha3->Add(uu_Top_alpha3);
    uu_HT_alpha3->Add(uu_Diboson_alpha3);
    uu_HT_alpha3->Add(uu_Triboson_alpha3);

    uu_HT_alpha4->Add(uu_Top_alpha4);
    uu_HT_alpha4->Add(uu_Diboson_alpha4);
    uu_HT_alpha4->Add(uu_Triboson_alpha4);

    uu_HT_3Dsig->Add(uu_Top_3Dsig);
    uu_HT_3Dsig->Add(uu_Diboson_3Dsig);
    uu_HT_3Dsig->Add(uu_Triboson_3Dsig);

    ee_HT_alpha->SetLineColor(kOrange - 3);
    // ee_HT_alpha->SetFillColor(kOrange - 3);

    ee_HT_alpha2->SetLineColor(kOrange - 3);
    // ee_HT_alpha2->SetFillColor(kOrange - 3);

    ee_HT_alpha3->SetLineColor(kOrange - 3);
    // ee_HT_alpha3->SetFillColor(kOrange - 3);

    ee_HT_alpha4->SetLineColor(kOrange - 3);
    // ee_HT_alpha4->SetFillColor(kOrange - 3);

    uu_HT_alpha->SetLineColor(kOrange - 3);
    uu_HT_alpha->SetFillColor(kOrange - 3);
    uu_HT_alpha->SetFillStyle(3001);

    uu_HT_alpha2->SetLineColor(kOrange - 3);
    uu_HT_alpha2->SetFillColor(kOrange - 3);
    uu_HT_alpha2->SetFillStyle(3001);

    uu_HT_alpha3->SetLineColor(kOrange - 3);
    uu_HT_alpha3->SetFillColor(kOrange - 3);
    uu_HT_alpha3->SetFillStyle(3001);

    uu_HT_alpha4->SetLineColor(kOrange - 3);
    uu_HT_alpha4->SetFillColor(kOrange - 3);
    uu_HT_alpha4->SetFillStyle(3001);

    ee_HT_3Dsig->SetLineColor(kOrange - 3);
    ee_HT_3Dsig->SetFillColor(kOrange - 3);
    ee_HT_3Dsig->SetFillStyle(3001);

    uu_HT_3Dsig->SetLineColor(kOrange - 3);
    uu_HT_3Dsig->SetFillColor(kOrange - 3);
    uu_HT_3Dsig->SetFillStyle(3001);

    ee_Sig1_alpha->SetLineColor(kRed);
    ee_Sig50_alpha->SetLineColor(kGray + 2);
    ee_Sig150_alpha->SetLineColor(kBlue);

    ee_Sig1_alpha2->SetLineColor(kRed);
    ee_Sig50_alpha2->SetLineColor(kGray + 2);
    ee_Sig150_alpha2->SetLineColor(kBlue);

    ee_Sig1_alpha3->SetLineColor(kRed);
    ee_Sig50_alpha3->SetLineColor(kGray + 2);
    ee_Sig150_alpha3->SetLineColor(kBlue);

    ee_Sig1_alpha4->SetLineColor(kRed);
    ee_Sig50_alpha4->SetLineColor(kGray + 2);
    ee_Sig150_alpha4->SetLineColor(kBlue);

    ee_Sig1_3Dsig->SetLineColor(kRed);
    ee_Sig50_3Dsig->SetLineColor(kGray + 2);
    ee_Sig150_3Dsig->SetLineColor(kBlue);

    uu_Sig1_alpha->SetLineColor(kRed);
    uu_Sig50_alpha->SetLineColor(kGray + 2);
    uu_Sig150_alpha->SetLineColor(kBlue);

    uu_Sig1_alpha2->SetLineColor(kRed);
    uu_Sig50_alpha2->SetLineColor(kGray + 2);
    uu_Sig150_alpha2->SetLineColor(kBlue);

    uu_Sig1_alpha3->SetLineColor(kRed);
    uu_Sig50_alpha3->SetLineColor(kGray + 2);
    uu_Sig150_alpha3->SetLineColor(kBlue);

    uu_Sig1_alpha4->SetLineColor(kRed);
    uu_Sig50_alpha4->SetLineColor(kGray + 2);
    uu_Sig150_alpha4->SetLineColor(kBlue);

    uu_Sig1_3Dsig->SetLineColor(kRed);
    uu_Sig50_3Dsig->SetLineColor(kGray + 2);
    uu_Sig150_3Dsig->SetLineColor(kBlue);

    ee_HT_alpha->SetLineWidth(2);
    ee_HT_alpha->SetFillColor(kOrange - 3);
    ee_HT_alpha->SetFillStyle(3001);

    ee_HT_alpha2->SetLineWidth(2);
    ee_HT_alpha2->SetFillColor(kOrange - 3);
    ee_HT_alpha2->SetFillStyle(3001);

    ee_HT_alpha3->SetLineWidth(2);
    ee_HT_alpha3->SetFillColor(kOrange - 3);
    ee_HT_alpha3->SetFillStyle(3001);

    ee_HT_alpha4->SetLineWidth(2);
    ee_HT_alpha4->SetFillColor(kOrange - 3);
    ee_HT_alpha4->SetFillStyle(3001);

    uu_HT_alpha->SetLineWidth(2);
    uu_HT_alpha->SetLineWidth(2);

    uu_HT_alpha2->SetLineWidth(2);
    uu_HT_alpha2->SetLineWidth(2);

    uu_HT_alpha3->SetLineWidth(2);
    uu_HT_alpha3->SetLineWidth(2);

    uu_HT_alpha4->SetLineWidth(2);
    uu_HT_alpha4->SetLineWidth(2);

    ee_Sig1_alpha->SetLineWidth(2);
    ee_Sig50_alpha->SetLineWidth(2);
    ee_Sig150_alpha->SetLineWidth(2);

    ee_Sig1_alpha2->SetLineWidth(2);
    ee_Sig50_alpha2->SetLineWidth(2);
    ee_Sig150_alpha2->SetLineWidth(2);

    ee_Sig1_alpha3->SetLineWidth(2);
    ee_Sig50_alpha3->SetLineWidth(2);
    ee_Sig150_alpha3->SetLineWidth(2);

    ee_Sig1_alpha4->SetLineWidth(2);
    ee_Sig50_alpha4->SetLineWidth(2);
    ee_Sig150_alpha4->SetLineWidth(2);

    uu_Sig1_alpha->SetLineWidth(2);
    uu_Sig50_alpha->SetLineWidth(2);
    uu_Sig150_alpha->SetLineWidth(2);

    uu_Sig1_alpha2->SetLineWidth(2);
    uu_Sig50_alpha2->SetLineWidth(2);
    uu_Sig150_alpha2->SetLineWidth(2);

    uu_Sig1_alpha3->SetLineWidth(2);
    uu_Sig50_alpha3->SetLineWidth(2);
    uu_Sig150_alpha3->SetLineWidth(2);

    uu_Sig1_alpha4->SetLineWidth(2);
    uu_Sig50_alpha4->SetLineWidth(2);
    uu_Sig150_alpha4->SetLineWidth(2);

    ee_HT_3Dsig->SetLineWidth(2);
    uu_HT_3Dsig->SetLineWidth(2);

    ee_Sig1_3Dsig->SetLineWidth(2);
    ee_Sig50_3Dsig->SetLineWidth(2);
    ee_Sig150_3Dsig->SetLineWidth(2);

    uu_Sig1_3Dsig->SetLineWidth(2);
    uu_Sig50_3Dsig->SetLineWidth(2);
    uu_Sig150_3Dsig->SetLineWidth(2);

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
    // canv->Divide(2, 2);
    // canv->cd(1);
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
    cout << "number of Events with DY = " << ee_HT_Met->Integral() << "\n";
    cout << "number of Events with Top = " << ee_Top_Met->Integral() << "\n";
    cout << "number of Events with Diboson = " << ee_Diboson_Met->Integral() << "\n";
    cout << "number of Events with Triboson = " << ee_Triboson_Met->Integral() << "\n";
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
    // canv->cd(2);
    
        ee_HT_alpha3->GetXaxis()->SetNdivisions(6, 5, 0);
        ee_HT_alpha3->GetXaxis()->SetTitleOffset(1.5);
        ee_HT_alpha3->GetXaxis()->SetTitle("#alpha_{3D}");
        ee_HT_alpha3->GetYaxis()->SetNdivisions(6, 5, 0);
        ee_HT_alpha3->GetYaxis()->SetTitleOffset(1.5);
        // uu_HT_alpha2->GetYaxis()->SetRangeUser(-0.1,0.5);
        ee_HT_alpha3->GetYaxis()->SetTitle("nJets / Normalized");

        uu_Sig150_alpha3->DrawNormalized("h same");
        uu_HT_alpha3->DrawNormalized("h same");
        
        //ee_Sig50_alpha3->DrawNormalized("h same");
        //uu_Sig1_alpha3->DrawNormalized("h same");

    
    /*
    uu_Sig1_3Dsig->GetXaxis()->SetNdivisions(6, 5, 0);
    uu_Sig1_3Dsig->GetXaxis()->SetTitleOffset(1.5);
    uu_Sig1_3Dsig->GetXaxis()->SetTitle("log_{10}(3D_{sig})");
    uu_Sig1_3Dsig->GetYaxis()->SetNdivisions(6, 5, 0);
    uu_Sig1_3Dsig->GetYaxis()->SetTitleOffset(1.5);
    // uu_HT_alpha2->GetYaxis()->SetRangeUser(-0.1,0.5);
    uu_Sig1_3Dsig->GetYaxis()->SetTitle("nTracks / Normalized");

    uu_Sig1_3Dsig->DrawNormalized("h same");
    uu_HT_3Dsig->DrawNormalized("h same");

    uu_Sig50_3Dsig->DrawNormalized("h same");
    uu_Sig150_3Dsig->DrawNormalized("h same");

    */
    TLegend *l1 = new TLegend(0.4, 0.4, 0.90, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(ee_HT_alpha2, "2016 MC background", "f");
    l1->AddEntry(ee_Sig1_alpha2, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(ee_Sig50_alpha2, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(ee_Sig150_alpha2, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();

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
