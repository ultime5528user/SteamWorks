// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<SpeedController> RobotMap::basePilotableMoteurG;
std::shared_ptr<SpeedController> RobotMap::basePilotableMoteurD;
std::shared_ptr<RobotDrive> RobotMap::basePilotableRobotDrive;
std::shared_ptr<SpeedController> RobotMap::shooterMoteur;
std::shared_ptr<Spark> RobotMap::cameraLight;

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    basePilotableMoteurG.reset(new VictorSP(0));
    lw->AddActuator("BasePilotable", "MoteurG", std::static_pointer_cast<VictorSP>(basePilotableMoteurG));
    
    basePilotableMoteurD.reset(new VictorSP(1));
    lw->AddActuator("BasePilotable", "MoteurD", std::static_pointer_cast<VictorSP>(basePilotableMoteurD));
    
    basePilotableRobotDrive.reset(new RobotDrive(basePilotableMoteurG, basePilotableMoteurD));
    
    basePilotableRobotDrive->SetSafetyEnabled(true);
        basePilotableRobotDrive->SetExpiration(0.1);
        basePilotableRobotDrive->SetSensitivity(0.5);
        basePilotableRobotDrive->SetMaxOutput(1.0);
        basePilotableRobotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
        basePilotableRobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
    

    shooterMoteur.reset(new VictorSP(4));
    lw->AddActuator("Shooter", "Moteur", std::static_pointer_cast<VictorSP>(shooterMoteur));

    cameraLight.reset(new Spark(9));
    lw->AddActuator("Camera", "Light", cameraLight);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
