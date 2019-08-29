export PATH=/cvmfs/sft.cern.ch/lcg/releases/LCG_93/Python/2.7.13/x86_64-slc6-gcc7-opt/bin/:$PATH
export LCGENV_PATH=/cvmfs/sft.cern.ch/lcg/releases/
export PATH=/cvmfs/sft.cern.ch/lcg/releases/lcgenv/latest/:$PATH
export PATH=/usr/bin:$PATH
eval "`lcgenv -p LCG_93 x86_64-slc6-gcc7-opt Geant4`"
eval "`lcgenv -p LCG_93 x86_64-slc6-gcc7-opt fastjet`"
#export PYTHIA8_HOME=/cvmfs/sft.cern.ch/lcg/external/MCGenerators_lcgcmt67c/pythia8/201/x86_64-slc6-gcc48-opt
export PYTHIA8_HOME=/cvmfs/cms.cern.ch/slc6_amd64_gcc700/external/pythia8/230-omkpbe4
LD_LIBRARY_PATH=$PYTHIA8_HOME/lib:$LD_LIBRARY_PATH

export G4INSTALL=/cvmfs/sft.cern.ch/lcg/releases/LCG_93/Geant4/10.04/x86_64-slc6-gcc7-opt/share/Geant4-10.4.0
export G4LEVELGAMMADATA=$G4INSTALL/data/PhotonEvaporation5.2
export G4NEUTRONXSDATA=$G4INSTALL/data/G4NEUTRONXS1.4
export G4LEDATA=$G4INSTALL/data/G4EMLOW7.3
export G4SAIDXSDATA=$G4INSTALL/data/G4SAIDDATA1.1
export G4RADIOACTIVEDATA=$G4INSTALL/data/RadioactiveDecay5.2
export G4NEUTRONHPDATA=$G4INSTALL/data/G4NDL4.5
export G4ENSDFSTATEDATA=$G4INSTALL/data/G4ENSDFSTATE2.2
