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

TFile *TTTo2L2Nufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/new/ee_top_TTTo2L2Nu.root");
TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/new/ee_top_TTWJetsToLNu.root");
TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/new/ee_top_TTWJetsToQQ.root");
TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/new/ee_top_TTZToQQ.root");
TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/new/ee_top_TTZToLLNuNu.root");
TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/new/ee_top_tW_antitop.root");
TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/new/ee_top_tW_top.root");

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
    TH1D *h_Top_dz = new TH1D("h_Top_dz", "", 600, -60., 50.);
    h_Top_dz->Sumw2();

    TH1D *h_Top_dxy = new TH1D("h_Top_dxy", "", 600, -60., 50.);
    h_Top_dxy->Sumw2();

    TH1D *h_Top_dzerr = new TH1D("h_Top_dzerr", "", 30, 0., 3.);
    h_Top_dzerr->Sumw2();

    TH1D *h_Top_dxyerr = new TH1D("h_Top_dxyerr", "", 30, 0., 3.);
    h_Top_dxyerr->Sumw2();

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

    vector<float> *v_TTTo2L2Nu_Trkdz = new vector<float>();
    vector<float> *v_ST_tW_top_Trkdz = new vector<float>();
    vector<float> *v_ST_tW_antitop_Trkdz = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Trkdz = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Trkdz = new vector<float>();
    vector<float> *v_TTZToQQ_Trkdz = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Trkdz = new vector<float>();

    v_TTTo2L2Nu_Trkdz->clear();
    v_ST_tW_top_Trkdz->clear();
    v_ST_tW_antitop_Trkdz->clear();
    v_TTWJetsToLNu_Trkdz->clear();
    v_TTWJetsToQQ_Trkdz->clear();
    v_TTZToQQ_Trkdz->clear();
    v_TTZToLLNuNu_Trkdz->clear();

    vector<float> *v_TTTo2L2Nu_Trkdxy = new vector<float>();
    vector<float> *v_ST_tW_top_Trkdxy = new vector<float>();
    vector<float> *v_ST_tW_antitop_Trkdxy = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Trkdxy = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Trkdxy = new vector<float>();
    vector<float> *v_TTZToQQ_Trkdxy = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Trkdxy = new vector<float>();

    v_TTTo2L2Nu_Trkdxy->clear();
    v_ST_tW_top_Trkdxy->clear();
    v_ST_tW_antitop_Trkdxy->clear();
    v_TTWJetsToLNu_Trkdxy->clear();
    v_TTWJetsToQQ_Trkdxy->clear();
    v_TTZToQQ_Trkdxy->clear();
    v_TTZToLLNuNu_Trkdxy->clear();

    vector<float> *v_TTTo2L2Nu_Trkdzerr = new vector<float>();
    vector<float> *v_ST_tW_top_Trkdzerr = new vector<float>();
    vector<float> *v_ST_tW_antitop_Trkdzerr = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Trkdzerr = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Trkdzerr = new vector<float>();
    vector<float> *v_TTZToQQ_Trkdzerr = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Trkdzerr = new vector<float>();

    v_TTTo2L2Nu_Trkdzerr->clear();
    v_ST_tW_top_Trkdzerr->clear();
    v_ST_tW_antitop_Trkdzerr->clear();
    v_TTWJetsToLNu_Trkdzerr->clear();
    v_TTWJetsToQQ_Trkdzerr->clear();
    v_TTZToQQ_Trkdzerr->clear();
    v_TTZToLLNuNu_Trkdzerr->clear();

    vector<float> *v_TTTo2L2Nu_Trkdxyerr = new vector<float>();
    vector<float> *v_ST_tW_top_Trkdxyerr = new vector<float>();
    vector<float> *v_ST_tW_antitop_Trkdxyerr = new vector<float>();
    vector<float> *v_TTWJetsToLNu_Trkdxyerr = new vector<float>();
    vector<float> *v_TTWJetsToQQ_Trkdxyerr = new vector<float>();
    vector<float> *v_TTZToQQ_Trkdxyerr = new vector<float>();
    vector<float> *v_TTZToLLNuNu_Trkdxyerr = new vector<float>();

    v_TTTo2L2Nu_Trkdxyerr->clear();
    v_ST_tW_top_Trkdxyerr->clear();
    v_ST_tW_antitop_Trkdxyerr->clear();
    v_TTWJetsToLNu_Trkdxyerr->clear();
    v_TTWJetsToQQ_Trkdxyerr->clear();
    v_TTZToQQ_Trkdxyerr->clear();
    v_TTZToLLNuNu_Trkdxyerr->clear();

    vector<float> *v_TTTo2L2Nu_JetCSVv2 = new vector<float>();
    vector<float> *v_ST_tW_top_JetCSVv2 = new vector<float>();
    vector<float> *v_ST_tW_antitop_JetCSVv2 = new vector<float>();
    vector<float> *v_TTWJetsToLNu_JetCSVv2 = new vector<float>();
    vector<float> *v_TTWJetsToQQ_JetCSVv2 = new vector<float>();
    vector<float> *v_TTZToQQ_JetCSVv2 = new vector<float>();
    vector<float> *v_TTZToLLNuNu_JetCSVv2 = new vector<float>();

    v_TTTo2L2Nu_JetCSVv2->clear();
    v_ST_tW_top_JetCSVv2->clear();
    v_ST_tW_antitop_JetCSVv2->clear();
    v_TTWJetsToLNu_JetCSVv2->clear();
    v_TTWJetsToQQ_JetCSVv2->clear();
    v_TTZToQQ_JetCSVv2->clear();
    v_TTZToLLNuNu_JetCSVv2->clear();

    double METcut = 0.;

    TTree *T_TTTo2L2Nu_tree;
    TTTo2L2Nufile->GetObject("T_tree", T_TTTo2L2Nu_tree);
    T_TTTo2L2Nu_tree->SetBranchAddress("I_weight", &I_TTTo2L2Nu_weight);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_Met", &f_TTTo2L2Nu_met);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_Trk_dz", &v_TTTo2L2Nu_Trkdz);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_Trk_dxy", &v_TTTo2L2Nu_Trkdxy);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_Trk_dzerror", &v_TTTo2L2Nu_Trkdzerr);
    T_TTTo2L2Nu_tree->SetBranchAddress("v_Trk_dxyerror", &v_TTTo2L2Nu_Trkdxyerr);
    T_TTTo2L2Nu_tree->SetBranchAddress("f_thinjetCSVv2", &v_TTTo2L2Nu_JetCSVv2);
    for (int evt = 0; evt < T_TTTo2L2Nu_tree->GetEntries(); evt++)
    {
        T_TTTo2L2Nu_tree->GetEntry(evt);
        for (size_t itk = 0; itk < v_TTTo2L2Nu_Trkdz->size(); itk++)
        {
            h_Top_dz->Fill((*v_TTTo2L2Nu_Trkdz)[itk], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_Top_dxy->Fill((*v_TTTo2L2Nu_Trkdxy)[itk], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_Top_dzerr->Fill((*v_TTTo2L2Nu_Trkdzerr)[itk], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
            h_Top_dxyerr->Fill((*v_TTTo2L2Nu_Trkdxyerr)[itk], I_TTTo2L2Nu_weight * TTTo2L2NuWeight);
        }
    }
    TTree *T_ST_tW_top_tree;
    Top_tW_topfile->GetObject("T_tree", T_ST_tW_top_tree);
    T_ST_tW_top_tree->SetBranchAddress("I_weight", &I_ST_tW_top_weight);
    T_ST_tW_top_tree->SetBranchAddress("f_Met", &f_ST_tW_top_met);
    T_ST_tW_top_tree->SetBranchAddress("v_Trk_dz", &v_ST_tW_top_Trkdz);
    T_ST_tW_top_tree->SetBranchAddress("v_Trk_dxy", &v_ST_tW_top_Trkdxy);
    T_ST_tW_top_tree->SetBranchAddress("v_Trk_dzerror", &v_ST_tW_top_Trkdzerr);
    T_ST_tW_top_tree->SetBranchAddress("v_Trk_dxyerror", &v_ST_tW_top_Trkdxyerr);
    T_ST_tW_top_tree->SetBranchAddress("f_thinjetCSVv2", &v_ST_tW_top_JetCSVv2);
    for (int evt = 0; evt < T_ST_tW_top_tree->GetEntries(); evt++)
    {
        T_ST_tW_top_tree->GetEntry(evt);
        for (size_t itk = 0; itk < v_ST_tW_top_Trkdz->size(); itk++)
        {
            h_Top_dz->Fill((*v_ST_tW_top_Trkdz)[itk], I_ST_tW_top_weight * ST_tW_topWeight);
            h_Top_dxy->Fill((*v_ST_tW_top_Trkdxy)[itk], I_ST_tW_top_weight * ST_tW_topWeight);
            h_Top_dzerr->Fill((*v_ST_tW_top_Trkdzerr)[itk], I_ST_tW_top_weight * ST_tW_topWeight);
            h_Top_dxyerr->Fill((*v_ST_tW_top_Trkdxyerr)[itk], I_ST_tW_top_weight * ST_tW_topWeight);
        }
    }
    TTree *T_ST_tW_antitop_tree;
    Top_tW_antitopfile->GetObject("T_tree", T_ST_tW_antitop_tree);
    T_ST_tW_antitop_tree->SetBranchAddress("I_weight", &I_ST_tW_antitop_weight);
    T_ST_tW_antitop_tree->SetBranchAddress("f_Met", &f_ST_tW_antitop_met);
    T_ST_tW_antitop_tree->SetBranchAddress("v_Trk_dz", &v_ST_tW_antitop_Trkdz);
    T_ST_tW_antitop_tree->SetBranchAddress("v_Trk_dxy", &v_ST_tW_antitop_Trkdxy);
    T_ST_tW_antitop_tree->SetBranchAddress("v_Trk_dzerror", &v_ST_tW_antitop_Trkdzerr);
    T_ST_tW_antitop_tree->SetBranchAddress("v_Trk_dxyerror", &v_ST_tW_antitop_Trkdxyerr);
    T_ST_tW_antitop_tree->SetBranchAddress("f_thinjetCSVv2", &v_ST_tW_antitop_JetCSVv2);
    for (int evt = 0; evt < T_ST_tW_antitop_tree->GetEntries(); evt++)
    {
        T_ST_tW_antitop_tree->GetEntry(evt);
        for (size_t itk = 0; itk < v_ST_tW_antitop_Trkdz->size(); itk++)
        {
            h_Top_dz->Fill((*v_ST_tW_antitop_Trkdz)[itk], I_ST_tW_antitop_weight * ST_tW_antitopWeight);
            h_Top_dxy->Fill((*v_ST_tW_antitop_Trkdxy)[itk], I_ST_tW_antitop_weight * ST_tW_antitopWeight);
            h_Top_dzerr->Fill((*v_ST_tW_antitop_Trkdzerr)[itk], I_ST_tW_antitop_weight * ST_tW_antitopWeight);
            h_Top_dxyerr->Fill((*v_ST_tW_antitop_Trkdxyerr)[itk], I_ST_tW_antitop_weight * ST_tW_antitopWeight);
        }
    }
    TTree *T_TTWJetsToLNu_tree;
    Top_TTWJetsToLNufile->GetObject("T_tree", T_TTWJetsToLNu_tree);
    T_TTWJetsToLNu_tree->SetBranchAddress("I_weight", &I_TTWJetsToLNu_weight);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_Met", &f_TTWJetsToLNu_met);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_Trk_dz", &v_TTWJetsToLNu_Trkdz);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_Trk_dxy", &v_TTWJetsToLNu_Trkdxy);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_Trk_dzerror", &v_TTWJetsToLNu_Trkdzerr);
    T_TTWJetsToLNu_tree->SetBranchAddress("v_Trk_dxyerror", &v_TTWJetsToLNu_Trkdxyerr);
    T_TTWJetsToLNu_tree->SetBranchAddress("f_thinjetCSVv2", &v_TTWJetsToLNu_JetCSVv2);
    for (int evt = 0; evt < T_TTWJetsToLNu_tree->GetEntries(); evt++)
    {
        T_TTWJetsToLNu_tree->GetEntry(evt);
        for (size_t itk = 0; itk < v_TTWJetsToLNu_Trkdz->size(); itk++)
        {
            h_Top_dz->Fill((*v_TTWJetsToLNu_Trkdz)[itk], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_Top_dxy->Fill((*v_TTWJetsToLNu_Trkdxy)[itk], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_Top_dzerr->Fill((*v_TTWJetsToLNu_Trkdzerr)[itk], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
            h_Top_dxyerr->Fill((*v_TTWJetsToLNu_Trkdxyerr)[itk], I_TTWJetsToLNu_weight * TTWJetsToLNuWeight);
        }
    }
    TTree *T_TTWJetsToQQ_tree;
    Top_TTWJetsToQQfile->GetObject("T_tree", T_TTWJetsToQQ_tree);
    T_TTWJetsToQQ_tree->SetBranchAddress("I_weight", &I_TTWJetsToQQ_weight);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_Met", &f_TTWJetsToQQ_met);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_Trk_dz", &v_TTWJetsToQQ_Trkdz);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_Trk_dxy", &v_TTWJetsToQQ_Trkdxy);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_Trk_dzerror", &v_TTWJetsToQQ_Trkdzerr);
    T_TTWJetsToQQ_tree->SetBranchAddress("v_Trk_dxyerror", &v_TTWJetsToQQ_Trkdxyerr);
    T_TTWJetsToQQ_tree->SetBranchAddress("f_thinjetCSVv2", &v_TTWJetsToQQ_JetCSVv2);
    for (int evt = 0; evt < T_TTWJetsToQQ_tree->GetEntries(); evt++)
    {
        T_TTWJetsToQQ_tree->GetEntry(evt);
        for (size_t itk = 0; itk < v_TTWJetsToQQ_Trkdz->size(); itk++)
        {
            h_Top_dz->Fill((*v_TTWJetsToQQ_Trkdz)[itk], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_Top_dxy->Fill((*v_TTWJetsToQQ_Trkdxy)[itk], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_Top_dzerr->Fill((*v_TTWJetsToQQ_Trkdzerr)[itk], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
            h_Top_dxyerr->Fill((*v_TTWJetsToQQ_Trkdxyerr)[itk], I_TTWJetsToQQ_weight * TTWJetsToQQWeight);
        }
    }
    TTree *T_TTZToQQ_tree;
    Top_TTZToQQfile->GetObject("T_tree", T_TTZToQQ_tree);
    T_TTZToQQ_tree->SetBranchAddress("I_weight", &I_TTZToQQ_weight);
    T_TTZToQQ_tree->SetBranchAddress("f_Met", &f_TTZToQQ_met);
    T_TTZToQQ_tree->SetBranchAddress("v_Trk_dz", &v_TTZToQQ_Trkdz);
    T_TTZToQQ_tree->SetBranchAddress("v_Trk_dxy", &v_TTZToQQ_Trkdxy);
    T_TTZToQQ_tree->SetBranchAddress("v_Trk_dzerror", &v_TTZToQQ_Trkdzerr);
    T_TTZToQQ_tree->SetBranchAddress("v_Trk_dxyerror", &v_TTZToQQ_Trkdxyerr);
    T_TTZToQQ_tree->SetBranchAddress("f_thinjetCSVv2", &v_TTZToQQ_JetCSVv2);
    for (int evt = 0; evt < T_TTZToQQ_tree->GetEntries(); evt++)
    {
        T_TTZToQQ_tree->GetEntry(evt);
        for (size_t itk = 0; itk < v_TTZToQQ_Trkdz->size(); itk++)
        {
            h_Top_dz->Fill((*v_TTZToQQ_Trkdz)[itk], I_TTZToQQ_weight * TTZToQQWeight);
            h_Top_dxy->Fill((*v_TTZToQQ_Trkdxy)[itk], I_TTZToQQ_weight * TTZToQQWeight);
            h_Top_dzerr->Fill((*v_TTZToQQ_Trkdzerr)[itk], I_TTZToQQ_weight * TTZToQQWeight);
            h_Top_dxyerr->Fill((*v_TTZToQQ_Trkdxyerr)[itk], I_TTZToQQ_weight * TTZToQQWeight);
        }
    }
    TTree *T_TTZToLLNuNu_tree;
    Top_TTZToLLNuNufile->GetObject("T_tree", T_TTZToLLNuNu_tree);
    T_TTZToLLNuNu_tree->SetBranchAddress("I_weight", &I_TTZToLLNuNu_weight);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_Met", &f_TTZToLLNuNu_met);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_Trk_dz", &v_TTZToLLNuNu_Trkdz);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_Trk_dxy", &v_TTZToLLNuNu_Trkdxy);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_Trk_dzerror", &v_TTZToLLNuNu_Trkdzerr);
    T_TTZToLLNuNu_tree->SetBranchAddress("v_Trk_dxyerror", &v_TTZToLLNuNu_Trkdxyerr);
    T_TTZToLLNuNu_tree->SetBranchAddress("f_thinjetCSVv2", &v_TTZToLLNuNu_JetCSVv2);
    for (int evt = 0; evt < T_TTZToLLNuNu_tree->GetEntries(); evt++)
    {
        T_TTZToLLNuNu_tree->GetEntry(evt);
        for (size_t itk = 0; itk < v_TTZToLLNuNu_Trkdz->size(); itk++)
        {
            h_Top_dz->Fill((*v_TTZToLLNuNu_Trkdz)[itk], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_Top_dxy->Fill((*v_TTZToLLNuNu_Trkdxy)[itk], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_Top_dzerr->Fill((*v_TTZToLLNuNu_Trkdzerr)[itk], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
            h_Top_dxyerr->Fill((*v_TTZToLLNuNu_Trkdxyerr)[itk], I_TTZToLLNuNu_weight * TTZToLLNuNuWeight);
        }
    }
    h_Top_dxy->DrawNormalized();

    TString outputfile1 = "./ee_Top_alpha.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Top_dz->Write();
    h_Top_dxy->Write();
    h_Top_dzerr->Write();
    h_Top_dxyerr->Write();

    outfile_HT0->Close();
}
int main()
{
    ee_Top_var();
}
