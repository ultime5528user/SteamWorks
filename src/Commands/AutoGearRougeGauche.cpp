#include <Commands/AutoGearRougeGauche.h>
#include "Avancer.h"
#include "Tourner.h"
#include "Viser.h"
AutoGearRougeGauche::AutoGearRougeGauche() {
	AddSequential(new Avancer(1.39));

	AddSequential(new Tourner(60));

	AddSequential(new Viser());
}
