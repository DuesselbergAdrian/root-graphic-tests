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
// graphtext.C from tutorials/graphs
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
   std::ofstream jsonFile("graphtext_pro.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();*/

   //Compare the generated JSON to a reference JSON file
   if (compare_json(jsonOutput, "./json_ref/graphtext.json")) {
        return true;
   } else {
        return false;
   }
}

//piechart from tutorials/graphics
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
   std::ofstream jsonFile("piechart_pro.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();
   //TString json = TBufferJSON::ToJSON(h1);*/

   //Compare the generated JSON to a reference JSON file
   if (compare_json(jsonOutput, "./json_ref/piechart.json")) {
        return true;
   } else {
        return false;
   }
}

// AtlasExample
const Int_t GMAX=864;

const int nren=3;
static const double mur[nren] = {1.0,0.25,4.0};
static const double muf[nren] = {1.0,0.25,4.0};
const unsigned int NUMPDF=41;

TGraphErrors* GetGraph(Int_t ir, Int_t ifs,Int_t icut, Int_t ipdf);
void AddtoBand(TGraphErrors* g1, TGraphAsymmErrors* g2);
TGraphAsymmErrors* MakeBand(TGraphErrors* g0, TGraphErrors* g1,TGraphErrors* g2);

bool AtlasExample()
{
   gROOT->SetStyle("ATLAS");

   Int_t icol1=5;
   Int_t icol2=5;

   auto canvas = new TCanvas("canvas","single inclusive jets",50,50,600,600);
   canvas->SetLogy();

   Double_t ymin = 1.e-3;  Double_t ymax = 2e7;
   Double_t xmin = 60.00;  Double_t xmax = 3500.;
   auto frame = canvas->DrawFrame(xmin,ymin,xmax,ymax);
   frame->SetYTitle("d#sigma_{jet}/dE_{T,jet} [fb/GeV]");
   frame->SetXTitle("E_{T,jet}  [GeV]");
   frame->GetYaxis()->SetTitleOffset(1.4);
   frame->GetXaxis()->SetTitleOffset(1.4);

   const Int_t ncut=1;
   TGraphErrors *data[ncut];

   for (Int_t icut=0; icut<ncut; icut++) { // loop over cuts
      TGraphErrors *g1[nren][ncut];
      for (Int_t ir=0; ir<nren; ir++) { // loop over ren scale
         g1[ir][icut] = GetGraph(ir,ir,icut,0);
         if (!g1[ir][icut]) {
            cout << " g1 not  found " << endl;
            return false;
         }
         g1[ir][icut]->SetLineColor(1);
         g1[ir][icut]->SetMarkerStyle(0);
      }

      char daname[100];
      sprintf(daname,"data_%d",icut);
      data[icut] = (TGraphErrors*)g1[0][icut]->Clone(daname);
      data[icut]->SetMarkerStyle(20);
      data[icut]->SetMarkerColor(1);

      // Just invent some data
      for (Int_t i=0; i< data[icut]->GetN(); i++) {
         Double_t x1,y1,e,dx1=0.;
         data[icut]->GetPoint(i,x1,y1);
         Double_t r1 = 0.4*(gRandom->Rndm(1)+2);
         Double_t r2 = 0.4*(gRandom->Rndm(1)+2);
         Double_t y;
         if (icut==0) y = r1*y1+r1*r2*r2*x1/50000.;
         else         y = r1*y1;
         e = sqrt(y*1000)/200;
         data[icut]->SetPoint(i, x1,y);
         data[icut]->SetPointError(i,dx1,e);
      }

      TGraphAsymmErrors* scale[ncut];
      TGraphAsymmErrors* scalepdf[ncut];

      scale[icut] =  MakeBand(g1[0][icut],g1[1][icut],g1[2][icut]);
      scalepdf[icut]=(TGraphAsymmErrors* ) scale[icut]->Clone("scalepdf");

      TGraphErrors *gpdf[NUMPDF][ncut];
      for (Int_t ipdf=0; ipdf<NUMPDF; ipdf++) {
         gpdf[ipdf][icut]= GetGraph(0,0,icut,ipdf);
         if (!gpdf[ipdf][icut]) {
            cout << " gpdf not  found " << endl;
            return false;
         }
         gpdf[ipdf][icut]->SetLineColor(2);
         gpdf[ipdf][icut]->SetLineStyle(1);
         gpdf[ipdf][icut]->SetMarkerStyle(0);
         AddtoBand(gpdf[ipdf][icut],scalepdf[icut]);
      }

      scalepdf[icut]->SetFillColor(icol2);
      scalepdf[icut]->Draw("zE2");
      scalepdf[icut]->SetLineWidth(3);
      scale[icut]->SetFillColor(icol1);
      scale[icut]->Draw("zE2");
      g1[0][icut]->SetLineWidth(3);
      g1[0][icut]->Draw("z");
      data[icut]->Draw("P");
   }

   TLatex t; t.SetNDC();
   t.DrawLatex(0.3,  0.85, "#sqrt{s}= 14 TeV");
   t.DrawLatex(0.57, 0.85, "|#eta_{jet}|<0.5");

   auto l = new TLegend(0.45,0.65,0.8,0.8,"","NDC");
   l->SetBorderSize(0.);
   l->SetTextFont(42);
   l->AddEntry("data_0", "Data 2009", "ep");
   l->AddEntry("scalepdf", "NLO QCD", "lf");
   l->Draw();

   //Create TWebCanvas
   TWebCanvas *webCanvas = new TWebCanvas(canvas, "WebCanvas3", 50, 50, 600, 600);
   TString jsonOutput = webCanvas->CreateCanvasJSON(canvas, 1, kFALSE);
   
   //Save JSON to a file
   std::ofstream jsonFile("AtlasExample_pro.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();

   //Compare the generated JSON to a reference JSON file
   if (compare_json(jsonOutput, "./json_ref/AtlasExample.json")) {
        return true;
   } else {
        return false;
   }
}

TGraphErrors* GetGraph(Int_t ir, Int_t ifs,Int_t icut, Int_t ipdf)
{
   const char *cuts[5] =
      {"0.0 <= |eta| < 0.5",
       "0.5 <= |eta| < 1.0",
       "1.0 <= |eta| < 1.5",
       "1.5 <= |eta| < 2.0",
       "2.0 <= |eta| < 3.0"};

   const double mur[] = {1.0,0.25,4.0};
   const double muf[] = {1.0,0.25,4.0};

   TFile::SetCacheFileDir(".");
   TFile *file = TFile::Open("http://root.cern/files/AtlasGraphs.root", "CACHEREAD");

   char gname[100];
   char tname[100];

   if (ipdf>=0)
      sprintf(tname," E_T (mu_r=%g, mu_f=%g);%s Pdf: %d",mur[ir],muf[ifs],cuts[icut],ipdf);
   else
      sprintf(tname," E_T %s Ms= %d",cuts[icut],-ipdf);

   TGraphErrors* g1 = 0;

   for (int i=1; i<=GMAX; i++) {
      sprintf(gname,"full_%d",i);
      g1 = (TGraphErrors*) file->Get(gname);
      if (!g1) {
         cout << gname << "  not found " << endl;
         return nullptr;
      }

      const char *title = g1->GetTitle();

      if (strcmp(title,tname)==0) break;
      g1 = 0;
   }

   if (!g1) return nullptr;
   return g1;
}

TGraphAsymmErrors* MakeBand(TGraphErrors* g0, TGraphErrors* g1,TGraphErrors* g2) {

   TGraphAsymmErrors* g3 = new TGraphAsymmErrors();

   Double_t  x1 = 0., y1 = 0., x2 = 0., y2 = 0., y0 = 0, x3 = 0.;
   Double_t dum;
   for (Int_t i=0; i<g1->GetN(); i++) {
      g0->GetPoint(i, x1, y0);
      g1->GetPoint(i, x1, y1);
      g2->GetPoint(i, x1, y2);

      if (i==g1->GetN()-1) x2=x1;
      else                 g2->GetPoint(i+1,x2,dum);

      if (i==0)            x3=x1;
      else                 g2->GetPoint(i-1,x3,dum);

      Double_t tmp = y2;
      if (y1 < y2) {
         y2 = y1;
         y1 = tmp;
      }
      g3->SetPoint(i,x1,y0);

      Double_t binwl = (x1-x3)/2.;
      Double_t binwh = (x2-x1)/2.;
      if (binwl == 0.)  binwl = binwh;
      if (binwh == 0.)  binwh = binwl;
      g3->SetPointError(i, binwl, binwh, y0-y2, y1-y0);

   }
   return g3;
}

void AddtoBand(TGraphErrors* g1, TGraphAsymmErrors* g2) {

   Double_t x1=0., y1=0., y2=0., y0=0;

   if (g1->GetN()!=g2->GetN())
      cout << " graphs don't have the same number of elements " << endl;

   Double_t* EYhigh = g2-> GetEYhigh();
   Double_t* EYlow  = g2-> GetEYlow();

   for (Int_t i=0; i<g1->GetN(); i++) {
      g1->GetPoint(i, x1, y1);
      g2->GetPoint(i, x1, y2);

      if ( y1==0 || y2==0 )
         cerr << "check these points very carefully : AddtoBand() : point " << i << endl;

      Double_t eyh=0., eyl=0.;

      y0 = y1-y2;
      if (y0 != 0) {
         if (y0 > 0) {
            eyh = EYhigh[i];
            eyh = sqrt(eyh*eyh+y0*y0);
            g2->SetPointEYhigh(i, eyh);
         } else {
            eyl = EYlow[i];
            eyl = sqrt(eyl*eyl+y0*y0);
            g2->SetPointEYlow (i, eyl);
         }
      }
   }
}

//fit from tutorials/fit

bool fit1() {
   TCanvas *c1 = new TCanvas("c1_fit1","The Fit Canvas",200,10,700,500);
   c1->SetGridx();
   c1->SetGridy();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderMode(-1);
   c1->GetFrame()->SetBorderSize(5);

   gBenchmark->Start("fit1");
   //
   // We connect the ROOT file generated in a previous tutorial
   // (see <a href="fillrandom.C.nbconvert.ipynb">Filling histograms with random numbers from a function</a>)
   //
   TString dir = gROOT->GetTutorialDir();
   dir.Append("/fit/");
   TFile *file = nullptr;
   if (!gSystem->AccessPathName("fillrandom.root")) {
      // file exists
      file = TFile::Open("fillrandom.root");
   } else {
      gROOT->ProcessLine(Form(".x %s../hist/fillrandom.C(0)",dir.Data()));
      file = TFile::Open("fillrandom.root");
      if (!file) return false;
   }

   //
   // The function "ls()" lists the directory contents of this file
   //
   file->ls();

   //
   // Get object "sqroot" from the file. Undefined objects are searched
   // for using gROOT->FindObject("xxx"), e.g.:
   // TF1 *sqroot = (TF1*) gROOT.FindObject("sqroot")
   //
   TF1 * sqroot = nullptr;
   file->GetObject("sqroot",sqroot);
   if (!sqroot){
      Error("fit1.C","Cannot find object sqroot of type TF1\n");
      return false;
   }
   sqroot->Print();

   //
   // Now get and fit histogram h1f with the function sqroot
   //
   TH1F* h1f = nullptr;
   file->GetObject("h1f",h1f);
   if (!h1f){
      Error("fit1.C","Cannot find object h1f of type TH1F\n");
      return false;
   }
   h1f->SetFillColor(45);
   h1f->Fit("sqroot");

   // We now annotate the picture by creating a PaveText object
   // and displaying the list of commands in this macro
   //
   TPaveText * fitlabel = new TPaveText(0.6,0.4,0.9,0.75,"NDC");
   fitlabel->SetTextAlign(12);
   fitlabel->SetFillColor(42);
   fitlabel->ReadFile(Form("%sfit1_C.txt",dir.Data()));
   fitlabel->Draw();
   c1->Update();
   gBenchmark->Show("fit1");

   //Create TWebCanvas
   TWebCanvas *webCanvas = new TWebCanvas(c1, "WebCanvas4", 200, 10, 700, 500);
   TString jsonOutput = webCanvas->CreateCanvasJSON(c1, 1, kFALSE);
   
   //Save JSON to a file
   std::ofstream jsonFile("fit1.json");
   jsonFile << jsonOutput.Data();
   jsonFile.close();
   return false;

   //Compare the generated JSON to a reference JSON file
   if (compare_json(jsonOutput, "fit1.json")) {
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
   /*if (AtlasExample()){
      std::cout << "*  Example  AtlasEx    - JSON MATCH                                  *" <<std::endl;
   } else {
      std::cout << "*  Example  AtlasEx    - JSON FAIL                                   *" <<std::endl;
   };*/
   /*if (fit1()){
      std::cout << "*  Example  Fit1       - JSON MATCH                                  *" <<std::endl;
   } else {
      std::cout << "*  Example  Fit1       - JSON FAIL                                   *" <<std::endl;
   };*/
}