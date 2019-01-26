#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> p;

int n, len, lis[100];
p a[100];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &a[i].fst, &a[i].snd);

	sort(a, a + n);

	for (int i=0; i < n; i++) {
		auto it = lower_bound(lis, lis + len, a[i].snd);
		if (!(*it)) len++;
		*it = a[i].snd;
	}

	printf("%d", n - len);

	return 0;
}
