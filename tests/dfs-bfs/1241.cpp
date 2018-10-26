#include <iostream>
#include <cstring>
 
using namespace std;

int m,n,vis[110][110],dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
char map[110][110];

void dfs(int x,int y) {
	if (x<0||x>=m||y<0||y>=n)
		return;
	vis[x][y]=1;
	for (int i=0;i<8;i++) {
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if (!vis[tx][ty]&&map[tx][ty]=='@')
			dfs(tx,ty); 
	}		
}

int main() {
	int cnt;
	while (cin>>m>>n&&m) {	
		for (int i=0;i<m;i++)
			cin>>map[i];
		memset(vis,0,sizeof(vis));
		cnt=0;
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++) {
				if (!vis[i][j]&&map[i][j]=='@') {
					dfs(i,j);
					cnt++;
				}	
			}
		cout<<cnt<<endl;		
	}
	return 0;
} 
