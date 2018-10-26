#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct rice {
	int price;
	int height;
}r[1100]; 

bool cmp(struct rice &a,struct rice &b) {
	return a.price<b.price;
}

int main() {
	int c,n,m;
	double cnt;
	cin>>c;
	while (c--) {
		cnt=0;
		cin>>n>>m;
		for (int i=0;i<m;i++)
			cin>>r[i].price>>r[i].height;
		sort(r,r+m,cmp);
		for (int i=0;i<m;i++) {
			if (r[i].height*r[i].price>=n) {
				cnt+=1.0*n/r[i].price;
				n-=1.0*n*r[i].height/r[i].height;
			} else {
				cnt+=r[i].height;
				n-=r[i].height*r[i].price;
			}
			if (!n)
				break;		
		}
		cout<<fixed<<setprecision(2)<<cnt<<endl;
	}
	return 0;
} 
