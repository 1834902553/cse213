
//Find Second Maximum from the array

#include<stdio.h>
#include<Limits.h>
int main(){
    int a[10] = {20, 16, 11, 9, 6, 10, 12, 15, 19, 18};
    int size = 10;
    int i, max, second_max;

    max = INT_MIN;
    second_max = INT_MIN;
    for(i=0; i<size; i++){
        if(a[i] > max){
            second_max = max;
            max = a[i];
        }
        else if(a[i] > second_max && a[i] < max){
            second_max = a[i];
        }
    }
    if(second_max == INT_MIN)
        printf("No Second Maximum Number\n");
    else
        printf("%d\n", second_max);
        return 0;
}

