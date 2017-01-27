#include "Camera.h"
#include "../RobotMap.h"
#include "../Commands/Capture.h"

Camera::Camera() :
	Subsystem("Camera"),
	source(),
	visionThread(nullptr),
	stopThread(false)
{
	frc::CameraServer* cs = frc::CameraServer::GetInstance();

	camera = new cs::UsbCamera{"MainCam", 0};
	//camera->SetResolution(640, 480);

	cvSink = new cs::CvSink("sink_MainCam");
	cvSink->SetSource(*camera);

	outputStream = new cs::CvSource("MainStream", cs::VideoMode::kMJPEG, 160, 120, 30);

	cs->AddCamera(*outputStream);
	auto server = cs->AddServer("serve_MainStream");
	server.SetSource(*outputStream);

/*
	visionThread = new std::thread([this](){
		while(true)
			{
				SendImage();
				std::this_thread::sleep_for(std::chrono::milliseconds(5));
			}
	});
*/

}


void Camera::InitDefaultCommand() {

	SetDefaultCommand(new Capture());

}



// Put methods for controlling this subsystem
// here. Call these from Commands.
void Camera::SendImage(){
	cvSink->GrabFrame(source);
	outputStream->PutFrame(source);
}

void Camera::StartThread(){

	frc::DriverStation::ReportError("StartThread called...");

	stopThread = false;

	visionThread = new std::thread( [this](){

		frc::DriverStation::ReportError("Thread beginning...");

		while(!stopThread.load())
		{
			this->SendImage();
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}

		frc::DriverStation::ReportError("Thread ending...");

	} );

	frc::DriverStation::ReportError("Exting StartThread...");

}
void Camera::StartGripThread(){

}
void Camera::EndThread(){

	stopThread = true;
	visionThread->join();
	delete visionThread;

}
void Camera::EndGripThread(){

}
void Camera::Analyse(){
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
}
