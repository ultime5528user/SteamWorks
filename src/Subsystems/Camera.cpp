#include "Camera.h"
#include "../RobotMap.h"
#include "../Commands/Capture.h"

Camera::Camera() :
	Subsystem("Camera"),
	visionRunning(false)
	//stopThread(false)
{
	frc::CameraServer* cs = frc::CameraServer::GetInstance();

	//Camera

	camera = new cs::UsbCamera{"MainCam", 0};
	camera->SetResolution(320, 240);
/*
	cvSink = new cs::CvSink("sink_MainCam");
	cvSink->SetSource(*camera);

	//MainStream
	mainStream = new cs::CvSource("MainStream", cs::VideoMode::kMJPEG, 320, 240, 30);
	cs->AddCamera(*mainStream);
	auto mainServer = cs->AddServer("serve_MainStream");
	mainServer.SetSource(*mainStream);
*/
	std::thread mainThread([this, cs](){

		cv::Mat img;

		//MainCamera
		cs::CvSink cvSink("sink_MainCam");
		cvSink.SetSource(*camera);

		//MainServer
		cs::CvSource mainStream("MainStream", cs::VideoMode::kMJPEG, 320, 240, 30);
		cs->AddCamera(mainStream);
		auto mainServer = cs->AddServer("serve_MainStream");
		mainServer.SetSource(mainStream);

		//GripServer
		cs::CvSource gripStream("GripStream", cs::VideoMode::kMJPEG, 320, 240, 30);
		cs->AddCamera(gripStream);
		auto gripServer = cs->AddServer("serve_GripStream");
		gripServer.SetSource(gripStream);

		cv::Mat output(2, 2, CV_8UC3, cv::Scalar(255, 0, 0));

		while(true)
		{
			cvSink.GrabFrame(img);
			mainStream.PutFrame(img);

			if(visionRunning.load())
			{
				frc::DriverStation::ReportError("Vision running loop...");
				Analyse(img, output);
			}

			gripStream.PutFrame(output);


		}

	});
	mainThread.detach();

	//Green light ring
	light = RobotMap::cameraLight;
	light->SetSafetyEnabled(false);

}


void Camera::InitDefaultCommand() {



}

void Camera::StartGrip() {
	light->Set(1);

	frc::DriverStation::ReportError("StartGrip called.");

	visionRunning = true;
}


void Camera::EndGrip(){

	light->Set(0);

	visionRunning = false;

}

void Camera::Analyse(const cv::Mat& img, const cv::Mat& output)
{

	pipeline.process(img);
	cv::Mat* image = pipeline.gethsvThresholdOutput();

	//cv::Mat image;
	//pipeline.getHsv...()->copyTo(image);

	frc::DriverStation::ReportError("HSV Threshold output # channels : " + std::to_string(image->channels()));

	/*
	cv::Mat tab[] = {*image, *image, *image};
	cv::merge(tab, 3, output);
	*/

	cv::cvtColor(*image, output, cv::COLOR_GRAY2BGR);

	frc::DriverStation::ReportError("GRAY2BGR output # channels : " + std::to_string(image->channels()));

	cv::rectangle(output, cv::Point(0, 0), cv::Point(10, 10), cv::Scalar(0, 255, 0), 2);

	return;

	double a(1.0), b(2.0);

	if(callbackFunc)
		callbackFunc(a, b);


	/*
	cvSink->GrabFrame(source);
	pipeline.process(source);
	std::vector<std::vector<cv::Point> >* contours = pipeline.getfilterContoursOutput();

	if(contours->size() < 2){

	}
	else if(contours->size() == 2){

	}
	else {
		std::vector<double> scores;
		double minuUn();
		double minDeux();
		for(auto it = contours->begin(); it != contours->end(); ++it)
		{
			cv::Rect rect = cv::boundingRect(*it);
			cv::rectangle(Widthe)

		}



		}
	}
	*/
}
