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
void draw_Sig_muon_info()
{
    TFile *Mx2_150_iso015 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_150_old_remove_0alpha.root");
    TFile *Mx2_150_iso025 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_150_old_remove_0alpha_muonv2.root");

    TH1D *nMu_iso015 = ((TH1D *)Mx2_150_iso015->Get("Event_Variable/h_mu_n"));
    TH1D *nMu_iso025 = ((TH1D *)Mx2_150_iso025->Get("Event_Variable/h_mu_n"));

    nMu_iso025->SetLineColor(kRed);
    nMu_iso025->Draw();
    nMu_iso015->Draw("same");

    

}