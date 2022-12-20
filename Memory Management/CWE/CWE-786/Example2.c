#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*The following is an example of code that may result in a buffer underwrite,
 if find() returns a negative value to indicate that ch is not found in srcBuf*/
 
int find(char* StringToSearchIn, char CharToFind)
{
    int index;
    for (index =0 ; index < strlen(StringToSearchIn); index++)
    {
        if(StringToSearchIn[index] == CharToFind)
        {
            return index;
        }
    }
    return -1;
}
int main() {

    char* destBuf;
    char srcBuf[5] = "Hello";
    char ch = 'k';
    /*Weakness :find will return -1 because 'k' is not in the srcBuf, code will exit due to overflow [exited with code=3221225477] */
    strncpy(destBuf, &srcBuf[find(srcBuf, ch)], 1024);

}
/*If the index to srcBuf is somehow under user control, this is an arbitrary write-what-where condition.*/