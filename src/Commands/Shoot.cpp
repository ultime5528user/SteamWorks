#include "Shoot.h"
#include "Robot.h"
#include <cmath>
#include <Timer.h>

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
    Shooter::INTERVAL = frc::Preferences::GetInstance()->GetDouble("Interval_de_tire",0);
    Shooter::SERVO_UP = frc::Preferences::GetInstance()->GetDouble("Servo_up",0);
    Shooter::SERVO_DOWN = frc::Preferences::GetInstance()->GetDouble("Servo_down",0);
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

	if (timer.Get() >= Shooter::INTERVAL){
		if (timer.Get() >= 1.2*Shooter::INTERVAL){
			servo.SetAngle(Shooter::SERVO_DOWN);
			timer.Reset();
		}
		else
		{
			servo.SetAngle(Shooter::SERVO_UP);
		}
	}

	servo.SetAngle(servo.GetAngle());

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
