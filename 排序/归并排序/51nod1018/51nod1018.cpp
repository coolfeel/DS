#include <iostream>

using namespace std;

void mer(int A[], int l1, int r1, int l2, int r2) {
    int i = l1, j = l2;
    int temp[50010], index = 0;  //temp暂时存合并后的数组
    while (i <= r1 && j <= r2) { //2个有序的合为1个
        if (A[i] <= A[j])
            temp[index++] = A[i++];
        else
            temp[index++] = A[j++];
    }
    while (i <= r1) //一方剩下的直接接上
        temp[index++] = A[i++];
    while (j <= r2)
        temp[index++] = A[j++];

    for (i = 0; i < index; i++)
        A[l1 + i] = temp[i];
}

void mersort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mersort(A, left, mid);
        mersort(A, mid + 1, right);
        mer(A, left, mid, mid + 1, right);
    }
}


int main() {
    int n, lis[50010];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> lis[i];
    mersort(lis, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << lis[i] << endl;
    return 0;
}
