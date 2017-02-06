#ifndef Shooter_H
#define Shooter_H

#include <Servo.h>
#include <Commands/Subsystem.h>
#include <SpeedController.h>
#include <Encoder.h>

class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> moteur;
	std::shared_ptr<Encoder> encoder;
	std::shared_ptr<Servo> servo;
	double servoPosition;
public:

	static double SHOOT_VALUE;
	static double THRESHOLD;
	static double MOTEUR;
	static double AJUST;
	static double INTERVAL_CLOSE;
	static double INTERVAL_OPEN;
	static double SERVO_OPEN;
	static double SERVO_CLOSE;


	Shooter();
	void InitDefaultCommand();
	void Shoot(double value);
	void ShootStop();
	double GetEncoder();
	void SetServoOpen();
	void SetServoClose();
	void ServoMove();
};

#endif  // Shooter_H
