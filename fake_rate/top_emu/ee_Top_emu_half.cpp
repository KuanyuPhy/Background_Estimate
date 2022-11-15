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

//---------------
// void Function
//---------------
void for_signalflavor_jet(int flavor, float hadronflavor, float tmp, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, int flavor2, int hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}
void ee_Top_emu_half(TString file = "tmp.root", TString outputfile = "output.root")
{
    TFile *Topfile = TFile::Open(file);
    cout << "Top weight = " << getWeight(file) << endl;
    //--------------------------------------------------------------
    // Hist: 0 : |eta| < 1, 1 : 1 < |eta| < 2, 2 : 2 < |eta| < 2.5
    //--------------------------------------------------------------
    TH1D *h_Top_nTrk_difeta[3];
    TH1D *h_Top_nTrk_cut_difeta[3];
    TH1D *h_Top_nTrk_bjet_difeta[3];
    TH1D *h_Top_nTrk_bjet_cut_difeta[3];
    TH1D *h_Top_nTrk_cjet_difeta[3];
    TH1D *h_Top_nTrk_cjet_cut_difeta[3];
    TH1D *h_Top_nTrk_ljet_difeta[3];
    TH1D *h_Top_nTrk_ljet_cut_difeta[3];
    TH1D *h_Top_nTrk_hjet_difeta[3];
    TH1D *h_Top_nTrk_hjet_cut_difeta[3];

    TH1D *h_Top_nTrk_bjet_difeta_lowMET[3];
    TH1D *h_Top_nTrk_bjet_cut_difeta_lowMET[3];
    TH1D *h_Top_nTrk_cjet_difeta_lowMET[3];
    TH1D *h_Top_nTrk_cjet_cut_difeta_lowMET[3];
    TH1D *h_Top_nTrk_ljet_difeta_lowMET[3];
    TH1D *h_Top_nTrk_ljet_cut_difeta_lowMET[3];

    TH1D *h_Top_nTrk_bjet_difeta_midMET[3];
    TH1D *h_Top_nTrk_bjet_cut_difeta_midMET[3];
    TH1D *h_Top_nTrk_cjet_difeta_midMET[3];
    TH1D *h_Top_nTrk_cjet_cut_difeta_midMET[3];
    TH1D *h_Top_nTrk_ljet_difeta_midMET[3];
    TH1D *h_Top_nTrk_ljet_cut_difeta_midMET[3];

    TH1D *h_Top_nTrk_bjet_difeta_highMET[3];
    TH1D *h_Top_nTrk_bjet_cut_difeta_highMET[3];
    TH1D *h_Top_nTrk_cjet_difeta_highMET[3];
    TH1D *h_Top_nTrk_cjet_cut_difeta_highMET[3];
    TH1D *h_Top_nTrk_ljet_difeta_highMET[3];
    TH1D *h_Top_nTrk_ljet_cut_difeta_highMET[3];

    // Separate for low dilepton PT and low PT
    TH1D *h_Top_nTrk_bjet_difeta_lowDilepPt[3];
    TH1D *h_Top_nTrk_bjet_cut_difeta_lowDilepPt[3];
    TH1D *h_Top_nTrk_ljet_difeta_lowDilepPt[3];
    TH1D *h_Top_nTrk_ljet_cut_difeta_lowDilepPt[3];

    TH1D *h_Top_nTrk_bjet_difeta_highDilepPt[3];
    TH1D *h_Top_nTrk_bjet_cut_difeta_highDilepPt[3];
    TH1D *h_Top_nTrk_ljet_difeta_highDilepPt[3];
    TH1D *h_Top_nTrk_ljet_cut_difeta_highDilepPt[3];

    const Int_t NBINS = 16;
    Double_t edges[NBINS + 1] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 12., 13, 14, 15., 25., 40.};

    for (int i = 0; i < 3; i++)
    {

        h_Top_nTrk_difeta[i] = new TH1D(Form("h_Top_nTrk_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_bjet_difeta[i] = new TH1D(Form("h_Top_nTrk_bjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_bjet_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_bjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cjet_difeta[i] = new TH1D(Form("h_Top_nTrk_cjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cjet_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_cjet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_ljet_difeta[i] = new TH1D(Form("h_Top_nTrk_ljet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_ljet_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_ljet_cut_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_hjet_difeta[i] = new TH1D(Form("h_Top_nTrk_hjet_difeta_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_hjet_cut_difeta[i] = new TH1D(Form("h_Top_nTrk_hjet_cut_difeta_%i", i + 1), "", 30, 1, 30);

        h_Top_nTrk_bjet_difeta_lowMET[i] = new TH1D(Form("h_Top_nTrk_bjet_difeta_lowMET_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_bjet_cut_difeta_lowMET[i] = new TH1D(Form("h_Top_nTrk_bjet_cut_difeta_lowMET_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_cjet_difeta_lowMET[i] = new TH1D(Form("h_Top_nTrk_cjet_difeta_lowMET_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cjet_cut_difeta_lowMET[i] = new TH1D(Form("h_Top_nTrk_cjet_cut_difeta_lowMET_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_ljet_difeta_lowMET[i] = new TH1D(Form("h_Top_nTrk_ljet_difeta_lowMET_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_ljet_cut_difeta_lowMET[i] = new TH1D(Form("h_Top_nTrk_ljet_cut_difeta_lowMET_%i", i + 1), "", NBINS, edges);

        h_Top_nTrk_bjet_difeta_midMET[i] = new TH1D(Form("h_Top_nTrk_bjet_difeta_midMET_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_bjet_cut_difeta_midMET[i] = new TH1D(Form("h_Top_nTrk_bjet_cut_difeta_midMET_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cjet_difeta_midMET[i] = new TH1D(Form("h_Top_nTrk_cjet_difeta_midMET_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cjet_cut_difeta_midMET[i] = new TH1D(Form("h_Top_nTrk_cjet_cut_difeta_midMET_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_ljet_difeta_midMET[i] = new TH1D(Form("h_Top_nTrk_ljet_difeta_midMET_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_ljet_cut_difeta_midMET[i] = new TH1D(Form("h_Top_nTrk_ljet_cut_difeta_midMET_%i", i + 1), "", 30, 1, 30);

        h_Top_nTrk_bjet_difeta_highMET[i] = new TH1D(Form("h_Top_nTrk_bjet_difeta_highMET_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_bjet_cut_difeta_highMET[i] = new TH1D(Form("h_Top_nTrk_bjet_cut_difeta_highMET_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_cjet_difeta_highMET[i] = new TH1D(Form("h_Top_nTrk_cjet_difeta_highMET_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_cjet_cut_difeta_highMET[i] = new TH1D(Form("h_Top_nTrk_cjet_cut_difeta_highMET_%i", i + 1), "", 30, 1, 30);
        h_Top_nTrk_ljet_difeta_highMET[i] = new TH1D(Form("h_Top_nTrk_ljet_difeta_highMET_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_ljet_cut_difeta_highMET[i] = new TH1D(Form("h_Top_nTrk_ljet_cut_difeta_highMET_%i", i + 1), "", NBINS, edges);

        h_Top_nTrk_bjet_difeta_lowDilepPt[i] = new TH1D(Form("h_Top_nTrk_bjet_difeta_lowDilepPt_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_bjet_cut_difeta_lowDilepPt[i] = new TH1D(Form("h_Top_nTrk_bjet_cut_difeta_lowDilepPt_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_ljet_difeta_lowDilepPt[i] = new TH1D(Form("h_Top_nTrk_ljet_difeta_lowDilepPt_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_ljet_cut_difeta_lowDilepPt[i] = new TH1D(Form("h_Top_nTrk_ljet_cut_difeta_lowDilepPt_%i", i + 1), "", NBINS, edges);

        h_Top_nTrk_bjet_difeta_highDilepPt[i] = new TH1D(Form("h_Top_nTrk_bjet_difeta_highDilepPt_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_bjet_cut_difeta_highDilepPt[i] = new TH1D(Form("h_Top_nTrk_bjet_cut_difeta_highDilepPt_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_ljet_difeta_highDilepPt[i] = new TH1D(Form("h_Top_nTrk_ljet_difeta_highDilepPt_%i", i + 1), "", NBINS, edges);
        h_Top_nTrk_ljet_cut_difeta_highDilepPt[i] = new TH1D(Form("h_Top_nTrk_ljet_cut_difeta_highDilepPt_%i", i + 1), "", NBINS, edges);

        h_Top_nTrk_difeta[i]->Sumw2();
        h_Top_nTrk_cut_difeta[i]->Sumw2();
        h_Top_nTrk_bjet_difeta[i]->Sumw2();
        h_Top_nTrk_bjet_cut_difeta[i]->Sumw2();
        h_Top_nTrk_cjet_difeta[i]->Sumw2();
        h_Top_nTrk_cjet_cut_difeta[i]->Sumw2();
        h_Top_nTrk_ljet_difeta[i]->Sumw2();
        h_Top_nTrk_ljet_cut_difeta[i]->Sumw2();
        h_Top_nTrk_hjet_difeta[i]->Sumw2();
        h_Top_nTrk_hjet_cut_difeta[i]->Sumw2();

        h_Top_nTrk_bjet_difeta_lowMET[i]->Sumw2();
        h_Top_nTrk_bjet_cut_difeta_lowMET[i]->Sumw2();
        h_Top_nTrk_cjet_difeta_lowMET[i]->Sumw2();
        h_Top_nTrk_cjet_cut_difeta_lowMET[i]->Sumw2();
        h_Top_nTrk_ljet_difeta_lowMET[i]->Sumw2();
        h_Top_nTrk_ljet_cut_difeta_lowMET[i]->Sumw2();

        h_Top_nTrk_bjet_difeta_midMET[i]->Sumw2();
        h_Top_nTrk_bjet_cut_difeta_midMET[i]->Sumw2();
        h_Top_nTrk_cjet_difeta_midMET[i]->Sumw2();
        h_Top_nTrk_cjet_cut_difeta_midMET[i]->Sumw2();
        h_Top_nTrk_ljet_difeta_midMET[i]->Sumw2();
        h_Top_nTrk_ljet_cut_difeta_midMET[i]->Sumw2();

        h_Top_nTrk_bjet_difeta_highMET[i]->Sumw2();
        h_Top_nTrk_bjet_cut_difeta_highMET[i]->Sumw2();
        h_Top_nTrk_cjet_difeta_highMET[i]->Sumw2();
        h_Top_nTrk_cjet_cut_difeta_highMET[i]->Sumw2();
        h_Top_nTrk_ljet_difeta_highMET[i]->Sumw2();
        h_Top_nTrk_ljet_cut_difeta_highMET[i]->Sumw2();

        h_Top_nTrk_bjet_difeta_lowDilepPt[i]->Sumw2();
        h_Top_nTrk_bjet_cut_difeta_lowDilepPt[i]->Sumw2();
        h_Top_nTrk_ljet_difeta_lowDilepPt[i]->Sumw2();
        h_Top_nTrk_ljet_cut_difeta_lowDilepPt[i]->Sumw2();

        h_Top_nTrk_bjet_difeta_highDilepPt[i]->Sumw2();
        h_Top_nTrk_bjet_cut_difeta_highDilepPt[i]->Sumw2();
        h_Top_nTrk_ljet_difeta_highDilepPt[i]->Sumw2();
        h_Top_nTrk_ljet_cut_difeta_highDilepPt[i]->Sumw2();
    }
    //-----------------------------
    // Not consider eta
    //-----------------------------
    TH1D *h_Top_nTrk_bjet = new TH1D("h_Top_nTrk_bjet", "", 30, 1, 30);
    TH1D *h_Top_nTrk_bjet_cut = new TH1D("h_Top_nTrk_bjet_cut", "", 30, 1, 30);
    TH1D *h_Top_nTrk_cjet = new TH1D("h_Top_nTrk_cjet", "", 30, 1, 30);
    TH1D *h_Top_nTrk_cjet_cut = new TH1D("h_Top_nTrk_cjet_cut", "", 30, 1, 30);
    TH1D *h_Top_nTrk_ljet = new TH1D("h_Top_nTrk_ljet", "", 30, 1, 30);
    TH1D *h_Top_nTrk_ljet_cut = new TH1D("h_Top_nTrk_ljet_cut", "", 30, 1, 30);
    TH1D *h_Top_nTrk_hjet = new TH1D("h_Top_nTrk_hjet", "", 30, 1, 30);
    TH1D *h_Top_nTrk_hjet_cut = new TH1D("h_Top_nTrk_hjet_cut", "", 30, 1, 30);

    TH1D *h_Top_nTrk_jet_lowDilepPt = new TH1D("h_Top_nTrk_jet_lowDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_jet_cut_lowDilepPt = new TH1D("h_Top_nTrk_jet_cut_lowDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_bjet_lowDilepPt = new TH1D("h_Top_nTrk_bjet_lowDilepPt", "", 50, 1, 50);
    TH1D *h_Top_nTrk_bjet_cut_lowDilepPt = new TH1D("h_Top_nTrk_bjet_cut_lowDilepPt", "", 50, 1, 50);
    TH1D *h_Top_nTrk_ljet_lowDilepPt = new TH1D("h_Top_nTrk_ljet_lowDilepPt", "", 50, 1, 50);
    TH1D *h_Top_nTrk_ljet_cut_lowDilepPt = new TH1D("h_Top_nTrk_ljet_cut_lowDilepPt", "", 50, 1, 50);

    TH1D *h_Top_nTrk_jet_highDilepPt = new TH1D("h_Top_nTrk_jet_highDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_jet_cut_highDilepPt = new TH1D("h_Top_nTrk_jet_cut_highDilepPt", "", NBINS, edges);
    TH1D *h_Top_nTrk_bjet_highDilepPt = new TH1D("h_Top_nTrk_bjet_highDilepPt", "", 50, 1, 50);
    TH1D *h_Top_nTrk_bjet_cut_highDilepPt = new TH1D("h_Top_nTrk_bjet_cut_highDilepPt", "", 50, 1, 50);
    TH1D *h_Top_nTrk_ljet_highDilepPt = new TH1D("h_Top_nTrk_ljet_highDilepPt", "", 50, 1, 50);
    TH1D *h_Top_nTrk_ljet_cut_highDilepPt = new TH1D("h_Top_nTrk_ljet_cut_highDilepPt", "", 50, 1, 50);

    h_Top_nTrk_bjet->Sumw2();
    h_Top_nTrk_bjet_cut->Sumw2();
    h_Top_nTrk_cjet->Sumw2();
    h_Top_nTrk_cjet_cut->Sumw2();
    h_Top_nTrk_ljet->Sumw2();
    h_Top_nTrk_ljet_cut->Sumw2();
    h_Top_nTrk_hjet->Sumw2();
    h_Top_nTrk_hjet_cut->Sumw2();

    h_Top_nTrk_bjet_lowDilepPt->Sumw2();
    h_Top_nTrk_bjet_cut_lowDilepPt->Sumw2();
    h_Top_nTrk_ljet_lowDilepPt->Sumw2();
    h_Top_nTrk_ljet_cut_lowDilepPt->Sumw2();

    h_Top_nTrk_bjet_highDilepPt->Sumw2();
    h_Top_nTrk_bjet_cut_highDilepPt->Sumw2();
    h_Top_nTrk_ljet_highDilepPt->Sumw2();
    h_Top_nTrk_ljet_cut_highDilepPt->Sumw2();

    //-----------------------------
    // Not consider flavor
    //-----------------------------
    TH1D *h_Top_nTrk = new TH1D("h_Top_nTrk", "", 30, 1, 30);
    TH1D *h_Top_nTrk_cut = new TH1D("h_Top_nTrk_cut", "", 30, 1, 30);
    h_Top_nTrk->Sumw2();
    h_Top_nTrk_cut->Sumw2();

    Int_t I_Top_nJets;

    Int_t I_Top_weight;

    float_t f_Top_met, f_Top_dileppt;

    vector<float> *v_Top_alpha = new vector<float>();
    vector<float> *v_Top_Chi3Dlog = new vector<float>();
    vector<float> *v_Top_2DIP = new vector<float>();
    vector<float> *v_Top_nTrack = new vector<float>();
    vector<float> *v_Top_Jethadronflavor = new vector<float>();
    vector<float> *v_Top_Jetpartonflavor = new vector<float>();
    vector<float> *v_Top_JetPT = new vector<float>();
    vector<float> *v_Top_JetEta = new vector<float>();
    vector<float> *v_Top_JetCsv = new vector<float>();
    vector<float> *v_Top_JetMass = new vector<float>();

    v_Top_alpha->clear();
    v_Top_Chi3Dlog->clear();
    v_Top_2DIP->clear();
    v_Top_nTrack->clear();
    v_Top_Jethadronflavor->clear();
    v_Top_Jetpartonflavor->clear();
    v_Top_JetPT->clear();
    v_Top_JetEta->clear();
    v_Top_JetCsv->clear();
    v_Top_JetMass->clear();

    float METcut = 130.;

    float DilepPTcut = 60.;

    TTree *T_Top_tree;
    Topfile->GetObject("h1", T_Top_tree);
    T_Top_tree->SetBranchAddress("I_weight", &I_Top_weight);
    T_Top_tree->SetBranchAddress("I_nJets", &I_Top_nJets);
    T_Top_tree->SetBranchAddress("v_N_Tracks", &v_Top_nTrack);
    T_Top_tree->SetBranchAddress("f_Met", &f_Top_met);
    T_Top_tree->SetBranchAddress("f_dileptonPT", &f_Top_dileppt);
    T_Top_tree->SetBranchAddress("v_IP2D", &v_Top_2DIP);
    T_Top_tree->SetBranchAddress("v_Chi3Dlog", &v_Top_Chi3Dlog);
    T_Top_tree->SetBranchAddress("v_fakealpha", &v_Top_alpha);
    T_Top_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Top_Jethadronflavor);
    T_Top_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Top_Jetpartonflavor);
    T_Top_tree->SetBranchAddress("v_fakeJetPt", &v_Top_JetPT);
    T_Top_tree->SetBranchAddress("v_fakeJetEta", &v_Top_JetEta);
    T_Top_tree->SetBranchAddress("v_fakeJetCSV", &v_Top_JetCsv);
    T_Top_tree->SetBranchAddress("v_fakeJetMass", &v_Top_JetMass);

    for (int evt = 0; evt < T_Top_tree->GetEntries(); evt++)
    {
        T_Top_tree->GetEntry(evt);
        if (f_Top_met < 0)
        {
            continue;
        }
        double Top_weight = getWeight(file) * I_Top_weight;
        // double Top_weight = 1.;
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks
        //-------------------------------------------------------------
        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;

        vector<ThinJet> v_thinjet;
        //-------------------------------------------------------------
        // Jet var : different flavor  nTracks
        //-------------------------------------------------------------
        for (size_t i = 0; i < v_Top_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], (*v_Top_JetEta)[i], (*v_Top_alpha)[i], (*v_Top_nTrack)[i], (*v_Top_JetMass)[i], (*v_Top_JetCsv)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());

        /*
        cout << "-------- No Sort ---------------" << endl;
        for (auto x : v_thinjet)
        {
            cout << "JetPT= " << x.GetPt() << endl;
        }
        */
        // cout << "-------- Start Sort ---------------" << endl;
        // sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());
        /*
        for (auto x : v_thinjet)
        {
            cout << "JetPT= " << x.GetPt() << endl;
        }
        cout << "END ------" << endl;
        */
        /*
        for (size_t i = 0; i < v_thinjet.size(); i++)
        {
            // Not Consider eta
            h_Top_nTrk_cut->Fill(v_thinjet[i].GetNtrk(), Top_weight);
            // b flavor
            for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet);
            // c flavor
            for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet);
            // l flavor
            for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet);
            if ((*v_Top_alpha)[i] < 0.15)
            {
                // Not Consider eta
                h_Top_nTrk_cut->Fill((*v_Top_nTrack)[i], Top_weight);
                //  For b jet
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_nTrk_bjet_cut);
                // For c jet
                for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_nTrk_cjet_cut);
                // For light flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_nTrk_ljet_cut);
                // For heavy flavor
                for_doubleflavor_jet(5, 4, (*v_Top_Jethadronflavor)[i], (*v_Top_nTrack)[i], Top_weight, h_Top_nTrk_hjet_cut);
            }
        }
        */

        if (f_Top_met < METcut)
        {
            for (size_t i = 0; i < v_thinjet.size(); i++)
            {
                /*
                if (v_thinjet[i].GetCsv() == -10)
                {
                    continue;
                }*/
                // Not Consider eta
                // b flavor
                for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet);
                // l flavor
                for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet);
                if ((*v_Top_alpha)[i] < 0.15)
                {
                    //  For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut);
                }

                //--------------------
                // Consider eta
                //--------------------
                // For Region |eta| < 1
                if (abs((*v_Top_JetEta)[i]) < 1)
                {
                    //  For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_lowMET[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_difeta_lowMET[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_lowMET[0]);
                    if ((*v_Top_alpha)[i] < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_lowMET[0]);
                        // For c jet
                        for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_cut_difeta_lowMET[0]);
                        // For light flavor
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_lowMET[0]);
                    }
                }
                // For Region 1 < |eta| < 2
                else if (abs((*v_Top_JetEta)[i]) > 1 && abs((*v_Top_JetEta)[i]) < 2)
                {
                    //  For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_lowMET[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_difeta_lowMET[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_lowMET[1]);
                    if ((*v_Top_alpha)[i] < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_lowMET[1]);
                        // For c jet
                        for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_cut_difeta_lowMET[1]);
                        // For light flavor
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_lowMET[1]);
                    }
                }
                // For Region 2 < |eta| < 2.5
                else if (abs((*v_Top_JetEta)[i]) > 2 && abs((*v_Top_JetEta)[i]) < 2.5)
                {
                    //  For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_lowMET[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_difeta_lowMET[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_lowMET[2]);
                    if ((*v_Top_alpha)[i] < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_lowMET[2]);
                        // For c jet
                        for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_cut_difeta_lowMET[2]);
                        // For light flavor
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_lowMET[2]);
                    }
                }
            }
        } // End MET < 130

        else if (f_Top_met > METcut)
        {
            for (size_t i = 0; i < v_thinjet.size(); i++)
            {
                //--------------------
                // Consider eta
                //--------------------
                // For Region |eta| < 1
                if (abs((*v_Top_JetEta)[i]) < 1)
                {
                    //  For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_highMET[0]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_difeta_highMET[0]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_highMET[0]);
                    if ((*v_Top_alpha)[i] < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_highMET[0]);
                        // For c jet
                        for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_cut_difeta_highMET[0]);
                        // For light flavor
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_highMET[0]);
                    }
                }
                // For Region 1 < |eta| < 2
                else if (abs((*v_Top_JetEta)[i]) > 1 && abs((*v_Top_JetEta)[i]) < 2)
                {
                    //  For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_highMET[1]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_difeta_highMET[1]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_highMET[1]);
                    if ((*v_Top_alpha)[i] < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_highMET[1]);
                        // For c jet
                        for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_cut_difeta_highMET[1]);
                        // For light flavor
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_highMET[1]);
                    }
                }
                // For Region 2 < |eta| < 2.5
                else if (abs((*v_Top_JetEta)[i]) > 2 && abs((*v_Top_JetEta)[i]) < 2.5)
                {
                    //  For b jet
                    for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_highMET[2]);
                    // For c jet
                    for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_difeta_highMET[2]);
                    // For light flavor
                    for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_highMET[2]);
                    if ((*v_Top_alpha)[i] < 0.15)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_highMET[2]);
                        // For c jet
                        for_signalflavor_jet(4, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_cjet_cut_difeta_highMET[2]);
                        // For light flavor
                        for_signalflavor_jet(0, (*v_Top_Jethadronflavor)[i], v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_highMET[2]);
                    }
                }
            } // End of for v_jet loop
        }     // End of Met > 130

        //----------------------------------------
        // Calculate fake rate base on dilepton PT
        //----------------------------------------
        if (f_Top_met > METcut)
        {
            if (f_Top_dileppt < DilepPTcut)
            {
                for (size_t i = 0; i < 2; i++)
                {
                    h_Top_nTrk_jet_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), Top_weight);
                    //  For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_lowDilepPt);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_lowDilepPt);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        h_Top_nTrk_jet_cut_lowDilepPt->Fill(v_thinjet[i].GetNtrk(), Top_weight);
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_lowDilepPt);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_lowDilepPt);
                    }
                    //--------------------
                    // Consider eta
                    //--------------------
                    // For Region |eta| < 1
                    if (abs(v_thinjet[i].GetEta()) <= 1)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_lowDilepPt[0]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_lowDilepPt[0]);
                        if (v_thinjet[i].GetAlpha() < 0.15)
                        {
                            //  For b jet
                            for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_lowDilepPt[0]);
                            // For light flavor
                            for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_lowDilepPt[0]);
                        }
                    }
                    // For Region 1 < |eta| < 2
                    else if (abs(v_thinjet[i].GetEta()) > 1 && abs(v_thinjet[i].GetEta()) <= 2)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_lowDilepPt[1]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_lowDilepPt[1]);
                        if (v_thinjet[i].GetAlpha() < 0.15)
                        {
                            //  For b jet
                            for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_lowDilepPt[1]);
                            // For light flavor
                            for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_lowDilepPt[1]);
                        }
                    }
                    // For Region 2 < |eta| < 2.5
                    else if (abs(v_thinjet[i].GetEta()) > 2 && abs(v_thinjet[i].GetEta()) <= 2.5)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_lowDilepPt[2]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_lowDilepPt[2]);
                        if (v_thinjet[i].GetAlpha() < 0.15)
                        {
                            //  For b jet
                            for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_lowDilepPt[2]);
                            // For light flavor
                            for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_lowDilepPt[2]);
                        }
                    }
                } // End of v_thinjet loop
            }     // End of low dilepton PT cut
            else
            {
                for (size_t i = 0; i < v_thinjet.size(); i++)
                {
                    h_Top_nTrk_jet_highDilepPt->Fill(v_thinjet[i].GetNtrk(), Top_weight);
                    //  For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_highDilepPt);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_highDilepPt);
                    if (v_thinjet[i].GetAlpha() < 0.15)
                    {
                        h_Top_nTrk_jet_cut_highDilepPt->Fill(v_thinjet[i].GetNtrk(), Top_weight);
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_highDilepPt);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_highDilepPt);
                    }
                    //--------------------
                    // Consider eta
                    //--------------------
                    // For Region |eta| < 1
                    if (abs(v_thinjet[i].GetEta()) <= 1)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_highDilepPt[0]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_highDilepPt[0]);
                        if (v_thinjet[i].GetAlpha() < 0.15)
                        {
                            //  For b jet
                            for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_highDilepPt[0]);
                            // For light flavor
                            for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_highDilepPt[0]);
                        }
                    }
                    // For Region 1 < |eta| < 2
                    else if (abs(v_thinjet[i].GetEta()) > 1 && abs(v_thinjet[i].GetEta()) <= 2)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_highDilepPt[1]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_highDilepPt[1]);
                        if (v_thinjet[i].GetAlpha() < 0.15)
                        {
                            //  For b jet
                            for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_highDilepPt[1]);
                            // For light flavor
                            for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_highDilepPt[1]);
                        }
                    }
                    // For Region 2 < |eta| < 2.5
                    else if (abs(v_thinjet[i].GetEta()) > 2 && abs(v_thinjet[i].GetEta()) <= 2.5)
                    {
                        //  For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_difeta_highDilepPt[2]);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_difeta_highDilepPt[2]);
                        if (v_thinjet[i].GetAlpha() < 0.15)
                        {
                            //  For b jet
                            for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_bjet_cut_difeta_highDilepPt[2]);
                            // For light flavor
                            for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_nTrk_ljet_cut_difeta_highDilepPt[2]);
                        }
                    }
                } // End of v_thinjet loop
            }     // End of high dilepton PT cut
        }         // End of MET cut

    } // End of Top loop

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();
    for (int i = 0; i < 3; i++)
    {
        h_Top_nTrk_difeta[i]->Write();
        h_Top_nTrk_cut_difeta[i]->Write();
        h_Top_nTrk_bjet_difeta[i]->Write();
        h_Top_nTrk_bjet_cut_difeta[i]->Write();
        h_Top_nTrk_cjet_difeta[i]->Write();
        h_Top_nTrk_cjet_cut_difeta[i]->Write();
        h_Top_nTrk_ljet_difeta[i]->Write();
        h_Top_nTrk_ljet_cut_difeta[i]->Write();
        h_Top_nTrk_hjet_difeta[i]->Write();
        h_Top_nTrk_hjet_cut_difeta[i]->Write();
        h_Top_nTrk_bjet_difeta_lowMET[i]->Write();
        h_Top_nTrk_bjet_cut_difeta_lowMET[i]->Write();
        h_Top_nTrk_cjet_difeta_lowMET[i]->Write();
        h_Top_nTrk_cjet_cut_difeta_lowMET[i]->Write();
        h_Top_nTrk_ljet_difeta_lowMET[i]->Write();
        h_Top_nTrk_ljet_cut_difeta_lowMET[i]->Write();

        h_Top_nTrk_bjet_difeta_midMET[i]->Write();
        h_Top_nTrk_bjet_cut_difeta_midMET[i]->Write();
        h_Top_nTrk_cjet_difeta_midMET[i]->Write();
        h_Top_nTrk_cjet_cut_difeta_midMET[i]->Write();
        h_Top_nTrk_ljet_difeta_midMET[i]->Write();
        h_Top_nTrk_ljet_cut_difeta_midMET[i]->Write();

        h_Top_nTrk_bjet_difeta_highMET[i]->Write();
        h_Top_nTrk_bjet_cut_difeta_highMET[i]->Write();
        h_Top_nTrk_cjet_difeta_highMET[i]->Write();
        h_Top_nTrk_cjet_cut_difeta_highMET[i]->Write();
        h_Top_nTrk_ljet_difeta_highMET[i]->Write();
        h_Top_nTrk_ljet_cut_difeta_highMET[i]->Write();

        h_Top_nTrk_bjet_difeta_lowDilepPt[i]->Write();
        h_Top_nTrk_bjet_cut_difeta_lowDilepPt[i]->Write();
        h_Top_nTrk_ljet_difeta_lowDilepPt[i]->Write();
        h_Top_nTrk_ljet_cut_difeta_lowDilepPt[i]->Write();

        h_Top_nTrk_bjet_difeta_highDilepPt[i]->Write();
        h_Top_nTrk_bjet_cut_difeta_highDilepPt[i]->Write();
        h_Top_nTrk_ljet_difeta_highDilepPt[i]->Write();
        h_Top_nTrk_ljet_cut_difeta_highDilepPt[i]->Write();
    }
    h_Top_nTrk_bjet->Write();
    h_Top_nTrk_ljet->Write();
    h_Top_nTrk_bjet_cut->Write();
    h_Top_nTrk_ljet_cut->Write();

    h_Top_nTrk_jet_lowDilepPt->Write();
    h_Top_nTrk_bjet_lowDilepPt->Write();
    h_Top_nTrk_ljet_lowDilepPt->Write();
    h_Top_nTrk_jet_cut_lowDilepPt->Write();
    h_Top_nTrk_bjet_cut_lowDilepPt->Write();
    h_Top_nTrk_ljet_cut_lowDilepPt->Write();

    h_Top_nTrk_jet_highDilepPt->Write();
    h_Top_nTrk_bjet_highDilepPt->Write();
    h_Top_nTrk_ljet_highDilepPt->Write();
    h_Top_nTrk_jet_cut_highDilepPt->Write();
    h_Top_nTrk_bjet_cut_highDilepPt->Write();
    h_Top_nTrk_ljet_cut_highDilepPt->Write();

    outfile->Close();

    // cout << getWeight(file) << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ee_Top_emu_half();
    }
    else if (argc == 3)
    {
        ee_Top_emu_half(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}