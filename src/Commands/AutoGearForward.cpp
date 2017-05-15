#include "AutoGearForward.h"

#include "Avancer.h"
#include "Viser.h"

AutoGearForward::AutoGearForward() {

	AddSequential(new Avancer(3.5, 4.0, 0.805, 0.2, 1.7));
	AddSequential(new Viser());

}
