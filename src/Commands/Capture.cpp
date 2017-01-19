#include "Capture.h"

Capture::Capture(): Command("Capture") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires (Robot::camera.get());
}

// Called just before this Command runs the first time
void Capture::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Capture::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Capture::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Capture::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Capture::Interrupted() {

}
