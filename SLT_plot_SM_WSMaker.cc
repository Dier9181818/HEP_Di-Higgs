#include "TFile.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TF1.h"
#include "TTree.h"
#include "TLegend.h"
#include "TChain.h"
#include "TLatex.h"
#include "TStyle.h"
#include "TPad.h"
#include "TMath.h"
#include <iostream>
using namespace std;
string itoa(int num);

void SLT_plot_SM_WSMaker(){

    
  const int n_smp = 40;
  string smp_tree[n_smp] = { "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal" };
  string smp;
  TChain  *chain_smp[n_smp];
  
  string smp_names[n_smp] = { "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt" };
    
  for (int i=0; i<n_smp; i++)
    {
      smp = smp_names[i] +".root";
      cout<<smp<<endl;
      chain_smp[i] = new TChain(smp_tree[i].c_str());
      chain_smp[i]->Add(smp.c_str());
    }
  
  string h_title[n_smp] = { "ttH", "ttZ", "ttW", "VBFHtautau", "WHbb", "qqZHbb", "ggZHbb", "WHtautau", "qqZHtautau", "ggZHtautau", "WZ", "WW", "ZZ", "DY", "DYtt", "ttbarFake", "WFake", "WttFake", "Zbb", "Zbc", "Zbl", "Zcc", "Zcl", "Zl", "W", "Wtt", "Zttbb", "Zttbc", "Zttbl", "Zttcc", "Zttcl", "Zttl", "stops", "stopWt", "stopt", "ttbar", "hh_bbtt", "ggFHtautau", "hhttbbVBFSM", "data" };
    
  TH1::SetDefaultSumw2();
  TH1F * h_hist[n_smp];
  const char *h_nm;
  string hist_draw[n_smp];


        //   ===========================================================   Mhh   ===========================================================
          
    
          TCanvas *c36 = new TCanvas ("c36", "Mhh",980,580);
            
          TPad *pad361 = new TPad("pad361","",0,0,0.75,1);
          TPad *pad362 = new TPad("pad362","",0.73,0,1,1);
          pad361->Draw();
          pad362->Draw();
            
          pad361->cd();
          pad361->SetTickx();
          //gStyle->SetOptStat(kFALSE);
          //gPad->SetLogy();
          
          for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            //h_hist[i]->GetXaxis()->SetTitle("m_{hh} [GeV]");
            h_hist[i]->GetYaxis()->SetTitle("Events/ 100 GeV");
            //h_hist[i]->GetXaxis()->SetRangeUser(0, 500);
            //h_hist[i]->GetYaxis()->SetRangeUser(1, 6000); //B:6000, P:2800
          } 
        
          for (int i=0; i<n_smp; i++){
              hist_draw[i]="mHHStar*0.001>>"+h_title[i];
          }
          
          for(int i = 0; i<n_smp; i++){
            
              if (i == 0 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"ttH\" )",  "SAMEHIST");}
              else if (i == 1 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"ttZ\" )",  "SAMEHIST");}
              else if (i == 2 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"ttW\" )",  "SAMEHIST");}
              else if (i == 3 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"VBFHtautau\" )",  "SAMEHIST");}
              else if (i == 4 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"WHbb\" )",  "SAMEHIST");}
              else if (i == 5 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"qqZHbb\" )",  "SAMEHIST");}
              else if (i == 6 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"ggZHbb\" )",  "SAMEHIST");}
              else if (i == 7 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"WHtautau\" )",  "SAMEHIST");}
              else if (i == 8 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"qqZHtautau\" )",  "SAMEHIST");}
              else if (i == 9 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"ggFHtautau\" )",  "SAMEHIST");}
              else if (i == 10 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"WZ\" )",  "SAMEHIST");}
              else if (i == 11 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"WZ\" )",  "SAMEHIST");}
              else if (i == 12 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"WW\" )",  "SAMEHIST");}
              else if (i == 13 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"ZZ\" )",  "SAMEHIST");}
              else if (i == 14 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"DY\" )",  "SAMEHIST");}
              else if (i == 15 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"DYtt\" )",  "SAMEHIST");}
              else if (i == 16 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"ttbarFake\" )",  "SAMEHIST");}
              else if (i == 17 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"WFake\" )",  "SAMEHIST");}
              else if (i == 18 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"WttFake\" )",  "SAMEHIST");}
              else if (i == 19 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zbb\" )",  "SAMEHIST");}
              else if (i == 20 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zbc\" )",  "SAMEHIST");}
              else if (i == 21 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zbl\" )",  "SAMEHIST");}
              else if (i == 22 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zcc\" )",  "SAMEHIST");}
              else if (i == 23 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zcl\" )",  "SAMEHIST");}
              else if (i == 24 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zl\" )",  "SAMEHIST");}
              else if (i == 25 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"W\" )",  "SAMEHIST");}
              else if (i == 26 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Wtt\" )",  "SAMEHIST");}
              else if (i == 27 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zttbb\" )",  "SAMEHIST");}
              else if (i == 28 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zttbc\" )",  "SAMEHIST");}
              else if (i == 29 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zttbl\" )",  "SAMEHIST");}
              else if (i == 30 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zttcc\" )",  "SAMEHIST");}
              else if (i == 31 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zttcl\" )",  "SAMEHIST");}
              else if (i == 32 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"Zttl\" )",  "SAMEHIST");}
              else if (i == 33 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"stops\" )",  "SAMEHIST");}
              else if (i == 34 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"stopWt\" )",  "SAMEHIST");}
              else if (i == 35 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"stopt\" )",  "SAMEHIST");}
              else if (i == 36 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"ttbar\" )",  "SAMEHIST");}
              else if (i == 37 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"hhttbb\" )",  "SAMEHIST");}
              else if (i == 38 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"hhttbbVBFSM\" )",  "SAMEHIST");}
              else if (i == 39 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && mjjVBF>500000 && sample ==\"data\" )",  "SAMEHIST");}
                          
          // && mjjVBF>500000 && mMMC<160000 && mTW<60000 && mBB>100000 && pTSixObjVBF<60000 && dEtaHH>0.6 && dRb0lep>2 && abs(dPhiTauTauMET)<0.8 && Lea
          // dBjet>70000 && dRTauLep<2.4 && pTj2VBF>30000 && dEtajjVBF>4 && tau_rnn>0.18 && abs(coshelicitytautau)<0.8

          }
          
          THStack *hs36 = new THStack("hs36", "");
          for(int i= 0; i<n_smp ; i++){ hs36->Add(h_hist[i], "hist36"); }
          hs36->Draw("SAMEHIST");


    TFile *f1 = new TFile("Mhh_WSMaker_With14Cut.root","recreate");
    f1 -> cd();

    for (int i=0; i<n_smp; i++){
        hist_draw[i]="Mhh*0.001>>"+h_title[i];
        h_hist[i]->Write();
    }

    f1->Close();
    
    
/*
    auto f1 = new TFile("Mhh_WSMaker.root","UPDATE");
   
    TH1F *h1; f1->GetObject("Fake_ttbar",h1);
    if(h1){ h1->SetName("Fake"); }

    TH1F *h2; f1->GetObject("Fake_W",h2);
    if(h2){ h1->SetName("WFake"); }

    TH1F *h3; f1->GetObject("SMH",h3);
    if(h3){ h3->SetName("WHbb"); }
    
    TH1F *h4; f1->GetObject("SMH",h4);
    if(h4){ h4->SetName("WHtautau"); }
    
    TH1F *h5; f1->GetObject("SMH",h5);
    if(h5){ h5->SetName("ZHbb"); }
    
    TH1F *h6; f1->GetObject("SMH",h6);
    if(h6){ h6->SetName("ZHtautau"); }
    
    TH1F *h7; f1->GetObject("SMH",h7);
    if(h7){ h7->SetName("ttH"); }

    TH1F *h8; f1->GetObject("diboson",h8);
    if(h8){ h8->SetName("WW"); }
    
    TH1F *h9; f1->GetObject("diboson",h9);
    if(h9){ h9->SetName("WZ"); }
    
    TH1F *h10; f1->GetObject("diboson",h10);
    if(h10){ h10->SetName("ZZ"); }

    TH1F *h11; f1->GetObject("DY",h11);
    if(h11){ h11->SetName("DYtt"); }

    TH1F *h12; f1->GetObject("Z",h12);
    if(h12){ h12->SetName("Zbb"); }
    
    TH1F *h13; f1->GetObject("Z",h13);
    if(h13){ h13->SetName("Zbc"); }
    
    TH1F *h14; f1->GetObject("Z",h14);
    if(h14){ h14->SetName("Zbl"); }
    
    TH1F *h15; f1->GetObject("Z",h15);
    if(h15){ h15->SetName("Zcc"); }
    
    TH1F *h16; f1->GetObject("Z",h16);
    if(h16){ h16->SetName("Zcl"); }
    
    TH1F *h17; f1->GetObject("Z",h17);
    if(h17){ h17->SetName("Zl"); }

    TH1F *h18; f1->GetObject("W",h18);
    if(h18){ h18->SetName("Wtt"); }
    
    TH1F *h19; f1->GetObject("W",h19);
    if(h19){ h19->SetName("WttFake"); }

    TH1F *h20; f1->GetObject("Ztt",h20);
    if(h20){ h20->SetName("Zttbb"); }
    
    TH1F *h21; f1->GetObject("Ztt",h21);
    if(h21){ h21->SetName("Zttbc"); }
    
    TH1F *h22; f1->GetObject("Ztt",h22);
    if(h22){ h22->SetName("Zttbl"); }
    
    TH1F *h23; f1->GetObject("Ztt",h23);
    if(h23){ h23->SetName("Zttcc"); }
    
    TH1F *h24; f1->GetObject("Ztt",h24);
    if(h24){ h24->SetName("Zttcl"); }
    
    TH1F *h25; f1->GetObject("Ztt",h25);
    if(h25){ h25->SetName("Zttl"); }

    TH1F *h26; f1->GetObject("singletop",h26);
    if(h26){ h26->SetName("stopWt"); }
    
    TH1F *h27; f1->GetObject("singletop",h27);
    if(h27){ h27->SetName("stops"); }
    
    TH1F *h28; f1->GetObject("singletop",h28);
    if(h28){ h28->SetName("stopt"); }

    TH1F *h29; f1->GetObject("VBFSM",h29);
    if(h29){ h29->SetName("VBFHtautau"); }
   
    f1->Write();

    */
}
