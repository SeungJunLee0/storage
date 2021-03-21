
/** Derived from DTGeometryAnalyzer by Nicola Amapane
 *
 *  \author M. Maggi - INFN Bari
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "Geometry/GEMGeometry/interface/GEMGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/GEMGeometry/interface/GEMEtaPartitionSpecs.h"
#include "Geometry/CommonTopologies/interface/StripTopology.h"
//#include "Geometry/CommonTopologies/interface/GEMStripTopology.h"

#include "DataFormats/Math/interface/deltaPhi.h"
#include "TMath.h"
#include <memory>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>

class GEMGeometryAnalyzer : public edm::one::EDAnalyzer<> {
	public:
		GEMGeometryAnalyzer(const edm::ParameterSet& pset);

		~GEMGeometryAnalyzer() override;

		void beginJob() override {}
		void analyze(edm::Event const& iEvent, edm::EventSetup const&) override;
		void endJob() override {}

	private:
		const std::string& myName() { return myName_; }

		const int dashedLineWidth_;
		const std::string dashedLine_;
		const std::string myName_;
		std::ofstream ofos;
};
int diffgl=0;
int anlocal=0;
int anglobal=0;
int difflo=0;
int dxdx=1;
using namespace std;
GEMGeometryAnalyzer::GEMGeometryAnalyzer(const edm::ParameterSet& /*iConfig*/)
	: dashedLineWidth_(104), dashedLine_(std::string(dashedLineWidth_, '-')), myName_("GEMGeometryAnalyzer") {
		//ofos.open("GEMtestOutput.out");
		if(diffgl==1)ofos.open("GEMtestOutputdiffgl.out");
		if(anlocal==1)ofos.open("GEMtestOutputanlocal.out");
		if(anglobal==1)ofos.open("GEMtestOutputanglobal.out");
		if(difflo==1)ofos.open("GEMtestOutputdifflo.out");
		if(dxdx==1)ofos.open("GEMdxdx.out");
		//ofos << "======================== Opening output file" << std::endl;
	}

GEMGeometryAnalyzer::~GEMGeometryAnalyzer() {
	ofos.close();
	//ofos << "======================== Closing output file" << std::endl;
}

void GEMGeometryAnalyzer::analyze(const edm::Event& /*iEvent*/, const edm::EventSetup& iSetup) {
	edm::ESHandle<GEMGeometry> pDD;
	iSetup.get<MuonGeometryRecord>().get(pDD);

	//  ofos << myName() << ": Analyzer..." << std::endl;
	//  ofos << "start " << dashedLine_ << std::endl;

	//ofos << " Geometry node for GEMGeom is  " << &(*pDD) << endl  ofos << " detTypes       \t" << pDD->detTypes().size() << endl;
	//ofos << " detTypes       \t" << pDD->detTypes().size() << endl;
	//ofos << " GeomDetUnit       \t" << pDD->detUnits().size() << endl;
	//ofos << " GeomDet           \t" << pDD->dets().size() << endl;
	//ofos << " GeomDetUnit DetIds\t" << pDD->detUnitIds().size() << endl;
	//ofos << " eta partitions \t" << pDD->etaPartitions().size() << endl;
	//ofos << " chambers       \t" << pDD->chambers().size() << endl;
	//ofos << " super chambers  \t" << pDD->superChambers().size() << endl;
	//ofos << " rings  \t\t" << pDD->rings().size() << endl;
	//ofos << " stations  \t\t" << pDD->stations().size() << endl;
	//ofos << " regions  \t\t" << pDD->regions().size() << endl;

	// checking uniqueness of roll detIds
	bool flagNonUniqueRollID = false;
	bool flagNonUniqueRollRawID = false;
	int nstrips = 0;
	int npads = 0;
	for (auto roll1 : pDD->etaPartitions()) {
		nstrips += roll1->nstrips();
		npads += roll1->npads();
		for (auto roll2 : pDD->etaPartitions()) {
			if (roll1 != roll2) {
				if (roll1->id() == roll2->id())
					flagNonUniqueRollID = true;
				if (roll1->id().rawId() == roll2->id().rawId())
					flagNonUniqueRollRawID = true;
			}
		}
	}
	// checking the number of strips and pads
	//ofos << " total number of strips\t" << nstrips << endl;
	//ofos << " total number of pads  \t" << npads << endl;
	if (flagNonUniqueRollID or flagNonUniqueRollRawID)
		ofos << " -- WARNING: non unique roll Ids!!!" << endl;

	// checking uniqueness of chamber detIds
	bool flagNonUniqueChID = false;
	bool flagNonUniqueChRawID = false;
	for (auto ch1 : pDD->chambers()) {
		for (auto ch2 : pDD->chambers()) {
			if (ch1 != ch2) {
				if (ch1->id() == ch2->id())
					flagNonUniqueChID = true;
				if (ch1->id().rawId() == ch2->id().rawId())
					flagNonUniqueChRawID = true;
			}
		}
	}
	if (flagNonUniqueChID or flagNonUniqueChRawID)
		ofos << " -- WARNING: non unique chamber Ids!!!" << endl;

	//ofos << myName() << ": Begin iteration over geometry..." << endl;
	//ofos << "iter " << dashedLine_ << endl;

	//----------------------- Global GEMGeometry TEST -------------------------------------------------------
	//ofos << myName() << "Begin GEMGeometry structure TEST" << endl;

	for (auto region : pDD->regions()) {
		//    ofos << "  GEMRegion " << region->region() << " has " << region->nStations() << " stations." << endl;
		for (auto station : region->stations()) {
			//ofos << "    GEMStation " << station->getName() << " has " << station->nRings() << " rings." << endl;
			if(station -> getName() =="GE-2/1" ||station -> getName() =="GE2/1")continue;
			for (auto ring : station->rings()) {
				//ofos << "      GEMRing " << ring->region() << " " << ring->station() << " " << ring->ring() << " has "
				//    << ring->nSuperChambers() << " super chambers." << endl;
				int i = 1;
				for (auto sch : ring->superChambers()) {
					GEMDetId schId(sch->id());
					//ofos << "        GEMSuperChamber " << i << ", GEMDetId = " << schId.rawId() << ", " << schId << " has "
					//     << sch->nChambers() << " chambers." << endl;
					// checking the dimensions of each partition & chamber
					int j = 1;
					for (auto ch : sch->chambers()) {
						if(j !=1) continue;
						GEMDetId chId(ch->id());
						int nRolls(ch->nEtaPartitions());
						//            ofos << "          GEMChamber " << j << ", GEMDetId = " << chId.rawId() << ", " << chId << " has " << nRolls
						//                 << " eta partitions." << endl;
						//
						int k = 1;
						auto& rolls(ch->etaPartitions());

						/*
						 * possible checklist for an eta partition:
						 *   base_bottom, base_top, height, strips, pads
						 *   cx, cy, cz, ceta, cphi
						 *   tx, ty, tz, teta, tphi
						 *   bx, by, bz, beta, bphi
						 *   pitch center, pitch bottom, pitch top
						 *   deta, dphi
						 *   gap thickness
						 *   sum of all dx + gap = chamber height
						 */

						for (auto roll : rolls) {
							GEMDetId rId(roll->id());
							//ofos << "            GEMEtaPartition " << k << ", GEMDetId = " << rId.rawId() << ", " << rId << endl;

							const BoundPlane& bSurface(roll->surface());
							const StripTopology* topology(&(roll->specificTopology()));

							// base_bottom, base_top, height, strips, pads (all half length)
							auto& parameters(roll->specs()->parameters());
							float bottomEdge(parameters[0]);
							float topEdge(parameters[1]);
							float height(parameters[2]);
							float nStrips(parameters[3]);
							float nPads(parameters[4]);

							LocalPoint lCentre(0., 0., 0.);
							GlobalPoint gCentre(bSurface.toGlobal(lCentre));

							LocalPoint lTop(0., height, 0.);
							GlobalPoint gTop(bSurface.toGlobal(lTop));

							LocalPoint lBottom(0., -height, 0.);
							GlobalPoint gBottom(bSurface.toGlobal(lBottom));

							//   gx, gy, gz, geta, gphi (center)
							double cx(gCentre.x());
							double cy(gCentre.y());
							double cz(gCentre.z());
							double ceta(gCentre.eta());
							//int cphi(static_cast<int>(gCentre.phi().degrees()));
							double cphi(static_cast<double>(gCentre.phi().degrees()));
							if (cphi < 0)
								cphi += 360;

							double tx(gTop.x());
							double ty(gTop.y());
							double tz(gTop.z());
							double teta(gTop.eta());
							//int tphi(static_cast<int>(gTop.phi().degrees()));
							double tphi(static_cast<double>(gTop.phi().degrees()));
							if (tphi < 0)
								tphi += 360;

							double bx(gBottom.x());
							double by(gBottom.y());
							double bz(gBottom.z());
							double beta(gBottom.eta());
							//int bphi(static_cast<int>(gBottom.phi().degrees()));
							double bphi(static_cast<double>(gBottom.phi().degrees()));
							if (bphi < 0)
								bphi += 360;

							// pitch bottom, pitch top, pitch centre
							float pitch(roll->pitch());
							float topPitch(roll->localPitch(lTop));
							float bottomPitch(roll->localPitch(lBottom));

							// Type - should be GHA[1-nRolls]
							string type(roll->type().name());

							// print info about edges
							LocalPoint lEdge1(topology->localPosition(0.));
							LocalPoint lEdgeN(topology->localPosition((float)nStrips));

							double cstrip1(roll->toGlobal(lEdge1).phi().degrees());
							double cstripN(roll->toGlobal(lEdgeN).phi().degrees());
							double dphi(cstripN - cstrip1);
							if (dphi < 0.)
								dphi += 360.;
							double deta(abs(beta - teta));
							const bool printDetails(true);
							if (printDetails) {
								if(difflo ==1){
									for(int ii=0;ii<383;ii++){
									int jj =ii+1;
									
										double ds(topology->stripAngle((float)ii));
										double ds1(topology->stripAngle((float)jj));
										double dss = (ds1-ds)*180.0/M_PI;
										ofos <<dss<<endl;
									}


								}

							//	int diffgl=0;
								if(dxdx ==1){
									for(int ii =0;ii<383;ii++){
									int jj = ii+1;
									//LocalPoint lEdgeii(topology->localPosition((float)ii));
									//LocalPoint lEdgeff(topology->localPosition((float)jj));
									//double cstripii(roll->toGlobal(lEdgeii).x());
									//double cstripff(roll->toGlobal(lEdgeff).x());
									//ofos << cstripff-cstripii <<endl;
									double dx1(topology->localPosition((float)ii).x());
									double dx2(topology->localPosition((float)jj).x());
									ofos<<dx2-dx1<<endl;
									}
								}
							//	int anlocal=0;
								if(anlocal ==1){
									for(int ii =0;ii<384;ii++){
										double ds(topology->stripAngle((float)ii));
										//double dss = ds*180.0/(Math::Pi());
										double dss = ds*180.0/M_PI;
										ofos <<dss<<endl;
									}
								}
							//	int anglobal=0;
								if(anglobal ==1){
									for(int ii =0;ii<384;ii++){
									LocalPoint lEdgeii(topology->localPosition((float)ii));
									double cstripii(roll->toGlobal(lEdgeii).phi().degrees());
									ofos << cstripii <<endl;
									}
									ofos << cphi << endl;
								}
								///////////////////
								// ofos << "    \t\tType: " << type << endl
								//      << "    \t\tDimensions[cm]: b = " << bottomEdge * 2 << ", B = " << topEdge * 2
								//      << ", h  = " << height * 2 << endl
								//      << "    \t\tnStrips = " << nStrips << ", nPads =  " << nPads << endl
								//      << "    \t\ttop(x,y,z)[cm] = (" << tx << ", " << ty << ", " << tz << "), top(eta,phi) = (" << teta
								//      << ", " << tphi << ")" << endl
								//      << "    \t\tcenter(x,y,z)[cm] = (" << cx << ", " << cy << ", " << cz << "), center(eta,phi) = ("
								//      << ceta << ", " << cphi << ")" << endl
								//      << "    \t\tbottom(x,y,z)[cm] = (" << bx << ", " << by << ", " << bz << "), bottom(eta,phi) = ("
								//      << beta << ", " << bphi << ")" << endl
								//      << "    \t\tpitch (top,center,bottom) = (" << topPitch << ", " << pitch <<", " << bottomPitch
								//      << "), dEta = " << deta << ", dPhi = " << dphi << endl;
							}
							++k;
						}
						++j;
					}
					++i;
				}
			}
		}
	}

	//ofos << dashedLine_ << " end" << std::endl;
}

//define this as a plug-in
#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(GEMGeometryAnalyzer);
