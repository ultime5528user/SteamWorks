#ifndef TTreuilD_H
#define TTreuilD_H

#include "Commands/Command.h"

class TTreuilD : public Command {
public:
	TTreuilD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TTreuilD_H
