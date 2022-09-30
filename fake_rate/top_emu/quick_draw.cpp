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

    TH1D *h_Top_JetPt_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_bybin_CR"));
    TH1D *h_Top_bJetPt_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_bybin_CR"));
    TH1D *h_Top_cJetPt_bybin_CR = ((TH1D *)Topfile->Get("h_Top_cJetPt_bybin_CR"));
    TH1D *h_Top_lJetPt_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_bybin_CR"));
    TH1D *h_Top_hJetPt_bybin_CR = ((TH1D *)Topfile->Get("h_Top_hJetPt_bybin_CR"));
    TH1D *h_Top_JetPt_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_SR"));
    TH1D *h_Top_bJetPt_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_SR"));
    TH1D *h_Top_cJetPt_SR = ((TH1D *)Topfile->Get("h_Top_cJetPt_SR"));
    TH1D *h_Top_lJetPt_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_SR"));
    TH1D *h_Top_hJetPt_SR = ((TH1D *)Topfile->Get("h_Top_hJetPt_SR"));
    TH1D *h_Top_JetPt_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_region1_bybin_CR"));
    TH1D *h_Top_JetPt_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_region2_bybin_CR"));
    TH1D *h_Top_JetPt_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetPt_region3_bybin_CR"));
    TH1D *h_Top_bJetPt_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region1_bybin_CR"));
    TH1D *h_Top_bJetPt_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region2_bybin_CR"));
    TH1D *h_Top_bJetPt_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region3_bybin_CR"));
    TH1D *h_Top_cJetPt_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_cJetPt_region1_bybin_CR"));
    TH1D *h_Top_cJetPt_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_cJetPt_region2_bybin_CR"));
    TH1D *h_Top_cJetPt_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_cJetPt_region3_bybin_CR"));
    TH1D *h_Top_lJetPt_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region1_bybin_CR"));
    TH1D *h_Top_lJetPt_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region2_bybin_CR"));
    TH1D *h_Top_lJetPt_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region3_bybin_CR"));
    TH1D *h_Top_hJetPt_region1_bybin_CR = ((TH1D *)Topfile->Get("h_Top_hJetPt_region1_bybin_CR"));
    TH1D *h_Top_hJetPt_region2_bybin_CR = ((TH1D *)Topfile->Get("h_Top_hJetPt_region2_bybin_CR"));
    TH1D *h_Top_hJetPt_region3_bybin_CR = ((TH1D *)Topfile->Get("h_Top_hJetPt_region3_bybin_CR"));

    TH1D *h_Top_JetPt_region1_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_region1_SR"));
    TH1D *h_Top_JetPt_region2_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_region2_SR"));
    TH1D *h_Top_JetPt_region3_SR = ((TH1D *)Topfile->Get("h_Top_JetPt_region3_SR"));
    TH1D *h_Top_bJetPt_region1_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region1_SR"));
    TH1D *h_Top_bJetPt_region2_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region2_SR"));
    TH1D *h_Top_bJetPt_region3_SR = ((TH1D *)Topfile->Get("h_Top_bJetPt_region3_SR"));
    TH1D *h_Top_cJetPt_region1_SR = ((TH1D *)Topfile->Get("h_Top_cJetPt_region1_SR"));
    TH1D *h_Top_cJetPt_region2_SR = ((TH1D *)Topfile->Get("h_Top_cJetPt_region2_SR"));
    TH1D *h_Top_cJetPt_region3_SR = ((TH1D *)Topfile->Get("h_Top_cJetPt_region3_SR"));
    TH1D *h_Top_lJetPt_region1_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region1_SR"));
    TH1D *h_Top_lJetPt_region2_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region2_SR"));
    TH1D *h_Top_lJetPt_region3_SR = ((TH1D *)Topfile->Get("h_Top_lJetPt_region3_SR"));
    TH1D *h_Top_hJetPt_region1_SR = ((TH1D *)Topfile->Get("h_Top_hJetPt_region1_SR"));
    TH1D *h_Top_hJetPt_region2_SR = ((TH1D *)Topfile->Get("h_Top_hJetPt_region2_SR"));
    TH1D *h_Top_hJetPt_region3_SR = ((TH1D *)Topfile->Get("h_Top_hJetPt_region3_SR"));

    //--------------------
    TH1D *h_Top_JetEta_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetEta_bybin_CR"));
    TH1D *h_Top_bJetEta_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetEta_bybin_CR"));
    TH1D *h_Top_cJetEta_bybin_CR = ((TH1D *)Topfile->Get("h_Top_cJetEta_bybin_CR"));
    TH1D *h_Top_lJetEta_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetEta_bybin_CR"));
    TH1D *h_Top_hJetEta_bybin_CR = ((TH1D *)Topfile->Get("h_Top_hJetEta_bybin_CR"));
    TH1D *h_Top_JetEta_SR = ((TH1D *)Topfile->Get("h_Top_JetEta_SR"));
    TH1D *h_Top_bJetEta_SR = ((TH1D *)Topfile->Get("h_Top_bJetEta_SR"));
    TH1D *h_Top_cJetEta_SR = ((TH1D *)Topfile->Get("h_Top_cJetEta_SR"));
    TH1D *h_Top_lJetEta_SR = ((TH1D *)Topfile->Get("h_Top_lJetEta_SR"));
    TH1D *h_Top_hJetEta_SR = ((TH1D *)Topfile->Get("h_Top_hJetEta_SR"));
    TH1D *h_Top_JetEta_diffregion_bybin_CR = ((TH1D *)Topfile->Get("h_Top_JetEta_diffregion_bybin_CR"));
    TH1D *h_Top_bJetEta_diffregion_bybin_CR = ((TH1D *)Topfile->Get("h_Top_bJetEta_diffregion_bybin_CR"));
    TH1D *h_Top_cJetEta_diffregion_bybin_CR = ((TH1D *)Topfile->Get("h_Top_cJetEta_diffregion_bybin_CR"));
    TH1D *h_Top_lJetEta_diffregion_bybin_CR = ((TH1D *)Topfile->Get("h_Top_lJetEta_diffregion_bybin_CR"));
    TH1D *h_Top_hJetEta_diffregion_bybin_CR = ((TH1D *)Topfile->Get("h_Top_hJetEta_diffregion_bybin_CR"));

    TH1D *h_Top_JetEta_diffregion_SR = ((TH1D *)Topfile->Get("h_Top_JetEta_diffregion_SR"));
    TH1D *h_Top_bJetEta_diffregion_SR = ((TH1D *)Topfile->Get("h_Top_bJetEta_diffregion_SR"));
    TH1D *h_Top_cJetEta_diffregion_SR = ((TH1D *)Topfile->Get("h_Top_cJetEta_diffregion_SR"));
    TH1D *h_Top_lJetEta_diffregion_SR = ((TH1D *)Topfile->Get("h_Top_lJetEta_diffregion_SR"));
    TH1D *h_Top_hJetEta_diffregion_SR = ((TH1D *)Topfile->Get("h_Top_hJetEta_diffregion_SR"));

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

    h_Top_JetPt_bybin_CR->SetLineWidth(2);
    h_Top_bJetPt_bybin_CR->SetLineWidth(2);
    h_Top_cJetPt_bybin_CR->SetLineWidth(2);
    h_Top_lJetPt_bybin_CR->SetLineWidth(2);
    h_Top_hJetPt_bybin_CR->SetLineWidth(2);
    h_Top_JetPt_SR->SetLineWidth(2);
    h_Top_bJetPt_SR->SetLineWidth(2);
    h_Top_cJetPt_SR->SetLineWidth(2);
    h_Top_lJetPt_SR->SetLineWidth(2);
    h_Top_hJetPt_SR->SetLineWidth(2);
    h_Top_JetPt_region1_bybin_CR->SetLineWidth(2);
    h_Top_JetPt_region2_bybin_CR->SetLineWidth(2);
    h_Top_JetPt_region3_bybin_CR->SetLineWidth(2);
    h_Top_bJetPt_region1_bybin_CR->SetLineWidth(2);
    h_Top_bJetPt_region2_bybin_CR->SetLineWidth(2);
    h_Top_bJetPt_region3_bybin_CR->SetLineWidth(2);
    h_Top_cJetPt_region1_bybin_CR->SetLineWidth(2);
    h_Top_cJetPt_region2_bybin_CR->SetLineWidth(2);
    h_Top_cJetPt_region3_bybin_CR->SetLineWidth(2);
    h_Top_lJetPt_region1_bybin_CR->SetLineWidth(2);
    h_Top_lJetPt_region2_bybin_CR->SetLineWidth(2);
    h_Top_lJetPt_region3_bybin_CR->SetLineWidth(2);
    h_Top_hJetPt_region1_bybin_CR->SetLineWidth(2);
    h_Top_hJetPt_region2_bybin_CR->SetLineWidth(2);
    h_Top_hJetPt_region3_bybin_CR->SetLineWidth(2);

    h_Top_JetPt_region1_SR->SetLineWidth(2);
    h_Top_JetPt_region2_SR->SetLineWidth(2);
    h_Top_JetPt_region3_SR->SetLineWidth(2);
    h_Top_bJetPt_region1_SR->SetLineWidth(2);
    h_Top_bJetPt_region2_SR->SetLineWidth(2);
    h_Top_bJetPt_region3_SR->SetLineWidth(2);
    h_Top_cJetPt_region1_SR->SetLineWidth(2);
    h_Top_cJetPt_region2_SR->SetLineWidth(2);
    h_Top_cJetPt_region3_SR->SetLineWidth(2);
    h_Top_lJetPt_region1_SR->SetLineWidth(2);
    h_Top_lJetPt_region2_SR->SetLineWidth(2);
    h_Top_lJetPt_region3_SR->SetLineWidth(2);
    h_Top_hJetPt_region1_SR->SetLineWidth(2);
    h_Top_hJetPt_region2_SR->SetLineWidth(2);
    h_Top_hJetPt_region3_SR->SetLineWidth(2);

    //--------------------
    h_Top_JetEta_bybin_CR->SetLineWidth(2);
    h_Top_bJetEta_bybin_CR->SetLineWidth(2);
    h_Top_cJetEta_bybin_CR->SetLineWidth(2);
    h_Top_lJetEta_bybin_CR->SetLineWidth(2);
    h_Top_hJetEta_bybin_CR->SetLineWidth(2);
    h_Top_JetEta_SR->SetLineWidth(2);
    h_Top_bJetEta_SR->SetLineWidth(2);
    h_Top_cJetEta_SR->SetLineWidth(2);
    h_Top_lJetEta_SR->SetLineWidth(2);
    h_Top_hJetEta_SR->SetLineWidth(2);
    h_Top_JetEta_diffregion_bybin_CR->SetLineWidth(2);
    h_Top_bJetEta_diffregion_bybin_CR->SetLineWidth(2);
    h_Top_cJetEta_diffregion_bybin_CR->SetLineWidth(2);
    h_Top_lJetEta_diffregion_bybin_CR->SetLineWidth(2);
    h_Top_hJetEta_diffregion_bybin_CR->SetLineWidth(2);

    h_Top_JetEta_diffregion_SR->SetLineWidth(2);
    h_Top_bJetEta_diffregion_SR->SetLineWidth(2);
    h_Top_cJetEta_diffregion_SR->SetLineWidth(2);
    h_Top_lJetEta_diffregion_SR->SetLineWidth(2);
    h_Top_hJetEta_diffregion_SR->SetLineWidth(2);

    h_Top_trk_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_btrk_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_ctrk_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_ltrk_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_htrk_bybin_CR->SetLineColor(kGreen + 3);

    h_Top_trk_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_trk_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_trk_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_btrk_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_btrk_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_btrk_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_ctrk_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_ctrk_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_ctrk_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_ltrk_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_ltrk_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_ltrk_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_htrk_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_htrk_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_htrk_region3_bybin_CR->SetLineColor(kGreen + 3);

    h_Top_JetPt_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_bJetPt_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_cJetPt_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_lJetPt_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_hJetPt_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_JetPt_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_JetPt_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_JetPt_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_bJetPt_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_bJetPt_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_bJetPt_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_cJetPt_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_cJetPt_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_cJetPt_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_lJetPt_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_lJetPt_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_lJetPt_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_hJetPt_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_hJetPt_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_hJetPt_region3_bybin_CR->SetLineColor(kGreen + 3);

    //--------------------
    h_Top_JetEta_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_bJetEta_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_cJetEta_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_lJetEta_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_hJetEta_bybin_CR->SetLineColor(kGreen + 3);

    h_Top_JetEta_diffregion_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_bJetEta_diffregion_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_cJetEta_diffregion_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_lJetEta_diffregion_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_hJetEta_diffregion_bybin_CR->SetLineColor(kGreen + 3);

    h_Top_btrk_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_ctrk_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_ltrk_bybin_CR->GetXaxis()->SetTitle("nTrk");

    h_Top_ltrk_region1_SR->GetXaxis()->SetTitle("nTrk");
    h_Top_ltrk_region1_SR->GetYaxis()->SetTitle("nJet");

    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_btrk_region1_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_btrk_region2_SR->GetXaxis()->SetTitle("nTrk");
    h_Top_btrk_region2_SR->GetYaxis()->SetTitle("nJet");

    h_Top_btrk_region3_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_btrk_region3_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_ltrk_region2_SR->GetXaxis()->SetTitle("nTrk");
    h_Top_ltrk_region2_SR->GetYaxis()->SetTitle("nJet");

    h_Top_ltrk_region3_bybin_CR->GetXaxis()->SetTitle("nTrk");
    h_Top_ltrk_region3_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_bJetPt_bybin_CR->GetXaxis()->SetTitle("JetPt");

    h_Top_bJetPt_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_cJetPt_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_SR->GetXaxis()->SetTitle("JetPt");

    h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_bJetPt_region3_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetTitle("JetPt");

    h_Top_cJetPt_region1_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_cJetPt_region1_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_cJetPt_region2_SR->GetXaxis()->SetTitle("JetPt");

    h_Top_cJetPt_region2_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_region1_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_region2_SR->GetXaxis()->SetTitle("JetPt");

    h_Top_cJetPt_region3_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_cJetPt_region3_bybin_CR->GetXaxis()->SetTitle("JetPt");

    h_Top_lJetPt_region1_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_region2_bybin_CR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_region3_SR->GetXaxis()->SetTitle("JetPt");
    h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetTitle("JetPt");

    h_Top_bJetPt_region1_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_bJetPt_region2_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitle("nJets");
    h_Top_bJetPt_region3_bybin_CR->GetYaxis()->SetTitle("nJets");

    h_Top_cJetPt_region1_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_cJetPt_region1_SR->GetYaxis()->SetTitle("nJets");
    h_Top_cJetPt_region2_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_cJetPt_region2_SR->GetYaxis()->SetTitle("nJets");
    h_Top_cJetPt_region3_SR->GetYaxis()->SetTitle("nJets");
    h_Top_cJetPt_region3_bybin_CR->GetYaxis()->SetTitle("nJets");

    h_Top_lJetPt_region1_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region2_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_region3_bybin_CR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetPt_bybin_CR->GetYaxis()->SetTitle("nJets");

    h_Top_btrk_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_ctrk_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_ltrk_bybin_CR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetPt_SR->GetYaxis()->SetTitle("nJets");
    h_Top_cJetPt_SR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetPt_SR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetEta_diffregion_bybin_CR->GetXaxis()->SetTitle("Jet #eta");
    h_Top_cJetEta_diffregion_SR->GetXaxis()->SetTitle("Jet #eta");
    h_Top_lJetEta_diffregion_bybin_CR->GetXaxis()->SetTitle("Jet #eta");
    h_Top_bJetEta_diffregion_bybin_CR->GetYaxis()->SetTitle("nJets");
    h_Top_cJetEta_diffregion_SR->GetYaxis()->SetTitle("nJets");
    h_Top_lJetEta_diffregion_bybin_CR->GetYaxis()->SetTitle("nJets");

    auto c1 = new TCanvas("c1", "");
    /*
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
    */
    c1->Divide(3, 2);
    c1->cd(1);

    gPad->SetBottomMargin(0.02);

    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_btrk_region1_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_btrk_region1_bybin_CR->Draw("");
    h_Top_btrk_region1_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor , |#eta| < 1.");
    l0->SetTextSize(0.03);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_btrk_region1_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l0->AddEntry(h_Top_btrk_region1_SR, "SR", "El");
    l0->Draw();

    c1->cd(4);

    gPad->SetTopMargin(1);

    TH1D *h_btrk_rg1_CR_SR_ratio = (TH1D *)h_Top_btrk_region1_bybin_CR->Clone("h_btrk_rg1_CR_SR_ratio");
    h_btrk_rg1_CR_SR_ratio->Divide(h_Top_btrk_region1_bybin_CR, h_Top_btrk_region1_SR, 1, 1);

    h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_btrk_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_btrk_rg1_CR_SR_ratio->Draw();

    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_btrk_region2_SR->GetXaxis()->SetLabelSize(0);

    h_Top_btrk_region2_SR->Draw("h");
    h_Top_btrk_region2_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor , 1 < |#eta| < 2.");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_btrk_region2_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_btrk_region2_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);

    gPad->SetTopMargin(1);

    TH1D *h_btrk_rg2_CR_SR_ratio = (TH1D *)h_Top_btrk_region2_bybin_CR->Clone("h_btrk_rg2_CR_SR_ratio");
    h_btrk_rg2_CR_SR_ratio->Divide(h_Top_btrk_region2_bybin_CR, h_Top_btrk_region2_SR, 1, 1);

    h_btrk_rg2_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_btrk_rg2_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_btrk_rg2_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_btrk_rg2_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_btrk_region3_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_btrk_region3_bybin_CR->Draw(" ");
    h_Top_btrk_region3_SR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor , 2 < |#eta| < 2.5");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_btrk_region3_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_btrk_region3_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);

    gPad->SetTopMargin(1);

    TH1D *h_btrk_rg3_CR_SR_ratio = (TH1D *)h_Top_btrk_region3_bybin_CR->Clone("h_btrk_rg3_CR_SR_ratio");
    h_btrk_rg3_CR_SR_ratio->Divide(h_Top_btrk_region3_bybin_CR, h_Top_btrk_region3_SR, 1, 1);

    h_btrk_rg3_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_btrk_rg3_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_btrk_rg3_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_btrk_rg3_CR_SR_ratio->Draw();

    /*
    c1->Divide(3, 2);
    c1->cd(1);

    gPad->SetBottomMargin(0.02);

    h_Top_ltrk_region1_bybin_CR->GetXaxis()->SetLabelSize(0);
    h_Top_ltrk_region1_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_ltrk_region1_bybin_CR->Draw("");
    h_Top_ltrk_region1_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor , |#eta| < 1.");
    l0->SetTextSize(0.03);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_ltrk_region1_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l0->AddEntry(h_Top_ltrk_region1_SR, "SR", "El");
    l0->Draw();

    c1->cd(4);

    gPad->SetTopMargin(1);

    TH1D *h_ltrk_rg1_CR_SR_ratio = (TH1D *)h_Top_ltrk_region1_bybin_CR->Clone("h_ltrk_rg1_CR_SR_ratio");
    h_ltrk_rg1_CR_SR_ratio->Divide(h_Top_ltrk_region1_bybin_CR, h_Top_ltrk_region1_SR, 1, 1);

    h_ltrk_rg1_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_btrk_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_ltrk_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_ltrk_rg1_CR_SR_ratio->Draw();

    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_ltrk_region2_SR->GetXaxis()->SetLabelSize(0);

    h_Top_ltrk_region2_SR->Draw("h");
    h_Top_ltrk_region2_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor , 1 < |#eta| < 2.");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_ltrk_region2_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_ltrk_region2_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);

    gPad->SetTopMargin(1);

    TH1D *h_ltrk_rg2_CR_SR_ratio = (TH1D *)h_Top_ltrk_region2_bybin_CR->Clone("h_ltrk_rg2_CR_SR_ratio");
    h_ltrk_rg2_CR_SR_ratio->Divide(h_Top_ltrk_region2_bybin_CR, h_Top_ltrk_region2_SR, 1, 1);

    h_ltrk_rg2_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_ltrk_rg2_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_ltrk_rg2_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_ltrk_rg2_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_ltrk_region3_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_ltrk_region3_bybin_CR->Draw(" ");
    h_Top_ltrk_region3_SR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor , 2 < |#eta| < 2.5");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_ltrk_region3_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_ltrk_region3_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);

    gPad->SetTopMargin(1);

    TH1D *h_ltrk_rg3_CR_SR_ratio = (TH1D *)h_Top_ltrk_region3_bybin_CR->Clone("h_ltrk_rg3_CR_SR_ratio");
    h_ltrk_rg3_CR_SR_ratio->Divide(h_Top_ltrk_region3_bybin_CR, h_Top_ltrk_region3_SR, 1, 1);

    h_ltrk_rg3_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_ltrk_rg3_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_ltrk_rg3_CR_SR_ratio->GetXaxis()->SetTitle("Jet ntrk");

    h_ltrk_rg3_CR_SR_ratio->Draw();

    */

    /*
     c1->Divide(3, 1);
     c1->cd(1);
     h_Top_bJetPt_bybin_CR->Draw();
     h_Top_bJetPt_SR->Draw("h same");

     TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l0->SetHeader("b flavor");
     l0->AddEntry(h_Top_bJetPt_bybin_CR, "CR", "l");
     l0->AddEntry(h_Top_bJetPt_SR, "SR", "l");
     l0->Draw();

     c1->cd(2);
     h_Top_cJetPt_SR->Draw("");
     h_Top_cJetPt_bybin_CR->Draw("h same");

     TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l1->SetHeader("c flavor");
     l1->AddEntry(h_Top_cJetPt_bybin_CR, "CR", "l");
     l1->AddEntry(h_Top_cJetPt_SR, "SR", "l");
     l1->Draw();

     c1->cd(3);
     h_Top_lJetPt_SR->Draw("");
     h_Top_lJetPt_bybin_CR->Draw("h same");

     TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l2->SetHeader("light flavor");
     l2->AddEntry(h_Top_lJetPt_bybin_CR, "CR", "l");
     l2->AddEntry(h_Top_lJetPt_SR, "SR", "l");
     l2->Draw();
     */
    /*
    c1->Divide(3, 2);
    c1->cd(1);

    gPad->SetBottomMargin(0.02);

    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetPt_region1_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region1_SR->GetYaxis()->SetRangeUser(-0.2, 35);

    h_Top_bJetPt_region1_SR->Draw("h ");
    h_Top_bJetPt_region1_bybin_CR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetTextSize(0.03);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->AddEntry(h_Top_bJetPt_region1_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l0->AddEntry(h_Top_bJetPt_region1_SR, "SR", "El");
    l0->Draw();

    c1->cd(4);

    gPad->SetTopMargin(1);

    TH1D *h_bJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_bJetPt_region1_bybin_CR->Clone("h_bJetPt_rg1_CR_SR_ratio");
    h_bJetPt_rg1_CR_SR_ratio->Divide(h_Top_bJetPt_region1_bybin_CR, h_Top_bJetPt_region1_SR, 1, 1);

    h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    //h_bJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_bJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_bJetPt_rg1_CR_SR_ratio->Draw();

    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitle("nJets");

    h_Top_bJetPt_region2_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region2_SR->GetYaxis()->SetRangeUser(-0.2, 35);

    h_Top_bJetPt_region2_SR->Draw("h ");
    h_Top_bJetPt_region2_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_lJetPt_region2_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_lJetPt_region2_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);

    gPad->SetTopMargin(1);

    TH1D *h_bJetPt_rg2_CR_SR_ratio = (TH1D *)h_Top_bJetPt_region2_bybin_CR->Clone("h_bJetPt_rg2_CR_SR_ratio");
    h_bJetPt_rg2_CR_SR_ratio->Divide(h_Top_bJetPt_region2_bybin_CR, h_Top_bJetPt_region2_SR, 1, 1);

    h_bJetPt_rg2_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    //h_bJetPt_rg2_CR_SR_ratio->GetYaxis()->SetRangeUser(-20, 10);
    h_bJetPt_rg2_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_bJetPt_rg2_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_bJetPt_region3_SR->GetXaxis()->SetLabelSize(0);
    h_Top_bJetPt_region3_SR->GetYaxis()->SetRangeUser(-0.2, 10);

    h_Top_bJetPt_region3_SR->Draw("h ");
    h_Top_bJetPt_region3_bybin_CR->Draw(" same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_lJetPt_region3_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_lJetPt_region3_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);

    gPad->SetTopMargin(1);

    TH1D *h_bJetPt_rg3_CR_SR_ratio = (TH1D *)h_Top_bJetPt_region3_bybin_CR->Clone("h_bJetPt_rg3_CR_SR_ratio");
    h_bJetPt_rg3_CR_SR_ratio->Divide(h_Top_bJetPt_region3_bybin_CR, h_Top_bJetPt_region3_SR, 1, 1);

    h_bJetPt_rg3_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    //h_bJetPt_rg3_CR_SR_ratio->GetYaxis()->SetRangeUser(-20, 20);
    h_bJetPt_rg3_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_bJetPt_rg3_CR_SR_ratio->Draw();
    */

    /*
    c1->Divide(3, 2);
    c1->cd(1);

    gPad->SetBottomMargin(0.02);

    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitle("nJets");

    h_Top_lJetPt_region1_SR->GetXaxis()->SetLabelSize(0);
    //h_Top_lJetPt_region1_SR->GetYaxis()->SetRangeUser(-0.2, 35);

    h_Top_lJetPt_region1_SR->Draw("h ");
    h_Top_lJetPt_region1_bybin_CR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetTextSize(0.03);
    l0->SetFillStyle(0);
    l0->SetBorderSize(0);
    l0->AddEntry(h_Top_lJetPt_region1_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l0->AddEntry(h_Top_lJetPt_region1_SR, "SR", "El");
    l0->Draw();

    c1->cd(4);

    gPad->SetTopMargin(1);

    TH1D *h_lJetPt_rg1_CR_SR_ratio = (TH1D *)h_Top_lJetPt_region1_bybin_CR->Clone("h_lJetPt_rg1_CR_SR_ratio");
    h_lJetPt_rg1_CR_SR_ratio->Divide(h_Top_lJetPt_region1_bybin_CR, h_Top_lJetPt_region1_SR, 1, 1);

    h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_lJetPt_rg1_CR_SR_ratio->GetYaxis()->SetRangeUser(-50, 10);
    h_lJetPt_rg1_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_lJetPt_rg1_CR_SR_ratio->Draw();

    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitle("nJets");

    h_Top_lJetPt_region2_SR->GetXaxis()->SetLabelSize(0);
    //h_Top_lJetPt_region2_SR->GetYaxis()->SetRangeUser(-0.2, 35);

    h_Top_lJetPt_region2_SR->Draw("h ");
    h_Top_lJetPt_region2_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_lJetPt_region2_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_lJetPt_region2_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);

    gPad->SetTopMargin(1);

    TH1D *h_lJetPt_rg2_CR_SR_ratio = (TH1D *)h_Top_lJetPt_region2_bybin_CR->Clone("h_lJetPt_rg2_CR_SR_ratio");
    h_lJetPt_rg2_CR_SR_ratio->Divide(h_Top_lJetPt_region2_bybin_CR, h_Top_lJetPt_region2_SR, 1, 1);

    h_lJetPt_rg2_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_bJetPt_rg2_CR_SR_ratio->GetYaxis()->SetRangeUser(-20, 10);
    h_lJetPt_rg2_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_lJetPt_rg2_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_lJetPt_region3_SR->GetXaxis()->SetLabelSize(0);
    //h_Top_lJetPt_region3_SR->GetYaxis()->SetRangeUser(-0.2, 10);

    h_Top_lJetPt_region3_SR->Draw("h ");
    h_Top_lJetPt_region3_bybin_CR->Draw(" same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_lJetPt_region3_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_lJetPt_region3_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);

    gPad->SetTopMargin(1);

    TH1D *h_lJetPt_rg3_CR_SR_ratio = (TH1D *)h_Top_lJetPt_region3_bybin_CR->Clone("h_lJetPt_rg3_CR_SR_ratio");
    h_lJetPt_rg3_CR_SR_ratio->Divide(h_Top_lJetPt_region3_bybin_CR, h_Top_lJetPt_region3_SR, 1, 1);

    h_lJetPt_rg3_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_bJetPt_rg3_CR_SR_ratio->GetYaxis()->SetRangeUser(-20, 20);
    h_lJetPt_rg3_CR_SR_ratio->GetXaxis()->SetTitle("Jet PT");

    h_lJetPt_rg3_CR_SR_ratio->Draw();

    */
    /*
    c1->Divide(3, 2);
    c1->cd(1);

    gPad->SetBottomMargin(0.02);

    h_Top_bJetEta_diffregion_bybin_CR->GetXaxis()->SetLabelSize(0);

    h_Top_bJetEta_diffregion_bybin_CR->Draw("");

    h_Top_bJetEta_diffregion_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor");
    l0->SetTextSize(0.03);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->AddEntry(h_Top_bJetEta_diffregion_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l0->AddEntry(h_Top_bJetEta_diffregion_SR, "SR", "El");
    l0->Draw();

    TH1D *h_bJetEta_CR_SR_ratio = (TH1D *)h_Top_bJetEta_diffregion_bybin_CR->Clone("h_bJetEta_CR_SR_ratio");
    h_bJetEta_CR_SR_ratio->Divide(h_Top_bJetEta_diffregion_bybin_CR, h_Top_bJetEta_diffregion_SR, 1, 1);

    c1->cd(4);
    gPad->SetTopMargin(1);
    h_bJetEta_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    h_bJetEta_CR_SR_ratio->Draw();

    c1->cd(2);

    gPad->SetBottomMargin(0.02);

    h_Top_cJetEta_diffregion_SR->GetXaxis()->SetLabelSize(0);

    h_Top_cJetEta_diffregion_SR->Draw("h");
    h_Top_cJetEta_diffregion_bybin_CR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("c flavor");
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Top_cJetEta_diffregion_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l1->AddEntry(h_Top_cJetEta_diffregion_SR, "SR", "El");
    l1->Draw();

    c1->cd(5);
    gPad->SetTopMargin(1);

    TH1D *h_cJetEta_CR_SR_ratio = (TH1D *)h_Top_cJetEta_diffregion_bybin_CR->Clone("h_cJetEta_CR_SR_ratio");
    h_cJetEta_CR_SR_ratio->Divide(h_Top_cJetEta_diffregion_bybin_CR, h_Top_cJetEta_diffregion_SR, 1, 1);

    h_cJetEta_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    h_cJetEta_CR_SR_ratio->GetYaxis()->SetRangeUser(-2, 50);
    h_cJetEta_CR_SR_ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cJetEta_CR_SR_ratio->Draw();

    c1->cd(3);

    gPad->SetBottomMargin(0.02);

    h_Top_lJetEta_diffregion_bybin_CR->GetXaxis()->SetLabelSize(0);
    //h_Top_lJetEta_diffregion_bybin_CR->GetXaxis()->SetTitleSize(0);

    h_Top_lJetEta_diffregion_bybin_CR->Draw(" ");
    h_Top_lJetEta_diffregion_SR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor");
    l2->SetTextSize(0.03);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->AddEntry(h_Top_lJetEta_diffregion_bybin_CR, "CR (Top to emu apply ee fake rate)", "El");
    l2->AddEntry(h_Top_lJetEta_diffregion_SR, "SR", "El");
    l2->Draw();

    c1->cd(6);
    gPad->SetTopMargin(1);

    TH1D *h_lJetEta_CR_SR_ratio = (TH1D *)h_Top_lJetEta_diffregion_bybin_CR->Clone("h_lJetEta_CR_SR_ratio");
    h_lJetEta_CR_SR_ratio->Divide(h_Top_lJetEta_diffregion_bybin_CR, h_Top_lJetEta_diffregion_SR, 1, 1);

    h_lJetEta_CR_SR_ratio->GetYaxis()->SetTitle("CR / SR");
    // h_lJetEta_CR_SR_ratio->GetYaxis()->SetRangeUser(-2, 50);
    h_lJetEta_CR_SR_ratio->GetXaxis()->SetTitle("Jet #eta");

    h_lJetEta_CR_SR_ratio->Draw();
    */

    gStyle->SetOptStat(0);
}