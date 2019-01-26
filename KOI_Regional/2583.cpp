#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int map[100][100];
vector<int> ans;
int n, m, k, sum;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

void dfs(int i, int j){
	if(map[i][j]) return;
	if(i < 0 || i >= n || j < 0 || j >= m) return;
	map[i][j] = 2;
	sum++;
    for(int k=0; k<4; k++){
        dfs(i+di[k], j+dj[k]);
    }
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<k; i++){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int j=b; j<d; j++){
			for (int z=a; z<c; z++)
				map[j][z] = 1;
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!map[i][j]){
				sum = 0;
				dfs(i, j);
				ans.push_back(sum);
			}
		}
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for(int i : ans) printf("%d ", i);
}
