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
#include <TH2.h>
#include "TLegend.h"
#include <cstring>
void Draw_diff_top_nTrk(TString file = "./top_all.root")
{
    TFile *Topfile = TFile::Open(file);

    TFile *Top_eu_file = TFile::Open(" ./../../../top_emu/top_all.root");

    TH1D *ee_Top_nTrk_bjet_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_lowMET_1"));
    TH1D *ee_Top_nTrk_cjet_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_lowMET_1"));
    TH1D *ee_Top_nTrk_ljet_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_lowMET_1"));

    TH1D *ee_Top_nTrk_bjet_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_lowMET_2"));
    TH1D *ee_Top_nTrk_cjet_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_lowMET_2"));
    TH1D *ee_Top_nTrk_ljet_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_lowMET_2"));

    TH1D *ee_Top_nTrk_bjet_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_lowMET_3"));
    TH1D *ee_Top_nTrk_cjet_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_lowMET_3"));
    TH1D *ee_Top_nTrk_ljet_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_lowMET_3"));

    TH1D *ee_Top_nTrk_bjet_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_midMET_1"));
    TH1D *ee_Top_nTrk_cjet_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_midMET_1"));
    TH1D *ee_Top_nTrk_ljet_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_midMET_1"));

    TH1D *ee_Top_nTrk_bjet_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_midMET_2"));
    TH1D *ee_Top_nTrk_cjet_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_midMET_2"));
    TH1D *ee_Top_nTrk_ljet_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_midMET_2"));

    TH1D *ee_Top_nTrk_bjet_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_midMET_3"));
    TH1D *ee_Top_nTrk_cjet_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_midMET_3"));
    TH1D *ee_Top_nTrk_ljet_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_midMET_3"));

    TH1D *ee_Top_nTrk_bjet_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_highMET_1"));
    TH1D *ee_Top_nTrk_cjet_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_highMET_1"));
    TH1D *ee_Top_nTrk_ljet_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_highMET_1"));

    TH1D *ee_Top_nTrk_bjet_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_highMET_2"));
    TH1D *ee_Top_nTrk_cjet_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_highMET_2"));
    TH1D *ee_Top_nTrk_ljet_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_highMET_2"));

    TH1D *ee_Top_nTrk_bjet_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_difeta_highMET_3"));
    TH1D *ee_Top_nTrk_cjet_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_difeta_highMET_3"));
    TH1D *ee_Top_nTrk_ljet_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_difeta_highMET_3"));

    TH1D *eu_Top_nTrk_bjet_difeta_lowMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_difeta_lowMET_1"));
    TH1D *eu_Top_nTrk_cjet_difeta_lowMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_difeta_lowMET_1"));
    TH1D *eu_Top_nTrk_ljet_difeta_lowMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_difeta_lowMET_1"));

    TH1D *eu_Top_nTrk_bjet_difeta_lowMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_difeta_lowMET_2"));
    TH1D *eu_Top_nTrk_cjet_difeta_lowMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_difeta_lowMET_2"));
    TH1D *eu_Top_nTrk_ljet_difeta_lowMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_difeta_lowMET_2"));

    TH1D *eu_Top_nTrk_bjet_difeta_lowMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_difeta_lowMET_3"));
    TH1D *eu_Top_nTrk_cjet_difeta_lowMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_difeta_lowMET_3"));
    TH1D *eu_Top_nTrk_ljet_difeta_lowMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_difeta_lowMET_3"));

    TH1D *eu_Top_nTrk_bjet_difeta_midMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_difeta_midMET_1"));
    TH1D *eu_Top_nTrk_cjet_difeta_midMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_difeta_midMET_1"));
    TH1D *eu_Top_nTrk_ljet_difeta_midMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_difeta_midMET_1"));

    TH1D *eu_Top_nTrk_bjet_difeta_midMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_difeta_midMET_2"));
    TH1D *eu_Top_nTrk_cjet_difeta_midMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_difeta_midMET_2"));
    TH1D *eu_Top_nTrk_ljet_difeta_midMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_difeta_midMET_2"));

    TH1D *eu_Top_nTrk_bjet_difeta_midMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_difeta_midMET_3"));
    TH1D *eu_Top_nTrk_cjet_difeta_midMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_difeta_midMET_3"));
    TH1D *eu_Top_nTrk_ljet_difeta_midMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_difeta_midMET_3"));

    TH1D *eu_Top_nTrk_bjet_difeta_highMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_difeta_highMET_1"));
    TH1D *eu_Top_nTrk_cjet_difeta_highMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_difeta_highMET_1"));
    TH1D *eu_Top_nTrk_ljet_difeta_highMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_difeta_highMET_1"));

    TH1D *eu_Top_nTrk_bjet_difeta_highMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_difeta_highMET_2"));
    TH1D *eu_Top_nTrk_cjet_difeta_highMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_difeta_highMET_2"));
    TH1D *eu_Top_nTrk_ljet_difeta_highMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_difeta_highMET_2"));

    TH1D *eu_Top_nTrk_bjet_difeta_highMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_difeta_highMET_3"));
    TH1D *eu_Top_nTrk_cjet_difeta_highMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_difeta_highMET_3"));
    TH1D *eu_Top_nTrk_ljet_difeta_highMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_difeta_highMET_3"));

    TH1D *ee_Top_nTrk_bjet_cut_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_lowMET_1"));
    TH1D *ee_Top_nTrk_cjet_cut_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_lowMET_1"));
    TH1D *ee_Top_nTrk_ljet_cut_difeta_lowMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_lowMET_1"));

    TH1D *ee_Top_nTrk_bjet_cut_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_lowMET_2"));
    TH1D *ee_Top_nTrk_cjet_cut_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_lowMET_2"));
    TH1D *ee_Top_nTrk_ljet_cut_difeta_lowMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_lowMET_2"));

    TH1D *ee_Top_nTrk_bjet_cut_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_lowMET_3"));
    TH1D *ee_Top_nTrk_cjet_cut_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_lowMET_3"));
    TH1D *ee_Top_nTrk_ljet_cut_difeta_lowMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_lowMET_3"));

    TH1D *ee_Top_nTrk_bjet_cut_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_midMET_1"));
    TH1D *ee_Top_nTrk_cjet_cut_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_midMET_1"));
    TH1D *ee_Top_nTrk_ljet_cut_difeta_midMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_midMET_1"));

    TH1D *ee_Top_nTrk_bjet_cut_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_midMET_2"));
    TH1D *ee_Top_nTrk_cjet_cut_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_midMET_2"));
    TH1D *ee_Top_nTrk_ljet_cut_difeta_midMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_midMET_2"));

    TH1D *ee_Top_nTrk_bjet_cut_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_midMET_3"));
    TH1D *ee_Top_nTrk_cjet_cut_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_midMET_3"));
    TH1D *ee_Top_nTrk_ljet_cut_difeta_midMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_midMET_3"));

    TH1D *ee_Top_nTrk_bjet_cut_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_highMET_1"));
    TH1D *ee_Top_nTrk_cjet_cut_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_highMET_1"));
    TH1D *ee_Top_nTrk_ljet_cut_difeta_highMET_1 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_highMET_1"));

    TH1D *ee_Top_nTrk_bjet_cut_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_highMET_2"));
    TH1D *ee_Top_nTrk_cjet_cut_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_highMET_2"));
    TH1D *ee_Top_nTrk_ljet_cut_difeta_highMET_2 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_highMET_2"));

    TH1D *ee_Top_nTrk_bjet_cut_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut_difeta_highMET_3"));
    TH1D *ee_Top_nTrk_cjet_cut_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut_difeta_highMET_3"));
    TH1D *ee_Top_nTrk_ljet_cut_difeta_highMET_3 = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut_difeta_highMET_3"));

    TH1D *eu_Top_nTrk_bjet_cut_difeta_lowMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_cut_difeta_lowMET_1"));
    TH1D *eu_Top_nTrk_cjet_cut_difeta_lowMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_cut_difeta_lowMET_1"));
    TH1D *eu_Top_nTrk_ljet_cut_difeta_lowMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_cut_difeta_lowMET_1"));

    TH1D *eu_Top_nTrk_bjet_cut_difeta_lowMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_cut_difeta_lowMET_2"));
    TH1D *eu_Top_nTrk_cjet_cut_difeta_lowMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_cut_difeta_lowMET_2"));
    TH1D *eu_Top_nTrk_ljet_cut_difeta_lowMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_cut_difeta_lowMET_2"));

    TH1D *eu_Top_nTrk_bjet_cut_difeta_lowMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_cut_difeta_lowMET_3"));
    TH1D *eu_Top_nTrk_cjet_cut_difeta_lowMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_cut_difeta_lowMET_3"));
    TH1D *eu_Top_nTrk_ljet_cut_difeta_lowMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_cut_difeta_lowMET_3"));

    TH1D *eu_Top_nTrk_bjet_cut_difeta_midMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_cut_difeta_midMET_1"));
    TH1D *eu_Top_nTrk_cjet_cut_difeta_midMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_cut_difeta_midMET_1"));
    TH1D *eu_Top_nTrk_ljet_cut_difeta_midMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_cut_difeta_midMET_1"));

    TH1D *eu_Top_nTrk_bjet_cut_difeta_midMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_cut_difeta_midMET_2"));
    TH1D *eu_Top_nTrk_cjet_cut_difeta_midMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_cut_difeta_midMET_2"));
    TH1D *eu_Top_nTrk_ljet_cut_difeta_midMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_cut_difeta_midMET_2"));

    TH1D *eu_Top_nTrk_bjet_cut_difeta_midMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_cut_difeta_midMET_3"));
    TH1D *eu_Top_nTrk_cjet_cut_difeta_midMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_cut_difeta_midMET_3"));
    TH1D *eu_Top_nTrk_ljet_cut_difeta_midMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_cut_difeta_midMET_3"));

    TH1D *eu_Top_nTrk_bjet_cut_difeta_highMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_cut_difeta_highMET_1"));
    TH1D *eu_Top_nTrk_cjet_cut_difeta_highMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_cut_difeta_highMET_1"));
    TH1D *eu_Top_nTrk_ljet_cut_difeta_highMET_1 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_cut_difeta_highMET_1"));

    TH1D *eu_Top_nTrk_bjet_cut_difeta_highMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_cut_difeta_highMET_2"));
    TH1D *eu_Top_nTrk_cjet_cut_difeta_highMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_cut_difeta_highMET_2"));
    TH1D *eu_Top_nTrk_ljet_cut_difeta_highMET_2 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_cut_difeta_highMET_2"));

    TH1D *eu_Top_nTrk_bjet_cut_difeta_highMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_bjet_cut_difeta_highMET_3"));
    TH1D *eu_Top_nTrk_cjet_cut_difeta_highMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_cjet_cut_difeta_highMET_3"));
    TH1D *eu_Top_nTrk_ljet_cut_difeta_highMET_3 = ((TH1D *)Top_eu_file->Get("h_Top_nTrk_ljet_cut_difeta_highMET_3"));

    ee_Top_nTrk_bjet_difeta_lowMET_1->SetLineWidth(2);
    ee_Top_nTrk_cjet_difeta_lowMET_1->SetLineWidth(2);
    ee_Top_nTrk_ljet_difeta_lowMET_1->SetLineWidth(2);

    ee_Top_nTrk_bjet_difeta_lowMET_2->SetLineWidth(2);
    ee_Top_nTrk_cjet_difeta_lowMET_2->SetLineWidth(2);
    ee_Top_nTrk_ljet_difeta_lowMET_2->SetLineWidth(2);

    ee_Top_nTrk_bjet_difeta_lowMET_3->SetLineWidth(2);
    ee_Top_nTrk_cjet_difeta_lowMET_3->SetLineWidth(2);
    ee_Top_nTrk_ljet_difeta_lowMET_3->SetLineWidth(2);

    ee_Top_nTrk_bjet_difeta_midMET_1->SetLineWidth(2);
    ee_Top_nTrk_cjet_difeta_midMET_1->SetLineWidth(2);
    ee_Top_nTrk_ljet_difeta_midMET_1->SetLineWidth(2);

    ee_Top_nTrk_bjet_difeta_midMET_2->SetLineWidth(2);
    ee_Top_nTrk_cjet_difeta_midMET_2->SetLineWidth(2);
    ee_Top_nTrk_ljet_difeta_midMET_2->SetLineWidth(2);

    ee_Top_nTrk_bjet_difeta_midMET_3->SetLineWidth(2);
    ee_Top_nTrk_cjet_difeta_midMET_3->SetLineWidth(2);
    ee_Top_nTrk_ljet_difeta_midMET_3->SetLineWidth(2);

    ee_Top_nTrk_bjet_difeta_highMET_1->SetLineWidth(2);
    ee_Top_nTrk_cjet_difeta_highMET_1->SetLineWidth(2);
    ee_Top_nTrk_ljet_difeta_highMET_1->SetLineWidth(2);

    ee_Top_nTrk_bjet_difeta_highMET_2->SetLineWidth(2);
    ee_Top_nTrk_cjet_difeta_highMET_2->SetLineWidth(2);
    ee_Top_nTrk_ljet_difeta_highMET_2->SetLineWidth(2);

    ee_Top_nTrk_bjet_difeta_highMET_3->SetLineWidth(2);
    ee_Top_nTrk_cjet_difeta_highMET_3->SetLineWidth(2);
    ee_Top_nTrk_ljet_difeta_highMET_3->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_lowMET_1->SetLineWidth(2);
    eu_Top_nTrk_cjet_difeta_lowMET_1->SetLineWidth(2);
    eu_Top_nTrk_ljet_difeta_lowMET_1->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_lowMET_2->SetLineWidth(2);
    eu_Top_nTrk_cjet_difeta_lowMET_2->SetLineWidth(2);
    eu_Top_nTrk_ljet_difeta_lowMET_2->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_lowMET_3->SetLineWidth(2);
    eu_Top_nTrk_cjet_difeta_lowMET_3->SetLineWidth(2);
    eu_Top_nTrk_ljet_difeta_lowMET_3->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_midMET_1->SetLineWidth(2);
    eu_Top_nTrk_cjet_difeta_midMET_1->SetLineWidth(2);
    eu_Top_nTrk_ljet_difeta_midMET_1->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_midMET_2->SetLineWidth(2);
    eu_Top_nTrk_cjet_difeta_midMET_2->SetLineWidth(2);
    eu_Top_nTrk_ljet_difeta_midMET_2->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_midMET_3->SetLineWidth(2);
    eu_Top_nTrk_cjet_difeta_midMET_3->SetLineWidth(2);
    eu_Top_nTrk_ljet_difeta_midMET_3->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_highMET_1->SetLineWidth(2);
    eu_Top_nTrk_cjet_difeta_highMET_1->SetLineWidth(2);
    eu_Top_nTrk_ljet_difeta_highMET_1->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_highMET_2->SetLineWidth(2);
    eu_Top_nTrk_cjet_difeta_highMET_2->SetLineWidth(2);
    eu_Top_nTrk_ljet_difeta_highMET_2->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_highMET_3->SetLineWidth(2);
    eu_Top_nTrk_cjet_difeta_highMET_3->SetLineWidth(2);
    eu_Top_nTrk_ljet_difeta_highMET_3->SetLineWidth(2);

    ee_Top_nTrk_bjet_cut_difeta_lowMET_1->SetLineWidth(2);
    ee_Top_nTrk_cjet_cut_difeta_lowMET_1->SetLineWidth(2);
    ee_Top_nTrk_ljet_cut_difeta_lowMET_1->SetLineWidth(2);

    ee_Top_nTrk_bjet_cut_difeta_lowMET_2->SetLineWidth(2);
    ee_Top_nTrk_cjet_cut_difeta_lowMET_2->SetLineWidth(2);
    ee_Top_nTrk_ljet_cut_difeta_lowMET_2->SetLineWidth(2);

    ee_Top_nTrk_bjet_cut_difeta_lowMET_3->SetLineWidth(2);
    ee_Top_nTrk_cjet_cut_difeta_lowMET_3->SetLineWidth(2);
    ee_Top_nTrk_ljet_cut_difeta_lowMET_3->SetLineWidth(2);

    ee_Top_nTrk_bjet_cut_difeta_midMET_1->SetLineWidth(2);
    ee_Top_nTrk_cjet_cut_difeta_midMET_1->SetLineWidth(2);
    ee_Top_nTrk_ljet_cut_difeta_midMET_1->SetLineWidth(2);

    ee_Top_nTrk_bjet_cut_difeta_midMET_2->SetLineWidth(2);
    ee_Top_nTrk_cjet_cut_difeta_midMET_2->SetLineWidth(2);
    ee_Top_nTrk_ljet_cut_difeta_midMET_2->SetLineWidth(2);

    ee_Top_nTrk_bjet_cut_difeta_midMET_3->SetLineWidth(2);
    ee_Top_nTrk_cjet_cut_difeta_midMET_3->SetLineWidth(2);
    ee_Top_nTrk_ljet_cut_difeta_midMET_3->SetLineWidth(2);

    ee_Top_nTrk_bjet_cut_difeta_highMET_1->SetLineWidth(2);
    ee_Top_nTrk_cjet_cut_difeta_highMET_1->SetLineWidth(2);
    ee_Top_nTrk_ljet_cut_difeta_highMET_1->SetLineWidth(2);

    ee_Top_nTrk_bjet_cut_difeta_highMET_2->SetLineWidth(2);
    ee_Top_nTrk_cjet_cut_difeta_highMET_2->SetLineWidth(2);
    ee_Top_nTrk_ljet_cut_difeta_highMET_2->SetLineWidth(2);

    ee_Top_nTrk_bjet_cut_difeta_highMET_3->SetLineWidth(2);
    ee_Top_nTrk_cjet_cut_difeta_highMET_3->SetLineWidth(2);
    ee_Top_nTrk_ljet_cut_difeta_highMET_3->SetLineWidth(2);

    eu_Top_nTrk_bjet_cut_difeta_lowMET_1->SetLineWidth(2);
    eu_Top_nTrk_cjet_cut_difeta_lowMET_1->SetLineWidth(2);
    eu_Top_nTrk_ljet_cut_difeta_lowMET_1->SetLineWidth(2);

    eu_Top_nTrk_bjet_cut_difeta_lowMET_2->SetLineWidth(2);
    eu_Top_nTrk_cjet_cut_difeta_lowMET_2->SetLineWidth(2);
    eu_Top_nTrk_ljet_cut_difeta_lowMET_2->SetLineWidth(2);

    eu_Top_nTrk_bjet_cut_difeta_lowMET_3->SetLineWidth(2);
    eu_Top_nTrk_cjet_cut_difeta_lowMET_3->SetLineWidth(2);
    eu_Top_nTrk_ljet_cut_difeta_lowMET_3->SetLineWidth(2);

    eu_Top_nTrk_bjet_cut_difeta_midMET_1->SetLineWidth(2);
    eu_Top_nTrk_cjet_cut_difeta_midMET_1->SetLineWidth(2);
    eu_Top_nTrk_ljet_cut_difeta_midMET_1->SetLineWidth(2);

    eu_Top_nTrk_bjet_cut_difeta_midMET_2->SetLineWidth(2);
    eu_Top_nTrk_cjet_cut_difeta_midMET_2->SetLineWidth(2);
    eu_Top_nTrk_ljet_cut_difeta_midMET_2->SetLineWidth(2);

    eu_Top_nTrk_bjet_cut_difeta_midMET_3->SetLineWidth(2);
    eu_Top_nTrk_cjet_cut_difeta_midMET_3->SetLineWidth(2);
    eu_Top_nTrk_ljet_cut_difeta_midMET_3->SetLineWidth(2);

    eu_Top_nTrk_bjet_cut_difeta_highMET_1->SetLineWidth(2);
    eu_Top_nTrk_cjet_cut_difeta_highMET_1->SetLineWidth(2);
    eu_Top_nTrk_ljet_cut_difeta_highMET_1->SetLineWidth(2);

    eu_Top_nTrk_bjet_cut_difeta_highMET_2->SetLineWidth(2);
    eu_Top_nTrk_cjet_cut_difeta_highMET_2->SetLineWidth(2);
    eu_Top_nTrk_ljet_cut_difeta_highMET_2->SetLineWidth(2);

    eu_Top_nTrk_bjet_cut_difeta_highMET_3->SetLineWidth(2);
    eu_Top_nTrk_cjet_cut_difeta_highMET_3->SetLineWidth(2);
    eu_Top_nTrk_ljet_cut_difeta_highMET_3->SetLineWidth(2);

    eu_Top_nTrk_bjet_difeta_lowMET_1->SetLineColor(kRed);
    eu_Top_nTrk_cjet_difeta_lowMET_1->SetLineColor(kRed);
    eu_Top_nTrk_ljet_difeta_lowMET_1->SetLineColor(kRed);

    eu_Top_nTrk_bjet_difeta_lowMET_2->SetLineColor(kRed);
    eu_Top_nTrk_cjet_difeta_lowMET_2->SetLineColor(kRed);
    eu_Top_nTrk_ljet_difeta_lowMET_2->SetLineColor(kRed);

    eu_Top_nTrk_bjet_difeta_lowMET_3->SetLineColor(kRed);
    eu_Top_nTrk_cjet_difeta_lowMET_3->SetLineColor(kRed);
    eu_Top_nTrk_ljet_difeta_lowMET_3->SetLineColor(kRed);

    eu_Top_nTrk_bjet_difeta_midMET_1->SetLineColor(kGreen + 3);
    eu_Top_nTrk_cjet_difeta_midMET_1->SetLineColor(kGreen + 3);
    eu_Top_nTrk_ljet_difeta_midMET_1->SetLineColor(kGreen + 3);

    eu_Top_nTrk_bjet_difeta_midMET_2->SetLineColor(kGreen + 3);
    eu_Top_nTrk_cjet_difeta_midMET_2->SetLineColor(kGreen + 3);
    eu_Top_nTrk_ljet_difeta_midMET_2->SetLineColor(kGreen + 3);

    eu_Top_nTrk_bjet_difeta_midMET_3->SetLineColor(kGreen + 3);
    eu_Top_nTrk_cjet_difeta_midMET_3->SetLineColor(kGreen + 3);
    eu_Top_nTrk_ljet_difeta_midMET_3->SetLineColor(kGreen + 3);

    eu_Top_nTrk_bjet_difeta_highMET_1->SetLineColor(kRed);
    eu_Top_nTrk_cjet_difeta_highMET_1->SetLineColor(kRed);
    eu_Top_nTrk_ljet_difeta_highMET_1->SetLineColor(kRed);

    eu_Top_nTrk_bjet_difeta_highMET_2->SetLineColor(kRed);
    eu_Top_nTrk_cjet_difeta_highMET_2->SetLineColor(kRed);
    eu_Top_nTrk_ljet_difeta_highMET_2->SetLineColor(kRed);

    eu_Top_nTrk_bjet_difeta_highMET_3->SetLineColor(kRed);
    eu_Top_nTrk_cjet_difeta_highMET_3->SetLineColor(kRed);
    eu_Top_nTrk_ljet_difeta_highMET_3->SetLineColor(kRed);

    eu_Top_nTrk_bjet_cut_difeta_lowMET_1->SetLineColor(kRed);
    eu_Top_nTrk_cjet_cut_difeta_lowMET_1->SetLineColor(kRed);
    eu_Top_nTrk_ljet_cut_difeta_lowMET_1->SetLineColor(kRed);

    eu_Top_nTrk_bjet_cut_difeta_lowMET_2->SetLineColor(kRed);
    eu_Top_nTrk_cjet_cut_difeta_lowMET_2->SetLineColor(kRed);
    eu_Top_nTrk_ljet_cut_difeta_lowMET_2->SetLineColor(kRed);

    eu_Top_nTrk_bjet_cut_difeta_lowMET_3->SetLineColor(kRed);
    eu_Top_nTrk_cjet_cut_difeta_lowMET_3->SetLineColor(kRed);
    eu_Top_nTrk_ljet_cut_difeta_lowMET_3->SetLineColor(kRed);

    eu_Top_nTrk_bjet_cut_difeta_midMET_1->SetLineColor(kGreen + 3);
    eu_Top_nTrk_cjet_cut_difeta_midMET_1->SetLineColor(kGreen + 3);
    eu_Top_nTrk_ljet_cut_difeta_midMET_1->SetLineColor(kGreen + 3);

    eu_Top_nTrk_bjet_cut_difeta_midMET_2->SetLineColor(kGreen + 3);
    eu_Top_nTrk_cjet_cut_difeta_midMET_2->SetLineColor(kGreen + 3);
    eu_Top_nTrk_ljet_cut_difeta_midMET_2->SetLineColor(kGreen + 3);

    eu_Top_nTrk_bjet_cut_difeta_midMET_3->SetLineColor(kGreen + 3);
    eu_Top_nTrk_cjet_cut_difeta_midMET_3->SetLineColor(kGreen + 3);
    eu_Top_nTrk_ljet_cut_difeta_midMET_3->SetLineColor(kGreen + 3);

    eu_Top_nTrk_bjet_cut_difeta_highMET_1->SetLineColor(kRed);
    eu_Top_nTrk_cjet_cut_difeta_highMET_1->SetLineColor(kRed);
    eu_Top_nTrk_ljet_cut_difeta_highMET_1->SetLineColor(kRed);

    eu_Top_nTrk_bjet_cut_difeta_highMET_2->SetLineColor(kRed);
    eu_Top_nTrk_cjet_cut_difeta_highMET_2->SetLineColor(kRed);
    eu_Top_nTrk_ljet_cut_difeta_highMET_2->SetLineColor(kRed);

    eu_Top_nTrk_bjet_cut_difeta_highMET_3->SetLineColor(kRed);
    eu_Top_nTrk_cjet_cut_difeta_highMET_3->SetLineColor(kRed);
    eu_Top_nTrk_ljet_cut_difeta_highMET_3->SetLineColor(kRed);

    int W = 800;
    int H = 600;

    int H_ref = 600;
    int W_ref = 800;

    float T = 0.08 * H_ref;
    float B = 0.12 * H_ref;
    float L = 0.12 * W_ref;
    float R = 0.04 * W_ref;

    auto c1 = new TCanvas("c1", "c1", 50, 50, W, H);
    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    c1->SetLeftMargin(L / W);
    c1->SetRightMargin(R / W);
    c1->SetTopMargin(T / H);
    c1->SetBottomMargin(B / H);
    c1->SetTickx(0);
    c1->SetTicky(0);

    c1->Divide(3, 1);

    c1->cd(1);

    eu_Top_nTrk_ljet_cut_difeta_lowMET_1->Draw();
    ee_Top_nTrk_ljet_cut_difeta_lowMET_1->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("low MET ,light flavor ,|#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(eu_Top_nTrk_ljet_cut_difeta_lowMET_1, "Top ee", "El");
    l0->AddEntry(ee_Top_nTrk_ljet_cut_difeta_lowMET_1, "Top emu", "El");
    l0->Draw();

    c1->cd(2);

    //eu_Top_nTrk_ljet_cut_difeta_midMET_1->Draw();
    //ee_Top_nTrk_ljet_cut_difeta_midMET_1->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("mid MET ,light flavor , |#eta| < 1");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(eu_Top_nTrk_ljet_cut_difeta_midMET_1, "Top ee", "El");
    l1->AddEntry(ee_Top_nTrk_ljet_cut_difeta_midMET_1, "Top emu", "El");
    l1->Draw();

    c1->cd(3);

    eu_Top_nTrk_ljet_cut_difeta_highMET_1->Draw();
    ee_Top_nTrk_ljet_cut_difeta_highMET_1->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("High MET ,light flavor , |#eta| < 1");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(eu_Top_nTrk_ljet_cut_difeta_highMET_1, "Top ee", "El");
    l2->AddEntry(ee_Top_nTrk_ljet_cut_difeta_highMET_1, "Top emu", "El");
    l2->Draw();

    /*
    c1->cd(1);

    eu_Top_nTrk_ljet_cut_difeta_highMET_1->Draw();
    ee_Top_nTrk_ljet_cut_difeta_highMET_1->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("High MET, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(ee_Top_nTrk_bjet_difeta_highMET_1, "Top ee", "El");
    l0->AddEntry(eu_Top_nTrk_bjet_difeta_highMET_1, "Top emu", "El");
    l0->Draw();

    c1->cd(2);

    eu_Top_nTrk_ljet_cut_difeta_highMET_2->Draw();
    ee_Top_nTrk_ljet_cut_difeta_highMET_2->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("High MET, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(ee_Top_nTrk_bjet_difeta_highMET_2, "Top ee", "El");
    l1->AddEntry(eu_Top_nTrk_bjet_difeta_highMET_2, "Top emu", "El");
    l1->Draw();

    c1->cd(3);

    eu_Top_nTrk_ljet_cut_difeta_highMET_3->Draw();
    ee_Top_nTrk_ljet_cut_difeta_highMET_3->Draw("same");

    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("High MET, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(ee_Top_nTrk_bjet_difeta_highMET_3, "Top ee", "El");
    l2->AddEntry(eu_Top_nTrk_bjet_difeta_highMET_3, "Top emu", "El");
    l2->Draw();

    */

    gStyle->SetOptStat(0);
}