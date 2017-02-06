#ifndef Avancer_H
#define Avancer_H

#include "Commands/Command.h"

class Avancer : public Command {
private:
	bool terminus;
	double df;
	double vi;
	double vf;
	double di;
	double pente;
	double calc;
	double moyenne;

public:
	Avancer();
	Avancer(double dist);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Avancer_H
