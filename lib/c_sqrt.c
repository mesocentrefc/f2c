#include <config.h>
#include "f2c.h"

#undef abs
#include <math.h>

void c_sqrt(complex *r, complex *z)
{
	double mag, t;
	double zi = z->i, zr = z->r;

	if( (mag = hypot(zr, zi)) == 0.)
		r->r = r->i = 0.;
	else if(zr > 0)
		{
		r->r = t = sqrt(0.5 * (mag + zr) );
		t = zi / t;
		r->i = 0.5 * t;
		}
	else
		{
		t = sqrt(0.5 * (mag - zr) );
		if(zi < 0)
			t = -t;
		r->i = t;
		t = zi / t;
		r->r = 0.5 * t;
		}
}
