#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	n/=10;
	int count=0;
	while(n>=5)
	{
		if(n/5)
		{
			count+=7;
			n-=5;
		}
	}
	if(n>=3)
	{
		count+=4;
		n-=3;
	}
	printf("%d\n",count+n);
	return 0;
 } 
