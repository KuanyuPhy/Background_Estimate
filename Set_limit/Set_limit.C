#include <iostream>
#include <sstream>
#include <TTree.h>
#include <TMath.h>
#include <TFile.h>
#include <TH3D.h>
#include <vector>
#include <TROOT.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TAxis.h>
#include <TLine.h>

using namespace RooFit;
TRandom3 rnd;

void CL_scan(double target_ns = 5., int ntoys = 1000, bool display = false)
{
    const int nobs = 8;
    const double nb = 4.5;

    double L0 = TMath::Poisson(nobs, nb);
    double L1 = TMath::Poisson(nobs, nb + target_ns);
    double Q_obs = -2. * (log(L1) - log(L0)); // observed test statistic

    double CL[2] = {0., 0.};
    vector<double> stat[2];
    for (int hypo = 0; hypo <= 1; hypo++)
    {
        for (int idx = 0; idx < ntoys; idx++)
        {
            int n = 0;
            if (hypo == 0)
                n = rnd.Poisson(nb); // toy sampling b-only
            if (hypo == 1)
                n = rnd.Poisson(nb + target_ns); // toy sampling s+b

            double L0 = TMath::Poisson(n, nb);
            double L1 = TMath::Poisson(n, nb + target_ns);
            double Q = -2. * (log(L1) - log(L0)); // sampled test statistic
            stat[hypo].push_back(Q);

            if (Q >= Q_obs)
                CL[hypo] += 1.;
        }
        CL[hypo] /= (double)ntoys;
    }
    double CLs = CL[1] / CL[0];

        if (display) {
        TH1D* h_stat0 = new TH1D("h_stat0","",25,-70.,30.);
        TH1D* h_stat1 = new TH1D("h_stat1","",25,-70.,30.);
        for (int idx=0; idx<ntoys; idx++) {
            h_stat0->Fill(stat[0][idx]);
            h_stat1->Fill(stat[1][idx]);
        }
        
        TCanvas *c1 = new TCanvas("c1","",600,600);
        c1->SetMargin(0.14,0.06,0.13,0.07);
        c1->SetLogy();
        h_stat1->SetStats(false);
        h_stat1->SetFillColor(kBlue-10);
        h_stat1->GetXaxis()->SetTitle("-2log(L_{s+b}/L_{b})");
        h_stat1->GetYaxis()->SetTitle("# of toys");
        h_stat1->GetXaxis()->SetTitleSize(0.06);
        h_stat1->GetYaxis()->SetTitleSize(0.06);
        h_stat1->GetYaxis()->SetTitleOffset(1.0);
        h_stat1->Draw();
        h_stat0->SetFillColor(kRed);
        h_stat0->SetFillStyle(3365);
        h_stat0->Draw("same");
        TLine l1;
        l1.SetLineWidth(3);
        l1.DrawLine(Q_obs,0.,Q_obs,h_stat1->GetMaximum());
    }
    
    printf("Target ns = %.1f, CLs+b = %.3f, CLb = %.3f, CLs = %.3f\n",target_ns,CL[1],CL[0],CLs);
    
    return CLs;
}

void Set_limit(){
    CL_scan(7.5,40000,true);
}
