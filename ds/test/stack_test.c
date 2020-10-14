/******************************************************************************
 * Title:		stack_test
 * Description:	
 * Author:		Mor Gafson
 * Reviewer:	
 * 
 * InfinityLabs OL95
 *****************************************************************************/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

 struct stack
{
	void *array;/*malloc - stack */
	void *current;
	size_t element_size;
	size_t capacity;
};

void TestStackCreate(void);
void TestStackDestroy(void);
void TestStackPush(void);
void TestStackPop(void);
void TestStackPeek(void);
void TestStackCapacity(void);
void TestStackIsEmpty(void);
void TestStackSize(void);



int main(void)
{
	TestStackCreate();
	TestStackDestroy();
	TestStackPush();
	TestStackPop();
	TestStackPeek();
	TestStackCapacity();
	TestStackIsEmpty();
	TestStackSize();
	return 0;
}

void TestStackCreate(void)
{
	size_t capacity = 50;
	size_t element_size_int = sizeof(int);
	stack_t *s1 = StackCreate(capacity, element_size_int);
	
	printf("\n\033[1;36m Test StackCreate: \n");
	printf("\033[0m");
	if(s1 != NULL )
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
	}
	else
		{
			printf("1;31m FAILED test\n");
			printf("\033[0m");
		}
	StackDestroy(s1);
}

void TestStackDestroy(void)
{
	printf("\n\033[1;36m Test StackDestroy: check in VLG\n");
	printf("\033[0m");
}

void TestStackPush(void)
{
    size_t element_size_int = sizeof(int);
    stack_t *s1 = StackCreate(50, element_size_int);
    stack_t *s2 = StackCreate(50, element_size_int);

    const int data1 = 5;
    const int data2 = 11;
    printf("\n\033[1;36m Test StackPush: \n");
    printf("\033[0m");
    if(s1 != NULL || s2 != NULL)
    {
        StackPush(s1, &data1);
        StackPush(s2, &data2);
        if((data1 == *(int*)StackPeek(s1) ) && (data2 == *(int*)StackPeek(s2)))
        {
            printf("\033[1;32m SUCCESS test\n");
            printf("\033[0m");    
        }
        else
            {
                    printf("\033[1;31m TestStackPush failed!\n");
                printf("\033[0m");
            }
            StackDestroy(s1);
            StackDestroy(s2);
    }
    else
    {
        printf("\033[1;31m StackCreate FAILED test\n");
        printf("\033[0m");
    }
}



void TestStackPop(void)
{
	size_t element_size_int = sizeof(int);
	stack_t *s1 = StackCreate(50, element_size_int);
	const int data1 = 5;
	StackPush(s1, &data1);

	printf("\n\033[1;36m Test StackPop: \n");
	printf("\033[0m");
	if(!StackIsEmpty(s1))
	{
		StackPop(s1);
		if(StackIsEmpty(s1))
		{
			printf("\033[1;32m SUCCESS POP test\n");
			printf("\033[0m");	
		}
		else
			{
			printf("\033[1;31m FAILED POP test\n");
			printf("\033[0m");
			}
	}
	else
		{
		printf("\033[1;31m FAILED PUSH BEFORE POP - STACK IS EMPTY  test\n");
		printf("\033[0m");
		}
	StackDestroy(s1);
}


void TestStackPeek(void)
{
	size_t element_size_int = sizeof(int);
	stack_t *s1 = StackCreate(50, element_size_int);
	const int data1 = 5;
	const int data2 = 11;
	StackPush(s1, &data1);
	StackPush(s1, &data2);

	printf("\n\033[1;36m Test StackPeek: \n");
	printf("\033[0m");
	if(!StackIsEmpty(s1))
	{
		StackPeek(s1);
		StackPeek(s1);
		if(*(int *)(StackPeek(s1)) == 11)
		{
			printf("\033[1;32m SUCCESS PEEK test\n");
			printf("\033[0m");	
		}
		else
			{
			printf("\033[1;31m FAILED PEEK test\n");
			printf("\033[0m");
			}
	}
	else
		{
		printf("\033[1;31m FAILED PUSH BEFORE PEEK - STACK IS EMPTY  test\n");
		printf("\033[0m");
		}
	StackDestroy(s1);
}


void TestStackCapacity(void)
{
	size_t element_size_int = sizeof(int);
	stack_t *s1 = StackCreate(50, element_size_int);
	
	printf("\n\033[1;36m Test StackCapacity: \n");
	printf("\033[0m");
	if(s1->capacity == 50)
	{
		printf("\033[1;32m SUCCESS StackCapacity test\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\033[1;31m FAILED StackCapacity test\n");
		printf("\033[0m");
	}
	StackDestroy(s1);
}


void TestStackIsEmpty(void)
{
	size_t element_size_int = sizeof(int);
	stack_t *s1 = StackCreate(50, element_size_int);
	const int data1 = 5;
	const int data2 = 11;
	StackPush(s1, &data1);
	StackPush(s1, &data2);
	StackPop(s1);
	StackPop(s1);

	printf("\n\033[1;36m Test StackIsEmpty: \n");
	printf("\033[0m");
	if(StackIsEmpty(s1) == 1)
	{
		printf("\033[1;32m SUCCESS StackIsEmpty test\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\033[1;31m FAILED StackIsEmpty test\n");
		printf("\033[0m");
	}
	StackDestroy(s1);
}


void TestStackSize(void)
{
	size_t element_size_int = sizeof(int);
	stack_t *s1 = StackCreate(50, element_size_int);
	const int data1 = 5;
	const int data2 = 11;
	const int data3 = 121;
	StackPush(s1, &data1);
	StackPush(s1, &data2);
	StackPush(s1, &data3);
	StackPop(s1);
	
	printf("\n\033[1;36m Test StackSize: \n");
	printf("\033[0m");
	if(StackSize(s1) == 2)
	{
		printf("\033[1;32m SUCCESS StackSize test\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\033[1;31m FAILED StackSize test\n");
		printf("\033[0m");
	}
	StackDestroy(s1);
}



