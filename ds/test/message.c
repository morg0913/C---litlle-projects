/************************************************************************
Title: data structures ws4 SingleLinkedList
Description: implement to basic function of Single Linked List
Author: MOR ESPRESKO
Reviewer: 
InfinityLabs OL95
*************************************************************************/
#include "cbuff.h" /*import lib*/
#include <stdlib.h> /* malloc,free*/
#include <assert.h> /* assert */
#include <stdio.h>
#define MALLOCTEST(a) if(NULL == a) return NULL 


/*******************************************************************************
*                              struct                                          *
*******************************************************************************/

static int flag = 0; /*status*/

struct circular_buffer
{
	size_t read;
	size_t write;
	size_t capacity;
	char data[1];
};


/*******************************************************************************
*                              forward declirations                            *
*******************************************************************************/

c_buff_t *CBuffCreate(size_t capacity);
void CBuffDestroy(c_buff_t *cbuff);
size_t CBuffWrite(c_buff_t *cbuff, void *src, size_t count);
size_t CBuffRead(c_buff_t *cbuff, void *dest, size_t count);
int CBuffIsEmpty(const c_buff_t *cbuff);
size_t CBuffFreeSpace(const c_buff_t *cbuff);
size_t CBuffCapacity(const c_buff_t *cbuff);



/*******************************************************************************
*                             implements                            *
*******************************************************************************/


c_buff_t *CBuffCreate(size_t capacity)
{
	c_buff_t *cbuff = (c_buff_t *)malloc(sizeof(c_buff_t) + capacity - 1);	
	
	assert (0 < capacity);
	MALLOCTEST(cbuff);
	
	cbuff->capacity = capacity;
	cbuff->read = 0;
	cbuff->write = 0;
	
	return cbuff;
}



void CBuffDestroy(c_buff_t *cbuff)
{
	assert(NULL != cbuff);
	
	free(cbuff);
	cbuff = NULL;
}



size_t CBuffWrite(c_buff_t *cbuff, void *src, size_t count)
{
	size_t mone = 0;
	size_t index = 0;
    	size_t readcount = CBuffFreeSpace(cbuff);
	assert(NULL != cbuff);
	assert(NULL != src);
	assert(0 < count);
	
	if(0 == CBuffFreeSpace(cbuff))
	{
		return mone;
	}
	
	if(count > CBuffFreeSpace(cbuff))
	{
		count = CBuffFreeSpace(cbuff);
	}
	
	while(0 < count && readcount(cbuff) > 0)
	{
readcount--;
		cbuff->data[cbuff->write] = *(char *)src + 1;/*write*/
		++cbuff->write; 
		++mone;
		--count;
		++index;
		cbuff->write = ((cbuff->write) % (cbuff->capacity)); /*to creata circular movement*/
	}
	if (cbuff->write == cbuff->read)
	{
		flag = 1;
	}		 			
	
	return mone;		
	
}


size_t CBuffRead(c_buff_t *cbuff, void *dest, size_t count)
{
	size_t index = 0;
	size_t tot = 0;
	
	assert(NULL != cbuff);
	assert(NULL != dest);
	assert(0 < count);
	
	if (count > cbuff->capacity - CBuffFreeSpace(cbuff))
	{
		count = cbuff->capacity - CBuffFreeSpace(cbuff);
	}
	
	flag = 0;
	
	tot = count;
	
	while((count > 0))
	{
		*((char*)dest + index) = cbuff->data[cbuff->read];
		++cbuff->read ;
		cbuff->read  = (cbuff->read) % (cbuff->capacity);
		++index;
		--count;
	}
	
	return tot;
}

int CBuffIsEmpty(const c_buff_t *cbuff)
{
	assert(NULL != cbuff);
	

	if(( CBuffCapacity(cbuff) == CBuffFreeSpace(cbuff)))
	{
		return 1;
	}
	return 0;
	
}


size_t CBuffFreeSpace(const c_buff_t *cbuff)
{
	
	assert(NULL != cbuff);
	
	if(flag == 1)
	{
		return 0;
	}
	return (cbuff->capacity - ((cbuff->write - cbuff->read)));
	
	/*
	if(cbuff->write >= cbuff->read)
	{
		return (cbuff->capacity - ((cbuff->write - cbuff->read)));	
	}
	*/
	
}




size_t CBuffCapacity(const c_buff_t *cbuff)
{
	assert(NULL != cbuff);
	
	return  cbuff->capacity;
}



























