#include <bits/stdc++.h>
using namespace std;

struct asdf{
	int s, e, x;
	bool operator < (asdf a){
		if(e != a.e) return e<a.e;
		return s<a.s;
	}
};

int n, c, m;
vector<asdf> v;

int main(){
	cin>>n>>c>>m;
	v.resize(m);
	for(int i=0; i<m; i++) cin >> v[i].s >> v[i].e >> v[i].x;
	sort(v.begin(), v.end());

	int ans = 0;
	vector<int> gogo(n+1);
	for(int i=0; i<m; i++){
		int maxi = 0;
		for(int j=v[i].s; j<v[i].e; j++) maxi = max(maxi, gogo[j]);
		int left = min(v[i].x, c-maxi);
		ans += left;
		for(int j=v[i].s; j<v[i].e; j++) gogo[j] += left;
	}
	cout << ans;
}
