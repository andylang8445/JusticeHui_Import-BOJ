#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

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
vector<p> v[500005];

int n, u, d, s, t;

inline int get(int pos){
	return max(s1.query(0, pos)-d*pos, s2.query(pos, 500002)+u*pos);
}

inline void update(int pos, int dp){
	s1.update(pos, dp + d * pos);
	s2.update(pos, dp - u * pos);
}

void step(int i){
	int num = v[i].size();
	if(!num) return;
	vector<int> dpl, dpr;
	for(int j=0; j<num; j++){
		int tmp = get(v[i][j].first) + v[i][j].second;
		dpl.push_back(tmp); dpr.push_back(tmp);
	}
	for(int j=1; j<num; j++){
		dpl[j] = max(dpl[j], dpl[j-1] - d * (v[i][j].first - v[i][j-1].first) + v[i][j].second);
	}
	for(int j=num-2; j>=0; j--){
		dpr[j] = max(dpr[j], dpr[j+1] - u * (v[i][j+1].first - v[i][j].first) + v[i][j].second);
	}
	for(int j=0; j<num; j++){
		int big = max(dpl[j], dpr[j]);
		update(v[i][j].first, big);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> u >> d >> s;
	for(int i=0; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({b, c});
		t = max(t, a);
	}
	v[0].push_back({s, 0});
	v[++t].push_back({s, 0});

	for(int i=0; i<=t; i++){
		sort(v[i].begin(), v[i].end());
	}

	s1.update(s, d*s);
	s2.update(s, -u*s);

	for(int i=1; i<=t; i++){
		step(i);
	}

	cout << get(s);
}
