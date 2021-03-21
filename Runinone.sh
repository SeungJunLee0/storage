#!/bin/bash

CFGFILE=${PWD}/ispy_10_X_X_cfg.py
#cd /afs/cern.ch/user/s/seungjun/public/ISPY/CMSSW_11_2_3/src
SRC= /afs/cern.ch/user/s/seungjun/public/ISPY/CMSSW_11_2_3/src
cd $SRC
scram b -j20

cmsRun ${CFGFILE}
cp -r igOutput_0.ig ~/public/copyinlxplus/
