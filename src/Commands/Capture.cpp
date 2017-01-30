#include "Capture.h"
#include <Robot.h>

Capture::Capture(): Command("Capture") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires (Robot::camera.get());
}

// Called just before this Command runs the first time
void Capture::Initialize( ) {

	frc::Preferences* prefs = frc::Preferences::GetInstance();

	grip::GripPipeline::H_MIN = prefs->GetDouble("hmin", 61);
	grip::GripPipeline::H_MAX = prefs->GetDouble("hmax", 80.0);
	grip::GripPipeline::S_MIN = prefs->GetDouble("smin", 241.0);
	grip::GripPipeline::S_MAX = prefs->GetDouble("smax", 255.0);
	grip::GripPipeline::V_MIN = prefs->GetDouble("vmin", 96.0);
	grip::GripPipeline::V_MAX = prefs->GetDouble("vmax", 190.0);
	Camera::EXPOSURE = (int)prefs->GetDouble("exposure", 0);

	Robot::camera->StartGrip();
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
	Robot::camera->EndGrip();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Capture::Interrupted() {
	End();
}
