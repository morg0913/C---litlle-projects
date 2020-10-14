/********************************************
File name : dynamic_vector.c
Author : Mor Gafson
Reviewer : me
Infinity Labs OL95	
*******************************************/




#include "dynamic_vector.h"
#include <assert.h> /*assert*/
#include <stdio.h>  /* malloc(), free() */
#include <stdlib.h> /*printf()*/
#include <string.h> /* memcpy() */
#include <stddef.h>/*size_t*/
/**********************************struct***************************************/


struct dynamic_vector
{
	void *vector;
	size_t num_of_elements;
	size_t capacity;
	size_t element_size;
};


vector_t *VectorCreate(size_t capacity, size_t element_size)
{
	vector_t *dvector = NULL;
	assert((0 < capacity) && (0 < element_size));

	dvector = (vector_t*)malloc(sizeof(vector_t));
	if(NULL == dvector)
	{
		return NULL;
	}
	
	dvector->vector = malloc(element_size * capacity);
	if(NULL == dvector->vector)
	{
		return NULL;
	}
	
	dvector->num_of_elements = 0;
	dvector->capacity = capacity;
	dvector->element_size = element_size;
	
	return dvector;
}

void VectorDestroy(vector_t *dynamic_vector)
{
	assert(NULL != dynamic_vector);
	free(dynamic_vector->vector);
	free(dynamic_vector);
}


void *VectorGetElement(const vector_t *dynamic_vector, size_t index)
{
	void *ptr = (void*)((size_t)dynamic_vector->vector + (index * dynamic_vector->element_size));

	return ptr;
}


int VectorPopBack(vector_t *dynamic_vector)
{
	if(dynamic_vector->num_of_elements == 0)
	{
		printf("\033[1;32m vector array already empty\n");
		return 1;
	}

	dynamic_vector->num_of_elements--;
	
	if(dynamic_vector->num_of_elements <= (0.25 * (float)dynamic_vector->capacity))
	{
		return VectorResize(dynamic_vector, (size_t)(dynamic_vector->capacity / 2));
	}
	
	return 0;
}


int VectorPushBack(vector_t *dynamic_vector, const void *element)
{
	void *dest = (void*)((size_t)dynamic_vector->vector + ((dynamic_vector->num_of_elements) * (dynamic_vector->element_size)));

	if(dynamic_vector->num_of_elements ==  dynamic_vector->capacity)
	{
		int returnValue = VectorResize(dynamic_vector, dynamic_vector->capacity * 2);
		if(returnValue == 0)
		{
			memcpy(dest, element, dynamic_vector->element_size);
			dynamic_vector->num_of_elements++;
			return 0;
		}
		else
			{
				return 1;
			}
	}
	else
		{
			memcpy(dest, element, dynamic_vector->element_size);
			dynamic_vector->num_of_elements++;
			return 0;
		}
	return 0;
}


size_t VectorSize(const vector_t *dynamic_vector)
{
	return dynamic_vector->num_of_elements;
}


size_t VectorCapacity(const vector_t *dynamic_vector)
{
	return dynamic_vector->capacity;
}


int VectorResize(vector_t *dynamic_vector, size_t new_size)
{
	dynamic_vector->vector = (void*)realloc(dynamic_vector->vector, new_size);
	if(NULL == dynamic_vector->vector)
	{
		return 1;
	} 
	
	dynamic_vector->capacity = new_size;
	return 0;
}
