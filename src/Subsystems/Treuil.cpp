#include <Subsystems/Treuil.h>
#include "../RobotMap.h"
#include "Robot.h"
#include "RobotBase.h"

double Treuil::VALEUR_MONTER(1);
double Treuil::VALEUR_MAINTIEN(0.15);

Treuil::Treuil() : Subsystem("Treuil") {
	moteur = RobotMap::treuilMoteur;
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
