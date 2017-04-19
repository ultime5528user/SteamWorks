#include "Shooter.h"
#include "../RobotMap.h"

double Shooter::VITESSE(79.0);
double Shooter::THRESHOLD(5.0);
double Shooter::VALEUR_INIT(0.75);
double Shooter::SERVO_OPEN(150);
double Shooter::SERVO_CLOSE(100);
double Shooter::VALEUR_UNLOAD(-0.27);

Shooter::Shooter() : Subsystem("Shooter") {

	moteur = RobotMap::shooterMoteur;
	servo = RobotMap::shooterServo;

	moteur->SetPID(0, 0, 0, 0);
	moteur->SelectProfileSlot(0);
	moteur->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	moteur->SetControlMode(CANTalon::ControlMode::kPercentVbus);


	SetServoClose();
}

void Shooter::InitDefaultCommand() {

}


void Shooter::Shoot(double value) {
	moteur->Set(value);
}


void Shooter::ShootStop() {
	moteur->Set(0);
}

double Shooter::GetEncoder(){
	return moteur->GetSpeed();
}

void Shooter::SetServoOpen(){
	servo->SetAngle(SERVO_OPEN);
}

void Shooter::SetServoClose(){
	servo->SetAngle(SERVO_CLOSE);
}

void Shooter::Disable() {
	moteur->Disable();
}



