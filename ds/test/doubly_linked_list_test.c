#include "doubly_linked_list.h" /* doubly_linked_list functions*/
#include <stdio.h>


int TestDListCreate(void);
int TestDListDestroy(void);
int TestDListPushBack(void);
int TestDListPopBack(void);
int TestDListInsert(void);
int TestDListRemove(void);
int TestDListFind(void);
int TestDListForEach(void);
int TestDListSize(void);
int TestDListBegin(void);
int TestDListEnd(void);
int TestDListNextIter(void); 
int TestDListPrevIter(void); 
int TestDListGetData(void);
int TestDListIsEmpty(void);
int TestDListIsSameIter(void);
int TestDListSplice(void);
int TestDListMultiFind(void);

int CompareInt(const void *data1, const void *data2);
int AddInt(void *data, void *add);
void printlist(dlist_t *list);
                                       
int main(void)
{
	TestDListCreate();
	TestDListDestroy();
	TestDListPushBack();
	TestDListPopBack();
	TestDListInsert();
	TestDListRemove();
	TestDListFind();
	TestDListForEach();
	TestDListSize();
	TestDListBegin();
	TestDListEnd();
	TestDListNextIter();
	TestDListPrevIter();
	TestDListGetData();
	TestDListIsEmpty();
	TestDListIsSameIter();
	TestDListMultiFind();
	TestDListSplice();
	
	return 0;
}

int TestDListCreate(void)
{
	dlist_t *new_dlist = DListCreate();
	
	printf("\n\033[1;36m Test DListCreate: \n");
	printf("\033[0m");
	
	if(NULL != new_dlist)
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListDestroy(void)
{
	printf("\n\033[1;36m Test DListDestroy: check in VLG\n");
	printf("\033[0m");
	return 1;
}

int TestDListPushBack(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);

	
	printf("\n\033[1;36m Test DListPushBack: \n");
	printf("\033[0m");
	

	
	if(DListIsEmpty(new_dlist) == 0)
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListPopBack(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 5;
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	
	DListPopBack(new_dlist);
	
	printf("\n\033[1;36m Test DListPopBack: \n");
	printf("\033[0m");
	
	printf("\nsize of list: %ld", DListSize(new_dlist));
	printf("\ndata of first value is : %d",*(int *)DListGetData(DListBegin(new_dlist)));
		
	if(2 == DListSize(new_dlist) && 10 == *(int *)DListGetData(DListBegin(new_dlist)))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListInsert(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	
	DListPushBack(new_dlist, &data1);
	DListInsert(new_dlist, DListBegin(new_dlist), &data2);
	DListInsert(new_dlist, DListEnd(new_dlist), &data2);
	
	printf("\n\033[1;36m Test DListInsert: \n");
	printf("\033[0m");
		
	if(*(int *)DListGetData(DListBegin(new_dlist)) == *(int *)DListGetData(DListPrevIter(DListEnd(new_dlist))))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListRemove(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 30;
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	
	
	DListRemove(new_dlist, DListNextIter(DListBegin(new_dlist)));
	
	printf("\n\033[1;36m Test DListRemove: \n");
	printf("\033[0m");
		
	if(DListGetData(DListNextIter(DListBegin(new_dlist))) == DListGetData(DListPrevIter(DListEnd(new_dlist))))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListFind(void)
{

	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 30;
	is_match_t cmp_int = &CompareInt;
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);

	
	printf("\n\033[1;36m Test DListFind: \n");
	printf("\033[0m");
	
	if(DListIsSameIter((DListFind(DListBegin(new_dlist),DListEnd(new_dlist), cmp_int, &data1)), 			     		DListBegin(new_dlist)))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}

}

int TestDListForEach(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 30;
	int add = 5;
	action_t add_int = &AddInt;

	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	

	
	DListForEach(DListBegin(new_dlist),DListEnd(new_dlist), add_int,(&add));
	
	printf("\n\033[1;36m Test DListForEachIter: \n");
	printf("\033[0m");
	
	if((*(int *)(DListGetData(DListBegin(new_dlist))) == 15)&&
	   (*(int *)(DListGetData(DListNextIter(DListBegin(new_dlist)))) == 20)&&
	   (*(int *)(DListGetData(DListPrevIter(DListEnd(new_dlist)))) == 35))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListSize(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 30;
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	
	printf("\n\033[1;36m Test DListSize: \n");
	printf("\033[0m");
		
	if( DListSize(new_dlist) == 3)
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListBegin(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	
	DListPushBack(new_dlist, &data1);
	DListInsert(new_dlist, DListBegin(new_dlist), &data2);
	
	
	printf("\n\033[1;36m Test DListBegin: \n");
	printf("\033[0m");
	
	if((*(int *)(DListGetData(DListBegin(new_dlist)))) == 15)
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListEnd(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	
	DListPushBack(new_dlist, &data1);
	DListInsert(new_dlist, DListBegin(new_dlist), &data2);
	
	
	printf("\n\033[1;36m Test DListEnd: \n");
	printf("\033[0m");
	
	if((DListGetData(DListEnd(new_dlist))) == NULL)
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListNextIter(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 30;
	dlist_iter_t iter = {NULL};
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	
	iter = DListNextIter(DListBegin(new_dlist));
	
	printf("\n\033[1;36m Test DListNextIter: \n");
	printf("\033[0m");
	
	if((*(int *)(DListGetData(iter))) == 15)
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListPrevIter(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 30;
	dlist_iter_t iter = {NULL};
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	
	iter = DListPrevIter(DListEnd(new_dlist));
	
	printf("\n\033[1;36m Test DListPrevIter: \n");
	printf("\033[0m");
	
	if((*(int *)(DListGetData(iter))) == 30)
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}

}

int TestDListGetData(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 30;
	dlist_iter_t iter = {NULL};
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	
	iter = DListPrevIter(DListEnd(new_dlist));
	
	printf("\n\033[1;36m Test DListGetData: \n");
	printf("\033[0m");
	
	if(30 == (*(int *)(DListGetData(iter))))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListIsEmpty(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 30;
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	
	DListPopBack(new_dlist);
	DListPopBack(new_dlist);
	DListPopBack(new_dlist);
	
	printf("\n\033[1;36m Test DListIsEmpty: \n");
	printf("\033[0m");
	
	if(DListIsEmpty(new_dlist))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
	
}

int TestDListIsSameIter(void)
{
	dlist_t *new_dlist = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	
	printf("\n\033[1;36m Test DListIsSameIter: \n");
	printf("\033[0m");
	
	if(DListIsSameIter(DListPrevIter(DListEnd(new_dlist)), DListNextIter(DListBegin(new_dlist))))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListSplice(void)
{
	dlist_t *new_dlist = DListCreate();
	dlist_t *to_add = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 10;
	
	const int data4 = 4;
	const int data5 = 2;
	const int data6 = 1;
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	
	DListPushBack(to_add, &data4);
	DListPushBack(to_add, &data5);
	DListPushBack(to_add, &data6);
	
	printf("\n\033[1;36m Test DListSplice: \n");
	printf("\033[0m");
	
	DListSplice(DListNextIter(DListBegin(new_dlist)),
				DListBegin(to_add),
				DListEnd(to_add));
	
	printlist(new_dlist);
				
	if(6 == DListSize(new_dlist))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		
		DListDestroy(new_dlist);
		DListDestroy(to_add);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int TestDListMultiFind(void)
{
	dlist_t *new_dlist = DListCreate();
	dlist_t *output_list = DListCreate();
	const int data1 = 10;
	const int data2 = 15;
	const int data3 = 10;
	is_match_t cmp_int = &CompareInt;
	
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	DListPushBack(new_dlist, &data3);
	DListPushBack(new_dlist, &data3);
	DListPushBack(new_dlist, &data1);
	DListPushBack(new_dlist, &data2);
	
	printf("\n\033[1;36m Test DListMultiFind: \n");
	printf("\033[0m");
	
	DListMultiFind(DListBegin(new_dlist), DListEnd(new_dlist), cmp_int, &data1, output_list);
	
	if(4 == DListSize(output_list))
	{
		printf("\033[1;32m SUCCESS test\n");
		printf("\033[0m");
		DListDestroy(new_dlist);
		DListDestroy(output_list);
		return 0;
	}
	
	else
	{
		printf("1;31m FAILED test\n");
		printf("\033[0m");
		return 1;
	}
}

int CompareInt(const void *data1, const void *data2)
{
	if(*(int *)data1 == *(int *)data2)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int AddInt(void *data, void *add)
{
	*(int *)data += *(int *)add;
	return 0;
}

void printlist(dlist_t *list)
{
	dlist_iter_t begin = DListBegin(list);
	while(begin.internal != DListEnd(list).internal)
	{
		printf(" %d-> ",*(int *)DListGetData(begin));
		begin = DListNextIter(begin);
		
	}
	printf("\n");
}

