/**********************************************************************************************
*                              	         bitarray/OL95 	     	        
**********************************************************************************************/

/*--------------------------------- Header Guard ----------------------------------------*/

#ifndef __ILRD_OL95_BIT_ARRAY_H__
#define __ILRD_OL95_BIT_ARRAY_H__

/*------------------------------------ Typedefs -----------------------------------------*/

typedef unsigned long bitarr_t;
#include <assert.h>

/*--------------------------- Functions declarations ------------------------------------*/

/* DESCRIPTION:
 * Function for setting on all of the bits in given array
 *
 * @param:
 * size_t array: 	bit array to be set on
 *
 * @return:
 * Returns the array with the set bits
 *
 */
bitarr_t BitArraySetAll(bitarr_t bit_array);


/* DESCRIPTION:
 * Function for resetting all of the bits in given array
 *
 * @param:
 * size_t array: 	bit array to be reset
 *
 * @return:
 * Returns the array with the reset bits
 *
 */
bitarr_t BitArrayResetAll(bitarr_t bit_array);


/* DESCRIPTION:
 * Function for setting on a single bit
 *
 * @param:
 * size_t array:	bit array holding the bit to be set on
 * int bit_on:		bit number to be set on
 *
 * @return:
 * Returns the array with the updated bit
 *
 */
bitarr_t BitArraySetOn(bitarr_t bit_array, unsigned int index);


/* DESCRIPTION:
 * Function for setting off a single bit
 *
 * @param:
 * size_t array: 	bit array holding the bit to be set off
 * int bit_off:		bit number to be set off
 *
 * @return:
 * Returns the array with the updated bit
 *
 */
bitarr_t BitArraySetOff(bitarr_t bit_array, unsigned int index);


/* DESCRIPTION:
 * Function for getting the value of a single bit in a given bit array
 *
 * @param:
 * size_t array: 	bit array holding the bit to be checked
 * int bit:			bit number to be checked
 *
 * @return:
 * Returns the value of specified bit in given array
 *
 */
unsigned int BitArrayGetVal(bitarr_t bit_array, unsigned int index);


/* DESCRIPTION:
 * Function for flipping a specified bit in a given bit array
 *
 * @param:
 * size_t array: 	bit array holding the bit to be flipped
 * int bit:			bit number to be flipped
 *
 * @return:
 * Returns the array with the flipped bit
 *
 */
bitarr_t BitArrayFlip(bitarr_t bit_array, unsigned int index);


/* DESCRIPTION:
 * Function for rotating a given array a given number of steps, specified in rotate, to the right
 *
 * @param:
 * size_t array: 	bit array to be rotated
 * int rotate:		number of steps for rotation
 *
 * @return:
 * Returns the rotated array
 *
 */
bitarr_t BitArrayRotRight(bitarr_t bit_array, unsigned int rot_num);


/* DESCRIPTION:
 * Function for rotating a given array a given number of steps, specified in rotate, to the left
 *
 * @param:
 * size_t array: 	bit array to be rotated
 * int rotate:		number of steps for rotation
 *
 * @return:
 * Returns the rotated array
 *
 */
bitarr_t BitArrayRotLeft(bitarr_t bit_array, unsigned int rot_num);


/* DESCRIPTION:
 * Function for counting bits that are set on in a given bit array
 *
 * @param:
 * size_t array: 	bit array holding the bits to be counted
 *
 * @return:
 * Returns the number of bits set on
 *
 */
unsigned int BitArrayCountOn(bitarr_t bit_array);


/* DESCRIPTION:
 * Function for counting bits that are set off in a given bit array
 *
 * @param:
 * size_t array: 	bit array holding the bits to be counted
 *
 * @return:
 * Returns the number of bits set off
 *
 */
unsigned int BitArrayCountOff(bitarr_t bit_array);


/* DESCRIPTION:
 * Function for turning a given bit array to a string,
 * pointer to the string should be sent by user and should hold enough
 * space to hold the string. In case it dosen't or in case the pointer
 * points to NULL, the behavior will be undefined
 *
 * @param:
 * size_t array: 	bit array to be turned to a string
 * char *str:		char * for string to be written on
 *
 * @return:
 * Returns the new string
 *
 */
char *BitArrayToString(bitarr_t bit_array, char *str);


/* DESCRIPTION:
 * Function for setting a bit, specified by user's parameter bit, to a value,
 * also specified by user's parameter bit_val. Sended value could be only
 * 0 or 1, otherwise the behavior will be undefined
 *
 * @param:
 * size_t array:	bit array holding the bit to be set
 * int bit:			bit number specified by user
 * int bit_val:		value specified by user
 *
 * @return:
 * Returns the bit array with the set bit
 *
 */
bitarr_t BitArraySetBit(bitarr_t bit_array, unsigned int index, int set_state);


/* DESCRIPTION:
 * Function for reversing a given bit array
 * 
 * @param:
 * size_t array:	bit array to be reversed
 *
 * @return:
 * Returns the bit array reversed
 *
 */
bitarr_t BitArrayMirror(bitarr_t bit_array);


#endif /* __ILRD_OL95_BIT_ARRAY_H__ */
