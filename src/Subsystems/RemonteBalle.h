#ifndef RemonteBalle_H
#define RemonteBalle_H
#include <Commands/Subsystem.h>
#include <SpeedController.h>

class RemonteBalle : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> Remonte;
public:
	RemonteBalle();
	void InitDefaultCommand();
	void Monte();
	void Stop();
};

#endif  // RemonteBalle_H
