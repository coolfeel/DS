#include <stdio.h>
int main() {
	int m,n,i,j,b;
	double sum1,sum2;
	while(~scanf("%d",&b)) {
		if (b>=100||b<=0) 
			break;
		for (i=0;i<b;i++) {
			sum1=0; 
			sum2=0;
			scanf("%d",&m);
			
			for (j=1;j<=m;j++) {
				if (j%2==0)
					sum2+=-(1.0/j);
				else
					sum1+=1.0/j;
			}
			printf("%.2f\n",sum1+sum2);
		}		
	}
}
 
