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
void ee_sig_2017()
{
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/new/2017_ee_Mx21_1p0.root");

    TH1D *h_Mx2_1_jetCSVv2 = new TH1D("h_Mx2_1_jetCSVv2", "", 20, 0, 1);
    h_Mx2_1_jetCSVv2->GetXaxis()->SetTitle("");
    h_Mx2_1_jetCSVv2->GetYaxis()->SetTitle("");
    h_Mx2_1_jetCSVv2->Sumw2();

    TH1D *h_Mx2_1_jetDeepCSV = new TH1D("h_Mx2_1_jetDeepCSV", "", 20, 0, 1);
    h_Mx2_1_jetDeepCSV->GetXaxis()->SetTitle("");
    h_Mx2_1_jetDeepCSV->GetYaxis()->SetTitle("");
    h_Mx2_1_jetDeepCSV->Sumw2();

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;

    vector<float> *v_Mx1_jetCSVv2 = new vector<float>();
    vector<float> *v_Mx50_jetCSVv2 = new vector<float>();
    vector<float> *v_Mx150_jetCSVv2 = new vector<float>();

    v_Mx1_jetCSVv2->clear();
    v_Mx50_jetCSVv2->clear();
    v_Mx150_jetCSVv2->clear();

    vector<float> *v_Mx1_jetDeepCSV = new vector<float>();
    v_Mx1_jetDeepCSV->clear();

    TTree *T_Mx2_1;
    Mx2_1->GetObject("T_tree", T_Mx2_1);
    T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
    T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
    T_Mx2_1->SetBranchAddress("f_thinjetCSVv2", &v_Mx1_jetCSVv2);
    T_Mx2_1->SetBranchAddress("f_thinjetDeepCsv", &v_Mx1_jetDeepCSV);
    for (int evt = 0; evt < T_Mx2_1->GetEntries(); evt++)
    {
        T_Mx2_1->GetEntry(evt);
        for (size_t ijet = 0; ijet < v_Mx1_jetCSVv2->size(); ijet++)
        {
            if ((*v_Mx1_jetCSVv2)[ijet] == -10)
            {
                continue;
            }
            h_Mx2_1_jetCSVv2->Fill((*v_Mx1_jetCSVv2)[ijet], I_Mx1_weight);
            h_Mx2_1_jetDeepCSV->Fill((*v_Mx1_jetDeepCSV)[ijet], I_Mx1_weight);
        }

    } // End of Mx2_1 Entries loop

    h_Mx2_1_jetCSVv2->Draw("h");

    TString outputfile1 = "./ee_Sig_Met_2017.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Mx2_1_jetCSVv2->Write();
    h_Mx2_1_jetDeepCSV->Write();

    outfile_HT0->Close();
}