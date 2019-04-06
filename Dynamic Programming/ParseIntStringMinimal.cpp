/*
@It's Chinese,boy.
@题目描述：
小浣熊松松来到文具店，选择了K支自己喜欢的水彩笔，
并抄下了它们的价格。可是到结算时，他发现自己抄价格时抄得太密集，
以至于所有价格连成了一个数字串（你可以假设价格都是正整数）。老板想和松松开个玩笑，于是对他说：
“你可以把这个数字串分成K段，代表这K支笔的价格，然后把他们加起来，就是你要付给我的钱了。”
当然，松松想尽可能省下钱去买《算法导论》，所以请你来帮忙算算，他最少需要付多少钱。 

输入描述 Input Description
	第一行包含一个整数N，代表松松抄下来的数字串。
	第二行包含一个整数K，代表松松买了K支水彩笔。
输出描述 Output Description
	输出仅一行，为松松买这些笔最少花的钱。
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
        	dp[i][0]=Count(1,i); //将我们dp数组的第一列置为1 12 123 1234 12345 
        }
        for(int i=2;i<=len;i++)//i=2 3 4 5 
            for(int j=1;j<i;j++)//j=1，j<i 
	        {
	            int Min=0x7fffffff;
	            for(int k=1;k<=i-j;k++)//i-k>j,迭代寻找min 
	            {
					Min=dp[i-k][j-1]+Count(i-k+1,i)<Min?dp[i-k][j-1]+Count(i-k+1,i):Min;
	            }
	            dp[i][j]=Min;
	        }
        cout<<dp[len][t-1]<<endl;
    }
    return 0;
}

