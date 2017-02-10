// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Robot.h"

std::shared_ptr<BasePilotable> Robot::basePilotable;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Camera> Robot::camera;

std::shared_ptr<Treuil> Robot::treuil;

std::shared_ptr<RemonteBalle> Robot::remonteBalle;

std::unique_ptr<OI> Robot::oi;


void Robot::RobotInit() {
	RobotMap::init();

	basePilotable.reset(new BasePilotable());
	shooter.reset (new Shooter());
	camera.reset(new Camera());
	treuil.reset(new Treuil());
	remonteBalle.reset(new RemonteBalle());
  
	prefs = Preferences::GetInstance();

	oi.reset(new OI());
	
}


void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {

	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

