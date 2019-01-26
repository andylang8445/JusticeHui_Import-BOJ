#include <bits/stdc++.h>
using namespace std;

int flag, cnt;

int main(){
	int n; cin >> n;
	string str; cin >> str;
	for(auto i : str){
		if(i == 'W') cnt++;
		else{
			if(cnt == 1) flag = 2;
			else if(cnt == 0 && flag == 0) flag = 1;
			else if(cnt == 0 && flag == 1) flag = 0;
		}
	}
	if(cnt >= 2){
		if(flag == 0) cout << 5;
		else if(flag == 1) cout << 1;
		else cout << 6;
	}else cout << 0;
}
