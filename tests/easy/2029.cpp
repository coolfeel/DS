#include <stdio.h>
#include <string.h>
int main() {
	int n,i,temp,len;
	char str[100];
	scanf("%d",&n);
	getchar();
	if (n<0)
		return 0;
	while (n--) {
		temp=0;
		scanf("%s",str);
		getchar();
		len=strlen(str);
		if (len==1) {
			printf("yes\n");
			continue;
		}
			
		for (i=0;i<(len/2);i++) 	
			if (str[i]==str[len-1-i])   //compare 
				temp++;
		if (temp==(len/2))
			printf("yes\n");
		else
			printf("no\n");
	}
	
} 
