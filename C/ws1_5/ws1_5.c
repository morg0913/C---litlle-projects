/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/*q1*/
void swapInt(int *s1, int *s2);

/*q2*/
void copyArr(void *src, void *dest, size_t bytesNeeded);

/*q4.A*/
void swapSizetPtr(size_t **s1, size_t **s2);
/*q4.B*/
void swapSizeT(size_t *s1, size_t *s2);
/****************************************************/

int main()
{
/* Q1 start*/
	int x = 6;
	int y = 1;
	int *a = &x;
	int *b = &y;
/* Q1 end */

/* Q2 start */
	int num1 = 2;
	int num2 = 3;

	int arr1[] = {1,2,3,4};
	int arr2[4];
	size_t size = 16;
/* Q2 end */	

		
/*Q4*/
	int *num3 = (int*)100;
	int *num4 = (int*)200;

/*----------------------------------------------------------------*/


/* Q1 start */
	printf("before swap a: %d, b: %d\n", x, y);	
	swapInt(a, b);
	printf("after swap a: %d, b: %d\n", x, y);
/* Q1 end */


/* Q2 start*/
	copyArr( arr1,  arr2, size);
	printf("%d , %d, %d, %d\n", arr2[0],arr2[1],arr2[2],arr2[3]  );
/* Q2 end */

/* Q4 start */
	printf("before swapSizet a: %d, b: %d\n",num1, num2);	
	swapSizeT((size_t*)&num1, (size_t*)&num2);
	printf("after swapsizet a: %d, b: %d\n", num1, num2);
	
	printf("before swapSizetPtr a: %p, b: %p\n", (void*)num3, (void*)num4);	
	swapSizetPtr((size_t**)&num3, (size_t**)&num4);
	printf("after swapsizetPtr a: %p, b: %p\n", (void*)num3, (void*)num4);
/* Q4 end */

    return 0;
}






/*q1*/
void swapInt(int *s1, int *s2){
	int temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}





/*q2*/
void copyArr(void *src, void *dest, size_t bytesNeeded){
	size_t i;
	char *tmp_src = (char*) src;
	char *tmp_dest = (char*) dest;

	for(i = 0; i < bytesNeeded; i++){
		tmp_dest[i] = tmp_src[i];
	}
}





/* 	q4.A) size_t 	*/
void swapSizeT(size_t *s1, size_t *s2){
	size_t tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

/* 	q4.B) size_t* 	*/
void swapSizetPtr(size_t **s1, size_t **s2)
{
	swapSizeT((size_t*)s1, (size_t*)s2);
}

























