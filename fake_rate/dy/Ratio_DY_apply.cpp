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
#include "./../../lib/Cross_section.h"
using namespace std;

//------------------
// Calculate weight
//------------------
TFile *DYincli = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
TFile *DYHT100 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
TFile *DYHT200 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
TFile *DYHT400 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
TFile *DYHT600 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
TFile *DYHT800 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
TFile *DYHT1200 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
TFile *DYHT2500 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

TFile *DY_fakerate_dibfile = new TFile("./DY_fakerate.root");

TH1D *DY_nTrk_fakeRate_difeta_1 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_fakeRate_difeta_1"));
TH1D *DY_nTrk_bfakeRate_difeta_1 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_bfakeRate_difeta_1"));
TH1D *DY_nTrk_cfakeRate_difeta_1 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_cfakeRate_difeta_1"));
TH1D *DY_nTrk_lfakeRate_difeta_1 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_lfakeRate_difeta_1"));
TH1D *DY_nTrk_hfakeRate_difeta_1 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_hfakeRate_difeta_1"));

TH1D *DY_nTrk_fakeRate_difeta_2 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_fakeRate_difeta_2"));
TH1D *DY_nTrk_bfakeRate_difeta_2 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_bfakeRate_difeta_2"));
TH1D *DY_nTrk_cfakeRate_difeta_2 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_cfakeRate_difeta_2"));
TH1D *DY_nTrk_lfakeRate_difeta_2 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_lfakeRate_difeta_2"));
TH1D *DY_nTrk_hfakeRate_difeta_2 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_hfakeRate_difeta_2"));

TH1D *DY_nTrk_fakeRate_difeta_3 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_fakeRate_difeta_3"));
TH1D *DY_nTrk_bfakeRate_difeta_3 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_bfakeRate_difeta_3"));
TH1D *DY_nTrk_cfakeRate_difeta_3 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_cfakeRate_difeta_3"));
TH1D *DY_nTrk_lfakeRate_difeta_3 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_lfakeRate_difeta_3"));
TH1D *DY_nTrk_hfakeRate_difeta_3 = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_hfakeRate_difeta_3"));

TH1D *DY_nTrk_bfakeRate = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_bfakeRate"));
TH1D *DY_nTrk_cfakeRate = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_cfakeRate"));
TH1D *DY_nTrk_lfakeRate = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_lfakeRate"));
TH1D *DY_nTrk_hfakeRate = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_hfakeRate"));
TH1D *DY_nTrk_fakeRate = ((TH1D *)DY_fakerate_dibfile->Get("DY_nTrk_fakeRate"));

TH1D *h_HT_eventCout = ((TH1D *)DYincli->Get("Event_Variable/h_HT_eventCout"));
TH1D *DYHT100_sumevt = ((TH1D *)DYHT100->Get("Event_Variable/h_totevent"));
TH1D *DYHT200_sumevt = ((TH1D *)DYHT200->Get("Event_Variable/h_totevent"));
TH1D *DYHT400_sumevt = ((TH1D *)DYHT400->Get("Event_Variable/h_totevent"));
TH1D *DYHT600_sumevt = ((TH1D *)DYHT600->Get("Event_Variable/h_totevent"));
TH1D *DYHT800_sumevt = ((TH1D *)DYHT800->Get("Event_Variable/h_totevent"));
TH1D *DYHT1200_sumevt = ((TH1D *)DYHT1200->Get("Event_Variable/h_totevent"));
TH1D *DYHT2500_sumevt = ((TH1D *)DYHT2500->Get("Event_Variable/h_totevent"));

int DYHT100_totevt = DYHT100_sumevt->Integral();
int DYHT200_totevt = DYHT200_sumevt->Integral();
int DYHT400_totevt = DYHT400_sumevt->Integral();
int DYHT600_totevt = DYHT600_sumevt->Integral();
int DYHT800_totevt = DYHT800_sumevt->Integral();
int DYHT1200_totevt = DYHT1200_sumevt->Integral();
int DYHT2500_totevt = DYHT2500_sumevt->Integral();

int HT0_70_event = h_HT_eventCout->GetBinContent(2);
int HT70_100_event = h_HT_eventCout->GetBinContent(3);
int HT100_200_event = h_HT_eventCout->GetBinContent(4);
int HT200_400_event = h_HT_eventCout->GetBinContent(5);
int HT400_600_event = h_HT_eventCout->GetBinContent(6);
int HT600_800_event = h_HT_eventCout->GetBinContent(7);
int HT800_1200_event = h_HT_eventCout->GetBinContent(8);
int HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
int HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);
//---------------------
// Define Diboson Weight
//---------------------
double HT0Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT0CS / (HT0_70_event)) * 1000 * 2;
double HT70Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT70CS / (HT70_100_event)) * 1000 * 2;
double HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000 * 2;
double HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000 * 2;
double HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000 * 2;
double HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000 * 2;
double HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000 * 2;
double HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000 * 2;
double HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000 * 2;

vector<double> v_xs_Weight = {HT100Weight,
                              HT200Weight, HT400Weight, HT600Weight, HT800Weight,
                              HT1200Weight, HT2500Weight};
vector<const char *> v_DY_filename = {"ht100",
                                      "ht200", "ht400", "ht600", "ht800",
                                      "ht1200", "ht2500"};
double getWeight(const char *file_name_tmp)
{
    TString file_name = file_name_tmp;
    for (int i = 0; i < v_DY_filename.size(); i++)
    {
        if (file_name.Contains(v_DY_filename[i]))
        {
            return v_xs_Weight[i];
        }
    }
    Fatal("getWeight", "%s is not a valid file", file_name_tmp);
    return -100000;
}
int getfakerate(float tmp1, float start, float Binwidth)
{
    int quotient;
    quotient = floor((tmp1 - start) / (Binwidth));

    return quotient + 1;
}
void for_inclusive_DY_var(float HT, float tmp, double Weight, TH1D *h_tmp)
{
    if (HT < 70)
    {
        h_tmp->Fill(tmp, Weight * HT0Weight);
    }
    else if (HT >= 70 && HT < 100)
    {
        h_tmp->Fill(tmp, Weight * HT70Weight);
    }
    else if (HT >= 100 && HT < 200)
    {
        h_tmp->Fill(tmp, Weight * HT100Weight);
    }
    else if (HT >= 200 && HT < 400)
    {
        h_tmp->Fill(tmp, Weight * HT200Weight);
    }
    else if (HT >= 400 && HT < 600)
    {
        h_tmp->Fill(tmp, Weight * HT400Weight);
    }
    else if (HT >= 600 && HT < 800)
    {
        h_tmp->Fill(tmp, Weight * HT600Weight);
    }
    else if (HT >= 800 && HT < 1200)
    {
        h_tmp->Fill(tmp, Weight * HT800Weight);
    }
    else if (HT >= 1200 && HT < 2500)
    {
        h_tmp->Fill(tmp, Weight * HT1200Weight);
    }
    else if (HT >= 2500)
    {
        h_tmp->Fill(tmp, Weight * HT2500Weight);
    }
}
void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, int flavor2, int hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void Ratio_DY_inclu_apply(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *DYfile = TFile::Open(file);
    cout << "DY weight = " << getWeight(file) << endl;

    //--------------------------------------
    //  nTrk : Not consider different eta
    //--------------------------------------
    TH1D *h_DY_trk_bybin_CR = new TH1D("h_DY_trk_bybin_CR", "", 30, 1, 30);
    h_DY_trk_bybin_CR->Sumw2();

    TH1D *h_DY_btrk_bybin_CR = new TH1D("h_DY_btrk_bybin_CR", "", 30, 1, 30);
    h_DY_btrk_bybin_CR->Sumw2();

    TH1D *h_DY_ctrk_bybin_CR = new TH1D("h_DY_ctrk_bybin_CR", "", 30, 1, 30);
    h_DY_ctrk_bybin_CR->Sumw2();

    TH1D *h_DY_ltrk_bybin_CR = new TH1D("h_DY_ltrk_bybin_CR", "", 30, 1, 30);
    h_DY_ltrk_bybin_CR->Sumw2();

    TH1D *h_DY_htrk_bybin_CR = new TH1D("h_DY_htrk_bybin_CR", "", 30, 1, 30);
    h_DY_htrk_bybin_CR->Sumw2();

    TH1D *h_DY_trk_SR = new TH1D("h_DY_trk_SR", "", 30, 1, 30);
    h_DY_trk_SR->Sumw2();

    TH1D *h_DY_btrk_SR = new TH1D("h_DY_btrk_SR", "", 30, 1, 30);
    h_DY_btrk_SR->Sumw2();

    TH1D *h_DY_ctrk_SR = new TH1D("h_DY_ctrk_SR", "", 30, 1, 30);
    h_DY_ctrk_SR->Sumw2();

    TH1D *h_DY_ltrk_SR = new TH1D("h_DY_ltrk_SR", "", 30, 1, 30);
    h_DY_ltrk_SR->Sumw2();

    TH1D *h_DY_htrk_SR = new TH1D("h_DY_htrk_SR", "", 30, 1, 30);
    h_DY_htrk_SR->Sumw2();

    //----------------------
    //  nTrk : different eta
    //----------------------
    TH1D *h_DY_trk_region1_bybin_CR = new TH1D("h_DY_trk_region1_bybin_CR", "", 30, 1, 30);
    h_DY_trk_region1_bybin_CR->Sumw2();
    TH1D *h_DY_trk_region2_bybin_CR = new TH1D("h_DY_trk_region2_bybin_CR", "", 30, 1, 30);
    h_DY_trk_region2_bybin_CR->Sumw2();
    TH1D *h_DY_trk_region3_bybin_CR = new TH1D("h_DY_trk_region3_bybin_CR", "", 30, 1, 30);
    h_DY_trk_region3_bybin_CR->Sumw2();

    TH1D *h_DY_btrk_region1_bybin_CR = new TH1D("h_DY_btrk_region1_bybin_CR", "", 30, 1, 30);
    h_DY_btrk_region1_bybin_CR->Sumw2();
    TH1D *h_DY_btrk_region2_bybin_CR = new TH1D("h_DY_btrk_region2_bybin_CR", "", 30, 1, 30);
    h_DY_btrk_region2_bybin_CR->Sumw2();
    TH1D *h_DY_btrk_region3_bybin_CR = new TH1D("h_DY_btrk_region3_bybin_CR", "", 30, 1, 30);
    h_DY_btrk_region3_bybin_CR->Sumw2();

    TH1D *h_DY_ctrk_region1_bybin_CR = new TH1D("h_DY_ctrk_region1_bybin_CR", "", 30, 1, 30);
    h_DY_ctrk_region1_bybin_CR->Sumw2();
    TH1D *h_DY_ctrk_region2_bybin_CR = new TH1D("h_DY_ctrk_region2_bybin_CR", "", 30, 1, 30);
    h_DY_ctrk_region2_bybin_CR->Sumw2();
    TH1D *h_DY_ctrk_region3_bybin_CR = new TH1D("h_DY_ctrk_region3_bybin_CR", "", 30, 1, 30);
    h_DY_ctrk_region3_bybin_CR->Sumw2();

    TH1D *h_DY_ltrk_region1_bybin_CR = new TH1D("h_DY_ltrk_region1_bybin_CR", "", 30, 1, 30);
    h_DY_ltrk_region1_bybin_CR->Sumw2();
    TH1D *h_DY_ltrk_region2_bybin_CR = new TH1D("h_DY_ltrk_region2_bybin_CR", "", 30, 1, 30);
    h_DY_ltrk_region2_bybin_CR->Sumw2();
    TH1D *h_DY_ltrk_region3_bybin_CR = new TH1D("h_DY_ltrk_region3_bybin_CR", "", 30, 1, 30);
    h_DY_ltrk_region3_bybin_CR->Sumw2();

    TH1D *h_DY_htrk_region1_bybin_CR = new TH1D("h_DY_htrk_region1_bybin_CR", "", 30, 1, 30);
    h_DY_htrk_region1_bybin_CR->Sumw2();
    TH1D *h_DY_htrk_region2_bybin_CR = new TH1D("h_DY_htrk_region2_bybin_CR", "", 30, 1, 30);
    h_DY_htrk_region2_bybin_CR->Sumw2();
    TH1D *h_DY_htrk_region3_bybin_CR = new TH1D("h_DY_htrk_region3_bybin_CR", "", 30, 1, 30);
    h_DY_htrk_region3_bybin_CR->Sumw2();

    TH1D *h_DY_trk_region1_SR = new TH1D("h_DY_trk_region1_SR", "", 30, 1, 30);
    h_DY_trk_region1_SR->Sumw2();
    TH1D *h_DY_trk_region2_SR = new TH1D("h_DY_trk_region2_SR", "", 30, 1, 30);
    h_DY_trk_region2_SR->Sumw2();
    TH1D *h_DY_trk_region3_SR = new TH1D("h_DY_trk_region3_SR", "", 30, 1, 30);
    h_DY_trk_region3_SR->Sumw2();

    TH1D *h_DY_btrk_region1_SR = new TH1D("h_DY_btrk_region1_SR", "", 30, 1, 30);
    h_DY_btrk_region1_SR->Sumw2();
    TH1D *h_DY_btrk_region2_SR = new TH1D("h_DY_btrk_region2_SR", "", 30, 1, 30);
    h_DY_btrk_region2_SR->Sumw2();
    TH1D *h_DY_btrk_region3_SR = new TH1D("h_DY_btrk_region3_SR", "", 30, 1, 30);
    h_DY_btrk_region3_SR->Sumw2();

    TH1D *h_DY_ctrk_region1_SR = new TH1D("h_DY_ctrk_region1_SR", "", 30, 1, 30);
    h_DY_ctrk_region1_SR->Sumw2();
    TH1D *h_DY_ctrk_region2_SR = new TH1D("h_DY_ctrk_region2_SR", "", 30, 1, 30);
    h_DY_ctrk_region2_SR->Sumw2();
    TH1D *h_DY_ctrk_region3_SR = new TH1D("h_DY_ctrk_region3_SR", "", 30, 1, 30);
    h_DY_ctrk_region3_SR->Sumw2();

    TH1D *h_DY_ltrk_region1_SR = new TH1D("h_DY_ltrk_region1_SR", "", 30, 1, 30);
    h_DY_ltrk_region1_SR->Sumw2();
    TH1D *h_DY_ltrk_region2_SR = new TH1D("h_DY_ltrk_region2_SR", "", 30, 1, 30);
    h_DY_ltrk_region2_SR->Sumw2();
    TH1D *h_DY_ltrk_region3_SR = new TH1D("h_DY_ltrk_region3_SR", "", 30, 1, 30);
    h_DY_ltrk_region3_SR->Sumw2();

    TH1D *h_DY_htrk_region1_SR = new TH1D("h_DY_htrk_region1_SR", "", 30, 1, 30);
    h_DY_htrk_region1_SR->Sumw2();
    TH1D *h_DY_htrk_region2_SR = new TH1D("h_DY_htrk_region2_SR", "", 30, 1, 30);
    h_DY_htrk_region2_SR->Sumw2();
    TH1D *h_DY_htrk_region3_SR = new TH1D("h_DY_htrk_region3_SR", "", 30, 1, 30);
    h_DY_htrk_region3_SR->Sumw2();

    float_t f_HT;

    Int_t I_DY_nJets;

    Int_t I_DY_weight;

    float_t f_DY_met;

    vector<float> *v_DY_alpha = new vector<float>();
    vector<float> *v_DY_Chi3Dlog = new vector<float>();
    vector<float> *v_DY_2DIP = new vector<float>();
    vector<float> *v_DY_nTrack = new vector<float>();
    vector<float> *v_DY_Jethadronflavor = new vector<float>();
    vector<float> *v_DY_Jetpartonflavor = new vector<float>();
    vector<float> *v_DY_JetPT = new vector<float>();
    vector<float> *v_DY_JetEta = new vector<float>();

    v_DY_alpha->clear();
    v_DY_Chi3Dlog->clear();
    v_DY_2DIP->clear();
    v_DY_nTrack->clear();
    v_DY_Jethadronflavor->clear();
    v_DY_Jetpartonflavor->clear();
    v_DY_JetPT->clear();
    v_DY_JetEta->clear();

    TTree *T_DY_tree;
    DYfile->GetObject("h1", T_DY_tree);
    T_DY_tree->SetBranchAddress("I_weight", &I_DY_weight);
    T_DY_tree->SetBranchAddress("f_HT", &f_HT);
    T_DY_tree->SetBranchAddress("I_nJets", &I_DY_nJets);
    T_DY_tree->SetBranchAddress("v_N_Tracks", &v_DY_nTrack);
    T_DY_tree->SetBranchAddress("f_Met", &f_DY_met);
    T_DY_tree->SetBranchAddress("v_IP2D", &v_DY_2DIP);
    T_DY_tree->SetBranchAddress("v_Chi3Dlog", &v_DY_Chi3Dlog);
    T_DY_tree->SetBranchAddress("v_fakealpha", &v_DY_alpha);
    T_DY_tree->SetBranchAddress("v_fakeJethadronflavor", &v_DY_Jethadronflavor);
    T_DY_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_DY_Jetpartonflavor);
    T_DY_tree->SetBranchAddress("v_fakeJetPt", &v_DY_JetPT);
    T_DY_tree->SetBranchAddress("v_fakeJetEta", &v_DY_JetEta);
    for (int evt = 0; evt < T_DY_tree->GetEntries(); evt++)
    {
        T_DY_tree->GetEntry(evt);
        if (f_DY_met < 0)
        {
            cout << "bug" << endl;
            continue;
        }
        double DY_weight = getWeight(file) * I_DY_weight;
        double bxBinwidth = DY_nTrk_fakeRate->GetBinWidth(5);
        //cout << "bxBinwidth = " << bxBinwidth << endl;
        for (size_t i = 0; i < v_DY_nTrack->size(); i++)
        {
            int bxBin_local = getfakerate((*v_DY_nTrack)[i], 1., bxBinwidth);
            int cxBin_local = getfakerate((*v_DY_nTrack)[i], 1., bxBinwidth);
            int lxBin_local = getfakerate((*v_DY_nTrack)[i], 1., bxBinwidth);
            double fakerate = DY_nTrk_fakeRate->GetBinContent(bxBin_local) * DY_weight;
            double b_fakerate = DY_nTrk_bfakeRate->GetBinContent(bxBin_local) * DY_weight;
            double c_fakerate = DY_nTrk_cfakeRate->GetBinContent(bxBin_local) * DY_weight;
            double l_fakerate = DY_nTrk_lfakeRate->GetBinContent(bxBin_local) * DY_weight;
            double h_fakerate = DY_nTrk_hfakeRate->GetBinContent(bxBin_local) * DY_weight;

            // Not Consider eta
            h_DY_trk_bybin_CR->Fill((*v_DY_nTrack)[i], fakerate);
            for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], b_fakerate, h_DY_btrk_bybin_CR);
            for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], c_fakerate, h_DY_ctrk_bybin_CR);
            for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], l_fakerate, h_DY_ltrk_bybin_CR);
            for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], h_fakerate, h_DY_htrk_bybin_CR);

            if ((*v_DY_alpha)[i] < 0.1)
            {
                // Not Consider eta
                h_DY_trk_SR->Fill((*v_DY_nTrack)[i], I_DY_weight);
                for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_btrk_SR);
                for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_ctrk_SR);
                for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_ltrk_SR);
                for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_htrk_SR);
            }
            //---------------------------------------------------------
            // Different eta
            //---------------------------------------------------------
            //  For Region |eta| < 1
            if (abs((*v_DY_JetEta)[i]) < 1)
            {
                h_DY_trk_region1_bybin_CR->Fill((*v_DY_nTrack)[i], fakerate);
                for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], b_fakerate, h_DY_btrk_region1_bybin_CR);
                for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], c_fakerate, h_DY_ctrk_region1_bybin_CR);
                for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], l_fakerate, h_DY_ltrk_region1_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], h_fakerate, h_DY_htrk_region1_bybin_CR);
                if ((*v_DY_alpha)[i] < 0.1)
                {
                    // Not Consider eta
                    h_DY_trk_region1_SR->Fill((*v_DY_nTrack)[i], I_DY_weight);
                    for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_btrk_region1_SR);
                    for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_ctrk_region1_SR);
                    for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_ltrk_region1_SR);
                    for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_htrk_region1_SR);
                }
            }
            // For Region 1 < |eta| < 2
            else if (abs((*v_DY_JetEta)[i]) > 1 && abs((*v_DY_JetEta)[i]) < 2)
            {
                h_DY_trk_region2_bybin_CR->Fill((*v_DY_nTrack)[i], fakerate);
                for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], b_fakerate, h_DY_btrk_region2_bybin_CR);
                for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], c_fakerate, h_DY_ctrk_region2_bybin_CR);
                for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], l_fakerate, h_DY_ltrk_region2_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], h_fakerate, h_DY_htrk_region2_bybin_CR);
                if ((*v_DY_alpha)[i] < 0.1)
                {
                    // Not Consider eta
                    h_DY_trk_region2_SR->Fill((*v_DY_nTrack)[i], I_DY_weight);
                    for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_btrk_region2_SR);
                    for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_ctrk_region2_SR);
                    for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_ltrk_region2_SR);
                    for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_htrk_region2_SR);
                }
            }
            // For Region 2 < |eta| < 2.5
            else if (abs((*v_DY_JetEta)[i]) > 2 && abs((*v_DY_JetEta)[i]) < 2.5)
            {
                h_DY_trk_region3_bybin_CR->Fill((*v_DY_nTrack)[i], fakerate);
                for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], b_fakerate, h_DY_btrk_region3_bybin_CR);
                for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], c_fakerate, h_DY_ctrk_region3_bybin_CR);
                for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], l_fakerate, h_DY_ltrk_region3_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], h_fakerate, h_DY_htrk_region3_bybin_CR);
                if ((*v_DY_alpha)[i] < 0.1)
                {
                    // Not Consider eta
                    h_DY_trk_region3_SR->Fill((*v_DY_nTrack)[i], I_DY_weight);
                    for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_btrk_region3_SR);
                    for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_ctrk_region3_SR);
                    for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_ltrk_region3_SR);
                    for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], I_DY_weight, h_DY_htrk_region3_SR);
                }
            }
        }
    }
    /*
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
    h_DY_ltrk_region1_SR->Draw();
    h_DY_ltrk_region1_bybin_CR->Draw("same");
    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    gStyle->SetOptStat(0);
    */
    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    h_DY_trk_bybin_CR->Write();
    h_DY_btrk_bybin_CR->Write();
    h_DY_ctrk_bybin_CR->Write();
    h_DY_ltrk_bybin_CR->Write();
    h_DY_htrk_bybin_CR->Write();
    h_DY_trk_SR->Write();
    h_DY_btrk_SR->Write();
    h_DY_ctrk_SR->Write();
    h_DY_ltrk_SR->Write();
    h_DY_htrk_SR->Write();
    h_DY_trk_region1_bybin_CR->Write();
    h_DY_trk_region2_bybin_CR->Write();
    h_DY_trk_region3_bybin_CR->Write();
    h_DY_btrk_region1_bybin_CR->Write();
    h_DY_btrk_region2_bybin_CR->Write();
    h_DY_btrk_region3_bybin_CR->Write();
    h_DY_ctrk_region1_bybin_CR->Write();
    h_DY_ctrk_region2_bybin_CR->Write();
    h_DY_ctrk_region3_bybin_CR->Write();
    h_DY_ltrk_region1_bybin_CR->Write();
    h_DY_ltrk_region2_bybin_CR->Write();
    h_DY_ltrk_region3_bybin_CR->Write();
    h_DY_htrk_region1_bybin_CR->Write();
    h_DY_htrk_region2_bybin_CR->Write();
    h_DY_htrk_region3_bybin_CR->Write();
    h_DY_trk_region1_SR->Write();
    h_DY_trk_region2_SR->Write();
    h_DY_trk_region3_SR->Write();
    h_DY_btrk_region1_SR->Write();
    h_DY_btrk_region2_SR->Write();
    h_DY_btrk_region3_SR->Write();
    h_DY_ctrk_region1_SR->Write();
    h_DY_ctrk_region2_SR->Write();
    h_DY_ctrk_region3_SR->Write();
    h_DY_ltrk_region1_SR->Write();
    h_DY_ltrk_region2_SR->Write();
    h_DY_ltrk_region3_SR->Write();
    h_DY_htrk_region1_SR->Write();
    h_DY_htrk_region2_SR->Write();
    h_DY_htrk_region3_SR->Write();
    outfile->Close();
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        Ratio_DY_inclu_apply();
    }
    else if (argc == 3)
    {
        Ratio_DY_inclu_apply(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}
