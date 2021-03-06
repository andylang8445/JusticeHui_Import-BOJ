#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int n, m;
int trash;
char arr[350][350];
char tmp[350][350];
char chk[350][350];
p a, b;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

bool bfs(){
	queue<p> q;
	q.push(a);
	while(!q.empty()){
		p poped = q.front(); q.pop();
		for(int k=0; k<4; k++){
			int i = poped.x+di[k], j = poped.y+dj[k];
			if(1<=i && i<=n && 1<=j && j<=m && !chk[i][j]){
				chk[i][j] = 1;
				if(arr[i][j] == '#') return true;
				if(arr[i][j] == '1'){
					tmp[i][j] = '0'; continue;
				}
				q.push({i, j});
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m; cin >> trash >> trash >> trash >> trash;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
		cin >> arr[i][j];
		if(arr[i][j] == '*') a = {i, j};
		if(arr[i][j] == '#') b = {i, j};
	}

	int ans = 0;
	while(1){
		ans++;
		memset(chk, 0, sizeof(chk));
		memcpy(tmp, arr, sizeof(tmp));
		if(bfs()) break;
		memcpy(arr, tmp, sizeof(tmp));
	}
	cout << ans;
}
