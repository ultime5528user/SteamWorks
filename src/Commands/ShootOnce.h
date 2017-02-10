#ifndef ShootOnce_H
#define ShootOnce_H

#include "Commands/Command.h"

class ShootOnce : public Command {

public:
	ShootOnce();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShootOnce_H
