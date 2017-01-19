#ifndef Camera_H
#define Camera_H

#include <Commands/Subsystem.h>
#include <atomic>

class Camera : public Subsystem {
private:
	cv::Mat output;
	cv::Mat source;
	cs::CvSink cvSink;
	cs::UsbCamera camera;
	cs::CvSource outputStreamStd;
	std::thread* visionThread;
	std::atomic<bool> stopThread;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Camera();
	void InitDefaultCommand();

	void SendImage();
	void StartThread();
	void StartGripThread();
	void EndThread();
	void EndGripThread();
	void Analyse();




};

#endif  // Camera_H
