#include "SafeSpin.h"

#include "Unload.h"
#include "Spin.h"

SafeSpin::SafeSpin() {

	AddSequential(new Unload());
	AddSequential(new Spin());

}
