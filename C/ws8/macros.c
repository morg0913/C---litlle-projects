#include <stdio.h>

#define SIZEOF_VAR(object) (char*)(&object+1) - (char*)(&object)

#define SIZEOF_TYPE(object) (char*)(&object+1) - (char*)(&object)


#define MAX2(a,b) ((a) > (b)  ? (a) : (b) )
#define MAX3(a,b,c) (MAX2(MAX2(a,b),c))

	struct s{
		int x;
		int z;
		char c;
		short s;
		long t;
	};

int main()
{
	
	int x = 1;
	int y = 2;
	int z = 3;
	char c = 'c';
	long blat = 1.2131242;
	struct s ssd = {1,2,'c',11, 1.2131242};
	/*printf("%d\n", MAX2(x,y));
	printf("%d\n", MAX3(x,y,z));*/
	printf("%ld\n", SIZEOF_TYPE(blat));
	printf("%ld\n", SIZEOF_VAR(ssd));
	return 0;
}





/*_ _ _ _    _ _ _ _    _  *	_ _ 	****	_ _ _ _ _ _ - _*/
    x		z	c	s			t
