#ifndef EventReader_h
#define EventReader_h

/** geant 4 libs **/
#include "G4VPrimaryGenerator.hh"

/** ROOT libs **/
#include "TFile.h"
#include "TTree.h"

/** standard libs **/
#include <string>
#include <vector>

#include "GaugiKernel/MsgStream.h"
#include "GaugiKernel/Property.h"
#include "GaugiKernel/macros.h"
#include "EventInfo/EventInfo.h"
#include "EventInfo/EventInfoContainer.h"





class ParticleGun : public G4VPrimaryGenerator, public MsgService, public PropertyService 
{
   
  public:
    /** Constructor **/
    ParticleGun();
    /** Destructor **/
    virtual ~ParticleGun();
    
    void Initialize();
    // The default behavior is that a single HepMC event generated by
    // GenerateHepMCEvent() will be converted to G4Event through HepMC2G4().
    virtual void GeneratePrimaryVertex(G4Event* anEvent);

    
  private:
    
    // We  have to take care for the position of primaries because
    // primary vertices outside the world voulme give rise to G4Execption.
    // If the default implementation is not adequate, an alternative
    // can be implemented in your own class.
    bool CheckVertexInsideWorld(const G4ThreeVector& pos) const;
    
};

#endif
