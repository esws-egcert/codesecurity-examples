#include <stdio.h>
#include <string.h>

void manipulate_string(char * string){
char buf[24];
/*Weakness :Coping a string passed to fn to the buff without checking the size, code will exit due to overflow [exited with code=3221225477]*/
strcpy(buf, string);
//printf("Length of buffer after coping = %d\n",strlen(buf));
/*Do Smth with buffer*/
}

int main()
{
    char * large_string = "This is a large large large string";
    manipulate_string(large_string);
}
/*However, the programmer does not ensure that the size of the data pointed to by string will fit in the local buffer and copies the data
 with the potentially dangerous strcpy() function. This may result in a buffer overflow condition if an attacker can influence the contents
  of the string parameter.

Best practise : strncpy()
*/