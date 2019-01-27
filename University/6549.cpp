#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

void solve(int n){
	vector<ll> v(n), left(n), right(n);
	vector<p> stk;
	ll ans;
	for(int i=0; i<n; i++) scanf("%lld", &v[i]);
	for(int i=0; i<n; i++){
		while(!stk.empty() && stk.back().first>=v[i]) stk.pop_back();
		left[i] = stk.empty()?-1:stk.back().second;
		stk.push_back({v[i], i});
	}
	stk.clear();
	for(int i=n-1; i>=0; i--){
		while(!stk.empty() && stk.back().first>=v[i]) stk.pop_back();
		right[i] = stk.empty()?n:stk.back().second;
		stk.push_back({v[i], i});
	}
	stk.clear();

	for(int i=0; i<n; i++){
		ll t = v[i] * (right[i] - left[i] - 1);
		ans = max(ans, t);
	}
	printf("%lld\n", ans);
}

int main(){
	int n;
	while(scanf("%d", &n) != 0){
		if(!n) return 0;
		solve(n);
	}
}
