
void LYSOPlots()
{
  TFile* f = new TFile("~/godaq_rootfiles/analysis_v2.19-calibC1/run44.root", "read");
  TTree* t = (TTree*) f->Get("tree");

  TFile* f1 = new TFile("~/godaq_rootfiles/analysis_v2.19-calibA1/run12.root", "read");
  TTree* t1 = (TTree*) f1->Get("tree");

  TCanvas* cCRT = new TCanvas("cCRT","cCRT");
  cCRT->SetGridx(1);
  cCRT->SetGridy(1);
  TH1F* hCRT = new TH1F("hCRT", "hCRT", 200, -10, 10);
  t->Draw("T30[0] - T30[1]>>hCRT","","goff");
  //hCRT->Sumw2();
  hCRT->Scale(1/hCRT->Integral());
  hCRT->GetYaxis()->SetTitle("Entries [a. u.]");
  hCRT->GetXaxis()->SetTitle("#Delta t [ns]");
  hCRT->GetXaxis()->SetTitleSize(0.06);
  hCRT->GetYaxis()->SetTitleSize(0.06);
  hCRT->GetXaxis()->SetTitleOffset(1.25);
  hCRT->GetYaxis()->SetTitleOffset(1.4);
  hCRT->GetXaxis()->SetLabelSize(0.06);
  hCRT->GetYaxis()->SetLabelSize(0.06);
  hCRT->GetXaxis()->SetNdivisions(10);
  hCRT->GetYaxis()->SetNdivisions(10);
  hCRT->SetLineWidth(3);
  hCRT->SetFillStyle(3002);
  hCRT->SetFillColor(kPink-2);
  hCRT->Draw();
  hCRT->Fit("gaus", "", "", -4, 4);

  PutText(0.25, 0.77, kBlack, "LAPD");
  PutText(0.25, 0.7, kBlack, "Background run");

  PutText(0.58, 0.75, kBlack, "CRT (FWHM) = 3.4 ns");

  cCRT->SaveAs("cCRT.png");

  


  TCanvas* cE = new TCanvas("cE","cE", 1000,400);
  cE->SetGridx(1);
  cE->SetGridy(1);
  TH1F* hE = new TH1F("hE", "hE", 200, 0, 1100);
  t->Draw("E>>hE","Sat==0 && Ampl > 600","goff");
  //hE->Sumw2();
  hE->Scale(1/hE->Integral());
  hE->GetYaxis()->SetTitle("Entries [a. u.]");
  hE->GetXaxis()->SetTitle("E [keV]");
  hE->GetXaxis()->SetTitleSize(0.06);
  hE->GetYaxis()->SetTitleSize(0.06);
  hE->GetXaxis()->SetTitleOffset(1.25);
  hE->GetYaxis()->SetTitleOffset(1.3);
  hE->GetXaxis()->SetLabelSize(0.06);
  hE->GetYaxis()->SetLabelSize(0.06);
  hE->GetXaxis()->SetNdivisions(10);
  hE->GetYaxis()->SetNdivisions(10);
  hE->SetLineWidth(3);
  hE->SetFillStyle(3002);
  hE->SetFillColor(kPink-2);
  hE->Draw();

  PutText(0.6, 0.77, kBlack, "LAPD", 0.06);
  PutText(0.6, 0.7, kBlack, "Background run", 0.06);

  cE->SaveAs("cE.png");


  TCanvas* cELeadWall = new TCanvas("cELeadWall","cELeadWall", 1000,400);
  cELeadWall->SetGridx(1);
  cELeadWall->SetGridy(1);
  TH1F* hELeadWall = new TH1F("hELeadWall", "hELeadWall", 200, 0, 1100);
  t1->Draw("E[0]>>hELeadWall","abs(T30[0]-T30[1])>5 && Sat[0]==0 && Ampl[0] > 600","goff");
  //hE->Sumw2();
  hELeadWall->Scale(1/hELeadWall->Integral());
  hELeadWall->GetYaxis()->SetTitle("Entries [a. u.]");
  hELeadWall->GetXaxis()->SetTitle("E [keV]");
  hELeadWall->GetXaxis()->SetTitleSize(0.06);
  hELeadWall->GetYaxis()->SetTitleSize(0.06);
  hELeadWall->GetXaxis()->SetTitleOffset(1.25);
  hELeadWall->GetYaxis()->SetTitleOffset(1.3);
  hELeadWall->GetXaxis()->SetLabelSize(0.06);
  hELeadWall->GetYaxis()->SetLabelSize(0.06);
  hELeadWall->GetXaxis()->SetNdivisions(10);
  hELeadWall->GetYaxis()->SetNdivisions(10);
  hELeadWall->SetLineWidth(3);
  hELeadWall->SetFillStyle(3002);
  hELeadWall->SetFillColor(kPink-2);
  hELeadWall->Draw();

  PutText(0.2, 0.8, kBlack, "LAPD", 0.06);
  PutText(0.2, 0.73, kBlack, "Background run", 0.06);
  PutText(0.2, 0.66, kBlack, "Lead wall between two sides of LAPD", 0.06);

  cELeadWall->SaveAs("cELeadWall.png");





  TCanvas* cE0VsE1 = new TCanvas("cE0VsE1","cE0VsE1", 800, 800);
  cE0VsE1->SetGridx(1);
  cE0VsE1->SetGridy(1);
  cE0VsE1->SetRightMargin(0.16);
  TH2F* hE0VsE1 = new TH2F("hE0VsE1", "hE0VsE1", 200, 0, 1000, 200, 0, 1000);
  t->Draw("E[0] : E[1] >>hE0VsE1","Sat[0]==0&&Sat[1]==0","goff");
  //hE0VsE1->Sumw2();
  hE0VsE1->Scale(1/hE0VsE1->Integral());
  hE0VsE1->GetYaxis()->SetTitle("E_{0} [keV]");
  hE0VsE1->GetXaxis()->SetTitle("E_{1} [keV]");
  hE0VsE1->GetXaxis()->SetTitleSize(0.045);
  hE0VsE1->GetYaxis()->SetTitleSize(0.045);
  hE0VsE1->GetXaxis()->SetTitleOffset(1.25);
  hE0VsE1->GetYaxis()->SetTitleOffset(1.8);
  hE0VsE1->GetXaxis()->SetLabelSize(0.045);
  hE0VsE1->GetYaxis()->SetLabelSize(0.045);
  hE0VsE1->GetZaxis()->SetLabelSize(0.045);
  //hE0VsE1->GetXaxis()->SetNdivisions(10);
  //hE0VsE1->GetYaxis()->SetNdivisions(10);
  hE0VsE1->SetLineWidth(3);
  hE0VsE1->SetFillStyle(3002);
  hE0VsE1->SetFillColor(kPink-2);
  hE0VsE1->Draw("colz");
  hE0VsE1->Fit("gaus", "", "", -4, 4);
 TPave *pave = new TPave(427,789,945,954,1,"br");
   pave->SetFillColor(10);
   pave->SetLineWidth(2);
   pave->Draw();

   PutText(0.47, 0.8, kBlack, "LAPD",0.045);
  PutText(0.47, 0.75, kBlack, "Background run",0.045);

  cE0VsE1->SaveAs("cE0VsE1.png");


}
