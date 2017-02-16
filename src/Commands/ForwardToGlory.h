#ifndef ForwardToGlory_H
#define ForwardToGlory_H

#include "Commands/Command.h"

class ForwardToGlory : public Command {
private:
	double cancer;

public:
	ForwardToGlory();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ForwardToGlory_H
