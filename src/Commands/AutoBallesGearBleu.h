#ifndef AutoBallesGearBleu_H
#define AutoBallesGearBleu_H

#include <Commands/CommandGroup.h>


class AutoBallesGearBleu : public CommandGroup {
public:
	static double VITESSE_SHOOT;

	AutoBallesGearBleu(double timeout = 3.0);
};

#endif  // AutoBallesGearBleu_H
