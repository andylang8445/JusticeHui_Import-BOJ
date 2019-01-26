#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
typedef pair<pair<int, int>, int> pi; //< <깊이, -1*거리>, 현재 노드>

vector<p> gph[50010]; //인접리스트 <노드, 거리>
int n, t;

pi dfs(int now, int par, int dph){ //(현재, 이전 노드, 깊이)
	pi ret = make_pair(make_pair(dph, 0), now);
	for(int i=0; i<gph[now].size(); i++){
		int next = gph[now][i].first; //다음 노드
		int dist = gph[now][i].second; //next까지의 거리
		if(next == par) continue; //이전 노드와 다음 노드가 같으면 skip
		pi tmp = dfs(next, now, dph+1);
		tmp.first.second -= dist;
		ret = max(ret, tmp);
	}
	return ret;
}

int main(){
	cin >> n >> t;
	for(int i=0; i<n-1; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		gph[a].push_back({b, c});
		gph[b].push_back({a, c});
	}

	int root = dfs(1, 0, 0).second; //루트에서 가장 멀리 떨어진 노드
	int ans = -dfs(root, 0, 0).first.second; //정답
	printf("%d", (ans+t-1)/t);

}
