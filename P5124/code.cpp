/*

* @Author: opzc35
* @Date:   2025-09-18 14:11:35
* @Last Modified by:   HP
* @Last Modified time: 2025-09-18 14:47:07

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

int T = 1;

int ans;
int n, m, q;
map<string, int> mp;
set<pair<int, int > > chongbian;
vector< pair<int, int> > g[1005];
int top;

int dis[1005][1005];
bool vis[1005];

void clear() {

}

void dijisktra(int s){
	memset(dis[s], 0x3f, sizeof dis[s]);
	dis[s][s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	memset(vis, 0, sizeof vis);
	q.push(make_pair(0, s));
	while(q.size()){
		int u = q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(auto [v,w]:g[u]){
			if(dis[s][v] > dis[s][u]+w){
				dis[s][v] = dis[s][u] + w;
				q.push(make_pair(dis[s][v],v));
			}
		}
	}
}

void work() {
	cin >> n >> m;
	for ( int i = 1 ; i <= m ; i ++) {
		string u, v ;
		int w;
		cin >> u >> v >> w;
		if (mp.count(u) == 0) {
			mp[u] = ++top;
		}
		if (mp.count(v) == 0) {
			mp[v] = ++top;
		}
		g[mp[u]].push_back(make_pair(mp[v], w));
	}
	for(int i = 1 ; i <= n ; i ++){
		dijisktra(i);
	}
	int q ;
	cin >> q;
	while( q --){
		string u, v;
		cin >> u >> v;
	    if(!mp.count(u) || !mp.count(v)){
	        cout << "Roger\n";
	        continue;
	    }
		if(dis[mp[u]][mp[v]] == 0x3f3f3f3f3f3f3f3f){
			cout<<"Roger\n";
		}else{
			cout<<dis[mp[u]][mp[v]]<<endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (T--) {
		clear();
		work();
		cout << "\n";
	}
}