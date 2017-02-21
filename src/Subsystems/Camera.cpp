#include <Commands/Viser.h>
#include "Camera.h"
#include "../RobotMap.h"
#include <cmath>
#include <iostream>


int Camera::EXPOSURE(5);
double Camera::X_THRESHOLD(0.02);
double Camera::WIDTH_THRESHOLD(5.0);
double Camera::OFFSET(0.05);

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

		cv::Mat img(240, 320, CV_8UC3, cv::Scalar(0, 255, 0));

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
			try
			{
				cvSink.GrabFrame(img);
				mainStream.PutFrame(img);

				if(visionRunning.load())
				{
					Analyse(img, output);
				}

				gripStream.PutFrame(output);
			}
			catch (cv::Exception & e)
			{
				std::cerr << e.what() << std::endl;
			}


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

	visionRunning = true;
}


void Camera::EndGrip(){

	light->Set(0);

	visionRunning = false;

	camera->SetExposureManual(35);
}

void Camera::Analyse(const cv::Mat& img, cv::Mat& output)
{

	pipeline.process(img);
	cv::Mat* image = pipeline.getcvErodeOutput();

	image->copyTo(output);

	std::vector<std::vector<cv::Point> >* contours = pipeline.getfindContoursOutput();

	double centreX, largeur;
	cv::Rect rect;


	if(contours->size() == 2)
	{

		std::vector<cv::Point> tableau;
		tableau = contours->at(0);
		tableau.insert(tableau.end(), contours->at(1).begin(), contours->at(1).end());
		rect = cv::boundingRect(tableau);

	}
	else if(contours->size() > 2)
	{
		std::vector<double> scores;
		int min1(0), min2(1), dist, distMin(241);
		//trouve min
		for(unsigned int i = 0; i < contours->size() - 1; i++)
		{
			for(unsigned int j = i + 1; j < contours->size(); j++)
			{
				cv::Rect rect1 = cv::boundingRect(contours->at(i));
				cv::Rect rect2 = cv::boundingRect(contours->at(j));
				dist = std::abs(rect2.y - rect1.y);

				if( dist < distMin)
				{
					distMin = dist;
					min1 = i;
					min2 = j;
				}
			}
		}


		std::vector<cv::Point> board ;
		board = contours->at(min1);
		board.insert(board.end(), contours->at(min2).begin(), contours->at(min2).end());

		rect = cv::boundingRect(board);

	}
	else {
		if(callbackFunc)
					callbackFunc(0, 0);
		return;
	}

		centreX = rect.x + rect.width / 2.0;
		largeur = rect.width;
		centreX = (2*(centreX/image->cols))-1;

		cv::rectangle(output, rect, cv::Scalar(255, 255, 255));

		if(callbackFunc)
			callbackFunc(centreX, largeur);


	}





