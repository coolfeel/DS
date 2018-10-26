#include <iostream>
using namespace std;

void selectSort(int list[], int n) {
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i; j < n; j++)
            if (list[j] < list[k])
                k = j;
        int tmp = list[i];
        list[i] = list[k];
        list[k] = tmp;
    }
}

int main() {
    int n, lis[50010];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> lis[i];
    selectSort(lis, n);
    for (int i = 0; i < n; i++)
        cout << lis[i] << endl;
    return 0;
}
