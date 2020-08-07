#include <cstdio>

int Tree[1001]={-1};

int findRoot(int x)
{
	if(Tree[x]==-1) return x;
	else{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
	
}

int main()
{
	int m,n;
	printf("%d\n",Tree[1]);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		Tree[i]=-1;
	}
	
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int fa=findRoot(a);
		int fb=findRoot(b);
		if(fb!=fa)
		{
			Tree[fb]=fa;
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(Tree[i]==-1) ans++;
	}
	printf("%d\n",ans-1);
	return 0;
 } 
