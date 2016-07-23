#include <bits/stdc++.h>
#include <utility>
#define int long long
#define pi pair<int, int>
#include <cmath>
using namespace std;

// 80 marks. 
// Partial Solved: 23/7/2016. Used Sequence Formulas
// Mysteries... People
// One before another. I wonder why.
// I guess human beings can't be understood right?

// When you'll read this future martian, just go back into the past allright?
// Those years, those things, those people. I cannot understand it.
// Narcissm. Huh. Craziness. Huh. Lies. Maybe.

// The code below is great isn't it? 23/7/2016: Watched a movie called True story. Funny since it reminded me of a person whose trust I lost.
// Because I gave someone more importance than him/her

// The mind is astounding, isn't it? So many details.. So many processes.
// BUT you always knew this didn't you? Nick. ___ . 
// 2015: Year of the crazy

pi q1(int t){
	double val = sqrt(1+t);
	double upper = (val-1)/2;
	int temp = static_cast<int>(upper);
	int value;

	if (temp == upper){
		value = temp;
		return make_pair(value, -1*value);
	}
	else {
		value = static_cast<int>(upper+1);
	}

	int bottom_right = 4*value*(value+1);
	int bottom_left = bottom_right - 2*value;
	int top_left = bottom_left - 2*value;
	int top_right = top_left - 2*value;
	int prev = top_right - 2*value;

	if (t > prev && t <= top_right){
		int x = value;
		int y_dif = top_right - t;
		int y = value - y_dif;
		return make_pair(x, y);
	}
	else if (t > top_right && t <= top_left){
			int y = value;
			int x_dif = t - top_right;
			int x = value - x_dif;
			return make_pair(x, y);
	}
	else if (t > top_left && t <= bottom_left) {
		int x = -1*value;
		int y_dif = t - top_left;
		int y = value - y_dif;
		return make_pair(x, y);
	}
	else {
		int y = -1*value;
		int x_dif = bottom_right - t;
		int x = value - x_dif;
		return make_pair(x, y);
	}
}


int q2(int x, int y){
	if (x == y && x == 0){
		return 0;
	}
	if (x>0){
		if (y>=-x && y<=x){
			// coord is on right side of square
			int b_right = (x*(x+1))*4;
			int del = 8*x - 1;
			int coorddif = x+y-1;
			int ans = b_right-del+coorddif;
			return ans;
		}
	}
	else if (x<0) {
		if (y>=x && y<=-1*x){
			int b_left = (-1*x*(1-x))*4  + 2*x;
			int coordif = y-x;
			int ans = b_left - coordif;
			return ans;
		}
	}
	if (y > 0){
		if (x<=y && x>=-1*y){
			int b_right = (y*(y+1))*4;
			int del = 8*y - 1;
			int d = 2*y - 1;
			int t_right = b_right - del + d;
			int v = y - x;
			int ans = t_right + v;
			return ans;
		}
	}
	if (y < 0){
		if (x<=-1*y && x>=y){
			int c_x = -1*y; 
			int b_right = (c_x*(c_x+1))*4;
			int dif = c_x - x;
			int ans = b_right - dif;
			return ans;
		}
	}
}
signed main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int q;
	cin >> q;
	while (q--){
		int code;
		cin >> code;
		if (code){
			int x, y;
			cin >> x >> y;
			cout << q2(x, y) << endl;
		}
		else {
			int t;
			cin >> t;
			pi ans = q1(t);
			cout << ans.first << " " << ans.second <<  endl;
		}
	}
	return 0;
}