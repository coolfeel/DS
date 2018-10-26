#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
    char str[1100], buf[1100], *p;
    LL res[1100];
    while ( cin >> str) {
        int len = strlen(str), tmp = 0, k = 0;
        memset(buf, '\0', sizeof(buf));
        p = strtok(str, "5");
        while (p != NULL) {
            res[k++] = atoi(p);
            p = strtok(NULL, "5");
        }
        sort(res, res + k);
        for (int j = 0; j < k; j++) {
            if (j == k - 1)
                cout << res[j] << endl;
            else
                cout << res[j] << ' ';
        }
    }
    return 0;
}
