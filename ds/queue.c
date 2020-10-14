/******************************************************************************
 * Title:		Queue.c
 * Description:	Implementations of Queue
 * Author:		Mor Gafson
 * Reviewer:		
 * 
 * InfinityLabs OL95
 *****************************************************************************/
#include <assert.h> /* assert() */
#include <stdio.h>  /* malloc(), free() */
#include <stdlib.h> /*printf()*/
#include "queue.h" /* queue function */
#include "singly_linked_list.h"

/**********************************queue************************************/
struct queue
{
	slist_t *list;
};

/*******************************************************************************
                             QCreate                             
*******************************************************************************/
queue_t *QueueCreate(void)
{
	queue_t *qu = (queue_t*)malloc(sizeof(queue_t));
	
	if(NULL == qu)
	{
		return NULL;
	}
	
	qu->list = SListCreate();
	if(NULL == qu->list)
	{
		free(qu);
		return NULL;
	}

	return qu;
}
/*******************************************************************************
                             QueueDestroy                             
*******************************************************************************/
void QueueDestroy(queue_t *queue)
{
	assert(NULL != queue);
	SListDestroy(queue->list);
	free(queue);
}

/*******************************************************************************
                             QueueEnqueue                             
*******************************************************************************/
int QueueEnqueue(queue_t *queue, const void *data)
{
	assert((NULL != queue) || (NULL != data));
	return SListPushBack(queue->list , data);
}

/*******************************************************************************
                             QueueDequeue                             
*******************************************************************************/
void QueueDequeue(queue_t *queue)
{
	assert(NULL != queue);
	SListRemove(queue->list, SListBegin(queue->list));
}

/*******************************************************************************
                             QueueSize                             
*******************************************************************************/
size_t QueueSize(const queue_t *queue)
{
	assert(NULL != queue);
	return SListSize(queue->list);
}

/*******************************************************************************
                             QueuePeek                            
*******************************************************************************/
void *QueuePeek(const queue_t *queue)
{
	assert(NULL != queue);
	return SListGetData(SListBegin(queue->list));
}

/*******************************************************************************
                             QueueIsEmpty                             
*******************************************************************************/
int QueueIsEmpty(const queue_t *queue)
{
	assert(NULL != queue);
	return SListIsEmpty(queue->list);
}

/*******************************************************************************
                             QueueAppend                            
*******************************************************************************/
void QueueAppend(queue_t *src, queue_t *dest)
{
	assert((NULL != src) || (NULL != dest));
	SListAppend(src->list, dest->list);
}
