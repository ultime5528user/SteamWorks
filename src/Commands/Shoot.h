#ifndef Shoot_H
#define Shoot_H

#include "Commands/Command.h"

class Shoot : public Command {
private:
	double value;
	bool ajust;
	frc::Timer timer;
	frc::Servo servo;
public:
	Shoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif //cancer
