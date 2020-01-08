package Sort;

public class QuickSort {
//    public static int count=0;
    public static int depth=0;
    public static void qsort(int p,int r,int[] a,int k)
    {
//        count+=1;
        if(k>=depth)
            depth=k;
        if(p<r)
        {
            int q=partition(p,r,a);
            qsort(p, q-1,a,k+1);
            qsort(q+1, r,a,k+1);
        }
    }
    public static int partition(int p,int r, int[] a)
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