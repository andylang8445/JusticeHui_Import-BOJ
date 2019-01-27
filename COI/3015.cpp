#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

void solve(int n){
	vector<ll> v(n);
	stack<p> s;
	for(int i=0; i<n; i++) cin >> v[i];
	ll ans = 0;

	for (int i=0; i<n; i++){
		int nu = 1;
        while(!s.empty() && s.top().first <= v[i]){
        	if(s.top().first == v[i]){
        		ans += s.top().second;
        		nu = s.top().second+1;
        		s.pop();
			}else{
				ans += s.top().second;
				s.pop(); nu = 1;
			}
		}

		if(!s.empty()) ans++;
		s.push({v[i], nu});
    }
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	solve(n);
}
