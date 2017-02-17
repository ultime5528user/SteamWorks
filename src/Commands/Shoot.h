#ifndef Shoot_H
#define Shoot_H

#include "Commands/Command.h"
#include <Timer.h>
#include <Servo.h>

class Shoot : public Command {
private:

	double setpoint;

public:
	Shoot();
	Shoot(double setpoint);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif //cancer
