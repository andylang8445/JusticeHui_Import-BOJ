#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
set<int> s[100010];
p a, b;
typedef pair<p, int> pi;

inline vector<p> can(p now){
	vector<p> ret;

	//fill
	ret.push_back({a.first, now.second});
	ret.push_back({now.first, a.second});

	//empty
	ret.push_back({0, now.second});
	ret.push_back({now.first, 0});

	//move
	int tmp = a.second-now.second;
	tmp = min(tmp, now.first);
	ret.push_back({now.first-tmp, now.second+tmp});

	tmp = a.first-now.first;
	tmp = min(tmp, now.second);
	ret.push_back({now.first+tmp, now.second-tmp});

	return ret;
}


int bfs(){
	queue<pi> q;
	q.push({ {0, 0}, 0 });
	s[0].insert(0);
	while(!q.empty()){
		pi pp = q.front(); q.pop();
		int i = pp.first.first, j = pp.first.second;
		int level = pp.second;
		if(b.first==i && b.second==j){
			return level;
		}
		vector<p> arr = can(pp.first);
		for(auto nxt : arr){
			int ii = nxt.first, jj = nxt.second;
			if(s[ii].count(jj)) continue;
			s[ii].insert(jj);
			q.push({nxt, level+1});
		}

	}
	return -1;
}

int main(){
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cout << bfs();
}
