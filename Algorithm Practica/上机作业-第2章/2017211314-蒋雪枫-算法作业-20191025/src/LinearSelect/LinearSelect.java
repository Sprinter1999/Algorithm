package LinearSelect;

import java.util.Arrays;
import java.util.Random;

public class LinearSelect
{
    //线性时间选择算法
    public static float select(float[] arr,int p,int r,int k)
    {
        if(r-p<5)
        {
            Arrays.sort(arr,p,r);
            return arr[p+k-1];
        }

        for(int i=0;i<=(r-p-4)/5;i++)
        {
            int s=p+5*i,t=s+4;
            for(int j=0;j<3;j++)
                Arrays.sort(arr,s,t-j);
            swap(arr,p+i,s+2);
        }

        float x=select(arr,p,p+(r-p-4)/5,(r-p+6)/10);
        int i=Partition(arr,p,r),j=i-p+1;
        if(k<=j) return select(arr,p,i,k);
        else return select(arr, i+1, r, k-j);
    }

    public static float RandomizedSelect(float[] arr,int p,int r,int k)
    {
        if(p==r) return arr[p];
        int i= RandomPartion(arr,p,r);
        int j=i-p+1;
        if(k<=j) return RandomizedSelect(arr,p,i,k);
        else return  RandomizedSelect(arr,i+1,r,k-j);
    }
    public static int RandomPartion(float[] arr,int p,int r)
    {
        Random random=new Random();
        int i=p+random.nextInt(r-p);
        swap(arr,i,p);
        return Partition(arr,p,r);
    }
    public static void swap(float[] a,int i,int j)
    {
        float temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    public static int Partition(float a[],int p,int r)
    {
        int i=p,j=r+1;
        float x=a[p];
        while (true)
        {
            while(a[++i]<x);
            while(a[--j]>x);
            if(i>=j) break;
            swap(a, i, j);
        }
        a[p]=a[j];
        a[j]=x;
        return j;
    }
}
