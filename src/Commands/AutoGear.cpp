
#include "Commands/AutoGear.h"
#include "TimedAvancer.h"
#include "Viser.h"


AutoGear::AutoGear() {

		AddSequential(new TimedAvancer(0.6, 1.0));
		AddSequential(new Viser());

}
