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

void SLT_cut_SM_Mhh_TotalBkg(){

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
  
  string h_title[n_smp] = { "ttH", "ttZ", "ttW", "VBFHtautau", "WHbb", "qqZHbb", "ggZHbb", "WHtautau", "qqZHtautau", "ggZHtautau", "WZ", "WW", "ZZ", "DY", "DYtt", "ttbarFake", "WFake", "WttFake", "Zbb", "Zbc", "Zbl", "Zcc", "Zcl", "Zl", "W", "Wtt", "Zttbb", "Zttbc", "Zttbl", "Zttcc", "Zttcl", "Zttl", "stops", "stopWt", "stopt", "ttbar", "hh_bbtt", "ggFHtautau", "hhttbbVBFSM" };  // only for legend
    
  TH1::SetDefaultSumw2();
  TH1F * h_hist[n_smp];
  const char *h_nm;
  string hist_draw[n_smp];

      TCut weight = "weight";
      TCut TwoBTaggedJets = "n_btag==2";
      TCut TwoOppositeSignTau = "OS==1";
      TCut mBB = "mBB<150000";
      TCut VBF = "((Etaj1VBF*Etaj2VBF)<0)";

      TCut ttH = "sample ==\"ttH\"";
      TCut ttZ = "sample ==\"ttZ\"";
      TCut ttW = "sample ==\"ttW\"";
      TCut VBFHtautau = "sample ==\"VBFHtautau\"";
      TCut WHbb = "sample ==\"WHbb\"";
      TCut qqZHbb = "sample ==\"qqZHbb\"";
      TCut ggZHbb = "sample ==\"ggZHbb\"";
      TCut WHtautau = "sample ==\"WHtautau\"";
      TCut qqZHtautau = "sample ==\"qqZHtautau\"";
      TCut ggZHtautau = "sample ==\"ggZHtautau\"";
      TCut ggFHtautau = "sample ==\"ggFHtautau\"";

      TCut WZ = "sample ==\"WZ\"";
      TCut WW = "sample ==\"WW\"";
      TCut ZZ = "sample ==\"ZZ\"";
      TCut DY = "sample ==\"DY\"";
      TCut DYtt = "sample ==\"DYtt\"";
      TCut ttbarFake = "sample ==\"ttbarFake\"";
      TCut WFake = "sample ==\"WFake\"";
      TCut WttFake = "sample ==\"WttFake\"";

      TCut Zbb = "sample ==\"Zbb\"";
      TCut Zbc = "sample ==\"Zbc\"";
      TCut Zbl = "sample ==\"Zbl\"";
      TCut Zcc = "sample ==\"Zcc\"";
      TCut Zcl = "sample ==\"Zcl\"";
      TCut Zl = "sample ==\"Zl\"";

      TCut W = "sample ==\"W\"";
      TCut Wtt = "sample ==\"Wtt\"";

      TCut Zttbb = "sample ==\"Zttbb\"";
      TCut Zttbc = "sample ==\"Zttbc\"";
      TCut Zttbl = "sample ==\"Zttbl\"";
      TCut Zttcc = "sample ==\"Zttcc\"";
      TCut Zttcl = "sample ==\"Zttcl\"";
      TCut Zttl = "sample ==\"Zttl\"";

      TCut stops = "sample ==\"stops\"";
      TCut stopWt = "sample ==\"stopWt\"";
      TCut stopt = "sample ==\"stopt\"";

      TCut ttbar = "sample ==\"ttbar\"";
      TCut hhttbb = "sample ==\"hhttbb\"";
      TCut hhttbbVBFSM = "sample ==\"hhttbbVBFSM\"";

      TCut mjjVBF = "mjjVBF>500000";
      TCut X_HH = "X_HH<0.4";
      TCut MtW = "mTW<60000";
      TCut pTSixObjVBF = "pTSixObjVBF<60000";
      TCut dEtaHH = "dEtaHH>0.6";
      TCut mMMC = "mMMC<140000";
      TCut dRb0lep = "dRb0lep>2";
      TCut dPhiTauTauMET = "abs(dPhiTauTauMET)<0.8";
      TCut VBFjj = "(etaj1VBF*etaj2VBF)<-3";
      TCut dEtaTauTau = "dEtaTauTau<1.4";
      TCut mBB1 = "mBB>100000";
       TCut tau_rnn = "tau_rnn>0.18";
       TCut coshelicitytautau = "coshelicitytautau<0.8";
       TCut dRBB = "dRBB<3.2";
      

  
   
    cout << " " << endl;
    cout << "  ===========================================================   dEtaHH   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut2 = 3;
    TCut cut2_1[n_cut2] = { "dEtaHH>0.2", "dEtaHH>0.4", "dEtaHH>0.6" };
    string cut2_2[n_cut2] = { "dEtaHH>0.2", "dEtaHH>0.4", "dEtaHH>0.6" };
    

      TCanvas *canvas2[n_cut2] ;
      canvas2[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas2[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas2[2] = new TCanvas ("c2", "Mhh",980,580);
      
      TPad *pad21[n_cut2];
      pad21[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad21[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad21[2] = new TPad ("pad2", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut2;k++) {
           canvas2[k]->cd();
           pad21[k]->Draw();
           
           pad21[k]->cd();
           pad21[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
         
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut2_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut2_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut2_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut2_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut2_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut2_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut2_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut2_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut2_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut2_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut2_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut2_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut2_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut2_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut2_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut2_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut2_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut2_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut2_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut2_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut2_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut2_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut2_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut2_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut2_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut2_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut2_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut2_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut2_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut2_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut2_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut2_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut2_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut2_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut2_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut2_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut2_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut2_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut2_1[k]), "SAMEHIST");}
        }

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_2 = 0;
        double integral_Bkg_2 = 0;
        double integral_noVBFSM_2 = 0;

        double error_VBFSM_2 = 0;
        double error_Bkg_2 = 0;
        double error_noVBFSM_2 = 0;

        integral_VBFSM_2 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_2, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_2 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_2, "");

            integral_noVBFSM_2 += integral_Bkg_2;
            error_noVBFSM_2 += error_Bkg_2*error_Bkg_2;
        }

        error_noVBFSM_2 = sqrt(error_noVBFSM_2);

                double S_2 = 0;   S_2 = integral_VBFSM_2;
                double dS_2 = 0;  dS_2 = error_VBFSM_2;
                double B_2 = 0;   B_2 = integral_noVBFSM_2;
                double dB_2 = 0;  dB_2 = error_noVBFSM_2;

                double Significance_2 = 0;
                double R_2 = 0;
                double E_2 = 0;
                double EE_2 = 0;

                if( B_2 > 0 && S_2 > 0) {
                    
                      double LSB_2 = log(1 + S_2/B_2);
                      R_2 =  2 * ( (S_2+B_2) * LSB_2 - S_2 );
                      E_2 = LSB_2 * LSB_2 * dS_2 * dS_2 + (LSB_2 - S_2/B_2) * (LSB_2 - S_2/B_2) * dB_2 * dB_2;

                      Significance_2 = sqrt(R_2);
                      if(Significance_2 > 0) { EE_2 = sqrt(E_2) / Significance_2; }
                    
                }

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut2_2[k] << endl;
        cout << " mHHStar : " << " S = " << Significance_2 << " E = " << EE_2 << endl;
        cout << "" << endl;
          
      }
      
      
    cout << " " << endl;
    cout << "  ===========================================================   dEtalepTau   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut3 = 3;
    TCut cut3_1[n_cut3] = { "dEtalepTau<1.4", "dEtalepTau<1.6", "dEtalepTau<1.8" };
    string cut3_2[n_cut3] = { "dEtalepTau<1.4", "dEtalepTau<1.6", "dEtalepTau<1.8" };
    

      TCanvas *canvas3[n_cut3] ;
      canvas3[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas3[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas3[2] = new TCanvas ("c2", "Mhh",980,580);
      
      TPad *pad31[n_cut3];
      pad31[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad31[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad31[2] = new TPad ("pad2", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut3;k++) {
           canvas3[k]->cd();
           pad31[k]->Draw();
           
           pad31[k]->cd();
           pad31[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut3_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut3_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut3_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut3_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut3_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut3_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut3_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut3_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut3_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut3_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut3_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut3_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut3_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut3_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut3_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut3_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut3_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut3_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut3_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut3_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut3_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut3_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut3_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut3_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut3_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut3_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut3_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut3_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut3_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut3_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut3_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut3_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut3_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut3_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut3_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut3_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut3_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut3_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut3_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_3 = 0;
        double integral_Bkg_3 = 0;
        double integral_noVBFSM_3 = 0;

        double error_VBFSM_3 = 0;
        double error_Bkg_3 = 0;
        double error_noVBFSM_3 = 0;

        integral_VBFSM_3 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_3, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_3 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_3, "");

            integral_noVBFSM_3 += integral_Bkg_3;
            error_noVBFSM_3 += error_Bkg_3*error_Bkg_3;
        }

        error_noVBFSM_3 = sqrt(error_noVBFSM_3);

                double S_3 = 0;   S_3 = integral_VBFSM_3;
                double dS_3 = 0;  dS_3 = error_VBFSM_3;
                double B_3 = 0;   B_3 = integral_noVBFSM_3;
                double dB_3 = 0;  dB_3 = error_noVBFSM_3;

                double Significance_3 = 0;
                double R_3 = 0;
                double E_3 = 0;
                double EE_3 = 0;

                if( B_3 > 0 && S_3 > 0) {
                    
                      double LSB_3 = log(1 + S_3/B_3);
                      R_3 =  2 * ( (S_3+B_3) * LSB_3 - S_3 );
                      E_3 = LSB_3 * LSB_3 * dS_3 * dS_3 + (LSB_3 - S_3/B_3) * (LSB_3 - S_3/B_3) * dB_3 * dB_3;

                      Significance_3 = sqrt(R_3);
                      if(Significance_3 > 0) { EE_3 = sqrt(E_3) / Significance_3; }
                    
                }
           
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut3_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_3 << " E = " << EE_3 << endl;
        cout << "" << endl;
          
      }
         
 
    cout << " " << endl;
    cout << "  ===========================================================   dEtajjVBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut4 = 6;
    TCut cut4_1[n_cut4] = { "dEtajjVBF>3", "dEtajjVBF>3.2", "dEtajjVBF>3.4", "dEtajjVBF>3.6", "dEtajjVBF>3.8", "dEtajjVBF>4" };
    string cut4_2[n_cut4] = { "dEtajjVBF>3", "dEtajjVBF>3.2", "dEtajjVBF>3.4", "dEtajjVBF>3.6", "dEtajjVBF>3.8", "dEtajjVBF>4" };
    

      TCanvas *canvas4[n_cut4] ;
      canvas4[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas4[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas4[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas4[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas4[4] = new TCanvas ("c4", "Mhh",980,580);
      canvas4[5] = new TCanvas ("c5", "Mhh",980,580);
    
      TPad *pad41[n_cut4];
      pad41[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad41[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad41[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad41[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad41[4] = new TPad ("pad4", "", 0,0,0.75,1);
      pad41[5] = new TPad ("pad5", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }
      
      for (int k=0;k<n_cut4;k++) {
           canvas4[k]->cd();
           pad41[k]->Draw();
           
           pad41[k]->cd();
           pad41[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut4_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut4_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut4_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut4_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut4_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut4_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut4_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut4_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut4_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut4_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut4_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut4_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut4_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut4_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut4_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut4_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut4_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut4_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut4_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut4_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut4_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut4_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut4_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut4_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut4_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut4_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut4_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut4_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut4_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut4_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut4_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut4_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut4_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut4_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut4_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut4_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut4_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut4_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut4_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_4 = 0;
        double integral_Bkg_4 = 0;
        double integral_noVBFSM_4 = 0;

        double error_VBFSM_4 = 0;
        double error_Bkg_4 = 0;
        double error_noVBFSM_4 = 0;

        integral_VBFSM_4 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_4, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_4 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_4, "");

            integral_noVBFSM_4 += integral_Bkg_4;
            error_noVBFSM_4 += error_Bkg_4*error_Bkg_4;
        }

        error_noVBFSM_4 = sqrt(error_noVBFSM_4);

                double S_4 = 0;   S_4 = integral_VBFSM_4;
                double dS_4 = 0;  dS_4 = error_VBFSM_4;
                double B_4 = 0;   B_4 = integral_noVBFSM_4;
                double dB_4 = 0;  dB_4 = error_noVBFSM_4;

                double Significance_4 = 0;
                double R_4 = 0;
                double E_4 = 0;
                double EE_4 = 0;

                if( B_4 > 0 && S_4 > 0) {
                    
                      double LSB_4 = log(1 + S_4/B_4);
                      R_4 =  2 * ( (S_4+B_4) * LSB_4 - S_4 );
                      E_4 = LSB_4 * LSB_4 * dS_4 * dS_4 + (LSB_4 - S_4/B_4) * (LSB_4 - S_4/B_4) * dB_4 * dB_4;

                      Significance_4 = sqrt(R_4);
                      if(Significance_4 > 0) { EE_4 = sqrt(E_4) / Significance_4; }
                    
                }
           
        
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut4_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_4 << " E = " << EE_4 << endl;
        cout << "" << endl;
          
      }
    
    

    cout << " " << endl;
    cout << "  ===========================================================   pTjjVBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut7 = 3;
    TCut cut7_1[n_cut7] = { "pTjjVBF*0.001>20", "pTjjVBF*0.001>30", "pTjjVBF*0.001>40" };
    string cut7_2[n_cut7] = { "pTjjVBF>20GeV", "pTjjVBF>30GeV", "pTjjVBF>40GeV" };
    

      TCanvas *canvas7[n_cut7] ;
      canvas7[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas7[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas7[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad71[n_cut7];
      pad71[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad71[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad71[2] = new TPad ("pad2", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut7;k++) {
           canvas7[k]->cd();
           pad71[k]->Draw();
           
           pad71[k]->cd();
           pad71[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut7_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut7_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut7_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut7_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut7_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut7_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut7_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut7_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut7_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut7_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut7_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut7_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut7_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut7_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut7_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut7_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut7_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut7_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut7_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut7_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut7_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut7_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut7_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut7_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut7_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut7_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut7_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut7_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut7_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut7_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut7_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut7_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut7_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut7_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut7_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut7_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut7_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut7_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut7_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_7 = 0;
        double integral_Bkg_7 = 0;
        double integral_noVBFSM_7 = 0;

        double error_VBFSM_7 = 0;
        double error_Bkg_7 = 0;
        double error_noVBFSM_7 = 0;

        integral_VBFSM_7 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_7, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_7 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_7, "");

            integral_noVBFSM_7 += integral_Bkg_7;
            error_noVBFSM_7 += error_Bkg_7*error_Bkg_7;
        }

        error_noVBFSM_7 = sqrt(error_noVBFSM_7);

                double S_7 = 0;   S_7 = integral_VBFSM_7;
                double dS_7 = 0;  dS_7 = error_VBFSM_7;
                double B_7 = 0;   B_7 = integral_noVBFSM_7;
                double dB_7 = 0;  dB_7 = error_noVBFSM_7;

                double Significance_7 = 0;
                double R_7 = 0;
                double E_7 = 0;
                double EE_7 = 0;

                if( B_7 > 0 && S_7 > 0) {
                    
                      double LSB_7 = log(1 + S_7/B_7);
                      R_7 =  2 * ( (S_7+B_7) * LSB_7 - S_7 );
                      E_7 = LSB_7 * LSB_7 * dS_7 * dS_7 + (LSB_7 - S_7/B_7) * (LSB_7 - S_7/B_7) * dB_7 * dB_7;

                      Significance_7 = sqrt(R_7);
                      if(Significance_7 > 0) { EE_7 = sqrt(E_7) / Significance_7; }
                    
                }
           
        
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut7_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_7 << " E = " << EE_7 << endl;
        cout << "" << endl;
          
      }
     
        
    cout << " " << endl;
    cout << "  ===========================================================   dPhiTauTauMET   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut8 = 7;
    TCut cut8_1[n_cut8] = { "abs(dPhiTauTauMET)<0.8", "abs(dPhiTauTauMET)<1", "abs(dPhiTauTauMET)<1.2", "abs(dPhiTauTauMET)<1.4", "abs(dPhiTauTauMET)<1.6", "abs(dPhiTauTauMET)<1.8", "abs(dPhiTauTauMET)<2" };
    string cut8_2[n_cut8] = { "abs(dPhiTauTauMET)<0.8", "abs(dPhiTauTauMET)<1", "abs(dPhiTauTauMET)<1.2", "abs(dPhiTauTauMET)<1.4", "abs(dPhiTauTauMET)<1.6", "abs(dPhiTauTauMET)<1.8", "abs(dPhiTauTauMET)<2" };
    

      TCanvas *canvas8[n_cut8] ;
      canvas8[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas8[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas8[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas8[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas8[4] = new TCanvas ("c4", "Mhh",980,580);
      canvas8[5] = new TCanvas ("c5", "Mhh",980,580);
      canvas8[6] = new TCanvas ("c6", "Mhh",980,580);
    
      TPad *pad81[n_cut8];
      pad81[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad81[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad81[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad81[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad81[4] = new TPad ("pad4", "", 0,0,0.75,1);
      pad81[5] = new TPad ("pad5", "", 0,0,0.75,1);
      pad81[6] = new TPad ("pad6", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut8;k++) {
           canvas8[k]->cd();
           pad81[k]->Draw();
           
           pad81[k]->cd();
           pad81[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut8_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut8_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut8_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut8_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut8_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut8_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut8_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut8_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut8_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut8_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut8_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut8_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut8_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut8_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut8_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut8_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut8_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut8_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut8_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut8_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut8_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut8_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut8_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut8_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut8_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut8_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut8_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut8_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut8_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut8_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut8_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut8_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut8_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut8_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut8_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut8_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut8_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut8_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut8_1[k]), "SAMEHIST");}
        }

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_8 = 0;
        double integral_Bkg_8 = 0;
        double integral_noVBFSM_8 = 0;

        double error_VBFSM_8 = 0;
        double error_Bkg_8 = 0;
        double error_noVBFSM_8 = 0;

        integral_VBFSM_8 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_8, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_8 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_8, "");

            integral_noVBFSM_8 += integral_Bkg_8;
            error_noVBFSM_8 += error_Bkg_8*error_Bkg_8;
        }

        error_noVBFSM_8 = sqrt(error_noVBFSM_8);

                double S_8 = 0;   S_8 = integral_VBFSM_8;
                double dS_8 = 0;  dS_8 = error_VBFSM_8;
                double B_8 = 0;   B_8 = integral_noVBFSM_8;
                double dB_8 = 0;  dB_8 = error_noVBFSM_8;

                double Significance_8 = 0;
                double R_8 = 0;
                double E_8 = 0;
                double EE_8 = 0;

                if( B_8 > 0 && S_8 > 0) {
                    
                      double LSB_8 = log(1 + S_8/B_8);
                      R_8 =  2 * ( (S_8+B_8) * LSB_8 - S_8 );
                      E_8 = LSB_8 * LSB_8 * dS_8 * dS_8 + (LSB_8 - S_8/B_8) * (LSB_8 - S_8/B_8) * dB_8 * dB_8;

                      Significance_8 = sqrt(R_8);
                      if(Significance_8 > 0) { EE_8 = sqrt(E_8) / Significance_8; }
                    
                }
           
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut8_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_8 << " E = " << EE_8 << endl;
        cout << "" << endl;
          
      }
       
 
    cout << " " << endl;
    cout << "  ===========================================================   dPhiLepMET   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut9 = 6;
    TCut cut9_1[n_cut9] = { "abs(dPhiLepMET)<1", "abs(dPhiLepMET)<1.2", "abs(dPhiLepMET)<1.4", "abs(dPhiLepMET)<1.6", "abs(dPhiLepMET)<1.8", "abs(dPhiLepMET)<2" };
    string cut9_2[n_cut9] = { "abs(dPhiLepMET)<1", "abs(dPhiLepMET)<1.2", "abs(dPhiLepMET)<1.4", "abs(dPhiLepMET)<1.6", "abs(dPhiLepMET)<1.8", "abs(dPhiLepMET)<2" };
    

      TCanvas *canvas9[n_cut9] ;
      canvas9[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas9[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas9[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas9[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas9[4] = new TCanvas ("c4", "Mhh",980,580);
      canvas9[5] = new TCanvas ("c5", "Mhh",980,580);
    
      TPad *pad91[n_cut9];
      pad91[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad91[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad91[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad91[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad91[4] = new TPad ("pad4", "", 0,0,0.75,1);
      pad91[5] = new TPad ("pad5", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut9;k++) {
           canvas9[k]->cd();
           pad91[k]->Draw();
           
           pad91[k]->cd();
           pad91[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut9_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut9_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut9_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut9_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut9_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut9_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut9_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut9_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut9_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut9_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut9_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut9_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut9_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut9_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut9_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut9_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut9_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut9_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut9_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut9_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut9_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut9_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut9_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut9_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut9_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut9_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut9_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut9_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut9_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut9_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut9_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut9_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut9_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut9_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut9_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut9_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut9_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut9_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut9_1[k]), "SAMEHIST");}
        }
    

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_9 = 0;
        double integral_Bkg_9 = 0;
        double integral_noVBFSM_9 = 0;

        double error_VBFSM_9 = 0;
        double error_Bkg_9 = 0;
        double error_noVBFSM_9 = 0;

        integral_VBFSM_9 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_9, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_9 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_9, "");

            integral_noVBFSM_9 += integral_Bkg_9;
            error_noVBFSM_9 += error_Bkg_9*error_Bkg_9;
        }

        error_noVBFSM_9 = sqrt(error_noVBFSM_9);

                double S_9 = 0;   S_9 = integral_VBFSM_9;
                double dS_9 = 0;  dS_9 = error_VBFSM_9;
                double B_9 = 0;   B_9 = integral_noVBFSM_9;
                double dB_9 = 0;  dB_9 = error_noVBFSM_9;

                double Significance_9 = 0;
                double R_9 = 0;
                double E_9 = 0;
                double EE_9 = 0;

                if( B_9 > 0 && S_9 > 0) {
                    
                      double LSB_9 = log(1 + S_9/B_9);
                      R_9 =  2 * ( (S_9+B_9) * LSB_9 - S_9 );
                      E_9 = LSB_9 * LSB_9 * dS_9 * dS_9 + (LSB_9 - S_9/B_9) * (LSB_9 - S_9/B_9) * dB_9 * dB_9;

                      Significance_9 = sqrt(R_9);
                      if(Significance_9 > 0) { EE_9 = sqrt(E_9) / Significance_9; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut9_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_9 << " E = " << EE_9 << endl;
        cout << "" << endl;
          
      }
  
     
    cout << " " << endl;
    cout << "  ===========================================================   dPhiTauMET   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut11 = 3;
    TCut cut11_1[n_cut11] = { "abs(dPhiTauMET)<2.4", "abs(dPhiTauMET)<2.6", "abs(dPhiTauMET)<3" };
    string cut11_2[n_cut11] = { "abs(dPhiTauMET)<2.4", "abs(dPhiTauMET)<2.6", "abs(dPhiTauMET)<3" };
    

      TCanvas *canvas11[n_cut11] ;
      canvas11[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas11[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas11[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad111[n_cut11];
      pad111[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad111[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad111[2] = new TPad ("pad2", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
              h_nm = h_title[i].c_str();
              h_hist[i] = new TH1F(h_nm, "",30,0,3000);
              h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
          }
      
      for (int k=0;k<n_cut11;k++) {
           canvas11[k]->cd();
           pad111[k]->Draw();
           
           pad111[k]->cd();
           pad111[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut11_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut11_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut11_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut11_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut11_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut11_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut11_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut11_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut11_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut11_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut11_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut11_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut11_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut11_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut11_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut11_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut11_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut11_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut11_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut11_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut11_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut11_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut11_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut11_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut11_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut11_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut11_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut11_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut11_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut11_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut11_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut11_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut11_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut11_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut11_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut11_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut11_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut11_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut11_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_11 = 0;
        double integral_Bkg_11 = 0;
        double integral_noVBFSM_11 = 0;

        double error_VBFSM_11 = 0;
        double error_Bkg_11 = 0;
        double error_noVBFSM_11 = 0;

        integral_VBFSM_11 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_11, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_11 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_11, "");

            integral_noVBFSM_11 += integral_Bkg_11;
            error_noVBFSM_11 += error_Bkg_11*error_Bkg_11;
        }

        error_noVBFSM_11 = sqrt(error_noVBFSM_11);

                double S_11 = 0;   S_11 = integral_VBFSM_11;
                double dS_11 = 0;  dS_11 = error_VBFSM_11;
                double B_11 = 0;   B_11 = integral_noVBFSM_11;
                double dB_11 = 0;  dB_11 = error_noVBFSM_11;

                double Significance_11 = 0;
                double R_11 = 0;
                double E_11 = 0;
                double EE_11 = 0;

                if( B_11 > 0 && S_11 > 0) {
                    
                      double LSB_11 = log(1 + S_11/B_11);
                      R_11 =  2 * ( (S_11+B_11) * LSB_11 - S_11 );
                      E_11 = LSB_11 * LSB_11 * dS_11 * dS_11 + (LSB_11 - S_11/B_11) * (LSB_11 - S_11/B_11) * dB_11 * dB_11;

                      Significance_11 = sqrt(R_11);
                      if(Significance_11 > 0) { EE_11 = sqrt(E_11) / Significance_11; }
                    
                }
           
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut11_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_11 << " E = " << EE_11 << endl;
        cout << "" << endl;
          
      }
    
    
 
    cout << " " << endl;
    cout << "  ===========================================================   dRBB   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut16 = 5;
    TCut cut16_1[n_cut16] = { "dRBB>0.6", "dRBB<3", "dRBB<3.2", "dRBB<3.4", "dRBB<3.6" };
    string cut16_2[n_cut16] = { "dRBB>0.6", "dRBB<3", "dRBB<3.2", "dRBB<3.4", "dRBB<3.6" };
    

      TCanvas *canvas16[n_cut16] ;
      canvas16[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas16[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas16[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas16[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas16[4] = new TCanvas ("c4", "Mhh",980,580);
    
      TPad *pad161[n_cut16];
      pad161[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad161[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad161[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad161[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad161[4] = new TPad ("pad4", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut16;k++) {
           canvas16[k]->cd();
           pad161[k]->Draw();
           
           pad161[k]->cd();
           pad161[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut16_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut16_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut16_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut16_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut16_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut16_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut16_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut16_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut16_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut16_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut16_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut16_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut16_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut16_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut16_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut16_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut16_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut16_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut16_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut16_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut16_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut16_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut16_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut16_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut16_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut16_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut16_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut16_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut16_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut16_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut16_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut16_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut16_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut16_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut16_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut16_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut16_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut16_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut16_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_16 = 0;
        double integral_Bkg_16 = 0;
        double integral_noVBFSM_16 = 0;

        double error_VBFSM_16 = 0;
        double error_Bkg_16 = 0;
        double error_noVBFSM_16 = 0;

        integral_VBFSM_16 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_16, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_16 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_16, "");

            integral_noVBFSM_16 += integral_Bkg_16;
            error_noVBFSM_16 += error_Bkg_16*error_Bkg_16;
        }

        error_noVBFSM_16 = sqrt(error_noVBFSM_16);

                double S_16 = 0;   S_16 = integral_VBFSM_16;
                double dS_16 = 0;  dS_16 = error_VBFSM_16;
                double B_16 = 0;   B_16 = integral_noVBFSM_16;
                double dB_16 = 0;  dB_16 = error_noVBFSM_16;

                double Significance_16 = 0;
                double R_16 = 0;
                double E_16 = 0;
                double EE_16 = 0;

                if( B_16 > 0 && S_16 > 0) {
                    
                      double LSB_16 = log(1 + S_16/B_16);
                      R_16 =  2 * ( (S_16+B_16) * LSB_16 - S_16 );
                      E_16 = LSB_16 * LSB_16 * dS_16 * dS_16 + (LSB_16 - S_16/B_16) * (LSB_16 - S_16/B_16) * dB_16 * dB_16;

                      Significance_16 = sqrt(R_16);
                      if(Significance_16 > 0) { EE_16 = sqrt(E_16) / Significance_16; }
                    
                }


        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut16_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_16 << " E = " << EE_16 << endl;
        cout << "" << endl;
          
      }
       
      
      
    cout << " " << endl;
    cout << "  ===========================================================   dRTauLep   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut18 = 5;
    TCut cut18_1[n_cut18] = { "dRTauLep<2.4", "dRTauLep<2.6", "dRTauLep<2.8", "dRTauLep<3", "dRTauLep<3.2" };
    string cut18_2[n_cut18] = { "dRTauLep<2.4", "dRTauLep<2.6", "dRTauLep<2.8", "dRTauLep<3", "dRTauLep<3.2" };
    

      TCanvas *canvas18[n_cut18] ;
      canvas18[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas18[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas18[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas18[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas18[4] = new TCanvas ("c4", "Mhh",980,580);
    
      TPad *pad181[n_cut18];
      pad181[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad181[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad181[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad181[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad181[4] = new TPad ("pad4", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut18;k++) {
           canvas18[k]->cd();
           pad181[k]->Draw();
           
           pad181[k]->cd();
           pad181[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut18_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut18_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut18_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut18_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut18_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut18_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut18_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut18_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut18_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut18_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut18_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut18_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut18_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut18_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut18_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut18_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut18_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut18_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut18_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut18_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut18_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut18_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut18_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut18_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut18_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut18_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut18_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut18_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut18_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut18_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut18_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut18_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut18_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut18_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut18_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut18_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut18_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut18_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut18_1[k]), "SAMEHIST");}
        }

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_18 = 0;
        double integral_Bkg_18 = 0;
        double integral_noVBFSM_18 = 0;

        double error_VBFSM_18 = 0;
        double error_Bkg_18 = 0;
        double error_noVBFSM_18 = 0;

        integral_VBFSM_18 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_18, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_18 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_18, "");

            integral_noVBFSM_18 += integral_Bkg_18;
            error_noVBFSM_18 += error_Bkg_18*error_Bkg_18;
        }

        error_noVBFSM_18 = sqrt(error_noVBFSM_18);

                double S_18 = 0;   S_18 = integral_VBFSM_18;
                double dS_18 = 0;  dS_18 = error_VBFSM_18;
                double B_18 = 0;   B_18 = integral_noVBFSM_18;
                double dB_18 = 0;  dB_18 = error_noVBFSM_18;

                double Significance_18 = 0;
                double R_18 = 0;
                double E_18 = 0;
                double EE_18 = 0;

                if( B_18 > 0 && S_18 > 0) {
                    
                      double LSB_18 = log(1 + S_18/B_18);
                      R_18 =  2 * ( (S_18+B_18) * LSB_18 - S_18 );
                      E_18 = LSB_18 * LSB_18 * dS_18 * dS_18 + (LSB_18 - S_18/B_18) * (LSB_18 - S_18/B_18) * dB_18 * dB_18;

                      Significance_18 = sqrt(R_18);
                      if(Significance_18 > 0) { EE_18 = sqrt(E_18) / Significance_18; }
                    
                }
           

        
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut18_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_18 << " E = " << EE_18 << endl;
        cout << "" << endl;
          
      }
      
       
    cout << " " << endl;
    cout << "  ===========================================================   dRjjVBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut19 = 8;
    TCut cut19_1[n_cut19] = { "dRjjVBF>3", "dRjjVBF>3.2", "dRjjVBF>3.4", "dRjjVBF>3.6", "dRjjVBF>3.8", "dRjjVBF>4", "dRjjVBF>4.2", "dRjjVBF>4.4" };
    string cut19_2[n_cut19] = { "dRjjVBF>3", "dRjjVBF>3.2", "dRjjVBF>3.4", "dRjjVBF>3.6", "dRjjVBF>3.8", "dRjjVBF>4", "dRjjVBF>4.2", "dRjjVBF>4.4" };
    

      TCanvas *canvas19[n_cut19] ;
      canvas19[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas19[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas19[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas19[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas19[4] = new TCanvas ("c4", "Mhh",980,580);
      canvas19[5] = new TCanvas ("c5", "Mhh",980,580);
      canvas19[6] = new TCanvas ("c6", "Mhh",980,580);
      canvas19[7] = new TCanvas ("c7", "Mhh",980,580);
    
      TPad *pad191[n_cut19];
      pad191[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad191[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad191[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad191[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad191[4] = new TPad ("pad4", "", 0,0,0.75,1);
      pad191[5] = new TPad ("pad5", "", 0,0,0.75,1);
      pad191[6] = new TPad ("pad6", "", 0,0,0.75,1);
      pad191[7] = new TPad ("pad7", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut19;k++) {
           canvas19[k]->cd();
           pad191[k]->Draw();
           
           pad191[k]->cd();
           pad191[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut19_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut19_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut19_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut19_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut19_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut19_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut19_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut19_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut19_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut19_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut19_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut19_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut19_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut19_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut19_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut19_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut19_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut19_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut19_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut19_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut19_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut19_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut19_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut19_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut19_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut19_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut19_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut19_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut19_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut19_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut19_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut19_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut19_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut19_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut19_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut19_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut19_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut19_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut19_1[k]), "SAMEHIST");}
        }


       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_19 = 0;
        double integral_Bkg_19 = 0;
        double integral_noVBFSM_19 = 0;

        double error_VBFSM_19 = 0;
        double error_Bkg_19 = 0;
        double error_noVBFSM_19 = 0;

        integral_VBFSM_19 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_19, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_19 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_19, "");

            integral_noVBFSM_19 += integral_Bkg_19;
            error_noVBFSM_19 += error_Bkg_19*error_Bkg_19;
        }

        error_noVBFSM_19= sqrt(error_noVBFSM_19);

                double S_19 = 0;   S_19 = integral_VBFSM_19;
                double dS_19 = 0;  dS_19 = error_VBFSM_19;
                double B_19 = 0;   B_19 = integral_noVBFSM_19;
                double dB_19 = 0;  dB_19 = error_noVBFSM_19;

                double Significance_19 = 0;
                double R_19 = 0;
                double E_19 = 0;
                double EE_19 = 0;

                if( B_19 > 0 && S_19 > 0) {
                    
                      double LSB_19 = log(1 + S_19/B_19);
                      R_19 =  2 * ( (S_19+B_19) * LSB_19 - S_19 );
                      E_19 = LSB_19 * LSB_19 * dS_19 * dS_19 + (LSB_19 - S_19/B_19) * (LSB_19 - S_19/B_19) * dB_19 * dB_19;

                      Significance_19 = sqrt(R_19);
                      if(Significance_19 > 0) { EE_19 = sqrt(E_19) / Significance_19; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut19_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_19 << " E = " << EE_19 << endl;
        cout << "" << endl;
          
      }
     
     
       
    cout << " " << endl;
    cout << "  ===========================================================   pTHH   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut24 = 2;
    TCut cut24_1[n_cut24] = { "pTHH*0.001>20", "pTHH*0.001>40" };
    string cut24_2[n_cut24] = { "pTHH>20GeV", "pTHH>40GeV" };
    

      TCanvas *canvas24[n_cut24] ;
      canvas24[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas24[1] = new TCanvas ("c1", "Mhh",980,580);
    
      TPad *pad241[n_cut24];
      pad241[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad241[1] = new TPad ("pad1", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut24;k++) {
           canvas24[k]->cd();
           pad241[k]->Draw();
           
           pad241[k]->cd();
           pad241[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut24_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut24_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut24_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut24_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut24_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut24_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut24_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut24_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut24_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut24_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut24_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut24_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut24_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut24_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut24_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut24_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut24_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut24_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut24_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut24_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut24_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut24_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut24_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut24_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut24_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut24_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut24_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut24_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut24_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut24_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut24_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut24_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut24_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut24_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut24_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut24_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut24_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut24_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut24_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_24 = 0;
        double integral_Bkg_24 = 0;
        double integral_noVBFSM_24 = 0;

        double error_VBFSM_24 = 0;
        double error_Bkg_24 = 0;
        double error_noVBFSM_24 = 0;

        integral_VBFSM_24 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_24, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_24 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_24, "");

            integral_noVBFSM_24 += integral_Bkg_24;
            error_noVBFSM_24 += error_Bkg_24*error_Bkg_24;
        }

        error_noVBFSM_24 = sqrt(error_noVBFSM_24);

                double S_24 = 0;   S_24 = integral_VBFSM_24;
                double dS_24 = 0;  dS_24 = error_VBFSM_24;
                double B_24 = 0;   B_24 = integral_noVBFSM_24;
                double dB_24 = 0;  dB_24 = error_noVBFSM_24;

                double Significance_24 = 0;
                double R_24 = 0;
                double E_24 = 0;
                double EE_24 = 0;

                if( B_24 > 0 && S_24 > 0) {
                    
                      double LSB_24 = log(1 + S_24/B_24);
                      R_24 =  2 * ( (S_24+B_24) * LSB_24 - S_24 );
                      E_24 = LSB_24 * LSB_24 * dS_24 * dS_24 + (LSB_24 - S_24/B_24) * (LSB_24 - S_24/B_24) * dB_24 * dB_24;

                      Significance_24 = sqrt(R_24);
                      if(Significance_24 > 0) { EE_24 = sqrt(E_24) / Significance_24; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut24_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_24 << " E = " << EE_24 << endl;
        cout << "" << endl;
          
      }
       
     
     
    cout << " " << endl;
    cout << "  ===========================================================   coshelicitytautau   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut28 = 2;
    TCut cut28_1[n_cut28] = { "abs(coshelicitytautau)<0.8", "abs(coshelicitytautau)<0.9" };
    string cut28_2[n_cut28] = { "abs(coshelicitytautau)<0.8", "abs(coshelicitytautau)<0.9" };
    

      TCanvas *canvas28[n_cut28] ;
      canvas28[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas28[1] = new TCanvas ("c1", "Mhh",980,580);
    
      TPad *pad281[n_cut28];
      pad281[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad281[1] = new TPad ("pad1", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut28;k++) {
           canvas28[k]->cd();
           pad281[k]->Draw();
           
           pad281[k]->cd();
           pad281[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut28_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut28_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut28_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut28_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut28_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut28_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut28_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut28_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut28_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut28_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut28_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut28_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut28_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut28_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut28_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut28_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut28_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut28_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut28_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut28_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut28_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut28_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut28_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut28_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut28_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut28_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut28_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut28_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut28_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut28_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut28_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut28_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut28_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut28_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut28_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut28_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut28_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut28_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut28_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_28 = 0;
        double integral_Bkg_28 = 0;
        double integral_noVBFSM_28 = 0;

        double error_VBFSM_28 = 0;
        double error_Bkg_28 = 0;
        double error_noVBFSM_28 = 0;

        integral_VBFSM_28 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_28, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_28 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_28, "");

            integral_noVBFSM_28 += integral_Bkg_28;
            error_noVBFSM_28 += error_Bkg_28*error_Bkg_28;
        }

        error_noVBFSM_28= sqrt(error_noVBFSM_28);

                double S_28 = 0;   S_28 = integral_VBFSM_28;
                double dS_28 = 0;  dS_28 = error_VBFSM_28;
                double B_28 = 0;   B_28 = integral_noVBFSM_28;
                double dB_28 = 0;  dB_28 = error_noVBFSM_28;

                double Significance_28 = 0;
                double R_28 = 0;
                double E_28 = 0;
                double EE_28 = 0;

                if( B_28 > 0 && S_28 > 0) {
                    
                      double LSB_28 = log(1 + S_28/B_28);
                      R_28 =  2 * ( (S_28+B_28) * LSB_28 - S_28 );
                      E_28 = LSB_28 * LSB_28 * dS_28 * dS_28 + (LSB_28 - S_28/B_28) * (LSB_28 - S_28/B_28) * dB_28 * dB_28;

                      Significance_28 = sqrt(R_28);
                      if(Significance_28 > 0) { EE_28 = sqrt(E_28) / Significance_28; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut28_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_28 << " E = " << EE_28 << endl;
        cout << "" << endl;
          
      }
    
     
      
    cout << " " << endl;
    cout << "  ===========================================================   pTLep   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut32 = 5;
    TCut cut32_1[n_cut32] = { "pTLep*0.001<120", "pTLep*0.001<140", "pTLep*0.001<160", "pTLep*0.001<180", "pTLep*0.001<200" };
    string cut32_2[n_cut32] = { "pTLep<120GeV", "pTLep<140GeV", "pTLep<160GeV", "pTLep<180GeV","pTLep<200GeV" };
    

      TCanvas *canvas32[n_cut32] ;
      canvas32[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas32[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas32[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas32[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas32[4] = new TCanvas ("c4", "Mhh",980,580);
    
      TPad *pad321[n_cut32];
      pad321[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad321[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad321[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad321[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad321[4] = new TPad ("pad4", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut32;k++) {
           canvas32[k]->cd();
           pad321[k]->Draw();
           
           pad321[k]->cd();
           pad321[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut32_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut32_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut32_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut32_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut32_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut32_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut32_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut32_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut32_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut32_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut32_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut32_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut32_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut32_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut32_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut32_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut32_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut32_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut32_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut32_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut32_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut32_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut32_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut32_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut32_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut32_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut32_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut32_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut32_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut32_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut32_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut32_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut32_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut32_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut32_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut32_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut32_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut32_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut32_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_32 = 0;
        double integral_Bkg_32 = 0;
        double integral_noVBFSM_32 = 0;

        double error_VBFSM_32 = 0;
        double error_Bkg_32 = 0;
        double error_noVBFSM_32 = 0;

        integral_VBFSM_32 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_32, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_32 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_32, "");

            integral_noVBFSM_32 += integral_Bkg_32;
            error_noVBFSM_32 += error_Bkg_32*error_Bkg_32;
        }

        error_noVBFSM_32 = sqrt(error_noVBFSM_32);

                double S_32 = 0;   S_32 = integral_VBFSM_32;
                double dS_32 = 0;  dS_32 = error_VBFSM_32;
                double B_32 = 0;   B_32 = integral_noVBFSM_32;
                double dB_32 = 0;  dB_32 = error_noVBFSM_32;

                double Significance_32 = 0;
                double R_32 = 0;
                double E_32 = 0;
                double EE_32 = 0;

                if( B_32 > 0 && S_32 > 0) {
                    
                      double LSB_32 = log(1 + S_32/B_32);
                      R_32 =  2 * ( (S_32+B_32) * LSB_32 - S_32 );
                      E_32 = LSB_32 * LSB_32 * dS_32 * dS_32 + (LSB_32 - S_32/B_32) * (LSB_32 - S_32/B_32) * dB_32 * dB_32;

                      Significance_32 = sqrt(R_32);
                      if(Significance_32 > 0) { EE_32 = sqrt(E_32) / Significance_32; }
                    
                }
           

        
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut32_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_32 << " E = " << EE_32 << endl;
        cout << "" << endl;
          
      }
      
             
    cout << " " << endl;
    cout << "  ===========================================================   mBB   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut33 = 3;
    TCut cut33_1[n_cut33] = { "mBB>60000", "mBB>80000", "mBB>100000" };
    string cut33_2[n_cut33] = { "mBB>60GeV", "mBB>80GeV", "mBB>100GeV" };
    

      TCanvas *canvas33[n_cut33] ;
      canvas33[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas33[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas33[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad331[n_cut33];
      pad331[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad331[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad331[2] = new TPad ("pad2", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut33;k++) {
           canvas33[k]->cd();
           pad331[k]->Draw();
           
           pad331[k]->cd();
           pad331[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut33_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut33_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut33_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut33_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut33_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut33_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut33_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut33_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut33_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut33_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut33_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut33_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut33_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut33_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut33_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut33_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut33_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut33_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut33_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut33_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut33_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut33_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut33_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut33_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut33_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut33_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut33_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut33_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut33_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut33_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut33_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut33_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut33_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut33_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut33_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut33_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut33_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut33_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut33_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_33 = 0;
        double integral_Bkg_33 = 0;
        double integral_noVBFSM_33 = 0;

        double error_VBFSM_33 = 0;
        double error_Bkg_33 = 0;
        double error_noVBFSM_33 = 0;

        integral_VBFSM_33 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_33, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_33 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_33, "");

            integral_noVBFSM_33 += integral_Bkg_33;
            error_noVBFSM_33 += error_Bkg_33*error_Bkg_33;
        }

        error_noVBFSM_33 = sqrt(error_noVBFSM_33);

                double S_33 = 0;   S_33 = integral_VBFSM_33;
                double dS_33 = 0;  dS_33 = error_VBFSM_33;
                double B_33 = 0;   B_33 = integral_noVBFSM_33;
                double dB_33 = 0;  dB_33 = error_noVBFSM_33;

                double Significance_33 = 0;
                double R_33 = 0;
                double E_33 = 0;
                double EE_33 = 0;

                if( B_33 > 0 && S_33 > 0) {
                    
                      double LSB_33 = log(1 + S_33/B_33);
                      R_33 =  2 * ( (S_33+B_33) * LSB_33 - S_33 );
                      E_33 = LSB_33 * LSB_33 * dS_33 * dS_33 + (LSB_33 - S_33/B_33) * (LSB_33 - S_33/B_33) * dB_33 * dB_33;

                      Significance_33 = sqrt(R_33);
                      if(Significance_33 > 0) { EE_33 = sqrt(E_33) / Significance_33; }
                    
                }
           
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut33_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_33 << " E = " << EE_33 << endl;
        cout << "" << endl;
          
      }
      
     
    cout << " " << endl;
    cout << "  ===========================================================   METCent   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut36 = 7;
    TCut cut36_1[n_cut36] = { "METCent>-1.3", "METCent>-1.1", "METCent>-0.9", "METCent>-0.7", "METCent>-0.5", "METCent>-0.3", "METCent>-0.1" };
    string cut36_2[n_cut36] = { "METCent>-1.3", "METCent>-1.1", "METCent>-0.9", "METCent>-0.7", "METCent>-0.5", "METCent>-0.3", "METCent>-0.1" };
    

      TCanvas *canvas36[n_cut36] ;
      canvas36[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas36[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas36[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas36[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas36[4] = new TCanvas ("c4", "Mhh",980,580);
      canvas36[5] = new TCanvas ("c5", "Mhh",980,580);
      canvas36[6] = new TCanvas ("c6", "Mhh",980,580);
    
      TPad *pad361[n_cut36];
      pad361[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad361[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad361[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad361[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad361[4] = new TPad ("pad4", "", 0,0,0.75,1);
      pad361[5] = new TPad ("pad5", "", 0,0,0.75,1);
      pad361[6] = new TPad ("pad6", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut36;k++) {
           canvas36[k]->cd();
           pad361[k]->Draw();
           
           pad361[k]->cd();
           pad361[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut36_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut36_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut36_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut36_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut36_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut36_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut36_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut36_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut36_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut36_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut36_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut36_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut36_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut36_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut36_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut36_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut36_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut36_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut36_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut36_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut36_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut36_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut36_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut36_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut36_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut36_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut36_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut36_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut36_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut36_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut36_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut36_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut36_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut36_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut36_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut36_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut36_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut36_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut36_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_36 = 0;
        double integral_Bkg_36 = 0;
        double integral_noVBFSM_36 = 0;

        double error_VBFSM_36 = 0;
        double error_Bkg_36 = 0;
        double error_noVBFSM_36 = 0;

        integral_VBFSM_36 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_36, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_36 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_36, "");

            integral_noVBFSM_36 += integral_Bkg_36;
            error_noVBFSM_36 += error_Bkg_36*error_Bkg_36;
        }

        error_noVBFSM_36 = sqrt(error_noVBFSM_36);

                double S_36 = 0;   S_36 = integral_VBFSM_36;
                double dS_36 = 0;  dS_36 = error_VBFSM_36;
                double B_36 = 0;   B_36 = integral_noVBFSM_36;
                double dB_36 = 0;  dB_36 = error_noVBFSM_36;

                double Significance_36 = 0;
                double R_36 = 0;
                double E_36 = 0;
                double EE_36 = 0;

                if( B_36 > 0 && S_36 > 0) {
                    
                      double LSB_36 = log(1 + S_36/B_36);
                      R_36 =  2 * ( (S_36+B_36) * LSB_36 - S_36 );
                      E_36 = LSB_36 * LSB_36 * dS_36 * dS_36 + (LSB_36 - S_36/B_36) * (LSB_36 - S_36/B_36) * dB_36 * dB_36;

                      Significance_36 = sqrt(R_36);
                      if(Significance_36 > 0) { EE_36 = sqrt(E_36) / Significance_36; }
                    
                }
           

        
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut36_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_36 << " E = " << EE_36 << endl;
        cout << "" << endl;
          
      }
     
  
        
    cout << " " << endl;
    cout << "  ===========================================================   mMMC   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut37 = 4;
    TCut cut37_1[n_cut37] = { "mMMC<140000", "mMMC<160000", "mMMC<180000", "mMMC<200000" };
    string cut37_2[n_cut37] = { "mMMC<140GeV", "mMMC<160GeV", "mMMC<180GeV", "mMMC<200GeV" };
    

      TCanvas *canvas37[n_cut37] ;
      canvas37[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas37[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas37[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas37[3] = new TCanvas ("c3", "Mhh",980,580);
    
      TPad *pad371[n_cut37];
      pad371[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad371[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad371[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad371[3] = new TPad ("pad3", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut37;k++) {
           canvas37[k]->cd();
           pad371[k]->Draw();
           
           pad371[k]->cd();
           pad371[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut37_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut37_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut37_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut37_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut37_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut37_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut37_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut37_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut37_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut37_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut37_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut37_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut37_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut37_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut37_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut37_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut37_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut37_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut37_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut37_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut37_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut37_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut37_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut37_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut37_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut37_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut37_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut37_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut37_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut37_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut37_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut37_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut37_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut37_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut37_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut37_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut37_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut37_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut37_1[k]), "SAMEHIST");}
        }
    

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_37 = 0;
        double integral_Bkg_37 = 0;
        double integral_noVBFSM_37 = 0;

        double error_VBFSM_37 = 0;
        double error_Bkg_37 = 0;
        double error_noVBFSM_37 = 0;

        integral_VBFSM_37 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_37, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_37 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_37, "");

            integral_noVBFSM_37 += integral_Bkg_37;
            error_noVBFSM_37 += error_Bkg_37*error_Bkg_37;
        }

        error_noVBFSM_37 = sqrt(error_noVBFSM_37);

                double S_37 = 0;   S_37 = integral_VBFSM_37;
                double dS_37 = 0;  dS_37 = error_VBFSM_37;
                double B_37 = 0;   B_37 = integral_noVBFSM_37;
                double dB_37 = 0;  dB_37 = error_noVBFSM_37;

                double Significance_37 = 0;
                double R_37 = 0;
                double E_37 = 0;
                double EE_37 = 0;

                if( B_37 > 0 && S_37 > 0) {
                    
                      double LSB_37 = log(1 + S_37/B_37);
                      R_37 =  2 * ( (S_37+B_37) * LSB_37 - S_37 );
                      E_37 = LSB_37 * LSB_37 * dS_37 * dS_37 + (LSB_37 - S_37/B_37) * (LSB_37 - S_37/B_37) * dB_37 * dB_37;

                      Significance_37 = sqrt(R_37);
                      if(Significance_37 > 0) { EE_37 = sqrt(E_37) / Significance_37; }
                    
                }

        
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut37_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_37 << " E = " << EE_37 << endl;
        cout << "" << endl;
          
      }
  
      
    cout << " " << endl;
    cout << "  ===========================================================   MT2   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut39 = 3;
    TCut cut39_1[n_cut39] = { "MT2<260000", "MT2<280000", "MT2<300000" };
    string cut39_2[n_cut39] = { "MT2<260GeV", "MT2<280GeV", "MT2<300GeV" };
    

      TCanvas *canvas39[n_cut39] ;
      canvas39[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas39[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas39[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad391[n_cut39];
      pad391[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad391[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad391[2] = new TPad ("pad2", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut39;k++) {
           canvas39[k]->cd();
           pad391[k]->Draw();
           
           pad391[k]->cd();
           pad391[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut39_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut39_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut39_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut39_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut39_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut39_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut39_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut39_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut39_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut39_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut39_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut39_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut39_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut39_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut39_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut39_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut39_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut39_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut39_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut39_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut39_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut39_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut39_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut39_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut39_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut39_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut39_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut39_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut39_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut39_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut39_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut39_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut39_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut39_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut39_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut39_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut39_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut39_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut39_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_39 = 0;
        double integral_Bkg_39 = 0;
        double integral_noVBFSM_39 = 0;

        double error_VBFSM_39 = 0;
        double error_Bkg_39 = 0;
        double error_noVBFSM_39 = 0;

        integral_VBFSM_39 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_39, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_39 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_39, "");

            integral_noVBFSM_39 += integral_Bkg_39;
            error_noVBFSM_39 += error_Bkg_39*error_Bkg_39;
        }

        error_noVBFSM_39 = sqrt(error_noVBFSM_39);

                double S_39 = 0;   S_39 = integral_VBFSM_39;
                double dS_39 = 0;  dS_39 = error_VBFSM_39;
                double B_39 = 0;   B_39 = integral_noVBFSM_39;
                double dB_39 = 0;  dB_39 = error_noVBFSM_39;

                double Significance_39 = 0;
                double R_39 = 0;
                double E_39 = 0;
                double EE_39 = 0;

                if( B_39 > 0 && S_39 > 0) {
                    
                      double LSB_39 = log(1 + S_39/B_39);
                      R_39 =  2 * ( (S_39+B_39) * LSB_39 - S_39 );
                      E_39 = LSB_39 * LSB_39 * dS_39 * dS_39 + (LSB_39 - S_39/B_39) * (LSB_39 - S_39/B_39) * dB_39 * dB_39;

                      Significance_39 = sqrt(R_39);
                      if(Significance_39 > 0) { EE_39 = sqrt(E_39) / Significance_39; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut39_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_39 << " E = " << EE_39 << endl;
        cout << "" << endl;
          
      }
      
              
    cout << " " << endl;
    cout << "  ===========================================================   mTW   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut40 = 3;
    TCut cut40_1[n_cut40] = { "mTW<60000", "mTW<80000", "mTW<100000" };
    string cut40_2[n_cut40] = { "mTW<60GeV", "mTW<80GeV", "mTW<100GeV" };
    

      TCanvas *canvas40[n_cut40] ;
      canvas40[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas40[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas40[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad401[n_cut40];
      pad401[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad401[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad401[2] = new TPad ("pad2", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut40;k++) {
           canvas40[k]->cd();
           pad401[k]->Draw();
           
           pad401[k]->cd();
           pad401[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut40_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut40_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut40_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut40_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut40_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut40_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut40_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut40_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut40_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut40_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut40_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut40_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut40_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut40_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut40_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut40_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut40_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut40_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut40_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut40_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut40_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut40_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut40_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut40_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut40_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut40_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut40_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut40_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut40_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut40_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut40_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut40_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut40_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut40_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut40_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut40_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut40_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut40_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut40_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_40 = 0;
        double integral_Bkg_40 = 0;
        double integral_noVBFSM_40 = 0;

        double error_VBFSM_40 = 0;
        double error_Bkg_40 = 0;
        double error_noVBFSM_40 = 0;

        integral_VBFSM_40 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_40, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_40 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_40, "");

            integral_noVBFSM_40 += integral_Bkg_40;
            error_noVBFSM_40 += error_Bkg_40*error_Bkg_40;
        }

        error_noVBFSM_40 = sqrt(error_noVBFSM_40);

                double S_40 = 0;   S_40 = integral_VBFSM_40;
                double dS_40 = 0;  dS_40 = error_VBFSM_40;
                double B_40 = 0;   B_40 = integral_noVBFSM_40;
                double dB_40 = 0;  dB_40 = error_noVBFSM_40;

                double Significance_40 = 0;
                double R_40 = 0;
                double E_40 = 0;
                double EE_40 = 0;

                if( B_40 > 0 && S_40 > 0) {
                    
                      double LSB_40 = log(1 + S_40/B_40);
                      R_40 =  2 * ( (S_40+B_40) * LSB_40 - S_40 );
                      E_40 = LSB_40 * LSB_40 * dS_40 * dS_40 + (LSB_40 - S_40/B_40) * (LSB_40 - S_40/B_40) * dB_40 * dB_40;

                      Significance_40 = sqrt(R_40);
                      if(Significance_40 > 0) { EE_40 = sqrt(E_40) / Significance_40; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut40_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_40 << " E = " << EE_40 << endl;
        cout << "" << endl;
          
      }
       
         /*
    cout << " " << endl;
    cout << "  ===========================================================   mjjVBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut41 = 10;
    TCut cut41_1[n_cut41] = { "mjjVBF>50000", "mjjVBF>100000", "mjjVBF>150000", "mjjVBF>200000", "mjjVBF>250000", "mjjVBF>300000", "mjjVBF>350000", "mjjVBF>400000", "mjjVBF>450000", "mjjVBF>500000" };
    string cut41_2[n_cut41] = { "mjjVBF>50GeV", "mjjVBF>100GeV", "mjjVBF>150GeV", "mjjVBF>200GeV", "mjjVBF>250GeV", "mjjVBF>300GeV", "mjjVBF>350GeV", "mjjVBF>400GeV", "mjjVBF>450GeV", "mjjVBF>500GeV" };
    

      TCanvas *canvas41[n_cut41] ;
      canvas41[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas41[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas41[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas41[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas41[4] = new TCanvas ("c4", "Mhh",980,580);
      canvas41[5] = new TCanvas ("c5", "Mhh",980,580);
      canvas41[6] = new TCanvas ("c6", "Mhh",980,580);
      canvas41[7] = new TCanvas ("c7", "Mhh",980,580);
      canvas41[8] = new TCanvas ("c8", "Mhh",980,580);
      canvas41[9] = new TCanvas ("c9", "Mhh",980,580);
    
      TPad *pad411[n_cut41];
      pad411[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad411[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad411[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad411[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad411[4] = new TPad ("pad4", "", 0,0,0.75,1);
      pad411[5] = new TPad ("pad5", "", 0,0,0.75,1);
      pad411[6] = new TPad ("pad6", "", 0,0,0.75,1);
      pad411[7] = new TPad ("pad7", "", 0,0,0.75,1);
      pad411[8] = new TPad ("pad8", "", 0,0,0.75,1);
      pad411[9] = new TPad ("pad9", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut41;k++) {
           canvas41[k]->cd();
           pad411[k]->Draw();
           
           pad411[k]->cd();
           pad411[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
         
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut41_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut41_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut41_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut41_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut41_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut41_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut41_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut41_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut41_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut41_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut41_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut41_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut41_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut41_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut41_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut41_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut41_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut41_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut41_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut41_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut41_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut41_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut41_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut41_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut41_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut41_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut41_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut41_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut41_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut41_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut41_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut41_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut41_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut41_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut41_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut41_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut41_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut41_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut41_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_41 = 0;
        double integral_Bkg_41 = 0;
        double integral_noVBFSM_41 = 0;

        double error_VBFSM_41 = 0;
        double error_Bkg_41 = 0;
        double error_noVBFSM_41 = 0;

        integral_VBFSM_41 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_41, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_41 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_41, "");

            integral_noVBFSM_41 += integral_Bkg_41;
            error_noVBFSM_41 += error_Bkg_41*error_Bkg_41;
        }

        error_noVBFSM_41= sqrt(error_noVBFSM_41);

                double S_41 = 0;   S_41 = integral_VBFSM_41;
                double dS_41 = 0;  dS_41 = error_VBFSM_41;
                double B_41 = 0;   B_41 = integral_noVBFSM_41;
                double dB_41 = 0;  dB_41 = error_noVBFSM_41;

                double Significance_41 = 0;
                double R_41 = 0;
                double E_41 = 0;
                double EE_41 = 0;

                if( B_41 > 0 && S_41 > 0) {
                    
                      double LSB_41 = log(1 + S_41/B_41);
                      R_41 =  2 * ( (S_41+B_41) * LSB_41 - S_41 );
                      E_41 = LSB_41 * LSB_41 * dS_41 * dS_41 + (LSB_41 - S_41/B_41) * (LSB_41 - S_41/B_41) * dB_41 * dB_41;

                      Significance_41 = sqrt(R_41);
                      if(Significance_41 > 0) { EE_41 = sqrt(E_41) / Significance_41; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut41_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_41 << " E = " << EE_41 << endl;
        cout << "" << endl;
          
      }
            */
   
    cout << " " << endl;
    cout << "  ===========================================================   dRb0tau   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut42 = 4;
    TCut cut42_1[n_cut42] = { "dRb0tau>1", "dRb0tau>1.2", "dRb0tau>1.4", "dRb0tau>1.6" };
    string cut42_2[n_cut42] = { "dRb0tau>1", "dRb0tau>1.2", "dRb0tau>1.4", "dRb0tau>1.6" };
    

      TCanvas *canvas42[n_cut42] ;
      canvas42[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas42[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas42[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas42[3] = new TCanvas ("c3", "Mhh",980,580);
    
      TPad *pad421[n_cut42];
      pad421[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad421[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad421[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad421[3] = new TPad ("pad3", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut42;k++) {
           canvas42[k]->cd();
           pad421[k]->Draw();
           
           pad421[k]->cd();
           pad421[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut42_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut42_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut42_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut42_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut42_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut42_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut42_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut42_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut42_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut42_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut42_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut42_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut42_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut42_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut42_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut42_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut42_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut42_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut42_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut42_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut42_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut42_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut42_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut42_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut42_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut42_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut42_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut42_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut42_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut42_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut42_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut42_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut42_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut42_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut42_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut42_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut42_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut42_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut42_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_42 = 0;
        double integral_Bkg_42 = 0;
        double integral_noVBFSM_42 = 0;

        double error_VBFSM_42 = 0;
        double error_Bkg_42 = 0;
        double error_noVBFSM_42 = 0;

        integral_VBFSM_42 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_42, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_42 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_42, "");

            integral_noVBFSM_42 += integral_Bkg_42;
            error_noVBFSM_42 += error_Bkg_42*error_Bkg_42;
        }

        error_noVBFSM_42 = sqrt(error_noVBFSM_42);

                double S_42 = 0;   S_42 = integral_VBFSM_42;
                double dS_42 = 0;  dS_42 = error_VBFSM_42;
                double B_42 = 0;   B_42 = integral_noVBFSM_42;
                double dB_42 = 0;  dB_42 = error_noVBFSM_42;

                double Significance_42 = 0;
                double R_42 = 0;
                double E_42 = 0;
                double EE_42 = 0;

                if( B_42 > 0 && S_42 > 0) {
                    
                      double LSB_42 = log(1 + S_42/B_42);
                      R_42 =  2 * ( (S_42+B_42) * LSB_42 - S_42 );
                      E_42 = LSB_42 * LSB_42 * dS_42 * dS_42 + (LSB_42 - S_42/B_42) * (LSB_42 - S_42/B_42) * dB_42 * dB_42;

                      Significance_42 = sqrt(R_42);
                      if(Significance_42 > 0) { EE_42 = sqrt(E_42) / Significance_42; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut42_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_42 << " E = " << EE_42 << endl;
        cout << "" << endl;
          
      }
          
    
    cout << " " << endl;
    cout << "  ===========================================================   dRb1tau   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut43 = 3;
    TCut cut43_1[n_cut43] = { "dRb1tau>1", "dRb1tau>1.2", "dRb1tau>1.4" };
    string cut43_2[n_cut43] = { "dRb1tau>1", "dRb1tau>1.2", "dRb1tau>1.4" };
    

      TCanvas *canvas43[n_cut43] ;
      canvas43[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas43[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas43[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad431[n_cut43];
      pad431[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad431[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad431[2] = new TPad ("pad2", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut43;k++) {
           canvas43[k]->cd();
           pad431[k]->Draw();
           
           pad431[k]->cd();
           pad431[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut43_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut43_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut43_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut43_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut43_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut43_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut43_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut43_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut43_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut43_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut43_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut43_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut43_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut43_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut43_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut43_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut43_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut43_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut43_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut43_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut43_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut43_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut43_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut43_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut43_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut43_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut43_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut43_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut43_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut43_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut43_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut43_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut43_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut43_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut43_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut43_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut43_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut43_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut43_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_43 = 0;
        double integral_Bkg_43 = 0;
        double integral_noVBFSM_43 = 0;

        double error_VBFSM_43 = 0;
        double error_Bkg_43 = 0;
        double error_noVBFSM_43 = 0;

        integral_VBFSM_43 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_43, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_43 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_43, "");

            integral_noVBFSM_43 += integral_Bkg_43;
            error_noVBFSM_43 += error_Bkg_43*error_Bkg_43;
        }

        error_noVBFSM_43 = sqrt(error_noVBFSM_43);

                double S_43 = 0;   S_43 = integral_VBFSM_43;
                double dS_43 = 0;  dS_43 = error_VBFSM_43;
                double B_43 = 0;   B_43 = integral_noVBFSM_43;
                double dB_43 = 0;  dB_43 = error_noVBFSM_43;

                double Significance_43 = 0;
                double R_43 = 0;
                double E_43 = 0;
                double EE_43 = 0;

                if( B_43 > 0 && S_43 > 0) {
                    
                      double LSB_43 = log(1 + S_43/B_43);
                      R_43 =  2 * ( (S_43+B_43) * LSB_43 - S_43 );
                      E_43 = LSB_43 * LSB_43 * dS_43 * dS_43 + (LSB_43 - S_43/B_43) * (LSB_43 - S_43/B_43) * dB_43 * dB_43;

                      Significance_43 = sqrt(R_43);
                      if(Significance_43 > 0) { EE_43 = sqrt(E_43) / Significance_43; }
                    
                }
           
        
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut43_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_43 << " E = " << EE_43 << endl;
        cout << "" << endl;
          
      }
    
     
      
    cout << " " << endl;
    cout << "  ===========================================================   dRb0lep   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut48 = 6;
    TCut cut48_1[n_cut48] = { "dRb0lep>1", "dRb0lep>1.2", "dRb0lep>1.4", "dRb0lep>1.6", "dRb0lep>1.8", "dRb0lep>2" };
    string cut48_2[n_cut48] = { "dRb0lep>1", "dRb0lep>1.2", "dRb0lep>1.4", "dRb0lep>1.6", "dRb0lep>1.8", "dRb0lep>2" };
    

      TCanvas *canvas48[n_cut48] ;
      canvas48[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas48[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas48[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas48[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas48[4] = new TCanvas ("c4", "Mhh",980,580);
      canvas48[5] = new TCanvas ("c5", "Mhh",980,580);
    
      TPad *pad481[n_cut48];
      pad481[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad481[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad481[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad481[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad481[4] = new TPad ("pad4", "", 0,0,0.75,1);
      pad481[5] = new TPad ("pad5", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut48;k++) {
           canvas48[k]->cd();
           pad481[k]->Draw();
           
           pad481[k]->cd();
           pad481[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut48_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut48_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut48_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut48_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut48_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut48_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut48_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut48_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut48_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut48_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut48_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut48_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut48_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut48_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut48_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut48_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut48_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut48_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut48_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut48_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut48_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut48_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut48_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut48_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut48_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut48_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut48_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut48_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut48_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut48_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut48_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut48_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut48_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut48_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut48_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut48_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut48_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut48_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut48_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_48 = 0;
        double integral_Bkg_48 = 0;
        double integral_noVBFSM_48 = 0;

        double error_VBFSM_48 = 0;
        double error_Bkg_48 = 0;
        double error_noVBFSM_48 = 0;

        integral_VBFSM_48 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_48, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_48 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_48, "");

            integral_noVBFSM_48 += integral_Bkg_48;
            error_noVBFSM_48 += error_Bkg_48*error_Bkg_48;
        }

        error_noVBFSM_48 = sqrt(error_noVBFSM_48);

                double S_48 = 0;   S_48 = integral_VBFSM_48;
                double dS_48 = 0;  dS_48 = error_VBFSM_48;
                double B_48 = 0;   B_48 = integral_noVBFSM_48;
                double dB_48 = 0;  dB_48 = error_noVBFSM_48;

                double Significance_48 = 0;
                double R_48 = 0;
                double E_48 = 0;
                double EE_48 = 0;

                if( B_48 > 0 && S_48 > 0) {
                    
                      double LSB_48 = log(1 + S_48/B_48);
                      R_48 =  2 * ( (S_48+B_48) * LSB_48 - S_48 );
                      E_48 = LSB_48 * LSB_48 * dS_48 * dS_48 + (LSB_48 - S_48/B_48) * (LSB_48 - S_48/B_48) * dB_48 * dB_48;

                      Significance_48 = sqrt(R_48);
                      if(Significance_48 > 0) { EE_48 = sqrt(E_48) / Significance_48; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut48_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_48 << " E = " << EE_48 << endl;
        cout << "" << endl;
          
      }
     
     
    cout << " " << endl;
    cout << "  ===========================================================   dRb1lep   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut49 = 4;
    TCut cut49_1[n_cut49] = { "dRb1lep>1", "dRb1lep>1.2", "dRb1lep>1.4", "dRb1lep>1.6" };
    string cut49_2[n_cut49] = { "dRb1lep>1", "dRb1lep>1.2", "dRb1lep>1.4", "dRb1lep>1.6" };
    

      TCanvas *canvas49[n_cut49] ;
      canvas49[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas49[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas49[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas49[3] = new TCanvas ("c3", "Mhh",980,580);
    
      TPad *pad491[n_cut49];
      pad491[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad491[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad491[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad491[3] = new TPad ("pad3", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut49;k++) {
           canvas49[k]->cd();
           pad491[k]->Draw();
           
           pad491[k]->cd();
           pad491[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut49_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut49_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut49_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut49_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut49_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut49_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut49_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut49_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut49_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut49_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut49_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut49_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut49_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut49_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut49_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut49_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut49_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut49_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut49_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut49_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut49_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut49_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut49_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut49_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut49_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut49_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut49_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut49_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut49_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut49_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut49_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut49_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut49_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut49_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut49_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut49_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut49_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut49_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut49_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_49 = 0;
        double integral_Bkg_49 = 0;
        double integral_noVBFSM_49 = 0;

        double error_VBFSM_49 = 0;
        double error_Bkg_49 = 0;
        double error_noVBFSM_49 = 0;

        integral_VBFSM_49 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_49, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_49 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_49, "");

            integral_noVBFSM_49 += integral_Bkg_49;
            error_noVBFSM_49 += error_Bkg_49*error_Bkg_49;
        }

        error_noVBFSM_49 = sqrt(error_noVBFSM_49);

                double S_49 = 0;   S_49 = integral_VBFSM_49;
                double dS_49 = 0;  dS_49 = error_VBFSM_49;
                double B_49 = 0;   B_49 = integral_noVBFSM_49;
                double dB_49 = 0;  dB_49 = error_noVBFSM_49;

                double Significance_49 = 0;
                double R_49 = 0;
                double E_49 = 0;
                double EE_49 = 0;

                if( B_49 > 0 && S_49 > 0) {
                    
                      double LSB_49 = log(1 + S_49/B_49);
                      R_49 =  2 * ( (S_49+B_49) * LSB_49 - S_49 );
                      E_49 = LSB_49 * LSB_49 * dS_49 * dS_49 + (LSB_49 - S_49/B_49) * (LSB_49 - S_49/B_49) * dB_49 * dB_49;

                      Significance_49 = sqrt(R_49);
                      if(Significance_49 > 0) { EE_49 = sqrt(E_49) / Significance_49; }
                    
                }
        
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut49_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_49 << " E = " << EE_49 << endl;
        cout << "" << endl;
          
      }
     
       
    cout << " " << endl;
    cout << "  ===========================================================   pTBB   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut50 = 3;
    TCut cut50_1[n_cut50] = { "pTBB>20000", "pTBB>40000", "pTBB>60000" };
    string cut50_2[n_cut50] = { "pTBB>20GeV", "pTBB>40GeV", "pTBB>60GeV" };
    

      TCanvas *canvas50[n_cut50] ;
      canvas50[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas50[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas50[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad501[n_cut50];
      pad501[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad501[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad501[2] = new TPad ("pad2", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut50;k++) {
           canvas50[k]->cd();
           pad501[k]->Draw();
           
           pad501[k]->cd();
           pad501[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut50_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut50_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut50_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut50_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut50_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut50_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut50_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut50_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut50_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut50_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut50_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut50_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut50_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut50_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut50_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut50_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut50_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut50_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut50_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut50_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut50_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut50_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut50_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut50_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut50_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut50_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut50_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut50_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut50_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut50_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut50_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut50_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut50_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut50_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut50_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut50_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut50_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut50_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut50_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_50 = 0;
        double integral_Bkg_50 = 0;
        double integral_noVBFSM_50 = 0;

        double error_VBFSM_50 = 0;
        double error_Bkg_50 = 0;
        double error_noVBFSM_50 = 0;

        integral_VBFSM_50 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_50, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_50 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_50, "");

            integral_noVBFSM_50 += integral_Bkg_50;
            error_noVBFSM_50 += error_Bkg_50*error_Bkg_50;
        }

        error_noVBFSM_50 = sqrt(error_noVBFSM_50);

                double S_50 = 0;   S_50 = integral_VBFSM_50;
                double dS_50 = 0;  dS_50 = error_VBFSM_50;
                double B_50 = 0;   B_50 = integral_noVBFSM_50;
                double dB_50 = 0;  dB_50 = error_noVBFSM_50;

                double Significance_50 = 0;
                double R_50 = 0;
                double E_50 = 0;
                double EE_50 = 0;

                if( B_50 > 0 && S_50 > 0) {
                    
                      double LSB_50 = log(1 + S_50/B_50);
                      R_50 =  2 * ( (S_50+B_50) * LSB_50 - S_50 );
                      E_50 = LSB_50 * LSB_50 * dS_50 * dS_50 + (LSB_50 - S_50/B_50) * (LSB_50 - S_50/B_50) * dB_50 * dB_50;

                      Significance_50 = sqrt(R_50);
                      if(Significance_50 > 0) { EE_50 = sqrt(E_50) / Significance_50; }
                    
                }

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut50_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_50 << " E = " << EE_50 << endl;
        cout << "" << endl;
          
      }
     
    
     
    cout << " " << endl;
    cout << "  ===========================================================   pTTauTau   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut52 = 4;
    TCut cut52_1[n_cut52] = { "pTTauTau>10000", "pTTauTau>20000", "pTTauTau>30000", "pTTauTau>40000" };
    string cut52_2[n_cut52] = { "pTTauTau>10GeV", "pTTauTau>20GeV", "pTTauTau>30GeV", "pTTauTau>40GeV" };
    

      TCanvas *canvas52[n_cut52] ;
      canvas52[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas52[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas52[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas52[3] = new TCanvas ("c3", "Mhh",980,580);
    
      TPad *pad521[n_cut52];
      pad521[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad521[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad521[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad521[3] = new TPad ("pad3", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
          h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut52;k++) {
           canvas52[k]->cd();
           pad521[k]->Draw();
           
           pad521[k]->cd();
           pad521[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut52_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut52_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut52_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut52_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut52_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut52_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut52_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut52_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut52_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut52_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut52_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut52_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut52_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut52_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut52_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut52_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut52_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut52_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut52_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut52_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut52_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut52_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut52_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut52_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut52_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut52_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut52_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut52_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut52_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut52_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut52_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut52_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut52_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut52_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut52_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut52_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut52_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut52_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut52_1[k]), "SAMEHIST");}
        }
          
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_52 = 0;
        double integral_Bkg_52 = 0;
        double integral_noVBFSM_52 = 0;

        double error_VBFSM_52 = 0;
        double error_Bkg_52 = 0;
        double error_noVBFSM_52 = 0;

        integral_VBFSM_52 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_52, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_52 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_52, "");

            integral_noVBFSM_52 += integral_Bkg_52;
            error_noVBFSM_52 += error_Bkg_52*error_Bkg_52;
        }

        error_noVBFSM_52= sqrt(error_noVBFSM_52);

                double S_52 = 0;   S_52 = integral_VBFSM_52;
                double dS_52 = 0;  dS_52 = error_VBFSM_52;
                double B_52 = 0;   B_52 = integral_noVBFSM_52;
                double dB_52 = 0;  dB_52 = error_noVBFSM_52;

                double Significance_52 = 0;
                double R_52 = 0;
                double E_52 = 0;
                double EE_52 = 0;

                if( B_52 > 0 && S_52 > 0) {
                    
                      double LSB_52 = log(1 + S_52/B_52);
                      R_52 =  2 * ( (S_52+B_52) * LSB_52 - S_52 );
                      E_52 = LSB_52 * LSB_52 * dS_52 * dS_52 + (LSB_52 - S_52/B_52) * (LSB_52 - S_52/B_52) * dB_52 * dB_52;

                      Significance_52 = sqrt(R_52);
                      if(Significance_52 > 0) { EE_52 = sqrt(E_52) / Significance_52; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut52_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_52 << " E = " << EE_52 << endl;
        cout << "" << endl;
          
      }
    
        
    cout << " " << endl;
    cout << "  ===========================================================   pTj1VBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut53 = 2;
    TCut cut53_1[n_cut53] = { "pTj1VBF>40000", "pTj1VBF>60000" };
    string cut53_2[n_cut53] = { "pTj1VBF>40GeV", "pTj1VBF>60GeV" };
    

      TCanvas *canvas53[n_cut53] ;
      canvas53[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas53[1] = new TCanvas ("c1", "Mhh",980,580);
    
      TPad *pad531[n_cut53];
      pad531[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad531[1] = new TPad ("pad1", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut53;k++) {
           canvas53[k]->cd();
           pad531[k]->Draw();
           
           pad531[k]->cd();
           pad531[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
        
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut53_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut53_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut53_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut53_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut53_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut53_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut53_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut53_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut53_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut53_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut53_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut53_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut53_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut53_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut53_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut53_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut53_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut53_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut53_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut53_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut53_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut53_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut53_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut53_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut53_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut53_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut53_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut53_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut53_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut53_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut53_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut53_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut53_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut53_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut53_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut53_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut53_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut53_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut53_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_53 = 0;
        double integral_Bkg_53 = 0;
        double integral_noVBFSM_53 = 0;

        double error_VBFSM_53 = 0;
        double error_Bkg_53 = 0;
        double error_noVBFSM_53 = 0;

        integral_VBFSM_53 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_53, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_53 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_53, "");

            integral_noVBFSM_53 += integral_Bkg_53;
            error_noVBFSM_53 += error_Bkg_53*error_Bkg_53;
        }

        error_noVBFSM_53 = sqrt(error_noVBFSM_53);

                double S_53 = 0;   S_53 = integral_VBFSM_53;
                double dS_53 = 0;  dS_53 = error_VBFSM_53;
                double B_53 = 0;   B_53 = integral_noVBFSM_53;
                double dB_53 = 0;  dB_53 = error_noVBFSM_53;

                double Significance_53 = 0;
                double R_53 = 0;
                double E_53 = 0;
                double EE_53 = 0;

                if( B_53 > 0 && S_53 > 0) {
                    
                      double LSB_53 = log(1 + S_53/B_53);
                      R_53 =  2 * ( (S_53+B_53) * LSB_53 - S_53 );
                      E_53 = LSB_53 * LSB_53 * dS_53 * dS_53 + (LSB_53 - S_53/B_53) * (LSB_53 - S_53/B_53) * dB_53 * dB_53;

                      Significance_53 = sqrt(R_53);
                      if(Significance_53 > 0) { EE_53 = sqrt(E_53) / Significance_53; }
                    
                }

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut53_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_53 << " E = " << EE_53 << endl;
        cout << "" << endl;
          
      }
      
     
    cout << " " << endl;
    cout << "  ===========================================================   pTj2VBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut54 = 3;
    TCut cut54_1[n_cut54] = { "pTj2VBF>20000", "pTj2VBF>30000", "pTj2VBF>40000" };
    string cut54_2[n_cut54] = { "pTj2VBF>20GeV", "pTj2VBF>30GeV", "pTj2VBF>40GeV" };
    

      TCanvas *canvas54[n_cut54] ;
      canvas54[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas54[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas54[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad541[n_cut54];
      pad541[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad541[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad541[2] = new TPad ("pad2", "", 0,0,0.75,1);
      
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut54;k++) {
           canvas54[k]->cd();
           pad541[k]->Draw();
           
           pad541[k]->cd();
           pad541[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);
      
        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut54_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut54_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut54_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut54_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut54_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut54_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut54_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut54_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut54_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut54_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut54_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut54_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut54_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut54_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut54_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut54_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut54_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut54_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut54_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut54_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut54_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut54_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut54_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut54_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut54_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut54_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut54_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut54_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut54_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut54_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut54_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut54_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut54_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut54_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut54_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut54_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut54_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut54_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut54_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_54 = 0;
        double integral_Bkg_54 = 0;
        double integral_noVBFSM_54 = 0;

        double error_VBFSM_54 = 0;
        double error_Bkg_54 = 0;
        double error_noVBFSM_54 = 0;

        integral_VBFSM_54 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_54, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_54 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_54, "");

            integral_noVBFSM_54 += integral_Bkg_54;
            error_noVBFSM_54 += error_Bkg_54*error_Bkg_54;
        }

        error_noVBFSM_54 = sqrt(error_noVBFSM_54);

                double S_54 = 0;   S_54 = integral_VBFSM_54;
                double dS_54 = 0;  dS_54 = error_VBFSM_54;
                double B_54 = 0;   B_54 = integral_noVBFSM_54;
                double dB_54 = 0;  dB_54 = error_noVBFSM_54;

                double Significance_54 = 0;
                double R_54 = 0;
                double E_54 = 0;
                double EE_54 = 0;

                if( B_54 > 0 && S_54 > 0) {
                    
                      double LSB_54 = log(1 + S_54/B_54);
                      R_54 =  2 * ( (S_54+B_54) * LSB_54 - S_54 );
                      E_54 = LSB_54 * LSB_54 * dS_54 * dS_54 + (LSB_54 - S_54/B_54) * (LSB_54 - S_54/B_54) * dB_54 * dB_54;

                      Significance_54 = sqrt(R_54);
                      if(Significance_54 > 0) { EE_54 = sqrt(E_54) / Significance_54; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut54_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_54 << " E = " << EE_54 << endl;
        cout << "" << endl;
          
      }
       
        
          
    cout << " " << endl;
    cout << "  ===========================================================   tau_rnn   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut21 = 3;
    TCut cut21_1[n_cut21] = { "tau_rnn>0.18", "tau_rnn>0.22", "tau_rnn>0.26" };
    string cut21_2[n_cut21] = { "tau_rnn>0.18", "tau_rnn>0.22", "tau_rnn>0.26" };
    

      TCanvas *canvas21[n_cut21] ;
      canvas21[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas21[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas21[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad211[n_cut21];
      pad211[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad211[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad211[2] = new TPad ("pad2", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut21;k++) {
           canvas21[k]->cd();
           pad211[k]->Draw();
           
           pad211[k]->cd();
           pad211[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut21_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut21_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut21_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut21_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut21_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut21_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut21_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut21_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut21_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut21_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut21_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut21_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut21_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut21_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut21_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut21_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut21_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut21_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut21_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut21_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut21_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut21_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut21_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut21_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut21_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut21_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut21_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut21_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut21_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut21_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut21_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut21_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut21_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut21_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut21_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut21_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut21_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut21_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut21_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_21 = 0;
        double integral_Bkg_21 = 0;
        double integral_noVBFSM_21 = 0;

        double error_VBFSM_21 = 0;
        double error_Bkg_21 = 0;
        double error_noVBFSM_21 = 0;

        integral_VBFSM_21 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_21, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_21 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_21, "");

            integral_noVBFSM_21 += integral_Bkg_21;
            error_noVBFSM_21 += error_Bkg_21*error_Bkg_21;
        }

        error_noVBFSM_21 = sqrt(error_noVBFSM_21);

                double S_21 = 0;   S_21 = integral_VBFSM_21;
                double dS_21 = 0;  dS_21 = error_VBFSM_21;
                double B_21 = 0;   B_21 = integral_noVBFSM_21;
                double dB_21 = 0;  dB_21 = error_noVBFSM_21;

                double Significance_21 = 0;
                double R_21 = 0;
                double E_21 = 0;
                double EE_21 = 0;

                if( B_21 > 0 && S_21 > 0) {
                    
                      double LSB_21 = log(1 + S_21/B_21);
                      R_21 =  2 * ( (S_21+B_21) * LSB_21 - S_21 );
                      E_21 = LSB_21 * LSB_21 * dS_21 * dS_21 + (LSB_21 - S_21/B_21) * (LSB_21 - S_21/B_21) * dB_21 * dB_21;

                      Significance_21 = sqrt(R_21);
                      if(Significance_21 > 0) { EE_21 = sqrt(E_21) / Significance_21; }
                    
                }

        
        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut21_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_21 << " E = " << EE_21 << endl;
        cout << "" << endl;
          
      }
       
      
   
    cout << " " << endl;
    cout << "  ===========================================================   LeadBjet   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut27 = 2;
    TCut cut27_1[n_cut27] = { "LeadBjet*0.001>60", "LeadBjet*0.001>70" };
    string cut27_2[n_cut27] = { "LeadBjet*0.001>60GeV", "LeadBjet*0.001>70GeV" };
    

      TCanvas *canvas27[n_cut27] ;
      canvas27[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas27[1] = new TCanvas ("c1", "Mhh",980,580);
    
      TPad *pad271[n_cut27];
      pad271[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad271[1] = new TPad ("pad1", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut27;k++) {
           canvas27[k]->cd();
           pad271[k]->Draw();
           
           pad271[k]->cd();
           pad271[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut27_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut27_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut27_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut27_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut27_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut27_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut27_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut27_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut27_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut27_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut27_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut27_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut27_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut27_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut27_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut27_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut27_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut27_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut27_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut27_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut27_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut27_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut27_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut27_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut27_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut27_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut27_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut27_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut27_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut27_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut27_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut27_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut27_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut27_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut27_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut27_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut27_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut27_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut27_1[k]), "SAMEHIST");}
        }
        
       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_27 = 0;
        double integral_Bkg_27 = 0;
        double integral_noVBFSM_27 = 0;

        double error_VBFSM_27 = 0;
        double error_Bkg_27 = 0;
        double error_noVBFSM_27 = 0;

        integral_VBFSM_27 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_27, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_27 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_27, "");

            integral_noVBFSM_27 += integral_Bkg_27;
            error_noVBFSM_27 += error_Bkg_27*error_Bkg_27;
        }

        error_noVBFSM_27 = sqrt(error_noVBFSM_27);

                double S_27 = 0;   S_27 = integral_VBFSM_27;
                double dS_27 = 0;  dS_27 = error_VBFSM_27;
                double B_27 = 0;   B_27 = integral_noVBFSM_27;
                double dB_27 = 0;  dB_27 = error_noVBFSM_27;

                double Significance_27 = 0;
                double R_27 = 0;
                double E_27 = 0;
                double EE_27 = 0;

                if( B_27 > 0 && S_27 > 0) {
                    
                      double LSB_27 = log(1 + S_27/B_27);
                      R_27 =  2 * ( (S_27+B_27) * LSB_27 - S_27 );
                      E_27 = LSB_27 * LSB_27 * dS_27 * dS_27 + (LSB_27 - S_27/B_27) * (LSB_27 - S_27/B_27) * dB_27 * dB_27;

                      Significance_27 = sqrt(R_27);
                      if(Significance_27 > 0) { EE_27 = sqrt(E_27) / Significance_27; }
                    
                }

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut27_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_27 << " E = " << EE_27 << endl;
        cout << "" << endl;
          
      }
    

    cout << " " << endl;
    cout << "  ===========================================================   LeadJetPt   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut38 = 2;
    TCut cut38_1[n_cut38] = { "LeadJetPt*0.001>50", "LeadJetPt*0.001>60" };
    string cut38_2[n_cut38] = { "LeadJetPt>50GeV", "LeadJetPt>60GeV" };
    

      TCanvas *canvas38[n_cut38] ;
      canvas38[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas38[1] = new TCanvas ("c1", "Mhh",980,580);
    
      TPad *pad381[n_cut38];
      pad381[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad381[1] = new TPad ("pad1", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut38;k++) {
           canvas38[k]->cd();
           pad381[k]->Draw();
           
           pad381[k]->cd();
           pad381[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut38_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut38_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut38_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut38_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut38_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut38_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut38_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut38_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut38_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut38_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut38_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut38_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut38_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut38_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut38_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut38_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut38_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut38_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut38_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut38_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut38_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut38_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut38_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut38_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut38_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut38_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut38_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut38_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut38_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut38_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut38_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut38_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut38_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut38_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut38_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut38_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut38_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut38_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut38_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_38 = 0;
        double integral_Bkg_38 = 0;
        double integral_noVBFSM_38 = 0;

        double error_VBFSM_38 = 0;
        double error_Bkg_38 = 0;
        double error_noVBFSM_38 = 0;

        integral_VBFSM_38 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_38, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_38 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_38, "");

            integral_noVBFSM_38 += integral_Bkg_38;
            error_noVBFSM_38 += error_Bkg_38*error_Bkg_38;
        }

        error_noVBFSM_38 = sqrt(error_noVBFSM_38);

                double S_38 = 0;   S_38 = integral_VBFSM_38;
                double dS_38 = 0;  dS_38 = error_VBFSM_38;
                double B_38 = 0;   B_38 = integral_noVBFSM_38;
                double dB_38 = 0;  dB_38 = error_noVBFSM_38;

                double Significance_38 = 0;
                double R_38 = 0;
                double E_38 = 0;
                double EE_38 = 0;

                if( B_38 > 0 && S_38 > 0) {
                    
                      double LSB_38 = log(1 + S_38/B_38);
                      R_38 =  2 * ( (S_38+B_38) * LSB_38 - S_38 );
                      E_38 = LSB_38 * LSB_38 * dS_38 * dS_38 + (LSB_38 - S_38/B_38) * (LSB_38 - S_38/B_38) * dB_38 * dB_38;

                      Significance_38 = sqrt(R_38);
                      if(Significance_38 > 0) { EE_38 = sqrt(E_38) / Significance_38; }
                    
                }

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut38_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_38 << " E = " << EE_38 << endl;
        cout << "" << endl;
          
      }
       

  
    cout << " " << endl;
    cout << "  ===========================================================   pTSixObjVBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut66 = 5;
    TCut cut66_1[n_cut66] = { "pTSixObjVBF*0.001<60", "pTSixObjVBF*0.001<70", "pTSixObjVBF*0.001<80", "pTSixObjVBF*0.001<90", "pTSixObjVBF*0.001<100" };
    string cut66_2[n_cut66] = { "pTSixObjVBF<60GeV", "pTSixObjVBF<70GeV", "pTSixObjVBF<80GeV", "pTSixObjVBF<90GeV", "pTSixObjVBF<100GeV" };
    

      TCanvas *canvas66[n_cut66] ;
      canvas66[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas66[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas66[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas66[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas66[4] = new TCanvas ("c4", "Mhh",980,580);
    
      TPad *pad661[n_cut66];
      pad661[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad661[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad661[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad661[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad661[4] = new TPad ("pad4", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut66;k++) {
           canvas66[k]->cd();
           pad661[k]->Draw();
           
           pad661[k]->cd();
           pad661[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut66_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut66_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut66_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut66_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut66_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut66_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut66_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut66_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut66_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut66_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut66_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut66_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut66_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut66_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut66_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut66_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut66_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut66_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut66_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut66_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut66_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut66_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut66_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut66_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut66_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut66_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut66_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut66_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut66_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut66_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut66_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut66_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut66_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut66_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut66_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut66_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut66_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut66_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut66_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_66 = 0;
        double integral_Bkg_66 = 0;
        double integral_noVBFSM_66 = 0;

        double error_VBFSM_66 = 0;
        double error_Bkg_66 = 0;
        double error_noVBFSM_66 = 0;

        integral_VBFSM_66 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_66, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_66 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_66, "");

            integral_noVBFSM_66 += integral_Bkg_66;
            error_noVBFSM_66 += error_Bkg_66*error_Bkg_66;
        }

        error_noVBFSM_66 = sqrt(error_noVBFSM_66);

                double S_66 = 0;   S_66 = integral_VBFSM_66;
                double dS_66 = 0;  dS_66 = error_VBFSM_66;
                double B_66 = 0;   B_66 = integral_noVBFSM_66;
                double dB_66 = 0;  dB_66 = error_noVBFSM_66;

                double Significance_66 = 0;
                double R_66 = 0;
                double E_66 = 0;
                double EE_66 = 0;

                if( B_66 > 0 && S_66 > 0) {
                    
                      double LSB_66 = log(1 + S_66/B_66);
                      R_66 =  2 * ( (S_66+B_66) * LSB_66 - S_66 );
                      E_66 = LSB_66 * LSB_66 * dS_66 * dS_66 + (LSB_66 - S_66/B_66) * (LSB_66 - S_66/B_66) * dB_66 * dB_66;

                      Significance_66 = sqrt(R_66);
                      if(Significance_66 > 0) { EE_66 = sqrt(E_66) / Significance_66; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut66_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_66 << " E = " << EE_66 << endl;
        cout << "" << endl;
          
      }
 
          

    cout << " " << endl;
    cout << "  ===========================================================   Etaj1VBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut69 = 5;
    TCut cut69_1[n_cut69] = { "Etaj1VBF>0.5", "Etaj1VBF>0.7","Etaj1VBF>0.9", "Etaj1VBF>1.1", "Etaj1VBF>1.3" };
    string cut69_2[n_cut69] = { "Etaj1VBF>0.5", "Etaj1VBF>0.7","Etaj1VBF>0.9", "Etaj1VBF>1.1", "Etaj1VBF>1.3" };
    

      TCanvas *canvas69[n_cut69] ;
      canvas69[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas69[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas69[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas69[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas69[4] = new TCanvas ("c4", "Mhh",980,580);
    
      TPad *pad691[n_cut69];
      pad691[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad691[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad691[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad691[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad691[4] = new TPad ("pad4", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut69;k++) {
           canvas69[k]->cd();
           pad691[k]->Draw();
           
           pad691[k]->cd();
           pad691[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut69_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut69_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut69_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut69_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut69_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut69_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut69_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut69_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut69_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut69_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut69_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut69_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut69_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut69_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut69_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut69_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut69_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut69_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut69_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut69_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut69_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut69_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut69_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut69_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut69_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut69_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut69_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut69_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut69_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut69_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut69_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut69_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut69_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut69_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut69_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut69_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut69_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut69_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut69_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_69 = 0;
        double integral_Bkg_69 = 0;
        double integral_noVBFSM_69 = 0;

        double error_VBFSM_69 = 0;
        double error_Bkg_69 = 0;
        double error_noVBFSM_69 = 0;

        integral_VBFSM_69 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_69, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_69 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_69, "");

            integral_noVBFSM_69 += integral_Bkg_69;
            error_noVBFSM_69 += error_Bkg_69*error_Bkg_69;
        }

        error_noVBFSM_69 = sqrt(error_noVBFSM_69);

                double S_69 = 0;   S_69 = integral_VBFSM_69;
                double dS_69 = 0;  dS_69 = error_VBFSM_69;
                double B_69 = 0;   B_69 = integral_noVBFSM_69;
                double dB_69 = 0;  dB_69 = error_noVBFSM_69;

                double Significance_69 = 0;
                double R_69 = 0;
                double E_69 = 0;
                double EE_69 = 0;

                if( B_69 > 0 && S_69 > 0) {
                    
                      double LSB_69 = log(1 + S_69/B_69);
                      R_69 =  2 * ( (S_69+B_69) * LSB_69 - S_69 );
                      E_69 = LSB_69 * LSB_69 * dS_69 * dS_69 + (LSB_69 - S_69/B_69) * (LSB_69 - S_69/B_69) * dB_69 * dB_69;

                      Significance_69 = sqrt(R_69);
                      if(Significance_69 > 0) { EE_69 = sqrt(E_69) / Significance_69; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut69_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_69 << " E = " << EE_69 << endl;
        cout << "" << endl;
          
      }    


    cout << " " << endl;
    cout << "  ===========================================================   Etaj2VBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut70 = 5;
    TCut cut70_1[n_cut70] = { "Etaj2VBF>0.5", "Etaj2VBF>0.7", "Etaj2VBF>0.9","Etaj2VBF>1.1", "Etaj2VBF>1.3" };
    string cut70_2[n_cut70] = { "Etaj2VBF>0.5", "Etaj2VBF>0.7", "Etaj2VBF>0.9","Etaj2VBF>1.1", "Etaj2VBF>1.3" };
    

      TCanvas *canvas70[n_cut70] ;
      canvas70[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas70[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas70[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas70[3] = new TCanvas ("c3", "Mhh",980,580);
      canvas70[4] = new TCanvas ("c4", "Mhh",980,580);
    
      TPad *pad701[n_cut70];
      pad701[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad701[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad701[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad701[3] = new TPad ("pad3", "", 0,0,0.75,1);
      pad701[4] = new TPad ("pad4", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut70;k++) {
           canvas70[k]->cd();
           pad701[k]->Draw();
           
           pad701[k]->cd();
           pad701[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut70_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut70_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut70_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut70_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut70_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut70_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut70_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut70_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut70_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut70_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut70_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut70_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut70_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut70_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut70_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut70_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut70_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut70_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut70_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut70_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut70_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut70_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut70_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut70_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut70_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut70_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut70_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut70_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut70_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut70_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut70_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut70_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut70_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut70_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut70_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut70_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut70_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut70_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut70_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_70 = 0;
        double integral_Bkg_70 = 0;
        double integral_noVBFSM_70 = 0;

        double error_VBFSM_70 = 0;
        double error_Bkg_70 = 0;
        double error_noVBFSM_70 = 0;

        integral_VBFSM_70 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_70, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_70 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_70, "");

            integral_noVBFSM_70 += integral_Bkg_70;
            error_noVBFSM_70 += error_Bkg_70*error_Bkg_70;
        }

        error_noVBFSM_70 = sqrt(error_noVBFSM_70);

                double S_70 = 0;   S_70 = integral_VBFSM_70;
                double dS_70 = 0;  dS_70 = error_VBFSM_70;
                double B_70 = 0;   B_70 = integral_noVBFSM_70;
                double dB_70 = 0;  dB_70 = error_noVBFSM_70;

                double Significance_70 = 0;
                double R_70 = 0;
                double E_70 = 0;
                double EE_70 = 0;

                if( B_70 > 0 && S_70 > 0) {
                    
                      double LSB_70 = log(1 + S_70/B_70);
                      R_70 =  2 * ( (S_70+B_70) * LSB_70 - S_70 );
                      E_70 = LSB_70 * LSB_70 * dS_70 * dS_70 + (LSB_70 - S_70/B_70) * (LSB_70 - S_70/B_70) * dB_70 * dB_70;

                      Significance_70 = sqrt(R_70);
                      if(Significance_70 > 0) { EE_70 = sqrt(E_70) / Significance_70; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut70_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_70 << " E = " << EE_70 << endl;
        cout << "" << endl;
          
      }    


    cout << " " << endl;
    cout << "  ===========================================================   EtajjVBF   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut71 = 3;
    TCut cut71_1[n_cut71] = { "EtajjVBF<3", "EtajjVBF<2","EtajjVBF<1" };
    string cut71_2[n_cut71] = { "EtajjVBF<3", "EtajjVBF<2","EtajjVBF<1" };
    

      TCanvas *canvas71[n_cut71] ;
      canvas71[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas71[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas71[2] = new TCanvas ("c2", "Mhh",980,580);
    
      TPad *pad711[n_cut71];
      pad711[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad711[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad711[2] = new TPad ("pad2", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut71;k++) {
           canvas71[k]->cd();
           pad711[k]->Draw();
           
           pad711[k]->cd();
           pad711[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut71_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut71_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut71_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut71_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut71_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut71_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut71_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut71_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut71_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut71_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut71_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut71_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut71_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut71_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut71_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut71_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut71_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut71_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut71_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut71_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut71_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut71_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut71_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut71_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut71_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut71_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut71_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut71_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut71_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut71_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut71_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut71_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut71_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut71_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut71_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut71_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut71_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut71_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut71_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_71 = 0;
        double integral_Bkg_71 = 0;
        double integral_noVBFSM_71 = 0;

        double error_VBFSM_71 = 0;
        double error_Bkg_71 = 0;
        double error_noVBFSM_71 = 0;

        integral_VBFSM_71 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_71, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_71 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_71, "");

            integral_noVBFSM_71 += integral_Bkg_71;
            error_noVBFSM_71 += error_Bkg_71*error_Bkg_71;
        }

        error_noVBFSM_71 = sqrt(error_noVBFSM_71);

                double S_71 = 0;   S_71 = integral_VBFSM_71;
                double dS_71 = 0;  dS_71 = error_VBFSM_71;
                double B_71 = 0;   B_71 = integral_noVBFSM_71;
                double dB_71 = 0;  dB_71 = error_noVBFSM_71;

                double Significance_71 = 0;
                double R_71 = 0;
                double E_71 = 0;
                double EE_71 = 0;

                if( B_71 > 0 && S_71 > 0) {
                    
                      double LSB_71 = log(1 + S_71/B_71);
                      R_71 =  2 * ( (S_71+B_71) * LSB_71 - S_71 );
                      E_71 = LSB_71 * LSB_71 * dS_71 * dS_71 + (LSB_71 - S_71/B_71) * (LSB_71 - S_71/B_71) * dB_71 * dB_71;

                      Significance_71 = sqrt(R_71);
                      if(Significance_71 > 0) { EE_71 = sqrt(E_71) / Significance_71; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut71_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_71 << " E = " << EE_71 << endl;
        cout << "" << endl;
          
      }

      cout << " " << endl;
    cout << "  ===========================================================   X_HH   =========================================================== " << endl;
    cout << " " << endl;
    
    const int n_cut72 = 4;
    TCut cut72_1[n_cut72] = { "X_HH<0.4", "X_HH<0.5", "X_HH<0.6","X_HH<0.7" };
    string cut72_2[n_cut72] = { "X_HH<0.4", "X_HH<0.5", "X_HH<0.6","X_HH<0.7" };
    

      TCanvas *canvas72[n_cut72] ;
      canvas72[0] = new TCanvas ("c0", "Mhh",980,580);
      canvas72[1] = new TCanvas ("c1", "Mhh",980,580);
      canvas72[2] = new TCanvas ("c2", "Mhh",980,580);
      canvas72[3] = new TCanvas ("c3", "Mhh",980,580);
    
      TPad *pad721[n_cut72];
      pad721[0] = new TPad ("pad0", "", 0,0,0.75,1);
      pad721[1] = new TPad ("pad1", "", 0,0,0.75,1);
      pad721[2] = new TPad ("pad2", "", 0,0,0.75,1);
      pad721[3] = new TPad ("pad3", "", 0,0,0.75,1);
    
      for (int i=0; i<n_smp; i++){
            h_nm = h_title[i].c_str();
            h_hist[i] = new TH1F(h_nm, "",30,0,3000);
            h_hist[i]->GetYaxis()->SetRangeUser(0, 70000);
        }

      for (int k=0;k<n_cut72;k++) {
           canvas72[k]->cd();
           pad721[k]->Draw();
           
           pad721[k]->cd();
           pad721[k]->SetTickx();

           gStyle->SetOptStat(kFALSE);

        for (int i=0; i<n_smp; i++){
            hist_draw[i]=("mHHStar*0.001>>"+h_title[i]);
        }

        for (int i=0; i<n_smp; i++){
	          h_hist[i]->Reset();
	          h_hist[i]->Sumw2();
        }
        
        for(int i = 0; i<n_smp; i++){
          if(i == 0){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttH && cut72_1[k]), "SAMEHIST");}
          else if(i == 1){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttZ && cut72_1[k]), "SAMEHIST");}
          else if(i == 2){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttW && cut72_1[k]), "SAMEHIST");}
          else if(i == 3){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && VBFHtautau && cut72_1[k]), "SAMEHIST");}
          else if(i == 4){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHbb && cut72_1[k]), "SAMEHIST");}
          else if(i == 5){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHbb && cut72_1[k]), "SAMEHIST");}
          else if(i == 6){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHbb && cut72_1[k]), "SAMEHIST");}
          else if(i == 7){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WHtautau && cut72_1[k]), "SAMEHIST");}
          else if(i == 8){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && qqZHtautau && cut72_1[k]), "SAMEHIST");}
          else if(i == 9){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggZHtautau && cut72_1[k]), "SAMEHIST");}
          else if(i == 10){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WZ && cut72_1[k]), "SAMEHIST");}
          else if(i == 11){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WW && cut72_1[k]), "SAMEHIST");}
          else if(i == 12){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ZZ && cut72_1[k]), "SAMEHIST");}
          else if(i == 13){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DY && cut72_1[k]), "SAMEHIST");}
          else if(i == 14){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && DYtt && cut72_1[k]), "SAMEHIST");}
          else if(i == 15){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbarFake && cut72_1[k]), "SAMEHIST");}
          else if(i == 16){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WFake && cut72_1[k]), "SAMEHIST");}
          else if(i == 17){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && WttFake && cut72_1[k]), "SAMEHIST");}
          else if(i == 18){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbb && cut72_1[k]), "SAMEHIST");}
          else if(i == 19){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbc && cut72_1[k]), "SAMEHIST");}
          else if(i == 20){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zbl && cut72_1[k]), "SAMEHIST");}
          else if(i == 21){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcc && cut72_1[k]), "SAMEHIST");}
          else if(i == 22){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zcl && cut72_1[k]), "SAMEHIST");}
          else if(i == 23){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zl && cut72_1[k]), "SAMEHIST");}
          else if(i == 24){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && W && cut72_1[k]), "SAMEHIST");}
          else if(i == 25){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Wtt && cut72_1[k]), "SAMEHIST");}
          else if(i == 26){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbb && cut72_1[k]), "SAMEHIST");}
          else if(i == 27){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbc && cut72_1[k]), "SAMEHIST");}
          else if(i == 28){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttbl && cut72_1[k]), "SAMEHIST");}
          else if(i == 29){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcc && cut72_1[k]), "SAMEHIST");}
          else if(i == 30){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttcl && cut72_1[k]), "SAMEHIST");}
          else if(i == 31){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && Zttl && cut72_1[k]), "SAMEHIST");}
          else if(i == 32){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stops && cut72_1[k]), "SAMEHIST");}
          else if(i == 33){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopWt && cut72_1[k]), "SAMEHIST");}
          else if(i == 34){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && stopt && cut72_1[k]), "SAMEHIST");}
          else if(i == 35){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ttbar && cut72_1[k]), "SAMEHIST");}
          else if(i == 36){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbb && cut72_1[k]), "SAMEHIST");}
          else if(i == 37){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && ggFHtautau && cut72_1[k]), "SAMEHIST");}
          else if(i == 38){chain_smp[i]->Draw(hist_draw[i].c_str(), weight*(TwoBTaggedJets && TwoOppositeSignTau && mBB && VBF && mjjVBF && hhttbbVBFSM && cut72_1[k]), "SAMEHIST");}
        }
        

       //cout << " ============== significance calculation ============== " << endl;

        double integral_VBFSM_72 = 0;
        double integral_Bkg_72 = 0;
        double integral_noVBFSM_72 = 0;

        double error_VBFSM_72 = 0;
        double error_Bkg_72 = 0;
        double error_noVBFSM_72 = 0;

        integral_VBFSM_72 = h_hist[38]->IntegralAndError(0, 3000, error_VBFSM_72, "");

        for (int i=0; i<38; i++)
        {
            integral_Bkg_72 = h_hist[i]->IntegralAndError(0, 3000, error_Bkg_72, "");

            integral_noVBFSM_72 += integral_Bkg_72;
            error_noVBFSM_72 += error_Bkg_72*error_Bkg_72;
        }

        error_noVBFSM_72 = sqrt(error_noVBFSM_72);

                double S_72 = 0;   S_72 = integral_VBFSM_72;
                double dS_72 = 0;  dS_72 = error_VBFSM_72;
                double B_72 = 0;   B_72 = integral_noVBFSM_72;
                double dB_72 = 0;  dB_72 = error_noVBFSM_72;

                double Significance_72 = 0;
                double R_72 = 0;
                double E_72 = 0;
                double EE_72 = 0;

                if( B_72 > 0 && S_72 > 0) {
                    
                      double LSB_72 = log(1 + S_72/B_72);
                      R_72 =  2 * ( (S_72+B_72) * LSB_72 - S_72 );
                      E_72 = LSB_72 * LSB_72 * dS_72 * dS_72 + (LSB_72 - S_72/B_72) * (LSB_72 - S_72/B_72) * dB_72 * dB_72;

                      Significance_72 = sqrt(R_72);
                      if(Significance_72 > 0) { EE_72 = sqrt(E_72) / Significance_72; }
                    
                }
           

        // =================  Significance  =================
          
        cout << "" << endl;
        cout << cut72_2[k] << endl;
        cout << " Mhh : " <<" S = " << Significance_72 << " E = " << EE_72 << endl;
        cout << "" << endl;
          
      }

  }

