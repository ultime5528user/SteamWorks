#include <Commands/AutoGear.h>
#include "Commands/AutoGear.h"

#include "TimedAvancer.h"
#include "SafeViser.h"


AutoGear::AutoGear() {

		AddSequential(new TimedAvancer(0.6, 1.0));

		AddSequential(new SafeViser());

}
