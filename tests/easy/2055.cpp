#include <stdio.h>
int main() {
	int n,num,result;
	char c;
	scanf("%d",&n);
	getchar();
	while (n--) {
		result=0;
		scanf("%c%d",&c,&num);
		getchar();                  
		if (c>=65&&c<=90) 
			result=(int)(c-64)+num;     //change
		if (c>=97&&c<=122)
			result=-(int)(c-96)+num;
		printf("%d\n",result);
	}
	return 0;
} 
