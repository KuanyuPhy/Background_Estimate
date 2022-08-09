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
void ee_sig_var()
{
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/Mx2_1_old_remove_0alpha.root");
    TFile *Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/Mx2_50_old_remove_0alpha.root");
    TFile *Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/Mx2_150_old_remove_0alpha.root");

    TH1D *h_Mx2_1_Met = new TH1D("h_Mx2_1_Met", "", 50, 0, 500);
    h_Mx2_1_Met->Sumw2();

    TH1D *h_Mx2_50_Met = new TH1D("h_Mx2_50_Met", "", 50, 0, 500);
    h_Mx2_50_Met->Sumw2();

    TH1D *h_Mx2_150_Met = new TH1D("h_Mx2_150_Met", "", 50, 0, 500);
    h_Mx2_150_Met->Sumw2();

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;

    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;

    vector<float> *v_Mx1_alpha = new vector<float>();
    vector<float> *v_Mx50_alpha = new vector<float>();
    vector<float> *v_Mx150_alpha = new vector<float>();

    v_Mx1_alpha->clear();
    v_Mx50_alpha->clear();
    v_Mx150_alpha->clear();

    for (int i = 1; i <= 50; i++)
    {
        float metcut = i * 10;

        TTree *T_Mx2_1;
        Mx2_1->GetObject("T_tree", T_Mx2_1);
        T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
        T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
        T_Mx2_1->SetBranchAddress("v_fakealpha", &v_Mx1_alpha);
        for (int evt = 0; evt < T_Mx2_1->GetEntries(); evt++)
        {
            T_Mx2_1->GetEntry(evt);
            h_Mx2_1_Met->Fill(f_Mx1_Met, I_Mx50_weight);

        } // End of Mx2_1 Entries loop
        TTree *T_Mx2_50;
        Mx2_50->GetObject("T_tree", T_Mx2_50);
        T_Mx2_50->SetBranchAddress("I_weight", &I_Mx50_weight);
        T_Mx2_50->SetBranchAddress("f_Met", &f_Mx50_Met);
        T_Mx2_50->SetBranchAddress("v_fakealpha", &v_Mx50_alpha);
        for (int evt = 0; evt < T_Mx2_50->GetEntries(); evt++)
        {
            T_Mx2_50->GetEntry(evt);
            h_Mx2_50_Met->Fill(f_Mx50_Met, I_Mx50_weight);
        } // End of Mx2_50 Entries loop
        TTree *T_Mx2_150;
        Mx2_150->GetObject("T_tree", T_Mx2_150);
        T_Mx2_150->SetBranchAddress("I_weight", &I_Mx150_weight);
        T_Mx2_150->SetBranchAddress("f_Met", &f_Mx150_Met);
        T_Mx2_150->SetBranchAddress("v_fakealpha", &v_Mx150_alpha);
        for (int evt = 0; evt < T_Mx2_150->GetEntries(); evt++)
        {
            T_Mx2_150->GetEntry(evt);
            h_Mx2_150_Met->Fill(f_Mx150_Met, I_Mx150_weight);
        } // End of Mx2_150 Entries loop
    }     // End of 150 loops

    TString outputfile1 = "./ee_Sig_Met.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Mx2_1_Met->Write();
    h_Mx2_50_Met->Write();
    h_Mx2_150_Met->Write();
    outfile_HT0->Close();
}