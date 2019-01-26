#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, cnt=0;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		int tmp;
		scanf("%d", &tmp);
		if(tmp != i) cnt++;
	}
	printf("%d", cnt);

}
