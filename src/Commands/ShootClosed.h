#ifndef ShootClosed_H
#define ShootClosed_H

#include "Commands/Command.h"
#include <Servo.h>

class ShootClosed : public Command {
private:

	double setpoint;

public:
	ShootClosed();
	ShootClosed(double setpoint);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif //cancer
