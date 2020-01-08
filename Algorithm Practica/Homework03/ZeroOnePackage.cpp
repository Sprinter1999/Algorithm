#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
const int packVol=300;
const int maxNum=50;
int m[maxNum+1][packVol+1];
int x[maxNum+1];
void Knapsack(int *v,int *w,int c,int n)
{   
// para:c package Vol
	int  Jmax= min(w[n]-1,c); 
    for(int j=0; j<=Jmax; j++) m[n][j]=0;
    for(int j=w[n]; j<=c; j++) m[n][j]=v[n];
    for(int i=n-1; i>1; i--) 
	{  
        Jmax= min(w[i]-1,c);
        for(int j=0;j<=Jmax;j++)
	   		m[i][j]=m[i+1][j];
        for(int j=w[i];j<=c;j++)
        	m[i][j]=max(m[i+1][j], m[i+1][j-w[i]]+v[i]);
    }
    m[1][c]=m[2][c];
    if (c>=w[1])  
	 	m[1][c]=max(m[2][c], m[1][c-w[1]]+v[1]);
}
int main(void)
{
	int ValueArr[]={50,72,16,69,46,9,8,59,49,28,36,1,38,28,2,35,74,71,44,61,58,55,63,59,48,41,39,9,25,9,32,50,48,19,22,3,19,51,68,9,77,4,72,46,41,20,12,15,52,77}; 
	int WeightArr[]= {14, 11, 36, 17, 40, 43, 14, 26, 10, 48, 16, 45, 41, 15 ,31 ,21, 37, 19, 48, 29, 30, 50, 13, 15, 9 ,10 ,46, 12, 49, 19, 49, 8 ,11, 21 ,11 ,36, 13, 8 ,50 ,42 ,45 ,10 ,28 ,16 ,9 ,17 ,18 ,33 ,23 ,18};
	Knapsack(ValueArr,WeightArr,packVol,maxNum);
	printf("%d",m[1][packVol]);
	return 0;
}
