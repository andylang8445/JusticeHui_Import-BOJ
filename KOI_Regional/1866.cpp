#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> arr(n+1), dp(n+1), sum(n+1);

	for(int i=1; i<=n; i++) cin >> arr[i];
	sort(arr.begin()+1, arr.end());
	for(int i=1; i<=n; i++) sum[i] = sum[i-1] + arr[i];

	int t, h; cin >> t >> h;

	for(int i=1; i<=n; i++){
		dp[i] = dp[i-1] + arr[i] * t;
		for(int j=i; j>=1; j--){
			int mid = (i+j) >> 1;

			int left = (arr[mid] * (mid-j+1) - (sum[mid] - sum[j-1])) * t;
			int right = ((sum[i] - sum[mid-1]) - (arr[mid] * (i-mid+1))) * t;

			int cost = left + right + h;
			dp[i] = min(dp[i], dp[j-1] + cost);
		}
	}

	cout << dp[n];
}
