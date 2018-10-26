#include <iostream>
#include <cstring>

using namespace std;

struct node {
    long long num, score;
}stu[1100];

int main()
{
    long long mark, i, res, cnt, ranklist[110];
    while (cin >> mark) {
        cnt = 0;
        i = 0;
        memset(ranklist, 0, sizeof(ranklist));
        while (cin >> stu[i].num >> stu[i].score) {
            if (!stu[i].num && !stu[i].score)
                break;
            if (stu[i].num == mark)
                res = stu[i].score;
            i++;
        }
        for (int j = 0; j < i; j++)
            ranklist[stu[j].score]++;
        for (int j = 0; j <= 100; j++)
            if (ranklist[j] && j > res)
                cnt += ranklist[j];
        cout << cnt + 1;
    }
    return 0;
}
