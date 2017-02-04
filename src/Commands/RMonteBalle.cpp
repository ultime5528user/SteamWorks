#include "RMonteBalle.h"
#include "../Subsystems/RemonteBalle.h"
#include "Robot.h"

RMonteBalle::RMonteBalle() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void RMonteBalle::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RMonteBalle::Execute() {
	Robot::remonteBalle->Monte();
}

// Make this return true when this Command no longer needs to run execute()
bool RMonteBalle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RMonteBalle::End() {
	Robot::remonteBalle->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RMonteBalle::Interrupted() {
	End();
}
