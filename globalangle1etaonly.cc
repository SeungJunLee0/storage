#include "TFile.h"
#include "TH2.h"
#include "TH1.h"
#include "TGraph.h"
using namespace std;

void oldold(){
	ifstream myfile;
//	ifstream myfile2;
	//myfile.open("new1110/GEMtestOutputanglobal.out");
	myfile.open("before1110/GEMtestOutputanglobal.out");
	for(int k=0;k<2;k++){
		TMultiGraph *mg = new TMultiGraph();
		TCanvas *c1 = new TCanvas("Validation","vali",1200,1200);
		TGraph *ss = new TGraph();
		TGraph *ss1 = new TGraph();
		//TGraph *ss2 = new TGraph();
		//TGraph *ss3 = new TGraph();
		for(int kk=1;kk<37;kk++){
			for(int kkk=1;kkk<9;kkk++){
				for(int kkkk=0;kkkk<385;kkkk++){

					TString ll;
					//TString ll2;
					myfile >>ll;
					//myfile2 >>ll2;
					if(kk<=18){
						if(kkk==1){
							double llll = ll.Atof();
							//double llll2 = ll2.Atof();
							double k2=kk+0.0;
							if(kkkk!=384){
								ss->SetPoint(ss->GetN(),2.*(kkkk+1.+k2*385)/385.,llll);
								//ss2->SetPoint(ss2->GetN(),2.*(kkkk+1.+k2*385)/385.,llll2);
							}
							if(kkkk==384){
								if(llll>=180)llll -= 360;
								//if(llll2>=180)llll -= 360;
								ss1->SetPoint(ss1->GetN(),2.*(192.+385.*k2)/385.,llll);
								//ss3->SetPoint(ss3->GetN(),2.*(192.+385.*k2)/385.,llll2);
							}
						}
					}


					if(kk>18){
						if(kkk==1){
							double llll = ll.Atof();
							//double llll2 = ll2.Atof();
							double k2 = kk+0.0;
							if(kkkk!=384){
								ss->SetPoint(ss->GetN(),1+2*((kkkk+1+k2*385.)/385.-19.),llll);
								//ss2->SetPoint(ss2->GetN(),1+2*((kkkk+1+k2*385.)/385.-19.),llll2);
							}
							if(kkkk==384){
								if(llll>=180)llll -= 360;
								//if(llll2>=180)llll2 -= 360;
								ss1->SetPoint(ss1->GetN(),1+2.*((192+385.*k2)/385.-19),llll);
								//ss2->SetPoint(ss1->GetN(),1+2.*((192+385.*k2)/385.-19),llll2);
								cout << 1+2.*((192+385.*k2)/385.-19)-0.9974<<endl;
							}
						}
					}

				}
			}
		}//
		ss1->SetMarkerColor(2);
		ss1->SetMarkerSize(1.5);
		ss1->SetMarkerStyle(21);	
		ss->SetMarkerColor(4);
		ss->SetMarkerSize(0.5);
		ss->SetMarkerStyle(21);	
	//	ss3->SetMarkerColor(3);
	//	ss3->SetMarkerSize(1.5);
	//	ss3->SetMarkerStyle(21);	
	//	ss2->SetMarkerColor(5);
	//	ss2->SetMarkerSize(0.5);
	//	ss2->SetMarkerStyle(21);	
		if(k==0)mg->SetTitle(Form("old topology GE-1/1 1 etapartition "));
		if(k==1)mg->SetTitle(Form("old topology GE+1/1 1 etapartition"));
		mg->Add(ss);
		mg->Add(ss1);
	//	mg->Add(ss2);
	//	mg->Add(ss3);
		mg->Draw("AP");
		mg->GetXaxis()->SetTitle("Chamber number");
		mg->GetYaxis()->SetTitle("Degrees");
	    TLegend *legend = new TLegend(0.6,0.7,0.9,0.9);
	    legend -> SetTextSize(0.03);
	    legend -> AddEntry(ss,"global angle");
	    legend -> AddEntry(ss1,"chamber center angle");
	    legend -> Draw();
		//c1 -> SaveAs(Form("globalangle1etaonly/GEMValidation_%d.pdf",k));
		c1 -> SaveAs(Form("beforeglobalangle1etaonly/GEMValidation_%d.pdf",k));
	}
	myfile.close();
	//myfile2.close();
}









void newnew(){
	ifstream myfile;
//	ifstream myfile2;
	myfile.open("new1110/GEMtestOutputanglobal.out");
	//myfile.open("before1110/GEMtestOutputanglobal.out");
	for(int k=0;k<2;k++){
		TMultiGraph *mg = new TMultiGraph();
		TCanvas *c1 = new TCanvas("Validation","vali",1200,1200);
		TGraph *ss = new TGraph();
		TGraph *ss1 = new TGraph();
		//TGraph *ss2 = new TGraph();
		//TGraph *ss3 = new TGraph();
		for(int kk=1;kk<37;kk++){
			for(int kkk=1;kkk<9;kkk++){
				for(int kkkk=0;kkkk<385;kkkk++){

					TString ll;
					//TString ll2;
					myfile >>ll;
					//myfile2 >>ll2;
					if(kk<=18){
						if(kkk==1){
							double llll = ll.Atof();
							//double llll2 = ll2.Atof();
							double k2=kk+0.0;
							if(kkkk!=384){
								ss->SetPoint(ss->GetN(),2.*(kkkk+1.+k2*385)/385.,llll);
								//ss2->SetPoint(ss2->GetN(),2.*(kkkk+1.+k2*385)/385.,llll2);
							}
							if(kkkk==384){
								if(llll>=180)llll -= 360;
								//if(llll2>=180)llll -= 360;
								ss1->SetPoint(ss1->GetN(),2.*(192.+385.*k2)/385.,llll);
								//ss3->SetPoint(ss3->GetN(),2.*(192.+385.*k2)/385.,llll2);
							}
						}
					}


					if(kk>18){
						if(kkk==1){
							double llll = ll.Atof();
							//double llll2 = ll2.Atof();
							double k2 = kk+0.0;
							if(kkkk!=384){
								ss->SetPoint(ss->GetN(),1+2*((kkkk+1+k2*385.)/385.-19.),llll);
								//ss2->SetPoint(ss2->GetN(),1+2*((kkkk+1+k2*385.)/385.-19.),llll2);
							}
							if(kkkk==384){
								if(llll>=180)llll -= 360;
								//if(llll2>=180)llll2 -= 360;
								ss1->SetPoint(ss1->GetN(),1+2.*((192+385.*k2)/385.-19),llll);
								//ss2->SetPoint(ss1->GetN(),1+2.*((192+385.*k2)/385.-19),llll2);
								cout << 1+2.*((192+385.*k2)/385.-19)-0.9974<<endl;
							}
						}
					}

				}
			}
		}//
		ss1->SetMarkerColor(2);
		ss1->SetMarkerSize(1.5);
		ss1->SetMarkerStyle(21);	
		ss->SetMarkerColor(4);
		ss->SetMarkerSize(0.5);
		ss->SetMarkerStyle(21);	
	//	ss3->SetMarkerColor(3);
	//	ss3->SetMarkerSize(1.5);
	//	ss3->SetMarkerStyle(21);	
	//	ss2->SetMarkerColor(5);
	//	ss2->SetMarkerSize(0.5);
	//	ss2->SetMarkerStyle(21);	
		if(k==0)mg->SetTitle(Form("new topology GE-1/1 1 etapartition "));
		if(k==1)mg->SetTitle(Form("new topology GE+1/1 1 etapartition"));
		mg->Add(ss);
		mg->Add(ss1);
	//	mg->Add(ss2);
	//	mg->Add(ss3);
		mg->Draw("AP");
		mg->GetXaxis()->SetTitle("Chamber number");
		mg->GetYaxis()->SetTitle("Degrees");
	    TLegend *legend = new TLegend(0.6,0.7,0.9,0.9);
	    legend -> SetTextSize(0.03);
	    legend -> AddEntry(ss,"global angle");
	    legend -> AddEntry(ss1,"chamber center angle");
	    legend -> Draw();
		c1 -> SaveAs(Form("globalangle1etaonly/GEMValidation_%d.pdf",k));
		//c1 -> SaveAs(Form("beforeglobalangle1etaonly/GEMValidation_%d.pdf",k));
	}
	myfile.close();
	//myfile2.close();
}
void globalangle1etaonly(){
newnew();
oldold();

}
