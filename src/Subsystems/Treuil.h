#ifndef Treuil_H
#define Treuil_H

#include <Commands/Subsystem.h>
#include <SpeedController.h>

class Treuil : public Subsystem {
private:
	std::shared_ptr<SpeedController> moteur;

public:

	static double VALEUR_MONTER;
	static double VALEUR_MAINTIEN;

	Treuil();
	void InitDefaultCommand();

	void Monter();
	void Maintien();
	void Stop();
};

#endif  // Treuil_H
