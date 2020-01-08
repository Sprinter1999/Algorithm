package Sort;

import java.util.Random;

public class QuickSortRandom {
    static Random random=new Random();
    public static int depth=0;
    public static void randomizedQuickSort(int p,int r,int[] a,int k)
    {
        if(k>=depth)
            depth=k;
        if(p<r)
        {
            int q=randomizedPartition(p,r,a);
            randomizedQuickSort(p, q-1,a,k+1);
            randomizedQuickSort(q+1, r,a,k+1);
        }
    }
    public static int randomizedPartition(int p,int r,int[] a)
    {
        int i=p+random.nextInt(r-p);
        swap(a,i,p);
        return Partition(p,r,a);

    }
    public static int Partition(int p,int r, int[] a)
    {
        int i=p,j=r+1;
        int key=a[p];
        while(true)
        {
            while((a[++i]<key)&&i<r);
            while(a[--j]>key);
            if(i>=j) break;
            swap(a,i,j);
        }
        a[p]=a[j];
        a[j]=key;
        return j;
    }
    public static void swap(int[] a,int i,int j)
    {
        a[i]=a[i]^a[j];
        a[j]=a[i]^a[j];
        a[i]=a[i]^a[j];
    }
}