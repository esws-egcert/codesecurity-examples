#include <string.h>
/*In the following example, the source character string is copied to the dest character string using the method strncpy.*/
int main()
{
    char source[21] = "the character string";
    char dest[12];
    /*Weakness : Coping to dest buffer with source buff size which is > deatination buff size*/
    strncpy(dest, source, sizeof(source)-1);
}
/*However, in the call to strncpy the source character string is used within the sizeof call to determine the number of characters to copy.
 This will create a buffer overflow as the size of the source character string is greater than the dest character string.
  The dest character string should be used within the sizeof call to ensure that the correct number of characters are copied,
  as shown below.

  (good code)
  Example Language: C 
  ...
  char source[21] = "the character string";
  char dest[12];
  strncpy(dest, source, sizeof(dest)-1);
  ...
   */