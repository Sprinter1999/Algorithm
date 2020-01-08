package Sort;

import java.util.Random;

public class ArrayGenerator
{
    //TODO:SEQ(n,N),固定N=30000,生成长度为n=2k,5k,10k,15k,20k,30k六类长度，每类五组测试用例
    //TODO:还需要计算Average Distinct Degree,但我们可以放在主函数中
    //TODO:So we have geneArray(int length),here we go
    public static int MAXI=30000;
    public static int[] geneArray(int length)
    {
        Random random=new Random();
        int[] test=new int[length];
        for(int i=0;i<length;i++)
            test[i]=random.nextInt(MAXI);
        return test;
    }
    public static int cal_ADD(int[] arr)
    {
        int len=arr.length,DD=0;
        for(int i=0;i<len;i++)
        {
            for(int j=i;j<len;j++)
                if(arr[j]<arr[i])
                    DD+=1;
        }
        return DD/len;
    }
    public static int[] CopyArray(int[] arr)
    {
        int len=arr.length;
        int[] newone=new int[len];
        for(int i=0;i<len;i++)
            newone[i]=arr[i];
        return newone;
    }
}
