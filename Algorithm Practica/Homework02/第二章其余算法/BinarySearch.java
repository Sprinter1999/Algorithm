import java.util.Arrays;

//TODO:二分查找是基于排序好的数组进行的查找
public class BinarySearch{
    public static void main(String[] args) {
        int[] a={1,2,3,4,6,7,7,8};
        Arrays.sort(a);
        int ans=BinarySearch(a, a.length, 7);
        // System.out.println(a.length);
        System.out.println(ans);
    }
    public static int BinarySearch(int[] a,int n,int x)
    {
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int middle=(left+right)/2;
            if(x==a[middle]) return middle;        
            if(x>a[middle]) left=middle+1;
            else right=middle-1;
        }
        return -1;//which stands for "not found"
    }
}
//