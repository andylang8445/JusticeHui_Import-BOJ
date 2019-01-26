int dp[11][11][1 << 12];
memset(dp, -1, sizeof(dp));

int f(int i, int j, int bit){
  int &ret = dp[i][j][bit];
  if(ret != -1) return ret; //이미 탐색 완료
  if(i == n) return ret = 0;
  if(j == n) return ret = f(i+1, 0, bit);

  if(!(bit & CUR)){ //현재 위치 포함 x
    if(j+1 < n && !(bit & RIGHT)){
      int now = board[i][j], nxt = board[i][j+1];
      int t1 = f(i, j+1, (bit<<2) % MOD) + cost[now][nxt];
      ret = max(ret, t1);
    }
    if(i+1 < n && !(bit&DOWN)){
      int now = board[i][j], nxt = board[i+1][j];
      int t2 = f(i, j+1, ((bit|DOWN)<<1) % MOD) + cost[now][nxt];
      ret = max(ret, t2);
    }
    int t3 = f(i, j+1, (bit<<1) % MOD);
    ret = max(ret, t3);
  }
  int t4 = f(i, j+1, (bit<<1) % MOD);
  ret = max(ret, t4);

  return ret;
}
