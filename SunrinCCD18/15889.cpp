#include <bits/stdc++.h>
using namespace std;

int n;

struct asdf{
	int pos, ran;
};

asdf arr[30001];
asdf ori[30001];
int chk[30001];

bool cmp(asdf a, asdf b){
	return a.pos < b.pos;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i].pos);
	if(n == 1){
		printf("권병장님, 중대장님이 찾으십니다");
		return 0;
	}
	for(int i=0; i<n-1; i++) scanf("%d", &arr[i].ran);
	arr[n-1].ran = 0;
	sort(arr, arr+n, cmp);


	int idx = 1;
	ori[0] = arr[0];
	for(int i=0; i<n; i++){
		if(ori[idx-1].pos != arr[i].pos) ori[idx++] = arr[i];
		else ori[idx-1].ran = max(ori[idx-1].ran, arr[i].ran);
	}

	chk[0] = 1;
	for(int i=0; i<idx; i++){
		for(int j=i+1; j<idx; j++){
			if(ori[j].pos-ori[i].pos <= ori[i].ran){
				chk[j] = 1;
			}else break;
		}
	}

	for(int i=0; i<idx; i++) if(!chk[i]){ printf("엄마 나 전역 늦어질 것 같아"); return 0;}
	printf("권병장님, 중대장님이 찾으십니다");
}
