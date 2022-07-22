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
#include "./../../../../lib/Cross_section.h"
using namespace std;
void ee_Top_half_fakerate(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *h_Top_nTrk_bjet = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet"));
    TH1D *h_Top_nTrk_bjet_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut"));
    TH1D *h_Top_nTrk_cjet = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet"));
    TH1D *h_Top_nTrk_cjet_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut"));
    TH1D *h_Top_nTrk_ljet = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet"));
    TH1D *h_Top_nTrk_ljet_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut"));
    TH1D *h_Top_nTrk_hjet = ((TH1D *)Topfile->Get("h_Top_nTrk_hjet"));
    TH1D *h_Top_nTrk_hjet_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_hjet_cut"));
    TH1D *h_Top_nTrk = ((TH1D *)Topfile->Get("h_Top_nTrk"));
    TH1D *h_Top_nTrk_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_cut"));

    TH1D *h_Top_nTrk_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_difeta_1"));
    TH1D *h_Top_nTrk_cut_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cut_difeta_1"));
    TH1D *h_Top_nTrk_bjet_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_1"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_1"));
    TH1D *h_Top_nTrk_cjet_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_1"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_1"));
    TH1D *h_Top_nTrk_ljet_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_1"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_1"));
    TH1D *h_Top_nTrk_hjet_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_hjet_difeta_1"));
    TH1D *h_Top_nTrk_hjet_cut_difeta_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_hjet_cut_difeta_1"));

    TH1D *h_Top_nTrk_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_difeta_2"));
    TH1D *h_Top_nTrk_cut_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cut_difeta_2"));
    TH1D *h_Top_nTrk_bjet_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_2"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_2"));
    TH1D *h_Top_nTrk_cjet_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_2"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_2"));
    TH1D *h_Top_nTrk_ljet_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_2"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_2"));
    TH1D *h_Top_nTrk_hjet_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_hjet_difeta_2"));
    TH1D *h_Top_nTrk_hjet_cut_difeta_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_hjet_cut_difeta_2"));

    TH1D *h_Top_nTrk_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_difeta_3"));
    TH1D *h_Top_nTrk_cut_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cut_difeta_3"));
    TH1D *h_Top_nTrk_bjet_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_3"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_3"));
    TH1D *h_Top_nTrk_cjet_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_3"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_3"));
    TH1D *h_Top_nTrk_ljet_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_3"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_3"));
    TH1D *h_Top_nTrk_hjet_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_hjet_difeta_3"));
    TH1D *h_Top_nTrk_hjet_cut_difeta_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_hjet_cut_difeta_3"));

    //---------------------
    // Calculate fake rate
    //---------------------
    TH1D *Top_nTrk_bfakeRate_difeta_1 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_1->Clone("Top_nTrk_bfakeRate_difeta_1");
    Top_nTrk_bfakeRate_difeta_1->Divide(h_Top_nTrk_bjet_cut_difeta_1, h_Top_nTrk_bjet_difeta_1, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_1 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_1->Clone("Top_nTrk_cfakeRate_difeta_1");
    Top_nTrk_cfakeRate_difeta_1->Divide(h_Top_nTrk_cjet_cut_difeta_1, h_Top_nTrk_cjet_difeta_1, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_1 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_1->Clone("Top_nTrk_lfakeRate_difeta_1");
    Top_nTrk_lfakeRate_difeta_1->Divide(h_Top_nTrk_ljet_cut_difeta_1, h_Top_nTrk_ljet_difeta_1, 1, 1, "b");
    TH1D *Top_nTrk_hfakeRate_difeta_1 = (TH1D *)h_Top_nTrk_hjet_cut_difeta_1->Clone("Top_nTrk_hfakeRate_difeta_1");
    Top_nTrk_hfakeRate_difeta_1->Divide(h_Top_nTrk_hjet_cut_difeta_1, h_Top_nTrk_hjet_difeta_1, 1, 1, "b");
    TH1D *Top_nTrk_fakeRate_difeta_1 = (TH1D *)h_Top_nTrk_cut_difeta_1->Clone("Top_nTrk_fakeRate_difeta_1");
    Top_nTrk_fakeRate_difeta_1->Divide(h_Top_nTrk_cut_difeta_1, h_Top_nTrk_difeta_1, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_2 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_2->Clone("Top_nTrk_bfakeRate_difeta_2");
    Top_nTrk_bfakeRate_difeta_2->Divide(h_Top_nTrk_bjet_cut_difeta_2, h_Top_nTrk_bjet_difeta_2, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_2 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_2->Clone("Top_nTrk_cfakeRate_difeta_2");
    Top_nTrk_cfakeRate_difeta_2->Divide(h_Top_nTrk_cjet_cut_difeta_2, h_Top_nTrk_cjet_difeta_2, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_2 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_2->Clone("Top_nTrk_lfakeRate_difeta_2");
    Top_nTrk_lfakeRate_difeta_2->Divide(h_Top_nTrk_ljet_cut_difeta_2, h_Top_nTrk_ljet_difeta_2, 1, 1, "b");
    TH1D *Top_nTrk_hfakeRate_difeta_2 = (TH1D *)h_Top_nTrk_hjet_cut_difeta_2->Clone("Top_nTrk_hfakeRate_difeta_2");
    Top_nTrk_hfakeRate_difeta_2->Divide(h_Top_nTrk_hjet_cut_difeta_2, h_Top_nTrk_hjet_difeta_2, 1, 1, "b");
    TH1D *Top_nTrk_fakeRate_difeta_2 = (TH1D *)h_Top_nTrk_cut_difeta_2->Clone("Top_nTrk_fakeRate_difeta_2");
    Top_nTrk_fakeRate_difeta_2->Divide(h_Top_nTrk_cut_difeta_2, h_Top_nTrk_difeta_2, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_3 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_3->Clone("Top_nTrk_bfakeRate_difeta_3");
    Top_nTrk_bfakeRate_difeta_3->Divide(h_Top_nTrk_bjet_cut_difeta_3, h_Top_nTrk_bjet_difeta_3, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_3 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_3->Clone("Top_nTrk_cfakeRate_difeta_3");
    Top_nTrk_cfakeRate_difeta_3->Divide(h_Top_nTrk_cjet_cut_difeta_3, h_Top_nTrk_cjet_difeta_3, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_3 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_3->Clone("Top_nTrk_lfakeRate_difeta_3");
    Top_nTrk_lfakeRate_difeta_3->Divide(h_Top_nTrk_ljet_cut_difeta_3, h_Top_nTrk_ljet_difeta_3, 1, 1, "b");
    TH1D *Top_nTrk_hfakeRate_difeta_3 = (TH1D *)h_Top_nTrk_hjet_cut_difeta_3->Clone("Top_nTrk_hfakeRate_difeta_3");
    Top_nTrk_hfakeRate_difeta_3->Divide(h_Top_nTrk_hjet_cut_difeta_3, h_Top_nTrk_hjet_difeta_3, 1, 1, "b");
    TH1D *Top_nTrk_fakeRate_difeta_3 = (TH1D *)h_Top_nTrk_cut_difeta_3->Clone("Top_nTrk_fakeRate_difeta_3");
    Top_nTrk_fakeRate_difeta_3->Divide(h_Top_nTrk_cut_difeta_3, h_Top_nTrk_difeta_3, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate = (TH1D *)h_Top_nTrk_bjet_cut->Clone("Top_nTrk_bfakeRate");
    Top_nTrk_bfakeRate->Divide(h_Top_nTrk_bjet_cut, h_Top_nTrk_bjet, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate = (TH1D *)h_Top_nTrk_cjet_cut->Clone("Top_nTrk_cfakeRate");
    Top_nTrk_cfakeRate->Divide(h_Top_nTrk_cjet_cut, h_Top_nTrk_cjet, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate = (TH1D *)h_Top_nTrk_ljet_cut->Clone("Top_nTrk_lfakeRate");
    Top_nTrk_lfakeRate->Divide(h_Top_nTrk_ljet_cut, h_Top_nTrk_ljet, 1, 1, "b");
    TH1D *Top_nTrk_hfakeRate = (TH1D *)h_Top_nTrk_hjet_cut->Clone("Top_nTrk_hfakeRate");
    Top_nTrk_hfakeRate->Divide(h_Top_nTrk_hjet_cut, h_Top_nTrk_hjet, 1, 1, "b");
    TH1D *Top_nTrk_fakeRate = (TH1D *)h_Top_nTrk_cut->Clone("Top_nTrk_fakeRate");
    Top_nTrk_fakeRate->Divide(h_Top_nTrk_cut, h_Top_nTrk, 1, 1, "b");


    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    Top_nTrk_bfakeRate_difeta_1->Write();
    Top_nTrk_cfakeRate_difeta_1->Write();
    Top_nTrk_lfakeRate_difeta_1->Write();
    Top_nTrk_hfakeRate_difeta_1->Write();
    Top_nTrk_fakeRate_difeta_1->Write();
    Top_nTrk_bfakeRate_difeta_2->Write();
    Top_nTrk_cfakeRate_difeta_2->Write();
    Top_nTrk_lfakeRate_difeta_2->Write();
    Top_nTrk_hfakeRate_difeta_2->Write();
    Top_nTrk_fakeRate_difeta_2->Write();
    Top_nTrk_bfakeRate_difeta_3->Write();
    Top_nTrk_cfakeRate_difeta_3->Write();
    Top_nTrk_lfakeRate_difeta_3->Write();
    Top_nTrk_hfakeRate_difeta_3->Write();
    Top_nTrk_fakeRate_difeta_3->Write();
    Top_nTrk_bfakeRate->Write();
    Top_nTrk_cfakeRate->Write();
    Top_nTrk_lfakeRate->Write();
    Top_nTrk_hfakeRate->Write();
    Top_nTrk_fakeRate->Write();
    outfile->Close();
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_Top_half_fakerate();
    }
    else if (argc == 3)
    {
        ee_Top_half_fakerate(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}