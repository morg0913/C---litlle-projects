#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Esc (27)
int TPress();
int APress();
int DoNot();
int Escape();

static int (*fp[256])();


void ifelsefunc(){
 

	char c = getchar();
    while(c != 0x01b){
        
        if(c == 'A' || c == 'a'){
            printf("A pressed");
	}else if(c == 'T' || c == 't'){
            printf("T pressed");
	}
	c = getchar();
    }


}


void scfunc()
{
	char c = getchar();
    while(c != 0x01b){

	switch(c){ 
        case 'A':
			APress();
			break;
		case 'T':
			TPress();
			break;
	}
	c = getchar();
    }
}

int TPress()
{
	printf("T pressed");
	return 1;
}

int APress()
{
	printf("A pressed");
	return 1;
}

int DoNot()
{
	return 1;
}

int Escape()
{
	return 0;
}


void initLUT()
{
	int idx = 0;

	while (256 > idx)
	{
		fp[idx] = DoNot;
		++idx;
	}
	
	
	fp['T'] = &TPress;
	fp['A'] = &APress;
	fp[Esc] = &Escape;
}


void funcLUT()
{
	int status = 1;
	system("stty -icanon -echo");
	initLUT();
	while(status == 1)
	{
		status = getchar();
		status = fp[status]();
	}
	system("stty icanon echo");
}


int main()
{
	/*ifelsefunc();
	scfunc();*/
	
	funcLUT();

	return 0;

}
