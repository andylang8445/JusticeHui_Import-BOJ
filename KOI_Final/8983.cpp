#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

int xpos[100100];
p a[100100];
int m, n, l, xidx, res;

int cal(int x, int y, int z) {
    return abs(x - z) + y;
}

int main(){
	scanf("%d %d %d", &m, &n, &l);
	for(int i=0; i<m; i++) scanf("%d", &xpos[i]);
	for(int i=0; i<n; i++) scanf("%d %d", &a[i].first, &a[i].second);
	sort(a, a+n);
	sort(xpos, xpos+m);

	for(int i=0; i<n; i++){
        while(xidx != m-1 && xpos[xidx + 1] < a[i].first){
            xidx++;
        }
        if(cal(a[i].first, a[i].second, xpos[xidx]) <= l){
            res++;
            continue;
        }
        if(xidx != m-1){
            if(cal(a[i].first, a[i].second, xpos[xidx + 1]) <= l){
                res++;
                continue;
            }
        }
    }

	printf("%d", res);
}
