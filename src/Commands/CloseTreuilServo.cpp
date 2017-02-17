#include "CloseTreuilServo.h"
#include "Robot.h"

CloseTreuilServo::CloseTreuilServo() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::treuil.get());
}

// Called just before this Command runs the first time
void CloseTreuilServo::Initialize() {

#ifdef DASHBOARD_VARIABLES

	Treuil::SERVO_CLOSE = frc::Preferences::GetInstance()->GetDouble("treuil_servo_close", 0);

#endif

	Robot::treuil->SetServoClose();
}

// Called repeatedly when this Command is scheduled to run
void CloseTreuilServo::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool CloseTreuilServo::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void CloseTreuilServo::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseTreuilServo::Interrupted() {

}
