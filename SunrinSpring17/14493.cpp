#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int ans = 0;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		int mod = ans % (a+b);
		if(mod < b) ans += b-mod;
		ans++;
	}
	cout << ans;
}
