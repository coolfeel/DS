#include <stdio.h>
int main() {
	int x,y,n,num,i,temp,s;
	while(~scanf("%d%d",&x,&y)) {
		if (x==0&&y==0) 
			break;
		if ((x<50&&x>=-39)&&(y>-39&&y<=50)) {
			if (x<y) {
				temp=0; s=0;                 //reset
				for (n=x;n<=y;n++) {
					num=n*n+n+41;
					for (i=2;i<num;i++) {    //2~self-1  count
						if (num%i==0)
							s++;
					}
					if (s==0)                //yes or no?
						temp++;	            //count num
				}
				if (temp==(y-x+1))          //all??
					printf("OK\n");
				else
					printf("Sorry\n");	
			}
			else break;
		}
		else break;		
	}
	return 0;
} 
