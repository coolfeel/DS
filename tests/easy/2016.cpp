#include <stdio.h>
int main() {
	int n,i,t,change,min,a[110];
	while (~scanf("%d",&n)) {
		t=0;                   //init t 
		if (n>=100||n<=0)
			break;	
		for (i=0;i<n;i++) 
			scanf("%d",&a[i]);
		min=a[0];
		for (i=1;i<n;i++) 
			if (a[i]<min) {    //compare
				min=a[i];
				t=i;
			}
		
		if (t!=0) {           //change
			change=a[t];
			a[t]=a[0];
			a[0]=change;
		}
		
		
		for (i=0;i<n;i++) {   //print
			if (i==(n-1))
				printf("%d",a[i]);
			else
				printf("%d ",a[i]);
		}
			
		printf("\n");
	}
	return 0;
} 
