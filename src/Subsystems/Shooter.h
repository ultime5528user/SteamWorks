#ifndef Shooter_H
#define Shooter_H

#include <Servo.h>
#include <Commands/PIDSubsystem.h>
#include <SpeedController.h>
#include <Encoder.h>

class Shooter : public PIDSubsystem {
private:
	std::shared_ptr<SpeedController> moteur;
	std::shared_ptr<Encoder> encoder;
	std::shared_ptr<Servo> servo;

public:

	static double VITESSE;
	static double THRESHOLD;
	static double VALEUR_INIT;
	static double AJUST;
	static double SERVO_OPEN;
	static double SERVO_CLOSE;
	static double VALEUR_UNLOAD;


	Shooter();
	void InitDefaultCommand();
	void Shoot(double value);
	void ShootStop();
	double GetEncoder();
	void SetServoOpen();
	void SetServoClose();

protected:
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);

};

#endif  // Shooter_H
