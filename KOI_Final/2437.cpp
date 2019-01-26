#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n+1);
    vector<int> s(n+1);
    for(int i=1; i<=n; i++) cin >> v[i];
    sort(v.begin()+1, v.end());
    if(v[1] > 1){
        cout << 1;
        return 0;
    }
    for(int i=1; i<=n; i++){
        s[i] = v[i] + s[i-1];
        if(s[i-1]+1 < v[i]){
            cout << s[i-1]+1;
            return 0;
        }
    }
    cout << s[n]+1;
}
