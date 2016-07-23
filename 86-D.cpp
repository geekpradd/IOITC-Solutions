#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#define int long long
#define N 311111
#define A 1111111

using namespace std;
struct query {
	int L;
	int R;
	int id;
};
int BLOCK_SIZE;
int answer = 0;

int marker[A], dest[N], ans[N];
bool compare(query a, query b){
	int block_a = a.L/BLOCK_SIZE;
	int block_b = b.L/BLOCK_SIZE;
	if (block_b!=block_a){
		return block_a < block_b;
	}
	return a.R < b.R;
}
void add(int element){
	if (!marker[element]){
		marker[element] = 1;
		answer+= element;
	}
	else {
		answer -= marker[element]*marker[element]*element;
		marker[element] = marker[element]+1;
		answer += marker[element]*marker[element]*element;
	}
}
void remove(int element){
	if (marker[element]){
		answer -= marker[element]*marker[element]*element;
		marker[element] -= 1;
		answer += marker[element]*marker[element]*element;
	}
}

signed main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int q;
	cin >> q;
	for (int i=0; i<n; ++i){
		int t;
		cin >> t;
		dest[i] = t;
		marker[i+1] = 0;
	}
	BLOCK_SIZE = static_cast<int>(sqrt(n));
	
	
	vector<query> queries(q);

	for (int i=0; i<q; ++i){
		int l, r;
		cin >> l >> r;
		query qu = {l-1, r-1, i};
		queries[i] = qu;
	}
	sort(queries.begin(), queries.end(), compare);

	int cnt = 0;
	int curL = 0;
	int curR = -1;
	for (int i=0; i<q; i++){
		int L = queries[i].L;
		int R = queries[i].R;

		while (curR < R){
			// Process for index curR + 1
			curR++;
			add(dest[curR]);
		}
		while (curR > R){
			// Process for index curR
			remove(dest[curR]);
			curR--;
		}
		while (curL < L){
			// Process for index curL;
			remove(dest[curL]);
			curL++;
		}
		while (curL > L ){
			// Process for index curL-1;
			curL--;
			add(dest[curL]);
		}
		ans[queries[i].id] = answer;
	}
	for (int i=0; i<q; ++i){
		cout << ans[i] << endl;
	}
	return 0;
}