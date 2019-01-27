#include <bits/stdc++.h>
using namespace std;

struct asdf{
	int t, l, m; //time, location, money
	bool operator < (asdf &rhs){
		return t < rhs.t;
	}
};

int dp[505050];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, u, s, d; cin >> n >> u >> d >> s;
	vector<asdf> v(n);
	for(int i=0; i<n; i++){
		cin >> v[i].t >> v[i].l >> v[i].m;
	}
	v.push_back({0, s, 0}); //시점
	v.push_back({500010, s, 0}); //종점

	sort(v.begin(), v.end());
	dp[0] = 0;
	for(int i=1; i<=n+1; i++){
		dp[i] = -1e9;
		for(int j=0; j<i; j++){
			int dist = abs(v[i].l - v[j].l);
			int baseCost = v[i].l <= v[j].l ? u : d;
			dp[i] = max(dp[i], dp[j] - dist*baseCost + v[i].m);
		}
	}

	cout << dp[n+1];
}
