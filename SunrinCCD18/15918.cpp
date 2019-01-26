#include <bits/stdc++.h>
using namespace std;

int arr[100];
int chk[100];
int n, x, y;
int cnt;

void f(int t){
	if(t == 2*n){
		cnt++; return;
	}
	if(!arr[t]){
		for(int i=1; i<=n; i++){
			if(chk[i]) continue;
			if(t+i+1<=2*n && !arr[t+i+1]){
				arr[t] = arr[t+i+1] = i;
				chk[i] = 1;
				f(t+1);
				arr[t] = arr[t+i+1] = chk[i] = 0;
			}
		}
	}
  else f(t+1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x >> y;
	arr[x] = arr[y] = y-x-1;
	chk[y-x-1] = 1;
	f(1);
	cout << cnt;
}
