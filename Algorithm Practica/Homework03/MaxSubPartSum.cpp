#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN=500;
int MaxSum(int n,int *a,int &l,int &r)
{
	int	sum=0,b=0;
	int	pos=1;
	for(int i=0;i<=n;i++)
	{
		if(b>0)
		{
			b+=a[i];
		}
		else
		{
			b=a[i];
			pos=i;
		}
		if(b>sum)
		{
			sum=b;
			l=pos;
			r=i;
		}
	}
	return sum;
}

//int main(void)
//{
//	freopen("����2.����Ӷκ���������-����1.txt","r",stdin);
//	freopen("maxsubsum1.txt","w",stdout);
//	int n=0;
//	int a[MAXN];
//	while(scanf("%d",&a[n])!=EOF)
//	{
//		n++;
//	}
//	n--;
//	int left=0,right=0;
//	printf("����ֶκ�Ϊ:%d\n",MaxSum(n,a,left,right));
//	printf("����ֶ�λ�ڵ�%d��Ԫ�ص���%d��Ԫ��\n",left,right);
//	return 0;
//}
