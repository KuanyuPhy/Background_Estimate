#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <TLegend.h>
#include <string>
#include <TCanvas.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../../lib/Cross_section.h"
using namespace std;

void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, float flavor2, float hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

void ee_Top_produce_half(TString inputfile = "/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTTo2L2Nu.root", TString outputfile1 = "./ee_diffeta_Top_emjet_half.root")
{
    TFile *TTTo2L2Nufile = TFile::Open(inputfile);
    TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToLNu.root");
    TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTWJetsToQQ.root");
    TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToQQ.root");
    TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_TTZToLLNuNu.root");
    TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_antitop.root");
    TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/top_tW_top.root");

    //-------------
    // Open Tree
    //-------------
    TFile *TTTo2L2Nufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTTo2L2Nu_1.root");
    TFile *Top_TTWJetsToLNufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTWJetsToLNu_1.root");
    TFile *Top_TTWJetsToQQfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTWJetsToQQ_1.root");
    TFile *Top_TTZToQQfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTZToQQ_1.root");
    TFile *Top_TTZToLLNuNufile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_TTZToLLNuNu_1.root");
    TFile *Top_tW_antitopfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_tW_antitop_1.root");
    TFile *Top_tW_topfile_1 = new TFile("/home/kuanyu/Documents/root_file/BgEstimation/top_tW_top_1.root");

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

    cout << "TTTo2L2NuWeight = " << TTTo2L2NuWeight << endl;
    cout << "ST_tW_topWeight = " << ST_tW_topWeight << endl;
    cout << "ST_tW_antitopWeight = " << ST_tW_antitopWeight << endl;
    cout << "TTWJetsToLNuWeight = " << TTWJetsToLNuWeight << endl;
    cout << "TTWJetsToQQWeight = " << TTWJetsToQQWeight << endl;
    cout << "ST_tW_topWeight = " << ST_tW_topWeight << endl;
    cout << "TTZToQQWeight = " << TTZToQQWeight << endl;
    cout << "TTZToLLNuNuWeight = " << TTZToLLNuNuWeight << endl;

    //--------------------------------------------------------------
    // Hist: 0 : |eta| < 1, 1 : 1 < |eta| < 2, 2 : 2 < |eta| < 2.5
    //--------------------------------------------------------------

    TH1D *h_Top_nTracks_bjet[3];
    TH1D *h_Top_nTracks_bjet_cut[3];
    TH1D *h_Top_nTracks_cjet[3];
    TH1D *h_Top_nTracks_cjet_cut[3];
    TH1D *h_Top_nTracks_ljet[3];
    TH1D *h_Top_nTracks_ljet_cut[3];

    for (int i = 0; i < 3; i++)
    {
        h_Top_nTracks_bjet[i] = new TH1D(Form("h_Top_nTracks_bjet_%i", i + 1), "", 30, 1, 30);
        h_Top_nTracks_bjet_cut[i] = new TH1D(Form("h_Top_nTracks_bjet_cut_%i", i + 1), "", 30, 1, 30);
        h_Top_nTracks_cjet[i] = new TH1D(Form("h_Top_nTracks_cjet_%i", i + 1), "", 30, 1, 30);
        h_Top_nTracks_cjet_cut[i] = new TH1D(Form("h_Top_nTracks_cjet_cut_%i", i + 1), "", 30, 1, 30);
        h_Top_nTracks_ljet[i] = new TH1D(Form("h_Top_nTracks_ljet_%i", i + 1), "", 30, 1, 30);
        h_Top_nTracks_ljet_cut[i] = new TH1D(Form("h_Top_nTracks_ljet_cut_%i", i + 1), "", 30, 1, 30);
        h_Top_nTracks_bjet[i]->Sumw2();
        h_Top_nTracks_bjet_cut[i]->Sumw2();
        h_Top_nTracks_cjet[i]->Sumw2();
        h_Top_nTracks_cjet_cut[i]->Sumw2();
        h_Top_nTracks_ljet[i]->Sumw2();
        h_Top_nTracks_ljet_cut[i]->Sumw2();
    }

    TH1D *h_Top_Met = new TH1D("h_Top_Met", "", 50, 0, 500);
    h_Top_Met->Sumw2();

    Int_t I_TTTo2L2Nu_nThinJets;
    Int_t I_ST_tW_top_nThinJets;
    Int_t I_ST_tW_antitop_nThinJets;
    Int_t I_TTWJetsToLNu_nThinJets;
    Int_t I_TTWJetsToQQ_nThinJets;
    Int_t I_TTZToQQ_nThinJets;
    Int_t I_TTZToLLNuNu_nThinJets;

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

    vector<float> *v_TTTo2L2Nu_alpha = new vector<float>();
    vector<float> *v_ST_tW_top_alpha = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha = new vector<float>();
    vector<float> *v_TTZToQQ_alpha = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Chi3Dlog = new vector<float>();
    vector<float> *v_ST_tW_top_Chi3Dlog = new vector<float>();
    vector<float> *v_ST_tW_antitop_Chi3Dlog = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Chi3Dlog = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Chi3Dlog = new vector<float>();
    vector<float> *v_TTZToQQ_Chi3Dlog = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Chi3Dlog = new vector<float>();

    vector<float> *v_TTTo2L2Nu_2DIP = new vector<float>();
    vector<float> *v_ST_tW_top_2DIP = new vector<float>();
    vector<float> *v_ST_tW_antitop_2DIP = new vector<float>();
    vector<float> *v_TTWJetsToLNu_2DIP = new vector<float>();
    vector<float> *v_TTWJetsToQQ_2DIP = new vector<float>();
    vector<float> *v_TTZToQQ_2DIP = new vector<float>();
    vector<float> *v_TTZToLLNuNu_2DIP = new vector<float>();

    vector<float> *v_TTTo2L2Nu_nTrack = new vector<float>();
    vector<float> *v_ST_tW_top_nTrack = new vector<float>();
    vector<float> *v_ST_tW_antitop_nTrack = new vector<float>();
    vector<float> *v_TTWJetsToLNu_nTrack = new vector<float>();
    vector<float> *v_TTWJetsToQQ_nTrack = new vector<float>();
    vector<float> *v_TTZToQQ_nTrack = new vector<float>();
    vector<float> *v_TTZToLLNuNu_nTrack = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Jethadronflavor = new vector<float>();
    vector<float> *v_ST_tW_top_Jethadronflavor = new vector<float>();
    vector<float> *v_ST_tW_antitop_Jethadronflavor = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Jethadronflavor = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Jethadronflavor = new vector<float>();
    vector<float> *v_TTZToQQ_Jethadronflavor = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Jethadronflavor = new vector<float>();

    vector<float> *v_TTTo2L2Nu_Jetpartonflavor = new vector<float>();
    vector<float> *v_ST_tW_top_Jetpartonflavor = new vector<float>();
    vector<float> *v_ST_tW_antitop_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTZToQQ_Jetpartonflavor = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Jetpartonflavor = new vector<float>();

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

    v_TTTo2L2Nu_alpha->clear();
    v_ST_tW_top_alpha->clear();
    v_ST_tW_antitop_alpha->clear();
    v_TTWJetsToLNu_alpha->clear();
    v_TTWJetsToQQ_alpha->clear();
    v_TTZToQQ_alpha->clear();
    v_TTZToLLNuNu_alpha->clear();

    v_TTTo2L2Nu_Chi3Dlog->clear();
    v_ST_tW_top_Chi3Dlog->clear();
    v_ST_tW_antitop_Chi3Dlog->clear();
    v_TTWJetsToLNu_Chi3Dlog->clear();
    v_TTWJetsToQQ_Chi3Dlog->clear();
    v_TTZToQQ_Chi3Dlog->clear();
    v_TTZToLLNuNu_Chi3Dlog->clear();

    v_TTTo2L2Nu_2DIP->clear();
    v_ST_tW_top_2DIP->clear();
    v_ST_tW_antitop_2DIP->clear();
    v_TTWJetsToLNu_2DIP->clear();
    v_TTWJetsToQQ_2DIP->clear();
    v_TTZToQQ_2DIP->clear();
    v_TTZToLLNuNu_2DIP->clear();

    v_TTTo2L2Nu_nTrack->clear();
    v_ST_tW_top_nTrack->clear();
    v_ST_tW_antitop_nTrack->clear();
    v_TTWJetsToLNu_nTrack->clear();
    v_TTWJetsToQQ_nTrack->clear();
    v_TTZToQQ_nTrack->clear();
    v_TTZToLLNuNu_nTrack->clear();

    v_TTTo2L2Nu_Jethadronflavor->clear();
    v_ST_tW_top_Jethadronflavor->clear();
    v_ST_tW_antitop_Jethadronflavor->clear();
    v_TTWJetsToLNu_Jethadronflavor->clear();
    v_TTWJetsToQQ_Jethadronflavor->clear();
    v_TTZToQQ_Jethadronflavor->clear();
    v_TTZToLLNuNu_Jethadronflavor->clear();

    v_TTTo2L2Nu_Jetpartonflavor->clear();
    v_ST_tW_top_Jetpartonflavor->clear();
    v_ST_tW_antitop_Jetpartonflavor->clear();
    v_TTWJetsToLNu_Jetpartonflavor->clear();
    v_TTWJetsToQQ_Jetpartonflavor->clear();
    v_TTZToQQ_Jetpartonflavor->clear();
    v_TTZToLLNuNu_Jetpartonflavor->clear();

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
    
    TTree *T_TTTo2L2Nu_tree;
    TTTo2L2Nufile_1->GetObject("h1", T_TTTo2L2Nu_tree);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_weight", &I_TTTo2L2Nu_weight);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_nJets", &I_TTTo2L2Nu_nThinJets);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_N_Tracks", &v_TTTo2L2Nu_nTrack);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_IP2D", &v_TTTo2L2Nu_2DIP);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTTo2L2Nu_Chi3Dlog);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTTo2L2Nu_Jethadronflavor);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTTo2L2Nu_Jetpartonflavor);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetPt", &v_TTTo2L2Nu_JetPT);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetEta", &v_TTTo2L2Nu_JetEta);
    for (int evt = 0; evt < T_TTTo2L2Nu_tree->GetEntries(); evt++)
    {
        T_TTTo2L2Nu_tree->GetEntry(evt);
        if (f_TTTo2L2Nu_met < 0)
        {
            continue;
        }
        double TTTo2L2Nu_eventWeight = I_TTTo2L2Nu_weight * TTTo2L2NuWeight;
        //double TTTo2L2Nu_eventWeight = 1.;
        //-----------------
        // Event var : Met
        //-----------------
        h_Top_Met->Fill(f_TTTo2L2Nu_met, TTTo2L2Nu_eventWeight);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_TTTo2L2Nu_nTrack->size(); i++)
        {
            // For Region |eta| < 1
            if (abs((*v_TTTo2L2Nu_JetEta)[i]) < 1)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_ljet[0]);
                // For SR cut
                if ((*v_TTTo2L2Nu_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet_cut[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet_cut[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_ljet_cut[0]);
                }
            }
            // For Region 1 < |eta| < 2
            else if (abs((*v_TTTo2L2Nu_JetEta)[i]) > 1 && abs((*v_TTTo2L2Nu_JetEta)[i]) < 2)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_ljet[1]);
                // For SR cut
                if ((*v_TTTo2L2Nu_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet_cut[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet_cut[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_ljet_cut[1]);
                }
            }
            // For Region 2 < |eta| < 2.5
            else if (abs((*v_TTTo2L2Nu_JetEta)[i]) > 2 && abs((*v_TTTo2L2Nu_JetEta)[i]) < 2.5)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_ljet[2]);
                // For SR cut
                if ((*v_TTTo2L2Nu_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_bjet_cut[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_cjet_cut[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTTo2L2Nu_Jethadronflavor)[i], (*v_TTTo2L2Nu_nTrack)[i], TTTo2L2Nu_eventWeight, h_Top_nTracks_ljet_cut[2]);
                }
            }
        }
    } // End of TTTo2L2Nu
    
    
    TTree *T_ST_tW_top_tree;
    Top_tW_topfile_1->GetObject("h1", T_ST_tW_top_tree);
    T_ST_tW_top_tree->SetBranchAddress("I_weight", &I_ST_tW_top_weight);
    T_ST_tW_top_tree->SetBranchAddress("I_nJets", &I_ST_tW_top_nThinJets);
    T_ST_tW_top_tree->SetBranchAddress("v_N_Tracks", &v_ST_tW_top_nTrack);
    T_ST_tW_top_tree->SetBranchAddress("f_Met", &f_ST_tW_top_met);
    T_ST_tW_top_tree->SetBranchAddress("v_IP2D", &v_ST_tW_top_2DIP);
    T_ST_tW_top_tree->SetBranchAddress("v_Chi3Dlog", &v_ST_tW_top_Chi3Dlog);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_top_alpha);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_top_Jethadronflavor);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ST_tW_top_Jetpartonflavor);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetPt", &v_ST_tW_top_JetPT);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetEta", &v_ST_tW_top_JetEta);
    for (int evt = 0; evt < T_ST_tW_top_tree->GetEntries(); evt++)
    {
        T_ST_tW_top_tree->GetEntry(evt);
        if (f_ST_tW_top_met < 0)
        {
            continue;
        }
        double ST_tW_top_eventWeight = I_ST_tW_top_weight * ST_tW_topWeight;
        //double ST_tW_top_eventWeight = 1.;
        //-----------------
        // Event var : Met
        //-----------------
        h_Top_Met->Fill(f_ST_tW_top_met, ST_tW_top_eventWeight);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ST_tW_top_nTrack->size(); i++)
        {
            // For Region |eta| < 1
            if (abs((*v_ST_tW_top_JetEta)[i]) < 1)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_ljet[0]);
                // For SR cut
                if ((*v_ST_tW_top_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet_cut[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet_cut[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_ljet_cut[0]);
                }
            }
            else if (abs((*v_ST_tW_top_JetEta)[i]) > 1 && abs((*v_ST_tW_top_JetEta)[i]) < 2)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_ljet[1]);
                // For SR cut
                if ((*v_ST_tW_top_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet_cut[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet_cut[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_ljet_cut[1]);
                }
            }
            else if (abs((*v_ST_tW_top_JetEta)[i]) > 2 && abs((*v_ST_tW_top_JetEta)[i]) < 2.5)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_ljet[2]);
                // For SR cut
                if ((*v_ST_tW_top_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_bjet_cut[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_cjet_cut[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_ST_tW_top_Jethadronflavor)[i], (*v_ST_tW_top_nTrack)[i], ST_tW_top_eventWeight, h_Top_nTracks_ljet_cut[2]);
                }
            }
        }
    } // End of ST_tW_top_tree
    
    
    TTree *T_ST_tW_antitop_tree;
    Top_tW_antitopfile_1->GetObject("h1", T_ST_tW_antitop_tree);
    T_ST_tW_antitop_tree->SetBranchAddress("I_weight", &I_ST_tW_antitop_weight);
    T_ST_tW_antitop_tree->SetBranchAddress("I_nJets", &I_ST_tW_antitop_nThinJets);
    T_ST_tW_antitop_tree->SetBranchAddress("v_N_Tracks", &v_ST_tW_antitop_nTrack);
    T_ST_tW_antitop_tree->SetBranchAddress("f_Met", &f_ST_tW_antitop_met);
    T_ST_tW_antitop_tree->SetBranchAddress("v_IP2D", &v_ST_tW_antitop_2DIP);
    T_ST_tW_antitop_tree->SetBranchAddress("v_Chi3Dlog", &v_ST_tW_antitop_Chi3Dlog);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_antitop_alpha);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_antitop_Jethadronflavor);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_ST_tW_antitop_Jetpartonflavor);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetPt", &v_ST_tW_antitop_JetPT);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetEta", &v_ST_tW_antitop_JetEta);
    for (int evt = 0; evt < T_ST_tW_antitop_tree->GetEntries(); evt++)
    {
        T_ST_tW_antitop_tree->GetEntry(evt);
        if (f_ST_tW_antitop_met < 0)
        {
            continue;
        }
        double ST_tW_antitop_eventWeight = I_ST_tW_antitop_weight * ST_tW_antitopWeight;
        //double ST_tW_antitop_eventWeight = 1.;
        
        //-----------------
        // Event var : Met
        //-----------------
        h_Top_Met->Fill(f_ST_tW_antitop_met, ST_tW_antitop_eventWeight);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_ST_tW_antitop_nTrack->size(); i++)
        {
            // For Region |eta| < 1
            if (abs((*v_ST_tW_antitop_JetEta)[i]) < 1)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_ljet[0]);
                // For SR cut
                if ((*v_ST_tW_antitop_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet_cut[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet_cut[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_ljet_cut[0]);
                }
            }
            else if (abs((*v_ST_tW_antitop_JetEta)[i]) > 1 && abs((*v_ST_tW_antitop_JetEta)[i]) < 2)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_ljet[1]);
                // For SR cut
                if ((*v_ST_tW_antitop_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet_cut[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet_cut[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_ljet_cut[1]);
                }
            }
            else if (abs((*v_ST_tW_antitop_JetEta)[i]) > 2 && abs((*v_ST_tW_antitop_JetEta)[i]) < 2.5)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_ljet[2]);

                // For SR cut
                if ((*v_ST_tW_antitop_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_bjet_cut[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_cjet_cut[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_ST_tW_antitop_Jethadronflavor)[i], (*v_ST_tW_antitop_nTrack)[i], ST_tW_antitop_eventWeight, h_Top_nTracks_ljet_cut[2]);
                }
            }
        }
    } // End of ST_tW_antitop
    TTree *T_TTWJetsToLNu_tree;
    Top_TTWJetsToLNufile_1->GetObject("h1", T_TTWJetsToLNu_tree);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_weight", &I_TTWJetsToLNu_weight);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_nJets", &I_TTWJetsToLNu_nThinJets);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_N_Tracks", &v_TTWJetsToLNu_nTrack);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_IP2D", &v_TTWJetsToLNu_2DIP);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTWJetsToLNu_Chi3Dlog);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToLNu_alpha);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToLNu_Jethadronflavor);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTWJetsToLNu_Jetpartonflavor);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToLNu_JetPT);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToLNu_JetEta);
    for (int evt = 0; evt < T_TTWJetsToLNu_tree->GetEntries(); evt++)
    {
        T_TTWJetsToLNu_tree->GetEntry(evt);
        if (f_TTWJetsToLNu_met < 0)
        {
            continue;
        }
        double TTWJetsToLNu_eventWeight = I_TTWJetsToLNu_weight * TTWJetsToLNuWeight;
        //double TTWJetsToLNu_eventWeight = 1.;
        //-----------------
        // Event var : Met
        //-----------------
        h_Top_Met->Fill(f_TTWJetsToLNu_met, TTWJetsToLNu_eventWeight);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_TTWJetsToLNu_nTrack->size(); i++)
        {
            // For Region |eta| < 1
            if (abs((*v_TTWJetsToLNu_JetEta)[i]) < 1)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_ljet[0]);

                // For SR cut
                if ((*v_TTWJetsToLNu_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet_cut[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet_cut[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_ljet_cut[0]);
                }
            }
            else if (abs((*v_TTWJetsToLNu_JetEta)[i]) > 1 && abs((*v_TTWJetsToLNu_JetEta)[i]) < 2)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_ljet[1]);

                // For SR cut
                if ((*v_TTWJetsToLNu_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet_cut[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet_cut[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_ljet_cut[1]);
                }
            }
            else if (abs((*v_TTWJetsToLNu_JetEta)[i]) > 2 && abs((*v_TTWJetsToLNu_JetEta)[i]) < 2.5)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_ljet[2]);

                // For SR cut
                if ((*v_TTWJetsToLNu_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_bjet_cut[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_cjet_cut[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTWJetsToLNu_Jethadronflavor)[i], (*v_TTWJetsToLNu_nTrack)[i], TTWJetsToLNu_eventWeight, h_Top_nTracks_ljet_cut[2]);
                }
            }
        }
    } // End of TTWJetsToLNu    
    TTree *T_TTWJetsToQQ_tree;
    Top_TTWJetsToQQfile_1->GetObject("h1", T_TTWJetsToQQ_tree);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_weight", &I_TTWJetsToQQ_weight);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_nJets", &I_TTWJetsToQQ_nThinJets);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_N_Tracks", &v_TTWJetsToQQ_nTrack);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_IP2D", &v_TTWJetsToQQ_2DIP);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_Chi3Dlog", &v_TTWJetsToQQ_Chi3Dlog);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToQQ_alpha);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToQQ_Jethadronflavor);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTWJetsToQQ_Jetpartonflavor);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetPt", &v_TTWJetsToQQ_JetPT);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetEta", &v_TTWJetsToQQ_JetEta);
    for (int evt = 0; evt < T_TTWJetsToQQ_tree->GetEntries(); evt++)
    {
        T_TTWJetsToQQ_tree->GetEntry(evt);
        if (f_TTWJetsToQQ_met < 0)
        {
            continue;
        }
        double TTWJetsToQQ_eventWeight = I_TTWJetsToQQ_weight * TTWJetsToQQWeight;
        //double TTWJetsToQQ_eventWeight = 1.;
        //-----------------
        // Event var : Met
        //-----------------
        h_Top_Met->Fill(f_TTWJetsToQQ_met, TTWJetsToQQ_eventWeight);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_TTWJetsToQQ_nTrack->size(); i++)
        {
            // For Region |eta| < 1
            if (abs((*v_TTWJetsToQQ_JetEta)[i]) < 1)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_ljet[0]);
                // For SR cut
                if ((*v_TTWJetsToQQ_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet_cut[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet_cut[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_ljet_cut[0]);
                }
            }
            else if (abs((*v_TTWJetsToQQ_JetEta)[i]) > 1 && abs((*v_TTWJetsToQQ_JetEta)[i]) < 2)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_ljet[1]);
                // For SR cut
                if ((*v_TTWJetsToQQ_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet_cut[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet_cut[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_ljet_cut[1]);
                }
            }
            else if (abs((*v_TTWJetsToQQ_JetEta)[i]) > 2 && abs((*v_TTWJetsToQQ_JetEta)[i]) < 2.5)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_ljet[2]);

                // For SR cut
                if ((*v_TTWJetsToQQ_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_bjet_cut[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_cjet_cut[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTWJetsToQQ_Jethadronflavor)[i], (*v_TTWJetsToQQ_nTrack)[i], TTWJetsToQQ_eventWeight, h_Top_nTracks_ljet_cut[2]);
                }
            }
        }
    } // End of TTWJetsToQQ
    
    
    TTree *T_TTZToQQ_tree;
    Top_TTZToQQfile_1->GetObject("h1", T_TTZToQQ_tree);
    T_TTZToQQ_tree->SetBranchAddress("I_weight", &I_TTZToQQ_weight);
    T_TTZToQQ_tree->SetBranchAddress("I_nJets", &I_TTZToQQ_nThinJets);
    T_TTZToQQ_tree->SetBranchAddress("v_N_Tracks", &v_TTZToQQ_nTrack);
    T_TTZToQQ_tree->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_TTZToQQ_tree->SetBranchAddress("v_IP2D", &v_TTZToQQ_2DIP);
    T_TTZToQQ_tree->SetBranchAddress("v_Chi3Dlog", &v_TTZToQQ_Chi3Dlog);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTZToQQ_alpha);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToQQ_Jethadronflavor);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTZToQQ_Jetpartonflavor);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetPt", &v_TTZToQQ_JetPT);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetEta", &v_TTZToQQ_JetEta);
    for (int evt = 0; evt < T_TTZToQQ_tree->GetEntries(); evt++)
    {
        T_TTZToQQ_tree->GetEntry(evt);
        if (f_TTZToQQ_met < 0)
        {
            continue;
        }
        double TTZToQQ_eventWeight = I_TTZToQQ_weight * TTZToQQWeight;
        //double TTZToQQ_eventWeight = 1.;
        //-----------------
        // Event var : Met
        //-----------------
        h_Top_Met->Fill(f_TTZToQQ_met, TTZToQQ_eventWeight);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_TTZToQQ_nTrack->size(); i++)
        {
            // For Region |eta| < 1
            if (abs((*v_TTZToQQ_JetEta)[i]) < 1)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_ljet[0]);
                // For SR cut
                if ((*v_TTZToQQ_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet_cut[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet_cut[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_ljet_cut[0]);
                }
            }
            else if (abs((*v_TTZToQQ_JetEta)[i]) > 1 && abs((*v_TTZToQQ_JetEta)[i]) < 2)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_ljet[1]);

                // For SR cut
                if ((*v_TTZToQQ_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet_cut[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet_cut[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_ljet_cut[1]);
                }
            }
            else if (abs((*v_TTZToQQ_JetEta)[i]) > 2 && abs((*v_TTZToQQ_JetEta)[i]) < 2.5)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_ljet[2]);
                // For SR cut
                if ((*v_TTZToQQ_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_bjet_cut[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_cjet_cut[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTZToQQ_Jethadronflavor)[i], (*v_TTZToQQ_nTrack)[i], TTZToQQ_eventWeight, h_Top_nTracks_ljet_cut[2]);
                }
            }
        }
    } // End of TTZToQQ
    
    
    TTree *T_TTZToLLNuNu_tree;
    Top_TTZToLLNuNufile_1->GetObject("h1", T_TTZToLLNuNu_tree);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_weight", &I_TTZToLLNuNu_weight);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_nJets", &I_TTZToLLNuNu_nThinJets);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_N_Tracks", &v_TTZToLLNuNu_nTrack);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_IP2D", &v_TTZToLLNuNu_2DIP);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTZToLLNuNu_Chi3Dlog);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha", &v_TTZToLLNuNu_alpha);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToLLNuNu_Jethadronflavor);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_TTZToLLNuNu_Jetpartonflavor);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetPt", &v_TTZToLLNuNu_JetPT);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetEta", &v_TTZToLLNuNu_JetEta);
    for (int evt = 0; evt < T_TTZToLLNuNu_tree->GetEntries(); evt++)
    {
        T_TTZToLLNuNu_tree->GetEntry(evt);
        if (f_TTZToLLNuNu_met < 0)
        {
            continue;
        }
        double TTZToLLNuNu_eventWeight = I_TTZToLLNuNu_weight * TTZToLLNuNuWeight;
        //double TTZToLLNuNu_eventWeight = 1.;
        //-----------------
        // Event var : Met
        //-----------------
        h_Top_Met->Fill(f_TTZToLLNuNu_met, TTZToLLNuNu_eventWeight);
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks, JetPt, JetEta, alpha3D
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_TTZToLLNuNu_nTrack->size(); i++)
        {
            // For Region |eta| < 1
            if (abs((*v_TTZToLLNuNu_JetEta)[i]) < 1)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_ljet[0]);
                // For SR cut
                if ((*v_TTZToLLNuNu_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet_cut[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet_cut[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_ljet_cut[0]);
                }
            }
            else if (abs((*v_TTZToLLNuNu_JetEta)[i]) > 1 && abs((*v_TTZToLLNuNu_JetEta)[i]) < 2)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_ljet[1]);
                // For SR cut
                if ((*v_TTZToLLNuNu_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet_cut[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet_cut[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_ljet_cut[1]);
                }
            }
            else if (abs((*v_TTZToLLNuNu_JetEta)[i]) > 2 && abs((*v_TTZToLLNuNu_JetEta)[i]) < 2.5)
            {
                // For b jet
                for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_ljet[2]);
                // For SR cut
                if ((*v_TTZToLLNuNu_alpha)[i] < 0.1)
                {
                    // For b jet
                    for_signalflavor_jet(5, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_bjet_cut[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_cjet_cut[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_TTZToLLNuNu_Jethadronflavor)[i], (*v_TTZToLLNuNu_nTrack)[i], TTZToLLNuNu_eventWeight, h_Top_nTracks_ljet_cut[2]);
                }
            }
        }
    } // End of TTZToLLNuNu
    

    //-----------------------
    // Fake rate : nTracks
    //-----------------------
    TH1D *Top_bfakeRate_eta1 = (TH1D *)h_Top_nTracks_bjet_cut[0]->Clone("Top_bfakeRate_eta1");
    Top_bfakeRate_eta1->Divide(h_Top_nTracks_bjet_cut[0], h_Top_nTracks_bjet[0], 1, 1, "b");
    TH1D *Top_cfakeRate_eta1 = (TH1D *)h_Top_nTracks_cjet_cut[0]->Clone("Top_cfakeRate_eta1");
    Top_cfakeRate_eta1->Divide(h_Top_nTracks_cjet_cut[0], h_Top_nTracks_cjet[0], 1, 1, "b");
    TH1D *Top_lfakeRate_eta1 = (TH1D *)h_Top_nTracks_ljet_cut[0]->Clone("Top_lfakeRate_eta1");
    Top_lfakeRate_eta1->Divide(h_Top_nTracks_ljet_cut[0], h_Top_nTracks_ljet[0], 1, 1, "b");

    TH1D *Top_bfakeRate_eta2 = (TH1D *)h_Top_nTracks_bjet_cut[1]->Clone("Top_bfakeRate_eta2");
    Top_bfakeRate_eta2->Divide(h_Top_nTracks_bjet_cut[1], h_Top_nTracks_bjet[1], 1, 1, "b");
    TH1D *Top_cfakeRate_eta2 = (TH1D *)h_Top_nTracks_cjet_cut[1]->Clone("Top_cfakeRate_eta2");
    Top_cfakeRate_eta2->Divide(h_Top_nTracks_cjet_cut[1], h_Top_nTracks_cjet[1], 1, 1, "b");
    TH1D *Top_lfakeRate_eta2 = (TH1D *)h_Top_nTracks_ljet_cut[1]->Clone("Top_lfakeRate_eta2");
    Top_lfakeRate_eta2->Divide(h_Top_nTracks_ljet_cut[1], h_Top_nTracks_ljet[1], 1, 1, "b");

    TH1D *Top_bfakeRate_eta3 = (TH1D *)h_Top_nTracks_bjet_cut[2]->Clone("Top_bfakeRate_eta3");
    Top_bfakeRate_eta3->Divide(h_Top_nTracks_bjet_cut[2], h_Top_nTracks_bjet[2], 1, 1, "b");
    TH1D *Top_cfakeRate_eta3 = (TH1D *)h_Top_nTracks_cjet_cut[2]->Clone("Top_cfakeRate_eta3");
    Top_cfakeRate_eta3->Divide(h_Top_nTracks_cjet_cut[2], h_Top_nTracks_cjet[2], 1, 1, "b");
    TH1D *Top_lfakeRate_eta3 = (TH1D *)h_Top_nTracks_ljet_cut[2]->Clone("Top_lfakeRate_eta3");
    Top_lfakeRate_eta3->Divide(h_Top_nTracks_ljet_cut[2], h_Top_nTracks_ljet[2], 1, 1, "b");

    /*
    auto c1 = new TCanvas("c1", "", 700, 700);
    c1->Divide(3, 3);
    c1->cd(1);
    Top_bfakeRate_eta1->Draw();
    c1->cd(2);
    Top_cfakeRate_eta1->Draw();
    c1->cd(3);
    Top_lfakeRate_eta1->Draw();
    c1->cd(4);
    Top_bfakeRate_eta2->Draw();
    c1->cd(5);
    Top_cfakeRate_eta2->Draw();
    c1->cd(6);
    Top_lfakeRate_eta2->Draw();
    c1->cd(7);
    Top_bfakeRate_eta3->Draw();
    c1->cd(8);
    Top_cfakeRate_eta3->Draw();
    c1->cd(9);
    Top_lfakeRate_eta3->Draw();
    */
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    outfile_HT0->cd();
    Top_bfakeRate_eta1->Write();
    Top_cfakeRate_eta1->Write();
    Top_lfakeRate_eta1->Write();
    Top_bfakeRate_eta2->Write();
    Top_cfakeRate_eta2->Write();
    Top_lfakeRate_eta2->Write();
    Top_bfakeRate_eta3->Write();
    Top_cfakeRate_eta3->Write();
    Top_lfakeRate_eta3->Write();
    outfile_HT0->Close();
}
/*
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_Top_produce_half();
    }
    else if (argc == 3)
    {
        ee_Top_produce_half(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}
*/