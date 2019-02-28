//
// Created by coolrp on 2/27/19.
//


#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
//最优表面积
int minArea = 1 << 30;
//正在搭建中的蛋糕的表面积
int area = 0;
//minV[n]表示n层蛋糕最小的体积,记录当前n层蛋糕最小的体积,为了实现剪枝3
int minV[30];
//minA[n]表示n层蛋糕的最小侧表面积,记录当前n层的最小的表面积,为了实现剪枝1
int minA[30];


int MaxVforNRH(int n, int r, int h) {
    //求在蛋糕有n层,底层最大半径为r,最高高度为h的情况下能凑出来的最大体积
    int v = 0;
    //半径r和高度h一个个递减枚举,同时开始枚举的时候他们取值也是最大的,将枚举的所有体积加起来
    for (int i = 0; i < n; i++)
        v += (r - i) * (r - i) * (h - i);
    return v;
}


void Dfs(int v, int n, int r, int h) {
    //要搭体积为v的n层蛋糕,最底层半径不能超过r,高度不能超过h
    if (n == 0) {
        //层数为0,体积不为0,不存在
        if (v)
            return;
        else {
            //层数和体积都是0,搭建成功,area是成品蛋糕的表面积,此处相当于初始化
            minArea = min(minArea, area);
            return;
        }
    }
    //体积<=0 ,搭建失败
    if (v <= 0)
        return;
    //剪枝3,搭建过程中预见到还没搭的那些层的体积一定会超过还缺少的体积,则停止搭建
    if (minV[n] > v)
        return;
    //剪枝1,搭建过程中发现已建好部分的表面积已经超过目前求得的最优表面积,或者预见到搭完后面积一定会超过目前最优表面积,则停止搭建
    //带预见最优性剪枝
    if (area + minA[n] >= minArea)
        return;
    //剪枝2,搭建过程中预见到再往上搭,高度已经无法安排,或者半径已经无法安排,则停止搭建(可行性剪枝),
    //例如,当前层高度不能超过h,上面还有n层蛋糕要搭,由于每往上一层高度就要减少至少1,那么.若h<n,则上面的高度就无法安排了
    if (h < n || r < n)
        return;
    //剪枝4,搭建过程中预见到没搭的那些层的体积最大也到不了还缺少的体积,则停止搭建(可行性剪枝)
    if (MaxVforNRH(n, r, h) < v)
        return;
    //枚举底层半径
    for (int rr = r; rr >= n; rr--) {
        if (n == M)
            //底面积
            area = rr * rr;
        //枚举底层高度
        for (int hh = h; hh >= n; hh--) {
            area += 2 * rr * hh;
            Dfs(v - rr * rr * hh, n - 1, rr - 1, hh - 1);
            area -= 2 * rr * hh;
        }
    }
}

int main() {
    //M层蛋糕,体积为N
    cin >> N >> M;
    minV[0] = 0;
    minA[0] = 0;
    //计算minV和minA数组,顶层蛋糕的层号是1,事先输入M层,然后计算M层下的蛋糕的整体最小体积,整体最小表面积
    for (int i = 1; i <= M; i++) {
        //第i层半径至少为i,高度至少为i
        minV[i] = minV[i - 1] + i * i * i;
        minA[i] = minA[i - 1] + 2 * i * i;
    }
    //可行性剪枝,要制作的蛋糕体积N比枚举的最小的各M层时蛋糕的体积还小,不存在这种情况
    if (minV[M] > N)
        cout << 0 << endl;
    else {
        //底层最大高度
        int maxH = (N - minV[M - 1]) / (M * M) + 1;
        //最底层体积不超过(N - minV[M - 1]),且半径至少为M,底层高度至少为M
        int maxR = sqrt(double(N - minV[M - 1]) / M) + 1;
        area = 0;
        minArea = 1 << 30;
        Dfs(N, M, maxR, maxH);
        if (minArea == 1 << 30)
            cout << 0 << endl;
        else
            cout << minArea << endl;
    }
    return 0;
}