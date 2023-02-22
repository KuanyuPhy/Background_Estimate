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
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_1_old_remove_0alpha.root");
    TFile *Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_50_old_remove_0alpha.root");
    TFile *Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_150_old_remove_0alpha.root");

    TH1D *h_Mx2_1_jetcsv = new TH1D("h_Mx2_1_jetcsv", "", 125, -11, 1.5);
    TH1D *h_Mx2_50_jetcsv = new TH1D("h_Mx2_50_jetcsv", "", 125, -11, 1.5);
    TH1D *h_Mx2_150_jetcsv = new TH1D("h_Mx2_150_jetcsv", "", 125, -11, 1.5);

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

    vector<float> *v_Mx1_jetcsv = new vector<float>();
    vector<float> *v_Mx50_jetcsv = new vector<float>();
    vector<float> *v_Mx150_jetcsv = new vector<float>();

    double MetCut = 130;

    TTree *T_Mx2_1;
    Mx2_1->GetObject("T_tree", T_Mx2_1);
    T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
    T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
    T_Mx2_1->SetBranchAddress("v_Chi3Dlog", &v_Mx1_3Dsig);
    T_Mx2_1->SetBranchAddress("v_fakealpha", &v_Mx1_alpha);
    T_Mx2_1->SetBranchAddress("f_thinjetCSV", &v_Mx1_jetcsv);
    // v_fakeJetCSV
    for (int evt = 0; evt < T_Mx2_1->GetEntries(); evt++)
    {
        T_Mx2_1->GetEntry(evt);
        for (int ijet = 0; ijet < v_Mx1_jetcsv->size(); ijet++)
        {
            h_Mx2_1_jetcsv->Fill((*v_Mx1_jetcsv)[ijet], I_Mx1_weight);
        }

    } // End of Mx2_1 Entries loop
    h_Mx2_1_jetcsv->Draw("h");
    TTree *T_Mx2_50;
    Mx2_50->GetObject("T_tree", T_Mx2_50);
    T_Mx2_50->SetBranchAddress("I_weight", &I_Mx50_weight);
    T_Mx2_50->SetBranchAddress("f_Met", &f_Mx50_Met);
    T_Mx2_50->SetBranchAddress("v_Chi3Dlog", &v_Mx50_3Dsig);
    T_Mx2_50->SetBranchAddress("v_fakealpha", &v_Mx50_alpha);
    T_Mx2_50->SetBranchAddress("f_thinjetCSV", &v_Mx50_jetcsv);
    for (int evt = 0; evt < T_Mx2_50->GetEntries(); evt++)
    {
        T_Mx2_50->GetEntry(evt);
        for (int ijet = 0; ijet < v_Mx50_jetcsv->size(); ijet++)
        {
            h_Mx2_50_jetcsv->Fill((*v_Mx50_jetcsv)[ijet], I_Mx50_weight);
        }

    } // End of Mx2_50 Entries loop
    TTree *T_Mx2_150;
    Mx2_150->GetObject("T_tree", T_Mx2_150);
    T_Mx2_150->SetBranchAddress("I_weight", &I_Mx150_weight);
    T_Mx2_150->SetBranchAddress("f_Met", &f_Mx150_Met);
    T_Mx2_150->SetBranchAddress("v_Chi3Dlog", &v_Mx150_3Dsig);
    T_Mx2_150->SetBranchAddress("v_fakealpha", &v_Mx150_alpha);
    T_Mx2_150->SetBranchAddress("f_thinjetCSV", &v_Mx150_jetcsv);
    for (int evt = 0; evt < T_Mx2_150->GetEntries(); evt++)
    {
        T_Mx2_150->GetEntry(evt);
        for (int ijet = 0; ijet < v_Mx150_jetcsv->size(); ijet++)
        {
            h_Mx2_150_jetcsv->Fill((*v_Mx150_jetcsv)[ijet], I_Mx150_weight);
        }

    } // End of Mx2_150 Entries loop

    TString outputfile1 = "./ee_Sig_jetcsv.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Mx2_1_jetcsv->Write();
    h_Mx2_50_jetcsv->Write();
    h_Mx2_150_jetcsv->Write();
    outfile_HT0->Close();
}