/******************************************************************************
 * Title:		Worksheet 6 (Bitwise operations) 
 * Description:	
 * Author:		Yehuda Gilad
 * Reviewer:	
 * 
 * InfinityLabs OL95
 *****************************************************************************/

#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

typedef struct elements
{
	void * data;
	void(*add)(struct elements*, int num);
	void(*print)(struct elements*);
	

} elements_t;


void Addtoint(elements_t *element, int num);
void Addtochar(elements_t *element, int num);
void Addtofloat(elements_t *element, int num);
float voidToFloat(void * num);
void * FloatToVoid(float num);
void printint(elements_t *element);
void printfloat(elements_t *element);
void printchar(elements_t *element);
void intial(elements_t *element);
void printelements(elements_t *element);
void addelements(elements_t *element, int add);


int main()
{
	
	elements_t element[SIZE];
	intial(element);
	printf("The original avlues of the array are: \n");
	printelements(element);
	addelements(element, 10);
	printf("The avlues of the array after addition are: \n");
	printelements(element);
	
	return 0;
	
}

void addelements(elements_t *element, int add)
{
	int i = 0;

	
	for(i = 0; i < SIZE; i++)
	{
		(element[i].add)(&element[i], add);
	
	}	
}


void printelements(elements_t *element)
{
	int i = 0;
	
	for(i = 0; i < SIZE; i++)
	{
		element[i].print(&element[i]);
	}
}

void intial(elements_t *element)
{
		
	float f1 = 4.9;
	float f2 = 6.7;	
	float f3 = 56.32;
	int num = 12;
	
	char *str = (char *)malloc(15);
	
	strcpy(str, "Helen");
	
	
		
	element[0].data = (void *)*(long*)&f1;
	element[0].add = &Addtofloat;
	element[0].print = &printfloat;
	
	element[1].data = (void *)*(long*)&f2;
	element[1].add = &Addtofloat;
	element[1].print = &printfloat;
	
	element[2].data = (void *)*(long*)&f3;
	element[2].add = &Addtofloat;
	element[2].print = &printfloat;
	
	element[3].data = (void *)(long)num;
	element[3].add = &Addtoint;
	element[3].print = &printint;
	
	element[4].data = (void *)str;
	element[4].add = &Addtochar;	
	element[4].print = &printchar; 
	
}

void Addtoint(elements_t *element, int num)
{
	element->data = (void *)((long)num + (long)(element->data));


}


void Addtochar(elements_t *element, int num)
{
	
	static char str[10];
	size_t size = 0;
	sprintf(str, "%d", num);
	size = strlen((char *)element->data)+strlen(str)+1;
	element->data = (char *)realloc(element->data, size);
	strcat((char *)element->data, str);

}


float voidToFloat(void * num)
{
	float *ret = (float *)&num;
	
	return *ret;
}

void * FloatToVoid(float num)
{
	long * ret;
	ret = (void *)*(long *)&num;
	
	return ret;
}

void Addtofloat(elements_t *element, int num)
{
	      float sum = voidToFloat(element->data) + (float)num;
	      element->data= (void *)(long)FloatToVoid(sum);
	 
}


 

void printint(elements_t *element)
{
	printf("%ld\n", (long)element->data);	
}


void printfloat(elements_t *element)
{
	printf("%f\n", *((float*)&(element->data)));	
}


void printchar(elements_t *element)
{
	printf("%s\n", (char*)(element->data));	
}






