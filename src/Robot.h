// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Subsystems/Shooter.h"
#include "Subsystems/BasePilotable.h"
#include "Subsystems/Camera.h"

#include "OI.h"

class Robot : public IterativeRobot {
private:
	Preferences *prefs;
public:
	std::unique_ptr<Command> autonomousCommand;
	LiveWindow *lw = LiveWindow::GetInstance();

	static std::unique_ptr<OI> oi;

    static std::shared_ptr<BasePilotable> basePilotable;
    static std::shared_ptr<Shooter> shooter;
    static std::shared_ptr<Camera> camera;


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
