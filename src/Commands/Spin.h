#ifndef Spin_H
#define Spin_H

#include "Commands/Command.h"
#include <Timer.h>
#include <Servo.h>

class Spin : public Command {
private:

public:
	Spin();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif //cancer
