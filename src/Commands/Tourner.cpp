#include "Tourner.h"
#include "Robot.h"
#include <cmath>

Tourner::Tourner() : Command ("Tourner"){

	Requires(Robot::basePilotable.get());

	af=45;
	ai=0.5;
	vi=0.5;
	vf=0.3;
	pente=0;

}

// Called just before this Command runs the first time
void Tourner::Initialize() {

	frc::Preferences* prefs = frc::Preferences::GetInstance();

	Robot::basePilotable->GyroReset();

	vi = prefs->GetDouble("vi", 0.5);

	vf = prefs->GetDouble("vf", 0.3);

	ai = prefs->GetDouble("ai", 0.5);

	af = prefs->GetDouble("af", 0.5);

	pente = ((vf-vi)/(af-ai));

	if (af > 0) {
		vi = std::abs(vi);
	}
	else {
		vi = -1*std::abs(vi);
	}

}

// Called repeatedly when this Command is scheduled to run
void Tourner::Execute() {

	if(Robot::basePilotable->GetGyro() < ai){
		Robot::basePilotable->Tourner(vi);
	}
	else {

		Robot::basePilotable->Tourner( pente * (Robot::basePilotable->GetGyro() - ai) + vi);
	}
	SmartDashboard::PutNumber("angle", Robot::basePilotable->GetGyro());

}

// Make this return true when this Command no longer needs to run execute()
bool Tourner::IsFinished() {
	bool terminus;
	if(std::abs(Robot::basePilotable->GetGyro()) >= std::abs(af)){
		terminus = true;
	}
	else{
		terminus = false;
	}
	return terminus;
}

// Called once after isFinished returns true
void Tourner::End() {
	Robot::basePilotable->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Tourner::Interrupted() {
	End();
}
