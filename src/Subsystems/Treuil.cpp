#include <Subsystems/Treuil.h>
#include "../RobotMap.h"
#include "Robot.h"
#include "RobotBase.h"

double Treuil::VALEUR_MONTER(1.0);

double Treuil::SERVO_OPEN(170.0);
double Treuil::SERVO_CLOSE(65.0);


Treuil::Treuil() : Subsystem("Treuil") {

	moteur = RobotMap::treuilMoteur;
	servo = RobotMap::treuilServo;

	SetServoOpen();
}

void Treuil::InitDefaultCommand() {

}

void Treuil::Monter(){
	moteur->Set(VALEUR_MONTER);
}

void Treuil::Stop(){
	moteur->Set(0);
}

void Treuil::SetServoOpen()
{
	frc::SmartDashboard::PutBoolean("Servo treuil", true);
	servo->SetAngle(SERVO_OPEN);
}

void Treuil::SetServoClose()
{
	frc::SmartDashboard::PutBoolean("Servo treuil", false);
	servo->SetAngle(SERVO_CLOSE);
}
