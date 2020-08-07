#include <stdio.h>
#include <algorithm>
using namespace std;

struct E{
	int x1,x2;
	int y1,y2;
	int initNum; 
}list[12]; 

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		list[i].x1=a;
		list[i].y1=b;
		list[i].x2=c;
		list[i].y2=d;
		list[i].initNum=i;
	}
	for(int i=1;i<=m;i++)
	{
		int touchX,touchY;
		scanf("%d%d",&touchX,&touchY);
		int ans=-1;
		for(int layer=n;layer>=1;layer--)
		{
			if(list[layer].x1<=touchX&&touchX<=list[layer].x2)
			{
				if(list[layer].y1<=touchY&&touchY<=list[layer].y2)
				{
					ans=layer;
					break;
				}
			}
		}
//		printf("ans is %d\n",ans);
		
		if(ans!=-1)
		{
			printf("%d\n",list[ans].initNum);
		}
		else
		{
			printf("IGNORED\n");
		}
		
		if(ans!=-1)
		{
			list[n+1]=list[ans];
			for(int i=ans;i<=n;i++)
			{
				list[i]=list[i+1];
			}
		}
		

	}
}
