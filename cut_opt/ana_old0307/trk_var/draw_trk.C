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
void draw_trk()
{
    TFile *Mx2_1 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/new/ee_Mx2_1_old_remove_0alpha.root");
    TFile *Mx2_50 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/new/ee_Mx2_50_old_remove_0alpha.root");
    TFile *Mx2_150 = new TFile("/home/kuanyu/Documents/root_file/Ztoee/new/ee_Mx2_150_old_remove_0alpha.root");
    TFile *Top_file = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/cut_opt/ana_old0307/trk_var/top/ee_Top_alpha.root", "Read");
    if (!Top_file || Top_file->IsZombie())
    {
        std::cerr << "Error: Cannot open file\n";
    }
    /*Get TH1D*/
    TH1D *h_Top_dz = (TH1D *)Top_file->Get("h_Top_dz");
    TH1D *h_Top_dxy = (TH1D *)Top_file->Get("h_Top_dxy");
    TH1D *h_Top_dzerr = (TH1D *)Top_file->Get("h_Top_dzerr");
    TH1D *h_Top_dxyerr = (TH1D *)Top_file->Get("h_Top_dxyerr");

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

    TH1D *h_Mx2_1_dz = new TH1D("h_Mx2_1_dz", "", 600, -60., 50.);
    h_Mx2_1_dz->Sumw2();

    TH1D *h_Mx2_50_dz = new TH1D("h_Mx2_50_dz", "", 600, -60., 50.);
    h_Mx2_50_dz->Sumw2();

    TH1D *h_Mx2_150_dz = new TH1D("h_Mx2_150_dz", "", 600, -60., 50.);
    h_Mx2_150_dz->Sumw2();

    TH1D *h_Mx2_1_dxy = new TH1D("h_Mx2_1_dxy", "", 600, -60., 50.);
    h_Mx2_1_dxy->Sumw2();

    TH1D *h_Mx2_50_dxy = new TH1D("h_Mx2_50_dxy", "", 600, -60., 50.);
    h_Mx2_50_dxy->Sumw2();

    TH1D *h_Mx2_150_dxy = new TH1D("h_Mx2_150_dxy", "", 600, -60., 50.);
    h_Mx2_150_dxy->Sumw2();

    TH1D *h_Mx2_1_TrkXYresolu = new TH1D("h_Mx2_1_TrkXYresolu", "", 1200, 0., 3000);
    h_Mx2_1_TrkXYresolu->Sumw2();

    TH1D *h_Mx2_50_TrkXYresolu = new TH1D("h_Mx2_50_TrkXYresolu", "", 1200, 0., 3000);
    h_Mx2_50_TrkXYresolu->Sumw2();

    TH1D *h_Mx2_150_TrkXYresolu = new TH1D("h_Mx2_150_TrkXYresolu", "", 1200, 0., 3000);
    h_Mx2_150_TrkXYresolu->Sumw2();

    TH1D *h_Mx2_1_TrkXYresolu_comp = new TH1D("h_Mx2_1_TrkXYresolu_comp", "", 1200, 0., 3000);
    h_Mx2_1_TrkXYresolu_comp->Sumw2();

    TH1D *h_Mx2_50_TrkXYresolu_comp = new TH1D("h_Mx2_50_TrkXYresolu_comp", "", 1200, 0., 3000);
    h_Mx2_50_TrkXYresolu_comp->Sumw2();

    TH1D *h_Mx2_150_TrkXYresolu_comp = new TH1D("h_Mx2_150_TrkXYresolu_comp", "", 1200, 0., 3000);
    h_Mx2_150_TrkXYresolu_comp->Sumw2();

    Int_t I_Mx1_weight, I_Mx50_weight, I_Mx150_weight;

    float_t f_Mx1_Met, f_Mx50_Met, f_Mx150_Met;

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

    vector<double> *v_Mx1_TrkXYresolu = new vector<double>();
    vector<double> *v_Mx50_TrkXYresolu = new vector<double>();
    vector<double> *v_Mx150_TrkXYresolu = new vector<double>();

    v_Mx1_TrkXYresolu->clear();
    v_Mx50_TrkXYresolu->clear();
    v_Mx150_TrkXYresolu->clear();

    vector<double> *v_Mx1_Trkpt = new vector<double>();
    vector<double> *v_Mx50_Trkpt = new vector<double>();
    vector<double> *v_Mx150_Trkpt = new vector<double>();

    v_Mx1_Trkpt->clear();
    v_Mx50_Trkpt->clear();
    v_Mx150_Trkpt->clear();

    vector<double> *v_Mx1_TrkEta = new vector<double>();
    vector<double> *v_Mx50_TrkEta = new vector<double>();
    vector<double> *v_Mx150_TrkEta = new vector<double>();

    v_Mx1_TrkEta->clear();
    v_Mx50_TrkEta->clear();
    v_Mx150_TrkEta->clear();

    double METcut = 0.;

    TTree *T_Mx2_1;
    Mx2_1->GetObject("T_tree", T_Mx2_1);
    T_Mx2_1->SetBranchAddress("I_weight", &I_Mx1_weight);
    T_Mx2_1->SetBranchAddress("f_Met", &f_Mx1_Met);
    T_Mx2_1->SetBranchAddress("v_Trk_dzerror", &v_Mx1_dzerror);
    T_Mx2_1->SetBranchAddress("v_Trk_dxyerror", &v_Mx1_dxyerror);
    T_Mx2_1->SetBranchAddress("v_Trk_dz", &v_Mx1_dz);
    T_Mx2_1->SetBranchAddress("v_Trk_dxy", &v_Mx1_dxy);
    T_Mx2_1->SetBranchAddress("v_TrkXYresolu", &v_Mx1_TrkXYresolu);
    T_Mx2_1->SetBranchAddress("v_TrkPT", &v_Mx1_Trkpt);
    T_Mx2_1->SetBranchAddress("v_TrkEta", &v_Mx1_TrkEta);
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
        for (size_t itrk = 0; itrk < v_Mx1_TrkXYresolu->size(); itrk++)
        {
            h_Mx2_1_TrkXYresolu->Fill((*v_Mx1_TrkXYresolu)[itrk], I_Mx1_weight);

            if ((*v_Mx1_Trkpt)[itrk] < 10 && abs((*v_Mx1_TrkEta)[itrk]) < 1.4)
            {
                h_Mx2_1_TrkXYresolu_comp->Fill((*v_Mx1_TrkXYresolu)[itrk], I_Mx1_weight);
            }
        }

    } // End of Mx2_1 Entries loop
    TTree *T_Mx2_50;
    Mx2_50->GetObject("T_tree", T_Mx2_50);
    T_Mx2_50->SetBranchAddress("I_weight", &I_Mx50_weight);
    T_Mx2_50->SetBranchAddress("f_Met", &f_Mx50_Met);
    T_Mx2_50->SetBranchAddress("v_Trk_dzerror", &v_Mx50_dzerror);
    T_Mx2_50->SetBranchAddress("v_Trk_dxyerror", &v_Mx50_dxyerror);
    T_Mx2_50->SetBranchAddress("v_Trk_dz", &v_Mx50_dz);
    T_Mx2_50->SetBranchAddress("v_Trk_dxy", &v_Mx50_dxy);
    T_Mx2_50->SetBranchAddress("v_TrkXYresolu", &v_Mx50_TrkXYresolu);
    T_Mx2_50->SetBranchAddress("v_TrkPT", &v_Mx50_Trkpt);
    T_Mx2_50->SetBranchAddress("v_TrkEta", &v_Mx50_TrkEta);
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
        for (size_t itrk = 0; itrk < v_Mx50_TrkXYresolu->size(); itrk++)
        {
            h_Mx2_50_TrkXYresolu->Fill((*v_Mx50_TrkXYresolu)[itrk], I_Mx50_weight);

            if ((*v_Mx50_Trkpt)[itrk] < 10 && abs((*v_Mx50_TrkEta)[itrk]) < 1.4)
            {
                h_Mx2_50_TrkXYresolu_comp->Fill((*v_Mx50_TrkXYresolu)[itrk], I_Mx50_weight);
            }
        }
    } // End of Mx2_50 Entries loop
    TTree *T_Mx2_150;
    Mx2_150->GetObject("T_tree", T_Mx2_150);
    T_Mx2_150->SetBranchAddress("I_weight", &I_Mx150_weight);
    T_Mx2_150->SetBranchAddress("f_Met", &f_Mx150_Met);
    T_Mx2_150->SetBranchAddress("v_Trk_dzerror", &v_Mx150_dzerror);
    T_Mx2_150->SetBranchAddress("v_Trk_dxyerror", &v_Mx150_dxyerror);
    T_Mx2_150->SetBranchAddress("v_Trk_dz", &v_Mx150_dz);
    T_Mx2_150->SetBranchAddress("v_Trk_dxy", &v_Mx150_dxy);
    T_Mx2_150->SetBranchAddress("v_TrkXYresolu", &v_Mx150_TrkXYresolu);
    T_Mx2_150->SetBranchAddress("v_TrkPT", &v_Mx150_Trkpt);
    T_Mx2_150->SetBranchAddress("v_TrkEta", &v_Mx150_TrkEta);
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
        for (size_t itrk = 0; itrk < v_Mx150_TrkXYresolu->size(); itrk++)
        {
            h_Mx2_150_TrkXYresolu->Fill((*v_Mx150_TrkXYresolu)[itrk], I_Mx150_weight);

            if ((*v_Mx150_Trkpt)[itrk] < 10 && abs((*v_Mx150_TrkEta)[itrk]) < 1.4)
            {
                h_Mx2_150_TrkXYresolu_comp->Fill((*v_Mx150_TrkXYresolu)[itrk], I_Mx150_weight);
            }
        }
    } // End of Mx2_150 Entries loop

    /*visualize the result*/
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

    /*For background*/
    h_Top_dz->SetLineWidth(2);
    h_Top_dxy->SetLineWidth(2);
    h_Top_dzerr->SetLineWidth(2);
    h_Top_dxyerr->SetLineWidth(2);

    h_Top_dz->SetLineColor(kGreen + 2);
    h_Top_dxy->SetLineColor(kGreen + 2);
    h_Top_dzerr->SetLineColor(kGreen + 2);
    h_Top_dxyerr->SetLineColor(kGreen + 2);

    h_Top_dz->SetFillColor(kGreen + 2);
    h_Top_dxy->SetFillColor(kGreen + 2);
    h_Top_dzerr->SetFillColor(kGreen + 2);
    h_Top_dxyerr->SetFillColor(kGreen + 2);

    h_Top_dz->SetFillStyle(3001);
    h_Top_dxy->SetFillStyle(3001);
    h_Top_dzerr->SetFillStyle(3001);
    h_Top_dxyerr->SetFillStyle(3001);

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

    h_Top_dxyerr->GetXaxis()->SetTitleSize(0.045);
    h_Top_dxyerr->GetXaxis()->SetLabelSize(0.045);
    h_Top_dxyerr->GetXaxis()->SetLabelOffset(0.02);
    h_Top_dxyerr->GetXaxis()->SetTitleOffset(1.3);
    h_Top_dxyerr->GetYaxis()->SetTitleSize(0.045);
    h_Top_dxyerr->GetYaxis()->SetLabelSize(0.045);
    h_Top_dxyerr->GetYaxis()->SetTitleOffset(1.3);
    h_Top_dxyerr->GetYaxis()->SetTitle("nTrack/ Normailized");
    h_Top_dxyerr->GetXaxis()->SetTitle("dxy_{error}");

    h_Top_dzerr->GetXaxis()->SetTitleSize(0.045);
    h_Top_dzerr->GetXaxis()->SetLabelSize(0.045);
    h_Top_dzerr->GetXaxis()->SetLabelOffset(0.02);
    h_Top_dzerr->GetXaxis()->SetTitleOffset(1.3);
    h_Top_dzerr->GetYaxis()->SetTitleSize(0.045);
    h_Top_dzerr->GetYaxis()->SetLabelSize(0.045);
    h_Top_dzerr->GetYaxis()->SetTitleOffset(1.3);
    h_Top_dzerr->GetYaxis()->SetTitle("nTrack/ Normailized");
    h_Top_dzerr->GetXaxis()->SetTitle("dz_{error}");

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

    h_Mx2_1_TrkXYresolu->GetXaxis()->SetTitleSize(0.045);
    h_Mx2_1_TrkXYresolu->GetXaxis()->SetLabelSize(0.045);
    h_Mx2_1_TrkXYresolu->GetXaxis()->SetLabelOffset(0.02);
    h_Mx2_1_TrkXYresolu->GetXaxis()->SetTitleOffset(1.3);
    h_Mx2_1_TrkXYresolu->GetYaxis()->SetTitleSize(0.045);
    h_Mx2_1_TrkXYresolu->GetYaxis()->SetLabelSize(0.045);
    h_Mx2_1_TrkXYresolu->GetYaxis()->SetTitleOffset(1.4);
    h_Mx2_1_TrkXYresolu->GetYaxis()->SetTitle("nTrack/ Normailized");
    h_Mx2_1_TrkXYresolu->GetXaxis()->SetTitle("Track IP resolution (dxy) [cm]");

    h_Mx2_1_TrkXYresolu_comp->GetXaxis()->SetTitleSize(0.045);
    h_Mx2_1_TrkXYresolu_comp->GetXaxis()->SetLabelSize(0.045);
    h_Mx2_1_TrkXYresolu_comp->GetXaxis()->SetLabelOffset(0.02);
    h_Mx2_1_TrkXYresolu_comp->GetXaxis()->SetTitleOffset(1.3);
    h_Mx2_1_TrkXYresolu_comp->GetYaxis()->SetTitleSize(0.045);
    h_Mx2_1_TrkXYresolu_comp->GetYaxis()->SetLabelSize(0.045);
    h_Mx2_1_TrkXYresolu_comp->GetYaxis()->SetTitleOffset(1.4);
    h_Mx2_1_TrkXYresolu_comp->GetYaxis()->SetTitle("nTrack/ Normailized");
    h_Mx2_1_TrkXYresolu_comp->GetXaxis()->SetTitle("Track IP resolution (dxy) [cm]");

    h_Top_dxy->GetXaxis()->SetTitleSize(0.045);
    h_Top_dxy->GetXaxis()->SetLabelSize(0.045);
    h_Top_dxy->GetXaxis()->SetLabelOffset(0.02);
    h_Top_dxy->GetXaxis()->SetTitleOffset(1.3);
    h_Top_dxy->GetYaxis()->SetTitleSize(0.045);
    h_Top_dxy->GetYaxis()->SetLabelSize(0.045);
    h_Top_dxy->GetYaxis()->SetTitleOffset(1.4);
    h_Top_dxy->GetYaxis()->SetTitle("nTrack/ Normailized");
    h_Top_dxy->GetXaxis()->SetTitle("dxy (cm)");

    h_Top_dz->GetXaxis()->SetTitleSize(0.045);
    h_Top_dz->GetXaxis()->SetLabelSize(0.045);
    h_Top_dz->GetXaxis()->SetLabelOffset(0.02);
    h_Top_dz->GetXaxis()->SetTitleOffset(1.3);
    h_Top_dz->GetYaxis()->SetTitleSize(0.045);
    h_Top_dz->GetYaxis()->SetLabelSize(0.045);
    h_Top_dz->GetYaxis()->SetTitleOffset(1.4);
    h_Top_dz->GetYaxis()->SetTitle("nTrack/ Normailized");
    h_Top_dz->GetXaxis()->SetTitle("dz (cm)");

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

    h_Mx2_1_TrkXYresolu->SetLineColor(kRed);
    h_Mx2_50_TrkXYresolu->SetLineColor(kGray + 2);
    h_Mx2_150_TrkXYresolu->SetLineColor(kBlue);

    h_Mx2_1_TrkXYresolu_comp->SetLineColor(kRed);
    h_Mx2_50_TrkXYresolu_comp->SetLineColor(kGray + 2);
    h_Mx2_150_TrkXYresolu_comp->SetLineColor(kBlue);

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

    h_Mx2_1_TrkXYresolu->SetLineWidth(2);
    h_Mx2_50_TrkXYresolu->SetLineWidth(2);
    h_Mx2_150_TrkXYresolu->SetLineWidth(2);

    h_Mx2_1_TrkXYresolu_comp->SetLineWidth(2);
    h_Mx2_50_TrkXYresolu_comp->SetLineWidth(2);
    h_Mx2_150_TrkXYresolu_comp->SetLineWidth(2);

    // h_Mx2_150_dxy->GetXaxis()->SetRangeUser(-30., 30.);
    // h_Top_dxy->GetXaxis()->SetRangeUser(-30., 30.);
    // h_Mx2_50_dxy->GetXaxis()->SetRangeUser(-30., 30.);
    // h_Mx2_1_dxy->GetXaxis()->SetRangeUser(-30., 30.);
    //  h_Mx2_150_dz->GetXaxis()->SetRangeUser(-2., 2.);

    /*
    h_Top_dzerr->DrawNormalized("h");
    h_Mx2_150_dzerror->DrawNormalized("same");
    h_Mx2_50_dzerror->DrawNormalized("same");
    h_Mx2_1_dzerror->DrawNormalized("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_dzerror, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_dzerror, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_dzerror, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Top_dzerr, "Top process", "lE");
    l1->Draw();
    */
    /*
    h_Top_dxyerr->DrawNormalized("h");
    h_Mx2_150_dxyerror->DrawNormalized("same");
    h_Mx2_50_dxyerror->DrawNormalized("same");
    h_Mx2_1_dxyerror->DrawNormalized("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_dxyerror, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_dxyerror, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_dxyerror, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Top_dxyerr, "Top process", "lE");
    l1->Draw();
    */
    // h_Top_dxy->GetXaxis()->SetRangeUser(-5., 5.);
    /*
    h_Top_dxy->DrawNormalized("h");
    h_Mx2_150_dxy->DrawNormalized("same");
    h_Mx2_50_dxy->DrawNormalized("same");
    h_Mx2_1_dxy->DrawNormalized("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_dxy, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_dxy, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_dxy, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Top_dxy, "Top process", "lE");
    l1->Draw();
    */
    /*
    h_Top_dz->GetXaxis()->SetRangeUser(-5., 5.);

    h_Top_dz->DrawNormalized("h");
    h_Mx2_150_dz->DrawNormalized("same");
    h_Mx2_50_dz->DrawNormalized("same");
    h_Mx2_1_dz->DrawNormalized("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_dz, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_dz, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_dz, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Top_dz, "Top process", "lE");
    l1->Draw();
    */

   h_Mx2_1_TrkXYresolu->GetXaxis()->SetRangeUser(0., 50.);
   h_Mx2_1_TrkXYresolu->Draw();

   gStyle->SetOptStat(1111);
    /*
    h_Mx2_1_TrkXYresolu->GetXaxis()->SetRangeUser(0., 50.);
    h_Mx2_1_TrkXYresolu->Draw();
    h_Mx2_50_TrkXYresolu->Draw("same");
    h_Mx2_150_TrkXYresolu->Draw("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_TrkXYresolu, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_TrkXYresolu, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_TrkXYresolu, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();*/
    
   /*
    h_Mx2_1_TrkXYresolu_comp->GetXaxis()->SetRangeUser(0., 50.);
    h_Mx2_1_TrkXYresolu_comp->Draw();
    h_Mx2_50_TrkXYresolu_comp->Draw("same");
    h_Mx2_150_TrkXYresolu_comp->Draw("same");

    TLegend *l1 = new TLegend(0.52, 0.7, 0.80, 0.90);
    l1->SetTextSize(0.03);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->AddEntry(h_Mx2_1_TrkXYresolu_comp, "m_{#chi_{2}} = 1 GeV, ctau = 1 mm", "lE");
    l1->AddEntry(h_Mx2_50_TrkXYresolu_comp, "m_{#chi_{2}} = 50 GeV, ctau = 10 mm", "lE");
    l1->AddEntry(h_Mx2_150_TrkXYresolu_comp, "m_{#chi_{2}} = 150 GeV, ctau = 1 mm", "lE");
    l1->Draw();
    */
    /*Compare match dd trk*/

    // gPad->SetLogy();

    CMS_lumi((TPad *)canv, 5, 0, "35.9 fb^{-1}", 2016, true, "Simulation", "", "");
}