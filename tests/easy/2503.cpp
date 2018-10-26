#include <iostream>
using namespace std;

int gcd(int a,int b) {  //最大公约数 
	return b ? gcd(b, a%b) : a;
}

int main() {
	int n,tmp1,tmp2,a,b,c,d;
	cin>>n;
	while (n--) {
		cin>>a>>b>>c>>d;
		tmp1 = a*d + b*c;
		tmp2 = b*d;
		cout<<tmp1/gcd(tmp1, tmp2)<<' '<<tmp2/gcd(tmp1, tmp2)<<endl;
	}	
	return 0;
}
