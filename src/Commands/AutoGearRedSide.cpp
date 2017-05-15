#include "AutoGearRedSide.h"

#include "Avancer.h"
#include "Tourner.h"
#include "Viser.h"

AutoGearRedSide::AutoGearRedSide() {

	AddSequential (new Avancer(7.0, 8.0, 0.705, -0.54, 1.7));
	AddSequential(new Tourner(29, 29, -0.7, 0.3, 1.3));
	AddSequential (new Avancer(1.0, 1.5, 0.705, -0.54, 1.7));

	AddSequential(new Viser());

}
