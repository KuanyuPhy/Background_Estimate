#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <TROOT.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TLine.h>
#include "./../../lib/setNCUStyle.C"
#include "./met/tdrstyle.C"
#include "./met/CMS_lumi.C"
using namespace std;
// define punzi_eq
double punzi(double sigeff, double bg)
{
    return sigeff / (1 + TMath::Power(abs(bg), 0.5));
}

void ana_punzi()
{
    setTDRStyle();

    TFile *Sigfile = new TFile("./ee_Sig_punzi.root");
    TFile *Bgfile = new TFile("./ee_bgall_punzi.root");

    TH1D *h_Mx2_1_eff = ((TH1D *)Sigfile->Get("h_Mx2_1_eff"));
    TH1D *h_Mx2_50_eff = ((TH1D *)Sigfile->Get("h_Mx2_50_eff"));
    TH1D *h_Mx2_150_eff = ((TH1D *)Sigfile->Get("h_Mx2_150_eff"));
    TH1D *h_pass_Bg_nMetcut = ((TH1D *)Bgfile->Get("h_pass_Bg_nMetcut"));

    //-------------------------
    // CMS style
    //-------------------------
    writeExtraText = true;
    extraText = "Simulation";
    lumi_sqrtS = "13 TeV";

    // h_Mx2_1_eff->Draw();

    // double DY_nbg = h_pass_DY->GetBinContent(2);
    // cout << "DY_nbg =" << DY_nbg << endl;

    double Sig1_eff[50];
    double Sig50_eff[50];
    double Sig150_eff[50];

    double Sig1_punzi[50];
    double Sig50_punzi[50];
    double Sig150_punzi[50];
    for (int i = 1; i <= 50; i++)
    {
        Sig1_punzi[i] = punzi(h_Mx2_1_eff->GetBinContent(i + 1), h_pass_Bg_nMetcut->GetBinContent(i + 1));
        Sig50_punzi[i] = punzi(h_Mx2_50_eff->GetBinContent(i + 1), h_pass_Bg_nMetcut->GetBinContent(i + 1));
        Sig150_punzi[i] = punzi(h_Mx2_150_eff->GetBinContent(i + 1), h_pass_Bg_nMetcut->GetBinContent(i + 1));
        cout << "i =" << i << endl;
        cout << "Sig_eff =" << h_Mx2_1_eff->GetBinContent(i + 1) << endl;
    }

    TH1D *h_punzisig1 = new TH1D("h_punzisig1", "", 50, 0, 50);
    TH1D *h_punzisig50 = new TH1D("h_punzisig50", "", 50, 0, 50);
    TH1D *h_punzisig150 = new TH1D("h_punzisig150", "", 50, 0, 50);
    for (int i = 1; i <= 50; i++)
    {
        h_punzisig1->SetBinContent(i + 1, Sig1_punzi[i]);
        h_punzisig50->SetBinContent(i + 1, Sig50_punzi[i]);
        h_punzisig150->SetBinContent(i + 1, Sig150_punzi[i]);
    }
    h_punzisig1->SetLineWidth(2);
    h_punzisig50->SetLineWidth(2);
    h_punzisig150->SetLineWidth(2);

    h_punzisig1->SetLineColor(kRed);
    h_punzisig50->SetLineColor(kBlack);
    h_punzisig150->SetLineColor(kBlue);

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
    // auto c1 = new TCanvas("c", "BPRE");
    h_punzisig150->GetYaxis()->SetNdivisions(6, 5, 0);
    h_punzisig150->GetYaxis()->SetTitleOffset(1.5);
    h_punzisig150->GetYaxis()->SetTitle("punzi significance");
    h_punzisig150->GetYaxis()->SetTitleSize(0.04);
    h_punzisig150->GetYaxis()->SetLabelSize(0.04);
    h_punzisig150->GetXaxis()->SetNdivisions(6, 5, 0);
    h_punzisig150->GetXaxis()->SetTitle("MET cut");
    h_punzisig150->GetXaxis()->SetBinLabel(1, "MET > 10");
    // h_punzisig1->GetXaxis()->SetBinLabel(2, "Met > 20");
    // h_punzisig1->GetXaxis()->SetBinLabel(3, "Met > 30");
    // h_punzisig150->GetXaxis()->SetBinLabel(5, "Met > 50");
    h_punzisig150->GetXaxis()->SetBinLabel(12, "MET > 120");
    h_punzisig150->GetXaxis()->SetBinLabel(20, "MET > 200");
    h_punzisig150->GetXaxis()->SetBinLabel(30, "MET > 300");
    // h_punzisig150->GetXaxis()->SetBinLabel(40, "Met > 400");
    // h_punzisig150->GetXaxis()->SetBinLabel(45, "Met > 450");
    // h_punzisig150->GetXaxis()->SetBinLabel(50, "Met > 500");
    h_punzisig150->GetXaxis()->SetTitleSize(0.04);
    h_punzisig150->GetXaxis()->SetLabelSize(0.04);

    h_punzisig150->Draw();
    h_punzisig50->Draw("same");
    h_punzisig1->Draw("same");

    gStyle->SetOptStat(0);

    TLegend *l1 = new TLegend(0.55, 0.55, 0.9, 0.88);
    l1->SetHeader("Signal & 2016MC background");
    l1->SetBorderSize(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_punzisig1, "m_{x^{2}}=1 GeV ctau=1mm ", "l");
    l1->AddEntry(h_punzisig50, "m_{x^{2}}=50 GeV ctau=10mm ", "l");
    l1->AddEntry(h_punzisig150, "m_{x^{2}}=150 GeV ctau=1mm ", "l");
    // l1->AddEntry(h_TTTo2L2Nu_Median_2DIPsig, "Top process", "l");
    l1->Draw();
    c1->SetGrid();
    c1->SetGridx();
    c1->SetGridy();

    int iPeriod = 0;
    int iPos = 33;
    CMS_lumi(c1, iPeriod, iPos);
    c1->Update();
    c1->RedrawAxis();
    TString canvName = "2016MCbg_Met";

    // c1->Update();
    c1->SaveAs("tmp.png");
}