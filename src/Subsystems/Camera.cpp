#include "Camera.h"
#include "../RobotMap.h"
#include "../Commands/Capture.h"

int Camera::EXPOSURE(25);

Camera::Camera() :
	Subsystem("Camera"),
	visionRunning(false)
{
	frc::CameraServer* cs = frc::CameraServer::GetInstance();

	//Camera

	camera = new cs::UsbCamera{"MainCam", 0};
	camera->SetResolution(320, 240);
	camera->SetExposureManual(25);

	//Thread vision
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

		cv::Mat output(240, 320, CV_8UC3, cv::Scalar(255, 0, 0));

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

	camera->SetExposureManual(EXPOSURE);

	frc::DriverStation::ReportError("StartGrip called.");

	visionRunning = true;
}


void Camera::EndGrip(){

	light->Set(0);

	visionRunning = false;

	camera->SetExposureManual(25);
}

void Camera::Analyse(const cv::Mat& img, cv::Mat& output)
{

	pipeline.process(img);
	cv::Mat* image = pipeline.getcvErodeOutput();

	frc::DriverStation::ReportError("# Contours : " + std::to_string(pipeline.getfilterContoursOutput()->size()));

	image->copyTo(output);

	//DEBUG (enlever)
	return;

	//À compléter

	if(callbackFunc)
		callbackFunc(0, 0);




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
