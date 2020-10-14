/********************************************
File name : circular Buffer functions
Author : Mor Gafson
Reviewer : 
Infinity Labs OL95	
*******************************************/

#include "cbuff.h"

#include <assert.h> /*assert*/
#include <stdio.h>  /* malloc(), free() */
#include <stdlib.h> /*printf()*/

/***************************************************************************/

struct circular_buffer
{
	size_t read;
	size_t write;
	size_t capacity;
	char data[1];
};

/***************************************************************************/
c_buff_t *CBuffCreate(size_t capacity)
{
	c_buff_t *cbuff = (c_buff_t*)malloc(capacity + sizeof(c_buff_t));
	if(NULL == cbuff)
	{
		return NULL;
	}
	cbuff->capacity = capacity;
	cbuff->read = 0;
	cbuff->write = 0;

	return cbuff;
	
}
void CBuffDestroy(c_buff_t *cbuff)
{
	assert(cbuff != NULL);
	free(cbuff);
	cbuff = NULL;
}


size_t CBuffRead(c_buff_t *cbuff, void *dest, size_t count)
{
    size_t readcount = 0;

        
    while(CBuffIsEmpty(cbuff) != 1 && (readcount <= count))
    {
    
        *(char*)dest = cbuff->data[cbuff->read % cbuff->capacity]; 
        dest = (void*)((size_t)dest +1);
        readcount += 1;
        ++cbuff->read;

    }     

    if(cbuff->write > cbuff->capacity && cbuff->read > cbuff->capacity)
    {
        cbuff->read -= cbuff->capacity;
        cbuff->write -= cbuff->capacity;
    }
    return readcount;


}

size_t CBuffWrite(c_buff_t *cbuff, void *src, size_t count)
{
		size_t w = (cbuff->write) % (cbuff->capacity);
    	size_t readcount = CBuffFreeSpace(cbuff);
    	size_t numOfCopeis = 0;

    while((readcount > 0) && (count > 0))
    {
		w = (cbuff->write) % (cbuff->capacity);
        cbuff->data[w] = *(char*)src;
        src = (void*)((size_t)src + 1);
        readcount--;
	count--;
       ++(cbuff->write);
	numOfCopeis++;
    }
    return numOfCopeis;
}

int CBuffIsEmpty(const c_buff_t *cbuff)
{
	return (cbuff->read == cbuff->write);
}
size_t CBuffFreeSpace(const c_buff_t *cbuff)
{
	return ((cbuff->capacity) - ((cbuff->write) - (cbuff->read)));
}
size_t CBuffCapacity(const c_buff_t *cbuff)
{
	return (cbuff->capacity);
}

