#include <stdio.h>
#include <algorithm>

using namespace std;

struct t{
    int startTime;
    int endTime;
}itemTime[120];

bool cmp(const t &a,const t &b) {
    return a.endTime<b.endTime;
}

int main()
{
    int n,count,lastTime;
    while (scanf("%d",&n)!=EOF&&n) {
        count=0;
        lastTime=-1;
        for (int i=0;i<n;i++)
            scanf("%d%d",&itemTime[i].startTime,&itemTime[i].endTime);

        sort(itemTime,itemTime+n,cmp);

        for (int i=0;i<n;i++) {
            if (itemTime[i].startTime>=lastTime) {
                count++;
                lastTime=itemTime[i].endTime;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
