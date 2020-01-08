#include<iostream>
#include<algorithm>
#include<fstream>
#define MAX 100
using  namespace std;
int n=20;                               //城市个数
float a[MAX][MAX];                   //城市间距离
int x[MAX];                       //记录路径
int bestx[MAX]  = {0};           //记录最优路径
float bestp = 63355;              //最短路径长
float cp = 0;                    //当前路径长

void backpack(int t){
     if(t>n){
        if((a[x[n]][1])&&(a[x[n]][1]+cp<bestp)){
              bestp = a[x[n]][1]+cp;
              for(int i = 1;i<=n;i++){
                 bestx[i] = x[i];
              }
        }
     }else{
         for(int i = t;i<=n;i++){
             /*约束为当前节点到下一节点的长度不为0,限界为走过的长度+当前要走的长度之和小于最优长度*/
            if((a[x[t-1]][x[i]])&&(cp+a[x[t-1]][x[i]]<bestp)){
                swap(x[t],x[i]);   
                cp+=a[x[t-1]][x[t]];
                backpack(t+1);
                cp-=a[x[t-1]][x[t]];
                swap(x[t],x[i]);
            }
         }
    }
}
int main(){    
    ifstream in("20vertexs.txt",ios::in);
	int i=1;
	for(int i = 1;i<=n;i++)
	{
         x[i] = i;
    }
	while(!in.eof())
	{
		in>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5]>>a[i][6]>>a[i][7]>>a[i][8]>>a[i][9]>>a[i][10]>>a[i][11]>>a[i][12]>>a[i][13]>>a[i][14]>>a[i][15]>>a[i][16]>>a[i][17]>>a[i][18]>>a[i][19]>>a[i][20];
		printf("i:%d 1:%f 2:%f\n",i,a[i][1],a[i][15]);
		i+=1;
	}
    backpack(2);
    cout<<"最少旅行费用为: "<<bestp<<endl;
    cout<<"旅行路径为:"<<endl;
    for(int i = 1;i<=n;i++){
       cout<<bestx[i]<<" ";
    }
    cout<<bestx[1];
    return 0;
}
