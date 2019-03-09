#include <cstdio>

using namespace std;

int main() {
	int N, a, b, c, d, val[101];
	scanf("%d", &N);
	for (int i = 2; i <= N; i++)
		val[i] = i * i * i;
	for (a = 6; a <= N; a++)
		for (b = 2; b < a; b++)
			for (c = b; c < a; c++)
				for (d = c; d < a; d++)
					if (val[a] == val[b] + val[c] + val[d])
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
	return 0;
} 
