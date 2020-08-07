#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

vector<long> v[1005];


int main(){
	int n;
	scanf("%d",&n);
	
	v[0].push_back(0);
	v[0].push_back(0);
	v[0].push_back(0);
	v[0].push_back(0);
	v[0].push_back(0);
	v[0].push_back(0);
	
	for(int i=1;i<=n;i++)
	{
		long long a,b,c,d,e,f;
		i > 1? a=1:a=0;
		
		b=v[i-1][1];
		c=v[i-1][2];
		d=v[i-1][3];
		e=v[i-1][4];
		f=v[i-1][5];
		
		v[i].push_back(a);
		v[i].push_back((b*2+a) % 1000000007);
		v[i].push_back((c+a) % 1000000007);
		v[i].push_back((d*2+b) % 1000000007);
		v[i].push_back((e*2+b+c) % 1000000007);
		v[i].push_back((f*2+e+d) % 1000000007);
	}
	printf("%lld\n",v[n][5]);
	return 0;
}

