
#include "RemonteBalle.h"
#include "../RobotMap.h"
#include "Robot.h"

double RemonteBalle::VITESSE(-0.3);
double RemonteBalle::VITESSE_LENT(-0.23);

RemonteBalle::RemonteBalle() : Subsystem("RemonteBalle") {
	moteur = RobotMap::remonteBalleMoteur;
}

void RemonteBalle::InitDefaultCommand() {

}

void RemonteBalle::Monte(){
	moteur->Set(VITESSE);
}

void RemonteBalle::MonteLent()
{
	moteur->Set(VITESSE_LENT);
}

void RemonteBalle::Stop(){
	moteur->Set(0);
}

