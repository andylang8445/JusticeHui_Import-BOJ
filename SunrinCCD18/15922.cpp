#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

vector<p> arr;
int n;

int low(int num){
    int front = 0, rear = arr.size()-1;  
    if(arr.size() == 0 || arr[arr.size()-1].second < num) return n+1;
    while(rear > front){
        int mid = (front+rear)/2;
        if(arr[mid].second >= num) rear = mid;
        else front = mid+1;
    }
    return rear;
}

int main(){
	int ans = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		int idx = low(x);

		if(idx > n || idx == -1){
			arr.push_back(make_pair(x, y));
		}
		else{
			arr[idx].second = max(arr[idx].second, y);
		}

	}

	for(int i=0; i<arr.size(); i++){
		ans += (arr[i].second - arr[i].first);
	}
	printf("%d", ans);
}
