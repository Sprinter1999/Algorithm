#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1001
int Tree[N];

int findRoot(int x)
{
	if(Tree[x]==-1) return x;
	else
	{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
 } 
 
struct Edge
{
 	int a,b;
 	int cost;
 	bool operator < (const Edge &A) const
 	{
 		return cost < A.cost; //重载小于号实现根据边权从小到大排序	
	}
}edge[100000];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
	}
	
	sort(edge+1,edge+1+m);
	
	for(int i=1;i<=n;i++) Tree[i]=-1;
	
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		Edge Once=edge[i];
		int a=findRoot(Once.a);
		int b=findRoot(Once.b);
		if(a!=b)
		{
			Tree[a]=b;
			ans+=edge[i].cost;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
 

