#include "RemonteBalle.h"
#include "../RobotMap.h"
#include "../Commands/RMonteBalle.h"

RemonteBalle::RemonteBalle() : Subsystem("ExampleSubsystem") {

}

void RemonteBalle::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new RMonteBalle());
}

void RemonteBalle::Monte(){
	Remonte->Set(0.5);
}

void RemonteBalle::Stop(){
	Remonte->Set(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
