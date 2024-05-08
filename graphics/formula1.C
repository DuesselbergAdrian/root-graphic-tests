/// \file
/// \ingroup tutorial_graphics
/// \notebook -js
/// Display interpreted functions.
///
/// \macro_image
/// \macro_code
///
/// \author Rene Brun

void formula1() {
   TCanvas *c12 = new TCanvas("c12","Example with Formula",200,10,700,500);
   //
   // We create a formula object and compute the value of this formula
   // for two different values of the x variable.
   //
   auto form1 = new TFormula("form1","sqrt(abs(x))");
   form1->Eval(2);
   form1->Eval(-45);
   //
   // Create a one dimensional function and draw it
   //
   auto fun1 = new TF1("fun1","abs(sin(x)/x)",0,10);
   c12->SetGridx();
   c12->SetGridy();
   fun1->Draw();
   c12->Update();
   //
   // Before leaving this demo, we print the list of objects known to ROOT
   //
   if (gObjectTable) gObjectTable->Print();

   //Create TWebCanvas
   TWebCanvas *webCanvas = new TWebCanvas(c12, "WebCanvas12", 200, 10, 700, 500);
   TString jsonOutput = webCanvas->CreateCanvasJSON(c12, 1, kFALSE);
   
   //Save JSON to a file
   std::ofstream jsonFile("./json_pro/formula1_pro.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();
}
