#include "Commands/AutoBallesGearRouge.h"
#include "Avancer.h"
#include "Tourner.h"
#include "Shoot.h"
#include "MonterBalle.h"
#include <Commands/WaitCommand.h>
#include "StopShoot.h"
#include "Viser.h"
#include "Spin.h"

AutoBallesGearRouge::AutoBallesGearRouge() {

	AddParallel(new MonterBalle());
	AddParallel(new Spin());
	AddSequential(new WaitCommand("Attente AutoBallesGearRouge", 0.5));
	AddParallel(new Shoot(80.5));
	AddSequential(new WaitCommand("Attente AutoBallesGearRouge", 3.0));
	AddParallel(new StopShoot());

	AddSequential(new Tourner(-36, -56, -0.55, 0.1));

	AddSequential (new Avancer(-10.5, -13.2, -0.6, 0.1));

	AddSequential(new Tourner(-120, -140, -0.55, 0.1));

	AddSequential(new Viser());
}
