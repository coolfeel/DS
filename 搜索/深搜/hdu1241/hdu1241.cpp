////
//// Created by coolrp on 2/16/19.
////
//

#include <cstdio>
#include <cstring>

char map[110][110];
//注意x的坐标++是向下,注意坐标,周围任何转向都行
int visit[110][110], m, n, dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

void dfs(int x, int y) {
    //标记已访问
    visit[x][y] = 0;
    for (int k = 0; k < 8; k++) {
        int xx, yy;
        xx = x + dir[k][0];
        yy = y + dir[k][1];
        if (map[xx][yy] == '@' && xx >= 0 && xx < m && yy >= 0 && yy < n && visit[xx][yy])
            dfs(xx, yy);
    }
}


int main() {
    int sum;
    while (scanf("%d%d", &m, &n) != EOF && m) {
        sum = 0;
        for (int i = 0; i < m; i++)
            scanf("%s", map[i]);
        memset(visit, 1, sizeof(visit));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (map[i][j] == '@' && visit[i][j]) {
                    dfs(i, j);
                    sum++;
                }
        printf("%d\n", sum);
    }
    return 0;
}