#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
ll arr[1010];

int main(){
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i=0; i<q; i++){
		int op;
		cin >> op;
		if(op == 1){
			int a, b;
			cin >> a >> b;
			int s1 = 0;
			for(int j=a; j<=b; j++) s1 += arr[j];
			cout << s1 << endl;
			swap(arr[a], arr[b]);
		}

		if(op == 2){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			int s1 = 0, s2 = 0;
			for(int j=a; j<=b; j++) s1 += arr[j];
			for(int j=c; j<=d; j++) s2 += arr[j];
			cout<<s1-s2<<endl;
		}
	}
}
