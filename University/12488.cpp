#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll init(vll &arr, vll &tree, int node, int start, int end){
	if(start == end){
		return tree[node] = arr[start];
	}
	return tree[node] = init(arr, tree, node*2, start, (start+end)/2) ^ init(arr, tree, node*2+1, (start+end)/2+1, end);
}

void update_lazy(vll &tree, vll &lazy, int node, int start, int end){
	if(lazy[node] != 0){ //업데이트를 해야 할 경우
		tree[node] ^= lazy[node] * ((end-start+1)%2); //관할 구역의 개수만큼 더함
		if(start != end){ //리프 노드가 아니면
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
		}
		lazy[node] = 0; //업데이트 완료
	}
}

int update_range(vll &tree, vll &lazy, int node, int start, int end, int left, int right, ll diff){
	update_lazy(tree, lazy, node, start, end);
	if(left>end || right<start){ //범위 초과
		return tree[node];
	}
	if(left<=start && end<=right){ //범위 포함
		tree[node] ^= diff * ((end-start+1)%2);
		if(start!=end){
			lazy[node*2] ^= diff;
			lazy[node*2+1] ^= diff;
		}
		return tree[node];
	}
	return tree[node] = update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff) ^
    					update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
}

ll sum(vll &tree, vll &lazy, int node, int start, int end, int left, int right){
	update_lazy(tree, lazy, node, start, end);
	if(left>end || right<start) return 0;
	if(left<=start && end<=right) return tree[node];
	return sum(tree, lazy, node*2, start, (start+end)/2, left, right) ^ sum(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin>>n;
	vll arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int h = (int)ceil(log2(n))+1;
	int size = (1 << h);
	vll tree(size);
	vll lazy(size);
	init(arr, tree, 1, 0, n-1);

	cin>>m;

	for(int i=0; i<m; i++){
		int t; cin>>t;
		if(t == 1){
			int b, c; ll d; cin>>b>>c>>d;
			if(b>c)swap(b, c);
			update_range(tree, lazy, 1, 0, n-1, b, c, d);
		}
		if(t == 2){
			int b, c; cin>>b>>c;
			if(b>c)swap(b, c);
			cout << sum(tree, lazy, 1, 0, n-1, b, c) << "\n";
		}
	}
}
