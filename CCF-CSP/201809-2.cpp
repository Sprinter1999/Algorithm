#include <iostream>
 
using namespace std;
const int N = 1000000;
int t[N];//�����洢ʱ�� 
 
int main(void)
{
    int n, a, b, c, d, max=0, time=0;
    
    cin >> n;//����ʱ������� 
    
    for(int i=0; i<N; i++){
    	t[i] = 0;
	}//�������ʼ��Ϊ�㣬��ʹ��memset��������� 
        
 
    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(b > max)
            max = b;
        for(int j=a; j<b; j++)
            t[j] ++;
    }//����СH��ʱ��Σ����ڶ�Ӧʱ���+1 
 
    for(int i=0; i<n; i++){
        cin >> c >> d;
        if(d > max)
            max = d;
        for(int j=c; j<d; j++)
            t[j] ++;
    }//����СW��ʱ��Σ����ڶ�Ӧʱ���+1 
 
    for(int i=0; i<max; i++){ 
        if(t[i] == 2)
            time ++;
    }//��ʱ��Ϊ2��˵����ʱ������+1�������˶���װ�����������죬timeͳ����ʱ�� 
	 
    cout << time << endl;//�������ʱ�� 
 
    return 0;
}
