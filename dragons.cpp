#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

typedef struct {
	long long x;
	long long y;
} node;

bool compare(node a, node b) { return a.x < b.x;}

long long DP[400][400];
long long rows, columns, K, D; 
node DS[400];

// Partial Solved. Something's wrong below though

int main(){
	cin >> ro
signed main(){
	int r, c, k, d;
	cin >> r >> c >> k >> d;
	vector<pd> dragons(d+1);

	for (int i=1; i<=d; ++i){
		pd current;
		int x, y;
		cin >> x >> y;
		current = make_pair(x, y);
		dragons[i] = current;
	}

	sort(dragons.begin(), dragons.end());
	vector< vector<int> > dp(d+1, vector<int>(d+1, INT_MIN));
	
	for (int id=d; id>0; --id){
		pd dragon = dragons[id];
		dp[id][1] = 0;
		for (int next=1; next<=d-id; ++next){
			int dif_dist = INT_MAX;
			for (int dr=id+1; dr<=d; ++dr){
				pd cur = dragons[dr];
				int del = abs(cur.first - dragon.first) + abs(cur.second - dragon.second);
				int tot = del + dp[dr][next];
				if (tot<dif_dist){
					dif_dist = tot;
				}
			}
			dp[id][1+next] = dif_dist;
		}
	}
	int ans = INT_MAX;
	for (int i=1; i<=d; ++i){
		pd cur = dragons[i];
		if (dp[i][k]==INT_MIN){
			break;
		}
		int current = cur.first + cur.second + dp[i][k];
		if (current <= ans){
			ans = current;
		}
	}
	cout << ans << endl;ws >> columns >> K >> D;
	
signed main(){
	int r, c, k, d;
	cin >> r >> c >> k >> d;
	vector<pd> dragons(d+1);

	for (int i=1; i<=d; ++i){
		pd current;
		int x, y;
		cin >> x >> y;
		current = make_pair(x, y);
		dragons[i] = current;
	}

	sort(dragons.begin(), dragons.end());
	vector< vector<int> > dp(d+1, vector<int>(d+1, INT_MIN));
	
	for (int id=d; id>0; --id){
		pd dragon = dragons[id];
		dp[id][1] = 0;
		for (int next=1; next<=d-id; ++next){
			int dif_dist = INT_MAX;
			for (int dr=id+1; dr<=d; ++dr){
				pd cur = dragons[dr];
				int del = abs(cur.first - dragon.first) + abs(cur.second - dragon.second);
				int tot = del + dp[dr][next];
				if (tot<dif_dist){
					dif_dist = tot;
				}
			}
			dp[id][1+next] = dif_dist;
		}
	}
	int ans = INT_MAX;
	for (int i=1; i<=d; ++i){
		pd cur = dragons[i];
		if (dp[i][k]==INT_MIN){
			break;
		}
		int current = cur.first + cur.second + dp[i][k];
		if (current <= ans){
			ans = current;
		}
	}
	cout << ans << endl;
	for (int i=1; i<=D; ++i){
		cin >> DS[i].x >> DS[i].y;
	}

}