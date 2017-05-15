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

	AddSequential(new Tourner(50, 50, 0.6, 0.6, 2.5));
	//AddSequential(new Tourner(55, 55, 0.6, 0.6, 2.5));
	AddParallel(new StopShoot());

	AddSequential(new Avancer(-3.9, -5.90, -0.805, 0.68, 2.5));
	//AddSequential(new Avancer(-5.9, -7.90, -0.805, 0.68, 2.5));

	AddSequential(new Tourner(95, 105, 0.85, -0.60, 3.0));
	//AddSequential(new Tourner(125, 140, 0.85, -0.60, 3.0));

	AddSequential(new Avancer(2.0, 2.5, 0.805, 0.0, 2.5));


	//AddSequential(new TimedAvancer(0.6, 0.65));

	AddSequential(new Viser());
}
