#include "Commands/AutoBallesGearRouge.h"
#include "Avancer.h"
#include "Tourner.h"
#include "Shoot.h"
#include "MonterBalle.h"
#include <Commands/TimedCommand.h>
#include "StopShoot.h"
#include "Viser.h"
AutoBallesGearRouge::AutoBallesGearRouge() {

	AddParallel(new MonterBalle());
	AddParallel(new Shoot());
	AddSequential(new TimedCommand("Attente AutoBallesGearRouge", 5.0));
	AddParallel(new StopShoot());

	AddSequential (new Avancer(-1.32));

	AddSequential(new Tourner(180));

	AddSequential(new Viser());
}
