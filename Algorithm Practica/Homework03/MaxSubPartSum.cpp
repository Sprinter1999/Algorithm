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
//	freopen("附件2.最大子段和输入数据-序列1.txt","r",stdin);
//	freopen("maxsubsum1.txt","w",stdout);
//	int n=0;
//	int a[MAXN];
//	while(scanf("%d",&a[n])!=EOF)
//	{
//		n++;
//	}
//	n--;
//	int left=0,right=0;
//	printf("最大字段和为:%d\n",MaxSum(n,a,left,right));
//	printf("最大字段位于第%d个元素到第%d个元素\n",left,right);
//	return 0;
//}
