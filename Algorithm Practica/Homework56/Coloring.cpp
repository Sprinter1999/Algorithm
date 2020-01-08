#include<iostream>
#include<math.h>
#include<fstream>
#include<cstdio>
using namespace std;
const int n=22;//vertex
const int bound=n+1;
int m=6; //color
int x[n+1];
bool a[n+1][n+1];
float path[n+1][n+1];

bool OK(int k)
{
	for(int j=1;j<k;j++)
	{
		if((a[k][j]==1)&&(x[j]==x[k]))
			return false;
	}
	return true;
}
void m_coloring(int n, int m, bool a[][bound], int x[])
{
	int i, k;
	for (i=1; i<=n; i++) //解向量x[]初始化
	    x[i]=0;
	k=1; //准备从第一个顶点开始
	while (k>=1) { //外层循环，控制为顶点1,2,..,k,..n着色
	    x[k]=x[k]+1; //为顶点k选择下一颜色
	    while ((x[k]<=m)&&(!OK(k))) //如果顶点k的当前着色x[k]不合适
	        x[k]=x[k]+1; //为顶点k选择下一颜色
	    if (x[k]<=m) 
	        { //前面步骤是否为顶点k找到了合适的着色；如果没找到，x[k]>m
		        if (k==n) break; //当前顶点是否是最后一个点？如果是，结束
		            else k=k+1; // 如果不是，回到外循环开始处，处理下一顶点k+1
	        }
	    else
	        { //没有为k找到合适着色，搜索失败
		         x[k]=0; //置空顶点k的颜色
		         k=k-1; //回溯到前一个顶点k-1，搜索k-1的其他子节点
	    }
} // 外循环结束
}

int main()
{
	ifstream in("station.txt",ios::in);
	int i=1;
	while(!in.eof())
	{
		in>>path[i][1]>>path[i][2]>>path[i][3]>>path[i][4]>>path[i][5]>>path[i][6]>>path[i][7]>>path[i][8]>>path[i][9]>>path[i][10]>>path[i][11]>>path[i][12]>>path[i][13]>>path[i][14]>>path[i][15]>>path[i][16]>>path[i][17]>>path[i][18]>>path[i][19]>>path[i][20]>>path[i][21]>>path[i][22];
		for(int ite=1;ite<=n;ite++)
		{
			if(fabs(path[i][ite]-99999)<1e-6)
				a[i][ite]=0;
			else
				a[i][ite]=1;
		}
		printf("i:%d 1:%lf 2:%lf\n",i,path[i][1],path[i][22]);
//		printf("%d %d\n",a[i][1],a[i][22]);
		i+=1;
	}
	m_coloring(n,m,a,x);
	for(int i=1;i<=n;i++)
	{
		cout<<"Vertex "<<i<<":Color index: "<<x[i]<<endl;
	}
}
