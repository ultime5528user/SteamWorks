#include "TMonter.h"
#include "Robot.h"
#include "../Subsystems/Treuil.h"

TMonter::TMonter() {


	Requires(Robot::treuil.get());
}

// Called just before this Command runs the first time
void TMonter::Initialize() {
	Robot::treuil->TreuilMoteur();

}

// Called repeatedly when this Command is scheduled to run
void TMonter::Execute() {
	Robot::treuil->TreuilMoteur();
}

// Make this return true when this Command no longer needs to run execute()
bool TMonter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TMonter::End() {
	Robot::treuil->TreuilStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TMonter::Interrupted() {
	End();
}
