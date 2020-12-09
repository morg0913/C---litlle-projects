
/***********************************   Libraries    **************************************/

#include <stdio.h>   /* printf() */
#include <math.h>

/***************************  Functions definitions    ***********************************/


/******************************************************************************************
*			             Function for swapping two given numbers   		                  *
*    			      				                                   					  *
******************************************************************************************/
void swap(int *s1, int *s2){
	int temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}


/******************************************************************************************
*			             Function for flipping a given number   		                  *
*    			      				                                   					  *
******************************************************************************************/
int flip(int num){
	int dig = 0;
	int flip = 0;

	while (num > 0 ) {
		dig = num % 10;
		flip = (flip * 10) + dig;
		num /= 10;
	}
	return flip;
	
}
	


/******************************************************************************************
*             Function for printing "Hello World!" using hexadicemal values   		      *
*    			      				                                   					  *
******************************************************************************************/
void PrintfHelloWorld()
{
	printf("\nPrintfHelloWorld function testing:");

	printf("\n\x22\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64\x21\x22\n");
}
/******************************************************************************************/

/******************************************************************************************
			             Function for powering a given number by 10   		              
   			      				                                   					  
******************************************************************************************/

double PowTen(double exponent){

	double base = 10.0;
	double res = 1.0;
	int i = 0;
	
	if(exponent < 0){
	   exponent *= (-1);
	   base = 1 / base;
	}

	for  (; i < exponent; i++){
	    res = res * base;
	}
	return res;
	}
/******************************************************************************************
*  			             		Testing Pow10 function   		                          *
*    			      				                                   					  *
******************************************************************************************/
void TestPow()
{
	double given_num = 2;
	double expected_answer = 100;

	printf("\nPow10 function testing:\n");

	if (expected_answer == PowTen(given_num))
	{
		printf("Pow10 funtion passed successfully\n");
	}
	else
	{
		printf("Pow10 funtion failed\n");
	}
}
/******************************************************************************************
*  			             		Testing Swap function   		                      *
*    			      				                                   					  *
******************************************************************************************/
void TestSwap(){
	int x = 1;
	int y = 2;
	
	printf("testing...");
	
	swap(&x, &y);

	if( x == 2 && y == 1){
	   printf("success");
	}else {
		printf("fild");
	}
}



/******************************************************************************************
*  			             		Testing FlipNum function   		                          *
*    			      				                                   					  *
******************************************************************************************/
void TestFlip(){
	int num = 12340;
	int rev = 4321;
	if ( rev == flip(num)){
		printf("ok");
	} else {
		printf("wrong");
}
}
/***************************************** MAIN ******************************************/

int main()
{
	PrintfHelloWorld();
	TestPow();
	TestFlip();
	TestSwap();

	return 0;
}





