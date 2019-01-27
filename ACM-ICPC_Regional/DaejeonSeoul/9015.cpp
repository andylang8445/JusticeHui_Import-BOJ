#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

set<int> s[20010];
int a, b, n, ret;

inline bool can(int n){
	if(n<0 || n>=20010) return 0;
	return 1;
}

void solve(){
	int n; cin >> n;
	vector<p> v(n);
	for(int i=0; i<20010; i++) s[i].clear();
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		a += 10000; b += 10000;
		v[i] = {a, b};
		s[v[i].first].insert(v[i].second);
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			p p1 = v[i], p2 = v[j];
			int x1 = p1.first, y1 = p1.second;
			int x2 = p2.first, y2 = p2.second;

			int a = x1-x2, b = y1-y2;

			int x3 = x1+b, y3 = y1-a;
			int x4 = x2+b, y4 = y2-a;

			if(!can(x3) || !can(y3) || !can(x4) || !can(y4)) continue;

			if(s[x3].count(y3) && s[x4].count(y4)){
				ans = max(ans, a*a + b*b);
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		solve();
	}  
}
