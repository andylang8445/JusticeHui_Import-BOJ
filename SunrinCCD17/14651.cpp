#include <stdio.h>

typedef long long ll;
int mod=1e9+9;

int main(){
	int n;
	scanf("%d", &n);
	ll dp[40000] = {0, 0, 2, };
	for(int i=3; i<=n; i++) dp[i] = dp[i-1] * 3 % mod;
	printf("%lld", dp[n] % mod);
}
