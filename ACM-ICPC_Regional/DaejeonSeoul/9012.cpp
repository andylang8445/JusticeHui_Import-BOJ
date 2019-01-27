#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    while(n--){
        char str[100]; scanf("%s", str);
        stack<int> s;
        bool flag = false;
        int len = strlen(str);
        for(int i=0; i<len; i++){
            if(str[i] == '(') s.push(1);
            else{
                if(s.empty()){
                    printf("NO\n");
                    flag = true;
                    break;
                }else s.pop();
            }
        }
        if(s.empty() && !flag) printf("YES\n");
        else if(!flag) printf("NO\n");
    }
}
