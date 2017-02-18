#include "Commands/AutoBallesGearBleu.h"

#include "Tourner.h"
#include "Shoot.h"
#include "MonterBalle.h"
#include "StopShoot.h"
#include "Avancer.h"
#include "Viser.h"
#include "Spin.h"
#include <Commands/WaitCommand.h>

double AutoBallesGearBleu::VITESSE_SHOOT(80.0);

AutoBallesGearBleu::AutoBallesGearBleu(double timeout) {

	AddParallel(new MonterBalle());
	AddParallel(new Spin());
	AddSequential(new WaitCommand("Attente AutoBallesGearBleu", 0.7));
	AddParallel(new Shoot(VITESSE_SHOOT));
	AddSequential(new WaitCommand("Attente AutoBallesGearRouge", timeout));
	AddParallel(new StopShoot());


	AddSequential(new Tourner(-26, -52, -0.7, 0.3));


	AddSequential (new Avancer(-8.8, -12.2, -0.805, 0.54));

	AddSequential(new Tourner(-100, -136, -0.85, 0.68));

	AddSequential(new Viser());


}
