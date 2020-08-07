#include <stdio.h>
#include <string.h>
#define N 100
char map[N*N];

void print()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%c ",map[i*N+j]);
		}
		printf("\n");
	}
}

int main()
{
	memset(map,'0',sizeof(map));
//	printf("sizeof map is %d\n",sizeof(map));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int ydis=d-b,xdis=c-a;
		for(int yiter=b;yiter<d;yiter++)
		{
			memset(map+N*yiter+a,'1',xdis);
		}
//		cout<<"THIS TURN:"<<endl;
//		print();
	}
	int counter=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(map[i*N+j]=='1')
				counter++;
		}
	}

	printf("%d\n",counter);
	return 0;
}
