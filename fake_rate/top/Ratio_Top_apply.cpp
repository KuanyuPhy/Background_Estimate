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
TFile *TTTo2L2Nufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/ee_top_TTTo2L2Nu.root");
TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/ee_top_TTWJetsToLNu.root");
TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/ee_top_TTWJetsToQQ.root");
TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/ee_top_TTZToQQ.root");
TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/ee_top_TTZToLLNuNu.root");
TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/ee_top_tW_antitop.root");
TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/ee_top_tW_top.root");

//----------------------
// Get fake rate
//----------------------
TFile *Top_fakerate_topfile = new TFile("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_all_fakerate.root");
// TFile *Top_fakerate_topfile = new TFile("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top/top_ee_fakerate.root");

TH1D *Topemu_nTrk_fakeRate_lowDilepPt = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_lowDilepPt"));
TH1D *Topemu_nTrk_fakeRate_highDilepPt = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_highDilepPt"));

TH1D *Top_nTrk_fakeRate_highDilepPt_1 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_highDilepPt_1"));
TH1D *Top_nTrk_fakeRate_highDilepPt_2 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_highDilepPt_2"));
TH1D *Top_nTrk_fakeRate_highDilepPt_3 = ((TH1D *)Top_fakerate_topfile->Get("Top_nTrk_fakeRate_highDilepPt_3"));

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

int getfakerate(float tmp1, float start, float Binwidth)
{
    int quotient;
    quotient = floor((tmp1 - start) / (Binwidth));

    return quotient + 1;
}
//---------------
// void Function
//---------------
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

    // const Int_t NBINS = 16;
    // Double_t edges[NBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13, 14, 15., 25., 40.};

    const Int_t NBINS = 14;
    Double_t edges[NBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13, 14, 15.};

    const Int_t NJet_Nbins = 10;
    Double_t NJet_edges[NJet_Nbins + 1] = {0., 30., 60., 90., 120., 150., 210., 270., 350., 450., 1500.};

    const Int_t JetEta_Nbins = 30.;
    Double_t JetEta_low_bound = -3.;
    Double_t JetEta_upper_bound = 3.;

    TH1D *h_Top_nTrk_HighDilepPt_true = new TH1D("h_Top_nTrk_HighDilepPt_true", "", NBINS, edges);
    h_Top_nTrk_HighDilepPt_true->Sumw2();

    TH1D *h_Top_nTrk_HighDilepPt_predict = new TH1D("h_Top_nTrk_HighDilepPt_predict", "", NBINS, edges);
    h_Top_nTrk_HighDilepPt_predict->Sumw2();

    TH1D *h_Top_JetPt_HighDilepPt_true = new TH1D("h_Top_JetPt_HighDilepPt_true", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_HighDilepPt_true->Sumw2();

    TH1D *h_Top_JetPt_HighDilepPt_predict = new TH1D("h_Top_JetPt_HighDilepPt_predict", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_HighDilepPt_predict->Sumw2();

    TH1D *h_Top_JetEta_HighDilepPt_true = new TH1D("h_Top_JetEta_HighDilepPt_true", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_JetEta_HighDilepPt_true->Sumw2();

    TH1D *h_Top_JetEta_HighDilepPt_predict = new TH1D("h_Top_JetEta_HighDilepPt_predict", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_JetEta_HighDilepPt_predict->Sumw2();

    TH1D *h_Top_nTrk_HighDilepPt_region1_true = new TH1D("h_Top_nTrk_HighDilepPt_region1_true", "", NBINS, edges);
    h_Top_nTrk_HighDilepPt_region1_true->Sumw2();
    TH1D *h_Top_nTrk_HighDilepPt_region2_true = new TH1D("h_Top_nTrk_HighDilepPt_region2_true", "", NBINS, edges);
    h_Top_nTrk_HighDilepPt_region2_true->Sumw2();
    TH1D *h_Top_nTrk_HighDilepPt_region3_true = new TH1D("h_Top_nTrk_HighDilepPt_region3_true", "", NBINS, edges);
    h_Top_nTrk_HighDilepPt_region3_true->Sumw2();

    TH1D *h_Top_nTrk_region1_predict = new TH1D("h_Top_nTrk_region1_predict", "", NBINS, edges);
    h_Top_nTrk_region1_predict->Sumw2();
    TH1D *h_Top_nTrk_region2_predict = new TH1D("h_Top_nTrk_region2_predict", "", NBINS, edges);
    h_Top_nTrk_region2_predict->Sumw2();
    TH1D *h_Top_nTrk_region3_predict = new TH1D("h_Top_nTrk_region3_predict", "", NBINS, edges);
    h_Top_nTrk_region3_predict->Sumw2();

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

    float METcut = 140.;

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
        if (f_Top_met < 0)
        {
            continue;
        }
        double Top_weight = getWeight(file) * I_Top_weight;
        vector<ThinJet> v_thinjet;
        if (v_Top_nTrack->size() < 2)
        {
            continue;
        }
        for (size_t i = 0; i < v_Top_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], (*v_Top_JetEta)[i], (*v_Top_alpha)[i], (*v_Top_nTrack)[i], (*v_Top_JetMass)[i], (*v_Top_JetCsv)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());

        if (f_Top_met <= METcut)
        {
            continue;
        } // MET Cut

        if (f_Top_dileppt >= DilepPTcut)
        {
            // v_thinjet.size()
            for (size_t ijet = 0; ijet < v_thinjet.size(); ijet++)
            {

                int fk_bin_pos = getbinfakerate(v_thinjet[ijet].GetNtrk());
                // cout << "fk_bin_pos = " << fk_bin_pos << endl;
                double no_flavor_fk = Topemu_nTrk_fakeRate_lowDilepPt->GetBinContent(fk_bin_pos) * Top_weight;
                h_Top_nTrk_HighDilepPt_predict->Fill(v_thinjet[ijet].GetNtrk(), no_flavor_fk);
                h_Top_JetPt_HighDilepPt_predict->Fill(v_thinjet[ijet].GetPt(), no_flavor_fk);
                h_Top_JetEta_HighDilepPt_predict->Fill(v_thinjet[ijet].GetEta(), no_flavor_fk);

                if (v_thinjet[ijet].GetAlpha() < 0.1)
                {
                    h_Top_nTrk_HighDilepPt_true->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                    h_Top_JetPt_HighDilepPt_true->Fill(v_thinjet[ijet].GetPt(), Top_weight);
                    h_Top_JetEta_HighDilepPt_true->Fill(v_thinjet[ijet].GetEta(), Top_weight);

                    if (abs(v_thinjet[ijet].GetEta()) < 1)
                    {
                        h_Top_nTrk_HighDilepPt_region1_true->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                    }
                    else if (abs(v_thinjet[ijet].GetEta()) > 1 && abs(v_thinjet[ijet].GetEta()) < 2)
                    {
                    }
                    else if (abs(v_thinjet[ijet].GetEta()) > 2 && abs(v_thinjet[ijet].GetEta()) < 2.5)
                    {
                    }
                }
            }

        } // For High dilepton PT
        else
        {
            continue;
        }

    } // End of Top loop

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    h_Top_nTrk_HighDilepPt_predict->Write();
    h_Top_JetPt_HighDilepPt_predict->Write();
    h_Top_JetEta_HighDilepPt_predict->Write();
    h_Top_nTrk_HighDilepPt_true->Write();
    h_Top_JetPt_HighDilepPt_true->Write();
    h_Top_JetEta_HighDilepPt_true->Write();
    outfile->Close();
    // h_Top_JetPt_bjet_SR->Draw();
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