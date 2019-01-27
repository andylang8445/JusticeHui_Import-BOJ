#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

int dp[1010][1010][2];

int cost[1010];

int solve(int i, int j, int flag){
	int &ret = dp[i][j][flag];
	if(ret != -1) return ret;
	if(i >= j){
		if(!flag) return ret = cost[i];
		else return ret = 0;
	}
	if(!flag){ //gnu
		return ret = max(solve(i+1, j, !flag) + cost[i], solve(i, j-1, !flag) + cost[j]);
	}else{
		return ret = min(solve(i+1, j, !flag), solve(i, j-1, !flag));
	}
}

void f(){
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> cost[i];

	cout << solve(1, n, 0) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) f();
}
