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

double DYHT100_totevt = DYHT100_sumevt->Integral();
double DYHT200_totevt = DYHT200_sumevt->Integral();
double DYHT400_totevt = DYHT400_sumevt->Integral();
double DYHT600_totevt = DYHT600_sumevt->Integral();
double DYHT800_totevt = DYHT800_sumevt->Integral();
double DYHT1200_totevt = DYHT1200_sumevt->Integral();
double DYHT2500_totevt = DYHT2500_sumevt->Integral();

double HT0_70_event = h_HT_eventCout->GetBinContent(2);
double HT70_100_event = h_HT_eventCout->GetBinContent(3);
double HT100_200_event = h_HT_eventCout->GetBinContent(4);
double HT200_400_event = h_HT_eventCout->GetBinContent(5);
double HT400_600_event = h_HT_eventCout->GetBinContent(6);
double HT600_800_event = h_HT_eventCout->GetBinContent(7);
double HT800_1200_event = h_HT_eventCout->GetBinContent(8);
double HT1200_2500_event = h_HT_eventCout->GetBinContent(9);
double HT2500_Inf_event = h_HT_eventCout->GetBinContent(10);
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

//---------------
// void Function
//---------------
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
void ee_DY_half(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *DYfile = TFile::Open(file);
    cout << "inputfile = " << file << endl;
    cout << "DY weight = " << getWeight(file) << endl;
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
    h_DY_nTrk->Sumw2();
    TH1D *h_DY_nTrk_cut = new TH1D("h_DY_nTrk_cut", "", 30, 1, 30);
    h_DY_nTrk_cut->Sumw2();

    //----------------------
    // For alpha
    //----------------------
    TH1D *h_DY_alpha_lowMET = new TH1D("h_DY_alpha_lowMET", "", 20, 0, 1.);
    h_DY_alpha_lowMET->Sumw2();

    TH1D *h_DY_alpha_highMET = new TH1D("h_DY_alpha_highMET", "", 20, 0, 1.);
    h_DY_alpha_highMET->Sumw2();

    TH1D *h_DY_alpha_lowdipt = new TH1D("h_DY_alpha_lowdipt", "", 20, 0, 1.);
    h_DY_alpha_lowdipt->Sumw2();

    TH1D *h_DY_alpha_highdipt = new TH1D("h_DY_alpha_highdipt", "", 20, 0, 1.);
    h_DY_alpha_highdipt->Sumw2();

    Int_t I_DY_nJets;

    Int_t I_DY_weight;

    float_t f_DY_met;

    float_t f_DY_dileppt;

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
    T_DY_tree->SetBranchAddress("I_nJets", &I_DY_nJets);
    T_DY_tree->SetBranchAddress("v_N_Tracks", &v_DY_nTrack);
    T_DY_tree->SetBranchAddress("f_Met", &f_DY_met);
    T_DY_tree->SetBranchAddress("f_dileptonPT", &f_DY_dileppt);
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
            continue;
        }
        double DY_weight = getWeight(file) * I_DY_weight;
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
                h_DY_alpha_lowMET->Fill(v_thinjet[i].GetAlpha(), DY_weight);
                //--------------------
                // Consider eta
                //--------------------
                // For Region |eta| < 1
                if (abs(v_thinjet[i].GetEta()) < 1)
                {
                    // For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_difeta_lowMET[0]);
                    // For c jet
                    for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_difeta_lowMET[0]);
                    // For l jet
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_difeta_lowMET[0]);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_cut_difeta_lowMET[0]);
                        // For c jet
                        for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_cut_difeta_lowMET[0]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_cut_difeta_lowMET[0]);
                    }
                }
                // For Region 1 < |eta| < 2
                else if (abs(v_thinjet[i].GetEta()) > 1 && abs(v_thinjet[i].GetEta()) < 2)
                {
                    // For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_difeta_lowMET[1]);
                    // For c jet
                    for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_difeta_lowMET[1]);
                    // For l jet
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_difeta_lowMET[1]);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_cut_difeta_lowMET[1]);
                        // For c jet
                        for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_cut_difeta_lowMET[1]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_cut_difeta_lowMET[1]);
                    }
                }
                // For Region 2 < |eta| < 2.5
                else if (abs(v_thinjet[i].GetEta()) > 2 && abs(v_thinjet[i].GetEta()) < 2.5)
                {
                    // For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_difeta_lowMET[2]);
                    // For c jet
                    for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_difeta_lowMET[2]);
                    // For l jet
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_difeta_lowMET[2]);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_cut_difeta_lowMET[2]);
                        // For c jet
                        for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_cut_difeta_lowMET[2]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_cut_difeta_lowMET[2]);
                    }
                }
            }
        }
        else if (f_DY_met > 140)
        {
            for (size_t i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_alpha_highMET->Fill(v_thinjet[i].GetAlpha(), DY_weight);
                //--------------------
                // Consider eta
                //--------------------
                // For Region |eta| < 1
                if (abs(v_thinjet[i].GetEta()) < 1)
                {
                    // For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_difeta_highMET[0]);
                    // For c jet
                    for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_difeta_highMET[0]);
                    // For l jet
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_difeta_highMET[0]);

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
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_cut_difeta_highMET[0]);
                        // For c jet
                        for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_cut_difeta_highMET[0]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_cut_difeta_highMET[0]);
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
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_difeta_highMET[1]);
                    // For c jet
                    for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_difeta_highMET[1]);
                    // For l jet
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_difeta_highMET[1]);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_cut_difeta_highMET[1]);
                        // For c jet
                        for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_cut_difeta_highMET[1]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_cut_difeta_highMET[1]);
                    }
                }
                // For Region 2 < |eta| < 2.5
                else if (abs(v_thinjet[i].GetEta()) > 2 && abs(v_thinjet[i].GetEta()) < 2.5)
                {
                    // For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_difeta_highMET[2]);
                    // For c jet
                    for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_difeta_highMET[2]);
                    // For l jet
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_difeta_highMET[2]);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_bjet_cut_difeta_highMET[2]);
                        // For c jet
                        for_signalflavor_jet(4, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_cjet_cut_difeta_highMET[2]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), DY_weight, h_DY_nTrk_ljet_cut_difeta_highMET[2]);
                    }
                }
            }
        } // End of high MET
        
        /*
        if (f_DY_dileppt < 90)
        {
            for (size_t i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_alpha_lowdipt->Fill(v_thinjet[i].GetAlpha(), DY_weight);
            }
        }
        else if (f_DY_dileppt > 90)
        {
            for (size_t i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_alpha_highdipt->Fill(v_thinjet[i].GetAlpha(), DY_weight);
            }
        }
        */
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

    h_DY_alpha_lowMET->Write();
    h_DY_alpha_highMET->Write();

    h_DY_alpha_lowdipt->Write();
    h_DY_alpha_highdipt->Write();

    outfile->Close();

    // cout << getWeight(file) << endl;
    // cout << "TTTo2L2NuWeight = " << TTTo2L2NuWeight << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_DY_half();
    }
    else if (argc == 3)
    {
        ee_DY_half(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}