#include "TimedAvancer.h"
#include <Robot.h>


TimedAvancer::TimedAvancer(double move, double timeout) : Command("TimedAvancer") {

	Requires(Robot::basePilotable.get());

	SetTimeout(timeout);

	this->move = move;

}

// Called just before this Command runs the first time
void TimedAvancer::Initialize() {


}


// Called repeatedly when this Command is scheduled to run
void TimedAvancer::Execute() {

	Robot::basePilotable->Avancer(move);

}

// Make this return true when this Command no longer needs to run execute()
bool TimedAvancer::IsFinished() {

	return IsTimedOut();

}

// Called once after isFinished returns true
void TimedAvancer::End() {
	Robot::basePilotable->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedAvancer::Interrupted() {
	End();
}
