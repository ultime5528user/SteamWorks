#include "Shoot.h"
#include "Robot.h"
#include <cmath>
#include <Timer.h>
#include "../Subsystems/Shooter.h"

Shoot::Shoot()
{
	Requires(Robot::shooter.get());
	Requires(Robot::remonteBalle.get());

	setpoint = Shooter::VITESSE;

	getDB = true;
}

Shoot::Shoot(double setpoint) : Command("Shoot") {

	Requires(Robot::shooter.get());
	Requires(Robot::remonteBalle.get());

	this->setpoint = setpoint;
	getDB = false;

}

// Called just before this Command runs the first time
void Shoot::Initialize() {

#ifdef DASHBOARD_VARIABLES

    Shooter::VITESSE = frc::Preferences::GetInstance()->GetDouble("shoot_vitesse", 79.0);
    Shooter::THRESHOLD = frc::Preferences::GetInstance()->GetDouble("shoot_threshold", 5.0);
    Shooter::SERVO_OPEN = frc::Preferences::GetInstance()->GetDouble("servo_open", 150.0);
    Shooter::SERVO_CLOSE = frc::Preferences::GetInstance()->GetDouble("servo_close", 100.0);

#endif

    Robot::shooter->SetServoOpen();

    Robot::shooter->SetAbsoluteTolerance(Shooter::THRESHOLD);

    if(getDB)
    	setpoint = Shooter::VITESSE;


    Robot::shooter->SetSetpoint(setpoint);
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
