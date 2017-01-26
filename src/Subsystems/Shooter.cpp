#include "Shooter.h"
#include "../RobotMap.h"

double Shooter::SHOOT_VALUE(0);


Shooter::Shooter() : Subsystem("Shooter") {
	moteur = RobotMap::shooterMoteur;
	encoder = RobotMap::shooterEncoder;
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Shooter::Shoot() {
	moteur->Set(SHOOT_VALUE);
}


void Shooter::ShootStop() {
	moteur->Set(0);
}

double Shooter::GetEncoder(){
	return encoder->GetRate();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
