#include <iostream>
#include <cstring>
using namespace std;

//大数结构体
struct bign {
    int d[1000], len;
    bign() {          //构造函数，初始化结构体
        len = 0;
        memset(d, 0, sizeof(d));   //d初始0，防止不确定数
    }
}

//存储
bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0;i < a.len; i++)           //逆着，整数高位仍然在数组的高位，方便先从数组的低位即整数的低位，即从个位开始加减
        a.d[i] = str[a.len - 1 - i] - '0';
    return a;
}


//2个大数比较
int compare(bign a, bign b) {
    if (a.len > b.len)
        return 1;
    else if (a.len < b.len)
        return -1;
    else {
        for (int i = a.len - 1; i >= 0; i--)   //长度一样，开始从整数的个位开始加减进位
            if (a.d[i] > b.d[i])
                return 1;
            else if (a.d[i] < b.d[i])
                return -1;
    }
    return 0;
}


//高精度加法
bign add(bign a, bign b) {
    bign c;
    int carry = 0;  //进位
    for (int i = 0; i < a.len || i < b.len; i++) {   //以较长的为界限
        int tmp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = tmp % 10;      //个位数的结果
        carry = tmp / 10;             //十位数为新的进位
    }
    if (carry != 0)                    //若最后进位不为0， 则直接将结果给最高位
        c.d[c.len++] = carry;
    return c;
}

//大-小 高精度减法
bign sub(bign a, bign b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++) {
        if (a.d[i] < b.d[i]) {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];   //减法结果为当前位结果
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)  //长度大于1，且最后位为0，即没有有效位了
        c.len--;   //真正长度,因len一直是指向下一位
    return c;
}


//高精度与低精度的乘法
bign multi(bign a, int b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; i++) {
        int tmp = a.d[i] * b + carry;
        c.d[c.len++] = tmp % 10;             //个位作为该位结果
        carry = tmp / 10;                    //高位作为新的进位
    }
    while (carry != 0) {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}


//高精度与低精度除法
bign divide(bign a, int b, int &r) {
    bign c;
    c.len = a.len;        //被除数的每一位和商的每一位是一一对应的，令长度相等
    for (int i = a.len - 1; i >= 0; i++) {   //从高位开始
        r = r * 10 + a.d[i];                 //和上一位遗留的余数开始
        if (r < b)
            c.d[i] = 0;                      //不够除，则该位为0
        else {
            c.d[i] = r / b;                  //商
            r = r % b;                       //新余数
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--；
    }
    return c;
}





int main() {
    return 0;
}
