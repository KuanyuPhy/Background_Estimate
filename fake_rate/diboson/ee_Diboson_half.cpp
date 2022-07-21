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
TFile *diboson_gg_ZZ_2e2mu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2mu.root");
TFile *diboson_gg_ZZ_2e2nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2nu.root");
TFile *diboson_gg_ZZ_2e2tau = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2tau.root");
TFile *diboson_gg_ZZ_2mu2nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2mu2nu.root");
TFile *diboson_gg_ZZ_2mu2tau = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2mu2tau.root");
TFile *diboson_gg_ZZ_4e = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4e.root");
TFile *diboson_gg_ZZ_4mu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4mu.root");
TFile *diboson_gg_ZZ_4tau = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4tau.root");
TFile *diboson_gg_WW_2L2Nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_WW_2L2Nu.root");
TFile *diboson_qq_WW_2L2Nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WW_2L2Nu.root");
TFile *diboson_qq_WZ_2L2Q = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WZ_2L2Q.root");
TFile *diboson_qq_WZ_3LNu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WZ_3LNu.root");
TFile *diboson_qq_ZZ_2L2Nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_2L2Nu.root");
TFile *diboson_qq_ZZ_2L2Q = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_2L2Q.root");
TFile *diboson_qq_ZZ_4L = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_4L.root");

TH1D *gg_ZZ_2e2mu_sumevt = ((TH1D *)diboson_gg_ZZ_2e2mu->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_2e2nu_sumevt = ((TH1D *)diboson_gg_ZZ_2e2nu->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_2e2tau_sumevt = ((TH1D *)diboson_gg_ZZ_2e2tau->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_2mu2nu_sumevt = ((TH1D *)diboson_gg_ZZ_2mu2nu->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_2mu2tau_sumevt = ((TH1D *)diboson_gg_ZZ_2mu2tau->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_4e_sumevt = ((TH1D *)diboson_gg_ZZ_4e->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_4mu_sumevt = ((TH1D *)diboson_gg_ZZ_4mu->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_4tau_sumevt = ((TH1D *)diboson_gg_ZZ_4tau->Get("Event_Variable/h_totevent"));
TH1D *gg_WW_2L2Nu_sumevt = ((TH1D *)diboson_gg_WW_2L2Nu->Get("Event_Variable/h_totevent"));
TH1D *qq_WW_2L2Nu_sumevt = ((TH1D *)diboson_qq_WW_2L2Nu->Get("Event_Variable/h_totevent"));
TH1D *qq_WZ_2L2Q_sumevt = ((TH1D *)diboson_qq_WZ_2L2Q->Get("Event_Variable/h_totevent"));
TH1D *qq_WZ_3LNu_sumevt = ((TH1D *)diboson_qq_WZ_3LNu->Get("Event_Variable/h_totevent"));
TH1D *qq_ZZ_2L2Nu_sumevt = ((TH1D *)diboson_qq_ZZ_2L2Nu->Get("Event_Variable/h_totevent"));
TH1D *qq_ZZ_2L2Q_sumevt = ((TH1D *)diboson_qq_ZZ_2L2Q->Get("Event_Variable/h_totevent"));
TH1D *qq_ZZ_4L_sumevt = ((TH1D *)diboson_qq_ZZ_4L->Get("Event_Variable/h_totevent"));

int gg_ZZ_2e2mu_totevt = gg_ZZ_2e2mu_sumevt->Integral();
int gg_ZZ_2e2nu_totevt = gg_ZZ_2e2nu_sumevt->Integral();
int gg_ZZ_2e2tau_totevt = gg_ZZ_2e2tau_sumevt->Integral();
int gg_ZZ_2mu2nu_totevt = gg_ZZ_2mu2nu_sumevt->Integral();
int gg_ZZ_2mu2tau_totevt = gg_ZZ_2mu2tau_sumevt->Integral();
int gg_ZZ_4e_totevt = gg_ZZ_4e_sumevt->Integral();
int gg_ZZ_4mu_totevt = gg_ZZ_4mu_sumevt->Integral();
int gg_ZZ_4tau_totevt = gg_ZZ_4tau_sumevt->Integral();
int gg_WW_2L2Nu_totevt = gg_WW_2L2Nu_sumevt->Integral();
int qq_WW_2L2Nu_totevt = qq_WW_2L2Nu_sumevt->Integral();
int qq_WZ_2L2Q_totevt = qq_WZ_2L2Q_sumevt->Integral();
int qq_WZ_3LNu_totevt = qq_WZ_3LNu_sumevt->Integral();
int qq_ZZ_2L2Nu_totevt = qq_ZZ_2L2Nu_sumevt->Integral();
int qq_ZZ_2L2Q_totevt = qq_ZZ_2L2Q_sumevt->Integral();
int qq_ZZ_4L_totevt = qq_ZZ_4L_sumevt->Integral();

//---------------------
// Define Diboson Weight
//---------------------
double diboson_gg_ZZ_2e2mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2mu / (gg_ZZ_2e2mu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2e2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2nu / (gg_ZZ_2e2nu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2e2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2tau / (gg_ZZ_2e2tau_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2mu2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2nu / (gg_ZZ_2mu2nu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2mu2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2tau / (gg_ZZ_2mu2tau_totevt)) * 1000 * 2;
double diboson_gg_ZZ_4e_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4e / (gg_ZZ_4e_totevt)) * 1000 * 2;
double diboson_gg_ZZ_4mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4mu / (gg_ZZ_4mu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_4tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4tau / (gg_ZZ_4tau_totevt)) * 1000 * 2;
double diboson_gg_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WW_2L2Nu / (gg_WW_2L2Nu_totevt)) * 1000 * 2;
double diboson_qq_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_WW_2L2Nu_totevt)) * 1000 * 2;
double diboson_qq_WZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_2L2Q / (qq_WZ_2L2Q_totevt)) * 1000 * 2;
double diboson_qq_WZ_3LNu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_3LNu / (qq_WZ_3LNu_totevt)) * 1000 * 2;
double diboson_qq_ZZ_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_ZZ_2L2Nu_totevt)) * 1000 * 2;
double diboson_qq_ZZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Q / (qq_ZZ_2L2Q_totevt)) * 1000 * 2;
double diboson_qq_ZZ_4L_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_4L / (qq_ZZ_4L_totevt)) * 1000 * 2;

vector<double> v_xs_Weight = {diboson_gg_ZZ_2e2mu_Weight, diboson_gg_ZZ_2e2nu_Weight, diboson_gg_ZZ_2e2tau_Weight,
                              diboson_gg_ZZ_2mu2nu_Weight, diboson_gg_ZZ_2mu2tau_Weight, diboson_gg_ZZ_4e_Weight, diboson_gg_ZZ_4mu_Weight,
                              diboson_gg_ZZ_4tau_Weight, diboson_gg_WW_2L2Nu_Weight, diboson_qq_WW_2L2Nu_Weight, diboson_qq_WZ_2L2Q_Weight, diboson_qq_WZ_3LNu_Weight, diboson_qq_ZZ_2L2Nu_Weight, diboson_qq_ZZ_2L2Q_Weight, diboson_qq_ZZ_4L_Weight};
vector<const char *> v_diboson_filename = {"diboson_gg_ZZ_2e2mu", "diboson_gg_ZZ_2e2nu", "diboson_gg_ZZ_2e2tau",
                                           "diboson_gg_ZZ_2mu2nu", "diboson_gg_ZZ_2mu2tau", "diboson_gg_ZZ_4e", "diboson_gg_ZZ_4mu",
                                           "diboson_gg_ZZ_4tau", "diboson_gg_WW_2L2Nu", "diboson_qq_WW_2L2Nu", "diboson_qq_WZ_2L2Q", "diboson_qq_WZ_3LNu", "diboson_qq_ZZ_2L2Nu", "diboson_qq_ZZ_2L2Q", "diboson_qq_ZZ_4L"};
double getWeight(const char *file_name_tmp)
{
    TString file_name = file_name_tmp;
    for (int i = 0; i < v_diboson_filename.size(); i++)
    {
        if (file_name.Contains(v_diboson_filename[i]))
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
void ee_Diboson_half(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *Dibosonfile = TFile::Open(file);
    cout << "Diboson weight = " << getWeight(file) << endl;
    //--------------------------------------------------------------
    // Hist: 0 : |eta| < 1, 1 : 1 < |eta| < 2, 2 : 2 < |eta| < 2.5
    //--------------------------------------------------------------
    TH1D *h_Diboson_nTrk_difeta[3];
    TH1D *h_Diboson_nTrk_cut_difeta[3];
    TH1D *h_Diboson_nTrk_bjet_difeta[3];
    TH1D *h_Diboson_nTrk_bjet_cut_difeta[3];
    TH1D *h_Diboson_nTrk_cjet_difeta[3];
    TH1D *h_Diboson_nTrk_cjet_cut_difeta[3];
    TH1D *h_Diboson_nTrk_ljet_difeta[3];
    TH1D *h_Diboson_nTrk_ljet_cut_difeta[3];
    TH1D *h_Diboson_nTrk_hjet_difeta[3];
    TH1D *h_Diboson_nTrk_hjet_cut_difeta[3];

    for (int i = 0; i < 3; i++)
    {
        h_Diboson_nTrk_difeta[i] = new TH1D(Form("h_Diboson_nTrk_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_cut_difeta[i] = new TH1D(Form("h_Diboson_nTrk_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_bjet_difeta[i] = new TH1D(Form("h_Diboson_nTrk_bjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_bjet_cut_difeta[i] = new TH1D(Form("h_Diboson_nTrk_bjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_cjet_difeta[i] = new TH1D(Form("h_Diboson_nTrk_cjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_cjet_cut_difeta[i] = new TH1D(Form("h_Diboson_nTrk_cjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_ljet_difeta[i] = new TH1D(Form("h_Diboson_nTrk_ljet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_ljet_cut_difeta[i] = new TH1D(Form("h_Diboson_nTrk_ljet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_hjet_difeta[i] = new TH1D(Form("h_Diboson_nTrk_hjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_hjet_cut_difeta[i] = new TH1D(Form("h_Diboson_nTrk_hjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Diboson_nTrk_difeta[i]->Sumw2();
        h_Diboson_nTrk_cut_difeta[i]->Sumw2();
        h_Diboson_nTrk_bjet_difeta[i]->Sumw2();
        h_Diboson_nTrk_bjet_cut_difeta[i]->Sumw2();
        h_Diboson_nTrk_cjet_difeta[i]->Sumw2();
        h_Diboson_nTrk_cjet_cut_difeta[i]->Sumw2();
        h_Diboson_nTrk_ljet_difeta[i]->Sumw2();
        h_Diboson_nTrk_ljet_cut_difeta[i]->Sumw2();
        h_Diboson_nTrk_hjet_difeta[i]->Sumw2();
        h_Diboson_nTrk_hjet_cut_difeta[i]->Sumw2();
    }
    //-----------------------------
    // Not consider eta
    //-----------------------------
    TH1D *h_Diboson_nTrk_bjet = new TH1D("h_Diboson_nTrk_bjet", "", 30, 1, 30);
    TH1D *h_Diboson_nTrk_bjet_cut = new TH1D("h_Diboson_nTrk_bjet_cut", "", 30, 1, 30);
    TH1D *h_Diboson_nTrk_cjet = new TH1D("h_Diboson_nTrk_cjet", "", 30, 1, 30);
    TH1D *h_Diboson_nTrk_cjet_cut = new TH1D("h_Diboson_nTrk_cjet_cut", "", 30, 1, 30);
    TH1D *h_Diboson_nTrk_ljet = new TH1D("h_Diboson_nTrk_ljet", "", 30, 1, 30);
    TH1D *h_Diboson_nTrk_ljet_cut = new TH1D("h_Diboson_nTrk_ljet_cut", "", 30, 1, 30);
    TH1D *h_Diboson_nTrk_hjet = new TH1D("h_Diboson_nTrk_hjet", "", 30, 1, 30);
    TH1D *h_Diboson_nTrk_hjet_cut = new TH1D("h_Diboson_nTrk_hjet_cut", "", 30, 1, 30);
    h_Diboson_nTrk_bjet->Sumw2();
    h_Diboson_nTrk_bjet_cut->Sumw2();
    h_Diboson_nTrk_cjet->Sumw2();
    h_Diboson_nTrk_cjet_cut->Sumw2();
    h_Diboson_nTrk_ljet->Sumw2();
    h_Diboson_nTrk_ljet_cut->Sumw2();
    h_Diboson_nTrk_hjet->Sumw2();
    h_Diboson_nTrk_hjet_cut->Sumw2();
    //-----------------------------
    // Not consider flavor
    //-----------------------------
    TH1D *h_Diboson_nTrk = new TH1D("h_Diboson_nTrk", "", 30, 1, 30);
    TH1D *h_Diboson_nTrk_cut = new TH1D("h_Diboson_nTrk_cut", "", 30, 1, 30);
    h_Diboson_nTrk->Sumw2();
    h_Diboson_nTrk_cut->Sumw2();

    Int_t I_Diboson_nJets;

    Int_t I_Diboson_weight;

    float_t f_Diboson_met;

    vector<float> *v_Diboson_alpha = new vector<float>();
    vector<float> *v_Diboson_Chi3Dlog = new vector<float>();
    vector<float> *v_Diboson_2DIP = new vector<float>();
    vector<float> *v_Diboson_nTrack = new vector<float>();
    vector<float> *v_Diboson_Jethadronflavor = new vector<float>();
    vector<float> *v_Diboson_Jetpartonflavor = new vector<float>();
    vector<float> *v_Diboson_JetPT = new vector<float>();
    vector<float> *v_Diboson_JetEta = new vector<float>();

    v_Diboson_alpha->clear();
    v_Diboson_Chi3Dlog->clear();
    v_Diboson_2DIP->clear();
    v_Diboson_nTrack->clear();
    v_Diboson_Jethadronflavor->clear();
    v_Diboson_Jetpartonflavor->clear();
    v_Diboson_JetPT->clear();
    v_Diboson_JetEta->clear();

    TTree *T_Diboson_tree;
    Dibosonfile->GetObject("h1", T_Diboson_tree);
    T_Diboson_tree->SetBranchAddress("I_weight", &I_Diboson_weight);
    T_Diboson_tree->SetBranchAddress("I_nJets", &I_Diboson_nJets);
    T_Diboson_tree->SetBranchAddress("v_N_Tracks", &v_Diboson_nTrack);
    T_Diboson_tree->SetBranchAddress("f_Met", &f_Diboson_met);
    T_Diboson_tree->SetBranchAddress("v_IP2D", &v_Diboson_2DIP);
    T_Diboson_tree->SetBranchAddress("v_Chi3Dlog", &v_Diboson_Chi3Dlog);
    T_Diboson_tree->SetBranchAddress("v_fakealpha", &v_Diboson_alpha);
    T_Diboson_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Diboson_Jethadronflavor);
    T_Diboson_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Diboson_Jetpartonflavor);
    T_Diboson_tree->SetBranchAddress("v_fakeJetPt", &v_Diboson_JetPT);
    T_Diboson_tree->SetBranchAddress("v_fakeJetEta", &v_Diboson_JetEta);
    for (int evt = 0; evt < T_Diboson_tree->GetEntries(); evt++)
    {
        T_Diboson_tree->GetEntry(evt);
        if (f_Diboson_met < 0)
        {
            continue;
        }
        double Diboson_weight = getWeight(file) * I_Diboson_weight;
        // double Diboson_weight = 1.;
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_Diboson_nTrack->size(); i++)
        {
            // Not Consider eta
            h_Diboson_nTrk->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
            //  For b jet
            for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_bjet);
            // For c jet
            for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_cjet);
            // For light flavor
            for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_ljet);
            // For heavy flavor
            for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_hjet);
            if ((*v_Diboson_alpha)[i] < 0.1)
            {
                // Not Consider eta
                h_Diboson_nTrk_cut->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                //  For b jet
                for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_cjet_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_ljet_cut);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_hjet_cut);
            }
            //--------------------
            // Consider eta
            //--------------------
            //  For Region |eta| < 1
            if (abs((*v_Diboson_JetEta)[i]) < 1)
            {
                // Not consider flavor
                h_Diboson_nTrk_difeta[0]->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_bjet_difeta[0]);
                // For c jet
                for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_cjet_difeta[0]);
                // For light flavor
                for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_ljet_difeta[0]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_hjet_difeta[0]);
                // For SR cut
                if ((*v_Diboson_alpha)[i] < 0.1)
                {
                    // Not consider flavor
                    h_Diboson_nTrk_cut_difeta[0]->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_bjet_cut_difeta[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_cjet_cut_difeta[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_ljet_cut_difeta[0]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_hjet_cut_difeta[0]);
                }
            }
            // For Region 1 < |eta| < 2
            else if (abs((*v_Diboson_JetEta)[i]) > 1 && abs((*v_Diboson_JetEta)[i]) < 2)
            {
                // Not consider flavor
                h_Diboson_nTrk_difeta[1]->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_bjet_difeta[1]);
                // For c jet
                for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_cjet_difeta[1]);
                // For light flavor
                for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_ljet_difeta[1]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_hjet_difeta[1]);
                // For SR cut
                if ((*v_Diboson_alpha)[i] < 0.1)
                {
                    // Not consider flavor
                    h_Diboson_nTrk_cut_difeta[1]->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_bjet_cut_difeta[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_cjet_cut_difeta[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_ljet_cut_difeta[1]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_hjet_cut_difeta[1]);
                }
            }
            // For Region 2 < |eta| < 2.5
            else if (abs((*v_Diboson_JetEta)[i]) > 2 && abs((*v_Diboson_JetEta)[i]) < 2.5)
            {
                // Not consider flavor
                h_Diboson_nTrk_difeta[2]->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                // For b jet
                for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_bjet_difeta[2]);
                // For c jet
                for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_cjet_difeta[2]);
                // For light flavor
                for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_ljet_difeta[2]);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_hjet_difeta[2]);

                // For SR cut
                if ((*v_Diboson_alpha)[i] < 0.1)
                {
                    // Not consider flavor
                    h_Diboson_nTrk_cut_difeta[2]->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                    // For b jet
                    for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_bjet_cut_difeta[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_cjet_cut_difeta[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_ljet_cut_difeta[2]);
                    // For heavy flavor
                    for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_Diboson_nTrk_hjet_cut_difeta[2]);
                }
            }
        }
    } // End of Diboson loop

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    for (int i = 0; i < 3; i++)
    {
        h_Diboson_nTrk_difeta[i]->Write();
        h_Diboson_nTrk_cut_difeta[i]->Write();
        h_Diboson_nTrk_bjet_difeta[i]->Write();
        h_Diboson_nTrk_bjet_cut_difeta[i]->Write();
        h_Diboson_nTrk_cjet_difeta[i]->Write();
        h_Diboson_nTrk_cjet_cut_difeta[i]->Write();
        h_Diboson_nTrk_ljet_difeta[i]->Write();
        h_Diboson_nTrk_ljet_cut_difeta[i]->Write();
        h_Diboson_nTrk_hjet_difeta[i]->Write();
        h_Diboson_nTrk_hjet_cut_difeta[i]->Write();
    }
    h_Diboson_nTrk_bjet->Write();
    h_Diboson_nTrk_bjet_cut->Write();
    h_Diboson_nTrk_cjet->Write();
    h_Diboson_nTrk_cjet_cut->Write();
    h_Diboson_nTrk_ljet->Write();
    h_Diboson_nTrk_ljet_cut->Write();
    h_Diboson_nTrk_hjet->Write();
    h_Diboson_nTrk_hjet_cut->Write();
    h_Diboson_nTrk->Write();
    h_Diboson_nTrk_cut->Write();

    outfile->Close();

    // cout << getWeight(file) << endl;
    // cout << "TTTo2L2NuWeight = " << TTTo2L2NuWeight << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_Diboson_half();
    }
    else if (argc == 3)
    {
        ee_Diboson_half(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}