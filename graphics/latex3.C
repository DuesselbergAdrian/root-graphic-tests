/// \file
/// \ingroup tutorial_graphics
/// \notebook
/// Example illustrating a TPaveText with Latex inside.
///
/// \macro_image
/// \macro_code
///
/// \author Rene Brun

void latex3() {

   TCanvas *c20 = new TCanvas("c20");
   TPaveText *pt = new TPaveText(.05,.1,.95,.8);

   pt->AddText("#frac{2s}{#pi#alpha^{2}}  #frac{d#sigma}{dcos#theta} "
               "(e^{+}e^{-} #rightarrow f#bar{f} ) = #left| #frac{1}{1 - #Delta#alpha} "
               "#right|^{2} (1+cos^{2}#theta)");

   pt->AddText("+ 4 Re #left{ #frac{2}{1 - #Delta#alpha} #chi(s) "
               "#[]{#hat{g}_{#nu}^{e}#hat{g}_{#nu}^{f} "
               "(1 + cos^{2}#theta) + 2 #hat{g}_{a}^{e}#hat{g}_{a}^{f} cos#theta) } #right}");

   pt->AddText("+ 16#left|#chi(s)#right|^{2} "
               "#left[(#hat{g}_{a}^{e}^{2} + #hat{g}_{v}^{e}^{2})"
               "(#hat{g}_{a}^{f}^{2} + #hat{g}_{v}^{f}^{2})(1+cos^{2}#theta)"
               "+ 8 #hat{g}_{a}^{e} #hat{g}_{a}^{f} #hat{g}_{v}^{e}"
               "#hat{g}_{v}^{f}cos#theta#right] ");

   pt->SetLabel("Born equation");
   pt->Draw();

    //Create TWebCanvas
   TWebCanvas *webCanvas = new TWebCanvas(c20, "WebCanvas20", 0, 0, 600, 700);
   TString jsonOutput = webCanvas->CreateCanvasJSON(c20, 1, kFALSE);
   
   //Save JSON to a file
   std::ofstream jsonFile("./json_pro/latex3_pro.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();
}
