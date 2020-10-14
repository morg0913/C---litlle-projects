#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    void *data;
    struct node *next;
}node_t;

node_t *Flip(node_t *head);
int HasLoop(const node_t *head);
node_t *FindIntersection(node_t *head1, node_t *head2);
node_t *Create(void *data, node_t *next);
void TestFlip(void);
void TestHasLoop(void);
void TestFindIntersection(void);

int main()
{
	TestFlip();
	TestHasLoop();
	TestFindIntersection();
	return 0;
}

void TestFindIntersection(void)
{
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	
	node_t *fourth = Create(&n4 ,NULL);
	node_t *third = Create(&n3 ,fourth);
	node_t *second = Create(&n2 ,third);
	node_t *first =  Create(&n1 ,second);

	int n5 = 5;
	int n6 = 6;
	int n7 = 7;


	node_t *three = Create(&n7 ,NULL);
	node_t *two = Create(&n6 ,three);
	node_t *one =  Create(&n5 ,two);
	

	
	printf("\n\033[1;36m Test FindIntersection1\n");
	if(FindIntersection(first, one) == NULL)
	{
		printf("\n\033[1;32m test successed!\n");

	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	
	three->next = third;

	
	printf("%p\n" ,(void*)FindIntersection(first, one));
	printf("\n\033[1;36m Test FindIntersection2\n");
	if(FindIntersection(first, one) == third)
	{
		printf("\n\033[1;32m test successed!\n");

	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	
	free(fourth);
	free(third);
	free(second);
	free(first);
	free(three);
	free(two);
	free(one);

}

void TestHasLoop(void)
{
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	
	node_t *fourth = Create(&n4 ,NULL);
	node_t *third = Create(&n3 ,fourth);
	node_t *second = Create(&n2 ,third);
	node_t *first =  Create(&n1 ,second);
	printf("\n\033[1;36m Test HasLoop1\n");
	if(HasLoop(first) == 1)
	{
		printf("\n\033[1;31m test failed!\n");
	}
	else
	{
		printf("\n\033[1;32m test successed!\n");
	}

	fourth->next = second;
		
	printf("\n\033[1;36m Test HasLoop2\n");
	if(HasLoop(first) == 1)
	{
		printf("\n\033[1;32m test successed!\n");
	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}

	free(fourth);
	free(third);
	free(second);
	free(first);
}

void TestFlip(void)
{
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	
	node_t *fourth = Create(&n4 ,NULL);
	node_t *third = Create(&n3 ,fourth);
	node_t *second = Create(&n2 ,third);
	node_t *first =  Create(&n1 ,second);
	node_t *head = Flip(first);
	node_t *itr = head;
	printf("\n\033[1;36m Test Flip\n");
	if(fourth == itr && third == itr->next && second == itr->next->next && first == itr->next->next->next && itr->next->next->next->next == NULL)
	{
		printf("\n\033[1;32m test successed!\n");
	}
	else
	{
		printf("\n\033[1;31m test failed!\n");
	}
	free(fourth);
	free(third);
	free(second);
	free(first);

}

node_t *Flip(node_t *head)
{
	node_t *runner = head;
	node_t *afterRunner = runner->next;
	node_t *curr = head;
	curr->next = NULL;

	while(afterRunner != NULL)
	{
		curr = runner;
		runner = afterRunner;
		afterRunner = afterRunner->next;
		runner->next = curr;
	}
	head = runner;
	return head;
}


int HasLoop(const node_t *head)
{
	node_t *runner = (node_t*)head;
	node_t *faster = (node_t*)head;

	while(faster != NULL)
	{
		faster = faster->next->next;
		runner = runner->next;
		if(faster == runner)
		{
			return 1;
		}
	}
	return 0;
}

node_t *FindIntersection(node_t *head_1 , node_t *head_2)
{
	node_t *first = head_1;
	node_t *second= head_2;
	node_t *h2 = head_2;
	while(first != NULL)
	{
		second = h2;
		while(second != NULL)
		{
			if(second == first)
			{
				return first;
			}
			second = second->next;
		}
		first = first->next;
	}
	return first;

}

node_t *Create(void *data, node_t *next)
{

	node_t *newNode = (node_t*)malloc(sizeof(node_t));

	if( NULL == newNode)
	{
		return NULL;
	
	}
	newNode->data = data;
	newNode->next = next;
	return newNode;
}







