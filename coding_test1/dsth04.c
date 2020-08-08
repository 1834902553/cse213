/*Search a value X (take input X from user) in the array and print "Found" if X found in the array otherwise print "NotFound".Access the array using pointer.*/


#include <stdio.h>
int main()
{
    int arr[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12};
    int i, X,size=12;
    int *ar=arr;
    int flag=0;
    scanf("%d", &X);
    for (i=0; i<size; i++)
    {
        if(*(ar+i)==X)
        {
            flag ++;
        }
    }
    if(flag==1)
    {
        printf("Found\n");
    }
    else
        printf("Not Found");
    return 0;
}

