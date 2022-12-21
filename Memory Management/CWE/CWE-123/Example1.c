/*The classic example of a write-what-where condition occurs when the accounting information
 for memory allocations is overwritten in a particular fashion. Here is an example of potentially vulnerable code:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 10

int main()
{
	char *buf1, *buf2;
    /*Weakness : input from user length > BUFSIZE and strcpy doesn't validate the length , code will exit due to overflow [exited with code=3221225477]*/
	char *input_from_user = "asdfghjklzxchbfherhjfbkjh";

	buf1 = (char *) malloc(BUFSIZE * sizeof(char));
	buf2 = (char *) malloc(BUFSIZE * sizeof(char));

    strcpy(buf1, input_from_user);
    
	free(buf2);
	return 0;
}

/*Vulnerability in this case is dependent on memory layout.
 The call to strcpy() can be used to write past the end of buf1, and, with a typical layout,
  can overwrite the accounting information that the system keeps for buf2 when it is allocated.
   Note that if the allocation header for buf2 can be overwritten, buf2 itself can be overwritten as well.*/