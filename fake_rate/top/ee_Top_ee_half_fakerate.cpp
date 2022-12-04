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

//------------------------------------------------------------------------------------r
//   Divide histogram (numerator/denominator): output hist, numerator, and denominator
//------------------------------------------------------------------------------------
void DivideHistogram(TH1D *h_fakerate, TH1D *h_numerator, TH1D *h_denominator)
{
    h_fakerate->Divide(h_numerator, h_denominator, 1, 1, "b");
}
void ee_Top_ee_half_fakerate(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *Topfile = TFile::Open(file);

    // For ntrk
    TH1D *h_Top_nTrk_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_lowDilepPt"));
    TH1D *h_Top_nTrk_cut_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_cut_lowDilepPt"));
    TH1D *h_Top_nTrk_highDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_highDilepPt"));
    TH1D *h_Top_nTrk_cut_highDilepPt = ((TH1D *)Topfile->Get("h_Top_nTrk_cut_highDilepPt"));

    // For JetPt
    TH1D *h_Top_JetPt_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_JetPt_lowDilepPt"));
    TH1D *h_Top_JetPt_cut_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_JetPt_cut_lowDilepPt"));
    TH1D *h_Top_JetPt_highDilepPt = ((TH1D *)Topfile->Get("h_Top_JetPt_highDilepPt"));
    TH1D *h_Top_JetPt_cut_highDilepPt = ((TH1D *)Topfile->Get("h_Top_JetPt_cut_highDilepPt"));

    // For JetEta
    TH1D *h_Top_JetEta_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_JetEta_lowDilepPt"));
    TH1D *h_Top_JetEta_cut_lowDilepPt = ((TH1D *)Topfile->Get("h_Top_JetEta_cut_lowDilepPt"));
    TH1D *h_Top_JetEta_highDilepPt = ((TH1D *)Topfile->Get("h_Top_JetEta_highDilepPt"));
    TH1D *h_Top_JetEta_cut_highDilepPt = ((TH1D *)Topfile->Get("h_Top_JetEta_cut_highDilepPt"));

    //---------------------
    // Calculate fake rate
    //---------------------
    // For nTrk
    TH1D *Top_nTrk_fakeRate_lowDilepPt = (TH1D *)h_Top_nTrk_cut_lowDilepPt->Clone("Top_nTrk_fakeRate_lowDilepPt");
    DivideHistogram(Top_nTrk_fakeRate_lowDilepPt, h_Top_nTrk_cut_lowDilepPt, h_Top_nTrk_lowDilepPt);

    TH1D *Top_nTrk_fakeRate_highDilepPt = (TH1D *)h_Top_nTrk_cut_highDilepPt->Clone("Top_nTrk_fakeRate_highDilepPt");
    DivideHistogram(Top_nTrk_fakeRate_highDilepPt, h_Top_nTrk_cut_highDilepPt, h_Top_nTrk_highDilepPt);

    // For JetPt
    TH1D *Top_JetPt_fakeRate_lowDilepPt = (TH1D *)h_Top_JetPt_cut_lowDilepPt->Clone("Top_JetPt_fakeRate_lowDilepPt");
    DivideHistogram(Top_JetPt_fakeRate_lowDilepPt, h_Top_JetPt_cut_lowDilepPt, h_Top_JetPt_lowDilepPt);

    TH1D *Top_JetPt_fakeRate_highDilepPt = (TH1D *)h_Top_JetPt_cut_highDilepPt->Clone("Top_JetPt_fakeRate_highDilepPt");
    DivideHistogram(Top_JetPt_fakeRate_highDilepPt, h_Top_JetPt_cut_highDilepPt, h_Top_JetPt_highDilepPt);

    // For JetEta
    TH1D *Top_JetEta_fakeRate_lowDilepPt = (TH1D *)h_Top_JetEta_cut_lowDilepPt->Clone("Top_JetEta_fakeRate_lowDilepPt");
    DivideHistogram(Top_JetEta_fakeRate_lowDilepPt, h_Top_JetEta_cut_lowDilepPt, h_Top_JetEta_lowDilepPt);

    TH1D *Top_JetEta_fakeRate_highDilepPt = (TH1D *)h_Top_JetEta_cut_highDilepPt->Clone("Top_JetEta_fakeRate_highDilepPt");
    DivideHistogram(Top_JetEta_fakeRate_highDilepPt, h_Top_JetEta_cut_highDilepPt, h_Top_JetEta_highDilepPt);

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    Top_nTrk_fakeRate_lowDilepPt->Write();
    Top_nTrk_fakeRate_highDilepPt->Write();
    Top_JetPt_fakeRate_lowDilepPt->Write();
    Top_JetPt_fakeRate_highDilepPt->Write();
    Top_JetEta_fakeRate_lowDilepPt->Write();
    Top_JetEta_fakeRate_highDilepPt->Write();

    outfile->Close();
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_Top_ee_half_fakerate();
    }
    else if (argc == 3)
    {
        ee_Top_ee_half_fakerate(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}