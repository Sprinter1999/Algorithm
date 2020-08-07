#include <stdio.h>

int map[31][31];
bool elimin[31][31]={0};

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
			
	for(int i=1;i<=n;i++)
	{
		int times=0;
		int pre=map[i][1];
		for(int j=1;j<=m;j++)
		{
			int temp=map[i][j];
			if(temp==pre)
			{
				times++;
				
				if(times==3)
				{
					elimin[i][j-2]=1;
					elimin[i][j-1]=1;
					elimin[i][j]=1;
				}
				if(times>3)
				{
					elimin[i][j]=1;
				}
			}
			else 
			{
				times=1;
				pre=temp;
			}
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		int times=0;
		int pre=map[1][i];
		for(int j=1;j<=n;j++)
		{
			int temp=map[j][i];
			if(temp==pre)
			{
				times++;
				
				if(times==3)
				{
					elimin[j-2][i]=1;
					elimin[j-1][i]=1;
					elimin[j][i]=1;
				}
				if(times>3)
				{
					elimin[j][i]=1;
				}
			}
			else 
			{
				times=1;
				pre=temp;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(elimin[i][j]==0){
				printf("%d",map[i][j]);
			}
			else
			{
				printf("0");
			}
			
			if(j!=m)
				printf(" ");
			else
				printf("\n");
		}
	
	return 0;
	
}
