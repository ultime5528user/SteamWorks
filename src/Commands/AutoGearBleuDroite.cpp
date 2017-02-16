#include <Commands/AutoGearBleuDroite.h>
#include "Commands/AutoGearBleuDroite.h"

#include "Tourner.h"
#include "Avancer.h"
#include "Viser.h"


AutoGearBleuDroite::AutoGearBleuDroite() {

		AddSequential(new Avancer(2.37));

		AddSequential (new Tourner(-60));

		AddSequential(new Viser());




	}
