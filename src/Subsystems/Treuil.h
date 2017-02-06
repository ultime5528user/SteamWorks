#ifndef Treuil_H
#define Treuil_H

#include <Commands/Subsystem.h>
#include <SpeedController.h>

class Treuil : public Subsystem {
private:
	std::shared_ptr<SpeedController> moteur;

public:
	Treuil();
	void InitDefaultCommand();

	void TreuilMoteur();
	void TreuilMaintien();
	void TreuilStop();
};

#endif  // Treuil_H
