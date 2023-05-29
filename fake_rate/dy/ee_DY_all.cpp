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
#include <TLegend.h>
#include "./../../lib/kuan_ana_utils.h"
using namespace std;

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

void ee_DY_all(TString outputfile = "./output/tmp.root")
{

    MergeBFiles merge_bfiles;
    MergeWeight merge_weight(&merge_bfiles);

    const Int_t NBINS = 16;
    Double_t edges[NBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13, 14, 15., 25., 40.};

    const Int_t NJet_Nbins = 10;
    Double_t NJet_edges[NJet_Nbins + 1] = {0., 30., 60., 90., 120., 150., 210., 270., 350., 450., 1500.};

    const Int_t JetEta_Nbins = 30.;
    Double_t JetEta_low_bound = -3.;
    Double_t JetEta_upper_bound = 3.;

    // TH1D *h_DY_nTrk_jet_lowDilepPt = new TH1D("h_DY_nTrk_jet_lowDilepPt", "", );
    TH1D *h_DY_nTrk_jet_lowDilepPt = new TH1D("h_DY_nTrk_jet_lowDilepPt", "", NBINS, edges);
    h_DY_nTrk_jet_lowDilepPt->Sumw2();
    TH1D *h_DY_nTrk_jet_cut_lowDilepPt = new TH1D("h_DY_nTrk_jet_cut_lowDilepPt", "", NBINS, edges);
    h_DY_nTrk_jet_cut_lowDilepPt->Sumw2();

    /*For single flavor*/
    TH1D *h_DY_nTrk_bjet_lowDilepPt = new TH1D("h_DY_nTrk_bjet_lowDilepPt", "", NBINS, edges);
    h_DY_nTrk_bjet_lowDilepPt->Sumw2();
    TH1D *h_DY_nTrk_bjet_cut_lowDilepPt = new TH1D("h_DY_nTrk_bjet_cut_lowDilepPt", "", NBINS, edges);
    h_DY_nTrk_bjet_cut_lowDilepPt->Sumw2();

    TH1D *h_DY_nTrk_ljet_lowDilepPt = new TH1D("h_DY_nTrk_ljet_lowDilepPt", "", NBINS, edges);
    h_DY_nTrk_ljet_lowDilepPt->Sumw2();
    TH1D *h_DY_nTrk_ljet_cut_lowDilepPt = new TH1D("h_DY_nTrk_ljet_cut_lowDilepPt", "", NBINS, edges);
    h_DY_nTrk_ljet_cut_lowDilepPt->Sumw2();

    TH1D *h_DY_nTrk_jet_highDilepPt = new TH1D("h_DY_nTrk_jet_highDilepPt", "", NBINS, edges);
    h_DY_nTrk_jet_highDilepPt->Sumw2();
    TH1D *h_DY_nTrk_jet_cut_highDilepPt = new TH1D("h_DY_nTrk_jet_cut_highDilepPt", "", NBINS, edges);
    h_DY_nTrk_jet_cut_highDilepPt->Sumw2();

    /*For single flavor*/
    TH1D *h_DY_nTrk_bjet_highDilepPt = new TH1D("h_DY_nTrk_bjet_highDilepPt", "", NBINS, edges);
    h_DY_nTrk_bjet_highDilepPt->Sumw2();
    TH1D *h_DY_nTrk_bjet_cut_highDilepPt = new TH1D("h_DY_nTrk_bjet_cut_highDilepPt", "", NBINS, edges);
    h_DY_nTrk_bjet_cut_highDilepPt->Sumw2();

    TH1D *h_DY_nTrk_ljet_highDilepPt = new TH1D("h_DY_nTrk_ljet_highDilepPt", "", NBINS, edges);
    h_DY_nTrk_ljet_highDilepPt->Sumw2();
    TH1D *h_DY_nTrk_ljet_cut_highDilepPt = new TH1D("h_DY_nTrk_ljet_cut_highDilepPt", "", NBINS, edges);
    h_DY_nTrk_ljet_cut_highDilepPt->Sumw2();

    // 2. JetPT
    TH1D *h_DY_JetPt_lowDilepPt = new TH1D("h_DY_JetPt_lowDilepPt", "", NJet_Nbins, NJet_edges);
    h_DY_JetPt_lowDilepPt->Sumw2();
    TH1D *h_DY_JetPt_cut_lowDilepPt = new TH1D("h_DY_JetPt_cut_lowDilepPt", "", NJet_Nbins, NJet_edges);
    h_DY_JetPt_cut_lowDilepPt->Sumw2();

    TH1D *h_DY_JetPt_highDilepPt = new TH1D("h_DY_JetPt_highDilepPt", "", NJet_Nbins, NJet_edges);
    h_DY_JetPt_highDilepPt->Sumw2();
    TH1D *h_DY_JetPt_cut_highDilepPt = new TH1D("h_DY_JetPt_cut_highDilepPt", "", NJet_Nbins, NJet_edges);
    h_DY_JetPt_cut_highDilepPt->Sumw2();

    // 3. JetEta
    TH1D *h_DY_JetEta_lowDilepPt = new TH1D("h_DY_JetEta_lowDilepPt", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_DY_JetEta_lowDilepPt->Sumw2();
    TH1D *h_DY_JetEta_cut_lowDilepPt = new TH1D("h_DY_JetEta_cut_lowDilepPt", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_DY_JetEta_cut_lowDilepPt->Sumw2();

    TH1D *h_DY_JetEta_highDilepPt = new TH1D("h_DY_JetEta_highDilepPt", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_DY_JetEta_highDilepPt->Sumw2();
    TH1D *h_DY_JetEta_cut_highDilepPt = new TH1D("h_DY_JetEta_cut_highDilepPt", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_DY_JetEta_cut_highDilepPt->Sumw2();

    float_t HT;

    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    Int_t I_ht0_nJets, I_ht70_nJets, I_ht100_nJets, I_ht200_nJets, I_ht400_nJets, I_ht600_nJets,
        I_ht800_nJets, I_ht1200_nJets, I_ht2500_nJets;

    float_t f_ht0_dileppt, f_ht70_dileppt, f_ht100_dileppt, f_ht200_dileppt, f_ht400_dileppt, f_ht600_dileppt, f_ht800_dileppt,
        f_ht1200_dileppt, f_ht2500_dileppt;

    vector<float> *v_ht0_nTrack = new vector<float>();
    vector<float> *v_ht70_nTrack = new vector<float>();
    vector<float> *v_ht100_nTrack = new vector<float>();
    vector<float> *v_ht200_nTrack = new vector<float>();
    vector<float> *v_ht400_nTrack = new vector<float>();
    vector<float> *v_ht600_nTrack = new vector<float>();
    vector<float> *v_ht800_nTrack = new vector<float>();
    vector<float> *v_ht1200_nTrack = new vector<float>();
    vector<float> *v_ht2500_nTrack = new vector<float>();

    v_ht0_nTrack->clear();
    v_ht70_nTrack->clear();
    v_ht100_nTrack->clear();
    v_ht200_nTrack->clear();
    v_ht400_nTrack->clear();
    v_ht600_nTrack->clear();
    v_ht800_nTrack->clear();
    v_ht1200_nTrack->clear();
    v_ht2500_nTrack->clear();

    vector<float> *v_ht0_Jethadronflavor = new vector<float>();
    vector<float> *v_ht70_Jethadronflavor = new vector<float>();
    vector<float> *v_ht100_Jethadronflavor = new vector<float>();
    vector<float> *v_ht200_Jethadronflavor = new vector<float>();
    vector<float> *v_ht400_Jethadronflavor = new vector<float>();
    vector<float> *v_ht600_Jethadronflavor = new vector<float>();
    vector<float> *v_ht800_Jethadronflavor = new vector<float>();
    vector<float> *v_ht1200_Jethadronflavor = new vector<float>();
    vector<float> *v_ht2500_Jethadronflavor = new vector<float>();

    v_ht0_Jethadronflavor->clear();
    v_ht70_Jethadronflavor->clear();
    v_ht100_Jethadronflavor->clear();
    v_ht200_Jethadronflavor->clear();
    v_ht400_Jethadronflavor->clear();
    v_ht600_Jethadronflavor->clear();
    v_ht800_Jethadronflavor->clear();
    v_ht1200_Jethadronflavor->clear();
    v_ht2500_Jethadronflavor->clear();

    vector<float> *v_ht0_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht70_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht100_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht200_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht400_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht600_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht800_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht1200_Jetpartonflavor = new vector<float>();
    vector<float> *v_ht2500_Jetpartonflavor = new vector<float>();

    v_ht0_Jetpartonflavor->clear();
    v_ht70_Jetpartonflavor->clear();
    v_ht100_Jetpartonflavor->clear();
    v_ht200_Jetpartonflavor->clear();
    v_ht400_Jetpartonflavor->clear();
    v_ht600_Jetpartonflavor->clear();
    v_ht800_Jetpartonflavor->clear();
    v_ht1200_Jetpartonflavor->clear();
    v_ht2500_Jetpartonflavor->clear();

    vector<float> *v_ht0_JetPT = new vector<float>();
    vector<float> *v_ht70_JetPT = new vector<float>();
    vector<float> *v_ht100_JetPT = new vector<float>();
    vector<float> *v_ht200_JetPT = new vector<float>();
    vector<float> *v_ht400_JetPT = new vector<float>();
    vector<float> *v_ht600_JetPT = new vector<float>();
    vector<float> *v_ht800_JetPT = new vector<float>();
    vector<float> *v_ht1200_JetPT = new vector<float>();
    vector<float> *v_ht2500_JetPT = new vector<float>();

    v_ht0_JetPT->clear();
    v_ht70_JetPT->clear();
    v_ht100_JetPT->clear();
    v_ht200_JetPT->clear();
    v_ht400_JetPT->clear();
    v_ht600_JetPT->clear();
    v_ht800_JetPT->clear();
    v_ht1200_JetPT->clear();
    v_ht2500_JetPT->clear();

    vector<float> *v_ht0_JetEta = new vector<float>();
    vector<float> *v_ht70_JetEta = new vector<float>();
    vector<float> *v_ht100_JetEta = new vector<float>();
    vector<float> *v_ht200_JetEta = new vector<float>();
    vector<float> *v_ht400_JetEta = new vector<float>();
    vector<float> *v_ht600_JetEta = new vector<float>();
    vector<float> *v_ht800_JetEta = new vector<float>();
    vector<float> *v_ht1200_JetEta = new vector<float>();
    vector<float> *v_ht2500_JetEta = new vector<float>();

    v_ht0_JetEta->clear();
    v_ht70_JetEta->clear();
    v_ht100_JetEta->clear();
    v_ht200_JetEta->clear();
    v_ht400_JetEta->clear();
    v_ht600_JetEta->clear();
    v_ht800_JetEta->clear();
    v_ht1200_JetEta->clear();
    v_ht2500_JetEta->clear();

    vector<float> *v_ht0_alpha = new vector<float>();
    vector<float> *v_ht70_alpha = new vector<float>();
    vector<float> *v_ht100_alpha = new vector<float>();
    vector<float> *v_ht200_alpha = new vector<float>();
    vector<float> *v_ht400_alpha = new vector<float>();
    vector<float> *v_ht600_alpha = new vector<float>();
    vector<float> *v_ht800_alpha = new vector<float>();
    vector<float> *v_ht1200_alpha = new vector<float>();
    vector<float> *v_ht2500_alpha = new vector<float>();

    v_ht0_alpha->clear();
    v_ht70_alpha->clear();
    v_ht100_alpha->clear();
    v_ht200_alpha->clear();
    v_ht400_alpha->clear();
    v_ht600_alpha->clear();
    v_ht800_alpha->clear();
    v_ht1200_alpha->clear();
    v_ht2500_alpha->clear();

    double METcut = 140.;
    double DileptonPT_cut = 60.;

    TTree *T_DYht0_tree;
    merge_bfiles.ee_DYincli->GetObject("T_tree", T_DYht0_tree);
    T_DYht0_tree->SetBranchAddress("I_weight", &I_ht0_weight);
    T_DYht0_tree->SetBranchAddress("f_HT", &HT);
    T_DYht0_tree->SetBranchAddress("I_nJets", &I_ht0_nJets);
    T_DYht0_tree->SetBranchAddress("v_N_Tracks", &v_ht0_nTrack);
    T_DYht0_tree->SetBranchAddress("f_Met", &f_ht0_Met);
    T_DYht0_tree->SetBranchAddress("f_dileptonPT", &f_ht0_dileppt);
    T_DYht0_tree->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    T_DYht0_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    T_DYht0_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ht0_Jetpartonflavor);
    T_DYht0_tree->SetBranchAddress("v_fakeJetPt", &v_ht0_JetPT);
    T_DYht0_tree->SetBranchAddress("v_fakeJetEta", &v_ht0_JetEta);
    for (int evt = 0; evt < T_DYht0_tree->GetEntries(); evt++)
    {
        T_DYht0_tree->GetEntry(evt);
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;
        vector<ThinJet> v_thinjet;

        if (v_ht0_nTrack->size() < 2)
        {
            continue;
        }

        for (size_t ijet = 0; ijet < v_ht0_nTrack->size(); ijet++)
        {
            v_thinjet.push_back(ThinJet((*v_ht0_Jethadronflavor)[ijet], (*v_ht0_JetPT)[ijet], (*v_ht0_JetEta)[ijet], (*v_ht0_alpha)[ijet], (*v_ht0_nTrack)[ijet]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        if (f_ht0_Met <= METcut)
        {
            continue;
        }
        if (f_ht0_dileppt < DileptonPT_cut)
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_jet_lowDilepPt);
                ee_for_inclusive_sample(HT, v_thinjet[i].GetPt(), merge_weight, I_ht0_weight, h_DY_JetPt_lowDilepPt);
                ee_for_inclusive_sample(HT, v_thinjet[i].GetEta(), merge_weight, I_ht0_weight, h_DY_JetEta_lowDilepPt);

                if (v_thinjet[i].GetFlavor() == 5)
                {
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_bjet_lowDilepPt);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_ljet_lowDilepPt);
                }

                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_jet_cut_lowDilepPt);
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetPt(), merge_weight, I_ht0_weight, h_DY_JetPt_cut_lowDilepPt);
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetEta(), merge_weight, I_ht0_weight, h_DY_JetEta_cut_lowDilepPt);

                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_bjet_cut_lowDilepPt);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_ljet_cut_lowDilepPt);
                    }
                }
            }
        } // low dilepton scope
        else
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_jet_highDilepPt);
                ee_for_inclusive_sample(HT, v_thinjet[i].GetPt(), merge_weight, I_ht0_weight, h_DY_JetPt_highDilepPt);
                ee_for_inclusive_sample(HT, v_thinjet[i].GetEta(), merge_weight, I_ht0_weight, h_DY_JetEta_highDilepPt);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_bjet_highDilepPt);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_ljet_highDilepPt);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_jet_cut_highDilepPt);
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetPt(), merge_weight, I_ht0_weight, h_DY_JetPt_cut_highDilepPt);
                    ee_for_inclusive_sample(HT, v_thinjet[i].GetEta(), merge_weight, I_ht0_weight, h_DY_JetEta_cut_highDilepPt);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_bjet_cut_highDilepPt);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        ee_for_inclusive_sample(HT, v_thinjet[i].GetNtrk(), merge_weight, I_ht0_weight, h_DY_nTrk_ljet_cut_highDilepPt);
                    }
                }
            }
        } // high dilepton scope
    }     // End of inclusive Event loop
    TTree *T_DYht100_tree;
    merge_bfiles.ee_DYHT100->GetObject("T_tree", T_DYht100_tree);
    T_DYht100_tree->SetBranchAddress("I_weight", &I_ht100_weight);
    T_DYht100_tree->SetBranchAddress("I_nJets", &I_ht100_nJets);
    T_DYht100_tree->SetBranchAddress("v_N_Tracks", &v_ht100_nTrack);
    T_DYht100_tree->SetBranchAddress("f_Met", &f_ht100_Met);
    T_DYht100_tree->SetBranchAddress("f_dileptonPT", &f_ht100_dileppt);
    T_DYht100_tree->SetBranchAddress("v_fakealpha", &v_ht100_alpha);
    T_DYht100_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ht100_Jethadronflavor);
    T_DYht100_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ht100_Jetpartonflavor);
    T_DYht100_tree->SetBranchAddress("v_fakeJetPt", &v_ht100_JetPT);
    T_DYht100_tree->SetBranchAddress("v_fakeJetEta", &v_ht100_JetEta);
    for (int evt = 0; evt < T_DYht100_tree->GetEntries(); evt++)
    {
        T_DYht100_tree->GetEntry(evt);
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;
        vector<ThinJet> v_thinjet;

        if (v_ht100_nTrack->size() < 2)
        {
            continue;
        }

        for (size_t ijet = 0; ijet < v_ht100_nTrack->size(); ijet++)
        {
            v_thinjet.push_back(ThinJet((*v_ht100_Jethadronflavor)[ijet], (*v_ht100_JetPT)[ijet], (*v_ht100_JetEta)[ijet], (*v_ht100_alpha)[ijet], (*v_ht100_nTrack)[ijet]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        if (f_ht100_Met <= METcut)
        {
            continue;
        }
        if (f_ht100_dileppt < DileptonPT_cut)
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                h_DY_JetPt_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht100_weight * merge_weight.ee_HT100Weight);
                h_DY_JetEta_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht100_weight * merge_weight.ee_HT100Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    h_DY_JetPt_cut_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    h_DY_JetEta_cut_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    }
                }
            }
        } // low dilepton scope
        else
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                h_DY_JetPt_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht100_weight * merge_weight.ee_HT100Weight);
                h_DY_JetEta_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht100_weight * merge_weight.ee_HT100Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    h_DY_JetPt_cut_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    h_DY_JetEta_cut_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht100_weight * merge_weight.ee_HT100Weight);
                    }
                }
            }
        } // high dilepton scope
    }
    TTree *T_DYht200_tree;
    merge_bfiles.ee_DYHT200->GetObject("T_tree", T_DYht200_tree);
    T_DYht200_tree->SetBranchAddress("I_weight", &I_ht200_weight);
    T_DYht200_tree->SetBranchAddress("I_nJets", &I_ht200_nJets);
    T_DYht200_tree->SetBranchAddress("v_N_Tracks", &v_ht200_nTrack);
    T_DYht200_tree->SetBranchAddress("f_Met", &f_ht200_Met);
    T_DYht200_tree->SetBranchAddress("f_dileptonPT", &f_ht200_dileppt);
    T_DYht200_tree->SetBranchAddress("v_fakealpha", &v_ht200_alpha);
    T_DYht200_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ht200_Jethadronflavor);
    T_DYht200_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ht200_Jetpartonflavor);
    T_DYht200_tree->SetBranchAddress("v_fakeJetPt", &v_ht200_JetPT);
    T_DYht200_tree->SetBranchAddress("v_fakeJetEta", &v_ht200_JetEta);
    for (int evt = 0; evt < T_DYht200_tree->GetEntries(); evt++)
    {
        T_DYht200_tree->GetEntry(evt);
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;
        vector<ThinJet> v_thinjet;

        if (v_ht200_nTrack->size() < 2)
        {
            continue;
        }

        for (size_t ijet = 0; ijet < v_ht200_nTrack->size(); ijet++)
        {
            v_thinjet.push_back(ThinJet((*v_ht200_Jethadronflavor)[ijet], (*v_ht200_JetPT)[ijet], (*v_ht200_JetEta)[ijet], (*v_ht200_alpha)[ijet], (*v_ht200_nTrack)[ijet]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        if (f_ht200_Met <= METcut)
        {
            continue;
        }
        if (f_ht200_dileppt < DileptonPT_cut)
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                h_DY_JetPt_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht200_weight * merge_weight.ee_HT200Weight);
                h_DY_JetEta_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht200_weight * merge_weight.ee_HT200Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                }

                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    h_DY_JetPt_cut_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    h_DY_JetEta_cut_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    }
                }
            }
        } // low dilepton scope
        else
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                h_DY_JetPt_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht200_weight * merge_weight.ee_HT200Weight);
                h_DY_JetEta_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht200_weight * merge_weight.ee_HT200Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    h_DY_JetPt_cut_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    h_DY_JetEta_cut_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht200_weight * merge_weight.ee_HT200Weight);
                    }
                }
            }
        } // high dilepton scope
    }
    TTree *T_DYht400_tree;
    merge_bfiles.ee_DYHT400->GetObject("T_tree", T_DYht400_tree);
    T_DYht400_tree->SetBranchAddress("I_weight", &I_ht400_weight);
    T_DYht400_tree->SetBranchAddress("I_nJets", &I_ht400_nJets);
    T_DYht400_tree->SetBranchAddress("v_N_Tracks", &v_ht400_nTrack);
    T_DYht400_tree->SetBranchAddress("f_Met", &f_ht400_Met);
    T_DYht400_tree->SetBranchAddress("f_dileptonPT", &f_ht400_dileppt);
    T_DYht400_tree->SetBranchAddress("v_fakealpha", &v_ht400_alpha);
    T_DYht400_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ht400_Jethadronflavor);
    T_DYht400_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ht400_Jetpartonflavor);
    T_DYht400_tree->SetBranchAddress("v_fakeJetPt", &v_ht400_JetPT);
    T_DYht400_tree->SetBranchAddress("v_fakeJetEta", &v_ht400_JetEta);
    for (int evt = 0; evt < T_DYht400_tree->GetEntries(); evt++)
    {
        T_DYht400_tree->GetEntry(evt);
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;
        vector<ThinJet> v_thinjet;

        if (v_ht400_nTrack->size() < 2)
        {
            continue;
        }

        for (size_t ijet = 0; ijet < v_ht400_nTrack->size(); ijet++)
        {
            v_thinjet.push_back(ThinJet((*v_ht400_Jethadronflavor)[ijet], (*v_ht400_JetPT)[ijet], (*v_ht400_JetEta)[ijet], (*v_ht400_alpha)[ijet], (*v_ht400_nTrack)[ijet]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        if (f_ht400_Met <= METcut)
        {
            continue;
        }
        if (f_ht400_dileppt < DileptonPT_cut)
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                h_DY_JetPt_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht400_weight * merge_weight.ee_HT400Weight);
                h_DY_JetEta_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht400_weight * merge_weight.ee_HT400Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    h_DY_JetPt_cut_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    h_DY_JetEta_cut_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    }
                }
            }
        } // low dilepton scope
        else
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                h_DY_JetPt_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht400_weight * merge_weight.ee_HT400Weight);
                h_DY_JetEta_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht400_weight * merge_weight.ee_HT400Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    h_DY_JetPt_cut_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    h_DY_JetEta_cut_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht400_weight * merge_weight.ee_HT400Weight);
                    }
                }
            }
        } // high dilepton scope
    }
    TTree *T_DYht600_tree;
    merge_bfiles.ee_DYHT600->GetObject("T_tree", T_DYht600_tree);
    T_DYht600_tree->SetBranchAddress("I_weight", &I_ht600_weight);
    T_DYht600_tree->SetBranchAddress("I_nJets", &I_ht600_nJets);
    T_DYht600_tree->SetBranchAddress("v_N_Tracks", &v_ht600_nTrack);
    T_DYht600_tree->SetBranchAddress("f_Met", &f_ht600_Met);
    T_DYht600_tree->SetBranchAddress("f_dileptonPT", &f_ht600_dileppt);
    T_DYht600_tree->SetBranchAddress("v_fakealpha", &v_ht600_alpha);
    T_DYht600_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ht600_Jethadronflavor);
    T_DYht600_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ht600_Jetpartonflavor);
    T_DYht600_tree->SetBranchAddress("v_fakeJetPt", &v_ht600_JetPT);
    T_DYht600_tree->SetBranchAddress("v_fakeJetEta", &v_ht600_JetEta);
    for (int evt = 0; evt < T_DYht600_tree->GetEntries(); evt++)
    {
        T_DYht600_tree->GetEntry(evt);
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;
        vector<ThinJet> v_thinjet;

        if (v_ht600_nTrack->size() < 2)
        {
            continue;
        }

        for (size_t ijet = 0; ijet < v_ht600_nTrack->size(); ijet++)
        {
            v_thinjet.push_back(ThinJet((*v_ht600_Jethadronflavor)[ijet], (*v_ht600_JetPT)[ijet], (*v_ht600_JetEta)[ijet], (*v_ht600_alpha)[ijet], (*v_ht600_nTrack)[ijet]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        if (f_ht600_Met <= METcut)
        {
            continue;
        }
        if (f_ht600_dileppt < DileptonPT_cut)
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                h_DY_JetPt_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht600_weight * merge_weight.ee_HT600Weight);
                h_DY_JetEta_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht600_weight * merge_weight.ee_HT600Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    h_DY_JetPt_cut_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    h_DY_JetEta_cut_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    }
                }
            }
        } // low dilepton scope
        else
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                h_DY_JetPt_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht600_weight * merge_weight.ee_HT600Weight);
                h_DY_JetEta_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht600_weight * merge_weight.ee_HT600Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    h_DY_JetPt_cut_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    h_DY_JetEta_cut_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht600_weight * merge_weight.ee_HT600Weight);
                    }
                }
            }
        } // high dilepton scope
    }
    TTree *T_DYht800_tree;
    merge_bfiles.ee_DYHT800->GetObject("T_tree", T_DYht800_tree);
    T_DYht800_tree->SetBranchAddress("I_weight", &I_ht800_weight);
    T_DYht800_tree->SetBranchAddress("I_nJets", &I_ht800_nJets);
    T_DYht800_tree->SetBranchAddress("v_N_Tracks", &v_ht800_nTrack);
    T_DYht800_tree->SetBranchAddress("f_Met", &f_ht800_Met);
    T_DYht800_tree->SetBranchAddress("f_dileptonPT", &f_ht800_dileppt);
    T_DYht800_tree->SetBranchAddress("v_fakealpha", &v_ht800_alpha);
    T_DYht800_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ht800_Jethadronflavor);
    T_DYht800_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ht800_Jetpartonflavor);
    T_DYht800_tree->SetBranchAddress("v_fakeJetPt", &v_ht800_JetPT);
    T_DYht800_tree->SetBranchAddress("v_fakeJetEta", &v_ht800_JetEta);
    for (int evt = 0; evt < T_DYht800_tree->GetEntries(); evt++)
    {
        T_DYht800_tree->GetEntry(evt);
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;
        vector<ThinJet> v_thinjet;

        if (v_ht800_nTrack->size() < 2)
        {
            continue;
        }

        for (size_t ijet = 0; ijet < v_ht800_nTrack->size(); ijet++)
        {
            v_thinjet.push_back(ThinJet((*v_ht800_Jethadronflavor)[ijet], (*v_ht800_JetPT)[ijet], (*v_ht800_JetEta)[ijet], (*v_ht800_alpha)[ijet], (*v_ht800_nTrack)[ijet]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        if (f_ht800_Met <= METcut)
        {
            continue;
        }
        if (f_ht800_dileppt < DileptonPT_cut)
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                h_DY_JetPt_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht800_weight * merge_weight.ee_HT800Weight);
                h_DY_JetEta_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht800_weight * merge_weight.ee_HT800Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    h_DY_JetPt_cut_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    h_DY_JetEta_cut_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    }
                }
            }
        } // low dilepton scope
        else
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                h_DY_JetPt_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht800_weight * merge_weight.ee_HT800Weight);
                h_DY_JetEta_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht800_weight * merge_weight.ee_HT800Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    h_DY_JetPt_cut_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    h_DY_JetEta_cut_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht800_weight * merge_weight.ee_HT800Weight);
                    }
                }
            }
        } // high dilepton scope
    }
    TTree *T_DYht1200_tree;
    merge_bfiles.ee_DYHT1200->GetObject("T_tree", T_DYht1200_tree);
    T_DYht1200_tree->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_DYht1200_tree->SetBranchAddress("I_nJets", &I_ht1200_nJets);
    T_DYht1200_tree->SetBranchAddress("v_N_Tracks", &v_ht1200_nTrack);
    T_DYht1200_tree->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_DYht1200_tree->SetBranchAddress("f_dileptonPT", &f_ht1200_dileppt);
    T_DYht1200_tree->SetBranchAddress("v_fakealpha", &v_ht1200_alpha);
    T_DYht1200_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ht1200_Jethadronflavor);
    T_DYht1200_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ht1200_Jetpartonflavor);
    T_DYht1200_tree->SetBranchAddress("v_fakeJetPt", &v_ht1200_JetPT);
    T_DYht1200_tree->SetBranchAddress("v_fakeJetEta", &v_ht1200_JetEta);
    for (int evt = 0; evt < T_DYht1200_tree->GetEntries(); evt++)
    {
        T_DYht1200_tree->GetEntry(evt);
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;
        vector<ThinJet> v_thinjet;

        if (v_ht1200_nTrack->size() < 2)
        {
            continue;
        }

        for (size_t ijet = 0; ijet < v_ht1200_nTrack->size(); ijet++)
        {
            v_thinjet.push_back(ThinJet((*v_ht1200_Jethadronflavor)[ijet], (*v_ht1200_JetPT)[ijet], (*v_ht1200_JetEta)[ijet], (*v_ht1200_alpha)[ijet], (*v_ht1200_nTrack)[ijet]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        if (f_ht1200_Met <= METcut)
        {
            continue;
        }
        if (f_ht1200_dileppt < DileptonPT_cut)
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                h_DY_JetPt_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                h_DY_JetEta_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    h_DY_JetPt_cut_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    h_DY_JetEta_cut_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    }
                }
            }
        } // low dilepton scope
        else
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                h_DY_JetPt_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                h_DY_JetEta_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    h_DY_JetPt_cut_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    h_DY_JetEta_cut_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht1200_weight * merge_weight.ee_HT1200Weight);
                    }
                }
            }
        } // high dilepton scope
    }
    TTree *T_DYht2500_tree;
    merge_bfiles.ee_DYHT2500->GetObject("T_tree", T_DYht2500_tree);
    T_DYht2500_tree->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_DYht2500_tree->SetBranchAddress("I_nJets", &I_ht2500_nJets);
    T_DYht2500_tree->SetBranchAddress("v_N_Tracks", &v_ht2500_nTrack);
    T_DYht2500_tree->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_DYht2500_tree->SetBranchAddress("f_dileptonPT", &f_ht2500_dileppt);
    T_DYht2500_tree->SetBranchAddress("v_fakealpha", &v_ht2500_alpha);
    T_DYht2500_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ht2500_Jethadronflavor);
    T_DYht2500_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ht2500_Jetpartonflavor);
    T_DYht2500_tree->SetBranchAddress("v_fakeJetPt", &v_ht2500_JetPT);
    T_DYht2500_tree->SetBranchAddress("v_fakeJetEta", &v_ht2500_JetEta);
    for (int evt = 0; evt < T_DYht2500_tree->GetEntries(); evt++)
    {
        T_DYht2500_tree->GetEntry(evt);
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;
        vector<ThinJet> v_thinjet;

        if (v_ht2500_nTrack->size() < 2)
        {
            continue;
        }

        for (size_t ijet = 0; ijet < v_ht2500_nTrack->size(); ijet++)
        {
            v_thinjet.push_back(ThinJet((*v_ht2500_Jethadronflavor)[ijet], (*v_ht2500_JetPT)[ijet], (*v_ht2500_JetEta)[ijet], (*v_ht2500_alpha)[ijet], (*v_ht2500_nTrack)[ijet]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        if (f_ht2500_Met <= METcut)
        {
            continue;
        }
        if (f_ht2500_dileppt < DileptonPT_cut)
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                h_DY_JetPt_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                h_DY_JetEta_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    h_DY_JetPt_cut_lowDilepPt->Fill(v_thinjet[i].GetPt(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    h_DY_JetEta_cut_lowDilepPt->Fill(v_thinjet[i].GetEta(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    }
                }
            }
        } // low dilepton scope
        else
        {
            for (int i = 0; i < v_thinjet.size(); i++)
            {
                h_DY_nTrk_jet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                h_DY_JetPt_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                h_DY_JetEta_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                if (v_thinjet[i].GetFlavor() == 5)
                {
                    h_DY_nTrk_bjet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                }
                if (v_thinjet[i].GetFlavor() == 0)
                {
                    h_DY_nTrk_ljet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                }
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_DY_nTrk_jet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    h_DY_JetPt_cut_highDilepPt->Fill(v_thinjet[i].GetPt(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    h_DY_JetEta_cut_highDilepPt->Fill(v_thinjet[i].GetEta(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    if (v_thinjet[i].GetFlavor() == 5)
                    {
                        h_DY_nTrk_bjet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    }
                    if (v_thinjet[i].GetFlavor() == 0)
                    {
                        h_DY_nTrk_ljet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), I_ht2500_weight * merge_weight.ee_HT2500Weight);
                    }
                }
            }
        } // high dilepton scope
    }

    TFile *outfile_HT0 = TFile::Open(outputfile, "RECREATE");
    h_DY_nTrk_jet_lowDilepPt->Write();
    h_DY_nTrk_jet_cut_lowDilepPt->Write();
    h_DY_nTrk_jet_highDilepPt->Write();
    h_DY_nTrk_jet_cut_highDilepPt->Write();
    h_DY_JetPt_lowDilepPt->Write();
    h_DY_JetPt_cut_lowDilepPt->Write();
    h_DY_JetPt_highDilepPt->Write();
    h_DY_JetPt_cut_highDilepPt->Write();
    h_DY_JetEta_lowDilepPt->Write();
    h_DY_JetEta_cut_lowDilepPt->Write();
    h_DY_JetEta_highDilepPt->Write();
    h_DY_JetEta_cut_highDilepPt->Write();
    /*Single flavor*/
    h_DY_nTrk_bjet_lowDilepPt->Write();
    h_DY_nTrk_bjet_cut_lowDilepPt->Write();
    h_DY_nTrk_ljet_lowDilepPt->Write();
    h_DY_nTrk_ljet_cut_lowDilepPt->Write();
    h_DY_nTrk_bjet_highDilepPt->Write();
    h_DY_nTrk_bjet_cut_highDilepPt->Write();
    h_DY_nTrk_ljet_highDilepPt->Write();
    h_DY_nTrk_ljet_cut_highDilepPt->Write();
    
    outfile_HT0->Close();
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        ee_DY_all(argv[1]);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}
