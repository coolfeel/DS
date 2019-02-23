//
// Created by coolrp on 2/22/19.
//

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

#define MAXN 60

struct Room {
    int r, c;
    //构造函数,用rr,cc去初始化结构体变量r,c
    Room(int rr, int cc) : r(rr), c(cc) {}
};

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


void Dfs(int r, int c) {
    //定义栈,类型就是结构体的类型,存储坐标点
    stack <Room> stk;
    //先入栈
    stk.push(Room(r, c));
    while (!stk.empty()) {
        //获得栈顶元素
        Room rm = stk.top();
        //其实就是坐标,分别得到坐标
        int i = rm.r;
        int k = rm.c;
        //被访问过的,直接出栈
        if (color[i][k])
            stk.pop();
        else {
            //当前面积数目
            roomArea++;
            //标记已访问
            color[i][k] = colorNum;
            //按照西1,北2,东4,南8的方向入栈
            if ((rooms[i][k] & 1) == 0)
                stk.push(Room(i, k -1));
            if ((rooms[i][k] & 2) == 0)
                stk.push(Room(i - 1, k));
            if ((rooms[i][k] & 4) == 0)
                stk.push(Room(i, k + 1));
            if ((rooms[i][k] & 8) == 0)
                stk.push(Room(i + 1, k));
        }
    }
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