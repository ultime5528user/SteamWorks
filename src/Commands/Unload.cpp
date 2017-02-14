#include "Unload.h"

#include "Robot.h"

Unload::Unload() {
	Requires(Robot::shooter.get());
	SetTimeout(0.25);
}


void Unload::Initialize() {

#ifdef DASHBOARD_VARIABLES
	Shooter::VALEUR_UNLOAD = frc::Preferences::GetInstance()->GetDouble("shooter_unload", -0.3);
#endif

}


void Unload::Execute() {
	Robot::shooter->Shoot(Shooter::VALEUR_UNLOAD);
}

// Make this return true when this Command no longer needs to run execute()
bool Unload::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Unload::End() {
	Robot::shooter->ShootStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Unload::Interrupted() {
	End();
}
