#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <SpeedController.h>

class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> moteur;

public:

	static double SHOOT_VALUE;

	Shooter();
	void InitDefaultCommand();
	void Shoot();
	void ShootStop();

};

#endif  // Shooter_H
