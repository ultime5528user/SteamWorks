#include "Avancer.h"
#include <Robot.h>




Avancer::Avancer(double dist) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::basePilotable.get());
	distance=dist;
	terminus=false;

	pente = ((vmin-vi)/(d*(1-p)));
}

// Called just before this Command runs the first time
void Avancer::Initialize() {

	frc::Preferences* prefs = frc::Preferences::GetInstance();

	vi = prefs->GetDouble("vi", 0.5);

	vmin = prefs->GetDouble("vmin", 0.5);

	p = prefs->GetDouble("p", 0.8);

	d = prefs->GetDouble("d", 0.5);



}//cancer


// Called repeatedly when this Command is scheduled to run
void Avancer::Execute() {
	if(Robot::basePilotable->GetEncoderD() < (p*d)|| Robot::basePilotable->GetEncoderG()< (p*d)){
		Robot::basePilotable->SetMoteur(vi);
	}
	else{
		Robot::basePilotable->SetMoteur(pente*((Robot::basePilotable->GetEncoderD()+Robot::basePilotable->GetEncoderG())/2)+((vi-p*vmin)/(1-p)));
	}

}

// Make this return true when this Command no longer needs to run execute()
bool Avancer::IsFinished() {
	if(Robot::basePilotable->GetEncoderD() >= distance || Robot::basePilotable->GetEncoderG() >= distance){
		terminus = true;
	}
	else{
		terminus = false;
	}
	return terminus;
}

// Called once after isFinished returns true
void Avancer::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Avancer::Interrupted() {

}
