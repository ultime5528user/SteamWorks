#ifndef Unload_H
#define Unload_H

#include <Commands/Command.h>

class Unload : public frc::Command {
public:
	Unload();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Unload_H
