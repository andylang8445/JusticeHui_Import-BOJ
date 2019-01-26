#include <bits/stdc++.h>
using namespace std;

int n;
int maxi = 0;
vector<int> arr;

vector<int>::iterator exist(int n){
	return find(arr.begin(), arr.end(), n);
}

int main(){
	cin>>n;
	for(int i=0; i<2*n; i++){
		int a;
		cin>>a;
		auto index=exist(a);
		if(index != arr.end()){
			arr.erase(index);
		}
		else{
			arr.push_back(a);
		}
		int len=arr.size();
		maxi=len>maxi?len:maxi;
	}
	printf("%d", maxi);
}
