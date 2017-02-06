#ifndef TDescendre_H
#define TDescendre_H

#include "Commands/Command.h"

class TDescendre : public Command {
public:
	TDescendre();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TDescendre_H
