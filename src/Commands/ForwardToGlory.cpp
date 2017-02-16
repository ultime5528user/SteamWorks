#include "ForwardToGlory.h"
#include "Avancer.h"
ForwardToGlory::ForwardToGlory() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	cancer = 2.4;
}

// Called just before this Command runs the first time
void ForwardToGlory::Initialize() {
	Avancer(cancer); //ceci n'est pas le cancer que vous chercher
}

// Called repeatedly when this Command is scheduled to run
void ForwardToGlory::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ForwardToGlory::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ForwardToGlory::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForwardToGlory::Interrupted() {

}
