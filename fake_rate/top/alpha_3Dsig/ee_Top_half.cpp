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
#include "./../../../lib/Cross_section.h"
using namespace std;

//------------------
// Calculate weight
//------------------
TFile *TTTo2L2Nufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root");
TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

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
void for_doubleflavor_jet(int flavor1, int flavor2, int hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void ee_Top_half(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *Topfile = TFile::Open(file);
    cout << "Top weight = " << getWeight(file) << endl;
    //--------------------------------------------------------------
    // Hist: 0 : |eta| < 1, 1 : 1 < |eta| < 2, 2 : 2 < |eta| < 2.5
    //--------------------------------------------------------------
    TH1D *h_Top_nTrk_difeta[3];
    TH1D *h_Top_nTrk_cut_difeta[3];
    TH1D *h_Top_nTrk_bjet_difeta[3];
    TH1D *h_Top_nTrk_bjet_cut_difeta[3];
    TH1D *h_Top_nTrk_cjet_difeta[3];
    TH1D *h_Top_nTrk_cjet_cut_difeta[3];
    TH1D *h_Top_nTrk_ljet_difeta[3];
    TH1D *h_Top_nTrk_ljet_cut_difeta[3];
    TH1D *h_Top_nTrk_hjet_difeta[3];
    TH1D *h_Top_nTrk_hjet_cut_difeta[3];
    TH1D *h_Top_jetpt_difeta[3];
    TH1D *h_Top_jetpt_cut_difeta[3];
    TH1D *h_Top_jetpt_bjet_difeta[3];
    TH1D *h_Top_jetpt_bjet_cut_difeta[3];
    TH1D *h_Top_jetpt_cjet_difeta[3];
    TH1D *h_Top_jetpt_cjet_cut_difeta[3];
    TH1D *h_Top_jetpt_ljet_difeta[3];
    TH1D *h_Top_jetpt_ljet_cut_difeta[3];
    TH1D *h_Top_jetpt_hjet_difeta[3];
    TH1D *h_Top_jetpt_hjet_cut_difeta[3];

    for (int i = 0; i < 3; i++)
    {

        h_Top_nTrk_difeta[i] = new TH1D(Form("h_Top_nTrk_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_bjet_difeta[i] = new TH1D(Form("h_Top_nTrk_bjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_bjet_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_bjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cjet_difeta[i] = new TH1D(Form("h_Top_nTrk_cjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cjet_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_cjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_ljet_difeta[i] = new TH1D(Form("h_Top_nTrk_ljet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_ljet_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_ljet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_hjet_difeta[i] = new TH1D(Form("h_Top_nTrk_hjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_hjet_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_hjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_jetpt_difeta[i] = new TH1D(Form("h_Top_jetpt_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_jetpt_cut_difeta[i] = new TH1D(Form("h_Top_jetpt_cut_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_jetpt_bjet_difeta[i] = new TH1D(Form("h_Top_jetpt_bjet_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_jetpt_bjet_cut_difeta[i] = new TH1D(Form("h_Top_jetpt_bjet_cut_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_jetpt_cjet_difeta[i] = new TH1D(Form("h_Top_jetpt_cjet_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_jetpt_cjet_cut_difeta[i] = new TH1D(Form("h_Top_jetpt_cjet_cut_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_jetpt_ljet_difeta[i] = new TH1D(Form("h_Top_jetpt_ljet_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_jetpt_ljet_cut_difeta[i] = new TH1D(Form("h_Top_jetpt_ljet_cut_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_jetpt_hjet_difeta[i] = new TH1D(Form("h_Top_jetpt_hjet_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_jetpt_hjet_cut_difeta[i] = new TH1D(Form("h_Top_jetpt_hjet_cut_difeta_%i", i + 1), "", 50, 0., 500.);
        h_Top_nTrk_difeta[i]->Sumw2();
        h_Top_nTrk_cut_difeta[i]->Sumw2();
        h_Top_nTrk_bjet_difeta[i]->Sumw2();
        h_Top_nTrk_bjet_cut_difeta[i]->Sumw2();
        h_Top_nTrk_cjet_difeta[i]->Sumw2();
        h_Top_nTrk_cjet_cut_difeta[i]->Sumw2();
        h_Top_nTrk_ljet_difeta[i]->Sumw2();
        h_Top_nTrk_ljet_cut_difeta[i]->Sumw2();
        h_Top_nTrk_hjet_difeta[i]->Sumw2();
        h_Top_nTrk_hjet_cut_difeta[i]->Sumw2();
        h_Top_jetpt_difeta[i]->Sumw2();
        h_Top_jetpt_cut_difeta[i]->Sumw2();
        h_Top_jetpt_bjet_difeta[i]->Sumw2();
        h_Top_jetpt_bjet_cut_difeta[i]->Sumw2();
        h_Top_jetpt_cjet_difeta[i]->Sumw2();
        h_Top_jetpt_cjet_cut_difeta[i]->Sumw2();
        h_Top_jetpt_ljet_difeta[i]->Sumw2();
        h_Top_jetpt_ljet_cut_difeta[i]->Sumw2();
        h_Top_jetpt_hjet_difeta[i]->Sumw2();
        h_Top_jetpt_hjet_cut_difeta[i]->Sumw2();
    }
    //-----------------------------
    // Not consider eta
    //-----------------------------
    TH1D *h_Top_nTrk_bjet = new TH1D("h_Top_nTrk_bjet", "", 30, 1, 30);
    TH1D *h_Top_nTrk_bjet_cut = new TH1D("h_Top_nTrk_bjet_cut", "", 30, 1, 30);
    TH1D *h_Top_nTrk_cjet = new TH1D("h_Top_nTrk_cjet", "", 30, 1, 30);
    TH1D *h_Top_nTrk_cjet_cut = new TH1D("h_Top_nTrk_cjet_cut", "", 30, 1, 30);
    TH1D *h_Top_nTrk_ljet = new TH1D("h_Top_nTrk_ljet", "", 30, 1, 30);
    TH1D *h_Top_nTrk_ljet_cut = new TH1D("h_Top_nTrk_ljet_cut", "", 30, 1, 30);
    TH1D *h_Top_nTrk_hjet = new TH1D("h_Top_nTrk_hjet", "", 30, 1, 30);
    TH1D *h_Top_nTrk_hjet_cut = new TH1D("h_Top_nTrk_hjet_cut", "", 30, 1, 30);
    TH1D *h_Top_jetpt_bjet = new TH1D("h_Top_jetpt_bjet", "", 50, 0., 500.);
    TH1D *h_Top_jetpt_bjet_cut = new TH1D("h_Top_jetpt_bjet_cut", "", 50, 0., 500.);
    TH1D *h_Top_jetpt_cjet = new TH1D("h_Top_jetpt_cjet", "", 50, 0., 500.);
    TH1D *h_Top_jetpt_cjet_cut = new TH1D("h_Top_jetpt_cjet_cut", "", 50, 0., 500.);
    TH1D *h_Top_jetpt_ljet = new TH1D("h_Top_jetpt_ljet", "", 50, 0., 500.);
    TH1D *h_Top_jetpt_ljet_cut = new TH1D("h_Top_jetpt_ljet_cut", "", 50, 0., 500.);
    TH1D *h_Top_jetpt_hjet = new TH1D("h_Top_jetpt_hjet", "", 50, 0., 500.);
    TH1D *h_Top_jetpt_hjet_cut = new TH1D("h_Top_jetpt_hjet_cut", "", 50, 0., 500.);
    h_Top_nTrk_bjet->Sumw2();
    h_Top_nTrk_bjet_cut->Sumw2();
    h_Top_nTrk_cjet->Sumw2();
    h_Top_nTrk_cjet_cut->Sumw2();
    h_Top_nTrk_ljet->Sumw2();
    h_Top_nTrk_ljet_cut->Sumw2();
    h_Top_nTrk_hjet->Sumw2();
    h_Top_nTrk_hjet_cut->Sumw2();
    h_Top_jetpt_bjet->Sumw2();
    h_Top_jetpt_bjet_cut->Sumw2();
    h_Top_jetpt_cjet->Sumw2();
    h_Top_jetpt_cjet_cut->Sumw2();
    h_Top_jetpt_ljet->Sumw2();
    h_Top_jetpt_ljet_cut->Sumw2();
    h_Top_jetpt_hjet->Sumw2();
    h_Top_jetpt_hjet_cut->Sumw2();
    //-----------------------------
    // Not consider flavor
    //-----------------------------
    TH1D *h_Top_nTrk = new TH1D("h_Top_nTrk", "", 30, 1, 30);
    TH1D *h_Top_nTrk_cut = new TH1D("h_Top_nTrk_cut", "", 30, 1, 30);
    TH1D *h_Top_jetpt = new TH1D("h_Top_jetpt", "", 50, 0., 500.);
    TH1D *h_Top_jetpt_cut = new TH1D("h_Top_jetpt_cut", "", 50, 0., 500.);

    h_Top_nTrk->Sumw2();
    h_Top_nTrk_cut->Sumw2();

    h_Top_jetpt->Sumw2();
    h_Top_jetpt_cut->Sumw2();

    Int_t I_Top_nJets;

    Int_t I_Top_weight;

    float_t f_Top_met;

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
    Topfile->GetObject("h1", T_Top_tree);
    T_Top_tree->SetBranchAddress("I_weight", &I_Top_weight);
    T_Top_tree->SetBranchAddress("I_nJets", &I_Top_nJets);
    T_Top_tree->SetBranchAddress("v_N_Tracks", &v_Top_nTrack);
    T_Top_tree->SetBranchAddress("f_Met", &f_Top_met);
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
        if (f_Top_met < 0)
        {
            continue;
        }
        double Top_weight = getWeight(file) * I_Top_weight;
        // double Top_weight = 1.;
        int iTrack = 0;
        for (size_t iJet = 0; iJet < v_Top_nTrack->size(); iJet++)
        {
            //------------------------------
            // Calculate ntrk pass 3D cut
            //------------------------------
            int ntrk_pass3Dsig = 0.;
            for (size_t j = iTrack; j < iTrack + (*v_Top_nTrack)[iJet]; j++)
            {

                if ((*v_Top_Chi3Dlog)[j] < 1.0)
                {
                    ntrk_pass3Dsig++;
                }

            } // End of Track loop
            // For debug
            if ((*v_Top_nTrack)[iJet] < ntrk_pass3Dsig)
            {
                cout << "ntrk = " << (*v_Top_nTrack)[iJet] << endl;
                cout << "ntrk pass 3D cut  = " << ntrk_pass3Dsig << endl;
            }
            //----------------------------------
            // Calculate fake rate denominator
            //----------------------------------
            //----------------------------------
            // For ntrk
            //----------------------------------
            // Not Consider eta
            h_Top_nTrk->Fill((*v_Top_nTrack)[iJet], Top_weight);
            //  For b jet
            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_cjet);
            // For light flavor
            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_ljet);
            // For heavy flavor
            for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_hjet);
            //----------------------------------
            // For JetPT
            //----------------------------------
            h_Top_jetpt->Fill((*v_Top_JetPT)[iJet], Top_weight);
            //  For b jet
            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_bjet);
            //  For c jet
            for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_cjet);
            //  For light flavor
            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_ljet);
            //  For heavy flavor
            for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_hjet);
            //--------------------
            // Consider eta
            //--------------------
            if (abs((*v_Top_JetEta)[iJet]) < 1)
            {
                // Not consider flavor
                h_Top_nTrk_difeta[0]->Fill((*v_Top_nTrack)[iJet], Top_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_bjet_difeta[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_cjet_difeta[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_ljet_difeta[0]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_hjet_difeta[0]);
                //----------------------------------
                // For JetPT
                //----------------------------------
                // Not consider flavor
                h_Top_jetpt_difeta[0]->Fill((*v_Top_JetPT)[iJet], Top_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_bjet_difeta[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_cjet_difeta[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_ljet_difeta[0]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_hjet_difeta[0]);
            }
            // For Region 1 < |eta| < 2
            else if (abs((*v_Top_JetEta)[iJet]) > 1 && abs((*v_Top_JetEta)[iJet]) < 2)
            {
                // Not consider flavor
                h_Top_nTrk_difeta[1]->Fill((*v_Top_nTrack)[iJet], Top_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_bjet_difeta[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_cjet_difeta[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_ljet_difeta[1]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_hjet_difeta[1]);

                //----------------------------------
                // For JetPT
                //----------------------------------
                // Not consider flavor
                h_Top_jetpt_difeta[1]->Fill((*v_Top_JetPT)[iJet], Top_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_bjet_difeta[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_cjet_difeta[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_ljet_difeta[1]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_hjet_difeta[1]);
            }
            // For Region 2 < |eta| < 2.5
            else if (abs((*v_Top_JetEta)[iJet]) > 2 && abs((*v_Top_JetEta)[iJet]) < 2.5)
            { // Not consider flavor
                h_Top_nTrk_difeta[2]->Fill((*v_Top_nTrack)[iJet], Top_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_bjet_difeta[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_cjet_difeta[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_ljet_difeta[2]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_hjet_difeta[2]);

                //----------------------------------
                // For JetPT
                //----------------------------------
                // Not consider flavor
                h_Top_jetpt_difeta[2]->Fill((*v_Top_JetPT)[iJet], Top_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_bjet_difeta[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_cjet_difeta[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_ljet_difeta[2]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_hjet_difeta[2]);
            }

            //-------------------------------------------------------------
            // Calculate fake rate numerator (SR)
            //-------------------------------------------------------------
            // cout << "iTrack = " <<iTrack<<endl;
            if (ntrk_pass3Dsig == 0)
            {
                iTrack += (*v_Top_nTrack)[iJet];
                //continue;
            }

            if ((*v_Top_alpha)[iJet] < 0.1)
            {
                // Not Consider eta
                h_Top_nTrk_cut->Fill((*v_Top_nTrack)[iJet], Top_weight);
                //  For b jet
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_cjet_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_ljet_cut);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_hjet_cut);
                //---------------
                // For JetPT
                //---------------
                // Not Consider eta
                h_Top_jetpt_cut->Fill((*v_Top_JetPT)[iJet], Top_weight);
                //  For b jet
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_cjet_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_ljet_cut);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_hjet_cut);

                //--------------------
                // Consider eta
                //--------------------
                if (abs((*v_Top_JetEta)[iJet]) < 1)
                {
                    // Not consider flavor
                    h_Top_nTrk_cut_difeta[0]->Fill((*v_Top_nTrack)[iJet], Top_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_bjet_cut_difeta[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_cjet_cut_difeta[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_ljet_cut_difeta[0]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_hjet_cut_difeta[0]);
                    //---------------
                    // For JetPT
                    //---------------
                    // Not consider flavor
                    h_Top_jetpt_cut_difeta[0]->Fill((*v_Top_JetPT)[iJet], Top_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_bjet_cut_difeta[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_cjet_cut_difeta[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_ljet_cut_difeta[0]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_hjet_cut_difeta[0]);
                } // For Region 1 < |eta| < 2
                else if (abs((*v_Top_JetEta)[iJet]) > 1 && abs((*v_Top_JetEta)[iJet]) < 2)
                {
                    // Not consider flavor
                    h_Top_nTrk_cut_difeta[1]->Fill((*v_Top_nTrack)[iJet], Top_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_bjet_cut_difeta[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_cjet_cut_difeta[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_ljet_cut_difeta[1]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_hjet_cut_difeta[1]);
                    //---------------
                    // For JetPT
                    //---------------
                    // Not consider flavor
                    h_Top_jetpt_cut_difeta[1]->Fill((*v_Top_JetPT)[iJet], Top_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_bjet_cut_difeta[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_cjet_cut_difeta[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_ljet_cut_difeta[1]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_hjet_cut_difeta[1]);
                } // For Region 2 < |eta| < 2.5
                else if (abs((*v_Top_JetEta)[iJet]) > 2 && abs((*v_Top_JetEta)[iJet]) < 2.5)
                {
                    // Not consider flavor
                    h_Top_nTrk_cut_difeta[2]->Fill((*v_Top_nTrack)[iJet], Top_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_bjet_cut_difeta[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_cjet_cut_difeta[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_ljet_cut_difeta[2]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_nTrack)[iJet], Top_weight, h_Top_nTrk_hjet_cut_difeta[2]);
                    //---------------
                    // For JetPT
                    //---------------
                    h_Top_jetpt_cut_difeta[2]->Fill((*v_Top_JetPT)[iJet], Top_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_bjet_cut_difeta[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_cjet_cut_difeta[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_ljet_cut_difeta[2]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[iJet], (*v_Top_JetPT)[iJet], Top_weight, h_Top_jetpt_hjet_cut_difeta[2]);
                }
            }

            iTrack += (*v_Top_nTrack)[iJet];
        } // End of Jet loop
    }     // End of Top loop

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    for (int i = 0; i < 3; i++)
    {
        h_Top_nTrk_difeta[i]->Write();
        h_Top_nTrk_cut_difeta[i]->Write();
        h_Top_nTrk_bjet_difeta[i]->Write();
        h_Top_nTrk_bjet_cut_difeta[i]->Write();
        h_Top_nTrk_cjet_difeta[i]->Write();
        h_Top_nTrk_cjet_cut_difeta[i]->Write();
        h_Top_nTrk_ljet_difeta[i]->Write();
        h_Top_nTrk_ljet_cut_difeta[i]->Write();
        h_Top_nTrk_hjet_difeta[i]->Write();
        h_Top_nTrk_hjet_cut_difeta[i]->Write();
        h_Top_jetpt_difeta[i]->Write();
        h_Top_jetpt_cut_difeta[i]->Write();
        h_Top_jetpt_bjet_difeta[i]->Write();
        h_Top_jetpt_bjet_cut_difeta[i]->Write();
        h_Top_jetpt_cjet_difeta[i]->Write();
        h_Top_jetpt_cjet_cut_difeta[i]->Write();
        h_Top_jetpt_ljet_difeta[i]->Write();
        h_Top_jetpt_ljet_cut_difeta[i]->Write();
        h_Top_jetpt_hjet_difeta[i]->Write();
        h_Top_jetpt_hjet_cut_difeta[i]->Write();
    }
    h_Top_nTrk_bjet->Write();
    h_Top_nTrk_bjet_cut->Write();
    h_Top_nTrk_cjet->Write();
    h_Top_nTrk_cjet_cut->Write();
    h_Top_nTrk_ljet->Write();
    h_Top_nTrk_ljet_cut->Write();
    h_Top_nTrk_hjet->Write();
    h_Top_nTrk_hjet_cut->Write();
    h_Top_nTrk->Write();
    h_Top_nTrk_cut->Write();
    h_Top_jetpt_bjet->Write();
    h_Top_jetpt_bjet_cut->Write();
    h_Top_jetpt_cjet->Write();
    h_Top_jetpt_cjet_cut->Write();
    h_Top_jetpt_ljet->Write();
    h_Top_jetpt_ljet_cut->Write();
    h_Top_jetpt_hjet->Write();
    h_Top_jetpt_hjet_cut->Write();
    h_Top_jetpt->Write();
    h_Top_jetpt_cut->Write();
    outfile->Close();

    // cout << getWeight(file) << endl;
    // cout << "TTTo2L2NuWeight = " << TTTo2L2NuWeight << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_Top_half();
    }
    else if (argc == 3)
    {
        ee_Top_half(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}