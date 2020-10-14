/*******************************************************************************
* Title: BitArray Functions
* Worksheet: 1	
* Description: Implementations of bit array functions
* Author: Mor Gafson
* Reviwer: Reut Cohen
*
* InfintyLabs OL95

********************************************************************************
********************************************************************************/




#include "bitarray.h"
#include <assert.h>
#include <limits.h>

#define BITS_AMOUNT sizeof(bitarr_t)*CHAR_BIT

bitarr_t BitArraySetAll(bitarr_t bit_array)
{
	bit_array |= 0xffffffffffffffff;
	return bit_array;
}


bitarr_t BitArrayResetAll(bitarr_t bit_array)
{
	return (bit_array & 0);
}


bitarr_t BitArraySetOn(bitarr_t bit_array, unsigned int index)
{
	unsigned long mask = 1 << index;
	return (bitarr_t)(bit_array | mask);
}


bitarr_t BitArraySetOff(bitarr_t bit_array, unsigned int index)
{
	unsigned long mask = 1 << index;
	return (bitarr_t)(bit_array & ~mask);
}


unsigned int BitArrayGetVal(bitarr_t bit_array, unsigned int index)
{

    bitarr_t mask = 1 << index;
    assert(64 > index);
    return (unsigned int)((mask & bit_array) >> index);
}


bitarr_t BitArrayFlip(bitarr_t bit_array, unsigned int index)
{
    bitarr_t mask;

    assert (BITS_AMOUNT > index);

    (63 > index) ?  (mask = 1 << (bitarr_t)(index)) : (mask = 0x8000000000000000);
    bit_array ^= mask;
    return bit_array;
}


bitarr_t BitArrayRotRight(bitarr_t bit_array, unsigned int rot_num)
{
	bitarr_t nShiftRight = bit_array >> rot_num;
	bit_array <<= (64 - rot_num);

	return (nShiftRight | bit_array);
}    

bitarr_t BitArrayRotLeft(bitarr_t bit_array, unsigned int rot_num)
{
	bitarr_t nShiftLeft = bit_array << rot_num;
	bit_array >>= (64 - rot_num);

	return (nShiftLeft | bit_array);
}


unsigned int BitArrayCountOn(bitarr_t bit_array)
{
    unsigned int one_counter = 0;
    bitarr_t mask = 0;
    bitarr_t temp = bit_array;    

    while((0 < temp) && (BITS_AMOUNT >= one_counter))
    {
        mask = temp & 1;
        if (0 != mask)
        {
            ++one_counter;
        }
        temp >>= 1;
    }
    return one_counter;
}


unsigned int BitArrayCountOff(bitarr_t bit_array)
{    
    return (BITS_AMOUNT - BitArrayCountOn(bit_array));
}


char *BitArrayToString(bitarr_t bit_array, char *str)
{
	unsigned int i = 0; 
    char *keep_str = str;
    bitarr_t mask = 0x8000000000000000;

    for (i = 0; i < 64; i++)
    {
        if (mask == (bit_array & mask))
        {
            str[i] = '1';
        }
        else
        {
            str[i] = '0';
        }
        mask >>= 1;
    } 
    printf("%s\n", keep_str);
    return keep_str;

}


bitarr_t BitArraySetBit(bitarr_t bit_array, unsigned int index, int set_state)
{
	return (set_state == 1) ? BitArraySetOn(bit_array, index) : BitArraySetOff(bit_array, index);
}


bitarr_t BitArrayMirror(bitarr_t bit_array)
{
    bitarr_t bit_last = 0x8000000000000000;
    bitarr_t bit_first = 1;
    bitarr_t temp = bit_array;


    while(bit_first <= bit_last)
    {
        if ((bit_last & bit_array) != (bit_first & bit_array))
        {
            temp = temp^bit_first;
            temp = temp^bit_last;
        }
        bit_last >>= 1;
        bit_first <<= 1;
    }
    return temp;

}

