#include <iostream>
using namespace std;

int binary(int nums[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == x)
            return 1;
        else if (nums[mid] > x)
            right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int n, nums[100010], q, aim[100010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> q;
    for (int i = 0; i < q; i++)
        cin >> aim[i];
    for (int i = 0; i < q; i++)
        if (binary(nums, 0, n - 1, aim[i]))
            cout << "Yes" << endl;
        else cout << "No" << endl;
    return 0;
}
