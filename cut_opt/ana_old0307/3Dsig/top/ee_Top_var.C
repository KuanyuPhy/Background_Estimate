#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <string>
#include <TCanvas.h>
#include <TAttLine.h>
#include <TStyle.h>
#include "/home/kuanyu/Documents/CMS/Background_Estimate/lib/Cross_section.h"
using namespace std;

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
float TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * ((GlobalConstants::TTTo2L2Nu) / (TTTo2L2Nu_totevt)) * 1000;
float ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000;
float ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000;
float TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000;
float TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000;
float TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000;
float TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000;

void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

void ee_Top_var()
{
    TH1D *h_bg_3DSig = new TH1D("h_bg_3DSig", "", 200, -10., 10.);
    h_bg_3DSig->Sumw2();

    TH1D *h_bg_alpha1 = new TH1D("h_bg_alpha1", "", 20, 0, 1);
    h_bg_alpha1->Sumw2();

    TH1D *h_bg_alpha2 = new TH1D("h_bg_alpha2", "", 20, 0, 1);
    h_bg_alpha2->Sumw2();

    TH1D *h_bg_alpha3 = new TH1D("h_bg_alpha3", "", 20, 0, 1);
    h_bg_alpha3->Sumw2();

    TH1D *h_bg_alpha4 = new TH1D("h_bg_alpha4", "", 20, 0, 1);
    h_bg_alpha4->Sumw2();

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

    v_TTTo2L2Nu_alpha->clear();
    v_ST_tW_top_alpha->clear();
    v_ST_tW_antitop_alpha->clear();
    v_TTWJetsToLNu_alpha->clear();
    v_TTWJetsToQQ_alpha->clear();
    v_TTZToQQ_alpha->clear();
    v_TTZToLLNuNu_alpha->clear();

    vector<float> *v_TTTo2L2Nu_alpha2 = new vector<float>();
    vector<float> *v_ST_tW_top_alpha2 = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha2 = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha2 = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha2 = new vector<float>();
    vector<float> *v_TTZToQQ_alpha2 = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha2 = new vector<float>();

    v_TTTo2L2Nu_alpha2->clear();
    v_ST_tW_top_alpha2->clear();
    v_ST_tW_antitop_alpha2->clear();
    v_TTWJetsToLNu_alpha2->clear();
    v_TTWJetsToQQ_alpha2->clear();
    v_TTZToQQ_alpha2->clear();
    v_TTZToLLNuNu_alpha2->clear();

    vector<float> *v_TTTo2L2Nu_alpha3 = new vector<float>();
    vector<float> *v_ST_tW_top_alpha3 = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha3 = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha3 = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha3 = new vector<float>();
    vector<float> *v_TTZToQQ_alpha3 = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha3 = new vector<float>();

    v_TTTo2L2Nu_alpha3->clear();
    v_ST_tW_top_alpha3->clear();
    v_ST_tW_antitop_alpha3->clear();
    v_TTWJetsToLNu_alpha3->clear();
    v_TTWJetsToQQ_alpha3->clear();
    v_TTZToQQ_alpha3->clear();
    v_TTZToLLNuNu_alpha3->clear();

    vector<float> *v_TTTo2L2Nu_alpha4 = new vector<float>();
    vector<float> *v_ST_tW_top_alpha4 = new vector<float>();
    vector<float> *v_ST_tW_antitop_alpha4 = new vector<float>();
    vector<float> *v_TTWJetsToLNu_alpha4 = new vector<float>();
    vector<float> *v_TTWJetsToQQ_alpha4 = new vector<float>();
    vector<float> *v_TTZToQQ_alpha4 = new vector<float>();
    vector<float> *v_TTZToLLNuNu_alpha4 = new vector<float>();

    v_TTTo2L2Nu_alpha4->clear();
    v_ST_tW_top_alpha4->clear();
    v_ST_tW_antitop_alpha4->clear();
    v_TTWJetsToLNu_alpha4->clear();
    v_TTWJetsToQQ_alpha4->clear();
    v_TTZToQQ_alpha4->clear();
    v_TTZToLLNuNu_alpha4->clear();

    vector<float> *v_TTTo2L2Nu_jetCSV = new vector<float>();
    vector<float> *v_ST_tW_top_jetCSV = new vector<float>();
    vector<float> *v_ST_tW_antitop_jetCSV = new vector<float>();
    vector<float> *v_TTWJetsToLNu_jetCSV = new vector<float>();
    vector<float> *v_TTWJetsToQQ_jetCSV = new vector<float>();
    vector<float> *v_TTZToQQ_jetCSV = new vector<float>();
    vector<float> *v_TTZToLLNuNu_jetCSV = new vector<float>();

    v_TTTo2L2Nu_jetCSV->clear();
    v_ST_tW_top_jetCSV->clear();
    v_ST_tW_antitop_jetCSV->clear();
    v_TTWJetsToLNu_jetCSV->clear();
    v_TTWJetsToQQ_jetCSV->clear();
    v_TTZToQQ_jetCSV->clear();
    v_TTZToLLNuNu_jetCSV->clear();

    vector<float> *v_TTTo2L2Nu_Jethadronflavor = new vector<float>();
    vector<float> *v_ST_tW_top_Jethadronflavor = new vector<float>();
    vector<float> *v_ST_tW_antitop_Jethadronflavor = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Jethadronflavor = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Jethadronflavor = new vector<float>();
    vector<float> *v_TTZToQQ_Jethadronflavor = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Jethadronflavor = new vector<float>();

    v_TTTo2L2Nu_Jethadronflavor->clear();
    v_ST_tW_top_Jethadronflavor->clear();
    v_ST_tW_antitop_Jethadronflavor->clear();
    v_TTWJetsToLNu_Jethadronflavor->clear();
    v_TTWJetsToQQ_Jethadronflavor->clear();
    v_TTZToQQ_Jethadronflavor->clear();
    v_TTZToLLNuNu_Jethadronflavor->clear();

    vector<float> *v_TTTo2L2Nu_log3Dsig = new vector<float>();
    vector<float> *v_ST_tW_top_log3Dsig = new vector<float>();
    vector<float> *v_ST_tW_antitop_log3Dsig = new vector<float>();
    vector<float> *v_TTWJetsToLNu_log3Dsig = new vector<float>();
    vector<float> *v_TTWJetsToQQ_log3Dsig = new vector<float>();
    vector<float> *v_TTZToQQ_log3Dsig = new vector<float>();
    vector<float> *v_TTZToLLNuNu_log3Dsig = new vector<float>();

    v_TTTo2L2Nu_log3Dsig->clear();
    v_ST_tW_top_log3Dsig->clear();
    v_ST_tW_antitop_log3Dsig->clear();
    v_TTWJetsToLNu_log3Dsig->clear();
    v_TTWJetsToQQ_log3Dsig->clear();
    v_TTZToQQ_log3Dsig->clear();
    v_TTZToLLNuNu_log3Dsig->clear();

    double METcut = 0.;

    TTree *T_TTTo2L2Nu_tree;
    TTTo2L2Nufile->GetObject("T_tree", T_TTTo2L2Nu_tree);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_weight", &I_TTTo2L2Nu_weight);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTTo2L2Nu_log3Dsig);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha2", &v_TTTo2L2Nu_alpha2);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha3", &v_TTTo2L2Nu_alpha3);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha4", &v_TTTo2L2Nu_alpha4);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_thinjetCSV", &v_TTTo2L2Nu_jetCSV);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTTo2L2Nu_Jethadronflavor);

    for (int evt = 0; evt < T_TTTo2L2Nu_tree->GetEntries(); evt++)
    {
        T_TTTo2L2Nu_tree->GetEntry(evt);
        /*if (f_TTTo2L2Nu_met < METcut)
        {
            continue;
        }*/
        for (size_t i = 0; i < v_TTTo2L2Nu_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_TTTo2L2Nu_log3Dsig)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
        for (size_t i = 0; i < v_TTTo2L2Nu_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_TTTo2L2Nu_alpha)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_bg_alpha2->Fill((*v_TTTo2L2Nu_alpha2)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_bg_alpha3->Fill((*v_TTTo2L2Nu_alpha3)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_bg_alpha4->Fill((*v_TTTo2L2Nu_alpha4)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
    }
    TTree *T_ST_tW_top_tree;
    Top_tW_topfile->GetObject("T_tree", T_ST_tW_top_tree);
    T_ST_tW_top_tree->SetBranchAddress("I_weight", &I_ST_tW_top_weight);
    T_ST_tW_top_tree->SetBranchAddress("f_Met", &f_ST_tW_top_met);
    T_ST_tW_top_tree->SetBranchAddress("v_Chi3Dlog", &v_ST_tW_top_log3Dsig);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_top_alpha);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha2", &v_ST_tW_top_alpha2);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha3", &v_ST_tW_top_alpha3);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha4", &v_ST_tW_top_alpha4);
    T_ST_tW_top_tree->SetBranchAddress("f_thinjetCSV", &v_ST_tW_top_jetCSV);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_top_Jethadronflavor);

    for (int evt = 0; evt < T_ST_tW_top_tree->GetEntries(); evt++)
    {
        T_ST_tW_top_tree->GetEntry(evt);
        /*if (f_ST_tW_top_met < METcut)
        {
            continue;
        }*/
        for (size_t i = 0; i < v_ST_tW_top_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ST_tW_top_log3Dsig)[i], I_ST_tW_top_weight * ST_tW_topWeight);
        }
        for (size_t i = 0; i < v_ST_tW_top_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ST_tW_top_alpha)[i], I_ST_tW_top_weight * ST_tW_topWeight);
            h_bg_alpha2->Fill((*v_ST_tW_top_alpha2)[i], I_ST_tW_top_weight * ST_tW_topWeight);
            h_bg_alpha3->Fill((*v_ST_tW_top_alpha3)[i], I_ST_tW_top_weight * ST_tW_topWeight);
            h_bg_alpha4->Fill((*v_ST_tW_top_alpha4)[i], I_ST_tW_top_weight * ST_tW_topWeight);
        }
    }
    TTree *T_ST_tW_antitop_tree;
    Top_tW_antitopfile->GetObject("T_tree", T_ST_tW_antitop_tree);
    T_ST_tW_antitop_tree->SetBranchAddress("I_weight", &I_ST_tW_antitop_weight);
    T_ST_tW_antitop_tree->SetBranchAddress("f_Met", &f_ST_tW_antitop_met);
    T_ST_tW_antitop_tree->SetBranchAddress("v_Chi3Dlog", &v_ST_tW_antitop_log3Dsig);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_antitop_alpha);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha2", &v_ST_tW_antitop_alpha2);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha3", &v_ST_tW_antitop_alpha3);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha4", &v_ST_tW_antitop_alpha4);
    T_ST_tW_antitop_tree->SetBranchAddress("f_thinjetCSV", &v_ST_tW_antitop_jetCSV);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_antitop_Jethadronflavor);
    for (int evt = 0; evt < T_ST_tW_antitop_tree->GetEntries(); evt++)
    {
        T_ST_tW_antitop_tree->GetEntry(evt);
        /*if (f_ST_tW_antitop_met < METcut)
        {
            continue;
        }*/
        for (size_t i = 0; i < v_ST_tW_antitop_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ST_tW_antitop_log3Dsig)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
        }
        for (size_t i = 0; i < v_ST_tW_antitop_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ST_tW_antitop_alpha)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
            h_bg_alpha2->Fill((*v_ST_tW_antitop_alpha2)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
            h_bg_alpha3->Fill((*v_ST_tW_antitop_alpha3)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
            h_bg_alpha4->Fill((*v_ST_tW_antitop_alpha4)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
        }
    }
    TTree *T_TTWJetsToLNu_tree;
    Top_TTWJetsToLNufile->GetObject("T_tree", T_TTWJetsToLNu_tree);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_weight", &I_TTWJetsToLNu_weight);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTWJetsToLNu_log3Dsig);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToLNu_alpha);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha2", &v_TTWJetsToLNu_alpha2);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha3", &v_TTWJetsToLNu_alpha3);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha4", &v_TTWJetsToLNu_alpha4);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_thinjetCSV", &v_TTWJetsToLNu_jetCSV);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToLNu_Jethadronflavor);
    for (int evt = 0; evt < T_TTWJetsToLNu_tree->GetEntries(); evt++)
    {
        T_TTWJetsToLNu_tree->GetEntry(evt);
        /*if (f_TTWJetsToLNu_met < METcut)
        {
            continue;
        }*/
        for (size_t i = 0; i < v_TTWJetsToLNu_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_TTWJetsToLNu_log3Dsig)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToLNu_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_TTWJetsToLNu_alpha)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_bg_alpha2->Fill((*v_TTWJetsToLNu_alpha2)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_bg_alpha3->Fill((*v_TTWJetsToLNu_alpha3)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_bg_alpha4->Fill((*v_TTWJetsToLNu_alpha4)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
    }
    TTree *T_TTWJetsToQQ_tree;
    Top_TTWJetsToQQfile->GetObject("T_tree", T_TTWJetsToQQ_tree);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_weight", &I_TTWJetsToQQ_weight);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_Chi3Dlog", &v_TTWJetsToQQ_log3Dsig);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToQQ_alpha);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha2", &v_TTWJetsToQQ_alpha2);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha3", &v_TTWJetsToQQ_alpha3);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha4", &v_TTWJetsToQQ_alpha4);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_thinjetCSV", &v_TTWJetsToQQ_jetCSV);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToQQ_Jethadronflavor);

    for (int evt = 0; evt < T_TTWJetsToQQ_tree->GetEntries(); evt++)
    {
        T_TTWJetsToQQ_tree->GetEntry(evt);
        /*if (f_TTWJetsToQQ_met < METcut)
        {
            continue;
        }*/
        for (size_t i = 0; i < v_TTWJetsToQQ_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_TTWJetsToQQ_log3Dsig)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
        for (size_t i = 0; i < v_TTWJetsToQQ_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_TTWJetsToQQ_alpha)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_bg_alpha2->Fill((*v_TTWJetsToQQ_alpha2)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_bg_alpha3->Fill((*v_TTWJetsToQQ_alpha3)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_bg_alpha4->Fill((*v_TTWJetsToQQ_alpha4)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
    }
    TTree *T_TTZToQQ_tree;
    Top_TTZToQQfile->GetObject("T_tree", T_TTZToQQ_tree);
    T_TTZToQQ_tree->SetBranchAddress("I_weight", &I_TTZToQQ_weight);
    T_TTZToQQ_tree->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_TTZToQQ_tree->SetBranchAddress("v_Chi3Dlog", &v_TTZToQQ_log3Dsig);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTZToQQ_alpha);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha2", &v_TTZToQQ_alpha2);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha3", &v_TTZToQQ_alpha3);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha4", &v_TTZToQQ_alpha4);
    T_TTZToQQ_tree->SetBranchAddress("f_thinjetCSV", &v_TTZToQQ_jetCSV);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToQQ_Jethadronflavor);
    for (int evt = 0; evt < T_TTZToQQ_tree->GetEntries(); evt++)
    {
        T_TTZToQQ_tree->GetEntry(evt);
        /*if (f_TTZToQQ_met < METcut)
        {
            continue;
        }*/
        for (size_t i = 0; i < v_TTZToQQ_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_TTZToQQ_log3Dsig)[i], I_TTZToQQ_weight * TTZToQQWeight);
        }
        for (size_t i = 0; i < v_TTZToQQ_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_TTZToQQ_alpha)[i], I_TTZToQQ_weight * TTZToQQWeight);
            h_bg_alpha2->Fill((*v_TTZToQQ_alpha2)[i], I_TTZToQQ_weight * TTZToQQWeight);
            h_bg_alpha3->Fill((*v_TTZToQQ_alpha3)[i], I_TTZToQQ_weight * TTZToQQWeight);
            h_bg_alpha4->Fill((*v_TTZToQQ_alpha4)[i], I_TTZToQQ_weight * TTZToQQWeight);
        }
    }
    TTree *T_TTZToLLNuNu_tree;
    Top_TTZToLLNuNufile->GetObject("T_tree", T_TTZToLLNuNu_tree);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_weight", &I_TTZToLLNuNu_weight);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_Chi3Dlog", &v_TTZToLLNuNu_log3Dsig);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha", &v_TTZToLLNuNu_alpha);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha2", &v_TTZToLLNuNu_alpha2);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha3", &v_TTZToLLNuNu_alpha3);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha4", &v_TTZToLLNuNu_alpha4);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_thinjetCSV", &v_TTZToLLNuNu_jetCSV);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToLLNuNu_Jethadronflavor);
    for (int evt = 0; evt < T_TTZToLLNuNu_tree->GetEntries(); evt++)
    {
        T_TTZToLLNuNu_tree->GetEntry(evt);
        /*if (f_TTZToLLNuNu_met < METcut)
        {
            continue;
        }*/
        for (size_t i = 0; i < v_TTZToLLNuNu_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_TTZToLLNuNu_log3Dsig)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
        for (size_t i = 0; i < v_TTZToLLNuNu_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_TTZToLLNuNu_alpha)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_bg_alpha2->Fill((*v_TTZToLLNuNu_alpha2)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_bg_alpha3->Fill((*v_TTZToLLNuNu_alpha3)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_bg_alpha4->Fill((*v_TTZToLLNuNu_alpha4)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
    }
    h_bg_3DSig->Draw();
    TString outputfile1 = "./ee_Top_alpha.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_bg_3DSig->Write();
    h_bg_alpha1->Write();
    h_bg_alpha2->Write();
    h_bg_alpha3->Write();
    h_bg_alpha4->Write();
    outfile_HT0->Close();
}
int main()
{
    ee_Top_var();
}
