#include <iostream>
 
using namespace std;
const int N = 1000000;
int t[N];//用来存储时间 
 
int main(void)
{
    int n, a, b, c, d, max=0, time=0;
    
    cin >> n;//读入时间段数量 
    
    for(int i=0; i<N; i++){
    	t[i] = 0;
	}//把数组初始化为零，若使用memset函数更简洁 
        
 
    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(b > max)
            max = b;
        for(int j=a; j<b; j++)
            t[j] ++;
    }//输入小H的时间段，并在对应时间段+1 
 
    for(int i=0; i<n; i++){
        cin >> c >> d;
        if(d > max)
            max = d;
        for(int j=c; j<d; j++)
            t[j] ++;
    }//输入小W的时间段，并在对应时间段+1 
 
    for(int i=0; i<max; i++){ 
        if(t[i] == 2)
            time ++;
    }//若时间为2，说明该时刻两次+1，即两人都在装车，可以聊天，time统计总时间 
	 
    cout << time << endl;//输出所求时间 
 
    return 0;
}
