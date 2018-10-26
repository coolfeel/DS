#include <stdio.h>
int main() {
    int n,sum,i;
    while(~scanf("%d",&n)) {
        sum=1;
        if (n<=1||n>=30)
            break;
        for (i=1;i<n;i++) //递推关系
            sum=(sum+1)*2;   
        printf("%d\n",sum);
    }
    return 0;
} 
