#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <string>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../../lib/Cross_section.h"
using namespace std;

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
// Define the HTWeight
//---------------------
double HT0Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT0CS) / (HT0_70_event)) * 1000;
double HT70Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::HT70CS) / (HT70_100_event)) * 1000;
double HT100Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT100CS / (DYHT100_totevt + HT100_200_event)) * 1000;
double HT200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT200CS / (DYHT200_totevt + HT200_400_event)) * 1000;
double HT400Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT400CS / (DYHT400_totevt + HT400_600_event)) * 1000;
double HT600Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT600CS / (DYHT600_totevt + HT600_800_event)) * 1000;
double HT800Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT800CS / (DYHT800_totevt + HT800_1200_event)) * 1000;
double HT1200Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT1200CS / (DYHT1200_totevt + HT1200_2500_event)) * 1000;
double HT2500Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::HT2500CS / (DYHT2500_totevt + HT2500_Inf_event)) * 1000;

void for_inclusive_sample(float HT, float i_tmp, double Weight, TH1D *h_tmp)
{
    if (HT < 70)
    {
        h_tmp->Fill(i_tmp, HT0Weight);
    }
    else if (HT >= 70 && HT < 100)
    {
        h_tmp->Fill(i_tmp, HT70Weight);
    }
    else if (HT >= 100 && HT < 200)
    {
        h_tmp->Fill(i_tmp, HT100Weight);
    }
    else if (HT >= 200 && HT < 400)
    {
        h_tmp->Fill(i_tmp, HT200Weight);
    }
    else if (HT >= 400 && HT < 600)
    {
        h_tmp->Fill(i_tmp, HT400Weight);
    }
    else if (HT >= 600 && HT < 800)
    {
        h_tmp->Fill(i_tmp, HT600Weight);
    }
    else if (HT >= 800 && HT < 1200)
    {
        h_tmp->Fill(i_tmp, HT800Weight);
    }
    else if (HT >= 1200 && HT < 2500)
    {
        h_tmp->Fill(i_tmp, HT1200Weight);
    }
    else if (HT >= 2500)
    {
        h_tmp->Fill(i_tmp, HT2500Weight);
    }
}
void for_inclusive_DY_sigle_flavor_jetvar(float HT, int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (HT < 70)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT0Weight);
        }
    }
    else if (HT >= 70 && HT < 100)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT70Weight);
        }
    }
    else if (HT >= 100 && HT < 200)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT100Weight);
        }
    }
    else if (HT >= 200 && HT < 400)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT200Weight);
        }
    }
    else if (HT >= 400 && HT < 600)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT400Weight);
        }
    }
    else if (HT >= 600 && HT < 800)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT600Weight);
        }
    }
    else if (HT >= 800 && HT < 1200)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT800Weight);
        }
    }
    else if (HT >= 1200 && HT < 2500)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT1200Weight);
        }
    }
    else if (HT >= 2500)
    {
        if (hadronflavor == flavor)
        {
            h_tmp->Fill(tmp, Weight * HT2500Weight);
        }
    }
}
void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

void ee_HT_var()
{
    TH1D *h_DY_Met = new TH1D("h_DY_Met", "", 50, 0, 500);
    h_DY_Met->Sumw2();

    TH1D *h_DY_Met_cut = new TH1D("h_DY_Met_cut", "", 50, 0, 500);
    h_DY_Met_cut->Sumw2();

    TH1D *h_bg_3DSig = new TH1D("h_bg_3DSig", "", 20, -5, 5);
    h_bg_3DSig->Sumw2();

    TH1D *h_bg_alpha1 = new TH1D("h_bg_alpha1", "", 20, 0, 1);
    h_bg_alpha1->Sumw2();

    TH1D *h_bg_alpha2 = new TH1D("h_bg_alpha2", "", 20, 0, 1);
    h_bg_alpha2->Sumw2();

    TH1D *h_bg_alpha3 = new TH1D("h_bg_alpha3", "", 20, 0, 1);
    h_bg_alpha3->Sumw2();

    TH1D *h_bg_alpha4 = new TH1D("h_bg_alpha4", "", 20, 0, 1);
    h_bg_alpha4->Sumw2();

    float_t HT;

    float_t f_ht0_Met, f_ht70_Met, f_ht100_Met, f_ht200_Met, f_ht400_Met, f_ht600_Met, f_ht800_Met,
        f_ht1200_Met, f_ht2500_Met;

    Int_t I_ht0_weight, I_ht70_weight, I_ht100_weight, I_ht200_weight, I_ht400_weight, I_ht600_weight,
        I_ht800_weight, I_ht1200_weight, I_ht2500_weight;

    vector<float> *v_ht0_alpha = new vector<float>();
    vector<float> *v_ht100_alpha = new vector<float>();
    vector<float> *v_ht200_alpha = new vector<float>();
    vector<float> *v_ht400_alpha = new vector<float>();
    vector<float> *v_ht600_alpha = new vector<float>();
    vector<float> *v_ht800_alpha = new vector<float>();
    vector<float> *v_ht1200_alpha = new vector<float>();
    vector<float> *v_ht2500_alpha = new vector<float>();

    v_ht0_alpha->clear();
    v_ht100_alpha->clear();
    v_ht200_alpha->clear();
    v_ht400_alpha->clear();
    v_ht600_alpha->clear();
    v_ht800_alpha->clear();
    v_ht1200_alpha->clear();
    v_ht2500_alpha->clear();

    vector<float> *v_ht0_alpha2 = new vector<float>();
    vector<float> *v_ht100_alpha2 = new vector<float>();
    vector<float> *v_ht200_alpha2 = new vector<float>();
    vector<float> *v_ht400_alpha2 = new vector<float>();
    vector<float> *v_ht600_alpha2 = new vector<float>();
    vector<float> *v_ht800_alpha2 = new vector<float>();
    vector<float> *v_ht1200_alpha2 = new vector<float>();
    vector<float> *v_ht2500_alpha2 = new vector<float>();

    v_ht0_alpha2->clear();
    v_ht100_alpha2->clear();
    v_ht200_alpha2->clear();
    v_ht400_alpha2->clear();
    v_ht600_alpha2->clear();
    v_ht800_alpha2->clear();
    v_ht1200_alpha2->clear();
    v_ht2500_alpha2->clear();

    vector<float> *v_ht0_alpha3 = new vector<float>();
    vector<float> *v_ht100_alpha3 = new vector<float>();
    vector<float> *v_ht200_alpha3 = new vector<float>();
    vector<float> *v_ht400_alpha3 = new vector<float>();
    vector<float> *v_ht600_alpha3 = new vector<float>();
    vector<float> *v_ht800_alpha3 = new vector<float>();
    vector<float> *v_ht1200_alpha3 = new vector<float>();
    vector<float> *v_ht2500_alpha3 = new vector<float>();

    v_ht0_alpha3->clear();
    v_ht100_alpha3->clear();
    v_ht200_alpha3->clear();
    v_ht400_alpha3->clear();
    v_ht600_alpha3->clear();
    v_ht800_alpha3->clear();
    v_ht1200_alpha3->clear();
    v_ht2500_alpha3->clear();

    vector<float> *v_ht0_alpha4 = new vector<float>();
    vector<float> *v_ht100_alpha4 = new vector<float>();
    vector<float> *v_ht200_alpha4 = new vector<float>();
    vector<float> *v_ht400_alpha4 = new vector<float>();
    vector<float> *v_ht600_alpha4 = new vector<float>();
    vector<float> *v_ht800_alpha4 = new vector<float>();
    vector<float> *v_ht1200_alpha4 = new vector<float>();
    vector<float> *v_ht2500_alpha4 = new vector<float>();

    v_ht0_alpha4->clear();
    v_ht100_alpha4->clear();
    v_ht200_alpha4->clear();
    v_ht400_alpha4->clear();
    v_ht600_alpha4->clear();
    v_ht800_alpha4->clear();
    v_ht1200_alpha4->clear();
    v_ht2500_alpha4->clear();

    vector<float> *v_ht0_jetcsv = new vector<float>();
    vector<float> *v_ht70_jetcsv = new vector<float>();
    vector<float> *v_ht100_jetcsv = new vector<float>();
    vector<float> *v_ht200_jetcsv = new vector<float>();
    vector<float> *v_ht400_jetcsv = new vector<float>();
    vector<float> *v_ht600_jetcsv = new vector<float>();
    vector<float> *v_ht800_jetcsv = new vector<float>();
    vector<float> *v_ht1200_jetcsv = new vector<float>();
    vector<float> *v_ht2500_jetcsv = new vector<float>();

    v_ht0_jetcsv->clear();
    v_ht70_jetcsv->clear();
    v_ht100_jetcsv->clear();
    v_ht200_jetcsv->clear();
    v_ht400_jetcsv->clear();
    v_ht600_jetcsv->clear();
    v_ht800_jetcsv->clear();
    v_ht1200_jetcsv->clear();
    v_ht2500_jetcsv->clear();

    vector<float> *v_ht0_log3Dsig = new vector<float>();
    vector<float> *v_ht70_log3Dsig = new vector<float>();
    vector<float> *v_ht100_log3Dsig = new vector<float>();
    vector<float> *v_ht200_log3Dsig = new vector<float>();
    vector<float> *v_ht400_log3Dsig = new vector<float>();
    vector<float> *v_ht600_log3Dsig = new vector<float>();
    vector<float> *v_ht800_log3Dsig = new vector<float>();
    vector<float> *v_ht1200_log3Dsig = new vector<float>();
    vector<float> *v_ht2500_log3Dsig = new vector<float>();

    v_ht0_log3Dsig->clear();
    v_ht70_log3Dsig->clear();
    v_ht100_log3Dsig->clear();
    v_ht200_log3Dsig->clear();
    v_ht400_log3Dsig->clear();
    v_ht600_log3Dsig->clear();
    v_ht800_log3Dsig->clear();
    v_ht1200_log3Dsig->clear();
    v_ht2500_log3Dsig->clear();

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

    double metcut = 0.;

    TTree *T_inclusive;
    DYincli->GetObject("T_tree", T_inclusive);
    T_inclusive->SetBranchAddress("I_weight", &I_ht0_weight);
    T_inclusive->SetBranchAddress("f_HT", &HT);
    T_inclusive->SetBranchAddress("f_Met", &f_ht0_Met);
    T_inclusive->SetBranchAddress("v_Chi3Dlog", &v_ht0_log3Dsig);
    T_inclusive->SetBranchAddress("v_fakealpha", &v_ht0_alpha);
    T_inclusive->SetBranchAddress("v_fakealpha2", &v_ht0_alpha2);
    T_inclusive->SetBranchAddress("v_fakealpha3", &v_ht0_alpha3);
    T_inclusive->SetBranchAddress("v_fakealpha4", &v_ht0_alpha4);
    T_inclusive->SetBranchAddress("f_thinjetCSV", &v_ht0_jetcsv);
    T_inclusive->SetBranchAddress("v_fakeJethadronflavor", &v_ht0_Jethadronflavor);
    for (int evt = 0; evt < T_inclusive->GetEntries(); evt++)
    {
        T_inclusive->GetEntry(evt);
        if (f_ht0_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_ht0_log3Dsig->size(); i++)
        {
            for_inclusive_sample(HT, (*v_ht0_log3Dsig)[i], I_ht0_weight, h_bg_3DSig);
        }
        for (size_t i = 0; i < v_ht0_alpha->size(); i++)
        {
            for_inclusive_sample(HT, (*v_ht0_alpha)[i], I_ht0_weight, h_bg_alpha1);
            for_inclusive_sample(HT, (*v_ht0_alpha2)[i], I_ht0_weight, h_bg_alpha2);
            for_inclusive_sample(HT, (*v_ht0_alpha3)[i], I_ht0_weight, h_bg_alpha3);
            for_inclusive_sample(HT, (*v_ht0_alpha4)[i], I_ht0_weight, h_bg_alpha4);
        }
    }
    TTree *T_HT100;
    DYHT100->GetObject("T_tree", T_HT100);
    T_HT100->SetBranchAddress("I_weight", &I_ht100_weight);
    T_HT100->SetBranchAddress("f_Met", &f_ht100_Met);
    T_HT100->SetBranchAddress("v_Chi3Dlog", &v_ht100_log3Dsig);
    T_HT100->SetBranchAddress("v_fakealpha", &v_ht100_alpha);
    T_HT100->SetBranchAddress("v_fakealpha2", &v_ht100_alpha2);
    T_HT100->SetBranchAddress("v_fakealpha3", &v_ht100_alpha3);
    T_HT100->SetBranchAddress("v_fakealpha4", &v_ht100_alpha4);
    T_HT100->SetBranchAddress("f_thinjetCSV", &v_ht100_jetcsv);
    T_HT100->SetBranchAddress("v_fakeJethadronflavor", &v_ht100_Jethadronflavor);
    for (int evt = 0; evt < T_HT100->GetEntries(); evt++)
    {
        T_HT100->GetEntry(evt);
        if (f_ht100_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_ht100_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ht100_log3Dsig)[i], I_ht100_weight * HT100Weight);
        }
        for (size_t i = 0; i < v_ht100_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ht100_alpha)[i], I_ht100_weight * HT100Weight);
            h_bg_alpha2->Fill((*v_ht100_alpha2)[i], I_ht100_weight * HT100Weight);
            h_bg_alpha3->Fill((*v_ht100_alpha3)[i], I_ht100_weight * HT100Weight);
            h_bg_alpha4->Fill((*v_ht100_alpha4)[i], I_ht100_weight * HT100Weight);
        }
    }
    TTree *T_HT200;
    DYHT200->GetObject("T_tree", T_HT200);
    T_HT200->SetBranchAddress("I_weight", &I_ht200_weight);
    T_HT200->SetBranchAddress("f_Met", &f_ht200_Met);
    T_HT200->SetBranchAddress("v_Chi3Dlog", &v_ht200_log3Dsig);
    T_HT200->SetBranchAddress("v_fakealpha", &v_ht200_alpha);
    T_HT200->SetBranchAddress("v_fakealpha2", &v_ht200_alpha2);
    T_HT200->SetBranchAddress("v_fakealpha3", &v_ht200_alpha3);
    T_HT200->SetBranchAddress("v_fakealpha4", &v_ht200_alpha4);
    T_HT200->SetBranchAddress("f_thinjetCSV", &v_ht200_jetcsv);
    T_HT200->SetBranchAddress("v_fakeJethadronflavor", &v_ht200_Jethadronflavor);
    for (int evt = 0; evt < T_HT200->GetEntries(); evt++)
    {
        T_HT200->GetEntry(evt);
        if (f_ht200_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_ht200_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ht200_log3Dsig)[i], I_ht200_weight * HT200Weight);
        }
        for (size_t i = 0; i < v_ht200_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ht200_alpha)[i], I_ht200_weight * HT200Weight);
            h_bg_alpha2->Fill((*v_ht200_alpha2)[i], I_ht200_weight * HT200Weight);
            h_bg_alpha3->Fill((*v_ht200_alpha3)[i], I_ht200_weight * HT200Weight);
            h_bg_alpha4->Fill((*v_ht200_alpha4)[i], I_ht200_weight * HT200Weight);
        }
    }
    TTree *T_HT400;
    DYHT400->GetObject("T_tree", T_HT400);
    T_HT400->SetBranchAddress("I_weight", &I_ht400_weight);
    T_HT400->SetBranchAddress("f_Met", &f_ht400_Met);
    T_HT400->SetBranchAddress("v_Chi3Dlog", &v_ht400_log3Dsig);
    T_HT400->SetBranchAddress("v_fakealpha", &v_ht400_alpha);
    T_HT400->SetBranchAddress("v_fakealpha2", &v_ht400_alpha2);
    T_HT400->SetBranchAddress("v_fakealpha3", &v_ht400_alpha3);
    T_HT400->SetBranchAddress("v_fakealpha4", &v_ht400_alpha4);
    T_HT400->SetBranchAddress("f_thinjetCSV", &v_ht400_jetcsv);
    T_HT400->SetBranchAddress("v_fakeJethadronflavor", &v_ht400_Jethadronflavor);
    for (int evt = 0; evt < T_HT400->GetEntries(); evt++)
    {
        T_HT400->GetEntry(evt);
        if (f_ht400_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_ht400_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ht400_log3Dsig)[i], I_ht400_weight * HT400Weight);
        }
        for (size_t i = 0; i < v_ht400_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ht400_alpha)[i], I_ht400_weight * HT400Weight);
            h_bg_alpha2->Fill((*v_ht400_alpha2)[i], I_ht400_weight * HT400Weight);
            h_bg_alpha3->Fill((*v_ht400_alpha3)[i], I_ht400_weight * HT400Weight);
            h_bg_alpha4->Fill((*v_ht400_alpha4)[i], I_ht400_weight * HT400Weight);
        }
    }
    TTree *T_HT600;
    DYHT600->GetObject("T_tree", T_HT600);
    T_HT600->SetBranchAddress("I_weight", &I_ht600_weight);
    T_HT600->SetBranchAddress("f_Met", &f_ht600_Met);
    T_HT600->SetBranchAddress("v_Chi3Dlog", &v_ht600_log3Dsig);
    T_HT600->SetBranchAddress("v_fakealpha", &v_ht600_alpha);
    T_HT600->SetBranchAddress("v_fakealpha2", &v_ht600_alpha2);
    T_HT600->SetBranchAddress("v_fakealpha3", &v_ht600_alpha3);
    T_HT600->SetBranchAddress("v_fakealpha4", &v_ht600_alpha4);
    T_HT600->SetBranchAddress("f_thinjetCSV", &v_ht600_jetcsv);
    T_HT600->SetBranchAddress("v_fakeJethadronflavor", &v_ht600_Jethadronflavor);
    for (int evt = 0; evt < T_HT600->GetEntries(); evt++)
    {
        T_HT600->GetEntry(evt);
        if (f_ht600_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_ht600_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ht600_log3Dsig)[i], I_ht600_weight * HT600Weight);
        }
        for (size_t i = 0; i < v_ht600_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ht600_alpha)[i], I_ht600_weight * HT600Weight);
            h_bg_alpha2->Fill((*v_ht600_alpha2)[i], I_ht600_weight * HT600Weight);
            h_bg_alpha3->Fill((*v_ht600_alpha3)[i], I_ht600_weight * HT600Weight);
            h_bg_alpha4->Fill((*v_ht600_alpha4)[i], I_ht600_weight * HT600Weight);
        }
    }
    TTree *T_HT800;
    DYHT800->GetObject("T_tree", T_HT800);
    T_HT800->SetBranchAddress("I_weight", &I_ht800_weight);
    T_HT800->SetBranchAddress("f_Met", &f_ht800_Met);
    T_HT800->SetBranchAddress("v_Chi3Dlog", &v_ht800_log3Dsig);
    T_HT800->SetBranchAddress("v_fakealpha", &v_ht800_alpha);
    T_HT800->SetBranchAddress("v_fakealpha2", &v_ht800_alpha2);
    T_HT800->SetBranchAddress("v_fakealpha3", &v_ht800_alpha3);
    T_HT800->SetBranchAddress("v_fakealpha4", &v_ht800_alpha4);
    T_HT800->SetBranchAddress("f_thinjetCSV", &v_ht800_jetcsv);
    T_HT800->SetBranchAddress("v_fakeJethadronflavor", &v_ht800_Jethadronflavor);
    for (int evt = 0; evt < T_HT800->GetEntries(); evt++)
    {
        T_HT800->GetEntry(evt);
        if (f_ht800_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_ht800_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ht800_log3Dsig)[i], I_ht800_weight * HT800Weight);
        }
        for (size_t i = 0; i < v_ht600_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ht800_alpha)[i], I_ht800_weight * HT800Weight);
            h_bg_alpha2->Fill((*v_ht800_alpha2)[i], I_ht800_weight * HT800Weight);
            h_bg_alpha3->Fill((*v_ht800_alpha3)[i], I_ht800_weight * HT800Weight);
            h_bg_alpha4->Fill((*v_ht800_alpha4)[i], I_ht800_weight * HT800Weight);
        }
    }
    TTree *T_HT1200;
    DYHT1200->GetObject("T_tree", T_HT1200);
    T_HT1200->SetBranchAddress("I_weight", &I_ht1200_weight);
    T_HT1200->SetBranchAddress("f_Met", &f_ht1200_Met);
    T_HT1200->SetBranchAddress("v_Chi3Dlog", &v_ht1200_log3Dsig);
    T_HT1200->SetBranchAddress("v_fakealpha", &v_ht1200_alpha);
    T_HT1200->SetBranchAddress("v_fakealpha2", &v_ht1200_alpha2);
    T_HT1200->SetBranchAddress("v_fakealpha3", &v_ht1200_alpha3);
    T_HT1200->SetBranchAddress("v_fakealpha4", &v_ht1200_alpha4);
    T_HT1200->SetBranchAddress("f_thinjetCSV", &v_ht1200_jetcsv);
    T_HT1200->SetBranchAddress("v_fakeJethadronflavor", &v_ht1200_Jethadronflavor);
    for (int evt = 0; evt < T_HT1200->GetEntries(); evt++)
    {
        T_HT1200->GetEntry(evt);
        if (f_ht1200_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_ht1200_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ht1200_log3Dsig)[i], I_ht1200_weight * HT1200Weight);
        }
        for (size_t i = 0; i < v_ht1200_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ht1200_alpha)[i], I_ht1200_weight * HT1200Weight);
            h_bg_alpha2->Fill((*v_ht1200_alpha2)[i], I_ht1200_weight * HT1200Weight);
            h_bg_alpha3->Fill((*v_ht1200_alpha3)[i], I_ht1200_weight * HT1200Weight);
            h_bg_alpha4->Fill((*v_ht1200_alpha4)[i], I_ht1200_weight * HT1200Weight);
        }
    }
    TTree *T_HT2500;
    DYHT2500->GetObject("T_tree", T_HT2500);
    T_HT2500->SetBranchAddress("I_weight", &I_ht2500_weight);
    T_HT2500->SetBranchAddress("f_Met", &f_ht2500_Met);
    T_HT2500->SetBranchAddress("v_Chi3Dlog", &v_ht2500_log3Dsig);
    T_HT2500->SetBranchAddress("v_fakealpha", &v_ht2500_alpha);
    T_HT2500->SetBranchAddress("v_fakealpha2", &v_ht2500_alpha2);
    T_HT2500->SetBranchAddress("v_fakealpha3", &v_ht2500_alpha3);
    T_HT2500->SetBranchAddress("v_fakealpha4", &v_ht2500_alpha4);
    T_HT2500->SetBranchAddress("f_thinjetCSV", &v_ht2500_jetcsv);
    T_HT2500->SetBranchAddress("v_fakeJethadronflavor", &v_ht2500_Jethadronflavor);
    for (int evt = 0; evt < T_HT2500->GetEntries(); evt++)
    {
        T_HT2500->GetEntry(evt);
        if (f_ht2500_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_ht2500_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ht2500_log3Dsig)[i], I_ht2500_weight * HT2500Weight);
        }
        for (size_t i = 0; i < v_ht2500_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ht2500_alpha)[i], I_ht2500_weight * HT2500Weight);
            h_bg_alpha2->Fill((*v_ht2500_alpha2)[i], I_ht2500_weight * HT2500Weight);
            h_bg_alpha3->Fill((*v_ht2500_alpha3)[i], I_ht2500_weight * HT2500Weight);
            h_bg_alpha4->Fill((*v_ht2500_alpha4)[i], I_ht2500_weight * HT2500Weight);
        }
    }
    h_bg_3DSig->Draw();
    TString outputfile1 = "./ee_DY_alpha.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_bg_3DSig->Write();
    h_bg_alpha1->Write();
    h_bg_alpha2->Write();
    h_bg_alpha3->Write();
    h_bg_alpha4->Write();
    outfile_HT0->Close();
}