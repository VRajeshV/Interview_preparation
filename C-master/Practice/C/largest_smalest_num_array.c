#include <stdio.h>
 
int main()
{
    int size, i, largest,smalest;
 
    printf("\n Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];  //Declaring array
 
    //Input array elements
 
    printf("\n Enter %d elements of the array: \n", size);
 
    for (i = 0; i < size; i++)
    {   
        scanf(" %d", &array[i]);
    }
 
     //Declaring Largest element as the first element
    largest = array[0];
 
    for (i = 1; i < size; i++) 
    {
        if (largest < array[i])
        largest = array[i];
    }

    //Declaring smalest element as the first element
    smalest = array[0];
 
    for (i = 1; i < size; i++) 
    {
        if (smalest > array[i])
        smalest = array[i];
    }

    printf("\n largest element present in the given array is : %d", largest);
    printf("\n smalest element present in the given array is : %d", smalest);
 
    return 0;
 }