{
TFile *filev2 = new TFile("hist_v2.root","read");
TFile *filec =  new TFile("hist_c.root","read");
TFile *filed =  new TFile("hist_d.root","read");
TFile *filee =  new TFile("hist_e.root","read");
TFile *filef =  new TFile("hist_f.root","read");
TFile *fileg =  new TFile("hist_g.root","read");
TFile *fileh =  new TFile("hist_h.root","read");
TFile *file132 = new TFile("/home/sjlee/program/DELPHES/Delphes-3.5.0/AddMlb_132_dilepton.root","read");
TH1F *histv2 = (TH1F*) filev2 -> Get("plots/m_lb");
TH1F *histc = (TH1F*) filec ->   Get("plots/m_lb");
TH1F *histd = (TH1F*) filed ->   Get("plots/m_lb");
TH1F *histe = (TH1F*) filee ->   Get("plots/m_lb");
TH1F *histf = (TH1F*) filef ->   Get("plots/m_lb");
TH1F *histg = (TH1F*) fileg ->   Get("plots/m_lb");
TH1F *histh = (TH1F*) fileh ->   Get("plots/m_lb");
TH1F *hist132_MC = (TH1F*) file132 -> Get("Invariant_Mass");
hist132_MC->Sumw2();
histv2->Sumw2();
histc->Sumw2();
histd->Sumw2();
histe->Sumw2();
histf->Sumw2();
histg->Sumw2();
histh->Sumw2();
TH1F hist_DoubleMu_2016= *histv2 + *histc + *histd + *histe + *histf + *histg + *histh;
cout << "Data : "<<hist_DoubleMu_2016.Integral()<<endl;
cout << "MC   : "<<hist132_MC -> Integral()<<endl;
cout << "MC/Data   : "<<hist132_MC -> Integral()<<endl;
hist132_MC -> Scale ( 1./hist132_MC -> Integral() * hist_DoubleMu_2016.Integral());
//hist132_MC -> Scale ( hist132_MC -> Integral() / hist_DoubleMu_2016.Integral());
hist132_MC->Rebin(4);
hist_DoubleMu_2016.Rebin(4);
TH1F *ratio_MC = (TH1F *) hist_DoubleMu_2016.Clone();
//TH1F *ratio_MC = (TH1F *)hist132_MC ->Clone();// hist_DoubleMu_2016.Clone();
//ratio_MC ->Divide(hist_DoubleMu_2016);
ratio_MC ->Divide(hist132_MC);


ratio_MC->SetLineColor(kRed);
TCanvas *canvas = new TCanvas("canvas","Example plot",1000,700);
TPad pad1 ( " pad1 " ," pad1 " ,0 ,0.3 ,1 ,1);
pad1.Draw();
pad1.cd();
hist132_MC->SetStats(0);
hist132_MC->SetTitle("m_{bl}^{minimax} Invariant Mass");
hist_DoubleMu_2016.SetLineColor(4);
hist132_MC->SetLineColor(2);

hist132_MC -> Draw("E HIST");
hist_DoubleMu_2016.Draw("HIST SAME");
TLegend *legend = new TLegend(0.6,0.7,0.85,0.85,"m_{bl}^{minimax} b_bbar_4l events");
legend -> SetBorderSize(0);
legend -> SetTextSize(0.05);
legend -> AddEntry("hist_DoubleMu_2016","Data ");
legend -> AddEntry(hist132_MC,"1.32 GeV ");
legend -> Draw();

canvas->cd();
TPad pad2( "pad2" ,"pad2" ,0 ,0.05 ,1 ,0.3);
pad2.Draw();
pad2.cd();
ratio_MC->Draw( "pe" );
//canvas.SaveAs( "plot.pdf");
pad1.SetBottomMargin (0);
pad2.SetTopMargin(0);
pad2.SetBottomMargin(0.25);


hist_DoubleMu_2016.SetTitle( "Inva" );
hist_DoubleMu_2016.GetXaxis() -> SetLabelSize(0);
hist_DoubleMu_2016.GetXaxis() -> SetTitleSize(0);
hist_DoubleMu_2016.GetYaxis() -> SetTitleSize (0.05);
ratio_MC-> SetStats(0);
ratio_MC -> SetTitle( "" );
ratio_MC -> GetXaxis() -> SetLabelSize(0.12);
ratio_MC -> GetXaxis() -> SetTitleSize(0.12);
ratio_MC -> GetYaxis() -> SetLabelSize(0.1);
ratio_MC -> GetYaxis() -> SetTitleSize(0.15);
ratio_MC -> GetYaxis() -> SetTitle( " Data / MC_132 " );
ratio_MC -> GetYaxis() -> SetTitleOffset(0.3);
ratio_MC -> GetYaxis() -> SetRangeUser(0.3,1.8);

TLine line(0.0 ,1 ,500. ,1);
line.SetLineColor ( kBlack );
line.SetLineWidth (2);
line.Draw ( " same " );

}
