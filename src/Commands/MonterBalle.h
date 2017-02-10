#ifndef MonterBalle_H
#define MonterBalle_H

#include "Commands/Command.h"

class MonterBalle : public Command {
public:
	MonterBalle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MonterBalle_H
