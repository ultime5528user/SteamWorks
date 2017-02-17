#include "Commands/AutoBallesGearBleu.h"

#include "Tourner.h"
#include "Shoot.h"
#include "MonterBalle.h"
#include "StopShoot.h"
#include "Avancer.h"
#include "Viser.h"
#include <Commands/TimedCommand.h>

AutoBallesGearBleu::AutoBallesGearBleu() {

	AddParallel(new MonterBalle());
	AddParallel(new Shoot());
	AddSequential(new TimedCommand("Attente AutoBallesGearBleu", 5.0));
	AddParallel(new StopShoot());

	AddSequential(new Avancer(-1.32));

	AddSequential(new Tourner(180));

	AddSequential(new Viser());
}