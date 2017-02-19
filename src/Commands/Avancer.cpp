#include "Avancer.h"
#include <Robot.h>

Avancer::Avancer() : Avancer(1.0) { }

Avancer::Avancer(double dist) : Command("Avancer")
{
	Requires(Robot::basePilotable.get());

	di = 0;
	df = dist;
	vi = 0;
	vf = 0;

	pente = 0;
	moyenne = 0;

	getDB = true;
}

Avancer::Avancer(double di, double df, double vi, double vf, double timeout) : Command("Avancer") {

	Requires(Robot::basePilotable.get());

	this->di = di;
	this->df = df;
	this->vi = vi;
	this->vf = vf;

	moyenne = 0.0;

	pente = (vf-vi)/(df-di);

	getDB = false;

	if(timeout >= 0.05)
		SetTimeout(timeout);

}

// Called just before this Command runs the first time
void Avancer::Initialize() {

#ifdef DASHBOARD_VARIABLES

	if(getDB)
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

	if(std::abs(Robot::basePilotable->GetEncoderD()) < std::abs(di) || std::abs(Robot::basePilotable->GetEncoderG()) < std::abs(di)){
		Robot::basePilotable->Avancer(vi);
	}
	else {
		moyenne = (Robot::basePilotable->GetEncoderD() + Robot::basePilotable->GetEncoderG()) / 2 ;
		Robot::basePilotable->Avancer( pente * (moyenne - di) + vi);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool Avancer::IsFinished() {

	return std::abs(Robot::basePilotable->GetEncoderD()) >= std::abs(df) || std::abs(Robot::basePilotable->GetEncoderG()) >= std::abs(df) || IsTimedOut();

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
