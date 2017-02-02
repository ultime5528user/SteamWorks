#include "Shooter.h"
#include "../RobotMap.h"

double Shooter::SHOOT_VALUE(0);
double Shooter::THRESHOLD(10);
double Shooter::MOTEUR(0.75);
double Shooter::AJUST(0.05);
double Shooter::INTERVAL(1);
double Shooter::SERVO_UP(90);
double Shooter::SERVO_DOWN(90);


Shooter::Shooter() : Subsystem("Shooter") {
	moteur = RobotMap::shooterMoteur;
	encoder = RobotMap::shooterEncoder;
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Shooter::Shoot(double value) {
	moteur->Set(value);
}


void Shooter::ShootStop() {
	moteur->Set(0);
}

double Shooter::GetEncoder(){
	return encoder->GetRate();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
