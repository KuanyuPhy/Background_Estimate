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

TFile *triboson_WWZfile = TFile::Open("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/triboson/uu_triboson_WWZ.root");
TFile *triboson_WZZfile = TFile::Open("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/triboson/uu_triboson_WZZ.root");
TFile *triboson_ZZZfile = TFile::Open("/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/triboson/uu_triboson_ZZZ.root");

TH1D *WWZ_sumevt = ((TH1D *)triboson_WWZfile->Get("Event_Variable/h_totevent"));
TH1D *WZZ_sumevt = ((TH1D *)triboson_WZZfile->Get("Event_Variable/h_totevent"));
TH1D *ZZZ_sumevt = ((TH1D *)triboson_ZZZfile->Get("Event_Variable/h_totevent"));

int WWZ_totevt = WWZ_sumevt->Integral();
int WZZ_totevt = WZZ_sumevt->Integral();
int ZZZ_totevt = ZZZ_sumevt->Integral();

//---------------------
// Define Triboson Weight
//---------------------
double WWZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::WWZ_TuneCUETP8M1 / (WWZ_totevt)) * 1000;
double WZZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::WZZ_TuneCUETP8M1 / (WZZ_totevt)) * 1000;
double ZZZWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ZZZ_TuneCUETP8M1 / (ZZZ_totevt)) * 1000;

void uu_Triboson_var()
{

    TH1D *h_bg_3DSig = new TH1D("h_bg_3DSig", "", 50, -5, 5);
    h_bg_3DSig->Sumw2();

    TH1D *h_bg_alpha1 = new TH1D("h_bg_alpha1", "", 20, 0, 1);
    h_bg_alpha1->Sumw2();

    TH1D *h_bg_alpha2 = new TH1D("h_bg_alpha2", "", 20, 0, 1);
    h_bg_alpha2->Sumw2();

    TH1D *h_bg_alpha3 = new TH1D("h_bg_alpha3", "", 20, 0, 1);
    h_bg_alpha3->Sumw2();

    TH1D *h_bg_alpha4 = new TH1D("h_bg_alpha4", "", 20, 0, 1);
    h_bg_alpha4->Sumw2();

    Int_t I_WWZ_weight, I_WZZ_weight, I_ZZZ_weight;

    float_t f_WWZ_met, f_WZZ_met, f_ZZZ_met;

    vector<float> *v_WWZ_alpha = new vector<float>();
    vector<float> *v_WZZ_alpha = new vector<float>();
    vector<float> *v_ZZZ_alpha = new vector<float>();

    v_WWZ_alpha->clear();
    v_WZZ_alpha->clear();
    v_ZZZ_alpha->clear();

    vector<float> *v_WWZ_alpha2 = new vector<float>();
    vector<float> *v_WZZ_alpha2 = new vector<float>();
    vector<float> *v_ZZZ_alpha2 = new vector<float>();

    v_WWZ_alpha2->clear();
    v_WZZ_alpha2->clear();
    v_ZZZ_alpha2->clear();

    vector<float> *v_WWZ_alpha3 = new vector<float>();
    vector<float> *v_WZZ_alpha3 = new vector<float>();
    vector<float> *v_ZZZ_alpha3 = new vector<float>();

    v_WWZ_alpha3->clear();
    v_WZZ_alpha3->clear();
    v_ZZZ_alpha3->clear();

    vector<float> *v_WWZ_alpha4 = new vector<float>();
    vector<float> *v_WZZ_alpha4 = new vector<float>();
    vector<float> *v_ZZZ_alpha4 = new vector<float>();

    v_WWZ_alpha4->clear();
    v_WZZ_alpha4->clear();
    v_ZZZ_alpha4->clear();

    vector<float> *v_WWZ_log3Dsig = new vector<float>();
    vector<float> *v_WZZ_log3Dsig = new vector<float>();
    vector<float> *v_ZZZ_log3Dsig = new vector<float>();

    v_WWZ_log3Dsig->clear();
    v_WZZ_log3Dsig->clear();
    v_ZZZ_log3Dsig->clear();

    double METcut = 140.0;

    TTree *T_tree;
    triboson_WWZfile->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("I_weight", &I_WWZ_weight);
    T_tree->SetBranchAddress("f_Met", &f_WWZ_met);
    T_tree->SetBranchAddress("v_Chi3Dlog", &v_WWZ_log3Dsig);
    T_tree->SetBranchAddress("v_fakealpha", &v_WWZ_alpha);
    T_tree->SetBranchAddress("v_fakealpha2", &v_WWZ_alpha2);
    T_tree->SetBranchAddress("v_fakealpha3", &v_WWZ_alpha3);
    T_tree->SetBranchAddress("v_fakealpha4", &v_WWZ_alpha4);
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    {
        T_tree->GetEntry(evt);
  /*       if (f_WWZ_met < 140)
        {
            continue;
        } */
        for (size_t i = 0; i < v_WWZ_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_WWZ_log3Dsig)[i], I_WWZ_weight * WWZWeight);
        }
        for (size_t i = 0; i < v_WWZ_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_WWZ_alpha)[i], I_WWZ_weight * WWZWeight);
            h_bg_alpha2->Fill((*v_WWZ_alpha2)[i], I_WWZ_weight * WWZWeight);
            h_bg_alpha3->Fill((*v_WWZ_alpha3)[i], I_WWZ_weight * WWZWeight);
            h_bg_alpha4->Fill((*v_WWZ_alpha4)[i], I_WWZ_weight * WWZWeight);
        }
    }
    TTree *T_tree2;
    triboson_WZZfile->GetObject("T_tree", T_tree2);
    T_tree2->SetBranchAddress("I_weight", &I_WZZ_weight);
    T_tree2->SetBranchAddress("f_Met", &f_WZZ_met);
    T_tree2->SetBranchAddress("v_Chi3Dlog", &v_WZZ_log3Dsig);
    T_tree2->SetBranchAddress("v_fakealpha", &v_WZZ_alpha);
    T_tree2->SetBranchAddress("v_fakealpha2", &v_WZZ_alpha2);
    T_tree2->SetBranchAddress("v_fakealpha3", &v_WZZ_alpha3);
    T_tree2->SetBranchAddress("v_fakealpha4", &v_WZZ_alpha4);
    for (int evt = 0; evt < T_tree2->GetEntries(); evt++)
    {
        T_tree2->GetEntry(evt);
 /*        if (f_WZZ_met < 140)
        {
            continue;
        } */
        for (size_t i = 0; i < v_WZZ_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_WZZ_log3Dsig)[i], I_WZZ_weight * WZZWeight);
        }
        for (size_t i = 0; i < v_WZZ_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_WZZ_alpha)[i], I_WZZ_weight * WZZWeight);
            h_bg_alpha2->Fill((*v_WZZ_alpha2)[i], I_WZZ_weight * WZZWeight);
            h_bg_alpha3->Fill((*v_WZZ_alpha3)[i], I_WZZ_weight * WZZWeight);
            h_bg_alpha4->Fill((*v_WZZ_alpha4)[i], I_WZZ_weight * WZZWeight);
        }
    }

    TTree *T_tree3;
    triboson_ZZZfile->GetObject("T_tree", T_tree3);
    T_tree3->SetBranchAddress("I_weight", &I_ZZZ_weight);
    T_tree3->SetBranchAddress("f_Met", &f_ZZZ_met);
    T_tree3->SetBranchAddress("v_Chi3Dlog", &v_ZZZ_log3Dsig);
    T_tree3->SetBranchAddress("v_fakealpha", &v_ZZZ_alpha);
    T_tree3->SetBranchAddress("v_fakealpha2", &v_ZZZ_alpha2);
    T_tree3->SetBranchAddress("v_fakealpha3", &v_ZZZ_alpha3);
    T_tree3->SetBranchAddress("v_fakealpha4", &v_ZZZ_alpha4);
    for (int evt = 0; evt < T_tree3->GetEntries(); evt++)
    {
        T_tree3->GetEntry(evt);
    /*     if (f_ZZZ_met < 140)
        {
            continue;
        } */
        for (size_t i = 0; i < v_ZZZ_log3Dsig->size(); i++)
        {
            h_bg_3DSig->Fill((*v_ZZZ_log3Dsig)[i], I_ZZZ_weight * ZZZWeight);
        }
        for (size_t i = 0; i < v_ZZZ_alpha->size(); i++)
        {
            h_bg_alpha1->Fill((*v_ZZZ_alpha)[i], I_ZZZ_weight * ZZZWeight);
            h_bg_alpha2->Fill((*v_ZZZ_alpha2)[i], I_ZZZ_weight * ZZZWeight);
            h_bg_alpha3->Fill((*v_ZZZ_alpha3)[i], I_ZZZ_weight * ZZZWeight);
            h_bg_alpha4->Fill((*v_ZZZ_alpha4)[i], I_ZZZ_weight * ZZZWeight);
        }
    }
    h_bg_3DSig->Draw();
    TString outputfile1 = "./uu_Triboson_alpha.root";
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
    uu_Triboson_var();
}