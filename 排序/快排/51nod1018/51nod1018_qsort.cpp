#include <iostream>
#include <stdlib.h>
using namespace std;

int cmp (const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, lis[50010];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> lis[i];
    qsort(lis, n, sizeof(lis[0]), cmp);
    for (int i = 0; i < n; i++)
        cout << lis[i] << endl;
    return 0;
}
