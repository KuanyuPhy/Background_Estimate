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

    TH1D *h_Top_nTracks_bjet_1 = ((TH1D *)Topfile->Get("h_Top_nTracks_bjet_1"));
    TH1D *h_Top_nTracks_bjet_cut_1 = ((TH1D *)Topfile->Get("h_Top_nTracks_bjet_cut_1"));
    TH1D *h_Top_nTracks_cjet_1 = ((TH1D *)Topfile->Get("h_Top_nTracks_cjet_1"));
    TH1D *h_Top_nTracks_cjet_cut_1 = ((TH1D *)Topfile->Get("h_Top_nTracks_cjet_cut_1"));
    TH1D *h_Top_nTracks_ljet_1 = ((TH1D *)Topfile->Get("h_Top_nTracks_ljet_1"));
    TH1D *h_Top_nTracks_ljet_cut_1 = ((TH1D *)Topfile->Get("h_Top_nTracks_ljet_cut_1"));
    TH1D *h_Top_nTracks_bjet_2 = ((TH1D *)Topfile->Get("h_Top_nTracks_bjet_2"));
    TH1D *h_Top_nTracks_bjet_cut_2 = ((TH1D *)Topfile->Get("h_Top_nTracks_bjet_cut_2"));
    TH1D *h_Top_nTracks_cjet_2 = ((TH1D *)Topfile->Get("h_Top_nTracks_cjet_2"));
    TH1D *h_Top_nTracks_cjet_cut_2 = ((TH1D *)Topfile->Get("h_Top_nTracks_cjet_cut_2"));
    TH1D *h_Top_nTracks_ljet_2 = ((TH1D *)Topfile->Get("h_Top_nTracks_ljet_2"));
    TH1D *h_Top_nTracks_ljet_cut_2 = ((TH1D *)Topfile->Get("h_Top_nTracks_ljet_cut_2"));
    TH1D *h_Top_nTracks_bjet_3 = ((TH1D *)Topfile->Get("h_Top_nTracks_bjet_3"));
    TH1D *h_Top_nTracks_bjet_cut_3 = ((TH1D *)Topfile->Get("h_Top_nTracks_bjet_cut_3"));
    TH1D *h_Top_nTracks_cjet_3 = ((TH1D *)Topfile->Get("h_Top_nTracks_cjet_3"));
    TH1D *h_Top_nTracks_cjet_cut_3 = ((TH1D *)Topfile->Get("h_Top_nTracks_cjet_cut_3"));
    TH1D *h_Top_nTracks_ljet_3 = ((TH1D *)Topfile->Get("h_Top_nTracks_ljet_3"));
    TH1D *h_Top_nTracks_ljet_cut_3 = ((TH1D *)Topfile->Get("h_Top_nTracks_ljet_cut_3"));

    //---------------------
    // Calculate fake rate
    //---------------------
    TH1D *Top_bfakeRate_eta1 = (TH1D *)h_Top_nTracks_bjet_cut_1->Clone("Top_bfakeRate_eta1");
    Top_bfakeRate_eta1->Divide(h_Top_nTracks_bjet_cut_1, h_Top_nTracks_bjet_1, 1, 1, "b");
    TH1D *Top_cfakeRate_eta1 = (TH1D *)h_Top_nTracks_cjet_cut_1->Clone("Top_cfakeRate_eta1");
    Top_cfakeRate_eta1->Divide(h_Top_nTracks_cjet_cut_1, h_Top_nTracks_cjet_1, 1, 1, "b");
    TH1D *Top_lfakeRate_eta1 = (TH1D *)h_Top_nTracks_ljet_cut_1->Clone("Top_lfakeRate_eta1");
    Top_lfakeRate_eta1->Divide(h_Top_nTracks_ljet_cut_1, h_Top_nTracks_ljet_1, 1, 1, "b");
    TH1D *Top_bfakeRate_eta2 = (TH1D *)h_Top_nTracks_bjet_cut_2->Clone("Top_bfakeRate_eta2");
    Top_bfakeRate_eta2->Divide(h_Top_nTracks_bjet_cut_2, h_Top_nTracks_bjet_2, 1, 1, "b");
    TH1D *Top_cfakeRate_eta2 = (TH1D *)h_Top_nTracks_cjet_cut_2->Clone("Top_cfakeRate_eta2");
    Top_cfakeRate_eta2->Divide(h_Top_nTracks_cjet_cut_2, h_Top_nTracks_cjet_2, 1, 1, "b");
    TH1D *Top_lfakeRate_eta2 = (TH1D *)h_Top_nTracks_ljet_cut_2->Clone("Top_lfakeRate_eta2");
    Top_lfakeRate_eta2->Divide(h_Top_nTracks_ljet_cut_2, h_Top_nTracks_ljet_2, 1, 1, "b");
    TH1D *Top_bfakeRate_eta3 = (TH1D *)h_Top_nTracks_bjet_cut_3->Clone("Top_bfakeRate_eta3");
    Top_bfakeRate_eta3->Divide(h_Top_nTracks_bjet_cut_3, h_Top_nTracks_bjet_3, 1, 1, "b");
    TH1D *Top_cfakeRate_eta3 = (TH1D *)h_Top_nTracks_cjet_cut_3->Clone("Top_cfakeRate_eta3");
    Top_cfakeRate_eta3->Divide(h_Top_nTracks_cjet_cut_3, h_Top_nTracks_cjet_3, 1, 1, "b");
    TH1D *Top_lfakeRate_eta3 = (TH1D *)h_Top_nTracks_ljet_cut_3->Clone("Top_lfakeRate_eta3");
    Top_lfakeRate_eta3->Divide(h_Top_nTracks_ljet_cut_3, h_Top_nTracks_ljet_3, 1, 1, "b");

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    Top_bfakeRate_eta1->Write();
    Top_cfakeRate_eta1->Write();
    Top_lfakeRate_eta1->Write();
    Top_bfakeRate_eta2->Write();
    Top_cfakeRate_eta2->Write();
    Top_lfakeRate_eta2->Write();
    Top_bfakeRate_eta3->Write();
    Top_cfakeRate_eta3->Write();
    Top_lfakeRate_eta3->Write();
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