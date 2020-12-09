


#include <stdio.h> /* printf */
#include <string.h> /* strcmp() memset() memcpy() memmove() */




void *MemSet(void *s, int c, size_t n);
void *MemCpy(void *dest, const void *src, size_t n);
void *Memmove(void *str1, const void *str2, size_t n);

void testMemmove();
void testMemSet();
void testMemCpy();

int main()
{

	testMemmove();
	testMemSet();
	testMemCpy();
	
	return 1;
}

 
void testMemSet()
{
	
	char str1[] = "helen is the queen";
	char str2[] = "helen is the queen";
	int res = 1;

	MemSet(str1+3, '1' , 6);
	memset(str2+3, '1' , 6);

	res = strcmp(str1, str2);

	if( res == 0)
	{
		printf("Memset works properly\n");
	}
	else
	{
		printf("Memset doesn't work\n");
	}		
}

void *MemSet(void *s, int c, size_t n)
{
	size_t place = ((size_t)s % 8);
	unsigned char *ptr = s;	
	size_t word = 0;
	int i = 0;

	int modul = 0;
	int div = 0;

	 for(; i < 8; i++)
	    {
	        word = word  | ((size_t)c << i*8);
	    }


	while (place < 8 && n > 0)
	{	
		++place;
		--n;
		*ptr++ = c;
	}
			
	modul = n % 8;  
	div = n / 8 ;  

	while (div > 0 )
	{
		*(size_t*)ptr = word;
		ptr += 8;
		div--;
	}

	while( modul > 0)
	{
		--modul;
		*ptr++ = c;
	}

	return s;
	
}
/********************************************************/

/*********************************************************/
void *MemCpy(void *dest, const void *src, size_t n)
{
	size_t index = 0;
	unsigned char *d = (unsigned char *)dest;
	unsigned char *s = (unsigned char *)src;

	while ( index < (n / 8))
	{
		*(size_t*)d = *(size_t*)s;
		
		d += 8;
		s += 8;
		index++;
	}

	n -= (index * 8);
	
	while ( n-- )
	{
		*d = *s;
		d++;
		s++;
	}

	return dest;
}


void testMemCpy()
{
	const char src[50] = "helen helen helen helen helen is";
	char dest[50];
	int res = 1;
		   
	strcpy(dest,"Heloooo!!");
	MemCpy(dest, src, strlen(src)+1);
	res = strcmp(dest, src);
	
	if( res == 0)
	{
	printf("Memcpy works properly\n");
	}
	else
	{
		printf("Memcpy doesn't work\n");
	}
}


/************************************************************/

/************************************************************/
void *Memmove(void *dest, const void *src, size_t n)
{

	unsigned char *d = (unsigned char *)dest;
	unsigned char *s = (unsigned char *)src;	
	
	if((s < d) && (d < (s + n)))
	{
        d += (n-1);
        s += (n-1);
		while (n--)
		{
			*d-- = *s--;
		}
	} else {

			while ( n--)
			{
				*d++ = *s++;
			}	
		}
		return dest;
}



void testMemmove()
{
	
	char src[19] = "hello world" ; 
	char src2[19] = "hello world" ;
	int res = 1; 
    	Memmove(src + 3, src, 5);
	memmove(src2 + 3, src2, 5);

	res = strcmp(src, src2);
	if( res == 0)
	{
		printf("Memmove works properly\n");
	}
	else
	{
		printf("Memmove doesn't work\n");
	}

}












