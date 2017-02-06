#include "TMaintien.h"
#include "Robot.h"
#include "../Subsystems/Treuil.h"

TMaintien::TMaintien() {
	Requires(Robot::treuil.get());
}

// Called just before this Command runs the first time
void TMaintien::Initialize() {
	Robot::treuil->TreuilMaintien();
}

// Called repeatedly when this Command is scheduled to run
void TMaintien::Execute() {
	Robot::treuil->TreuilMaintien();
}

// Make this return true when this Command no longer needs to run execute()
bool TMaintien::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TMaintien::End() {
	Robot::treuil->TreuilStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TMaintien::Interrupted() {
	End();
}
