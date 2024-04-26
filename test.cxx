//Simple function to compare a created json  to a reference json
bool compare_json(const TString& created_json, const std::string& ref_filename){
   // Read the reference JSON content from file
    std::ifstream refFile(ref_filename);
    if (!refFile.is_open()) {
        std::cerr << "Failed to open reference JSON file: " << ref_filename << std::endl;
        return false;
    }

    std::stringstream refBuffer;
    refBuffer << refFile.rdbuf();
    refFile.close();

    // Compare the created JSON to the reference JSON
    return created_json.Data() == refBuffer.str();
}


// TESTS
// graphtext
void drawtext()
{
   Int_t i,n;
   Double_t x,y;
   TLatex l;

   l.SetTextSize(0.025);
   l.SetTextFont(42);
   l.SetTextAlign(21);
   l.SetTextColor(kBlue);

   auto g = (TGraph*)gPad->GetListOfPrimitives()->FindObject("Graph");
   n = g->GetN();

   for (i=0; i<n; i++) {
      g->GetPoint(i,x,y);
      l.PaintText(x,y+0.2,Form("(%4.2f,%4.2f)",x,y));
   }
}

bool graphtext(){
   TCanvas *c = new TCanvas("c","A Simple Graph Example with Text",700,500);
   c->SetGrid();

   const Int_t n = 10;
   auto gr = new TGraph(n);
   gr->SetTitle("A Simple Graph Example with Text");
   gr->SetMarkerStyle(20);
   auto ex = new TExec("ex","drawtext();");
   gr->GetListOfFunctions()->Add(ex);

   Double_t x, y;
   for (Int_t i=0;i<n;i++) {
      x = i*0.1;
      y = 10*sin(x+0.2);
      gr->SetPoint(i,x,y);

   }
   gr->Draw("ALP");
   
   //Create TWebCanvas
   TWebCanvas *webCanvas = new TWebCanvas(c, "WebCanvas1", 100, 100, 700, 500);
   TString jsonOutput = webCanvas->CreateCanvasJSON(c, 1, kFALSE);
   
   /*Save JSON to a file
   std::ofstream jsonFile("graphtext.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();
   return false;*/

   //Compare the generated JSON to a reference JSON file
   if (compare_json(jsonOutput, "graphtext.json")) {
        return true;
   } else {
        return false;
   }
}

//piechart
bool piechart()
{
   Float_t vals[] = {.2,1.1,.6,.9,2.3};
   Int_t colors[] = {2,3,4,5,6};
   Int_t nvals = sizeof(vals)/sizeof(vals[0]);

   TCanvas *cpie = new TCanvas("cpie","TPie test",700,700);
   cpie->Divide(2,2);

   TPie *pie1 = new TPie("pie1",
      "Pie with offset and no colors",nvals,vals);
   TPie *pie2 = new TPie("pie2",
      "Pie with radial labels",nvals,vals,colors);
   TPie *pie3 = new TPie("pie3",
      "Pie with tangential labels",nvals,vals,colors);
   TPie *pie4 = new TPie("pie4",
      "Pie with verbose labels",nvals,vals,colors);

   cpie->cd(1);
   pie1->SetAngularOffset(30.);
   pie1->SetEntryRadiusOffset( 4, 0.1);
   pie1->SetRadius(.35);
   pie1->Draw("3d");

   cpie->cd(2);
   pie2->SetEntryRadiusOffset(2,.05);
   pie2->SetEntryLineColor(2,2);
   pie2->SetEntryLineWidth(2,5);
   pie2->SetEntryLineStyle(2,2);
   pie2->SetEntryFillStyle(1,3030);
   pie2->SetCircle(.5,.45,.3);
   pie2->Draw("rsc");

   cpie->cd(3);
   pie3->SetY(.32);
   pie3->GetSlice(0)->SetValue(.8);
   pie3->GetSlice(1)->SetFillStyle(3031);
   pie3->SetLabelsOffset(-.1);
   pie3->Draw("3d t nol");
   TLegend *pieleg = pie3->MakeLegend();
   pieleg->SetY1(.56); pieleg->SetY2(.86);

   cpie->cd(4);
   pie4->SetRadius(.2);
   pie4->SetLabelsOffset(.01);
   pie4->SetLabelFormat("#splitline{%val (%perc)}{%txt}");
   pie4->Draw("nol <");

   //Create TWebCanvas
   TWebCanvas *webCanvas = new TWebCanvas(cpie, "WebCanvas2", 100, 100, 700, 700);
   TString jsonOutput = webCanvas->CreateCanvasJSON(cpie, 1, kFALSE);
   
   /*Save JSON to a file
   std::ofstream jsonFile("piechart.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();
   return false;*/

   //Compare the generated JSON to a reference JSON file
   if (compare_json(jsonOutput, "piechart.json")) {
        return true;
   } else {
        return false;
   }
}

void test(){
   std::cout << "**********************************************************************" <<std::endl;
   std::cout << "*  Starting  Graphics - TEST suite                                   *" <<std::endl;
   std::cout << "**********************************************************************" <<std::endl;
   if (graphtext()){
      std::cout << "*  Example  Graphtext  - JSON MATCH                                  *" <<std::endl;
   } else {
      std::cout << "*  Example  Graphtext  - JSON FAIL                                   *" <<std::endl;
   };
   if (piechart()){
      std::cout << "*  Example  Piechart   - JSON MATCH                                  *" <<std::endl;
   } else {
      std::cout << "*  Example  Piechart   - JSON FAIL                                   *" <<std::endl;
   };

}