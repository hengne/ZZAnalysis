#!/bin/tcsh -fe

############## For miniAOD/CMSSW_7_0_7 patch1

#ZZAnalysis
git clone https://github.com/CJLST/ZZAnalysis.git ZZAnalysis
(cd ZZAnalysis; git checkout giacomo_miniAOD)

#Not needed anymore
#git clone https://github.com/HZZ4l/CombinationPy.git HZZ4L_Combination/CombinationPy 

#effective areas (to be updated)
git clone -n https://github.com/latinos/UserCode-sixie-Muon-MuonAnalysisTools Muon/MuonAnalysisTools
(cd Muon/MuonAnalysisTools ; git checkout master -- interface/MuonEffectiveArea.h )

git clone -n https://github.com/cms-analysis/EgammaAnalysis-ElectronTools EGamma/EGammaAnalysisTools
(cd EGamma/EGammaAnalysisTools; git checkout master -- interface/ElectronEffectiveArea.h)

#MuScleFit: probably tbf
#git clone https://github.com/scasasso/usercode MuScleFit

#MELA
git clone https://github.com/cms-analysis/HiggsAnalysis-ZZMatrixElement.git ZZMatrixElement
(cd ZZMatrixElement ; git checkout -b from-c125098 c125098)

#MELA dependencies
git clone https://github.com/usarica/HiggsAnalysis-CombinedLimit HiggsAnalysis/CombinedLimit
(cd HiggsAnalysis/CombinedLimit ; git checkout US_slc6root53417)

# Not needed, for the time being
#git clone https://github.com/msnowball/HCSaW Higgs/Higgs_CS_and_Width
#cd Higgs/Higgs_CS_and_Width
#git filter-branch --subdirectory-filter Higgs_CS_and_Width
#cd -
