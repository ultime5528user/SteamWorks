#ifndef Shoot_H
#define Shoot_H

#include "Commands/Command.h"
#include <Timer.h>
#include <Servo.h>

class Shoot : public Command {
private:
	double value;
	bool ajust;
	frc::Timer timer;
public:
	Shoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif //cancer
