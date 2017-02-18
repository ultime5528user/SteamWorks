#include <Commands/MonterBalle.h>
#include "../Subsystems/RemonteBalle.h"
#include "Robot.h"
#include "RobotMap.h"

MonterBalle::MonterBalle() : Command("MonterBalle") {

	Requires(Robot::remonteBalle.get());

}

// Called just before this Command runs the first time
void MonterBalle::Initialize() {

#ifdef DASHBOARD_VARIABLES
	RemonteBalle::VITESSE_LENT = frc::Preferences::GetInstance()->GetDouble("vitesse_remonte_lent", -0.23);
#endif
}

// Called repeatedly when this Command is scheduled to run
void MonterBalle::Execute() {
	Robot::remonteBalle->MonteLent();
}

// Make this return true when this Command no longer needs to run execute()
bool MonterBalle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MonterBalle::End() {
	Robot::remonteBalle->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MonterBalle::Interrupted() {
	End();
}
