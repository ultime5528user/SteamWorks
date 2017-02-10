#include "Commands/MonterBalle.h"
#include "RemonteBalle.h"
#include "../RobotMap.h"
#include "Robot.h"

double RemonteBalle::VITESSE(0.5);

RemonteBalle::RemonteBalle() : Subsystem("RemonteBalle") {
	moteur = RobotMap::remonteBalleMoteur;
}

void RemonteBalle::InitDefaultCommand() {
    SetDefaultCommand(new MonterBalle());
}

void RemonteBalle::Monte(){
	moteur->Set(VITESSE);
}

void RemonteBalle::Stop(){
	moteur->Set(0);
}

