#include "include/common.h"
mt19937 rng(time(0));
uniform_int_distribution<> rd(0, 100);
int randint() { return rd(rng); }

