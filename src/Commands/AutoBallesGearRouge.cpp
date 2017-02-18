#include "Commands/AutoBallesGearRouge.h"
#include "Avancer.h"
#include "Tourner.h"
#include "Shoot.h"
#include "MonterBalle.h"
#include <Commands/WaitCommand.h>
#include <Commands/PrintCommand.h>
#include "StopShoot.h"
#include "Viser.h"
#include "Spin.h"
#include "TimedAvancer.h"

double AutoBallesGearRouge::VITESSE_SHOOT(80.0);

AutoBallesGearRouge::AutoBallesGearRouge() {

	AddParallel(new MonterBalle());
	AddParallel(new Spin());
	AddSequential(new WaitCommand("Attente AutoBallesGearBleu", 0.7));
	AddParallel(new MonterBalle());
	AddParallel(new Shoot());
	AddSequential(new WaitCommand("Attente AutoBallesGearBleu", 4.0));
	AddParallel(new StopShoot());

	AddSequential(new Avancer(-7.2, -9.8, -0.805, 0.65));

	AddSequential(new Tourner(-130, -164, -0.85, 0.65));

	AddSequential(new TimedAvancer(0.6, 0.65));

	AddSequential(new Viser());
}
