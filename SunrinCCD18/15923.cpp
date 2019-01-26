#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
vector<p> arr;

int main(){
	int sum = 0;
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++){
		int x, y; scanf("%d %d", &x, &y);
		arr.push_back(make_pair(x, y));
	}

	int xx, yy;
	for(int i=0; i<n-1; i++){
		xx = arr[i+1].first - arr[i].first;
		yy = arr[i+1].second - arr[i].second;
		sum += (int)sqrt(xx*xx + yy*yy);
	}
	xx = arr[n-1].first - arr[0].first;
	yy = arr[n-1].second - arr[0].second;
	sum += (int)sqrt(xx*xx + yy*yy);
	printf("%d", sum);
}
