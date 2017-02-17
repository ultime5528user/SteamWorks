#include "ShootOnce.h"
#include "Robot.h"


ShootOnce::ShootOnce() : Command("ShootOnce") {

	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void ShootOnce::Initialize() {
	Robot::shooter->Shoot(Shooter::VALEUR_INIT);

}

// Called repeatedly when this Command is scheduled to run
void ShootOnce::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ShootOnce::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootOnce::End() {
	Robot::shooter->ShootStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootOnce::Interrupted() {
	End();
}
