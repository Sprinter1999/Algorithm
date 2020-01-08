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
	for (i=1; i<=n; i++) //������x[]��ʼ��
	    x[i]=0;
	k=1; //׼���ӵ�һ�����㿪ʼ
	while (k>=1) { //���ѭ��������Ϊ����1,2,..,k,..n��ɫ
	    x[k]=x[k]+1; //Ϊ����kѡ����һ��ɫ
	    while ((x[k]<=m)&&(!OK(k))) //�������k�ĵ�ǰ��ɫx[k]������
	        x[k]=x[k]+1; //Ϊ����kѡ����һ��ɫ
	    if (x[k]<=m) 
	        { //ǰ�沽���Ƿ�Ϊ����k�ҵ��˺��ʵ���ɫ�����û�ҵ���x[k]>m
		        if (k==n) break; //��ǰ�����Ƿ������һ���㣿����ǣ�����
		            else k=k+1; // ������ǣ��ص���ѭ����ʼ����������һ����k+1
	        }
	    else
	        { //û��Ϊk�ҵ�������ɫ������ʧ��
		         x[k]=0; //�ÿն���k����ɫ
		         k=k-1; //���ݵ�ǰһ������k-1������k-1�������ӽڵ�
	    }
} // ��ѭ������
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
