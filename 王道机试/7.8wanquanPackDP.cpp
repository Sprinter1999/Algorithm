#include <stdio.h>
#define INF 0x3fffffff
int min(int a,int b){
	return a<b?a:b;
}
struct E{
	int w;
	int v;
}list[501];
int dp[10001];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int s,temp;
		scanf("%d%d",&temp,&s); //输入空存储罐重量和装满时的重量
		s-=temp; //钱币有多重
		int n;
		scanf("%d",&n); //有多少种钱
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&list[i].v,&list[i].w);	
		} 
		
		for(int i=0;i<=s;i++)
			dp[i]=INF;
			
		dp[0]=0;//重要 
		
		for(int i=1;i<=n;i++)
			for(int j=list[i].w;j<=s;j++)
			{
				dp[j] = min(dp[j],dp[j - list[i].w] + list[i].v);
			}
		if(dp[s]!=INF)
			printf("MIN is %d\n",dp[s]);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
