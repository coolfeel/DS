#include <iostream>
using namespace std;


int part(int A[], int left, int right) {
    int tmp = A[left];
    while (left < right) {
        while (left < right && A[right] > tmp)
            right--;
        A[left] = A[right];
        while (left < right && A[left] < tmp)
            left++;
        A[right] = A[left];
    }
    A[left] = tmp;
    return left;
}


void quicksort(int A[], int left, int right) {
    if (left < right) {
        int pos = part(A, left, right);
        quicksort(A, left, pos - 1);
        quicksort(A, pos + 1, right);
    }
}


int main() {
    int n, lis[50010];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> lis[i];
    quicksort(lis, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << lis[i] << endl;
    return 0;
}
