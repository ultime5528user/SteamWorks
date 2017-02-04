#ifndef StopShoot_H
#define StopShoot_H

#include "Commands/Command.h"

class StopShoot : public Command {
public:
	StopShoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StopShoot_H
