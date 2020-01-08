#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
#define M_PI 3.14159265358979323846
const double Earth_R=6378.137;
ofstream out("最优三角剖分结果.txt");

struct Node
{
	int ENodeID,seq;
	double LongiTude,LatiTude;
	double radLat,radLon;
	Node(){
	}
	Node(int ID,double Long,double Lati,int ord):ENodeID(ID),LongiTude(Long),LatiTude(Lati),seq(ord)
	{
		radLat=LatiTude*M_PI/180.0;
		radLon=LongiTude*M_PI/180.0;
	}
}node[50];
double dist(int a,int b)
{
	struct Node p1=node[a],p2=node[b];
 	return Earth_R*acos(cos(p1.radLat)*cos(p2.radLat)*cos(p1.radLon-p2.radLon)+sin(p1.radLat)*sin(p2.radLat));
}

double dp[50][50],s[50][50],cunt;
double Weight(int a,int b,int c)
{
	return dist(a,b)+dist(a,c)+dist(b,c);
}

//double solve(int n)
//{
//	for(int r=2;r<=n;r++)
//	{
//		printf("called");
//		for(int i=1;i<=n-r+1;i++)
//		{
//			//Solve sub-problem(i,j)
//			int j=i+r-1;
//			dp[i][j]=dp[i+1][j]+Weight(i-1,i,j);
//			s[i][j]=i;
//			for(int k=i+1;k<j;k++)
//			{
//				double temp=dp[i][k]+dp[k+1][j]+Weight(i-1,k,j);
//				printf("temp:%d,i:%d,j:%d,k:%d",temp,i,j,k);
//				if(temp<dp[i][j])
//				{
//					dp[i][j]=temp;
//					s[i][j]=k;
//				}
//			}
//		}
//		printf("%d\n",dp[1][n]);
//		return dp[1][n];
//	}
//}

double solve(int n)
{
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int r=2;r<=n;r++)
	{
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			dp[i][j]=dp[i+1][j]+Weight(i-1,i,j);
			s[i][j]=i;
			for(int k=i+1;k<i+r-1;k++)
			{
				double u=dp[i][k]+dp[k+1][j]+Weight(i-1,k,j);
				if(u<dp[i][j])
				{
					dp[i][j]=u;
					s[i][j]=k;
				}
			}
		}
	}
	return dp[1][n];
}


void Recall(int h,int n)
{
	if(n==h) return;
	cout<<h-1<<" "<<s[h][n]<<" "<<n<<endl;
	out<<"点"<<h-1<<", "<<s[h][n]<<", "<<n<<endl;
	Recall(h,s[h][n]); 
	Recall(s[h][n]+1,n);
}


//int main()
//{
//	ifstream in("附件3-2.29个基站凸多边形数据.txt",ios::in);
//	int COUNT,ID,i,j;
//	double Long,Lati,ans,sum=0.0;
//	while(!in.eof())
//	{
//		in>>ID>>Long>>Lati>>i;
//		node[i]=Node(ID,Long,Lati,i);
////		memset(dp[i],0,sizeof(dp[i]));
//		printf("%d %f %f %d\n",ID,Long,Lati,i);
//	}
//	COUNT=i;
//	ans=solve(COUNT);
//	out<<"最优三角形的剖分结果为"<<endl; 
////	printf("calledB");
//	Recall(1,COUNT); 
//	
//	
//	printf("%.6f千米",ans); 
//	out<<"最小边长弦长总和为"<<ans<<"千米"<<endl; 
//	out.close(); 
//	in.close(); 
//	return 0;
//}
