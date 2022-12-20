/*This Code is only to show the weakness but trimming white spaces is done with another way*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* trimTrailingWhitespace(char *strMessage, int length) {
char *retMessage;

// copy input string to a temporary string
char message[length+1];
int index;
for (index = 0; index < length; index++) {
message[index] = strMessage[index];
}
//message[index] = '\0';

// trim trailing whitespace
int len = index-1;
printf("Current index in clearing white space fn = %d\n",len);
while (isspace(message[len])) {
message[len] = '\0';
len--;
printf("Current index in clearing white space fn = %d\n",len);
}

// return string without trailing whitespace
retMessage = message;
return retMessage;
}

int main()
{
     /*Weakness :String with white space at the begining will cause access mem before start of buffer*/
    char *malicious_string  = "  ";
    char *return_message = "";
    printf("Message length is %d\n",strlen(malicious_string));
    return_message = trimTrailingWhitespace(malicious_string,strlen(malicious_string));
}
/*However, this function can cause a buffer underwrite if the input character string contains all whitespace.
 On some systems the while statement will move backwards past the beginning of a character string
  and will call the isspace() function on an address outside of the bounds of the local buffer.*/