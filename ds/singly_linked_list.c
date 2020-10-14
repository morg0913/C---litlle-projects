/********************************************
File name : singly_linked_list
Author : Mor Gafson
Reviewer : 
Infinity Labs OL95	
*******************************************/

#include "singly_linked_list.h"
#include <assert.h> /*assert*/
#include <stdio.h>  /* malloc(), free() */
#include <stdlib.h> /*printf()*/
#include <string.h> /* memcpy() */
#include <stddef.h> /*size_t*/



struct node 
{
	void *data;
	node_t *next;
};

struct singly_linked_list
{
	node_t *begin;
	node_t *end;
};


slist_t *SListCreate(void)
{
	slist_t *list = NULL;
	node_t *dummy = NULL;

	list = (slist_t *)malloc(sizeof(slist_t));

	if(NULL == list)
	{
		return NULL;
	}

	dummy = (node_t *)malloc(sizeof(node_t));

	if(NULL == dummy)
	{
		free(list);
		list = NULL;
		return NULL;
	}

	dummy->data = NULL;
	dummy->next = NULL;
	list->end = dummy;
	list->begin = list->end;

	return list;
}

 
void SListDestroy(slist_t *list)
{
	slist_iter_t runner = NULL;
	assert(NULL != list);
	
	runner = SListBegin(list);
	while ( 1 != SListIsSameIter(runner,SListEnd(list)))
	{
		slist_iter_t tmp = runner;
		runner = SListNextIter(runner);
		free(tmp);
	}
	free(SListEnd(list));
	free(list);
	list = NULL;
}


int SListPushBack(slist_t *list, const void *data)
{
		assert(NULL != list && NULL != data);
	return SListInsertBefore(list, list->end, data);
}


 
void SListPopBack(slist_t *list)
{
	slist_iter_t runner = NULL;
	assert(NULL != list);
	if(SListIsEmpty(list) ==1 )
	{
		return;
	}
	runner = SListBegin(list);
	while (1 != SListIsSameIter(runner->next, SListEnd(list)))
	{
		runner = SListNextIter(runner);
	}
	SListRemove(list, runner);
}

 int SListInsertBefore (slist_t *list, slist_iter_t next_iterator, const void *data)
{
	slist_iter_t newNode = (node_t*)malloc(sizeof(node_t));

	if(NULL == newNode)
	{
		return 1;
	}
    newNode->data = next_iterator->data;
    newNode->next = next_iterator->next;
	next_iterator->data = (void*)data;
	next_iterator->next = newNode;
	if(SListIsEmpty(list) == 1)
	{
		list->begin = next_iterator;
	}
	if(SListIsSameIter(next_iterator,list->end) == 1)
	{
		list->end = newNode;
	}
	return 0;
}

void SListRemove(slist_t *list, slist_iter_t iterator)
{
	slist_iter_t tmp = iterator->next;
	assert ((NULL != list) && (NULL != iterator));
    (void)list;
    if(iterator->next == list->end)
    {
        list->end = iterator; 
    }	
    iterator->data = iterator->next->data;
    iterator->next = iterator->next->next;
	free(tmp);
}

 
slist_iter_t SListFindIter (const slist_t *list, const compare_t compare, const void *data)
{ 
	slist_iter_t runner = SListBegin(list);
	
	assert(NULL != list);
	assert (NULL != data);
	assert(NULL != compare);
	
	while(1 != SListIsSameIter(runner, SListEnd(list)))
	{

		if (0 == compare(runner->data , data))
		{
			return runner;
		}

		runner = SListNextIter(runner);
	}
	return SListEnd(list);
}



 
int SListForEachIter(slist_iter_t first, slist_iter_t last, const action_function_t func, void *param)
{
	int res = 0;
	
	assert(NULL != first);
	assert(NULL != last);
	assert(NULL != func);
	assert(NULL != param);
	
	while(SListIsSameIter(first, last) != 1 || res != 0)
	{
		res = func(first->data, param);
		first = SListNextIter(first);
	}
	return res;
}
 
size_t SListSize(const slist_t *list)
{
	slist_iter_t runner = SListBegin(list);
	size_t count = 0;
	assert(NULL != list);
	while(SListIsSameIter(runner, SListEnd(list)) != 1)
	{
		runner = SListNextIter(runner);
		count++;
	}
	return count;
}

 
slist_iter_t SListBegin(const slist_t *list)
{
	assert(NULL != list);
	return list->begin;
}

 
slist_iter_t SListEnd(const slist_t *list)
{
	assert(NULL != list);
	return list->end;
}


slist_iter_t SListNextIter( slist_iter_t iterator)
{
	assert(NULL != iterator);
	return iterator->next;
}


void *SListGetData(slist_iter_t iterator)
{
	assert(NULL != iterator);
	return iterator->data;
}


int SListIsEmpty(const slist_t *list)
{
	assert(NULL != list);
	return(SListIsSameIter(SListBegin(list),SListEnd(list)));
}


int SListIsSameIter (slist_iter_t iterator1, slist_iter_t iterator2)
{

    if(iterator1 == iterator2) 
    {
        return 1;
    }
    return 0;
}

void SListAppend(slist_t *src, slist_t *dest)
{
	dest->end->data = src->begin->data;
	dest->end->next = src->begin->next;
	dest->end = src->end;
	src->begin->data = NULL;
	src->begin->next = NULL;
	src->end = src->begin;
}

