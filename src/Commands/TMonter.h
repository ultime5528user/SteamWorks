#ifndef TMonter_H
#define TMonter_H

#include "commands/Command.h"

class TMonter : public Command {
public:
	TMonter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TMonter_H
