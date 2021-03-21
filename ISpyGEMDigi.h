#ifndef ANALYZER_ISPY_GEMDIGI_H
#define ANALYZER_ISPY_GEMDIGI_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/GEMDigi/interface/GEMDigiCollection.h"

class ISpyGEMDigi : public edm::EDAnalyzer
{
public:
  explicit ISpyGEMDigi(const edm::ParameterSet&);
  virtual ~ISpyGEMDigi(void) {}
  
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
private:
  edm::InputTag 		inputTag_;
  int 				thresholdOffset_;
  edm::EDGetTokenT<GEMDigiCollection> digiToken_;
};

#endif //ANALYZER_ISPY_GEMDIGI_H
