#include "Shoot.h"
#include "Robot.h"
#include <cmath>
#include <Timer.h>
#include "../Subsystems/Shooter.h"

Shoot::Shoot() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::shooter.get());
	value = Shooter::MOTEUR;
	ajust = false;
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
    Shooter::SHOOT_VALUE = frc::Preferences::GetInstance()->GetDouble("ShooterValue",0);
    Shooter::THRESHOLD = frc::Preferences::GetInstance()->GetDouble("Threshold",0);
    Shooter::AJUST = frc::Preferences::GetInstance()->GetDouble("AjustementShooter",0);
    Shooter::INTERVAL_CLOSE = frc::Preferences::GetInstance()->GetDouble("Interval_Close",0);
    Shooter::INTERVAL_OPEN = frc::Preferences::GetInstance()->GetDouble("Interval_Open",0);
    Shooter::SERVO_OPEN = frc::Preferences::GetInstance()->GetDouble("Servo_open",0);
    Shooter::SERVO_CLOSE = frc::Preferences::GetInstance()->GetDouble("Servo_close",0);
    timer.Reset();
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	ajust = std::abs(Robot::shooter->GetEncoder() - Shooter::SHOOT_VALUE) > Shooter::THRESHOLD;
	if (ajust){
		if (Robot::shooter->GetEncoder() < Shooter::SHOOT_VALUE && value <= 1-Shooter::AJUST){
			value += Shooter::AJUST;
		}
		else {
			value -= Shooter::AJUST;
		}
	}
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
	Robot::shooter->ServoMove();



	Robot::shooter->Shoot(value);


}
// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Shoot::End() {
	Robot::shooter->ShootStop();
	timer.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	End();
}
