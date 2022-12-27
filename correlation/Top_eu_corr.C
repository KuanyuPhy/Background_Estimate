#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <string>
#include <TCanvas.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../lib/Cross_section.h"

using namespace std;

//-------------------
// Create New class
//-------------------
class ThinJet
{
private:
    float jetpt, jeteta, jetntrk;

public:
    ThinJet() {}
    ThinJet(const float &a, const float &b, const float &c) : jetpt(a), jeteta(b), jetntrk(c) {}

    Float_t GetPt() const { return jetpt; }
    Float_t GetEta() const { return jeteta; }
    Float_t GetNtrk() const { return jetntrk; }

    friend ostream &operator<<(ostream &out, const ThinJet &foo)
    {
        return out << foo.jetpt << " " << foo.jeteta << " " << foo.jetntrk << "" << endl;
    }
    // greater() is used for JetPT
    friend bool operator>(const ThinJet &a, const ThinJet &b)
    {
        return a.GetPt() > b.GetPt();
    }
};

TFile *TTTo2L2Nufile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTTo2L2Nu.root");
TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTWJetsToLNu.root");
TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTWJetsToQQ.root");
TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTZToQQ.root");
TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTZToLLNuNu.root");
TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_tW_antitop.root");
TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_tW_top.root");

TH1D *TTTo2L2Nu_sumevt = ((TH1D *)TTTo2L2Nufile->Get("Event_Variable/h_totevent"));
TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNufile->Get("Event_Variable/h_totevent"));
TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQfile->Get("Event_Variable/h_totevent"));
TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQfile->Get("Event_Variable/h_totevent"));
TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNufile->Get("Event_Variable/h_totevent"));
TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitopfile->Get("Event_Variable/h_totevent"));
TH1D *tW_top_sumevt = ((TH1D *)Top_tW_topfile->Get("Event_Variable/h_totevent"));

double TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
double TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
double TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
double TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
double TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
double tW_antitop_totevt = tW_antitop_sumevt->Integral();
double tW_top_totevt = tW_top_sumevt->Integral();

//---------------------
// Define Weight
//---------------------
double TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * ((GlobalConstants::TTTo2L2Nu) / (TTTo2L2Nu_totevt)) * 1000;
double ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000;
double ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000;
double TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000;
double TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000;
double TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000;
double TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000;

void Top_eu_corr()
{
    TH2D *h_Top_JetPT_ntrk = new TH2D("h_Top_JetPT_ntrk", "", 150, 0, 1500, 30., 0, 30.);
    h_Top_JetPT_ntrk->Sumw2();

    TH2D *h_Top_ntrk_JetPT = new TH2D("h_Top_ntrk_JetPT", "", 30., 0, 30., 150, 0, 1500);
    h_Top_ntrk_JetPT->Sumw2();

    TH2D *h_Top_JetPT_JetEta = new TH2D("h_Top_JetPT_JetEta", "", 150, 0., 1500., 30., -3., 3.);
    h_Top_JetPT_JetEta->Sumw2();

    TH2D *h_Top_ntrk_JetEta = new TH2D("h_Top_ntrk_JetEta", "", 30., 0., 30., 30., -3., 3.);
    h_Top_ntrk_JetEta->Sumw2();

    TH1D *h_Top_ntrk = new TH1D("h_Top_ntrk", "", 30., 0, 30.);
    h_Top_ntrk->Sumw2();

    TH1D *h_Top_JetPT = new TH1D("h_Top_JetPT", "", 150, 0, 1500);
    h_Top_JetPT->Sumw2();

    //-------------------------
    // Create TProfile
    //-------------------------
    TProfile *h_ntrk_prof = new TProfile("h_ntrk_prof", "profile track multiplicity", 30., 0, 30.);
    h_ntrk_prof->Sumw2();

    TProfile *h_JetPt_prof = new TProfile("h_JetPt_prof", "profile Jet Pt", 150, 0, 1500);
    h_JetPt_prof->Sumw2();

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

    float_t f_TTTo2L2Nu_dileppt;
    float_t f_ST_tW_top_dileppt;
    float_t f_ST_tW_antitop_dileppt;
    float_t f_TTWJetsToLNu_dileppt;
    float_t f_TTWJetsToQQ_dileppt;
    float_t f_TTZToQQ_dileppt;
    float_t f_TTZToLLNuNu_dileppt;

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

    vector<float> *v_TTTo2L2Nu_nTrack = new vector<float>();
    vector<float> *v_ST_tW_top_nTrack = new vector<float>();
    vector<float> *v_ST_tW_antitop_nTrack = new vector<float>();
    vector<float> *v_TTWJetsToLNu_nTrack = new vector<float>();
    vector<float> *v_TTWJetsToQQ_nTrack = new vector<float>();
    vector<float> *v_TTZToQQ_nTrack = new vector<float>();
    vector<float> *v_TTZToLLNuNu_nTrack = new vector<float>();

    v_TTTo2L2Nu_nTrack->clear();
    v_ST_tW_top_nTrack->clear();
    v_ST_tW_antitop_nTrack->clear();
    v_TTWJetsToLNu_nTrack->clear();
    v_TTWJetsToQQ_nTrack->clear();
    v_TTZToQQ_nTrack->clear();
    v_TTZToLLNuNu_nTrack->clear();

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

    //----------------------
    // Alias some cut
    //----------------------
    double METcut = 130.;

    double DilepPTcut = 60.;

    TTree *T_TTTo2L2Nu_tree;
    TTTo2L2Nufile->GetObject("T_tree", T_TTTo2L2Nu_tree);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_weight", &I_TTTo2L2Nu_weight);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_N_Tracks", &v_TTTo2L2Nu_nTrack);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_Met", &f_ST_tW_top_met);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_dileptonPT", &f_ST_tW_top_dileppt);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetPt", &v_TTTo2L2Nu_JetPT);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetEta", &v_TTTo2L2Nu_JetEta);
    for (int evt = 0; evt < T_TTTo2L2Nu_tree->GetEntries(); evt++)
    {
        T_TTTo2L2Nu_tree->GetEntry(evt);
        if (f_TTTo2L2Nu_met < METcut)
        {
            continue;
        }
        if (f_ST_tW_top_dileppt < DilepPTcut)
        {
            continue;
        }
        vector<ThinJet> v_thinjet;
        if (v_TTTo2L2Nu_nTrack->size() < 2)
        {
            continue;
        }
        for (size_t i = 0; i < v_TTTo2L2Nu_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_TTTo2L2Nu_JetPT)[i], (*v_TTTo2L2Nu_JetEta)[i], (*v_TTTo2L2Nu_nTrack)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        double TTTo2L2Nu_eventWeight = I_TTTo2L2Nu_weight * TTTo2L2NuWeight;
        for (size_t ijet = 0; ijet < 2; ijet++)
        {
            h_Top_JetPT_ntrk->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetNtrk(), TTTo2L2Nu_eventWeight);
            h_Top_ntrk_JetPT->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetPt(), TTTo2L2Nu_eventWeight);

            h_Top_JetPT_JetEta->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetEta(), TTTo2L2Nu_eventWeight);
            h_Top_ntrk_JetEta->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetEta(), TTTo2L2Nu_eventWeight);

            h_Top_JetPT->Fill(v_thinjet[ijet].GetPt(), TTTo2L2Nu_eventWeight);
            h_Top_ntrk->Fill(v_thinjet[ijet].GetNtrk(), TTTo2L2Nu_eventWeight);

            // For TProfile
            h_ntrk_prof->Fill(v_thinjet[ijet].GetNtrk(), TTTo2L2Nu_eventWeight);
            h_JetPt_prof->Fill(v_thinjet[ijet].GetPt(), TTTo2L2Nu_eventWeight);
        }
    }
    TTree *T_ST_tW_top_tree;
    TTTo2L2Nufile->GetObject("T_tree", T_ST_tW_top_tree);
    T_ST_tW_top_tree->SetBranchAddress("I_weight", &I_ST_tW_top_weight);
    T_ST_tW_top_tree->SetBranchAddress("v_N_Tracks", &v_ST_tW_top_nTrack);
    T_ST_tW_top_tree->SetBranchAddress("f_Met", &f_ST_tW_top_met);
    T_ST_tW_top_tree->SetBranchAddress("f_dileptonPT", &f_ST_tW_top_dileppt);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetPt", &v_ST_tW_top_JetPT);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetEta", &v_ST_tW_top_JetEta);
    for (int evt = 0; evt < T_ST_tW_top_tree->GetEntries(); evt++)
    {
        T_ST_tW_top_tree->GetEntry(evt);
        if (f_ST_tW_top_met < METcut)
        {
            continue;
        }
        if (f_ST_tW_top_dileppt < DilepPTcut)
        {
            continue;
        }
        vector<ThinJet> v_thinjet;
        if (v_ST_tW_top_nTrack->size() < 2)
        {
            continue;
        }
        for (size_t i = 0; i < v_ST_tW_top_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_ST_tW_top_JetPT)[i], (*v_ST_tW_top_JetEta)[i], (*v_ST_tW_top_nTrack)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());

        double ST_tW_top_eventWeight = I_ST_tW_top_weight * ST_tW_topWeight;
        for (size_t ijet = 0; ijet < 2; ijet++)
        {
            h_Top_JetPT_ntrk->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetNtrk(), ST_tW_top_eventWeight);
            h_Top_ntrk_JetPT->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetPt(), ST_tW_top_eventWeight);

            h_Top_JetPT_JetEta->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetEta(), ST_tW_top_eventWeight);
            h_Top_ntrk_JetEta->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetEta(), ST_tW_top_eventWeight);

            h_Top_JetPT->Fill(v_thinjet[ijet].GetPt(), ST_tW_top_eventWeight);
            h_Top_ntrk->Fill(v_thinjet[ijet].GetNtrk(), ST_tW_top_eventWeight);

            // For TProfile
            h_ntrk_prof->Fill(v_thinjet[ijet].GetNtrk(), ST_tW_top_eventWeight);
            h_JetPt_prof->Fill(v_thinjet[ijet].GetPt(), ST_tW_top_eventWeight);
        }
    }
    TTree *T_ST_tW_antitop_tree;
    Top_tW_antitopfile->GetObject("T_tree", T_ST_tW_antitop_tree);
    T_ST_tW_antitop_tree->SetBranchAddress("I_weight", &I_ST_tW_antitop_weight);
    T_ST_tW_antitop_tree->SetBranchAddress("v_N_Tracks", &v_ST_tW_antitop_nTrack);
    T_ST_tW_antitop_tree->SetBranchAddress("f_Met", &f_ST_tW_antitop_met);
    T_ST_tW_antitop_tree->SetBranchAddress("f_dileptonPT", &f_ST_tW_antitop_dileppt);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetPt", &v_ST_tW_antitop_JetPT);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetEta", &v_ST_tW_antitop_JetEta);
    for (int evt = 0; evt < T_ST_tW_antitop_tree->GetEntries(); evt++)
    {
        T_ST_tW_antitop_tree->GetEntry(evt);
        if (f_ST_tW_antitop_met < METcut)
        {
            continue;
        }
        if (f_ST_tW_antitop_dileppt < DilepPTcut)
        {
            continue;
        }
        vector<ThinJet> v_thinjet;
        if (v_ST_tW_antitop_nTrack->size() < 2)
        {
            continue;
        }
        for (size_t i = 0; i < v_ST_tW_antitop_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_ST_tW_antitop_JetPT)[i], (*v_ST_tW_antitop_JetEta)[i], (*v_ST_tW_antitop_nTrack)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        double ST_tW_antitop_eventWeight = I_ST_tW_antitop_weight * ST_tW_antitopWeight;
        for (size_t ijet = 0; ijet < 2; ijet++)
        {
            h_Top_JetPT_ntrk->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetNtrk(), ST_tW_antitop_eventWeight);
            h_Top_ntrk_JetPT->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetPt(), ST_tW_antitop_eventWeight);

            h_Top_JetPT_JetEta->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetEta(), ST_tW_antitop_eventWeight);
            h_Top_ntrk_JetEta->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetEta(), ST_tW_antitop_eventWeight);

            h_Top_JetPT->Fill(v_thinjet[ijet].GetPt(), ST_tW_antitop_eventWeight);
            h_Top_ntrk->Fill(v_thinjet[ijet].GetNtrk(), ST_tW_antitop_eventWeight);

            // For TProfile
            h_ntrk_prof->Fill(v_thinjet[ijet].GetNtrk(), ST_tW_antitop_eventWeight);
            h_JetPt_prof->Fill(v_thinjet[ijet].GetPt(), ST_tW_antitop_eventWeight);
        }
    }
    TTree *T_TTWJetsToLNu_tree;
    Top_TTWJetsToLNufile->GetObject("T_tree", T_TTWJetsToLNu_tree);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_weight", &I_TTWJetsToLNu_weight);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_N_Tracks", &v_TTWJetsToLNu_nTrack);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_dileptonPT", &f_TTWJetsToLNu_dileppt);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToLNu_JetPT);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToLNu_JetEta);
    for (int evt = 0; evt < T_TTWJetsToLNu_tree->GetEntries(); evt++)
    {
        T_TTWJetsToLNu_tree->GetEntry(evt);
        if (f_TTWJetsToLNu_met < METcut)
        {
            continue;
        }
        if (f_TTWJetsToLNu_dileppt < DilepPTcut)
        {
            continue;
        }
        vector<ThinJet> v_thinjet;
        if (v_TTWJetsToLNu_nTrack->size() < 2)
        {
            continue;
        }
        for (size_t i = 0; i < v_TTWJetsToLNu_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_TTWJetsToLNu_JetPT)[i], (*v_TTWJetsToLNu_JetEta)[i], (*v_TTWJetsToLNu_nTrack)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        double TTWJetsToLNu_eventWeight = I_TTWJetsToLNu_weight * TTWJetsToLNuWeight;
        for (size_t ijet = 0; ijet < 2; ijet++)
        {
            h_Top_JetPT_ntrk->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetNtrk(), TTWJetsToLNu_eventWeight);
            h_Top_ntrk_JetPT->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetPt(), TTWJetsToLNu_eventWeight);

            h_Top_JetPT_JetEta->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetEta(), TTWJetsToLNu_eventWeight);
            h_Top_ntrk_JetEta->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetEta(), TTWJetsToLNu_eventWeight);

            h_Top_JetPT->Fill(v_thinjet[ijet].GetPt(), TTWJetsToLNu_eventWeight);
            h_Top_ntrk->Fill(v_thinjet[ijet].GetNtrk(), TTWJetsToLNu_eventWeight);

            // For TProfile
            h_ntrk_prof->Fill(v_thinjet[ijet].GetNtrk(), TTWJetsToLNu_eventWeight);
            h_JetPt_prof->Fill(v_thinjet[ijet].GetPt(), TTWJetsToLNu_eventWeight);
        }
    }
    TTree *T_TTWJetsToQQ_tree;
    Top_TTWJetsToQQfile->GetObject("T_tree", T_TTWJetsToQQ_tree);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_weight", &I_TTWJetsToQQ_weight);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_N_Tracks", &v_TTWJetsToQQ_nTrack);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_dileptonPT", &f_TTWJetsToQQ_dileppt);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToQQ_JetPT);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToQQ_JetEta);
    for (int evt = 0; evt < T_TTWJetsToQQ_tree->GetEntries(); evt++)
    {
        T_TTWJetsToQQ_tree->GetEntry(evt);
        if (f_TTWJetsToQQ_met < METcut)
        {
            continue;
        }
        if (f_TTWJetsToQQ_dileppt < DilepPTcut)
        {
            continue;
        }
        vector<ThinJet> v_thinjet;
        if (v_TTWJetsToQQ_nTrack->size() < 2)
        {
            continue;
        }
        for (size_t i = 0; i < v_TTWJetsToQQ_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_TTWJetsToQQ_JetPT)[i], (*v_TTWJetsToQQ_JetEta)[i], (*v_TTWJetsToQQ_nTrack)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        double TTWJetsToQQ_eventWeight = I_TTWJetsToQQ_weight * TTWJetsToQQWeight;
        for (size_t ijet = 0; ijet < 2; ijet++)
        {
            h_Top_JetPT_ntrk->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetNtrk(), TTWJetsToQQ_eventWeight);
            h_Top_ntrk_JetPT->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetPt(), TTWJetsToQQ_eventWeight);

            h_Top_JetPT_JetEta->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetEta(), TTWJetsToQQ_eventWeight);
            h_Top_ntrk_JetEta->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetEta(), TTWJetsToQQ_eventWeight);

            h_Top_JetPT->Fill(v_thinjet[ijet].GetPt(), TTWJetsToQQ_eventWeight);
            h_Top_ntrk->Fill(v_thinjet[ijet].GetNtrk(), TTWJetsToQQ_eventWeight);

            // For TProfile
            h_ntrk_prof->Fill(v_thinjet[ijet].GetNtrk(), TTWJetsToQQ_eventWeight);
            h_JetPt_prof->Fill(v_thinjet[ijet].GetPt(), TTWJetsToQQ_eventWeight);
        }
    }
    TTree *T_TTZToQQ_tree;
    Top_TTZToQQfile->GetObject("T_tree", T_TTZToQQ_tree);
    T_TTZToQQ_tree->SetBranchAddress("I_weight", &I_TTZToQQ_weight);
    T_TTZToQQ_tree->SetBranchAddress("v_N_Tracks", &v_TTZToQQ_nTrack);
    T_TTZToQQ_tree->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_TTZToQQ_tree->SetBranchAddress("f_dileptonPT", &f_TTZToQQ_dileppt);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetPt", &v_TTZToQQ_JetPT);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetEta", &v_TTZToQQ_JetEta);
    for (int evt = 0; evt < T_TTZToQQ_tree->GetEntries(); evt++)
    {
        T_TTZToQQ_tree->GetEntry(evt);
        if (f_TTZToQQ_met < METcut)
        {
            continue;
        }
        if (f_TTZToQQ_dileppt < DilepPTcut)
        {
            continue;
        }
        vector<ThinJet> v_thinjet;
        if (v_TTZToQQ_nTrack->size() < 2)
        {
            continue;
        }
        for (size_t i = 0; i < v_TTZToQQ_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_TTZToQQ_JetPT)[i], (*v_TTZToQQ_JetEta)[i], (*v_TTZToQQ_nTrack)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        double TTZToQQ_eventWeight = I_TTZToQQ_weight * TTZToQQWeight;
        for (size_t ijet = 0; ijet < 2; ijet++)
        {
            h_Top_JetPT_ntrk->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetNtrk(), TTZToQQ_eventWeight);
            h_Top_ntrk_JetPT->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetPt(), TTZToQQ_eventWeight);

            h_Top_JetPT_JetEta->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetEta(), TTZToQQ_eventWeight);
            h_Top_ntrk_JetEta->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetEta(), TTZToQQ_eventWeight);

            h_Top_JetPT->Fill(v_thinjet[ijet].GetPt(), TTZToQQ_eventWeight);
            h_Top_ntrk->Fill(v_thinjet[ijet].GetNtrk(), TTZToQQ_eventWeight);

            // For TProfile
            h_ntrk_prof->Fill(v_thinjet[ijet].GetNtrk(), TTZToQQ_eventWeight);
            h_JetPt_prof->Fill(v_thinjet[ijet].GetPt(), TTZToQQ_eventWeight);
        }
    }
    TTree *T_TTZToLLNuNu_tree;
    Top_TTZToLLNuNufile->GetObject("T_tree", T_TTZToLLNuNu_tree);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_weight", &I_TTZToLLNuNu_weight);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_N_Tracks", &v_TTZToLLNuNu_nTrack);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_dileptonPT", &f_TTZToLLNuNu_dileppt);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetPt", &v_TTZToLLNuNu_JetPT);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetEta", &v_TTZToLLNuNu_JetEta);
    for (int evt = 0; evt < T_TTZToLLNuNu_tree->GetEntries(); evt++)
    {
        T_TTZToLLNuNu_tree->GetEntry(evt);
        if (f_TTZToLLNuNu_met < METcut)
        {
            continue;
        }
        if (f_TTZToLLNuNu_dileppt < DilepPTcut)
        {
            continue;
        }
        vector<ThinJet> v_thinjet;
        if (v_TTZToLLNuNu_nTrack->size() < 2)
        {
            continue;
        }
        for (size_t i = 0; i < v_TTZToLLNuNu_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_TTZToLLNuNu_JetPT)[i], (*v_TTZToLLNuNu_JetEta)[i], (*v_TTZToLLNuNu_nTrack)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        double TTZToLLNuNu_eventWeight = I_TTZToLLNuNu_weight * TTZToLLNuNuWeight;
        for (size_t ijet = 0; ijet < 2; ijet++)
        {
            h_Top_JetPT_ntrk->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetNtrk(), TTZToLLNuNu_eventWeight);
            h_Top_ntrk_JetPT->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetPt(), TTZToLLNuNu_eventWeight);

            h_Top_JetPT_JetEta->Fill(v_thinjet[ijet].GetPt(), v_thinjet[ijet].GetEta(), TTZToLLNuNu_eventWeight);
            h_Top_ntrk_JetEta->Fill(v_thinjet[ijet].GetNtrk(), v_thinjet[ijet].GetEta(), TTZToLLNuNu_eventWeight);

            h_Top_JetPT->Fill(v_thinjet[ijet].GetPt(), TTZToLLNuNu_eventWeight);
            h_Top_ntrk->Fill(v_thinjet[ijet].GetNtrk(), TTZToLLNuNu_eventWeight);

            // For TProfile
            h_ntrk_prof->Fill(v_thinjet[ijet].GetNtrk(), TTZToLLNuNu_eventWeight);
            h_JetPt_prof->Fill(v_thinjet[ijet].GetPt(), TTZToLLNuNu_eventWeight);
        }
    }
    h_Top_JetPT_ntrk->SetTitle("Top to emu (Jet PT vs Track multiplicity)");
    h_Top_JetPT_JetEta->SetTitle("Top to emu (Jet PT vs Jet #eta)");
    h_Top_ntrk_JetEta->SetTitle("Top to emu (Track multiplicity vs Jet #eta)");

    h_Top_JetPT_ntrk->GetXaxis()->SetTitle("Jet PT");
    h_Top_JetPT_ntrk->GetYaxis()->SetTitle("Track multiplicity");

    h_Top_JetPT_JetEta->GetXaxis()->SetTitle("Jet PT");
    h_Top_JetPT_JetEta->GetYaxis()->SetTitle("Jet #eta");

    h_Top_ntrk_JetEta->GetXaxis()->SetTitle("Track multiplicity");
    h_Top_ntrk_JetEta->GetYaxis()->SetTitle("Jet #eta");

    h_Top_JetPT_ntrk->Draw("colz");
    gStyle->SetOptStat(0);
    // gPad->SetLogx();
    // h_ntrk_prof->Draw();
    double corr_JetPt_ntrk = h_Top_JetPT_ntrk->GetCorrelationFactor();
    double corr_ntrk_JetPt = h_Top_ntrk_JetPT->GetCorrelationFactor();
    double corr_JetPt_JetEta = h_Top_JetPT_JetEta->GetCorrelationFactor();
    double corr_ntrk_JetEta = h_Top_ntrk_JetEta->GetCorrelationFactor();

    cout << "correlation between Jet PT and ntrk = " << corr_JetPt_ntrk << endl;
    cout << "correlation between ntrk and Jet PT = " << corr_ntrk_JetPt << endl;
    cout << "correlation between Jet PT and JetEta = " << corr_JetPt_JetEta << endl;
    cout << "correlation between ntrk and JetEta = " << corr_ntrk_JetEta << endl;
}