
LEPTON_SETUP = 2015
PD = ""
MCFILTER = ""
ELECORRTYPE   = "None" # "None", "Moriond", or "Paper"
ELEREGRESSION = "None" # "None", "Moriond", "PaperNoComb", or "Paper" 
APPLYMUCORR = False

#KEEPLOOSECOMB = True

#For DATA: 
#IsMC = False
#PD = "DoubleEle"

# Get absolute path
import os
PyFilePath = os.environ['CMSSW_BASE'] + "/src/ZZAnalysis/AnalysisStep/test/"

### ----------------------------------------------------------------------
### Standard sequence
### ----------------------------------------------------------------------

execfile(PyFilePath + "analyzer.py")


### ----------------------------------------------------------------------
### Replace parameters
### ----------------------------------------------------------------------
process.source.fileNames = cms.untracked.vstring(
    #'/store/cmst3/user/gpetrucc/miniAOD/v1/GluGluToHToZZTo4L_M-125_13TeV-powheg-pythia6_PU_S14_PAT.root'
    #'/store/cmst3/user/gpetrucc/miniAOD/v1/GluGluToHToZZTo4L_M-125_13TeV-powheg-pythia6_PU_S14_PAT_big.root' #S14 = 50ns scenario, GT: PLS170_V6AN1
    #"/store/mc/Spring14miniaod/GluGluToHToZZTo4L_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_POSTLS170_V5-v1/00000/0881ABEB-2709-E411-9E42-00145EDD7581.root" # 1st file from the central 20bx25 sample, GT: PLS170_V7AN1

    #'root://cms-xrd-global.cern.ch//store/mc/Phys14DR/ZZTo4L_Tune4C_13TeV-powheg-pythia8/MINIAODSIM/PU20bx25_PHYS14_25_V1-v1/00000/04CD96C9-E269-E411-9D64-00266CF9ADA0.root',

#    '/store/mc/Phys14DR/GluGluToHToZZTo4L_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v1/00000/3295EF7C-2070-E411-89C4-7845C4FC35DB.root' # Official sync file for signal

#    'file:/afs/cern.ch/user/g/gortona/work/public/miniAODPhys14/DYJetsToLL_M-50_13TeV_3leptons.root' # Official sync file for CR

     '/store/cmst3/group/susy/gpetrucc/13TeV/Phys14DR/MINIAODSIM/ggH_JHU_125/ggH_JHU_125.MINIAODSIM00.root',
     '/store/cmst3/group/susy/gpetrucc/13TeV/Phys14DR/MINIAODSIM/VBF_JHU_125/VBF_JHU_125.MINIAODSIM00.root',
     '/store/cmst3/group/susy/gpetrucc/13TeV/Phys14DR/MINIAODSIM/WminusH_JHU_125/WminusH_JHU_125.MINIAODSIM00.root',
     '/store/cmst3/group/susy/gpetrucc/13TeV/Phys14DR/MINIAODSIM/ZH_JHU_125/ZH_JHU_125.MINIAODSIM00.root',
     '/store/cmst3/group/susy/gpetrucc/13TeV/Phys14DR/MINIAODSIM/ttH_JHU_125/ttH_JHU_125.MINIAODSIM00.root',
    )


### FIXME: DEBUGGING ONLY, turns off smearing if used with special tag
#process.calibratedPatElectrons.synchronization = True
#process.calibratedMuons.fakeSmearing = cms.bool(True)

process.maxEvents.input = -1

# Silence output
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.TFileService.fileName=cms.string('ZZ4lAnalysis_ct.root')
                                


### ----------------------------------------------------------------------
### Analyzer for Plots
### ----------------------------------------------------------------------


#process.source.eventsToProcess = cms.untracked.VEventRange("1:122490", "1:1343", "1:177684")
#process.source.eventsToProcess = cms.untracked.VEventRange("1:30602")
#process.source.eventsToProcess = cms.untracked.VEventRange("191062:303:330091192")

# Debug
process.dumpUserData =  cms.EDAnalyzer("dumpUserData",
     dumpTrigger = cms.untracked.bool(True),
#     muonSrc = cms.InputTag("slimmedMuons"),
#     electronSrc = cms.InputTag("slimmedElectrons"),
     muonSrc = cms.InputTag("appendPhotons:muons"), 
     electronSrc = cms.InputTag("appendPhotons:electrons"),
     candidateSrcs = cms.PSet(
        Z     = cms.InputTag("ZCand"),                                  
        ZZ  = cms.InputTag("ZZCand"),
#        ZLL  = cms.InputTag("ZLLCand"),
     ),
     jetSrc = cms.InputTag("cleanJets"),
)

# Create lepton sync file
process.PlotsZZ.dumpForSync = True;

# Also process CRs
process.CRPath = cms.Path(process.CR)
process.CRtrees = cms.EndPath(process.CRZLLTree + process.CRZLTree)

# replace the paths in analyzer.py
process.p = cms.EndPath( process.PlotsZZ)
process.trees = cms.EndPath(process.ZZTree)

#Dump reconstructed variables
#process.appendPhotons.debug = cms.untracked.bool(True)
#process.dump = cms.Path(process.dumpUserData)

#Print MC history
#process.mch = cms.EndPath(process.printTree)
