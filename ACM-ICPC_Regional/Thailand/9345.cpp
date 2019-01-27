#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
struct MinMaxSeg{
	vector<int> Max, Min;
	int size;

	MinMaxSeg(int s) : size(s) {
		Max.resize(4*s, 0), Min.resize(4*s, 0);
	}

	void init(int node, int start, int end){
		if(start == end){
			Min[node] = Max[node] = start; return;
		}

		int mid = (start+end) >> 1;
		init(node*2, start, mid), init(node*2+1, mid+1, end);

		Min[node] = min(Min[node*2], Min[node*2+1]);
		Max[node] = max(Max[node*2], Max[node*2+1]);
	}

	void init(){
		init(1, 0, size-1);
	}

	void update(int node, int start, int end, int idx, int val){
		if(idx < start || end < idx) return;
		if(start == end){
			Min[node] = Max[node] = val; return;
		}

		int mid = (start+end) >> 1;
		update(node*2, start, mid, idx, val), update(node*2+1, mid+1, end, idx, val);

		Min[node] = min(Min[node*2], Min[node*2+1]);
		Max[node] = max(Max[node*2], Max[node*2+1]);
	}

	void update(int val, int idx){
		update(1, 0, size-1, idx, val);
	}

	p get(int node, int start, int end, int left, int right){
		if(right < start || end < left) return {1e9+7, 0};
		if(left<=start && end<=right) return {Min[node], Max[node]};

		int mid = (start+end) >> 1;
		p i = get(node*2, start, mid, left, right);
		p j = get(node*2+1, mid+1, end, left, right);
		return {min(i.first, j.first), max(i.second, j.second)};
	}

	p get(int left, int right){
		return get(1, 0, size-1, left, right);
	}

};

void solve(){
    int n, m; cin >> n >> m;
    MinMaxSeg tree(n);
    tree.init();

    while(m--){
        int q, a, b; cin >> q >> a >> b;
        if(q){
            auto tmp = tree.get(a, b);
            if(tmp.first == a && tmp.second == b) cout << "YES\n";
            else cout << "NO\n";
        }else{
            auto i = tree.get(a, a);
            auto j = tree.get(b, b);
            tree.update(j.first, a);
            tree.update(i.first, b);
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
