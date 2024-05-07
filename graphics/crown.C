/// \file
/// \ingroup tutorial_graphics
/// \notebook
/// Draw crowns.
///
/// \macro_image
/// \macro_code
///
/// \author Olivier Couet

void crown(){
   auto c1 = new TCanvas("c1","c1",400,400);
   auto cr1 = new TCrown(.5,.5,.3,.4);
   cr1->SetLineStyle(2);
   cr1->SetLineWidth(4);
   cr1->Draw();
   auto cr2 = new TCrown(.5,.5,.2,.3,45,315);
   cr2->SetFillColor(38);
   cr2->SetFillStyle(3010);
   cr2->Draw();
   auto cr3 = new TCrown(.5,.5,.2,.3,-45,45);
   cr3->SetFillColor(50);
   cr3->SetFillStyle(3025);
   cr3->Draw();
   auto cr4 = new TCrown(.5,.5,.0,.2);
   cr4->SetFillColor(4);
   cr4->SetFillStyle(3008);
   cr4->Draw();

   //Create TWebCanvas
   TWebCanvas *webCanvas = new TWebCanvas(c1, "WebCanvas6", 100, 100, 400, 400);
   TString jsonOutput = webCanvas->CreateCanvasJSON(c1, 1, kFALSE);
   
   //Save JSON to a file
   std::ofstream jsonFile("./json_pro/crown_pro.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();
}
