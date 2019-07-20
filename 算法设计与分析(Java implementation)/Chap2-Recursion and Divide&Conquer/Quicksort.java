package sort;

public class quicksort {
	public static void main(String[] args)
	{
		int[] a= {55,99,88,33,66,77,22,11,44};
		qsort(0,a.length-1,a);
		System.out.print("Quicksort result:");
		for (int i : a) {
			System.out.println(i);
		}
	}
	
	public static void qsort(int p,int r,int[] a)
	{
		if(p<r)
		{
			int q=partition(p,r,a);
			qsort(p, q-1,a);
			qsort(q+1, r,a);
		}
	}
	
	public static int partition(int p,int r, int[] a)
	{
		int i=p,j=r+1;
		int key=a[p];
		
		while(true)
		{
			while((a[++i]<key)&& i<r);
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
