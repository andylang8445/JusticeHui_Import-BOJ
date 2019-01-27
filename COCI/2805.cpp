#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[1000010];
ll nu[1000010];
ll n, m, sum = 0;

ll conv(int value){
	int* it = upper_bound(arr, arr+n, value);
	int idx = it-arr;
	ll ret = sum - ( (ll)value*(n-idx) + nu[idx-1] );
	return ret;
}

int search(){
	int l = 1e9, r = 0;
	int mid;
	while(1){
		mid = (l+r)/2;
		ll c = conv(mid);
		if(l < r){
			return l;
		}
		if(c <= 0){
			l = mid-1;
			continue;
		}
		if(conv(mid+1)<m && c>m){
			return mid;
		}
		if(m > c){
			l = mid-1;
		}
		else r = mid+1;
	}
}
