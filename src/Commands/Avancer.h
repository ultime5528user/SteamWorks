#ifndef Avancer_H
#define Avancer_H

#include "Commands/Command.h"

class Avancer : public Command {
private:

	double di;
	double df;
	double vi;
	double vf;

	double pente;
	double moyenne;

	bool getDB;

public:
	Avancer();
	Avancer(double dist);
	Avancer(double di, double df, double vi, double vf);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Avancer_H
