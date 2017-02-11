#include "Shooter.h"
#include "../RobotMap.h"

double Shooter::VITESSE(0);
double Shooter::THRESHOLD(10);
double Shooter::VALEUR_INIT(0.75);
double Shooter::AJUST(0.05);
double Shooter::INTERVAL_CLOSE(1);
double Shooter::INTERVAL_OPEN(0.2);
double Shooter::SERVO_OPEN(100);
double Shooter::SERVO_CLOSE(90);

Shooter::Shooter() : Subsystem("Shooter") {
	moteur = RobotMap::shooterMoteur;
	encoder = RobotMap::shooterEncoder;
	servo = RobotMap::shooterServo;
	servoPosition = SERVO_CLOSE;
}

void Shooter::InitDefaultCommand() {

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

void Shooter::SetServoOpen(){
	servo->SetAngle(SERVO_OPEN);
}
void Shooter::SetServoClose(){
	servo->SetAngle(SERVO_CLOSE);
}



