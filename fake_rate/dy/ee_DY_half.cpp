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
            continue;
        }
        double DY_weight = getWeight(file) * I_DY_weight;
        // double Diboson_weight = 1.;
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_DY_nTrack->size(); i++)
        {
            // Not Consider eta
            h_DY_nTrk->Fill((*v_DY_nTrack)[i], DY_weight);
            //  For b jet
            for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_cjet);
            // For light flavor
            for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_ljet);
            // For heavy flavor
            for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_hjet);
            if ((*v_DY_alpha)[i] < 0.1)
            {
                // Not Consider eta
                h_DY_nTrk_cut->Fill((*v_DY_nTrack)[i], DY_weight);
                //  For b jet
                for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_cjet_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_ljet_cut);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_hjet_cut);
            }
            //--------------------
            // Consider eta
            //--------------------
            //  For Region |eta| < 1
            if (abs((*v_DY_JetEta)[i]) < 1)
            {
                // Not consider flavor
                h_DY_nTrk_difeta[0]->Fill((*v_DY_nTrack)[i], DY_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_bjet_difeta[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_cjet_difeta[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_ljet_difeta[0]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_hjet_difeta[0]);
                // For SR cut
                if ((*v_DY_alpha)[i] < 0.1)
                {
                    // Not consider flavor
                    h_DY_nTrk_cut_difeta[0]->Fill((*v_DY_nTrack)[i], DY_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_bjet_cut_difeta[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_cjet_cut_difeta[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_ljet_cut_difeta[0]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_hjet_cut_difeta[0]);
                }
            }
            // For Region 1 < |eta| < 2
            else if (abs((*v_DY_JetEta)[i]) > 1 && abs((*v_DY_JetEta)[i]) < 2)
            {
                // Not consider flavor
                h_DY_nTrk_difeta[1]->Fill((*v_DY_nTrack)[i], DY_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_bjet_difeta[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_cjet_difeta[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_ljet_difeta[1]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_hjet_difeta[1]);
                // For SR cut
                if ((*v_DY_alpha)[i] < 0.1)
                {
                    // Not consider flavor
                    h_DY_nTrk_cut_difeta[1]->Fill((*v_DY_nTrack)[i], DY_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_bjet_cut_difeta[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_cjet_cut_difeta[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_ljet_cut_difeta[1]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_hjet_cut_difeta[1]);
                }
            }
            // For Region 2 < |eta| < 2.5
            else if (abs((*v_DY_JetEta)[i]) > 2 && abs((*v_DY_JetEta)[i]) < 2.5)
            {
                // Not consider flavor
                h_DY_nTrk_difeta[2]->Fill((*v_DY_nTrack)[i], DY_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_bjet_difeta[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_cjet_difeta[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_ljet_difeta[2]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_hjet_difeta[2]);

                // For SR cut
                if ((*v_DY_alpha)[i] < 0.1)
                {
                    // Not consider flavor
                    h_DY_nTrk_cut_difeta[2]->Fill((*v_DY_nTrack)[i], DY_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_bjet_cut_difeta[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_cjet_cut_difeta[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_ljet_cut_difeta[2]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_DY_Jethadronflavor)[i], (*v_DY_nTrack)[i], DY_weight, h_DY_nTrk_hjet_cut_difeta[2]);
                }
            }
        }
    } // End of Diboson loop

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