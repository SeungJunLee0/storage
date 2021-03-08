void HW_statics(){
for(int i =0;i<3;i++){
int NN;
if(i ==0)NN =3;
if(i==1)NN=10;
if(i==2)NN=100;
int N = 2*NN+1;
double x[N];//entropy = {0};//{1,2,3,4,5};
double y[N];//Energy `= V{-1,1,3,5,7};
double s[N];
for(int k =0;k<N;k++){
x[k]=0.0;
y[k]=0.0;
}
for(int k=0;k<NN+1;k++){
if(k==0 ||k==NN)y[k]=log(1)/NN;

else y[k]=log(TMath::Factorial(NN)/TMath::Factorial(NN-k)/TMath::Factorial(k))/NN;
 
x[k] = -NN+2*(k);
}
TCanvas *c1 = new TCanvas();
TGraph *gr = new TGraph(N,x,y);
gr -> SetMarkerStyle(8);
gr -> SetLineWidth(3);
gr -> SetMarkerColor(2);
gr -> SetMarkerSize(1);

gr ->Draw("ALP");
gr->SetTitle(Form("S(N,E)/N vs E  if N = %d",NN));
gr->GetXaxis()->SetTitle("E");
gr->GetYaxis()->SetTitle("S(N,E)/N");
if(i==0)c1->SaveAs(Form("N = %d",NN));
if(i==1)c1->SaveAs(Form("N = %d",NN));
if(i==2)c1->SaveAs(Form("N = %d",NN));

}
}
