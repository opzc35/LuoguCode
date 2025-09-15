/*

* @Author: opzc35
* @Date:   2025-09-15 16:50:45
* @Last Modified by:   HP
* @Last Modified time: 2025-09-15 17:13:17

*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

int T = 1;

int ans;

void clear() {

}

map<string,int> mp;
int dp[2005][2005];
int c[2005][2005];
string s;
int n,k;

void work() {
	c[0][0] = 1;
	for(int i=1;i<=2000;i++){
		c[i][0] = c[i][i]=1;
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++){
		cin>>s;
		sort(s.begin(),s.end());
		mp[s] ++;
	}
	dp[0][0]=1;
	int tmp = 1;
	for(auto it:mp){
		for(int j = 0 ; j <= k ;j ++){
			for(int i = 0; i <= (it.second) ; i++){
				if((i*(i-1))/2>j){
					break;
				}
				dp[tmp][j] = (dp[tmp][j]+(dp[tmp-1][j-i*(i-1)/2] * c[it.second][i])%mod)%mod;
			}
		}

		tmp ++;
	}
	ans = dp[tmp-1][k];
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