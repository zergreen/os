//Phongsakorn Kawhaolai 63050159
#include<stdio.h>
int main(){
    //int a,b,c;
    //scanf("%d %d", &a, &b);
    //c = a * b;
    //printf("a = %d, b = %d, c = %d\n",a,b,c);
    int arr[1000];
    int sum;
    int i=0;
    while(1)
    {
        printf("Enter (INT) : ");
        scanf("%d",&arr[i]);
        if(arr[i]==0)
        {
            break;
        }
        sum += arr[i];
        i++;
    }
    float mean = sum / i;
    printf("sum = %d, mean = %.2f",sum,mean);
    return 0;
}
