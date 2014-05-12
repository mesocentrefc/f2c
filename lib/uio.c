#include <config.h>
#include "f2c.h"
#include "fio.h"

uiolen f__reclen;

int do_us(ftnint *number, char *ptr, ftnlen len)
{
	if(f__reading)
	{
		f__recpos += (int)(*number * len);
		if(f__recpos>f__reclen)
			err(f__elist->cierr, 110, "do_us");
		if (fread(ptr,(int)len,(int)(*number),f__cf) != *number)
			err(f__elist->ciend, EOF, "do_us");
		return(0);
	}
	else
	{
		f__reclen += *number * len;
		(void) fwrite(ptr,(int)len,(int)(*number),f__cf);
		return(0);
	}
}

integer do_ud(ftnint *number, char *ptr, ftnlen len)
{
	f__recpos += (int)(*number * len);
	if(f__recpos > f__curunit->url && f__curunit->url!=1)
		err(f__elist->cierr,110,"do_ud");
	if(f__reading)
	{
#ifdef Pad_UDread
#ifdef KR_headers
	int i;
#else
	size_t i;
#endif
		if (!(i = fread(ptr,(int)len,(int)(*number),f__cf))
		 && !(f__recpos - *number*len))
			err(f__elist->cierr,EOF,"do_ud")
		if (i < *number)
			memset(ptr + i*len, 0, (*number - i)*len);
		return 0;
#else
		if(fread(ptr,(int)len,(int)(*number),f__cf) != *number)
			err(f__elist->cierr,EOF,"do_ud")
		else return(0);
#endif
	}
	(void) fwrite(ptr,(int)len,(int)(*number),f__cf);
	return(0);
}

integer do_uio(ftnint *number, char *ptr, ftnlen len)
{
	if(f__sequential)
		return(do_us(number,ptr,len));
	else	return(do_ud(number,ptr,len));
}
