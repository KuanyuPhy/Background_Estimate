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
#include "TLegend.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "./../../lib/Cross_section.h"
using namespace std;

//------------------
// Calculate weight
//------------------
TFile *diboson_gg_ZZ_2e2mu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2mu.root");
TFile *diboson_gg_ZZ_2e2nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2nu.root");
TFile *diboson_gg_ZZ_2e2tau = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2e2tau.root");
TFile *diboson_gg_ZZ_2mu2nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2mu2nu.root");
TFile *diboson_gg_ZZ_2mu2tau = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_2mu2tau.root");
TFile *diboson_gg_ZZ_4e = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4e.root");
TFile *diboson_gg_ZZ_4mu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4mu.root");
TFile *diboson_gg_ZZ_4tau = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_ZZ_4tau.root");
TFile *diboson_gg_WW_2L2Nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_gg_WW_2L2Nu.root");
TFile *diboson_qq_WW_2L2Nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WW_2L2Nu.root");
TFile *diboson_qq_WZ_2L2Q = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WZ_2L2Q.root");
TFile *diboson_qq_WZ_3LNu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_WZ_3LNu.root");
TFile *diboson_qq_ZZ_2L2Nu = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_2L2Nu.root");
TFile *diboson_qq_ZZ_2L2Q = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_2L2Q.root");
TFile *diboson_qq_ZZ_4L = new TFile("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/diboson_qq_ZZ_4L.root");

TFile *dib_fakerate_dibfile = new TFile("./dib_fakerate.root");
TH1D *dib_nTrk_fakeRate_difeta_1 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_fakeRate_difeta_1"));
TH1D *dib_nTrk_bfakeRate_difeta_1 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_bfakeRate_difeta_1"));
TH1D *dib_nTrk_cfakeRate_difeta_1 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_cfakeRate_difeta_1"));
TH1D *dib_nTrk_lfakeRate_difeta_1 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_lfakeRate_difeta_1"));
TH1D *dib_nTrk_hfakeRate_difeta_1 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_hfakeRate_difeta_1"));

TH1D *dib_nTrk_fakeRate_difeta_2 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_fakeRate_difeta_2"));
TH1D *dib_nTrk_bfakeRate_difeta_2 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_bfakeRate_difeta_2"));
TH1D *dib_nTrk_cfakeRate_difeta_2 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_cfakeRate_difeta_2"));
TH1D *dib_nTrk_lfakeRate_difeta_2 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_lfakeRate_difeta_2"));
TH1D *dib_nTrk_hfakeRate_difeta_2 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_hfakeRate_difeta_2"));

TH1D *dib_nTrk_fakeRate_difeta_3 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_fakeRate_difeta_3"));
TH1D *dib_nTrk_bfakeRate_difeta_3 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_bfakeRate_difeta_3"));
TH1D *dib_nTrk_cfakeRate_difeta_3 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_cfakeRate_difeta_3"));
TH1D *dib_nTrk_lfakeRate_difeta_3 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_lfakeRate_difeta_3"));
TH1D *dib_nTrk_hfakeRate_difeta_3 = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_hfakeRate_difeta_3"));

TH1D *dib_nTrk_bfakeRate = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_bfakeRate"));
TH1D *dib_nTrk_cfakeRate = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_cfakeRate"));
TH1D *dib_nTrk_lfakeRate = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_lfakeRate"));
TH1D *dib_nTrk_hfakeRate = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_hfakeRate"));
TH1D *dib_nTrk_fakeRate = ((TH1D *)dib_fakerate_dibfile->Get("dib_nTrk_fakeRate"));

TH1D *gg_ZZ_2e2mu_sumevt = ((TH1D *)diboson_gg_ZZ_2e2mu->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_2e2nu_sumevt = ((TH1D *)diboson_gg_ZZ_2e2nu->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_2e2tau_sumevt = ((TH1D *)diboson_gg_ZZ_2e2tau->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_2mu2nu_sumevt = ((TH1D *)diboson_gg_ZZ_2mu2nu->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_2mu2tau_sumevt = ((TH1D *)diboson_gg_ZZ_2mu2tau->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_4e_sumevt = ((TH1D *)diboson_gg_ZZ_4e->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_4mu_sumevt = ((TH1D *)diboson_gg_ZZ_4mu->Get("Event_Variable/h_totevent"));
TH1D *gg_ZZ_4tau_sumevt = ((TH1D *)diboson_gg_ZZ_4tau->Get("Event_Variable/h_totevent"));
TH1D *gg_WW_2L2Nu_sumevt = ((TH1D *)diboson_gg_WW_2L2Nu->Get("Event_Variable/h_totevent"));
TH1D *qq_WW_2L2Nu_sumevt = ((TH1D *)diboson_qq_WW_2L2Nu->Get("Event_Variable/h_totevent"));
TH1D *qq_WZ_2L2Q_sumevt = ((TH1D *)diboson_qq_WZ_2L2Q->Get("Event_Variable/h_totevent"));
TH1D *qq_WZ_3LNu_sumevt = ((TH1D *)diboson_qq_WZ_3LNu->Get("Event_Variable/h_totevent"));
TH1D *qq_ZZ_2L2Nu_sumevt = ((TH1D *)diboson_qq_ZZ_2L2Nu->Get("Event_Variable/h_totevent"));
TH1D *qq_ZZ_2L2Q_sumevt = ((TH1D *)diboson_qq_ZZ_2L2Q->Get("Event_Variable/h_totevent"));
TH1D *qq_ZZ_4L_sumevt = ((TH1D *)diboson_qq_ZZ_4L->Get("Event_Variable/h_totevent"));

int gg_ZZ_2e2mu_totevt = gg_ZZ_2e2mu_sumevt->Integral();
int gg_ZZ_2e2nu_totevt = gg_ZZ_2e2nu_sumevt->Integral();
int gg_ZZ_2e2tau_totevt = gg_ZZ_2e2tau_sumevt->Integral();
int gg_ZZ_2mu2nu_totevt = gg_ZZ_2mu2nu_sumevt->Integral();
int gg_ZZ_2mu2tau_totevt = gg_ZZ_2mu2tau_sumevt->Integral();
int gg_ZZ_4e_totevt = gg_ZZ_4e_sumevt->Integral();
int gg_ZZ_4mu_totevt = gg_ZZ_4mu_sumevt->Integral();
int gg_ZZ_4tau_totevt = gg_ZZ_4tau_sumevt->Integral();
int gg_WW_2L2Nu_totevt = gg_WW_2L2Nu_sumevt->Integral();
int qq_WW_2L2Nu_totevt = qq_WW_2L2Nu_sumevt->Integral();
int qq_WZ_2L2Q_totevt = qq_WZ_2L2Q_sumevt->Integral();
int qq_WZ_3LNu_totevt = qq_WZ_3LNu_sumevt->Integral();
int qq_ZZ_2L2Nu_totevt = qq_ZZ_2L2Nu_sumevt->Integral();
int qq_ZZ_2L2Q_totevt = qq_ZZ_2L2Q_sumevt->Integral();
int qq_ZZ_4L_totevt = qq_ZZ_4L_sumevt->Integral();

//---------------------
// Define Diboson Weight
//---------------------
double diboson_gg_ZZ_2e2mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2mu / (gg_ZZ_2e2mu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2e2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2nu / (gg_ZZ_2e2nu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2e2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2e2tau / (gg_ZZ_2e2tau_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2mu2nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2nu / (gg_ZZ_2mu2nu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_2mu2tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_2mu2tau / (gg_ZZ_2mu2tau_totevt)) * 1000 * 2;
double diboson_gg_ZZ_4e_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4e / (gg_ZZ_4e_totevt)) * 1000 * 2;
double diboson_gg_ZZ_4mu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4mu / (gg_ZZ_4mu_totevt)) * 1000 * 2;
double diboson_gg_ZZ_4tau_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::gg_ZZ_4tau / (gg_ZZ_4tau_totevt)) * 1000 * 2;
double diboson_gg_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WW_2L2Nu / (gg_WW_2L2Nu_totevt)) * 1000 * 2;
double diboson_qq_WW_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_WW_2L2Nu_totevt)) * 1000 * 2;
double diboson_qq_WZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_2L2Q / (qq_WZ_2L2Q_totevt)) * 1000 * 2;
double diboson_qq_WZ_3LNu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_WZ_3LNu / (qq_WZ_3LNu_totevt)) * 1000 * 2;
double diboson_qq_ZZ_2L2Nu_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Nu / (qq_ZZ_2L2Nu_totevt)) * 1000 * 2;
double diboson_qq_ZZ_2L2Q_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_2L2Q / (qq_ZZ_2L2Q_totevt)) * 1000 * 2;
double diboson_qq_ZZ_4L_Weight = (GlobalConstants::Lumi2016) * (GlobalConstants::qq_ZZ_4L / (qq_ZZ_4L_totevt)) * 1000 * 2;

vector<double> v_xs_Weight = {diboson_gg_ZZ_2e2mu_Weight, diboson_gg_ZZ_2e2nu_Weight, diboson_gg_ZZ_2e2tau_Weight,
                              diboson_gg_ZZ_2mu2nu_Weight, diboson_gg_ZZ_2mu2tau_Weight, diboson_gg_ZZ_4e_Weight, diboson_gg_ZZ_4mu_Weight,
                              diboson_gg_ZZ_4tau_Weight, diboson_gg_WW_2L2Nu_Weight, diboson_qq_WW_2L2Nu_Weight, diboson_qq_WZ_2L2Q_Weight, diboson_qq_WZ_3LNu_Weight, diboson_qq_ZZ_2L2Nu_Weight, diboson_qq_ZZ_2L2Q_Weight, diboson_qq_ZZ_4L_Weight};
vector<const char *> v_diboson_filename = {"diboson_gg_ZZ_2e2mu", "diboson_gg_ZZ_2e2nu", "diboson_gg_ZZ_2e2tau",
                                           "diboson_gg_ZZ_2mu2nu", "diboson_gg_ZZ_2mu2tau", "diboson_gg_ZZ_4e", "diboson_gg_ZZ_4mu",
                                           "diboson_gg_ZZ_4tau", "diboson_gg_WW_2L2Nu", "diboson_qq_WW_2L2Nu", "diboson_qq_WZ_2L2Q", "diboson_qq_WZ_3LNu", "diboson_qq_ZZ_2L2Nu", "diboson_qq_ZZ_2L2Q", "diboson_qq_ZZ_4L"};
double getWeight(const char *file_name_tmp)
{
    TString file_name = file_name_tmp;
    for (int i = 0; i < v_diboson_filename.size(); i++)
    {
        if (file_name.Contains(v_diboson_filename[i]))
        {
            return v_xs_Weight[i];
        }
    }
    Fatal("getWeight", "%s is not a valid file", file_name_tmp);
    return -100000;
}
int getfakerate(float tmp1, float start, float Binwidth)
{
    int quotient;
    quotient = floor((tmp1 - start) / (Binwidth));

    return quotient + 1;
}
void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, int flavor2, int hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void Ratio_dib_apply(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *Dibosonfile = TFile::Open(file);
    cout << "Diboson weight = " << getWeight(file) << endl;
    //--------------------------------------
    //  nTrk : Not consider different eta
    //--------------------------------------
    TH1D *h_dib_trk_bybin_CR = new TH1D("h_dib_trk_bybin_CR", "", 30, 1, 30);
    h_dib_trk_bybin_CR->Sumw2();

    TH1D *h_dib_btrk_bybin_CR = new TH1D("h_dib_btrk_bybin_CR", "", 30, 1, 30);
    h_dib_btrk_bybin_CR->Sumw2();

    TH1D *h_dib_ctrk_bybin_CR = new TH1D("h_dib_ctrk_bybin_CR", "", 30, 1, 30);
    h_dib_ctrk_bybin_CR->Sumw2();

    TH1D *h_dib_ltrk_bybin_CR = new TH1D("h_dib_ltrk_bybin_CR", "", 30, 1, 30);
    h_dib_ltrk_bybin_CR->Sumw2();

    TH1D *h_dib_htrk_bybin_CR = new TH1D("h_dib_htrk_bybin_CR", "", 30, 1, 30);
    h_dib_htrk_bybin_CR->Sumw2();

    TH1D *h_dib_trk_SR = new TH1D("h_dib_trk_SR", "", 30, 1, 30);
    h_dib_trk_SR->Sumw2();

    TH1D *h_dib_btrk_SR = new TH1D("h_dib_btrk_SR", "", 30, 1, 30);
    h_dib_btrk_SR->Sumw2();

    TH1D *h_dib_ctrk_SR = new TH1D("h_dib_ctrk_SR", "", 30, 1, 30);
    h_dib_ctrk_SR->Sumw2();

    TH1D *h_dib_ltrk_SR = new TH1D("h_dib_ltrk_SR", "", 30, 1, 30);
    h_dib_ltrk_SR->Sumw2();

    TH1D *h_dib_htrk_SR = new TH1D("h_dib_htrk_SR", "", 30, 1, 30);
    h_dib_htrk_SR->Sumw2();

    //----------------------
    //  nTrk : different eta
    //----------------------
    TH1D *h_dib_trk_region1_bybin_CR = new TH1D("h_dib_trk_region1_bybin_CR", "", 30, 1, 30);
    h_dib_trk_region1_bybin_CR->Sumw2();
    TH1D *h_dib_trk_region2_bybin_CR = new TH1D("h_dib_trk_region2_bybin_CR", "", 30, 1, 30);
    h_dib_trk_region2_bybin_CR->Sumw2();
    TH1D *h_dib_trk_region3_bybin_CR = new TH1D("h_dib_trk_region3_bybin_CR", "", 30, 1, 30);
    h_dib_trk_region3_bybin_CR->Sumw2();

    TH1D *h_dib_btrk_region1_bybin_CR = new TH1D("h_dib_btrk_region1_bybin_CR", "", 30, 1, 30);
    h_dib_btrk_region1_bybin_CR->Sumw2();
    TH1D *h_dib_btrk_region2_bybin_CR = new TH1D("h_dib_btrk_region2_bybin_CR", "", 30, 1, 30);
    h_dib_btrk_region2_bybin_CR->Sumw2();
    TH1D *h_dib_btrk_region3_bybin_CR = new TH1D("h_dib_btrk_region3_bybin_CR", "", 30, 1, 30);
    h_dib_btrk_region3_bybin_CR->Sumw2();

    TH1D *h_dib_ctrk_region1_bybin_CR = new TH1D("h_dib_ctrk_region1_bybin_CR", "", 30, 1, 30);
    h_dib_ctrk_region1_bybin_CR->Sumw2();
    TH1D *h_dib_ctrk_region2_bybin_CR = new TH1D("h_dib_ctrk_region2_bybin_CR", "", 30, 1, 30);
    h_dib_ctrk_region2_bybin_CR->Sumw2();
    TH1D *h_dib_ctrk_region3_bybin_CR = new TH1D("h_dib_ctrk_region3_bybin_CR", "", 30, 1, 30);
    h_dib_ctrk_region3_bybin_CR->Sumw2();

    TH1D *h_dib_ltrk_region1_bybin_CR = new TH1D("h_dib_ltrk_region1_bybin_CR", "", 30, 1, 30);
    h_dib_ltrk_region1_bybin_CR->Sumw2();
    TH1D *h_dib_ltrk_region2_bybin_CR = new TH1D("h_dib_ltrk_region2_bybin_CR", "", 30, 1, 30);
    h_dib_ltrk_region2_bybin_CR->Sumw2();
    TH1D *h_dib_ltrk_region3_bybin_CR = new TH1D("h_dib_ltrk_region3_bybin_CR", "", 30, 1, 30);
    h_dib_ltrk_region3_bybin_CR->Sumw2();

    TH1D *h_dib_htrk_region1_bybin_CR = new TH1D("h_dib_htrk_region1_bybin_CR", "", 30, 1, 30);
    h_dib_htrk_region1_bybin_CR->Sumw2();
    TH1D *h_dib_htrk_region2_bybin_CR = new TH1D("h_dib_htrk_region2_bybin_CR", "", 30, 1, 30);
    h_dib_htrk_region2_bybin_CR->Sumw2();
    TH1D *h_dib_htrk_region3_bybin_CR = new TH1D("h_dib_htrk_region3_bybin_CR", "", 30, 1, 30);
    h_dib_htrk_region3_bybin_CR->Sumw2();

    TH1D *h_dib_trk_region1_SR = new TH1D("h_dib_trk_region1_SR", "", 30, 1, 30);
    h_dib_trk_region1_SR->Sumw2();
    TH1D *h_dib_trk_region2_SR = new TH1D("h_dib_trk_region2_SR", "", 30, 1, 30);
    h_dib_trk_region2_SR->Sumw2();
    TH1D *h_dib_trk_region3_SR = new TH1D("h_dib_trk_region3_SR", "", 30, 1, 30);
    h_dib_trk_region3_SR->Sumw2();

    TH1D *h_dib_btrk_region1_SR = new TH1D("h_dib_btrk_region1_SR", "", 30, 1, 30);
    h_dib_btrk_region1_SR->Sumw2();
    TH1D *h_dib_btrk_region2_SR = new TH1D("h_dib_btrk_region2_SR", "", 30, 1, 30);
    h_dib_btrk_region2_SR->Sumw2();
    TH1D *h_dib_btrk_region3_SR = new TH1D("h_dib_btrk_region3_SR", "", 30, 1, 30);
    h_dib_btrk_region3_SR->Sumw2();

    TH1D *h_dib_ctrk_region1_SR = new TH1D("h_dib_ctrk_region1_SR", "", 30, 1, 30);
    h_dib_ctrk_region1_SR->Sumw2();
    TH1D *h_dib_ctrk_region2_SR = new TH1D("h_dib_ctrk_region2_SR", "", 30, 1, 30);
    h_dib_ctrk_region2_SR->Sumw2();
    TH1D *h_dib_ctrk_region3_SR = new TH1D("h_dib_ctrk_region3_SR", "", 30, 1, 30);
    h_dib_ctrk_region3_SR->Sumw2();

    TH1D *h_dib_ltrk_region1_SR = new TH1D("h_dib_ltrk_region1_SR", "", 30, 1, 30);
    h_dib_ltrk_region1_SR->Sumw2();
    TH1D *h_dib_ltrk_region2_SR = new TH1D("h_dib_ltrk_region2_SR", "", 30, 1, 30);
    h_dib_ltrk_region2_SR->Sumw2();
    TH1D *h_dib_ltrk_region3_SR = new TH1D("h_dib_ltrk_region3_SR", "", 30, 1, 30);
    h_dib_ltrk_region3_SR->Sumw2();

    TH1D *h_dib_htrk_region1_SR = new TH1D("h_dib_htrk_region1_SR", "", 30, 1, 30);
    h_dib_htrk_region1_SR->Sumw2();
    TH1D *h_dib_htrk_region2_SR = new TH1D("h_dib_htrk_region2_SR", "", 30, 1, 30);
    h_dib_htrk_region2_SR->Sumw2();
    TH1D *h_dib_htrk_region3_SR = new TH1D("h_dib_htrk_region3_SR", "", 30, 1, 30);
    h_dib_htrk_region3_SR->Sumw2();

    Int_t I_Diboson_nJets;

    Int_t I_Diboson_weight;

    float_t f_Diboson_met;

    vector<float> *v_Diboson_alpha = new vector<float>();
    vector<float> *v_Diboson_Chi3Dlog = new vector<float>();
    vector<float> *v_Diboson_2DIP = new vector<float>();
    vector<float> *v_Diboson_nTrack = new vector<float>();
    vector<float> *v_Diboson_Jethadronflavor = new vector<float>();
    vector<float> *v_Diboson_Jetpartonflavor = new vector<float>();
    vector<float> *v_Diboson_JetPT = new vector<float>();
    vector<float> *v_Diboson_JetEta = new vector<float>();

    v_Diboson_alpha->clear();
    v_Diboson_Chi3Dlog->clear();
    v_Diboson_2DIP->clear();
    v_Diboson_nTrack->clear();
    v_Diboson_Jethadronflavor->clear();
    v_Diboson_Jetpartonflavor->clear();
    v_Diboson_JetPT->clear();
    v_Diboson_JetEta->clear();

    TTree *T_Diboson_tree;
    Dibosonfile->GetObject("h2", T_Diboson_tree);
    T_Diboson_tree->SetBranchAddress("I_weight", &I_Diboson_weight);
    T_Diboson_tree->SetBranchAddress("I_nJets", &I_Diboson_nJets);
    T_Diboson_tree->SetBranchAddress("v_N_Tracks", &v_Diboson_nTrack);
    T_Diboson_tree->SetBranchAddress("f_Met", &f_Diboson_met);
    T_Diboson_tree->SetBranchAddress("v_IP2D", &v_Diboson_2DIP);
    T_Diboson_tree->SetBranchAddress("v_Chi3Dlog", &v_Diboson_Chi3Dlog);
    T_Diboson_tree->SetBranchAddress("v_fakealpha", &v_Diboson_alpha);
    T_Diboson_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Diboson_Jethadronflavor);
    T_Diboson_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Diboson_Jetpartonflavor);
    T_Diboson_tree->SetBranchAddress("v_fakeJetPt", &v_Diboson_JetPT);
    T_Diboson_tree->SetBranchAddress("v_fakeJetEta", &v_Diboson_JetEta);
    for (int evt = 0; evt < T_Diboson_tree->GetEntries(); evt++)
    {
        T_Diboson_tree->GetEntry(evt);
        if (f_Diboson_met < 0)
        {
            cout << "bug" << endl;
            continue;
        }
        double Diboson_weight = getWeight(file) * I_Diboson_weight;
        double bxBinwidth = dib_nTrk_fakeRate->GetBinWidth(5);
        for (size_t i = 0; i < v_Diboson_nTrack->size(); i++)
        {
            int bxBin_local = getfakerate((*v_Diboson_nTrack)[i], 1., bxBinwidth);
            int cxBin_local = getfakerate((*v_Diboson_nTrack)[i], 1., bxBinwidth);
            int lxBin_local = getfakerate((*v_Diboson_nTrack)[i], 1., bxBinwidth);
            double fakerate = dib_nTrk_fakeRate->GetBinContent(bxBin_local) * Diboson_weight;
            double b_fakerate = dib_nTrk_bfakeRate->GetBinContent(bxBin_local) * Diboson_weight;
            double c_fakerate = dib_nTrk_cfakeRate->GetBinContent(bxBin_local) * Diboson_weight;
            double l_fakerate = dib_nTrk_lfakeRate->GetBinContent(bxBin_local) * Diboson_weight;
            double h_fakerate = dib_nTrk_hfakeRate->GetBinContent(bxBin_local) * Diboson_weight;

            h_dib_trk_bybin_CR->Fill((*v_Diboson_nTrack)[i], fakerate);
            for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], b_fakerate, h_dib_btrk_bybin_CR);
            for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], c_fakerate, h_dib_ctrk_bybin_CR);
            for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], l_fakerate, h_dib_ltrk_bybin_CR);
            for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], h_fakerate, h_dib_htrk_bybin_CR);

            if ((*v_Diboson_alpha)[i] < 0.1)
            {
                h_dib_trk_SR->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_btrk_SR);
                for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_ctrk_SR);
                for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_ltrk_SR);
                for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_htrk_SR);
            }
            //---------------------------------------------------------
            // Different eta
            //---------------------------------------------------------
            //  For Region |eta| < 1
            if (abs((*v_Diboson_JetEta)[i]) < 1)
            {
                h_dib_trk_region1_bybin_CR->Fill((*v_Diboson_nTrack)[i], fakerate);
                for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], b_fakerate, h_dib_btrk_region1_bybin_CR);
                for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], c_fakerate, h_dib_ctrk_region1_bybin_CR);
                for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], l_fakerate, h_dib_ltrk_region1_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], h_fakerate, h_dib_htrk_region1_bybin_CR);

                if ((*v_Diboson_alpha)[i] < 0.1)
                {
                    h_dib_trk_region1_SR->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                    for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_btrk_region1_SR);
                    for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_ctrk_region1_SR);
                    for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_ltrk_region1_SR);
                    for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_htrk_region1_SR);
                }
            }
            // For Region 1 < |eta| < 2
            else if (abs((*v_Diboson_JetEta)[i]) > 1 && abs((*v_Diboson_JetEta)[i]) < 2)
            {
                h_dib_trk_region2_bybin_CR->Fill((*v_Diboson_nTrack)[i], fakerate);
                for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], b_fakerate, h_dib_btrk_region2_bybin_CR);
                for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], c_fakerate, h_dib_ctrk_region2_bybin_CR);
                for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], l_fakerate, h_dib_ltrk_region2_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], h_fakerate, h_dib_htrk_region2_bybin_CR);

                if ((*v_Diboson_alpha)[i] < 0.1)
                {
                    h_dib_trk_region2_SR->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                    for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_btrk_region2_SR);
                    for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_ctrk_region2_SR);
                    for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_ltrk_region2_SR);
                    for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_htrk_region2_SR);
                }
            }
            // For Region 2 < |eta| < 2.5
            else if (abs((*v_Diboson_JetEta)[i]) > 2 && abs((*v_Diboson_JetEta)[i]) < 2.5)
            {
                h_dib_trk_region3_bybin_CR->Fill((*v_Diboson_nTrack)[i], fakerate);
                for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], b_fakerate, h_dib_btrk_region3_bybin_CR);
                for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], c_fakerate, h_dib_ctrk_region3_bybin_CR);
                for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], l_fakerate, h_dib_ltrk_region3_bybin_CR);
                for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], h_fakerate, h_dib_htrk_region3_bybin_CR);

                if ((*v_Diboson_alpha)[i] < 0.1)
                {
                    h_dib_trk_region3_SR->Fill((*v_Diboson_nTrack)[i], Diboson_weight);
                    for_signalflavor_jet(5, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_btrk_region3_SR);
                    for_signalflavor_jet(4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_ctrk_region3_SR);
                    for_signalflavor_jet(0, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_ltrk_region3_SR);
                    for_doubleflavor_jet(5, 4, (*v_Diboson_Jethadronflavor)[i], (*v_Diboson_nTrack)[i], Diboson_weight, h_dib_htrk_region3_SR);
                }
            }
        }
    }
    /*
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
    c1->Divide(3, 1);
    c1->cd(1);
    h_dib_ltrk_region1_SR->Draw();
    h_dib_ltrk_region1_bybin_CR->Draw("same");
    TLegend *l0 = new TLegend(0.45, 0.4, 0.80, 0.80);
    gStyle->SetOptStat(0);
    */
    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    h_dib_trk_bybin_CR->Write();
    h_dib_btrk_bybin_CR->Write();
    h_dib_ctrk_bybin_CR->Write();
    h_dib_ltrk_bybin_CR->Write();
    h_dib_htrk_bybin_CR->Write();
    h_dib_trk_SR->Write();
    h_dib_btrk_SR->Write();
    h_dib_ctrk_SR->Write();
    h_dib_ltrk_SR->Write();
    h_dib_htrk_SR->Write();
    h_dib_trk_region1_bybin_CR->Write();
    h_dib_trk_region2_bybin_CR->Write();
    h_dib_trk_region3_bybin_CR->Write();
    h_dib_btrk_region1_bybin_CR->Write();
    h_dib_btrk_region2_bybin_CR->Write();
    h_dib_btrk_region3_bybin_CR->Write();
    h_dib_ctrk_region1_bybin_CR->Write();
    h_dib_ctrk_region2_bybin_CR->Write();
    h_dib_ctrk_region3_bybin_CR->Write();
    h_dib_ltrk_region1_bybin_CR->Write();
    h_dib_ltrk_region2_bybin_CR->Write();
    h_dib_ltrk_region3_bybin_CR->Write();
    h_dib_htrk_region1_bybin_CR->Write();
    h_dib_htrk_region2_bybin_CR->Write();
    h_dib_htrk_region3_bybin_CR->Write();
    h_dib_trk_region1_SR->Write();
    h_dib_trk_region2_SR->Write();
    h_dib_trk_region3_SR->Write();
    h_dib_btrk_region1_SR->Write();
    h_dib_btrk_region2_SR->Write();
    h_dib_btrk_region3_SR->Write();
    h_dib_ctrk_region1_SR->Write();
    h_dib_ctrk_region2_SR->Write();
    h_dib_ctrk_region3_SR->Write();
    h_dib_ltrk_region1_SR->Write();
    h_dib_ltrk_region2_SR->Write();
    h_dib_ltrk_region3_SR->Write();
    h_dib_htrk_region1_SR->Write();
    h_dib_htrk_region2_SR->Write();
    h_dib_htrk_region3_SR->Write();
    outfile->Close();
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        Ratio_dib_apply();
    }
    else if (argc == 3)
    {
        Ratio_dib_apply(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}
