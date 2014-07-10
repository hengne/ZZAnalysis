#!/bin/tcsh -fe

############## For miniAOD/CMSSW_7_0_6 patch1

#ZZAnalysis
git clone https://github.com/CJLST/ZZAnalysis.git ZZAnalysis
cd ZZAnalysis
git checkout giacomo_miniAOD
cd ..
git clone https://github.com/HZZ4l/CombinationPy.git HZZ4L_Combination/CombinationPy #find a way to remove this

#MuScleFit: probably tbf
git clone https://github.com/scasasso/usercode/MuScleFit

#MELA
git clone https://github.com/cms-analysis/HiggsAnalysis-ZZMatrixElement.git ZZMatrixElement
#MELA dependencies
git clone https://github.com/usarica/HiggsAnalysis-CombinedLimit HiggsAnalysis/CombinedLimit
cd HiggsAnalysis/CombinedLimit 
git checkout US_slc6root53417
cd -
git clone https://github.com/msnowball/HCSaW Higgs/Higgs_CS_and_Width
cd Higgs/Higgs_CS_and_Width
git filter-branch --subdirectory-filter Higgs_CS_and_Width
cd -
