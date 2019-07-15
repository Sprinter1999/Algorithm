1.分析复杂度的时候可能会用到数学手段：
 - 斯特林公式：$N!=>sqrt (2* Pi *N )*(n \div e)^{n}$,反正他的复杂度肯定比2^N要大，比2^N要大就比x^m次方要大了。

2.Prove n！=o($n^{n}$)
 - Stirling approxiamation,as what I have showed above

3.写一个通用方法来判定指定的数组是否已经排好序了
```java
public static boolean IsOrdered(Comparable []a)
{
    int j=0,n=a.length;
    while(j<n-1&&a[j].compareTo(a[j+1])==0)
        j++;
    if(n<=1||j==n-1)
        return true;
    else
        j=a[j].compareTo(a[j+1]);
    for(int i=1;i<n-1;i++)
        if(a[i].compareTo(a[i+1])*j<0)
            return false;
    return true;
}
```

4. 通用方法
   通用方法一般借助接口实现
   - Computable 接口，一般可以提供add（this不被修改） sub multi divide mod inc（this被修改） dec zero(0) identity(1)抽象方法
   - Comparable 接口，比如x.compareTo(y)返回x-y的符号
   - Operable 接口，它extends了上面俩借口
   - 自定义包装类，略
    举个例子：
    ```java
    public static Computable sum(Computable []a,int n)
    {
        if(a.length==0) return null;
        Computable sum=(Computable)a[o].zero();
        for(int i=0;i<n;i++)
            sum.inc(a[i]);
        return sum;
    }
    ```