#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ARR_SIZE 5
#define STR_SIZE 50




typedef struct element
{
	void* ptr;
	void(*AddInt)(struct element*, int);
	void(*PrintElem)(struct element*);
	void(*CleanUpElem)(struct element*);

} element_t;

void AddToInt(element_t *element, int num);
void AddToFloat(element_t *element, int num);
void AddToStr(element_t *element, int num);
size_t CountDigits(int num);
void InitStructArray(element_t *elem_arr);
void PrintInt(element_t *element);
void PrintFloat(element_t *element);
void PrintStr(element_t *element);
void PrintElementsArray(element_t *arr);
void AddElementsArray(element_t *arr, int num);
void *FloatToVoid(float real_num);
float VoidToFloat(void *real_num);
void CleanUpNum(element_t *elem);
void CleanUpStr(element_t *elem);
void CleanUpElementsArray(element_t *arr);

int main(void)
{	

	element_t elem_arr[ARR_SIZE];
	InitStructArray(elem_arr);							

	PrintElementsArray(elem_arr);
	
	AddElementsArray(elem_arr, 10);
	printf("-----\n");
	PrintElementsArray(elem_arr);
CleanUpElementsArray(elem_arr);
	
	
	return 0;
}

void InitStructArray(element_t *elem_arr)
{
	float num1 = 4.7;
	float num2 = 6.7;	
	char *str1 = malloc(sizeof(char)*8);
	int num3 = 12;
	float num4 = 56.32;
	
 	strcpy(str1, "chapter");

	elem_arr[0].ptr = (void*)*(long*)&num1;
	elem_arr[0].AddInt = &AddToFloat;
	elem_arr[0].PrintElem = &PrintFloat;
	elem_arr[0].CleanUpElem = &CleanUpNum;

	elem_arr[1].ptr = (void*)*(long*)&num2;
	elem_arr[1].AddInt = &AddToFloat;
	elem_arr[1].PrintElem = &PrintFloat;
	elem_arr[1].CleanUpElem = &CleanUpNum;

	elem_arr[2].ptr = (void*)str1;
	elem_arr[2].AddInt = &AddToStr;
	elem_arr[2].PrintElem = &PrintStr;
	elem_arr[2].CleanUpElem = &CleanUpStr;

	elem_arr[3].ptr = (void*)(long)num3;
	elem_arr[3].AddInt = &AddToInt;
	elem_arr[3].PrintElem = &PrintInt;
	elem_arr[3].CleanUpElem = &CleanUpNum;

	elem_arr[4].ptr = (void*)*(long*)&num4;
	elem_arr[4].AddInt = &AddToFloat;
	elem_arr[4].PrintElem = &PrintFloat;
	elem_arr[4].CleanUpElem = &CleanUpNum;
}


void AddElementsArray(element_t *arr, int num)
{	
	int i = 0;
	for(i = 0; i < ARR_SIZE; i++)
	{
		(arr[i].AddInt)(&arr[i], num);
	}
}


void PrintElementsArray(element_t *arr)
{	
	int i = 0;
	for(i = 0; i < ARR_SIZE; i++)
	{
		(arr[i].PrintElem)(&arr[i]);
	}
}

void CleanUpElementsArray(element_t *arr)
{	
	int i = 0;
	for(i = 0; i < ARR_SIZE; i++)
	{
		(arr[i].CleanUpElem)(&arr[i]);
	}
}

void AddToInt(element_t *elem, int num)
{
	elem->ptr = (void*)((long)(elem->ptr) + (long)num);
}


void *FloatToVoid(float real_num)
{
    long *num = (long *)&real_num;

    return (void *)*num;
}


float VoidToFloat(void *real_num)
{
    float *num = (float *)&real_num;
	
    return *num;
}


void AddToFloat(element_t *elem, int num)
{
	float sum = VoidToFloat(elem->ptr) + (float)num;
    elem->ptr = FloatToVoid(sum);   
}


size_t CountDigits(int num)
{
	size_t counter = 0;
	
	while (1 <= num)
	{
		num = num / 10;
		++counter;
	}

	return counter;
}

void AddToStr(element_t *elem, int num)
{	
	size_t len_num = CountDigits(num);
	size_t len_str = strlen(elem->ptr);
	char num_str[STR_SIZE];	
	elem->ptr = (char*)realloc(elem->ptr, (len_num+len_str));
	
	sprintf(num_str, "%d", num);

	strcat(elem->ptr, num_str);
}

void PrintInt(element_t *elem)
{
	printf("Int elem is: %ld\n", (long)elem->ptr);
}

void PrintFloat(element_t *elem)
{
	printf("Float elem is: %f\n", *((float*)&(elem->ptr)));
}

void PrintStr(element_t *elem)
{
	printf("String elem is: %s\n", (char*)elem->ptr);
}

void CleanUpNum(element_t *elem)
{
	elem->ptr = NULL;
	elem->AddInt = NULL;
	elem->PrintElem = NULL;
	elem->CleanUpElem = NULL;
}


void CleanUpStr(element_t *elem)
{
	free(elem->ptr);
	elem->ptr = NULL;
	elem->AddInt = NULL;
	elem->PrintElem = NULL;
	elem->CleanUpElem = NULL;
}

