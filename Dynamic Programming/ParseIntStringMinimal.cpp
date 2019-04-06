/*
@It's Chinese,boy.
@��Ŀ������
С������������ľߵ꣬ѡ����K֧�Լ�ϲ����ˮ�ʱʣ�
�����������ǵļ۸񡣿��ǵ�����ʱ���������Լ����۸�ʱ����̫�ܼ���
���������м۸�������һ�����ִ�������Լ���۸��������������ϰ�������ɿ�����Ц�����Ƕ���˵��
������԰�������ִ��ֳ�K�Σ�������K֧�ʵļ۸�Ȼ������Ǽ�������������Ҫ�����ҵ�Ǯ�ˡ���
��Ȼ�������뾡����ʡ��Ǯȥ���㷨���ۡ���������������æ���㣬��������Ҫ������Ǯ�� 

�������� Input Description
	��һ�а���һ������N���������ɳ����������ִ���
	�ڶ��а���һ������K��������������K֧ˮ�ʱʡ�
������� Output Description
	�����һ�У�Ϊ��������Щ�����ٻ���Ǯ��
*/ 
#include<iostream>
#include<cstring>
using namespace std;
int dp[1001][1001];
char s[1000];
int t;
int Count(int start,int End)
{
	//Parse into Integer
    int sum=0;
    int j=1;
    for(int i=End-1;i>=start-1;i--)
    {
        sum+=(s[i]-'0')*j;
        j*=10;
    }
    return sum;
}
int main()
{
    while(cin>>s>>t)
    {
        int len=strlen(s);//suppose we have 12345 , 5 as input data
        for(int i=1;i<=len;i++)
        {
        	dp[i][0]=Count(1,i); //������dp����ĵ�һ����Ϊ1 12 123 1234 12345 
        }
        for(int i=2;i<=len;i++)//i=2 3 4 5 
            for(int j=1;j<i;j++)//j=1��j<i 
	        {
	            int Min=0x7fffffff;
	            for(int k=1;k<=i-j;k++)//i-k>j,����Ѱ��min 
	            {
					Min=dp[i-k][j-1]+Count(i-k+1,i)<Min?dp[i-k][j-1]+Count(i-k+1,i):Min;
	            }
	            dp[i][j]=Min;
	        }
        cout<<dp[len][t-1]<<endl;
    }
    return 0;
}

