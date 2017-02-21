#ifndef Treuil_H
#define Treuil_H

#include <Commands/Subsystem.h>
#include <SpeedController.h>
#include <Servo.h>

class Treuil : public Subsystem {
private:
	std::shared_ptr<SpeedController> moteur;
	std::shared_ptr<Servo> servo;


public:

	static double VALEUR_MONTER;

	static double SERVO_OPEN;
	static double SERVO_CLOSE;

	Treuil();
	void InitDefaultCommand();

	void Monter();
	void Stop();

	void SetServoOpen();
	void SetServoClose();
};

#endif  // Treuil_H
