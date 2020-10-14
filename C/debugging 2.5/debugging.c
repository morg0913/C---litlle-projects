#include <stdlib.h> /* malloc */
#include <stdio.h>
#include <string.h>

 #include <stdlib.h>




/*
char *Strcpy(char *dest, const char *src);
char *Strdup(const char *str);*/
int main(void)
{

	while(1)
	{
		 
		printf("1");
		 abort();
	}
	/*char *str1 = "hello world";
	char *str2 = Strdup(str1);
	char *str3 = (char*)malloc(8);

	*str3 = 'a';
	*(str3 + 1) = 'b';

	printf("%s\n", str2);
 
	free(str2);
	free(str3);*/

	return 0;

}
/*
char *Strcpy(char *dest, const char *src)
{
	char *start = dest;

	while(*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return start;
}

char *Strdup(const char *str)
{
	char *dest = (char*)malloc(strlen(str)+1);
	Strcpy(dest, str);
	return dest;
}
*/
