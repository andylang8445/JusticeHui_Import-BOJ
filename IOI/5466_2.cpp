#include <bits/stdc++.h>
using namespace std;

struct asdf{
	int t, l, m; //time, location, money
	bool operator < (asdf &rhs){
		return t < rhs.t;
	}
};

const int MAX_N = 1<<19;
struct SegTree {
	int seg[MAX_N*2-1];
	SegTree() {
		for(int i=0; i<MAX_N*2-1; i++) seg[i] = -1e9;
	}

	int query(int a, int b, int k=0, int l=0, int r=MAX_N){
    	if (b <= l || r <=a)return -1e9;
    	if (a<=l&&r<=b) return seg[k];
		return max(query(a,b,k*2+1,l,(l+r)/2), query(a,b,k*2+2,(l+r)/2,r));
	}

	void update(int k, int v) {
    	k += MAX_N-1;
    	seg[k] = v;
		while (k > 0) {
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
};

SegTree s1, s2;
vector<asdf> v;
int dp[505050];
int n, u, s, d;

void update(int i){
	s1.update(v[i].l, dp[i] + d * v[i].l);
	s2.update(v[i].l, dp[i] - u * v[i].l);
}

int get(int i){
	int t1 = s1.query(0, v[i].l) - d*v[i].l + v[i].m;
	int t2 = s2.query(v[i].l, 500000) + u*v[i].l + v[i].m;
	return max(t1, t2);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> u >> d >> s;
	v.resize(n);

	for(int i=0; i<n; i++){
		cin >> v[i].t >> v[i].l >> v[i].m;
	}
	v.push_back({0, s, 0}); //시점
	v.push_back({500010, s, 0}); //종점
	sort(v.begin(), v.end());

	dp[0] = 0;
	update(0);

	for(int i=1; i<=n+1; i++){
		dp[i] = get(i);
		update(i);
	}

	cout << dp[n+1];
}
