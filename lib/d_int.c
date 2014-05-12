#include <math.h>
#include <config.h>
#define F2C_NO_INLINE_H
#include <f2c.h>

double d_int(const doublereal *x)
{
  return (*x>0) ? floor(*x) : -floor(-*x);
}
