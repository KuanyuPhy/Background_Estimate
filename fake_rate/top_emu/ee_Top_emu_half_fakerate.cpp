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
void ee_Top_emu_half_fakerate(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *h_Top_nTrk_bjet_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_lowMET_1"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_lowMET_1"));
    TH1D *h_Top_nTrk_cjet_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_lowMET_1"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_lowMET_1"));
    TH1D *h_Top_nTrk_ljet_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_lowMET_1"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_lowMET_1"));

    TH1D *h_Top_nTrk_bjet_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_lowMET_2"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_lowMET_2"));
    TH1D *h_Top_nTrk_cjet_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_lowMET_2"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_lowMET_2"));
    TH1D *h_Top_nTrk_ljet_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_lowMET_2"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_lowMET_2"));

    TH1D *h_Top_nTrk_bjet_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_lowMET_3"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_lowMET_3"));
    TH1D *h_Top_nTrk_cjet_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_lowMET_3"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_lowMET_3"));
    TH1D *h_Top_nTrk_ljet_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_lowMET_3"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_lowMET_3"));

    TH1D *h_Top_nTrk_bjet_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_midMET_1"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_midMET_1"));
    TH1D *h_Top_nTrk_cjet_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_midMET_1"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_midMET_1"));
    TH1D *h_Top_nTrk_ljet_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_midMET_1"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_midMET_1"));

    TH1D *h_Top_nTrk_bjet_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_midMET_2"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_midMET_2"));
    TH1D *h_Top_nTrk_cjet_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_midMET_2"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_midMET_2"));
    TH1D *h_Top_nTrk_ljet_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_midMET_2"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_midMET_2"));

    TH1D *h_Top_nTrk_bjet_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_midMET_3"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_midMET_3"));
    TH1D *h_Top_nTrk_cjet_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_midMET_3"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_midMET_3"));
    TH1D *h_Top_nTrk_ljet_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_midMET_3"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_midMET_3"));


    TH1D *h_Top_nTrk_bjet_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_highMET_1"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_highMET_1"));
    TH1D *h_Top_nTrk_cjet_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_highMET_1"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_highMET_1"));
    TH1D *h_Top_nTrk_ljet_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_highMET_1"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_highMET_1"));

    TH1D *h_Top_nTrk_bjet_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_highMET_2"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_highMET_2"));
    TH1D *h_Top_nTrk_cjet_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_highMET_2"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_highMET_2"));
    TH1D *h_Top_nTrk_ljet_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_highMET_2"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_highMET_2"));

    TH1D *h_Top_nTrk_bjet_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_highMET_3"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_highMET_3"));
    TH1D *h_Top_nTrk_cjet_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_highMET_3"));
    TH1D *h_Top_nTrk_cjet_cut_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_highMET_3"));
    TH1D *h_Top_nTrk_ljet_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_highMET_3"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_highMET_3"));

    //---------------------
    // Calculate fake rate
    //---------------------
    // For Hight MET mid MET Low MET
    TH1D *Top_nTrk_bfakeRate_difeta_lowMET_1 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_lowMET_1->Clone("Top_nTrk_bfakeRate_difeta_lowMET_1");
    Top_nTrk_bfakeRate_difeta_lowMET_1->Divide(h_Top_nTrk_bjet_cut_difeta_lowMET_1, h_Top_nTrk_bjet_difeta_lowMET_1, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_lowMET_1 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_lowMET_1->Clone("Top_nTrk_cfakeRate_difeta_lowMET_1");
    Top_nTrk_cfakeRate_difeta_lowMET_1->Divide(h_Top_nTrk_cjet_cut_difeta_lowMET_1, h_Top_nTrk_cjet_difeta_lowMET_1, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_lowMET_1 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_lowMET_1->Clone("Top_nTrk_lfakeRate_difeta_lowMET_1");
    Top_nTrk_lfakeRate_difeta_lowMET_1->Divide(h_Top_nTrk_ljet_cut_difeta_lowMET_1, h_Top_nTrk_ljet_difeta_lowMET_1, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_lowMET_2 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_lowMET_2->Clone("Top_nTrk_bfakeRate_difeta_lowMET_2");
    Top_nTrk_bfakeRate_difeta_lowMET_2->Divide(h_Top_nTrk_bjet_cut_difeta_lowMET_2, h_Top_nTrk_bjet_difeta_lowMET_2, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_lowMET_2 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_lowMET_2->Clone("Top_nTrk_cfakeRate_difeta_lowMET_2");
    Top_nTrk_cfakeRate_difeta_lowMET_2->Divide(h_Top_nTrk_cjet_cut_difeta_lowMET_2, h_Top_nTrk_cjet_difeta_lowMET_2, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_lowMET_2 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_lowMET_2->Clone("Top_nTrk_lfakeRate_difeta_lowMET_2");
    Top_nTrk_lfakeRate_difeta_lowMET_2->Divide(h_Top_nTrk_ljet_cut_difeta_lowMET_2, h_Top_nTrk_ljet_difeta_lowMET_2, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_lowMET_3 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_lowMET_3->Clone("Top_nTrk_bfakeRate_difeta_lowMET_3");
    Top_nTrk_bfakeRate_difeta_lowMET_3->Divide(h_Top_nTrk_bjet_cut_difeta_lowMET_3, h_Top_nTrk_bjet_difeta_lowMET_3, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_lowMET_3 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_lowMET_3->Clone("Top_nTrk_cfakeRate_difeta_lowMET_3");
    Top_nTrk_cfakeRate_difeta_lowMET_3->Divide(h_Top_nTrk_cjet_cut_difeta_lowMET_3, h_Top_nTrk_cjet_difeta_lowMET_3, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_lowMET_3 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_lowMET_3->Clone("Top_nTrk_lfakeRate_difeta_lowMET_3");
    Top_nTrk_lfakeRate_difeta_lowMET_3->Divide(h_Top_nTrk_ljet_cut_difeta_lowMET_3, h_Top_nTrk_ljet_difeta_lowMET_3, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_midMET_1 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_midMET_1->Clone("Top_nTrk_bfakeRate_difeta_midMET_1");
    Top_nTrk_bfakeRate_difeta_midMET_1->Divide(h_Top_nTrk_bjet_cut_difeta_midMET_1, h_Top_nTrk_bjet_difeta_midMET_1, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_midMET_1 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_midMET_1->Clone("Top_nTrk_cfakeRate_difeta_midMET_1");
    Top_nTrk_cfakeRate_difeta_midMET_1->Divide(h_Top_nTrk_cjet_cut_difeta_midMET_1, h_Top_nTrk_cjet_difeta_midMET_1, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_midMET_1 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_midMET_1->Clone("Top_nTrk_lfakeRate_difeta_midMET_1");
    Top_nTrk_lfakeRate_difeta_midMET_1->Divide(h_Top_nTrk_ljet_cut_difeta_midMET_1, h_Top_nTrk_ljet_difeta_midMET_1, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_midMET_2 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_midMET_2->Clone("Top_nTrk_bfakeRate_difeta_midMET_2");
    Top_nTrk_bfakeRate_difeta_midMET_2->Divide(h_Top_nTrk_bjet_cut_difeta_midMET_2, h_Top_nTrk_bjet_difeta_midMET_2, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_midMET_2 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_midMET_2->Clone("Top_nTrk_cfakeRate_difeta_midMET_2");
    Top_nTrk_cfakeRate_difeta_midMET_2->Divide(h_Top_nTrk_cjet_cut_difeta_midMET_2, h_Top_nTrk_cjet_difeta_midMET_2, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_midMET_2 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_midMET_2->Clone("Top_nTrk_lfakeRate_difeta_midMET_2");
    Top_nTrk_lfakeRate_difeta_midMET_2->Divide(h_Top_nTrk_ljet_cut_difeta_midMET_2, h_Top_nTrk_ljet_difeta_midMET_2, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_midMET_3 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_midMET_3->Clone("Top_nTrk_bfakeRate_difeta_midMET_3");
    Top_nTrk_bfakeRate_difeta_midMET_3->Divide(h_Top_nTrk_bjet_cut_difeta_midMET_3, h_Top_nTrk_bjet_difeta_midMET_3, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_midMET_3 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_midMET_3->Clone("Top_nTrk_cfakeRate_difeta_midMET_3");
    Top_nTrk_cfakeRate_difeta_midMET_3->Divide(h_Top_nTrk_cjet_cut_difeta_midMET_3, h_Top_nTrk_cjet_difeta_midMET_3, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_midMET_3 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_midMET_3->Clone("Top_nTrk_lfakeRate_difeta_midMET_3");
    Top_nTrk_lfakeRate_difeta_midMET_3->Divide(h_Top_nTrk_ljet_cut_difeta_midMET_3, h_Top_nTrk_ljet_difeta_midMET_3, 1, 1, "b");


    TH1D *Top_nTrk_bfakeRate_difeta_highMET_1 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_highMET_1->Clone("Top_nTrk_bfakeRate_difeta_highMET_1");
    Top_nTrk_bfakeRate_difeta_highMET_1->Divide(h_Top_nTrk_bjet_cut_difeta_highMET_1, h_Top_nTrk_bjet_difeta_highMET_1, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_highMET_1 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_highMET_1->Clone("Top_nTrk_cfakeRate_difeta_highMET_1");
    Top_nTrk_cfakeRate_difeta_highMET_1->Divide(h_Top_nTrk_cjet_cut_difeta_highMET_1, h_Top_nTrk_cjet_difeta_highMET_1, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_highMET_1 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_highMET_1->Clone("Top_nTrk_lfakeRate_difeta_highMET_1");
    Top_nTrk_lfakeRate_difeta_highMET_1->Divide(h_Top_nTrk_ljet_cut_difeta_highMET_1, h_Top_nTrk_ljet_difeta_highMET_1, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_highMET_2 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_highMET_2->Clone("Top_nTrk_bfakeRate_difeta_highMET_2");
    Top_nTrk_bfakeRate_difeta_highMET_2->Divide(h_Top_nTrk_bjet_cut_difeta_highMET_2, h_Top_nTrk_bjet_difeta_highMET_2, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_highMET_2 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_highMET_2->Clone("Top_nTrk_cfakeRate_difeta_highMET_2");
    Top_nTrk_cfakeRate_difeta_highMET_2->Divide(h_Top_nTrk_cjet_cut_difeta_highMET_2, h_Top_nTrk_cjet_difeta_highMET_2, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_highMET_2 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_highMET_2->Clone("Top_nTrk_lfakeRate_difeta_highMET_2");
    Top_nTrk_lfakeRate_difeta_highMET_2->Divide(h_Top_nTrk_ljet_cut_difeta_highMET_2, h_Top_nTrk_ljet_difeta_highMET_2, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_highMET_3 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_highMET_3->Clone("Top_nTrk_bfakeRate_difeta_highMET_3");
    Top_nTrk_bfakeRate_difeta_highMET_3->Divide(h_Top_nTrk_bjet_cut_difeta_highMET_3, h_Top_nTrk_bjet_difeta_highMET_3, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate_difeta_highMET_3 = (TH1D *)h_Top_nTrk_cjet_cut_difeta_highMET_3->Clone("Top_nTrk_cfakeRate_difeta_highMET_3");
    Top_nTrk_cfakeRate_difeta_highMET_3->Divide(h_Top_nTrk_cjet_cut_difeta_highMET_3, h_Top_nTrk_cjet_difeta_highMET_3, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_highMET_3 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_highMET_3->Clone("Top_nTrk_lfakeRate_difeta_highMET_3");
    Top_nTrk_lfakeRate_difeta_highMET_3->Divide(h_Top_nTrk_ljet_cut_difeta_highMET_3, h_Top_nTrk_ljet_difeta_highMET_3, 1, 1, "b");

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();

    Top_nTrk_bfakeRate_difeta_lowMET_1->Write();
    Top_nTrk_cfakeRate_difeta_lowMET_1->Write();
    Top_nTrk_lfakeRate_difeta_lowMET_1->Write();

    Top_nTrk_bfakeRate_difeta_lowMET_2->Write();
    Top_nTrk_cfakeRate_difeta_lowMET_2->Write();
    Top_nTrk_lfakeRate_difeta_lowMET_2->Write();

    Top_nTrk_bfakeRate_difeta_lowMET_3->Write();
    Top_nTrk_cfakeRate_difeta_lowMET_3->Write();
    Top_nTrk_lfakeRate_difeta_lowMET_3->Write();

    Top_nTrk_bfakeRate_difeta_midMET_1->Write();
    Top_nTrk_cfakeRate_difeta_midMET_1->Write();
    Top_nTrk_lfakeRate_difeta_midMET_1->Write();

    Top_nTrk_bfakeRate_difeta_midMET_2->Write();
    Top_nTrk_cfakeRate_difeta_midMET_2->Write();
    Top_nTrk_lfakeRate_difeta_midMET_2->Write();

    Top_nTrk_bfakeRate_difeta_midMET_3->Write();
    Top_nTrk_cfakeRate_difeta_midMET_3->Write();
    Top_nTrk_lfakeRate_difeta_midMET_3->Write();

    Top_nTrk_bfakeRate_difeta_highMET_1->Write();
    Top_nTrk_cfakeRate_difeta_highMET_1->Write();
    Top_nTrk_lfakeRate_difeta_highMET_1->Write();

    Top_nTrk_bfakeRate_difeta_highMET_2->Write();
    Top_nTrk_cfakeRate_difeta_highMET_2->Write();
    Top_nTrk_lfakeRate_difeta_highMET_2->Write();

    Top_nTrk_bfakeRate_difeta_highMET_3->Write();
    Top_nTrk_cfakeRate_difeta_highMET_3->Write();
    Top_nTrk_lfakeRate_difeta_highMET_3->Write();

    outfile->Close();
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_Top_emu_half_fakerate();
    }
    else if (argc == 3)
    {
        ee_Top_emu_half_fakerate(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}