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
#include "TLegend.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "./../../../lib/Cross_section.h"
using namespace std;
void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, int flavor2, int hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void Ratio_Top_apply_JetPt()
{
    TFile *TTTo2L2Nufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
    TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    //-------------
    // Open Tree
    //-------------
    TFile *TTTo2L2Nufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTTo2L2Nu_2.root");
    TFile *Top_TTWJetsToLNufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTWJetsToLNu_2.root");
    TFile *Top_TTWJetsToQQfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTWJetsToQQ_2.root");
    TFile *Top_TTZToQQfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTZToQQ_2.root");
    TFile *Top_TTZToLLNuNufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTZToLLNuNu_2.root");
    TFile *Top_tW_antitopfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_tW_antitop_2.root");
    TFile *Top_tW_topfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_tW_top_2.root");

    TFile *Topfile = new TFile("./ee_diffeta_Top_emjet_half.root");

    TH1D *TTTo2L2Nu_sumevt = ((TH1D *)TTTo2L2Nufile->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNufile->Get("Event_Variable/h_totevent"));
    TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQfile->Get("Event_Variable/h_totevent"));
    TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQfile->Get("Event_Variable/h_totevent"));
    TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNufile->Get("Event_Variable/h_totevent"));
    TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitopfile->Get("Event_Variable/h_totevent"));
    TH1D *tW_top_sumevt = ((TH1D *)Top_tW_topfile->Get("Event_Variable/h_totevent"));

    TH1D *Top_bfakeRate_eta1 = ((TH1D *)Topfile->Get("Top_bfakeRate_eta1"));
    TH1D *Top_cfakeRate_eta1 = ((TH1D *)Topfile->Get("Top_cfakeRate_eta1"));
    TH1D *Top_lfakeRate_eta1 = ((TH1D *)Topfile->Get("Top_lfakeRate_eta1"));

    TH1D *Top_bfakeRate_eta2 = ((TH1D *)Topfile->Get("Top_bfakeRate_eta2"));
    TH1D *Top_cfakeRate_eta2 = ((TH1D *)Topfile->Get("Top_cfakeRate_eta2"));
    TH1D *Top_lfakeRate_eta2 = ((TH1D *)Topfile->Get("Top_lfakeRate_eta2"));

    TH1D *Top_bfakeRate_eta3 = ((TH1D *)Topfile->Get("Top_bfakeRate_eta3"));
    TH1D *Top_cfakeRate_eta3 = ((TH1D *)Topfile->Get("Top_cfakeRate_eta3"));
    TH1D *Top_lfakeRate_eta3 = ((TH1D *)Topfile->Get("Top_lfakeRate_eta3"));

    int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
    int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
    int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
    int TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
    int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
    int tW_antitop_totevt = tW_antitop_sumevt->Integral();
    int tW_top_totevt = tW_top_sumevt->Integral();

    //---------------------
    // Define TopWeight
    //---------------------
    double TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * ((GlobalConstants::TTTo2L2Nu) / (TTTo2L2Nu_totevt)) * 1000 * 2;
    double ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000 * 2;
    double ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000 * 2;
    double TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000 * 2;
    double TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000 * 2;
    double TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000 * 2;
    double TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000 * 2;

    //-------------
    //  nTracks
    //-------------
    TH1D *h_Top_bJetPt_region1_bybin_CR = new TH1D("h_Top_bJetPt_region1_bybin_CR", "", 50, 0, 500);
    h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_bJetPt_region1_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_bJetPt_region1_bybin_CR->Sumw2();

    TH1D *h_Top_bJetPt_region1_SR = new TH1D("h_Top_bJetPt_region1_SR", "", 50, 0, 500);
    h_Top_bJetPt_region1_SR->GetXaxis()->SetTitle("");
    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitle("");
    h_Top_bJetPt_region1_SR->Sumw2();

    TH1D *h_Top_bJetPt_region2_bybin_CR = new TH1D("h_Top_bJetPt_region2_bybin_CR", "", 50, 0, 500);
    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_bJetPt_region2_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_bJetPt_region2_bybin_CR->Sumw2();

    TH1D *h_Top_bJetPt_region2_SR = new TH1D("h_Top_bJetPt_region2_SR", "", 50, 0, 500);
    h_Top_bJetPt_region2_SR->GetXaxis()->SetTitle("");
    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitle("");
    h_Top_bJetPt_region2_SR->Sumw2();

    TH1D *h_Top_bJetPt_region3_bybin_CR = new TH1D("h_Top_bJetPt_region3_bybin_CR", "", 50, 0, 500);
    h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_bJetPt_region3_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_bJetPt_region3_bybin_CR->Sumw2();

    TH1D *h_Top_bJetPt_region3_SR = new TH1D("h_Top_bJetPt_region3_SR", "", 50, 0, 500);
    h_Top_bJetPt_region3_SR->GetXaxis()->SetTitle("");
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitle("");
    h_Top_bJetPt_region3_SR->Sumw2();

    TH1D *h_Top_cJetPt_region1_bybin_CR = new TH1D("h_Top_cJetPt_region1_bybin_CR", "", 50, 0, 500);
    h_Top_cJetPt_region1_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_cJetPt_region1_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_cJetPt_region1_bybin_CR->Sumw2();

    TH1D *h_Top_cJetPt_region1_SR = new TH1D("h_Top_cJetPt_region1_SR", "", 50, 0, 500);
    h_Top_cJetPt_region1_SR->GetXaxis()->SetTitle("");
    h_Top_cJetPt_region1_SR->GetYaxis()->SetTitle("");
    h_Top_cJetPt_region1_SR->Sumw2();

    TH1D *h_Top_cJetPt_region2_bybin_CR = new TH1D("h_Top_cJetPt_region2_bybin_CR", "", 50, 0, 500);
    h_Top_cJetPt_region2_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_cJetPt_region2_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_cJetPt_region2_bybin_CR->Sumw2();

    TH1D *h_Top_cJetPt_region2_SR = new TH1D("h_Top_cJetPt_region2_SR", "", 50, 0, 500);
    h_Top_cJetPt_region2_SR->GetXaxis()->SetTitle("");
    h_Top_cJetPt_region2_SR->GetYaxis()->SetTitle("");
    h_Top_cJetPt_region2_SR->Sumw2();

    TH1D *h_Top_cJetPt_region3_bybin_CR = new TH1D("h_Top_cJetPt_region3_bybin_CR", "", 50, 0, 500);
    h_Top_cJetPt_region3_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_cJetPt_region3_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_cJetPt_region3_bybin_CR->Sumw2();

    TH1D *h_Top_cJetPt_region3_SR = new TH1D("h_Top_cJetPt_region3_SR", "", 50, 0, 500);
    h_Top_cJetPt_region3_SR->GetXaxis()->SetTitle("");
    h_Top_cJetPt_region3_SR->GetYaxis()->SetTitle("");
    h_Top_cJetPt_region3_SR->Sumw2();

    TH1D *h_Top_lJetPt_region1_bybin_CR = new TH1D("h_Top_lJetPt_region1_bybin_CR", "", 50, 0, 500);
    h_Top_lJetPt_region1_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_lJetPt_region1_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_lJetPt_region1_bybin_CR->Sumw2();

    TH1D *h_Top_lJetPt_region1_SR = new TH1D("h_Top_lJetPt_region1_SR", "", 50, 0, 500);
    h_Top_lJetPt_region1_SR->GetXaxis()->SetTitle("");
    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitle("");
    h_Top_lJetPt_region1_SR->Sumw2();

    TH1D *h_Top_lJetPt_region2_bybin_CR = new TH1D("h_Top_lJetPt_region2_bybin_CR", "", 50, 0, 500);
    h_Top_lJetPt_region2_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_lJetPt_region2_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_lJetPt_region2_bybin_CR->Sumw2();

    TH1D *h_Top_lJetPt_region2_SR = new TH1D("h_Top_lJetPt_region2_SR", "", 50, 0, 500);
    h_Top_lJetPt_region2_SR->GetXaxis()->SetTitle("");
    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitle("");
    h_Top_lJetPt_region2_SR->Sumw2();

    TH1D *h_Top_lJetPt_region3_bybin_CR = new TH1D("h_Top_lJetPt_region3_bybin_CR", "", 50, 0, 500);
    h_Top_lJetPt_region3_bybin_CR->GetXaxis()->SetTitle("");
    h_Top_lJetPt_region3_bybin_CR->GetYaxis()->SetTitle("");
    h_Top_lJetPt_region3_bybin_CR->Sumw2();

    TH1D *h_Top_lJetPt_region3_SR = new TH1D("h_Top_lJetPt_region3_SR", "", 50, 0, 500);
    h_Top_lJetPt_region3_SR->GetXaxis()->SetTitle("");
    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitle("");
    h_Top_lJetPt_region3_SR->Sumw2();

    Int_t I_TTTo2L2Nu_nThinJets;
    Int_t I_ST_tW_top_nThinJets;
    Int_t I_ST_tW_antitop_nThinJets;
    Int_t I_TTWJetsToLNu_nThinJets;
    Int_t I_TTWJetsToQQ_nThinJets;
    Int_t I_TTZToQQ_nThinJets;
    Int_t I_TTZToLLNuNu_nThinJets;

    Int_t I_TTTo2L2Nu_weight;
    Int_t I_ST_tW_top_weight;
    Int_t I_ST_tW_antitop_weight;
    Int_t I_TTWJetsToLNu_weight;
    Int_t I_TTWJetsToQQ_weight;
    Int_t I_TTZToQQ_weight;
    Int_t I_TTZToLLNuNu_weight;

    float_t f_TTTo2L2Nu_met;
    float_t f_ST_tW_top_met;
    float_t f_ST_tW_antitop_met;
    float_t f_TTWJetsToLNu_met;
    float_t f_TTWJetsToQQ_met;
    float_t f_TTZToQQ_met;
    float_t f_TTZToLLNuNu_met;

    vector<float> *v_TTTo2L2Nu_alpha = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha2 = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha3 = new vector<float>();
    vector<float> *v_TTTo2L2Nu_alpha4 = new vector<float>();

    vector<float> *v_ST_tW_top_alpha = new vector<float>();
    vector<float> *v_ST_tW_top_alpha2 = new vector<float>();
    vector<float> *v_ST_tW_top_alpha3 = new vector<float>();
    vector<float> *v_ST_tW_top_alpha4 = new vector<float>();

    vector<float> *v_ST_tW_antitop_alpha = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha2 = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha3 = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha4 = new vector<float>();

    vector<float> *v_TTWJetsToLNu_alpha = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha2 = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha3 = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha4 = new vector<float>();

    vector<float> *v_TTWJetsToQQ_alpha = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha2 = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha3 = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha4 = new vector<float>();

    vector<float> *v_TTZToQQ_alpha = new vector<float>();
    vector<float> *v_TTZToQQ_alpha2 = new vector<float>();
    vector<float> *v_TTZToQQ_alpha3 = new vector<float>();
    vector<float> *v_TTZToQQ_alpha4 = new vector<float>();

    vector<float> *v_TTZToLLNuNu_alpha = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha2 = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha3 = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha4 = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Chi3Dlog = new vector<float>();
    vector<float> *v_ST_tW_top_Chi3Dlog = new vector<float>();
    vector<float> *v_ST_tW_antitop_Chi3Dlog = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Chi3Dlog = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Chi3Dlog = new vector<float>();
    vector<float> *v_TTZToQQ_Chi3Dlog = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Chi3Dlog = new vector<float>();

    vector<float> *v_TTTo2L2Nu_2DIP = new vector<float>();
    vector<float> *v_ST_tW_top_2DIP = new vector<float>();
    vector<float> *v_ST_tW_antitop_2DIP = new vector<float>();
    vector<float> *v_TTWJetsToLNu_2DIP = new vector<float>();
    vector<float> *v_TTWJetsToQQ_2DIP = new vector<float>();
    vector<float> *v_TTZToQQ_2DIP = new vector<float>();
    vector<float> *v_TTZToLLNuNu_2DIP = new vector<float>();

    vector<float> *v_TTTo2L2Nu_nTrack = new vector<float>();
    vector<float> *v_ST_tW_top_nTrack = new vector<float>();
    vector<float> *v_ST_tW_antitop_nTrack = new vector<float>();
    vector<float> *v_TTWJetsToLNu_nTrack = new vector<float>();
    vector<float> *v_TTWJetsToQQ_nTrack = new vector<float>();
    vector<float> *v_TTZToQQ_nTrack = new vector<float>();
    vector<float> *v_TTZToLLNuNu_nTrack = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Jethadronflavor = new vector<float>();
    vector<float> *v_ST_tW_top_Jethadronflavor = new vector<float>();
    vector<float> *v_ST_tW_antitop_Jethadronflavor = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Jethadronflavor = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Jethadronflavor = new vector<float>();
    vector<float> *v_TTZToQQ_Jethadronflavor = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Jethadronflavor = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Jetpartonflavor = new vector<float>();
    vector<float> *v_ST_tW_top_Jetpartonflavor = new vector<float>();
    vector<float> *v_ST_tW_antitop_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTZToQQ_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Jetpartonflavor = new vector<float>();

    vector<float> *v_TTTo2L2Nu_JetPT = new vector<float>();
    vector<float> *v_ST_tW_top_JetPT = new vector<float>();
    vector<float> *v_ST_tW_antitop_JetPT = new vector<float>();
    vector<float> *v_TTWJetsToLNu_JetPT = new vector<float>();
    vector<float> *v_TTWJetsToQQ_JetPT = new vector<float>();
    vector<float> *v_TTZToQQ_JetPT = new vector<float>();
    vector<float> *v_TTZToLLNuNu_JetPT = new vector<float>();

    vector<float> *v_TTTo2L2Nu_JetEta = new vector<float>();
    vector<float> *v_ST_tW_top_JetEta = new vector<float>();
    vector<float> *v_ST_tW_antitop_JetEta = new vector<float>();
    vector<float> *v_TTWJetsToLNu_JetEta = new vector<float>();
    vector<float> *v_TTWJetsToQQ_JetEta = new vector<float>();
    vector<float> *v_TTZToQQ_JetEta = new vector<float>();
    vector<float> *v_TTZToLLNuNu_JetEta = new vector<float>();

    v_TTTo2L2Nu_alpha->clear();
    v_TTTo2L2Nu_alpha2->clear();
    v_TTTo2L2Nu_alpha3->clear();
    v_TTTo2L2Nu_alpha4->clear();

    v_ST_tW_top_alpha->clear();
    v_ST_tW_top_alpha2->clear();
    v_ST_tW_top_alpha3->clear();
    v_ST_tW_top_alpha4->clear();

    v_ST_tW_antitop_alpha->clear();
    v_ST_tW_antitop_alpha2->clear();
    v_ST_tW_antitop_alpha3->clear();
    v_ST_tW_antitop_alpha4->clear();

    v_TTWJetsToLNu_alpha->clear();
    v_TTWJetsToLNu_alpha2->clear();
    v_TTWJetsToLNu_alpha3->clear();
    v_TTWJetsToLNu_alpha4->clear();

    v_TTWJetsToQQ_alpha->clear();
    v_TTWJetsToQQ_alpha2->clear();
    v_TTWJetsToQQ_alpha3->clear();
    v_TTWJetsToQQ_alpha4->clear();

    v_TTZToQQ_alpha->clear();
    v_TTZToQQ_alpha2->clear();
    v_TTZToQQ_alpha3->clear();
    v_TTZToQQ_alpha4->clear();

    v_TTZToLLNuNu_alpha->clear();
    v_TTZToLLNuNu_alpha2->clear();
    v_TTZToLLNuNu_alpha3->clear();
    v_TTZToLLNuNu_alpha4->clear();

    v_TTTo2L2Nu_Chi3Dlog->clear();
    v_ST_tW_top_Chi3Dlog->clear();
    v_ST_tW_antitop_Chi3Dlog->clear();
    v_TTWJetsToLNu_Chi3Dlog->clear();
    v_TTWJetsToQQ_Chi3Dlog->clear();
    v_TTZToQQ_Chi3Dlog->clear();
    v_TTZToLLNuNu_Chi3Dlog->clear();

    v_TTTo2L2Nu_2DIP->clear();
    v_ST_tW_top_2DIP->clear();
    v_ST_tW_antitop_2DIP->clear();
    v_TTWJetsToLNu_2DIP->clear();
    v_TTWJetsToQQ_2DIP->clear();
    v_TTZToQQ_2DIP->clear();
    v_TTZToLLNuNu_2DIP->clear();

    v_TTTo2L2Nu_nTrack->clear();
    v_ST_tW_top_nTrack->clear();
    v_ST_tW_antitop_nTrack->clear();
    v_TTWJetsToLNu_nTrack->clear();
    v_TTWJetsToQQ_nTrack->clear();
    v_TTZToQQ_nTrack->clear();
    v_TTZToLLNuNu_nTrack->clear();

    v_TTTo2L2Nu_Jethadronflavor->clear();
    v_ST_tW_top_Jethadronflavor->clear();
    v_ST_tW_antitop_Jethadronflavor->clear();
    v_TTWJetsToLNu_Jethadronflavor->clear();
    v_TTWJetsToQQ_Jethadronflavor->clear();
    v_TTZToQQ_Jethadronflavor->clear();
    v_TTZToLLNuNu_Jethadronflavor->clear();

    v_TTTo2L2Nu_Jetpartonflavor->clear();
    v_ST_tW_top_Jetpartonflavor->clear();
    v_ST_tW_antitop_Jetpartonflavor->clear();
    v_TTWJetsToLNu_Jetpartonflavor->clear();
    v_TTWJetsToQQ_Jetpartonflavor->clear();
    v_TTZToQQ_Jetpartonflavor->clear();
    v_TTZToLLNuNu_Jetpartonflavor->clear();

    v_TTTo2L2Nu_JetPT->clear();
    v_ST_tW_top_JetPT->clear();
    v_ST_tW_antitop_JetPT->clear();
    v_TTWJetsToLNu_JetPT->clear();
    v_TTWJetsToQQ_JetPT->clear();
    v_TTZToQQ_JetPT->clear();
    v_TTZToLLNuNu_JetPT->clear();

    v_TTTo2L2Nu_JetEta->clear();
    v_ST_tW_top_JetEta->clear();
    v_ST_tW_antitop_JetEta->clear();
    v_TTWJetsToLNu_JetEta->clear();
    v_TTWJetsToQQ_JetEta->clear();
    v_TTZToQQ_JetEta->clear();
    v_TTZToLLNuNu_JetEta->clear();

    TTree *T_TTTo2L2Nu_tree;
    TTTo2L2Nufile_1->GetObject("h2", T_TTTo2L2Nu_tree);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_weight", &I_TTTo2L2Nu_weight);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_nJets", &I_TTTo2L2Nu_nThinJets);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_N_Tracks", &v_TTTo2L2Nu_nTrack);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_IP2D", &v_TTTo2L2Nu_2DIP);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTTo2L2Nu_Chi3Dlog);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha2", &v_TTTo2L2Nu_alpha2);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha3", &v_TTTo2L2Nu_alpha3);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha4", &v_TTTo2L2Nu_alpha4);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTTo2L2Nu_Jethadronflavor);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTTo2L2Nu_Jetpartonflavor);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetPt", &v_TTTo2L2Nu_JetPT);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetEta", &v_TTTo2L2Nu_JetEta);
    for (int evt = 0; evt < T_TTTo2L2Nu_tree->GetEntries(); evt++)
    {
        T_TTTo2L2Nu_tree->GetEntry(evt);
        double TTTo2L2Nu_eventWeight = I_TTTo2L2Nu_weight * TTTo2L2NuWeight;
        for (size_t i = 0; i < v_TTTo2L2Nu_nTrack->size(); i++)
        {
            // Region 1
            if (abs((*v_TTTo2L2Nu_JetEta)[i]) < 1)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region1 = Top_bfakeRate_eta1->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
                double cWeightbybin_region1 = Top_cfakeRate_eta1->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
                double lWeightbybin_region1 = Top_lfakeRate_eta1->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], bWeightbybin_region1, h_Top_bJetPt_region1_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], cWeightbybin_region1, h_Top_cJetPt_region1_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], lWeightbybin_region1, h_Top_lJetPt_region1_bybin_CR);
                if ((*v_TTTo2L2Nu_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_bJetPt_region1_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_cJetPt_region1_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_lJetPt_region1_SR);
                }
            }
            // Region 2
            else if (abs((*v_TTTo2L2Nu_JetEta)[i]) > 1 && abs((*v_TTTo2L2Nu_JetEta)[i]) < 2)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region2 = Top_bfakeRate_eta2->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
                double cWeightbybin_region2 = Top_cfakeRate_eta2->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
                double lWeightbybin_region2 = Top_lfakeRate_eta2->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], bWeightbybin_region2, h_Top_bJetPt_region2_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], cWeightbybin_region2, h_Top_cJetPt_region2_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], lWeightbybin_region2, h_Top_lJetPt_region2_bybin_CR);
                if ((*v_TTTo2L2Nu_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_bJetPt_region2_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_cJetPt_region2_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_lJetPt_region2_SR);
                }
            }
            // Region 3
            else if (abs((*v_TTTo2L2Nu_JetEta)[i]) > 2 && abs((*v_TTTo2L2Nu_JetEta)[i]) < 2.5)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region3 = Top_bfakeRate_eta3->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
                double cWeightbybin_region3 = Top_cfakeRate_eta3->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
                double lWeightbybin_region3 = Top_lfakeRate_eta3->GetBinContent((*v_TTTo2L2Nu_nTrack)[i] + 1) * TTTo2L2Nu_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], bWeightbybin_region3, h_Top_bJetPt_region3_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], cWeightbybin_region3, h_Top_cJetPt_region3_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], lWeightbybin_region3, h_Top_lJetPt_region3_bybin_CR);
                if ((*v_TTTo2L2Nu_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_bJetPt_region3_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_cJetPt_region3_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_JetPT)[i], TTTo2L2Nu_eventWeight, h_Top_lJetPt_region3_SR);
                }
            }
        }
    } // End of TTTo2L2Nu

    TTree *T_ST_tW_top_tree;
    Top_tW_topfile_1->GetObject("h2", T_ST_tW_top_tree);
    T_ST_tW_top_tree->SetBranchAddress("I_weight", &I_ST_tW_top_weight);
    T_ST_tW_top_tree->SetBranchAddress("I_nJets", &I_ST_tW_top_nThinJets);
    T_ST_tW_top_tree->SetBranchAddress("v_N_Tracks", &v_ST_tW_top_nTrack);
    T_ST_tW_top_tree->SetBranchAddress("f_Met", &f_ST_tW_top_met);
    T_ST_tW_top_tree->SetBranchAddress("v_IP2D", &v_ST_tW_top_2DIP);
    T_ST_tW_top_tree->SetBranchAddress("v_Chi3Dlog", &v_ST_tW_top_Chi3Dlog);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_top_alpha);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha2", &v_ST_tW_top_alpha2);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha3", &v_ST_tW_top_alpha3);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha4", &v_ST_tW_top_alpha4);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_top_Jethadronflavor);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ST_tW_top_Jetpartonflavor);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetPt", &v_ST_tW_top_JetPT);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetEta", &v_ST_tW_top_JetEta);
    for (int evt = 0; evt < T_ST_tW_top_tree->GetEntries(); evt++)
    {
        T_ST_tW_top_tree->GetEntry(evt);
        double ST_tW_top_eventWeight = I_ST_tW_top_weight * ST_tW_topWeight;
        for (size_t i = 0; i < v_ST_tW_top_nTrack->size(); i++)
        {
            // Region 1
            if (abs((*v_ST_tW_top_JetEta)[i]) < 1)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region1 = Top_bfakeRate_eta1->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
                double cWeightbybin_region1 = Top_cfakeRate_eta1->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
                double lWeightbybin_region1 = Top_lfakeRate_eta1->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], bWeightbybin_region1, h_Top_bJetPt_region1_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], cWeightbybin_region1, h_Top_cJetPt_region1_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], lWeightbybin_region1, h_Top_lJetPt_region1_bybin_CR);
                if ((*v_ST_tW_top_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_bJetPt_region1_SR);
                    // c
                    for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_cJetPt_region1_SR);
                    // l
                    for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_lJetPt_region1_SR);
                }
            }
            // Region 2
            else if (abs((*v_ST_tW_top_JetEta)[i]) > 1 && abs((*v_ST_tW_top_JetEta)[i]) < 2)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region2 = Top_bfakeRate_eta2->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
                double cWeightbybin_region2 = Top_cfakeRate_eta2->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
                double lWeightbybin_region2 = Top_lfakeRate_eta2->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], bWeightbybin_region2, h_Top_bJetPt_region2_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], cWeightbybin_region2, h_Top_cJetPt_region2_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], lWeightbybin_region2, h_Top_lJetPt_region2_bybin_CR);
                if ((*v_ST_tW_top_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_bJetPt_region2_SR);
                    // c
                    for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_cJetPt_region2_SR);
                    // l
                    for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_lJetPt_region2_SR);
                }
            }
            // Region 3
            else if (abs((*v_ST_tW_top_JetEta)[i]) > 2 && abs((*v_ST_tW_top_JetEta)[i]) < 2.5)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region3 = Top_bfakeRate_eta3->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
                double cWeightbybin_region3 = Top_cfakeRate_eta3->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
                double lWeightbybin_region3 = Top_lfakeRate_eta3->GetBinContent((*v_ST_tW_top_nTrack)[i] + 1) * ST_tW_top_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], bWeightbybin_region3, h_Top_bJetPt_region3_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], cWeightbybin_region3, h_Top_cJetPt_region3_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], lWeightbybin_region3, h_Top_lJetPt_region3_bybin_CR);
                if ((*v_ST_tW_top_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_bJetPt_region3_SR);
                    // c
                    for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_cJetPt_region3_SR);
                    // l
                    for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_JetPT)[i], ST_tW_top_eventWeight, h_Top_lJetPt_region3_SR);
                }
            }
        }
    } // End of ST_tW_top
    TTree *T_ST_tW_antitop_tree;
    Top_tW_antitopfile_1->GetObject("h2", T_ST_tW_antitop_tree);
    T_ST_tW_antitop_tree->SetBranchAddress("I_weight", &I_ST_tW_antitop_weight);
    T_ST_tW_antitop_tree->SetBranchAddress("I_nJets", &I_ST_tW_antitop_nThinJets);
    T_ST_tW_antitop_tree->SetBranchAddress("v_N_Tracks", &v_ST_tW_antitop_nTrack);
    T_ST_tW_antitop_tree->SetBranchAddress("f_Met", &f_ST_tW_antitop_met);
    T_ST_tW_antitop_tree->SetBranchAddress("v_IP2D", &v_ST_tW_antitop_2DIP);
    T_ST_tW_antitop_tree->SetBranchAddress("v_Chi3Dlog", &v_ST_tW_antitop_Chi3Dlog);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_antitop_alpha);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha2", &v_ST_tW_antitop_alpha2);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha3", &v_ST_tW_antitop_alpha3);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha4", &v_ST_tW_antitop_alpha4);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_antitop_Jethadronflavor);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ST_tW_antitop_Jetpartonflavor);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetPt", &v_ST_tW_antitop_JetPT);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetEta", &v_ST_tW_antitop_JetEta);
    for (int evt = 0; evt < T_ST_tW_antitop_tree->GetEntries(); evt++)
    {
        T_ST_tW_antitop_tree->GetEntry(evt);
        double ST_tW_antitop_eventWeight = I_ST_tW_antitop_weight * ST_tW_antitopWeight;
        for (size_t i = 0; i < v_ST_tW_antitop_nTrack->size(); i++)
        {
            // Region 1
            if (abs((*v_ST_tW_antitop_JetEta)[i]) < 1)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region1 = Top_bfakeRate_eta1->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
                double cWeightbybin_region1 = Top_cfakeRate_eta1->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
                double lWeightbybin_region1 = Top_lfakeRate_eta1->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], bWeightbybin_region1, h_Top_bJetPt_region1_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], cWeightbybin_region1, h_Top_cJetPt_region1_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], lWeightbybin_region1, h_Top_lJetPt_region1_bybin_CR);
                if ((*v_ST_tW_antitop_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_bJetPt_region1_SR);
                    // c
                    for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_cJetPt_region1_SR);
                    // l
                    for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_lJetPt_region1_SR);
                }
            }
            // Region 2
            else if (abs((*v_ST_tW_antitop_JetEta)[i]) > 1 && abs((*v_ST_tW_antitop_JetEta)[i]) < 2)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region2 = Top_bfakeRate_eta2->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
                double cWeightbybin_region2 = Top_cfakeRate_eta2->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
                double lWeightbybin_region2 = Top_lfakeRate_eta2->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], bWeightbybin_region2, h_Top_bJetPt_region2_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], cWeightbybin_region2, h_Top_cJetPt_region2_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], lWeightbybin_region2, h_Top_lJetPt_region2_bybin_CR);
                if ((*v_ST_tW_antitop_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_bJetPt_region2_SR);
                    // c
                    for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_cJetPt_region2_SR);
                    // l
                    for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_lJetPt_region2_SR);
                }
            }
            // Region 3
            else if (abs((*v_ST_tW_antitop_JetEta)[i]) > 2 && abs((*v_ST_tW_antitop_JetEta)[i]) < 2.5)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region3 = Top_bfakeRate_eta3->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
                double cWeightbybin_region3 = Top_cfakeRate_eta3->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
                double lWeightbybin_region3 = Top_lfakeRate_eta3->GetBinContent((*v_ST_tW_antitop_nTrack)[i] + 1) * ST_tW_antitop_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], bWeightbybin_region3, h_Top_bJetPt_region3_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], cWeightbybin_region3, h_Top_cJetPt_region3_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], lWeightbybin_region3, h_Top_lJetPt_region3_bybin_CR);
                if ((*v_ST_tW_antitop_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_bJetPt_region3_SR);
                    // c
                    for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_cJetPt_region3_SR);
                    // l
                    for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_JetPT)[i], ST_tW_antitop_eventWeight, h_Top_lJetPt_region3_SR);
                }
            }
        }
    } // End of ST_tW_antitop

    TTree *T_TTWJetsToLNu_tree;
    Top_TTWJetsToLNufile_1->GetObject("h2", T_TTWJetsToLNu_tree);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_weight", &I_TTWJetsToLNu_weight);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_nJets", &I_TTWJetsToLNu_nThinJets);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_N_Tracks", &v_TTWJetsToLNu_nTrack);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_IP2D", &v_TTWJetsToLNu_2DIP);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTWJetsToLNu_Chi3Dlog);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToLNu_alpha);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha2", &v_TTWJetsToLNu_alpha2);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha3", &v_TTWJetsToLNu_alpha3);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha4", &v_TTWJetsToLNu_alpha4);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToLNu_Jethadronflavor);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTWJetsToLNu_Jetpartonflavor);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToLNu_JetPT);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToLNu_JetEta);
    for (int evt = 0; evt < T_TTWJetsToLNu_tree->GetEntries(); evt++)
    {
        T_TTWJetsToLNu_tree->GetEntry(evt);
        double TTWJetsToLNu_eventWeight = I_TTWJetsToLNu_weight * TTWJetsToLNuWeight;
        for (size_t i = 0; i < v_TTWJetsToLNu_nTrack->size(); i++)
        {
            // Region 1
            if (abs((*v_TTWJetsToLNu_JetEta)[i]) < 1)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region1 = Top_bfakeRate_eta1->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
                double cWeightbybin_region1 = Top_cfakeRate_eta1->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
                double lWeightbybin_region1 = Top_lfakeRate_eta1->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], bWeightbybin_region1, h_Top_bJetPt_region1_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], cWeightbybin_region1, h_Top_cJetPt_region1_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], lWeightbybin_region1, h_Top_lJetPt_region1_bybin_CR);
                if ((*v_TTWJetsToLNu_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_bJetPt_region1_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_cJetPt_region1_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_lJetPt_region1_SR);
                }
            }
            // Region 2
            else if (abs((*v_TTWJetsToLNu_JetEta)[i]) > 1 && abs((*v_TTWJetsToLNu_JetEta)[i]) < 2)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region2 = Top_bfakeRate_eta2->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
                double cWeightbybin_region2 = Top_cfakeRate_eta2->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
                double lWeightbybin_region2 = Top_lfakeRate_eta2->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], bWeightbybin_region2, h_Top_bJetPt_region2_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], cWeightbybin_region2, h_Top_cJetPt_region2_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], lWeightbybin_region2, h_Top_lJetPt_region2_bybin_CR);
                if ((*v_TTWJetsToLNu_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_bJetPt_region2_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_cJetPt_region2_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_lJetPt_region2_SR);
                }
            }
            // Region 3
            else if (abs((*v_TTWJetsToLNu_JetEta)[i]) > 2 && abs((*v_TTWJetsToLNu_JetEta)[i]) < 2.5)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region3 = Top_bfakeRate_eta3->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
                double cWeightbybin_region3 = Top_cfakeRate_eta3->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
                double lWeightbybin_region3 = Top_lfakeRate_eta3->GetBinContent((*v_TTWJetsToLNu_nTrack)[i] + 1) * TTWJetsToLNu_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], bWeightbybin_region3, h_Top_bJetPt_region3_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], cWeightbybin_region3, h_Top_cJetPt_region3_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], lWeightbybin_region3, h_Top_lJetPt_region3_bybin_CR);
                if ((*v_TTWJetsToLNu_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_bJetPt_region3_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_cJetPt_region3_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_JetPT)[i], TTWJetsToLNu_eventWeight, h_Top_lJetPt_region3_SR);
                }
            }
        }
    } // End of TTWJetsToLNu

    TTree *T_TTWJetsToQQ_tree;
    Top_TTWJetsToQQfile_1->GetObject("h2", T_TTWJetsToQQ_tree);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_weight", &I_TTWJetsToQQ_weight);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_nJets", &I_TTWJetsToQQ_nThinJets);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_N_Tracks", &v_TTWJetsToQQ_nTrack);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_IP2D", &v_TTWJetsToQQ_2DIP);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_Chi3Dlog", &v_TTWJetsToQQ_Chi3Dlog);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToQQ_alpha);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha2", &v_TTWJetsToQQ_alpha2);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha3", &v_TTWJetsToQQ_alpha3);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha4", &v_TTWJetsToQQ_alpha4);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToQQ_Jethadronflavor);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTWJetsToQQ_Jetpartonflavor);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToQQ_JetPT);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToQQ_JetEta);
    for (int evt = 0; evt < T_TTWJetsToQQ_tree->GetEntries(); evt++)
    {
        T_TTWJetsToQQ_tree->GetEntry(evt);
        double TTWJetsToQQ_eventWeight = I_TTWJetsToQQ_weight * TTWJetsToQQWeight;
        for (size_t i = 0; i < v_TTWJetsToQQ_nTrack->size(); i++)
        {
            // Region 1
            if (abs((*v_TTWJetsToQQ_JetEta)[i]) < 1)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region1 = Top_bfakeRate_eta1->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
                double cWeightbybin_region1 = Top_cfakeRate_eta1->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
                double lWeightbybin_region1 = Top_lfakeRate_eta1->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], bWeightbybin_region1, h_Top_bJetPt_region1_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], cWeightbybin_region1, h_Top_cJetPt_region1_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], lWeightbybin_region1, h_Top_lJetPt_region1_bybin_CR);
                if ((*v_TTWJetsToQQ_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_bJetPt_region1_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_cJetPt_region1_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_lJetPt_region1_SR);
                }
            }
            // Region 2
            else if (abs((*v_TTWJetsToQQ_JetEta)[i]) > 1 && abs((*v_TTWJetsToQQ_JetEta)[i]) < 2)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region2 = Top_bfakeRate_eta2->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
                double cWeightbybin_region2 = Top_cfakeRate_eta2->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
                double lWeightbybin_region2 = Top_lfakeRate_eta2->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], bWeightbybin_region2, h_Top_bJetPt_region2_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], cWeightbybin_region2, h_Top_cJetPt_region2_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], lWeightbybin_region2, h_Top_lJetPt_region2_bybin_CR);
                if ((*v_TTWJetsToQQ_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_bJetPt_region2_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_cJetPt_region2_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_lJetPt_region2_SR);
                }
            }
            // Region 3
            else if (abs((*v_TTWJetsToQQ_JetEta)[i]) > 2 && abs((*v_TTWJetsToQQ_JetEta)[i]) < 2.5)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region3 = Top_bfakeRate_eta3->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
                double cWeightbybin_region3 = Top_cfakeRate_eta3->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
                double lWeightbybin_region3 = Top_lfakeRate_eta3->GetBinContent((*v_TTWJetsToQQ_nTrack)[i] + 1) * TTWJetsToQQ_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], bWeightbybin_region3, h_Top_bJetPt_region3_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], cWeightbybin_region3, h_Top_cJetPt_region3_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], lWeightbybin_region3, h_Top_lJetPt_region3_bybin_CR);
                if ((*v_TTWJetsToQQ_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_bJetPt_region3_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_cJetPt_region3_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jetpartonflavor)[i], (*v_TTWJetsToQQ_JetPT)[i], TTWJetsToQQ_eventWeight, h_Top_lJetPt_region3_SR);
                }
            }
        }
    } // End of TTWJetsToQQ

    TTree *T_TTZToQQ_tree;
    Top_TTZToQQfile_1->GetObject("h2", T_TTZToQQ_tree);
    T_TTZToQQ_tree->SetBranchAddress("I_weight", &I_TTZToQQ_weight);
    T_TTZToQQ_tree->SetBranchAddress("I_nJets", &I_TTZToQQ_nThinJets);
    T_TTZToQQ_tree->SetBranchAddress("v_N_Tracks", &v_TTZToQQ_nTrack);
    T_TTZToQQ_tree->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_TTZToQQ_tree->SetBranchAddress("v_IP2D", &v_TTZToQQ_2DIP);
    T_TTZToQQ_tree->SetBranchAddress("v_Chi3Dlog", &v_TTZToQQ_Chi3Dlog);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTZToQQ_alpha);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha2", &v_TTZToQQ_alpha2);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha3", &v_TTZToQQ_alpha3);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha4", &v_TTZToQQ_alpha4);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToQQ_Jethadronflavor);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTZToQQ_Jetpartonflavor);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetPt", &v_TTZToQQ_JetPT);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetEta", &v_TTZToQQ_JetEta);
    for (int evt = 0; evt < T_TTZToQQ_tree->GetEntries(); evt++)
    {
        T_TTZToQQ_tree->GetEntry(evt);
        double TTZToQQ_eventWeight = I_TTZToQQ_weight * TTZToQQWeight;
        for (size_t i = 0; i < v_TTZToQQ_nTrack->size(); i++)
        {
            // Region 1
            if (abs((*v_TTZToQQ_JetEta)[i]) < 1)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region1 = Top_bfakeRate_eta1->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
                double cWeightbybin_region1 = Top_cfakeRate_eta1->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
                double lWeightbybin_region1 = Top_lfakeRate_eta1->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], bWeightbybin_region1, h_Top_bJetPt_region1_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], cWeightbybin_region1, h_Top_cJetPt_region1_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], lWeightbybin_region1, h_Top_lJetPt_region1_bybin_CR);
                if ((*v_TTZToQQ_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_bJetPt_region1_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_cJetPt_region1_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_lJetPt_region1_SR);
                }
            }
            // Region 2
            else if (abs((*v_TTZToQQ_JetEta)[i]) > 1 && abs((*v_TTZToQQ_JetEta)[i]) < 2)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region2 = Top_bfakeRate_eta2->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
                double cWeightbybin_region2 = Top_cfakeRate_eta2->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
                double lWeightbybin_region2 = Top_lfakeRate_eta2->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], bWeightbybin_region2, h_Top_bJetPt_region2_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], cWeightbybin_region2, h_Top_cJetPt_region2_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], lWeightbybin_region2, h_Top_lJetPt_region2_bybin_CR);
                if ((*v_TTZToQQ_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_bJetPt_region2_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_cJetPt_region2_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_lJetPt_region2_SR);
                }
            }
            // Region 3
            else if (abs((*v_TTZToQQ_JetEta)[i]) > 2 && abs((*v_TTZToQQ_JetEta)[i]) < 2.5)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region3 = Top_bfakeRate_eta3->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
                double cWeightbybin_region3 = Top_cfakeRate_eta3->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
                double lWeightbybin_region3 = Top_lfakeRate_eta3->GetBinContent((*v_TTZToQQ_nTrack)[i] + 1) * TTZToQQ_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], bWeightbybin_region3, h_Top_bJetPt_region3_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], cWeightbybin_region3, h_Top_cJetPt_region3_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], lWeightbybin_region3, h_Top_lJetPt_region3_bybin_CR);
                if ((*v_TTZToQQ_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_bJetPt_region3_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_cJetPt_region3_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_JetPT)[i], TTZToQQ_eventWeight, h_Top_lJetPt_region3_SR);
                }
            }
        }
    } // End of TTZToQQ

    TTree *T_TTZToLLNuNu_tree;
    Top_TTZToLLNuNufile_1->GetObject("h2", T_TTZToLLNuNu_tree);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_weight", &I_TTZToLLNuNu_weight);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_nJets", &I_TTZToLLNuNu_nThinJets);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_N_Tracks", &v_TTZToLLNuNu_nTrack);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_IP2D", &v_TTZToLLNuNu_2DIP);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTZToLLNuNu_Chi3Dlog);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha", &v_TTZToLLNuNu_alpha);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha2", &v_TTZToLLNuNu_alpha2);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha3", &v_TTZToLLNuNu_alpha3);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha4", &v_TTZToLLNuNu_alpha4);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToLLNuNu_Jethadronflavor);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTZToLLNuNu_Jetpartonflavor);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetPt", &v_TTZToLLNuNu_JetPT);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetEta", &v_TTZToLLNuNu_JetEta);
    for (int evt = 0; evt < T_TTZToLLNuNu_tree->GetEntries(); evt++)
    {
        T_TTZToLLNuNu_tree->GetEntry(evt);
        double TTZToLLNuNu_eventWeight = I_TTZToLLNuNu_weight * TTZToLLNuNuWeight;
        for (size_t i = 0; i < v_TTZToLLNuNu_nTrack->size(); i++)
        {
            // Region 1
            if (abs((*v_TTZToLLNuNu_JetEta)[i]) < 1)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region1 = Top_bfakeRate_eta1->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
                double cWeightbybin_region1 = Top_cfakeRate_eta1->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
                double lWeightbybin_region1 = Top_lfakeRate_eta1->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], bWeightbybin_region1, h_Top_bJetPt_region1_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], cWeightbybin_region1, h_Top_cJetPt_region1_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], lWeightbybin_region1, h_Top_lJetPt_region1_bybin_CR);
                if ((*v_TTZToLLNuNu_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_bJetPt_region1_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_cJetPt_region1_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_lJetPt_region1_SR);
                }
            }
            // Region 2
            else if (abs((*v_TTZToLLNuNu_JetEta)[i]) > 1 && abs((*v_TTZToLLNuNu_JetEta)[i]) < 2)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region2 = Top_bfakeRate_eta2->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
                double cWeightbybin_region2 = Top_cfakeRate_eta2->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
                double lWeightbybin_region2 = Top_lfakeRate_eta2->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], bWeightbybin_region2, h_Top_bJetPt_region2_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], cWeightbybin_region2, h_Top_cJetPt_region2_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], lWeightbybin_region2, h_Top_lJetPt_region2_bybin_CR);
                if ((*v_TTZToLLNuNu_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_bJetPt_region2_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_cJetPt_region2_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_lJetPt_region2_SR);
                }
            }
            // Region 3
            else if (abs((*v_TTZToLLNuNu_JetEta)[i]) > 2 && abs((*v_TTZToLLNuNu_JetEta)[i]) < 2.5)
            {
                //----------------------------
                // apply bin by bin fake rate
                //----------------------------
                double bWeightbybin_region3 = Top_bfakeRate_eta3->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
                double cWeightbybin_region3 = Top_cfakeRate_eta3->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
                double lWeightbybin_region3 = Top_lfakeRate_eta3->GetBinContent((*v_TTZToLLNuNu_nTrack)[i] + 1) * TTZToLLNuNu_eventWeight;
                // b
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], bWeightbybin_region3, h_Top_bJetPt_region3_bybin_CR);
                // c
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], cWeightbybin_region3, h_Top_cJetPt_region3_bybin_CR);
                // l
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], lWeightbybin_region3, h_Top_lJetPt_region3_bybin_CR);
                if ((*v_TTZToLLNuNu_alpha)[i] < 0.1)
                {
                    // b
                    for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_bJetPt_region3_SR);
                    // c
                    for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_cJetPt_region3_SR);
                    // l
                    for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_JetPT)[i], TTZToLLNuNu_eventWeight, h_Top_lJetPt_region3_SR);
                }
            }
        }
    } // End of TTZToLLNuNu

    h_Top_bJetPt_region1_bybin_CR->SetLineWidth(2);
    h_Top_bJetPt_region1_SR->SetLineWidth(2);
    h_Top_bJetPt_region2_bybin_CR->SetLineWidth(2);
    h_Top_bJetPt_region2_SR->SetLineWidth(2);
    h_Top_bJetPt_region3_bybin_CR->SetLineWidth(2);
    h_Top_bJetPt_region3_SR->SetLineWidth(2);
    h_Top_cJetPt_region1_bybin_CR->SetLineWidth(2);
    h_Top_cJetPt_region1_SR->SetLineWidth(2);
    h_Top_cJetPt_region2_bybin_CR->SetLineWidth(2);
    h_Top_cJetPt_region2_SR->SetLineWidth(2);
    h_Top_cJetPt_region3_bybin_CR->SetLineWidth(2);
    h_Top_cJetPt_region3_SR->SetLineWidth(2);
    h_Top_lJetPt_region1_bybin_CR->SetLineWidth(2);
    h_Top_lJetPt_region1_SR->SetLineWidth(2);
    h_Top_lJetPt_region2_bybin_CR->SetLineWidth(2);
    h_Top_lJetPt_region2_SR->SetLineWidth(2);
    h_Top_lJetPt_region3_bybin_CR->SetLineWidth(2);
    h_Top_lJetPt_region3_SR->SetLineWidth(2);

    h_Top_bJetPt_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_bJetPt_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_bJetPt_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_cJetPt_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_cJetPt_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_cJetPt_region3_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_lJetPt_region1_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_lJetPt_region2_bybin_CR->SetLineColor(kGreen + 3);
    h_Top_lJetPt_region3_bybin_CR->SetLineColor(kGreen + 3);

    h_Top_bJetPt_region1_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_bJetPt_region2_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_bJetPt_region3_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_cJetPt_region1_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_cJetPt_region2_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_cJetPt_region3_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_lJetPt_region1_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_lJetPt_region2_SR->GetXaxis()->SetTitle("Jet PT");
    h_Top_lJetPt_region3_SR->GetXaxis()->SetTitle("Jet PT");

    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_cJetPt_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_cJetPt_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_cJetPt_region3_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitle("nJet");

    h_Top_bJetPt_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region1_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region2_SR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region3_SR->GetXaxis()->SetNdivisions(6, 5, 0);

    h_Top_bJetPt_region1_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region2_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region3_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region1_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region2_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_cJetPt_region3_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region1_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region2_SR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_lJetPt_region3_SR->GetYaxis()->SetNdivisions(6, 5, 0);

    h_Top_bJetPt_region1_SR->GetXaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region2_SR->GetXaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region3_SR->GetXaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region1_SR->GetXaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region2_SR->GetXaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region3_SR->GetXaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region1_SR->GetXaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region2_SR->GetXaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region3_SR->GetXaxis()->SetTitleSize(0.04);

    h_Top_bJetPt_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_bJetPt_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_cJetPt_region3_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region1_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region2_SR->GetYaxis()->SetTitleSize(0.04);
    h_Top_lJetPt_region3_SR->GetYaxis()->SetTitleSize(0.04);

    h_Top_bJetPt_region1_SR->GetXaxis()->SetLabelSize(0.04);
    h_Top_bJetPt_region2_SR->GetXaxis()->SetLabelSize(0.04);
    h_Top_bJetPt_region3_SR->GetXaxis()->SetLabelSize(0.04);
    h_Top_cJetPt_region1_SR->GetXaxis()->SetLabelSize(0.04);
    h_Top_cJetPt_region2_SR->GetXaxis()->SetLabelSize(0.04);
    h_Top_cJetPt_region3_SR->GetXaxis()->SetLabelSize(0.04);
    h_Top_lJetPt_region1_SR->GetXaxis()->SetLabelSize(0.04);
    h_Top_lJetPt_region2_SR->GetXaxis()->SetLabelSize(0.04);
    h_Top_lJetPt_region3_SR->GetXaxis()->SetLabelSize(0.04);

    h_Top_bJetPt_region1_SR->GetYaxis()->SetLabelSize(0.04);
    h_Top_bJetPt_region2_SR->GetYaxis()->SetLabelSize(0.04);
    h_Top_bJetPt_region3_SR->GetYaxis()->SetLabelSize(0.04);
    h_Top_cJetPt_region1_SR->GetYaxis()->SetLabelSize(0.04);
    h_Top_cJetPt_region2_SR->GetYaxis()->SetLabelSize(0.04);
    h_Top_cJetPt_region3_SR->GetYaxis()->SetLabelSize(0.04);
    h_Top_lJetPt_region1_SR->GetYaxis()->SetLabelSize(0.04);
    h_Top_lJetPt_region2_SR->GetYaxis()->SetLabelSize(0.04);
    h_Top_lJetPt_region3_SR->GetYaxis()->SetLabelSize(0.04);

    h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetTitle("Jet PT");
    h_Top_bJetPt_region1_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region2_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region3_bybin_CR->GetYaxis()->SetTitle("nJet");
    h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region1_bybin_CR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region2_bybin_CR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region3_bybin_CR->GetYaxis()->SetNdivisions(6, 5, 0);
    h_Top_bJetPt_region1_bybin_CR->GetXaxis()->SetLabelSize(0.04);
    h_Top_bJetPt_region2_bybin_CR->GetXaxis()->SetLabelSize(0.04);
    h_Top_bJetPt_region3_bybin_CR->GetXaxis()->SetLabelSize(0.04);
    h_Top_bJetPt_region1_bybin_CR->GetYaxis()->SetLabelSize(0.04);
    h_Top_bJetPt_region2_bybin_CR->GetYaxis()->SetLabelSize(0.04);
    h_Top_bJetPt_region3_bybin_CR->GetYaxis()->SetLabelSize(0.04);

    int W = 800;
    int H = 600;

    int H_ref = 600;
    int W_ref = 800;

    float T = 0.08 * H_ref;
    float B = 0.12 * H_ref;
    float L = 0.12 * W_ref;
    float R = 0.04 * W_ref;
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

    c1->Divide(3, 1);
    c1->cd(1);
    h_Top_bJetPt_region1_bybin_CR->Draw("h ");
    h_Top_bJetPt_region1_SR->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("Top process (b Jet in |eta| < 1)");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(h_Top_bJetPt_region1_SR, "Top SR", "l");
    l0->AddEntry(h_Top_bJetPt_region1_bybin_CR, "Top apply bin by bin result", "l");
    l0->Draw();
    c1->cd(2);

    h_Top_bJetPt_region2_bybin_CR->Draw("h");
    h_Top_bJetPt_region2_SR->Draw(" same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("Top process (b Jet in 1 < |eta| < 2)");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_Top_bJetPt_region2_SR, "Top SR", "l");
    l1->AddEntry(h_Top_bJetPt_region2_bybin_CR, "Top apply bin by bin result", "l");
    l1->Draw();
    c1->cd(3);

    h_Top_bJetPt_region3_SR->Draw();
    h_Top_bJetPt_region3_bybin_CR->Draw("h same");
    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("Top process (b Jet in 2 < |eta| < 2.5)");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(h_Top_bJetPt_region3_SR, "Top SR", "l");
    l2->AddEntry(h_Top_bJetPt_region3_bybin_CR, "Top apply bin by bin result", "l");
    l2->Draw();

    gStyle->SetOptStat(0);
}
