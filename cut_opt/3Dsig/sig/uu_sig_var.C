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
void uu_sig_var()
{
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztouu/Mu_Mx1_old_remove_0alpha.root");
    TFile *Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztouu/Mu_Mx50_old_remove_0alpha.root");
    TFile *Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztouu/Mu_Mx150_old_remove_0alpha.root");

    TH1D *h_Mx2_1_alpha = new TH1D("h_Mx2_1_alpha", "", 20, 0., 1.);
    h_Mx2_1_alpha->Sumw2();

    TH1D *h_Mx2_50_alpha = new TH1D("h_Mx2_50_alpha", "", 20, 0., 1.);
    h_Mx2_50_alpha->Sumw2();

    TH1D *h_Mx2_150_alpha = new TH1D("h_Mx2_150_alpha", "", 20, 0., 1.);
    h_Mx2_150_alpha->Sumw2();

    TH1D *h_Mx2_1_alpha2 = new TH1D("h_Mx2_1_alpha2", "", 20, 0., 1.);
    h_Mx2_1_alpha2->Sumw2();

    TH1D *h_Mx2_50_alpha2 = new TH1D("h_Mx2_50_alpha2", "", 20, 0., 1.);
    h_Mx2_50_alpha2->Sumw2();

    TH1D *h_Mx2_150_alpha2 = new TH1D("h_Mx2_150_alpha2", "", 20, 0., 1.);
    h_Mx2_150_alpha2->Sumw2();

    TH1D *h_Mx2_1_alpha3 = new TH1D("h_Mx2_1_alpha3", "", 20, 0., 1.);
    h_Mx2_1_alpha3->Sumw2();

    TH1D *h_Mx2_50_alpha3 = new TH1D("h_Mx2_50_alpha3", "", 20, 0., 1.);
    h_Mx2_50_alpha3->Sumw2();

    TH1D *h_Mx2_150_alpha3 = new TH1D("h_Mx2_150_alpha3", "", 20, 0., 1.);
    h_Mx2_150_alpha3->Sumw2();

    TH1D *h_Mx2_1_alpha4 = new TH1D("h_Mx2_1_alpha4", "", 20, 0., 1.);
    h_Mx2_1_alpha4->Sumw2();

    TH1D *h_Mx2_50_alpha4 = new TH1D("h_Mx2_50_alpha4", "", 20, 0., 1.);
    h_Mx2_50_alpha4->Sumw2();

    TH1D *h_Mx2_150_alpha4 = new TH1D("h_Mx2_150_alpha4", "", 20, 0., 1.);
    h_Mx2_150_alpha4->Sumw2();

    TH1D *h_Mx2_1_3DSig = new TH1D("h_Mx2_1_3DSig", "", 20, -5., 5.);
    h_Mx2_1_3DSig->Sumw2();

    TH1D *h_Mx2_50_3DSig = new TH1D("h_Mx2_50_3DSig", "", 20, -5., 5.);
    h_Mx2_50_3DSig->Sumw2();

    TH1D *h_Mx2_150_3DSig = new TH1D("h_Mx2_150_3DSig", "", 20, -5., 5.);
    h_Mx2_150_3DSig->Sumw2();

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;

    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;

    vector<float> *v_Mx1_alpha = new vector<float>();
    vector<float> *v_Mx50_alpha = new vector<float>();
    vector<float> *v_Mx150_alpha = new vector<float>();

    v_Mx1_alpha->clear();
    v_Mx50_alpha->clear();
    v_Mx150_alpha->clear();

    vector<float> *v_Mx1_alpha2 = new vector<float>();
    vector<float> *v_Mx50_alpha2 = new vector<float>();
    vector<float> *v_Mx150_alpha2 = new vector<float>();

    v_Mx1_alpha2->clear();
    v_Mx50_alpha2->clear();
    v_Mx150_alpha2->clear();

    vector<float> *v_Mx1_alpha3 = new vector<float>();
    vector<float> *v_Mx50_alpha3 = new vector<float>();
    vector<float> *v_Mx150_alpha3 = new vector<float>();

    v_Mx1_alpha3->clear();
    v_Mx50_alpha3->clear();
    v_Mx150_alpha3->clear();

    vector<float> *v_Mx1_alpha4 = new vector<float>();
    vector<float> *v_Mx50_alpha4 = new vector<float>();
    vector<float> *v_Mx150_alpha4 = new vector<float>();

    v_Mx1_alpha4->clear();
    v_Mx50_alpha4->clear();
    v_Mx150_alpha4->clear();

    
    vector<float> *v_Mx1_3Dsig = new vector<float>();
    vector<float> *v_Mx50_3Dsig = new vector<float>();
    vector<float> *v_Mx150_3Dsig = new vector<float>();

    v_Mx1_3Dsig->clear();
    v_Mx50_3Dsig->clear();
    v_Mx150_3Dsig->clear();

    TTree *T_Mx2_1;
    Mx2_1->GetObject("T_tree", T_Mx2_1);
    T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
    T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
    T_Mx2_1->SetBranchAddress("v_Chi3Dlog", &v_Mx1_3Dsig);
    T_Mx2_1->SetBranchAddress("v_fakealpha", &v_Mx1_alpha);
    T_Mx2_1->SetBranchAddress("v_fakealpha2", &v_Mx1_alpha2);
    T_Mx2_1->SetBranchAddress("v_fakealpha3", &v_Mx1_alpha3);
    T_Mx2_1->SetBranchAddress("v_fakealpha4", &v_Mx1_alpha4);
    for (int evt = 0; evt < T_Mx2_1->GetEntries(); evt++)
    {
        T_Mx2_1->GetEntry(evt);
        if(f_Mx1_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_Mx1_3Dsig->size(); i++)
        {
            h_Mx2_1_3DSig->Fill((*v_Mx1_3Dsig)[i], I_Mx1_weight);
        }
        for (size_t i = 0; i < v_Mx1_alpha->size(); i++)
        {
            h_Mx2_1_alpha->Fill((*v_Mx1_alpha)[i], I_Mx1_weight);
            h_Mx2_1_alpha2->Fill((*v_Mx1_alpha2)[i], I_Mx1_weight);
            h_Mx2_1_alpha3->Fill((*v_Mx1_alpha3)[i], I_Mx1_weight);
            h_Mx2_1_alpha4->Fill((*v_Mx1_alpha4)[i], I_Mx1_weight);
        }
    } // End of Mx2_1 Entries loop
    TTree *T_Mx2_50;
    Mx2_50->GetObject("T_tree", T_Mx2_50);
    T_Mx2_50->SetBranchAddress("I_weight", &I_Mx50_weight);
    T_Mx2_50->SetBranchAddress("f_Met", &f_Mx50_Met);
    T_Mx2_50->SetBranchAddress("v_Chi3Dlog", &v_Mx50_3Dsig);
    T_Mx2_50->SetBranchAddress("v_fakealpha", &v_Mx50_alpha);
    T_Mx2_50->SetBranchAddress("v_fakealpha2", &v_Mx50_alpha2);
    T_Mx2_50->SetBranchAddress("v_fakealpha3", &v_Mx50_alpha3);
    T_Mx2_50->SetBranchAddress("v_fakealpha4", &v_Mx50_alpha4);
    for (int evt = 0; evt < T_Mx2_50->GetEntries(); evt++)
    {
        T_Mx2_50->GetEntry(evt);
        if(f_Mx50_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_Mx50_3Dsig->size(); i++)
        {
            h_Mx2_50_3DSig->Fill((*v_Mx50_3Dsig)[i], I_Mx50_weight);
        }
        for (size_t i = 0; i < v_Mx50_alpha->size(); i++)
        {
            h_Mx2_50_alpha->Fill((*v_Mx50_alpha)[i], I_Mx50_weight);
            h_Mx2_50_alpha2->Fill((*v_Mx50_alpha2)[i], I_Mx50_weight);
            h_Mx2_50_alpha3->Fill((*v_Mx50_alpha3)[i], I_Mx50_weight);
            h_Mx2_50_alpha4->Fill((*v_Mx50_alpha4)[i], I_Mx50_weight);
        }
    } // End of Mx2_50 Entries loop
    TTree *T_Mx2_150;
    Mx2_150->GetObject("T_tree", T_Mx2_150);
    T_Mx2_150->SetBranchAddress("I_weight", &I_Mx150_weight);
    T_Mx2_150->SetBranchAddress("f_Met", &f_Mx150_Met);
    T_Mx2_150->SetBranchAddress("v_Chi3Dlog", &v_Mx150_3Dsig);
    T_Mx2_150->SetBranchAddress("v_fakealpha", &v_Mx150_alpha);
    T_Mx2_150->SetBranchAddress("v_fakealpha2", &v_Mx150_alpha2);
    T_Mx2_150->SetBranchAddress("v_fakealpha3", &v_Mx150_alpha3);
    T_Mx2_150->SetBranchAddress("v_fakealpha4", &v_Mx150_alpha4);
    for (int evt = 0; evt < T_Mx2_150->GetEntries(); evt++)
    {
        T_Mx2_150->GetEntry(evt);
        if(f_Mx150_Met < 140)
        {
            continue;
        }
        for (size_t i = 0; i < v_Mx150_3Dsig->size(); i++)
        {
            h_Mx2_150_3DSig->Fill((*v_Mx150_3Dsig)[i], I_Mx150_weight);
        }
        for (size_t i = 0; i < v_Mx150_alpha->size(); i++)
        {
            h_Mx2_150_alpha->Fill((*v_Mx150_alpha)[i], I_Mx150_weight);
            h_Mx2_150_alpha2->Fill((*v_Mx150_alpha2)[i], I_Mx150_weight);
            h_Mx2_150_alpha3->Fill((*v_Mx150_alpha3)[i], I_Mx150_weight);
            h_Mx2_150_alpha4->Fill((*v_Mx150_alpha4)[i], I_Mx150_weight);
        }
    } // End of Mx2_150 Entries loop

    TString outputfile1 = "./uu_Sig_alpha.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Mx2_1_alpha->Write();
    h_Mx2_1_alpha2->Write();
    h_Mx2_1_alpha3->Write();
    h_Mx2_1_alpha4->Write();
    h_Mx2_50_alpha->Write();
    h_Mx2_50_alpha2->Write();
    h_Mx2_50_alpha3->Write();
    h_Mx2_50_alpha4->Write();
    h_Mx2_150_alpha->Write();
    h_Mx2_150_alpha2->Write();
    h_Mx2_150_alpha3->Write();
    h_Mx2_150_alpha4->Write();
    h_Mx2_1_3DSig->Write();
    h_Mx2_50_3DSig->Write();
    h_Mx2_150_3DSig->Write();
    outfile_HT0->Close();
}