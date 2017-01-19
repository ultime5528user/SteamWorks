#ifndef Capture_H
#define Capture_H

#include "../CommandBase.h"

class Capture : public CommandBase {
public:
	Capture();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Capture_H
