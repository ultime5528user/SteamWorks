#ifndef Capture_H
#define Capture_H

#include "Commands/Command.h"
#include <mutex>

class Capture : public frc::Command {
public:
	Capture();
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

#endif  // Capture_H
