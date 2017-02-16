#ifndef NoMotion_H
#define NoMotion_H

#include "Commands/Command.h"

class NoMotion : public Command {
public:
	NoMotion();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // NoMotion_H
