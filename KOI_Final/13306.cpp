#include <bits/stdc++.h>
using namespace std;

int parent[200020];
int level[200020];
int g[200020];
int n;

int query[400010][3];

void init(){
	for(int i=0; i<=200000; i++){
		parent[i] = i;
		level[i] = 1;
	}
}

int find(int u){
	if(u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v){
	u = find(u);
	v = find(v);

	if(u == v) return;
	if(level[u] > level[v]) swap(u, v);
	parent[u] = v;
	if(level[u] == level[v]) level[v]++;
}

int main(){
	ios_base::sync_with_stdio(0); //cin.tie(0);
	int n, q; cin >> n >> q;
	g[1] = 1;
	for(int i=2; i<=n; i++){
		int t; cin >> t;
		g[i] = t;
	}
	init();
	q += (n-1);
	for(int i=0; i<q; i++){
		int op; cin >> op;
		if(op) cin >> query[i][1] >> query[i][2];
		else{
			cin >> query[i][1]; query[i][2] = 0;
		}
	}
	stack<bool> s;
	for(int i=q-1; i>=0; i--){
		if(query[i][2]){
			if(find(query[i][1]) == find(query[i][2])) s.push(true);
			else s.push(false);
		}else{
			merge(query[i][1], g[query[i][1]]);
		}
	}


	while(!s.empty()){
		cout << (s.top()?"YES":"NO") << "\n"; s.pop();
	}

	return 0;
}
