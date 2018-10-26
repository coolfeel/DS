#include <stdio.h>
int main() {
	int n,i,j,t;
	double sum,a[105];             //array size
	while(~scanf("%d",&n)) {
		sum=0;
		if (n<=2||n>100)
			break;
		for (i=0;i<n;i++) {
			scanf("%lf",&a[i]);
			if (a[i]<0||a[i]>100)
				return 0;
		}
			
		for (i=0;i<n-1;i++)                 //sort
			for (j=0;j<n-1-i;j++)
				if (a[j]<a[j+1]) {
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
		for (i=1;i<n-1;i++)
			sum+=a[i];
		printf("%.2f\n",sum/(n-2));
	}
} 
