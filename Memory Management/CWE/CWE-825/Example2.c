/*The following code shows a simple example of a double free error:*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int size = 50;
    int abrt = 0;

    char* ptr = (char*)malloc (size);
   
   /*Simulating the error */
    abrt = 1;
    if (abrt) {
    printf("Pointer : %d is freed\n",ptr);
    /*Weakness :if code aboted pointer will double free*/
    free(ptr);
    }
    printf("Pointer : %d is freed\n",ptr);
    free(ptr);
    
}
/*Double free vulnerabilities have two common (and sometimes overlapping) causes:

Error conditions and other exceptional circumstances
Confusion over which part of the program is responsible for freeing the memory
Although some double free vulnerabilities are not much more complicated than the previous example, 
most are spread out across hundreds of lines of code or even different files. 
Programmers seem particularly susceptible to freeing global variables more than once.*/