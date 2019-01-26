#include <bits/stdc++.h>
#define x first
#define y second
#define st first
#define ed second
using namespace std;

typedef double db;
typedef pair<db, db> point;
typedef pair<point, point> line;

int ccw(point a, point b, point c){
	double value = a.x*b.y + b.x*c.y + c.x*a.y;
	value -= (a.y*b.x + b.y*c.x + c.y*a.x);
	if(value > 0.0) return 1;
	else if(value < 0.0) return -1;
	else return 0;
}

int crash(line _a, line _b){
	point a = _a.st, b = _a.ed, c = _b.st, d = _b.ed;
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if(!ab && !cd){
		if(a > b) swap(a, b);
		if(c > d) swap(c, d);
		return c<=b && a<=d;
	}
	return ab<=0.0 && cd<=0.0;
}

point arr[100010];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i=1; i<=n; i++) arr[i].x = i, cin >> arr[i].y;
	double k; cin >> k;

	for(int i=1; i<=n; i++){
		point t1 = {i-1, k*(i-1)};
		point t2 = {i, k*i};
		line x = {arr[i-1], arr[i]};
		line y = {t1, t2};

		if(crash(x, y) && (arr[i-1].x || arr[i] == t2)){
			cout << "T";
			return 0;
		}
	}
	cout << "F";
}
