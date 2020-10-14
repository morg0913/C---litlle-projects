/******************************************************************************
 * Title:		dynamic_vector_test
 * Description:	
 * Author:		Mor Gafson
 * Reviewer:	
 * 
 * InfinityLabs OL95
 *****************************************************************************/
#include "dynamic_vector.h"
#include <stdio.h>
#include <stdlib.h>

struct dynamic_vector
{
	void *vector;
	size_t num_of_elements;
	size_t capacity;
	size_t element_size;
};

void TestVectorCreate(void);
void TestVectorGetElement(void);
void TestVectorPopBack(void);
void TestVectorPushBack(void);
void TestVectorSize(void);
void TestVectorCapacity(void);
void TestVectorResize(void);

int main(void)
{
    TestVectorCreate();
    TestVectorGetElement();
    TestVectorPopBack();
    TestVectorPushBack();
    TestVectorSize();
    TestVectorCapacity();
    TestVectorResize();

    return 0;
}


void TestVectorCreate(void)
{
	size_t capacity = 50;
	size_t element_size_int = sizeof(int);
	vector_t *v1 = VectorCreate(capacity, element_size_int);
	
	printf("\n\033[1;36m Test StackCreate: \n");
	printf("\033[0m");
	if(v1 != NULL )
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
	}
	else
		{
			printf("1;31m FAILED test\n");
			printf("\033[0m");
		}
	VectorDestroy(v1);
}

void TestVectorDestroy(void)
{
	printf("\n\033[1;36m Test StackDestroy: check in VLG\n");
	printf("\033[0m");
}


void TestVectorGetElement(void)
{
	size_t capacity = 5;	
	size_t element_size = sizeof(int);
	int elm1 = 1;
	vector_t *v1 = VectorCreate(capacity , element_size);
	printf("\n\033[1;36m Test VectorGetElement\n");
	if(v1 != NULL)
	{
		VectorPushBack(v1, &elm1);
	
		if((*(int*)VectorGetElement(v1 , 0)) == elm1)
		{
			printf("\n\033[1;32m VectorGetElement successed!\n");
		}
		else
		{
			printf("\n\033[1;31m VectorGetElement failed!\n");
		}	
	}
	else
	{
		printf("\n\033[1;31m VectorCreate failed!\n");
	}
	VectorDestroy(v1);	
}


void TestVectorPopBack(void)
{
	size_t capacity = 5;	
	size_t element_size = sizeof(int);
	int elm1 = 1;
	int elm2 = 2;
	int elm3 = 3;
	vector_t *v1 = VectorCreate(capacity , element_size);
	printf("\n\033[1;36m Test VectorPopBack\n");
	if(v1 != NULL)
	{
		VectorPushBack(v1, &elm1);
		VectorPushBack(v1, &elm2);
		VectorPushBack(v1, &elm3);
		VectorPopBack(v1);
		if((*(int*)VectorGetElement(v1 , (VectorSize(v1)-1))) == elm2)
		{
			printf("\n\033[1;32m VectorPopBack successed!\n");
		}
		else
		{
			printf("\n\033[1;31m VectorPopBack failed!\n");
		}	
	}
	else
	{
		printf("\n\033[1;31m VectorCreate failed!\n");
	}
	VectorDestroy(v1);
}


void TestVectorPushBack(void)
{
	size_t capacity = 5;	
	size_t element_size = sizeof(int);
	int elm1 = 1;
	int elm2 = 2;
	int elm3 = 3;
	vector_t *v1 = VectorCreate(capacity , element_size);
	printf("\n\033[1;36m Test VectorPushBack\n");
	if(v1 != NULL)
	{
		VectorPushBack(v1, &elm1);
		VectorPushBack(v1, &elm2);
		VectorPushBack(v1, &elm3);
		if((*(int*)(VectorGetElement(v1 , 2))) == elm3)
		{
			printf("\n\033[1;32m VectorPushBack successed!\n");
		}
		else
		{
			printf("\n\033[1;31m VectorPushBack failed!\n");
		}	
	}
	else
	{
		printf("\n\033[1;31m VectorCreate failed!\n");
	}
	VectorDestroy(v1);	

}

void TestVectorSize(void)
{
	size_t capacity = 5;	
	size_t element_size = sizeof(int);
	int elm1 = 1;
	int elm2 = 2;
	int elm3 = 3;
	vector_t *v1 = VectorCreate(capacity , element_size);
	printf("\n\033[1;36m Test VectorSize\n");
	if(v1 != NULL)
	{
		VectorPushBack(v1, &elm1);
		VectorPushBack(v1, &elm2);
		VectorPushBack(v1, &elm3);
		if(VectorSize(v1) == 3)
		{
			printf("\n\033[1;32m VectorSize successed!\n");
		}
		else
		{
			printf("\n\033[1;31m VectorSize failed!\n");
		}	
	}
	else
	{
		printf("\n\033[1;31m VectorCreate failed!\n");
	}
	VectorDestroy(v1);	

}


void TestVectorCapacity(void)
{
    size_t capacity = 5;    
    size_t element_size = sizeof(int);
    vector_t *v1 = VectorCreate(capacity , element_size);
    printf("\n\033[1;36m Test VectorCapacity\n");
    if(v1 != NULL)
    {
        if(VectorCapacity(v1) == 5)
        {
            printf("\n\033[1;32m VectorCapacity successed!\n");
        }
        else
        {
            printf("\n\033[1;31m VectorCapacity failed!\n");
        }    
    }
    else
    {
        printf("\n\033[1;31m VectorCreate failed!\n");
    }
    VectorDestroy(v1);    

    
}


void TestVectorResize(void)
{
	size_t capacity = 5;	
	size_t element_size = sizeof(int);
	size_t new_size = 12;
	vector_t *v1 = VectorCreate(capacity, element_size);
	printf("\n\033[1;36m Test VectorResize\n");
	if(v1 != NULL)
	{
		VectorResize(v1 , new_size);
		if(VectorCapacity(v1) == 12)
		{
			printf("\n\033[1;32m VectorResize successed!\n");
		}
		else
		{
			printf("\n\033[1;31m VectorResize failed!\n");
		}	
	}
	else
	{
		printf("\n\033[1;31m VectorCreate failed!\n");
	}
	VectorDestroy(v1);	
}
