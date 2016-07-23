#include <bits/stdc++.h>
#define int long long
using namespace std;
// Solved 22/7/2016. Ad-Hoc
// I can't read it.
// Narcissm? Really?

signed main(){
	int m, n;
	cin >> m >> n;
	int r, c;
	cin >> r >> c;
	int k;
	cin >> k;
	int x[k];
	int y[k];
	for (int i=0; i<k; ++i){
		cin >> y[i] >> x[i];
	}
	int ans = 0;
	int cur_x_r = c-1;
	int cur_x_l = 0;
	int cur_y_r = r-1;
	int cur_y_l = 0;
	for (int i=0; i<k; ++i){
		int cor = x[i];
		int vor = y[i];
		if (cor <= cur_x_r && cor>=cur_x_l && vor <= cur_y_r && vor >= cur_y_l){
			continue;
		}
		else if (cor <= cur_x_r && cor>=cur_x_l){
			if (vor < cur_y_l){
				int dif = (cur_y_l - vor);
				ans += dif;
				cur_y_r -= dif;
				cur_y_l -= dif;
			}
			if (vor > cur_y_r){
				int dif = (vor - cur_y_r);
				ans += dif;
				cur_y_r += dif;
				cur_y_l += dif;
			}
		}
		else if (vor <= cur_y_r && vor>=cur_y_l){
			if (cor < cur_x_l){
				int dif = (cur_x_l - cor);
				ans += dif;
				cur_x_r -= dif;
				cur_x_l -= dif;
			}
			if (cor > cur_x_r){
				int dif = (cor - cur_x_r);
				ans += dif;
				cur_x_r += dif;
				cur_x_l += dif;
			}
		}
		else {
			if (vor < cur_y_l){
				int dif = (cur_y_l - vor);
				ans += dif;
				cur_y_r -= dif;
				cur_y_l -= dif;
			}
			if (vor > cur_y_r){
				int dif = (vor - cur_y_r);
				ans += dif;
				cur_y_r += dif;
				cur_y_l += dif;
			}
			if (cor < cur_x_l){
				int dif = (cur_x_l - cor);
				ans += dif;
				cur_x_r -= dif;
				cur_x_l -= dif;
			}
			if (cor > cur_x_r){
				int dif = (cor - cur_x_r);
				ans += dif;
				cur_x_r += dif;
				cur_x_l += dif;
			}
		}
	}
	cout << ans << endl;
}