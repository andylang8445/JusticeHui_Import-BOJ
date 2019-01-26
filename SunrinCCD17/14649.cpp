#include <stdio.h>

struct P{
	int pos, dir;
};

double p;
int n, arr[110]={0};
P people[110];
int r, g, b;

int main(){
	scanf("%lf %d", &p, &n);
	for(int i=1; i<=n; i++){
		int a; char b;
		scanf("%d %c", &a, &b);
		P tmp;
		tmp.pos=a;
		tmp.dir = (b=='L' ? -1 : 1);
		people[i] = tmp;
	}

	for(int i=1; i<=n; i++){
		if(people[i].dir  == -1){
			for(int j=people[i].pos-1; j>=1; j--) arr[j]++;
		}

		if(people[i].dir == 1){
			for(int j=people[i].pos+1; j<=100; j++) arr[j]++;
		}
	}

	for(int i=1; i<=100; i++){
		if(arr[i]%3==0) b++;
		if(arr[i]%3==1) r++;
		if(arr[i]%3==2) g++;
	}

	printf("%.2f %.2f %.2f", p*b/(r+g+b), p*r/(r+g+b), p*g/(r+g+b));
}
