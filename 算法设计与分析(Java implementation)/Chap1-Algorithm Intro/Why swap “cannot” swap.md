**See here is an example which aims to swap two strings.**  
```java
public class Swap5
{
    public static void main(String[] args)
    {
        String x = new String("x111");
        String y = new String("y111");
        swap(x, y);
        System.out.println(x);
        System.out.println(y);
    }

    public static void swap(String a, String b)
    {
        String temp = a;
        a = b;
        b = temp;
    }
}
```
运行结果：java Swap5
x111
y111
可见并没有发生交换。
**Let's see another example：**  
```java
public class Swap
{
    public static void main(String[] args)
    {
        int c = 3;
        int d = 5;
        swap(c, d);
        System.out.println("c: " + c + "  d: " + d);

    }

    public static void swap(int a, int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}
```
运行结果： 
java Swap 
c: 3 d: 5
可见，他也没有交换。

什么调用swap()方法后并没有交换c、d的值呢，因为java只有值传递（没有引用传递），所以  **其实调用swap()时是把值赋给a、b,赋完后与c、d就没什么关系，c、d还是原来的值。**  其实就是值传递。不理解的话回去看看值传递。

**而交换数组元素的时候：**
```java
public class Swap5
{
    public static void main(String[] args)
    {
        int[] i = {3, 5};

        swap(i);
        System.out.println(i[0]);
        System.out.println(i[1]);
    }

    public static void swap(int[] a)
    {
        int temp = a[0];
        a[0] = a[1];
        a[1] = temp;
    }
}

```
#### 总结：引用类型才可以交换。因为原生数据类型是直接赋值，而引用类型直接赋的是地址，地址指向的是同一个对象，所以能改变。一般我们常见的都是值参数。