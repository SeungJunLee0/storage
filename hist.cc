//for before global angle diff, After global angle diff, After local angle diff  
#include "TFile.h"
#include "TH2.h"
#include "TH1.h"
#include "TGraph.h"
using namespace std;

void hist(){
	ifstream myfile3;
	ifstream myfile4;
	myfile3.open("new1110/GEMtestOutputdifflo.out"); //
	myfile4.open("before1110/GEMtestOutputdifflo.out"); //

	auto *mg = new TMultiGraph();
	TCanvas *c1 = new TCanvas("Validation","vali",2000,1000);
	TGraph *ss3 = new TGraph();
	TGraph *ss4 = new TGraph();
	for(int k=0;k<2;k++){
		for(int kk=1;kk<37;kk++){
			for(int kkk=1;kkk<9;kkk++){
				for(int kkkk=0;kkkk<383;kkkk++){

					TString ll3;
					TString ll4;
					myfile3 >>ll3;
					myfile4 >>ll4;
					double llll3 = ll3.Atof();
					double llll4 = ll4.Atof();
					if(llll3<0) llll3 *=-1.0;
					if(llll4<0) llll4 *=-1.0;

					ss3->SetPoint(ss3->GetN(),kkkk+1,llll3);
					ss4->SetPoint(ss3->GetN(),kkkk+1,llll4);
				}

			}

		}
	}

	ss3->SetMarkerColor(3);//new dif lo
	ss4->SetMarkerColor(2);//old dif ld

	ss3-> SetMarkerStyle(3);
	ss4-> SetMarkerStyle(3);
	ss3-> SetMarkerSize(0.35);
	ss4-> SetMarkerSize(0.35);
	mg->SetTitle(Form("GEM Local Delta phi(1~36 chamber and 1~8etapartition)"));

	mg->Add(ss3);
	mg->Add(ss4);
	mg -> Draw("AP");
	mg ->GetXaxis()->SetTitle("strip number");
	mg ->GetYaxis()->SetTitle("Angle(degree)");
	gPad ->Modified();
	mg ->GetYaxis()->SetLimits(0.0262,0.0266);
	mg ->SetMinimum(0.0262);
	mg ->SetMaximum(0.0266);
	TLegend *legend = new TLegend(0.6,0.7,0.9,0.9);
	legend -> SetTextSize(0.03);
	legend -> AddEntry(ss3,"local dphi in new topology");
	legend -> AddEntry(ss4,"local dphi in old topology");
	legend -> Draw();

	c1 -> SaveAs(Form("newshow/GEMValidation_localDphi.pdf"));
	myfile3.close();
	myfile4.close();
}
