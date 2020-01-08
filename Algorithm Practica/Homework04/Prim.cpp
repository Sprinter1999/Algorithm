#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm> 
using namespace std;
#define M_PI 3.14159265358979323846
const double Earth_R=6378.137;
double a[22][22];
const int MAX=100000; 

void Prim(int n,double c[][22])
{
	double lowcost[1000];
	int closest[1000];
	bool s[1000];
	s[0]=true;
	for(int i=1;i<=n;i++)
	{
		lowcost[i]=c[0][i];
		closest[i]=0;
		s[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		double min=MAX;
		int j=0;
		for(int k=1;k<=n;k++)
		{
			if((lowcost[k]<min)&&(!s[k]))
			{
				min=lowcost[k];
				j=k;
			}
			cout<<"j and closest[j]:"<<j<<" "<<closest[j]<<endl;
			s[j]=true;
			for(int k=1;k<=n;k++)
			{
				if((c[j][k]<lowcost[k])&&(!s[k]))
				{
					lowcost[k]=c[j][k];
					closest[k]=j;
				}
			}
		}
	}
 } 

int main(void)
{
	ifstream in("Matrix22.txt",ios::in);
	int i=0;
	while(!in.eof())
	{
		in>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5]>>a[i][6]>>a[i][7]>>a[i][8]>>a[i][9]>>a[i][10]>>a[i][11]>>a[i][12]>>a[i][13]>>a[i][14]>>a[i][15]>>a[i][16]>>a[i][17]>>a[i][18]>>a[i][19]>>a[i][20]>>a[i][21];
		printf("i:%d 1:%lf 2:%lf\n",i,a[i][1],a[i][22]);
		i+=1;
	}
	Prim(21,a);
	system("pause");
 } 
