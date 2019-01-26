#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p; //node depth

int a, b, n, m;
int arr[1010][1010];
int visit[1010];
int bfs(){
	queue<p> q;
	q.push(make_pair(a, 0));
	visit[a]=1;
	while(!q.empty()){
		p poped=q.front();
		q.pop();
		if(poped.first == b) return poped.second;
		for(int i=1; i<=n; i++){
			if(!visit[i] && arr[poped.first][i]){
				q.push(make_pair(i, poped.second+1));
				visit[i]=1;
			}
		}
	}
	return -1;
}

int main(){
	scanf("%d %d %d %d", &a, &b, &n, &m);
	for(int i=0; i<m; i++){
		int as, df;
		scanf("%d %d", &as, &df);
		arr[as][df]=1;
		arr[df][as]=1;
	}
	printf("%d", bfs());
}
