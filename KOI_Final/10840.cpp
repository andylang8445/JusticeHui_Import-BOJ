#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
const int mod = 524287;
typedef pair<int, int> p; //hash, len

bool isPrime(int n){
	if(n < 2) return 0;
	for(int i=2; i*i<=n; i++) if(n%2 == 0) return 0;
	return 1;
}

void getPrime(){
	for(int i=2; i<=10000; i++){
		if(isPrime(i)) prime.push_back(i);
	}
}

vector<p> Hash[mod];


void solve(string &a, string &b){
	int x, y;
	for(int i=0; i<a.size(); i++){
		x = y = 1;
		for(int j=i; j<a.size(); j++){
			int now = a[j] - 'a';
			int len = j - i + 1;
			x = (x * prime[now]) % mod;
			y = (y * prime[now + 26]) % mod;
			Hash[x].push_back({y, len});
		}
	}

	int ans = 0;
	for(int i=0; i<b.size(); i++){
		x = y = 1;
		for(int j=i; j<b.size(); j++){
			int now = b[j] - 'a';
			int len = j - i + 1;
			x = (x * prime[now]) % mod;
			y = (y * prime[now + 26]) % mod;
            bool flag = 0;
            for(int i=0; i<Hash[x].size(); i++) if(Hash[x][i] == make_pair(y, len)) flag = 1;
			if(flag) ans = max(ans, len);
		}
	}
	cout << ans;
}

int main(){
	getPrime();
	string a, b;
	cin >> a >> b;
	solve(a, b);
}
