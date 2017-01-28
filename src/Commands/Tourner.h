#ifndef Tourner_H
#define Tourner_H

#include "commands/Command.h"

class Tourner : public Command {
private:
	double af;
	double ai;
	double vf;
	double vi;
	double pente;

public:
	Tourner();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Tourner_H
