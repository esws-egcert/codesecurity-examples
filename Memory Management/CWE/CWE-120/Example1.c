#include <stdio.h>
#include <string.h>

int main(){
    char last_name[20];
    printf ("Enter your last name: ");
    /*Weakness :Accepting input from user with no checking on*/
    scanf ("%s", last_name);
    printf("You entered string with length = %d\n",strlen(last_name));
    return 0;
}
/*The problem with the code above is that it does not restrict or limit the size of the name entered by the user.
 If the user enters "Very_very_long_last_name" which is 24 characters long,
then a buffer overflow will occur since the array can only hold 20 characters total.*/