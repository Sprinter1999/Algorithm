#include<stdio.h>
int matrix[1001][1001];

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&matrix[i][j]);
			
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
		{
			if(j==m) printf("%d\n",matrix[j][i]);
			else
				printf("%d ",matrix[j][i]);
		}
		
	return 0;
}
