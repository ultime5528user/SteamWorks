#include "Shoot.h"
#include "Robot.h"
#include <cmath>
#include <Timer.h>
#include "../Subsystems/Shooter.h"

Shoot::Shoot() : Command("Shoot") {

	Requires(Robot::shooter.get());

	value = Shooter::VALEUR_INIT;
	ajust = false;
}

// Called just before this Command runs the first time
void Shoot::Initialize() {

#ifdef DASHBOARD_VARIABLES

    Shooter::VITESSE = frc::Preferences::GetInstance()->GetDouble("shoot_vitesse",0);
    Shooter::THRESHOLD = frc::Preferences::GetInstance()->GetDouble("shoot_threshold",0);
    Shooter::AJUST = frc::Preferences::GetInstance()->GetDouble("shoot_ajust",0);
    Shooter::INTERVAL_CLOSE = frc::Preferences::GetInstance()->GetDouble("interval_close",0);
    Shooter::INTERVAL_OPEN = frc::Preferences::GetInstance()->GetDouble("interval_open",0);
    Shooter::SERVO_OPEN = frc::Preferences::GetInstance()->GetDouble("servo_open", 70);
    Shooter::SERVO_CLOSE = frc::Preferences::GetInstance()->GetDouble("servo_close", 20);
#endif

    timer.Reset();

    Robot::shooter->SetServoOpen();

    Robot::shooter->SetAbsoluteTolerance(Shooter::THRESHOLD);
    Robot::shooter->SetSetpoint(Shooter::VITESSE);
    Robot::shooter->Enable();

}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	/*
	ajust = std::abs(Robot::shooter->GetEncoder() - Shooter::VITESSE) > Shooter::THRESHOLD;

	frc::SmartDashboard::PutBoolean("Ajust", ajust);

	if (ajust) {
		if (Robot::shooter->GetEncoder() < Shooter::VITESSE && value <= 1-Shooter::AJUST){
			value += Shooter::AJUST;
		}
		else {
			value -= Shooter::AJUST;
		}
	}
	else {
		Robot::shooter->SetServoOpen();
	}

	frc::SmartDashboard::PutNumber("Shooter value", value);
	frc::SmartDashboard::PutNumber("Encoder rate", Robot::shooter->GetEncoder());
*/
	/*
	else{
		timer.Start();
	}

	if (timer.Get() >= Shooter::INTERVAL_CLOSE){
		if (timer.Get() >= Shooter::INTERVAL_OPEN + Shooter::INTERVAL_CLOSE){
			Robot::shooter->SetServoClose();
			timer.Reset();
		}
		else
		{
			Robot::shooter->SetServoOpen();
		}
	}
*/
	//Robot::shooter->Shoot(value);


}
// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Shoot::End() {
	Robot::shooter->SetServoClose();
	//Robot::shooter->ShootStop();
	Robot::shooter->Disable();
	timer.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	End();
}
