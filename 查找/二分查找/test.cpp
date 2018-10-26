#include <iostream>
using namespace std;


int binary(int A[], int left, int right, int x) {
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (A[mid] == x)
            return mid;
        else if (A[mid] > x)
            right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}


int main() {
    int A[10] = {1, 3, 4, 6, 6, 8, 10, 11, 12, 15};
    cout << binary(A, 0, 9, 6);
    return 0;
}

