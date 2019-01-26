#include <bits/stdc++.h>
using namespace std;

int cost[4][4] = {
	{100, 70, 40, 0},
	{70, 50, 30, 0},
	{40, 30, 20, 0},
	{0, 0, 0, 0}
};
int dp[11][11][1 << 12];
int board[11][11];
int n;

int CUR, RIGHT, DOWN, MOD;

int f(int i, int j, int bit){
	int &ret = dp[i][j][bit];
	if(ret != -1) return ret;
	if(i == n) return ret = 0;
	if(j == n) return ret = f(i+1, 0, bit);

	if(ret == -1){
		if(!(bit & CUR)){ //현재 선택 안했다면
			if(j+1 < n && !(bit&RIGHT)){ //오른쪽
				int now = board[i][j];
				int nxt = board[i][j+1];
				int t1 = f(i, j+2, (bit<<2) % MOD) + cost[now][nxt];
				ret = max(ret, t1);
			}
			if(i+1 < n && !(bit&DOWN)){ //오른쪽
				int now = board[i][j];
				int nxt = board[i+1][j];
				int t2 = f(i, j+1, ((bit|DOWN)<<1) % MOD) + cost[now][nxt];
				ret = max(ret, t2);
			}
			int t3 = f(i, j+1, (bit<<1) % MOD);
			ret = max(ret, t3);
		}
		int t4 = f(i, j+1, (bit<<1) % MOD);
		ret = max(ret, t4);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	CUR = (1 << n), RIGHT = (1 << (n-1)), DOWN = 1, MOD = (1 << (n+1));

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			char t; cin >> t;
			board[i][j] = t=='F' ? 3 : t-'A';
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << f(0, 0, 0);
}
