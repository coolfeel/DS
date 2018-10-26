#include <iostream>
#include <cstring>
using namespace std;

int mod[100010];

int main() {
    float a;
    int n, m;
    cin >> n;
    while (n--) {
    	memset(mod, 0, sizeof(mod));
    	mod[1] = 1;
        cin >> m;
        if (m < 0) {
        	cout << '-';
        	m = -m;
		}      
        if (m == 1) {
        	cout << '1'<< endl;
        	continue;
		}
		cout << "0.";
        int d = 1;
		while (d) {
			d *= 10;
			cout << d / m;
			d %= m;
			if (mod[d])
				break;
			mod[d] = 1;
		}
		cout << endl; 
    }    
    return 0;
}
