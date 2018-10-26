#include <stdio.h>
#include <string.h>
int main() {
	int n,i;
	char str[15];
	scanf("%d",&n);
	getchar();
	while (n--) {	
		for (i=0;i<11;i++)
			scanf("%c",&str[i]);
		getchar();
		for (i=6;i<11;i++) 
			if (i==6)
				printf("6%c",str[i]);
			else
				printf("%c",str[i]);
		printf("\n");
	} 
	return 0;
} 
