/********************************************
File name : doubly_linked_list
Author : Mor Gafson
Reviewer : 
Infinity Labs OL95	
*******************************************/

#include "doubly_linked_list.h"

#include <assert.h> /*assert*/
#include <stdio.h>  /* malloc(), free() */
#include <stdlib.h> /*printf()*/

static node_t *extract(dlist_iter_t iter);
/***************************************************************************/
struct node 
{
	void *data;
	node_t *next;
	node_t *prev;
};

struct doubly_linked_list 
{
	node_t head;
	node_t tail;
	
};


/***************************************************************************/

dlist_t *DListCreate(void)
{
	dlist_t *list = (dlist_t *)malloc(sizeof(dlist_t));

	if(NULL == list)
	{
		return NULL;
	}

	list->head.data = NULL;
	list->tail.data = NULL;

	list->head.next = &list->tail;
	list->tail.next = NULL;

	list->head.prev = NULL;
	list->tail.prev = &list->head;

	return list;
} 
void DListDestroy(dlist_t *list)
{
	dlist_iter_t runner = {0};

	assert(NULL != list);

	runner = DListBegin(list);
	
	while(!DListIsEmpty(list))
	{
		runner = DListRemove(list, runner);
	}
	
}
dlist_iter_t DListPushBack(dlist_t *list, const void *data)
{
	return DListInsert(list, DListEnd(list), data);
}
void DListPopBack(dlist_t *list)
{
	DListRemove(list, DListPrevIter(DListEnd(list)));
}
dlist_iter_t DListInsert(dlist_t *list, dlist_iter_t next_iterator, const void *data)
{
	dlist_iter_t iter = {0};
	node_t *newNode = (node_t*)malloc(sizeof(node_t*));
	if(NULL == newNode)
	{
		return DListEnd(list);
	}
	
	newNode->data = (void*)data;
	newNode->prev = DListPrevIter(next_iterator).internal;
	newNode->next = next_iterator.internal;

	extract(DListPrevIter(next_iterator))->next = newNode;
	extract(next_iterator)->prev = newNode;
	
	iter.internal = newNode;
	return iter;
}
dlist_iter_t DListRemove(dlist_t *list, dlist_iter_t iterator)
{
	dlist_iter_t iter = {0};

	if(DListIsEmpty(list))
	{
		return DListEnd(list);
	}
	iter = DListNextIter(iterator);
	
	extract(DListPrevIter(iterator))->next = extract(DListNextIter(iterator));
	extract(DListNextIter(iterator))->prev = extract(DListPrevIter(iterator));

	extract(iterator)->next = NULL;
	extract(iterator)->prev = NULL;

	free(iterator.internal);
	return iter;
}
 
dlist_iter_t DListFind(dlist_iter_t from, dlist_iter_t to, is_match_t is_match, const void *data)
{
	dlist_iter_t itr = {NULL};

	itr = from;

	while(1 != DListIsSameIter(itr, to))
	{
		if(is_match(DListGetData(itr), data) == 1)
		{
			return itr;
		}
		itr = DListNextIter(itr);
	}

	return to;
}
int DListForEach(dlist_iter_t from, dlist_iter_t to, action_t func, void *param)
{
	dlist_iter_t itr = {NULL};
	itr = from;

	while(1 != DListIsSameIter(itr, to))
	{
		int num = func(DListGetData(itr), param);
		if(num != 0)
		{
			return 1;
		}
		itr = DListNextIter(itr);
	}
	return 0;
		
}
size_t DListSize(const dlist_t *list)
{
	size_t count = 0;
	dlist_iter_t itr = {NULL};
	itr = DListBegin(list);
	
	while(1 != DListIsSameIter(itr, DListEnd(list)))
	{
		itr = DListNextIter(itr);
		++count;
	}
	return count;
}
dlist_iter_t DListBegin(const dlist_t *list)
{
	dlist_iter_t itr = {NULL};
	dlist_t *listPointer = (dlist_t*)list;
	itr.internal = listPointer->head.next;

	return itr;
}
dlist_iter_t DListEnd(const dlist_t *list)
{
	dlist_iter_t itr = {NULL};
	dlist_t *listPoint = (dlist_t*)list;
	itr.internal = &listPoint->tail;

	return itr;
}

dlist_iter_t DListNextIter(dlist_iter_t iterator)
{
	iterator.internal = iterator.internal->next;
	return iterator;
}

dlist_iter_t DListPrevIter(dlist_iter_t iterator)
{
	iterator.internal = iterator.internal->prev;
	return iterator;
}

void *DListGetData(dlist_iter_t iterator)
{
	return iterator.internal->data;
}

int DListIsEmpty(const dlist_t *list)
{
	
	if(DListIsSameIter(DListBegin(list), DListEnd(list)) == 1)
	{
		return 1;
	}
	return 0;
}
int DListIsSameIter(dlist_iter_t iterator1, dlist_iter_t iterator2)
{
	return ( iterator1.internal == iterator2.internal) ? 1 : 0;
}

dlist_iter_t DListSplice(dlist_iter_t dest_iter, dlist_iter_t from, dlist_iter_t to)
{
	dlist_iter_t tmp = DListNextIter(dest_iter);

	from.internal->prev->next = to.internal->
	dest_iter.internal->next = from.internal;
	from.internal->prev = dest_iter.internal;

	tmp.internal->prev = to.internal;
	to.internal->next = tmp.internal;

	return tmp;
}

int DListMultiFind(dlist_iter_t from, dlist_iter_t to, is_match_t is_match, const void *data, dlist_t *output_list)
{
	int match = 3;
	dlist_iter_t itr = {NULL};

	while(1 != DListIsSameIter(from, to))
	{
		match = is_match(DListGetData(from),data);
		if(match == 1)
		{
			itr = DListPushBack(output_list, data);
			if(DListIsSameIter(itr, DListEnd(output_list)) == 1)
			{
				return 1;
			}
		}
		from = DListNextIter(from);
	}
	return 0;
}
 
/*************************************************/
static node_t *extract(dlist_iter_t iter)
{
	return iter.internal;
}
