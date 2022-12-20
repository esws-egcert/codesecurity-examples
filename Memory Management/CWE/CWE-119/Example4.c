#include <stdio.h>

int getValueFromArray(int *array, int len, int index) {
    int value;
    // check that the array index is less than the maximum
    // length of the array
    if (index < len) {
        // get the value at the specified index of the array
        value = array[index];
    }
    // if array index is invalid then output error message
    // and return value indicating error
    else {
        printf("Value is: %d\n", array[index]);
        value = -1;
    }
    return value;
}

int main(){
    int num_array[5] = {1,2,3,4,5};
    int array_len = sizeof(num_array)/sizeof(num_array[0]);
    int ret_val=0;
    /*Weakness :Index is less than the maximum length of the array cause unexpected output from printf */
    int wrong_index = -1;
    ret_val = getValueFromArray(num_array,array_len,wrong_index);
    printf("Value selected by user = %d\n",ret_val);
}
