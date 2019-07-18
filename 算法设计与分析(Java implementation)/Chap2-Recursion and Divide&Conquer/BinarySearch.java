//
public class BinarySearch{
    public static void main(String[] args) {
        // ...
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