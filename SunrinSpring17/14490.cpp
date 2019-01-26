#include <stdio.h>

int gcd(int a, int b){
    if(!b) return a;
    gcd(b, a%b);
}

int main(){
    int g;
    int a, b; scanf("%d:%d", &a, &b);
    g = gcd(a, b);
    printf("%d:%d", a/g, b/g);
}
