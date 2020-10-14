#include <stdio.h>
#include <string.h>
#include "bitarray.h"

void TestBitArraySetAll(void);
void TestBitArrayResetAll(void);
void TestBitArraySetOn(void);
void TestBitArraySetOff(void);
void TestBitArrayGetVal(void);
void TestBitArrayFlip(void);
void TestBitArrayRotRight(void);
int TestBitArrayRotLeft(void);
void TestBitArrayCountOn(void);
void TestBitArrayCountOff(void);
void TestBitArrayToString(void);
void TestBitArraySetBit(void);
void TestBitArrayMirror(void);

int main(void)
{
	TestBitArraySetAll();
	TestBitArrayResetAll();
	TestBitArraySetOn();
	TestBitArraySetOff();
	TestBitArrayGetVal();
	TestBitArrayFlip();/* res too short (4 bytes) */
	TestBitArrayRotRight();
	TestBitArrayRotLeft();
	TestBitArrayCountOn();/**/
	TestBitArrayCountOff();/**/
	TestBitArrayToString();
	TestBitArraySetBit();/* res too short (4 bytes)*/
	TestBitArrayMirror();

	return 0;
}



void TestBitArraySetAll(void)
{
	bitarr_t ok_res = 0xffffffffffffffff;
	bitarr_t b_arr1 = 0x0000000000000000;
	bitarr_t b_arr2 = 0x000000a00000ffff;
	bitarr_t b_arr3 = 0x0000000000000000;
	bitarr_t b_arr4 = 0xf00bac400000ffff;
	int i = 0;

	bitarr_t test_arr[4] = {0};
	test_arr[0] = b_arr1;
	test_arr[1] = b_arr2;
	test_arr[2] = b_arr3;
	test_arr[3] = b_arr4;

	printf("\n\033[1;36m Test BitArraySetAll: \n");
	printf("\033[0m");
	for (i = 0; i < 4; i++)
	{
		if (ok_res == BitArraySetAll(test_arr[i]))
		{
			printf("\033[1;32m SUCCESS test #%d\n", i);
			printf("\033[0m");
		}	
		else
		{
			printf("1;31m FAILED test #%d\n", i);
			printf("\033[0m");
		}
	}
}

void TestBitArrayResetAll(void)
{
	bitarr_t ok_res = 0x0000000000000000;
	bitarr_t b_arr1 = 0x0000000000000000;
	bitarr_t b_arr2 = 0x000000a00000ffff;
	bitarr_t b_arr3 = 0xffffffffffffffff;
	bitarr_t b_arr4 = 0xf00bac400000ffff;
	int i = 0;

	bitarr_t test_arr[4] = {0};
	test_arr[0] = b_arr1;
	test_arr[1] = b_arr2;
	test_arr[2] = b_arr3;
	test_arr[3] = b_arr4;

	printf("\n\033[1;36m Test BitArrayResetAll: \n");
	printf("\033[0m");
	for (i = 0; i < 4; i++)
	{
		if (ok_res == BitArrayResetAll(test_arr[i]))
		{
			printf("\033[1;32m SUCCESS test #%d\n", i);
			printf("\033[0m");
		}	
		else
		{
			printf("1;31m FAILED test #%d\n", i);
			printf("\033[0m");
		}
	}
}

void TestBitArraySetOn(void)
{
	unsigned int index_start = 63;
	unsigned int index_end = 1;
	bitarr_t checker1 = 1 << index_start;
	bitarr_t checker2 = 1 << index_end;
	bitarr_t b_arr1 = 0xff00000000000000;
	bitarr_t b_arr2 = 0x000000a00000ffff;
	
	printf("\n\033[1;36m Test BitArraySetOn: \n");
	printf("\033[0m");
	if (BitArraySetOn(b_arr1, index_start) & checker1)
	{
		printf("\033[1;32m SUCCESS test #1\n");
		printf("\033[0m");
	}
	else
	{
		printf("1;31m FAILED test #1\n");
		printf("\033[0m");
	}

	if (BitArraySetOn(b_arr2, index_start) & checker1)
	{
		printf("\033[1;32m SUCCESS test #2\n");
		printf("\033[0m");
	}
	else
	{
		printf("1;31m FAILED test #2\n");
		printf("\033[0m");
	}

	if (BitArraySetOn(b_arr2, index_end) & checker2)
	{
		printf("\033[1;32m SUCCESS test #3\n");
		printf("\033[0m");
	}
	else
	{
		printf("1;31m FAILED test #3\n");
		printf("\033[0m");
	}	
}


void TestBitArraySetOff(void)
{
	unsigned int index_start = 63;
	unsigned int index_end = 1;
	bitarr_t checker1 = 1 << index_start;
	bitarr_t checker2 = 1 << index_end;
	bitarr_t b_arr1 = 0xffffffffffffffff;
	bitarr_t b_arr2 = 0x000000a00000ffff;
	
	printf("\n\033[1;36m Test BitArraySetOff: \n");
	printf("\033[0m");
	if (checker1 == (checker1 & BitArraySetOff(b_arr1, index_start)))
	{
		printf("1;31m FAILED test #1\n");
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;32m SUCCESS test #1\n");
		printf("\033[0m");
	}

	if (checker1 == (checker1 & BitArraySetOff(b_arr2, index_start)))
	{
		printf("1;31m FAILED test #2\n");
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;32m SUCCESS test #2\n");
	}

	if (checker2 == (checker2 & BitArraySetOff(b_arr2, index_end)))
	{
		printf("1;31m FAILED test #3\n");
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;32m SUCCESS test #3\n");
		printf("\033[0m");
	}	
}


void TestBitArrayGetVal(void)
{
	bitarr_t b_arr1 = 0x0000000000000000;
	bitarr_t b_arr2 = 0x000000a00000ff0f;
	bitarr_t b_arr3 = 0xffffffffffffffff;
	bitarr_t b_arr4 = 0xf00bac400000ffff;
	int i = 0;

	bitarr_t test_arr[4] = {0};
	unsigned int test_res[4] = {0, 0, 1, 1};
	unsigned int test_index[4] = {1, 5, 63, 10};

	test_arr[0] = b_arr1;
	test_arr[1] = b_arr2;
	test_arr[2] = b_arr3;
	test_arr[3] = b_arr4;


	printf("\n\033[1;36m Test BitArrayGetVal: \n");
	printf("\033[0m");
	for (i = 0; i < 4; i++)
	{
		if (test_res[i] == BitArrayGetVal(test_arr[i], test_index[i]))
		{
			printf("\033[1;32m SUCCESS test #%d\n", i);
			printf("\033[0m");
		}	
		else
		{
			printf("\033[1;31m FAILED test #%d\n", i);
			printf("\033[0m");
		}
	}
}


void TestBitArrayFlip(void)
{
	bitarr_t b_arr1 = 0x0000000000000000;
	bitarr_t b_arr2 = 0x000000a00000ff0f;
	bitarr_t b_arr3 = 0xffffffffffffffff;
	bitarr_t b_arr4 = 0xf00bac400000ffff;

	bitarr_t b_arr1_res = 0x0000000000000002;
	bitarr_t b_arr2_res = 0x000000a00000ff1f;
	bitarr_t b_arr3_res = 0x7fffffffffffffff;
	bitarr_t b_arr4_res = 0xf00bac400000fdff;
	int i = 0;

	bitarr_t test_arr[4] = {0};
	bitarr_t test_res[4] = {0};
	unsigned int test_index[4] = {1, 4, 63, 9};


	test_arr[0] = b_arr1;
	test_arr[1] = b_arr2;
	test_arr[2] = b_arr3;
	test_arr[3] = b_arr4;

	test_res[0] = b_arr1_res;
	test_res[1] = b_arr2_res;
	test_res[2] = b_arr3_res;
	test_res[3] = b_arr4_res;

	printf("\n\033[1;36m Test BitArrayFlip: \n");
	printf("\033[0m");
	for (i = 0; i < 4; i++)
	{
		if (test_res[i] == BitArrayFlip(test_arr[i], test_index[i]))
		{
			printf("\033[1;32m SUCCESS test #%d\n", i);
			printf("\033[0m");
		}	
		else
		{
			printf("\033[1;31m FAILED test #%d\n", i);
			printf("\033[0m");
		}
	}
}


void TestBitArrayRotRight(void)
{
	bitarr_t b_arr1 = 0x0000000000000000;
	bitarr_t b_arr2 = 0x000000000000000f;
	bitarr_t b_arr3 = 0xffffffffffffffff;
	bitarr_t b_arr4 = 0xffff00000000ffff;

	bitarr_t b_arr1_res = 0x0000000000000000;
	bitarr_t b_arr2_res = 0xc000000000000003;
	bitarr_t b_arr3_res = 0xffffffffffffffff;
	bitarr_t b_arr4_res = 0xffffffff00000000;
	int i = 0;

	bitarr_t test_arr[4] = {0};
	bitarr_t test_res[4] = {0};
	unsigned int test_rot[4] = {10, 2, 5, 16};

	test_arr[0] = b_arr1;
	test_arr[1] = b_arr2;
	test_arr[2] = b_arr3;
	test_arr[3] = b_arr4;

	test_res[0] = b_arr1_res;
	test_res[1] = b_arr2_res;
	test_res[2] = b_arr3_res;
	test_res[3] = b_arr4_res;

	printf("\n\033[1;36m Test BitArrayRotRight: \n");
	printf("\033[0m");	
	for (i = 0; i < 4; i++)
	{
		if (test_res[i] == BitArrayRotRight(test_arr[i], test_rot[i]))
		{
			printf("\033[1;32m SUCCESS test #%d\n", i);
			printf("\033[0m");
		}	
		else
		{
			printf("1 %#lx\n", BitArrayRotRight(test_arr[i], test_rot[i]));
			printf("\033[0m");
			printf("2 %#lx\n", test_res[i]);
			printf("1;31m FAILED test #%d\n", i);
			printf("\033[0m");
		}
	}
}


int TestBitArrayRotLeft(void)
{
	bitarr_t b_arr1 = 0x0000000000000000;
	bitarr_t b_arr2 = 0xc000000000000003;
	bitarr_t b_arr3 = 0xffffffffffffffff;
	bitarr_t b_arr4 = 0xffffffff00000000;

	bitarr_t b_arr1_res = 0x0000000000000000;
	bitarr_t b_arr2_res = 0x000000000000000f;
	bitarr_t b_arr3_res = 0xffffffffffffffff;
	bitarr_t b_arr4_res = 0xffff00000000ffff;

	int i = 0;

	bitarr_t test_arr[4] = {0};
	bitarr_t test_res[4] = {0};
	unsigned int test_rot[4] = {10, 2, 5, 16};

	test_arr[0] = b_arr1;
	test_arr[1] = b_arr2;
	test_arr[2] = b_arr3;
	test_arr[3] = b_arr4;
	
	test_res[0] = b_arr1_res;
	test_res[1] = b_arr2_res;
	test_res[2] = b_arr3_res;
	test_res[3] = b_arr4_res;


	printf("\n\033[1;36m Test BitArrayRotLeft: \n");
	printf("\033[0m");
	for (i = 0; i < 4; i++)
	{
		if (test_res[i] == BitArrayRotLeft(test_arr[i], test_rot[i]))
		{
			printf("\033[1;32m SUCCESS test #%d\n", i);
			printf("\033[0m");
		}	
		else
		{
			printf("1;31m FAILED test #%d\n", i);
			printf("\033[0m");
		}
	}
}


void TestBitArrayCountOn(void)
{
	bitarr_t b_arr1 = 0x00030000f0003000;
	bitarr_t b_arr2 = 0x0000030000000000;
	bitarr_t b_arr3 = 0xffffffffffffffff;
	bitarr_t b_arr4 = 0xfff0000000000000;
	int i = 0;

	bitarr_t test_arr[4] = {0};
	unsigned int test_res[4] = {8, 2, 64, 12};

	test_arr[0] = b_arr1;
	test_arr[1] = b_arr2;
	test_arr[2] = b_arr3;
	test_arr[3] = b_arr4;

	printf("\n\033[1;36m Test BitArrayCountOn: \n");
	for (i = 0; i < 4; i++)
	{
		if (test_res[i] == BitArrayCountOn(test_arr[i]))
		{
			printf("\033[1;32m SUCCESS test #%d\n", i);
			printf("\033[0m");
		}	
		else
		{
			printf("\033[1;31m FAILED test #%d\n", i);
			printf("\033[0m");
		}
	}
}
void TestBitArrayCountOff(void)
{
	bitarr_t b_arr1 = 0x00030000f0003000;
	bitarr_t b_arr2 = 0x0000030000000000;
	bitarr_t b_arr3 = 0xffffffffffffffff;
	bitarr_t b_arr4 = 0xfff0000fff000000;
	int i = 0;

	bitarr_t test_arr[4] = {0};
	unsigned int test_res[4] = {56, 62, 0, 40};

	test_arr[0] = b_arr1;
	test_arr[1] = b_arr2;
	test_arr[2] = b_arr3;
	test_arr[3] = b_arr4;

	printf("\n\033[1;36m Test BitArrayCountOff: \n");
	for (i = 0; i < 4; i++)
	{
		if (test_res[i] == BitArrayCountOff(test_arr[i]))
		{
			printf("\033[1;32m SUCCESS test #%d\n", i);
			printf("\033[0m");
		}	
		else
		{
			printf("\033[1;31m FAILED test #%d\n", i);
			printf("\033[0m");
		}
	}
}


void TestBitArrayToString(void)
{
	bitarr_t bit_array = 31;
    char str[64] = {'\0'};

	printf("\n\033[1;36m Test BitArrayToString:\n");
	printf("\033[0m");	
    if(strcmp(BitArrayToString(bit_array,str), "0000000000000000000000000000000000000000000000000000000000011111") == 0)
    {
		printf("\033[1;32m SUCCESS test #1\n");
		printf("\033[0m");
    }
    else
    {
		printf("\033[1;31m FAILED test #1\n");
		printf("\033[0m");
    }
}


void TestBitArraySetBit(void)
{
	bitarr_t b_arr1 = 0x0000000000000000;
	bitarr_t b_arr2 = 0x000000a00000ff0f;
	bitarr_t b_arr3 = 0xffffffffffffffff;
	bitarr_t b_arr4 = 0xf00bac400000ffff;
	
	bitarr_t b_arr1_res = 0x0000000000000002;
	bitarr_t b_arr2_res = 0x000000a00000ff2f;
	bitarr_t b_arr3_res = 0x7fffffffffffffff;
	bitarr_t b_arr4_res = 0xf00bac400000fbff;
	int i = 0;

	bitarr_t test_arr[4] = {0};
	bitarr_t test_res[4] = {0};
	unsigned int test_index[4] = {1, 5, 63, 10};
	int test_state[4] = {1, 1, 0, 0};

	test_arr[0] = b_arr1;
	test_arr[1] = b_arr2;
	test_arr[2] = b_arr3;
	test_arr[3] = b_arr4;

	test_res[0] = b_arr1_res;
	test_res[1] = b_arr2_res;
	test_res[2] = b_arr3_res;
	test_res[3] = b_arr4_res;

	printf("\n\033[1;36m Test BitArraySetBit:\n");
	printf("\033[0m");
	for (i = 0; i < 4; i++)
	{
		if (test_res[i] == BitArraySetBit(test_arr[i], test_index[i], test_state[i]))
		{
			printf("\033[1;32m SUCCESS test #%d\n", i);
			printf("\033[0m");
		}	
		else
		{
			printf("\033[1;31m 1 %#lx\n", BitArraySetBit(test_arr[i], test_index[i], test_state[i]));
			printf("\033[1;31m 2 %#lx\n", test_res[i]);
			printf("\033[1;31m FAILED test #%d\n", i);
			printf("\033[0m");
		}
	}
}


void TestBitArrayMirror(void)
{
	bitarr_t bitarray1 = 0x00000000ffffffff;
	printf("\n\033[1;36m Test BitArrayMirror:\n");
    if(0xffffffff00000000 == BitArrayMirror(bitarray1))
    {
        printf("\033[1;32m BitArrayMirror is working\n");
	printf("\033[0m");
    }
    else
    {
        printf("\033[1;31m BitArrayMirror doesn't working\n");
    }
}


