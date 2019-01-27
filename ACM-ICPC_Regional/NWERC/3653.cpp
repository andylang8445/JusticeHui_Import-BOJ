#include <bits/stdc++.h>
using namespace std;

vector<int> tree, arr;

void update(int node, int start, int end, int idx, int diff){
	if(idx<start || idx>end) return;
	tree[node] += diff;
	if(start^end){
		update(node*2, start, (start+end)/2, idx, diff);
     update(node*2+1, (start+end)/2+1, end, idx, diff);
	}
}

int sum(int node, int start, int end, int left, int right){
	if(left>end || right<start){
    	return 0;
	}
	if(left<=start && end<=right){
    	return tree[node];
	}
	return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		arr = vector<int>(n+m+10);
		tree = vector<int>(4*(n+m+10));

		for(int i=m+1; i<=n+m; i++){
			update(1, 1, n+m, i, 1);
			arr[i-m] = i;
		}
		int idx = m;

		for(int i=0; i<m; i++){
			int v; cin >> v;
			cout << sum(1, 1, n+m, 1, arr[v]-1) << " ";
			update(1, 1, n+m, arr[v], -1);
			arr[v] = idx--;
			update(1, 1, n+m, arr[v], 1);
		}
		cout << "\n";
	}
}
