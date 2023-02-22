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
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_1_old_remove_0alpha.root");
    TFile *Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_50_old_remove_0alpha.root");
    TFile *Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_150_old_remove_0alpha.root");

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

    TH1D *h_Mx2_1_Met = new TH1D("h_Mx2_1_Met", "", 50, 0, 500);
    h_Mx2_1_Met->Sumw2();

    TH1D *h_Mx2_50_Met = new TH1D("h_Mx2_50_Met", "", 50, 0, 500);
    h_Mx2_50_Met->Sumw2();

    TH1D *h_Mx2_150_Met = new TH1D("h_Mx2_150_Met", "", 50, 0, 500);
    h_Mx2_150_Met->Sumw2();

    TH1D *h_Mx2_1_dilepPT = new TH1D("h_Mx2_1_dilepPT", "", 100, 0., 1000.);
    h_Mx2_1_dilepPT->Sumw2();

    TH1D *h_Mx2_50_dilepPT = new TH1D("h_Mx2_50_dilepPT", "", 100, 0., 1000.);
    h_Mx2_50_dilepPT->Sumw2();

    TH1D *h_Mx2_150_dilepPT = new TH1D("h_Mx2_150_dilepPT", "", 100, 0., 1000.);
    h_Mx2_150_dilepPT->Sumw2();

    TH1D *h_Mx2_1_Met_cut = new TH1D("h_Mx2_1_Met_cut", "", 50, 0, 500);
    h_Mx2_1_Met_cut->Sumw2();

    TH1D *h_Mx2_50_Met_cut = new TH1D("h_Mx2_50_Met_cut", "", 50, 0, 500);
    h_Mx2_50_Met_cut->Sumw2();

    TH1D *h_Mx2_150_Met_cut = new TH1D("h_Mx2_150_Met_cut", "", 50, 0, 500);
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

    float metcut = 140;

    TTree *T_Mx2_1;
    Mx2_1->GetObject("T_tree", T_Mx2_1);
    T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
    T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
    T_Mx2_1->SetBranchAddress("f_dileptonPT", &f_Mx1_dilepPT);
    T_Mx2_1->SetBranchAddress("v_fakealpha", &v_Mx1_alpha);
    for (int evt = 0; evt < T_Mx2_1->GetEntries(); evt++)
    {
        T_Mx2_1->GetEntry(evt);
        h_Mx2_1_Met->Fill(f_Mx1_Met, I_Mx1_weight);
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
    T_Mx2_50->SetBranchAddress("f_dileptonPT", &f_Mx50_dilepPT);
    T_Mx2_50->SetBranchAddress("v_fakealpha", &v_Mx50_alpha);
    for (int evt = 0; evt < T_Mx2_50->GetEntries(); evt++)
    {
        T_Mx2_50->GetEntry(evt);
        h_Mx2_50_Met->Fill(f_Mx50_Met, I_Mx50_weight);
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
    T_Mx2_150->SetBranchAddress("f_dileptonPT", &f_Mx150_dilepPT);
    T_Mx2_150->SetBranchAddress("v_fakealpha", &v_Mx150_alpha);
    for (int evt = 0; evt < T_Mx2_150->GetEntries(); evt++)
    {
        T_Mx2_150->GetEntry(evt);
        h_Mx2_150_Met->Fill(f_Mx150_Met, I_Mx150_weight);
        if (f_Mx150_Met > metcut)
        {
            h_Mx2_150_Met_cut->Fill(f_Mx150_Met, I_Mx150_weight);
            h_Mx2_150_dilepPT->Fill(f_Mx150_dilepPT, I_Mx150_weight);
        }
    } // End of Mx2_150 Entries loop

    /*
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
            //-------------------
            // Scan Met
            //-------------------
            h_pass_Mx2_1->Fill(i, I_Mx1_weight);
            // cout << "Met cut"<<i*10<<endl;
            if (f_Mx1_Met > metcut)
            {
                h_pass_Mx2_1_nMetcut->Fill(i, I_Mx1_weight);
            }
        } // End of Mx2_1 Entries loop
        TTree *T_Mx2_50;
        Mx2_50->GetObject("T_tree", T_Mx2_50);
        T_Mx2_50->SetBranchAddress("I_weight", &I_Mx50_weight);
        T_Mx2_50->SetBranchAddress("f_Met", &f_Mx50_Met);
        T_Mx2_50->SetBranchAddress("v_fakealpha", &v_Mx50_alpha);
        for (int evt = 0; evt < T_Mx2_50->GetEntries(); evt++)
        {
            T_Mx2_50->GetEntry(evt);
            //-------------------
            // Scan Met
            //-------------------
            h_pass_Mx2_50->Fill(i, I_Mx50_weight);
            // cout << "Met cut"<<i*10<<endl;
            if (f_Mx50_Met > metcut)
            {
                // cout << "metcut = " << metcut << endl;
                // cout << "Met = " << f_Mx1_Met << endl;
                h_pass_Mx2_50_nMetcut->Fill(i, I_Mx50_weight);
            }
        } // End of Mx2_50 Entries loop
        TTree *T_Mx2_150;
        Mx2_150->GetObject("T_tree", T_Mx2_150);
        T_Mx2_150->SetBranchAddress("I_weight", &I_Mx150_weight);
        T_Mx2_150->SetBranchAddress("f_Met", &f_Mx150_Met);
        T_Mx2_150->SetBranchAddress("v_fakealpha", &v_Mx150_alpha);
        for (int evt = 0; evt < T_Mx2_150->GetEntries(); evt++)
        {
            T_Mx2_150->GetEntry(evt);
            //-------------------
            // Scan Met
            //-------------------
            // h_Mx2_150_Met->Fill(f_Mx150_Met);
            h_pass_Mx2_150->Fill(i, I_Mx150_weight);
            if (f_Mx150_Met > metcut)
            {
                // cout << "metcut = " << metcut << endl;
                // cout << "Met = " << f_Mx1_Met << endl;
                h_pass_Mx2_150_nMetcut->Fill(i, I_Mx150_weight);
            }
        } // End of Mx2_150 Entries loop
    }     // End of 150 loops

    TH1D *h_Mx2_1_eff = (TH1D *)h_pass_Mx2_1_nMetcut->Clone("h_Mx2_1_eff");
    h_Mx2_1_eff->Divide(h_pass_Mx2_1_nMetcut, h_pass_Mx2_1, 1, 1);

    TH1D *h_Mx2_50_eff = (TH1D *)h_pass_Mx2_50_nMetcut->Clone("h_Mx2_50_eff");
    h_Mx2_50_eff->Divide(h_pass_Mx2_50_nMetcut, h_pass_Mx2_50, 1, 1);

    TH1D *h_Mx2_150_eff = (TH1D *)h_pass_Mx2_150_nMetcut->Clone("h_Mx2_150_eff");
    h_Mx2_150_eff->Divide(h_pass_Mx2_150_nMetcut, h_pass_Mx2_150, 1, 1);

    */

    TString outputfile1 = "./ee_Sig_Met.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Mx2_1_Met->Write();
    h_Mx2_50_Met->Write();
    h_Mx2_150_Met->Write();
    h_Mx2_1_Met_cut->Write();
    h_Mx2_50_Met_cut->Write();
    h_Mx2_150_Met_cut->Write();
    h_Mx2_1_dilepPT->Write();
    h_Mx2_50_dilepPT->Write();
    h_Mx2_150_dilepPT->Write();
    outfile_HT0->Close();
}