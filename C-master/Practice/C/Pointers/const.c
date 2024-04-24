#include<stdio.h>
int ReplaceValue(int *iData)
{
    *iData = 11;
    return 0;
}

int main()
{
    const int arr[5] = {1, 2, 3, 4, 5};
    
    printf("arr[3] before calling function = %d\n\n", arr[3]);
    ReplaceValue(&arr[3]);
    printf("\narr[3] after calling  function = %d\n\n", arr[3]);
        
    int data = 2,data2 = 3;

    //pointer to const int -> value cannot be changed
    
    const int* piData = &data;
    /*
    Assign the address of iIndexData
    to a pointer to const,here integer
    variable qualify to const integer
    its called up qualification which is valid in c
    */
    piData = &data;
    //Try to change data constant object
    //*piData = 3;
    printf("Data is %d",*piData);
    
    //Display data
    printf("*piData is %d\n",*piData);
    //It's valid because pointer is not a constant
    piData = &data2;

    printf("*piData is %d\n",*piData);

    // constant pointer to int -> pointer cannot be changed
    int* const piData1 = &data;
    //Display data
    printf("*piData is %d\n",*piData1);
    /*It's invalid because pointer is constant*/
    //piData1 = &Data2;
    *piData1 = 10;
    printf("*piData is %d\n",*piData1);
    printf("*data is %d\n",data);


    // constant pointer to constant int -> pointer and data both cannot be changed
    const int* const piData2 = &data;

    /*It's invalid because pointer is constant pointer to constant int*/
    //piData2 = &Data2;
    //*piData2 = 10;
}

