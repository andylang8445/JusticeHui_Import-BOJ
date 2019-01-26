#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
const db maxi = 1e18;
const db E = 1e-08;

int n; db t;
int pos[50050], speed[50050];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	db left = -maxi, right = maxi;

	cin >> n >> t;

	for(int i=0; i<n; i++) cin >> pos[i];
	for(int i=0; i<n; i++) cin >> speed[i];
	for(int i=0; i<n; i++){
		left = max((double)left, pos[i] - speed[i] * t);
		right = min((double)right, pos[i] + speed[i] * t);
	}
	if(left < right + E) cout << 1;
	else cout << 0;
}
