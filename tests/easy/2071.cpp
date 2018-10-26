#include <stdio.h>
int main() {
	int t,n,i;
	double height[105],max;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		if (n<1||n>100)
			break;
		for (i=0;i<n;i++)
			scanf("%lf",&height[i]);
		max=height[0];
		for (i=1;i<n;i++)
			if(height[i]>max)
				max=height[i];
		printf("%.2lf\n",max);
	}
	return 0;
} 
