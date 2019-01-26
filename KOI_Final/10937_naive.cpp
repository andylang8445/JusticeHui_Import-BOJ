int chk[11][11];
int f(int i, int j){
  int ans = 0;
  if(i == n) return 0; //탐색 종료
  if(j == n) return f(i+1, 0); //다음 행

  if(!chk[i][j]){ //현재 위치 판매x
    chk[i][j] = 1;
    if(j+1 < n && !chk[i][j+1]){ //가로
      int now = board[i][j], nxt = board[i][j+1];
      chk[i][j+1] = 1;
      ans = max(ans, f(i, j+2) + cost[now][nxt]);
      chk[i][j+1] = 0;
    }
    if(i+1 < n && !chk[i+1][j]){ //세로
      int now = board[i][j], nxt = board[i+1][j];
      chk[i+1][j] = 1;
      ans = max(ans, f(i, j+1) + cost[now][nxt]);
      chk[i+1][j] = 0;
    }
    ans = max(ans, f(i, j+1)); //구매 x
  }
  else ans = max(ans, f(i, j+1)); //다음 위치
  return ans;
}
