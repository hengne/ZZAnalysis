#include <ZZAnalysis/AnalysisStep/interface/Category.h>

#include <cmath>

#include "Math/GenVector/LorentzVector.h"
#include "Math/GenVector/PtEtaPhiM4D.h"

typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> >  LV;


int flagDijetVH(
		int nJets, 
		float* jetpt,
		float* jeteta,
		float* jetphi,
		float* jetmass
		)
{

  bool found = false;

  if(nJets>=2){

    for(int j1=0; j1<nJets; j1++){
      if( std::abs(jeteta[j1])<2.4 && jetpt[j1]>40. ){

	for(int j2=j1+1; j2<nJets; j2++){
	  if( std::abs(jeteta[j2])<2.4 && jetpt[j2]>40. ){

	    LV jet1 (jetpt[j1],jeteta[j1],jetphi[j1],jetmass[j1]);
	    LV jet2 (jetpt[j2],jeteta[j2],jetphi[j2],jetmass[j2]);
	    float mjj = (jet1+jet2).mass();

            std::cout << "jet1 pt: " << jet1.Pt() << ", jet2 pt: " << jet2.Pt() << ", jet1 eta: " << fabs(jet1.Eta()) << ", jet2 eta: " << fabs(jet2.Eta()) << std::endl;
            std::cout << "diJets mass: " << (jet1+jet2).M() << ", diJets eta: " << (jet1+jet2).Eta() << ", diJets pt: " << (jet1+jet2).Pt() << std::endl;

	    if( 60.<mjj && mjj<120. ){
	      found = true;
	      break;
	    }

	  }
	}

	if(found) break;
      }
    }

  }
  
  return found;

}


//int category(
extern "C" int category(
	     int nExtraLeptons,
	     float ZZPt,
	     float ZZMass,
	     int nJets, 
	     int nBTaggedJets,
	     float* jetpt,
	     float* jeteta,
	     float* jetphi,
	     float* jetmass,
	     float Fisher
	     )
{

  int category = -1;
  // 0 = Untagged  
  // 1 = 1-jet tagged  
  // 2 = VBF tagged  
  // 3 = VH-leptonic tagged  
  // 4 = VH-hadronic tagged  
  // 5 = ttH tagged  

  if( nExtraLeptons==0 && nJets>=2 && nBTaggedJets<=1 && Fisher>0.5 ){

    category = 2; // VBF tagged

  }else if( ( nExtraLeptons==0 && nJets>=2 && ZZPt>ZZMass && flagDijetVH(nJets,jetpt,jeteta,jetphi,jetmass) )
            || ( nExtraLeptons==0 && nJets==2 && nBTaggedJets==2 ) ){

    category = 4; // VH-hadronic tagged

  }else if( nExtraLeptons>=1 && nJets<=2 && nBTaggedJets==0 ){

    category = 3; // VH-leptonic tagged

  }else if( nExtraLeptons>=1 || (nJets>=3 && nBTaggedJets>=1) ){

    category = 5; // ttH tagged

  }else if(nJets>=1){

    category = 1; // 1-jet tagged

  }else{

    category = 0; // Untagged

  }

  return category;

}
