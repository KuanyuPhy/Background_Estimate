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
    float jetflavor, jetpt, jeteta, jetalpha, jetntrk;

public:
    ThinJet() {}
    ThinJet(const float &a, const float &b, const float &c, const float &d, const float &e) : jetflavor(a), jetpt(b), jeteta(c), jetalpha(d), jetntrk(e) {}
    Float_t GetFlavor() const { return jetflavor; }
    Float_t GetPt() const { return jetpt; }
    Float_t GetEta() const { return jeteta; }
    Float_t GetAlpha() const { return jetalpha; }
    Float_t GetNtrk() const { return jetntrk; }

    friend ostream &operator<<(ostream &out, const ThinJet &foo)
    {
        return out << foo.jetflavor << " " << foo.jetpt << " " << foo.jeteta << " " << foo.jetalpha << " " << foo.jetntrk << endl;
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
TFile *DYincli = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root");
TFile *DYHT100 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht100.root");
TFile *DYHT200 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht200.root");
TFile *DYHT400 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht400.root");
TFile *DYHT600 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht600.root");
TFile *DYHT800 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht800.root");
TFile *DYHT1200 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht1200.root");
TFile *DYHT2500 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_ht2500.root");

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

/*
double HT0Weight = 1.;
double HT70Weight = 1.;
double HT100Weight = 1.;
double HT200Weight = 1.;
double HT400Weight = 1.;
double HT600Weight = 1.;
double HT800Weight = 1.;
double HT1200Weight = 1.;
double HT2500Weight = 1.;
*/
//---------------
// void Function
//---------------
void for_inclusive_DY_sigle_flavor_jetvar(float HT, int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (HT < 70)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT0Weight);
        }
    }
    else if (HT >= 70 && HT < 100)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT70Weight);
        }
    }
    else if (HT >= 100 && HT < 200)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT100Weight);
        }
    }
    else if (HT >= 200 && HT < 400)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT200Weight);
        }
    }
    else if (HT >= 400 && HT < 600)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT400Weight);
        }
    }
    else if (HT >= 600 && HT < 800)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT600Weight);
        }
    }
    else if (HT >= 800 && HT < 1200)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT800Weight);
        }
    }
    else if (HT >= 1200 && HT < 2500)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT1200Weight);
        }
    }
    else if (HT >= 2500)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT2500Weight);
        }
    }
}
void for_inclusive_DY_two_flavor_jetvar(float HT, int flavor1, int flavor2, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (HT < 70)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT0Weight);
        }
    }
    else if (HT >= 70 && HT < 100)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT70Weight);
        }
    }
    else if (HT >= 100 && HT < 200)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT100Weight);
        }
    }
    else if (HT >= 200 && HT < 400)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT200Weight);
        }
    }
    else if (HT >= 400 && HT < 600)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT400Weight);
        }
    }
    else if (HT >= 600 && HT < 800)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT600Weight);
        }
    }
    else if (HT >= 800 && HT < 1200)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT800Weight);
        }
    }
    else if (HT >= 1200 && HT < 2500)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT1200Weight);
        }
    }
    else if (HT >= 2500)
    {
        if (hadronflavor == flavor1 || hadronflavor == flavor2)
        {
            h_tmp->Fill(tmp, Weight * HT2500Weight);
        }
    }
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
void ee_DY_half_inclu(TString file = "tmp.root", TString outputfile = "output.root")
{
    cout << "HT0Weight = " << HT0Weight << endl;
    cout << "HT100Weight = " << HT100Weight << endl;
    cout << "HT200Weight = " << HT200Weight << endl;
    cout << "HT400Weight = " << HT400Weight << endl;
    cout << "HT600Weight = " << HT600Weight << endl;
    cout << "HT800Weight = " << HT800Weight << endl;
    cout << "HT1200Weight = " << HT1200Weight << endl;
    cout << "HT2500Weight = " << HT2500Weight << endl;
    cout << "inputfile = " << file << endl;
    TFile *DYfile = TFile::Open(file);
    //--------------------------------------------------------------
    // Hist: 0 : |eta| < 1, 1 : 1 < |eta| < 2, 2 : 2 < |eta| < 2.5
    //--------------------------------------------------------------
    TH1D *h_DY_nTrk_difeta[3];
    TH1D *h_DY_nTrk_cut_difeta[3];
    TH1D *h_DY_nTrk_bjet_difeta[3];
    TH1D *h_DY_nTrk_bjet_cut_difeta[3];
    TH1D *h_DY_nTrk_cjet_difeta[3];
    TH1D *h_DY_nTrk_cjet_cut_difeta[3];
    TH1D *h_DY_nTrk_ljet_difeta[3];
    TH1D *h_DY_nTrk_ljet_cut_difeta[3];
    TH1D *h_DY_nTrk_hjet_difeta[3];
    TH1D *h_DY_nTrk_hjet_cut_difeta[3];

    TH1D *h_DY_nTrk_bjet_difeta_lowMET[3];
    TH1D *h_DY_nTrk_bjet_cut_difeta_lowMET[3];
    TH1D *h_DY_nTrk_cjet_difeta_lowMET[3];
    TH1D *h_DY_nTrk_cjet_cut_difeta_lowMET[3];
    TH1D *h_DY_nTrk_ljet_difeta_lowMET[3];
    TH1D *h_DY_nTrk_ljet_cut_difeta_lowMET[3];

    TH1D *h_DY_nTrk_bjet_difeta_highMET[3];
    TH1D *h_DY_nTrk_bjet_cut_difeta_highMET[3];
    TH1D *h_DY_nTrk_cjet_difeta_highMET[3];
    TH1D *h_DY_nTrk_cjet_cut_difeta_highMET[3];
    TH1D *h_DY_nTrk_ljet_difeta_highMET[3];
    TH1D *h_DY_nTrk_ljet_cut_difeta_highMET[3];

    for (int i = 0; i < 3; i++)
    {
        h_DY_nTrk_difeta[i] = new TH1D(Form("h_DY_nTrk_difeta_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_cut_difeta[i] = new TH1D(Form("h_DY_nTrk_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_bjet_difeta[i] = new TH1D(Form("h_DY_nTrk_bjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_bjet_cut_difeta[i] = new TH1D(Form("h_DY_nTrk_bjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_cjet_difeta[i] = new TH1D(Form("h_DY_nTrk_cjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_cjet_cut_difeta[i] = new TH1D(Form("h_DY_nTrk_cjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_ljet_difeta[i] = new TH1D(Form("h_DY_nTrk_ljet_difeta_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_ljet_cut_difeta[i] = new TH1D(Form("h_DY_nTrk_ljet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_hjet_difeta[i] = new TH1D(Form("h_DY_nTrk_hjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_hjet_cut_difeta[i] = new TH1D(Form("h_DY_nTrk_hjet_cut_difeta_%i", i + 1), "", 30, 1, 30);

        h_DY_nTrk_bjet_difeta_lowMET[i] = new TH1D(Form("h_DY_nTrk_bjet_difeta_lowMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_bjet_cut_difeta_lowMET[i] = new TH1D(Form("h_DY_nTrk_bjet_cut_difeta_lowMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_cjet_difeta_lowMET[i] = new TH1D(Form("h_DY_nTrk_cjet_difeta_lowMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_cjet_cut_difeta_lowMET[i] = new TH1D(Form("h_DY_nTrk_cjet_cut_difeta_lowMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_ljet_difeta_lowMET[i] = new TH1D(Form("h_DY_nTrk_ljet_difeta_lowMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_ljet_cut_difeta_lowMET[i] = new TH1D(Form("h_DY_nTrk_ljet_cut_difeta_lowMET_%i", i + 1), "", 30, 1, 30);

        h_DY_nTrk_bjet_difeta_highMET[i] = new TH1D(Form("h_DY_nTrk_bjet_difeta_highMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_bjet_cut_difeta_highMET[i] = new TH1D(Form("h_DY_nTrk_bjet_cut_difeta_highMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_cjet_difeta_highMET[i] = new TH1D(Form("h_DY_nTrk_cjet_difeta_highMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_cjet_cut_difeta_highMET[i] = new TH1D(Form("h_DY_nTrk_cjet_cut_difeta_highMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_ljet_difeta_highMET[i] = new TH1D(Form("h_DY_nTrk_ljet_difeta_highMET_%i", i + 1), "", 30, 1, 30);
        h_DY_nTrk_ljet_cut_difeta_highMET[i] = new TH1D(Form("h_DY_nTrk_ljet_cut_difeta_highMET_%i", i + 1), "", 30, 1, 30);

        h_DY_nTrk_difeta[i]->Sumw2();
        h_DY_nTrk_cut_difeta[i]->Sumw2();
        h_DY_nTrk_bjet_difeta[i]->Sumw2();
        h_DY_nTrk_bjet_cut_difeta[i]->Sumw2();
        h_DY_nTrk_cjet_difeta[i]->Sumw2();
        h_DY_nTrk_cjet_cut_difeta[i]->Sumw2();
        h_DY_nTrk_ljet_difeta[i]->Sumw2();
        h_DY_nTrk_ljet_cut_difeta[i]->Sumw2();
        h_DY_nTrk_hjet_difeta[i]->Sumw2();
        h_DY_nTrk_hjet_cut_difeta[i]->Sumw2();

        h_DY_nTrk_bjet_difeta_lowMET[i]->Sumw2();
        h_DY_nTrk_bjet_cut_difeta_lowMET[i]->Sumw2();
        h_DY_nTrk_cjet_difeta_lowMET[i]->Sumw2();
        h_DY_nTrk_cjet_cut_difeta_lowMET[i]->Sumw2();
        h_DY_nTrk_ljet_difeta_lowMET[i]->Sumw2();
        h_DY_nTrk_ljet_cut_difeta_lowMET[i]->Sumw2();

        h_DY_nTrk_bjet_difeta_highMET[i]->Sumw2();
        h_DY_nTrk_bjet_cut_difeta_highMET[i]->Sumw2();
        h_DY_nTrk_cjet_difeta_highMET[i]->Sumw2();
        h_DY_nTrk_cjet_cut_difeta_highMET[i]->Sumw2();
        h_DY_nTrk_ljet_difeta_highMET[i]->Sumw2();
        h_DY_nTrk_ljet_cut_difeta_highMET[i]->Sumw2();
    }
    //-----------------------------
    // Not consider eta
    //-----------------------------
    TH1D *h_DY_nTrk_bjet = new TH1D("h_DY_nTrk_bjet", "", 30, 1, 30);
    TH1D *h_DY_nTrk_bjet_cut = new TH1D("h_DY_nTrk_bjet_cut", "", 30, 1, 30);
    TH1D *h_DY_nTrk_cjet = new TH1D("h_DY_nTrk_cjet", "", 30, 1, 30);
    TH1D *h_DY_nTrk_cjet_cut = new TH1D("h_DY_nTrk_cjet_cut", "", 30, 1, 30);
    TH1D *h_DY_nTrk_ljet = new TH1D("h_DY_nTrk_ljet", "", 30, 1, 30);
    TH1D *h_DY_nTrk_ljet_cut = new TH1D("h_DY_nTrk_ljet_cut", "", 30, 1, 30);
    TH1D *h_DY_nTrk_hjet = new TH1D("h_DY_nTrk_hjet", "", 30, 1, 30);
    TH1D *h_DY_nTrk_hjet_cut = new TH1D("h_DY_nTrk_hjet_cut", "", 30, 1, 30);
    h_DY_nTrk_bjet->Sumw2();
    h_DY_nTrk_bjet_cut->Sumw2();
    h_DY_nTrk_cjet->Sumw2();
    h_DY_nTrk_cjet_cut->Sumw2();
    h_DY_nTrk_ljet->Sumw2();
    h_DY_nTrk_ljet_cut->Sumw2();
    h_DY_nTrk_hjet->Sumw2();
    h_DY_nTrk_hjet_cut->Sumw2();
    //-----------------------------
    // Not consider flavor
    //-----------------------------
    TH1D *h_DY_nTrk = new TH1D("h_DY_nTrk", "", 30, 1, 30);
    TH1D *h_DY_nTrk_cut = new TH1D("h_DY_nTrk_cut", "", 30, 1, 30);
    h_DY_nTrk->Sumw2();
    h_DY_nTrk_cut->Sumw2();

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
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;
        vector<ThinJet> v_thinjet;
        for (size_t i = 0; i < v_DY_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_DY_Jethadronflavor)[i], (*v_DY_JetPT)[i], (*v_DY_JetEta)[i], (*v_DY_alpha)[i], (*v_DY_nTrack)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        if (f_DY_met < 140)
        {
            for (size_t i = 0; i < v_thinjet.size(); i++)
            {
                //--------------------
                // Consider eta
                //--------------------
                // For Region |eta| < 1
                if (abs(v_thinjet[i].GetEta()) < 1)
                {
                    // For b jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_difeta_lowMET[0]);
                    // For c jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_difeta_lowMET[0]);
                    // For l jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_difeta_lowMET[0]);

                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_cut_difeta_lowMET[0]);
                        // For c jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_cut_difeta_lowMET[0]);
                        // For light flavor
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_cut_difeta_lowMET[0]);
                    }
                }
                // For Region 1 < |eta| < 2
                else if (abs(v_thinjet[i].GetEta()) > 1 && abs(v_thinjet[i].GetEta()) < 2)
                {
                    // For b jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_difeta_lowMET[1]);
                    // For c jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_difeta_lowMET[1]);
                    // For l jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_difeta_lowMET[1]);

                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_cut_difeta_lowMET[1]);
                        // For c jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_cut_difeta_lowMET[1]);
                        // For light flavor
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_cut_difeta_lowMET[1]);
                    }
                }
                // For Region 2 < |eta| < 2.5
                else if (abs(v_thinjet[i].GetEta()) > 2 && abs(v_thinjet[i].GetEta()) < 2.5)
                {
                    // For b jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_difeta_lowMET[2]);
                    // For c jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_difeta_lowMET[2]);
                    // For l jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_difeta_lowMET[2]);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_cut_difeta_lowMET[2]);
                        // For c jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_cut_difeta_lowMET[2]);
                        // For light flavor
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_cut_difeta_lowMET[2]);
                    }
                }
            }
        }
        else if (f_DY_met > 140)
        {
            for (size_t i = 0; i < v_thinjet.size(); i++)
            {
                //--------------------
                // Consider eta
                //--------------------
                // For Region |eta| < 1
                if (abs(v_thinjet[i].GetEta()) < 1)
                {
                    // For b jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_difeta_highMET[0]);
                    // For c jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_difeta_highMET[0]);
                    // For l jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_difeta_highMET[0]);

                    if (v_thinjet[i].GetNtrk() == 1)
                    {
                        if (v_thinjet[i].GetFlavor() == 5)
                        {
                            cout << "ntrk = " << v_thinjet[i].GetNtrk() << endl;
                        }
                    }

                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_cut_difeta_highMET[0]);
                        // For c jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_cut_difeta_highMET[0]);
                        // For light flavor
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_cut_difeta_highMET[0]);

                        if (v_thinjet[i].GetNtrk() == 1)
                        {
                            if (v_thinjet[i].GetFlavor() == 5)
                            {
                                cout << "cut ntrk = " << v_thinjet[i].GetNtrk() << endl;
                            }
                        }
                    }
                }
                // For Region 1 < |eta| < 2
                else if (abs(v_thinjet[i].GetEta()) > 1 && abs(v_thinjet[i].GetEta()) < 2)
                {
                    // For b jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_difeta_highMET[1]);
                    // For c jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_difeta_highMET[1]);
                    // For l jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_difeta_highMET[1]);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_cut_difeta_highMET[1]);
                        // For c jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_cut_difeta_highMET[1]);
                        // For light flavor
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_cut_difeta_highMET[1]);
                    }
                }
                // For Region 2 < |eta| < 2.5
                else if (abs(v_thinjet[i].GetEta()) > 2 && abs(v_thinjet[i].GetEta()) < 2.5)
                {
                    // For b jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_difeta_highMET[2]);
                    // For c jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_difeta_highMET[2]);
                    // For l jet
                    for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_difeta_highMET[2]);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_bjet_cut_difeta_highMET[2]);
                        // For c jet
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_cjet_cut_difeta_highMET[2]);
                        // For light flavor
                        for_inclusive_DY_sigle_flavor_jetvar(f_HT, 0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), I_DY_weight, h_DY_nTrk_ljet_cut_difeta_highMET[2]);
                    }
                }
            }
        }

    } // End of DY loop

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    for (int i = 0; i < 3; i++)
    {
        h_DY_nTrk_difeta[i]->Write();
        h_DY_nTrk_cut_difeta[i]->Write();
        h_DY_nTrk_bjet_difeta[i]->Write();
        h_DY_nTrk_bjet_cut_difeta[i]->Write();
        h_DY_nTrk_cjet_difeta[i]->Write();
        h_DY_nTrk_cjet_cut_difeta[i]->Write();
        h_DY_nTrk_ljet_difeta[i]->Write();
        h_DY_nTrk_ljet_cut_difeta[i]->Write();
        h_DY_nTrk_hjet_difeta[i]->Write();
        h_DY_nTrk_hjet_cut_difeta[i]->Write();

        h_DY_nTrk_bjet_difeta_lowMET[i]->Write();
        h_DY_nTrk_bjet_cut_difeta_lowMET[i]->Write();
        h_DY_nTrk_cjet_difeta_lowMET[i]->Write();
        h_DY_nTrk_cjet_cut_difeta_lowMET[i]->Write();
        h_DY_nTrk_ljet_difeta_lowMET[i]->Write();
        h_DY_nTrk_ljet_cut_difeta_lowMET[i]->Write();

        h_DY_nTrk_bjet_difeta_highMET[i]->Write();
        h_DY_nTrk_bjet_cut_difeta_highMET[i]->Write();
        h_DY_nTrk_cjet_difeta_highMET[i]->Write();
        h_DY_nTrk_cjet_cut_difeta_highMET[i]->Write();
        h_DY_nTrk_ljet_difeta_highMET[i]->Write();
        h_DY_nTrk_ljet_cut_difeta_highMET[i]->Write();
    }
    h_DY_nTrk_bjet->Write();
    h_DY_nTrk_bjet_cut->Write();
    h_DY_nTrk_cjet->Write();
    h_DY_nTrk_cjet_cut->Write();
    h_DY_nTrk_ljet->Write();
    h_DY_nTrk_ljet_cut->Write();
    h_DY_nTrk_hjet->Write();
    h_DY_nTrk_hjet_cut->Write();
    h_DY_nTrk->Write();
    h_DY_nTrk_cut->Write();

    outfile->Close();

    // cout << getWeight(file) << endl;
    // cout << "TTTo2L2NuWeight = " << TTTo2L2NuWeight << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_DY_half_inclu();
    }
    else if (argc == 3)
    {
        ee_DY_half_inclu(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}