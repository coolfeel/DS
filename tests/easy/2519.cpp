#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
	int t,m,n,i,j;
	double a,b;
	cin>>t;
	while(t--)
	{
		a=1;b=1;
		cin>>n>>m;
		for(i=0;i<m;i++)
			a*=(n-i);
		for(j=0;j<m;j++)
			b*=(m-j);
		cout<<fixed<<setprecision(0)<<a/b<<endl;
	}
	return 0;
}
