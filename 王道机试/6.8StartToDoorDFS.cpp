#include <stdio.h>
char maze[8][8];
int n,m,t;
bool success=false;
int go[][2]= {1,0,-1,0,0,1,0,-1};

void DFS(int x,int y,int time) {
	for(int i=0; i<4; i++) {

		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(maze[nx][ny]=='X') continue;
		if(maze[nx][ny]=='D') {
			if(time+1==t) {
				success=true;
				return;
			} else continue; //经过的点不能再经过
		}
		maze[nx][ny]='X'; //不会重复经过
		DFS(nx,ny,time+1);
		maze[nx][ny]='.';
		if(success) return; //已经成功则不必返回
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&t);
//	if(n==0&&m==0&&t==0)
	for(int i=1;i<=n;i++)
	{
		scanf("%s",maze[i]+1);
	}
	success=false;
	int sx,sy;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(maze[i][j]=='D')
			{
				sx=i;sy=j;
			}
		}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(maze[i][j]=='S'&&(i+j)%2==((sx+sy)%2+t%2)%2)
			{
				maze[i][j]=='X';
				DFS(i,j,0);
			}
		}
	
	puts(success==true?"YES":"NO");
	return 0;
}
