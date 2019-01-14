//
// Created by coolrp on 1/14/19.
//
//车上空间总能容纳我们的所有箱子，当搬一只箱子的时候，
// 我们去前边已经堆好的那些垛里看看这只箱子能否堆在它们上边，若能就堆到上边，若不能就另开一堆

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int w[60] = {0}, res[60] = {0}, N, cnt = 0, i, j, flag;
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> w[i];
    res[cnt++] = w[0];
    for (i = 1; i < N; i++) {
        flag = 0;
        sort(res, res + cnt);
        for (j = 0; j < cnt; j++)
            if (res[j] >= w[i]) {
                res[j] = w[i];
                flag = 1;
                break;
            }
        if (!flag)
            res[cnt++] = w[i];
    }
    cout << cnt << endl;
    return 0;
}
