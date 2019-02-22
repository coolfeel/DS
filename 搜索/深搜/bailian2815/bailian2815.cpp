//
// Created by coolrp on 2/22/19.
//

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

#define MAXN 60
int R, C;
//存放代表每个方块的整数
int rooms[MAXN][MAXN];
//0表示未染过(访问)
int color[MAXN][MAXN];
//最大房间面积
int maxRoomArea = 0;
//颜色编号
int colorNum = 0;
//当前正在染色的房间的面积
int roomArea;


void Dfs(int i, int k) {
    //从i, k 出发
    //如果被访问过,就终止
    if (color[i][k])
        return;
    //走到新的未染色的块
    roomArea++;
    //做已访问的标记
    color[i][k] = colorNum;
    //此处1的二进制0001,  2,4,8分别对应0010,0100,1000,他们加起来刚好是1111,1可以代表有墙
    //若1011 & 0100 则表示4的方向 即东 有路可走
    if ((rooms[i][k] & 1) == 0)
        Dfs(i, k - 1);
    if ((rooms[i][k] & 2) == 0)
        Dfs(i - 1, k);
    if ((rooms[i][k] & 4) == 0)
        Dfs(i, k + 1);
    if ((rooms[i][k] & 8) == 0)
        Dfs(i + 1, k);
}


int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
        for (int k = 1; k <= C; k++)
            cin >> rooms[i][k];
    memset(color, 0, sizeof(color));
    //从第1个开始找未染色的
    for (int i = 1; i <= R; i++)
        for (int k = 1; k <= C; k++)
            if (!color[i][k]) {
                //染色计数
                colorNum++;
                //当前房间面试计数
                roomArea = 0;
                //搜索
                Dfs(i, k);
                //记最大面积数
                maxRoomArea = max(roomArea, maxRoomArea);
            }
    cout << colorNum << endl;
    cout << maxRoomArea << endl;
    return 0;
}