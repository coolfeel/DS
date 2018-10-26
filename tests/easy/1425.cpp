#include <stdio.h>
#include <stdlib.h>
using namespace std;


int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int nums[1000010];

int main()
{
    int n, t, mark;
    while (~scanf("%d %d", &n, &mark)) {
        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        qsort(nums, n, sizeof(nums[0]), cmp);
        for (int i = n - 1; i >= n - mark; i--) {
            if (i == n - mark)
                printf("%d\n", nums[i]);
            else
                printf("%d ", nums[i]);
        }
    }
    return 0;
}
