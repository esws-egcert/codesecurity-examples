#define MAX_SIZE 16
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
/*This example applies an encoding procedure to an input string and stores it into a buffer.*/
char * copy_input(char *user_supplied_string){
    int i, dst_index;
    char *dst_buf = (char*) malloc(4*sizeof(char)*MAX_SIZE);
    printf("Size alocated to buffer = %d\n",(4*sizeof(char)*MAX_SIZE) -1);
    if ( MAX_SIZE <= strlen(user_supplied_string) ){
        printf("user string too long, die evil hacker!");
        exit(0);
    }
    dst_index = 0;
/*The programmer attempts to encode the ampersand character in the user-controlled string,
 however the length of the string is validated before the encoding procedure is applied. 
Furthermore, the programmer assumes encoding expansion will only expand a given character by a factor of 4,
while the encoding of the ampersand expands by 5. As a result, 
when the encoding procedure expands the string it is possible to overflow the destination buffer if the attacker provides a string of many ampersands.*/
    for ( i = 0; i < strlen(user_supplied_string); i++ ){
        if( '&' == user_supplied_string[i] ){
            dst_buf[dst_index++] = '&';
            dst_buf[dst_index++] = 'a';
            dst_buf[dst_index++] = 'm';
            dst_buf[dst_index++] = 'p';
            dst_buf[dst_index++] = ';';
        }
        else if ('<' == user_supplied_string[i] ){
        /* encode to &lt; */
        }
        else dst_buf[dst_index++] = user_supplied_string[i];
    }
    /*Weakness : User supplied string has more than "&" thats why printf prints unexpected output*/
    printf("Buffer content after encoding [%s]\n",dst_buf);
    //printf("%d\n",sizeof(dst_buf)/sizeof(dst_buf[0]));
    return dst_buf;
}

int main(){
    char *dst_buff;
    char *uss;
    uss = "H&M&s&f&h&k&z&&";
    dst_buff=copy_input(uss);
  //  printf("%s\n",*dst_buff);
    return 0;
}