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

//-------------------
// Create New class
//-------------------
class ThinJet
{
private:
    float jetflavor, jetpt, jeteta, jetalpha, jetntrk, jetmass, jetcsv;

public:
    ThinJet() {}
    ThinJet(const float &a, const float &b, const float &c, const float &d, const float &e, const float &f, const float &g) : jetflavor(a), jetpt(b), jeteta(c), jetalpha(d), jetntrk(e), jetmass(f), jetcsv(g) {}
    Float_t GetFlavor() const { return jetflavor; }
    Float_t GetPt() const { return jetpt; }
    Float_t GetEta() const { return jeteta; }
    Float_t GetAlpha() const { return jetalpha; }
    Float_t GetNtrk() const { return jetntrk; }
    Float_t GetMass() const { return jetmass; }
    Float_t GetCsv() const { return jetcsv; }

    friend ostream &operator<<(ostream &out, const ThinJet &foo)
    {
        return out << foo.jetflavor << " " << foo.jetpt << " " << foo.jeteta << " " << foo.jetalpha << " " << foo.jetntrk << "" << foo.jetmass << "" << foo.jetcsv << endl;
    }

    // greater() is used for JetPT
    friend bool operator>(const ThinJet &a, const ThinJet &b)
    {
        return a.GetPt() > b.GetPt();
    }
};
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
// 1. For dilepton PT fake rate
TH1D *Top_nTrk_fakeRate_lowDilepPt = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_fakeRate_highDilepPt"));
TH1D *Top_nTrk_bfakeRate_lowDilepPt = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_highDilepPt"));
TH1D *Top_nTrk_lfakeRate_lowDilepPt = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_highDilepPt"));
// Consider eta
TH1D *Top_nTrk_bfakeRate_lowDilepPt_1 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowDilepPt_1"));
TH1D *Top_nTrk_bfakeRate_lowDilepPt_2 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowDilepPt_2"));
TH1D *Top_nTrk_bfakeRate_lowDilepPt_3 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowDilepPt_3"));

TH1D *Top_nTrk_lfakeRate_lowDilepPt_1 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowDilepPt_1"));
TH1D *Top_nTrk_lfakeRate_lowDilepPt_2 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowDilepPt_2"));
TH1D *Top_nTrk_lfakeRate_lowDilepPt_3 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowDilepPt_3"));

// 2. For Met fake rate
TH1D *Top_nTrk_bfakeRate_lowMET_1 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_1"));
TH1D *Top_nTrk_bfakeRate_lowMET_2 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_2"));
TH1D *Top_nTrk_bfakeRate_lowMET_3 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_3"));

TH1D *Top_nTrk_lfakeRate_lowMET_1 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_1"));
TH1D *Top_nTrk_lfakeRate_lowMET_2 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_2"));
TH1D *Top_nTrk_lfakeRate_lowMET_3 = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_3"));

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
    if (tmp_ntrk >= 15 && tmp_ntrk < 25)
    {
        bin_pos_info = 15;
    }
    else if (tmp_ntrk >= 25 && tmp_ntrk < 40)
    {
        bin_pos_info = 16;
    }
    else
    {
        bin_pos_info = tmp_ntrk;
    }
    return bin_pos_info;
}
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

void Ratio_Top_apply_LO(TString file = "/home/kuanyu/Documents/root_file/BgEstimation/top_TTTo2L2Nu_2.root", TString outputfile = "output.root")
{
    TFile *Topfile = TFile::Open(file);
    cout << "Top weight = " << getWeight(file) << endl;

    //----------------------------------
    // Define histogram bin information
    //----------------------------------
    const Int_t Ntrk_Nbins = 16;
    Double_t Ntrk_edges[Ntrk_Nbins + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13, 14, 15., 25., 40.};

    const Int_t NJet_Nbins = 10;
    Double_t NJet_edges[Ntrk_Nbins + 1] = {0., 30., 60., 90., 120., 150., 210., 270., 350., 450., 1500.};

    const Int_t JetPt_Nbins = 20.;
    Double_t JetPt_low_bound = 0.;
    Double_t JetPt_upper_bound = 1000.;

    const Int_t JetEta_Nbins = 30.;
    Double_t JetEta_low_bound = -3.;
    Double_t JetEta_upper_bound = 3.;

    //-------------------
    // For Signal Region
    //-------------------
    // ntrk
    // Not consider eta
    TH1D *h_Top_trk_SR = new TH1D("h_Top_trk_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_SR->Sumw2();

    TH1D *h_Top_btrk_SR = new TH1D("h_Top_btrk_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_SR->Sumw2();

    TH1D *h_Top_ltrk_SR = new TH1D("h_Top_ltrk_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_SR->Sumw2();

    // consider eta fake rate
    TH1D *h_Top_trk_region1_SR = new TH1D("h_Top_trk_region1_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_region1_SR->Sumw2();
    TH1D *h_Top_trk_region2_SR = new TH1D("h_Top_trk_region2_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_region2_SR->Sumw2();
    TH1D *h_Top_trk_region3_SR = new TH1D("h_Top_trk_region3_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_region3_SR->Sumw2();

    TH1D *h_Top_btrk_region1_LO_SR = new TH1D("h_Top_btrk_region1_LO_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_region1_LO_SR->Sumw2();
    TH1D *h_Top_btrk_region2_LO_SR = new TH1D("h_Top_btrk_region2_LO_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_region2_LO_SR->Sumw2();
    TH1D *h_Top_btrk_region3_LO_SR = new TH1D("h_Top_btrk_region3_LO_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_region3_LO_SR->Sumw2();

    TH1D *h_Top_ltrk_region1_LO_SR = new TH1D("h_Top_ltrk_region1_LO_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_region1_LO_SR->Sumw2();
    TH1D *h_Top_ltrk_region2_LO_SR = new TH1D("h_Top_ltrk_region2_LO_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_region2_LO_SR->Sumw2();
    TH1D *h_Top_ltrk_region3_LO_SR = new TH1D("h_Top_ltrk_region3_LO_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_region3_LO_SR->Sumw2();

    // JetPt
    // Not consider eta
    TH1D *h_Top_JetPt_SR = new TH1D("h_Top_JetPt_SR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_SR->Sumw2();
    TH1D *h_Top_bJetPt_SR = new TH1D("h_Top_bJetPt_SR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_SR->Sumw2();
    TH1D *h_Top_lJetPt_SR = new TH1D("h_Top_lJetPt_SR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_SR->Sumw2();
    // consider eta fake rate
    TH1D *h_Top_JetPt_region1_SR = new TH1D("h_Top_JetPt_region1_SR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_region1_SR->Sumw2();
    TH1D *h_Top_JetPt_region2_SR = new TH1D("h_Top_JetPt_region2_SR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_region2_SR->Sumw2();
    TH1D *h_Top_JetPt_region3_SR = new TH1D("h_Top_JetPt_region3_SR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_region3_SR->Sumw2();

    TH1D *h_Top_bJetPt_region1_LO_SR = new TH1D("h_Top_bJetPt_region1_LO_SR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_region1_LO_SR->Sumw2();
    TH1D *h_Top_bJetPt_region2_LO_SR = new TH1D("h_Top_bJetPt_region2_LO_SR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_region2_LO_SR->Sumw2();
    TH1D *h_Top_bJetPt_region3_LO_SR = new TH1D("h_Top_bJetPt_region3_LO_SR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_region3_LO_SR->Sumw2();

    TH1D *h_Top_lJetPt_region1_LO_SR = new TH1D("h_Top_lJetPt_region1_LO_SR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_region1_LO_SR->Sumw2();
    TH1D *h_Top_lJetPt_region2_LO_SR = new TH1D("h_Top_lJetPt_region2_LO_SR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_region2_LO_SR->Sumw2();
    TH1D *h_Top_lJetPt_region3_LO_SR = new TH1D("h_Top_lJetPt_region3_LO_SR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_region3_LO_SR->Sumw2();

    // JetEta
    TH1D *h_Top_JetEta_SR = new TH1D("h_Top_JetEta_SR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_JetEta_SR->Sumw2();
    TH1D *h_Top_bJetEta_LO_SR = new TH1D("h_Top_bJetEta_LO_SR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_bJetEta_LO_SR->Sumw2();
    TH1D *h_Top_lJetEta_LO_SR = new TH1D("h_Top_lJetEta_LO_SR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_lJetEta_LO_SR->Sumw2();

    //--------------------------
    // For old fake rate (MET)
    //--------------------------
    //-------------------
    // For Signal Region
    //-------------------
    // 1. Jet trk
    // consider eta fake rate
    TH1D *h_Top_btrk_MET_region1_SR = new TH1D("h_Top_btrk_MET_region1_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_MET_region1_SR->Sumw2();
    TH1D *h_Top_btrk_MET_region2_SR = new TH1D("h_Top_btrk_MET_region2_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_MET_region2_SR->Sumw2();
    TH1D *h_Top_btrk_MET_region3_SR = new TH1D("h_Top_btrk_MET_region3_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_MET_region3_SR->Sumw2();

    TH1D *h_Top_ltrk_MET_region1_SR = new TH1D("h_Top_ltrk_MET_region1_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_MET_region1_SR->Sumw2();
    TH1D *h_Top_ltrk_MET_region2_SR = new TH1D("h_Top_ltrk_MET_region2_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_MET_region2_SR->Sumw2();
    TH1D *h_Top_ltrk_MET_region3_SR = new TH1D("h_Top_ltrk_MET_region3_SR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_MET_region3_SR->Sumw2();

    // 2. JetPt
    TH1D *h_Top_bJetPt_MET_region1_SR = new TH1D("h_Top_bJetPt_MET_region1_SR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_MET_region1_SR->Sumw2();
    TH1D *h_Top_bJetPt_MET_region2_SR = new TH1D("h_Top_bJetPt_MET_region2_SR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_MET_region2_SR->Sumw2();
    TH1D *h_Top_bJetPt_MET_region3_SR = new TH1D("h_Top_bJetPt_MET_region3_SR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_MET_region3_SR->Sumw2();

    TH1D *h_Top_lJetPt_MET_region1_SR = new TH1D("h_Top_lJetPt_MET_region1_SR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_MET_region1_SR->Sumw2();
    TH1D *h_Top_lJetPt_MET_region2_SR = new TH1D("h_Top_lJetPt_MET_region2_SR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_MET_region2_SR->Sumw2();
    TH1D *h_Top_lJetPt_MET_region3_SR = new TH1D("h_Top_lJetPt_MET_region3_SR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_MET_region3_SR->Sumw2();

    // 3. JetEta
    TH1D *h_Top_bJetEta_MET_SR = new TH1D("h_Top_bJetEta_MET_SR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_bJetEta_MET_SR->Sumw2();
    TH1D *h_Top_lJetEta_MET_SR = new TH1D("h_Top_lJetEta_MET_SR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_lJetEta_MET_SR->Sumw2();

    //---------------------------------
    // For Control Region (predicted)
    //---------------------------------
    // ntrk
    // Not consider eta
    TH1D *h_Top_trk_bybin_CR = new TH1D("h_Top_trk_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_bybin_CR->Sumw2();

    TH1D *h_Top_btrk_bybin_CR = new TH1D("h_Top_btrk_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_bybin_CR->Sumw2();

    TH1D *h_Top_ltrk_bybin_CR = new TH1D("h_Top_ltrk_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_bybin_CR->Sumw2();

    // consider eta fake rate
    TH1D *h_Top_trk_region1_bybin_CR = new TH1D("h_Top_trk_region1_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_region1_bybin_CR->Sumw2();
    TH1D *h_Top_trk_region2_bybin_CR = new TH1D("h_Top_trk_region2_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_region2_bybin_CR->Sumw2();
    TH1D *h_Top_trk_region3_bybin_CR = new TH1D("h_Top_trk_region3_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_region3_bybin_CR->Sumw2();

    TH1D *h_Top_btrk_region1_LO_bybin_CR = new TH1D("h_Top_btrk_region1_LO_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_region1_LO_bybin_CR->Sumw2();
    TH1D *h_Top_btrk_region2_LO_bybin_CR = new TH1D("h_Top_btrk_region2_LO_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_region2_LO_bybin_CR->Sumw2();
    TH1D *h_Top_btrk_region3_LO_bybin_CR = new TH1D("h_Top_btrk_region3_LO_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_region3_LO_bybin_CR->Sumw2();

    TH1D *h_Top_ltrk_region1_LO_bybin_CR = new TH1D("h_Top_ltrk_region1_LO_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_region1_LO_bybin_CR->Sumw2();
    TH1D *h_Top_ltrk_region2_LO_bybin_CR = new TH1D("h_Top_ltrk_region2_LO_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_region2_LO_bybin_CR->Sumw2();
    TH1D *h_Top_ltrk_region3_LO_bybin_CR = new TH1D("h_Top_ltrk_region3_LO_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_region3_LO_bybin_CR->Sumw2();

    // JetPT
    // Not consider eta
    TH1D *h_Top_JetPt_bybin_CR = new TH1D("h_Top_JetPt_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_bybin_CR->Sumw2();

    TH1D *h_Top_bJetPt_bybin_CR = new TH1D("h_Top_bJetPt_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_bybin_CR->Sumw2();

    TH1D *h_Top_lJetPt_bybin_CR = new TH1D("h_Top_lJetPt_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_bybin_CR->Sumw2();

    // consider eta fake rate
    TH1D *h_Top_JetPt_region1_bybin_CR = new TH1D("h_Top_JetPt_region1_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_region1_bybin_CR->Sumw2();
    TH1D *h_Top_JetPt_region2_bybin_CR = new TH1D("h_Top_JetPt_region2_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_region2_bybin_CR->Sumw2();
    TH1D *h_Top_JetPt_region3_bybin_CR = new TH1D("h_Top_JetPt_region3_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_region3_bybin_CR->Sumw2();

    TH1D *h_Top_bJetPt_region1_LO_bybin_CR = new TH1D("h_Top_bJetPt_region1_LO_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_region1_LO_bybin_CR->Sumw2();
    TH1D *h_Top_bJetPt_region2_LO_bybin_CR = new TH1D("h_Top_bJetPt_region2_LO_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_region2_LO_bybin_CR->Sumw2();
    TH1D *h_Top_bJetPt_region3_LO_bybin_CR = new TH1D("h_Top_bJetPt_region3_LO_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_region3_LO_bybin_CR->Sumw2();

    TH1D *h_Top_lJetPt_region1_LO_bybin_CR = new TH1D("h_Top_lJetPt_region1_LO_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_region1_LO_bybin_CR->Sumw2();
    TH1D *h_Top_lJetPt_region2_LO_bybin_CR = new TH1D("h_Top_lJetPt_region2_LO_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_region2_LO_bybin_CR->Sumw2();
    TH1D *h_Top_lJetPt_region3_LO_bybin_CR = new TH1D("h_Top_lJetPt_region3_LO_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_region3_LO_bybin_CR->Sumw2();

    // JetEta
    // consider eta fake rate
    TH1D *h_Top_JetEta_bybin_CR = new TH1D("h_Top_JetEta_bybin_CR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_JetEta_bybin_CR->Sumw2();

    TH1D *h_Top_bJetEta_bybin_CR = new TH1D("h_Top_bJetEta_bybin_CR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_bJetEta_bybin_CR->Sumw2();

    TH1D *h_Top_lJetEta_bybin_CR = new TH1D("h_Top_lJetEta_bybin_CR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_lJetEta_bybin_CR->Sumw2();

    TH1D *h_Top_bJetEta_diffFR_LO_CR = new TH1D("h_Top_bJetEta_diffFR_LO_CR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_bJetEta_diffFR_LO_CR->Sumw2();

    TH1D *h_Top_lJetEta_diffFR_LO_CR = new TH1D("h_Top_lJetEta_diffFR_LO_CR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_lJetEta_diffFR_LO_CR->Sumw2();

    //--------------------------
    // For old fake rate (MET)
    //--------------------------
    // 1. Jet trk
    // consider eta fake rate
    TH1D *h_Top_btrk_MET_region1_bybin_CR = new TH1D("h_Top_btrk_MET_region1_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_MET_region1_bybin_CR->Sumw2();
    TH1D *h_Top_btrk_MET_region2_bybin_CR = new TH1D("h_Top_btrk_MET_region2_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_MET_region2_bybin_CR->Sumw2();
    TH1D *h_Top_btrk_MET_region3_bybin_CR = new TH1D("h_Top_btrk_MET_region3_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_MET_region3_bybin_CR->Sumw2();

    TH1D *h_Top_ltrk_MET_region1_bybin_CR = new TH1D("h_Top_ltrk_MET_region1_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_MET_region1_bybin_CR->Sumw2();
    TH1D *h_Top_ltrk_MET_region2_bybin_CR = new TH1D("h_Top_ltrk_MET_region2_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_MET_region2_bybin_CR->Sumw2();
    TH1D *h_Top_ltrk_MET_region3_bybin_CR = new TH1D("h_Top_ltrk_MET_region3_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_MET_region3_bybin_CR->Sumw2();

    // 2. JetPt
    TH1D *h_Top_bJetPt_MET_region1_bybin_CR = new TH1D("h_Top_bJetPt_MET_region1_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_MET_region1_bybin_CR->Sumw2();
    TH1D *h_Top_bJetPt_MET_region2_bybin_CR = new TH1D("h_Top_bJetPt_MET_region2_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_MET_region2_bybin_CR->Sumw2();
    TH1D *h_Top_bJetPt_MET_region3_bybin_CR = new TH1D("h_Top_bJetPt_MET_region3_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_MET_region3_bybin_CR->Sumw2();

    TH1D *h_Top_lJetPt_MET_region1_bybin_CR = new TH1D("h_Top_lJetPt_MET_region1_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_MET_region1_bybin_CR->Sumw2();
    TH1D *h_Top_lJetPt_MET_region2_bybin_CR = new TH1D("h_Top_lJetPt_MET_region2_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_MET_region2_bybin_CR->Sumw2();
    TH1D *h_Top_lJetPt_MET_region3_bybin_CR = new TH1D("h_Top_lJetPt_MET_region3_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_MET_region3_bybin_CR->Sumw2();

    // 3. JetEta
    TH1D *h_Top_bJetEta_MET_diffFR_CR = new TH1D("h_Top_bJetEta_MET_diffFR_CR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_bJetEta_MET_diffFR_CR->Sumw2();

    TH1D *h_Top_lJetEta_MET_diffFR_CR = new TH1D("h_Top_lJetEta_MET_diffFR_CR", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_lJetEta_MET_diffFR_CR->Sumw2();

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
    vector<float> *v_Top_JetCsv = new vector<float>();
    vector<float> *v_Top_JetMass = new vector<float>();

    v_Top_alpha->clear();
    v_Top_Chi3Dlog->clear();
    v_Top_2DIP->clear();
    v_Top_nTrack->clear();
    v_Top_Jethadronflavor->clear();
    v_Top_Jetpartonflavor->clear();
    v_Top_JetPT->clear();
    v_Top_JetEta->clear();
    v_Top_JetCsv->clear();
    v_Top_JetMass->clear();

    float METcut = 130.;

    float DilepPTcut = 60.;

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
    T_Top_tree->SetBranchAddress("v_fakeJetCSV", &v_Top_JetCsv);
    T_Top_tree->SetBranchAddress("v_fakeJetMass", &v_Top_JetMass);

    for (int evt = 0; evt < T_Top_tree->GetEntries(); evt++)
    {
        T_Top_tree->GetEntry(evt);
        double Top_weight = getWeight(file) * I_Top_weight;

        vector<ThinJet> v_thinjet;
        for (size_t i = 0; i < v_Top_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], (*v_Top_JetEta)[i], (*v_Top_alpha)[i], (*v_Top_nTrack)[i], (*v_Top_JetMass)[i], (*v_Top_JetCsv)[i]));
        }
        //--------------
        // Sort by Jet Pt
        //--------------
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        // check sort result
        //cout << "i = " << evt << endl;
        for (size_t i = 0; i < v_thinjet.size() - 1; i++)
        {
            float a_pt = v_thinjet[i].GetPt();
            float b_pt = v_thinjet[i + 1].GetPt();
            if (b_pt > a_pt)
            {
                cout << "a_pt = " << a_pt << endl;
                cout << "b_pt = " << b_pt << endl;
            }
        } /*
         for (auto x : v_thinjet)
         {
             cout << "JetPT= " << x.GetPt() << endl;
         }*/

        //------------------------------------------------------
        // New version of fake rate apply(non eq bin fake rate)
        //------------------------------------------------------
        if (f_Top_met > METcut)
        {
            if (f_Top_dileppt > DilepPTcut)
            {
                if (v_thinjet[0].GetAlpha() < 0.15)
                {
                    // Fot Jet Eta
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetEta(), Top_weight, h_Top_bJetEta_LO_SR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetEta(), Top_weight, h_Top_lJetEta_LO_SR);

                    // Consider diff eta
                    if (abs(v_thinjet[0].GetEta()) <= 1)
                    {
                        // For ntrk
                        for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), Top_weight, h_Top_btrk_region1_LO_SR);
                        for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), Top_weight, h_Top_ltrk_region1_LO_SR);
                        // For Jet PT
                        for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), Top_weight, h_Top_bJetPt_region1_LO_SR);
                        for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), Top_weight, h_Top_lJetPt_region1_LO_SR);
                    }
                    else if (abs(v_thinjet[0].GetEta()) > 1 && abs(v_thinjet[0].GetEta()) <= 2)
                    {
                        // For ntrk
                        for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), Top_weight, h_Top_btrk_region2_LO_SR);
                        for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), Top_weight, h_Top_ltrk_region2_LO_SR);
                        // For Jet PT
                        for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), Top_weight, h_Top_bJetPt_region2_LO_SR);
                        for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), Top_weight, h_Top_lJetPt_region2_LO_SR);
                    }
                    else if (abs(v_thinjet[0].GetEta()) > 2 && abs(v_thinjet[0].GetEta()) <= 2.5)
                    {
                        // For ntrk
                        for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), Top_weight, h_Top_btrk_region3_LO_SR);
                        for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), Top_weight, h_Top_ltrk_region3_LO_SR);
                        // For Jet PT
                        for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), Top_weight, h_Top_bJetPt_region3_LO_SR);
                        for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), Top_weight, h_Top_lJetPt_region3_LO_SR);
                    }
                } // End of alpha cut
                //------------------------------------
                // 2. Apply low dilepton PT fake rate
                //------------------------------------
                if (abs(v_thinjet[0].GetEta()) <= 1)
                {
                    int fr_bin_pos_1 = getbinfakerate(v_thinjet[0].GetNtrk());
                    double bfr_1 = Top_nTrk_bfakeRate_lowDilepPt_1->GetBinContent(fr_bin_pos_1) * Top_weight;
                    double lfr_1 = Top_nTrk_lfakeRate_lowDilepPt_1->GetBinContent(fr_bin_pos_1) * Top_weight;
                    // For ntrk
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), bfr_1, h_Top_btrk_region1_LO_bybin_CR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), lfr_1, h_Top_ltrk_region1_LO_bybin_CR);
                    // For Jet PT
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), bfr_1, h_Top_bJetPt_region1_LO_bybin_CR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), lfr_1, h_Top_lJetPt_region1_LO_bybin_CR);
                    // Fot Jet Eta
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetEta(), bfr_1, h_Top_bJetEta_diffFR_LO_CR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetEta(), lfr_1, h_Top_lJetEta_diffFR_LO_CR);
                }
                else if (abs(v_thinjet[0].GetEta()) > 1 && abs(v_thinjet[0].GetEta()) <= 2)
                {
                    int fr_bin_pos_2 = getbinfakerate(v_thinjet[0].GetNtrk());
                    double bfr_2 = Top_nTrk_bfakeRate_lowDilepPt_2->GetBinContent(fr_bin_pos_2) * Top_weight;
                    double lfr_2 = Top_nTrk_lfakeRate_lowDilepPt_2->GetBinContent(fr_bin_pos_2) * Top_weight;
                    // For ntrk
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), bfr_2, h_Top_btrk_region2_LO_bybin_CR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), lfr_2, h_Top_ltrk_region2_LO_bybin_CR);
                    // For Jet PT
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), bfr_2, h_Top_bJetPt_region2_LO_bybin_CR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), lfr_2, h_Top_lJetPt_region2_LO_bybin_CR);
                    // Fot Jet Eta
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetEta(), bfr_2, h_Top_bJetEta_diffFR_LO_CR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetEta(), lfr_2, h_Top_lJetEta_diffFR_LO_CR);
                }
                else if (abs(v_thinjet[0].GetEta()) > 2 && abs(v_thinjet[0].GetEta()) <= 2.5)
                {
                    int fr_bin_pos_3 = getbinfakerate(v_thinjet[0].GetNtrk());
                    double bfr_3 = Top_nTrk_bfakeRate_lowDilepPt_3->GetBinContent(fr_bin_pos_3) * Top_weight;
                    double lfr_3 = Top_nTrk_lfakeRate_lowDilepPt_3->GetBinContent(fr_bin_pos_3) * Top_weight;
                    // For ntrk
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), bfr_3, h_Top_btrk_region3_LO_bybin_CR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetNtrk(), lfr_3, h_Top_ltrk_region3_LO_bybin_CR);
                    // For Jet PT
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), bfr_3, h_Top_bJetPt_region3_LO_bybin_CR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetPt(), lfr_3, h_Top_lJetPt_region3_LO_bybin_CR);
                    // Fot Jet Eta
                    for_signalflavor_jet(5, v_thinjet[0].GetFlavor(), v_thinjet[0].GetEta(), bfr_3, h_Top_bJetEta_diffFR_LO_CR);
                    for_signalflavor_jet(0, v_thinjet[0].GetFlavor(), v_thinjet[0].GetEta(), lfr_3, h_Top_lJetEta_diffFR_LO_CR);
                }

            } // End of dilepton PT required
        }     // End of MET cut

    } // End of Top loop

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    h_Top_trk_SR->Write();
    h_Top_btrk_SR->Write();
    h_Top_ltrk_SR->Write();
    h_Top_trk_region1_SR->Write();
    h_Top_trk_region2_SR->Write();
    h_Top_trk_region3_SR->Write();
    h_Top_btrk_region1_LO_SR->Write();
    h_Top_btrk_region2_LO_SR->Write();
    h_Top_btrk_region3_LO_SR->Write();
    h_Top_ltrk_region1_LO_SR->Write();
    h_Top_ltrk_region2_LO_SR->Write();
    h_Top_ltrk_region3_LO_SR->Write();
    h_Top_JetPt_SR->Write();
    h_Top_bJetPt_SR->Write();
    h_Top_lJetPt_SR->Write();
    h_Top_JetPt_region1_SR->Write();
    h_Top_JetPt_region2_SR->Write();
    h_Top_JetPt_region3_SR->Write();
    h_Top_bJetPt_region1_LO_SR->Write();
    h_Top_bJetPt_region2_LO_SR->Write();
    h_Top_bJetPt_region3_LO_SR->Write();
    h_Top_lJetPt_region1_LO_SR->Write();
    h_Top_lJetPt_region2_LO_SR->Write();
    h_Top_lJetPt_region3_LO_SR->Write();
    h_Top_JetEta_SR->Write();
    h_Top_bJetEta_LO_SR->Write();
    h_Top_lJetEta_LO_SR->Write();
    h_Top_trk_bybin_CR->Write();
    h_Top_btrk_bybin_CR->Write();
    h_Top_ltrk_bybin_CR->Write();
    h_Top_trk_region1_bybin_CR->Write();
    h_Top_trk_region2_bybin_CR->Write();
    h_Top_trk_region3_bybin_CR->Write();
    h_Top_btrk_region1_LO_bybin_CR->Write();
    h_Top_btrk_region2_LO_bybin_CR->Write();
    h_Top_btrk_region3_LO_bybin_CR->Write();
    h_Top_ltrk_region1_LO_bybin_CR->Write();
    h_Top_ltrk_region2_LO_bybin_CR->Write();
    h_Top_ltrk_region3_LO_bybin_CR->Write();
    h_Top_JetPt_bybin_CR->Write();
    h_Top_bJetPt_bybin_CR->Write();
    h_Top_lJetPt_bybin_CR->Write();
    h_Top_JetPt_region1_bybin_CR->Write();
    h_Top_JetPt_region2_bybin_CR->Write();
    h_Top_JetPt_region3_bybin_CR->Write();
    h_Top_bJetPt_region1_LO_bybin_CR->Write();
    h_Top_bJetPt_region2_LO_bybin_CR->Write();
    h_Top_bJetPt_region3_LO_bybin_CR->Write();
    h_Top_lJetPt_region1_LO_bybin_CR->Write();
    h_Top_lJetPt_region2_LO_bybin_CR->Write();
    h_Top_lJetPt_region3_LO_bybin_CR->Write();
    h_Top_JetEta_bybin_CR->Write();
    h_Top_bJetEta_bybin_CR->Write();
    h_Top_lJetEta_bybin_CR->Write();
    h_Top_bJetEta_diffFR_LO_CR->Write();
    h_Top_lJetEta_diffFR_LO_CR->Write();

    h_Top_btrk_MET_region1_SR->Write();
    h_Top_btrk_MET_region2_SR->Write();
    h_Top_btrk_MET_region3_SR->Write();
    h_Top_ltrk_MET_region1_SR->Write();
    h_Top_ltrk_MET_region2_SR->Write();
    h_Top_ltrk_MET_region3_SR->Write();
    h_Top_bJetPt_MET_region1_SR->Write();
    h_Top_bJetPt_MET_region2_SR->Write();
    h_Top_bJetPt_MET_region3_SR->Write();
    h_Top_lJetPt_MET_region1_SR->Write();
    h_Top_lJetPt_MET_region2_SR->Write();
    h_Top_lJetPt_MET_region3_SR->Write();
    h_Top_bJetEta_MET_SR->Write();
    h_Top_lJetEta_MET_SR->Write();

    h_Top_btrk_MET_region1_bybin_CR->Write();
    h_Top_btrk_MET_region2_bybin_CR->Write();
    h_Top_btrk_MET_region3_bybin_CR->Write();
    h_Top_ltrk_MET_region1_bybin_CR->Write();
    h_Top_ltrk_MET_region2_bybin_CR->Write();
    h_Top_ltrk_MET_region3_bybin_CR->Write();
    h_Top_bJetPt_MET_region1_bybin_CR->Write();
    h_Top_bJetPt_MET_region2_bybin_CR->Write();
    h_Top_bJetPt_MET_region3_bybin_CR->Write();
    h_Top_lJetPt_MET_region1_bybin_CR->Write();
    h_Top_lJetPt_MET_region2_bybin_CR->Write();
    h_Top_lJetPt_MET_region3_bybin_CR->Write();
    h_Top_bJetEta_MET_diffFR_CR->Write();
    h_Top_lJetEta_MET_diffFR_CR->Write();

    outfile->Close();
    // h_Top_JetPt_bjet_SR->Draw();

    // cout << getWeight(file) << endl;
    // cout << "TTTo2L2NuWeight = " << TTTo2L2NuWeight << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        Ratio_Top_apply_LO();
    }
    else if (argc == 3)
    {
        Ratio_Top_apply_LO(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}