#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[120];

int main(){
	int n;
	scanf("%d", &n);
	dp[0] = 1, dp[1] = 1, dp[2] = 1, dp[3] = 1;
	for(int i=4; i<=n; i++) dp[i] = dp[i-1] + dp[i-3];
	printf("%lld", dp[n]);
}
