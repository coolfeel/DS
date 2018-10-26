#include <stdio.h>
int main() {
	int n,a[100],i,j,m;
	while(~scanf("%d",&n)) {
		i=0;
		if (n<=0||n>=1000)
			break;
		while(1) {
			m=n%2;
			a[i++]=m;
			n=n/2;
			if (n==0)
				break;			
		}
		for (j=i-1;j>=0;j--) {
			printf("%d",a[j]);
		}
		printf("\n");
	}
	return 0;
} 
