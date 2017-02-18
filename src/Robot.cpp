// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include <Commands/AutoGearBleuDroite.h>
#include <Commands/AutoGearRougeGauche.h>
#include <Robot.h>
#include "Commands/AutoBallesGearRouge.h"
#include "Commands/AutoBallesGearBleu.h"



std::shared_ptr<BasePilotable> Robot::basePilotable;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Camera> Robot::camera;

std::shared_ptr<Treuil> Robot::treuil;

std::shared_ptr<RemonteBalle> Robot::remonteBalle;

std::unique_ptr<OI> Robot::oi;


void Robot::RobotInit() {

#ifdef DASHBOARD_VARIABLES
	frc::DriverStation::ReportError("DASHBOARD_VARIABLES is defined.");
#endif

	RobotMap::init();

	basePilotable.reset(new BasePilotable());
	shooter.reset (new Shooter());
	camera.reset(new Camera());
	treuil.reset(new Treuil());
	remonteBalle.reset(new RemonteBalle());
  
	prefs = Preferences::GetInstance();

	oi.reset(new OI());
	
	chooser.AddDefault("No_Motion" , nullptr);
	chooser.AddObject("Porter_Gear_Devant", new Viser());
	chooser.AddObject("Auto_Balles_Gear_Rouge", new AutoBallesGearRouge());
	chooser.AddObject("Auto_Balles_Gear_Bleu", new AutoBallesGearBleu());
	chooser.AddObject("Auto_Gear_Bleu_Droite", new AutoGearBleuDroite());
	chooser.AddObject("Auto_Gear_Rouge_Gauche", new AutoGearRougeGauche());

	frc::SmartDashboard::PutData("Modes autonomes", &chooser);


}



void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {

	autonomousCommand.reset(chooser.GetSelected());

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}


void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

}

void Robot::TeleopPeriodic() {

	frc::SmartDashboard::PutNumber("Encodeur Gauche", basePilotable->GetEncoderG());
	frc::SmartDashboard::PutNumber("Encodeur Droite", basePilotable->GetEncoderD());
	frc::SmartDashboard::PutNumber("Angle X", basePilotable->GetGyro());
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

