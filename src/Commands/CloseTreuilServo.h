#ifndef CloseTreuilServo_H
#define CloseTreuilServo_H

#include <Commands/Command.h>

class CloseTreuilServo : public Command {
public:
	CloseTreuilServo();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CloseTreuilServo_H
