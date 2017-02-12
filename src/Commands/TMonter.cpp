#include "TMonter.h"
#include "Robot.h"
#include "../Subsystems/Treuil.h"


TMonter::TMonter() : Command("TMonter") {

	Requires(Robot::treuil.get());

}



// Called just before this Command runs the first time
void TMonter::Initialize() {

#ifdef SMARTDASHBOARD_VARIABLES
	Treuil::VALEUR_MONTER = frc::Preferences::GetInstance()->GetDouble("treuil_monter", 1);
#endif

	Robot::treuil->Monter();

}

// Called repeatedly when this Command is scheduled to run
void TMonter::Execute() {
	Robot::treuil->Monter();
}

// Make this return true when this Command no longer needs to run execute()
bool TMonter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TMonter::End() {
	Robot::treuil->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TMonter::Interrupted() {
	End();
}
