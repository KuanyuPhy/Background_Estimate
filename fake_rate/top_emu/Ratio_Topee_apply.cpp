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
#include "./../../lib/Cross_section.h"
using namespace std;

//-------------------
// Create New class
//-------------------
class ThinJet
{
private:
    float jetflavor, jetpt, jeteta, jetalpha, jetntrk;

public:
    ThinJet() {}
    ThinJet(const float &a, const float &b, const float &c, const float &d, const float &e) : jetflavor(a), jetpt(b), jeteta(c), jetalpha(d), jetntrk(e) {}
    Float_t GetFlavor() const { return jetflavor; }
    Float_t GetPt() const { return jetpt; }
    Float_t GetEta() const { return jeteta; }
    Float_t GetAlpha() const { return jetalpha; }
    Float_t GetNtrk() const { return jetntrk; }

    friend ostream &operator<<(ostream &out, const ThinJet &foo)
    {
        return out << foo.jetflavor << " " << foo.jetpt << " " << foo.jeteta << " " << foo.jetalpha << " " << foo.jetntrk << endl;
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
TFile *Topee_fakerate_topfile = new TFile("./../top/diffeta/new_macro/top_fakerate.root");
TFile *Topemu_fakerate_topfile = new TFile("./top_emu_fakerate.root");

TH1D *Topee_nTrk_bfakeRate_difeta_1_LM = ((TH1D *)Topee_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_1"));
TH1D *Topee_nTrk_lfakeRate_difeta_1_LM = ((TH1D *)Topee_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_1"));

TH1D *Topee_nTrk_bfakeRate_difeta_2_LM = ((TH1D *)Topee_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_2"));
TH1D *Topee_nTrk_lfakeRate_difeta_2_LM = ((TH1D *)Topee_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_2"));

TH1D *Topee_nTrk_bfakeRate_difeta_3_LM = ((TH1D *)Topee_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_3"));
TH1D *Topee_nTrk_lfakeRate_difeta_3_LM = ((TH1D *)Topee_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_3"));

TH1D *Topemu_nTrk_bfakeRate_LM = ((TH1D *)Topemu_fakerate_topfile->Get("Top_nTrk_bfakeRate_lowMET"));
TH1D *Topemu_nTrk_lfakeRate_LM = ((TH1D *)Topemu_fakerate_topfile->Get("Top_nTrk_lfakeRate_lowMET"));

TH1D *Topemu_nTrk_bfakeRate_difeta_1_LM = ((TH1D *)Topemu_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_1"));
TH1D *Topemu_nTrk_lfakeRate_difeta_1_LM = ((TH1D *)Topemu_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_1"));

TH1D *Topemu_nTrk_bfakeRate_difeta_2_LM = ((TH1D *)Topemu_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_2"));
TH1D *Topemu_nTrk_lfakeRate_difeta_2_LM = ((TH1D *)Topemu_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_2"));

TH1D *Topemu_nTrk_bfakeRate_difeta_3_LM = ((TH1D *)Topemu_fakerate_topfile->Get("Top_nTrk_bfakeRate_difeta_lowMET_3"));
TH1D *Topemu_nTrk_lfakeRate_difeta_3_LM = ((TH1D *)Topemu_fakerate_topfile->Get("Top_nTrk_lfakeRate_difeta_lowMET_3"));

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

int getfakerate(float tmp1, float start, float Binwidth)
{
    int quotient;
    quotient = floor((tmp1 - start) / (Binwidth));

    return quotient + 1;
}
//---------------
// void Function
//---------------
void for_signalflavor_jet2d(int flavor, float hadronflavor, float tmp1, float tmp2, double Weight, TH2D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp1, tmp2, Weight);
    }
}
void for_signalflavor_jet(int flavor, float hadronflavor, float tmp1, double Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor)
    {
        h_tmp->Fill(tmp1, Weight);
    }
}
void for_doubleflavor_jet(int flavor1, int flavor2, int hadronflavor, float tmp, float Weight, TH1D *h_tmp)
{
    if (hadronflavor == flavor1 || hadronflavor == flavor2)
    {
        h_tmp->Fill(tmp, Weight);
    }
}

void Ratio_Topee_apply(TString file = "/home/kuanyu/Documents/root_file/BgEstimation/top_TTTo2L2Nu_2.root", TString outputfile = "output.root")
{
    TFile *Topfile = TFile::Open(file);
    cout << "Top weight = " << getWeight(file) << endl;

    TH1D *h_Top_btrk_LMet = new TH1D("h_Top_btrk_LMet", "", 30, 1, 30);
    h_Top_btrk_LMet->Sumw2();
    TH1D *h_Top_ltrk_LMet = new TH1D("h_Top_ltrk_LMet", "", 30, 1, 30);
    h_Top_ltrk_LMet->Sumw2();

    TH1D *h_Top_bJetPt_LMet = new TH1D("h_Top_bJetPt_LMet", "", 50, 0., 500);
    h_Top_bJetPt_LMet->Sumw2();
    TH1D *h_Top_lJetPt_LMet = new TH1D("h_Top_lJetPt_LMet", "", 50, 0., 500);
    h_Top_lJetPt_LMet->Sumw2();

    TH1D *h_Top_bJetEta_noeta_LMet = new TH1D("h_Top_bJetEta_noeta_LMet", "", 30, -3., 3.);
    h_Top_bJetEta_noeta_LMet->Sumw2();
    TH1D *h_Top_lJetEta_noeta_LMet = new TH1D("h_Top_lJetEta_noeta_LMet", "", 30, -3., 3.);
    h_Top_lJetEta_noeta_LMet->Sumw2();

    TH1D *h_Topee_btrk_HMet = new TH1D("h_Topee_btrk_HMet", "", 30, 1, 30);
    h_Topee_btrk_HMet->Sumw2();
    TH1D *h_Topee_ltrk_HMet = new TH1D("h_Topee_ltrk_HMet", "", 30, 1, 30);
    h_Topee_ltrk_HMet->Sumw2();

    TH1D *h_Topee_bJetPt_HMet = new TH1D("h_Topee_bJetPt_HMet", "", 50, 0., 500);
    h_Topee_bJetPt_HMet->Sumw2();
    TH1D *h_Topee_lJetPt_HMet = new TH1D("h_Topee_lJetPt_HMet", "", 50, 0., 500);
    h_Topee_lJetPt_HMet->Sumw2();

    TH1D *h_Topee_bJetEta_noeta_HMet = new TH1D("h_Topee_bJetEta_noeta_HMet", "", 30, -3., 3.);
    h_Topee_bJetEta_noeta_HMet->Sumw2();
    TH1D *h_Topee_lJetEta_noeta_HMet = new TH1D("h_Topee_lJetEta_noeta_HMet", "", 30, -3., 3.);
    h_Topee_lJetEta_noeta_HMet->Sumw2();

    TH1D *h_Topemu_btrk_HMet = new TH1D("h_Topemu_btrk_HMet", "", 30, 1, 30);
    h_Topemu_btrk_HMet->Sumw2();
    TH1D *h_Topemu_ltrk_HMet = new TH1D("h_Topemu_ltrk_HMet", "", 30, 1, 30);
    h_Topemu_ltrk_HMet->Sumw2();

    TH1D *h_Topemu_bJetPt_HMet = new TH1D("h_Topemu_bJetPt_HMet", "", 50, 0., 500);
    h_Topemu_bJetPt_HMet->Sumw2();
    TH1D *h_Topemu_lJetPt_HMet = new TH1D("h_Topemu_lJetPt_HMet", "", 50, 0., 500);
    h_Topemu_lJetPt_HMet->Sumw2();

    TH1D *h_Topemu_bJetEta_noeta_HMet = new TH1D("h_Topemu_bJetEta_noeta_HMet", "", 30, -3., 3.);
    h_Topemu_bJetEta_noeta_HMet->Sumw2();
    TH1D *h_Topemu_lJetEta_noeta_HMet = new TH1D("h_Topemu_lJetEta_noeta_HMet", "", 30, -3., 3.);
    h_Topemu_lJetEta_noeta_HMet->Sumw2();

    //------------------------
    //  nTrk : different eta
    //------------------------
    TH1D *h_Top_btrk_region1_LMet = new TH1D("h_Top_btrk_region1_LMet", "", 30, 1, 30);
    h_Top_btrk_region1_LMet->Sumw2();

    TH1D *h_Top_btrk_region2_LMet = new TH1D("h_Top_btrk_region2_LMet", "", 30, 1, 30);
    h_Top_btrk_region2_LMet->Sumw2();

    TH1D *h_Top_btrk_region3_LMet = new TH1D("h_Top_btrk_region3_LMet", "", 30, 1, 30);
    h_Top_btrk_region3_LMet->Sumw2();

    TH1D *h_Top_ltrk_region1_LMet = new TH1D("h_Top_ltrk_region1_LMet", "", 30, 1, 30);
    h_Top_ltrk_region1_LMet->Sumw2();

    TH1D *h_Top_ltrk_region2_LMet = new TH1D("h_Top_ltrk_region2_LMet", "", 30, 1, 30);
    h_Top_ltrk_region2_LMet->Sumw2();

    TH1D *h_Top_ltrk_region3_LMet = new TH1D("h_Top_ltrk_region3_LMet", "", 30, 1, 30);
    h_Top_ltrk_region3_LMet->Sumw2();

    TH1D *h_Topee_btrk_region1_HMet = new TH1D("h_Topee_btrk_region1_HMet", "", 30, 1, 30);
    h_Topee_btrk_region1_HMet->Sumw2();

    TH1D *h_Topee_btrk_region2_HMet = new TH1D("h_Topee_btrk_region2_HMet", "", 30, 1, 30);
    h_Topee_btrk_region2_HMet->Sumw2();

    TH1D *h_Topee_btrk_region3_HMet = new TH1D("h_Topee_btrk_region3_HMet", "", 30, 1, 30);
    h_Topee_btrk_region3_HMet->Sumw2();

    TH1D *h_Topee_ltrk_region1_HMet = new TH1D("h_Topee_ltrk_region1_HMet", "", 30, 1, 30);
    h_Topee_ltrk_region1_HMet->Sumw2();

    TH1D *h_Topee_ltrk_region2_HMet = new TH1D("h_Topee_ltrk_region2_HMet", "", 30, 1, 30);
    h_Topee_ltrk_region2_HMet->Sumw2();

    TH1D *h_Topee_ltrk_region3_HMet = new TH1D("h_Topee_ltrk_region3_HMet", "", 30, 1, 30);
    h_Topee_ltrk_region3_HMet->Sumw2();

    TH1D *h_Topemu_btrk_region1_HMet = new TH1D("h_Topemu_btrk_region1_HMet", "", 30, 1, 30);
    h_Topemu_btrk_region1_HMet->Sumw2();

    TH1D *h_Topemu_btrk_region2_HMet = new TH1D("h_Topemu_btrk_region2_HMet", "", 30, 1, 30);
    h_Topemu_btrk_region2_HMet->Sumw2();

    TH1D *h_Topemu_btrk_region3_HMet = new TH1D("h_Topemu_btrk_region3_HMet", "", 30, 1, 30);
    h_Topemu_btrk_region3_HMet->Sumw2();

    TH1D *h_Topemu_ltrk_region1_HMet = new TH1D("h_Topemu_ltrk_region1_HMet", "", 30, 1, 30);
    h_Topemu_ltrk_region1_HMet->Sumw2();

    TH1D *h_Topemu_ltrk_region2_HMet = new TH1D("h_Topemu_ltrk_region2_HMet", "", 30, 1, 30);
    h_Topemu_ltrk_region2_HMet->Sumw2();

    TH1D *h_Topemu_ltrk_region3_HMet = new TH1D("h_Topemu_ltrk_region3_HMet", "", 30, 1, 30);
    h_Topemu_ltrk_region3_HMet->Sumw2();

    //--------------------
    //       JetPt
    //--------------------
    TH1D *h_Top_bJetPt_region1_LMet = new TH1D("h_Top_bJetPt_region1_LMet", "", 50, 0., 500);
    h_Top_bJetPt_region1_LMet->Sumw2();

    TH1D *h_Top_bJetPt_region2_LMet = new TH1D("h_Top_bJetPt_region2_LMet", "", 50, 0., 500);
    h_Top_bJetPt_region2_LMet->Sumw2();

    TH1D *h_Top_bJetPt_region3_LMet = new TH1D("h_Top_bJetPt_region3_LMet", "", 50, 0., 500);
    h_Top_bJetPt_region3_LMet->Sumw2();

    TH1D *h_Top_lJetPt_region1_LMet = new TH1D("h_Top_lJetPt_region1_LMet", "", 50, 0., 500);
    h_Top_lJetPt_region1_LMet->Sumw2();

    TH1D *h_Top_lJetPt_region2_LMet = new TH1D("h_Top_lJetPt_region2_LMet", "", 50, 0., 500);
    h_Top_lJetPt_region2_LMet->Sumw2();

    TH1D *h_Top_lJetPt_region3_LMet = new TH1D("h_Top_lJetPt_region3_LMet", "", 50, 0., 500);
    h_Top_lJetPt_region3_LMet->Sumw2();

    TH1D *h_Topee_bJetPt_region1_HMet = new TH1D("h_Topee_bJetPt_region1_HMet", "", 50, 0., 500);
    h_Topee_bJetPt_region1_HMet->Sumw2();

    TH1D *h_Topee_bJetPt_region2_HMet = new TH1D("h_Topee_bJetPt_region2_HMet", "", 50, 0., 500);
    h_Topee_bJetPt_region2_HMet->Sumw2();

    TH1D *h_Topee_bJetPt_region3_HMet = new TH1D("h_Topee_bJetPt_region3_HMet", "", 50, 0., 500);
    h_Topee_bJetPt_region3_HMet->Sumw2();

    TH1D *h_Topee_lJetPt_region1_HMet = new TH1D("h_Topee_lJetPt_region1_HMet", "", 50, 0., 500);
    h_Topee_lJetPt_region1_HMet->Sumw2();

    TH1D *h_Topee_lJetPt_region2_HMet = new TH1D("h_Topee_lJetPt_region2_HMet", "", 50, 0., 500);
    h_Topee_lJetPt_region2_HMet->Sumw2();

    TH1D *h_Topee_lJetPt_region3_HMet = new TH1D("h_Topee_lJetPt_region3_HMet", "", 50, 0., 500);
    h_Topee_lJetPt_region3_HMet->Sumw2();

    TH1D *h_Topemu_bJetPt_region1_HMet = new TH1D("h_Topemu_bJetPt_region1_HMet", "", 50, 0., 500);
    h_Topemu_bJetPt_region1_HMet->Sumw2();

    TH1D *h_Topemu_bJetPt_region2_HMet = new TH1D("h_Topemu_bJetPt_region2_HMet", "", 50, 0., 500);
    h_Topemu_bJetPt_region2_HMet->Sumw2();

    TH1D *h_Topemu_bJetPt_region3_HMet = new TH1D("h_Topemu_bJetPt_region3_HMet", "", 50, 0., 500);
    h_Topemu_bJetPt_region3_HMet->Sumw2();

    TH1D *h_Topemu_lJetPt_region1_HMet = new TH1D("h_Topemu_lJetPt_region1_HMet", "", 50, 0., 500);
    h_Topemu_lJetPt_region1_HMet->Sumw2();

    TH1D *h_Topemu_lJetPt_region2_HMet = new TH1D("h_Topemu_lJetPt_region2_HMet", "", 50, 0., 500);
    h_Topemu_lJetPt_region2_HMet->Sumw2();

    TH1D *h_Topemu_lJetPt_region3_HMet = new TH1D("h_Topemu_lJetPt_region3_HMet", "", 50, 0., 500);
    h_Topemu_lJetPt_region3_HMet->Sumw2();

    //--------------------
    //       JetEta
    //--------------------
    TH1D *h_Top_bJetEta_LMet = new TH1D("h_Top_bJetEta_LMet", "", 30, -3., 3.);
    h_Top_bJetEta_LMet->Sumw2();

    TH1D *h_Top_lJetEta_LMet = new TH1D("h_Top_lJetEta_LMet", "", 30, -3., 3.);
    h_Top_lJetEta_LMet->Sumw2();

    TH1D *h_Topee_bJetEta_HMet = new TH1D("h_Topee_bJetEta_HMet", "", 30, -3., 3.);
    h_Topee_bJetEta_HMet->Sumw2();

    TH1D *h_Topee_lJetEta_HMet = new TH1D("h_Topee_lJetEta_HMet", "", 30, -3., 3.);
    h_Topee_lJetEta_HMet->Sumw2();

    TH1D *h_Topemu_bJetEta_HMet = new TH1D("h_Topemu_bJetEta_HMet", "", 30, -3., 3.);
    h_Topemu_bJetEta_HMet->Sumw2();

    TH1D *h_Topemu_lJetEta_HMet = new TH1D("h_Topemu_lJetEta_HMet", "", 30, -3., 3.);
    h_Topemu_lJetEta_HMet->Sumw2();

    Int_t I_Top_nJets;

    Int_t I_Top_weight;

    float_t f_Top_met;

    vector<float> *v_Top_alpha = new vector<float>();
    vector<float> *v_Top_Chi3Dlog = new vector<float>();
    vector<float> *v_Top_2DIP = new vector<float>();
    vector<float> *v_Top_nTrack = new vector<float>();
    vector<float> *v_Top_Jethadronflavor = new vector<float>();
    vector<float> *v_Top_Jetpartonflavor = new vector<float>();
    vector<float> *v_Top_JetPT = new vector<float>();
    vector<float> *v_Top_JetEta = new vector<float>();

    v_Top_alpha->clear();
    v_Top_Chi3Dlog->clear();
    v_Top_2DIP->clear();
    v_Top_nTrack->clear();
    v_Top_Jethadronflavor->clear();
    v_Top_Jetpartonflavor->clear();
    v_Top_JetPT->clear();
    v_Top_JetEta->clear();

    TTree *T_Top_tree;
    Topfile->GetObject("h2", T_Top_tree);
    T_Top_tree->SetBranchAddress("I_weight", &I_Top_weight);
    T_Top_tree->SetBranchAddress("I_nJets", &I_Top_nJets);
    T_Top_tree->SetBranchAddress("v_N_Tracks", &v_Top_nTrack);
    T_Top_tree->SetBranchAddress("f_Met", &f_Top_met);
    T_Top_tree->SetBranchAddress("v_IP2D", &v_Top_2DIP);
    T_Top_tree->SetBranchAddress("v_Chi3Dlog", &v_Top_Chi3Dlog);
    T_Top_tree->SetBranchAddress("v_fakealpha", &v_Top_alpha);
    T_Top_tree->SetBranchAddress("v_fakeJethadronflavor", &v_Top_Jethadronflavor);
    T_Top_tree->SetBranchAddress("v_fakeJetpartonflavor", &v_Top_Jetpartonflavor);
    T_Top_tree->SetBranchAddress("v_fakeJetPt", &v_Top_JetPT);
    T_Top_tree->SetBranchAddress("v_fakeJetEta", &v_Top_JetEta);
    for (int evt = 0; evt < T_Top_tree->GetEntries(); evt++)
    {
        T_Top_tree->GetEntry(evt);
        if (f_Top_met < 0)
        {
            continue;
        }
        double Top_weight = getWeight(file) * I_Top_weight;
        // double Top_weight = 1.;

        double bxBinwidth = Topee_nTrk_bfakeRate_difeta_1_LM->GetBinWidth(5);

        // jetflavor, jetpt, jeteta, jetalpha, jetntrk;

        vector<ThinJet> v_thinjet;
        for (size_t i = 0; i < v_Top_nTrack->size(); i++)
        {
            v_thinjet.push_back(ThinJet((*v_Top_Jethadronflavor)[i], (*v_Top_JetPT)[i], (*v_Top_JetEta)[i], (*v_Top_alpha)[i], (*v_Top_nTrack)[i]));
        }
        sort(v_thinjet.begin(), v_thinjet.end(), greater<ThinJet>());

        for (size_t i = 0; i < v_thinjet.size(); i++)
        {
            // For Low MET region
            if (f_Top_met > 140)
            {
                if (v_thinjet[i].GetAlpha() < 0.15)
                {
                    // For trk
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_btrk_LMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_ltrk_LMet);
                    // For JetPt
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), Top_weight, h_Top_bJetPt_LMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), Top_weight, h_Top_lJetPt_LMet);

                    // For JetEta
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), Top_weight, h_Top_bJetEta_noeta_LMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), Top_weight, h_Top_lJetEta_noeta_LMet);

                    // For Region |eta| < 1
                    if (abs(v_thinjet[i].GetEta()) < 1)
                    {
                        // For trk
                        //   For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_btrk_region1_LMet);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_ltrk_region1_LMet);

                        // For JetPt
                        //   For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), Top_weight, h_Top_bJetPt_region1_LMet);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), Top_weight, h_Top_lJetPt_region1_LMet);

                        // For JetEta
                        //   For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), Top_weight, h_Top_bJetEta_LMet);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), Top_weight, h_Top_lJetEta_LMet);
                    }
                    // For Region 1 < |eta| < 2
                    else if (abs(v_thinjet[i].GetEta()) > 1 && abs(v_thinjet[i].GetEta()) < 2)
                    {
                        // For trk
                        //   For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_btrk_region2_LMet);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_ltrk_region2_LMet);

                        // For JetPt
                        //   For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), Top_weight, h_Top_bJetPt_region2_LMet);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), Top_weight, h_Top_lJetPt_region2_LMet);

                        // For JetEta
                        //   For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), Top_weight, h_Top_bJetEta_LMet);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), Top_weight, h_Top_lJetEta_LMet);
                    }
                    // For Region 2 < |eta| < 2.5
                    else if (abs(v_thinjet[i].GetEta()) > 2 && abs(v_thinjet[i].GetEta()) < 2.5)
                    {
                        // For trk
                        //   For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_btrk_region3_LMet);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), Top_weight, h_Top_ltrk_region3_LMet);

                        // For JetPt
                        //   For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), Top_weight, h_Top_bJetPt_region3_LMet);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), Top_weight, h_Top_lJetPt_region3_LMet);

                        // For JetEta
                        //   For b jet
                        for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), Top_weight, h_Top_bJetEta_LMet);
                        // For light flavor
                        for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), Top_weight, h_Top_lJetEta_LMet);
                    }
                }
            }
            // For High MET region apply Low MET fake rate
            if (f_Top_met > 140)
            {
                int bxBin_local = getfakerate(v_thinjet[i].GetNtrk(), 1., bxBinwidth);
                int cxBin_local = getfakerate(v_thinjet[i].GetNtrk(), 1., bxBinwidth);
                int lxBin_local = getfakerate(v_thinjet[i].GetNtrk(), 1., bxBinwidth);
                if (bxBin_local != cxBin_local)
                {
                    cout << "bxBin_local = " << bxBin_local << endl;
                    cout << "cxBin_local = " << cxBin_local << endl;
                    cout << "lxBin_local = " << lxBin_local << endl;
                }
                double b_FR = Topemu_nTrk_bfakeRate_LM->GetBinContent(bxBin_local) * Top_weight;
                double l_FR = Topemu_nTrk_lfakeRate_LM->GetBinContent(bxBin_local) * Top_weight;
                // For trk
                //   For b jet
                for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), b_FR, h_Topemu_btrk_HMet);
                // For light flavor
                for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), l_FR, h_Topemu_ltrk_HMet);

                // For JetPt
                //   For b jet
                for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), b_FR, h_Topemu_bJetPt_HMet);
                // For light flavor
                for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), l_FR, h_Topemu_lJetPt_HMet);

                // For JetEta
                //   For b jet
                for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), b_FR, h_Topemu_bJetEta_noeta_HMet);
                // For light flavor
                for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), l_FR, h_Topemu_lJetEta_noeta_HMet);

                // For Region |eta| < 1
                if (abs(v_thinjet[i].GetEta()) < 1)
                {
                    double b_fakerate = Topee_nTrk_bfakeRate_difeta_1_LM->GetBinContent(bxBin_local) * Top_weight;
                    double l_fakerate = Topee_nTrk_lfakeRate_difeta_1_LM->GetBinContent(bxBin_local) * Top_weight;
                    // For trk
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), b_fakerate, h_Topee_btrk_region1_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), l_fakerate, h_Topee_ltrk_region1_HMet);

                    // For JetPt
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), b_fakerate, h_Topee_bJetPt_region1_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), l_fakerate, h_Topee_lJetPt_region1_HMet);

                    // For JetEta
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), b_fakerate, h_Topee_bJetEta_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), l_fakerate, h_Topee_lJetEta_HMet);
                }
                // For Region 1 < |eta| < 2
                else if (abs(v_thinjet[i].GetEta()) > 1 && abs(v_thinjet[i].GetEta()) < 2)
                {
                    double b_fakerate = Topee_nTrk_bfakeRate_difeta_2_LM->GetBinContent(bxBin_local) * Top_weight;
                    double l_fakerate = Topee_nTrk_lfakeRate_difeta_2_LM->GetBinContent(bxBin_local) * Top_weight;
                    // For trk
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), b_fakerate, h_Topee_btrk_region2_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), l_fakerate, h_Topee_ltrk_region2_HMet);

                    // For JetPt
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), b_fakerate, h_Topee_bJetPt_region2_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), l_fakerate, h_Topee_lJetPt_region2_HMet);

                    // For JetEta
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), b_fakerate, h_Topee_bJetEta_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), l_fakerate, h_Topee_lJetEta_HMet);
                }
                // For Region 2 < |eta| < 2.5
                else if (abs(v_thinjet[i].GetEta()) > 2 && abs(v_thinjet[i].GetEta()) < 2.5)
                {
                    double b_fakerate = Topee_nTrk_bfakeRate_difeta_3_LM->GetBinContent(bxBin_local) * Top_weight;
                    double l_fakerate = Topee_nTrk_lfakeRate_difeta_3_LM->GetBinContent(bxBin_local) * Top_weight;
                    // For trk
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), b_fakerate, h_Topee_btrk_region3_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), l_fakerate, h_Topee_ltrk_region3_HMet);

                    // For JetPt
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), b_fakerate, h_Topee_bJetPt_region3_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), l_fakerate, h_Topee_lJetPt_region3_HMet);

                    // For JetEta
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), b_fakerate, h_Topee_bJetEta_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), l_fakerate, h_Topee_lJetEta_HMet);
                }
            }
            if (f_Top_met > 140)
            {
                int bxBin_local = getfakerate(v_thinjet[i].GetNtrk(), 1., bxBinwidth);
                int cxBin_local = getfakerate(v_thinjet[i].GetNtrk(), 1., bxBinwidth);
                int lxBin_local = getfakerate(v_thinjet[i].GetNtrk(), 1., bxBinwidth);
                if (bxBin_local != cxBin_local)
                {
                    cout << "bxBin_local = " << bxBin_local << endl;
                    cout << "cxBin_local = " << cxBin_local << endl;
                    cout << "lxBin_local = " << lxBin_local << endl;
                }
                // For Region |eta| < 1
                if (abs(v_thinjet[i].GetEta()) < 1)
                {
                    double b_fakerate = Topemu_nTrk_bfakeRate_difeta_1_LM->GetBinContent(bxBin_local) * Top_weight;
                    double l_fakerate = Topemu_nTrk_lfakeRate_difeta_1_LM->GetBinContent(bxBin_local) * Top_weight;
                    // For trk
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), b_fakerate, h_Topemu_btrk_region1_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), l_fakerate, h_Topemu_ltrk_region1_HMet);

                    // For JetPt
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), b_fakerate, h_Topemu_bJetPt_region1_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), l_fakerate, h_Topemu_lJetPt_region1_HMet);

                    // For JetEta
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), b_fakerate, h_Topemu_bJetEta_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), l_fakerate, h_Topemu_lJetEta_HMet);
                }
                // For Region 1 < |eta| < 2
                else if (abs(v_thinjet[i].GetEta()) > 1 && abs(v_thinjet[i].GetEta()) < 2)
                {
                    double b_fakerate = Topemu_nTrk_bfakeRate_difeta_2_LM->GetBinContent(bxBin_local) * Top_weight;
                    double l_fakerate = Topemu_nTrk_lfakeRate_difeta_2_LM->GetBinContent(bxBin_local) * Top_weight;
                    // For trk
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), b_fakerate, h_Topemu_btrk_region2_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), l_fakerate, h_Topemu_ltrk_region2_HMet);

                    // For JetPt
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), b_fakerate, h_Topemu_bJetPt_region2_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), l_fakerate, h_Topemu_lJetPt_region2_HMet);

                    // For JetEta
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), b_fakerate, h_Topemu_bJetEta_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), l_fakerate, h_Topemu_lJetEta_HMet);
                }
                // For Region 2 < |eta| < 2.5
                else if (abs(v_thinjet[i].GetEta()) > 2 && abs(v_thinjet[i].GetEta()) < 2.5)
                {
                    double b_fakerate = Topemu_nTrk_bfakeRate_difeta_3_LM->GetBinContent(bxBin_local) * Top_weight;
                    double l_fakerate = Topemu_nTrk_lfakeRate_difeta_3_LM->GetBinContent(bxBin_local) * Top_weight;
                    // For trk
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), b_fakerate, h_Topemu_btrk_region3_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetNtrk(), l_fakerate, h_Topemu_ltrk_region3_HMet);

                    // For JetPt
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), b_fakerate, h_Topemu_bJetPt_region3_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetPt(), l_fakerate, h_Topemu_lJetPt_region3_HMet);

                    // For JetEta
                    //   For b jet
                    for_signalflavor_jet(5, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), b_fakerate, h_Topemu_bJetEta_HMet);
                    // For light flavor
                    for_signalflavor_jet(0, v_thinjet[i].GetFlavor(), v_thinjet[i].GetEta(), l_fakerate, h_Topemu_lJetEta_HMet);
                }
            }
        }
    } // End of Top loop

    TFile *outfile = TFile::Open(outputfile, "RECREATE");
    outfile->cd();

    h_Top_btrk_region1_LMet->Write();

    h_Top_btrk_region2_LMet->Write();

    h_Top_btrk_region3_LMet->Write();

    h_Top_ltrk_region1_LMet->Write();

    h_Top_ltrk_region2_LMet->Write();

    h_Top_ltrk_region3_LMet->Write();

    h_Topee_btrk_region1_HMet->Write();

    h_Topee_btrk_region2_HMet->Write();

    h_Topee_btrk_region3_HMet->Write();

    h_Topee_ltrk_region1_HMet->Write();

    h_Topee_ltrk_region2_HMet->Write();

    h_Topee_ltrk_region3_HMet->Write();

    h_Top_bJetPt_region1_LMet->Write();

    h_Top_bJetPt_region2_LMet->Write();

    h_Top_bJetPt_region3_LMet->Write();

    h_Top_lJetPt_region1_LMet->Write();

    h_Top_lJetPt_region2_LMet->Write();

    h_Top_lJetPt_region3_LMet->Write();

    h_Topee_bJetPt_region1_HMet->Write();

    h_Topee_bJetPt_region2_HMet->Write();

    h_Topee_bJetPt_region3_HMet->Write();

    h_Topee_lJetPt_region1_HMet->Write();

    h_Topee_lJetPt_region2_HMet->Write();

    h_Topee_lJetPt_region3_HMet->Write();

    h_Top_bJetEta_LMet->Write();

    h_Top_lJetEta_LMet->Write();

    h_Topee_bJetEta_HMet->Write();

    h_Topee_lJetEta_HMet->Write();

    h_Topemu_btrk_region1_HMet->Write();

    h_Topemu_btrk_region2_HMet->Write();

    h_Topemu_btrk_region3_HMet->Write();

    h_Topemu_ltrk_region1_HMet->Write();

    h_Topemu_ltrk_region2_HMet->Write();

    h_Topemu_ltrk_region3_HMet->Write();

    h_Topemu_bJetPt_region1_HMet->Write();

    h_Topemu_bJetPt_region2_HMet->Write();

    h_Topemu_bJetPt_region3_HMet->Write();

    h_Topemu_lJetPt_region1_HMet->Write();

    h_Topemu_lJetPt_region2_HMet->Write();

    h_Topemu_lJetPt_region3_HMet->Write();

    h_Topemu_bJetEta_HMet->Write();

    h_Topemu_lJetEta_HMet->Write();

    h_Top_btrk_LMet->Write();
    h_Top_ltrk_LMet->Write();
    h_Top_bJetPt_LMet->Write();
    h_Top_lJetPt_LMet->Write();
    h_Top_bJetEta_noeta_LMet->Write();
    h_Top_lJetEta_noeta_LMet->Write();
    h_Topee_btrk_HMet->Write();
    h_Topee_ltrk_HMet->Write();
    h_Topee_bJetPt_HMet->Write();
    h_Topee_lJetPt_HMet->Write();
    h_Topee_bJetEta_noeta_HMet->Write();
    h_Topee_lJetEta_noeta_HMet->Write();
    h_Topemu_btrk_HMet->Write();
    h_Topemu_ltrk_HMet->Write();
    h_Topemu_bJetPt_HMet->Write();
    h_Topemu_lJetPt_HMet->Write();
    h_Topemu_bJetEta_noeta_HMet->Write();
    h_Topemu_lJetEta_noeta_HMet->Write();
    outfile->Close();
    // h_Top_JetPt_bjet_SR->Draw();

    // cout << getWeight(file) << endl;
    // cout << "TTTo2L2NuWeight = " << TTTo2L2NuWeight << endl;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        Ratio_Topee_apply();
    }
    else if (argc == 3)
    {
        Ratio_Topee_apply(argv[1], argv[2]);
    }
    else
    {
        cout << "argc" << argc << endl;
        cout << "ERROR" << endl;
    }
}