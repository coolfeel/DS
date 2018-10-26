#include <stdio.h>
int main() {
	double array[50];
	int n,i,j,a,b,c;
	while (~scanf("%d",&n)) {
		a=0,b=0,c=0;
		if (n>=100||n==0) 
			break;
		for (i=0;i<n;i++)  
			scanf("%lf",&array[i]);
		for (j=0;j<n;j++) {         /*统计正负零个数*/ 
			if (array[j]<0) a++;    
			if (array[j]==0) b++;
			if (array[j]>0) c++;
		}	
		printf("%d %d %d\n",a,b,c);	 
	}
	return 0;
} 
