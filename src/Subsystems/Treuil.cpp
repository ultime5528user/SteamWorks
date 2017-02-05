#include <Subsystems/Treuil.h>
#include "../RobotMap.h"

Treuil::Treuil() : Subsystem("Treuil") {
	moteur = RobotMap::treuilMoteur;
}

void Treuil::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Treuil::TreuilMoteur(){
	moteur->Set(0.5);
}

void Treuil::TreuilMaintien(){
	moteur->Set(0.15);
}

void Treuil::TreuilStop(){
	moteur->Set(0.08);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
