#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int ans = 0;

int main(){
    char str[100100];
    int len;
    scanf("%s", str);
    len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i] == '(') s.push(1);
        else{
            if(str[i-1] == '('){
                s.pop();
                ans += s.size();
                //s.pop();
            }
            else{
                s.pop();
                ans++;
            }
        }

    }
    printf("%d", ans);
}
