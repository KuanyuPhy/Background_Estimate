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
//-------------------------------------------
// Get Weight Function
//-------------------------------------------
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

void ee_Top_ee_half(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *Topfile = TFile::Open(file);

    //const Int_t NBINS = 16;
    //Double_t edges[NBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13, 14, 15., 25., 40.};

    const Int_t NBINS = 14;
    Double_t edges[NBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13, 14, 15.};

    const Int_t NJet_Nbins = 10;
    Double_t NJet_edges[NJet_Nbins + 1] = {0., 30., 60., 90., 120., 150., 210., 270., 350., 450., 1500.};

    const Int_t JetEta_Nbins = 30.;
    Double_t JetEta_low_bound = -3.;
    Double_t JetEta_upper_bound = 3.;

    // 1. nTrk
    TH1D *h_Top_nTrk_lowDilepPt = new TH1D("h_Top_nTrk_lowDilepPt", "", NBINS, edges);
    h_Top_nTrk_lowDilepPt->Sumw2();
    TH1D *h_Top_nTrk_cut_lowDilepPt = new TH1D("h_Top_nTrk_cut_lowDilepPt", "", NBINS, edges);
    h_Top_nTrk_cut_lowDilepPt->Sumw2();

    TH1D *h_Top_nTrk_highDilepPt = new TH1D("h_Top_nTrk_highDilepPt", "", NBINS, edges);
    h_Top_nTrk_highDilepPt->Sumw2();
    TH1D *h_Top_nTrk_cut_highDilepPt = new TH1D("h_Top_nTrk_cut_highDilepPt", "", NBINS, edges);
    h_Top_nTrk_cut_highDilepPt->Sumw2();

    // 2. JetPt
    TH1D *h_Top_JetPt_lowDilepPt = new TH1D("h_Top_JetPt_lowDilepPt", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_lowDilepPt->Sumw2();
    TH1D *h_Top_JetPt_cut_lowDilepPt = new TH1D("h_Top_JetPt_cut_lowDilepPt", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_cut_lowDilepPt->Sumw2();

    TH1D *h_Top_JetPt_highDilepPt = new TH1D("h_Top_JetPt_highDilepPt", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_highDilepPt->Sumw2();
    TH1D *h_Top_JetPt_cut_highDilepPt = new TH1D("h_Top_JetPt_cut_highDilepPt", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_cut_highDilepPt->Sumw2();

    // 3. JetEta
    TH1D *h_Top_JetEta_lowDilepPt = new TH1D("h_Top_JetEta_lowDilepPt", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_JetEta_lowDilepPt->Sumw2();
    TH1D *h_Top_JetEta_cut_lowDilepPt = new TH1D("h_Top_JetEta_cut_lowDilepPt", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_JetEta_cut_lowDilepPt->Sumw2();

    TH1D *h_Top_JetEta_highDilepPt = new TH1D("h_Top_JetEta_highDilepPt", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_JetEta_highDilepPt->Sumw2();
    TH1D *h_Top_JetEta_cut_highDilepPt = new TH1D("h_Top_JetEta_cut_highDilepPt", "", JetEta_Nbins, JetEta_low_bound, JetEta_upper_bound);
    h_Top_JetEta_cut_highDilepPt->Sumw2();

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
    Topfile->GetObject("h1", T_Top_tree);
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
        if (v_Top_nTrack->size() < 2)
        {
            // cout << "v_thinjet.size() == " << v_Top_nTrack->size() << endl;
            // cout << "bug" << endl;
            continue;
        }
        for (size_t i = 0; i < v_Top_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], (*v_Top_JetEta)[i], (*v_Top_alpha)[i], (*v_Top_nTrack)[i], (*v_Top_JetMass)[i], (*v_Top_JetCsv)[i]));
        }
        //--------------
        // Sort by Jet Pt
        //--------------
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        for (size_t i = 0; i < v_Top_JetPT->size() - 1; i++)
        {
            float a_pt = (*v_Top_JetPT)[i];
            float b_pt = (*v_Top_JetPT)[i + 1];
            if (b_pt > a_pt)
            {
                cout << "a_pt = " << a_pt << endl;
                cout << "b_pt = " << b_pt << endl;
            }
        }
        for (size_t i = 0; i < v_thinjet.size(); i++)
        {
            if (v_thinjet[i].GetPt() < 30)
            {
                cout << "JetPT= " << v_thinjet[i].GetPt() << endl;
            }
            else
            {
                continue;
            }
        }
        //------------------
        // Apply MET cut
        //------------------
        if (f_Top_met <= METcut)
        {
            continue;
        }
        //-----------------------
        // For Low dilepPT region
        //-----------------------
        if (f_Top_dileppt < DilepPTcut)
        {
            // Only consider LO & NLO Jet PT
            for (size_t i = 0; i < v_thinjet.size(); i++)
            {
                /*if (abs(v_thinjet[i].GetEta()) >= 1.442 && abs(v_thinjet[i].GetEta()) <= 1.566)
                {
                    continue;
                }*/

                h_Top_nTrk_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), Top_weight);
                h_Top_JetPt_lowDilepPt->Fill(v_thinjet[i].GetPt(), Top_weight);
                h_Top_JetEta_lowDilepPt->Fill(v_thinjet[i].GetEta(), Top_weight);

                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_Top_nTrk_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), Top_weight);
                    h_Top_JetPt_cut_lowDilepPt->Fill(v_thinjet[i].GetPt(), Top_weight);
                    h_Top_JetEta_cut_lowDilepPt->Fill(v_thinjet[i].GetEta(), Top_weight);
                }
            } // End of LO & NLO Jet loop
        }     // End of low dilepPT region
        //----------------------------
        // For High dilepPT region
        //----------------------------
        else
        {
            for (size_t i = 0; i < v_thinjet.size(); i++)
            {
                /*if (abs(v_thinjet[i].GetEta()) >= 1.442 && abs(v_thinjet[i].GetEta()) <= 1.566)
                {
                    continue;
                }*/

                h_Top_nTrk_highDilepPt->Fill(v_thinjet[i].GetNtrk(), Top_weight);
                h_Top_JetPt_highDilepPt->Fill(v_thinjet[i].GetPt(), Top_weight);
                h_Top_JetEta_highDilepPt->Fill(v_thinjet[i].GetEta(), Top_weight);
                if (v_thinjet[i].GetAlpha() < 0.1)
                {
                    h_Top_nTrk_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), Top_weight);
                    h_Top_JetPt_cut_highDilepPt->Fill(v_thinjet[i].GetPt(), Top_weight);
                    h_Top_JetEta_cut_highDilepPt->Fill(v_thinjet[i].GetEta(), Top_weight);
                }

            } // End of LO & NLO Jet loop
        }     // End of high dilepPT region
    }
    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    h_Top_nTrk_lowDilepPt->Write();
    h_Top_nTrk_cut_lowDilepPt->Write();
    h_Top_nTrk_highDilepPt->Write();
    h_Top_nTrk_cut_highDilepPt->Write();
    h_Top_JetPt_lowDilepPt->Write();
    h_Top_JetPt_cut_lowDilepPt->Write();
    h_Top_JetPt_highDilepPt->Write();
    h_Top_JetPt_cut_highDilepPt->Write();
    h_Top_JetEta_lowDilepPt->Write();
    h_Top_JetEta_cut_lowDilepPt->Write();
    h_Top_JetEta_highDilepPt->Write();
    h_Top_JetEta_cut_highDilepPt->Write();
    outfile->Close();
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_Top_ee_half();
    }
    else if (argc == 3)
    {
        ee_Top_ee_half(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}
