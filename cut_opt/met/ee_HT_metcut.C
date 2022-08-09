#include "TFile.h"
#include <iostream>
#include "TTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <TH1D.h>
#include <string>
#include <TAttLine.h>
#include <TStyle.h>
#include "./../../../lib/Cross_section.h"
using namespace std;

void ee_HT_metcut(TString inputfile = "tmp", TString outputfile = "./tmp.root")
{

    TFile *File = TFile::Open(inputfile);
    TTree *originalTree;
    File->GetObject("T_tree", originalTree);
    TH1D *h_HT_eventCout_copyed = ((TH1D *)File->Get("Event_Variable/h_HT_eventCout"));
    TH1D *h_sumevt_copyed = ((TH1D *)File->Get("Event_Variable/h_totevent"));

    TFile *outfile = new TFile(outputfile, "RECREATE");
    TTree *selectedTree = originalTree->CopyTree("f_Met>140.");
    TH1D *h_HT_eventCout = (TH1D*)h_HT_eventCout_copyed->Clone("h_HT_eventCout");
    TH1D *h_totevent = (TH1D*)h_sumevt_copyed->Clone("h_totevent");
    outfile->cd();
    selectedTree->Write();
    outfile->mkdir("Event_Variable", "Event_Variable")->cd();
    h_HT_eventCout->Write();
    h_totevent->Write();
    outfile->Close();
    File->Close();
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        ee_HT_metcut();
    }
    else if (argc == 3)
    {
        ee_HT_metcut(argv[1], argv[2]);
    }
    else
    {
        cout << "ERROR" << endl;
    }
}