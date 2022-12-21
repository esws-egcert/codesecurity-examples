/*In this example, the method outputFilenameToLog outputs a filename to a log file.
 The method arguments include a pointer to a character string containing the file
  name and an integer for the number of characters in the string. The filename is
   copied to a buffer where the buffer size is set to a maximum size for inputs to the log file.
    The method then calls another method to save the contents of the buffer to the log file.*/

#include <string.h>
#define LOG_INPUT_SIZE 40

int saveToLogFile(char* buff_to_save)
{
    return 1;
}

// saves the file name to a log file
int outputFilenameToLog(char *filename, int length) {
int success;

// buffer with size set to maximum size for input to log file
char buf[LOG_INPUT_SIZE];

// copy filename to buffer
strncpy(buf, filename, length);

// save to log file
success = saveToLogFile(buf);

return success;
}

int main ()
{
    /*Weakness : File name length max size [LOG_INPUT_SIZE] > */
    int filenamelen = 50;
    char namefile[filenamelen];
    outputFilenameToLog(namefile,filenamelen);
}

/*However, in this case the string copy method, strncpy,
 mistakenly uses the length method argument to determine
  the number of characters to copy rather than using the size of the local character string,
  buf. This can lead to a buffer overflow if the number of characters contained in character
  string pointed to by filename is larger then the number of characters allowed for the local character string.
  The string copy method should use the buf character string within a sizeof call to ensure that only characters
   up to the size of the buf array are copied to avoid a buffer overflow, as shown below.

(good code)
Example Language: C 
...
// copy filename to buffer
strncpy(buf, filename, sizeof(buf)-1);
...
*/