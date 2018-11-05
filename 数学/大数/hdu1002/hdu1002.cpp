#include <iostream>
#include <cstring>
using namespace std;

struct bign {
    int d[1010], len;
    bign() {
        len = 0;
        memset(d, 0, sizeof(d));
    }
};



bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0;i < a.len; i++)
        a.d[i] = str[a.len - 1 - i] - '0';
    return a;
}




bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++) {
        int tmp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    if (carry != 0)
        c.d[c.len++] = carry;
    return c;
}



int main() {
    int n, t;
    cin >> n;
    t = n;
    while (n--) {
        char a[1010], b[1010];
        cin >> a >> b;
        bign numa = change(a);
        bign numb = change(b);
        bign result = add(numa, numb);
        cout << "Case " << t - n << ':' << endl;
        cout << a << " + " << b << " = ";
        for (int i = result.len - 1; i >= 0; i--)
            cout << result.d[i];
        cout << endl;
        if ((t - n) != t)
            cout << endl;
    }
    return 0;
}
