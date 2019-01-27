#include <bits/stdc++.h>
using namespace std;

int dp[510][510], k[510][510];

void solve(int n){
	vector<int> v(n+1), s(n+1);
	for(int i=1; i<=n; i++) cin >> v[i], s[i] = s[i-1] + v[i];
	for(int m=1; m<n; m++){
		for(int i=1; m+i<=n; i++){
			int j = i+m; dp[i][j] = 1e9+7;
			for(int k=i; k<j; k++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + s[j] - s[i-1]);
			}
		}
	}
	cout << dp[1][n] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		solve(n);
	}
}
