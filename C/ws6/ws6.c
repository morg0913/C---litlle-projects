#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

long Pow2(unsigned int x, unsigned int y);
int powOfTwo(unsigned int n);
int powOfTwo2(unsigned int n);
unsigned int add1(unsigned int x);
void bitsOn(unsigned int *arr, int size_of_arr);
unsigned int byte_mirror_loop (unsigned int num);
unsigned char PrintByteMirror_noloop(unsigned char num);
int if2and6IsOn (unsigned char num);
int swap3and5 (unsigned char num);
int if2or6IsOn (unsigned char num);
unsigned int divisibleby16 (unsigned int num);
void swapwithoutothervar (int *num1, int *num2);
int checknum(unsigned int num);
int checknum_noloop(unsigned int n);
void PrintFloatBits(void *real_num);
void PrintIntBits(int num);
void PrintFolatBitsTest(void);

int main()
{

	PrintFolatBitsTest();
/*	unsigned int arr[] = {0,5,11,6,50};
	int size = 5;
	bitsOn(arr,size);
	printf("%d\n" ,add1(6));
	printf("val: %d\n",powOfTwo2(32));
	printf("val: %lu\n", Pow2(3,3));*/
	return 1;
}

/*   x*(2^y)   */
long Pow2(unsigned int x, unsigned int y)
{
		long shift2 = (1 << y);

		if (x == 0)
		{
			return 0;
		}

		if (x == 1)
		{
			return shift2;
		}

	
		if (x % 2 == 0)
		{
			shift2 <<= (x / 2);
		}else{
			shift2 = (shift2) + (shift2 << ((x - 1) / 2));
			}
	
		return shift2;	
}

/*with loop*/
int powOfTwo(unsigned int n)
{
	unsigned int dup = 1;

	while(dup < n)
	{
		dup <<= 1;
	}
	
	if (dup == n)
	{
		return 1;
	}

	return 0;
	
}

/*without loop*/
int powOfTwo2(unsigned int n)
{
	unsigned int x = (n) & (n - 1);
	if( x == 0)
	{
		return 1;
	}

	return 0;
}

unsigned int add1(unsigned int x)
{
	unsigned int bit = 1;

	while((bit & x) != 0 )
	{
		x &= ~bit;
		bit <<= 1;
	}
	
	x |= bit;
	return x;
}



void bitsOn(unsigned int *arr, int size_of_arr)
{

	int i;
	
	for(i = 0; i < size_of_arr; i++)
	{
		int count = 0;
		unsigned int tmp = arr[i];
		unsigned int bit = 1;
		while(bit < tmp )
		{
			if((bit & tmp) != 0)
			{
				count++;
			}
			bit <<= 1;
		}
		if(count == 3)
		{
			printf("arr[%d] = %d\n", i, arr[i]);
		}
	}
}



 
unsigned int byte_mirror_loop (unsigned int num)
{

	unsigned int bit_last = 1 << 31;
	unsigned int bit_first = 1;
	unsigned int temp = num;
	
	
	while( bit_first <= bit_last)
	{
		if((bit_last & num) != (bit_first & num))
		{
			temp = temp^bit_first;
			temp = temp^bit_last;
		}
		
		bit_last >>= 1;
		bit_first <<= 1;
		
	}
	return temp;
}
	

unsigned char PrintByteMirror_noloop(unsigned char num)
{
    num = ((num & 0xf0) >> 4) | ((num & 0x0f) << 4); 
            /* 0xf0 = 11110000 , 0x0f = 00001111 /
    num = ((num & 0xcc) >> 2) | ((num & 0x33) << 2); 
            / 0xcc = 11001100 , 0x33 = 00110011 /
    num = ((num & 0xaa) >> 1) | ((num & 0x55) << 1); 
            / 0xf0 = 10101010 , 0x55 = 01010101 */
    return num;
}	



int if2and6IsOn (unsigned char num)
{
	unsigned char bits2 = num >> 1;
	unsigned char bits6 = num >> 5;
	unsigned char mask = 1;
	
	return ((mask & bits2) && (mask & bits6));
	

}


int if2or6IsOn (unsigned char num)
{
	unsigned char bits2 = num >> 1;
	unsigned char bits6 = num >> 5;
	unsigned char mask = 1;
	
	return ((mask & bits2) || (mask & bits6));
	

}


int swap3and5 (unsigned char num)
{
	unsigned char mask = 20;
	
	return ((20 == (num & mask)) || (0 == (num & mask))) ? num : (num ^= mask);	
	
	
}



unsigned int divisibleby16 (unsigned int num)
{
	unsigned int mask = 0xffffffff^15;
	return num & mask;	
}
 


void swapwithoutothervar (int *num1, int *num2)
{
	*num1 = *num1^ *num2;
	*num2 = *num2^ *num1;
	*num1 = *num1^ *num2;
} 





int checknum(unsigned int num)
{
	
	unsigned int bit = 1;
	unsigned int temp = 0;
	int count = 0;

	temp = num;
	while(temp)
	{
		if(1 == (temp & bit))
		{
			++count;
		} 
			temp >>= 1;
	}
		
		return count;	
}


int checknum_noloop(unsigned int n)
{
	
    n = n - ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}


void PrintFloatBits(void *real_num)
{
	unsigned int *num = NULL;

	assert(NULL != real_num);
	
	num = real_num;
	PrintIntBits(*num);
}

void PrintIntBits(int num)
{
	size_t idx = 0;	
	size_t shift = 8 * sizeof(int);

	while (shift > idx)
	{
		if ((num >> (shift - 1 - idx)) & 0x01)
		{
			printf("1");
		}
		else
        {
            printf("0");
        }

        idx++;
    }
    
    printf("\n");
}

void PrintFolatBitsTest(void)
{
    float real_num = 5.2;    

    printf("\nPrintFolatBits function testing:\n");

    printf("5.2  represented in bits is: ");
    PrintFloatBits(&real_num);

    real_num = 6.7;
    printf("6.7  represented in bits is: ");
    PrintFloatBits(&real_num);

    real_num = 10.3;
    printf("10.3 represented in bits is: ");
    PrintFloatBits(&real_num);
}















