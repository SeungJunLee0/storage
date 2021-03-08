void justdraw(){

//TString cat="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.@obj.size()";
TString cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.pt()";
//TString cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.p()";
//TString cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.eta()";
//TString cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.phi()";
//TString cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.found()";
//TString cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.chi2()";
//TString cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.dz()";
//TString cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.dxy()";
//TString cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.ndof()";

 TFile *fileold = new TFile("/xrootd_user/seungjun/xrootd/old4/step4_000.root","read");
TFile *filenew = new TFile("/xrootd_user/seungjun/xrootd/fast4/step4_000.root","read");
TString hist1=">>h1(,0,100)";
TString hist2=">>h2(,0,100)";
//TString hist1=">>h1(,,)";
//TString hist2=">>h2(,,)";
TString save="/cms/scratch/seungjun/soso/";
TString form=".pdf";
TString form2=".eps";
//TTree* o1= (TTree*)fileold->Get("Events");
//o1->Draw(cat+hist1);
//TTree* o2= (TTree*)filenew->Get("Events");
//o2->Draw(cat+hist2);
fileold->Get("Events")->Draw(cat+hist1);
filenew->Get("Events")->Draw(cat+hist2);
h1->Draw();
h1->SetLineColor(1);
h2->Draw("SAME");
h2->SetLineColor(2);
h1->SetStats(0);
h2->SetStats(0);
TH1F *hnew = (TH1F*)h1->Clone("hnew");
hnew->SetLineColor(4);
hnew->Add(h2, -1);
hnew->Draw("SAME");
hnew->SetStats(0);
TLegend *legend = new TLegend(0.8,0.7,0.9,0.9);
legend -> SetTextSize(0.03);
legend -> AddEntry(h1,"ref");
legend -> AddEntry(h2,"new");
legend -> AddEntry(hnew,"ref-new");
legend -> Draw();
c1->SaveAs(save+cat+form);
c1->SaveAs(save+cat+form2);


}








double dodo(TString cat){
TCanvas *c1 = new TCanvas();
TFile *fileold = new TFile("/xrootd_user/seungjun/xrootd/old4/step4_000.root","read");
TFile *filenew = new TFile("/xrootd_user/seungjun/xrootd/fast4/step4_000.root","read");
TString hist1=">>h3(,,)";
TString hist2=">>h4(,,)";
TString save="/cms/scratch/seungjun/soso/";
TString form=".pdf";
TString form2=".eps";
TTree* o1= (TTree*)fileold->Get("Events");
o1->Draw(cat+hist1);
TH1F *h1 =static_cast<TH1F*>(gDirectory->Get("h3"));//->Draw(cat);
TTree* o2= (TTree*)filenew->Get("Events");
o2->Draw(cat+hist2);
TH1F *h2 =static_cast<TH1F*>(gDirectory->Get("h4"));//->Draw(cat);
h1->Draw();
h1->SetLineColor(1);
h2->Draw("SAME");
h2->SetLineColor(2);
h1->SetStats(0);
h2->SetStats(0);
TH1F *hnew = (TH1F*)h1->Clone("hnew");
hnew->SetLineColor(4);
hnew->Add(h2, -1);
hnew->Draw("SAME");
hnew->SetStats(0);
TLegend *legend = new TLegend(0.8,0.7,0.9,0.9);
legend -> SetTextSize(0.03);
legend -> AddEntry(h1,"ref");
legend -> AddEntry(h2,"new");
legend -> AddEntry(hnew,"ref-new");
legend -> Draw();
c1->SaveAs(save+cat+form);
c1->SaveAs(save+cat+form2);
return 0;
}

void compare_rootfile_save(){
    
TString cat="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.@obj.size()";
dodo(cat);
 cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.pt()";
dodo(cat);
 cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.p()";
dodo(cat);
 cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.eta()";
dodo(cat);
 cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.phi()";
dodo(cat);
 cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.found()";
dodo(cat);
 cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.chi2()";
dodo(cat);
 cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.dz()";
dodo(cat);
 cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.dxy()";
dodo(cat);
 cat ="recoTracks_standAloneMuons_UpdatedAtVtx_RECO.obj.ndof()";

dodo(cat);


}

