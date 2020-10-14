#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#define NUMBER_OF_STRING 8
#define MAX_STRING_SIZE 40

size_t countRow(char *envp[]);
void Tolower(char *s);
void copy_envp(char **envp, char **newEnvp, size_t len_envp);
void printSize();
void freeAlloc(char **newEnvp, size_t size);

int main (int argc, char *argv[], char *envp[])
{

	/*printSize();*/
	size_t len_envp = countRow(envp);
	char **newEnvp = (char**)malloc(len_envp * sizeof(char));
	copy_envp(envp, newEnvp, len_envp);
	freeAlloc(newEnvp,len_envp);
	free(newEnvp);

	(void)argc;
	(void)argv;
	/*while (*envp != NULL){
		
		printf("envp: %s\n" , *envp);
		envp++;
	}*/
	
	
	return 0;
	
}

void freeAlloc(char **newEnvp, size_t size){
	size_t i = 0;
	while(i < size){
		free(newEnvp[i]);
		i++;
	}
}

size_t countRow(char *envp[]){
	char **count = envp;
	
	while(*count != NULL){
		count++;
	}
	return count - envp;
}

void Tolower(char *s){
	int slen = strlen(s);
	int i;
	for(i = 0; i < slen;i++){
		s[i] = tolower(s[i]);
	}
}

void copy_envp(char **envp, char **newEnvp, size_t len_envp){
	
	size_t i = 0;
	for(i = 0; i < len_envp; i++){
		
		int rowLen = strlen(envp[i]);
		newEnvp[i] = (char *)malloc(rowLen * sizeof(char));
		newEnvp[i] = envp[i];
		Tolower(newEnvp[i]);
		printf("%s \n", newEnvp[i]);
	}
}

void printSize(){

	FILE *fp= fopen("types.txt", "w+");
	
	char types [NUMBER_OF_STRING] [MAX_STRING_SIZE] = {"char","unsigned char", "int", "unsigne int", "short", "unsigned short","long","unsigned long"};
	size_t size [NUMBER_OF_STRING] = {sizeof(char),sizeof(unsigned char), sizeof(int),sizeof (unsigned int), sizeof(short), sizeof(unsigned short),sizeof(long),sizeof(unsigned long)};
	int i=0;
	

	for (i = 0; i < NUMBER_OF_STRING; i++)
	{
		fprintf(fp,"The size of %s is %ld\n", types[i], size[i]);
	}

	fclose(fp);

}
