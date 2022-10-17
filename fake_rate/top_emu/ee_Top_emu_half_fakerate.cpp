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

    // Not Consider eta
    TH1D *h_Top_nTrk_bjet = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet"));
    TH1D *h_Top_nTrk_bjet_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut"));
    TH1D *h_Top_nTrk_ljet = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet"));
    TH1D *h_Top_nTrk_ljet_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut"));

    TH1D *h_Top_nTrk_jet_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_jet_lowDilepPt"));
    TH1D *h_Top_nTrk_jet_cut_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_jet_cut_lowDilepPt"));
    TH1D *h_Top_nTrk_bjet_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_lowDilepPt"));
    TH1D *h_Top_nTrk_bjet_cut_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_lowDilepPt"));
    TH1D *h_Top_nTrk_ljet_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_lowDilepPt"));
    TH1D *h_Top_nTrk_ljet_cut_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_lowDilepPt"));

    TH1D *h_Top_nTrk_jet_highDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_jet_highDilepPt"));
    TH1D *h_Top_nTrk_jet_cut_highDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_jet_cut_highDilepPt"));
    TH1D *h_Top_nTrk_bjet_highDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_highDilepPt"));
    TH1D *h_Top_nTrk_bjet_cut_highDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_highDilepPt"));
    TH1D *h_Top_nTrk_ljet_highDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_highDilepPt"));
    TH1D *h_Top_nTrk_ljet_cut_highDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_highDilepPt"));

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

    //---------------------------
    // For dilepton PT separation
    //---------------------------
    TH1D *h_Top_nTrk_bjet_difeta_lowDilepPt_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_lowDilepPt_1"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_lowDilepPt_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_lowDilepPt_1"));
    TH1D *h_Top_nTrk_ljet_difeta_lowDilepPt_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_lowDilepPt_1"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_lowDilepPt_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_lowDilepPt_1"));

    TH1D *h_Top_nTrk_bjet_difeta_lowDilepPt_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_lowDilepPt_2"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_lowDilepPt_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_lowDilepPt_2"));
    TH1D *h_Top_nTrk_ljet_difeta_lowDilepPt_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_lowDilepPt_2"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_lowDilepPt_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_lowDilepPt_2"));

    TH1D *h_Top_nTrk_bjet_difeta_lowDilepPt_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_lowDilepPt_3"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_lowDilepPt_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_lowDilepPt_3"));
    TH1D *h_Top_nTrk_ljet_difeta_lowDilepPt_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_lowDilepPt_3"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_lowDilepPt_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_lowDilepPt_3"));

    TH1D *h_Top_nTrk_bjet_difeta_highDilepPt_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_highDilepPt_1"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_highDilepPt_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_highDilepPt_1"));
    TH1D *h_Top_nTrk_ljet_difeta_highDilepPt_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_highDilepPt_1"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_highDilepPt_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_highDilepPt_1"));

    TH1D *h_Top_nTrk_bjet_difeta_highDilepPt_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_highDilepPt_2"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_highDilepPt_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_highDilepPt_2"));
    TH1D *h_Top_nTrk_ljet_difeta_highDilepPt_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_highDilepPt_2"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_highDilepPt_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_highDilepPt_2"));

    TH1D *h_Top_nTrk_bjet_difeta_highDilepPt_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_highDilepPt_3"));
    TH1D *h_Top_nTrk_bjet_cut_difeta_highDilepPt_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_highDilepPt_3"));
    TH1D *h_Top_nTrk_ljet_difeta_highDilepPt_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_highDilepPt_3"));
    TH1D *h_Top_nTrk_ljet_cut_difeta_highDilepPt_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_highDilepPt_3"));

    //---------------------
    // Calculate fake rate
    //---------------------
    // Not consider eta
    TH1D *Top_nTrk_bfakeRate_lowMET = (TH1D *)h_Top_nTrk_bjet_cut->Clone("Top_nTrk_bfakeRate_lowMET");
    Top_nTrk_bfakeRate_lowMET->Divide(h_Top_nTrk_bjet_cut, h_Top_nTrk_bjet, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_lowMET = (TH1D *)h_Top_nTrk_ljet_cut->Clone("Top_nTrk_lfakeRate_lowMET");
    Top_nTrk_lfakeRate_lowMET->Divide(h_Top_nTrk_ljet_cut, h_Top_nTrk_ljet, 1, 1, "b");

    TH1D *Top_nTrk_fakeRate_lowDilepPt = (TH1D *)h_Top_nTrk_jet_cut_lowDilepPt->Clone("Top_nTrk_fakeRate_lowDilepPt");
    Top_nTrk_fakeRate_lowDilepPt->Divide(h_Top_nTrk_jet_cut_lowDilepPt, h_Top_nTrk_jet_lowDilepPt, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_lowDilepPt = (TH1D *)h_Top_nTrk_bjet_cut_lowDilepPt->Clone("Top_nTrk_bfakeRate_lowDilepPt");
    Top_nTrk_bfakeRate_lowDilepPt->Divide(h_Top_nTrk_bjet_cut_lowDilepPt, h_Top_nTrk_bjet_lowDilepPt, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_lowDilepPt = (TH1D *)h_Top_nTrk_ljet_cut_lowDilepPt->Clone("Top_nTrk_lfakeRate_lowDilepPt");
    Top_nTrk_lfakeRate_lowDilepPt->Divide(h_Top_nTrk_ljet_cut_lowDilepPt, h_Top_nTrk_ljet_lowDilepPt, 1, 1, "b");

    TH1D *Top_nTrk_fakeRate_highDilepPt = (TH1D *)h_Top_nTrk_jet_cut_highDilepPt->Clone("Top_nTrk_fakeRate_highDilepPt");
    Top_nTrk_fakeRate_highDilepPt->Divide(h_Top_nTrk_jet_cut_highDilepPt, h_Top_nTrk_jet_highDilepPt, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_highDilepPt = (TH1D *)h_Top_nTrk_bjet_cut_highDilepPt->Clone("Top_nTrk_bfakeRate_highDilepPt");
    Top_nTrk_bfakeRate_highDilepPt->Divide(h_Top_nTrk_bjet_cut_highDilepPt, h_Top_nTrk_bjet_highDilepPt, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_highDilepPt = (TH1D *)h_Top_nTrk_ljet_cut_highDilepPt->Clone("Top_nTrk_lfakeRate_highDilepPt");
    Top_nTrk_lfakeRate_highDilepPt->Divide(h_Top_nTrk_ljet_cut_highDilepPt, h_Top_nTrk_ljet_highDilepPt, 1, 1, "b");
    // Consider eta
    TH1D *Top_nTrk_bfakeRate_lowDilepPt_1 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_lowDilepPt_1->Clone("Top_nTrk_bfakeRate_lowDilepPt_1");
    Top_nTrk_bfakeRate_lowDilepPt_1->Divide(h_Top_nTrk_bjet_cut_difeta_lowDilepPt_1, h_Top_nTrk_bjet_difeta_lowDilepPt_1, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_lowDilepPt_1 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_lowDilepPt_1->Clone("Top_nTrk_lfakeRate_lowDilepPt_1");
    Top_nTrk_lfakeRate_lowDilepPt_1->Divide(h_Top_nTrk_ljet_cut_difeta_lowDilepPt_1, h_Top_nTrk_ljet_difeta_lowDilepPt_1, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_lowDilepPt_2 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_lowDilepPt_2->Clone("Top_nTrk_bfakeRate_lowDilepPt_2");
    Top_nTrk_bfakeRate_lowDilepPt_2->Divide(h_Top_nTrk_bjet_cut_difeta_lowDilepPt_2, h_Top_nTrk_bjet_difeta_lowDilepPt_2, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_lowDilepPt_2 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_lowDilepPt_2->Clone("Top_nTrk_lfakeRate_lowDilepPt_2");
    Top_nTrk_lfakeRate_lowDilepPt_2->Divide(h_Top_nTrk_ljet_cut_difeta_lowDilepPt_2, h_Top_nTrk_ljet_difeta_lowDilepPt_2, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_lowDilepPt_3 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_lowDilepPt_3->Clone("Top_nTrk_bfakeRate_lowDilepPt_2");
    Top_nTrk_bfakeRate_lowDilepPt_3->Divide(h_Top_nTrk_bjet_cut_difeta_lowDilepPt_3, h_Top_nTrk_bjet_difeta_lowDilepPt_2, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_lowDilepPt_3 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_lowDilepPt_3->Clone("Top_nTrk_lfakeRate_lowDilepPt_2");
    Top_nTrk_lfakeRate_lowDilepPt_3->Divide(h_Top_nTrk_ljet_cut_difeta_lowDilepPt_3, h_Top_nTrk_ljet_difeta_lowDilepPt_2, 1, 1, "b");
 

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

    //---------------------
    TH1D *Top_nTrk_bfakeRate_difeta_lowDilepPt_1 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_lowDilepPt_1->Clone("Top_nTrk_bfakeRate_difeta_lowDilepPt_1");
    Top_nTrk_bfakeRate_difeta_lowDilepPt_1->Divide(h_Top_nTrk_bjet_cut_difeta_lowDilepPt_1, h_Top_nTrk_bjet_difeta_lowDilepPt_1, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_lowDilepPt_1 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_lowDilepPt_1->Clone("Top_nTrk_lfakeRate_difeta_lowDilepPt_1");
    Top_nTrk_lfakeRate_difeta_lowDilepPt_1->Divide(h_Top_nTrk_ljet_cut_difeta_lowDilepPt_1, h_Top_nTrk_ljet_difeta_lowDilepPt_1, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_lowDilepPt_2 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_lowDilepPt_2->Clone("Top_nTrk_bfakeRate_difeta_lowDilepPt_2");
    Top_nTrk_bfakeRate_difeta_lowDilepPt_2->Divide(h_Top_nTrk_bjet_cut_difeta_lowDilepPt_2, h_Top_nTrk_bjet_difeta_lowDilepPt_2, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_lowDilepPt_2 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_lowDilepPt_2->Clone("Top_nTrk_lfakeRate_difeta_lowDilepPt_2");
    Top_nTrk_lfakeRate_difeta_lowDilepPt_2->Divide(h_Top_nTrk_ljet_cut_difeta_lowDilepPt_2, h_Top_nTrk_ljet_difeta_lowDilepPt_2, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_lowDilepPt_3 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_lowDilepPt_3->Clone("Top_nTrk_bfakeRate_difeta_lowDilepPt_3");
    Top_nTrk_bfakeRate_difeta_lowDilepPt_3->Divide(h_Top_nTrk_bjet_cut_difeta_lowDilepPt_3, h_Top_nTrk_bjet_difeta_lowDilepPt_3, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_lowDilepPt_3 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_lowDilepPt_3->Clone("Top_nTrk_lfakeRate_difeta_lowDilepPt_3");
    Top_nTrk_lfakeRate_difeta_lowDilepPt_3->Divide(h_Top_nTrk_ljet_cut_difeta_lowDilepPt_3, h_Top_nTrk_ljet_difeta_lowDilepPt_3, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_highDilepPt_1 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_highDilepPt_1->Clone("Top_nTrk_bfakeRate_difeta_highDilepPt_1");
    Top_nTrk_bfakeRate_difeta_highDilepPt_1->Divide(h_Top_nTrk_bjet_cut_difeta_highDilepPt_1, h_Top_nTrk_bjet_difeta_highDilepPt_1, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_highDilepPt_1 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_highDilepPt_1->Clone("Top_nTrk_lfakeRate_difeta_highDilepPt_1");
    Top_nTrk_lfakeRate_difeta_highDilepPt_1->Divide(h_Top_nTrk_ljet_cut_difeta_highDilepPt_1, h_Top_nTrk_ljet_difeta_highDilepPt_1, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_highDilepPt_2 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_highDilepPt_2->Clone("Top_nTrk_bfakeRate_difeta_highDilepPt_2");
    Top_nTrk_bfakeRate_difeta_highDilepPt_2->Divide(h_Top_nTrk_bjet_cut_difeta_highDilepPt_2, h_Top_nTrk_bjet_difeta_highDilepPt_2, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_highDilepPt_2 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_highDilepPt_2->Clone("Top_nTrk_lfakeRate_difeta_highDilepPt_2");
    Top_nTrk_lfakeRate_difeta_highDilepPt_2->Divide(h_Top_nTrk_ljet_cut_difeta_highDilepPt_2, h_Top_nTrk_ljet_difeta_highDilepPt_2, 1, 1, "b");

    TH1D *Top_nTrk_bfakeRate_difeta_highDilepPt_3 = (TH1D *)h_Top_nTrk_bjet_cut_difeta_highDilepPt_3->Clone("Top_nTrk_bfakeRate_difeta_highDilepPt_3");
    Top_nTrk_bfakeRate_difeta_highDilepPt_3->Divide(h_Top_nTrk_bjet_cut_difeta_highDilepPt_3, h_Top_nTrk_bjet_difeta_highDilepPt_3, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate_difeta_highDilepPt_3 = (TH1D *)h_Top_nTrk_ljet_cut_difeta_highDilepPt_3->Clone("Top_nTrk_lfakeRate_difeta_highDilepPt_3");
    Top_nTrk_lfakeRate_difeta_highDilepPt_3->Divide(h_Top_nTrk_ljet_cut_difeta_highDilepPt_3, h_Top_nTrk_ljet_difeta_highDilepPt_3, 1, 1, "b");

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();

    Top_nTrk_bfakeRate_lowMET->Write();
    Top_nTrk_lfakeRate_lowMET->Write();

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

    Top_nTrk_bfakeRate_difeta_lowDilepPt_1->Write();
    Top_nTrk_lfakeRate_difeta_lowDilepPt_1->Write();

    Top_nTrk_bfakeRate_difeta_lowDilepPt_2->Write();
    Top_nTrk_lfakeRate_difeta_lowDilepPt_2->Write();

    Top_nTrk_bfakeRate_difeta_lowDilepPt_3->Write();
    Top_nTrk_lfakeRate_difeta_lowDilepPt_3->Write();

    Top_nTrk_bfakeRate_difeta_highDilepPt_1->Write();
    Top_nTrk_lfakeRate_difeta_highDilepPt_1->Write();

    Top_nTrk_bfakeRate_difeta_highDilepPt_2->Write();
    Top_nTrk_lfakeRate_difeta_highDilepPt_2->Write();

    Top_nTrk_bfakeRate_difeta_highDilepPt_3->Write();
    Top_nTrk_lfakeRate_difeta_highDilepPt_3->Write();

    Top_nTrk_fakeRate_lowDilepPt->Write();
    Top_nTrk_bfakeRate_lowDilepPt->Write();
    Top_nTrk_lfakeRate_lowDilepPt->Write();

    Top_nTrk_fakeRate_highDilepPt->Write();
    Top_nTrk_bfakeRate_highDilepPt->Write();
    Top_nTrk_lfakeRate_highDilepPt->Write();

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