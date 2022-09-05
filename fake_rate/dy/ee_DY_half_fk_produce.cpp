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
#include <TH2.h>
#include <TLine.h>
#include <TError.h>
#include "TLegend.h"
#include <cstring>
#include "./../../lib/Cross_section.h"
using namespace std;
void ee_DY_half_fk_produce(TString file = "DY_all.root", TString outputfile = "DY_fakerate.root")
{
    TFile *DYfile = TFile::Open(file);

    TH1D *h_DY_nTrk_bjet_difeta_lowMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_difeta_lowMET_1"));
    TH1D *h_DY_nTrk_bjet_cut_difeta_lowMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_cut_difeta_lowMET_1"));
    TH1D *h_DY_nTrk_cjet_difeta_lowMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_difeta_lowMET_1"));
    TH1D *h_DY_nTrk_cjet_cut_difeta_lowMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_cut_difeta_lowMET_1"));
    TH1D *h_DY_nTrk_ljet_difeta_lowMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_difeta_lowMET_1"));
    TH1D *h_DY_nTrk_ljet_cut_difeta_lowMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_cut_difeta_lowMET_1"));

    TH1D *h_DY_nTrk_bjet_difeta_lowMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_difeta_lowMET_2"));
    TH1D *h_DY_nTrk_bjet_cut_difeta_lowMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_cut_difeta_lowMET_2"));
    TH1D *h_DY_nTrk_cjet_difeta_lowMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_difeta_lowMET_2"));
    TH1D *h_DY_nTrk_cjet_cut_difeta_lowMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_cut_difeta_lowMET_2"));
    TH1D *h_DY_nTrk_ljet_difeta_lowMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_difeta_lowMET_2"));
    TH1D *h_DY_nTrk_ljet_cut_difeta_lowMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_cut_difeta_lowMET_2"));

    TH1D *h_DY_nTrk_bjet_difeta_lowMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_difeta_lowMET_3"));
    TH1D *h_DY_nTrk_bjet_cut_difeta_lowMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_cut_difeta_lowMET_3"));
    TH1D *h_DY_nTrk_cjet_difeta_lowMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_difeta_lowMET_3"));
    TH1D *h_DY_nTrk_cjet_cut_difeta_lowMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_cut_difeta_lowMET_3"));
    TH1D *h_DY_nTrk_ljet_difeta_lowMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_difeta_lowMET_3"));
    TH1D *h_DY_nTrk_ljet_cut_difeta_lowMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_cut_difeta_lowMET_3"));

    TH1D *h_DY_nTrk_bjet_difeta_highMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_difeta_highMET_1"));
    TH1D *h_DY_nTrk_bjet_cut_difeta_highMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_cut_difeta_highMET_1"));
    TH1D *h_DY_nTrk_cjet_difeta_highMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_difeta_highMET_1"));
    TH1D *h_DY_nTrk_cjet_cut_difeta_highMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_cut_difeta_highMET_1"));
    TH1D *h_DY_nTrk_ljet_difeta_highMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_difeta_highMET_1"));
    TH1D *h_DY_nTrk_ljet_cut_difeta_highMET_1 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_cut_difeta_highMET_1"));

    TH1D *h_DY_nTrk_bjet_difeta_highMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_difeta_highMET_2"));
    TH1D *h_DY_nTrk_bjet_cut_difeta_highMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_cut_difeta_highMET_2"));
    TH1D *h_DY_nTrk_cjet_difeta_highMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_difeta_highMET_2"));
    TH1D *h_DY_nTrk_cjet_cut_difeta_highMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_cut_difeta_highMET_2"));
    TH1D *h_DY_nTrk_ljet_difeta_highMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_difeta_highMET_2"));
    TH1D *h_DY_nTrk_ljet_cut_difeta_highMET_2 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_cut_difeta_highMET_2"));

    TH1D *h_DY_nTrk_bjet_difeta_highMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_difeta_highMET_3"));
    TH1D *h_DY_nTrk_bjet_cut_difeta_highMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_bjet_cut_difeta_highMET_3"));
    TH1D *h_DY_nTrk_cjet_difeta_highMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_difeta_highMET_3"));
    TH1D *h_DY_nTrk_cjet_cut_difeta_highMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_cjet_cut_difeta_highMET_3"));
    TH1D *h_DY_nTrk_ljet_difeta_highMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_difeta_highMET_3"));
    TH1D *h_DY_nTrk_ljet_cut_difeta_highMET_3 = ((TH1D *)DYfile->Get("h_DY_nTrk_ljet_cut_difeta_highMET_3"));

    //---------------------
    // Calculate fake rate
    //---------------------
    // For High MET mid MET Low MET
    TH1D *DY_nTrk_bfakeRate_difeta_lowMET_1 = (TH1D *)h_DY_nTrk_bjet_cut_difeta_lowMET_1->Clone("DY_nTrk_bfakeRate_difeta_lowMET_1");
    DY_nTrk_bfakeRate_difeta_lowMET_1->Divide(h_DY_nTrk_bjet_cut_difeta_lowMET_1, h_DY_nTrk_bjet_difeta_lowMET_1, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate_difeta_lowMET_1 = (TH1D *)h_DY_nTrk_cjet_cut_difeta_lowMET_1->Clone("DY_nTrk_cfakeRate_difeta_lowMET_1");
    DY_nTrk_cfakeRate_difeta_lowMET_1->Divide(h_DY_nTrk_cjet_cut_difeta_lowMET_1, h_DY_nTrk_cjet_difeta_lowMET_1, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_difeta_lowMET_1 = (TH1D *)h_DY_nTrk_ljet_cut_difeta_lowMET_1->Clone("DY_nTrk_lfakeRate_difeta_lowMET_1");
    DY_nTrk_lfakeRate_difeta_lowMET_1->Divide(h_DY_nTrk_ljet_cut_difeta_lowMET_1, h_DY_nTrk_ljet_difeta_lowMET_1, 1, 1, "b");

    TH1D *DY_nTrk_bfakeRate_difeta_lowMET_2 = (TH1D *)h_DY_nTrk_bjet_cut_difeta_lowMET_2->Clone("DY_nTrk_bfakeRate_difeta_lowMET_2");
    DY_nTrk_bfakeRate_difeta_lowMET_2->Divide(h_DY_nTrk_bjet_cut_difeta_lowMET_2, h_DY_nTrk_bjet_difeta_lowMET_2, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate_difeta_lowMET_2 = (TH1D *)h_DY_nTrk_cjet_cut_difeta_lowMET_2->Clone("DY_nTrk_cfakeRate_difeta_lowMET_2");
    DY_nTrk_cfakeRate_difeta_lowMET_2->Divide(h_DY_nTrk_cjet_cut_difeta_lowMET_2, h_DY_nTrk_cjet_difeta_lowMET_2, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_difeta_lowMET_2 = (TH1D *)h_DY_nTrk_ljet_cut_difeta_lowMET_2->Clone("DY_nTrk_lfakeRate_difeta_lowMET_2");
    DY_nTrk_lfakeRate_difeta_lowMET_2->Divide(h_DY_nTrk_ljet_cut_difeta_lowMET_2, h_DY_nTrk_ljet_difeta_lowMET_2, 1, 1, "b");

    TH1D *DY_nTrk_bfakeRate_difeta_lowMET_3 = (TH1D *)h_DY_nTrk_bjet_cut_difeta_lowMET_3->Clone("DY_nTrk_bfakeRate_difeta_lowMET_3");
    DY_nTrk_bfakeRate_difeta_lowMET_3->Divide(h_DY_nTrk_bjet_cut_difeta_lowMET_3, h_DY_nTrk_bjet_difeta_lowMET_3, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate_difeta_lowMET_3 = (TH1D *)h_DY_nTrk_cjet_cut_difeta_lowMET_3->Clone("DY_nTrk_cfakeRate_difeta_lowMET_3");
    DY_nTrk_cfakeRate_difeta_lowMET_3->Divide(h_DY_nTrk_cjet_cut_difeta_lowMET_3, h_DY_nTrk_cjet_difeta_lowMET_3, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_difeta_lowMET_3 = (TH1D *)h_DY_nTrk_ljet_cut_difeta_lowMET_3->Clone("DY_nTrk_lfakeRate_difeta_lowMET_3");
    DY_nTrk_lfakeRate_difeta_lowMET_3->Divide(h_DY_nTrk_ljet_cut_difeta_lowMET_3, h_DY_nTrk_ljet_difeta_lowMET_3, 1, 1, "b");

    TH1D *DY_nTrk_bfakeRate_difeta_highMET_1 = (TH1D *)h_DY_nTrk_bjet_cut_difeta_highMET_1->Clone("DY_nTrk_bfakeRate_difeta_highMET_1");
    DY_nTrk_bfakeRate_difeta_highMET_1->Divide(h_DY_nTrk_bjet_cut_difeta_highMET_1, h_DY_nTrk_bjet_difeta_highMET_1, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate_difeta_highMET_1 = (TH1D *)h_DY_nTrk_cjet_cut_difeta_highMET_1->Clone("DY_nTrk_cfakeRate_difeta_highMET_1");
    DY_nTrk_cfakeRate_difeta_highMET_1->Divide(h_DY_nTrk_cjet_cut_difeta_highMET_1, h_DY_nTrk_cjet_difeta_highMET_1, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_difeta_highMET_1 = (TH1D *)h_DY_nTrk_ljet_cut_difeta_highMET_1->Clone("DY_nTrk_lfakeRate_difeta_highMET_1");
    DY_nTrk_lfakeRate_difeta_highMET_1->Divide(h_DY_nTrk_ljet_cut_difeta_highMET_1, h_DY_nTrk_ljet_difeta_highMET_1, 1, 1, "b");

    TH1D *DY_nTrk_bfakeRate_difeta_highMET_2 = (TH1D *)h_DY_nTrk_bjet_cut_difeta_highMET_2->Clone("DY_nTrk_bfakeRate_difeta_highMET_2");
    DY_nTrk_bfakeRate_difeta_highMET_2->Divide(h_DY_nTrk_bjet_cut_difeta_highMET_2, h_DY_nTrk_bjet_difeta_highMET_2, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate_difeta_highMET_2 = (TH1D *)h_DY_nTrk_cjet_cut_difeta_highMET_2->Clone("DY_nTrk_cfakeRate_difeta_highMET_2");
    DY_nTrk_cfakeRate_difeta_highMET_2->Divide(h_DY_nTrk_cjet_cut_difeta_highMET_2, h_DY_nTrk_cjet_difeta_highMET_2, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_difeta_highMET_2 = (TH1D *)h_DY_nTrk_ljet_cut_difeta_highMET_2->Clone("DY_nTrk_lfakeRate_difeta_highMET_2");
    DY_nTrk_lfakeRate_difeta_highMET_2->Divide(h_DY_nTrk_ljet_cut_difeta_highMET_2, h_DY_nTrk_ljet_difeta_highMET_2, 1, 1, "b");

    TH1D *DY_nTrk_bfakeRate_difeta_highMET_3 = (TH1D *)h_DY_nTrk_bjet_cut_difeta_highMET_3->Clone("DY_nTrk_bfakeRate_difeta_highMET_3");
    DY_nTrk_bfakeRate_difeta_highMET_3->Divide(h_DY_nTrk_bjet_cut_difeta_highMET_3, h_DY_nTrk_bjet_difeta_highMET_3, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate_difeta_highMET_3 = (TH1D *)h_DY_nTrk_cjet_cut_difeta_highMET_3->Clone("DY_nTrk_cfakeRate_difeta_highMET_3");
    DY_nTrk_cfakeRate_difeta_highMET_3->Divide(h_DY_nTrk_cjet_cut_difeta_highMET_3, h_DY_nTrk_cjet_difeta_highMET_3, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_difeta_highMET_3 = (TH1D *)h_DY_nTrk_ljet_cut_difeta_highMET_3->Clone("DY_nTrk_lfakeRate_difeta_highMET_3");
    DY_nTrk_lfakeRate_difeta_highMET_3->Divide(h_DY_nTrk_ljet_cut_difeta_highMET_3, h_DY_nTrk_ljet_difeta_highMET_3, 1, 1, "b");

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();

    DY_nTrk_bfakeRate_difeta_lowMET_1->Write();
    DY_nTrk_cfakeRate_difeta_lowMET_1->Write();
    DY_nTrk_lfakeRate_difeta_lowMET_1->Write();

    DY_nTrk_bfakeRate_difeta_lowMET_2->Write();
    DY_nTrk_cfakeRate_difeta_lowMET_2->Write();
    DY_nTrk_lfakeRate_difeta_lowMET_2->Write();

    DY_nTrk_bfakeRate_difeta_lowMET_3->Write();
    DY_nTrk_cfakeRate_difeta_lowMET_3->Write();
    DY_nTrk_lfakeRate_difeta_lowMET_3->Write();

    DY_nTrk_bfakeRate_difeta_highMET_1->Write();
    DY_nTrk_cfakeRate_difeta_highMET_1->Write();
    DY_nTrk_lfakeRate_difeta_highMET_1->Write();

    DY_nTrk_bfakeRate_difeta_highMET_2->Write();
    DY_nTrk_cfakeRate_difeta_highMET_2->Write();
    DY_nTrk_lfakeRate_difeta_highMET_2->Write();

    DY_nTrk_bfakeRate_difeta_highMET_3->Write();
    DY_nTrk_cfakeRate_difeta_highMET_3->Write();
    DY_nTrk_lfakeRate_difeta_highMET_3->Write();

    outfile->Close();
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_DY_half_fk_produce();
    }
    else if (argc == 3)
    {
        ee_DY_half_fk_produce(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}