/******************************************************************************
 * Title:		queue_list_test
 * Description:	
 * Author:		Mor Gafson
 * Reviewer:	
 * 
 * InfinityLabs OL95
 *****************************************************************************/
#include <assert.h> /* assert() */
#include <stdio.h>  /* malloc(), free() */
#include <stdlib.h> /*printf()*/
#include <string.h> /*strlen*/
#include "cbuff.h" /* queue function */


/* (in .c file:)
 
struct circular_buffer
{
	size_t read;
	size_t write;
	size_t capacity;
	char data[1];
};*/


void TestCBuffCreate(void);
void TestCBuffRead(void);
void TestCBuffWrite(void);
void TestCBuffIsEmpty(void);
void TestCBuffFreeSpace(void);
void TestCBuffCapacity(void);



/*******************************************************************************
                             main                               
*******************************************************************************/
int main(void)
{
	TestCBuffCreate();
	TestCBuffRead();
	TestCBuffWrite();
	TestCBuffIsEmpty();
	TestCBuffFreeSpace();
	TestCBuffCapacity();
	
	return 0;
}


/*******************************************************************************
                             TestCreate                             
*******************************************************************************/

void TestCBuffCreate(void)
{
	size_t capacity = 10;
	c_buff_t *cbuff = CBuffCreate(capacity);
	printf("\n\033[1;33m Test CBuffCreate\n");
	if(NULL != cbuff)
	{
		printf("\n\033[1;32m test successed!\n");

	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	CBuffDestroy(cbuff);
}

void TestCBuffRead(void)
{
	size_t capacity1 = 8;
	size_t capacity2 = 5;
	size_t capacity3 = 3;
	char src[] = "hello";
	c_buff_t *cbuff1 = CBuffCreate(capacity1);
	c_buff_t *cbuff2 = CBuffCreate(capacity2);
	c_buff_t *cbuff3 = CBuffCreate(capacity3);
		
	printf("\n\033[1;33m Test CBuffRead\n");
	
	if(	NULL == cbuff1 || NULL == cbuff2)
	{
		printf("\n\033[1;31m CBuffCreate failed!\n");
		return;
	}
	
	CBuffWrite(cbuff1,src, strlen(src));
	CBuffWrite(cbuff2,src, strlen(src));
	CBuffWrite(cbuff3,src, strlen(src));

	if(CBuffFreeSpace(cbuff1) == 3 && CBuffFreeSpace(cbuff2) == 0 && CBuffFreeSpace(cbuff3) == 0)
	{
		CBuffRead(cbuff1,src, strlen(src));
		CBuffRead(cbuff2,src, strlen(src));
		CBuffRead(cbuff3,src, strlen(src));
	
		if(CBuffIsEmpty(cbuff1) == 1 && CBuffIsEmpty(cbuff2) == 1 && CBuffIsEmpty(cbuff3) == 1)
		{
			printf("\n\033[1;32m test successed!\n");
		}
			
		else
		{
			printf("\n\033[1;31m test failed!\n");
		}
	}
	else
	{
		printf("\n\033[1;31m test CBuffWrite failed!\n");
	}
	CBuffDestroy(cbuff1);
	CBuffDestroy(cbuff2);
	CBuffDestroy(cbuff3);
}
void TestCBuffWrite(void)
{
	size_t capacity1 = 8;
	size_t capacity2 = 5;
	size_t capacity3 = 3;
	char src[] = "hello";
	c_buff_t *cbuff1 = CBuffCreate(capacity1);
	c_buff_t *cbuff2 = CBuffCreate(capacity2);
	c_buff_t *cbuff3 = CBuffCreate(capacity3);
		
	printf("\n\033[1;33m Test CBuffWrite\n");
	
	if(	NULL == cbuff1 || NULL == cbuff2)
	{
		printf("\n\033[1;31m CBuffCreate failed!\n");
		return;
	}
	
	CBuffWrite(cbuff1,src, strlen(src));
	CBuffWrite(cbuff2,src, strlen(src));
	CBuffWrite(cbuff3,src, strlen(src));

	if(CBuffFreeSpace(cbuff1) == 3 && CBuffFreeSpace(cbuff2) == 0 && CBuffFreeSpace(cbuff3) == 0)
	{
		printf("\n\033[1;32m test successed!\n");
	}		
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	
	CBuffDestroy(cbuff1);
	CBuffDestroy(cbuff2);
	CBuffDestroy(cbuff3);
}
void TestCBuffIsEmpty(void)
{
	size_t capacity1 = 8;
	size_t capacity2 = 5;
	char src[] = "hello";
	c_buff_t *cbuff1 = CBuffCreate(capacity1);
	c_buff_t *cbuff2 = CBuffCreate(capacity2);
	
	printf("\n\033[1;33m Test CBuffIsEmpty\n");
	
	if(	NULL == cbuff1 || NULL == cbuff2)
	{
		printf("\n\033[1;31m CBuffCreate failed!\n");
		return;
	}
	
	CBuffWrite(cbuff1,src, strlen(src));
	
	if(CBuffIsEmpty(cbuff2) == 1 && CBuffIsEmpty(cbuff1) == 0)
	{
		CBuffRead(cbuff1,src, strlen(src));
		CBuffWrite(cbuff2,src, 1);
		if(CBuffIsEmpty(cbuff1) == 1 && CBuffIsEmpty(cbuff2) == 0)
		{
			printf("\n\033[1;32m test successed!\n");
		}
			
		else
		{
			printf("\n\033[1;31m test failed!\n");
		}
	}
	else
	{
		printf("\n\033[1;31m test CBuffWrite failed!\n");
	}
	CBuffDestroy(cbuff1);
	CBuffDestroy(cbuff2);
}

void TestCBuffFreeSpace(void)
{
	c_buff_t *cbuff1 = CBuffCreate(6);
	c_buff_t *cbuff2 = CBuffCreate(6);
	char *src = "hello";
	printf("\n\033[1;33m Test TestCBuffFreeSpace\n");
	if(NULL == cbuff1)
	{
		printf("CBuffFreeSpace doesn't work\n");
	}
	else
	{
		if(CBuffFreeSpace(cbuff1) == 6) 
		{
			printf("\n\033[1;32m CBuffFreeSpace test 1 workS\n");
		}
		else
		{
			printf("\n\033[1;31m CBuffFreeSpace test 1 doesn't work\n");	
		} 					
	}
	
	if(NULL == cbuff2)
	{
		printf("\n\033[1;31m CBuffCreate doesn't work\n");
	}
	else
	{
		CBuffWrite(cbuff2, src, 6);
		if(CBuffFreeSpace(cbuff2) == 0) 
		{
			printf("\n\033[1;32m CBuffFreeSpace test 2 workS\n");
		}
		else
		{
			printf("\n\033[1;31m CBuffFreeSpace test 2 doesn't work\n");	
		} 					
	}
	
	
	CBuffDestroy(cbuff1);
	CBuffDestroy(cbuff2);
}
void TestCBuffCapacity(void)
{
	size_t capacity = 10;
	c_buff_t *cbuff = CBuffCreate(capacity);
	
	printf("\n\033[1;33m Test CBuffCapacity\n");
	
	if(	NULL == cbuff)
	{
		printf("\n\033[1;31m CBuffCreate failed!\n");
		return;
	}

	if(CBuffCapacity(cbuff) == 10)
	{
		printf("\n\033[1;32m test successed!\n");

	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	CBuffDestroy(cbuff);

}
