#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

 struct stack
{
	void *array;/*malloc - stack */
	void *current;
	size_t element_size;
	size_t capacity;
};


stack_t *StackCreate(size_t capacity, size_t element_size)
{
	stack_t *stack = NULL;
	assert((0 < capacity) && (0 < element_size));
	
	stack = (stack_t*)malloc(sizeof(stack_t));
	if(NULL == stack)
	{
		return NULL;
	}
	stack->array = malloc(element_size * capacity);
	if(NULL == stack->array)
	{
		return NULL;
	}
	stack->current = stack->array;
	stack->element_size = element_size;
	stack->capacity = capacity;
	return stack;
}

void StackDestroy(stack_t *stack)
{
	assert(  NULL != stack );

/*	void *p = stack->array;*/
	free(stack->array);
	stack->current = NULL;
	/*p = NULL;*/
	free(stack);
}
/* update current &  [array + current + 1]*/
void StackPush(stack_t *stack, const void *data)
{


	assert ((NULL != stack) && (NULL != data));

	if(StackCapacity(stack) <= StackSize(stack))
	{
		printf("\n\033[1;38m STACK IS FULL \n");
		return;
	}
	else
	{
		memcpy(stack->current, data, stack->element_size);
		stack->current = (void*)((size_t)stack->current + stack->element_size);
	}

}


void StackPop(stack_t *stack)
{
	stack->current = (void*)((size_t)stack->current - stack->element_size);
	
}


void *StackPeek(const stack_t *stack)
{
	void *ptr = (void*)((size_t)stack->current - stack->element_size);
	return ptr;
}

size_t StackCapacity(const stack_t *stack)
{
	assert(NULL != stack);
	return stack->capacity;
}


int StackIsEmpty(const stack_t *stack)
{
	return (stack->current == stack->array)? 1 : 0;
}

/*  how many elements */
size_t StackSize(const stack_t *stack)
{
	assert(NULL != stack);
	return (((size_t)stack->current - (size_t)stack->array) / (stack->element_size));
}




