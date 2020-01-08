#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<memory>
using namespace std; 
double a[22][22];//only use 1-22
bool s[22]; 
const int MAX=1000000;
double dist[22];

void Dij(int n,int v,double *dist,int *prev,double a[][22])
{
	bool s[30];
	for(int i=0;i<=n;i++)
	{
		dist[i]=a[v][i];
		s[i]=false;
		if(dist[i]==MAX)
		{
			prev[i]=0;
		}
		else
			prev[i]=v;
	}
	dist[v]=0;s[v]=true;
	for(int i=0;i<n;i++)
		{
			int temp=MAX;
			int u=v;
			for(int j=0;j<=n;j++)
			{
				if((!s[j])&&(dist[j]<temp))
				{
					u=j;
					temp=dist[j];
				}
			}
			s[u]=true;
			for(int j=0;j<=n;j++)
			{
				if((!s[j])&&(a[u][j]<MAX))
				{
					double newdist=dist[u]+a[u][j];
					if(newdist<dist[j])
					{
						dist[j]=newdist;
						prev[j]=u;
					}
				}
			}
		}
}
int main()
{
	cout<<"Our goal is for POINT20 to find SP towards POINT1"<<endl;
	ifstream in("Matrix22.txt",ios::in);
	int i=0;
	for(int in=0;in<=21;in++)
		dist[in]=MAX;
//	printf("dist[in]:%lf",dist[1]);
	while(!in.eof())
	{
		in>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5]>>a[i][6]>>a[i][7]>>a[i][8]>>a[i][9]>>a[i][10]>>a[i][11]>>a[i][12]>>a[i][13]>>a[i][14]>>a[i][15]>>a[i][16]>>a[i][17]>>a[i][18]>>a[i][19]>>a[i][20]>>a[i][21];
		printf("i:%d 1:%lf 2:%lf\n",i,a[i][1],a[i][22]);
		i+=1;
	}
	int prev[22];
	Dij(21,19,dist,prev,a);
	for(int in=0;in<=21;in++)
		cout<<dist[in]<<endl;
	cout<<"target: "<<dist[0];
	system("pause");
	
} 
