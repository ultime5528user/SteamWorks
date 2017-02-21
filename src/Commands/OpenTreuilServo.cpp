#include "OpenTreuilServo.h"
#include "Robot.h"

OpenTreuilServo::OpenTreuilServo() {
	Requires(Robot::treuil.get());
}

// Called just before this Command runs the first time
void OpenTreuilServo::Initialize() {

#ifdef DASHBOARD_VARIABLES

	Treuil::SERVO_OPEN = frc::Preferences::GetInstance()->GetDouble("treuil_servo_open", 170.0);

#endif

	Robot::treuil->SetServoOpen();
}

// Called repeatedly when this Command is scheduled to run
void OpenTreuilServo::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool OpenTreuilServo::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void OpenTreuilServo::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenTreuilServo::Interrupted() {

}
