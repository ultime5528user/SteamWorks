#ifndef Avancer_H
#define Avancer_H

#include "Commands/Command.h"

class Avancer : public Command {
private:
	bool terminus;
	double distance;
	double vi;
	double vmin;
	double d;
	double p;
	double pente;

public:
	Avancer(double dist);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Avancer_H
