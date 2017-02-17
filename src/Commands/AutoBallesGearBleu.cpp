#include "Commands/AutoBallesGearBleu.h"

#include "Tourner.h"
#include "Shoot.h"
#include "MonterBalle.h"
#include "StopShoot.h"
#include "Avancer.h"
#include "Viser.h"
#include <Commands/WaitCommand.h>

AutoBallesGearBleu::AutoBallesGearBleu() {

	AddParallel(new MonterBalle());
	AddParallel(new Shoot());
	AddSequential(new WaitCommand("Attente AutoBallesGearBleu", 5.0));
	AddParallel(new StopShoot());

	AddSequential(new Avancer(-1.32));

	AddSequential(new Tourner(180));

	AddSequential(new Viser());
}
