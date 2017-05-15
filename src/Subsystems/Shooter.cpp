#include "Shooter.h"
#include "../RobotMap.h"

double Shooter::VITESSE(84.0);
double Shooter::THRESHOLD(5.0);
double Shooter::VALEUR_INIT(0.75);
double Shooter::SERVO_OPEN(150);
double Shooter::SERVO_CLOSE(100);
double Shooter::VALEUR_UNLOAD(-0.27);

Shooter::Shooter() : PIDSubsystem("Shooter", 0.005, 0.002, 0.0) {

	moteur = RobotMap::shooterMoteur;
	encoder = RobotMap::shooterEncoder;
	servo = RobotMap::shooterServo;

	SetAbsoluteTolerance(5.5);
	SetInputRange(0.0, 100.0);
	SetOutputRange(-1.0, 1.0);

	GetPIDController()->SetContinuous(false);
	frc::LiveWindow::GetInstance()->AddActuator("Shooter", "PID Controller", GetPIDController());

	Disable();
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
	return encoder->GetRate();
}

void Shooter::SetServoOpen(){
	servo->SetAngle(SERVO_OPEN);
}
void Shooter::SetServoClose(){
	servo->SetAngle(SERVO_CLOSE);
}

double Shooter::ReturnPIDInput()
{
	frc::SmartDashboard::PutNumber("Shooter rate", encoder->GetRate()); 					//À ENLEVER
	return encoder->GetRate();
}

void Shooter::UsePIDOutput(double output)
{
	frc::SmartDashboard::PutNumber("Shooter PID Output", output); 					//À ENLEVER
	moteur->Set(output);
}


