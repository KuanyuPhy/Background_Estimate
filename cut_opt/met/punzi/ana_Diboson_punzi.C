#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TLine.h>
#include "./../../../lib/Cross_section.h"
using namespace std;

TFile *diboson_gg_ZZ_2e2mu = TFile::Open("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_gg_ZZ_2e2mu.root");
TFile *diboson_gg_ZZ_2e2nu = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_gg_ZZ_2e2nu.root");
TFile *diboson_gg_ZZ_2e2tau = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_gg_ZZ_2e2tau.root");
TFile *diboson_gg_ZZ_2mu2nu = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_gg_ZZ_2mu2nu.root");
TFile *diboson_gg_ZZ_2mu2tau = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_gg_ZZ_2mu2tau.root");
TFile *diboson_gg_ZZ_4e = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_gg_ZZ_4e.root");
TFile *diboson_gg_ZZ_4mu = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_gg_ZZ_4mu.root");
TFile *diboson_gg_ZZ_4tau = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_gg_ZZ_4tau.root");
TFile *diboson_gg_WW_2L2Nu = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_gg_WW_2L2Nu.root");
TFile *diboson_qq_WW_2L2Nu = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_qq_WW_2L2Nu.root");
TFile *diboson_qq_WZ_2L2Q = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_qq_WZ_2L2Q.root");
TFile *diboson_qq_WZ_3LNu = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_qq_WZ_3LNu.root");
TFile *diboson_qq_ZZ_2L2Nu = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_qq_ZZ_2L2Nu.root");
TFile *diboson_qq_ZZ_2L2Q = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_qq_ZZ_2L2Q.root");
TFile *diboson_qq_ZZ_4L = new TFile("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/uu_diboson_qq_ZZ_4L.root");

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
double diboson_gg_ZZ_2e2mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2mu / (gg_ZZ_2e2mu_totevt)) * 1000;
double diboson_gg_ZZ_2e2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2nu / (gg_ZZ_2e2nu_totevt)) * 1000;
double diboson_gg_ZZ_2e2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2tau / (gg_ZZ_2e2tau_totevt)) * 1000;
double diboson_gg_ZZ_2mu2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2nu / (gg_ZZ_2mu2nu_totevt)) * 1000;
double diboson_gg_ZZ_2mu2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2tau / (gg_ZZ_2mu2tau_totevt)) * 1000;
double diboson_gg_ZZ_4e_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4e / (gg_ZZ_4e_totevt)) * 1000;
double diboson_gg_ZZ_4mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4mu / (gg_ZZ_4mu_totevt)) * 1000;
double diboson_gg_ZZ_4tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4tau / (gg_ZZ_4tau_totevt)) * 1000;
double diboson_gg_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_WW_2L2Nu / (gg_WW_2L2Nu_totevt)) * 1000;
double diboson_qq_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WW_2L2Nu / (qq_WW_2L2Nu_totevt)) * 1000;
double diboson_qq_WZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_2L2Q / (qq_WZ_2L2Q_totevt)) * 1000;
double diboson_qq_WZ_3LNu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_3LNu / (qq_WZ_3LNu_totevt)) * 1000;
double diboson_qq_ZZ_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_ZZ_2L2Nu_totevt)) * 1000;
double diboson_qq_ZZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Q / (qq_ZZ_2L2Q_totevt)) * 1000;
double diboson_qq_ZZ_4L_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_4L / (qq_ZZ_4L_totevt)) * 1000;

void ana_Diboson_punzi(const char *scanMet_step = "tmp", TString outputfile = "./output/tmp.root")
{

    //---------------------
    // Met cut
    //---------------------
    float metcut = atoi(scanMet_step) * 10;
    cout << "metcut" << metcut << endl;

    TH1D *h_pass_Bg_nMetcut = new TH1D("h_pass_Bg_nMetcut", "", 50, 0, 50);
    h_pass_Bg_nMetcut->Sumw2();

    Int_t f_gg_ZZ_2e2mu_weight, f_gg_ZZ_2e2nu_weight, f_gg_ZZ_2e2tau_weight, f_gg_ZZ_2mu2nu_weight,
        f_gg_ZZ_2mu2tau_weight, f_gg_ZZ_4e_weight, f_gg_ZZ_4mu_weight, f_gg_ZZ_4tau_weight, f_gg_WW_2L2Nu_weight,
        f_qq_WW_2L2Nu_weight, f_qq_WZ_2L2Q_weight, f_qq_WZ_3LNu_weight, f_qq_ZZ_2L2Nu_weight, f_qq_ZZ_2L2Q_weight,
        f_qq_ZZ_4L_weight;

    float_t f_gg_ZZ_2e2mu_met, f_gg_ZZ_2e2nu_met, f_gg_ZZ_2e2tau_met, f_gg_ZZ_2mu2nu_met,
        f_gg_ZZ_2mu2tau_met, f_gg_ZZ_4e_met, f_gg_ZZ_4mu_met, f_gg_ZZ_4tau_met, f_gg_WW_2L2Nu_met,
        f_qq_WW_2L2Nu_met, f_qq_WZ_2L2Q_met, f_qq_WZ_3LNu_met, f_qq_ZZ_2L2Nu_met, f_qq_ZZ_2L2Q_met,
        f_qq_ZZ_4L_met;

    vector<float> *v_gg_ZZ_2e2mu_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_2e2nu_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_2e2tau_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2nu_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_2mu2tau_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_4e_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_4mu_alpha = new vector<float>();
    vector<float> *v_gg_ZZ_4tau_alpha = new vector<float>();
    vector<float> *v_gg_WW_2L2Nu_alpha = new vector<float>();
    vector<float> *v_qq_WW_2L2Nu_alpha = new vector<float>();
    vector<float> *v_qq_WZ_2L2Q_alpha = new vector<float>();
    vector<float> *v_qq_WZ_3LNu_alpha = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Nu_alpha = new vector<float>();
    vector<float> *v_qq_ZZ_2L2Q_alpha = new vector<float>();
    vector<float> *v_qq_ZZ_4L_alpha = new vector<float>();

    v_gg_ZZ_2e2mu_alpha->clear();
    v_gg_ZZ_2e2nu_alpha->clear();
    v_gg_ZZ_2e2tau_alpha->clear();
    v_gg_ZZ_2mu2nu_alpha->clear();
    v_gg_ZZ_2mu2tau_alpha->clear();
    v_gg_ZZ_4e_alpha->clear();
    v_gg_ZZ_4mu_alpha->clear();
    v_gg_ZZ_4tau_alpha->clear();
    v_gg_WW_2L2Nu_alpha->clear();
    v_qq_WW_2L2Nu_alpha->clear();
    v_qq_WZ_2L2Q_alpha->clear();
    v_qq_WZ_3LNu_alpha->clear();
    v_qq_ZZ_2L2Nu_alpha->clear();
    v_qq_ZZ_2L2Q_alpha->clear();
    v_qq_ZZ_4L_alpha->clear();

    TTree *T_event;
    diboson_gg_ZZ_2e2mu->GetObject("T_tree", T_event);
    T_event->SetBranchAddress("I_weight", &f_gg_ZZ_2e2mu_weight);
    T_event->SetBranchAddress("f_Met", &f_gg_ZZ_2e2mu_met);
    T_event->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2e2mu_alpha);
    for (int evt = 0; evt < T_event->GetEntries(); evt++)
    {
        T_event->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_gg_ZZ_2e2mu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_gg_ZZ_2e2mu_weight * diboson_gg_ZZ_2e2mu_Weight);
        }
    }
    TTree *T_event1;
    diboson_gg_ZZ_2e2nu->GetObject("T_tree", T_event1);
    T_event1->SetBranchAddress("I_weight", &f_gg_ZZ_2e2nu_weight);
    T_event1->SetBranchAddress("f_Met", &f_gg_ZZ_2e2nu_met);
    T_event1->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2e2nu_alpha);
    for (int evt = 0; evt < T_event1->GetEntries(); evt++)
    {
        T_event1->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_gg_ZZ_2e2nu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_gg_ZZ_2e2nu_weight * diboson_gg_ZZ_2e2nu_Weight);
        }
    }
    TTree *T_event2;
    diboson_gg_ZZ_2e2tau->GetObject("T_tree", T_event2);
    T_event2->SetBranchAddress("I_weight", &f_gg_ZZ_2e2tau_weight);
    T_event2->SetBranchAddress("f_Met", &f_gg_ZZ_2e2tau_met);
    T_event2->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2e2tau_alpha);
    for (int evt = 0; evt < T_event2->GetEntries(); evt++)
    {
        T_event2->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_gg_ZZ_2e2tau_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_gg_ZZ_2e2tau_weight * diboson_gg_ZZ_2e2tau_Weight);
        }
    }
    TTree *T_event3;
    diboson_gg_ZZ_2mu2nu->GetObject("T_tree", T_event3);
    T_event3->SetBranchAddress("I_weight", &f_gg_ZZ_2mu2nu_weight);
    T_event3->SetBranchAddress("f_Met", &f_gg_ZZ_2mu2nu_met);
    T_event3->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2mu2nu_alpha);
    for (int evt = 0; evt < T_event3->GetEntries(); evt++)
    {
        T_event3->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_gg_ZZ_2mu2nu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_gg_ZZ_2mu2nu_weight * diboson_gg_ZZ_2mu2nu_Weight);
        }
    }
    TTree *T_event4;
    diboson_gg_ZZ_2mu2tau->GetObject("T_tree", T_event4);
    T_event4->SetBranchAddress("I_weight", &f_gg_ZZ_2mu2tau_weight);
    T_event4->SetBranchAddress("f_Met", &f_gg_ZZ_2mu2tau_met);
    T_event4->SetBranchAddress("v_fakealpha", &v_gg_ZZ_2mu2tau_alpha);
    for (int evt = 0; evt < T_event4->GetEntries(); evt++)
    {
        T_event4->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_gg_ZZ_2mu2tau_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_gg_ZZ_2mu2tau_weight * diboson_gg_ZZ_2mu2tau_Weight);
        }
    }
    TTree *T_event5;
    diboson_gg_ZZ_4e->GetObject("T_tree", T_event5);
    T_event5->SetBranchAddress("I_weight", &f_gg_ZZ_4e_weight);
    T_event5->SetBranchAddress("f_Met", &f_gg_ZZ_4e_met);
    T_event5->SetBranchAddress("v_fakealpha", &v_gg_ZZ_4e_alpha);
    for (int evt = 0; evt < T_event5->GetEntries(); evt++)
    {
        T_event5->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_gg_ZZ_4e_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_gg_ZZ_4e_weight * diboson_gg_ZZ_4e_Weight);
        }
    }
    TTree *T_event6;
    diboson_gg_ZZ_4mu->GetObject("T_tree", T_event6);
    T_event6->SetBranchAddress("I_weight", &f_gg_ZZ_4mu_weight);
    T_event6->SetBranchAddress("f_Met", &f_gg_ZZ_4mu_met);
    T_event6->SetBranchAddress("v_fakealpha", &v_gg_ZZ_4mu_alpha);
    for (int evt = 0; evt < T_event6->GetEntries(); evt++)
    {
        T_event6->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_gg_ZZ_4mu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_gg_ZZ_4mu_weight * diboson_gg_ZZ_4mu_Weight);
        }
    }
    TTree *T_event7;
    diboson_gg_ZZ_4tau->GetObject("T_tree", T_event7);
    T_event7->SetBranchAddress("I_weight", &f_gg_ZZ_4tau_weight);
    T_event7->SetBranchAddress("f_Met", &f_gg_ZZ_4tau_met);
    T_event7->SetBranchAddress("v_fakealpha", &v_gg_ZZ_4tau_alpha);
    for (int evt = 0; evt < T_event7->GetEntries(); evt++)
    {
        T_event7->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_gg_ZZ_4tau_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_gg_ZZ_4tau_weight * diboson_gg_ZZ_4tau_Weight);
        }
    }
    TTree *T_event8;
    diboson_gg_WW_2L2Nu->GetObject("T_tree", T_event8);
    T_event8->SetBranchAddress("I_weight", &f_gg_WW_2L2Nu_weight);
    T_event8->SetBranchAddress("f_Met", &f_gg_WW_2L2Nu_met);
    T_event8->SetBranchAddress("v_fakealpha", &v_gg_WW_2L2Nu_alpha);
    for (int evt = 0; evt < T_event8->GetEntries(); evt++)
    {
        T_event8->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_gg_WW_2L2Nu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_gg_WW_2L2Nu_weight * diboson_gg_WW_2L2Nu_Weight);
        }
    }
    TTree *T_event9;
    diboson_qq_WW_2L2Nu->GetObject("T_tree", T_event9);
    T_event9->SetBranchAddress("I_weight", &f_qq_WW_2L2Nu_weight);
    T_event9->SetBranchAddress("f_Met", &f_qq_WW_2L2Nu_met);
    T_event9->SetBranchAddress("v_fakealpha", &v_qq_WW_2L2Nu_alpha);
    for (int evt = 0; evt < T_event9->GetEntries(); evt++)
    {
        T_event9->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_qq_WW_2L2Nu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_qq_WW_2L2Nu_weight * diboson_qq_WW_2L2Nu_Weight);
        }
    }
    TTree *T_event10;
    diboson_qq_WZ_2L2Q->GetObject("T_tree", T_event10);
    T_event10->SetBranchAddress("I_weight", &f_qq_WZ_2L2Q_weight);
    T_event10->SetBranchAddress("f_Met", &f_qq_WZ_2L2Q_met);
    T_event10->SetBranchAddress("v_fakealpha", &v_qq_WZ_2L2Q_alpha);
    for (int evt = 0; evt < T_event10->GetEntries(); evt++)
    {
        T_event10->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_qq_WZ_2L2Q_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_qq_WZ_2L2Q_weight * diboson_qq_WZ_2L2Q_Weight);
        }
    }
    TTree *T_event11;
    diboson_qq_WZ_3LNu->GetObject("T_tree", T_event11);
    T_event11->SetBranchAddress("I_weight", &f_qq_WZ_3LNu_weight);
    T_event11->SetBranchAddress("f_Met", &f_qq_WZ_3LNu_met);
    T_event11->SetBranchAddress("v_fakealpha", &v_qq_WZ_3LNu_alpha);
    for (int evt = 0; evt < T_event11->GetEntries(); evt++)
    {
        T_event11->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_qq_WZ_3LNu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_qq_WZ_3LNu_weight * diboson_qq_WZ_3LNu_Weight);
        }
    }
    TTree *T_event12;
    diboson_qq_ZZ_2L2Nu->GetObject("T_tree", T_event12);
    T_event12->SetBranchAddress("I_weight", &f_qq_ZZ_2L2Nu_weight);
    T_event12->SetBranchAddress("f_Met", &f_qq_ZZ_2L2Nu_met);
    T_event12->SetBranchAddress("v_fakealpha", &v_qq_ZZ_2L2Nu_alpha);
    for (int evt = 0; evt < T_event12->GetEntries(); evt++)
    {
        T_event12->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_qq_ZZ_2L2Nu_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_qq_ZZ_2L2Nu_weight * diboson_qq_ZZ_2L2Nu_Weight);
        }
    }
    TTree *T_event13;
    diboson_qq_ZZ_2L2Q->GetObject("T_tree", T_event13);
    T_event13->SetBranchAddress("I_weight", &f_qq_ZZ_2L2Q_weight);
    T_event13->SetBranchAddress("f_Met", &f_qq_ZZ_2L2Q_met);
    T_event13->SetBranchAddress("v_fakealpha", &v_qq_ZZ_2L2Q_alpha);
    for (int evt = 0; evt < T_event13->GetEntries(); evt++)
    {
        T_event13->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_qq_ZZ_2L2Q_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_qq_ZZ_2L2Q_weight * diboson_qq_ZZ_2L2Q_Weight);
        }
    }
    TTree *T_event14;
    diboson_qq_ZZ_4L->GetObject("T_tree", T_event14);
    T_event14->SetBranchAddress("I_weight", &f_qq_ZZ_4L_weight);
    T_event14->SetBranchAddress("f_Met", &f_qq_ZZ_4L_met);
    T_event14->SetBranchAddress("v_fakealpha", &v_qq_ZZ_4L_alpha);
    for (int evt = 0; evt < T_event14->GetEntries(); evt++)
    {
        T_event14->GetEntry(evt);
        //-------------------
        // Scan Met
        //-------------------
        if (f_qq_ZZ_4L_met > metcut)
        {
            h_pass_Bg_nMetcut->Fill(atoi(scanMet_step), f_qq_ZZ_4L_weight * diboson_qq_ZZ_4L_Weight);
        }
    }
    TFile *outfile_HT0 = TFile::Open(outputfile, "RECREATE");
    h_pass_Bg_nMetcut->Write();
    outfile_HT0->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        ana_Diboson_punzi(argv[1], argv[2]);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}