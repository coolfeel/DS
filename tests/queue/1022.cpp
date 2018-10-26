#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	int n, im, om, flag, len, k, vis[1100];
	char instr[1100], outstr[1100];
	while (cin >> n >> instr >> outstr) {
		im = 1;
		om = 1;
		flag = 1;
		k = 0;
		memset(vis, 0, sizeof(vis));
		len = strlen(outstr);
		while (om <= len) {
			if ((instr[im - 1] - '0') == (outstr[om - 1] - '0')) { //注意会有同号的一节车厢 
				im++; 
				om++;
				vis[k++] = 1;
				vis[k++] = 0;			//遇到对应的值，入完就出，非对应顺序，有停留 
			} else if (!s.empty() && s.top() == (outstr[om - 1] - '0')) {
				s.pop(); 
				vis[k++] = 0;
				om++;
			} else if (im <= len) {
				s.push((instr[im - 1] - '0'));
				vis[k++] = 1; 
				im++;
			} else {
				flag = 0; 
				break;
			}
		}
		if (flag)
			cout << "Yes." << endl;
		else
			cout << "No." << endl;
			
		if (flag) {
			for (int i = 0; i < k; i++) {
				if (vis[i])
					cout << "in" << endl;
				else
					cout << "out" << endl;
			}
		}
		memset(instr, '\0', sizeof(instr));
		memset(outstr, '\0', sizeof(outstr)); 
		while (!s.empty()) {
			s.pop();
		}
		cout << "FINISH" << endl; 
	}
	return 0;
} 
