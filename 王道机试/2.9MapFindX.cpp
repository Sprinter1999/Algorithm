#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	map<int,int> m;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		m[temp]=i;
	}
	int x;
	scanf("%d",&x);
	if(m.find(x)!=m.end())
	{
		printf("%d\n",m[x]);
	}
	else{
		printf("-1\n");
	}
	return 0;
}
