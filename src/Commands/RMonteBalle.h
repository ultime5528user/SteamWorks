#ifndef RMonteBalle_H
#define RMonteBalle_H

#include "Commands/Command.h"

class RMonteBalle : public Command {
public:
	RMonteBalle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RMonteBalle_H
