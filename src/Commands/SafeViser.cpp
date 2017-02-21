#include "SafeViser.h"
#include "Viser.h"
#include "TimedAvancer.h"
#include "../Subsystems/BasePilotable.h"

SafeViser::SafeViser() {

	AddSequential(new Viser());
	//AddSequential(new TimedAvancer(BasePilotable::K_MOVE, 0.4));

}
