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

	SetTimeout(1);
}

// Called just before this Command runs the first time
void Viser::Initialize( ) {

#ifdef DASHBOARD_VARIABLES

	frc::Preferences* prefs = frc::Preferences::GetInstance();

	grip::GripPipeline::H_MIN = prefs->GetDouble("h_min", 70.0);
	grip::GripPipeline::H_MAX = prefs->GetDouble("h_max", 80.0);
	grip::GripPipeline::S_MIN = prefs->GetDouble("s_min", 230.0);
	grip::GripPipeline::S_MAX = prefs->GetDouble("s_max", 255.0);
	grip::GripPipeline::V_MIN = prefs->GetDouble("v_min", 40.0);
	grip::GripPipeline::V_MAX = prefs->GetDouble("v_max", 255.0);

	Camera::EXPOSURE = (int)prefs->GetDouble("exposure", 0);
	Camera::WIDTH_THRESHOLD = prefs->GetDouble("width_threshold", 5.0);
	Camera::X_THRESHOLD = prefs->GetDouble("x_threshold", 0.1);

	BasePilotable::B_TURN = prefs->GetDouble("b_turn", 0.0);
	BasePilotable::K_MOVE = prefs->GetDouble("k_move", 0.0);
	BasePilotable::K_TURN = prefs->GetDouble("k_turn", 0.0);

	BasePilotable::DI_MOVE = prefs->GetDouble("di_move", 0.2);
	BasePilotable::A_MOVE = prefs->GetDouble("a_move", 0.1);


	BasePilotable::ACCEL_THRESHOLD = prefs->GetDouble("accel_threshold", 100);

	Camera::OFFSET = prefs->GetDouble("offset", 0.4);

#endif

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

	double move(0.0), turn(0.0);

	centreX -= Camera::OFFSET;

	if(std::abs(centreX) > Camera::X_THRESHOLD){
		turn = centreX * BasePilotable::K_TURN + (centreX > 0 ? 1.0 : -1.0) * BasePilotable::B_TURN;
	}
	else {
		turn = 0;
	}

	if(largeur == 0) {
		move = 0;
	}
	else if(largeur < BasePilotable::DI_MOVE) {
		move = BasePilotable::K_MOVE;
	}
	else {
		move = BasePilotable::A_MOVE/(largeur - (BasePilotable::DI_MOVE - BasePilotable::A_MOVE / BasePilotable::K_MOVE));
	}

	Robot::basePilotable->Drive(move, turn);

	frc::SmartDashboard::PutNumber("Centre X", centreX);
	//frc::SmartDashboard::PutNumber("Largeur particule", largeur);
	frc::SmartDashboard::PutNumber("X_Threshold", Camera::X_THRESHOLD);
	frc::SmartDashboard::PutNumber("Width threshold", Camera::WIDTH_THRESHOLD);
	frc::SmartDashboard::PutNumber("Move", move);
	frc::SmartDashboard::PutNumber("Turn", turn);
	frc::SmartDashboard::PutNumber("DI_MOVE", BasePilotable::DI_MOVE);
	frc::SmartDashboard::PutNumber("A_MOVE", BasePilotable::A_MOVE);

}

// Make this return true when this Command no longer needs to run execute()
bool Viser::IsFinished() {

	double largeur;
	{
		std::lock_guard<priority_mutex> lock(mutex);
		largeur = m_largeur;
	}

	frc::SmartDashboard::PutNumber("Largeur particulue", largeur);
	frc::SmartDashboard::PutNumber("Accel_Threshold", BasePilotable::ACCEL_THRESHOLD);

	return (largeur > BasePilotable::ACCEL_THRESHOLD) && IsTimedOut();
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
