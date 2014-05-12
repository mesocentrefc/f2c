#include <config.h>
#include "f2c.h"

/* compare two strings */

integer s_cmp(const char *a0, const char *b0, ftnlen la, ftnlen lb)
{
register unsigned const char *a, *aend, *b, *bend;
a = (const unsigned char *)a0;
b = (const unsigned char *)b0;
aend = a + la;
bend = b + lb;

if(la <= lb)
	{
	while(a < aend)
		if(*a != *b)
			return( *a - *b );
		else
			{ ++a; ++b; }

	while(b < bend)
		if(*b != ' ')
			return( ' ' - *b );
		else	++b;
	}

else
	{
	while(b < bend)
		if(*a == *b)
			{ ++a; ++b; }
		else
			return( *a - *b );
	while(a < aend)
		if(*a != ' ')
			return(*a - ' ');
		else	++a;
	}
return(0);
}

