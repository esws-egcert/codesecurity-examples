#include <stdio.h>

/*The following example asks a user for an offset into an array to select an item.*/
int GetUntrustedOffset(){
     /*Weakness : Choosing not valid index caused unexpected output in printf*/
    int x=-1;
    return x;
}

int main (int argc, char **argv) {
    char *items[] = {"boat", "car", "truck", "train"};
    int index = GetUntrustedOffset();
    printf("You selected %s\n", items[index-1]);
}