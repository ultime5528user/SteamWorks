#ifndef TimedAvancer_H
#define TimedAvancer_H

#include "Commands/Command.h"

class TimedAvancer : public Command {
private:

	double move;

public:
	TimedAvancer(double move, double timeout);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TimedAvancer_H
