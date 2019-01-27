#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
string str;
vector<string> ans;
vector<p> bra;
stack<int> s;

int main(){
    cin >> str;
    int len = str.length();
    for(int i=0; i<len; i++){
        if(str[i] == '(') s.push(i);
        else if(str[i] == ')'){
            bra.push_back( make_pair(s.top(), i) );
            s.pop();
        }
    }
    int bin = 1<<(bra.size());
    for(int i=0; i<bin; i++){
        string now = str;
        for(int j=0; j<bra.size(); j++){
            if(i & (1<<j)){
                now[bra[j].first] = '.';
                now[bra[j].second] = '.';
            }
            ans.push_back(now);
        }
    }
    for(int i=0; i<ans.size(); i++){
        string tmpstr = "";
        for(int j=0; j<ans[i].length(); j++){
            if(ans[i][j] != '.') tmpstr += ans[i][j];
        }
        ans[i] = tmpstr;
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        int length = ans[i].length();
        bool flag = false;
        for(int k=0; k<i; k++){
            if(ans[i] == ans[k]) flag = true;
        }
        if(ans[i] == str) continue;
        if(flag) continue;
        for(int j=0; j<length; j++){
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
}
