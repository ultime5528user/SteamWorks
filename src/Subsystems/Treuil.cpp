#include <Subsystems/Treuil.h>
#include "../RobotMap.h"
#include "Robot.h"
#include "RobotBase.h"

double Treuil::VALEUR_MONTER(1);
double Treuil::VALEUR_MAINTIEN(0.15);

double Treuil::SERVO_OPEN(0.0);
double Treuil::SERVO_CLOSE(90.0);


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

void Treuil::Maintien(){
	moteur->Set(VALEUR_MAINTIEN);
}

void Treuil::Stop(){
	moteur->Set(0);
}

void Treuil::SetServoOpen()
{
	servo->Set(SERVO_OPEN);
}

void Treuil::SetServoClose()
{
	servo->Set(SERVO_CLOSE);
}
