
#include <stdio.h>
#include <string.h>

int main()
{
    char buf[24];
    printf("Please enter your name and press <Enter>\n");
    /*Weakness :Coping a string passed from terminal to the buff without checking the size, will cause overflow*/
    gets(buf);
    printf("Length of buffer after accepting user input = %d\n",strlen(buf));
}

/*However, gets() is inherently unsafe,
because it copies all input from STDIN to the buffer without checking size.
This allows the user to provide a string that is larger than the buffer size,
resulting in an overflow condition.

Best practise : fgets()
*/