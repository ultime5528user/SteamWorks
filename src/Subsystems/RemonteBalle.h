#ifndef RemonteBalle_H
#define RemonteBalle_H
#include <Commands/Subsystem.h>
#include <SpeedController.h>

class RemonteBalle : public Subsystem {
private:
	std::shared_ptr<SpeedController> moteur;

public:

	static double VITESSE;
	static double VITESSE_LENT;

	RemonteBalle();
	void InitDefaultCommand();
	void Monte();
	void MonteLent();
	void Stop();
};

#endif  // RemonteBalle_H
