//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B4aActionInitialization.cc 68058 2013-03-13 14:47:43Z gcosmo $
//
/// \file B4aActionInitialization.cc
/// \brief Implementation of the B4aActionInitialization class

#include "B4aActionInitialization.hh"
#include "B4PrimaryGeneratorAction.hh"
#include "B4JetGeneratorAction.hh"
#include "B4RunAction.hh"
#include "B4aEventAction.hh"
#include "B4aSteppingAction.hh"
#include "B4DetectorConstruction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4aActionInitialization::B4aActionInitialization
            (B4DetectorConstruction* detConstruction, bool particleGun/* = true*/)
 : G4VUserActionInitialization(),
   fDetConstruction(detConstruction),
   particleGun_(particleGun)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4aActionInitialization::~B4aActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4aActionInitialization::BuildForMaster() const
{
  G4VUserPrimaryGeneratorAction* gen(nullptr);

  if (particleGun_)
    gen=new B4PrimaryGeneratorAction;
  else
    gen=new B4JetGeneratorAction;

  auto ev=new B4aEventAction(particleGun_);
  SetUserAction(new B4RunAction(gen,ev,""));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4aActionInitialization::Build() const
{
  G4VUserPrimaryGeneratorAction* gen(nullptr);
  if (particleGun_) {
    gen=new B4PrimaryGeneratorAction;
    SetUserAction(new B4PrimaryGeneratorAction);
  }
  else {
    gen = new B4JetGeneratorAction;
    SetUserAction(new B4JetGeneratorAction);
  }

  auto eventAction = new B4aEventAction(particleGun_);
  eventAction->setDetector(fDetConstruction);
  auto runact=new B4RunAction(gen,eventAction,fname_);
  SetUserAction(runact);
  SetUserAction(eventAction);
  SetUserAction(new B4aSteppingAction(fDetConstruction,eventAction));
  G4cout << "actions initialised" <<G4endl;
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
