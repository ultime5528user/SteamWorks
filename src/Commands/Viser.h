#ifndef Viser_H
#define Viser_H

#include "Commands/Command.h"
#include <mutex>

class Viser : public frc::Command {
public:
	Viser();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	void SetParam(double centreX, double largeur);


private:
	double m_centreX;
	double m_largeur;
	priority_mutex mutex;

};

#endif  // Viser_H
