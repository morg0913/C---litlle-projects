/**********************************************************************************************
*                              	  DS - Stack                                           *
* 												 *
* Description: implementations of stack functions.					         *
* Worksheet: 2											 *
* Date: 24.09.2020										 *
* InfinityLabs OL95										 *
**********************************************************************************************/

/*--------------------------------- Header Guard ----------------------------------------*/

#ifndef __ILRD_OL95_STACK_H__
#define __ILRD_OL95_STACK_H__

/*------------------------------------ Libraries ----------------------------------------*/
#include <stddef.h> /* size_t */

/*------------------------------------ Typedefs -----------------------------------------*/

typedef struct stack stack_t;

/*
* in c file:
struct stack
{
	void *array;
	void *current;
	size_t element_size;
	size_t capacity;
};
*/

/*--------------------------- Functions declarations ------------------------------------*/

/* DESCRIPTION:
 * Function for creating a new available stack. Memory will be specially allocated.
 * In case of failure allocating memory, NULL will be returned.
 * In order to avoid memory leaking, the StackDestroy function is requiered in end of use.
 * Time complexity: O(1)
 *
 * @return:
 * Returns pointer to new stack created, or NULL if failed allocating memory
 *
 */
stack_t *StackCreate(size_t capacity, size_t element_size);
	

/* DESCRIPTION:
 * Function for destroying given stack. memory will be freed
 * and any remaining data will be lost 
 * In case of pointer pointing to NULL, the behavior will be undefined
 * Time complexity: O(1)
 *
 * @param:
 * stack_t stack:	pointer to stack
 *
 */
void StackDestroy(stack_t *stack);


/* DESCRIPTION:
 * Function for pushing a new element, pointed by data,
 * to the top of given stack.
 * In case any of the pointers is pointing to NULL,
 * the behavior will be undefined.
 * Time complexity: O(1)
 *
 * @param:
 * stack_t *stack:	pointer to stack
 * void *data:		pointer to the element to be pushed
 *
 * @return:
 * Returns the updated stack
 *
 */
void StackPush(stack_t *stack, const void *data);


/* DESCRIPTION:
 * Function for popping the top element off given stack.
 * In case the pointer is pointing to NULL,
 * the behavior will be undefined.
 * Time complexity: O(1)
 *
 * @param:
 * stack_t *stack:	pointer to stack
 *
 * @return:
 * Returns pointer to updated stack
 *
 */
void StackPop(stack_t *stack);


/* DESCRIPTION:
 * Function for peeking at the element placed at the top of the stack,
 * In case the pointer is pointing to NULL,
 * the behavior will be undefined.
 * Time complexity: O(1)
 *
 * @param:
 * stack_t *stack:	pointer to stack
 *
 * @return:
 * Returns pointer to top element of the stack
 *
 */
void *StackPeek(const stack_t *stack);


/* DESCRIPTION:
 * Function for checking the capacity of stack.
 * In case the pointer is pointing to NULL,
 * the behavior will be undefined.
 * Time complexity: O(1)
 *
 * @param:
 * stack_t *stack:	pointer to stack
 *
 * @return:
 * Returns pointer to top element of the stack
 *
 */
size_t StackCapacity(const stack_t *stack);


/* DESCRIPTION:
 * Function for checking if stack is empty.
 * In case the pointer is pointing to NULL,
 * the behavior will be undefined.
 * Time complexity: O(1)
 *
 * @param:
 * stack_t *stack:	pointer to stack
 *
 * @return:
 * Returns 1 if stack is empty, or 0 if it's not
 *
 */
int StackIsEmpty(const stack_t *stack);


/* DESCRIPTION:
 * Function for checking the size of used space of stack.
 * In case the pointer is pointing to NULL,
 * the behavior will be undefined.
 * Time complexity: O(1)
 *
 * @param:
 * stack_t *stack:	pointer to stack
 *
 * @return:
 * Returns the size of used space
 *
 */
size_t StackSize(const stack_t *stack);


#endif /* __ILRD_OL95_STACK_H__ */
