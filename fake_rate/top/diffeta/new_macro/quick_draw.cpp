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

    h_Top_trk_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_btrk_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ctrk_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ltrk_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_htrk_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_trk_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_btrk_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ctrk_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ltrk_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_htrk_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_trk_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_trk_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_trk_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_btrk_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_btrk_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_btrk_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ctrk_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ctrk_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ctrk_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ltrk_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ltrk_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ltrk_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_htrk_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_htrk_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_htrk_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_trk_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_trk_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_trk_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_btrk_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_btrk_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_btrk_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ctrk_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ctrk_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ctrk_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ltrk_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ltrk_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_ltrk_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_htrk_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_htrk_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_htrk_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetPt_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetPt_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetPt_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetPt_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetPt_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetPt_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetPt_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetPt_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetPt_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetEta_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetEta_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetEta_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetEta_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetEta_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetEta_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetEta_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetEta_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetEta_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetEta_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetEta_diffregion_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetEta_diffregion_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetEta_diffregion_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetEta_diffregion_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetEta_diffregion_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_JetEta_diffregion_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetEta_diffregion_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetEta_diffregion_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetEta_diffregion_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_hJetEta_diffregion_SR->GetXaxis()->SetNdivisions(6, 5, 0);

    h_Top_trk_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_btrk_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ctrk_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ltrk_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_htrk_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_trk_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_btrk_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ctrk_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ltrk_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_htrk_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_trk_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_trk_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_trk_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_btrk_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_btrk_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_btrk_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ctrk_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ctrk_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ctrk_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ltrk_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ltrk_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ltrk_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_htrk_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_htrk_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_htrk_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_trk_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_trk_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_trk_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_btrk_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_btrk_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_btrk_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ctrk_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ctrk_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ctrk_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ltrk_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ltrk_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_ltrk_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_htrk_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_htrk_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_htrk_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetPt_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetPt_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetPt_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetPt_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetPt_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetPt_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetPt_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetPt_region1_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetPt_region2_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetPt_region3_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetPt_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetPt_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetPt_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetPt_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetPt_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetPt_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetEta_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetEta_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetEta_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetEta_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetEta_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetEta_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetEta_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetEta_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetEta_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetEta_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetEta_diffregion_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetEta_diffregion_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetEta_diffregion_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetEta_diffregion_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetEta_diffregion_bybin_CR->GetYaxis()->SetTitleSize(0.04);
    h_Top_JetEta_diffregion_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetEta_diffregion_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetEta_diffregion_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetEta_diffregion_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_hJetEta_diffregion_SR->GetYaxis()->SetTitleSize(0.04);

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

    int W = 800;
    int H = 600;

    int H_ref = 600;
    int W_ref = 800;

    float T = 0.08 * H_ref;
    float B = 0.12 * H_ref;
    float L = 0.12 * W_ref;
    float R = 0.04 * W_ref;

    /*
    auto c1 = new TCanvas("c1", "");
    c1->Divide(3, 1);
    c1->cd(1);
    h_Top_bJetPt_region1_bybin_CR->Draw("h ");
    h_Top_bJetPt_region1_SR->Draw(" same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->AddEntry(h_Top_btrk_bybin_CR, "CR", "l");
    l0->AddEntry(h_Top_btrk_SR, "SR", "l");
    l0->Draw();

    c1->cd(2);
    h_Top_bJetPt_region2_bybin_CR->Draw("h");
    h_Top_bJetPt_region2_SR->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->AddEntry(h_Top_ctrk_bybin_CR, "CR", "l");
    l1->AddEntry(h_Top_ctrk_SR, "SR", "l");
    l1->Draw();

    c1->cd(3);
    h_Top_bJetPt_region3_bybin_CR->Draw("");
    h_Top_bJetPt_region3_SR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->AddEntry(h_Top_ltrk_bybin_CR, "CR", "l");
    l2->AddEntry(h_Top_ltrk_SR, "SR", "l");
    l2->Draw();
    */

    /*
    auto c1 = new TCanvas("c1", "");
    c1->Divide(3, 1);
    c1->cd(1);
    h_Top_btrk_bybin_CR->Draw();
    h_Top_btrk_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->AddEntry(h_Top_btrk_bybin_CR, "CR", "l");
    l0->AddEntry(h_Top_btrk_SR, "SR", "l");
    l0->Draw();

    c1->cd(2);
    h_Top_ctrk_bybin_CR->Draw("h");
    h_Top_ctrk_SR->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->AddEntry(h_Top_ctrk_bybin_CR, "CR", "l");
    l1->AddEntry(h_Top_ctrk_SR, "SR", "l");
    l1->Draw();

    c1->cd(3);
    h_Top_ltrk_bybin_CR->Draw("");
    h_Top_ltrk_SR->Draw("h same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->AddEntry(h_Top_ltrk_bybin_CR, "CR", "l");
    l2->AddEntry(h_Top_ltrk_SR, "SR", "l");
    l2->Draw();
    */
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

    /*
    c1->Divide(3, 1);
    c1->cd(1);

    h_Top_bJetEta_diffregion_bybin_CR->GetXaxis()->SetTitle("Jet #eta");
    h_Top_bJetEta_diffregion_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_bJetEta_diffregion_bybin_CR->Draw();
    h_Top_bJetEta_diffregion_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(h_Top_bJetEta_bybin_CR, "CR", "l");
    l0->AddEntry(h_Top_bJetEta_SR, "SR", "l");
    l0->Draw();

    h_Top_cJetEta_diffregion_SR->GetXaxis()->SetTitle("Jet #eta");
    h_Top_cJetEta_diffregion_SR->GetYaxis()->SetTitle("nJet");

    c1->cd(2);

    h_Top_cJetEta_diffregion_SR->Draw(" h");
    h_Top_cJetEta_diffregion_bybin_CR->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("c flavor");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_Top_cJetEta_bybin_CR, "CR", "l");
    l1->AddEntry(h_Top_cJetEta_SR, "SR", "l");
    l1->Draw();

    h_Top_lJetEta_diffregion_SR->GetXaxis()->SetTitle("Jet #eta");
    h_Top_lJetEta_diffregion_SR->GetYaxis()->SetTitle("nJet");

    c1->cd(3);

    h_Top_lJetEta_diffregion_SR->Draw("h ");
    h_Top_lJetEta_diffregion_bybin_CR->Draw("same ");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(h_Top_lJetEta_bybin_CR, "CR", "l");
    l2->AddEntry(h_Top_lJetEta_SR, "SR", "l");
    l2->Draw();
    */
    c1->Divide(3, 1);
    c1->cd(1);

    h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_bJetPt_region1_bybin_CR->GetYaxis()->SetTitle("nJet");

    h_Top_bJetPt_region1_bybin_CR->Draw("");
    h_Top_bJetPt_region1_SR->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(h_Top_JetPt_region1_bybin_CR, "CR", "l");
    l0->AddEntry(h_Top_JetPt_region1_SR, "SR", "l");
    l0->Draw();

    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_bJetPt_region2_bybin_CR->GetYaxis()->SetTitle("nJet");

    c1->cd(2);

    h_Top_bJetPt_region2_bybin_CR->Draw("");
    h_Top_bJetPt_region2_SR->Draw(" h same");


    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_Top_cJetPt_bybin_CR, "CR", "l");
    l1->AddEntry(h_Top_cJetPt_SR, "SR", "l");
    l1->Draw();

    h_Top_bJetPt_region3_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitle("nJet");

    c1->cd(3);

    h_Top_bJetPt_region3_SR->Draw("h ");
    h_Top_bJetPt_region3_bybin_CR->Draw("same ");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(h_Top_lJetPt_bybin_CR, "CR", "l");
    l2->AddEntry(h_Top_lJetPt_SR, "SR", "l");
    l2->Draw();

    gStyle->SetOptStat(0);
}