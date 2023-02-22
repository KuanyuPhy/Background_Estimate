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
#include "./../../../lib/Cross_section.h"
using namespace std;

//-------------------
// Create New class
//-------------------
class ThinJet
{
private:
    float jetflavor, jetpt, jeteta, jetalpha, jetntrk, jetmass, jetcsv;

public:
    ThinJet() {}
    ThinJet(const float &a, const float &b, const float &c, const float &d, const float &e, const float &f, const float &g) : jetflavor(a), jetpt(b), jeteta(c), jetalpha(d), jetntrk(e), jetmass(f), jetcsv(g) {}
    Float_t GetFlavor() const { return jetflavor; }
    Float_t GetPt() const { return jetpt; }
    Float_t GetEta() const { return jeteta; }
    Float_t GetAlpha() const { return jetalpha; }
    Float_t GetNtrk() const { return jetntrk; }
    Float_t GetMass() const { return jetmass; }
    Float_t GetCsv() const { return jetcsv; }

    friend ostream &operator<<(ostream &out, const ThinJet &foo)
    {
        return out << foo.jetflavor << " " << foo.jetpt << " " << foo.jeteta << " " << foo.jetalpha << " " << foo.jetntrk << "" << foo.jetmass << "" << foo.jetcsv << endl;
    }

    // greater() is used for JetPT
    friend bool operator>(const ThinJet &a, const ThinJet &b)
    {
        return a.GetPt() > b.GetPt();
    }
};

//------------------
// Calculate weight
//------------------
TFile *TTTo2L2Nufile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTTo2L2Nu.root");
TFile *Top_TTWJetsToLNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTWJetsToLNu.root");
TFile *Top_TTWJetsToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTWJetsToQQ.root");
TFile *Top_TTZToQQfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTZToQQ.root");
TFile *Top_TTZToLLNuNufile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_TTZToLLNuNu.root");
TFile *Top_tW_antitopfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_tW_antitop.root");
TFile *Top_tW_topfile = new TFile("/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/eu_top_emu_tW_top.root");

//----------------------
// Get fake rate
//----------------------
TFile *Top_emu_fakerate_topfile = new TFile("./../top_emu_fakerate.root");
TFile *Ratio_apply_file = new TFile("./../Ratio_apply.root");

//---------------------------
// Get Top to e mu fake rate
//---------------------------
// 1. For low dilepton PT region, fake rate(ntrk) without consider eta
TH1D *Top_nTrk_fakeRate_lowDilepPt = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_nTrk_fakeRate_lowDilepPt"));
// 2. For low dilepton PT region, fake rate(JetPt) without consider eta
TH1D *Top_JetPt_fakeRate_lowDilepPt = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_JetPt_fakeRate_lowDilepPt"));
// 3. For low dilepton PT region, fake rate(JetEta) without consider eta
TH1D *Top_JetEta_fakeRate_lowDilepPt = ((TH1D *)Top_emu_fakerate_topfile->Get("Top_JetEta_fakeRate_lowDilepPt"));

//-----------------------------------
// Get Top to e mu SR and all Region
//-----------------------------------
// 1. For low dilepton PT region, fake rate(ntrk) without consider eta
TH1D *h_Top_trk_LO_SR = ((TH1D *)Ratio_apply_file->Get("h_Top_trk_LO_SR"));
// 2. For low dilepton PT region, fake rate(JetPt) without consider eta
TH1D *h_Top_JetPt_LO_SR = ((TH1D *)Ratio_apply_file->Get("h_Top_JetPt_LO_SR"));
// 3. For low dilepton PT region, fake rate(JetEta) without consider eta
TH1D *h_Top_JetEta_LO_SR = ((TH1D *)Ratio_apply_file->Get("h_Top_JetEta_LO_SR"));

// 1. For low dilepton PT region, fake rate(ntrk) without consider eta
TH1D *h_Top_trk_LO_allR = ((TH1D *)Ratio_apply_file->Get("h_Top_trk_LO_bybin_CR"));
// 2. For low dilepton PT region, fake rate(JetPt) without consider eta
TH1D *h_Top_JetPt_LO_allR = ((TH1D *)Ratio_apply_file->Get("h_Top_JetPt_LO_bybin_CR"));
// 3. For low dilepton PT region, fake rate(JetEta) without consider eta
TH1D *h_Top_JetEta_LO_bybin_CR = ((TH1D *)Ratio_apply_file->Get("h_Top_JetEta_LO_bybin_CR"));

TH1D *TTTo2L2Nu_sumevt = ((TH1D *)TTTo2L2Nufile->Get("Event_Variable/h_totevent"));
TH1D *TTWJetsToLNu_sumevt = ((TH1D *)Top_TTWJetsToLNufile->Get("Event_Variable/h_totevent"));
TH1D *TTWJetsToQQ_sumevt = ((TH1D *)Top_TTWJetsToQQfile->Get("Event_Variable/h_totevent"));
TH1D *TTZToQQ_sumevt = ((TH1D *)Top_TTZToQQfile->Get("Event_Variable/h_totevent"));
TH1D *TTZToLLNuNu_sumevt = ((TH1D *)Top_TTZToLLNuNufile->Get("Event_Variable/h_totevent"));
TH1D *tW_antitop_sumevt = ((TH1D *)Top_tW_antitopfile->Get("Event_Variable/h_totevent"));
TH1D *tW_top_sumevt = ((TH1D *)Top_tW_topfile->Get("Event_Variable/h_totevent"));

int TTTo2L2Nu_totevt = TTTo2L2Nu_sumevt->Integral();
int TTWJetsToLNu_totevt = TTWJetsToLNu_sumevt->Integral();
int TTWJetsToQQ_totevt = TTWJetsToQQ_sumevt->Integral();
int TTZToQQ_totevt = TTZToQQ_sumevt->Integral();
int TTZToLLNuNu_totevt = TTZToLLNuNu_sumevt->Integral();
int tW_antitop_totevt = tW_antitop_sumevt->Integral();
int tW_top_totevt = tW_top_sumevt->Integral();

//---------------------
// Define TopWeight
//---------------------
double TTTo2L2NuWeight = (GlobalConstants::Lumi2016) * ((GlobalConstants::TTTo2L2Nu) / (TTTo2L2Nu_totevt)) * 1000 * 2;
double ST_tW_topWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_top_5fCS / (tW_top_totevt)) * 1000 * 2;
double ST_tW_antitopWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::ST_tW_antitop_5fCS / (tW_antitop_totevt)) * 1000 * 2;
double TTWJetsToLNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToLNu / (TTWJetsToLNu_totevt)) * 1000 * 2;
double TTWJetsToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTWJetsToQQ / (TTWJetsToQQ_totevt)) * 1000 * 2;
double TTZToQQWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToQQ / (TTZToQQ_totevt)) * 1000 * 2;
double TTZToLLNuNuWeight = (GlobalConstants::Lumi2016) * (GlobalConstants::TTZToLLNuNu / (TTZToLLNuNu_totevt)) * 1000 * 2;

vector<double> v_xs_Weight = {TTTo2L2NuWeight, ST_tW_topWeight, ST_tW_antitopWeight, TTWJetsToLNuWeight, TTWJetsToQQWeight, TTZToQQWeight, TTZToLLNuNuWeight};
vector<const char *> v_top_filename = {"TTTo2L2Nu", "tW_top", "tW_antitop", "TTWJetsToLNu", "TTWJetsToQQ", "TTZToQQ", "TTZToLLNuNu"};
double getWeight(const char *file_name_tmp)
{
    TString file_name = file_name_tmp;
    for (int i = 0; i < v_top_filename.size(); i++)
    {
        if (file_name.Contains(v_top_filename[i]))
        {
            return v_xs_Weight[i];
        }
    }
    Fatal("getWeight", "%s is not a valid file", file_name_tmp);
    return -100000;
}
//-------------------------------------------------------------
//    Fake rate cut bin information
//    const Int_t NBINS = 5;
//    Double_t edges[NBINS + 1] = {1., 5., 10., 15., 20., 40.};
//-------------------------------------------------------------

int get_eta_binfakerate(float tmp1, float start, float Binwidth)
{
    int quotient;
    quotient = floor((tmp1 - start) / (Binwidth));
    return quotient + 1;
}

void FR_Top_apply_LO()
{

    //----------------------------------
    // Define histogram bin information
    //----------------------------------
    const Int_t Ntrk_Nbins = 16;
    Double_t Ntrk_edges[Ntrk_Nbins + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13, 14, 15., 25., 40.};

    const Int_t NJet_Nbins = 10;
    Double_t NJet_edges[Ntrk_Nbins + 1] = {0., 30., 60., 90., 120., 150., 210., 270., 350., 450., 1500.};

    const Int_t JetPt_Nbins = 20.;
    Double_t JetPt_low_bound = 0.;
    Double_t JetPt_upper_bound = 1000.;

    const Int_t JetEta_Nbins = 30.;
    Double_t JetEta_low_bound = -3.;
    Double_t JetEta_upper_bound = 3.;

    //---------------------------------
    // For Control Region (predicted)
    //---------------------------------
    // ntrk
    // Not consider eta
    TH1D *h_Top_trk_bybin_CR = new TH1D("h_Top_trk_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_bybin_CR->Sumw2();

    TH1D *h_Top_btrk_bybin_CR = new TH1D("h_Top_btrk_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_btrk_bybin_CR->Sumw2();

    TH1D *h_Top_ltrk_bybin_CR = new TH1D("h_Top_ltrk_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_ltrk_bybin_CR->Sumw2();

    TH1D *h_Top_trk_LO_bybin_CR = new TH1D("h_Top_trk_LO_bybin_CR", "", Ntrk_Nbins, Ntrk_edges);
    h_Top_trk_LO_bybin_CR->Sumw2();

    // JetPT
    // Not consider eta
    TH1D *h_Top_JetPt_bybin_CR = new TH1D("h_Top_JetPt_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_bybin_CR->Sumw2();

    TH1D *h_Top_bJetPt_bybin_CR = new TH1D("h_Top_bJetPt_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_bJetPt_bybin_CR->Sumw2();

    TH1D *h_Top_lJetPt_bybin_CR = new TH1D("h_Top_lJetPt_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_lJetPt_bybin_CR->Sumw2();

    TH1D *h_Top_JetPt_LO_bybin_CR = new TH1D("h_Top_JetPt_LO_bybin_CR", "", NJet_Nbins, NJet_edges);
    h_Top_JetPt_LO_bybin_CR->Sumw2();

    TH1D *h_Top_JetEta_LO_CR = (TH1D *)Top_JetEta_fakeRate_lowDilepPt->Clone("h_Top_JetEta_LO_CR");

    h_Top_JetEta_LO_CR->Multiply(Top_JetEta_fakeRate_lowDilepPt, h_Top_JetEta_LO_bybin_CR);

    //TH1D *h_Top_JetPT_LO_CR = (TH1D *)Top_JetPT_fakeRate_lowDilepPt->Clone("h_Top_JetPT_LO_CR");


    h_Top_JetEta_LO_SR->SetLineColor(kRed);

    h_Top_JetEta_LO_SR->Draw();
    h_Top_JetEta_LO_CR->Draw("h same");
}
