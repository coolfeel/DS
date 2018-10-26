#include <stdio.h>
int main() {
	int n,m,i,j,temp,a[105],sum,c;
	while (~scanf("%d%d",&n,&m)) {
		temp=0;
		if ((n>0&&n<=100)&&(m>0&&m<=n)) {
			for (i=1;i<=n;i++)                  //put number 
				a[i-1]=2*i;
				
			for (j=0;j<n;j=j+m)	{
				sum=0;
				if (n/m==temp)
					c=c+n%m;                   //last
				else
					c=m*(temp+1);               
				for (i=j;i<c;i++) 
					sum+=a[i];
				if ((n%m)<m&&(n/m==temp))
					printf("%d\n",sum/(n%m));
				else {
					if (n%m==0&&n/m==(temp+1))  //judge last?
						printf("%d\n",sum/m);
					else	
						printf("%d ",sum/m);
					temp+=1;
				}
			}		
		}
		else 
			break;			
	}
	return 0;
} 
