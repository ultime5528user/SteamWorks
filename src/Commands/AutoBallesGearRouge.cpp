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
#include "ShootClosed.h"

double AutoBallesGearRouge::VITESSE_SHOOT(79.5);

AutoBallesGearRouge::AutoBallesGearRouge(double timeout) {

	AddParallel(new MonterBalle());
	AddParallel(new Spin());
	AddSequential(new WaitCommand("Attente AutoBallesGearBleu", 0.7));
	AddParallel(new Shoot());
	AddSequential(new WaitCommand("Attente AutoBallesGearBleu", timeout));
	AddParallel(new ShootClosed());

	AddSequential(new Tourner(10, 10, 0.6, 0.6, 0.6));
	AddParallel(new StopShoot());

	AddSequential(new Avancer(-5.9, -7.9, -0.805, 0.68, 2.5));

	AddSequential(new Tourner(120, 140, 0.85, -0.60, 1.2));

	AddSequential(new TimedAvancer(0.6, 0.65));

	AddSequential(new Viser());
}
