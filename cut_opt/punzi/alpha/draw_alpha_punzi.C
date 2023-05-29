#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <TLegend.h>
#include <TCanvas.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <TH1D.h>
#include <string>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../../lib/kuan_ana_utils.h"

void draw_alpha_punzi()
{
    TFile *ee_punzi_result = TFile::Open("/home/kuanyu/Documents/CMS/Background_Estimate/cut_opt/punzi/alpha/ee_alpha_punzi.root");

    TH1D *h_ee_punzi_Sig1 = ee_punzi_result->Get<TH1D>("h_punzi_Sig1");
    TH1D *h_ee_punzi_Sig50 = ee_punzi_result->Get<TH1D>("h_punzi_Sig50");
    TH1D *h_ee_punzi_Sig150 = ee_punzi_result->Get<TH1D>("h_punzi_Sig150");

    int W = 800;
    int H = 600;

    int H_ref = 600;
    int W_ref = 800;

    TCanvas *canv = new TCanvas("canv", "", 50, 50, W, H);

    h_ee_punzi_Sig1->SetLineWidth(2);
    h_ee_punzi_Sig50->SetLineWidth(2);
    h_ee_punzi_Sig150->SetLineWidth(2);

    h_ee_punzi_Sig1->SetLineColor(kRed);
    h_ee_punzi_Sig50->SetLineColor(kGray + 2);
    h_ee_punzi_Sig150->SetLineColor(kBlue);

    h_ee_punzi_Sig50->GetYaxis()->SetTitle("Punzi Significance");
    h_ee_punzi_Sig50->GetYaxis()->SetTitleOffset(1.5);

    h_ee_punzi_Sig50->GetXaxis()->SetBinLabel(1,"#alpha<0.05");
    h_ee_punzi_Sig50->GetXaxis()->SetBinLabel(4,"#alpha<0.2");
    h_ee_punzi_Sig50->GetXaxis()->SetBinLabel(10,"#alpha<0.5");
    h_ee_punzi_Sig50->GetXaxis()->SetBinLabel(15,"#alpha<0.75");

    h_ee_punzi_Sig50->GetXaxis()->SetTitle("#alpha_{3D}");
    h_ee_punzi_Sig50->SetAxisRange(-0.06, 0.045, "Y");
    
    // h_ee_punzi_Sig50->GetXaxis()->SetTitleOffset(1.5);

    h_ee_punzi_Sig50->Draw();
    h_ee_punzi_Sig150->Draw("same");
    h_ee_punzi_Sig1->Draw("same");

    

    TLegend *l1 = new TLegend(0.5, 0.7, 0.90, 0.90);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.03);
    l1->AddEntry(h_ee_punzi_Sig1, "m_{#chi_{2}} = 1 GeV, c#tau = 1 mm", "lE");
    l1->AddEntry(h_ee_punzi_Sig50, "m_{#chi_{2}} = 50 GeV, c#tau = 10 mm", "lE");
    l1->AddEntry(h_ee_punzi_Sig150, "m_{#chi_{2}} = 150 GeV, c#tau = 1 mm", "lE");
    l1->Draw();

    gStyle->SetOptStat(0);

    //canv->SaveAs("ee_alpha3_punzi_Metcut.png");
}

int main()
{
    draw_alpha_punzi();

    return 0;
}