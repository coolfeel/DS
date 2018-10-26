#include <stdio.h>
int main() {
	int N,a,i,sum;
	scanf("%d",&N);
	if (N>0) {
		while (N--) {
			sum=3;
			scanf("%d",&a);
			if (a<=0||a>30)
				break;
			for (i=1;i<=a;i++) 
				sum=(sum-1)*2;     
			printf("%d\n",sum);
		} 
	}
	return 0;
} 
