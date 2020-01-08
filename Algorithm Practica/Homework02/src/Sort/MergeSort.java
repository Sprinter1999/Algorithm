package Sort;

public class MergeSort {
    public static int depth=0;
    public static void mergesort(int []array,int left,int right,int k)
    {
        if(k>=depth)
            depth=k;
        if(left<right)
        {
            int mid=(left+right)/2;
            mergesort(array, left, mid,k+1);
            mergesort(array, mid+1, right,k+1);
            merge(array,left,mid,right);
        }
    }
    //二路归并
    public static void merge(int []array,int left,int mid,int right)
    {
        int[] temp=new int[array.length];
        int p1=left,p2=mid+1,k=left;
        //p1为A数组指针，p2为B数组检测指针，k指针用于存放
        while(p1<=mid&&p2<=right)
        {
            if(array[p1]<=array[p2])
                temp[k++]=array[p1++];
            else
                temp[k++]=array[p2++];
        }

        while(p1<=mid) temp[k++]=array[p1++];
        while(p2<=right) temp[k++]=array[p2++];

        for(int i=left;i<=right;i++)
            array[i]=temp[i];
    }
}
