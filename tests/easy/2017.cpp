#include <stdio.h>
int main () {
	int n,i,count;
	char str[100];
	scanf("%d",&n);
	while (n--) {
		count=0;
		scanf("%s",str);
		for (i=0;str[i]!='\0';i++) 
			if (str[i]>=48&&str[i]<=57)  //count num
				count++;
		printf("%d\n",count);
	} 
	return 0;
} 
