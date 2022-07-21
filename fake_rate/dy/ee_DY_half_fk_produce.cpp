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
    TFile *dibfile = TFile::Open(file);

    TH1D *h_DY_nTrk_bjet = ((TH1D *)dibfile->Get("h_DY_nTrk_bjet"));
    TH1D *h_DY_nTrk_bjet_cut = ((TH1D *)dibfile->Get("h_DY_nTrk_bjet_cut"));
    TH1D *h_DY_nTrk_cjet = ((TH1D *)dibfile->Get("h_DY_nTrk_cjet"));
    TH1D *h_DY_nTrk_cjet_cut = ((TH1D *)dibfile->Get("h_DY_nTrk_cjet_cut"));
    TH1D *h_DY_nTrk_ljet = ((TH1D *)dibfile->Get("h_DY_nTrk_ljet"));
    TH1D *h_DY_nTrk_ljet_cut = ((TH1D *)dibfile->Get("h_DY_nTrk_ljet_cut"));
    TH1D *h_DY_nTrk_hjet = ((TH1D *)dibfile->Get("h_DY_nTrk_hjet"));
    TH1D *h_DY_nTrk_hjet_cut = ((TH1D *)dibfile->Get("h_DY_nTrk_hjet_cut"));
    TH1D *h_DY_nTrk = ((TH1D *)dibfile->Get("h_DY_nTrk"));
    TH1D *h_DY_nTrk_cut = ((TH1D *)dibfile->Get("h_DY_nTrk_cut"));

    TH1D *h_DY_nTrk_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_difeta_1"));
    TH1D *h_DY_nTrk_cut_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_cut_difeta_1"));
    TH1D *h_DY_nTrk_bjet_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_bjet_difeta_1"));
    TH1D *h_DY_nTrk_bjet_cut_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_bjet_cut_difeta_1"));
    TH1D *h_DY_nTrk_cjet_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_cjet_difeta_1"));
    TH1D *h_DY_nTrk_cjet_cut_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_cjet_cut_difeta_1"));
    TH1D *h_DY_nTrk_ljet_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_ljet_difeta_1"));
    TH1D *h_DY_nTrk_ljet_cut_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_ljet_cut_difeta_1"));
    TH1D *h_DY_nTrk_hjet_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_hjet_difeta_1"));
    TH1D *h_DY_nTrk_hjet_cut_difeta_1 = ((TH1D *)dibfile->Get("h_DY_nTrk_hjet_cut_difeta_1"));

    TH1D *h_DY_nTrk_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_difeta_2"));
    TH1D *h_DY_nTrk_cut_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_cut_difeta_2"));
    TH1D *h_DY_nTrk_bjet_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_bjet_difeta_2"));
    TH1D *h_DY_nTrk_bjet_cut_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_bjet_cut_difeta_2"));
    TH1D *h_DY_nTrk_cjet_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_cjet_difeta_2"));
    TH1D *h_DY_nTrk_cjet_cut_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_cjet_cut_difeta_2"));
    TH1D *h_DY_nTrk_ljet_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_ljet_difeta_2"));
    TH1D *h_DY_nTrk_ljet_cut_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_ljet_cut_difeta_2"));
    TH1D *h_DY_nTrk_hjet_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_hjet_difeta_2"));
    TH1D *h_DY_nTrk_hjet_cut_difeta_2 = ((TH1D *)dibfile->Get("h_DY_nTrk_hjet_cut_difeta_2"));

    TH1D *h_DY_nTrk_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_difeta_3"));
    TH1D *h_DY_nTrk_cut_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_cut_difeta_3"));
    TH1D *h_DY_nTrk_bjet_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_bjet_difeta_3"));
    TH1D *h_DY_nTrk_bjet_cut_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_bjet_cut_difeta_3"));
    TH1D *h_DY_nTrk_cjet_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_cjet_difeta_3"));
    TH1D *h_DY_nTrk_cjet_cut_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_cjet_cut_difeta_3"));
    TH1D *h_DY_nTrk_ljet_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_ljet_difeta_3"));
    TH1D *h_DY_nTrk_ljet_cut_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_ljet_cut_difeta_3"));
    TH1D *h_DY_nTrk_hjet_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_hjet_difeta_3"));
    TH1D *h_DY_nTrk_hjet_cut_difeta_3 = ((TH1D *)dibfile->Get("h_DY_nTrk_hjet_cut_difeta_3"));

    //---------------------
    // Calculate fake rate
    //---------------------
    TH1D *DY_nTrk_bfakeRate_difeta_1 = (TH1D *)h_DY_nTrk_bjet_cut_difeta_1->Clone("DY_nTrk_bfakeRate_difeta_1");
    DY_nTrk_bfakeRate_difeta_1->Divide(h_DY_nTrk_bjet_cut_difeta_1, h_DY_nTrk_bjet_difeta_1, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate_difeta_1 = (TH1D *)h_DY_nTrk_cjet_cut_difeta_1->Clone("DY_nTrk_cfakeRate_difeta_1");
    DY_nTrk_cfakeRate_difeta_1->Divide(h_DY_nTrk_cjet_cut_difeta_1, h_DY_nTrk_cjet_difeta_1, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_difeta_1 = (TH1D *)h_DY_nTrk_ljet_cut_difeta_1->Clone("DY_nTrk_lfakeRate_difeta_1");
    DY_nTrk_lfakeRate_difeta_1->Divide(h_DY_nTrk_ljet_cut_difeta_1, h_DY_nTrk_ljet_difeta_1, 1, 1, "b");
    TH1D *DY_nTrk_hfakeRate_difeta_1 = (TH1D *)h_DY_nTrk_hjet_cut_difeta_1->Clone("DY_nTrk_hfakeRate_difeta_1");
    DY_nTrk_hfakeRate_difeta_1->Divide(h_DY_nTrk_hjet_cut_difeta_1, h_DY_nTrk_hjet_difeta_1, 1, 1, "b");
    TH1D *DY_nTrk_fakeRate_difeta_1 = (TH1D *)h_DY_nTrk_cut_difeta_1->Clone("DY_nTrk_fakeRate_difeta_1");
    DY_nTrk_fakeRate_difeta_1->Divide(h_DY_nTrk_cut_difeta_1, h_DY_nTrk_difeta_1, 1, 1, "b");

    TH1D *DY_nTrk_bfakeRate_difeta_2 = (TH1D *)h_DY_nTrk_bjet_cut_difeta_2->Clone("DY_nTrk_bfakeRate_difeta_2");
    DY_nTrk_bfakeRate_difeta_2->Divide(h_DY_nTrk_bjet_cut_difeta_2, h_DY_nTrk_bjet_difeta_2, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate_difeta_2 = (TH1D *)h_DY_nTrk_cjet_cut_difeta_2->Clone("DY_nTrk_cfakeRate_difeta_2");
    DY_nTrk_cfakeRate_difeta_2->Divide(h_DY_nTrk_cjet_cut_difeta_2, h_DY_nTrk_cjet_difeta_2, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_difeta_2 = (TH1D *)h_DY_nTrk_ljet_cut_difeta_2->Clone("DY_nTrk_lfakeRate_difeta_2");
    DY_nTrk_lfakeRate_difeta_2->Divide(h_DY_nTrk_ljet_cut_difeta_2, h_DY_nTrk_ljet_difeta_2, 1, 1, "b");
    TH1D *DY_nTrk_hfakeRate_difeta_2 = (TH1D *)h_DY_nTrk_hjet_cut_difeta_2->Clone("DY_nTrk_hfakeRate_difeta_2");
    DY_nTrk_hfakeRate_difeta_2->Divide(h_DY_nTrk_hjet_cut_difeta_2, h_DY_nTrk_hjet_difeta_2, 1, 1, "b");
    TH1D *DY_nTrk_fakeRate_difeta_2 = (TH1D *)h_DY_nTrk_cut_difeta_2->Clone("DY_nTrk_fakeRate_difeta_2");
    DY_nTrk_fakeRate_difeta_2->Divide(h_DY_nTrk_cut_difeta_2, h_DY_nTrk_difeta_2, 1, 1, "b");

    TH1D *DY_nTrk_bfakeRate_difeta_3 = (TH1D *)h_DY_nTrk_bjet_cut_difeta_3->Clone("DY_nTrk_bfakeRate_difeta_3");
    DY_nTrk_bfakeRate_difeta_3->Divide(h_DY_nTrk_bjet_cut_difeta_3, h_DY_nTrk_bjet_difeta_3, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate_difeta_3 = (TH1D *)h_DY_nTrk_cjet_cut_difeta_3->Clone("DY_nTrk_cfakeRate_difeta_3");
    DY_nTrk_cfakeRate_difeta_3->Divide(h_DY_nTrk_cjet_cut_difeta_3, h_DY_nTrk_cjet_difeta_3, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate_difeta_3 = (TH1D *)h_DY_nTrk_ljet_cut_difeta_3->Clone("DY_nTrk_lfakeRate_difeta_3");
    DY_nTrk_lfakeRate_difeta_3->Divide(h_DY_nTrk_ljet_cut_difeta_3, h_DY_nTrk_ljet_difeta_3, 1, 1, "b");
    TH1D *DY_nTrk_hfakeRate_difeta_3 = (TH1D *)h_DY_nTrk_hjet_cut_difeta_3->Clone("DY_nTrk_hfakeRate_difeta_3");
    DY_nTrk_hfakeRate_difeta_3->Divide(h_DY_nTrk_hjet_cut_difeta_3, h_DY_nTrk_hjet_difeta_3, 1, 1, "b");
    TH1D *DY_nTrk_fakeRate_difeta_3 = (TH1D *)h_DY_nTrk_cut_difeta_3->Clone("DY_nTrk_fakeRate_difeta_3");
    DY_nTrk_fakeRate_difeta_3->Divide(h_DY_nTrk_cut_difeta_3, h_DY_nTrk_difeta_3, 1, 1, "b");

    TH1D *DY_nTrk_bfakeRate = (TH1D *)h_DY_nTrk_bjet_cut->Clone("DY_nTrk_bfakeRate");
    DY_nTrk_bfakeRate->Divide(h_DY_nTrk_bjet_cut, h_DY_nTrk_bjet, 1, 1, "b");
    TH1D *DY_nTrk_cfakeRate = (TH1D *)h_DY_nTrk_cjet_cut->Clone("DY_nTrk_cfakeRate");
    DY_nTrk_cfakeRate->Divide(h_DY_nTrk_cjet_cut, h_DY_nTrk_cjet, 1, 1, "b");
    TH1D *DY_nTrk_lfakeRate = (TH1D *)h_DY_nTrk_ljet_cut->Clone("DY_nTrk_lfakeRate");
    DY_nTrk_lfakeRate->Divide(h_DY_nTrk_ljet_cut, h_DY_nTrk_ljet, 1, 1, "b");
    TH1D *DY_nTrk_hfakeRate = (TH1D *)h_DY_nTrk_hjet_cut->Clone("DY_nTrk_hfakeRate");
    DY_nTrk_hfakeRate->Divide(h_DY_nTrk_hjet_cut, h_DY_nTrk_hjet, 1, 1, "b");
    TH1D *DY_nTrk_fakeRate = (TH1D *)h_DY_nTrk_cut->Clone("DY_nTrk_fakeRate");
    DY_nTrk_fakeRate->Divide(h_DY_nTrk_cut, h_DY_nTrk, 1, 1, "b");

    //------------------------
    // Read TH2D
    //------------------------
    /*
    TH2D *h_DY_nTrk_eta_bjet = ((TH2D *)dibfile->Get("h_DY_nTrk_eta_bjet"));
    TH2D *h_DY_nTrk_eta_bjet_cut = ((TH2D *)dibfile->Get("h_DY_nTrk_eta_bjet_cut"));
    TH2D *h_DY_nTrk_eta_cjet = ((TH2D *)dibfile->Get("h_DY_nTrk_eta_cjet"));
    TH2D *h_DY_nTrk_eta_cjet_cut = ((TH2D *)dibfile->Get("h_DY_nTrk_eta_cjet_cut"));
    TH2D *h_DY_nTrk_eta_ljet = ((TH2D *)dibfile->Get("h_DY_nTrk_eta_ljet"));
    TH2D *h_DY_nTrk_eta_ljet_cut = ((TH2D *)dibfile->Get("h_DY_nTrk_eta_ljet_cut"));

    TH2D *h_DY_nTrk_eta_bfakerate = new TH2D("h_DY_nTrk_eta_bfakerate", "", 30, 1, 30, 30, -3.0, 3.0);
    h_DY_nTrk_eta_bfakerate->Sumw2();
    TH2D *h_DY_nTrk_eta_cfakerate = new TH2D("h_DY_nTrk_eta_cfakerate", "", 30, 1, 30, 30, -3.0, 3.0);
    h_DY_nTrk_eta_cfakerate->Sumw2();
    TH2D *h_DY_nTrk_eta_lfakerate = new TH2D("h_DY_nTrk_eta_lfakerate", "", 30, 1, 30, 30, -3.0, 3.0);
    h_DY_nTrk_eta_lfakerate->Sumw2();

    int nbinx = h_DY_nTrk_eta_bjet->GetNbinsX();
    int nbiny = h_DY_nTrk_eta_bjet->GetNbinsY();
    cout << "nbinx = " << nbinx << endl;

    for (int i = 1; i <= nbinx; i++)
    {
        for (int j = 1; j <= nbiny; j++)
        {
            double b_fakerate;
            double c_fakerate;
            double l_fakerate;
            b_fakerate = h_DY_nTrk_eta_bjet_cut->GetBinContent(i, j) / h_DY_nTrk_eta_bjet->GetBinContent(i, j);
            c_fakerate = h_DY_nTrk_eta_cjet_cut->GetBinContent(i, j) / h_DY_nTrk_eta_cjet->GetBinContent(i, j);
            l_fakerate = h_DY_nTrk_eta_ljet_cut->GetBinContent(i, j) / h_DY_nTrk_eta_ljet->GetBinContent(i, j);
            if (h_DY_nTrk_eta_bjet->GetBinContent(i, j) == 0)
            {
                b_fakerate = 0;
            }
            if (h_DY_nTrk_eta_cjet->GetBinContent(i, j) == 0)
            {
                c_fakerate = 0;
            }
            if (h_DY_nTrk_eta_ljet->GetBinContent(i, j) == 0)
            {
                l_fakerate = 0;
            }
            h_DY_nTrk_eta_bfakerate->SetBinContent(i, j, b_fakerate);
            h_DY_nTrk_eta_cfakerate->SetBinContent(i, j, c_fakerate);
            h_DY_nTrk_eta_lfakerate->SetBinContent(i, j, l_fakerate);
        }
    }
    */

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    DY_nTrk_bfakeRate_difeta_1->Write();
    DY_nTrk_cfakeRate_difeta_1->Write();
    DY_nTrk_lfakeRate_difeta_1->Write();
    DY_nTrk_hfakeRate_difeta_1->Write();
    DY_nTrk_fakeRate_difeta_1->Write();
    DY_nTrk_bfakeRate_difeta_2->Write();
    DY_nTrk_cfakeRate_difeta_2->Write();
    DY_nTrk_lfakeRate_difeta_2->Write();
    DY_nTrk_hfakeRate_difeta_2->Write();
    DY_nTrk_fakeRate_difeta_2->Write();
    DY_nTrk_bfakeRate_difeta_3->Write();
    DY_nTrk_cfakeRate_difeta_3->Write();
    DY_nTrk_lfakeRate_difeta_3->Write();
    DY_nTrk_hfakeRate_difeta_3->Write();
    DY_nTrk_fakeRate_difeta_3->Write();
    DY_nTrk_bfakeRate->Write();
    DY_nTrk_cfakeRate->Write();
    DY_nTrk_lfakeRate->Write();
    DY_nTrk_hfakeRate->Write();
    DY_nTrk_fakeRate->Write();

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