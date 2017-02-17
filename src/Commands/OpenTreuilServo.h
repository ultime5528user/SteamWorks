#ifndef OpenTreuilServo_H
#define OpenTreuilServo_H

#include <Commands/Command.h>

class OpenTreuilServo : public Command {
public:
	OpenTreuilServo();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OpenTreuilServo_H
