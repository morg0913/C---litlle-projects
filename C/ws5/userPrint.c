#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef enum status
{
	STOP = 0,
	RUN = 1,
	REMOVE_ERR = 2,
	ERR = 3
} status_t ;

struct sInput
{
	char *str;
	int (*fpcmp)(const char* usrStr, const char* inputStr);
	status_t (*fpof)(const char *filename, char *str);
};

status_t activate(struct sInput sInArr[],  char *str, const char *filename);
status_t stringFromUser(char *filename);
status_t removeFile(const char *filename, char *str);
status_t countLines(const char *filename, char *str);
status_t exitFile(const char *filename, char *str);
status_t addToBegining(const char *filename, char *str);
status_t Filecpy(FILE *dest, FILE *src);
status_t printToFile(const char *filename, char *str);
int cmpChar(const char* usrStr, const char* inputStr);
void initStructArray(struct sInput sInArr[]);

int main(int argc, char *argv[])
{	
	(void)argc;

	stringFromUser(argv[1]);
	

	return 0;
}

/************************************************************/
status_t removeFile(const char *filename, char *str)
{
	assert(NULL != filename); 
	
	(void)str;
	
	return (0 == remove(filename)) ? RUN : REMOVE_ERR;
}


status_t countLines(const char *filename, char *str)
{
	FILE *file;
	char c;
	int count = 0;
	(void)str;
	file = fopen(filename, "r");
	while((c = fgetc(file)) != EOF) {
      if(c == '\n')
         count++;
   }
	printf("number of lines: %d\n", count);
	fclose(file);
	return RUN;
}

status_t exitFile(const char *filename, char *str)
{
	(void)str;
	(void)filename;
	return STOP;
}

status_t addToBegining(const char *filename, char *str)
{
	FILE *tmp = fopen("tmp.txt", "a+");
	FILE *file = fopen(filename, "r");
	++str;
	fprintf(tmp, "%s\n", str);
	fflush(tmp);
	Filecpy(tmp, file);
	fclose(tmp);
	fclose(file);
	removeFile(filename,str);
	rename (filename, "tmp.txt");
	return (0 == fclose(file)) ? RUN : REMOVE_ERR;
}
status_t Filecpy(FILE *dest, FILE *src)
{
    int ch = 0;

    assert(NULL != dest);
    assert(NULL != src);

    ch = getc(src);

    while (EOF != ch)
    {
        fputc(ch, dest);
        ch = getc(src);
    }
   

    return RUN;
}

status_t printToFile(const char *filename, char *str)
{
	FILE *fp = fopen(filename, "a+");
	if(fp == NULL)
	{
		printf("cant open file %d", ERR); 
	}
	
	fprintf(fp, "%s\n", str);

	return (0 == fclose(fp)) ? RUN : REMOVE_ERR;
}


/***************************************************************/
int cmpChar(const char* usrStr, const char* inputStr)
{
		return !(*usrStr == *inputStr) ;
}

/****************************************************************/
void initStructArray(struct sInput sInArr[])
{
	sInArr[0].str = "-remove";
	sInArr[0].fpcmp = strcmp;
	sInArr[0].fpof = removeFile;
	
	sInArr[1].str = "-count";
	sInArr[1].fpcmp = strcmp;
	sInArr[1].fpof = countLines;

	sInArr[2].str = "-exit";
	sInArr[2].fpcmp = strcmp;
	sInArr[2].fpof = exitFile;
	
	sInArr[3].str = "<";
	sInArr[3].fpcmp = cmpChar;
	sInArr[3].fpof = addToBegining;
}

status_t activate(struct sInput sInArr[],  char *str, const char *filename)
{
	int i;
	status_t res = 1;
	for (i = 0; i < 4; i++)
	{
		if(0 == sInArr[i].fpcmp(str, sInArr[i].str))
		{
			res = sInArr[i].fpof(filename, str); 
			return res;
		}
	}
	
	res = printToFile(filename, str); 
	return res;
}

status_t stringFromUser(char *filename)
{
	status_t status = RUN;

	struct sInput sInArr[4];

	char str[40] = {0};

	initStructArray(sInArr);
	while (status == RUN){
	printf("please enter a string and press ENTER\n");
	scanf(" %[^\n]s",str);
	status = activate(sInArr, str, filename); 
	}
	
	return status;
}
