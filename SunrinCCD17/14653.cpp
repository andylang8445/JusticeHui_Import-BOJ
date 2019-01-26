#include <bits/stdc++.h>
using namespace std;

int n, k, q;
int num[10001], who[10001];
int chk[26];

int main(){
	cin >> n >> k >> q;
	for(int i=1; i<=k; i++){
		int a;
		char b;
		cin >> a >> b;
		num[i] = a; who[i] = b;
	}

	if(num[q]==0){
		printf("-1");
		return 0;
	}

	for(int i=1; i<=k; i++){
		if(num[q] <= num[i]) chk[who[i]-'A']=1;
	}

	chk[0] = 1;

	for(int i=0; i<n; i++){
		if(!chk[i]) printf("%c ", i+'A');
	}
}
