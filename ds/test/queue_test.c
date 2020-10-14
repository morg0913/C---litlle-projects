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
#include "queue.h" /* queue function */



/* in c file

#include "singly_linked_list.h"

struct queue
{
	slist_t *slist;
};
*/


/*******************************************************************************
                             function declaration                               
*******************************************************************************/
void TestQueueCreate(void);
void TestQueueEnqueue(void);
void TestQueueDequeue(void);
void TestQueueSize(void);
void TestQueuePeek(void);
void TestQueueIsEmpty(void);
void TestQueueAppend(void);

/*******************************************************************************
                             main                               
*******************************************************************************/
int main(void)
{
	TestQueueCreate();
	TestQueueEnqueue();
  TestQueueDequeue();
	TestQueueSize();
	TestQueuePeek();
	TestQueueIsEmpty();
	TestQueueAppend();
	return 0;
}


/*******************************************************************************
                             TestQCreate                             
*******************************************************************************/
void TestQueueCreate(void)
{
	queue_t *queue = QueueCreate();
	printf("\n\033[1;36m Test QueueCreate\n");
	
	if(NULL != queue)
	{
		printf("\n\033[1;32m test successed!\n");

	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	QueueDestroy(queue);
}

/*******************************************************************************
                             TestQueueEnqueue                             
*******************************************************************************/
void TestQueueEnqueue(void)
{
	queue_t *queue = QueueCreate();
	int data1 = 1;
	int data2 = 2;
	
	if(	NULL == queue)
	{
		return;
	}
	
	QueueEnqueue(queue, &data1);
	QueueEnqueue(queue, &data2);
	printf("\n\033[1;36m Test QueueEnqueue\n");
	if(QueueSize(queue) == 2 && *(int*)QueuePeek(queue) == data1)
	{
		printf("\n\033[1;32m test successed!\n");

	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	QueueDestroy(queue);
}

/*******************************************************************************
                             TestQueueDequeue                             
*******************************************************************************/
void TestQueueDequeue(void)
{
	queue_t *queue = QueueCreate();
	int data1 = 1;
	int data2 = 2;

	QueueEnqueue(queue, &data1);
	QueueEnqueue(queue, &data2);
	
	QueueDequeue(queue);

	printf("\n\033[1;36m Test TestQueueDequeue\n");
	if((QueueSize(queue) == 1) && (*(int*)QueuePeek(queue) == data2))
	{
			printf("\n\033[1;32m test successed!\n");
	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	QueueDestroy(queue);
}

/*******************************************************************************
                             TestQueueSize                             
*******************************************************************************/
void TestQueueSize(void)
{
		queue_t *queue = QueueCreate();
	int data1 = 1;
	int data2 = 2;
	int data3 = 3;

	QueueEnqueue(queue, &data1);
	QueueEnqueue(queue, &data2);
	QueueEnqueue(queue, &data3);

	QueueDequeue(queue);

	printf("\n\033[1;36m Test TestQueueSize\n");
	if(QueueSize(queue) == 2)
	{
			printf("\n\033[1;32m test successed!\n");
	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	QueueDestroy(queue);
}

/*******************************************************************************
                             TestQueuePeek                            
*******************************************************************************/
void TestQueuePeek(void)
{
	queue_t *queue = QueueCreate();
	int data1 = 1;
	int data2 = 2;

	QueueEnqueue(queue, &data1);
	QueueEnqueue(queue, &data2);

	printf("\n\033[1;36m Test TestQueuePeek\n");
	if((QueueSize(queue) == 2) && (*(int*)QueuePeek(queue) == data1))
	{
			printf("\n\033[1;32m test successed!\n");
	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	QueueDestroy(queue);
}

/*******************************************************************************
                             TestQueueIsEmpty                             
*******************************************************************************/
void TestQueueIsEmpty(void)
{
	queue_t *queue1 = QueueCreate();
	queue_t *queue2 = QueueCreate();
	
	int data1 = 1;
	int data2 = 2;

	QueueEnqueue(queue1, &data1);
	QueueEnqueue(queue1, &data2);
	QueueDequeue(queue1);
	QueueDequeue(queue1);

	QueueEnqueue(queue2, &data1);
	QueueEnqueue(queue2, &data2);
	QueueDequeue(queue2);

	printf("\n\033[1;36m Test TestQueueIsEmpty\n");
	if((QueueIsEmpty(queue1) == 1) && (QueueIsEmpty(queue2) == 0))
	{
			printf("\n\033[1;32m test successed!\n");
	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	QueueDestroy(queue1);
	QueueDestroy(queue2);
}

/*******************************************************************************
                             TestQueueAppend                            
*******************************************************************************/
void TestQueueAppend(void)
{
    queue_t *queuedest = QueueCreate();
    queue_t *queuesrc = QueueCreate();
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    int data4 = 4;
    int data5 = 5;
    int data6 = 6;

    
    if((NULL == queuedest) || (NULL == queuesrc))
    {
        return;
    }
    
    QueueEnqueue(queuedest, &data1);
    QueueEnqueue(queuedest, &data2);
    QueueEnqueue(queuedest, &data3);
    QueueEnqueue(queuesrc, &data4);
    QueueEnqueue(queuesrc, &data5);
    QueueEnqueue(queuesrc, &data6);
    QueueAppend(queuesrc,queuedest);
    
    printf("\n\033[1;36m Test QueueAppend\n");
    if(QueueSize(queuedest) == 6 && QueueIsEmpty(queuesrc) == 1)
    {
        printf("\n\033[1;32m test successed!\n");
    }
    else
    {
        printf("\n\033[1;31m test failed!\n");
    }
    QueueDestroy(queuedest);    
    QueueDestroy(queuesrc);    

        
}

