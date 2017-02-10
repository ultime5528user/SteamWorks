#include <Commands/Viser.h>
#include <Robot.h>
#include <cmath>

Viser::Viser():
	Command("Viser"),
	m_centreX(0.0),
	m_largeur(0.0)
{

	Requires(Robot::camera.get());
	Requires(Robot::basePilotable.get());
}

// Called just before this Command runs the first time
void Viser::Initialize( ) {

	frc::Preferences* prefs = frc::Preferences::GetInstance();

	grip::GripPipeline::H_MIN = prefs->GetDouble("hmin", 61);
	grip::GripPipeline::H_MAX = prefs->GetDouble("hmax", 80.0);
	grip::GripPipeline::S_MIN = prefs->GetDouble("smin", 241.0);
	grip::GripPipeline::S_MAX = prefs->GetDouble("smax", 255.0);
	grip::GripPipeline::V_MIN = prefs->GetDouble("vmin", 96.0);
	grip::GripPipeline::V_MAX = prefs->GetDouble("vmax", 190.0);

	Camera::EXPOSURE = (int)prefs->GetDouble("exposure", 0);
	Camera::WIDTH_THRESHOLD = prefs->GetDouble("width_threshold");
	Camera::X_THRESHOLD = prefs->GetDouble("x_threshold");
	BasePilotable::B_MOVE = prefs->GetDouble("b_move");
	BasePilotable::B_TURN = prefs->GetDouble("b_turn");
	BasePilotable::K_MOVE = prefs->GetDouble("k_move");
	BasePilotable::K_TURN = prefs->GetDouble("k_turn");

	Robot::camera->StartGrip(&Viser::SetParam, this);
}

// Called repeatedly when this Command is scheduled to run
void Viser::Execute() {

	double centreX, largeur;

	{
		std::lock_guard<priority_mutex> lock(mutex);
		centreX = m_centreX;
		largeur = m_largeur;
	}

	double move, turn;

	if(abs(centreX) > Camera::X_THRESHOLD){
		turn = centreX*BasePilotable::K_TURN + BasePilotable::B_TURN;
	}
	else {
		turn = 0;
	}

	if(largeur <= Camera::WIDTH_THRESHOLD){
		move = BasePilotable::K_MOVE/largeur + BasePilotable::B_MOVE;
	}
	else {
		move = 0;
	}






	Robot::basePilotable->Drive(move, turn);
	//Coeur de la commande

	frc::SmartDashboard::PutNumber("Centre X", centreX);
	frc::SmartDashboard::PutNumber("Largeur particule", largeur);

}

// Make this return true when this Command no longer needs to run execute()
bool Viser::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Viser::End() {
	Robot::camera->EndGrip();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Viser::Interrupted() {
	End();
}

void Viser::SetParam(double centreX, double largeur)
{
	std::lock_guard<priority_mutex> lock(mutex);
	m_centreX = centreX;
	m_largeur = largeur;
}
