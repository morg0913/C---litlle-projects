#include <stdio.h>
#include <string.h>

int Strcmp (const char* str1, const char* str2);
int Strlen(const char *str);

int main()
{
	char str[] = {"hello"};
	char str2[] = {"Hello"};
	char str3[] = {"hell"};
	char str4[] = {"hello"};

	printf("testing Strlen \n**************************\n");
	printf("%d\n", Strlen(str));
	printf("%d\n", Strlen(str2));
	printf("%d\n", Strlen(str3));

	printf("\ntesting Strcmp\n**************************\n");
	printf("%d\n", Strcmp(str, str2));
	printf("%d\n", Strcmp(str2, str3));
	printf("%d\n", Strcmp(str, str4));

	return 0;
}

int Strcmp (const char* str1, const char* str2){

	if (str1 == NULL || str2 == NULL){
		return -1;
	}

	while(*str1 == *str2){

		if (*str1 == '\0'){
				return 0;	
		}
	++str1;
	++str2;
	}
	
	return (int)(*str1 - *str2);

}

int Strlen(const char *str){
	int length = 0;
	
	if (str == NULL){
		return -1;
	}

	while (*str != '\0'){
		length++;
		str++;
	}
	return length;
}
