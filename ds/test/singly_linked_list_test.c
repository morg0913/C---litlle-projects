/******************************************************************************
 * Title:		dsingly_linked_list_test
 * Description:	
 * Author:		Mor Gafson
 * Reviewer:	
 * 
 * InfinityLabs OL95
 *****************************************************************************/
#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/* (in .c file:)

struct node 
{
	void *data;
	node_t *next;
};

struct singly_linked_list
{
	node_t *begin;
	node_t *end;
};*/

void TestSListCreate(void);
void TestSListPushBack(void);
void TestSListPopBack(void);
void TestSListInsertBefore(void);
void TestSListRemove(void); 
void TestSListFindIter (void);
void TestSListForEachIter(void);
void TestSListSize(void);
void TestSListBegin(void);
void TestSListEnd(void);
void TestSListNextIter(void); 
void TestSListGetData(void);
void TestSListIsEmpty(void);
void TestSListIsSameIter (void);
int compare(const void *data1, const void *data2);
int func(void *data, void *param);

int main(void)
{
	TestSListCreate();
	TestSListPushBack();
	TestSListPopBack();
	TestSListInsertBefore();
	TestSListRemove();
	TestSListFindIter();
	 TestSListForEachIter();
	 TestSListSize();
	 TestSListBegin();
	 TestSListEnd();
	 TestSListNextIter(); 
	 TestSListGetData();
	 TestSListIsEmpty();
	 TestSListIsSameIter();
	return 0;
}

/*******************************************************************************
                             TestSListCreate                               
*******************************************************************************/
void TestSListCreate(void)
{
	slist_t *list = SListCreate();
	printf("\n\033[1;36m Test ListCreate: \n");
	printf("\033[0m");
	if(list != NULL )
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
	}
	else
		{
			printf("1;31m FAILED test\n");
			printf("\033[0m");
		}
	 SListDestroy(list);
}


/*******************************************************************************
                             TestSListPushBack                               
*******************************************************************************/
void TestSListPushBack(void)
{
	
	slist_t *list = SListCreate();
	printf("\n\033[1;36m Test SListPushBack\n");
	printf("\033[0m");
	if(NULL != list)
	{
		int data1 = 5;
		int data2 = 7;
		SListPushBack(list ,&data1);
		SListPushBack(list ,&data2);
		
		if(*(int*)SListGetData(SListBegin(list)) == 5)
		{
			printf("\n\033[1;32m test successed!\n");
			printf("\033[0m");
		}
		else
		{
			printf("\n\033[1;31m test failed!\n");
			printf("\033[0m");
		}

	}
		SListDestroy(list);
}

/*******************************************************************************
                             TestSListPopBack                               
*******************************************************************************/
void TestSListPopBack(void)
{
    int numtopush1 = 1;
    int numtopush2 = 2;
    slist_t *list = SListCreate();   
	printf("\n\033[1;36m Test TestSListPopBack\n");
	printf("\033[0m"); 
    if(NULL == list)
    {
        printf("list create failed\n");
        return;
    }
    
    SListPushBack(list, &numtopush1);
    SListPushBack(list, &numtopush2);
    SListPopBack(list);
    SListPopBack(list);
    if(SListSize(list) == 0)
    {
			printf("\n\033[1;32m test successed!\n");
			printf("\033[0m");
    }
    else
    {
			printf("\n\033[1;31m test failed!\n");
			printf("\033[0m");
    }    
SListDestroy(list);
}

/*******************************************************************************
                             TestSListInsertBefore                               
*******************************************************************************/
void TestSListInsertBefore(void)
{
	slist_t *list = SListCreate();
	printf("\n\033[1;36m Test SListInsertBefore\n");
	printf("\033[0m");
	if(NULL != list)
	{
		int data1 = 5;
		int data2 = 7;
		SListPushBack(list ,&data1);
		SListInsertBefore(list, SListBegin(list), &data2);
		if(*(int*)SListGetData(SListBegin(list)) == 7)
		{
			printf("\n\033[1;32m test successed!\n");
			printf("\033[0m");
		}
		else
		{
			printf("\n\033[1;31m test failed!\n");
			printf("\033[0m");		
	}

	}
	SListDestroy(list);
}

/*******************************************************************************
                             TestSListRemove                               
*******************************************************************************/
void TestSListRemove(void)
{
    int numtopush1 = 1;
    int numtopush2 = 2;
    slist_t *list = SListCreate();    
    if(NULL == list)
    {
        printf("list create failed\n");
        return;
    }
   	printf("\n\033[1;36m Test TestSListRemove\n");
	printf("\033[0m");
    SListPushBack(list, &numtopush1);
    SListPushBack(list, &numtopush2);
    SListRemove(list, SListBegin(list));
    if(*(int*)SListGetData(SListBegin(list)) == 2)
    {
			printf("\n\033[1;32m test successed!\n");
			printf("\033[0m");
    }
    else
    {
			printf("\n\033[1;31m test failed!\n");
			printf("\033[0m");		
    }        
SListDestroy(list);
}

/*******************************************************************************
                             TestSListFindIter                               
*******************************************************************************/
void TestSListFindIter(void)
{
    int res = 0;
    int numtopush1 = 1;
    int numtopush2 = 2;
    slist_t *list = SListCreate();    
	printf("\n\033[1;36m Test TestSListFindIter\n");
	printf("\033[0m");
    if(NULL == list)
    {
        printf("list create failed\n");
		printf("\033[0m");
        return;
    }
    
    SListPushBack(list, &numtopush1);
    SListPushBack(list, &numtopush2);
    res = SListIsSameIter(SListFindIter(list, compare, &numtopush1), SListBegin(list));
    if(res == 1)
    {
			printf("\n\033[1;32m test successed!\n");
			printf("\033[0m");
    }
    else
    {
			printf("\n\033[1;31m test failed!\n");
			printf("\033[0m");	
    }
SListDestroy(list);
}

/*******************************************************************************
                             TestSListForEachIter                               
*******************************************************************************/
void TestSListForEachIter(void)
{
	slist_iter_t iter1 = NULL;
	slist_iter_t iter2 = NULL;
	int numtopush1 = 1;
	int numtopush2 = 2;
	int numtopush3 = 3;
	int add = 1;
	slist_t *list = SListCreate();	
	if(NULL == list)
	{
		printf("\n\033[1;31m list create failed\n");
		printf("\033[0m");	
		return;
	}

	SListPushBack(list, &numtopush1);
	SListPushBack(list, &numtopush2);
	SListPushBack(list, &numtopush3);
	iter1 = SListBegin(list);
	iter2 = SListBegin(list);
	iter2 = SListNextIter(iter2);
	iter2 = SListNextIter(iter2);
	SListForEachIter(iter1, iter2, func, &add);
	printf("\n\033[1;36m Test TestSListForEachIter\n");
	printf("\033[0m");
	if(*(int*)SListGetData(iter1) == 2)
	{
		printf("\n\033[1;32m TestSListForEachIter number 1 succeed\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\n\033[1;31m TestSListForEachIter number 1 failed\n");
		printf("\033[0m");	
	}	
	if(*(int*)SListGetData(SListNextIter(iter1)) == 3)
	{
		printf("\n\033[1;32m TestSListForEachIter number 2 succeed\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\n\033[1;31m TestSListForEachIter number 2 failed\n");
		printf("\033[0m");	
	}	
	if(*(int*)SListGetData(SListNextIter(SListNextIter(iter1))) == 4)
	{
		printf("\n\033[1;32m TestSListForEachIter number 3 succeed\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\n\033[1;31m TestSListForEachIter number 3 failed\n");
		printf("\033[0m");	
	}	
	SListDestroy(list);	

}

/*******************************************************************************
                            TestSListSize                          
*******************************************************************************/
void TestSListSize(void)
{
	int numtopush1 = 1;
	int numtopush2 = 2;
	int numtopush3 = 3;
	slist_t *list = SListCreate();	
	
	printf("\n\033[1;36m Test TestSListSize\n");
	printf("\033[0m");	
	if(NULL == list)
	{
		printf("\n\033[1;31m list create failed\n");
		printf("\033[0m");	
		return;
	}
	
	SListPushBack(list, &numtopush1);
	SListPushBack(list, &numtopush2);
	SListPushBack(list, &numtopush3);
	if(SListSize(list) == 3)
	{
		printf("\n\033[1;32m SListSize works\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\n\033[1;31m SListSize doesn't work\n");
		printf("\033[0m");	
	}
	SListDestroy(list);	
	
}
/*******************************************************************************
                           TestSListBegin                               
*******************************************************************************/
void TestSListBegin(void)
{

	int numtopush1 = 1;
	int numtopush2 = 2;
	int numtopush3 = 3;
	slist_t *list = SListCreate();	

	printf("\n\033[1;36m Test TestSListBegin\n");
	printf("\033[0m");	
	if(NULL == list)
	{
		printf("\n\033[1;31m list create failed\n");
		printf("\033[0m");	
		return;
	}
	SListPushBack(list, &numtopush1);
	SListPushBack(list, &numtopush2);
	SListPushBack(list, &numtopush3);
	if(*(int*)SListGetData(SListBegin(list)) == 1)
	{
		printf("\n\033[1;32m SListBegin works\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\n\033[1;31m SListBegin doesn't work\n");
		printf("\033[0m");	
	}	
	SListDestroy(list);	
	
}

/*******************************************************************************
                            TestSListEnd                               
*******************************************************************************/
void TestSListEnd (void)
{

	slist_t *list = SListCreate();

	printf("\n\033[1;36m Test TestSListEnd\n");
	printf("\033[0m");		
	if(NULL == list)
	{
		printf("\n\033[1;31m list create failed\n");
		printf("\033[0m");	
		return;
	}
	
	if(SListGetData(SListEnd(list)) == NULL)
	{
		printf("\n\033[1;32m SListEnd works\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\n\033[1;31m SListEnd doesn't work\n");
		printf("\033[0m");	
	}
	SListDestroy(list);	

}

/*******************************************************************************
                             TestSListNextIter                               
*******************************************************************************/
void TestSListNextIter(void)
{
	int numtopush1 = 1;
	int numtopush2 = 2;
	int numtopush3 = 3;
	slist_t *list = SListCreate();	

	printf("\n\033[1;36m Test TestSListNextIter\n");
	printf("\033[0m");	
	if(NULL == list)
	{
		printf("\n\033[1;31m list create failed\n");
		printf("\033[0m");	
		return;
	}
	SListPushBack(list, &numtopush1);
	SListPushBack(list, &numtopush2);
	SListPushBack(list, &numtopush3);
	if(*(int*)SListGetData(SListNextIter(SListBegin(list))) == 2)
	{
		printf("\n\033[1;32m SListNextIter works\n");
		printf("\033[0m");	
	}
	else
	{
		printf("\n\033[1;31m SListNextIter doesn't work\n");
		printf("\033[0m");	
	}
	SListDestroy(list);	
	
}


/*******************************************************************************
                            TestSListGetData                               
*******************************************************************************/
void TestSListGetData(void)
{
	int numtopush1 = 1;
	slist_t *list = SListCreate();	

	printf("\n\033[1;36m Test TestSListGetData\n");
	printf("\033[0m");	
	if(NULL == list)
	{
		printf("\n\033[1;31m list create failed\n");
		printf("\033[0m");
		return;
	}
	SListPushBack(list, &numtopush1);

	if(*(int*)SListGetData(SListBegin(list)) == 1)
	{
		printf("\n\033[1;32m SListGetData works\n");
		printf("\033[0m");
	}
	else
	{
		printf("\n\033[1;31m SListGetData doesn't work\n");
		printf("\033[0m");
	}
	SListDestroy(list);	
	
}

/*******************************************************************************
                            TestSListIsEmpty                               
*******************************************************************************/
void TestSListIsEmpty (void)
{
	slist_t *list = SListCreate();	

	printf("\n\033[1;36m Test TestSListIsEmpty\n");
	printf("\033[0m");	
	if(NULL == list)
	{
		printf("\n\033[1;31m list create failed\n");
		printf("\033[0m");
		return;
	}
	if(SListIsEmpty(list) == 1)
	{
		printf("\n\033[1;32m SListIsEmpty works\n");
		printf("\033[0m");
	}
	else
	{
		printf("\n\033[1;31m SListIsEmpty doesn't work\n");
		printf("\033[0m");
	}	
	SListDestroy(list);	

}

/*******************************************************************************
                             TestSListIsSameIter                               
*******************************************************************************/
void TestSListIsSameIter(void)
{
	slist_iter_t iter1 = NULL;
	slist_iter_t iter2 = NULL;
	int numtopush1 = 1;
	slist_t *list = SListCreate();	

	printf("\n\033[1;36m Test TestSListIsEmpty\n");
	printf("\033[0m");
	if(NULL == list)
	{
		printf("\n\033[1;31m list create failed\n");
		printf("\033[0m");
		return;
	}
	
	SListPushBack(list, &numtopush1);
	iter1 = SListBegin(list);
	iter2 = SListBegin(list);
	
	if(SListIsSameIter(iter1, iter2) == 1)
	{
		printf("\n\033[1;32m SListIsSameIter works\n");
		printf("\033[0m");
	}
	else
	{
		printf("\n\033[1;31m SListIsSameIter doesn't work\n");
		printf("\033[0m");
	}
	SListDestroy(list);
}
/*******************************************************************************
                             TestSListIsSameIter                               
*******************************************************************************/
int compare(const void *data1, const void *data2)
{
	if(*(int*)data1 == *(int*)data2)
	{
		return 0;
	}
	else
	{
		return 1;
	}	 
}
/*******************************************************************************
                             func                              
*******************************************************************************/
int func(void *data, void *param)
{
	*(int*)data += *(int*)param;
	
	return 0;
}

