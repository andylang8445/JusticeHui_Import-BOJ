#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int arr[60010]; //초밥 상태
int cnt[3010]; //내가 먹은거!
int now; //현재 먹은 종류

void goRight(int a){
	if(!cnt[a]) now++; //안먹은거면 먹을거
	cnt[a]++; //먹은거 추가
}

void goLeft(int a){
	cnt[a]--; //먹은거 뱉음
	if(!cnt[a]) now--; //다 뱉었으면 삭제
}

int main(){
	int ans = 0;
	cin >> n >> d >> k >> c;
	for(int i=0; i<n; i++) scanf("%d", arr+i);
	for(int i=0; i<k-1; i++) arr[n+i] = arr[i];
	goRight(c);
	for(int i=0; i<k-1; i++){
		goRight(arr[i]);
	}
	for(int i=0; i<n; i++){
		goRight(arr[i+k-1]);
		ans = max(ans, now);
		goLeft(arr[i]);
	}
	printf("%d", ans);
}
