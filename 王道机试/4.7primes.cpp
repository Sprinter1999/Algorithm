#include<stdio.h>
int prime[10001];
int primeSize;
bool mark[10001];

void init() {
	for(int i=2; i<=10000; i++) {
		if(mark[i]==true) continue;
		prime[primeSize++]=i;

		for(int j=i*i; j<=10000; j+=i) {
			mark[j]=true;
		}
	}
}

int main() {
	init();
	int n,count=0;
	while(scanf("%d",&n)!=EOF) {
		count=0;
		for(int i=0; i<primeSize; i++) {
			if(prime[i]%10==1&&prime[i]<=n) {
				count++;
				printf("%d\n",prime[i]);
			}
		}
		printf("Sum num of primes is %d\n",count);
	}
	return 0;
}

