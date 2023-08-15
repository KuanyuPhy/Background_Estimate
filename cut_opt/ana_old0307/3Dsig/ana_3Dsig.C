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
#include "/home/kuanyu/Documents/CMS/Background_Estimate/lib/Cross_section.h"
// #include "./../../lib/setNCUStyle.C"
#include "/home/kuanyu/Documents/CMS/Background_Estimate/lib/tdrstyle.C"
#include "/home/kuanyu/Documents/CMS/Background_Estimate/lib/CMS_lumi.h"

using namespace std;
void ana_3Dsig(TString inputfile = "./DY/ee_DY_alpha.root")
{

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

    TH1D *ee_HT_alpha_metcut = ((TH1D *)ee_DYprocess->Get("h_bg_alpha1_metcut"));
    TH1D *ee_Top_alpha_metcut = ((TH1D *)ee_Topprocess->Get("h_bg_alpha1_metcut"));
    TH1D *ee_Diboson_alpha_metcut = ((TH1D *)ee_Dibosonprocess->Get("h_bg_alpha1_metcut"));
    TH1D *ee_Triboson_alpha_metcut = ((TH1D *)ee_Tribosonprocess->Get("h_bg_alpha1_metcut"));

    TH1D *ee_Top_heav_alpha_metcut = ((TH1D *)ee_Topprocess->Get("h_bg_bcalpha1_metcut"));
    TH1D *ee_Top_light_alpha_metcut = ((TH1D *)ee_Topprocess->Get("h_bg_lalpha1_metcut"));

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

    TH1D *h_ee_3Dsig2016MCbg = (TH1D *)ee_HT_3Dsig->Clone("h_ee_3Dsig2016MCbg");
    h_ee_3Dsig2016MCbg->Add(ee_Top_3Dsig);
    h_ee_3Dsig2016MCbg->Add(ee_Diboson_3Dsig);
    h_ee_3Dsig2016MCbg->Add(ee_Triboson_3Dsig);

    TH1D *h_ee_alpha2016MCbg = (TH1D *)ee_HT_alpha->Clone("h_ee_alpha2016MCbg");
    h_ee_alpha2016MCbg->Add(ee_Top_alpha);
    h_ee_alpha2016MCbg->Add(ee_Diboson_alpha);
    h_ee_alpha2016MCbg->Add(ee_Triboson_alpha);

    TH1D *h_ee_alpha22016MCbg = (TH1D *)ee_HT_alpha2->Clone("h_ee_alpha22016MCbg");
    h_ee_alpha22016MCbg->Add(ee_Top_alpha2);
    h_ee_alpha22016MCbg->Add(ee_Diboson_alpha2);
    h_ee_alpha22016MCbg->Add(ee_Triboson_alpha2);

    TH1D *h_ee_alpha32016MCbg = (TH1D *)ee_HT_alpha3->Clone("h_ee_alpha32016MCbg");
    h_ee_alpha32016MCbg->Add(ee_Top_alpha3);
    h_ee_alpha32016MCbg->Add(ee_Diboson_alpha3);
    h_ee_alpha32016MCbg->Add(ee_Triboson_alpha3);

    TH1D *h_ee_alpha42016MCbg = (TH1D *)ee_HT_alpha4->Clone("h_ee_alpha42016MCbg");
    h_ee_alpha42016MCbg->Add(ee_Top_alpha4);
    h_ee_alpha42016MCbg->Add(ee_Diboson_alpha4);
    h_ee_alpha42016MCbg->Add(ee_Triboson_alpha4);

    ee_HT_alpha->SetLineWidth(2);
    ee_Top_alpha->SetLineWidth(2);
    ee_Diboson_alpha->SetLineWidth(2);
    ee_Triboson_alpha->SetLineWidth(2);

    ee_HT_alpha->SetFillColor(kOrange - 3);
    ee_Top_alpha->SetFillColor(kGreen + 3);
    ee_Diboson_alpha->SetFillColor(kAzure + 7);
    ee_Triboson_alpha->SetFillColor(kMagenta - 3);

    ee_HT_alpha->SetLineColor(kOrange - 3);
    ee_Top_alpha->SetLineColor(kGreen + 3);
    ee_Diboson_alpha->SetLineColor(kAzure + 7);
    ee_Triboson_alpha->SetLineColor(kMagenta - 3);

    ee_HT_alpha_metcut->SetLineWidth(2);
    ee_Top_alpha_metcut->SetLineWidth(2);
    ee_Diboson_alpha_metcut->SetLineWidth(2);
    ee_Triboson_alpha_metcut->SetLineWidth(2);

    ee_HT_alpha_metcut->SetFillColor(kOrange - 3);
    ee_Top_alpha_metcut->SetFillColor(kGreen + 3);
    ee_Diboson_alpha_metcut->SetFillColor(kAzure + 7);
    ee_Triboson_alpha_metcut->SetFillColor(kMagenta - 3);

    ee_HT_alpha_metcut->SetLineColor(kOrange - 3);
    ee_Top_alpha_metcut->SetLineColor(kGreen + 3);
    ee_Diboson_alpha_metcut->SetLineColor(kAzure + 7);
    ee_Triboson_alpha_metcut->SetLineColor(kMagenta - 3);

    ee_Top_heav_alpha_metcut->SetLineWidth(2);
    ee_Top_light_alpha_metcut->SetLineWidth(2);

    ee_Top_heav_alpha_metcut->SetLineColor(kRed);
    ee_Top_light_alpha_metcut->SetLineColor(kBlue);

    ee_Top_heav_alpha_metcut->SetMarkerColor(kRed);
    ee_Top_light_alpha_metcut->SetMarkerColor(kBlue);

    ee_Top_heav_alpha_metcut->SetMarkerStyle(20);
    ee_Top_light_alpha_metcut->SetMarkerStyle(21);

    /*Create THstack*/
    THStack *hs_ee_alpha2016MCbg = new THStack("hs_ee_alpha2016MCbg", "");
    hs_ee_alpha2016MCbg->Add(ee_HT_alpha_metcut);
    hs_ee_alpha2016MCbg->Add(ee_Top_alpha_metcut);
    hs_ee_alpha2016MCbg->Add(ee_Diboson_alpha_metcut);
    hs_ee_alpha2016MCbg->Add(ee_Triboson_alpha_metcut);

    /*
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
    */

    h_ee_alpha2016MCbg->SetLineColor(kGreen - 2);
    h_ee_alpha2016MCbg->SetFillColor(kGreen - 2);
    h_ee_alpha2016MCbg->SetFillStyle(3001);
    h_ee_alpha32016MCbg->SetLineColor(kGreen - 2);
    h_ee_alpha32016MCbg->SetFillColor(kGreen - 2);
    h_ee_alpha32016MCbg->SetFillStyle(3001);

    // ee_HT_alpha->SetFillColor(kOrange - 3);

    h_ee_alpha22016MCbg->SetLineColor(kOrange - 3);
    // ee_HT_alpha2->SetFillColor(kOrange - 3);

    // h_ee_alpha32016MCbg->SetLineColor(kOrange - 3);
    //  ee_HT_alpha3->SetFillColor(kOrange - 3);

    h_ee_alpha42016MCbg->SetLineColor(kOrange - 3);
    // ee_HT_alpha4->SetFillColor(kOrange - 3);

    uu_HT_alpha->SetLineColor(kGreen - 2);
    uu_HT_alpha->SetFillColor(kGreen - 2);
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

    h_ee_3Dsig2016MCbg->SetLineColor(kGreen - 2);
    h_ee_3Dsig2016MCbg->SetFillColor(kGreen - 2);
    h_ee_3Dsig2016MCbg->SetFillStyle(3001);

    uu_HT_3Dsig->SetLineColor(kGreen - 2);
    uu_HT_3Dsig->SetFillColor(kGreen - 2);
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

    // ee_HT_alpha->SetLineWidth(2);
    // ee_HT_alpha->SetFillColor(kGreen - 2);
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

    ee_Sig1_alpha3->SetLineWidth(2);
    ee_Sig50_alpha3->SetLineWidth(2);
    ee_Sig150_alpha3->SetLineWidth(2);

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

    h_ee_3Dsig2016MCbg->GetXaxis()->SetTitleSize(0.045);
    h_ee_3Dsig2016MCbg->GetXaxis()->SetLabelSize(0.045);
    h_ee_3Dsig2016MCbg->GetXaxis()->SetLabelOffset(0.02);
    h_ee_3Dsig2016MCbg->GetXaxis()->SetTitleOffset(1.3);
    h_ee_3Dsig2016MCbg->GetYaxis()->SetTitleSize(0.045);
    h_ee_3Dsig2016MCbg->GetYaxis()->SetLabelSize(0.045);
    h_ee_3Dsig2016MCbg->GetYaxis()->SetTitleOffset(1.4);
    h_ee_3Dsig2016MCbg->GetYaxis()->SetTitle("nTracks / Normalized");
    h_ee_3Dsig2016MCbg->GetXaxis()->SetTitle("log_{10}(#Chi_{3D})");
    h_ee_3Dsig2016MCbg->GetXaxis()->SetRangeUser(-4, 5);

    /*
    h_ee_3Dsig2016MCbg->DrawNormalized("h");
    ee_Sig1_3Dsig->DrawNormalized("h same");
    ee_Sig50_3Dsig->DrawNormalized("h same");
    ee_Sig150_3Dsig->DrawNormalized("h same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_ee_3Dsig2016MCbg, "2016 MC background", "f");
    l1->AddEntry(ee_Sig1_3Dsig, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(ee_Sig50_3Dsig, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(ee_Sig150_3Dsig, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */

    ee_Sig150_alpha3->GetXaxis()->SetTitleSize(0.045);
    ee_Sig150_alpha3->GetXaxis()->SetLabelSize(0.045);
    ee_Sig150_alpha3->GetXaxis()->SetLabelOffset(0.02);
    ee_Sig150_alpha3->GetXaxis()->SetTitleOffset(1.3);
    ee_Sig150_alpha3->GetYaxis()->SetTitleSize(0.045);
    ee_Sig150_alpha3->GetYaxis()->SetLabelSize(0.045);
    ee_Sig150_alpha3->GetYaxis()->SetTitleOffset(1.4);
    ee_Sig150_alpha3->GetYaxis()->SetTitle("nJets / Normalized");
    ee_Sig150_alpha3->GetXaxis()->SetTitle("#alpha_{3D}");

    /*
    ee_Sig150_alpha3->DrawNormalized("h");
    h_ee_alpha32016MCbg->DrawNormalized("h same");
    ee_Sig1_alpha3->DrawNormalized("h same");
    ee_Sig50_alpha3->DrawNormalized("h same");

    TLegend *l1 = new TLegend(0.3, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.04);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_ee_alpha32016MCbg, "2016 MC background", "f");
    l1->AddEntry(ee_Sig1_alpha3, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(ee_Sig50_alpha3, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(ee_Sig150_alpha3, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */

    ee_Sig50_alpha->GetXaxis()->SetTitleSize(0.045);
    ee_Sig50_alpha->GetXaxis()->SetLabelSize(0.045);
    ee_Sig50_alpha->GetXaxis()->SetLabelOffset(0.02);
    ee_Sig50_alpha->GetXaxis()->SetTitleOffset(1.3);
    ee_Sig50_alpha->GetYaxis()->SetTitleSize(0.045);
    ee_Sig50_alpha->GetYaxis()->SetLabelSize(0.045);
    ee_Sig50_alpha->GetYaxis()->SetTitleOffset(1.4);
    ee_Sig50_alpha->GetYaxis()->SetTitle("nJets / Normalized");
    ee_Sig50_alpha->GetXaxis()->SetTitle("#alpha_{3D}");

    /*
    ee_Sig50_alpha->DrawNormalized("h ");
    ee_Sig150_alpha->DrawNormalized("h same");
    h_ee_alpha2016MCbg->DrawNormalized("h same");
    ee_Sig1_alpha->DrawNormalized("h same");

    TLegend *l1 = new TLegend(0.3, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.04);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_ee_alpha2016MCbg, "2016 MC background", "f");
    l1->AddEntry(ee_Sig1_alpha, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(ee_Sig50_alpha, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(ee_Sig150_alpha, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */

    /*
    hs_ee_alpha2016MCbg->Draw("hist");

    hs_ee_alpha2016MCbg->GetXaxis()->SetTitleSize(0.045);
    hs_ee_alpha2016MCbg->GetXaxis()->SetLabelSize(0.045);
    hs_ee_alpha2016MCbg->GetXaxis()->SetLabelOffset(0.02);
    hs_ee_alpha2016MCbg->GetXaxis()->SetTitleOffset(1.3);
    hs_ee_alpha2016MCbg->GetXaxis()->SetTitle("alpha_{3D}");
    hs_ee_alpha2016MCbg->GetYaxis()->SetTitleSize(0.045);
    hs_ee_alpha2016MCbg->GetYaxis()->SetLabelSize(0.045);
    hs_ee_alpha2016MCbg->GetYaxis()->SetTitleOffset(1.4);
    hs_ee_alpha2016MCbg->GetYaxis()->SetTitle("nJets");

    TLegend *l0 = new TLegend(0.3, 0.60, 0.92, 0.88);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("2016 MC Background");
    l0->AddEntry(ee_HT_alpha_metcut, "Drell-Yan process", "f");
    l0->AddEntry(ee_Top_alpha_metcut, "Top process", "f");
    l0->AddEntry(ee_Diboson_alpha_metcut, "Diboson process", "f");
    l0->AddEntry(ee_Triboson_alpha_metcut, "Triboson process", "f");
    l0->Draw();
    */

    /*
    ee_Top_alpha_metcut->GetXaxis()->SetTitleSize(0.045);
    ee_Top_alpha_metcut->GetXaxis()->SetLabelSize(0.045);
    ee_Top_alpha_metcut->GetXaxis()->SetLabelOffset(0.02);
    ee_Top_alpha_metcut->GetXaxis()->SetTitleOffset(1.3);
    ee_Top_alpha_metcut->GetYaxis()->SetTitleSize(0.045);
    ee_Top_alpha_metcut->GetYaxis()->SetLabelSize(0.045);
    ee_Top_alpha_metcut->GetYaxis()->SetTitleOffset(1.4);
    ee_Top_alpha_metcut->GetYaxis()->SetTitle("nJets");
    ee_Top_alpha_metcut->GetXaxis()->SetTitle("#alpha_{3D}");
    ee_Top_alpha_metcut->Draw();

    TLegend *l1 = new TLegend(0.2, 0.6, 0.60, 0.90);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(ee_Top_alpha_metcut, "Top process", "l");
    l1->Draw();
    */
    /*
    ee_HT_alpha_metcut->GetXaxis()->SetTitleSize(0.045);
    ee_HT_alpha_metcut->GetXaxis()->SetLabelSize(0.045);
    ee_HT_alpha_metcut->GetXaxis()->SetLabelOffset(0.02);
    ee_HT_alpha_metcut->GetXaxis()->SetTitleOffset(1.3);
    ee_HT_alpha_metcut->GetYaxis()->SetTitleSize(0.045);
    ee_HT_alpha_metcut->GetYaxis()->SetLabelSize(0.045);
    ee_HT_alpha_metcut->GetYaxis()->SetTitleOffset(1.4);
    ee_HT_alpha_metcut->GetYaxis()->SetTitle("nJets");
    ee_HT_alpha_metcut->GetXaxis()->SetTitle("#alpha_{3D}");
    ee_HT_alpha_metcut->Draw();

    TLegend *l1 = new TLegend(0.2, 0.6, 0.60, 0.90);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(ee_HT_alpha_metcut, "Drell-Yan process", "l");
    l1->Draw();
    */
    /*
    ee_Diboson_alpha_metcut->GetXaxis()->SetTitleSize(0.045);
    ee_Diboson_alpha_metcut->GetXaxis()->SetLabelSize(0.045);
    ee_Diboson_alpha_metcut->GetXaxis()->SetLabelOffset(0.02);
    ee_Diboson_alpha_metcut->GetXaxis()->SetTitleOffset(1.3);
    ee_Diboson_alpha_metcut->GetYaxis()->SetTitleSize(0.045);
    ee_Diboson_alpha_metcut->GetYaxis()->SetLabelSize(0.045);
    ee_Diboson_alpha_metcut->GetYaxis()->SetTitleOffset(1.4);
    ee_Diboson_alpha_metcut->GetYaxis()->SetTitle("nJets");
    ee_Diboson_alpha_metcut->GetXaxis()->SetTitle("#alpha_{3D}");
    ee_Diboson_alpha_metcut->Draw();

    TLegend *l1 = new TLegend(0.2, 0.6, 0.60, 0.90);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(ee_Diboson_alpha_metcut, "Diboson process", "l");
    l1->Draw();
    */
    ee_Triboson_alpha_metcut->GetXaxis()->SetTitleSize(0.045);
    ee_Triboson_alpha_metcut->GetXaxis()->SetLabelSize(0.045);
    ee_Triboson_alpha_metcut->GetXaxis()->SetLabelOffset(0.02);
    ee_Triboson_alpha_metcut->GetXaxis()->SetTitleOffset(1.3);
    ee_Triboson_alpha_metcut->GetYaxis()->SetTitleSize(0.045);
    ee_Triboson_alpha_metcut->GetYaxis()->SetLabelSize(0.045);
    ee_Triboson_alpha_metcut->GetYaxis()->SetTitleOffset(1.4);
    ee_Triboson_alpha_metcut->GetYaxis()->SetTitle("nJets");
    ee_Triboson_alpha_metcut->GetXaxis()->SetTitle("#alpha_{3D}");
    /*
    ee_Triboson_alpha_metcut->Draw();

    TLegend *l1 = new TLegend(0.2, 0.6, 0.60, 0.90);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(ee_Triboson_alpha_metcut, "Triboson process", "l");
    l1->Draw();
    */
    /*
    ee_Top_alpha_metcut->DrawNormalized("");
    ee_Diboson_alpha_metcut->DrawNormalized(" same");
    ee_Triboson_alpha_metcut->DrawNormalized(" same");
    ee_HT_alpha_metcut->DrawNormalized(" same");
    */
    ee_Top_alpha_metcut->GetXaxis()->SetTitleSize(0.045);
    ee_Top_alpha_metcut->GetXaxis()->SetLabelSize(0.045);
    ee_Top_alpha_metcut->GetXaxis()->SetLabelOffset(0.02);
    ee_Top_alpha_metcut->GetXaxis()->SetTitleOffset(1.3);
    ee_Top_alpha_metcut->GetYaxis()->SetTitleSize(0.045);
    ee_Top_alpha_metcut->GetYaxis()->SetLabelSize(0.045);
    ee_Top_alpha_metcut->GetYaxis()->SetTitleOffset(1.4);
    ee_Top_alpha_metcut->GetYaxis()->SetTitle("nJets");
    ee_Top_alpha_metcut->GetXaxis()->SetTitle("#alpha_{3D}");

    ee_Top_alpha_metcut->Draw();
    ee_Top_heav_alpha_metcut->Draw("p same");
    ee_Top_light_alpha_metcut->Draw("p same");

    gPad->SetLogy();

    TLegend *l1 = new TLegend(0.2, 0.6, 0.70, 0.90);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(ee_Top_alpha_metcut, "All jet", "lEp");
    l1->AddEntry(ee_Top_heav_alpha_metcut, "heavy flavor", "lEp");
    l1->AddEntry(ee_Top_light_alpha_metcut, "light flavor", "lEp");
    l1->Draw();

    CMS_lumi((TPad *)canv, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");

    // gPad->SetLogy();

    // canv->cd(2);
    //  uu_HT_alpha2->GetYaxis()->SetRangeUser(-0.1,0.5);
    // uu_Sig150_alpha3->DrawNormalized("h same");
    // uu_HT_alpha3->DrawNormalized("h same");

    // ee_Sig50_alpha->DrawNormalized("h same");
    // ee_HT_alpha->DrawNormalized("h same");
    // ee_Sig1_alpha->DrawNormalized("h same");
    // ee_Sig150_alpha->DrawNormalized("h same");
    //  uu_Sig1_alpha3->DrawNormalized("h same");
    /*
            ee_HT_3Dsig->GetXaxis()->SetNdivisions(6, 5, 0);
            ee_HT_3Dsig->GetXaxis()->SetTitleOffset(1.5);
            ee_HT_3Dsig->GetXaxis()->SetTitle("log_{10}(#Chi_{3D})");
            ee_HT_3Dsig->GetYaxis()->SetNdivisions(6, 5, 0);
            ee_HT_3Dsig->GetYaxis()->SetTitleOffset(1.5);
            ee_HT_3Dsig->GetYaxis()->SetRangeUser(-0.02,0.17);
            ee_HT_3Dsig->GetYaxis()->SetTitle("nTracks / Normalized");

            ee_HT_3Dsig->Add(ee_Top_3Dsig);
            ee_HT_3Dsig->Add(ee_Diboson_3Dsig);
            ee_HT_3Dsig->Add(ee_Triboson_3Dsig);

            ee_HT_3Dsig->DrawNormalized("h same");


             TLegend *l1 = new TLegend(0.15, 0.4, 0.50, 0.80);
            l1->SetBorderSize(0);
            l1->SetFillStyle(0);
            l1->SetTextSize(0.03);
            l1->AddEntry(ee_HT_3Dsig, "2016 MC background", "f");
            l1->AddEntry(ee_Sig1_3Dsig, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
            l1->AddEntry(ee_Sig50_3Dsig, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
            l1->AddEntry(ee_Sig150_3Dsig, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
            l1->Draw();
            */

    /*     uu_HT_3Dsig->GetXaxis()->SetNdivisions(6, 5, 0);
        uu_HT_3Dsig->GetXaxis()->SetTitleOffset(1.5);
        uu_HT_3Dsig->GetXaxis()->SetTitle("log_{10}(#Chi_{3D})");
        uu_HT_3Dsig->GetYaxis()->SetNdivisions(6, 5, 0);
        uu_HT_3Dsig->GetYaxis()->SetTitleOffset(1.5);
        uu_HT_3Dsig->GetYaxis()->SetRangeUser(-0.02, 0.17);
        uu_HT_3Dsig->GetYaxis()->SetTitle("nTracks / Normalized");

        uu_HT_3Dsig->Add(uu_Top_3Dsig);
        uu_HT_3Dsig->Add(uu_Diboson_3Dsig);
        uu_HT_3Dsig->Add(uu_Triboson_3Dsig);

        uu_HT_3Dsig->DrawNormalized("h e same");
        uu_Sig1_3Dsig->DrawNormalized("h same");
        uu_Sig50_3Dsig->DrawNormalized("h same");
        uu_Sig150_3Dsig->DrawNormalized("h same");

        TLegend *l1 = new TLegend(0.15, 0.4, 0.50, 0.80);
        l1->SetBorderSize(0);
        l1->SetFillStyle(0);
        l1->SetTextSize(0.03);
        l1->AddEntry(uu_HT_3Dsig, "2016 MC background", "f");
        l1->AddEntry(uu_Sig1_3Dsig, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
        l1->AddEntry(uu_Sig50_3Dsig, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
        l1->AddEntry(uu_Sig150_3Dsig, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
        l1->Draw(); */
    /*
          ee_Sig50_alpha->GetXaxis()->SetNdivisions(6, 5, 0);
            ee_Sig50_alpha->GetXaxis()->SetTitleOffset(1.5);
            ee_Sig50_alpha->GetXaxis()->SetTitle("#alpha_{3D}");
            ee_Sig50_alpha->GetYaxis()->SetNdivisions(6, 5, 0);
            ee_Sig50_alpha->GetYaxis()->SetTitleOffset(1.5);
            ee_Sig50_alpha->GetYaxis()->SetTitle("nJets / Normalized");

            ee_Sig50_alpha->DrawNormalized("h same");
            ee_HT_alpha->DrawNormalized("h same");
            ee_Sig1_alpha->DrawNormalized("h same");
            ee_Sig150_alpha->DrawNormalized("h same");

            TLegend *l1 = new TLegend(0.3, 0.4, 0.50, 0.80);
            l1->SetBorderSize(0);
            l1->SetFillStyle(0);
            l1->SetTextSize(0.03);
            l1->AddEntry(ee_HT_alpha, "2016 MC background", "f");
            l1->AddEntry(ee_Sig1_alpha, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
            l1->AddEntry(ee_Sig50_alpha, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
            l1->AddEntry(ee_Sig150_alpha, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
            l1->Draw();
            */

    /* uu_Sig50_alpha->GetXaxis()->SetNdivisions(6, 5, 0);
    uu_Sig50_alpha->GetXaxis()->SetTitleOffset(1.5);
    uu_Sig50_alpha->GetXaxis()->SetTitle("#alpha_{3D}");
    uu_Sig50_alpha->GetYaxis()->SetNdivisions(6, 5, 0);
    uu_Sig50_alpha->GetYaxis()->SetTitleOffset(1.5);
    uu_Sig50_alpha->GetYaxis()->SetTitle("nJets / Normalized");

    uu_Sig50_alpha->DrawNormalized("h same");
    uu_HT_alpha->DrawNormalized("h same");
    uu_Sig1_alpha->DrawNormalized("h same");
    uu_Sig150_alpha->DrawNormalized("h same");

    TLegend *l1 = new TLegend(0.3, 0.4, 0.50, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(uu_HT_alpha, "2016 MC background", "f");
    l1->AddEntry(uu_Sig1_alpha, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(uu_Sig50_alpha, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(uu_Sig150_alpha, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw(); */

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
