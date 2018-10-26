#include <iostream>
using namespace std;

int main() {
	int n,m,f[35];
	cin>>n;
	f[1]=1;
	f[2]=3;
	for (int i=3;i<31;i++)
		f[i]=f[i-1]+2*f[i-2];
	while (n--) {
		cin>>m;
		cout<<f[m]<<endl;		
	}
} 
