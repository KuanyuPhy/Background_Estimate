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
#include "./../../lib/kuan_ana_utils.h"
using namespace std;

//-------------------
// Create New class
//-------------------
class ThinJet
{
private:
    float jetflavor, jetpt, jeteta, jetalpha, jetntrk, jetmass;

public:
    ThinJet() {}
    ThinJet(const float &a, const float &b, const float &c, const float &d, const float &e, const float &f) : jetflavor(a), jetpt(b), jeteta(c), jetalpha(d), jetntrk(e), jetmass(f) {}
    Float_t GetFlavor() const { return jetflavor; }
    Float_t GetPt() const { return jetpt; }
    Float_t GetEta() const { return jeteta; }
    Float_t GetAlpha() const { return jetalpha; }
    Float_t GetNtrk() const { return jetntrk; }
    Float_t GetMass() const { return jetmass; }

    friend ostream &operator<<(ostream &out, const ThinJet &foo)
    {
        return out << foo.jetflavor << " " << foo.jetpt << " " << foo.jeteta << " " << foo.jetalpha << " " << foo.jetntrk << "" << foo.jetmass << endl;
    }

    // greater() is used for JetPT
    friend bool operator>(const ThinJet &a, const ThinJet &b)
    {
        return a.GetPt() > b.GetPt();
    }
};

MergeBFiles merge_bfiles;
MergeWeight merge_weight(&merge_bfiles);

vector<double> v_xs_Weight = {merge_weight.emu_TTTo2L2NuWeight, merge_weight.emu_ST_tW_topWeight,
                              merge_weight.emu_ST_tW_antitopWeight, merge_weight.emu_TTWJetsToLNuWeight, merge_weight.emu_TTWJetsToQQWeight,
                              merge_weight.emu_TTZToQQWeight, merge_weight.emu_TTZToLLNuNuWeight};
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

void ee_Top_emu(TString file = "tmp.root", TString outputfile = "output.root")
{

    TFile *Topfile = TFile::Open(file);
    cout << "Top weight = " << getWeight(file) << endl;

    const Int_t NBINS = 16;
    Double_t edges[NBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13, 14, 15., 25., 40.};

    const Int_t NJet_Nbins = 10;
    Double_t NJet_edges[NJet_Nbins + 1] = {0., 30., 60., 90., 120., 150., 210., 270., 350., 450., 1500.};

    const Int_t JetEta_Nbins = 30.;
    Double_t JetEta_low_bound = -3.;
    Double_t JetEta_upper_bound = 3.;

    // TH1D *h_Top_nTrk_jet_lowDilepPt = new TH1D("h_Top_nTrk_jet_lowDilepPt", "", );
    TH1D *h_Top_nTrk_jet_lowDilepPt = new TH1D("h_Top_nTrk_jet_lowDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_jet_cut_lowDilepPt = new TH1D("h_Top_nTrk_jet_cut_lowDilepPt", "", NBINS, edges);

    TH1D *h_Top_nTrk_jet_highDilepPt = new TH1D("h_Top_nTrk_jet_highDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_jet_cut_highDilepPt = new TH1D("h_Top_nTrk_jet_cut_highDilepPt", "", NBINS, edges);

    /*For single flavor*/
    TH1D *h_Top_nTrk_bjet_lowDilepPt = new TH1D("h_Top_nTrk_bjet_lowDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_bjet_cut_lowDilepPt = new TH1D("h_Top_nTrk_bjet_cut_lowDilepPt", "", NBINS, edges);

    TH1D *h_Top_nTrk_bjet_highDilepPt = new TH1D("h_Top_nTrk_bjet_highDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_bjet_cut_highDilepPt = new TH1D("h_Top_nTrk_bjet_cut_highDilepPt", "", NBINS, edges);

    TH1D *h_Top_nTrk_ljet_lowDilepPt = new TH1D("h_Top_nTrk_ljet_lowDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_ljet_cut_lowDilepPt = new TH1D("h_Top_nTrk_ljet_cut_lowDilepPt", "", NBINS, edges);

    TH1D *h_Top_nTrk_ljet_highDilepPt = new TH1D("h_Top_nTrk_ljet_highDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_ljet_cut_highDilepPt = new TH1D("h_Top_nTrk_ljet_cut_highDilepPt", "", NBINS, edges);

    // 2. JetPT
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

    //-----------------------------
    // Not consider flavor
    //-----------------------------
    TH1D *h_Top_nTrk = new TH1D("h_Top_nTrk", "", 30, 1, 30);
    TH1D *h_Top_nTrk_cut = new TH1D("h_Top_nTrk_cut", "", 30, 1, 30);
    h_Top_nTrk->Sumw2();
    h_Top_nTrk_cut->Sumw2();

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
    Topfile->GetObject("T_tree", T_Top_tree);
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
    T_Top_tree->SetBranchAddress("v_fakeJetMass", &v_Top_JetMass);
    for (int evt = 0; evt < T_Top_tree->GetEntries(); evt++)
    {

        T_Top_tree->GetEntry(evt);
        if (f_Top_met < 0)
        {
            continue;
        }
        double Top_weight = getWeight(file) * I_Top_weight;
        // double Top_weight = 1.;
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks
        //-------------------------------------------------------------
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;

        vector<ThinJet> v_thinjet;

        if (v_Top_nTrack->size() < 2)
        {
            // cout << "v_thinjet.size() == " << v_Top_nTrack->size() << endl;
            // cout << "bug" << endl;
            continue;
        }
        // cout << "v_thinjet.size() == " << v_Top_nTrack->size() << endl;
        //-------------------------------------------------------------
        //  Jet var : different flavor  nTracks
        //-------------------------------------------------------------
        for (size_t ijet = 0; ijet < v_Top_nTrack->size(); ijet++)
        {
            v_thinjet.push_back(ThinJet((*v_Top_Jethadronflavor)[ijet], (*v_Top_JetPT)[ijet], (*v_Top_JetEta)[ijet], (*v_Top_alpha)[ijet], (*v_Top_nTrack)[ijet], (*v_Top_JetMass)[ijet]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());

        //----------------------------------------
        // Calculate fake rate base on dilepton PT
        //----------------------------------------

        if (f_Top_met > METcut)
        {
            if (f_Top_dileppt < DilepPTcut)
            {
                // v_thinjet.size()
                for (int ijet = 0; ijet < v_thinjet.size(); ijet++)
                {
                    h_Top_nTrk_jet_lowDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                    h_Top_JetPt_lowDilepPt->Fill(v_thinjet[ijet].GetPt(), Top_weight);
                    h_Top_JetEta_lowDilepPt->Fill(v_thinjet[ijet].GetEta(), Top_weight);
                    if (v_thinjet[ijet].GetFlavor() == 5)
                    {
                        h_Top_nTrk_bjet_lowDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                    }
                    if (v_thinjet[ijet].GetFlavor() == 0)
                    {
                        h_Top_nTrk_ljet_lowDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                    }

                    //-------------------------
                    // For SR
                    //-------------------------
                    if (v_thinjet[ijet].GetAlpha() < 0.1)
                    {
                        h_Top_nTrk_jet_cut_lowDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                        h_Top_JetPt_cut_lowDilepPt->Fill(v_thinjet[ijet].GetPt(), Top_weight);
                        h_Top_JetEta_cut_lowDilepPt->Fill(v_thinjet[ijet].GetEta(), Top_weight);
                        if (v_thinjet[ijet].GetFlavor() == 5)
                        {
                            h_Top_nTrk_bjet_cut_lowDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                        }
                        if (v_thinjet[ijet].GetFlavor() == 0)
                        {
                            h_Top_nTrk_ljet_cut_lowDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                        }
                    } // End of alpha cut

                } // End of v_thinjet loop
            }     // End of low dilepton PT cut
            else
            {
                for (int ijet = 0; ijet < v_thinjet.size(); ijet++)
                {
                    h_Top_nTrk_jet_highDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                    h_Top_JetPt_highDilepPt->Fill(v_thinjet[ijet].GetPt(), Top_weight);
                    h_Top_JetEta_highDilepPt->Fill(v_thinjet[ijet].GetEta(), Top_weight);
                    if (v_thinjet[ijet].GetFlavor() == 5)
                    {
                        h_Top_nTrk_bjet_highDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                    }
                    if (v_thinjet[ijet].GetFlavor() == 0)
                    {
                        h_Top_nTrk_ljet_highDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                    }
                    //-------------------------
                    // For SR
                    //-------------------------
                    if (v_thinjet[ijet].GetAlpha() < 0.1)
                    {
                        h_Top_nTrk_jet_cut_highDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                        h_Top_JetPt_cut_highDilepPt->Fill(v_thinjet[ijet].GetPt(), Top_weight);
                        h_Top_JetEta_cut_highDilepPt->Fill(v_thinjet[ijet].GetEta(), Top_weight);
                        if (v_thinjet[ijet].GetFlavor() == 5)
                        {
                            h_Top_nTrk_bjet_cut_highDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                        }
                        if (v_thinjet[ijet].GetFlavor() == 0)
                        {
                            h_Top_nTrk_ljet_cut_highDilepPt->Fill(v_thinjet[ijet].GetNtrk(), Top_weight);
                        }
                    }
                } // End of v_thinjet loop
            }     // End of high dilepton PT cut
        }         // End of MET cut

    } // End of Top loop

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();

    h_Top_nTrk_jet_lowDilepPt->Write();
    h_Top_nTrk_jet_cut_lowDilepPt->Write();
    h_Top_nTrk_jet_highDilepPt->Write();
    h_Top_nTrk_jet_cut_highDilepPt->Write();

    h_Top_nTrk_bjet_lowDilepPt->Write();
    h_Top_nTrk_bjet_cut_lowDilepPt->Write();
    h_Top_nTrk_bjet_highDilepPt->Write();
    h_Top_nTrk_bjet_cut_highDilepPt->Write();

    h_Top_nTrk_ljet_lowDilepPt->Write();
    h_Top_nTrk_ljet_cut_lowDilepPt->Write();
    h_Top_nTrk_ljet_highDilepPt->Write();
    h_Top_nTrk_ljet_cut_highDilepPt->Write();

    h_Top_JetPt_lowDilepPt->Write();
    h_Top_JetPt_cut_lowDilepPt->Write();
    h_Top_JetPt_highDilepPt->Write();
    h_Top_JetPt_cut_highDilepPt->Write();

    h_Top_JetEta_lowDilepPt->Write();
    h_Top_JetEta_cut_lowDilepPt->Write();
    h_Top_JetEta_highDilepPt->Write();
    h_Top_JetEta_cut_highDilepPt->Write();

    outfile->Close();

    // cout << getWeight(file) << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_Top_emu();
    }
    else if (argc == 3)
    {
        ee_Top_emu(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}