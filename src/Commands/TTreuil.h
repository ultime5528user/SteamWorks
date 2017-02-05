#ifndef TTreuil_H
#define TTreuil_H

#include "commands/Command.h"

class TTreuil : public Command {
public:
	TTreuil();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TTreuil_H
