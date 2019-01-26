#include <bits/stdc++.h>
using namespace std;

int n, m, all, maximum;
int arr[510][510];
int sumi[510], sumj[510];

int split(int n){
	int cnt = 0;
	while(n > 0){
		if(n%10 == 9) cnt++;
		n /= 10;
	}
	return cnt;
}

int main(){
	cin >> n >> m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			sumi[i] += split(arr[i][j]);
			sumj[j] += split(arr[i][j]);
			all += split(arr[i][j]);
		}
	}

	for(int i=0; i<n; i++){
		if(sumi[i] > maximum) maximum=sumi[i];
	}

	for(int j=0; j<m; j++){
		if(sumj[j]>maximum) maximum=sumj[j];
	}
	printf("%d", all-maximum);
}
