#include <stdio.h>
#include <stdlib.h>
int fibonacciNumber(int n){
    if(n<=0){
        return 0;
    }
    if(n==1||n==2){
        return 1;
    }
    int *num = (int *)malloc(sizeof(int)*n);
    num[0] = 1;
    num[1] = 1;
    for(int i=3; i<=n;i++){
        num[i-1] = num[i-2] + num[i-3];
    }
    int ans = num[n-1];
    free(num);
    return ans;
}

int main(){
    printf("%d", fibonacciNumber(30));
    return 0;
}
