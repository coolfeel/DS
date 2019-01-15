//
// Created by coolrp on 1/15/19.
//
/*宽度优先搜索（BFS，Breadth-First Search）按照距开始状态由远及近的顺序进行搜索，
 * 因此可以很容易用来求最短路径，最少操作之类的问题。它与深度优先搜索类似，从某个状态出发搜索所有可以到达的状态。
 * 对于同一个状态，宽度优先搜索只经过一次，因此复杂度为O（状态数∗转移方式）
 * 因为要向三个状态发生转移，所以我们用d[i]d[i]数组来表示三个状态的方向向量，这样通过一个循环就可以实现三个状态的遍历。
深度优先搜索（隐式地）利用了栈进行计算，而宽度优先搜索则利用了队列。搜索时首先将初始状态添加到队列里，此后从队列的最前端不断取状态，
 把从该状态可以转移到的状态中尚未访问的部分加入队列，如此往复，直至队列被取空或者找到了问题的解。

 * */

#include <cstdio>
#include <queue>
#include <cstring>

#define MAX 100001

using namespace std;

int x, y, curt, res, close[MAX], state[3];
queue<int> aim;

void bfs() {
    memset(close, -1, sizeof(close));
    //出发点
    aim.push(x);
    //初始步数为0
    close[x] = 0;
    //队列不空就继续进行
    while (!aim.empty()) {
        curt = aim.front();
        aim.pop();
        //找到终点则结束
        if (curt == y)
            break;
        //3个状态点
        state[0] = curt - 1;
        state[1] = curt + 1;
        state[2] = curt * 2;
        for (int i = 0; i < 3; i++) {
            //未被访问的
            if (state[i] >= 0 && state[i] < MAX && close[state[i]] == -1) {
                //未来的状态中还未被访问的,进入队列
                aim.push(state[i]);
                //在原始的出发点上步数加1
                close[state[i]] = close[curt] + 1;
            }
        }
    }
    res = close[y];
    printf("%d\n", res);
}

int main() {
    scanf("%d%d", &x, &y);
    bfs();
    return 0;
}


