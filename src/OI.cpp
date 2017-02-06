// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include <Commands/TDescendre.h>
#include <Commands/TMonter.h>
#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Pilotage.h"
#include "Commands/SShootOnce.h"
#include "Commands/Capture.h"
#include "Commands/Avancer.h"
#include "Commands/Tourner.h"
#include "Commands/Shoot.h"
#include "Commands/StopShoot.h"

OI::OI() {

    stick.reset(new Joystick(0));


    bouton1.reset(new JoystickButton(stick.get(), 1));
    bouton1->WhenPressed(new Shoot());
    

    bouton2.reset(new JoystickButton(stick.get(), 2));
    bouton2->ToggleWhenPressed(new Capture());

    bouton3.reset(new JoystickButton(stick.get(), 3));
    bouton3->WhenPressed(new Avancer(1.0));

    bouton4.reset(new JoystickButton(stick.get(), 4));
    bouton4->WhenPressed(new Tourner());

    bouton5.reset(new JoystickButton(stick.get(), 5));
    bouton5->WhileHeld(new TMonter());

    bouton6.reset(new JoystickButton(stick.get(), 6));
    bouton6->WhenPressed(new TDescendre());


    SmartDashboard::PutData("Pilotage", new Pilotage());
    SmartDashboard::PutData("Avancer", new Avancer());
    SmartDashboard::PutData("Tourner", new Tourner());
    SmartDashboard::PutData(frc::Scheduler::GetInstance());

}


std::shared_ptr<Joystick> OI::getStick() {
   return stick;
}

