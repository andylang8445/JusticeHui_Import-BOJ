#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int g, p; cin >> g >> p;
	set<int> s;
	for(int i=1; i<=g; i++) s.insert(i);
	for(int i=0; i<p; i++){
		int t; cin >> t;
		set<int>::iterator it = s.find(t);
		if(it != s.end()){
			s.erase(it);
			continue;
		}
		it = s.lower_bound(t);
		if(it == s.begin()){
			cout << i;
			return 0;
		}
		if(*(--it) > t){
			cout << i;
			return 0;
		}
		s.erase(it);
	}
	cout << p;
	return 0;
}
