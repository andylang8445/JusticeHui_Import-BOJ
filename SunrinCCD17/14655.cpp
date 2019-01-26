#include <stdio.h>
#include <math.h>

int main(){
	int n, sum=0, tmp;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		sum+=abs(tmp);
	}
	printf("%d", 2*sum);
	return 0;
}
