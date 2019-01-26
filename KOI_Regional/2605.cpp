#include <bits/stdc++.h>
using namespace std;

typedef vector<int>::iterator iter;

int main(){
	int n; scanf("%d", &n);
	vector<int> v(n+1);
	for(int i=1; i<=n; i++) v[i] = i;
	for(int i=1; i<=n; i++){
		int t; scanf("%d", &t);
		iter it = find(v.begin(), v.end(), i);
		iter a = it;

		while(t--) a--;
		v.erase(it);
		v.insert(a, i);
	}

	for(int i=1; i<=n; i++) printf("%d ", v[i]);
}
