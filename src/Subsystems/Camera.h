#ifndef Camera_H
#define Camera_H

#include <Commands/Subsystem.h>
#include <atomic>
#include <Commands/Capture.h>
#include "opencv2/core/core.hpp"
#include <thread>
#include "CameraServer.h"
#include "Spark.h"
#include "GripPipeline.h"
#include "DriverStation.h"

typedef std::function<void(double,double)> SetParamHandler;

class Camera : public Subsystem {
private:
	cv::Mat source;
	cs::UsbCamera* camera;
	//cs::CvSink* cvSink;
	//cs::CvSource* mainStream;
	//cs::CvSource* gripStream;
	//std::thread* visionThread;
	std::atomic<bool> visionRunning;
	//std::atomic<bool> stopThread;
	grip::GripPipeline pipeline;
	std::shared_ptr<frc::Spark> light;
	SetParamHandler callbackFunc;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:

	static int EXPOSURE;
	static double XTHRESHOLD;
	Camera();
	void InitDefaultCommand();

	void StartGrip();

	template <typename Callable, typename Arg>
	void StartGrip(Callable&& f, Arg&& arg){

		using namespace std::placeholders;

		callbackFunc =
				std::bind(std::forward<Callable>(f), std::forward<Arg>(arg), _1, _2);

		StartGrip();

	}


	void EndGrip();

	void Analyse(const cv::Mat& img, cv::Mat& output);

};

#endif  // Camera_H
