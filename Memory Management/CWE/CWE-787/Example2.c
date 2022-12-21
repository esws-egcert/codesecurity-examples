#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Widget;
#define MAX_NUM_WIDGETS 30 

unsigned int GetUntrustedSizeValue()
{
    unsigned int num = 10;
    return num;
}

void ExitError (char* message)
{
    printf("%s\n",message);
    exit(1);
}


int main()
{
    int i;
    unsigned int numWidgets;
    
    Widget **WidgetList;
    Widget *innerlist;

    int rowsize=0;
    int columnsize =0;

    numWidgets = GetUntrustedSizeValue();
    printf("WidgetList Size = %d\n",numWidgets);
    if ((numWidgets == 0) || (numWidgets > MAX_NUM_WIDGETS)) {
    ExitError("Incorrect number of widgets requested!");
    }

    WidgetList = (Widget **)malloc(numWidgets * sizeof(Widget*));
    innerlist = (Widget *)malloc(numWidgets * sizeof(Widget));

    for(i=0; i<numWidgets; i++) {
        innerlist[i] = 123;
    }

    for(i=0; i<numWidgets; i++) {
        WidgetList[i] = (Widget *)innerlist[i];
    }

    WidgetList[numWidgets] = NULL;
    /*Weakness :Printf of array[arraylength] should be rubbish value but here it will print zero because code had accessd array out of bound*/
    printf("Content of WidgetList[%d] = %d\n",numWidgets,WidgetList[numWidgets]);
    
}
/*However, this code contains an off-by-one calculation error (CWE-193).
 It allocates exactly enough space to contain the specified number of widgets,
  but it does not include the space for the NULL pointer.
  As a result, the allocated buffer is smaller than it is supposed to be (CWE-131).
  So if the user ever requests MAX_NUM_WIDGETS, there is an out-of-bounds write (CWE-787) when the NULL is assigned.
  Depending on the environment and compilation settings, this could cause memory corruption.*/