//
// Created by coolrp on 2/24/19.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Road {
    //此路终点为d,长度为L,过路费为t
    int d, L, t;
};

//邻接表, cityMap[i]是从点i有路连到的城市的集合
vector <vector <Road>> cityMap(110);

//目前最优路径的长度,输入的钱,终点城市,R行,正在走的路径的长度,正在走的路径的花费,标记已走过,minL[i][j]表示从1到i点,花费为j的最短路的长度
int minLen = 1 << 30, K, N, R, totalLen, totalCost, visited[110], minL[110][10100];

void Dfs(int s) {
    //从s出发开始向N走
    if (s == N) {
        minLen = min(minLen, totalLen);
        return;
    }
    //逐个考察s右路连到的点
    for (int i = 0; i < cityMap[s].size(); i++) {
        //s有路连到d
        int d = cityMap[s][i].d;
        if (!visited[d]) {
            int cost = totalCost + cityMap[s][i].t;
            //超过钱数,直接跳过,计算下一个s连到的点, 可行性剪枝
            if (cost > K)
                continue;
            //基本最优性剪枝和处处最优剪枝(还要考虑花费)
            if (totalLen + cityMap[s][i].L >= minLen || totalLen + cityMap[s][i].L >= minL[d][cost])
                continue;
            totalLen += cityMap[s][i].L;
            totalCost += cityMap[s][i].t;
            minL[d][cost] = totalLen;
            visited[d] = 1;
            Dfs(d);
            visited[d] = 0;
            totalCost -= cityMap[s][i].t;
            totalLen -= cityMap[s][i].L;
        }
    }
}

int main() {
    cin >> K >> N >> R;
    //构建邻接表
    for (int i = 0; i < R; i++) {
        int s;
        Road r;
        cin >> s >> r.d >> r.L >> r.t;
        if (s != r.d)
            cityMap[s].push_back(r);
    }
    //初始化都为最大
    for (int i = 0; i < 110; i++)
        for (int j = 0; j < 10100; j++)
            minL[i][j] = 1 << 30;
    memset(visited, 0, sizeof(visited));
    totalLen = 0;
    totalCost = 0;
    visited[1] = 1;
    minLen = 1 << 30;
    Dfs(1);
    if (minLen < (1 << 30))
        cout << minLen << endl;
    else
        cout << "-1" << endl;
    return 0;
}

