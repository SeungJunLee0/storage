import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.StandardSequences.FrontierConditions_GlobalTag_cff import *

GlobalTag.globaltag = "110X_dataRun3_Express_GEMRecoGEO_v1" 
#GlobalTag.globaltag = "111X_dataRun3_HLT_v2" 
#GlobalTag.globaltag = "111X_mcRun3_2021_design_v7" 
#GlobalTag.globaltag = "111X_mcRun3_2021_design_Candidate_2020_06_05_21_54_29"

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)
process.source = cms.Source("EmptySource")

process.GEMGeometryESModule = cms.ESProducer("GEMGeometryESModule",
    fromDDD = cms.bool(False),
    fromDD4Hep = cms.bool(False),
    alignmentsLabel = cms.string(''),
    applyAlignment = cms.bool(False)
)


"""
process.MessageLogger = cms.Service("MessageLogger",
                                    destinations = cms.untracked.vstring('cout'),
                                    categories = cms.untracked.vstring('GEMGeometryBuilderFromDDD'),
                                    cout = cms.untracked.PSet(
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
            ),
        GEMGeometryBuilderFromDDD = cms.untracked.PSet(
            limit = cms.untracked.int32(-1)
            )
        )
                                    )
"""
process.test = cms.EDAnalyzer("GEMGeometryAnalyzer")

process.p = cms.Path(process.test)

### TO ACTIVATE LogTrace NEED TO COMPILE IT WITH:
### -----------------------------------------------------------
### --> scram b -j8 USER_CXXFLAGS="-DEDM_ML_DEBUG"
### Make sure that you first cleaned your CMSSW version:
### --> scram b clean
### before issuing the scram command above
###############################################################
process.load("FWCore.MessageLogger.MessageLogger_cfi")
# process.MessageLogger.categories.append("GEMGeometryBuilderFromDDD")
# process.MessageLogger.categories.append("GEMNumberingScheme")
process.MessageLogger.debugModules = cms.untracked.vstring("*")
process.MessageLogger.destinations = cms.untracked.vstring("cout","junk")
process.MessageLogger.cout = cms.untracked.PSet(
    threshold = cms.untracked.string("DEBUG"),
    default = cms.untracked.PSet( limit = cms.untracked.int32(0) ),
    FwkReport = cms.untracked.PSet( limit = cms.untracked.int32(-1) ),
    # GEMGeometryBuilderFromDDD   = cms.untracked.PSet( limit = cms.untracked.int32(-1) ),
    # GEMNumberingScheme            = cms.untracked.PSet( limit = cms.untracked.int32(-1) ),
)
