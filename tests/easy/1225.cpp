#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;

struct node {
	string name;
	int score, netball, ball;
}team[100000];

bool cmp(node a, node b) {
	if (a.score != b.score)
		return a.score > b.score;
	if (a.netball != b.netball)
		return a.netball > b.netball;
	if (a.ball != b.ball)
		return a.ball > b.ball;
	return a.name < b.name;
}

int main() {
	int n ,num, p, q;
	char c;
	string team1, vs, team2;
	while (cin >> n) {
		num = 0;
		for (int i = 1; i <= n; i++) {
			team[i].score = 0;
			team[i].netball = 0;
			team[i].ball = 0; 
		}
		
        for (int i = 1; i <= n * (n - 1); i++) {     
            cin >> team1 >> vs >> team2 >> p >> c >> q;
 
            if(m[team1] == 0) { //map一标记值 map[string]此值即为0 
                m[team1] = ++num;
                team[num].name = team1;
            }
            team[m[team1]].netball += p - q;
            team[m[team1]].ball += p;
 
            if(m[team2] == 0) {
                m[team2] = ++num;
                team[num].name = team2;
            }
            team[m[team2]].netball += q - p;
            team[m[team2]].ball += q;
 
            if(p > q)
                team[m[team1]].score += 3;
            else if(p == q) {
                team[m[team1]].score += 1;
                team[m[team2]].score += 1;
            } else if(p < q)
                team[m[team2]].score += 3;
        }
 
        sort(team + 1, team + n + 1, cmp);
        for(int i = 1; i <= n; i++)
            cout << team[i].name << " " << team[i].score << endl;
		cout << endl;			
	}
	return 0;
} 
