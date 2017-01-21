#ifndef SShootOnce_H
#define SShootOnce_H

#include "Commands/Command.h"

class SShootOnce : public Command {
public:
	SShootOnce();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SShootOnce_H
