#include "Tourner.h"
#include "Robot.h"
#include <cmath>

Tourner::Tourner() : Tourner(90) {}

Tourner::Tourner(double angle) : Command("Tourner")
{
	Requires(Robot::basePilotable.get());

	ai = 0;
	af = angle;
	vi = 0;
	vf = 0;

	pente = 0;

	getDB = true;
}

Tourner::Tourner(double ai, double af, double vi, double vf) : Command ("Tourner"){

	Requires(Robot::basePilotable.get());

	this->ai = ai;
	this->af = af;
	this->vi = vi;
	this->vf = vf;

	pente = 0;

	getDB = false;

}

// Called just before this Command runs the first time
void Tourner::Initialize() {


	Robot::basePilotable->GyroReset();


#ifdef DASHBOARD_VARIABLES

	if(getDB)
	{
		frc::Preferences* prefs = frc::Preferences::GetInstance();

		ai = prefs->GetDouble("ai", 0.8 * af);
		af = prefs->GetDouble("af", af);
		vi = prefs->GetDouble("vi", 0.5);
		vf = prefs->GetDouble("vf", 0.3);
	}


#endif


	pente = ((vf-vi)/(af-ai));

}

// Called repeatedly when this Command is scheduled to run
void Tourner::Execute() {

	if(std::abs(Robot::basePilotable->GetGyro()) < std::abs(ai)){
		Robot::basePilotable->Tourner(vi);
	}
	else {
		Robot::basePilotable->Tourner( pente * (Robot::basePilotable->GetGyro() - ai) + vi);
	}

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
