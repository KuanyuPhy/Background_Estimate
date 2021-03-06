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
#include <TH2.h>
#include <TAxis.h>
#include <TLine.h>
#include <TError.h>
#include "TLegend.h"
#include <cstring>

void draw_all_fake_rate()
{
    TFile *DYfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/dy/DY_fakerate.root");
    TFile *Topfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top/diffeta/new_macro/top_fakerate.root");
    TFile *Top_emufile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu/top_emu_fakerate.root");
    TFile *Dibfile = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/diboson/dib_fakerate.root");

    // For DYfile
    TH1D *DY_nTrk_fakeRate_difeta_1 = ((TH1D *)DYfile->Get("DY_nTrk_fakeRate_difeta_1"));
    TH1D *DY_nTrk_bfakeRate_difeta_1 = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate_difeta_1"));
    TH1D *DY_nTrk_cfakeRate_difeta_1 = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate_difeta_1"));
    TH1D *DY_nTrk_lfakeRate_difeta_1 = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate_difeta_1"));
    TH1D *DY_nTrk_hfakeRate_difeta_1 = ((TH1D *)DYfile->Get("DY_nTrk_hfakeRate_difeta_1"));

    TH1D *DY_nTrk_fakeRate_difeta_2 = ((TH1D *)DYfile->Get("DY_nTrk_fakeRate_difeta_2"));
    TH1D *DY_nTrk_bfakeRate_difeta_2 = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate_difeta_2"));
    TH1D *DY_nTrk_cfakeRate_difeta_2 = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate_difeta_2"));
    TH1D *DY_nTrk_lfakeRate_difeta_2 = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate_difeta_2"));
    TH1D *DY_nTrk_hfakeRate_difeta_2 = ((TH1D *)DYfile->Get("DY_nTrk_hfakeRate_difeta_2"));

    TH1D *DY_nTrk_fakeRate_difeta_3 = ((TH1D *)DYfile->Get("DY_nTrk_fakeRate_difeta_3"));
    TH1D *DY_nTrk_bfakeRate_difeta_3 = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate_difeta_3"));
    TH1D *DY_nTrk_cfakeRate_difeta_3 = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate_difeta_3"));
    TH1D *DY_nTrk_lfakeRate_difeta_3 = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate_difeta_3"));
    TH1D *DY_nTrk_hfakeRate_difeta_3 = ((TH1D *)DYfile->Get("DY_nTrk_hfakeRate_difeta_3"));

    TH1D *DY_nTrk_bfakeRate = ((TH1D *)DYfile->Get("DY_nTrk_bfakeRate"));
    TH1D *DY_nTrk_cfakeRate = ((TH1D *)DYfile->Get("DY_nTrk_cfakeRate"));
    TH1D *DY_nTrk_lfakeRate = ((TH1D *)DYfile->Get("DY_nTrk_lfakeRate"));
    TH1D *DY_nTrk_hfakeRate = ((TH1D *)DYfile->Get("DY_nTrk_hfakeRate"));
    TH1D *DY_nTrk_fakeRate = ((TH1D *)DYfile->Get("DY_nTrk_fakeRate"));

    // For Topfile
    TH1D *Top_nTrk_fakeRate_difeta_1 = ((TH1D *)Topfile->Get("Top_nTrk_fakeRate_difeta_1"));
    TH1D *Top_nTrk_bfakeRate_difeta_1 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_1"));
    TH1D *Top_nTrk_cfakeRate_difeta_1 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_1"));
    TH1D *Top_nTrk_lfakeRate_difeta_1 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_1"));
    TH1D *Top_nTrk_hfakeRate_difeta_1 = ((TH1D *)Topfile->Get("Top_nTrk_hfakeRate_difeta_1"));

    TH1D *Top_nTrk_fakeRate_difeta_2 = ((TH1D *)Topfile->Get("Top_nTrk_fakeRate_difeta_2"));
    TH1D *Top_nTrk_bfakeRate_difeta_2 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_2"));
    TH1D *Top_nTrk_cfakeRate_difeta_2 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_2"));
    TH1D *Top_nTrk_lfakeRate_difeta_2 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_2"));
    TH1D *Top_nTrk_hfakeRate_difeta_2 = ((TH1D *)Topfile->Get("Top_nTrk_hfakeRate_difeta_2"));

    TH1D *Top_nTrk_fakeRate_difeta_3 = ((TH1D *)Topfile->Get("Top_nTrk_fakeRate_difeta_3"));
    TH1D *Top_nTrk_bfakeRate_difeta_3 = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate_difeta_3"));
    TH1D *Top_nTrk_cfakeRate_difeta_3 = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate_difeta_3"));
    TH1D *Top_nTrk_lfakeRate_difeta_3 = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate_difeta_3"));
    TH1D *Top_nTrk_hfakeRate_difeta_3 = ((TH1D *)Topfile->Get("Top_nTrk_hfakeRate_difeta_3"));

    TH1D *Top_nTrk_bfakeRate = ((TH1D *)Topfile->Get("Top_nTrk_bfakeRate"));
    TH1D *Top_nTrk_cfakeRate = ((TH1D *)Topfile->Get("Top_nTrk_cfakeRate"));
    TH1D *Top_nTrk_lfakeRate = ((TH1D *)Topfile->Get("Top_nTrk_lfakeRate"));
    TH1D *Top_nTrk_hfakeRate = ((TH1D *)Topfile->Get("Top_nTrk_hfakeRate"));
    TH1D *Top_nTrk_fakeRate = ((TH1D *)Topfile->Get("Top_nTrk_fakeRate"));

    // For Top emu file
    TH1D *Top_emu_nTrk_fakeRate_difeta_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_fakeRate_difeta_1"));
    TH1D *Top_emu_nTrk_bfakeRate_difeta_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_1"));
    TH1D *Top_emu_nTrk_cfakeRate_difeta_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate_difeta_1"));
    TH1D *Top_emu_nTrk_lfakeRate_difeta_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_1"));
    TH1D *Top_emu_nTrk_hfakeRate_difeta_1 = ((TH1D *)Top_emufile->Get("Top_nTrk_hfakeRate_difeta_1"));

    TH1D *Top_emu_nTrk_fakeRate_difeta_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_fakeRate_difeta_2"));
    TH1D *Top_emu_nTrk_bfakeRate_difeta_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_2"));
    TH1D *Top_emu_nTrk_cfakeRate_difeta_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate_difeta_2"));
    TH1D *Top_emu_nTrk_lfakeRate_difeta_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_2"));
    TH1D *Top_emu_nTrk_hfakeRate_difeta_2 = ((TH1D *)Top_emufile->Get("Top_nTrk_hfakeRate_difeta_2"));

    TH1D *Top_emu_nTrk_fakeRate_difeta_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_fakeRate_difeta_3"));
    TH1D *Top_emu_nTrk_bfakeRate_difeta_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate_difeta_3"));
    TH1D *Top_emu_nTrk_cfakeRate_difeta_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate_difeta_3"));
    TH1D *Top_emu_nTrk_lfakeRate_difeta_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate_difeta_3"));
    TH1D *Top_emu_nTrk_hfakeRate_difeta_3 = ((TH1D *)Top_emufile->Get("Top_nTrk_hfakeRate_difeta_3"));

    TH1D *Top_emu_nTrk_bfakeRate = ((TH1D *)Top_emufile->Get("Top_nTrk_bfakeRate"));
    TH1D *Top_emu_nTrk_cfakeRate = ((TH1D *)Top_emufile->Get("Top_nTrk_cfakeRate"));
    TH1D *Top_emu_nTrk_lfakeRate = ((TH1D *)Top_emufile->Get("Top_nTrk_lfakeRate"));
    TH1D *Top_emu_nTrk_hfakeRate = ((TH1D *)Top_emufile->Get("Top_nTrk_hfakeRate"));
    TH1D *Top_emu_nTrk_fakeRate = ((TH1D *)Top_emufile->Get("Top_nTrk_fakeRate"));

    // For diboson
    TH1D *dib_nTrk_fakeRate_difeta_1 = ((TH1D *)Dibfile->Get("dib_nTrk_fakeRate_difeta_1"));
    TH1D *dib_nTrk_bfakeRate_difeta_1 = ((TH1D *)Dibfile->Get("dib_nTrk_bfakeRate_difeta_1"));
    TH1D *dib_nTrk_cfakeRate_difeta_1 = ((TH1D *)Dibfile->Get("dib_nTrk_cfakeRate_difeta_1"));
    TH1D *dib_nTrk_lfakeRate_difeta_1 = ((TH1D *)Dibfile->Get("dib_nTrk_lfakeRate_difeta_1"));
    TH1D *dib_nTrk_hfakeRate_difeta_1 = ((TH1D *)Dibfile->Get("dib_nTrk_hfakeRate_difeta_1"));

    TH1D *dib_nTrk_fakeRate_difeta_2 = ((TH1D *)Dibfile->Get("dib_nTrk_fakeRate_difeta_2"));
    TH1D *dib_nTrk_bfakeRate_difeta_2 = ((TH1D *)Dibfile->Get("dib_nTrk_bfakeRate_difeta_2"));
    TH1D *dib_nTrk_cfakeRate_difeta_2 = ((TH1D *)Dibfile->Get("dib_nTrk_cfakeRate_difeta_2"));
    TH1D *dib_nTrk_lfakeRate_difeta_2 = ((TH1D *)Dibfile->Get("dib_nTrk_lfakeRate_difeta_2"));
    TH1D *dib_nTrk_hfakeRate_difeta_2 = ((TH1D *)Dibfile->Get("dib_nTrk_hfakeRate_difeta_2"));

    TH1D *dib_nTrk_fakeRate_difeta_3 = ((TH1D *)Dibfile->Get("dib_nTrk_fakeRate_difeta_3"));
    TH1D *dib_nTrk_bfakeRate_difeta_3 = ((TH1D *)Dibfile->Get("dib_nTrk_bfakeRate_difeta_3"));
    TH1D *dib_nTrk_cfakeRate_difeta_3 = ((TH1D *)Dibfile->Get("dib_nTrk_cfakeRate_difeta_3"));
    TH1D *dib_nTrk_lfakeRate_difeta_3 = ((TH1D *)Dibfile->Get("dib_nTrk_lfakeRate_difeta_3"));
    TH1D *dib_nTrk_hfakeRate_difeta_3 = ((TH1D *)Dibfile->Get("dib_nTrk_hfakeRate_difeta_3"));

    TH1D *dib_nTrk_bfakeRate = ((TH1D *)Dibfile->Get("dib_nTrk_bfakeRate"));
    TH1D *dib_nTrk_cfakeRate = ((TH1D *)Dibfile->Get("dib_nTrk_cfakeRate"));
    TH1D *dib_nTrk_lfakeRate = ((TH1D *)Dibfile->Get("dib_nTrk_lfakeRate"));
    TH1D *dib_nTrk_hfakeRate = ((TH1D *)Dibfile->Get("dib_nTrk_hfakeRate"));
    TH1D *dib_nTrk_fakeRate = ((TH1D *)Dibfile->Get("dib_nTrk_fakeRate"));

    DY_nTrk_fakeRate_difeta_1->SetLineWidth(2);
    DY_nTrk_bfakeRate_difeta_1->SetLineWidth(2);
    DY_nTrk_cfakeRate_difeta_1->SetLineWidth(2);
    DY_nTrk_lfakeRate_difeta_1->SetLineWidth(2);
    DY_nTrk_hfakeRate_difeta_1->SetLineWidth(2);
    DY_nTrk_fakeRate_difeta_2->SetLineWidth(2);
    DY_nTrk_bfakeRate_difeta_2->SetLineWidth(2);
    DY_nTrk_cfakeRate_difeta_2->SetLineWidth(2);
    DY_nTrk_lfakeRate_difeta_2->SetLineWidth(2);
    DY_nTrk_hfakeRate_difeta_2->SetLineWidth(2);
    DY_nTrk_fakeRate_difeta_3->SetLineWidth(2);
    DY_nTrk_bfakeRate_difeta_3->SetLineWidth(2);
    DY_nTrk_cfakeRate_difeta_3->SetLineWidth(2);
    DY_nTrk_lfakeRate_difeta_3->SetLineWidth(2);
    DY_nTrk_hfakeRate_difeta_3->SetLineWidth(2);
    DY_nTrk_bfakeRate->SetLineWidth(2);
    DY_nTrk_cfakeRate->SetLineWidth(2);
    DY_nTrk_lfakeRate->SetLineWidth(2);
    DY_nTrk_hfakeRate->SetLineWidth(2);
    DY_nTrk_fakeRate->SetLineWidth(2);
    Top_nTrk_fakeRate_difeta_1->SetLineWidth(2);
    Top_nTrk_bfakeRate_difeta_1->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_1->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_1->SetLineWidth(2);
    Top_nTrk_hfakeRate_difeta_1->SetLineWidth(2);
    Top_nTrk_fakeRate_difeta_2->SetLineWidth(2);
    Top_nTrk_bfakeRate_difeta_2->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_2->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_2->SetLineWidth(2);
    Top_nTrk_hfakeRate_difeta_2->SetLineWidth(2);
    Top_nTrk_fakeRate_difeta_3->SetLineWidth(2);
    Top_nTrk_bfakeRate_difeta_3->SetLineWidth(2);
    Top_nTrk_cfakeRate_difeta_3->SetLineWidth(2);
    Top_nTrk_lfakeRate_difeta_3->SetLineWidth(2);
    Top_nTrk_hfakeRate_difeta_3->SetLineWidth(2);
    Top_nTrk_bfakeRate->SetLineWidth(2);
    Top_nTrk_cfakeRate->SetLineWidth(2);
    Top_nTrk_lfakeRate->SetLineWidth(2);
    Top_nTrk_hfakeRate->SetLineWidth(2);
    Top_nTrk_fakeRate->SetLineWidth(2);

    Top_emu_nTrk_fakeRate_difeta_1->SetLineWidth(2);
    Top_emu_nTrk_bfakeRate_difeta_1->SetLineWidth(2);
    Top_emu_nTrk_cfakeRate_difeta_1->SetLineWidth(2);
    Top_emu_nTrk_lfakeRate_difeta_1->SetLineWidth(2);
    Top_emu_nTrk_hfakeRate_difeta_1->SetLineWidth(2);
    Top_emu_nTrk_fakeRate_difeta_2->SetLineWidth(2);
    Top_emu_nTrk_bfakeRate_difeta_2->SetLineWidth(2);
    Top_emu_nTrk_cfakeRate_difeta_2->SetLineWidth(2);
    Top_emu_nTrk_lfakeRate_difeta_2->SetLineWidth(2);
    Top_emu_nTrk_hfakeRate_difeta_2->SetLineWidth(2);
    Top_emu_nTrk_fakeRate_difeta_3->SetLineWidth(2);
    Top_emu_nTrk_bfakeRate_difeta_3->SetLineWidth(2);
    Top_emu_nTrk_cfakeRate_difeta_3->SetLineWidth(2);
    Top_emu_nTrk_lfakeRate_difeta_3->SetLineWidth(2);
    Top_emu_nTrk_hfakeRate_difeta_3->SetLineWidth(2);
    Top_emu_nTrk_bfakeRate->SetLineWidth(2);
    Top_emu_nTrk_cfakeRate->SetLineWidth(2);
    Top_emu_nTrk_lfakeRate->SetLineWidth(2);
    Top_emu_nTrk_hfakeRate->SetLineWidth(2);
    Top_emu_nTrk_fakeRate->SetLineWidth(2);

    dib_nTrk_fakeRate_difeta_1->SetLineWidth(2);
    dib_nTrk_bfakeRate_difeta_1->SetLineWidth(2);
    dib_nTrk_cfakeRate_difeta_1->SetLineWidth(2);
    dib_nTrk_lfakeRate_difeta_1->SetLineWidth(2);
    dib_nTrk_hfakeRate_difeta_1->SetLineWidth(2);
    dib_nTrk_fakeRate_difeta_2->SetLineWidth(2);
    dib_nTrk_bfakeRate_difeta_2->SetLineWidth(2);
    dib_nTrk_cfakeRate_difeta_2->SetLineWidth(2);
    dib_nTrk_lfakeRate_difeta_2->SetLineWidth(2);
    dib_nTrk_hfakeRate_difeta_2->SetLineWidth(2);
    dib_nTrk_fakeRate_difeta_3->SetLineWidth(2);
    dib_nTrk_bfakeRate_difeta_3->SetLineWidth(2);
    dib_nTrk_cfakeRate_difeta_3->SetLineWidth(2);
    dib_nTrk_lfakeRate_difeta_3->SetLineWidth(2);
    dib_nTrk_hfakeRate_difeta_3->SetLineWidth(2);
    dib_nTrk_bfakeRate->SetLineWidth(2);
    dib_nTrk_cfakeRate->SetLineWidth(2);
    dib_nTrk_lfakeRate->SetLineWidth(2);
    dib_nTrk_hfakeRate->SetLineWidth(2);
    dib_nTrk_fakeRate->SetLineWidth(2);

    DY_nTrk_fakeRate_difeta_1->SetLineColor(kOrange - 3);
    DY_nTrk_bfakeRate_difeta_1->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate_difeta_1->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate_difeta_1->SetLineColor(kOrange - 3);
    DY_nTrk_hfakeRate_difeta_1->SetLineColor(kOrange - 3);
    DY_nTrk_fakeRate_difeta_2->SetLineColor(kOrange - 3);
    DY_nTrk_bfakeRate_difeta_2->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate_difeta_2->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate_difeta_2->SetLineColor(kOrange - 3);
    DY_nTrk_hfakeRate_difeta_2->SetLineColor(kOrange - 3);
    DY_nTrk_fakeRate_difeta_3->SetLineColor(kOrange - 3);
    DY_nTrk_bfakeRate_difeta_3->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate_difeta_3->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate_difeta_3->SetLineColor(kOrange - 3);
    DY_nTrk_hfakeRate_difeta_3->SetLineColor(kOrange - 3);
    DY_nTrk_bfakeRate->SetLineColor(kOrange - 3);
    DY_nTrk_cfakeRate->SetLineColor(kOrange - 3);
    DY_nTrk_lfakeRate->SetLineColor(kOrange - 3);
    DY_nTrk_hfakeRate->SetLineColor(kOrange - 3);
    DY_nTrk_fakeRate->SetLineColor(kOrange - 3);
    Top_nTrk_fakeRate_difeta_1->SetLineColor(kGreen + 3);
    Top_nTrk_bfakeRate_difeta_1->SetLineColor(kGreen + 3);
    Top_nTrk_cfakeRate_difeta_1->SetLineColor(kGreen + 3);
    Top_nTrk_lfakeRate_difeta_1->SetLineColor(kGreen + 3);
    Top_nTrk_hfakeRate_difeta_1->SetLineColor(kGreen + 3);
    Top_nTrk_fakeRate_difeta_2->SetLineColor(kGreen + 3);
    Top_nTrk_bfakeRate_difeta_2->SetLineColor(kGreen + 3);
    Top_nTrk_cfakeRate_difeta_2->SetLineColor(kGreen + 3);
    Top_nTrk_lfakeRate_difeta_2->SetLineColor(kGreen + 3);
    Top_nTrk_hfakeRate_difeta_2->SetLineColor(kGreen + 3);
    Top_nTrk_fakeRate_difeta_3->SetLineColor(kGreen + 3);
    Top_nTrk_bfakeRate_difeta_3->SetLineColor(kGreen + 3);
    Top_nTrk_cfakeRate_difeta_3->SetLineColor(kGreen + 3);
    Top_nTrk_lfakeRate_difeta_3->SetLineColor(kGreen + 3);
    Top_nTrk_hfakeRate_difeta_3->SetLineColor(kGreen + 3);
    Top_nTrk_bfakeRate->SetLineColor(kGreen + 3);
    Top_nTrk_cfakeRate->SetLineColor(kGreen + 3);
    Top_nTrk_lfakeRate->SetLineColor(kGreen + 3);
    Top_nTrk_hfakeRate->SetLineColor(kGreen + 3);
    Top_nTrk_fakeRate->SetLineColor(kGreen + 3);
    dib_nTrk_fakeRate_difeta_1->SetLineColor(kAzure + 7);
    dib_nTrk_bfakeRate_difeta_1->SetLineColor(kAzure + 7);
    dib_nTrk_cfakeRate_difeta_1->SetLineColor(kAzure + 7);
    dib_nTrk_lfakeRate_difeta_1->SetLineColor(kAzure + 7);
    dib_nTrk_hfakeRate_difeta_1->SetLineColor(kAzure + 7);
    dib_nTrk_fakeRate_difeta_2->SetLineColor(kAzure + 7);
    dib_nTrk_bfakeRate_difeta_2->SetLineColor(kAzure + 7);
    dib_nTrk_cfakeRate_difeta_2->SetLineColor(kAzure + 7);
    dib_nTrk_lfakeRate_difeta_2->SetLineColor(kAzure + 7);
    dib_nTrk_hfakeRate_difeta_2->SetLineColor(kAzure + 7);
    dib_nTrk_fakeRate_difeta_3->SetLineColor(kAzure + 7);
    dib_nTrk_bfakeRate_difeta_3->SetLineColor(kAzure + 7);
    dib_nTrk_cfakeRate_difeta_3->SetLineColor(kAzure + 7);
    dib_nTrk_lfakeRate_difeta_3->SetLineColor(kAzure + 7);
    dib_nTrk_hfakeRate_difeta_3->SetLineColor(kAzure + 7);
    dib_nTrk_bfakeRate->SetLineColor(kAzure + 7);
    dib_nTrk_cfakeRate->SetLineColor(kAzure + 7);
    dib_nTrk_lfakeRate->SetLineColor(kAzure + 7);
    dib_nTrk_hfakeRate->SetLineColor(kAzure + 7);
    dib_nTrk_fakeRate->SetLineColor(kAzure + 7);

    dib_nTrk_fakeRate->GetXaxis()->SetTitle("nTrk");
    dib_nTrk_fakeRate->GetYaxis()->SetTitle("fake rate");
    dib_nTrk_bfakeRate->GetXaxis()->SetTitle("nTrk");
    dib_nTrk_bfakeRate->GetYaxis()->SetTitle("fake rate");
    dib_nTrk_cfakeRate->GetXaxis()->SetTitle("nTrk");
    dib_nTrk_cfakeRate->GetYaxis()->SetTitle("fake rate");
    dib_nTrk_lfakeRate->GetXaxis()->SetTitle("nTrk");
    dib_nTrk_lfakeRate->GetYaxis()->SetTitle("fake rate");
    dib_nTrk_hfakeRate->GetXaxis()->SetTitle("nTrk");
    dib_nTrk_hfakeRate->GetYaxis()->SetTitle("fake rate");

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

    Top_nTrk_lfakeRate_difeta_1->GetXaxis()->SetTitle("ntrk");
    Top_nTrk_lfakeRate_difeta_1->GetYaxis()->SetTitle("fake rate");

    Top_nTrk_lfakeRate_difeta_1->Draw("h text");
    Top_emu_nTrk_lfakeRate_difeta_1->Draw("h same text");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetTextSize(0.03);
    l0->AddEntry(Top_nTrk_bfakeRate_difeta_1, "Top (Z to ee)", "l");
    l0->AddEntry(Top_emu_nTrk_bfakeRate_difeta_1, "Top to e mu", "l");
    l0->Draw();

    c1->cd(2);

    Top_nTrk_lfakeRate_difeta_2->GetXaxis()->SetTitle("ntrk");
    Top_nTrk_lfakeRate_difeta_2->GetYaxis()->SetTitle("fake rate");

    Top_nTrk_lfakeRate_difeta_2->Draw("h text");
    Top_emu_nTrk_lfakeRate_difeta_2->Draw("h same text");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(Top_nTrk_bfakeRate_difeta_1, "Top (Z to ee)", "l");
    l1->AddEntry(Top_emu_nTrk_bfakeRate_difeta_1, "Top to e mu", "l");
    l1->Draw();

    c1->cd(3);

    Top_nTrk_lfakeRate_difeta_3->GetXaxis()->SetTitle("ntrk");
    Top_nTrk_lfakeRate_difeta_3->GetYaxis()->SetTitle("fake rate");

    Top_nTrk_lfakeRate_difeta_3->Draw("h text");
    Top_emu_nTrk_lfakeRate_difeta_3->Draw("h same text");


    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetTextSize(0.03);
    l2->AddEntry(Top_nTrk_bfakeRate_difeta_1, "Top (Z to ee)", "l");
    l2->AddEntry(Top_emu_nTrk_bfakeRate_difeta_1, "Top to e mu", "l");
    l2->Draw();

    /*
    c1->Divide(4, 1);
    c1->cd(1);
    dib_nTrk_bfakeRate_difeta_1->Draw();
    Top_nTrk_bfakeRate_difeta_1->Draw("h same");
    DY_nTrk_bfakeRate_difeta_1->Draw("h same");
    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor");
    l0->AddEntry(dib_nTrk_fakeRate, "diboson", "l");
    l0->AddEntry(Top_nTrk_fakeRate, "Top", "l");
    l0->AddEntry(DY_nTrk_fakeRate, "DY", "l");
    l0->Draw();
    c1->cd(2);
    dib_nTrk_cfakeRate_difeta_3->Draw();
    Top_nTrk_cfakeRate_difeta_3->Draw("h same");
    DY_nTrk_cfakeRate_difeta_3->Draw("h same");
    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetHeader("c flavor");
    l1->AddEntry(dib_nTrk_fakeRate, "diboson", "l");
    l1->AddEntry(Top_nTrk_fakeRate, "Top", "l");
    l1->AddEntry(DY_nTrk_fakeRate, "DY", "l");
    l1->Draw();
    c1->cd(3);
    Top_nTrk_hfakeRate->GetXaxis()->SetTitle("nTrk");
    Top_nTrk_hfakeRate->GetYaxis()->SetTitle("fake rate");
    Top_nTrk_hfakeRate_difeta_3->Draw();
    dib_nTrk_hfakeRate_difeta_3->Draw("h same");
    DY_nTrk_hfakeRate_difeta_3->Draw("h same");
    TLegend *l2 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l2->SetHeader("heavy flavor");
    l2->AddEntry(dib_nTrk_fakeRate, "diboson", "l");
    l2->AddEntry(Top_nTrk_fakeRate, "Top", "l");
    l2->AddEntry(DY_nTrk_fakeRate, "DY", "l");
    l2->Draw();
    c1->cd(4);

    DY_nTrk_lfakeRate->GetXaxis()->SetTitle("nTrk");
    DY_nTrk_lfakeRate->GetYaxis()->SetTitle("fake rate");
    DY_nTrk_lfakeRate_difeta_3->Draw();
    dib_nTrk_lfakeRate_difeta_3->Draw("h same");
    Top_nTrk_lfakeRate_difeta_3->Draw("h same");

    TLegend *l3 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l3->SetHeader("light flavor");
    l3->AddEntry(dib_nTrk_fakeRate, "diboson", "l");
    l3->AddEntry(Top_nTrk_fakeRate, "Top", "l");
    l3->AddEntry(DY_nTrk_fakeRate, "DY", "l");
    l3->Draw();
    */
    /*
     DY_nTrk_fakeRate->GetXaxis()->SetTitle("nTrk");
     DY_nTrk_fakeRate->GetYaxis()->SetTitle("fake rate");

     DY_nTrk_fakeRate->Draw();
     dib_nTrk_fakeRate->Draw("same");
     Top_nTrk_fakeRate->Draw("same");

     TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
     l0->AddEntry(dib_nTrk_fakeRate, "diboson", "l");
     l0->AddEntry(Top_nTrk_fakeRate, "Top", "l");
     l0->AddEntry(DY_nTrk_fakeRate, "DY", "l");
     l0->Draw();
     */
    /*
    Top_nTrk_lfakeRate->GetXaxis()->SetTitle("nTrk");
    Top_nTrk_lfakeRate->GetYaxis()->SetTitle("fake rate");

    Top_nTrk_lfakeRate->Draw();
    Top_emu_nTrk_lfakeRate->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetHeader("light flavor");
    l0->AddEntry(Top_emu_nTrk_bfakeRate, "Top to e mu", "l");
    l0->AddEntry(Top_nTrk_bfakeRate, "Top (Z to ee)", "l");
    l0->Draw();
    */
    gStyle->SetOptStat(0);
}