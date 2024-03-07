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
#include <iostream>
using namespace std;
string itoa(int num);
void SLT_txt_SM_TotalBkg(){

  const int n_smp = 39;
  string smp_tree[n_smp] = { "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal", "Nominal" };
  string smp;
  TChain  *chain_smp[n_smp];
  
  string smp_names[n_smp] = { "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt", "hh_bbtt" };
    
  for (int i=0; i<n_smp; i++)
    {
      smp = smp_names[i] +".root";
      cout<<smp<<endl;
      chain_smp[i] = new TChain(smp_tree[i].c_str());
      chain_smp[i]->Add(smp.c_str());
    }
  
  string h_title[n_smp] = { "ttH", "ttZ", "ttW", "VBFHtautau", "WHbb", "qqZHbb", "ggZHbb", "WHtautau", "qqZHtautau", "ggZHtautau", "ggFHtautau", "WZ", "WW", "ZZ", "DY", "DYtt", "ttbarFake", "WFake", "WttFake", "Zbb", "Zbc", "Zbl", "Zcc", "Zcl", "Zl", "W", "Wtt", "Zttbb", "Zttbc", "Zttbl", "Zttcc", "Zttcl", "Zttl", "stops", "stopWt", "stopt", "ttbar", "hh_bbtt", "hh_bbttVBFSM" };  // only for legend
    
  TH1::SetDefaultSumw2();
  TH1F * h_hist[n_smp];
  const char *h_nm;
  string hist_draw[n_smp];
    
// sqrt( ((mMMC-118000)/(mMMC)) * ((mMMC-118000)/(mMMC)) + ((mBB-120000)/(mBB)) * ((mBB-120000)/(mBB)) )


  //   ===========================================================   Mhh   ===========================================================
          
          TCanvas *c36 = new TCanvas ("c36", "Mhh",980,580);
            
          TPad *pad361 = new TPad("pad361","",0,0,0.75,1);
          TPad *pad362 = new TPad("pad362","",0.73,0,1,1);
          pad361->Draw();
          pad362->Draw();
            
          pad361->cd();
          pad361->SetTickx();
          gStyle->SetOptStat(kFALSE);
          
          for (int i=0; i<n_smp; i++){
              h_nm = h_title[i].c_str();
              h_hist[i] = new TH1F(h_nm, "",30,0,3000);
              h_hist[i]->GetYaxis()->SetRangeUser(0, 70000); //16000
          }
          
          for (int i=0; i<n_smp; i++){
              hist_draw[i]="mHHStar*0.001>>"+h_title[i];
          }
    
          for (int i=0; i<n_smp; i++){
	           h_hist[i]->Reset();
	           h_hist[i]->Sumw2();
          }
          
          for(int i = 0; i<n_smp; i++){
            
            if (i == 0 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"ttH\" )",  "SAMEHIST");}
            else if (i == 1 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"ttZ\" )",  "SAMEHIST");}
            else if (i == 2 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"ttW\" )",  "SAMEHIST");}
            else if (i == 3 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"VBFHtautau\" )",  "SAMEHIST");}
            else if (i == 4 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"WHbb\" )",  "SAMEHIST");}
            else if (i == 5 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"qqZHbb\" )",  "SAMEHIST");}
            else if (i == 6 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"ggZHbb\" )",  "SAMEHIST");}
            else if (i == 7 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"WHtautau\" )",  "SAMEHIST");}
            else if (i == 8 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"qqZHtautau\" )",  "SAMEHIST");}
            else if (i == 9 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"ggFHtautau\" )",  "SAMEHIST");}
            else if (i == 10 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"WZ\" )",  "SAMEHIST");}
            else if (i == 11 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"WZ\" )",  "SAMEHIST");}
            else if (i == 12 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"WW\" )",  "SAMEHIST");}
            else if (i == 13 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"ZZ\" )",  "SAMEHIST");}
            else if (i == 14 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"DY\" )",  "SAMEHIST");}
            else if (i == 15 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"DYtt\" )",  "SAMEHIST");}
            else if (i == 16 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"ttbarFake\" )",  "SAMEHIST");}
            else if (i == 17 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"WFake\" )",  "SAMEHIST");}
            else if (i == 18 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"WttFake\" )",  "SAMEHIST");}
            else if (i == 19 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zbb\" )",  "SAMEHIST");}
            else if (i == 20 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zbc\" )",  "SAMEHIST");}
            else if (i == 21 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zbl\" )",  "SAMEHIST");}
            else if (i == 22 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zcc\" )",  "SAMEHIST");}
            else if (i == 23 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zcl\" )",  "SAMEHIST");}
            else if (i == 24 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zl\" )",  "SAMEHIST");}
            else if (i == 25 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"W\" )",  "SAMEHIST");}
            else if (i == 26 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Wtt\" )",  "SAMEHIST");}
            else if (i == 27 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zttbb\" )",  "SAMEHIST");}
            else if (i == 28 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zttbc\" )",  "SAMEHIST");}
            else if (i == 29 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zttbl\" )",  "SAMEHIST");}
            else if (i == 30 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zttcc\" )",  "SAMEHIST");}
            else if (i == 31 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zttcl\" )",  "SAMEHIST");}
            else if (i == 32 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"Zttl\" )",  "SAMEHIST");}
            else if (i == 33 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"stops\" )",  "SAMEHIST");}
            else if (i == 34 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"stopWt\" )",  "SAMEHIST");}
            else if (i == 35 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"stopt\" )",  "SAMEHIST");}
            else if (i == 36 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"ttbar\" )",  "SAMEHIST");}
            else if (i == 37 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"hhttbb\" )",  "SAMEHIST");}
            else if (i == 38 ){chain_smp[i]->Draw(hist_draw[i].c_str(), "  (weight)*(OS==1 && n_btag==2 && mBB<150000 && ((Etaj1VBF*Etaj2VBF)<0) && sample ==\"hhttbbVBFSM\" )",  "SAMEHIST");}
            
          }
          
  
  double entries_VBFSM = 0; 
  double entries_Bkg = 0;
  double entries_noVBFSM = 0;

  double integral_VBFSM = 0;
  double integral_Bkg = 0;
  double integral_noVBFSM = 0;

  double error_VBFSM = 0;
  double error_Bkg = 0;
  double error_noVBFSM = 0;

  ofstream myfile;
  myfile.open ("Yields_SM_TotalBkg_BDT.txt");
  myfile << "---------------------------------------------------------------------" <<endl;
  myfile <<"                                                                                    "<<endl;
  myfile <<"        Sample                Entries                Sig                Error"<<endl;
  myfile <<"                                                                                    "<<endl;

    entries_VBFSM = h_hist[38]->GetEntries();
    integral_VBFSM = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM, "");

    myfile << "\t" << h_title[38] << "\t \t" << entries_VBFSM << "\t \t" << integral_VBFSM << "\t \t"  << error_VBFSM << endl;
    myfile << "                                                                  " << endl;


    for (int i=0; i<38; i++)
    {
        entries_Bkg = h_hist[i]->GetEntries();
        integral_Bkg = h_hist[i]->IntegralAndError(0, 3000, error_Bkg, "");

        myfile<<"\t" << h_title[i] << "\t \t" << entries_Bkg << "\t \t" << integral_Bkg << "\t \t"  << error_Bkg << endl;
        myfile << "                                                                                   " << endl;

        entries_noVBFSM += entries_Bkg;
        integral_noVBFSM += integral_Bkg; 
        error_noVBFSM += error_Bkg*error_Bkg;
    }

    error_noVBFSM = sqrt(error_noVBFSM);
    
  myfile << "---------------------------------------------------------------------" <<endl; 
  myfile<<"\t" << "Bkg :" << "\t \t" << entries_noVBFSM << "\t \t" << integral_noVBFSM << "\t \t" << error_noVBFSM << endl;
  myfile << "                                                                                   " << endl;
  myfile << "---------------------------------------------------------------------" <<endl;

            double S = 0;   S = integral_VBFSM;
            double dS = 0;  dS = error_VBFSM;
            double B = 0;   B = integral_noVBFSM;
            double dB = 0;  dB = error_noVBFSM;

            double Significance = 0;
            double R = 0;
            double E = 0;
            double EE = 0;

            if( B > 0 && S > 0) {
                 
                  double LSB = log(1 + S/B);
                  R =  2 * ( (S+B) * LSB - S );
                  E = LSB * LSB * dS * dS + (LSB - S/B) * (LSB - S/B) * dB * dB;

                  Significance = sqrt(R);
                  if(Significance > 0) { EE = sqrt(E) / Significance; }
                 
             }

  myfile<<"\t \t" << "Significance = " << "\t \t" << Significance << "\t \t" << "Error = " << "\t \t" << EE << endl;

  myfile.close();

    
  }
