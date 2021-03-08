from FWCore.ParameterSet import VarParsing
import os
import glob

options = VarParsing.VarParsing('analysis')
options.register(
    "inPath",
    "./step3_inDQM.root",
    VarParsing.VarParsing.multiplicity.singleton,
    VarParsing.VarParsing.varType.string,
    "a path to a inDQM file or a directory having such files")
options.parseArguments()

if os.path.isdir(options.inPath):
    pathname = os.path.join(options.inPath, '*inDQM*.root')
    fileNames = ['file:' + each for each in glob.glob(pathname)]
    fileNames = cms.untracked.vstring(*fileNames)
else:
    fileNames = cms.untracked.vstring('file:' + options.inPath)

process.source = cms.Source("DQMRootSource",
    fileNames = fileNames
)