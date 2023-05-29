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
void ee_DY_all_fk_produce(TString file = "./output/DY_all_output.root", TString outputfile = "DY_fakerate.root")
{
    TFile *DYfile = TFile::Open(file);

    TH1D *h_DY_nTrk_jet_lowDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_jet_lowDilepPt");
    TH1D *h_DY_nTrk_jet_cut_lowDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_jet_cut_lowDilepPt");
    TH1D *h_DY_nTrk_jet_highDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_jet_highDilepPt");
    TH1D *h_DY_nTrk_jet_cut_highDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_jet_cut_highDilepPt");
    TH1D *h_DY_JetPt_lowDilepPt = DYfile->Get<TH1D>("h_DY_JetPt_lowDilepPt");
    TH1D *h_DY_JetPt_cut_lowDilepPt = DYfile->Get<TH1D>("h_DY_JetPt_cut_lowDilepPt");
    TH1D *h_DY_JetPt_highDilepPt = DYfile->Get<TH1D>("h_DY_JetPt_highDilepPt");
    TH1D *h_DY_JetPt_cut_highDilepPt = DYfile->Get<TH1D>("h_DY_JetPt_cut_highDilepPt");
    TH1D *h_DY_JetEta_lowDilepPt = DYfile->Get<TH1D>("h_DY_JetEta_lowDilepPt");
    TH1D *h_DY_JetEta_cut_lowDilepPt = DYfile->Get<TH1D>("h_DY_JetEta_cut_lowDilepPt");
    TH1D *h_DY_JetEta_highDilepPt = DYfile->Get<TH1D>("h_DY_JetEta_highDilepPt");
    TH1D *h_DY_JetEta_cut_highDilepPt = DYfile->Get<TH1D>("h_DY_JetEta_cut_highDilepPt");

    /*Single flavor*/
    TH1D *h_DY_nTrk_bjet_lowDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_bjet_lowDilepPt");
    TH1D *h_DY_nTrk_bjet_cut_lowDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_bjet_cut_lowDilepPt");
    TH1D *h_DY_nTrk_ljet_lowDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_ljet_lowDilepPt");
    TH1D *h_DY_nTrk_ljet_cut_lowDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_ljet_cut_lowDilepPt");
    TH1D *h_DY_nTrk_bjet_highDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_bjet_highDilepPt");
    TH1D *h_DY_nTrk_bjet_cut_highDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_bjet_cut_highDilepPt");
    TH1D *h_DY_nTrk_ljet_highDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_ljet_highDilepPt");
    TH1D *h_DY_nTrk_ljet_cut_highDilepPt = DYfile->Get<TH1D>("h_DY_nTrk_ljet_cut_highDilepPt");
    //---------------------
    // Calculate fake rate
    //---------------------
    // For High dileptonPT Low dileptonPT
    TH1D *DY_nTrk_fakeRate_lowDilepPt = (TH1D *)h_DY_nTrk_jet_cut_lowDilepPt->Clone("DY_nTrk_fakeRate_lowDilepPt");
    DY_nTrk_fakeRate_lowDilepPt->Divide(h_DY_nTrk_jet_cut_lowDilepPt, h_DY_nTrk_jet_lowDilepPt, 1, 1, "b");
    TH1D *DY_JetPt_fakeRate_lowDilepPt = (TH1D *)h_DY_JetPt_cut_lowDilepPt->Clone("DY_JetPt_fakeRate_lowDilepPt");
    DY_JetPt_fakeRate_lowDilepPt->Divide(h_DY_JetPt_cut_lowDilepPt, h_DY_JetPt_lowDilepPt, 1, 1, "b");
    TH1D *DY_JetEta_fakeRate_lowDilepPt = (TH1D *)h_DY_JetEta_cut_lowDilepPt->Clone("DY_JetEta_fakeRate_lowDilepPt");
    DY_JetEta_fakeRate_lowDilepPt->Divide(h_DY_JetEta_cut_lowDilepPt, h_DY_JetEta_lowDilepPt, 1, 1, "b");

    /*Single flavor*/
    TH1D *DY_nTrk_bfakeRate_lowDilepPt = (TH1D *)h_DY_nTrk_bjet_cut_lowDilepPt->Clone("DY_nTrk_bfakeRate_lowDilepPt");
    DY_nTrk_bfakeRate_lowDilepPt->Divide(h_DY_nTrk_bjet_cut_lowDilepPt, h_DY_nTrk_bjet_lowDilepPt, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_lowDilepPt = (TH1D *)h_DY_nTrk_ljet_cut_lowDilepPt->Clone("DY_nTrk_lfakeRate_lowDilepPt");
    DY_nTrk_lfakeRate_lowDilepPt->Divide(h_DY_nTrk_ljet_cut_lowDilepPt, h_DY_nTrk_ljet_lowDilepPt, 1, 1, "b");

    TH1D *DY_nTrk_fakeRate_highDilepPt = (TH1D *)h_DY_nTrk_jet_cut_highDilepPt->Clone("DY_nTrk_fakeRate_highDilepPt");
    DY_nTrk_fakeRate_highDilepPt->Divide(h_DY_nTrk_jet_cut_highDilepPt, h_DY_nTrk_jet_highDilepPt, 1, 1, "b");
    TH1D *DY_JetPt_fakeRate_highDilepPt = (TH1D *)h_DY_JetPt_cut_highDilepPt->Clone("DY_JetPt_fakeRate_highDilepPt");
    DY_JetPt_fakeRate_highDilepPt->Divide(h_DY_JetPt_cut_highDilepPt, h_DY_JetPt_highDilepPt, 1, 1, "b");
    TH1D *DY_JetEta_fakeRate_highDilepPt = (TH1D *)h_DY_JetEta_cut_highDilepPt->Clone("DY_JetEta_fakeRate_highDilepPt");
    DY_JetEta_fakeRate_highDilepPt->Divide(h_DY_JetEta_cut_highDilepPt, h_DY_JetEta_highDilepPt, 1, 1, "b");

    /*Single flavor*/
    TH1D *DY_nTrk_bfakeRate_highDilepPt = (TH1D *)h_DY_nTrk_bjet_cut_highDilepPt->Clone("DY_nTrk_bfakeRate_highDilepPt");
    DY_nTrk_bfakeRate_highDilepPt->Divide(h_DY_nTrk_bjet_cut_highDilepPt, h_DY_nTrk_bjet_highDilepPt, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_highDilepPt = (TH1D *)h_DY_nTrk_ljet_cut_highDilepPt->Clone("DY_nTrk_lfakeRate_highDilepPt");
    DY_nTrk_lfakeRate_highDilepPt->Divide(h_DY_nTrk_ljet_cut_highDilepPt, h_DY_nTrk_ljet_highDilepPt, 1, 1, "b");

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();

    DY_nTrk_fakeRate_lowDilepPt->Write();
    DY_JetPt_fakeRate_lowDilepPt->Write();
    DY_JetEta_fakeRate_lowDilepPt->Write();
    DY_nTrk_fakeRate_highDilepPt->Write();
    DY_JetPt_fakeRate_highDilepPt->Write();
    DY_JetEta_fakeRate_highDilepPt->Write();

    /*Single flavor*/
    DY_nTrk_bfakeRate_lowDilepPt->Write();
    DY_nTrk_lfakeRate_lowDilepPt->Write();
    DY_nTrk_bfakeRate_highDilepPt->Write();
    DY_nTrk_lfakeRate_highDilepPt->Write();


    outfile->Close();
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_DY_all_fk_produce();
    }
    else if (argc == 3)
    {
        ee_DY_all_fk_produce(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}