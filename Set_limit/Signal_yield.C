#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <vector>
#include <TROOT.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TLine.h>
#include "/home/kuanyu/Documents/CMS/Background_Estimate/lib/Cross_section.h"

using namespace std;
void Signal_yield()
{
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_1_old_remove_0alpha.root");
    TFile *Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_50_old_remove_0alpha.root");
    TFile *Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_150_old_remove_0alpha.root");

    TH1D *h_Mx2_1_Met_cut = new TH1D("h_Mx2_1_Met_cut", "", 150, 0., 1500.);
    h_Mx2_1_Met_cut->Sumw2();

    TH1D *h_Mx2_50_Met_cut = new TH1D("h_Mx2_50_Met_cut", "", 150, 0., 1500.);
    h_Mx2_50_Met_cut->Sumw2();

    TH1D *h_Mx2_150_Met_cut = new TH1D("h_Mx2_150_Met_cut", "", 150, 0., 1500.);
    h_Mx2_150_Met_cut->Sumw2();

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;

    double metcut = 130.;

    TTree *T_Mx2_1;
    Mx2_1->GetObject("T_tree", T_Mx2_1);
    T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
    T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
    for (int evt = 0; evt < T_Mx2_1->GetEntries(); evt++)
    {
        T_Mx2_1->GetEntry(evt);
        if (f_Mx1_Met > metcut)
        {
            h_Mx2_1_Met_cut->Fill(f_Mx1_Met, I_Mx1_weight);
        }
    }
    TTree *T_Mx2_50;
    Mx2_50->GetObject("T_tree", T_Mx2_50);
    T_Mx2_50->SetBranchAddress("I_weight", &I_Mx50_weight);
    T_Mx2_50->SetBranchAddress("f_Met", &f_Mx50_Met);
    for (int evt = 0; evt < T_Mx2_50->GetEntries(); evt++)
    {
        T_Mx2_50->GetEntry(evt);
        if (f_Mx50_Met > metcut)
        {
            h_Mx2_50_Met_cut->Fill(f_Mx50_Met, I_Mx50_weight);
        }
    }
    TTree *T_Mx2_150;
    Mx2_150->GetObject("T_tree", T_Mx2_150);
    T_Mx2_150->SetBranchAddress("I_weight", &I_Mx150_weight);
    T_Mx2_150->SetBranchAddress("f_Met", &f_Mx150_Met);
    for (int evt = 0; evt < T_Mx2_150->GetEntries(); evt++)
    {
        T_Mx2_150->GetEntry(evt);
        if (f_Mx150_Met > metcut)
        {
            h_Mx2_150_Met_cut->Fill(f_Mx150_Met, I_Mx150_weight);
        }
    }
    // h_Mx2_150_Met_cut->Draw("h");
    cout << "Calculate Expect Signal yeild" << endl;

    TH1D *Mx2_1_sumevt = ((TH1D *)Mx2_1->Get("Event_Variable/h_totevent"));
    TH1D *Mx2_50_sumevt = ((TH1D *)Mx2_50->Get("Event_Variable/h_totevent"));
    TH1D *Mx2_150_sumevt = ((TH1D *)Mx2_150->Get("Event_Variable/h_totevent"));

    int Mx2_1_totevt = Mx2_1_sumevt->Integral();
    int Mx2_50_totevt = Mx2_50_sumevt->Integral();
    int Mx2_150_totevt = Mx2_150_sumevt->Integral();

    double Mx2_1Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::Mx2_1CS) / (Mx2_1_totevt)) * 1000;
    double Mx2_50Weight = (GlobalConstants::Lumi2016) * ((GlobalConstants::Mx2_50CS) / (Mx2_50_totevt)) * 1000;
    double Mx2_150Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::Mx2_150CS / (Mx2_150_totevt)) * 1000;

    cout << "Before weight" << endl;
    cout << "Number of event for Mx2 = 1 Gev: " << h_Mx2_1_Met_cut->Integral() << endl;
    cout << "Number of event for Mx2 = 50 Gev: " << h_Mx2_50_Met_cut->Integral() << endl;
    cout << "Number of event for Mx2 = 150 Gev: " << h_Mx2_150_Met_cut->Integral() << endl;

    cout << "After weight" << endl;
    cout << "Number of event for Mx2 = 1 Gev: " << h_Mx2_1_Met_cut->Integral() * Mx2_1Weight << endl;
    cout << "Number of event for Mx2 = 50 Gev: " << h_Mx2_50_Met_cut->Integral() * Mx2_50Weight << endl;
    cout << "Number of event for Mx2 = 150 Gev: " << h_Mx2_150_Met_cut->Integral() * Mx2_150Weight << endl;
}