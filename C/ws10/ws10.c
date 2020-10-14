#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define LittleEndian (!("ab" == (short*) "ab"))


/***********************************/
char *intToString(int value);
void testIntToString(void);
/***********************************/
char *  Itoa ( int value, char * str, int base );
void testItoa(void);
/************************************************/
int stringToInt(const char *str);
void testStringToInt(void);
/**********************************************/
int Atoi(const char *str, int base);
void testToAtoi(void);
/************************************************/
void arraysTinder(char *str1, char *str2, char *str3);
void testToArrTinder(void);
/*******************************************/
void testIsLitlle(void);
bool isLitlle(void);
/*******************************************/


int main()
{
		
	testToAtoi();
	return 0;
}



/***************************************************/
char *intToString(int value)
{	
	int i = 0;
	char *str;
	int num = value;
	int digits = 0;
	int rem = 0;

	if (num < 0)
		{
			num *= (-1);
			value *= (-1);
			printf("-");
		}

	while (num != 0)
	{
		digits++;
		num /= 10;
	}

	str = malloc(sizeof(*str)*(digits + 1));

	for (; i < digits; i++)
	{
		rem = value % 10;
		value /= 10;
		str[digits - (i + 1)] = rem + '0';
	}

	str[digits] = '\0';

	return str;
}

void testIntToString(void)
{
	int x = -1989;
	printf("%s\n", intToString(x));
}
/**********************************************/

char *  Itoa ( int value, char * str, int base )
{
	int i = 0;
	int rem = 0;
	int num = value;
	int digits = 0;

	if ( num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if (num < 0)
		{
			num *= (-1);
			value *= (-1);
			printf("-");
		}

	while (num != 0)
	{
		digits++;
		num /= base;
	}

	for (; i < digits; i++)
	{
		rem = value % base;
		str[digits - (i + 1)] = (rem > 9)? 'a' + (rem - 10)  : rem + '0';
		value /= base;
	}

	str[digits] = '\0';

	return str;
}

void testItoa(void)
{
	int x = -(10 + (11*16) + (12 * 16*16));
	char str[50];
	int base = 2;
	printf("%s\n", Itoa(x, str, base));
}


/************************************************************************/

int stringToInt(const char *str)
{
	int res = 0;
	int i = 0;

	if(str[0] == '-')
	{
		i = 1;
		
	}

	while (str[i] != '\0' )
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
	
	if(str[0] == '-')
	{
		res *= (-1);
	}
	return res;
}


void testStringToInt(void)
{
	const char *str = "-1030";
	printf("%d\n" , stringToInt(str));
}
/************************************************************************/

int Atoi(const char *str, int base)
{
	char *s =(char *)str;
	int num = 0;
	bool isNegative = false;

	if( *s == '-' )
	{
		isNegative = true;
		s++;
	}

	while (*s)
	{
		if(*s >= 'a' && *s <= 'z')
		{
			num = num * base + (*s - 'a' + 10);
		}
		else
		{
			num = num * base + (*s - '0');
		}
		
		s++;
	}

	if (isNegative == true)
	{
		num *= (-1);
	}

	return num;
}


void testToAtoi(void)
{
	const char *str = "1234";
	int base = 8;

	int res = Atoi(str, base);

	printf("%d \n", res);
}



/************************************************************************/

void arraysTinder(char *str1, char *str2, char *str3)
{
	int arr[256] = {0};
	int i = 0;
	
	while (str1[i] != '\0')
	{
		arr[str1[i]] = 1;
		i++;
	}
	
	i = 0;
	
	while(str2[i] != '\0')
	{
		if(arr[str2[i]] == 1)
		{
			arr[str2[i]]++;
		}
		
		i++;
	}

	i = 0;
	while (str3[i] != '\0')
	{
		if(arr[str3[i]] == 2)
		{
			arr[str3[i]]--;
		}
		i++;
	}

	for (i = 0; i < 256; i++)
	{
		if(arr[i] == 2)
		{
			printf("%c\n" , (char)i );
		}
	}
}


void testToArrTinder(void)
{
	char *str1 = "avbfdufar";
    char *str2 = "ayuof";
    char *str3 = "fovgp";
	
	arraysTinder(str1, str2, str3);
}
/*********************************************************/
bool isLitlle(void)
{
	short num = 0x1100;
	char *p = (char *)&num;
	return (*p == 0);
}

void testIsLitlle(void)
{
	printf("%d\n", isLitlle());
}

/*********************************************************/









