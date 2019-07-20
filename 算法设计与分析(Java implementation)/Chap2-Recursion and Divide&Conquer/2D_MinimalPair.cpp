//2d10-2 二维最邻近点对问题
#include "stdafx.h"
#include<time.h>
#include<iostream> 
#include<cmath>
 
using namespace std;
const int M=50;
 
//用类PointX和PointY表示依x坐标和y坐标排好序的点
class PointX {
	public: 
		int operator<=(PointX a)const
		{ return (x<=a.x); }
		int ID; //点编号
		float x,y; //点坐标 
};
 
class PointY { 
	public: 
		int operator<=(PointY a)const
		{ return(y<=a.y); }
		int p; //同一点在数组x中的坐标 
		float x,y; //点坐标
};
 
float Random();
template <class Type>
float dis(const Type&u,const Type&v); 
 
bool Cpair2(PointX X[], int n,PointX& a,PointX& b, float& d);
void closest(PointX X[],PointY Y[],PointY Z[], int l, int r,PointX& a,PointX& b,float& d);
 
template <typename Type> 
void Copy(Type a[],Type b[], int left,int right);
 
template <class Type>
void Merge(Type c[],Type d[],int l,int m,int r);
 
template <class Type>
void MergeSort(Type a[],Type b[],int left,int right);
 
int main()
{ 
	srand((unsigned)time(NULL));
	int length;
 
	cout<<"请输入点对数：";
	cin>>length;
 
	PointX X[M];
	cout<<"随机生成的二维点对为："<<endl;
 
	for(int i=0;i<length;i++)
	{
		X[i].ID=i;
		X[i].x=Random();
		X[i].y=Random();
		cout<<"("<<X[i].x<<","<<X[i].y<<") ";
	}
 
	PointX a; 
	PointX b; 
	float d;
 
	Cpair2(X,length,a,b,d); 
 
	cout<<endl;
	cout<<"最邻近点对为：("<<a.x<<","<<a.y<<")和("<<b.x<<","<<b.y<<") "<<endl;
	cout<<"最邻近距离为： "<<d<<endl;
 
	return 0;
}
 
float Random()
{
	float result=rand()%10000;
	return result*0.01;
}
 
//平面上任意两点u和v之间的距离可计算如下
template <class Type>
inline float dis(const Type& u,const Type& v)
{
	float dx=u.x-v.x;
	float dy=u.y-v.y; 
	return sqrt(dx*dx+dy*dy); 
}
 
bool Cpair2(PointX X[], int n,PointX& a,PointX& b,float& d)
{
	if(n<2) return false;
 
	PointX* tmpX = new PointX[n];
	MergeSort(X,tmpX,0,n-1);
 
	PointY* Y=new PointY[n]; 
	for(int i=0;i<n;i++) //将数组X中的点复制到数组Y中
	{ 
		Y[i].p=i;
		Y[i].x=X[i].x;
		Y[i].y=X[i].y;
	} 
 
	PointY* tmpY = new PointY[n];
	MergeSort(Y,tmpY,0,n-1);
 
	PointY* Z=new PointY[n];
	closest(X,Y,Z,0,n-1,a,b,d); 
 
	delete []Y; 
	delete []Z;
	delete []tmpX;
	delete []tmpY;
	return true; 
}
void closest(PointX X[],PointY Y[],PointY Z[], int l, int r,PointX& a,PointX& b,float& d) 
{ 
	if(r-l==1) //两点的情形 
	{
		a=X[l];
		b=X[r];
		d=dis(X[l],X[r]);
		return; 
	} 
 
	if(r-l==2) //3点的情形 
	{
		float d1=dis(X[l],X[l+1]);
		float d2=dis(X[l+1],X[r]); 
		float d3=dis(X[l],X[r]); 
 
		if(d1<=d2 && d1<=d3) 
		{ 
			a=X[l];
			b=X[l+1];
			d=d1;
			return;
		} 
 
		if(d2<=d3)
		{ 
			a=X[l+1];
			b=X[r];
			d=d2;
		} 
		else { 
			a=X[l]; 
			b=X[r]; 
			d=d3; 
		}
		return; 
	} 
 
	//多于3点的情形，用分治法 
	int m=(l+r)/2; 
	int f=l,g=m+1; 
 
	//在算法预处理阶段，将数组X中的点依x坐标排序，将数组Y中的点依y坐标排序
	//算法分割阶段，将子数组X[l:r]均匀划分成两个不想交的子集，取m=(l+r)/2
	//X[l:m]和X[m+1:r]就是满足要求的分割。
	for(int i=l;i<=r;i++)
	{
		if(Y[i].p>m) Z[g++]=Y[i]; 
		else Z[f++]=Y[i];
	}
 
	closest(X,Z,Y,l,m,a,b,d);
	float dr;
 
	PointX ar,br;
	closest(X,Z,Y,m+1,r,ar,br,dr); 
 
	if(dr<d)
	{
		a=ar; 
		b=br; 
		d=dr; 
	} 
 
	Merge(Z,Y,l,m,r);//重构数组Y
 
	//d矩形条内的点置于Z中
	int k=l; 
	for(int i=l;i<=r;i++)
	{
		if(fabs(X[m].x-Y[i].x)<d)
		{ 
			Z[k++]=Y[i]; 
		}
	}
 
	//搜索Z[l:k-1]
	for(int i=l;i<k;i++) 
	{ 
		for(int j=i+1;j<k && Z[j].y-Z[i].y<d;j++) 
		{ 
			float dp=dis(Z[i],Z[j]);
			if(dp<d) 
			{ 
				d=dp; 
				a=X[Z[i].p];
				b=X[Z[j].p]; 
			}
		}
	} 
}
 
template <class Type>
void Merge(Type c[],Type d[],int l,int m,int r)
{
	int i = l,j = m + 1,k = l;
	while((i<=m)&&(j<=r))
	{
		if(c[i]<=c[j])
		{
			d[k++] = c[i++];
		}
		else
		{
			d[k++] = c[j++];
		}
	}
 
	if(i>m)
	{
		for(int q=j; q<=r; q++)
		{
			d[k++] = c[q];
		}	
	}
	else
	{
		for(int q=i; q<=m; q++)
		{
			d[k++] = c[q];
		}
	}
}
 
template <class Type>
void MergeSort(Type a[],Type b[],int left,int right)
{
	if(left<right)
	{
		int i = (left + right)/2;
		MergeSort(a,b,left,i);
		MergeSort(a,b,i+1,right);
		Merge(a,b,left,i,right);//合并到数组b
		Copy(a,b,left,right);//复制回数组a		
	}
}
 
template <typename Type> 
void Copy(Type a[],Type b[], int left,int right)
{
	for(int i=left;i<=right;i++) 
		a[i]=b[i]; 
}
