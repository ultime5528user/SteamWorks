#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <SpeedController.h>
#include <Encoder.h>

class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> moteur;
	std::shared_ptr<Encoder> encoder;

public:

	static double SHOOT_VALUE;

	Shooter();
	void InitDefaultCommand();
	void Shoot();
	void ShootStop();
	double GetEncoder();

};

#endif  // Shooter_H
