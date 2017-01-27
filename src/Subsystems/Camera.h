#ifndef Camera_H
#define Camera_H

#include <Commands/Subsystem.h>
#include <atomic>
#include <Commands/Capture.h>
#include "opencv2/core/core.hpp"
#include <thread>
#include "CameraServer.h"


class Camera : public Subsystem {
private:
	cv::Mat source;
	cs::UsbCamera* camera;
	cs::CvSink* cvSink;
	cs::CvSource* outputStream;
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
