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

using namespace std;
void ee_sig()
{
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/new/ee_Mx2_1_old_remove_0alpha.root");
    TFile *Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/new/ee_Mx2_50_old_remove_0alpha.root");
    TFile *Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/new/ee_Mx2_150_old_remove_0alpha.root");

    TH1D *h_pass_Mx2_1 = new TH1D("h_pass_Mx2_1", "", 50, 0, 50);
    h_pass_Mx2_1->Sumw2();

    TH1D *h_pass_Mx2_1_nMetcut = new TH1D("h_pass_Mx2_1_nMetcut", "", 50, 0, 50);
    h_pass_Mx2_1_nMetcut->Sumw2();

    TH1D *h_pass_Mx2_50 = new TH1D("h_pass_Mx2_50", "", 50, 0, 50);
    h_pass_Mx2_50->Sumw2();

    TH1D *h_pass_Mx2_50_nMetcut = new TH1D("h_pass_Mx2_50_nMetcut", "", 50, 0, 50);
    h_pass_Mx2_50_nMetcut->Sumw2();

    TH1D *h_pass_Mx2_150 = new TH1D("h_pass_Mx2_150", "", 50, 0, 50);
    h_pass_Mx2_150->Sumw2();

    TH1D *h_pass_Mx2_150_nMetcut = new TH1D("h_pass_Mx2_150_nMetcut", "", 50, 0, 50);
    h_pass_Mx2_150_nMetcut->Sumw2();

    TH1D *h_Mx2_1_Met = new TH1D("h_Mx2_1_Met", "", 150, 0, 1500);
    h_Mx2_1_Met->Sumw2();

    TH1D *h_Mx2_50_Met = new TH1D("h_Mx2_50_Met", "", 150, 0, 1500);
    h_Mx2_50_Met->Sumw2();

    TH1D *h_Mx2_150_Met = new TH1D("h_Mx2_150_Met", "", 150, 0, 1500);
    h_Mx2_150_Met->Sumw2();

    TH1D *h_Mx2_150_Met_noweight = new TH1D("h_Mx2_150_Met_noweight", "", 150, 0, 1500);
    h_Mx2_150_Met_noweight->Sumw2();

    TH1D *h_Mx2_1_dilepPT = new TH1D("h_Mx2_1_dilepPT", "", 100, 0., 1000.);
    h_Mx2_1_dilepPT->Sumw2();

    TH1D *h_Mx2_50_dilepPT = new TH1D("h_Mx2_50_dilepPT", "", 100, 0., 1000.);
    h_Mx2_50_dilepPT->Sumw2();

    TH1D *h_Mx2_150_dilepPT = new TH1D("h_Mx2_150_dilepPT", "", 100, 0., 1000.);
    h_Mx2_150_dilepPT->Sumw2();

    TH1D *h_Mx2_1_jetcsv = new TH1D("h_Mx2_1_jetcsv", "", 20, 0, 1);
    h_Mx2_1_jetcsv->GetXaxis()->SetTitle("");
    h_Mx2_1_jetcsv->GetYaxis()->SetTitle("");
    h_Mx2_1_jetcsv->Sumw2();

    TH1D *h_Mx2_50_jetcsv = new TH1D("h_Mx2_50_jetcsv", "", 20, 0, 1);
    h_Mx2_50_jetcsv->GetXaxis()->SetTitle("");
    h_Mx2_50_jetcsv->GetYaxis()->SetTitle("");
    h_Mx2_50_jetcsv->Sumw2();

    TH1D *h_Mx2_150_jetcsv = new TH1D("h_Mx2_150_jetcsv", "", 20, 0, 1);
    h_Mx2_150_jetcsv->GetXaxis()->SetTitle("");
    h_Mx2_150_jetcsv->GetYaxis()->SetTitle("");
    h_Mx2_150_jetcsv->Sumw2();

    TH1D *h_Mx2_1_jetcsv_unweight = new TH1D("h_Mx2_1_jetcsv_unweight", "", 20, 0, 1);
    h_Mx2_1_jetcsv_unweight->GetXaxis()->SetTitle("");
    h_Mx2_1_jetcsv_unweight->GetYaxis()->SetTitle("");
    h_Mx2_1_jetcsv_unweight->Sumw2();

    TH1D *h_Mx2_50_jetcsv_unweight = new TH1D("h_Mx2_50_jetcsv_unweight", "", 20, 0, 1);
    h_Mx2_50_jetcsv_unweight->GetXaxis()->SetTitle("");
    h_Mx2_50_jetcsv_unweight->GetYaxis()->SetTitle("");
    h_Mx2_50_jetcsv_unweight->Sumw2();

    TH1D *h_Mx2_150_jetcsv_unweight = new TH1D("h_Mx2_150_jetcsv_unweight", "", 20, 0, 1);
    h_Mx2_150_jetcsv_unweight->GetXaxis()->SetTitle("");
    h_Mx2_150_jetcsv_unweight->GetYaxis()->SetTitle("");
    h_Mx2_150_jetcsv_unweight->Sumw2();

    TH1D *h_Mx2_1_jetcsv_SR = new TH1D("h_Mx2_1_jetcsv_SR", "", 20, 0, 1);
    h_Mx2_1_jetcsv_SR->GetXaxis()->SetTitle("");
    h_Mx2_1_jetcsv_SR->GetYaxis()->SetTitle("");
    h_Mx2_1_jetcsv_SR->Sumw2();

    TH1D *h_Mx2_50_jetcsv_SR = new TH1D("h_Mx2_50_jetcsv_SR", "", 20, 0, 1);
    h_Mx2_50_jetcsv_SR->GetXaxis()->SetTitle("");
    h_Mx2_50_jetcsv_SR->GetYaxis()->SetTitle("");
    h_Mx2_50_jetcsv_SR->Sumw2();

    TH1D *h_Mx2_150_jetcsv_SR = new TH1D("h_Mx2_150_jetcsv_SR", "", 20, 0, 1);
    h_Mx2_150_jetcsv_SR->GetXaxis()->SetTitle("");
    h_Mx2_150_jetcsv_SR->GetYaxis()->SetTitle("");
    h_Mx2_150_jetcsv_SR->Sumw2();

    TH1D *h_Mx2_1_Met_cut = new TH1D("h_Mx2_1_Met_cut", "", 150, 0, 1500);
    h_Mx2_1_Met_cut->Sumw2();

    TH1D *h_Mx2_50_Met_cut = new TH1D("h_Mx2_50_Met_cut", "", 150, 0, 1500);
    h_Mx2_50_Met_cut->Sumw2();

    TH1D *h_Mx2_150_Met_cut = new TH1D("h_Mx2_150_Met_cut", "", 150, 0, 1500);
    h_Mx2_150_Met_cut->Sumw2();

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;

    float_t f_Mx1_dilepPT, f_Mx50_dilepPT, f_Mx150_dilepPT;

    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;

    vector<float> *v_Mx1_alpha = new vector<float>();
    vector<float> *v_Mx50_alpha = new vector<float>();
    vector<float> *v_Mx150_alpha = new vector<float>();

    v_Mx1_alpha->clear();
    v_Mx50_alpha->clear();
    v_Mx150_alpha->clear();

    vector<float> *v_Mx1_jetCSV = new vector<float>();
    vector<float> *v_Mx50_jetCSV = new vector<float>();
    vector<float> *v_Mx150_jetCSV = new vector<float>();

    v_Mx1_jetCSV->clear();
    v_Mx50_jetCSV->clear();
    v_Mx150_jetCSV->clear();

    float metcut = 140;

    TTree *T_Mx2_1;
    Mx2_1->GetObject("T_tree", T_Mx2_1);
    T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
    T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
    T_Mx2_1->SetBranchAddress("v_nPassthinJetCSVv2", &v_Mx1_jetCSV);
    T_Mx2_1->SetBranchAddress("f_dileptonPT", &f_Mx1_dilepPT);
    T_Mx2_1->SetBranchAddress("v_nPassthinJetalpha", &v_Mx1_alpha);
    for (int evt = 0; evt < T_Mx2_1->GetEntries(); evt++)
    {
        T_Mx2_1->GetEntry(evt);
        h_Mx2_1_Met->Fill(f_Mx1_Met, I_Mx1_weight);
        
                    for (size_t i = 0; i < v_Mx1_jetCSV->size(); i++)
            {
                if ((*v_Mx1_jetCSV)[i] == -10)
                {
                    continue;
                }
                h_Mx2_1_jetcsv->Fill((*v_Mx1_jetCSV)[i], I_Mx1_weight);
                h_Mx2_1_jetcsv_unweight->Fill((*v_Mx1_jetCSV)[i], 1);
                if ((*v_Mx1_alpha)[i] < 0.1)
                {
                    h_Mx2_1_jetcsv_SR->Fill((*v_Mx1_jetCSV)[i], I_Mx1_weight);
                }
            }
        
        if (f_Mx1_Met > metcut)
        {


            h_Mx2_1_Met_cut->Fill(f_Mx1_Met, I_Mx1_weight);
            h_Mx2_1_dilepPT->Fill(f_Mx1_dilepPT, I_Mx1_weight);
        }
    } // End of Mx2_1 Entries loop
    TTree *T_Mx2_50;
    Mx2_50->GetObject("T_tree", T_Mx2_50);
    T_Mx2_50->SetBranchAddress("I_weight", &I_Mx50_weight);
    T_Mx2_50->SetBranchAddress("f_Met", &f_Mx50_Met);
    T_Mx2_50->SetBranchAddress("v_nPassthinJetCSVv2", &v_Mx50_jetCSV);
    T_Mx2_50->SetBranchAddress("f_dileptonPT", &f_Mx50_dilepPT);
    T_Mx2_50->SetBranchAddress("v_nPassthinJetalpha", &v_Mx50_alpha);
    for (int evt = 0; evt < T_Mx2_50->GetEntries(); evt++)
    {
        T_Mx2_50->GetEntry(evt);
        h_Mx2_50_Met->Fill(f_Mx50_Met, I_Mx50_weight);
            for (size_t i = 0; i < v_Mx50_jetCSV->size(); i++)
            {
                if ((*v_Mx50_jetCSV)[i] == -10)
                {
                    continue;
                }
                h_Mx2_50_jetcsv->Fill((*v_Mx50_jetCSV)[i], I_Mx50_weight);
                h_Mx2_50_jetcsv_unweight->Fill((*v_Mx50_jetCSV)[i], 1);
                if ((*v_Mx50_alpha)[i] < 0.1)
                {
                    h_Mx2_50_jetcsv_SR->Fill((*v_Mx50_jetCSV)[i], I_Mx50_weight);
                }
            }
        if (f_Mx50_Met > metcut)
        {

            h_Mx2_50_Met_cut->Fill(f_Mx50_Met, I_Mx50_weight);
            h_Mx2_50_dilepPT->Fill(f_Mx50_dilepPT, I_Mx50_weight);
        }
    } // End of Mx2_50 Entries loop
    TTree *T_Mx2_150;
    Mx2_150->GetObject("T_tree", T_Mx2_150);
    T_Mx2_150->SetBranchAddress("I_weight", &I_Mx150_weight);
    T_Mx2_150->SetBranchAddress("f_Met", &f_Mx150_Met);
    T_Mx2_150->SetBranchAddress("v_nPassthinJetCSVv2", &v_Mx150_jetCSV);
    T_Mx2_150->SetBranchAddress("f_dileptonPT", &f_Mx150_dilepPT);
    T_Mx2_150->SetBranchAddress("v_nPassthinJetalpha", &v_Mx150_alpha);
    for (int evt = 0; evt < T_Mx2_150->GetEntries(); evt++)
    {
        T_Mx2_150->GetEntry(evt);
        h_Mx2_150_Met->Fill(f_Mx150_Met, I_Mx150_weight);
        h_Mx2_150_Met_noweight->Fill(f_Mx150_Met, 1);
                    for (size_t i = 0; i < v_Mx150_jetCSV->size(); i++)
            {
                if ((*v_Mx150_jetCSV)[i] == -10)
                {
                    continue;
                }
                h_Mx2_150_jetcsv->Fill((*v_Mx150_jetCSV)[i], I_Mx150_weight);
                h_Mx2_150_jetcsv_unweight->Fill((*v_Mx150_jetCSV)[i], 1);
                if ((*v_Mx150_alpha)[i] < 0.1)
                {
                    h_Mx2_150_jetcsv_SR->Fill((*v_Mx150_jetCSV)[i], I_Mx150_weight);
                }
            }
        if (f_Mx150_Met > metcut)
        {

            h_Mx2_150_Met_cut->Fill(f_Mx150_Met, I_Mx150_weight);
            h_Mx2_150_dilepPT->Fill(f_Mx150_dilepPT, I_Mx150_weight);
        }
    } // End of Mx2_150 Entries loop

    h_Mx2_50_jetcsv->Draw("text");

    TString outputfile1 = "./ee_Sig_Met.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Mx2_1_Met->Write();
    h_Mx2_50_Met->Write();
    h_Mx2_150_Met->Write();
    h_Mx2_150_Met_noweight->Write();
    h_Mx2_1_Met_cut->Write();
    h_Mx2_50_Met_cut->Write();
    h_Mx2_150_Met_cut->Write();
    h_Mx2_1_dilepPT->Write();
    h_Mx2_50_dilepPT->Write();
    h_Mx2_150_dilepPT->Write();
    h_Mx2_1_jetcsv->Write();
    h_Mx2_50_jetcsv->Write();
    h_Mx2_150_jetcsv->Write();
    h_Mx2_1_jetcsv_SR->Write();
    h_Mx2_50_jetcsv_SR->Write();
    h_Mx2_150_jetcsv_SR->Write();
    h_Mx2_1_jetcsv_unweight->Write();
    h_Mx2_50_jetcsv_unweight->Write();
    h_Mx2_150_jetcsv_unweight->Write();
    outfile_HT0->Close();
}