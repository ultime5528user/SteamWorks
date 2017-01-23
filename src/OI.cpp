// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Pilotage.h"
#include "Commands/SShootOnce.h"
#include "Commands/Capture.h"

OI::OI() {

    stick.reset(new Joystick(0));


    bouton1.reset(new JoystickButton(stick.get(), 1));
    bouton1->WhileHeld(new SShootOnce());
    

    bouton2.reset(new JoystickButton(stick.get(), 2));
    bouton2->WhenPressed(new Capture());


    SmartDashboard::PutData("Pilotage", new Pilotage());


}


std::shared_ptr<Joystick> OI::getStick() {
   return stick;
}

