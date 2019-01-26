#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> arr, aidx, bidx, sum;
int n, m;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	arr.resize(n), aidx.resize(n);
	for(int i=0; i<n; i++){
		ll idx, value; cin >> idx >> value;
		arr[i] = value;
		aidx[i] = idx;
	}
	cin >> m;
	bidx.resize(m+10), sum.resize(m+10);
	for(int i=0; i<m; i++){
		ll idx, value; cin >> idx >> value;
		bidx[i] = idx;
		sum[i+1] = sum[i] + value;
	}
	for(int i=m; i<m+10; i++) bidx[i] = 1e18;
	int a, b; cin >> a >> b;

	ll ans = 0;
	for(int i=0; i<n; i++){
		int low = lower_bound(bidx.begin(), bidx.end(), aidx[i]+a) - bidx.begin();
		int high = lower_bound(bidx.begin(), bidx.end(), aidx[i]+b+1) - bidx.begin();
		ll go = arr[i] * (sum[high] - sum[low]);
		ans += go;
	}
	cout << ans;
} 
