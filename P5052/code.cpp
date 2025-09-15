/*

* @Author: opzc35
* @Date:   2025-09-15 15:34:37
* @Last Modified by:   HP
* @Last Modified time: 2025-09-15 16:43:57

*/

#include<bits/stdc++.h>
using namespace std;

// #define int long long

int T = 1;

int ans;

int n, k, m;
int a[115], b[115], t[115];

int dp[2005][115][115][2];// dp[l][r][t][beta]表示左到l右到r 用时t秒 并且现在在[0,1][左/右 端点]

bool vis[1005];
int startpoint = 0;

struct node {
	int a, b, t;
} tmp[115];

bool cmp(node a, node b) {
	return a.a < b.a;
}

void clear() {
}

void work() {
	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> t[i];
		vis[a[i]] = 1;
		tmp[i] = {a[i], b[i], t[i]};
	}
	if (!vis[k]) {
		tmp[++m] = {k, 0, 0};
	}
	sort(tmp + 1, tmp + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		a[i] = tmp[i].a;
		b[i] = tmp[i].b;
		t[i] = tmp[i].t;
		if (a[i] == k) {
			startpoint = i;
		}
		// cout << a[i] << " " << b[i] << " " << t[i] << endl;
	}
	// cout << endl;
	// cout << "startpoint: " << startpoint << " ";
	memset(dp, -0x3f, sizeof dp);
	dp[0][startpoint][startpoint][0] = dp[0][startpoint][startpoint][1] = b[startpoint];

	// cout << n << " " << k << " " << m <<endl;
	for (int  k = 1; k <= 2000; k++) {
		for (int i = 1; i <= m; i++) {
			for (int l = 1; i + l - 1 <= m; l++) {
				int r = i + l - 1;
				int t1 = k - (a[l + 1] - a[l]);
				int t2 = k - (a[r] - a[l]);
				int t3 = k - (a[r] - a[r - 1]);
				if (l < m && t1 >= 0) {
					dp[k][l][r][0] = max(dp[k][l][r][0], dp[t1][l + 1][r][0] + b[l] * (t[l] > k));
				}
				if (t2 >= 0) {
					dp[k][l][r][0] = max(dp[k][l][r][0], dp[t2][l + 1][r][1] + b[l] * (t[l] > k));
				}
				if (t2 >= 0) {
					dp[k][l][r][1] = max(dp[k][l][r][1], dp[t2][l][r - 1][0] + b[r] * (t[r] > k));
				}
				if (t3 >= 0) {
					dp[k][l][r][1] = max(dp[k][l][r][1], dp[t3][l][r - 1][1] + b[r] * (t[r] > k));
				}
				ans = max(ans, max(dp[k][l][r][1], dp[k][l][r][0]));
			}
		}
	}

	cout << ans ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// cin >> T;
	while (T--) {
		clear();
		work();
		cout << "\n";
	}
}