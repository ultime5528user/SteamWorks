#ifndef TMaintien_H
#define TMaintien_H

#include "Commands/Command.h"

class TMaintien : public Command {
public:
	TMaintien();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TMaintien_H
