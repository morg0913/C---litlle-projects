#include <stdio.h>
#include <string.h>

void print(int num);
void print_struct();

int main()
{
	print_struct();
	
	return 0;
}

struct print_me
{
	int num;
	void (*fp)(int);
};

void print(int num)
{
	printf("value =: %d\n", num);
}


void print_struct()
{
	int i;
	struct print_me pm[10];

	for (i = 0; i < 10; i++)
	{
		pm[i].num = i;
		pm[i].fp = &print;
		pm[i].fp(i);
	}
}

