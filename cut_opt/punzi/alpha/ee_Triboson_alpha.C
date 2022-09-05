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

TFile *triboson_WWZfile = TFile::Open("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/triboson/ee_triboson_WWZ.root");
TFile *triboson_WZZfile = TFile::Open("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/triboson/ee_triboson_WZZ.root");
TFile *triboson_ZZZfile = TFile::Open("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/triboson/ee_triboson_ZZZ.root");

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

void ee_Triboson_alpha()
{

    int sumstep = 20;
    TH1D *h_Bg_nJet_cut[sumstep];
    TH1D *h_Bg_nJet_[sumstep];
    TH1D *h_Bg_alpha = new TH1D("h_Bg_alpha", "", 20, 0, 1);

    for (int i = 0; i < sumstep; i++)
    {
        float alphacut = (i + 1) * 0.05;
        cout << "alphacut = " << alphacut << endl;

        h_Bg_nJet_[i] = new TH1D(Form("h_Bg_nJet_%i", i + 1), "", 30, 0, 30);
        h_Bg_nJet_cut[i] = new TH1D(Form("h_Bg_nJet_cut_%i", i + 1), "", 30, 0, 30);

        Int_t I_WWZ_weight, I_WZZ_weight, I_ZZZ_weight;
        float_t f_WWZ_met, f_WZZ_met, f_ZZZ_met;

        vector<float> *v_WWZ_alpha = new vector<float>();
        vector<float> *v_WZZ_alpha = new vector<float>();
        vector<float> *v_ZZZ_alpha = new vector<float>();

        v_WWZ_alpha->clear();
        v_WZZ_alpha->clear();
        v_ZZZ_alpha->clear();

        TTree *T_tree;
        triboson_WWZfile->GetObject("T_tree", T_tree);
        T_tree->SetBranchAddress("I_weight", &I_WWZ_weight);
        T_tree->SetBranchAddress("f_Met", &f_WWZ_met);
        T_tree->SetBranchAddress("v_fakealpha3", &v_WWZ_alpha);
        for (int evt = 0; evt < T_tree->GetEntries(); evt++)
        {
            T_tree->GetEntry(evt);
            int jet_passalpha_cut = 0;
            for (int i = 0; i < v_WWZ_alpha->size(); i++)
            {
                h_Bg_alpha->Fill((*v_WWZ_alpha)[i], I_WWZ_weight * WWZWeight);
                if ((*v_WWZ_alpha)[i] < alphacut)
                {
                    jet_passalpha_cut++;
                }
            }
            
            if (jet_passalpha_cut == 0)
            {
                continue;
            }
            
            h_Bg_nJet_[i]->Fill(jet_passalpha_cut, I_WWZ_weight * WWZWeight);

            if (jet_passalpha_cut < 2)
            {
                continue;
            }
            h_Bg_nJet_cut[i]->Fill(jet_passalpha_cut, I_WWZ_weight * WWZWeight);
        }
        TTree *T_tree2;
        triboson_WZZfile->GetObject("T_tree", T_tree2);
        T_tree2->SetBranchAddress("I_weight", &I_WZZ_weight);
        T_tree2->SetBranchAddress("f_Met", &f_WZZ_met);
        T_tree2->SetBranchAddress("v_fakealpha3", &v_WZZ_alpha);
        for (int evt = 0; evt < T_tree2->GetEntries(); evt++)
        {
            T_tree2->GetEntry(evt);
            int jet_passalpha_cut = 0;
            for (int i = 0; i < v_WZZ_alpha->size(); i++)
            {
                h_Bg_alpha->Fill((*v_WZZ_alpha)[i], I_WZZ_weight * WZZWeight);
                if ((*v_WZZ_alpha)[i] < alphacut)
                {
                    jet_passalpha_cut++;
                }
            }
            
            if (jet_passalpha_cut == 0)
            {
                continue;
            }
            
            h_Bg_nJet_[i]->Fill(jet_passalpha_cut, I_WZZ_weight * WZZWeight);

            if (jet_passalpha_cut < 2)
            {
                continue;
            }
            h_Bg_nJet_cut[i]->Fill(jet_passalpha_cut, I_WZZ_weight * WZZWeight);
        }

        TTree *T_tree3;
        triboson_ZZZfile->GetObject("T_tree", T_tree3);
        T_tree3->SetBranchAddress("I_weight", &I_ZZZ_weight);
        T_tree3->SetBranchAddress("f_Met", &f_ZZZ_met);
        T_tree3->SetBranchAddress("v_fakealpha3", &v_ZZZ_alpha);
        for (int evt = 0; evt < T_tree3->GetEntries(); evt++)
        {
            T_tree3->GetEntry(evt);
            int jet_passalpha_cut = 0;
            for (int i = 0; i < v_ZZZ_alpha->size(); i++)
            {
                h_Bg_alpha->Fill((*v_ZZZ_alpha)[i], I_ZZZ_weight * ZZZWeight);
                if ((*v_ZZZ_alpha)[i] < alphacut)
                {
                    jet_passalpha_cut++;
                }
            }
            
            if (jet_passalpha_cut == 0)
            {
                continue;
            }
            
            h_Bg_nJet_[i]->Fill(jet_passalpha_cut, I_ZZZ_weight * ZZZWeight);
            if (jet_passalpha_cut < 2)
            {
                continue;
            }
            h_Bg_nJet_cut[i]->Fill(jet_passalpha_cut, I_ZZZ_weight * ZZZWeight);
        }
        double bgeff = (h_Bg_nJet_cut[i]->Integral()) / (h_Bg_nJet_[i]->Integral());
        cout << "bgeff = " << bgeff << endl;
    }
    //_Bg_Met->Draw();
    TString outputfile1 = "./output/Triboson_output.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    for (int i = 0; i < sumstep; i++)
    {
        h_Bg_nJet_cut[i]->Write();
        h_Bg_nJet_[i]->Write();
    }
    h_Bg_alpha->Write();
    outfile_HT0->Close();
}
