#include <iostream>
using namespace std;

void insertSort(int list[], int n) {
    for (int i = 1; i < n; i++) {
        int tmp = list[i], j = i;
        while (j > 0 && tmp < list[j - 1]) {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = tmp;
    }
}

int main() {
    int n, lis[50010];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> lis[i];
    insertSort(lis, n);
    for (int i = 0; i < n; i++)
        cout << lis[i] << endl;
    return 0;
}
