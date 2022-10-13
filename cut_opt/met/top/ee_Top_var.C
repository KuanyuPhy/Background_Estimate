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
#include "./../../../lib/Cross_section.h"
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
    TH1D *h_Top_Met = new TH1D("h_Top_Met", "", 50, 0, 500);
    h_Top_Met->GetXaxis()->SetTitle("");
    h_Top_Met->GetYaxis()->SetTitle("");
    h_Top_Met->Sumw2();

    TH1D *h_Top_dilepPT = new TH1D("h_Top_dilepPT", "", 100, 0, 1000);
    h_Top_dilepPT->GetXaxis()->SetTitle("");
    h_Top_dilepPT->GetYaxis()->SetTitle("");
    h_Top_dilepPT->Sumw2();

    TH1D *h_Top_Met_cut = new TH1D("h_Top_Met_cut", "", 50, 0, 500);
    h_Top_Met_cut->GetXaxis()->SetTitle("");
    h_Top_Met_cut->GetYaxis()->SetTitle("");
    h_Top_Met_cut->Sumw2();

    TH1D *h_Top_jetcsv = new TH1D("h_Top_jetcsv", "", 20, 0, 1);
    h_Top_jetcsv->GetXaxis()->SetTitle("");
    h_Top_jetcsv->GetYaxis()->SetTitle("");
    h_Top_jetcsv->Sumw2();

    TH1D *h_Top_bjetcsv = new TH1D("h_Top_bjetcsv", "", 20, 0, 1);
    h_Top_bjetcsv->GetXaxis()->SetTitle("");
    h_Top_bjetcsv->GetYaxis()->SetTitle("");
    h_Top_bjetcsv->Sumw2();

    TH1D *h_Top_cjetcsv = new TH1D("h_Top_cjetcsv", "", 20, 0, 1);
    h_Top_cjetcsv->GetXaxis()->SetTitle("");
    h_Top_cjetcsv->GetYaxis()->SetTitle("");
    h_Top_cjetcsv->Sumw2();

    TH1D *h_Top_ljetcsv = new TH1D("h_Top_ljetcsv", "", 20, 0, 1);
    h_Top_ljetcsv->GetXaxis()->SetTitle("");
    h_Top_ljetcsv->GetYaxis()->SetTitle("");
    h_Top_ljetcsv->Sumw2();

    TH1D *h_Top_bJetMass = new TH1D("h_Top_bJetMass", "", 50, 0., 150.);
    h_Top_bJetMass->Sumw2();

    TH1D *h_Top_lJetMass = new TH1D("h_Top_lJetMass", "", 50, 0., 150.);
    h_Top_lJetMass->Sumw2();

    // Cut alpha
    TH1D *h_Top_jetcsv_cutalpha = new TH1D("h_Top_jetcsv_cutalpha", "", 20, 0, 1);
    h_Top_jetcsv_cutalpha->Sumw2();

    TH1D *h_Top_bjetcsv_cutalpha = new TH1D("h_Top_bjetcsv_cutalpha", "", 20, 0, 1);
    h_Top_bjetcsv_cutalpha->Sumw2();

    TH1D *h_Top_ljetcsv_cutalpha = new TH1D("h_Top_ljetcsv_cutalpha", "", 20, 0, 1);
    h_Top_ljetcsv_cutalpha->Sumw2();

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

    float_t f_TTTo2L2Nu_dilepPT;
    float_t f_ST_tW_top_dilepPT;
    float_t f_ST_tW_antitop_dilepPT;
    float_t f_TTWJetsToLNu_dilepPT;
    float_t f_TTWJetsToQQ_dilepPT;
    float_t f_TTZToQQ_dilepPT;
    float_t f_TTZToLLNuNu_dilepPT;

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

    vector<float> *v_TTTo2L2Nu_JetMass = new vector<float>();
    vector<float> *v_ST_tW_top_JetMass = new vector<float>();
    vector<float> *v_ST_tW_antitop_JetMass = new vector<float>();
    vector<float> *v_TTWJetsToLNu_JetMass = new vector<float>();
    vector<float> *v_TTWJetsToQQ_JetMass = new vector<float>();
    vector<float> *v_TTZToQQ_JetMass = new vector<float>();
    vector<float> *v_TTZToLLNuNu_JetMass = new vector<float>();

    v_TTTo2L2Nu_JetMass->clear();
    v_ST_tW_top_JetMass->clear();
    v_ST_tW_antitop_JetMass->clear();
    v_TTWJetsToLNu_JetMass->clear();
    v_TTWJetsToQQ_JetMass->clear();
    v_TTZToQQ_JetMass->clear();
    v_TTZToLLNuNu_JetMass->clear();

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

    double METcut = 140.0;

    TTree *T_TTTo2L2Nu_tree;
    TTTo2L2Nufile->GetObject("T_tree", T_TTTo2L2Nu_tree);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_weight", &I_TTTo2L2Nu_weight);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_dileptonPT", &f_TTTo2L2Nu_dilepPT);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakealpha", &v_TTTo2L2Nu_alpha);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJetMass", &v_TTTo2L2Nu_JetMass);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_thinjetCSV", &v_TTTo2L2Nu_jetCSV);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTTo2L2Nu_Jethadronflavor);
    for (int evt = 0; evt < T_TTTo2L2Nu_tree->GetEntries(); evt++)
    {
        T_TTTo2L2Nu_tree->GetEntry(evt);
        h_Top_Met->Fill(f_TTTo2L2Nu_met, I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        if (f_TTTo2L2Nu_met > METcut)
        {
            h_Top_dilepPT->Fill(f_TTTo2L2Nu_dilepPT, I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_Top_Met_cut->Fill(f_TTTo2L2Nu_met, I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            for (size_t i = 0; i < v_TTTo2L2Nu_jetCSV->size(); i++)
            {
                h_Top_jetcsv->Fill((*v_TTTo2L2Nu_jetCSV)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                if ((*v_TTTo2L2Nu_Jethadronflavor)[i] == 5)
                {
                    h_Top_bjetcsv->Fill((*v_TTTo2L2Nu_jetCSV)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_Top_bJetMass->Fill((*v_TTTo2L2Nu_JetMass)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    if (((*v_TTTo2L2Nu_alpha)[i] < 0.15))
                    {
                        h_Top_bjetcsv_cutalpha->Fill((*v_TTTo2L2Nu_jetCSV)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    }
                }
                else if ((*v_TTTo2L2Nu_Jethadronflavor)[i] == 0)
                {
                    h_Top_ljetcsv->Fill((*v_TTTo2L2Nu_jetCSV)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    h_Top_lJetMass->Fill((*v_TTTo2L2Nu_JetMass)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    if (((*v_TTTo2L2Nu_alpha)[i] < 0.15))
                    {
                        h_Top_ljetcsv_cutalpha->Fill((*v_TTTo2L2Nu_jetCSV)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                    }
                }
                if (((*v_TTTo2L2Nu_alpha)[i] < 0.15))
                {
                    h_Top_jetcsv_cutalpha->Fill((*v_TTTo2L2Nu_jetCSV)[i], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
                }
            } // End of csv loop
        }
    }
    TTree *T_ST_tW_top_tree;
    Top_tW_topfile->GetObject("T_tree", T_ST_tW_top_tree);
    T_ST_tW_top_tree->SetBranchAddress("I_weight", &I_ST_tW_top_weight);
    T_ST_tW_top_tree->SetBranchAddress("f_Met", &f_ST_tW_top_met);
    T_ST_tW_top_tree->SetBranchAddress("f_dileptonPT", &f_ST_tW_top_dilepPT);
    T_ST_tW_top_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_top_alpha);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJetMass", &v_ST_tW_top_JetMass);
    T_ST_tW_top_tree->SetBranchAddress("f_thinjetCSV", &v_ST_tW_top_jetCSV);
    T_ST_tW_top_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_top_Jethadronflavor);
    for (int evt = 0; evt < T_ST_tW_top_tree->GetEntries(); evt++)
    {
        T_ST_tW_top_tree->GetEntry(evt);
        h_Top_Met->Fill(f_ST_tW_top_met, I_ST_tW_top_weight * ST_tW_topWeight);
        if (f_ST_tW_top_met > METcut)
        {
            h_Top_dilepPT->Fill(f_ST_tW_top_dilepPT, I_ST_tW_top_weight * ST_tW_topWeight);
            h_Top_Met_cut->Fill(f_ST_tW_top_met, I_ST_tW_top_weight * ST_tW_topWeight);
            for (size_t i = 0; i < v_ST_tW_top_jetCSV->size(); i++)
            {
                h_Top_jetcsv->Fill((*v_ST_tW_top_jetCSV)[i], I_ST_tW_top_weight * ST_tW_topWeight);
                if ((*v_ST_tW_top_Jethadronflavor)[i] == 5)
                {
                    h_Top_bjetcsv->Fill((*v_ST_tW_top_jetCSV)[i], I_ST_tW_top_weight * ST_tW_topWeight);
                    h_Top_bJetMass->Fill((*v_ST_tW_top_JetMass)[i], I_ST_tW_top_weight * ST_tW_topWeight);
                    if (((*v_ST_tW_top_alpha)[i] < 0.15))
                    {
                        h_Top_bjetcsv_cutalpha->Fill((*v_ST_tW_top_jetCSV)[i], I_ST_tW_top_weight * ST_tW_topWeight);
                    }
                }
                else if ((*v_ST_tW_top_Jethadronflavor)[i] == 0)
                {
                    h_Top_ljetcsv->Fill((*v_ST_tW_top_jetCSV)[i], I_ST_tW_top_weight * ST_tW_topWeight);
                    h_Top_lJetMass->Fill((*v_ST_tW_top_JetMass)[i], I_ST_tW_top_weight * ST_tW_topWeight);
                    if (((*v_ST_tW_top_alpha)[i] < 0.15))
                    {
                        h_Top_ljetcsv_cutalpha->Fill((*v_ST_tW_top_jetCSV)[i], I_ST_tW_top_weight * ST_tW_topWeight);
                    }
                }
                if (((*v_ST_tW_top_alpha)[i] < 0.15))
                {
                    h_Top_jetcsv_cutalpha->Fill((*v_ST_tW_top_jetCSV)[i], I_ST_tW_top_weight * ST_tW_topWeight);
                }
            } // End of csv loop
        }
    }
    TTree *T_ST_tW_antitop_tree;
    Top_tW_antitopfile->GetObject("T_tree", T_ST_tW_antitop_tree);
    T_ST_tW_antitop_tree->SetBranchAddress("I_weight", &I_ST_tW_antitop_weight);
    T_ST_tW_antitop_tree->SetBranchAddress("f_Met", &f_ST_tW_antitop_met);
    T_ST_tW_antitop_tree->SetBranchAddress("f_dileptonPT", &f_ST_tW_antitop_dilepPT);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakealpha", &v_ST_tW_antitop_alpha);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJetMass", &v_ST_tW_antitop_JetMass);
    T_ST_tW_antitop_tree->SetBranchAddress("f_thinjetCSV", &v_ST_tW_antitop_jetCSV);
    T_ST_tW_antitop_tree->SetBranchAddress("v_fakeJethadronflavor", &v_ST_tW_antitop_Jethadronflavor);

    for (int evt = 0; evt < T_ST_tW_antitop_tree->GetEntries(); evt++)
    {
        T_ST_tW_antitop_tree->GetEntry(evt);
        h_Top_Met->Fill(f_ST_tW_antitop_met, I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
        if (f_ST_tW_antitop_met > METcut)
        {
            h_Top_dilepPT->Fill(f_ST_tW_antitop_dilepPT, I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
            h_Top_Met_cut->Fill(f_ST_tW_antitop_met, I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
            for (size_t i = 0; i < v_ST_tW_antitop_jetCSV->size(); i++)
            {
                h_Top_jetcsv->Fill((*v_ST_tW_antitop_jetCSV)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
                if ((*v_ST_tW_antitop_Jethadronflavor)[i] == 5)
                {
                    h_Top_bjetcsv->Fill((*v_ST_tW_antitop_jetCSV)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
                    h_Top_bJetMass->Fill((*v_ST_tW_antitop_JetMass)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
                    if (((*v_ST_tW_antitop_alpha)[i] < 0.15))
                    {
                        h_Top_bjetcsv_cutalpha->Fill((*v_ST_tW_antitop_jetCSV)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
                    }
                }
                else if ((*v_ST_tW_antitop_Jethadronflavor)[i] == 0)
                {
                    h_Top_ljetcsv->Fill((*v_ST_tW_antitop_jetCSV)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
                    h_Top_lJetMass->Fill((*v_ST_tW_antitop_JetMass)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
                    if (((*v_ST_tW_antitop_alpha)[i] < 0.15))
                    {
                        h_Top_ljetcsv_cutalpha->Fill((*v_ST_tW_antitop_jetCSV)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
                    }
                }
                if (((*v_ST_tW_antitop_alpha)[i] < 0.15))
                {
                    h_Top_jetcsv_cutalpha->Fill((*v_ST_tW_antitop_jetCSV)[i], I_ST_tW_antitop_weight * I_ST_tW_antitop_weight);
                }
            } // End of csv loop
        }
    }
    TTree *T_TTWJetsToLNu_tree;
    Top_TTWJetsToLNufile->GetObject("T_tree", T_TTWJetsToLNu_tree);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_weight", &I_TTWJetsToLNu_weight);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_dileptonPT", &f_TTWJetsToLNu_dilepPT);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToLNu_alpha);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJetMass", &v_TTWJetsToLNu_JetMass);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_thinjetCSV", &v_TTWJetsToLNu_jetCSV);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToLNu_Jethadronflavor);
    for (int evt = 0; evt < T_TTWJetsToLNu_tree->GetEntries(); evt++)
    {
        T_TTWJetsToLNu_tree->GetEntry(evt);
        h_Top_Met->Fill(f_TTWJetsToLNu_met, I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        if (f_TTWJetsToLNu_met > METcut)
        {
            h_Top_dilepPT->Fill(f_TTWJetsToLNu_dilepPT, I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_Top_Met_cut->Fill(f_TTWJetsToLNu_met, I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            for (size_t i = 0; i < v_TTWJetsToLNu_jetCSV->size(); i++)
            {
                h_Top_jetcsv->Fill((*v_TTWJetsToLNu_jetCSV)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                if ((*v_TTWJetsToLNu_Jethadronflavor)[i] == 5)
                {
                    h_Top_bjetcsv->Fill((*v_TTWJetsToLNu_jetCSV)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    h_Top_bJetMass->Fill((*v_TTWJetsToLNu_JetMass)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    if (((*v_TTWJetsToLNu_alpha)[i] < 0.15))
                    {
                        h_Top_bjetcsv_cutalpha->Fill((*v_TTWJetsToLNu_jetCSV)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    }
                }
                else if ((*v_TTWJetsToLNu_Jethadronflavor)[i] == 0)
                {
                    h_Top_ljetcsv->Fill((*v_TTWJetsToLNu_jetCSV)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    h_Top_lJetMass->Fill((*v_TTWJetsToLNu_JetMass)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    if (((*v_TTWJetsToLNu_alpha)[i] < 0.15))
                    {
                        h_Top_ljetcsv_cutalpha->Fill((*v_TTWJetsToLNu_jetCSV)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                    }
                }
                if (((*v_TTWJetsToLNu_alpha)[i] < 0.15))
                {
                    h_Top_jetcsv_cutalpha->Fill((*v_TTWJetsToLNu_jetCSV)[i], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
                }
            } // End of csv loop
        }
    }
    TTree *T_TTWJetsToQQ_tree;
    Top_TTWJetsToQQfile->GetObject("T_tree", T_TTWJetsToQQ_tree);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_weight", &I_TTWJetsToQQ_weight);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_dileptonPT", &f_TTWJetsToQQ_dilepPT);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTWJetsToQQ_alpha);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJetMass", &v_TTWJetsToQQ_JetMass);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_thinjetCSV", &v_TTWJetsToQQ_jetCSV);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTWJetsToQQ_Jethadronflavor);

    for (int evt = 0; evt < T_TTWJetsToQQ_tree->GetEntries(); evt++)
    {
        T_TTWJetsToQQ_tree->GetEntry(evt);
        h_Top_Met->Fill(f_TTWJetsToQQ_met, I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        if (f_TTWJetsToQQ_met > METcut)
        {
            h_Top_dilepPT->Fill(f_TTWJetsToQQ_dilepPT, I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_Top_Met_cut->Fill(f_TTWJetsToQQ_met, I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            for (size_t i = 0; i < v_TTWJetsToQQ_jetCSV->size(); i++)
            {
                h_Top_jetcsv->Fill((*v_TTWJetsToQQ_jetCSV)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                if ((*v_TTWJetsToQQ_Jethadronflavor)[i] == 5)
                {
                    h_Top_bjetcsv->Fill((*v_TTWJetsToQQ_jetCSV)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    h_Top_bJetMass->Fill((*v_TTWJetsToQQ_JetMass)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    if (((*v_TTWJetsToQQ_alpha)[i] < 0.15))
                    {
                        h_Top_bjetcsv_cutalpha->Fill((*v_TTWJetsToQQ_jetCSV)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    }
                }
                else if ((*v_TTWJetsToQQ_Jethadronflavor)[i] == 0)
                {
                    h_Top_ljetcsv->Fill((*v_TTWJetsToQQ_jetCSV)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    h_Top_lJetMass->Fill((*v_TTWJetsToQQ_JetMass)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    if (((*v_TTWJetsToQQ_alpha)[i] < 0.15))
                    {
                        h_Top_ljetcsv_cutalpha->Fill((*v_TTWJetsToQQ_jetCSV)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                    }
                }
                if (((*v_TTWJetsToQQ_alpha)[i] < 0.15))
                {
                    h_Top_jetcsv_cutalpha->Fill((*v_TTWJetsToQQ_jetCSV)[i], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
                }
            } // End of csv loop
        }
    }
    TTree *T_TTZToQQ_tree;
    Top_TTZToQQfile->GetObject("T_tree", T_TTZToQQ_tree);
    T_TTZToQQ_tree->SetBranchAddress("I_weight", &I_TTZToQQ_weight);
    T_TTZToQQ_tree->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_TTZToQQ_tree->SetBranchAddress("f_dileptonPT", &f_TTZToQQ_dilepPT);
    T_TTZToQQ_tree->SetBranchAddress("v_fakealpha", &v_TTZToQQ_alpha);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJetMass", &v_TTZToQQ_JetMass);
    T_TTZToQQ_tree->SetBranchAddress("f_thinjetCSV", &v_TTZToQQ_jetCSV);
    T_TTZToQQ_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToQQ_Jethadronflavor);
    for (int evt = 0; evt < T_TTZToQQ_tree->GetEntries(); evt++)
    {
        T_TTZToQQ_tree->GetEntry(evt);
        h_Top_Met->Fill(f_TTZToQQ_met, I_TTZToQQ_weight * TTZToQQWeight);
        if (f_TTZToQQ_met > METcut)
        {
            h_Top_dilepPT->Fill(f_TTZToQQ_dilepPT, I_TTZToQQ_weight * TTZToQQWeight);
            h_Top_Met_cut->Fill(f_TTZToQQ_met, I_TTZToQQ_weight * TTZToQQWeight);
            for (size_t i = 0; i < v_TTZToQQ_jetCSV->size(); i++)
            {
                h_Top_jetcsv->Fill((*v_TTZToQQ_jetCSV)[i], I_TTZToQQ_weight * TTZToQQWeight);
                if ((*v_TTZToQQ_Jethadronflavor)[i] == 5)
                {
                    h_Top_bjetcsv->Fill((*v_TTZToQQ_jetCSV)[i], I_TTZToQQ_weight * TTZToQQWeight);
                    h_Top_bJetMass->Fill((*v_TTZToQQ_JetMass)[i], I_TTZToQQ_weight * TTZToQQWeight);
                    if (((*v_TTZToQQ_alpha)[i] < 0.15))
                    {
                        h_Top_bjetcsv_cutalpha->Fill((*v_TTZToQQ_jetCSV)[i], I_TTZToQQ_weight * TTZToQQWeight);
                    }
                }
                else if ((*v_TTZToQQ_Jethadronflavor)[i] == 0)
                {
                    h_Top_ljetcsv->Fill((*v_TTZToQQ_jetCSV)[i], I_TTZToQQ_weight * TTZToQQWeight);
                    h_Top_lJetMass->Fill((*v_TTZToQQ_JetMass)[i], I_TTZToQQ_weight * TTZToQQWeight);
                    if (((*v_TTZToQQ_alpha)[i] < 0.15))
                    {
                        h_Top_ljetcsv_cutalpha->Fill((*v_TTZToQQ_jetCSV)[i], I_TTZToQQ_weight * TTZToQQWeight);
                    }
                }
                if (((*v_TTZToQQ_alpha)[i] < 0.15))
                {
                    h_Top_jetcsv_cutalpha->Fill((*v_TTZToQQ_jetCSV)[i], I_TTZToQQ_weight * TTZToQQWeight);
                }
            } // End of csv loop
        }
    }
    TTree *T_TTZToLLNuNu_tree;
    Top_TTZToLLNuNufile->GetObject("T_tree", T_TTZToLLNuNu_tree);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_weight", &I_TTZToLLNuNu_weight);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_dileptonPT", &f_TTZToLLNuNu_dilepPT);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakealpha", &v_TTZToLLNuNu_alpha);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJetMass", &v_TTZToLLNuNu_JetMass);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_thinjetCSV", &v_TTZToLLNuNu_jetCSV);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_fakeJethadronflavor", &v_TTZToLLNuNu_Jethadronflavor);
    for (int evt = 0; evt < T_TTZToLLNuNu_tree->GetEntries(); evt++)
    {
        T_TTZToLLNuNu_tree->GetEntry(evt);
        h_Top_Met->Fill(f_TTZToLLNuNu_met, I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        if (f_TTZToLLNuNu_met > METcut)
        {
            h_Top_dilepPT->Fill(f_TTZToLLNuNu_dilepPT, I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_Top_Met_cut->Fill(f_TTZToLLNuNu_met, I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            for (size_t i = 0; i < v_TTZToLLNuNu_jetCSV->size(); i++)
            {
                h_Top_jetcsv->Fill((*v_TTZToLLNuNu_jetCSV)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                if ((*v_TTZToLLNuNu_Jethadronflavor)[i] == 5)
                {
                    h_Top_bjetcsv->Fill((*v_TTZToLLNuNu_jetCSV)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    h_Top_bJetMass->Fill((*v_TTZToLLNuNu_JetMass)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    if (((*v_TTZToLLNuNu_alpha)[i] < 0.15))
                    {
                        h_Top_bjetcsv_cutalpha->Fill((*v_TTZToLLNuNu_jetCSV)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    }
                }
                else if ((*v_TTZToLLNuNu_Jethadronflavor)[i] == 0)
                {
                    h_Top_ljetcsv->Fill((*v_TTZToLLNuNu_jetCSV)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    h_Top_lJetMass->Fill((*v_TTZToLLNuNu_JetMass)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    if (((*v_TTZToLLNuNu_alpha)[i] < 0.15))
                    {
                        h_Top_ljetcsv_cutalpha->Fill((*v_TTZToLLNuNu_jetCSV)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                    }
                }
                if (((*v_TTZToLLNuNu_alpha)[i] < 0.15))
                {
                    h_Top_jetcsv_cutalpha->Fill((*v_TTZToLLNuNu_jetCSV)[i], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
                }
            } // End of csv loop
        }
    }
    h_Top_dilepPT->Draw();
    TString outputfile1 = "./ee_Top_Met.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Top_dilepPT->Write();
    h_Top_Met->Write();
    h_Top_Met_cut->Write();
    h_Top_jetcsv->Write();
    h_Top_bjetcsv->Write();
    h_Top_ljetcsv->Write();
    h_Top_bJetMass->Write();
    h_Top_lJetMass->Write();
    h_Top_jetcsv_cutalpha->Write();
    h_Top_bjetcsv_cutalpha->Write();
    h_Top_ljetcsv_cutalpha->Write();

    outfile_HT0->Close();
}
int main()
{
    ee_Top_var();
}
