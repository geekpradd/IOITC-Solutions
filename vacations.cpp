#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#define int long long
#define N 311111
#define A 1111111
#define gc getchar_unlocked
using namespace std;
struct query {
	int L;
	int R;
	int id;
};
int BLOCK_SIZE;
int answer = 0;

// Solved 22/7/2016. Mo's Algorithm + Fast IO

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
		answer++;
	}
	else {
		marker[element] = marker[element]+1;
	}
}
void remove(int element){
	if (marker[element]){
		marker[element] -= 1;
		if (marker[element] == 0){
			answer--;
		}
	}
}
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

signed main(){
	int n;
	scanint(n);
	for (int i=0; i<n; ++i){
		int t;
		scanint(t);
		dest[i] = t;
		marker[i+1] = 0;
	}
	BLOCK_SIZE = static_cast<int>(sqrt(n));
	
	int q;
	scanint(q);
	vector<query> queries(q);

	for (int i=0; i<q; ++i){
		int l, r;
		scanint(l);
		scanint(r);
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
		printf("%d\n", ans[i]);
	}
	return 0;
}