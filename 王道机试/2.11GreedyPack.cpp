#include <stdio.h>
#include <algorithm>
using namespace std;
struct Thing{
	double price;
	double weight;
	double mean;
	Thing():price(),weight(),mean() {}
	Thing(int _p,int _w,double _m):price(_p),weight(_w),mean(_m){}
	
	bool operator < (const Thing &A) const{
		return mean > A.mean;
	}
}list[1001];

int main()
{
	double m;
	int n;
	while(scanf("%lf %d",&m,&n)!=EOF)
	{
		if(m==-1&&n==-1) break;
		for(int i=0;i<n;i++)
		{
			double price,weight;
			scanf("%lf %lf",&price,&weight);
			double mean=price/weight;
			Thing thing(price,weight,mean);
			list[i]=thing;
		}
		sort(list,list+n);
		int ptr=0;
		double sum=0;
		while(m>0&&ptr<n)
		{
			if(m<=list[ptr].weight)
			{
				sum+=m*list[ptr].mean;
				m=0;
			}
			else{
				sum+=list[ptr].price;
				m-=list[ptr].weight;
				ptr++;
			}
		}
		printf("test %.3lf\n",sum);
	}
	return 0;
}
