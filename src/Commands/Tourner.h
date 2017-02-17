#ifndef Tourner_H
#define Tourner_H

#include "Commands/Command.h"

class Tourner : public Command {
private:

	double ai;
	double af;
	double vi;
	double vf;

	double pente;

	bool getDB;

public:
	Tourner();
	Tourner(double angle);
	Tourner(double ai, double af, double vi, double vf);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Tourner_H
