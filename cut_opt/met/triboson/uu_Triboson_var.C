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
    TH1D *h_Triboson_Met = new TH1D("h_Triboson_Met", "", 150, 0, 1500);
    h_Triboson_Met->GetXaxis()->SetTitle("");
    h_Triboson_Met->GetYaxis()->SetTitle("");
    h_Triboson_Met->Sumw2();

    TH1D *h_Triboson_dilepPT = new TH1D("h_Triboson_dilepPT", "", 150, 0, 1500);
    h_Triboson_dilepPT->GetXaxis()->SetTitle("");
    h_Triboson_dilepPT->GetYaxis()->SetTitle("");
    h_Triboson_dilepPT->Sumw2();

    TH1D *h_Triboson_Met_cut = new TH1D("h_Triboson_Met_cut", "", 50, 0, 500);
    h_Triboson_Met_cut->GetXaxis()->SetTitle("");
    h_Triboson_Met_cut->GetYaxis()->SetTitle("");
    h_Triboson_Met_cut->Sumw2();

    Int_t I_WWZ_weight, I_WZZ_weight, I_ZZZ_weight;

    float_t f_WWZ_met, f_WZZ_met, f_ZZZ_met;

    float_t f_WWZ_dilepPT, f_WZZ_dilepPT, f_ZZZ_dilepPT;

    vector<float> *v_WWZ_alpha = new vector<float>();
    vector<float> *v_WZZ_alpha = new vector<float>();
    vector<float> *v_ZZZ_alpha = new vector<float>();

    v_WWZ_alpha->clear();
    v_WZZ_alpha->clear();
    v_ZZZ_alpha->clear();

    double METcut = 140.0;

    TTree *T_tree;
    triboson_WWZfile->GetObject("T_tree", T_tree);
    T_tree->SetBranchAddress("I_weight", &I_WWZ_weight);
    T_tree->SetBranchAddress("f_Met", &f_WWZ_met);
    T_tree->SetBranchAddress("f_dileptonPT", &f_WWZ_dilepPT);
    T_tree->SetBranchAddress("v_fakealpha", &v_WWZ_alpha);
    for (int evt = 0; evt < T_tree->GetEntries(); evt++)
    {
        T_tree->GetEntry(evt);
        h_Triboson_Met->Fill(f_WWZ_met, I_WWZ_weight * WWZWeight);
        h_Triboson_dilepPT->Fill(f_WWZ_dilepPT, I_WWZ_weight * WWZWeight);

        if (f_WWZ_met > METcut)
        {
            h_Triboson_Met_cut->Fill(f_WWZ_met, I_WWZ_weight * WWZWeight);
        }
    }
    TTree *T_tree2;
    triboson_WZZfile->GetObject("T_tree", T_tree2);
    T_tree2->SetBranchAddress("I_weight", &I_WZZ_weight);
    T_tree2->SetBranchAddress("f_Met", &f_WZZ_met);
    T_tree2->SetBranchAddress("f_dileptonPT", &f_WZZ_dilepPT);
    T_tree2->SetBranchAddress("v_fakealpha", &v_WZZ_alpha);
    for (int evt = 0; evt < T_tree2->GetEntries(); evt++)
    {
        T_tree2->GetEntry(evt);
        h_Triboson_Met->Fill(f_WZZ_met, I_WZZ_weight * WZZWeight);
        h_Triboson_dilepPT->Fill(f_WZZ_dilepPT, I_WZZ_weight * WZZWeight);

        if (f_WZZ_met > METcut)
        {
            h_Triboson_Met_cut->Fill(f_WZZ_met, I_WZZ_weight * WZZWeight);
        }
    }

    TTree *T_tree3;
    triboson_ZZZfile->GetObject("T_tree", T_tree3);
    T_tree3->SetBranchAddress("I_weight", &I_ZZZ_weight);
    T_tree3->SetBranchAddress("f_Met", &f_ZZZ_met);
    T_tree3->SetBranchAddress("f_dileptonPT", &f_ZZZ_dilepPT);
    T_tree3->SetBranchAddress("v_fakealpha", &v_ZZZ_alpha);
    for (int evt = 0; evt < T_tree3->GetEntries(); evt++)
    {
        T_tree3->GetEntry(evt);
        h_Triboson_Met->Fill(f_ZZZ_met, I_ZZZ_weight * ZZZWeight);
        h_Triboson_dilepPT->Fill(f_ZZZ_dilepPT, I_ZZZ_weight * ZZZWeight);

        if (f_ZZZ_met > METcut)
        {
            h_Triboson_Met_cut->Fill(f_ZZZ_met, I_ZZZ_weight * ZZZWeight);
        }
    }
    h_Triboson_dilepPT->Draw();
    TString outputfile1 = "./uu_Triboson_Met.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Triboson_Met->Write();
    h_Triboson_Met_cut->Write();
    outfile_HT0->Close();
}
int main()
{
    uu_Triboson_var();
}