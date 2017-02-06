#include "TDescendre.h"
#include "Robot.h"
#include "../Subsystems/Treuil.h"
TDescendre::TDescendre() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::treuil.get());
}

// Called just before this Command runs the first time
void TDescendre::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TDescendre::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TDescendre::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void TDescendre::End() {
	Robot::treuil->TreuilStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TDescendre::Interrupted() {
	End();
}
