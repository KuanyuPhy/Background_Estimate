#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TLine.h>
#include <TError.h>
#include "TLegend.h"
#include <cstring>
#include "./../../lib/Cross_section.h"
using namespace std;

TFile *Top_ee = new TFile("/home/kuanyu/Documents/CMS/Background_Estimate/cut_opt/cuteff/top/output/Top_ee_output.root");
TFile *Top_eu = new TFile("/home/kuanyu/Documents/CMS/Background_Estimate/cut_opt/cuteff/top_eu/output/Top_eu_output.root");

TH1D *h_ee_npass = ((TH1D *)Top_ee->Get("h_ee_pass"));
TH1D *h_eu_npass = ((TH1D *)Top_eu->Get("h_eu_pass"));

void Top_eff(TString outputfile = "Top_ee_output.root")
{

    h_ee_npass->SetBarWidth(0.45);
    h_ee_npass->SetBarOffset(0.1);
    h_ee_npass->SetFillColor(49);

    h_eu_npass->SetBarWidth(0.4);
    h_eu_npass->SetBarOffset(0.6);
    h_eu_npass->SetFillColor(50);

    h_eu_npass->GetXaxis()->SetBinLabel(2, "Total Event");

    h_eu_npass->GetXaxis()->SetBinLabel(3, "Vertex Cut");

    h_eu_npass->GetXaxis()->SetBinLabel(4, "dilep PT Cut");

    h_eu_npass->GetXaxis()->SetBinLabel(5, "dilep Mass Cut");

    h_eu_npass->GetXaxis()->SetBinLabel(6, "diboson Cut");

    h_eu_npass->GetXaxis()->SetBinLabel(7, "Veto Tau");

    h_eu_npass->GetXaxis()->SetBinLabel(8, "At least One Jet");

    h_eu_npass->GetXaxis()->SetBinLabel(9, "Track Cut");


    h_eu_npass->GetXaxis()->SetTitle("Cut");

    h_eu_npass->GetYaxis()->SetTitle("N event");

    h_eu_npass->Draw("bar2,text0");

    h_ee_npass->Draw("bar2,text0 ,same");

    TLegend *legend = new TLegend(0.55, 0.65, 0.76, 0.82);
    legend->AddEntry(h_ee_npass, "Top to ee", "f");
    legend->AddEntry(h_eu_npass, "Top to eu", "f");
    legend->Draw();

    gStyle->SetOptStat(0);

    // TFile *outfile = TFile::Open(outputfile, "RECREATE");
    // outfile->cd();
    // h_ee_pass->Write();
    // outfile->Close();

    // cout << getWeight(file) << endl;
    // cout << "TTTo2L2NuWeight = " << TTTo2L2NuWeight << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        Top_eff();
    }
    else if (argc == 3)
    {
        Top_eff(argv[1]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}