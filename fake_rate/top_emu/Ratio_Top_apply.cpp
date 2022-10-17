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
#include "./../../lib/Cross_section.h"
using namespace std;

//------------------
// Calculate weight
//------------------
TFile *TTTo2L2Nufile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTTo2L2Nu.root");
TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTWJetsToLNu.root");
TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTWJetsToQQ.root");
TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTZToQQ.root");
TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTZToLLNuNu.root");
TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_tW_antitop.root");
TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_tW_top.root");

//----------------------
// Get fake rate
//----------------------
TFile *Top_fakerate_topfile = new TFile("./../top/diffeta/new_macro/top_fakerate.root");

TFile *Top_emu_fakerate_topfile = new TFile("./top_emu_fakerate.root");

TH1D *Top_nTrk_fakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_difeta_1"));
TH1D *Top_nTrk_bfakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_1"));
TH1D *Top_nTrk_cfakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_cfakeRate_difeta_1"));
TH1D *Top_nTrk_lfakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_1"));
TH1D *Top_nTrk_hfakeRate_difeta_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_hfakeRate_difeta_1"));

TH1D *Top_nTrk_fakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_difeta_2"));
TH1D *Top_nTrk_bfakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_2"));
TH1D *Top_nTrk_cfakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_cfakeRate_difeta_2"));
TH1D *Top_nTrk_lfakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_2"));
TH1D *Top_nTrk_hfakeRate_difeta_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_hfakeRate_difeta_2"));

TH1D *Top_nTrk_fakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_difeta_3"));
TH1D *Top_nTrk_bfakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_3"));
TH1D *Top_nTrk_cfakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_cfakeRate_difeta_3"));
TH1D *Top_nTrk_lfakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_3"));
TH1D *Top_nTrk_hfakeRate_difeta_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_hfakeRate_difeta_3"));

TH1D *Top_nTrk_bfakeRate = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_bfakeRate"));
TH1D *Top_nTrk_cfakeRate = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_cfakeRate"));
TH1D *Top_nTrk_lfakeRate = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_lfakeRate"));
TH1D *Top_nTrk_hfakeRate = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_hfakeRate"));
TH1D *Top_nTrk_fakeRate = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate"));

//---------------------------
// Get Top to e mu fake rate
//---------------------------
TH1D *Top_nTrk_fakeRate_lowDilepPt = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_fakeRate_highDilepPt"));
TH1D *Top_nTrk_bfakeRate_lowDilepPt = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_highDilepPt"));
TH1D *Top_nTrk_lfakeRate_lowDilepPt = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_highDilepPt"));
// Consider eta
TH1D *Top_nTrk_bfakeRate_lowDilepPt_1 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_lowDilepPt_1"));
TH1D *Top_nTrk_lfakeRate_lowDilepPt_1 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_lowDilepPt_1"));
TH1D *Top_nTrk_bfakeRate_lowDilepPt_2 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_lowDilepPt_2"));
TH1D *Top_nTrk_lfakeRate_lowDilepPt_2 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_lowDilepPt_2"));
TH1D *Top_nTrk_bfakeRate_lowDilepPt_3 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_lowDilepPt_3"));
TH1D *Top_nTrk_lfakeRate_lowDilepPt_3 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_lowDilepPt_3"));



TH1D *TTTo2L2Nu_sumevt = ((TH1D *)TTTo2L2Nufile->Get("Event_Variable/h_totevent"));
TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNufile->Get("Event_Variable/h_totevent"));
TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQfile->Get("Event_Variable/h_totevent"));
TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQfile->Get("Event_Variable/h_totevent"));
TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNufile->Get("Event_Variable/h_totevent"));
TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitopfile->Get("Event_Variable/h_totevent"));
TH1D *tW_top_sumevt = ((TH1D *)Top_tW_topfile->Get("Event_Variable/h_totevent"));

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

vector<double> v_xs_Weight = {TTTo2L2NuWeight, ST_tW_topWeight, ST_tW_antitopWeight, TTWJetsToLNuWeight, TTWJetsToQQWeight, TTZToQQWeight, TTZToLLNuNuWeight};
vector<const char *> v_top_filename = {"TTTo2L2Nu", "tW_top", "tW_antitop", "TTWJetsToLNu", "TTWJetsToQQ", "TTZToQQ", "TTZToLLNuNu"};
double getWeight(const char *file_name_tmp)
{
    TString file_name = file_name_tmp;
    for (int i = 0; i < v_top_filename.size(); i++)
    {
        if (file_name.Contains(v_top_filename[i]))
        {
            return v_xs_Weight[i];
        }
    }
    Fatal("getWeight", "%s is not a valid file", file_name_tmp);
    return -100000;
}
//-------------------------------------------------------------
//    Fake rate cut bin information
//    const Int_t NBINS = 5;
//    Double_t edges[NBINS + 1] = {1., 5., 10., 15., 20., 40.};
//-------------------------------------------------------------
int getfakerate(float tmp1, float start, float Binwidth)
{
    int quotient;
    quotient = floor((tmp1 - start) / (Binwidth));
    return quotient + 1;
}
int getbinfakerate(float tmp_ntrk)
{
    int bin_pos_info;
    if (tmp_ntrk < 5)
    {
        bin_pos_info = 1;
    }
    else if (tmp_ntrk < 10)
    {
        bin_pos_info = 2;
    }
    else if (tmp_ntrk < 15)
    {
        bin_pos_info = 3;
    }
    else if (tmp_ntrk < 20)
    {
        bin_pos_info = 4;
    }
    else
    {
        bin_pos_info = 5;
    }
    return bin_pos_info;
}

//

//---------------
// void Function
//---------------
void for_signalflavor_jet2d(int flavor, float hadronflavor, float tmp1, float tmp2, double Weight, TH2D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp1, tmp2, Weight);
    }
}
void for_signalflavor_jet(int flavor, float hadronflavor, float tmp1, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp1, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, int flavor2, int hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

void Ratio_Top_apply(TString file = "/home/kuanyu/Documents/root_file/BgEstimation/top_TTTo2L2Nu_2.root", TString outputfile = "output.root")
{
    TFile *Topfile = TFile::Open(file);
    cout << "Top weight = " << getWeight(file) << endl;

    const Int_t NBINS = 5;
    Double_t edges[NBINS + 1] = {1., 5., 10., 15., 20., 40.};

    TH1D *h_Top_trk_bybin_CR = new TH1D("h_Top_trk_bybin_CR", "", NBINS, edges);
    h_Top_trk_bybin_CR->Sumw2();

    TH1D *h_Top_btrk_bybin_CR = new TH1D("h_Top_btrk_bybin_CR", "", NBINS, edges);
    h_Top_btrk_bybin_CR->Sumw2();

    TH1D *h_Top_ctrk_bybin_CR = new TH1D("h_Top_ctrk_bybin_CR", "",NBINS, edges);
    h_Top_ctrk_bybin_CR->Sumw2();

    TH1D *h_Top_ltrk_bybin_CR = new TH1D("h_Top_ltrk_bybin_CR", "", NBINS, edges);
    h_Top_ltrk_bybin_CR->Sumw2();

    TH1D *h_Top_htrk_bybin_CR = new TH1D("h_Top_htrk_bybin_CR", "",NBINS, edges);
    h_Top_htrk_bybin_CR->Sumw2();

    TH1D *h_Top_trk_SR = new TH1D("h_Top_trk_SR", "", NBINS, edges);
    h_Top_trk_SR->Sumw2();

    TH1D *h_Top_btrk_SR = new TH1D("h_Top_btrk_SR", "", NBINS, edges);
    h_Top_btrk_SR->Sumw2();

    TH1D *h_Top_ctrk_SR = new TH1D("h_Top_ctrk_SR", "",NBINS, edges);
    h_Top_ctrk_SR->Sumw2();

    TH1D *h_Top_ltrk_SR = new TH1D("h_Top_ltrk_SR", "", NBINS, edges);
    h_Top_ltrk_SR->Sumw2();

    TH1D *h_Top_htrk_SR = new TH1D("h_Top_htrk_SR", "",NBINS, edges);
    h_Top_htrk_SR->Sumw2();

    // Jet PT

    TH1D *h_Top_JetPt_bybin_CR = new TH1D("h_Top_JetPt_bybin_CR", "", 20., 0., 1000.);
    h_Top_JetPt_bybin_CR->Sumw2();

    TH1D *h_Top_bJetPt_bybin_CR = new TH1D("h_Top_bJetPt_bybin_CR", "", 20., 0., 1000.);
    h_Top_bJetPt_bybin_CR->Sumw2();

    TH1D *h_Top_lJetPt_bybin_CR = new TH1D("h_Top_lJetPt_bybin_CR", "", 20., 0., 1000.);
    h_Top_lJetPt_bybin_CR->Sumw2();

    TH1D *h_Top_bJetPt_SR = new TH1D("h_Top_bJetPt_SR", "", 20., 0., 1000.);
    h_Top_bJetPt_SR->Sumw2();

    TH1D *h_Top_lJetPt_SR = new TH1D("h_Top_lJetPt_SR", "", 20., 0., 1000.);
    h_Top_lJetPt_SR->Sumw2();

    // Jet Eta
    TH1D *h_Top_JetEta_bybin_CR = new TH1D("h_Top_JetEta_bybin_CR", "", 10., -3., 3.);
    h_Top_JetEta_bybin_CR->Sumw2();

    TH1D *h_Top_bJetEta_bybin_CR = new TH1D("h_Top_bJetEta_bybin_CR", "", 10., -3., 3.);
    h_Top_bJetEta_bybin_CR->Sumw2();

    TH1D *h_Top_lJetEta_bybin_CR = new TH1D("h_Top_lJetEta_bybin_CR", "", 10., -3., 3.);
    h_Top_lJetEta_bybin_CR->Sumw2();

    TH1D *h_Top_bJetEta_SR = new TH1D("h_Top_bJetEta_SR", "", 10., -3., 3.);
    h_Top_bJetEta_SR->Sumw2();

    TH1D *h_Top_lJetEta_SR = new TH1D("h_Top_lJetEta_SR", "", 10., -3., 3.);
    h_Top_lJetEta_SR->Sumw2();

    //----------------------
    //  nTrk : different eta
    //----------------------
    TH1D *h_Top_trk_region1_bybin_CR = new TH1D("h_Top_trk_region1_bybin_CR", "",NBINS, edges);
    h_Top_trk_region1_bybin_CR->Sumw2();
    TH1D *h_Top_trk_region2_bybin_CR = new TH1D("h_Top_trk_region2_bybin_CR", "",NBINS, edges);
    h_Top_trk_region2_bybin_CR->Sumw2();
    TH1D *h_Top_trk_region3_bybin_CR = new TH1D("h_Top_trk_region3_bybin_CR", "",NBINS, edges);
    h_Top_trk_region3_bybin_CR->Sumw2();

    TH1D *h_Top_btrk_region1_bybin_CR = new TH1D("h_Top_btrk_region1_bybin_CR", "",NBINS, edges);
    h_Top_btrk_region1_bybin_CR->Sumw2();
    TH1D *h_Top_btrk_region2_bybin_CR = new TH1D("h_Top_btrk_region2_bybin_CR", "",NBINS, edges);
    h_Top_btrk_region2_bybin_CR->Sumw2();
    TH1D *h_Top_btrk_region3_bybin_CR = new TH1D("h_Top_btrk_region3_bybin_CR", "",NBINS, edges);
    h_Top_btrk_region3_bybin_CR->Sumw2();

    TH1D *h_Top_ctrk_region1_bybin_CR = new TH1D("h_Top_ctrk_region1_bybin_CR", "",NBINS, edges);
    h_Top_ctrk_region1_bybin_CR->Sumw2();
    TH1D *h_Top_ctrk_region2_bybin_CR = new TH1D("h_Top_ctrk_region2_bybin_CR", "",NBINS, edges);
    h_Top_ctrk_region2_bybin_CR->Sumw2();
    TH1D *h_Top_ctrk_region3_bybin_CR = new TH1D("h_Top_ctrk_region3_bybin_CR", "",NBINS, edges);
    h_Top_ctrk_region3_bybin_CR->Sumw2();

    TH1D *h_Top_ltrk_region1_bybin_CR = new TH1D("h_Top_ltrk_region1_bybin_CR", "",NBINS, edges);
    h_Top_ltrk_region1_bybin_CR->Sumw2();
    TH1D *h_Top_ltrk_region2_bybin_CR = new TH1D("h_Top_ltrk_region2_bybin_CR", "",NBINS, edges);
    h_Top_ltrk_region2_bybin_CR->Sumw2();
    TH1D *h_Top_ltrk_region3_bybin_CR = new TH1D("h_Top_ltrk_region3_bybin_CR", "",NBINS, edges);
    h_Top_ltrk_region3_bybin_CR->Sumw2();

    TH1D *h_Top_htrk_region1_bybin_CR = new TH1D("h_Top_htrk_region1_bybin_CR", "",NBINS, edges);
    h_Top_htrk_region1_bybin_CR->Sumw2();
    TH1D *h_Top_htrk_region2_bybin_CR = new TH1D("h_Top_htrk_region2_bybin_CR", "",NBINS, edges);
    h_Top_htrk_region2_bybin_CR->Sumw2();
    TH1D *h_Top_htrk_region3_bybin_CR = new TH1D("h_Top_htrk_region3_bybin_CR", "",NBINS, edges);
    h_Top_htrk_region3_bybin_CR->Sumw2();

    TH1D *h_Top_trk_region1_SR = new TH1D("h_Top_trk_region1_SR", "",NBINS, edges);
    h_Top_trk_region1_SR->Sumw2();
    TH1D *h_Top_trk_region2_SR = new TH1D("h_Top_trk_region2_SR", "",NBINS, edges);
    h_Top_trk_region2_SR->Sumw2();
    TH1D *h_Top_trk_region3_SR = new TH1D("h_Top_trk_region3_SR", "",NBINS, edges);
    h_Top_trk_region3_SR->Sumw2();

    TH1D *h_Top_btrk_region1_SR = new TH1D("h_Top_btrk_region1_SR", "",NBINS, edges);
    h_Top_btrk_region1_SR->Sumw2();
    TH1D *h_Top_btrk_region2_SR = new TH1D("h_Top_btrk_region2_SR", "",NBINS, edges);
    h_Top_btrk_region2_SR->Sumw2();
    TH1D *h_Top_btrk_region3_SR = new TH1D("h_Top_btrk_region3_SR", "",NBINS, edges);
    h_Top_btrk_region3_SR->Sumw2();

    TH1D *h_Top_ctrk_region1_SR = new TH1D("h_Top_ctrk_region1_SR", "",NBINS, edges);
    h_Top_ctrk_region1_SR->Sumw2();
    TH1D *h_Top_ctrk_region2_SR = new TH1D("h_Top_ctrk_region2_SR", "",NBINS, edges);
    h_Top_ctrk_region2_SR->Sumw2();
    TH1D *h_Top_ctrk_region3_SR = new TH1D("h_Top_ctrk_region3_SR", "",NBINS, edges);
    h_Top_ctrk_region3_SR->Sumw2();

    TH1D *h_Top_ltrk_region1_SR = new TH1D("h_Top_ltrk_region1_SR", "",NBINS, edges);
    h_Top_ltrk_region1_SR->Sumw2();
    TH1D *h_Top_ltrk_region2_SR = new TH1D("h_Top_ltrk_region2_SR", "",NBINS, edges);
    h_Top_ltrk_region2_SR->Sumw2();
    TH1D *h_Top_ltrk_region3_SR = new TH1D("h_Top_ltrk_region3_SR", "",NBINS, edges);
    h_Top_ltrk_region3_SR->Sumw2();

    TH1D *h_Top_htrk_region1_SR = new TH1D("h_Top_htrk_region1_SR", "",NBINS, edges);
    h_Top_htrk_region1_SR->Sumw2();
    TH1D *h_Top_htrk_region2_SR = new TH1D("h_Top_htrk_region2_SR", "",NBINS, edges);
    h_Top_htrk_region2_SR->Sumw2();
    TH1D *h_Top_htrk_region3_SR = new TH1D("h_Top_htrk_region3_SR", "",NBINS, edges);
    h_Top_htrk_region3_SR->Sumw2();

    //--------------------
    //       JetPt
    //--------------------

    TH1D *h_Top_cJetPt_bybin_CR = new TH1D("h_Top_cJetPt_bybin_CR", "", 20., 0., 1000.);
    h_Top_cJetPt_bybin_CR->Sumw2();

    TH1D *h_Top_hJetPt_bybin_CR = new TH1D("h_Top_hJetPt_bybin_CR", "", 20., 0., 1000.);
    h_Top_hJetPt_bybin_CR->Sumw2();

    TH1D *h_Top_JetPt_SR = new TH1D("h_Top_JetPt_SR", "", 20., 0., 1000.);
    h_Top_JetPt_SR->Sumw2();

    TH1D *h_Top_cJetPt_SR = new TH1D("h_Top_cJetPt_SR", "", 20., 0., 1000.);
    h_Top_cJetPt_SR->Sumw2();

    TH1D *h_Top_hJetPt_SR = new TH1D("h_Top_hJetPt_SR", "", 20., 0., 1000.);
    h_Top_hJetPt_SR->Sumw2();

    //----------------------
    //  JetPt : different eta
    //----------------------
    TH1D *h_Top_JetPt_region1_bybin_CR = new TH1D("h_Top_JetPt_region1_bybin_CR", "", 20., 0., 1000.);
    h_Top_JetPt_region1_bybin_CR->Sumw2();
    TH1D *h_Top_JetPt_region2_bybin_CR = new TH1D("h_Top_JetPt_region2_bybin_CR", "", 20., 0., 1000.);
    h_Top_JetPt_region2_bybin_CR->Sumw2();
    TH1D *h_Top_JetPt_region3_bybin_CR = new TH1D("h_Top_JetPt_region3_bybin_CR", "", 20., 0., 1000.);
    h_Top_JetPt_region3_bybin_CR->Sumw2();

    TH1D *h_Top_bJetPt_region1_bybin_CR = new TH1D("h_Top_bJetPt_region1_bybin_CR", "", 20., 0., 1000.);
    h_Top_bJetPt_region1_bybin_CR->Sumw2();
    TH1D *h_Top_bJetPt_region2_bybin_CR = new TH1D("h_Top_bJetPt_region2_bybin_CR", "", 20., 0., 1000.);
    h_Top_bJetPt_region2_bybin_CR->Sumw2();
    TH1D *h_Top_bJetPt_region3_bybin_CR = new TH1D("h_Top_bJetPt_region3_bybin_CR", "", 20., 0., 1000.);
    h_Top_bJetPt_region3_bybin_CR->Sumw2();

    TH1D *h_Top_cJetPt_region1_bybin_CR = new TH1D("h_Top_cJetPt_region1_bybin_CR", "", 20., 0., 1000.);
    h_Top_cJetPt_region1_bybin_CR->Sumw2();
    TH1D *h_Top_cJetPt_region2_bybin_CR = new TH1D("h_Top_cJetPt_region2_bybin_CR", "", 20., 0., 1000.);
    h_Top_cJetPt_region2_bybin_CR->Sumw2();
    TH1D *h_Top_cJetPt_region3_bybin_CR = new TH1D("h_Top_cJetPt_region3_bybin_CR", "", 20., 0., 1000.);
    h_Top_cJetPt_region3_bybin_CR->Sumw2();

    TH1D *h_Top_lJetPt_region1_bybin_CR = new TH1D("h_Top_lJetPt_region1_bybin_CR", "", 20., 0., 1000.);
    h_Top_lJetPt_region1_bybin_CR->Sumw2();
    TH1D *h_Top_lJetPt_region2_bybin_CR = new TH1D("h_Top_lJetPt_region2_bybin_CR", "", 20., 0., 1000.);
    h_Top_lJetPt_region2_bybin_CR->Sumw2();
    TH1D *h_Top_lJetPt_region3_bybin_CR = new TH1D("h_Top_lJetPt_region3_bybin_CR", "", 20., 0., 1000.);
    h_Top_lJetPt_region3_bybin_CR->Sumw2();

    TH1D *h_Top_hJetPt_region1_bybin_CR = new TH1D("h_Top_hJetPt_region1_bybin_CR", "", 20., 0., 1000.);
    h_Top_hJetPt_region1_bybin_CR->Sumw2();
    TH1D *h_Top_hJetPt_region2_bybin_CR = new TH1D("h_Top_hJetPt_region2_bybin_CR", "", 20., 0., 1000.);
    h_Top_hJetPt_region2_bybin_CR->Sumw2();
    TH1D *h_Top_hJetPt_region3_bybin_CR = new TH1D("h_Top_hJetPt_region3_bybin_CR", "", 20., 0., 1000.);
    h_Top_hJetPt_region3_bybin_CR->Sumw2();

    TH1D *h_Top_JetPt_region1_SR = new TH1D("h_Top_JetPt_region1_SR", "", 20., 0., 1000.);
    h_Top_JetPt_region1_SR->Sumw2();
    TH1D *h_Top_JetPt_region2_SR = new TH1D("h_Top_JetPt_region2_SR", "", 20., 0., 1000.);
    h_Top_JetPt_region2_SR->Sumw2();
    TH1D *h_Top_JetPt_region3_SR = new TH1D("h_Top_JetPt_region3_SR", "", 20., 0., 1000.);
    h_Top_JetPt_region3_SR->Sumw2();

    TH1D *h_Top_bJetPt_region1_SR = new TH1D("h_Top_bJetPt_region1_SR", "", 20., 0., 1000.);
    h_Top_bJetPt_region1_SR->Sumw2();
    TH1D *h_Top_bJetPt_region2_SR = new TH1D("h_Top_bJetPt_region2_SR", "", 20., 0., 1000.);
    h_Top_bJetPt_region2_SR->Sumw2();
    TH1D *h_Top_bJetPt_region3_SR = new TH1D("h_Top_bJetPt_region3_SR", "", 20., 0., 1000.);
    h_Top_bJetPt_region3_SR->Sumw2();

    TH1D *h_Top_cJetPt_region1_SR = new TH1D("h_Top_cJetPt_region1_SR", "", 20., 0., 1000.);
    h_Top_cJetPt_region1_SR->Sumw2();
    TH1D *h_Top_cJetPt_region2_SR = new TH1D("h_Top_cJetPt_region2_SR", "", 20., 0., 1000.);
    h_Top_cJetPt_region2_SR->Sumw2();
    TH1D *h_Top_cJetPt_region3_SR = new TH1D("h_Top_cJetPt_region3_SR", "", 20., 0., 1000.);
    h_Top_cJetPt_region3_SR->Sumw2();

    TH1D *h_Top_lJetPt_region1_SR = new TH1D("h_Top_lJetPt_region1_SR", "", 20., 0., 1000.);
    h_Top_lJetPt_region1_SR->Sumw2();
    TH1D *h_Top_lJetPt_region2_SR = new TH1D("h_Top_lJetPt_region2_SR", "", 20., 0., 1000.);
    h_Top_lJetPt_region2_SR->Sumw2();
    TH1D *h_Top_lJetPt_region3_SR = new TH1D("h_Top_lJetPt_region3_SR", "", 20., 0., 1000.);
    h_Top_lJetPt_region3_SR->Sumw2();

    TH1D *h_Top_hJetPt_region1_SR = new TH1D("h_Top_hJetPt_region1_SR", "", 20., 0., 1000.);
    h_Top_hJetPt_region1_SR->Sumw2();
    TH1D *h_Top_hJetPt_region2_SR = new TH1D("h_Top_hJetPt_region2_SR", "", 20., 0., 1000.);
    h_Top_hJetPt_region2_SR->Sumw2();
    TH1D *h_Top_hJetPt_region3_SR = new TH1D("h_Top_hJetPt_region3_SR", "", 20., 0., 1000.);
    h_Top_hJetPt_region3_SR->Sumw2();

    //--------------------
    //       JetEta
    //--------------------

    TH1D *h_Top_cJetEta_bybin_CR = new TH1D("h_Top_cJetEta_bybin_CR", "", 30, -3., 3.);
    h_Top_cJetEta_bybin_CR->Sumw2();

    TH1D *h_Top_hJetEta_bybin_CR = new TH1D("h_Top_hJetEta_bybin_CR", "", 30, -3., 3.);
    h_Top_hJetEta_bybin_CR->Sumw2();

    TH1D *h_Top_JetEta_SR = new TH1D("h_Top_JetEta_SR", "", 10, -3., 3.);
    h_Top_JetEta_SR->Sumw2();

    TH1D *h_Top_cJetEta_SR = new TH1D("h_Top_cJetEta_SR", "", 30, -3., 3.);
    h_Top_cJetEta_SR->Sumw2();

    TH1D *h_Top_hJetEta_SR = new TH1D("h_Top_hJetEta_SR", "", 30, -3., 3.);
    h_Top_hJetEta_SR->Sumw2();

    //----------------------
    //  JetEta : different eta
    //----------------------
    /*
    TH1D *h_Top_JetEta_region1_bybin_CR = new TH1D("h_Top_JetEta_region1_bybin_CR", "", 30, -3., 3.);
    h_Top_JetEta_region1_bybin_CR->Sumw2();
    TH1D *h_Top_JetEta_region2_bybin_CR = new TH1D("h_Top_JetEta_region2_bybin_CR", "", 30, -3., 3.);
    h_Top_JetEta_region2_bybin_CR->Sumw2();
    TH1D *h_Top_JetEta_region3_bybin_CR = new TH1D("h_Top_JetEta_region3_bybin_CR", "", 30, -3., 3.);
    h_Top_JetEta_region3_bybin_CR->Sumw2();

    TH1D *h_Top_bJetEta_region1_bybin_CR = new TH1D("h_Top_bJetEta_region1_bybin_CR", "", 30, -3., 3.);
    h_Top_bJetEta_region1_bybin_CR->Sumw2();
    TH1D *h_Top_bJetEta_region2_bybin_CR = new TH1D("h_Top_bJetEta_region2_bybin_CR", "", 30, -3., 3.);
    h_Top_bJetEta_region2_bybin_CR->Sumw2();
    TH1D *h_Top_bJetEta_region3_bybin_CR = new TH1D("h_Top_bJetEta_region3_bybin_CR", "", 30, -3., 3.);
    h_Top_bJetEta_region3_bybin_CR->Sumw2();

    TH1D *h_Top_cJetEta_region1_bybin_CR = new TH1D("h_Top_cJetEta_region1_bybin_CR", "", 30, -3., 3.);
    h_Top_cJetEta_region1_bybin_CR->Sumw2();
    TH1D *h_Top_cJetEta_region2_bybin_CR = new TH1D("h_Top_cJetEta_region2_bybin_CR", "", 30, -3., 3.);
    h_Top_cJetEta_region2_bybin_CR->Sumw2();
    TH1D *h_Top_cJetEta_region3_bybin_CR = new TH1D("h_Top_cJetEta_region3_bybin_CR", "", 30, -3., 3.);
    h_Top_cJetEta_region3_bybin_CR->Sumw2();

    TH1D *h_Top_lJetEta_region1_bybin_CR = new TH1D("h_Top_lJetEta_region1_bybin_CR", "", 30, -3., 3.);
    h_Top_lJetEta_region1_bybin_CR->Sumw2();
    TH1D *h_Top_lJetEta_region2_bybin_CR = new TH1D("h_Top_lJetEta_region2_bybin_CR", "", 30, -3., 3.);
    h_Top_lJetEta_region2_bybin_CR->Sumw2();
    TH1D *h_Top_lJetEta_region3_bybin_CR = new TH1D("h_Top_lJetEta_region3_bybin_CR", "", 30, -3., 3.);
    h_Top_lJetEta_region3_bybin_CR->Sumw2();

    TH1D *h_Top_hJetEta_region1_bybin_CR = new TH1D("h_Top_hJetEta_region1_bybin_CR", "", 30, -3., 3.);
    h_Top_hJetEta_region1_bybin_CR->Sumw2();
    TH1D *h_Top_hJetEta_region2_bybin_CR = new TH1D("h_Top_hJetEta_region2_bybin_CR", "", 30, -3., 3.);
    h_Top_hJetEta_region2_bybin_CR->Sumw2();
    TH1D *h_Top_hJetEta_region3_bybin_CR = new TH1D("h_Top_hJetEta_region3_bybin_CR", "", 30, -3., 3.);
    h_Top_hJetEta_region3_bybin_CR->Sumw2();

    TH1D *h_Top_JetEta_region1_SR = new TH1D("h_Top_JetEta_region1_SR", "", 30, -3., 3.);
    h_Top_JetEta_region1_SR->Sumw2();
    TH1D *h_Top_JetEta_region2_SR = new TH1D("h_Top_JetEta_region2_SR", "", 30, -3., 3.);
    h_Top_JetEta_region2_SR->Sumw2();
    TH1D *h_Top_JetEta_region3_SR = new TH1D("h_Top_JetEta_region3_SR", "", 30, -3., 3.);
    h_Top_JetEta_region3_SR->Sumw2();

    TH1D *h_Top_bJetEta_region1_SR = new TH1D("h_Top_bJetEta_region1_SR", "", 30, -3., 3.);
    h_Top_bJetEta_region1_SR->Sumw2();
    TH1D *h_Top_bJetEta_region2_SR = new TH1D("h_Top_bJetEta_region2_SR", "", 30, -3., 3.);
    h_Top_bJetEta_region2_SR->Sumw2();
    TH1D *h_Top_bJetEta_region3_SR = new TH1D("h_Top_bJetEta_region3_SR", "", 30, -3., 3.);
    h_Top_bJetEta_region3_SR->Sumw2();

    TH1D *h_Top_cJetEta_region1_SR = new TH1D("h_Top_cJetEta_region1_SR", "", 30, -3., 3.);
    h_Top_cJetEta_region1_SR->Sumw2();
    TH1D *h_Top_cJetEta_region2_SR = new TH1D("h_Top_cJetEta_region2_SR", "", 30, -3., 3.);
    h_Top_cJetEta_region2_SR->Sumw2();
    TH1D *h_Top_cJetEta_region3_SR = new TH1D("h_Top_cJetEta_region3_SR", "", 30, -3., 3.);
    h_Top_cJetEta_region3_SR->Sumw2();

    TH1D *h_Top_lJetEta_region1_SR = new TH1D("h_Top_lJetEta_region1_SR", "", 30, -3., 3.);
    h_Top_lJetEta_region1_SR->Sumw2();
    TH1D *h_Top_lJetEta_region2_SR = new TH1D("h_Top_lJetEta_region2_SR", "", 30, -3., 3.);
    h_Top_lJetEta_region2_SR->Sumw2();
    TH1D *h_Top_lJetEta_region3_SR = new TH1D("h_Top_lJetEta_region3_SR", "", 30, -3., 3.);
    h_Top_lJetEta_region3_SR->Sumw2();

    TH1D *h_Top_hJetEta_region1_SR = new TH1D("h_Top_hJetEta_region1_SR", "", 30, -3., 3.);
    h_Top_hJetEta_region1_SR->Sumw2();
    TH1D *h_Top_hJetEta_region2_SR = new TH1D("h_Top_hJetEta_region2_SR", "", 30, -3., 3.);
    h_Top_hJetEta_region2_SR->Sumw2();
    TH1D *h_Top_hJetEta_region3_SR = new TH1D("h_Top_hJetEta_region3_SR", "", 30, -3., 3.);
    h_Top_hJetEta_region3_SR->Sumw2();
    */
    TH1D *h_Top_JetEta_diffregion_bybin_CR = new TH1D("h_Top_JetEta_diffregion_bybin_CR", "", 30, -3., 3.);
    h_Top_JetEta_diffregion_bybin_CR->Sumw2();

    TH1D *h_Top_bJetEta_diffregion_bybin_CR = new TH1D("h_Top_bJetEta_diffregion_bybin_CR", "", 30, -3., 3.);
    h_Top_bJetEta_diffregion_bybin_CR->Sumw2();

    TH1D *h_Top_cJetEta_diffregion_bybin_CR = new TH1D("h_Top_cJetEta_diffregion_bybin_CR", "", 30, -3., 3.);
    h_Top_cJetEta_diffregion_bybin_CR->Sumw2();

    TH1D *h_Top_lJetEta_diffregion_bybin_CR = new TH1D("h_Top_lJetEta_diffregion_bybin_CR", "", 30, -3., 3.);
    h_Top_lJetEta_diffregion_bybin_CR->Sumw2();

    TH1D *h_Top_hJetEta_diffregion_bybin_CR = new TH1D("h_Top_hJetEta_diffregion_bybin_CR", "", 30, -3., 3.);
    h_Top_hJetEta_diffregion_bybin_CR->Sumw2();

    TH1D *h_Top_JetEta_diffregion_SR = new TH1D("h_Top_JetEta_diffregion_SR", "", 30, -3., 3.);
    h_Top_JetEta_diffregion_SR->Sumw2();

    TH1D *h_Top_bJetEta_diffregion_SR = new TH1D("h_Top_bJetEta_diffregion_SR", "", 30, -3., 3.);
    h_Top_bJetEta_diffregion_SR->Sumw2();

    TH1D *h_Top_cJetEta_diffregion_SR = new TH1D("h_Top_cJetEta_diffregion_SR", "", 30, -3., 3.);
    h_Top_cJetEta_diffregion_SR->Sumw2();

    TH1D *h_Top_lJetEta_diffregion_SR = new TH1D("h_Top_lJetEta_diffregion_SR", "", 30, -3., 3.);
    h_Top_lJetEta_diffregion_SR->Sumw2();

    TH1D *h_Top_hJetEta_diffregion_SR = new TH1D("h_Top_hJetEta_diffregion_SR", "", 30, -3., 3.);
    h_Top_hJetEta_diffregion_SR->Sumw2();

    Int_t I_Top_nJets;

    Int_t I_Top_weight;

    float_t f_Top_met, f_Top_dileppt;

    vector<float> *v_Top_alpha = new vector<float>();
    vector<float> *v_Top_Chi3Dlog = new vector<float>();
    vector<float> *v_Top_2DIP = new vector<float>();
    vector<float> *v_Top_nTrack = new vector<float>();
    vector<float> *v_Top_Jethadronflavor = new vector<float>();
    vector<float> *v_Top_Jetpartonflavor = new vector<float>();
    vector<float> *v_Top_JetPT = new vector<float>();
    vector<float> *v_Top_JetEta = new vector<float>();

    v_Top_alpha->clear();
    v_Top_Chi3Dlog->clear();
    v_Top_2DIP->clear();
    v_Top_nTrack->clear();
    v_Top_Jethadronflavor->clear();
    v_Top_Jetpartonflavor->clear();
    v_Top_JetPT->clear();
    v_Top_JetEta->clear();

    TTree *T_Top_tree;
    Topfile->GetObject("h2", T_Top_tree);
    T_Top_tree->SetBranchAddress("I_weight", &I_Top_weight);
    T_Top_tree->SetBranchAddress("I_nJets", &I_Top_nJets);
    T_Top_tree->SetBranchAddress("v_N_Tracks", &v_Top_nTrack);
    T_Top_tree->SetBranchAddress("f_Met", &f_Top_met);
    T_Top_tree->SetBranchAddress("f_dileptonPT", &f_Top_dileppt);
    T_Top_tree->SetBranchAddress("v_IP2D", &v_Top_2DIP);
    T_Top_tree->SetBranchAddress("v_Chi3Dlog", &v_Top_Chi3Dlog);
    T_Top_tree->SetBranchAddress("v_fakealpha", &v_Top_alpha);
    T_Top_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Top_Jethadronflavor);
    T_Top_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Top_Jetpartonflavor);
    T_Top_tree->SetBranchAddress("v_fakeJetPt", &v_Top_JetPT);
    T_Top_tree->SetBranchAddress("v_fakeJetEta", &v_Top_JetEta);
    for (int evt = 0; evt < T_Top_tree->GetEntries(); evt++)
    {
        T_Top_tree->GetEntry(evt);
        double Top_weight = getWeight(file) * I_Top_weight;
        // double Top_weight = 1.;
        //--------------------------------
        // Old version of fake rate apply
        //--------------------------------
        /*
        double bxBinwidth = Top_nTrk_fakeRate->GetBinWidth(5);
        for (int i = 0; i < v_Top_nTrack->size(); i++)
        {
            int bxBin_local = getfakerate((*v_Top_nTrack)[i], 1., bxBinwidth);
            int cxBin_local = getfakerate((*v_Top_nTrack)[i], 1., bxBinwidth);
            int lxBin_local = getfakerate((*v_Top_nTrack)[i], 1., bxBinwidth);

            if (bxBin_local != cxBin_local)
            {
                cout << "bxBin_local = " << bxBin_local << endl;
                cout << "cxBin_local = " << cxBin_local << endl;
                cout << "lxBin_local = " << lxBin_local << endl;
            }
            double fakerate = Top_nTrk_fakeRate->GetBinContent(bxBin_local) * Top_weight;
            double b_fakerate = Top_nTrk_bfakeRate->GetBinContent(bxBin_local) * Top_weight;
            double c_fakerate = Top_nTrk_cfakeRate->GetBinContent(bxBin_local) * Top_weight;
            double l_fakerate = Top_nTrk_lfakeRate->GetBinContent(bxBin_local) * Top_weight;
            double h_fakerate = Top_nTrk_hfakeRate->GetBinContent(bxBin_local) * Top_weight;

            h_Top_trk_bybin_CR->Fill((*v_Top_nTrack)[i], fakerate);
            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], b_fakerate, h_Top_btrk_bybin_CR);
            for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], c_fakerate, h_Top_ctrk_bybin_CR);
            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], l_fakerate, h_Top_ltrk_bybin_CR);
            for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], h_fakerate, h_Top_htrk_bybin_CR);

            // For Jet PT
            h_Top_JetPt_bybin_CR->Fill((*v_Top_JetPT)[i], fakerate);
            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], b_fakerate, h_Top_bJetPt_bybin_CR);
            for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], c_fakerate, h_Top_cJetPt_bybin_CR);
            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], l_fakerate, h_Top_lJetPt_bybin_CR);
            for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], h_fakerate, h_Top_hJetPt_bybin_CR);

            // For Jet Eta
            h_Top_JetEta_bybin_CR->Fill((*v_Top_JetEta)[i], fakerate);
            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], b_fakerate, h_Top_bJetEta_bybin_CR);
            for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], c_fakerate, h_Top_cJetEta_bybin_CR);
            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], l_fakerate, h_Top_lJetEta_bybin_CR);
            for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], h_fakerate, h_Top_hJetEta_bybin_CR);

            if ((*v_Top_alpha)[i] < 0.1)
            {
                h_Top_trk_SR->Fill((*v_Top_nTrack)[i], Top_weight);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_btrk_SR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ctrk_SR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ltrk_SR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_htrk_SR);

                h_Top_JetPt_SR->Fill((*v_Top_JetPT)[i], Top_weight);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_bJetPt_SR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_cJetPt_SR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_lJetPt_SR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_hJetPt_SR);

                h_Top_JetEta_SR->Fill((*v_Top_JetEta)[i], Top_weight);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_SR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_cJetEta_SR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_SR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_hJetEta_SR);
            }
            //---------------------------------------------------------
            // Different eta
            //---------------------------------------------------------
            //  For Region |eta| < 1
            if (abs((*v_Top_JetEta)[i]) < 1)
            {
                double jetfake_region1 = Top_nTrk_fakeRate_difeta_1->GetBinContent(bxBin_local) * Top_weight;
                double bjetfake_region1 = Top_nTrk_bfakeRate_difeta_1->GetBinContent(bxBin_local) * Top_weight;
                double cjetfake_region1 = Top_nTrk_cfakeRate_difeta_1->GetBinContent(bxBin_local) * Top_weight;
                double ljetfake_region1 = Top_nTrk_lfakeRate_difeta_1->GetBinContent(bxBin_local) * Top_weight;
                double hjetfake_region1 = Top_nTrk_hfakeRate_difeta_1->GetBinContent(bxBin_local) * Top_weight;

                h_Top_trk_region1_bybin_CR->Fill((*v_Top_nTrack)[i], jetfake_region1);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], bjetfake_region1, h_Top_btrk_region1_bybin_CR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], cjetfake_region1, h_Top_ctrk_region1_bybin_CR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], ljetfake_region1, h_Top_ltrk_region1_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], hjetfake_region1, h_Top_htrk_region1_bybin_CR);

                h_Top_JetPt_region1_bybin_CR->Fill((*v_Top_JetPT)[i], jetfake_region1);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], bjetfake_region1, h_Top_bJetPt_region1_bybin_CR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], cjetfake_region1, h_Top_cJetPt_region1_bybin_CR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], ljetfake_region1, h_Top_lJetPt_region1_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], hjetfake_region1, h_Top_hJetPt_region1_bybin_CR);

                h_Top_JetEta_diffregion_bybin_CR->Fill((*v_Top_JetEta)[i], jetfake_region1);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], bjetfake_region1, h_Top_bJetEta_diffregion_bybin_CR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], cjetfake_region1, h_Top_cJetEta_diffregion_bybin_CR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], ljetfake_region1, h_Top_lJetEta_diffregion_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], hjetfake_region1, h_Top_hJetEta_diffregion_bybin_CR);

                if ((*v_Top_alpha)[i] < 0.1)
                {
                    h_Top_trk_region1_SR->Fill((*v_Top_nTrack)[i], Top_weight);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_btrk_region1_SR);
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ctrk_region1_SR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ltrk_region1_SR);
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_htrk_region1_SR);

                    h_Top_JetPt_region1_SR->Fill((*v_Top_JetPT)[i], Top_weight);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_bJetPt_region1_SR);
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_cJetPt_region1_SR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_lJetPt_region1_SR);
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_hJetPt_region1_SR);

                    h_Top_JetEta_diffregion_SR->Fill((*v_Top_JetEta)[i], Top_weight);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_diffregion_SR);
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_cJetEta_diffregion_SR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_diffregion_SR);
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_hJetEta_diffregion_SR);
                }
            }
            else if (abs((*v_Top_JetEta)[i]) > 1 && abs((*v_Top_JetEta)[i]) < 2)
            {
                double jetfake_region2 = Top_nTrk_fakeRate_difeta_2->GetBinContent(bxBin_local) * Top_weight;
                double bjetfake_region2 = Top_nTrk_bfakeRate_difeta_2->GetBinContent(bxBin_local) * Top_weight;
                double cjetfake_region2 = Top_nTrk_cfakeRate_difeta_2->GetBinContent(cxBin_local) * Top_weight;
                double ljetfake_region2 = Top_nTrk_lfakeRate_difeta_2->GetBinContent(lxBin_local) * Top_weight;
                double hjetfake_region2 = Top_nTrk_hfakeRate_difeta_2->GetBinContent(lxBin_local) * Top_weight;

                h_Top_trk_region2_bybin_CR->Fill((*v_Top_nTrack)[i], jetfake_region2);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], bjetfake_region2, h_Top_btrk_region2_bybin_CR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], cjetfake_region2, h_Top_ctrk_region2_bybin_CR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], ljetfake_region2, h_Top_ltrk_region2_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], hjetfake_region2, h_Top_htrk_region2_bybin_CR);

                h_Top_JetPt_region2_bybin_CR->Fill((*v_Top_JetPT)[i], jetfake_region2);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], bjetfake_region2, h_Top_bJetPt_region2_bybin_CR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], cjetfake_region2, h_Top_cJetPt_region2_bybin_CR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], ljetfake_region2, h_Top_lJetPt_region2_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], hjetfake_region2, h_Top_hJetPt_region2_bybin_CR);

                h_Top_JetEta_diffregion_bybin_CR->Fill((*v_Top_JetEta)[i], jetfake_region2);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], bjetfake_region2, h_Top_bJetEta_diffregion_bybin_CR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], cjetfake_region2, h_Top_cJetEta_diffregion_bybin_CR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], ljetfake_region2, h_Top_lJetEta_diffregion_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], hjetfake_region2, h_Top_hJetEta_diffregion_bybin_CR);

                if ((*v_Top_alpha)[i] < 0.1)
                {
                    h_Top_trk_region2_SR->Fill((*v_Top_nTrack)[i], Top_weight);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_btrk_region2_SR);
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ctrk_region2_SR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ltrk_region2_SR);
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_htrk_region2_SR);

                    h_Top_JetPt_region2_SR->Fill((*v_Top_JetPT)[i], Top_weight);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_bJetPt_region2_SR);
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_cJetPt_region2_SR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_lJetPt_region2_SR);
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_hJetPt_region2_SR);

                    h_Top_JetEta_diffregion_SR->Fill((*v_Top_JetEta)[i], Top_weight);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_diffregion_SR);
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_cJetEta_diffregion_SR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_diffregion_SR);
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_hJetEta_diffregion_SR);
                }
            }
            else if (abs((*v_Top_JetEta)[i]) > 2 && abs((*v_Top_JetEta)[i]) < 2.5)
            {
                double jetfake_region3 = Top_nTrk_fakeRate_difeta_3->GetBinContent(bxBin_local) * Top_weight;
                double bjetfake_region3 = Top_nTrk_bfakeRate_difeta_3->GetBinContent(bxBin_local) * Top_weight;
                double cjetfake_region3 = Top_nTrk_cfakeRate_difeta_3->GetBinContent(cxBin_local) * Top_weight;
                double ljetfake_region3 = Top_nTrk_lfakeRate_difeta_3->GetBinContent(lxBin_local) * Top_weight;
                double hjetfake_region3 = Top_nTrk_hfakeRate_difeta_3->GetBinContent(lxBin_local) * Top_weight;

                h_Top_trk_region3_bybin_CR->Fill((*v_Top_nTrack)[i], jetfake_region3);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], bjetfake_region3, h_Top_btrk_region3_bybin_CR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], cjetfake_region3, h_Top_ctrk_region3_bybin_CR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], ljetfake_region3, h_Top_ltrk_region3_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], hjetfake_region3, h_Top_htrk_region3_bybin_CR);

                h_Top_JetPt_region3_bybin_CR->Fill((*v_Top_JetPT)[i], jetfake_region3);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], bjetfake_region3, h_Top_bJetPt_region3_bybin_CR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], cjetfake_region3, h_Top_cJetPt_region3_bybin_CR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], ljetfake_region3, h_Top_lJetPt_region3_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], hjetfake_region3, h_Top_hJetPt_region3_bybin_CR);

                h_Top_JetEta_diffregion_bybin_CR->Fill((*v_Top_JetEta)[i], jetfake_region3);
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], bjetfake_region3, h_Top_bJetEta_diffregion_bybin_CR);
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], cjetfake_region3, h_Top_cJetEta_diffregion_bybin_CR);
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], ljetfake_region3, h_Top_lJetEta_diffregion_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], hjetfake_region3, h_Top_hJetEta_diffregion_bybin_CR);

                if ((*v_Top_alpha)[i] < 0.1)
                {
                    h_Top_trk_region3_SR->Fill((*v_Top_nTrack)[i], Top_weight);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_btrk_region3_SR);
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ctrk_region3_SR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ltrk_region3_SR);
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_htrk_region3_SR);

                    h_Top_JetPt_region3_SR->Fill((*v_Top_JetPT)[i], Top_weight);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_bJetPt_region3_SR);
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_cJetPt_region3_SR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_lJetPt_region3_SR);
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_hJetPt_region3_SR);

                    h_Top_JetEta_diffregion_SR->Fill((*v_Top_JetEta)[i], Top_weight);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_diffregion_SR);
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_cJetEta_diffregion_SR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_diffregion_SR);
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_hJetEta_diffregion_SR);
                }
            }
        }// End of for v_thinJet loop
        */
        //------------------------------------------------------
        // New version of fake rate apply(non eq bin fake rate)
        //------------------------------------------------------
        if (f_Top_met > 140)
        {
            for (int i = 0; i < v_Top_nTrack->size(); i++)
            {
                if (f_Top_dileppt > 60)
                {
                    //--------------------
                    // 1. Plot True BG
                    //--------------------
                    if ((*v_Top_alpha)[i] < 0.15)
                    {
                        h_Top_trk_SR->Fill((*v_Top_nTrack)[i], Top_weight);
                        h_Top_JetPt_SR->Fill((*v_Top_JetPT)[i], Top_weight);
                        h_Top_JetEta_SR->Fill((*v_Top_JetEta)[i], Top_weight);
                        // For ntrk
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_btrk_SR);
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ltrk_SR);
                        // For Jet PT
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_bJetPt_SR);
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_lJetPt_SR);
                        // Fot Jet Eta
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_SR);
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_SR);
                        // Consider diff eta
                        if (abs((*v_Top_JetEta)[i]) < 1)
                        {
                            // For ntrk
                            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_btrk_region1_SR);
                            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ltrk_region1_SR);
                            // For Jet PT
                            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_bJetPt_region1_SR);
                            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_lJetPt_region1_SR);
                            // Fot Jet Eta
                            // for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_SR);
                            // for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_SR);
                        }
                        else if (abs((*v_Top_JetEta)[i]) > 1 && abs((*v_Top_JetEta)[i]) < 2)
                        {
                            // For ntrk
                            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_btrk_region2_SR);
                            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ltrk_region2_SR);
                            // For Jet PT
                            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_bJetPt_region2_SR);
                            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_lJetPt_region2_SR);
                            // Fot Jet Eta
                            // for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_SR);
                            // for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_SR);
                        }
                        else if (abs((*v_Top_JetEta)[i]) > 2 && abs((*v_Top_JetEta)[i]) < 2.5)
                        {
                            // For ntrk
                            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_btrk_region3_SR);
                            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_ltrk_region3_SR);
                            // For Jet PT
                            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_bJetPt_region3_SR);
                            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], Top_weight, h_Top_lJetPt_region3_SR);
                            // Fot Jet Eta
                            // for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_SR);
                            // for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_SR);
                        }
                    }
                    //------------------------------------
                    // 2. Apply low dilepton PT fake rate
                    //------------------------------------
                    int fk_bin_pos = getbinfakerate((*v_Top_nTrack)[i]);
                    cout << "fk_bin_pos = " << fk_bin_pos << endl;
                    double no_flavor_fk = Top_nTrk_fakeRate_lowDilepPt->GetBinContent(fk_bin_pos) * Top_weight;
                    double b_flavor_fk = Top_nTrk_bfakeRate_lowDilepPt->GetBinContent(fk_bin_pos) * Top_weight;
                    double l_flavor_fk = Top_nTrk_lfakeRate_lowDilepPt->GetBinContent(fk_bin_pos) * Top_weight;

                    // For ntrk
                    h_Top_trk_bybin_CR->Fill((*v_Top_nTrack)[i], no_flavor_fk);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], b_flavor_fk, h_Top_btrk_bybin_CR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], l_flavor_fk, h_Top_ltrk_bybin_CR);
                    // For Jet PT
                    h_Top_JetPt_bybin_CR->Fill((*v_Top_JetPT)[i], no_flavor_fk);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], b_flavor_fk, h_Top_bJetPt_bybin_CR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], l_flavor_fk, h_Top_lJetPt_bybin_CR);
                    // Fot Jet Eta
                    h_Top_JetEta_bybin_CR->Fill((*v_Top_JetEta)[i], no_flavor_fk);
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], b_flavor_fk, h_Top_bJetEta_bybin_CR);
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], l_flavor_fk, h_Top_lJetEta_bybin_CR);
                    // Consider diff eta
                    if (abs((*v_Top_JetEta)[i]) < 1)
                    {
                        int fk_bin_pos = getbinfakerate((*v_Top_nTrack)[i]);
                        cout << "fk_bin_pos = " << fk_bin_pos << endl;
                        //double no_flavor_fk = Top_nTrk_fakeRate_lowDilepPt_1->GetBinContent(fk_bin_pos) * Top_weight;
                        double b_flavor_fk = Top_nTrk_bfakeRate_lowDilepPt_1->GetBinContent(fk_bin_pos) * Top_weight;
                        double l_flavor_fk = Top_nTrk_lfakeRate_lowDilepPt_1->GetBinContent(fk_bin_pos) * Top_weight;
                        // For ntrk
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], b_flavor_fk, h_Top_btrk_region1_bybin_CR);
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], l_flavor_fk, h_Top_ltrk_region1_bybin_CR);
                        // For Jet PT
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], b_flavor_fk, h_Top_bJetPt_region1_bybin_CR);
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], l_flavor_fk, h_Top_lJetPt_region1_bybin_CR);
                        // Fot Jet Eta
                        // for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_SR);
                        // for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_SR);
                    }
                    else if (abs((*v_Top_JetEta)[i]) > 1 && abs((*v_Top_JetEta)[i]) < 2)
                    {
                        int fk_bin_pos = getbinfakerate((*v_Top_nTrack)[i]);
                        cout << "fk_bin_pos = " << fk_bin_pos << endl;
                        //double no_flavor_fk = Top_nTrk_fakeRate_lowDilepPt_2->GetBinContent(fk_bin_pos) * Top_weight;
                        double b_flavor_fk = Top_nTrk_bfakeRate_lowDilepPt_2->GetBinContent(fk_bin_pos) * Top_weight;
                        double l_flavor_fk = Top_nTrk_lfakeRate_lowDilepPt_2->GetBinContent(fk_bin_pos) * Top_weight;
                        // For ntrk
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], b_flavor_fk, h_Top_btrk_region2_bybin_CR);
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], l_flavor_fk, h_Top_ltrk_region2_bybin_CR);
                        // For Jet PT
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], b_flavor_fk, h_Top_bJetPt_region2_bybin_CR);
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], l_flavor_fk, h_Top_lJetPt_region2_bybin_CR);
                        // Fot Jet Eta
                        // for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_SR);
                        // for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_SR);
                    }
                    else if (abs((*v_Top_JetEta)[i]) > 2 && abs((*v_Top_JetEta)[i]) < 2.5)
                    {
                        int fk_bin_pos = getbinfakerate((*v_Top_nTrack)[i]);
                        cout << "fk_bin_pos = " << fk_bin_pos << endl;
                        //double no_flavor_fk = Top_nTrk_fakeRate_lowDilepPt->GetBinContent(fk_bin_pos) * Top_weight;
                        double b_flavor_fk = Top_nTrk_bfakeRate_lowDilepPt_3->GetBinContent(fk_bin_pos) * Top_weight;
                        double l_flavor_fk = Top_nTrk_lfakeRate_lowDilepPt_3->GetBinContent(fk_bin_pos) * Top_weight;
                        // For ntrk
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], b_flavor_fk, h_Top_btrk_region3_bybin_CR);
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], l_flavor_fk, h_Top_ltrk_region3_bybin_CR);
                        // For Jet PT
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], b_flavor_fk, h_Top_bJetPt_region3_bybin_CR);
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], l_flavor_fk, h_Top_lJetPt_region3_bybin_CR);
                        // Fot Jet Eta
                        // for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_bJetEta_SR);
                        // for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_JetEta)[i], Top_weight, h_Top_lJetEta_SR);
                    }
                } // End of High dilepton PT required
            }
        } // End of MET cut

    } // End of Top loop

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    h_Top_trk_bybin_CR->Write();
    h_Top_btrk_bybin_CR->Write();
    h_Top_ctrk_bybin_CR->Write();
    h_Top_ltrk_bybin_CR->Write();
    h_Top_htrk_bybin_CR->Write();
    h_Top_trk_SR->Write();
    h_Top_btrk_SR->Write();
    h_Top_ctrk_SR->Write();
    h_Top_ltrk_SR->Write();
    h_Top_htrk_SR->Write();
    h_Top_JetPt_bybin_CR->Write();
    h_Top_bJetPt_bybin_CR->Write();
    h_Top_lJetPt_bybin_CR->Write();
    h_Top_bJetPt_SR->Write();
    h_Top_lJetPt_SR->Write();
    h_Top_JetEta_bybin_CR->Write();
    h_Top_bJetEta_bybin_CR->Write();
    h_Top_lJetEta_bybin_CR->Write();
    h_Top_bJetEta_SR->Write();
    h_Top_lJetEta_SR->Write();
    h_Top_trk_region1_bybin_CR->Write();
    h_Top_trk_region2_bybin_CR->Write();
    h_Top_trk_region3_bybin_CR->Write();
    h_Top_btrk_region1_bybin_CR->Write();
    h_Top_btrk_region2_bybin_CR->Write();
    h_Top_btrk_region3_bybin_CR->Write();
    h_Top_ctrk_region1_bybin_CR->Write();
    h_Top_ctrk_region2_bybin_CR->Write();
    h_Top_ctrk_region3_bybin_CR->Write();
    h_Top_ltrk_region1_bybin_CR->Write();
    h_Top_ltrk_region2_bybin_CR->Write();
    h_Top_ltrk_region3_bybin_CR->Write();
    h_Top_htrk_region1_bybin_CR->Write();
    h_Top_htrk_region2_bybin_CR->Write();
    h_Top_htrk_region3_bybin_CR->Write();
    h_Top_trk_region1_SR->Write();
    h_Top_trk_region2_SR->Write();
    h_Top_trk_region3_SR->Write();
    h_Top_btrk_region1_SR->Write();
    h_Top_btrk_region2_SR->Write();
    h_Top_btrk_region3_SR->Write();
    h_Top_ctrk_region1_SR->Write();
    h_Top_ctrk_region2_SR->Write();
    h_Top_ctrk_region3_SR->Write();
    h_Top_ltrk_region1_SR->Write();
    h_Top_ltrk_region2_SR->Write();
    h_Top_ltrk_region3_SR->Write();
    h_Top_htrk_region1_SR->Write();
    h_Top_htrk_region2_SR->Write();
    h_Top_htrk_region3_SR->Write();

    h_Top_bJetPt_bybin_CR->Write();
    h_Top_cJetPt_bybin_CR->Write();
    h_Top_lJetPt_bybin_CR->Write();
    h_Top_hJetPt_bybin_CR->Write();
    h_Top_JetPt_SR->Write();
    h_Top_bJetPt_SR->Write();
    h_Top_cJetPt_SR->Write();
    h_Top_lJetPt_SR->Write();
    h_Top_hJetPt_SR->Write();
    h_Top_JetPt_region1_bybin_CR->Write();
    h_Top_JetPt_region2_bybin_CR->Write();
    h_Top_JetPt_region3_bybin_CR->Write();
    h_Top_bJetPt_region1_bybin_CR->Write();
    h_Top_bJetPt_region2_bybin_CR->Write();
    h_Top_bJetPt_region3_bybin_CR->Write();
    h_Top_cJetPt_region1_bybin_CR->Write();
    h_Top_cJetPt_region2_bybin_CR->Write();
    h_Top_cJetPt_region3_bybin_CR->Write();
    h_Top_lJetPt_region1_bybin_CR->Write();
    h_Top_lJetPt_region2_bybin_CR->Write();
    h_Top_lJetPt_region3_bybin_CR->Write();
    h_Top_hJetPt_region1_bybin_CR->Write();
    h_Top_hJetPt_region2_bybin_CR->Write();
    h_Top_hJetPt_region3_bybin_CR->Write();
    h_Top_JetPt_region1_SR->Write();
    h_Top_JetPt_region2_SR->Write();
    h_Top_JetPt_region3_SR->Write();
    h_Top_bJetPt_region1_SR->Write();
    h_Top_bJetPt_region2_SR->Write();
    h_Top_bJetPt_region3_SR->Write();
    h_Top_cJetPt_region1_SR->Write();
    h_Top_cJetPt_region2_SR->Write();
    h_Top_cJetPt_region3_SR->Write();
    h_Top_lJetPt_region1_SR->Write();
    h_Top_lJetPt_region2_SR->Write();
    h_Top_lJetPt_region3_SR->Write();
    h_Top_hJetPt_region1_SR->Write();
    h_Top_hJetPt_region2_SR->Write();
    h_Top_hJetPt_region3_SR->Write();
    h_Top_JetEta_bybin_CR->Write();
    h_Top_bJetEta_bybin_CR->Write();
    h_Top_cJetEta_bybin_CR->Write();
    h_Top_lJetEta_bybin_CR->Write();
    h_Top_hJetEta_bybin_CR->Write();
    h_Top_JetEta_SR->Write();
    h_Top_bJetEta_SR->Write();
    h_Top_cJetEta_SR->Write();
    h_Top_lJetEta_SR->Write();
    h_Top_hJetEta_SR->Write();
    h_Top_JetEta_diffregion_bybin_CR->Write();
    h_Top_bJetEta_diffregion_bybin_CR->Write();
    h_Top_cJetEta_diffregion_bybin_CR->Write();
    h_Top_lJetEta_diffregion_bybin_CR->Write();
    h_Top_hJetEta_diffregion_bybin_CR->Write();
    h_Top_JetEta_diffregion_SR->Write();
    h_Top_bJetEta_diffregion_SR->Write();
    h_Top_cJetEta_diffregion_SR->Write();
    h_Top_lJetEta_diffregion_SR->Write();
    h_Top_hJetEta_diffregion_SR->Write();
    outfile->Close();
    // h_Top_JetPt_bjet_SR->Draw();

    // cout << getWeight(file) << endl;
    // cout << "TTTo2L2NuWeight = " << TTTo2L2NuWeight << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        Ratio_Top_apply();
    }
    else if (argc == 3)
    {
        Ratio_Top_apply(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}