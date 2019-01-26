#include <bits/stdc++.h>
using namespace std;

vector<int> g[600];
int arr[600][3];
vector<int> par(600, -1);
bool chk[600];

int match(int v){
	for(auto i : g[v]){
		if(chk[i]) continue;
		chk[i] = 1;
		if(par[i] == -1 || match(par[i])){
			par[i] = v;
			return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin>>n>>m>>k;

	for(int i=0; i<k; i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}

	//make graph
	for(int i=0; i<k; i++){
		for(int j=i+1; j<k; j++){
			if((arr[i][0]==arr[j][0] || arr[i][1]==arr[j][1]) && arr[i][2]!=arr[j][2]){
				if(arr[i][2]) g[j].push_back(i);
				else g[i].push_back(j);
			}
		}
	}

	int ans = 0;
	for(int i=0; i<k; i++){
		memset(chk, 0, sizeof(chk));
		if(match(i)) ans++;
	}
	cout << ans;
}
