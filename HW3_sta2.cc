void HW3_sta2(){
TCanvas *c1 = new TCanvas();
auto *mg = new TMultiGraph();
TGraph *gr = new TGraph();
TGraph *gr1 = new TGraph();
TGraph *gr2 = new TGraph();
TGraph *gr3 = new TGraph();
TGraph *gr4 = new TGraph();
TGraph *gr5 = new TGraph();
for(int i =0;i<3;i++){
int NN[2] = {10,100};
int N[2]={6,51};
double T[3] ={0.5,1.0,2.0};
//TCanvas *c1 = new TCanvas();
//auto *mg = new TMultiGraph();
//TGraph *gr = new TGraph();
//TGraph *gr1 = new TGraph();
//TGraph *gr2 = new TGraph();
//TGraph *gr3 = new TGraph();
//TGraph *gr4 = new TGraph();
//TGraph *gr5 = new TGraph();
/////////for 10
for(int j=0;j<2;j++){
double E[N[j]];//energy = {0};//{1,2,3,4,5};
double S[N[j]];//Entropy `= V{-1,1,3,5,7};
double F[N[j]];
for(int k=0;k<N[j];k++){
if(k==0 ||k==N[j]-1) {S[k]=log(2*1);
}
else{ S[k]=log(2*TMath::Factorial(NN[j])/TMath::Factorial(NN[j]-2*k)/TMath::Factorial(2*k));
}
F[k] = (-NN[j]+4.0*(double)k-T[i]*S[k])/(double)NN[j];
E[k]=(-NN[j]+4.0*(double)k)/(double)NN[j];
if(j==0 && i==2)cout<<F[k]<<endl;
if(j==0 && i==0)gr->SetPoint(gr->GetN(),E[k],F[k]);
if(j==1 && i==0)gr1->SetPoint(gr1->GetN(),E[k],F[k]);
if(j==0 && i==1)gr2->SetPoint(gr2->GetN(),E[k],F[k]);
if(j==1 && i==1)gr3->SetPoint(gr3->GetN(),E[k],F[k]);
if(j==0 && i==2)gr4->SetPoint(gr4->GetN(),E[k],F[k]);
if(j==1 && i==2)gr5->SetPoint(gr5->GetN(),E[k],F[k]);
}
}
}
///////////////////////////////////////
gr -> SetMarkerStyle(8);
gr -> SetLineWidth(3);
gr -> SetMarkerColor(4);
gr -> SetMarkerSize(1);
gr ->Draw("ALP");
gr1 -> SetMarkerStyle(8);
gr1 -> SetLineWidth(3);
gr1 -> SetMarkerColor(2);
gr1 -> SetMarkerSize(1);
gr1 ->Draw("ALP");
gr2 -> SetMarkerStyle(8);
gr2 -> SetLineWidth(3);
gr2 -> SetMarkerColor(5);
gr2 -> SetMarkerSize(1);
gr2 ->Draw("ALP");
gr3 -> SetMarkerStyle(8);
gr3 -> SetLineWidth(3);
gr3 -> SetMarkerColor(6);
gr3 -> SetMarkerSize(1);
gr3 ->Draw("ALP");
gr4 -> SetMarkerStyle(8);
gr4 -> SetLineWidth(3);
gr4 -> SetMarkerColor(7);
gr4 -> SetMarkerSize(1);
gr4 ->Draw("ALP");
gr5 -> SetMarkerStyle(8);
gr5 -> SetLineWidth(3);
gr5 -> SetMarkerColor(8);
gr5 -> SetMarkerSize(1);
gr5 ->Draw("ALP");
mg->Add(gr);
mg->Add(gr1);
mg->Add(gr2);
mg->Add(gr3);
mg->Add(gr4);
mg->Add(gr5);
mg->Draw("ALP");
mg->SetTitle(Form("F(N,E)/N vs E/N"));
mg->GetXaxis()->SetTitle("E/N");
mg->GetYaxis()->SetTitle("F(N,E)/N");
//if(i==0)c1->SaveAs(Form("N = ,T =0.5"));
//if(i==1)c1->SaveAs(Form("N =,T=1"));
//if(i==2)c1->SaveAs(Form("N =,T=2"));
c1->SaveAs(Form("N =,T=2"));
TLegend *legend = new TLegend(0.6,0.7,0.9,0.9);
legend -> SetTextSize(0.03);
legend -> AddEntry(gr,"N=10,T=0.5T_{0}");
legend -> AddEntry(gr1,"N=100,T=0.5T_{0}");
legend -> AddEntry(gr2,"N=10,T=T_{0}");
legend -> AddEntry(gr3,"N=100,T=T_{0}");
legend -> AddEntry(gr4,"N=10,T=2T_{0}");
legend -> AddEntry(gr5,"N=100,T=2T_{0}");
legend -> Draw();

}
