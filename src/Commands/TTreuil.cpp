#include "TTreuil.h"
#include "Robot.h"
#include "../Subsystems/Treuil.h"
TTreuil::TTreuil() {


	Requires(Robot::treuil.get());
}

// Called just before this Command runs the first time
void TTreuil::Initialize() {


}

// Called repeatedly when this Command is scheduled to run
void TTreuil::Execute() {
	Robot::treuil->TreuilMoteur();
}

// Make this return true when this Command no longer needs to run execute()
bool TTreuil::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TTreuil::End() {
	Robot::treuil->TreuilMaintien();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TTreuil::Interrupted() {
	Robot::treuil->TreuilStop();
}
