#include <bits/stdc++.h>
using namespace std;

bool isPal(string a, int l, int r){
	while(l<r){
		if(a[l] != a[r]) return 0;
		l++; r--;
	}
	return 1;
}

int main(){
	string a; cin >> a;
	if(!isPal(a, 0, a.size()-1)) cout << a.size();
	else if(!isPal(a, 0, a.size()-2)) cout << a.size()-1;
	else cout << -1;
}
