#include "Avancer.h"
#include <Robot.h>

Avancer::Avancer() : Avancer(1.0)
{

}

Avancer::Avancer(double dist) : Command("Avancer") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::basePilotable.get());
	df=dist;
	terminus=false;
	moyenne = 0;
	di=0.5;
	vf=0.3;
	vi=0.5;
	calc=0;
	pente=(vf-vi/df-di);



}

// Called just before this Command runs the first time
void Avancer::Initialize() {

	frc::Preferences* prefs = frc::Preferences::GetInstance();

	vi = prefs->GetDouble("vi", 0.5);

	vf = prefs->GetDouble("vf", 0.3);

	di = prefs->GetDouble("di", 0.5);

	df = prefs->GetDouble("df", 0.5);

	pente = ((vf-vi)/(df-di));

	moyenne = 0.0;

	calc = (moyenne-di);
	Robot::basePilotable->EncoderReset();


}//cancer


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
	else{
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
