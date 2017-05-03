
void LYSOPlots()
{
  TFile* f = new TFile("~/godaq_rootfiles/analysis_v2.19-calibG2/run44.root", "read");
  TTree* t = (TTree*) f->Get("tree");


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

  
  TCanvas* cE0VsE1 = new TCanvas("cE0VsE1","cE0VsE1", 800, 800);
  cE0VsE1->SetGridx(1);
  cE0VsE1->SetGridy(1);
  cE0VsE1->SetRightMargin(0.16);
  TH2F* hE0VsE1 = new TH2F("hE0VsE1", "hE0VsE1", 200, 0, 1000, 200, 0, 1000);
  t->Draw("E[0] : E[1] >>hE0VsE1","","goff");
  //hE0VsE1->Sumw2();
  hE0VsE1->Scale(1/hE0VsE1->Integral());
  hE0VsE1->GetYaxis()->SetTitle("Entries [a. u.]");
  hE0VsE1->GetXaxis()->SetTitle("E [keV]");
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
