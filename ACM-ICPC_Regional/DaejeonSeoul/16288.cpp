#include <bits/stdc++.h>
using namespace std;

stack<int> s[110];

int main(){
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];

	reverse(v.begin(), v.end());

	for(int i=0; i<100; i++) s[i].push(1010);
	for(int i=0; i<n; i++){
		int idx = 0;
		int j;
		for(j=0; j<k; j++){
			if(s[j].top() > v[i]) break;
		}
		if(j == k){
			cout << "NO"; return 0;
		}

		s[j].push(v[i]);
	}
	cout << "YES";
}
