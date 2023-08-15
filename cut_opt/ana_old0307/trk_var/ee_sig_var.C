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
#include </home/kuanyu/Documents/CMS/Background_Estimate/lib/tdrstyle.C>
#include </home/kuanyu/Documents/CMS/Background_Estimate/lib/CMS_lumi.h>
using namespace std;
void ee_sig_var()
{
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_1_old_remove_0alpha.root");
    TFile *Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_50_old_remove_0alpha.root");
    TFile *Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_150_old_remove_0alpha.root");

    TFile *Mx2_1_matchdd = new TFile("/home/kuanyu/Documents/root_file/Ztoee/ee_Mx2_1_old_remove_0alpha_matchdd.root");

    TH1D *h_Mx2_1_alpha = new TH1D("h_Mx2_1_alpha", "", 20, 0., 1.);
    h_Mx2_1_alpha->Sumw2();

    TH1D *h_Mx2_50_alpha = new TH1D("h_Mx2_50_alpha", "", 20, 0., 1.);
    h_Mx2_50_alpha->Sumw2();

    TH1D *h_Mx2_150_alpha = new TH1D("h_Mx2_150_alpha", "", 20, 0., 1.);
    h_Mx2_150_alpha->Sumw2();

    TH1D *h_Mx2_1_dzerror = new TH1D("h_Mx2_1_dzerror", "", 30, 0., 3.);
    h_Mx2_1_dzerror->Sumw2();

    TH1D *h_Mx2_50_dzerror = new TH1D("h_Mx2_50_dzerror", "", 30, 0., 3.);
    h_Mx2_50_dzerror->Sumw2();

    TH1D *h_Mx2_150_dzerror = new TH1D("h_Mx2_150_dzerror", "", 30, 0., 3.);
    h_Mx2_150_dzerror->Sumw2();

    TH1D *h_Mx2_1_dxyerror = new TH1D("h_Mx2_1_dxyerror", "", 30, 0., 3.);
    h_Mx2_1_dxyerror->Sumw2();

    TH1D *h_Mx2_50_dxyerror = new TH1D("h_Mx2_50_dxyerror", "", 30, 0., 3.);
    h_Mx2_50_dxyerror->Sumw2();

    TH1D *h_Mx2_150_dxyerror = new TH1D("h_Mx2_150_dxyerror", "", 30, 0., 3.);
    h_Mx2_150_dxyerror->Sumw2();

    TH1D *h_Mx2_1_dz = new TH1D("h_Mx2_1_dz", "", 600, -30., 30.);
    h_Mx2_1_dz->Sumw2();

    TH1D *h_Mx2_50_dz = new TH1D("h_Mx2_50_dz", "", 600, -30., 30.);
    h_Mx2_50_dz->Sumw2();

    TH1D *h_Mx2_150_dz = new TH1D("h_Mx2_150_dz", "", 600, -30., 30.);
    h_Mx2_150_dz->Sumw2();

    TH1D *h_Mx2_1_dxy = new TH1D("h_Mx2_1_dxy", "", 600, -60., 50.);
    h_Mx2_1_dxy->Sumw2();

    TH1D *h_Mx2_50_dxy = new TH1D("h_Mx2_50_dxy", "", 600, -60., 50.);
    h_Mx2_50_dxy->Sumw2();

    TH1D *h_Mx2_150_dxy = new TH1D("h_Mx2_150_dxy", "", 600, -60., 50.);
    h_Mx2_150_dxy->Sumw2();

    TH1D *h_Mx2_1_dxy_matchdd = new TH1D("h_Mx2_1_dxy_matchdd", "", 100, -30., 30.);
    h_Mx2_1_dxy_matchdd->Sumw2();

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    Int_t I_Mx1_weight_matchdd, I_Mx50_weight_matchdd, I_Mx150_weight_matchdd;

    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;

    Int_t I_Mx1_nThinJets, I_Mx50_nThinJets, I_Mx150_nThinJets;

    vector<float> *v_Mx1_alpha = new vector<float>();
    vector<float> *v_Mx50_alpha = new vector<float>();
    vector<float> *v_Mx150_alpha = new vector<float>();

    v_Mx1_alpha->clear();
    v_Mx50_alpha->clear();
    v_Mx150_alpha->clear();

    vector<float> *v_Mx1_alpha2 = new vector<float>();
    vector<float> *v_Mx50_alpha2 = new vector<float>();
    vector<float> *v_Mx150_alpha2 = new vector<float>();

    v_Mx1_alpha2->clear();
    v_Mx50_alpha2->clear();
    v_Mx150_alpha2->clear();

    vector<float> *v_Mx1_alpha3 = new vector<float>();
    vector<float> *v_Mx50_alpha3 = new vector<float>();
    vector<float> *v_Mx150_alpha3 = new vector<float>();

    v_Mx1_alpha3->clear();
    v_Mx50_alpha3->clear();
    v_Mx150_alpha3->clear();

    vector<float> *v_Mx1_alpha4 = new vector<float>();
    vector<float> *v_Mx50_alpha4 = new vector<float>();
    vector<float> *v_Mx150_alpha4 = new vector<float>();

    v_Mx1_alpha4->clear();
    v_Mx50_alpha4->clear();
    v_Mx150_alpha4->clear();

    vector<float> *v_Mx1_2Dsig = new vector<float>();
    vector<float> *v_Mx50_2Dsig = new vector<float>();
    vector<float> *v_Mx150_2Dsig = new vector<float>();

    v_Mx1_2Dsig->clear();
    v_Mx50_2Dsig->clear();
    v_Mx150_2Dsig->clear();

    vector<float> *v_Mx1_3Dsig = new vector<float>();
    vector<float> *v_Mx50_3Dsig = new vector<float>();
    vector<float> *v_Mx150_3Dsig = new vector<float>();

    v_Mx1_3Dsig->clear();
    v_Mx50_3Dsig->clear();
    v_Mx150_3Dsig->clear();

    vector<float> *v_Mx1_dzerror = new vector<float>();
    vector<float> *v_Mx50_dzerror = new vector<float>();
    vector<float> *v_Mx150_dzerror = new vector<float>();

    v_Mx1_dzerror->clear();
    v_Mx50_dzerror->clear();
    v_Mx150_dzerror->clear();

    vector<float> *v_Mx1_dxyerror = new vector<float>();
    vector<float> *v_Mx50_dxyerror = new vector<float>();
    vector<float> *v_Mx150_dxyerror = new vector<float>();

    v_Mx1_dxyerror->clear();
    v_Mx50_dxyerror->clear();
    v_Mx150_dxyerror->clear();

    vector<float> *v_Mx1_dz = new vector<float>();
    vector<float> *v_Mx50_dz = new vector<float>();
    vector<float> *v_Mx150_dz = new vector<float>();

    v_Mx1_dz->clear();
    v_Mx50_dz->clear();
    v_Mx150_dz->clear();

    vector<float> *v_Mx1_dxy = new vector<float>();
    vector<float> *v_Mx50_dxy = new vector<float>();
    vector<float> *v_Mx150_dxy = new vector<float>();

    v_Mx1_dxy->clear();
    v_Mx50_dxy->clear();
    v_Mx150_dxy->clear();

    vector<float> *v_Mx1_dxy_matchdd = new vector<float>();
    vector<float> *v_Mx50_dxy_matchdd = new vector<float>();
    vector<float> *v_Mx150_dxy_matchdd = new vector<float>();

    v_Mx1_dxy_matchdd->clear();
    v_Mx50_dxy_matchdd->clear();
    v_Mx150_dxy_matchdd->clear();

    // visualize the fitting result
    setTDRStyle();
    TCanvas *canv = new TCanvas("canv", "canv", 800, 700);
    canv->cd();
    canv->SetRightMargin(0.08);
    canv->SetBottomMargin(0.12);
    canv->SetTopMargin(0.07);
    canv->SetLeftMargin(0.12);

    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);

    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    pad1->SetGridx();         // Vertical grid
    pad1->Draw();             // Draw the upper pad: pad1

    double METcut = 0.;
    TTree *T_Mx2_1;
    Mx2_1->GetObject("T_tree", T_Mx2_1);
    T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
    T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
    T_Mx2_1->SetBranchAddress("v_Chi3Dlog", &v_Mx1_3Dsig);
    T_Mx2_1->SetBranchAddress("v_IP2D", &v_Mx1_2Dsig);
    T_Mx2_1->SetBranchAddress("v_Trk_dzerror", &v_Mx1_dzerror);
    T_Mx2_1->SetBranchAddress("v_Trk_dxyerror", &v_Mx1_dxyerror);
    T_Mx2_1->SetBranchAddress("v_Trk_dz", &v_Mx1_dz);
    T_Mx2_1->SetBranchAddress("v_Trk_dxy", &v_Mx1_dxy);
    T_Mx2_1->SetBranchAddress("v_fakealpha", &v_Mx1_alpha);
    T_Mx2_1->SetBranchAddress("v_fakealpha2", &v_Mx1_alpha2);
    T_Mx2_1->SetBranchAddress("v_fakealpha3", &v_Mx1_alpha3);
    T_Mx2_1->SetBranchAddress("v_fakealpha4", &v_Mx1_alpha4);
    for (int evt = 0; evt < T_Mx2_1->GetEntries(); evt++)
    {
        T_Mx2_1->GetEntry(evt);
        for (size_t itk = 0; itk < v_Mx1_dzerror->size(); itk++)
        {
            h_Mx2_1_dzerror->Fill((*v_Mx1_dzerror)[itk], I_Mx1_weight);
        }
        for (size_t itk = 0; itk < v_Mx1_dxyerror->size(); itk++)
        {
            h_Mx2_1_dxyerror->Fill((*v_Mx1_dxyerror)[itk], I_Mx1_weight);
        }
        for (size_t itk = 0; itk < v_Mx1_dz->size(); itk++)
        {
            h_Mx2_1_dz->Fill((*v_Mx1_dz)[itk], I_Mx1_weight);
        }
        for (size_t itk = 0; itk < v_Mx1_dxy->size(); itk++)
        {
            h_Mx2_1_dxy->Fill((*v_Mx1_dxy)[itk], I_Mx1_weight);
        }

    } // End of Mx2_1 Entries loop
    TTree *T_Mx2_50;
    Mx2_50->GetObject("T_tree", T_Mx2_50);
    T_Mx2_50->SetBranchAddress("I_weight", &I_Mx50_weight);
    T_Mx2_50->SetBranchAddress("f_Met", &f_Mx50_Met);
    T_Mx2_50->SetBranchAddress("v_Chi3Dlog", &v_Mx50_3Dsig);
    T_Mx2_50->SetBranchAddress("v_IP2D", &v_Mx50_2Dsig);
    T_Mx2_50->SetBranchAddress("v_Trk_dzerror", &v_Mx50_dzerror);
    T_Mx2_50->SetBranchAddress("v_Trk_dxyerror", &v_Mx50_dxyerror);
    T_Mx2_50->SetBranchAddress("v_Trk_dz", &v_Mx50_dz);
    T_Mx2_50->SetBranchAddress("v_Trk_dxy", &v_Mx50_dxy);
    T_Mx2_50->SetBranchAddress("v_fakealpha", &v_Mx50_alpha);
    T_Mx2_50->SetBranchAddress("v_fakealpha2", &v_Mx50_alpha2);
    T_Mx2_50->SetBranchAddress("v_fakealpha3", &v_Mx50_alpha3);
    T_Mx2_50->SetBranchAddress("v_fakealpha4", &v_Mx50_alpha4);
    for (int evt = 0; evt < T_Mx2_50->GetEntries(); evt++)
    {
        T_Mx2_50->GetEntry(evt);
        for (size_t itk = 0; itk < v_Mx50_dzerror->size(); itk++)
        {
            h_Mx2_50_dzerror->Fill((*v_Mx50_dzerror)[itk], I_Mx50_weight);
        }
        for (size_t itk = 0; itk < v_Mx50_dxyerror->size(); itk++)
        {
            h_Mx2_50_dxyerror->Fill((*v_Mx50_dxyerror)[itk], I_Mx50_weight);
        }
        for (size_t itk = 0; itk < v_Mx50_dz->size(); itk++)
        {
            h_Mx2_50_dz->Fill((*v_Mx50_dz)[itk], I_Mx50_weight);
        }
        for (size_t itk = 0; itk < v_Mx50_dxy->size(); itk++)
        {
            h_Mx2_50_dxy->Fill((*v_Mx50_dxy)[itk], I_Mx50_weight);
        }

    } // End of Mx2_50 Entries loop
    TTree *T_Mx2_150;
    Mx2_150->GetObject("T_tree", T_Mx2_150);
    T_Mx2_150->SetBranchAddress("I_weight", &I_Mx150_weight);
    T_Mx2_150->SetBranchAddress("f_Met", &f_Mx150_Met);
    T_Mx2_150->SetBranchAddress("v_Chi3Dlog", &v_Mx150_3Dsig);
    T_Mx2_150->SetBranchAddress("v_IP2D", &v_Mx150_2Dsig);
    T_Mx2_150->SetBranchAddress("v_Trk_dzerror", &v_Mx150_dzerror);
    T_Mx2_150->SetBranchAddress("v_Trk_dxyerror", &v_Mx150_dxyerror);
    T_Mx2_150->SetBranchAddress("v_Trk_dz", &v_Mx150_dz);
    T_Mx2_150->SetBranchAddress("v_Trk_dxy", &v_Mx150_dxy);
    T_Mx2_150->SetBranchAddress("v_fakealpha", &v_Mx150_alpha);
    T_Mx2_150->SetBranchAddress("v_fakealpha2", &v_Mx150_alpha2);
    T_Mx2_150->SetBranchAddress("v_fakealpha3", &v_Mx150_alpha3);
    T_Mx2_150->SetBranchAddress("v_fakealpha4", &v_Mx150_alpha4);
    for (int evt = 0; evt < T_Mx2_150->GetEntries(); evt++)
    {
        T_Mx2_150->GetEntry(evt);

        for (size_t itk = 0; itk < v_Mx150_dzerror->size(); itk++)
        {
            h_Mx2_150_dzerror->Fill((*v_Mx150_dzerror)[itk], I_Mx150_weight);
        }
        for (size_t itk = 0; itk < v_Mx150_dxyerror->size(); itk++)
        {
            h_Mx2_150_dxyerror->Fill((*v_Mx150_dxyerror)[itk], I_Mx150_weight);
        }
        for (size_t itk = 0; itk < v_Mx150_dz->size(); itk++)
        {
            h_Mx2_150_dz->Fill((*v_Mx150_dz)[itk], I_Mx150_weight);
        }
        for (size_t itk = 0; itk < v_Mx150_dxy->size(); itk++)
        {
            h_Mx2_150_dxy->Fill((*v_Mx150_dxy)[itk], I_Mx150_weight);
        }

    } // End of Mx2_150 Entries loop

    TTree *T_Mx2_1_matchdd;
    Mx2_1_matchdd->GetObject("T_tree", T_Mx2_1_matchdd);
    T_Mx2_1_matchdd->SetBranchAddress("I_weight", &I_Mx1_weight_matchdd);
    // T_Mx2_1_matchdd->SetBranchAddress("f_Met", &f_Mx1_Met);
    // T_Mx2_1_matchdd->SetBranchAddress("v_Chi3Dlog", &v_Mx1_3Dsig);
    // T_Mx2_1_matchdd->SetBranchAddress("v_IP2D", &v_Mx1_2Dsig);
    // T_Mx2_1_matchdd->SetBranchAddress("v_Trk_dzerror", &v_Mx1_dzerror);
    // T_Mx2_1_matchdd->SetBranchAddress("v_Trk_dxyerror", &v_Mx1_dxyerror);
    // T_Mx2_1_matchdd->SetBranchAddress("v_Trk_dz", &v_Mx1_dz);
    T_Mx2_1_matchdd->SetBranchAddress("v_Trk_dxy", &v_Mx1_dxy_matchdd);
    // T_Mx2_1_matchdd->SetBranchAddress("v_fakealpha", &v_Mx1_alpha);
    // T_Mx2_1_matchdd->SetBranchAddress("v_fakealpha2", &v_Mx1_alpha2);
    // T_Mx2_1_matchdd->SetBranchAddress("v_fakealpha3", &v_Mx1_alpha3);
    // T_Mx2_1_matchdd->SetBranchAddress("v_fakealpha4", &v_Mx1_alpha4);
    for (int evt = 0; evt < T_Mx2_1_matchdd->GetEntries(); evt++)
    {
        T_Mx2_1_matchdd->GetEntry(evt);
        /*for (size_t itk = 0; itk < v_Mx1_dzerror->size(); itk++)
        {
            h_Mx2_1_dzerror->Fill((*v_Mx1_dzerror)[itk], I_Mx1_weight);
        }
        for (size_t itk = 0; itk < v_Mx1_dxyerror->size(); itk++)
        {
            h_Mx2_1_dxyerror->Fill((*v_Mx1_dxyerror)[itk], I_Mx1_weight);
        }
        for (size_t itk = 0; itk < v_Mx1_dz->size(); itk++)
        {
            h_Mx2_1_dz->Fill((*v_Mx1_dz)[itk], I_Mx1_weight);
        }
        */
        for (size_t itk = 0; itk < v_Mx1_dxy_matchdd->size(); itk++)
        {
            h_Mx2_1_dxy_matchdd->Fill((*v_Mx1_dxy_matchdd)[itk], I_Mx1_weight_matchdd);
        }
    }

    h_Mx2_150_dzerror->GetXaxis()->SetTitleSize(0.045);
    h_Mx2_150_dzerror->GetXaxis()->SetLabelSize(0.045);
    h_Mx2_150_dzerror->GetXaxis()->SetLabelOffset(0.02);
    h_Mx2_150_dzerror->GetXaxis()->SetTitleOffset(1.3);
    h_Mx2_150_dzerror->GetYaxis()->SetTitleSize(0.045);
    h_Mx2_150_dzerror->GetYaxis()->SetLabelSize(0.045);
    h_Mx2_150_dzerror->GetYaxis()->SetTitleOffset(1.3);
    h_Mx2_150_dzerror->GetYaxis()->SetTitle("nTrack");
    h_Mx2_150_dzerror->GetXaxis()->SetTitle("dz_{error}");

    h_Mx2_150_dxyerror->GetXaxis()->SetTitleSize(0.045);
    h_Mx2_150_dxyerror->GetXaxis()->SetLabelSize(0.045);
    h_Mx2_150_dxyerror->GetXaxis()->SetLabelOffset(0.02);
    h_Mx2_150_dxyerror->GetXaxis()->SetTitleOffset(1.3);
    h_Mx2_150_dxyerror->GetYaxis()->SetTitleSize(0.045);
    h_Mx2_150_dxyerror->GetYaxis()->SetLabelSize(0.045);
    h_Mx2_150_dxyerror->GetYaxis()->SetTitleOffset(1.3);
    h_Mx2_150_dxyerror->GetYaxis()->SetTitle("nTrack");
    h_Mx2_150_dxyerror->GetXaxis()->SetTitle("dxy_{error}");

    h_Mx2_150_dz->GetXaxis()->SetTitleSize(0.045);
    h_Mx2_150_dz->GetXaxis()->SetLabelSize(0.045);
    h_Mx2_150_dz->GetXaxis()->SetLabelOffset(0.02);
    h_Mx2_150_dz->GetXaxis()->SetTitleOffset(1.3);
    h_Mx2_150_dz->GetYaxis()->SetTitleSize(0.045);
    h_Mx2_150_dz->GetYaxis()->SetLabelSize(0.045);
    h_Mx2_150_dz->GetYaxis()->SetTitleOffset(1.4);
    h_Mx2_150_dz->GetYaxis()->SetTitle("nTrack");
    h_Mx2_150_dz->GetXaxis()->SetTitle("dz (cm)");

    h_Mx2_150_dxy->GetXaxis()->SetTitleSize(0.045);
    h_Mx2_150_dxy->GetXaxis()->SetLabelSize(0.045);
    h_Mx2_150_dxy->GetXaxis()->SetLabelOffset(0.02);
    h_Mx2_150_dxy->GetXaxis()->SetTitleOffset(1.3);
    h_Mx2_150_dxy->GetYaxis()->SetTitleSize(0.045);
    h_Mx2_150_dxy->GetYaxis()->SetLabelSize(0.045);
    h_Mx2_150_dxy->GetYaxis()->SetTitleOffset(1.4);
    h_Mx2_150_dxy->GetYaxis()->SetTitle("nTrack");
    h_Mx2_150_dxy->GetXaxis()->SetTitle("dxy (cm)");

    h_Mx2_1_dzerror->SetLineColor(kRed);
    h_Mx2_50_dzerror->SetLineColor(kGray + 2);
    h_Mx2_150_dzerror->SetLineColor(kBlue);

    h_Mx2_1_dxyerror->SetLineColor(kRed);
    h_Mx2_50_dxyerror->SetLineColor(kGray + 2);
    h_Mx2_150_dxyerror->SetLineColor(kBlue);

    h_Mx2_1_dz->SetLineColor(kRed);
    h_Mx2_50_dz->SetLineColor(kGray + 2);
    h_Mx2_150_dz->SetLineColor(kBlue);

    h_Mx2_1_dxy->SetLineColor(kRed);
    h_Mx2_50_dxy->SetLineColor(kGray + 2);
    h_Mx2_150_dxy->SetLineColor(kBlue);

    h_Mx2_1_dzerror->SetLineWidth(2);
    h_Mx2_50_dzerror->SetLineWidth(2);
    h_Mx2_150_dzerror->SetLineWidth(2);

    h_Mx2_1_dxyerror->SetLineWidth(2);
    h_Mx2_50_dxyerror->SetLineWidth(2);
    h_Mx2_150_dxyerror->SetLineWidth(2);

    h_Mx2_1_dz->SetLineWidth(2);
    h_Mx2_50_dz->SetLineWidth(2);
    h_Mx2_150_dz->SetLineWidth(2);

    h_Mx2_1_dxy->SetLineWidth(2);
    h_Mx2_50_dxy->SetLineWidth(2);
    h_Mx2_150_dxy->SetLineWidth(2);

    //h_Mx2_150_dxy->GetXaxis()->SetRangeUser(-2., 2.);
    //h_Mx2_150_dz->GetXaxis()->SetRangeUser(-2., 2.);
    
    /*

    h_Mx2_150_dzerror->Draw();
    h_Mx2_50_dzerror->Draw("same");
    h_Mx2_1_dzerror->Draw("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_dzerror, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_dzerror, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_dzerror, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */
    /*
    h_Mx2_150_dxyerror->Draw();
    h_Mx2_50_dxyerror->Draw("same");
    h_Mx2_1_dxyerror->Draw("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_dxyerror, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_dxyerror, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_dxyerror, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */
    

    /*
    h_Mx2_150_dxy->Draw();
    h_Mx2_50_dxy->Draw("same");
    h_Mx2_1_dxy->Draw("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_dxy, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_dxy, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_dxy, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    
    */

    /*
    h_Mx2_150_dz->Draw();
    h_Mx2_50_dz->Draw("same");
    h_Mx2_1_dz->Draw("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_dz, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_dz, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_dz, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */

    h_Mx2_1_dzerror->Draw();

    gStyle->SetOptStat(1111);

    /*Compare match dd trk*/

    h_Mx2_1_dxy_matchdd->SetLineWidth(2);
    h_Mx2_1_dxy->SetLineWidth(2);

    h_Mx2_1_dxy_matchdd->SetLineColor(kRed);
    // h_Mx2_1_dxy->SetLineColor(kBlue);

    /*
    h_Mx2_1_dxy_matchdd->DrawNormalized();
    h_Mx2_1_dxy->DrawNormalized("same");
    */
    gPad->SetLogy();

    CMS_lumi((TPad *)canv, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");

    TString outputfile1 = "./ee_Sig.root";
    TFile *outfile_HT0 = TFile::Open(outputfile1, "RECREATE");
    h_Mx2_1_dzerror->Write();
    h_Mx2_50_dzerror->Write();
    h_Mx2_150_dzerror->Write();
    h_Mx2_1_dxyerror->Write();
    h_Mx2_50_dxyerror->Write();
    h_Mx2_150_dxyerror->Write();

    outfile_HT0->Close();
}