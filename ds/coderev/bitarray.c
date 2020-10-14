/*******************************************************************************
* Title: BitArray Functions
* Worksheet: 1	
* Description: Implementations of bit array functions
* Author: Reut Cohen
* Reviwer: Mor Gafson
*
* InfintyLabs OL95

********************************************************************************
********************************************************************************/

/*******************************Libraries***************************************/

#include <stdlib.h> /* size_t */
#include <assert.h> /* assert() */
#include <limits.h> /* CHAR_BIT */
#include <stdio.h>
#include "bitarray.h" /* bitarr_t functions declaration */

#define BITARRAY_SIZE sizeof(bitarr_t) * CHAR_BIT  
#define LUT_SIZE 16
#define NIBBLE_SIZE 4
/*******************************************************************************
                             BitArraySetAll                               
*******************************************************************************/

bitarr_t BitArraySetAll(bitarr_t bit_array)
{
	bit_array = 0xFFFFFFFFFFFFFFFF;
	return (bit_array);
}

/*******************************************************************************
                             BitArraySetAll                               
*******************************************************************************/

bitarr_t BitArrayResetAll(bitarr_t bit_array)
{
	bit_array = 0x0;
	return (bit_array);
}

/*******************************************************************************
                             BitArrayToString                               
*******************************************************************************/
/* DESCRIPTION: Function that will convert the bits to string. */

char *BitArrayToString(bitarr_t bit_array, char *str)
{
	int i = 0;
	size_t mask = 1;
	char *s_runner = str;	
	for (i = BITARRAY_SIZE - 1 ; 0 <= i; --i)
	{
		*s_runner = (((mask << i) == (bit_array & (mask << i))) ? '1' : '0');
		++s_runner;
	}
	return (str);
}

/*******************************************************************************
                             BitArraySetOn                               
*******************************************************************************/
/* DESCRIPTION: Function that will set a specific bit on. */

bitarr_t BitArraySetOn(bitarr_t bit_array, unsigned int index)
{
	size_t mask = 1;
	assert(BITARRAY_SIZE > index);
	
	if ((mask << index) != (bit_array & (mask << index)))
	{
		bit_array ^= (mask << index);
	}
	return (bit_array);
}

/*******************************************************************************
                             BitArraySetOff                               
*******************************************************************************/
/* DESCRIPTION: Function that will set a specific bit off. */

bitarr_t BitArraySetOff(bitarr_t bit_array, unsigned int index)
{
	size_t mask = 1;
	assert(BITARRAY_SIZE > index);
	if ((mask << index) == (bit_array & (mask << index))) /*check if the bit is on*/
	{
		bit_array ^= (mask << index);
	}
	return (bit_array);
}


/*******************************************************************************
                             BitArraySetBit                               
*******************************************************************************/
/* DESCRIPTION: Function that will set a specific bit on or off as the user decides. */

bitarr_t BitArraySetBit(bitarr_t bit_array, unsigned int index, unsigned int set_state)
{
	assert(BITARRAY_SIZE > index);
	assert((1 == set_state) || (0 == set_state));

	if (1 == set_state)
	{
	 	return (BitArraySetOn(bit_array, index));	
	}
	return (BitArraySetOff(bit_array, index));
}


/*******************************************************************************
                             BitArrayGetVal                               
*******************************************************************************/
/* DESCRIPTION: Function that will inform us about bit's value. */

unsigned int BitArrayGetVal(bitarr_t bit_array, unsigned int index)
{
	size_t mask = 1;
	assert(BITARRAY_SIZE > index);
	return (((mask << index) == (bit_array & (mask << index))) ? 1 : 0);
}


/*******************************************************************************
                             BitArrayFlip                               
*******************************************************************************/
/* DESCRIPTION: Function that will change bit mode at index. */

bitarr_t BitArrayFlip(bitarr_t bit_array, unsigned int index)
{
	unsigned int is_on;
	assert(BITARRAY_SIZE > index);
	is_on = BitArrayGetVal(bit_array, index);
	
	return ((is_on ? BitArraySetOff(bit_array, index) : BitArraySetOn(bit_array, index)));

}


/*******************************************************************************
                             BitArrayMirror                               
*******************************************************************************/
/* DESCRIPTION: Function that will reverse all bits. */

bitarr_t BitArrayMirror(bitarr_t bit_array)
{		
	bit_array = (((bit_array & 0xaaaaaaaaaaaaaaaa) >> 1) | ((bit_array & 0x5555555555555555) << 1));
	bit_array = (((bit_array & 0xcccccccccccccccc) >> 2) | ((bit_array & 0x3333333333333333) << 2));
	bit_array = (((bit_array & 0xf0f0f0f0f0f0f0f0) >> 4) | ((bit_array & 0x0f0f0f0f0f0f0f0f) << 4));
	bit_array = (((bit_array & 0xff00ff00ff00ff00) >> 8) | ((bit_array & 0x00ff00ff00ff00ff) << 8));
	bit_array = (((bit_array & 0xffff0000ffff0000) >> 16) | ((bit_array & 0x0000ffff0000ffff) << 16));
	
	return ((bit_array >> 32) | (bit_array << 32));

}


bitarr_t BitArrayMirrorLUT(bitarr_t bit_array) 
{							
	static unsigned int lut[LUT_SIZE] = {0, 8, 6, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};	
	unsigned int shift_nibble_l = BITARRAY_SIZE - NIBBLE_SIZE;
	bitarr_t mirror_bit_arr = 0;
	while (0 != bit_array)
	{	
		mirror_bit_arr |= (bitarr_t)lut[bit_array & 0xf] << shift_nibble_l;
		bit_array >>= NIBBLE_SIZE;
		shift_nibble_l -= NIBBLE_SIZE;
	}
	return mirror_bit_arr;
}

/*******************************************************************************
                             BitArrayRotRight                               
*******************************************************************************/
/* DESCRIPTION: Function that will rotate right rot_num times. */

bitarr_t BitArrayRotRight(bitarr_t bit_array, unsigned int rot_num)
{
	bitarr_t n_shift_right = bit_array >> rot_num;
	bit_array <<= (BITARRAY_SIZE - rot_num);

	return (n_shift_right | bit_array);
}


/*******************************************************************************
                             BitArrayRotLeft                               
*******************************************************************************/
/* DESCRIPTION: Function that will rotate left rot_num times. */

bitarr_t BitArrayRotLeft(bitarr_t bit_array, unsigned int rot_num)
{
	bitarr_t n_shift_left = bit_array << rot_num;
	bit_array >>= (BITARRAY_SIZE - rot_num);

	return (n_shift_left | bit_array);
}

/*******************************************************************************
                             BitArrayCountOn                               
*******************************************************************************/
/* DESCRIPTION: Function that will counts on bits. */

unsigned int BitArrayCountOn(bitarr_t bit_array)
{
	unsigned int count = 0;
	while (0 != bit_array)
	{
		bit_array &= (bit_array - 1); /* set off the rightest set on bit*/
		++count;
	}

	return (count);
}

unsigned int BitArrayCountOnLUT(bitarr_t bit_array)
{
	static unsigned int lut[LUT_SIZE] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
	unsigned int count = 0;
	
	while (0 != bit_array)
	{
		count += lut[bit_array & 0xF]; /* count 1 nibble each time */
		bit_array >>= NIBBLE_SIZE;
	}

	return count;
}


/*******************************************************************************
                             BitArrayCountOff                               
*******************************************************************************/
/* DESCRIPTION: Function that will counts off bits. */

unsigned int BitArrayCountOff(bitarr_t bit_array)
{
	return (BITARRAY_SIZE - BitArrayCountOn(bit_array));
}



