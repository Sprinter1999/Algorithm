//TODO:整数划分
import java.util.Scanner;
/*
将一个整数n表示成若干正整数之和，n=n1+n2+...+nk，其中k>=1显然，问对于一个
整数n，其分法P(n)有多少？

思路：
n=n1+n2+...+n3,suppose n1>=n2>=n3...>=1,将最大加数n1不超过m的分法记为q（n，m）
*/
public class IntegerDivide
{
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int result=q(n,n);
        System.out.println("result is:"+result);
    }
    /**
     * @param m 最大值n1
     * @param n  总数为n
     */
    public static int q(int n,int m)

    {
        // edge conditions
        if((n<1)||(m<1)) return 0;
        if((n==1)||(m==1)) return 1;
        if(n<m) return q(n,n);
        if(n==m) return 1+q(n, m-1);
        //TODO:in general,all q(n,m) can resolved to q(n,m-1) plus q(n-m,m)
        return q(n,m-1)+q(n-m,m);
    }
    
}