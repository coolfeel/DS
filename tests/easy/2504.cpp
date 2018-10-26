#include <iostream>
using namespace std;

int gcd(int a,int b) {  //最大公约数 
	return b ? gcd(b, a%b) : a;
}

int main() {
	int n,x,y,c;
	cin>>n;
	while (n--) {
		cin>>x>>y;
		for (int i = 1;;i++) {
			if (gcd(x, i)==y&&y!=i) {
				c=i;
				break;
			}			
		}
		cout<<c<<endl;
	}
	return 0;
}
