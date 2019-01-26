#include <stdio.h>

int main(){
	int arr[110][110] = {0};
	int n, m; scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a, b; scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(arr[i][k] && arr[k][j]) arr[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i=2; i<=n; i++){
		if(arr[1][i]) cnt++;
	}
	printf("%d", cnt);
}
