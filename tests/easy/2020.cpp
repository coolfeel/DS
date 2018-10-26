#include <stdio.h>
int main() {
    int n,a[130],b[130],c[130],i,j,t,count,k,m;
    while (~scanf("%d",&n)) {
        count=0;
        if (n<=0||n>100) 
            break;
        if (n==1) {
            scanf("%d",&a[0]);
            printf("%d\n",a[0]);
            continue;
        }    
        for (i=0;i<n;i++) {
            scanf("%d",&a[i]);
            for (j=0;j<i;j++) {
                if (a[j]==a[i]||a[j]==-a[i])
                return 0;
            }        
        }    
        for (i=0;i<n;i++) {              //change +
            if (a[i]<0) {
                b[i]=-a[i];
                c[count]=a[i];
                count++;
            }        
            else
                b[i]=a[i];
        }    
        for (k=1;k<n;k++)                 //sort
            for (j=0;j<n-k;j++)
                if (b[j+1]>b[j]) {
                    t=b[j+1];
                    b[j+1]=b[j];
                    b[j]=t;
                }
        
        for (k=0;k<n;k++) {
        	if (count>0) {
        		for (j=0;j<count;j++) {
	                if (c[j]==(-b[k])) {
	                        printf("%d ",-b[k]);
	                        break;
	                    }    
	            }            
            
	        	if (j==count) {
	        		if (k==(n-1))
	        			printf("%d",b[k]);
	        		else
	        			printf("%d ",b[k]);
				}		
			}	 
	        else {
	        	if (k==(n-1))
					printf("%d",b[k]);
				else 
	        		printf("%d ",b[k]);
			}  
        }
        printf("\n");            
    }
} 
