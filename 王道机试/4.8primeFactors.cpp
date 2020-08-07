#include <stdio.h>
#include <math.h>

int primes[10001];
int primeSize=0;
bool mark[10001];

void init()
{
	for(int i=2;i<10000;i++)
	{
		if(mark[i]==true) continue;
		else
		{
			primes[primeSize++]=i;
			for(int j=i*i;j<=10000;j+=i)
			{
				mark[j]=true;
			}
		}
	} 
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int temp=n;
		int nums=0;
		for(int i=0;i<primeSize;i++)
		{
			while(temp%primes[i]==0)
			{
				nums++;
				temp/=primes[i];
			}
		}
		printf("Factors are %d\n",nums);
	}
	return 0;
}
