#include <iostream>
using namespace std;

int main() {
	double v, d;
	while (cin >> v >> d) {
		int time = 0;
		for (int i = 1;  ; i++) {
			if (v - (d * i) >= 0.0000001) {
				v -= d * i;
				if (v)
					time += i + 1;
				else {
					time += i;
					break;	
				}						
			} else {
				while (v - d >= 0.0000001) {
					v -= d;
					time++;
				}
				if (v) {
					time++;
					break;
				}				
				else
					break;
			}
		}
		cout << time << endl;
	}	
	return 0;
} 
