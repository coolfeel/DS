#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring> 
using namespace std;
 
int m, n, k, numbers[1025], mark, tmp, flag;
 
void next(int size) {
	flag = 0;
	for (int i = size - 1; i > 0; i--) 
		if (numbers[i] > numbers[i - 1]) {
			mark = i;
			flag = 1; 
			break;
		}	
	if (!flag) {
		for (int i = 0; i < size; i++)
			numbers[i] = i + 1;
		return;
	}	
	for (int i = size - 1; i >= mark; i--) {
		if (numbers[i] > numbers[mark - 1]) {
			tmp = numbers[mark - 1];
			numbers[mark - 1] = numbers[i];
			numbers[i] = tmp;
			break;
		}
	}
	while (size - 1 > mark) {
		tmp = numbers[size - 1];
		numbers[size - 1] = numbers[mark];
		numbers[mark] = tmp;
		mark++;
		size--; 
	}
}
 
int main() {
 	scanf("%d", &m);
 	while (m--) {
 		scanf("%d%d", &n, &k);
 		memset(numbers, 0, sizeof(numbers));
 		for (int i = 0; i < n; i++)
			scanf("%d", &numbers[i]);		
		for (int i = 0; i < k; i++)
 			next(n);
		for (int i = 0; i < n; i++) {
			if (i == (n - 1))
				printf("%d", numbers[i]);
			else
				printf("%d ", numbers[i]);
		}
		printf("\n");
	}
 	return 0;
}
