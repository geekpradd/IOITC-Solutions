#include <bits/stdc++.h>
using namespace std;
typedef struct {
	int from;
	int to;
	int weight;
} edge;

signed main(){
	//First DP on trees. Let's hope I don't screw it up
	int n;
	cin >> n;
	vector<edge> adj[n];
	for (int i=0; i<n-1; ++i){
		int from, to, weight;
		cin >> from >> to >> weight;
		edge link = {from-1, to-1, weight};
		adj[from-1].push_back(link);
	}
}