#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<assert.h>
#include<stdlib.h>
#include<ctype.h>



char * Strcpy(char *dest, const char *src);
void test_Strcpy();
char * Strncpy(char *dest, const char *src, size_t n);
void test_strncpy();
int Strcmp (char * str1, char * str2);
int Strlen (char *string);
int Strcasecmp(const char * str1, const char *str2);
void test_Strcasecmp();
char *Strdup(char *s);
void test_Strdup();
char *Strndup(char *s, size_t n);
void test_Strndup();
char *Strstr(const char *main, const char *sub);
char *Strchr(const char *str, int c);
int palindrome(const char * string);
char* Strcat(char *dest, const char *src);
void test_Strcat();
char * Strncat(char *dest, const char *src, size_t n);
void test_Strncat();
size_t Strspn(const char *str1, const char *str2);
void test_Strspn();
void test_Strchr();
void test_Strstr();
void test_palindrome();


int main()
{
  
		test_Strstr();
		test_Strchr();
		test_Strspn();
		test_palindrome();
		test_Strncat();
		test_Strcat();
		test_Strndup();
		test_Strcasecmp();
		test_Strcpy();


	return 0;

}


int Strcmp (char * str1, char * str2)
{
	int i, res;

	for (i=0;i<Strlen(str1) || i<Strlen(str2);i++)
	{
		if(str1[i]!=str2[i])
		{
			res=(int)str1[i]-(int)str2[i];
            break;
		
		}
		
		else
		res=0;
	}
	
	


	return res;

}
   

int Strlen (char *string)
{

	char *str=string;
	int count=0;
	
	while(*str!='\0')
	{
		count+=1;
		str++;
	}


	return count;
}



char * Strcpy(char *dest, const char *src)
{

    int i=0;
    
    while(src[i]!= '\0')
    {
        dest[i] = src[i];
        i++;
      
    }
    dest[i] = '\0';
    
    return dest;
}

void test_Strcpy()
{
   const char src[20] = "Helen";
   char dest[20];


  if(Strcpy(dest, src) == strcpy(dest, src))
  {
  	printf("Strcpy works properly\n");
  }
  
  else
  {
  	printf("Strcpy doesn't work properly\n");
  }
  

}




char * Strncpy(char *dest, const char *src, size_t n)
{



    char * start= dest;
    
    
    while(n && *src)
    {
        *dest++ = *src++;
        n--;
    }
    
    
    
    while(n--)
    {
        *dest++ = '\0'; 
    }
    
    *dest = '\0';
    
    return start;
}



void test_Strncpy()
{
   const char src[20] = "Helen";
   char dest[20];
   size_t n=3;


  if(Strncpy(dest, src,n) == strncpy(dest, src,n))
  {
  	printf("Strncpy works properly\n");
  }
  
  else
  {
  	printf("Strncpy doesn't work properly\n");
  }
  

}



int Strcasecmp(const char * str1, const char *str2)
{

	assert (NULL != str1);
	assert (NULL != str2);
	
	while(tolower(*str1) == tolower(*str2))
	{
		if(*str1 == '\0')
		{
			return 0;
		}
		
		str1++;
		str2++;
	}


		return *str1-*str2;
}

void test_Strcasecmp()
{
	char str1[]="HELeN";
	char str2[]="helen";
	
	if(strcasecmp(str1,str2) == Strcasecmp(str1,str2))
	printf("strcasecmp works properly\n");
	
	else
	printf("strcasecmp doesn't work properly\n");
}


char* Strcat(char *dest, const char *src)
{
	
	char * start= dest;
																
	while(*dest != '\0')
	{
		dest++;
	}		
	
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	
	*dest = '\0';
	
	return start;
	
	
}


void test_Strcat()
{

	char str1[100] = "This is ", str2[] = "Helen";
	char st1[100] = "This is ", st2[] = "Helen";
  
   	Strcat(str1, str2);
   	strcat(st1,st2);
   
  	if(strcmp(str1,st1) == 0)
   	printf("Strcat works properly");
   
   	else
   	printf("Strcat doesn't work");


}

char * Strncat(char *dest, const char *src, size_t n)
{
	
	char * start= dest;
	
	while(*dest!='\0')
	{
		dest++;
	}		
	
	while(n>0 && *src!='\0')
	{
		*dest=*src;
		dest++;
		src++;
		n--;
	}
	
	*dest = '\0';
	return start;
}

void test_Strncat()
{
	char str1[100] = "This is ", str2[] = "Helen";
	char st1[100] = "This is ", st2[] = "Helen";
	size_t n=3;
  
    Strncat(str1, str2,n);
    strncat(st1,st2,n);
   
    if(strcmp(str1,st1) == 0)
    printf("Strncat works properly");
    
    else
    printf("Strncat doesn't work");


}



char *Strdup(char *s)
{
	char *target=(char *)malloc(sizeof(s));
	
	Strcpy(target,s);
	
	return target;

}

void test_Strdup()
{

	char source[] = "Helen"; 
 	char* target = Strdup(source); 
 	int res; 
  
 	res= strcmp(source, target);
 	if(res == 0)
  	 printf("Strdup works properly\n");
   
  	 else
  	 printf("Strdup doesn't work\n");


}


char *Strndup(char *s, size_t n)
{
	char *target=(char *)malloc(sizeof(s));
	
	
	Strncpy(target,s,n);
	
	return target;

}


void test_Strndup()
{
 	char source[] = "abcdefghijk"; 
 	char* target1 = Strndup(source, 5); 
    char* target2 = Strndup(source, 5); 
    int res;
    
    res=strcmp(target1,target2);
    
    if(res == 0)
    printf("Strndupworks properly\n"); 
  
    else
    printf("Strndup doesn't work\n");



}


char *Strchr(const char *str, int c)
{
    char *ret = (char *)malloc(sizeof(str));
	
	ret=(char *)str;
	while(*ret != c)
	{
		ret++;
	}
	
	return ret;

}


void test_Strchr()
{

	const char str[] = "yehuda.gilad";
    const char ch = '.';
    char *ret1,*ret2;
    int res;

    ret1 = Strchr(str, ch);
    ret2 = strchr(str, ch);
   
    res= strcmp(ret1,ret2);
    
    if(res == 0)
    printf("Strchr works properly\n");
    
    else
    printf("Strchr doesn't work properly\n");



}

char *Strstr(const char *main, const char *sub)
{
	int res =1;
	int size = strlen(sub) + 1;
	char *dest= (char *)malloc(size);
	
	while(*main++ != '\0')
	{
	    if(*main == *sub)
	    {
	        strncpy(dest,main,size);
	        res=  strcmp(dest,sub);
	        if(res == 0)
	        {
	            free(dest);
	            return (char *)main;
	            break;
	        }
	    }
	}
	
	
	return NULL;
	
}


void test_Strstr()
{
   const char mains[20] = "asdlsPointaa";
   const char subs[10] = "Point";
   char *ret1, *ret2;
   int res;
   

   ret1 = Strstr(mains, subs);
   ret2 = strstr(mains, subs);

   res= strcmp(ret1,ret2);
   
   if(res == 0)
   printf("Strstr works properly\n");
   
   else
   printf("Strstr doesn't work\n");

}

size_t Strspn(const char *s, const char * accept)
{

    size_t counter=0;
    
    while(*s && strchr(accept, *s))
    {
        s++;
        counter++;
    }

    return counter;

}


void test_Strspn()
{
   size_t len1=0, len2=0;
   const char str1[] = "ABCDEFG019874";
   const char str2[] = "ABCD";

   len1 = Strspn(str1, str2);
   len2 = strspn(str1, str2);
   
   if(len1 == len2)
   printf("Strspn works properly\n");
   
   else
   printf("Strspn doesn't work\n");



}


int palindrome(const char * string)
{

	size_t i=0, res=1;
	size_t size= strlen(string);
	
	while(i < size/2)
	{
		if( *(string+i) != *(string+size-1))
		{
			res=0;
			break;
		}
		    i++;
		    size--;
	}
	

	return res;

}


void test_palindrome()
{
	char str1[] ="abba";
	char str2[]= "a bba";
	char str3[]= "step on no pets";
	
	if (palindrome(str1) == 1 && palindrome(str2) == 0 && palindrome(str3) == 1)
	printf("Palindrome works properly\n");
	
	else
	printf("Palindrome doesn't really work..\n");

	 
}
