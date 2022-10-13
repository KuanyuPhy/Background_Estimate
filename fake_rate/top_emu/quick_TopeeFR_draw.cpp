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
void quick_TopeeFR_draw(TString file = "./Ratio_apply.root")
{
    TFile *Topfile = TFile::Open(file);

    TH1D *h_Top_btrk_TrueBG = ((TH1D *)Topfile->Get("h_Top_btrk_TrueBG"));
    TH1D *h_Top_ltrk_TrueBG = ((TH1D *)Topfile->Get("h_Top_ltrk_TrueBG"));
    TH1D *h_Top_bJetPt_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetPt_TrueBG"));
    TH1D *h_Top_lJetPt_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetPt_TrueBG"));
    TH1D *h_Top_bJetEta_noeta_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetEta_noeta_TrueBG"));
    TH1D *h_Top_lJetEta_noeta_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetEta_noeta_TrueBG"));
    TH1D *h_Topee_btrk_HMet = ((TH1D *)Topfile->Get("h_Topee_btrk_HMet"));
    TH1D *h_Topee_ltrk_HMet = ((TH1D *)Topfile->Get("h_Topee_ltrk_HMet"));
    TH1D *h_Topee_bJetPt_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetPt_HMet"));
    TH1D *h_Topee_lJetPt_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetPt_HMet"));
    TH1D *h_Topee_bJetEta_noeta_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetEta_noeta_HMet"));
    TH1D *h_Topee_lJetEta_noeta_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetEta_noeta_HMet"));
    TH1D *h_Topemu_btrk_HMet = ((TH1D *)Topfile->Get("h_Topemu_btrk_HMet"));
    TH1D *h_Topemu_ltrk_HMet = ((TH1D *)Topfile->Get("h_Topemu_ltrk_HMet"));
    TH1D *h_Topemu_bJetPt_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetPt_HMet"));
    TH1D *h_Topemu_lJetPt_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetPt_HMet"));
    TH1D *h_Topemu_bJetEta_noeta_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetEta_noeta_HMet"));
    TH1D *h_Topemu_lJetEta_noeta_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetEta_noeta_HMet"));

    TH1D *h_Top_btrk_region1_TrueBG = ((TH1D *)Topfile->Get("h_Top_btrk_region1_TrueBG"));
    TH1D *h_Top_btrk_region2_TrueBG = ((TH1D *)Topfile->Get("h_Top_btrk_region2_TrueBG"));
    TH1D *h_Top_btrk_region3_TrueBG = ((TH1D *)Topfile->Get("h_Top_btrk_region3_TrueBG"));
    TH1D *h_Top_ltrk_region1_TrueBG = ((TH1D *)Topfile->Get("h_Top_ltrk_region1_TrueBG"));
    TH1D *h_Top_ltrk_region2_TrueBG = ((TH1D *)Topfile->Get("h_Top_ltrk_region2_TrueBG"));
    TH1D *h_Top_ltrk_region3_TrueBG = ((TH1D *)Topfile->Get("h_Top_ltrk_region3_TrueBG"));
    TH1D *h_Topee_btrk_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_btrk_region1_HMet"));
    TH1D *h_Topee_btrk_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_btrk_region2_HMet"));
    TH1D *h_Topee_btrk_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_btrk_region3_HMet"));
    TH1D *h_Topee_ltrk_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_ltrk_region1_HMet"));
    TH1D *h_Topee_ltrk_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_ltrk_region2_HMet"));
    TH1D *h_Topee_ltrk_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_ltrk_region3_HMet"));
    TH1D *h_Topemu_btrk_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_btrk_region1_HMet"));
    TH1D *h_Topemu_btrk_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_btrk_region2_HMet"));
    TH1D *h_Topemu_btrk_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_btrk_region3_HMet"));
    TH1D *h_Topemu_ltrk_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_ltrk_region1_HMet"));
    TH1D *h_Topemu_ltrk_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_ltrk_region2_HMet"));
    TH1D *h_Topemu_ltrk_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_ltrk_region3_HMet"));

    TH1D *h_Top_bJetPt_region1_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetPt_region1_TrueBG"));
    TH1D *h_Top_bJetPt_region2_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetPt_region2_TrueBG"));
    TH1D *h_Top_bJetPt_region3_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetPt_region3_TrueBG"));
    TH1D *h_Top_lJetPt_region1_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetPt_region1_TrueBG"));

    TH1D *h_Top_lJetPt_region2_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetPt_region2_TrueBG"));
    TH1D *h_Top_lJetPt_region3_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetPt_region3_TrueBG"));
    TH1D *h_Topee_bJetPt_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetPt_region1_HMet"));
    TH1D *h_Topee_bJetPt_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetPt_region2_HMet"));
    TH1D *h_Topee_bJetPt_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetPt_region3_HMet"));
    TH1D *h_Topee_lJetPt_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetPt_region1_HMet"));
    TH1D *h_Topee_lJetPt_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetPt_region2_HMet"));
    TH1D *h_Topee_lJetPt_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetPt_region3_HMet"));

    TH1D *h_Topemu_bJetPt_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetPt_region1_HMet"));
    TH1D *h_Topemu_bJetPt_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetPt_region2_HMet"));
    TH1D *h_Topemu_bJetPt_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetPt_region3_HMet"));
    TH1D *h_Topemu_lJetPt_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetPt_region1_HMet"));
    TH1D *h_Topemu_lJetPt_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetPt_region2_HMet"));
    TH1D *h_Topemu_lJetPt_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetPt_region3_HMet"));

    TH1D *h_Top_bJetMass_region1_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetMass_region1_TrueBG"));
    TH1D *h_Top_bJetMass_region2_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetMass_region2_TrueBG"));
    TH1D *h_Top_bJetMass_region3_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetMass_region3_TrueBG"));

    TH1D *h_Top_lJetMass_region1_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetMass_region1_TrueBG"));
    TH1D *h_Top_lJetMass_region2_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetMass_region2_TrueBG"));
    TH1D *h_Top_lJetMass_region3_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetMass_region3_TrueBG"));

    TH1D *h_Topee_bJetMass_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetMass_region1_HMet"));
    TH1D *h_Topee_bJetMass_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetMass_region2_HMet"));
    TH1D *h_Topee_bJetMass_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetMass_region3_HMet"));
    TH1D *h_Topee_lJetMass_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetMass_region1_HMet"));
    TH1D *h_Topee_lJetMass_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetMass_region2_HMet"));
    TH1D *h_Topee_lJetMass_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetMass_region3_HMet"));

    TH1D *h_Topemu_bJetMass_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetMass_region1_HMet"));
    TH1D *h_Topemu_bJetMass_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetMass_region2_HMet"));
    TH1D *h_Topemu_bJetMass_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetMass_region3_HMet"));
    TH1D *h_Topemu_lJetMass_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetMass_region1_HMet"));
    TH1D *h_Topemu_lJetMass_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetMass_region2_HMet"));
    TH1D *h_Topemu_lJetMass_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetMass_region3_HMet"));

    TH1D *h_Top_bJetCsv_region1_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetCsv_region1_TrueBG"));
    TH1D *h_Top_bJetCsv_region2_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetCsv_region2_TrueBG"));
    TH1D *h_Top_bJetCsv_region3_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetCsv_region3_TrueBG"));

    TH1D *h_Top_lJetCsv_region1_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetCsv_region1_TrueBG"));
    TH1D *h_Top_lJetCsv_region2_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetCsv_region2_TrueBG"));
    TH1D *h_Top_lJetCsv_region3_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetCsv_region3_TrueBG"));

    TH1D *h_Topee_bJetCsv_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetCsv_region1_HMet"));
    TH1D *h_Topee_bJetCsv_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetCsv_region2_HMet"));
    TH1D *h_Topee_bJetCsv_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetCsv_region3_HMet"));
    TH1D *h_Topee_lJetCsv_region1_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetCsv_region1_HMet"));
    TH1D *h_Topee_lJetCsv_region2_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetCsv_region2_HMet"));
    TH1D *h_Topee_lJetCsv_region3_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetCsv_region3_HMet"));

    TH1D *h_Topemu_bJetCsv_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetCsv_region1_HMet"));
    TH1D *h_Topemu_bJetCsv_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetCsv_region2_HMet"));
    TH1D *h_Topemu_bJetCsv_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetCsv_region3_HMet"));
    TH1D *h_Topemu_lJetCsv_region1_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetCsv_region1_HMet"));
    TH1D *h_Topemu_lJetCsv_region2_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetCsv_region2_HMet"));
    TH1D *h_Topemu_lJetCsv_region3_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetCsv_region3_HMet"));

    TH1D *h_Top_bJetEta_TrueBG = ((TH1D *)Topfile->Get("h_Top_bJetEta_TrueBG"));
    TH1D *h_Top_lJetEta_TrueBG = ((TH1D *)Topfile->Get("h_Top_lJetEta_TrueBG"));
    TH1D *h_Topee_bJetEta_HMet = ((TH1D *)Topfile->Get("h_Topee_bJetEta_HMet"));
    TH1D *h_Topee_lJetEta_HMet = ((TH1D *)Topfile->Get("h_Topee_lJetEta_HMet"));
    TH1D *h_Topemu_bJetEta_HMet = ((TH1D *)Topfile->Get("h_Topemu_bJetEta_HMet"));
    TH1D *h_Topemu_lJetEta_HMet = ((TH1D *)Topfile->Get("h_Topemu_lJetEta_HMet"));

    h_Top_btrk_TrueBG->SetLineWidth(2);
    h_Top_ltrk_TrueBG->SetLineWidth(2);
    h_Top_bJetPt_TrueBG->SetLineWidth(2);
    h_Top_lJetPt_TrueBG->SetLineWidth(2);
    h_Top_bJetEta_noeta_TrueBG->SetLineWidth(2);
    h_Top_lJetEta_noeta_TrueBG->SetLineWidth(2);
    h_Topee_btrk_HMet->SetLineWidth(2);
    h_Topee_ltrk_HMet->SetLineWidth(2);
    h_Topee_bJetPt_HMet->SetLineWidth(2);
    h_Topee_lJetPt_HMet->SetLineWidth(2);
    h_Topee_bJetEta_noeta_HMet->SetLineWidth(2);
    h_Topee_lJetEta_noeta_HMet->SetLineWidth(2);
    h_Topemu_btrk_HMet->SetLineWidth(2);
    h_Topemu_ltrk_HMet->SetLineWidth(2);
    h_Topemu_bJetPt_HMet->SetLineWidth(2);
    h_Topemu_lJetPt_HMet->SetLineWidth(2);
    h_Topemu_bJetEta_noeta_HMet->SetLineWidth(2);
    h_Topemu_lJetEta_noeta_HMet->SetLineWidth(2);

    h_Top_btrk_region1_TrueBG->SetLineWidth(2);
    h_Top_btrk_region2_TrueBG->SetLineWidth(2);
    h_Top_btrk_region3_TrueBG->SetLineWidth(2);
    h_Top_ltrk_region1_TrueBG->SetLineWidth(2);
    h_Top_ltrk_region2_TrueBG->SetLineWidth(2);
    h_Top_ltrk_region3_TrueBG->SetLineWidth(2);
    h_Topee_btrk_region1_HMet->SetLineWidth(2);
    h_Topee_btrk_region2_HMet->SetLineWidth(2);
    h_Topee_btrk_region3_HMet->SetLineWidth(2);
    h_Topee_ltrk_region1_HMet->SetLineWidth(2);
    h_Topee_ltrk_region2_HMet->SetLineWidth(2);
    h_Topee_ltrk_region3_HMet->SetLineWidth(2);
    h_Top_bJetPt_region1_TrueBG->SetLineWidth(2);
    h_Top_bJetPt_region2_TrueBG->SetLineWidth(2);
    h_Top_bJetPt_region3_TrueBG->SetLineWidth(2);
    h_Top_lJetPt_region1_TrueBG->SetLineWidth(2);
    h_Top_lJetPt_region2_TrueBG->SetLineWidth(2);
    h_Top_lJetPt_region3_TrueBG->SetLineWidth(2);
    h_Topee_bJetPt_region1_HMet->SetLineWidth(2);
    h_Topee_bJetPt_region2_HMet->SetLineWidth(2);
    h_Topee_bJetPt_region3_HMet->SetLineWidth(2);
    h_Topee_lJetPt_region1_HMet->SetLineWidth(2);
    h_Topee_lJetPt_region2_HMet->SetLineWidth(2);
    h_Topee_lJetPt_region3_HMet->SetLineWidth(2);
    h_Top_bJetEta_TrueBG->SetLineWidth(2);
    h_Top_lJetEta_TrueBG->SetLineWidth(2);
    h_Topee_bJetEta_HMet->SetLineWidth(2);
    h_Topee_lJetEta_HMet->SetLineWidth(2);

    h_Topemu_btrk_region1_HMet->SetLineWidth(2);
    h_Topemu_btrk_region2_HMet->SetLineWidth(2);
    h_Topemu_btrk_region3_HMet->SetLineWidth(2);
    h_Topemu_ltrk_region1_HMet->SetLineWidth(2);
    h_Topemu_ltrk_region2_HMet->SetLineWidth(2);
    h_Topemu_ltrk_region3_HMet->SetLineWidth(2);
    h_Topemu_bJetPt_region1_HMet->SetLineWidth(2);
    h_Topemu_bJetPt_region2_HMet->SetLineWidth(2);
    h_Topemu_bJetPt_region3_HMet->SetLineWidth(2);
    h_Topemu_lJetPt_region1_HMet->SetLineWidth(2);
    h_Topemu_lJetPt_region2_HMet->SetLineWidth(2);
    h_Topemu_lJetPt_region3_HMet->SetLineWidth(2);
    h_Topemu_bJetEta_HMet->SetLineWidth(2);
    h_Topemu_lJetEta_HMet->SetLineWidth(2);

    h_Top_bJetMass_region1_TrueBG->SetLineWidth(2);
    h_Top_bJetMass_region2_TrueBG->SetLineWidth(2);
    h_Top_bJetMass_region3_TrueBG->SetLineWidth(2);

    h_Top_lJetMass_region1_TrueBG->SetLineWidth(2);
    h_Top_lJetMass_region2_TrueBG->SetLineWidth(2);
    h_Top_lJetMass_region3_TrueBG->SetLineWidth(2);

    h_Topee_bJetMass_region1_HMet->SetLineWidth(2);
    h_Topee_bJetMass_region2_HMet->SetLineWidth(2);
    h_Topee_bJetMass_region3_HMet->SetLineWidth(2);
    h_Topee_lJetMass_region1_HMet->SetLineWidth(2);
    h_Topee_lJetMass_region2_HMet->SetLineWidth(2);
    h_Topee_lJetMass_region3_HMet->SetLineWidth(2);

    h_Topemu_bJetMass_region1_HMet->SetLineWidth(2);
    h_Topemu_bJetMass_region2_HMet->SetLineWidth(2);
    h_Topemu_bJetMass_region3_HMet->SetLineWidth(2);
    h_Topemu_lJetMass_region1_HMet->SetLineWidth(2);
    h_Topemu_lJetMass_region2_HMet->SetLineWidth(2);
    h_Topemu_lJetMass_region3_HMet->SetLineWidth(2);

    h_Top_bJetCsv_region1_TrueBG->SetLineWidth(2);
    h_Top_bJetCsv_region2_TrueBG->SetLineWidth(2);
    h_Top_bJetCsv_region3_TrueBG->SetLineWidth(2);

    h_Top_lJetCsv_region1_TrueBG->SetLineWidth(2);
    h_Top_lJetCsv_region2_TrueBG->SetLineWidth(2);
    h_Top_lJetCsv_region3_TrueBG->SetLineWidth(2);

    h_Topee_bJetCsv_region1_HMet->SetLineWidth(2);
    h_Topee_bJetCsv_region2_HMet->SetLineWidth(2);
    h_Topee_bJetCsv_region3_HMet->SetLineWidth(2);
    h_Topee_lJetCsv_region1_HMet->SetLineWidth(2);
    h_Topee_lJetCsv_region2_HMet->SetLineWidth(2);
    h_Topee_lJetCsv_region3_HMet->SetLineWidth(2);

    h_Topemu_bJetCsv_region1_HMet->SetLineWidth(2);
    h_Topemu_bJetCsv_region2_HMet->SetLineWidth(2);
    h_Topemu_bJetCsv_region3_HMet->SetLineWidth(2);
    h_Topemu_lJetCsv_region1_HMet->SetLineWidth(2);
    h_Topemu_lJetCsv_region2_HMet->SetLineWidth(2);
    h_Topemu_lJetCsv_region3_HMet->SetLineWidth(2);

    h_Topee_btrk_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_btrk_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_btrk_region3_HMet->SetLineColor(kGreen + 3);
    h_Topee_ltrk_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_ltrk_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_ltrk_region3_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetPt_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetPt_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetPt_region3_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetPt_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetPt_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetPt_region3_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetEta_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetEta_HMet->SetLineColor(kGreen + 3);

    h_Topee_bJetMass_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetMass_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetMass_region3_HMet->SetLineColor(kGreen + 3);

    h_Topee_lJetMass_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetMass_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetMass_region3_HMet->SetLineColor(kGreen + 3);

    h_Topee_bJetCsv_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetCsv_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_bJetCsv_region3_HMet->SetLineColor(kGreen + 3);

    h_Topee_lJetCsv_region1_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetCsv_region2_HMet->SetLineColor(kGreen + 3);
    h_Topee_lJetCsv_region3_HMet->SetLineColor(kGreen + 3);

    h_Topemu_btrk_HMet->SetLineColor(kOrange + 7);
    h_Topemu_ltrk_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetPt_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetPt_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetEta_noeta_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetEta_noeta_HMet->SetLineColor(kOrange + 7);

    h_Topemu_btrk_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_btrk_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_btrk_region3_HMet->SetLineColor(kOrange + 7);
    h_Topemu_ltrk_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_ltrk_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_ltrk_region3_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetPt_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetPt_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetPt_region3_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetPt_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetPt_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetPt_region3_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetEta_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetEta_HMet->SetLineColor(kOrange + 7);

    h_Topemu_bJetMass_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetMass_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetMass_region3_HMet->SetLineColor(kOrange + 7);

    h_Topemu_lJetMass_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetMass_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetMass_region3_HMet->SetLineColor(kOrange + 7);

    h_Topemu_bJetCsv_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetCsv_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_bJetCsv_region3_HMet->SetLineColor(kOrange + 7);

    h_Topemu_lJetCsv_region1_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetCsv_region2_HMet->SetLineColor(kOrange + 7);
    h_Topemu_lJetCsv_region3_HMet->SetLineColor(kOrange + 7);

    int W = 1000;
    int H = 800;

    auto c1 = new TCanvas("c1", "c1", 50, 50, W, H);

    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetFrameFillStyle(0);
    c1->SetFrameBorderMode(0);
    c1->SetTickx(0);
    c1->SetTicky(0);

    c1->Divide(3, 2, 0.01, 0.01);
    // c1->Divide(2, 2, 0.01, 0.01);
    //  c1->Divide(3, 1);
    //  c1->Divide(2, 1);
    //  c1->cd(1);

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Topee_btrk_region1_HMet->GetXaxis()->SetTitleSize(0);
    h_Topee_btrk_region1_HMet->GetXaxis()->SetLabelSize(0);

    h_Topee_btrk_region1_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_btrk_region1_HMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_btrk_region1_HMet->SetFillStyle(3001);
    h_Topee_btrk_region1_HMet->SetFillColor(kGreen + 3);

    h_Top_btrk_region1_TrueBG->SetMarkerStyle(20);

    h_Topee_btrk_region1_HMet->Draw("h");
    // h_Topemu_btrk_region1_HMet->Draw("same");
    h_Top_btrk_region1_TrueBG->Draw("h same");

    TLegend *l0 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->AddEntry(h_Top_btrk_region1_TrueBG, "True Background", "l");
    l0->AddEntry(h_Topee_btrk_region1_HMet, "Predicted", "l");
    // l0->AddEntry(h_Topemu_btrk_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_btrk_region2_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_btrk_region2_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_btrk_region2_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_region2_TrueBG->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_btrk_region2_HMet->SetFillStyle(3001);
    h_Topee_btrk_region2_HMet->SetFillColor(kGreen + 3);

    h_Top_btrk_region2_TrueBG->SetMarkerStyle(20);

    h_Top_btrk_region2_TrueBG->Draw("h ");
    h_Topee_btrk_region2_HMet->Draw("h same");
    // h_Topemu_btrk_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->AddEntry(h_Top_btrk_region2_TrueBG, "True Background", "l");
    l1->AddEntry(h_Topee_btrk_region2_HMet, "Predicted", "l");
    // l1->AddEntry(h_Topemu_btrk_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    gPad->SetLogy();

    c1->cd(3);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Topee_btrk_region3_HMet->GetXaxis()->SetTitleSize(0);
    h_Topee_btrk_region3_HMet->GetXaxis()->SetLabelSize(0);

    h_Topee_btrk_region3_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_btrk_region3_HMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_btrk_region3_HMet->SetFillStyle(3001);
    h_Topee_btrk_region3_HMet->SetFillColor(kGreen + 3);

    h_Top_btrk_region3_TrueBG->SetMarkerStyle(20);

    h_Topee_btrk_region3_HMet->Draw("h");
    h_Top_btrk_region3_TrueBG->Draw("h same");
    // h_Topemu_btrk_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->AddEntry(h_Top_btrk_region3_TrueBG, "True Background", "l");
    l2->AddEntry(h_Topee_btrk_region3_HMet, "Predicted", "l");
    // l2->AddEntry(h_Topemu_btrk_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();

    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_1 = (TH1F *)h_Top_btrk_region1_TrueBG->Clone("h_TrueBG_EEFR_lRatio_1");
    h_TrueBG_EEFR_bRatio_1->Divide(h_Topee_btrk_region1_HMet);
    h_TrueBG_EEFR_bRatio_1->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetTitle("Track multiplicity");
    h_TrueBG_EEFR_bRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_1->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_2 = (TH1F *)h_Top_btrk_region2_TrueBG->Clone("h_TrueBG_EEFR_bRatio_2");
    h_TrueBG_EEFR_bRatio_2->Divide(h_Topee_btrk_region2_HMet);
    h_TrueBG_EEFR_bRatio_2->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetTitle("Track multiplicity");
    h_TrueBG_EEFR_bRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_2->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_3 = (TH1F *)h_Top_btrk_region3_TrueBG->Clone("h_TrueBG_EEFR_bRatio_3");
    h_TrueBG_EEFR_bRatio_3->Divide(h_Topee_btrk_region3_HMet);
    h_TrueBG_EEFR_bRatio_3->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetTitle("Track multiplicity");
    h_TrueBG_EEFR_bRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_3->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_3->Draw("e");
    */

    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_ltrk_region1_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_ltrk_region1_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_ltrk_region1_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_region1_TrueBG->GetXaxis()->SetTitle("Track multiplicity");

                h_Topee_ltrk_region1_HMet->SetFillStyle(3001);
    h_Topee_ltrk_region1_HMet->SetFillColor(kGreen + 3);

    h_Top_ltrk_region1_TrueBG->SetMarkerStyle(20);

    h_Top_ltrk_region1_TrueBG->Draw("h ");
    h_Topee_ltrk_region1_HMet->Draw("h same");
    //h_Topemu_ltrk_region1_HMet->Draw("same");

    TLegend *l0 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->AddEntry(h_Top_ltrk_region1_TrueBG, "True Background", "l");
    l0->AddEntry(h_Topee_ltrk_region1_HMet, "Predicted", "l");
    //l0->AddEntry(h_Topemu_ltrk_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    //gPad->SetLogy();

    c1->cd(2);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_ltrk_region2_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_ltrk_region2_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_ltrk_region2_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_region2_TrueBG->GetXaxis()->SetTitle("Track multiplicity");

            h_Topee_ltrk_region2_HMet->SetFillStyle(3001);
    h_Topee_ltrk_region2_HMet->SetFillColor(kGreen + 3);

    h_Top_ltrk_region2_TrueBG->SetMarkerStyle(20);

    h_Top_ltrk_region2_TrueBG->Draw("h ");
    h_Topee_ltrk_region2_HMet->Draw("h same");
    //h_Topemu_ltrk_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->AddEntry(h_Top_ltrk_region2_TrueBG, "True Background", "l");
    l1->AddEntry(h_Topee_ltrk_region2_HMet, "Predicted", "l");
    //l1->AddEntry(h_Topemu_ltrk_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    //gPad->SetLogy();

    c1->cd(3);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Topee_ltrk_region3_HMet->GetXaxis()->SetTitleSize(0);
    h_Topee_ltrk_region3_HMet->GetXaxis()->SetLabelSize(0);

    h_Topee_ltrk_region3_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_ltrk_region3_HMet->GetXaxis()->SetTitle("Track multiplicity");

        h_Topee_ltrk_region3_HMet->SetFillStyle(3001);
    h_Topee_ltrk_region3_HMet->SetFillColor(kGreen + 3);

    h_Top_ltrk_region3_TrueBG->SetMarkerStyle(20);

    h_Topee_ltrk_region3_HMet->Draw("h");
    h_Top_ltrk_region3_TrueBG->Draw("h same");
    //h_Topemu_ltrk_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->AddEntry(h_Top_ltrk_region3_TrueBG, "True Background", "l");
    l2->AddEntry(h_Topee_ltrk_region3_HMet, "Predicted", "l");
    //l2->AddEntry(h_Topemu_ltrk_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();

    //gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_1 = (TH1F *)h_Top_ltrk_region1_TrueBG->Clone("h_TrueBG_EEFR_lRatio_1");
    h_TrueBG_EEFR_lRatio_1->Divide(h_Topee_ltrk_region1_HMet);
    h_TrueBG_EEFR_lRatio_1->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetTitle("Track multiplicity");
    h_TrueBG_EEFR_lRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_1->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_2 = (TH1F *)h_Top_ltrk_region2_TrueBG->Clone("h_TrueBG_EEFR_lRatio_2");
    h_TrueBG_EEFR_lRatio_2->Divide(h_Topee_ltrk_region2_HMet);
    h_TrueBG_EEFR_lRatio_2->GetYaxis()->SetTitle("True Background /Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetTitle("Track multiplicity");
    h_TrueBG_EEFR_lRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_2->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_3 = (TH1F *)h_Top_ltrk_region3_TrueBG->Clone("h_TrueBG_EEFR_lRatio_3");
    h_TrueBG_EEFR_lRatio_3->Divide(h_Topee_ltrk_region3_HMet);
    h_TrueBG_EEFR_lRatio_3->GetYaxis()->SetTitle("True Background /Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetTitle("Track multiplicity");
    h_TrueBG_EEFR_lRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_3->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_3->Draw("e");

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Topee_bJetPt_region1_HMet->GetXaxis()->SetTitleSize(0);
    h_Topee_bJetPt_region1_HMet->GetXaxis()->SetLabelSize(0);

    h_Topee_bJetPt_region1_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_bJetPt_region1_HMet->GetXaxis()->SetTitle("Jet PT");

    h_Topee_bJetPt_region1_HMet->SetFillStyle(3001);
    h_Topee_bJetPt_region1_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetPt_region1_TrueBG->SetMarkerStyle(20);

    h_Topee_bJetPt_region1_HMet->Draw("h");
    // h_Topemu_bJetPt_region1_HMet->Draw("same");
    h_Top_bJetPt_region1_TrueBG->Draw("same");

    TLegend *l0 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->AddEntry(h_Top_bJetPt_region1_TrueBG, "True Background", "l");
    l0->AddEntry(h_Topee_bJetPt_region1_HMet, "Predicted", "l");
    //l0->AddEntry(h_Topee_bJetPt_region1_HMet, "HM apply fakerate (Top ee)", "l");
    // l0->AddEntry(h_Topemu_bJetPt_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Topee_bJetPt_region2_HMet->GetXaxis()->SetTitleSize(0);
    h_Topee_bJetPt_region2_HMet->GetXaxis()->SetLabelSize(0);

    h_Topee_bJetPt_region2_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_bJetPt_region2_HMet->GetXaxis()->SetTitle("Jet PT");

    h_Topee_bJetPt_region2_HMet->SetFillStyle(3001);
    h_Topee_bJetPt_region2_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetPt_region2_TrueBG->SetMarkerStyle(20);

    h_Topee_bJetPt_region2_HMet->Draw("h");
    h_Top_bJetPt_region2_TrueBG->Draw("same");
    //h_Topemu_bJetPt_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->AddEntry(h_Top_bJetPt_region2_TrueBG, "True Background", "l");
    l1->AddEntry(h_Topee_bJetPt_region2_HMet, "Predicted", "l");
    //l1->AddEntry(h_Topemu_bJetPt_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    gPad->SetLogy();

    c1->cd(3);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Topee_bJetPt_region3_HMet->GetXaxis()->SetTitleSize(0);
    h_Topee_bJetPt_region3_HMet->GetXaxis()->SetLabelSize(0);

    h_Topee_bJetPt_region3_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_bJetPt_region3_HMet->GetXaxis()->SetTitle("Jet PT");

    h_Topee_bJetPt_region3_HMet->SetFillStyle(3001);
    h_Topee_bJetPt_region3_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetPt_region3_TrueBG->SetMarkerStyle(20);

    h_Topee_bJetPt_region3_HMet->Draw("h");
    h_Top_bJetPt_region3_TrueBG->Draw(" same");
    //h_Topemu_bJetPt_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("b flavor, 2 < |#eta| < 2.5");
    l2->AddEntry(h_Top_bJetPt_region3_TrueBG, "True Background", "l");
    l2->AddEntry(h_Topee_bJetPt_region3_HMet, "Predicted", "l");
    //l2->AddEntry(h_Topemu_bJetPt_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();

    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_1 = (TH1F *)h_Top_bJetPt_region1_TrueBG->Clone("h_TrueBG_EEFR_bRatio_1");
    h_TrueBG_EEFR_bRatio_1->Divide(h_Topee_bJetPt_region1_HMet);
    h_TrueBG_EEFR_bRatio_1->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetTitle("Jet PT");
    h_TrueBG_EEFR_bRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_1->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_2 = (TH1F *)h_Top_bJetPt_region2_TrueBG->Clone("h_TrueBG_EEFR_bRatio_2");
    h_TrueBG_EEFR_bRatio_2->Divide(h_Topee_bJetPt_region2_HMet);
    h_TrueBG_EEFR_bRatio_2->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetTitle("Jet PT");
    h_TrueBG_EEFR_bRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_2->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_3 = (TH1F *)h_Top_bJetPt_region3_TrueBG->Clone("h_TrueBG_EEFR_bRatio_3");
    h_TrueBG_EEFR_bRatio_3->Divide(h_Topee_bJetPt_region3_HMet);
    h_TrueBG_EEFR_bRatio_3->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetTitle("Jet PT");
    h_TrueBG_EEFR_bRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_3->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_3->Draw("e");
    */

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetPt_region1_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetPt_region1_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetPt_region1_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region1_TrueBG->GetXaxis()->SetTitle("Jet PT");

    h_Topee_lJetPt_region1_HMet->SetFillStyle(3001);
    h_Topee_lJetPt_region1_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetPt_region1_TrueBG->SetMarkerStyle(20);

    h_Top_lJetPt_region1_TrueBG->Draw("h ");
    h_Topee_lJetPt_region1_HMet->Draw("h same");
    // h_Topemu_lJetPt_region1_HMet->Draw("same");

    TLegend *l0 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("light flavor, |#eta| < 1");
    l0->AddEntry(h_Top_lJetPt_region1_TrueBG, "True Background", "l");
    l0->AddEntry(h_Topee_lJetPt_region1_HMet, "Predicted", "l");
    // l0->AddEntry(h_Topemu_lJetPt_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetPt_region2_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetPt_region2_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetPt_region2_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region2_TrueBG->GetXaxis()->SetTitle("Jet PT");

    h_Topee_lJetPt_region2_HMet->SetFillStyle(3001);
    h_Topee_lJetPt_region2_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetPt_region2_TrueBG->SetMarkerStyle(20);

    h_Top_lJetPt_region2_TrueBG->Draw("h ");
    h_Topee_lJetPt_region2_HMet->Draw("h same");
    // h_Topemu_lJetPt_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor, 1 < |#eta| < 2");
    l1->AddEntry(h_Top_lJetPt_region2_TrueBG, "True Background", "l");
    l1->AddEntry(h_Topee_lJetPt_region2_HMet, "Predicted", "l");
    // l1->AddEntry(h_Topemu_lJetPt_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    gPad->SetLogy();

    c1->cd(3);
    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetPt_region3_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetPt_region3_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetPt_region3_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_region3_TrueBG->GetXaxis()->SetTitle("Jet PT");

    h_Topee_lJetPt_region3_HMet->SetFillStyle(3001);
    h_Topee_lJetPt_region3_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetPt_region3_TrueBG->SetMarkerStyle(20);

    h_Top_lJetPt_region3_TrueBG->Draw("h ");
    h_Topee_lJetPt_region3_HMet->Draw("h same");
    // h_Topemu_lJetPt_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->SetHeader("light flavor, 2 < |#eta| < 2.5");
    l2->AddEntry(h_Top_lJetPt_region3_TrueBG, "True Background", "l");
    l2->AddEntry(h_Topee_lJetPt_region3_HMet, "Predicted", "l");
    // l2->AddEntry(h_Topemu_lJetPt_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();

    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_1 = (TH1F *)h_Top_lJetPt_region1_TrueBG->Clone("h_TrueBG_EEFR_lRatio_1");
    h_TrueBG_EEFR_lRatio_1->Divide(h_Topee_lJetPt_region1_HMet);
    h_TrueBG_EEFR_lRatio_1->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetTitle("Jet PT");
    h_TrueBG_EEFR_lRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_1->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_2 = (TH1F *)h_Top_lJetPt_region2_TrueBG->Clone("h_TrueBG_EEFR_lRatio_2");
    h_TrueBG_EEFR_lRatio_2->Divide(h_Topee_lJetPt_region2_HMet);
    h_TrueBG_EEFR_lRatio_2->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetTitle("Jet PT");
    h_TrueBG_EEFR_lRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_2->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_3 = (TH1F *)h_Top_lJetPt_region3_TrueBG->Clone("h_TrueBG_EEFR_lRatio_3");
    h_TrueBG_EEFR_lRatio_3->Divide(h_Topee_lJetPt_region3_HMet);
    h_TrueBG_EEFR_lRatio_3->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetTitle("Jet PT");
    h_TrueBG_EEFR_lRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_3->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_3->Draw("e");
    */

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_bJetEta_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_bJetEta_TrueBG->GetXaxis()->SetTitle("Jet #eta");

    h_Top_bJetEta_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_bJetEta_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Topee_bJetEta_HMet->SetFillStyle(3001);
    h_Topee_bJetEta_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetEta_TrueBG->SetMarkerStyle(20);

    h_Top_bJetEta_TrueBG->Draw("h ");
    // h_Topemu_bJetEta_HMet->Draw("same");
    h_Topee_bJetEta_HMet->Draw("h same");

    c1->cd(2);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetEta_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_TrueBG->GetXaxis()->SetTitle("Jet #eta");

    h_Top_lJetEta_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetEta_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Topee_lJetEta_HMet->SetFillStyle(3001);
    h_Topee_lJetEta_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetEta_TrueBG->SetMarkerStyle(20);

    h_Top_lJetEta_TrueBG->Draw("h ");
    // h_Topemu_lJetEta_HMet->Draw("same");
    h_Topee_lJetEta_HMet->Draw("h same");



    c1->cd(3);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio = (TH1F *)h_Top_bJetEta_TrueBG->Clone("h_TrueBG_EEFR_bRatio");
    h_TrueBG_EEFR_bRatio->Divide(h_Topee_bJetEta_HMet);
    h_TrueBG_EEFR_bRatio->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio->GetXaxis()->SetTitle("Jet #eta");
    h_TrueBG_EEFR_bRatio->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio->Draw("e");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_bJetEta_TrueBG, "True Background", "l");
    l0->AddEntry(h_Topee_bJetEta_HMet, "Predicted", "l");
    // l0->AddEntry(h_Topemu_bJetEta_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio = (TH1F *)h_Top_lJetEta_TrueBG->Clone("h_TrueBG_EEFR_lRatio");
    h_TrueBG_EEFR_lRatio->Divide(h_Topee_lJetEta_HMet);
    h_TrueBG_EEFR_lRatio->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio->GetXaxis()->SetTitle("Jet #eta");
    h_TrueBG_EEFR_lRatio->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio->Draw("e");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetEta_TrueBG, "True Background", "l");
    l1->AddEntry(h_Topee_lJetEta_HMet, "Predicted", "l");
    // l1->AddEntry(h_Topemu_lJetEta_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    */

    /*
    c1->cd(1);

    h_Top_btrk_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_btrk_TrueBG->GetXaxis()->SetTitle("Track multiplicity");

    h_Top_btrk_TrueBG->Draw("h ");
    h_Topemu_btrk_HMet->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_btrk_TrueBG, "HM cut alpha", "l");
    //l0->AddEntry(h_Topee_bJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_btrk_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_ltrk_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_ltrk_TrueBG->GetXaxis()->SetTitle("Track multiplicity");

    h_Top_ltrk_TrueBG->Draw("h ");
    h_Topemu_ltrk_HMet->Draw("same");


    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetEta_TrueBG, "HM cut alpha", "l");
    //l1->AddEntry(h_Topee_lJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_ltrk_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    h_Topemu_bJetPt_HMet->GetYaxis()->SetTitle("nJet");
    h_Topemu_bJetPt_HMet->GetXaxis()->SetTitle("Jet PT");

    h_Topemu_bJetPt_HMet->Draw("");
    h_Top_bJetPt_TrueBG->Draw("h same");


    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_bJetPt_TrueBG, "HM cut alpha", "l");
    // l0->AddEntry(h_Topee_bJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_bJetPt_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_lJetPt_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetPt_TrueBG->GetXaxis()->SetTitle("Jet PT");

    h_Top_lJetPt_TrueBG->Draw("h ");
    h_Topemu_lJetPt_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetPt_TrueBG, "HM cut alpha", "l");
    // l1->AddEntry(h_Topee_lJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_lJetPt_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    */
    /*
    c1->cd(1);

    h_Topemu_bJetEta_noeta_HMet->GetYaxis()->SetTitle("nJet");
    h_Topemu_bJetEta_noeta_HMet->GetXaxis()->SetTitle("Jet #eta");

    h_Topemu_bJetEta_noeta_HMet->Draw("");
    h_Top_bJetEta_noeta_TrueBG->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_bJetEta_noeta_TrueBG, "HM cut alpha", "l");
    // l0->AddEntry(h_Topee_bJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l0->AddEntry(h_Topemu_bJetEta_noeta_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(2);

    h_Top_lJetEta_noeta_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_noeta_TrueBG->GetXaxis()->SetTitle("Jet #eta");

    h_Top_lJetEta_noeta_TrueBG->Draw("h ");
    h_Topemu_lJetEta_noeta_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetEta_noeta_TrueBG, "HM cut alpha", "l");
    // l1->AddEntry(h_Topee_lJetEta_HMet, "HM apply fakerate (Top ee)", "l");
    l1->AddEntry(h_Topemu_lJetEta_noeta_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    */
    // c1->Divide(2, 2);

    /*
    // Plot Ratio
    TH1F *h_cutalpha_applyfr_Ratio;
    h_cutalpha_applyfr_Ratio = (TH1F *)h_Top_bJetEta_noeta_TrueBG->Clone("h_cutalpha_applyfr_Ratio");
    h_cutalpha_applyfr_Ratio->Divide(h_Top_bJetEta_noeta_TrueBG, h_Topemu_bJetEta_noeta_HMet, 1, 1, "b");

    const double LABELSIZE = 20.0;
    c1->cd(1);

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Topemu_bJetEta_noeta_HMet->SetTitle("without consider eta");

    h_Topemu_bJetEta_noeta_HMet->GetYaxis()->SetTitle("nJet");
    h_Topemu_bJetEta_noeta_HMet->GetXaxis()->SetTitle("Jet #eta");
    h_Topemu_bJetEta_noeta_HMet->GetXaxis()->SetTitleSize(0);
    h_Topemu_bJetEta_noeta_HMet->GetXaxis()->SetLabelSize(0);

    h_Topemu_bJetEta_noeta_HMet->Draw("");
    h_Top_bJetEta_noeta_TrueBG->Draw("h same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("b flavor");
    l0->AddEntry(h_Top_bJetEta_noeta_TrueBG, "HM cut alpha", "l");
    l0->AddEntry(h_Topemu_bJetEta_noeta_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(3);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_cutalpha_applyfr_Ratio->GetYaxis()->SetTitle("cut alpha / apply FR");
    h_cutalpha_applyfr_Ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cutalpha_applyfr_Ratio->Draw("e1");

    c1->cd(2);
    TH1F *h_cutalpha_applyfr_diffeta_Ratio;
    h_cutalpha_applyfr_diffeta_Ratio = (TH1F *)h_Top_bJetEta_TrueBG->Clone("h_cutalpha_applyfr_diffeta_Ratio");
    h_cutalpha_applyfr_diffeta_Ratio->Divide(h_Top_bJetEta_TrueBG, h_Topemu_bJetEta_HMet, 1, 1, "b");

    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);


    h_Top_bJetEta_TrueBG->SetTitle("consider eta");

    h_Top_bJetEta_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_bJetEta_TrueBG->GetXaxis()->SetTitle("Jet #eta");
    h_Top_bJetEta_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_bJetEta_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_bJetEta_TrueBG->Draw("h ");
    h_Topemu_bJetEta_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("b flavor");
    l1->AddEntry(h_Top_bJetEta_TrueBG, "HM cut alpha", "l");
    l1->AddEntry(h_Topemu_bJetEta_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    c1->cd(4);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_cutalpha_applyfr_diffeta_Ratio->GetYaxis()->SetTitle("cut alpha / apply FR");
    h_cutalpha_applyfr_diffeta_Ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cutalpha_applyfr_diffeta_Ratio->Draw("e1");

    */

    // Plot Ratio
    /*
    TH1F *h_cutalpha_applyfr_Ratio;
    h_cutalpha_applyfr_Ratio = (TH1F *)h_Top_lJetEta_noeta_TrueBG->Clone("h_cutalpha_applyfr_Ratio");
    h_cutalpha_applyfr_Ratio->Divide(h_Top_lJetEta_noeta_TrueBG, h_Topemu_lJetEta_noeta_HMet, 1, 1, "b");

    const double LABELSIZE = 20.0;
    c1->cd(1);

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_lJetEta_noeta_TrueBG->SetTitle("without consider eta");

    h_Top_lJetEta_noeta_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_noeta_TrueBG->GetXaxis()->SetTitle("Jet #eta");
    h_Top_lJetEta_noeta_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetEta_noeta_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetEta_noeta_TrueBG->Draw("h ");
    h_Topemu_lJetEta_noeta_HMet->Draw("same");

    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->SetHeader("light flavor");
    l0->AddEntry(h_Top_lJetEta_noeta_TrueBG, "HM cut alpha", "l");
    l0->AddEntry(h_Topemu_lJetEta_noeta_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    c1->cd(3);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_cutalpha_applyfr_Ratio->GetYaxis()->SetTitle("cut alpha / apply FR");
    h_cutalpha_applyfr_Ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cutalpha_applyfr_Ratio->Draw("e1");

    c1->cd(2);
    TH1F *h_cutalpha_applyfr_diffeta_Ratio;
    h_cutalpha_applyfr_diffeta_Ratio = (TH1F *)h_Top_lJetEta_TrueBG->Clone("h_cutalpha_applyfr_diffeta_Ratio");
    h_cutalpha_applyfr_diffeta_Ratio->Divide(h_Top_lJetEta_TrueBG, h_Topemu_lJetEta_HMet, 1, 1, "b");

    double temp1_pad = gPad->GetWh() * gPad->GetAbsHNDC();
    double label1_size = LABELSIZE / temp1_pad;

    gPad->SetTopMargin(0 - 0.3);
    gPad->SetBottomMargin(0.02);
    gPad->SetRightMargin(0.04);

    h_Top_lJetEta_TrueBG->SetTitle("consider eta");

    h_Top_lJetEta_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetEta_TrueBG->GetXaxis()->SetTitle("Jet #eta");
    h_Top_lJetEta_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetEta_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetEta_TrueBG->Draw("h ");
    h_Topemu_lJetEta_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.45, 0.4, 0.80, 0.80);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->SetHeader("light flavor");
    l1->AddEntry(h_Top_lJetEta_TrueBG, "HM cut alpha", "l");
    l1->AddEntry(h_Topemu_lJetEta_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    c1->cd(4);
    gStyle->SetStatW(0.3);
    gStyle->SetStatH(0.3);
    gStyle->SetStatX(0.879447);
    gStyle->SetStatY(0.939033);
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatBorderSize(0);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    h_cutalpha_applyfr_diffeta_Ratio->GetYaxis()->SetTitle("cut alpha / apply FR");
    h_cutalpha_applyfr_diffeta_Ratio->GetXaxis()->SetTitle("Jet #eta");

    h_cutalpha_applyfr_diffeta_Ratio->Draw("e1");
    gStyle->SetOptStat(0);
    */

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Topee_bJetMass_region1_HMet->GetXaxis()->SetTitleSize(0);
    h_Topee_bJetMass_region1_HMet->GetXaxis()->SetLabelSize(0);

    h_Topee_bJetMass_region1_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_bJetMass_region1_HMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_bJetMass_region1_HMet->GetXaxis()->SetRangeUser(0, 80);

    h_Topee_bJetMass_region1_HMet->SetFillStyle(3001);
    h_Topee_bJetMass_region1_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetMass_region1_TrueBG->SetMarkerStyle(20);

    h_Topee_bJetMass_region1_HMet->Draw("h");
    // h_Topemu_bJetMass_region1_HMet->Draw("same");
    h_Top_bJetMass_region1_TrueBG->Draw("h same");

    TLegend *l0 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(h_Top_bJetMass_region1_TrueBG, "True Background", "l");
    l0->AddEntry(h_Topee_bJetMass_region1_HMet, "Predicted", "l");
    // l0->AddEntry(h_Topemu_bJetMass_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Topee_bJetMass_region2_HMet->GetXaxis()->SetTitleSize(0);
    h_Topee_bJetMass_region2_HMet->GetXaxis()->SetLabelSize(0);

    h_Topee_bJetMass_region2_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_bJetMass_region2_HMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_bJetMass_region2_HMet->GetXaxis()->SetRangeUser(0, 80);

    h_Topee_bJetMass_region2_HMet->SetFillStyle(3001);
    h_Topee_bJetMass_region2_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetMass_region2_TrueBG->SetMarkerStyle(20);

    h_Topee_bJetMass_region2_HMet->Draw("h");
    // h_Topemu_bJetMass_region2_HMet->Draw("same");
    h_Top_bJetMass_region2_TrueBG->Draw("h same");

    TLegend *l1 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_Top_bJetMass_region2_TrueBG, "True Background", "l");
    l1->AddEntry(h_Topee_bJetMass_region2_HMet, "Predicted", "l");
    // l1->AddEntry(h_Topemu_bJetMass_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    gPad->SetLogy();

    c1->cd(3);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Topee_bJetMass_region3_HMet->GetXaxis()->SetTitleSize(0);
    h_Topee_bJetMass_region3_HMet->GetXaxis()->SetLabelSize(0);

    h_Topee_bJetMass_region3_HMet->GetYaxis()->SetTitle("nJet");
    h_Topee_bJetMass_region3_HMet->GetXaxis()->SetTitle("Track multiplicity");

    h_Topee_bJetMass_region3_HMet->GetXaxis()->SetRangeUser(0, 80);

    h_Topee_bJetMass_region3_HMet->SetFillStyle(3001);
    h_Topee_bJetMass_region3_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetMass_region3_TrueBG->SetMarkerStyle(20);

    h_Topee_bJetMass_region3_HMet->Draw("h");
    // h_Topemu_bJetMass_region3_HMet->Draw("same");
    h_Top_bJetMass_region3_TrueBG->Draw("h same");

    TLegend *l2 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor,2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(h_Top_bJetMass_region3_TrueBG, "True Background", "l");
    l2->AddEntry(h_Topee_bJetMass_region3_HMet, "Predicted", "l");
    // l2->AddEntry(h_Topemu_bJetMass_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();

    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_1 = (TH1F *)h_Top_bJetMass_region1_TrueBG->Clone("h_TrueBG_EEFR_bRatio_1");
    h_TrueBG_EEFR_bRatio_1->Divide(h_Topee_bJetMass_region1_HMet);
    h_TrueBG_EEFR_bRatio_1->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetTitle("Jet Mass");
    h_TrueBG_EEFR_bRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetRangeUser(0., 80.);
    h_TrueBG_EEFR_bRatio_1->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_2 = (TH1F *)h_Top_bJetMass_region2_TrueBG->Clone("h_TrueBG_EEFR_bRatio_2");
    h_TrueBG_EEFR_bRatio_2->Divide(h_Topee_bJetMass_region2_HMet);
    h_TrueBG_EEFR_bRatio_2->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetTitle("Jet Mass");
    h_TrueBG_EEFR_bRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetRangeUser(0., 80.);
    h_TrueBG_EEFR_bRatio_2->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_3 = (TH1F *)h_Top_bJetMass_region3_TrueBG->Clone("h_TrueBG_EEFR_bRatio_3");
    h_TrueBG_EEFR_bRatio_3->Divide(h_Topee_bJetMass_region3_HMet);
    h_TrueBG_EEFR_bRatio_3->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetTitle("Jet Mass");
    h_TrueBG_EEFR_bRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetRangeUser(0., 80.);
    h_TrueBG_EEFR_bRatio_3->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_3->Draw("e");
    */
    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetMass_region1_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetMass_region1_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetMass_region1_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetMass_region1_TrueBG->GetXaxis()->SetTitle("Jet Mass");

    h_Top_lJetMass_region1_TrueBG->GetXaxis()->SetRangeUser(0, 80);

    h_Topee_lJetMass_region1_HMet->SetFillStyle(3001);
    h_Topee_lJetMass_region1_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetMass_region1_TrueBG->SetMarkerStyle(20);

    h_Top_lJetMass_region1_TrueBG->Draw("h ");
    h_Topee_lJetMass_region1_HMet->Draw("h same");
    // h_Topemu_lJetMass_region1_HMet->Draw("same");

    TLegend *l0 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l0->SetHeader("l flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(h_Top_lJetMass_region1_TrueBG, "True Background", "l");
    l0->AddEntry(h_Topee_lJetMass_region1_HMet, "Predicted", "l");
    // l0->AddEntry(h_Topemu_lJetMass_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();

    gPad->SetLogy();

    c1->cd(2);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetMass_region2_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetMass_region2_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetMass_region2_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetMass_region2_TrueBG->GetXaxis()->SetTitle("Jet Mass");

    h_Top_lJetMass_region2_TrueBG->GetXaxis()->SetRangeUser(0, 80);

    h_Topee_lJetMass_region2_HMet->SetFillStyle(3001);
    h_Topee_lJetMass_region2_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetMass_region2_TrueBG->SetMarkerStyle(20);

    h_Top_lJetMass_region2_TrueBG->Draw("h ");
    h_Topee_lJetMass_region2_HMet->Draw("h same");
    // h_Topemu_lJetMass_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l1->SetHeader("l flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_Top_lJetMass_region2_TrueBG, "True Background", "l");
    l1->AddEntry(h_Topee_lJetMass_region2_HMet, "Predicted", "l");
    // l1->AddEntry(h_Topemu_lJetMass_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();

    gPad->SetLogy();

    c1->cd(3);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetMass_region3_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetMass_region3_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetMass_region3_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetMass_region3_TrueBG->GetXaxis()->SetTitle("Jet Mass");

    h_Top_lJetMass_region3_TrueBG->GetXaxis()->SetRangeUser(0, 80);

    h_Topee_lJetMass_region3_HMet->SetFillStyle(3001);
    h_Topee_lJetMass_region3_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetMass_region3_TrueBG->SetMarkerStyle(20);

    h_Top_lJetMass_region3_TrueBG->Draw("h ");
    h_Topee_lJetMass_region3_HMet->Draw("h same");
    // h_Topemu_lJetMass_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l2->SetHeader("l flavor,2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(h_Top_lJetMass_region3_TrueBG, "True Background", "l");
    l2->AddEntry(h_Topee_lJetMass_region3_HMet, "Predicted", "l");
    // l2->AddEntry(h_Topemu_lJetMass_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();

    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_1 = (TH1F *)h_Top_lJetMass_region1_TrueBG->Clone("h_TrueBG_EEFR_lRatio_1");
    h_TrueBG_EEFR_lRatio_1->Divide(h_Topee_lJetMass_region1_HMet);
    h_TrueBG_EEFR_lRatio_1->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetTitle("Jet Mass");
    h_TrueBG_EEFR_lRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetRangeUser(0., 80.);
    h_TrueBG_EEFR_lRatio_1->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_2 = (TH1F *)h_Top_lJetMass_region2_TrueBG->Clone("h_TrueBG_EEFR_lRatio_2");
    h_TrueBG_EEFR_lRatio_2->Divide(h_Topee_lJetMass_region2_HMet);
    h_TrueBG_EEFR_lRatio_2->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetTitle("Jet Mass");
    h_TrueBG_EEFR_lRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetRangeUser(0., 80.);
    h_TrueBG_EEFR_lRatio_2->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_3 = (TH1F *)h_Top_lJetMass_region3_TrueBG->Clone("h_TrueBG_EEFR_lRatio_3");
    h_TrueBG_EEFR_lRatio_3->Divide(h_Topee_lJetMass_region3_HMet);
    h_TrueBG_EEFR_lRatio_3->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetTitle("Jet Mass");
    h_TrueBG_EEFR_lRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetRangeUser(0., 80.);
    h_TrueBG_EEFR_lRatio_3->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_3->Draw("e");

    */

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_bJetCsv_region1_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_bJetCsv_region1_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_bJetCsv_region1_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_bJetCsv_region1_TrueBG->GetXaxis()->SetTitle("Jet Csv");

    h_Topee_bJetCsv_region1_HMet->SetFillStyle(3001);
    h_Topee_bJetCsv_region1_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetCsv_region1_TrueBG->SetMarkerStyle(20);

    h_Top_bJetCsv_region1_TrueBG->Draw("h");
    h_Topee_bJetCsv_region1_HMet->Draw("h same");
    // h_Topemu_bJetCsv_region1_HMet->Draw("same");

    TLegend *l0 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l0->SetHeader("b flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(h_Top_bJetCsv_region1_TrueBG, "True Background", "l");
    l0->AddEntry(h_Topee_bJetCsv_region1_HMet, "Predicted", "l");
    // l0->AddEntry(h_Topemu_bJetCsv_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_bJetCsv_region2_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_bJetCsv_region2_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_bJetCsv_region2_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_bJetCsv_region2_TrueBG->GetXaxis()->SetTitle("Jet Csv");

    h_Topee_bJetCsv_region2_HMet->SetFillStyle(3001);
    h_Topee_bJetCsv_region2_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetCsv_region2_TrueBG->SetMarkerStyle(20);

    h_Top_bJetCsv_region2_TrueBG->Draw("h ");
    h_Topee_bJetCsv_region2_HMet->Draw("h same");
    // h_Topemu_bJetCsv_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l1->SetHeader("b flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_Top_bJetCsv_region2_TrueBG, "True Background", "l");
    l1->AddEntry(h_Topee_bJetCsv_region2_HMet, "Predicted", "l");
    // l1->AddEntry(h_Topemu_bJetCsv_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    gPad->SetLogy();

    c1->cd(3);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_bJetCsv_region3_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_bJetCsv_region3_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_bJetCsv_region3_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_bJetCsv_region3_TrueBG->GetXaxis()->SetTitle("Jet Csv");

    h_Topee_bJetCsv_region3_HMet->SetFillStyle(3001);
    h_Topee_bJetCsv_region3_HMet->SetFillColor(kGreen + 3);

    h_Top_bJetCsv_region3_TrueBG->SetMarkerStyle(20);

    h_Top_bJetCsv_region3_TrueBG->Draw("h ");
    h_Topee_bJetCsv_region3_HMet->Draw("h same");
    // h_Topemu_bJetCsv_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l2->SetHeader("b flavor,2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(h_Top_bJetCsv_region3_TrueBG, "True Background", "l");
    l2->AddEntry(h_Topee_bJetCsv_region3_HMet, "Predicted", "l");
    // l2->AddEntry(h_Topemu_bJetCsv_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();
    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_1 = (TH1F *)h_Top_bJetCsv_region1_TrueBG->Clone("h_TrueBG_EEFR_bRatio_1");
    h_TrueBG_EEFR_bRatio_1->Divide(h_Topee_bJetCsv_region1_HMet);
    h_TrueBG_EEFR_bRatio_1->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_1->GetXaxis()->SetTitle("Jet Csv");
    h_TrueBG_EEFR_bRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_1->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_2 = (TH1F *)h_Top_bJetCsv_region2_TrueBG->Clone("h_TrueBG_EEFR_bRatio_2");
    h_TrueBG_EEFR_bRatio_2->Divide(h_Topee_bJetCsv_region2_HMet);
    h_TrueBG_EEFR_bRatio_2->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_2->GetXaxis()->SetTitle("Jet Csv");
    h_TrueBG_EEFR_bRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_2->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_bRatio_3 = (TH1F *)h_Top_bJetCsv_region3_TrueBG->Clone("h_TrueBG_EEFR_bRatio_3");
    h_TrueBG_EEFR_bRatio_3->Divide(h_Topee_bJetCsv_region3_HMet);
    h_TrueBG_EEFR_bRatio_3->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_bRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_bRatio_3->GetXaxis()->SetTitle("Jet Csv");
    h_TrueBG_EEFR_bRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_bRatio_3->SetLineColor(kBlack);
    // h_High_Low_bRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_bRatio_3->Draw("e");

    */

    /*
    c1->cd(1);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetCsv_region1_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetCsv_region1_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetCsv_region1_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetCsv_region1_TrueBG->GetXaxis()->SetTitle("Jet Csv");

    h_Topee_lJetCsv_region1_HMet->SetFillStyle(3001);
    h_Topee_lJetCsv_region1_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetCsv_region1_TrueBG->SetMarkerStyle(20);

    h_Top_lJetCsv_region1_TrueBG->Draw("h");
    h_Topee_lJetCsv_region1_HMet->Draw("h same");
    // h_Topemu_lJetCsv_region1_HMet->Draw("same");

    TLegend *l0 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l0->SetHeader("l flavor, |#eta| < 1");
    l0->SetBorderSize(0);
    l0->SetFillStyle(0);
    l0->SetTextSize(0.04);
    l0->AddEntry(h_Top_lJetCsv_region1_TrueBG, "True Background", "l");
    l0->AddEntry(h_Topee_lJetCsv_region1_HMet, "Predicted", "l");
    // l0->AddEntry(h_Topemu_lJetCsv_region1_HMet, "HM apply fakerate (Top emu)", "l");
    l0->Draw();
    gPad->SetLogy();

    c1->cd(2);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetCsv_region2_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetCsv_region2_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetCsv_region2_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetCsv_region2_TrueBG->GetXaxis()->SetTitle("Jet Csv");

    h_Topee_lJetCsv_region2_HMet->SetFillStyle(3001);
    h_Topee_lJetCsv_region2_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetCsv_region2_TrueBG->SetMarkerStyle(20);

    h_Top_lJetCsv_region2_TrueBG->Draw("h ");
    h_Topee_lJetCsv_region2_HMet->Draw("h same");
    // h_Topemu_lJetCsv_region2_HMet->Draw("same");

    TLegend *l1 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l1->SetHeader("l flavor, 1 < |#eta| < 2");
    l1->SetBorderSize(0);
    l1->SetFillStyle(0);
    l1->SetTextSize(0.04);
    l1->AddEntry(h_Top_lJetCsv_region2_TrueBG, "True Background", "l");
    l1->AddEntry(h_Topee_lJetCsv_region2_HMet, "Predicted", "l");
    // l1->AddEntry(h_Topemu_lJetCsv_region2_HMet, "HM apply fakerate (Top emu)", "l");
    l1->Draw();
    gPad->SetLogy();

    c1->cd(3);

    gPad->SetTopMargin(0.01);
    gPad->SetBottomMargin(0.05);
    gPad->SetRightMargin(0.04);

    h_Top_lJetCsv_region3_TrueBG->GetXaxis()->SetTitleSize(0);
    h_Top_lJetCsv_region3_TrueBG->GetXaxis()->SetLabelSize(0);

    h_Top_lJetCsv_region3_TrueBG->GetYaxis()->SetTitle("nJet");
    h_Top_lJetCsv_region3_TrueBG->GetXaxis()->SetTitle("Jet Csv");

    h_Topee_lJetCsv_region3_HMet->SetFillStyle(3001);
    h_Topee_lJetCsv_region3_HMet->SetFillColor(kGreen + 3);

    h_Top_lJetCsv_region3_TrueBG->SetMarkerStyle(20);

    h_Top_lJetCsv_region3_TrueBG->Draw("h ");
    h_Topee_lJetCsv_region3_HMet->Draw("h same");
    // h_Topemu_lJetCsv_region3_HMet->Draw("same");

    TLegend *l2 = new TLegend(0.35, 0.4, 0.80, 0.80);
    l2->SetHeader("l flavor,2 < |#eta| < 2.5");
    l2->SetBorderSize(0);
    l2->SetFillStyle(0);
    l2->SetTextSize(0.04);
    l2->AddEntry(h_Top_lJetCsv_region3_TrueBG, "True Background", "l");
    l2->AddEntry(h_Topee_lJetCsv_region3_HMet, "Predicted", "l");
    // l2->AddEntry(h_Topemu_lJetCsv_region3_HMet, "HM apply fakerate (Top emu)", "l");
    l2->Draw();
    gPad->SetLogy();

    c1->cd(4);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_1 = (TH1F *)h_Top_lJetCsv_region1_TrueBG->Clone("h_TrueBG_EEFR_lRatio_1");
    h_TrueBG_EEFR_lRatio_1->Divide(h_Topee_lJetCsv_region1_HMet);
    h_TrueBG_EEFR_lRatio_1->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_1->GetXaxis()->SetTitle("Jet Csv");
    h_TrueBG_EEFR_lRatio_1->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_1->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_1->Draw("e");

    c1->cd(5);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_2 = (TH1F *)h_Top_lJetCsv_region2_TrueBG->Clone("h_TrueBG_EEFR_lRatio_2");
    h_TrueBG_EEFR_lRatio_2->Divide(h_Topee_lJetCsv_region2_HMet);
    h_TrueBG_EEFR_lRatio_2->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_2->GetXaxis()->SetTitle("Jet Csv");
    h_TrueBG_EEFR_lRatio_2->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_2->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_2->Draw("e");

    c1->cd(6);
    gPad->SetRightMargin(0.04);
    gPad->SetTopMargin(0);
    gPad->SetBottomMargin(0.2);
    gPad->SetTickx();

    TH1F *h_TrueBG_EEFR_lRatio_3 = (TH1F *)h_Top_lJetCsv_region3_TrueBG->Clone("h_TrueBG_EEFR_lRatio_3");
    h_TrueBG_EEFR_lRatio_3->Divide(h_Topee_lJetCsv_region3_HMet);
    h_TrueBG_EEFR_lRatio_3->GetYaxis()->SetTitle("True Background / Predicted");
    // h_High_Low_lRatio_1->GetXaxis()->SetTitle("Ratio");

    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetTitleSize(0.04);
    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetLabelSize(0.04);

    h_TrueBG_EEFR_lRatio_3->GetXaxis()->SetTitle("Jet Csv");
    h_TrueBG_EEFR_lRatio_3->GetYaxis()->SetRangeUser(0., 2.);
    h_TrueBG_EEFR_lRatio_3->SetLineColor(kBlack);
    // h_High_Low_lRatio_1->GetYaxis()->SetLabelSize(1);

    h_TrueBG_EEFR_lRatio_3->Draw("e");

    */

    gStyle->SetOptStat(0);
}