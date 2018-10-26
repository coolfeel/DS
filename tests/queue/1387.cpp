#include <iostream>
#include <queue>
#include <map>
#include <set> 
using namespace std;

#define MAX 1500

map<int, int> team;
queue<int> qteam, q[MAX]; 
vector<int> v;

void clear(queue<int> &q) {
	while (!q.empty()) {
		q.pop();
	}
}

int main() {
	int tmp, k = 0;
	while (cin >> tmp && tmp) {	
		for (int i = 0; i < tmp; i++) {
			int val, num;
			cin >> num;
			while (num--) {
				cin >> val;
				team[val] = i;
			}
		}		
		while (1) {
			int val;
			char cmd[20];
			cin >> cmd;
			if (cmd[0] == 'S')
				break;
		    else if (cmd[0] == 'D') {
				int c = qteam.front();
				v.push_back(q[c].front());
				q[c].pop();
				if (q[c].empty())
					qteam.pop();
			} else if (cmd[0] == 'E') {
				cin >> val;
				int c = team[val];
				if (q[c].empty())
					qteam.push(c);
				q[c].push(val);
			}
		}
		cout << "Scenario #" << ++k << endl;
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
			cout << *it << endl;
		v.clear();
		for (int i = 0; i < tmp; i++)
			clear(q[i]);           //清空各个队列 
		clear(qteam);             //清空团体队列 
		team.clear();
		cout << endl;
	}
	return 0;
} 
