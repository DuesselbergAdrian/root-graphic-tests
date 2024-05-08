/// \file
/// \ingroup tutorial_hist
/// \notebook
/// Create grey scale of `200 x 200` boxes.
///
/// \macro_image
/// \macro_code
///
/// \author Olivier Couet

void greyscale()
{
   TCanvas *c16 = new TCanvas("grey", "Grey Scale", 500, 500);
   c16->SetBorderMode(0);

   Int_t   n = 200;   // tunable parameter
   Float_t n1 = 1./n;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         TBox *b = new TBox(n1*j, n1*(n-1-i), n1*(j+1), n1*(n-i));
         Float_t grey = Float_t(i*n+j)/(n*n);
         b->SetFillColor(TColor::GetColor(grey, grey, grey));
         b->Draw();
      }
   }
   TPad *p = new TPad("p","p",0.3, 0.3, 0.7,0.7);
   const char *guibackground = gEnv->GetValue("Gui.BackgroundColor", "");
   p->SetFillColor(TColor::GetColor(guibackground));
   p->Draw();
   p->cd();
   TText *t = new TText(0.5, 0.5, "GUI Background Color");
   t->SetTextAlign(22);
   t->SetTextSize(.09);
   t->Draw();

   c16->SetEditable(kFALSE);

   //Create TWebCanvas
   TWebCanvas *webCanvas = new TWebCanvas(c16, "WebCanvas16", 0, 0, 500, 500);
   TString jsonOutput = webCanvas->CreateCanvasJSON(c16, 1, kFALSE);
   
   //Save JSON to a file
   std::ofstream jsonFile("./json_pro/greyscale_pro.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();
}
