#include <stdio.h>

int main() {
	int m,n,t,num,temp;
	while(~scanf("%d%d",&m,&n)) {
		if (m<=0||n<=0)
			break;
		if (m<n) {
			t=m; m=n; n=t; //保证大小数 
		}
		
		while(1) {
			temp=m%n;     //2个数，大数对小数取余
			if (temp==0)  //若为0，小数就是最大公约数 
				break;
			else {
				m=n; n=temp;  //否则用小数和余数继续取余 
			}
		}		
		printf("%d\n",n);
	}
	return 0;
} 
