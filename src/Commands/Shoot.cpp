#include "Shoot.h"
#include "Robot.h"
#include <cmath>
#include <Timer.h>
#include "../Subsystems/Shooter.h"

Shoot::Shoot() : Command("Shoot") {

	Requires(Robot::shooter.get());
	Requires(Robot::remonteBalle.get());

}

// Called just before this Command runs the first time
void Shoot::Initialize() {

#ifdef DASHBOARD_VARIABLES

    Shooter::VITESSE = frc::Preferences::GetInstance()->GetDouble("shoot_vitesse", -0.3);
    Shooter::THRESHOLD = frc::Preferences::GetInstance()->GetDouble("shoot_threshold",0);
    Shooter::AJUST = frc::Preferences::GetInstance()->GetDouble("shoot_ajust",0);
    Shooter::INTERVAL_CLOSE = frc::Preferences::GetInstance()->GetDouble("interval_close",0);
    Shooter::INTERVAL_OPEN = frc::Preferences::GetInstance()->GetDouble("interval_open",0);
    Shooter::SERVO_OPEN = frc::Preferences::GetInstance()->GetDouble("servo_open", 70);
    Shooter::SERVO_CLOSE = frc::Preferences::GetInstance()->GetDouble("servo_close", 20);

#endif

    Robot::shooter->SetServoOpen();

    Robot::shooter->SetAbsoluteTolerance(Shooter::THRESHOLD);
    Robot::shooter->SetSetpoint(Shooter::VITESSE);
    Robot::shooter->Enable();

}



void Shoot::Execute() {
	Robot::remonteBalle->Monte();
}



bool Shoot::IsFinished() {
	return false;
}



void Shoot::End() {
	Robot::shooter->SetServoClose();
	Robot::shooter->Disable();
	Robot::remonteBalle->Stop();
}



void Shoot::Interrupted() {
	End();
}
