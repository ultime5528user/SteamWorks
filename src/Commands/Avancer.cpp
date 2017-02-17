#include "Avancer.h"
#include <Robot.h>

Avancer::Avancer() : Avancer(1.0) { }

Avancer::Avancer(double dist) : Avancer(0, dist, 0, 0) {}

Avancer::Avancer(double di, double df, double vi, double vf) : Command("Avancer") {

	Requires(Robot::basePilotable.get());

	this->di = di;
	this->df = df;
	this->vi = vi;
	this->vf = vf;

	terminus = false;
	moyenne = 0.0;

	pente = (vf-vi)/(df-di);

}

// Called just before this Command runs the first time
void Avancer::Initialize() {

#ifdef DASHBOARD_VARIABLES

	if(vi == 0)
	{
		frc::Preferences* prefs = frc::Preferences::GetInstance();

		vi = prefs->GetDouble("vi", 0.5);
		vf = prefs->GetDouble("vf", 0.3);
		di = prefs->GetDouble("di", 0.8*df);
		df = prefs->GetDouble("df", df);
	}

#endif

	pente = ((vf-vi)/(df-di));

	moyenne = 0.0;

	Robot::basePilotable->EncoderReset();


}


// Called repeatedly when this Command is scheduled to run
void Avancer::Execute() {

	if(Robot::basePilotable->GetEncoderD() < di && Robot::basePilotable->GetEncoderG() < di){
		Robot::basePilotable->Avancer(vi);
	}
	else {
		moyenne = (Robot::basePilotable->GetEncoderD() + Robot::basePilotable->GetEncoderG()) / 2 ;
		Robot::basePilotable->Avancer( pente * (moyenne - di) + vi);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool Avancer::IsFinished() {

	if(Robot::basePilotable->GetEncoderD() >= df || Robot::basePilotable->GetEncoderG() >= df){
		terminus = true;
	}
	else {
		terminus = false;
	}
	return terminus;
}

// Called once after isFinished returns true
void Avancer::End() {
	Robot::basePilotable->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Avancer::Interrupted() {
	End();
}
