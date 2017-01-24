#include "Camera.h"
#include "../RobotMap.h"


Camera::Camera() :
	Subsystem("Camera"),
	camera{ "USB Camera 0", 0},
	cvSink{"serve_USB Camera 0"},
	visionThread(nullptr),
	stopThread(false)

{

    camera.SetResolution(640, 480);

    cvSink.SetSource(camera);

    outputStreamStd = frc::CameraServer::GetInstance()->PutVideo("Standard", 640, 480);
}


void Camera::InitDefaultCommand() {

}



// Put methods for controlling this subsystem
// here. Call these from Commands.
void Camera::SendImage(){
	cvSink.GrabFrame(source);
	outputStreamStd.PutFrame(source);
}

void Camera::StartThread(){

	stopThread = false;

	visionThread = new std::thread( [this](){

		while(!stopThread.load())
		{
			this->SendImage();
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}

	} );

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

}
