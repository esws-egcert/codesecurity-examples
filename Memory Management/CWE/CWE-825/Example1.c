/*The following code shows a simple example of a use after free error:*/
#include <stdio.h>
#include <stdlib.h>

void logError(char* errmsg, char* ptr)
{
    printf("%s\n Pointer = %d\n",errmsg,ptr);
}

int main ()
{
    int size = 50;
    int abrt = 0; 
    int err = 0;
    char* ptr = (char*)malloc (size);
    /*Simulating the error */
    err = 1;
    if (err == 1) {
        abrt = 1;
        printf("Pointer to free = %d\n",ptr);
        free(ptr);
    }

    if (abrt) {
        /*weakness: Using pointer after free*/
        logError("operation aborted before commit", ptr);
    }
}
/*When an error occurs, the pointer is immediately freed. However, this pointer is later incorrectly used in the logError function.*/