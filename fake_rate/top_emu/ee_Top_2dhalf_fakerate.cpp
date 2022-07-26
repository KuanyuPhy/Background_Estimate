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
#include "./../../../../lib/Cross_section.h"
using namespace std;
void ee_Top_2dhalf_fakerate(TString file = "top_all.root", TString outputfile = "top_fakerate.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *h_Top_nTrk_bjet = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet"));
    //TH1D *h_Top_nTrk_bjet_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_bjet_cut"));
    //TH1D *h_Top_nTrk_cjet = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet"));
    //TH1D *h_Top_nTrk_cjet_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_cjet_cut"));
    //TH1D *h_Top_nTrk_ljet = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet"));
    //TH1D *h_Top_nTrk_ljet_cut = ((TH1D *)Topfile->Get("h_Top_nTrk_ljet_cut"));

    TH1D *h_Top_eta_bjet = ((TH1D *)Topfile->Get("h_Top_eta_bjet"));
    //TH1D *h_Top_eta_bjet_cut = ((TH1D *)Topfile->Get("h_Top_eta_bjet_cut"));
    //TH1D *h_Top_eta_cjet = ((TH1D *)Topfile->Get("h_Top_eta_cjet"));
    //TH1D *h_Top_eta_cjet_cut = ((TH1D *)Topfile->Get("h_Top_eta_cjet_cut"));
    //TH1D *h_Top_eta_ljet = ((TH1D *)Topfile->Get("h_Top_eta_ljet"));
    //TH1D *h_Top_eta_ljet_cut = ((TH1D *)Topfile->Get("h_Top_eta_ljet_cut"));

    /*
    //---------------------
    // Calculate fake rate
    //---------------------
    TH1D *Top_nTrk_bfakeRate = (TH1D *)h_Top_nTrk_bjet_cut->Clone("Top_nTrk_bfakeRate");
    Top_nTrk_bfakeRate->Divide(h_Top_nTrk_bjet_cut, h_Top_nTrk_bjet, 1, 1, "b");
    TH1D *Top_nTrk_cfakeRate = (TH1D *)h_Top_nTrk_cjet_cut->Clone("Top_nTrk_cfakeRate");
    Top_nTrk_cfakeRate->Divide(h_Top_nTrk_cjet_cut, h_Top_nTrk_cjet, 1, 1, "b");
    TH1D *Top_nTrk_lfakeRate = (TH1D *)h_Top_nTrk_ljet_cut->Clone("Top_nTrk_lfakeRate");
    Top_nTrk_lfakeRate->Divide(h_Top_nTrk_ljet_cut, h_Top_nTrk_ljet, 1, 1, "b");

    TH1D *Top_eta_bfakeRate = (TH1D *)h_Top_eta_bjet_cut->Clone("Top_eta_bfakeRate");
    Top_eta_bfakeRate->Divide(h_Top_eta_bjet_cut, h_Top_eta_bjet, 1, 1, "b");
    TH1D *Top_eta_cfakeRate = (TH1D *)h_Top_eta_cjet_cut->Clone("Top_eta_cfakeRate");
    Top_eta_cfakeRate->Divide(h_Top_eta_cjet_cut, h_Top_eta_cjet, 1, 1, "b");
    TH1D *Top_eta_lfakeRate = (TH1D *)h_Top_eta_ljet_cut->Clone("Top_eta_lfakeRate");
    Top_eta_lfakeRate->Divide(h_Top_eta_ljet_cut, h_Top_eta_ljet, 1, 1, "b");
    */
    //------------------------
    // Read TH2D
    //------------------------
    TH2D *h_Top_nTrk_eta_bjet = ((TH2D *)Topfile->Get("h_Top_nTrk_eta_bjet"));
    TH2D *h_Top_nTrk_eta_bjet_cut = ((TH2D *)Topfile->Get("h_Top_nTrk_eta_bjet_cut"));
    TH2D *h_Top_nTrk_eta_cjet = ((TH2D *)Topfile->Get("h_Top_nTrk_eta_cjet"));
    TH2D *h_Top_nTrk_eta_cjet_cut = ((TH2D *)Topfile->Get("h_Top_nTrk_eta_cjet_cut"));
    TH2D *h_Top_nTrk_eta_ljet = ((TH2D *)Topfile->Get("h_Top_nTrk_eta_ljet"));
    TH2D *h_Top_nTrk_eta_ljet_cut = ((TH2D *)Topfile->Get("h_Top_nTrk_eta_ljet_cut"));

    TH2D *h_Top_nTrk_eta_bfakerate = new TH2D("h_Top_nTrk_eta_bfakerate", "", 30, 1, 30, 30, -3.0, 3.0);
    h_Top_nTrk_eta_bfakerate->Sumw2();
    TH2D *h_Top_nTrk_eta_cfakerate = new TH2D("h_Top_nTrk_eta_cfakerate", "", 30, 1, 30, 30, -3.0, 3.0);
    h_Top_nTrk_eta_cfakerate->Sumw2();
    TH2D *h_Top_nTrk_eta_lfakerate = new TH2D("h_Top_nTrk_eta_lfakerate", "", 30, 1, 30, 30, -3.0, 3.0);
    h_Top_nTrk_eta_lfakerate->Sumw2();

    int nbinx = h_Top_nTrk_eta_bjet->GetNbinsX();
    int nbiny = h_Top_nTrk_eta_bjet->GetNbinsY();

    cout << "nbinx = " << nbinx << endl;
    for (int i = 1; i <= nbinx; i++)
    {
        for (int j = 1; j <= nbiny; j++)
        {
            double b_fakerate;
            double c_fakerate;
            double l_fakerate;
            b_fakerate = h_Top_nTrk_eta_bjet_cut->GetBinContent(i, j) / h_Top_nTrk_eta_bjet->GetBinContent(i, j);
            c_fakerate = h_Top_nTrk_eta_cjet_cut->GetBinContent(i, j) / h_Top_nTrk_eta_cjet->GetBinContent(i, j);
            l_fakerate = h_Top_nTrk_eta_ljet_cut->GetBinContent(i, j) / h_Top_nTrk_eta_ljet->GetBinContent(i, j);
            if (h_Top_nTrk_eta_bjet->GetBinContent(i, j) == 0)
            {
                b_fakerate = 0;
            }
            if (h_Top_nTrk_eta_cjet->GetBinContent(i, j) == 0)
            {
                c_fakerate = 0;
            }
            if (h_Top_nTrk_eta_ljet->GetBinContent(i, j) == 0)
            {
                l_fakerate = 0;
            }
            h_Top_nTrk_eta_bfakerate->SetBinContent(i, j, b_fakerate);
            h_Top_nTrk_eta_cfakerate->SetBinContent(i, j, c_fakerate);
            h_Top_nTrk_eta_lfakerate->SetBinContent(i, j, l_fakerate);
        }
    }

    auto c1 = new TCanvas("c1", "");
    c1->Divide(3, 1);
    c1->cd(1);
    h_Top_nTrk_eta_cjet->Draw("COLZ text");
    c1->cd(2);
    h_Top_nTrk_eta_cjet_cut->Draw("COLZ text");
    c1->cd(3);
    h_Top_nTrk_eta_cfakerate->Draw("COLZ text");

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    h_Top_nTrk_eta_bfakerate->Write();
    h_Top_nTrk_eta_cfakerate->Write();
    h_Top_nTrk_eta_lfakerate->Write();
    h_Top_nTrk_bjet->Write();
    h_Top_eta_bjet->Write();
    outfile->Close();
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_Top_2dhalf_fakerate();
    }
    else if (argc == 3)
    {
        ee_Top_2dhalf_fakerate(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}