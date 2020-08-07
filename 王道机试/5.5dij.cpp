#include <stdio.h>
#include <algorithm>
using namespace std;
int ans[101][101];
int dist[101];
int n,m;
const int INF=0x3fffffff;
bool vis[101]={false};

void Dij(int s)
{
	fill(dist,dist+n,INF);
	dist[s]=0;
	
	for(int i=1;i<=n;i++)
	{
		int u=-1,MIN=INF;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==false&&dist[j]<MIN)
			{
				u=j;MIN=dist[j];
			}
		}
		
		if(u==-1) return; //剩下的都不连通
		vis[u]=true;
		for(int v=1;v<=n;v++)
		{
			if(vis[v]==false&&ans[u][v]!=INF&&dist[u]+ans[u][v]<dist[v])
			{
				dist[v]=dist[u]+ans[u][v];	
			}	
		} 
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ans[i][j]=-1; //邻接矩阵初始化 
			}
			ans[i][i]=0; 
		}
		
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ans[a][b]=ans[b][a]=c;
		}
		
		Dij(1);
		
		
		printf("%d\n",ans[1][n]);
	}
	return 0;
}
