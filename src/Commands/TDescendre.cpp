#include "TDescendre.h"
#include "Robot.h"
#include "../Subsystems/Treuil.h"


TDescendre::TDescendre() : Command("TDescendre") {
	Requires(Robot::treuil.get());
}


void TDescendre::Initialize() {

	//Aucune méthode de Treuil disponible pour descendre?
	//Est-ce physiquement possible ?

}


void TDescendre::Execute() {

}


bool TDescendre::IsFinished() {
	return false;
}


void TDescendre::End() {
	Robot::treuil->Stop();
}


void TDescendre::Interrupted() {
	End();
}
