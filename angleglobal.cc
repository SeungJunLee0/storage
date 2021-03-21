#include "TFile.h"
#include "TH2.h"
#include "TH1.h"
#include "TGraph.h"
using namespace std;

void oldold(){
	ifstream myfile;
	myfile.open("before1110/GEMtestOutputanglobal.out");
	for(int k=0;k<2;k++){

		for(int kk=1;kk<37;kk++){

			for(int kkk=1;kkk<9;kkk++){
				TMultiGraph *mg = new TMultiGraph();
				TCanvas *c1 = new TCanvas("Validation","vali",1200,1200);
				TGraph *ss = new TGraph();
				TGraph *ss1 = new TGraph();
				double before =0;
				for(int kkkk=0;kkkk<385;kkkk++){

					TString ll;
					myfile >>ll;
					double llll = ll.Atof();
					
				if(kkkk!=384)ss->SetPoint(ss->GetN(),kkkk+1,llll);
				if(kkkk==384){
					if(llll>=180)llll -= 360;
					ss1->SetPoint(ss1->GetN(),192,llll);

				}
				}
				ss1->SetMarkerColor(2);
				ss1->SetMarkerSize(1.5);
				ss1->SetMarkerStyle(21);	
				
				ss->SetMarkerColor(4);
				ss->SetMarkerSize(0.5);
				ss->SetMarkerStyle(21);
				if(kk<=18){	
				if(k==0)mg->SetTitle(Form("GE-1/1  %d chamber %d etaposition(Global angle)",kk*2,kkk));
				if(k==1)mg->SetTitle(Form("GE+1/1  %d chamber %d etaposition(Global angle)",kk*2,kkk));
				}

				if(kk>18){	
				if(k==0)mg->SetTitle(Form("GE-1/1  %d chamber %d etaposition(Global angle)",1+2*(kk-19),kkk));
				if(k==1)mg->SetTitle(Form("GE+1/1  %d chamber %d etaposition(Global angle)",1+2*(kk-19),kkk));
				}
				mg->Add(ss);
				mg->Add(ss1);
				mg->Draw("ACP");

				mg ->GetXaxis()->SetTitle("strip number");
				mg ->GetYaxis()->SetTitle("Angle(degree)");
				TLegend *legend = new TLegend(0.6,0.7,0.9,0.9);
				legend -> SetTextSize(0.03);
				legend -> AddEntry(ss,"Global angle in old topology");
				legend -> AddEntry(ss1,"Chamber center angle in old topology");
				legend -> Draw();
				if(kk<=18)c1 -> SaveAs(Form("oldangleglobal/GEMValidation_%d_%d_%d.pdf",k,kk*2,kkk));
				if(kk>18)c1 -> SaveAs(Form("oldangleglobal/GEMValidation_%d_%d_%d.pdf",k,1+2*(kk-19),kkk));

			}

		}


	}
	myfile.close();
}




void newnew(){
	ifstream myfile;
	myfile.open("new1110/GEMtestOutputanglobal.out");
	for(int k=0;k<2;k++){

		for(int kk=1;kk<37;kk++){

			for(int kkk=1;kkk<9;kkk++){
				TMultiGraph *mg = new TMultiGraph();
				TCanvas *c1 = new TCanvas("Validation","vali",1200,1200);
				TGraph *ss = new TGraph();
				TGraph *ss1 = new TGraph();
				double before =0;
				for(int kkkk=0;kkkk<385;kkkk++){

					TString ll;
					myfile >>ll;
					double llll = ll.Atof();
					
				if(kkkk!=384)ss->SetPoint(ss->GetN(),kkkk+1,llll);
				if(kkkk==384){
					if(llll>=180)llll -= 360;
					ss1->SetPoint(ss1->GetN(),192,llll);

				}
				}
				ss1->SetMarkerColor(2);
				ss1->SetMarkerSize(1.5);
				ss1->SetMarkerStyle(21);	
				
				ss->SetMarkerColor(4);
				ss->SetMarkerSize(0.5);
				ss->SetMarkerStyle(21);
				if(kk<=18){	
				if(k==0)mg->SetTitle(Form("GE-1/1  %d chamber %d etaposition(Global angle)",kk*2,kkk));
				if(k==1)mg->SetTitle(Form("GE+1/1  %d chamber %d etaposition(Global angle)",kk*2,kkk));
				}

				if(kk>18){	
				if(k==0)mg->SetTitle(Form("GE-1/1  %d chamber %d etaposition(Global angle)",1+2*(kk-19),kkk));
				if(k==1)mg->SetTitle(Form("GE+1/1  %d chamber %d etaposition(Global angle)",1+2*(kk-19),kkk));
				}
				mg->Add(ss);
				mg->Add(ss1);
				mg->Draw("ACP");

				mg ->GetXaxis()->SetTitle("strip number");
				mg ->GetYaxis()->SetTitle("Angle(degree)");
				TLegend *legend = new TLegend(0.6,0.7,0.9,0.9);
				legend -> SetTextSize(0.03);
				legend -> AddEntry(ss,"Global angle in new topology");
				legend -> AddEntry(ss1,"Chamber center angle in new topology");
				legend -> Draw();
				if(kk<=18)c1 -> SaveAs(Form("newangleglobal/GEMValidation_%d_%d_%d.pdf",k,kk*2,kkk));
				if(kk>18)c1 -> SaveAs(Form("newangleglobal/GEMValidation_%d_%d_%d.pdf",k,1+2*(kk-19),kkk));

			}

		}


	}
	myfile.close();
}

void angleglobal(){
newnew();
oldold();
}
