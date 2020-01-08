package ClosestPair;
import java.math.*;
import jxl.Cell;
import jxl.Sheet;
import jxl.Workbook;
import jxl.read.biff.BiffException;
import java.lang.String;
import java.io.File;
import java.io.IOException;

public class Test {
    public final static double EARTH_RADIUS = 6378.137;//赤道半径km
    public static double rad(double LatOrLon)
    {
        return     LatOrLon * Math.PI / 180.0;
    }
    public static double GetDistance2(double lng1, double lat1, double lng2, double lat2)
    {
        {
            //将对应的经纬度转化为弧度
            double radLat1 = rad(lat1);
            double radLat2 = rad(lat2);
            double radlng1 = rad(lng1);
            double radlng2 = rad(lng2);
            //利用正弦余弦公式求距离
            double s = Math.acos(Math.cos(radLat1) * Math.cos(radLat2) * Math.cos(radlng1 - radlng2) + Math.sin(radLat1) * Math.sin(radLat2));
            s = s * EARTH_RADIUS;
            s = Math.round(s*1000);
            return  s;
        }
    }
    public static void mergeSort(Comparable[] a) {
        Comparable[] b = new Comparable[a.length];
        int s = 1;
        while(s < a.length) {
            mergePass(a, b, s);
            s += s;
            mergePass(b, a, s);
            s += s;
        }
    }

    public static void mergePass(Comparable[] x, Comparable[] y, int s) {
        //合并大小为s的相邻子数组
        int i = 0;
        while(i <= x.length - 2 * s) {
            merge(x, y, i, i + s - 1, i + 2 * s - 1);
            i += 2 * s;
        }
        //设下的元素少于2s
        if(i + s < x.length)
            merge(x, y, i, i + s - 1, x.length - 1);
        else
            for(int j = i;j < x.length; j++)
                y[j] = x[j];
    }

    public static void merge(Comparable[] c, Comparable[] d, int l, int m, int r) {
        //合并c[l:m]和c[m+1:r]到d[l:r]
        int i = l,
                j = m + 1,
                k = l;
        while((i <= m)&&(j <= r))
            if(c[i].compareTo(c[j]) <= 0)
                d[k ++] = c[i ++];
            else d[k ++] = c[j ++];
        //具体步骤可通过调试感受
        if(i > m)//判断哪侧数组有剩余
            //右侧剩余数组移入
            for(int q = j; q <= r; q++)
                d[k ++] = c[q];
        else
            //左侧剩余数组移入
            for(int q = i; q <= m; q++)
                d[k ++] = c[q];
    }

    public static class Point {
        double x, y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    public static class Point1 extends Point implements Comparable {
        int id;//编号
        public Point1(double x, double y, int id) {
            super(x, y);
            this.id = id;
        }
        @Override
        public int compareTo(Object o) {
            // TODO Auto-generated method stub
            double ox = ((Point1) o).x;
            if (this.x < ox) return -1;
            if (this.x == ox) return 0;
            return 1;
        }
        public boolean equals(Object o) {
            return this.x == ((Point1) o).x;
        }
    }

    public static class Point2 extends Point implements Comparable {
        int p; //同一点在数组X中的坐标
        public Point2(double x, double y, int p) {
            super(x, y);
            this.p = p;
        }
        @Override
        public int compareTo(Object o) {
            double oy = ((Point2) o).y;
            if (this.y < oy) return -1;
            if (this.y == oy) return 0;
            return 1;
        }

        public boolean equals(Object o) {
            return this.y == ((Point2)o).y;
        }
    }

    public static class Pair {
        Point1 a;
        Point1 b;
        double dist;// a与b间的距离

        public Pair(Point1 a, Point1 b, double dist) {
            this.a = a;
            this.b = b;
            this.dist = dist;
        }
    }

    //计算点u,v之间的距离
    public static double dist(Point u, Point v)
    {
        return GetDistance2(u.x,v.x,u.y,v.y);
    }

    public static Pair cPair2(Point1[] x) {
        if (x.length < 2) return null;
        //依x进行排序
        mergeSort(x);
        Point2[] y = new Point2[x.length];
        for (int i = 0; i < x.length; i++)
            y[i] = new Point2(x[i].x, x[i].y, i);
        //依y进行排序
        mergeSort(y);
        Point2[] z = new Point2[x.length];
        return closedPair(x, y, z, 0, x.length - 1);
    }

    //计算最接近点
    private static Pair closedPair(Point1[] x, Point2[] y, Point2[] z, int l, int r) {
//        System.out.println(1);
        if (r - l == 1)
            return new Pair(x[l], x[r], dist(x[l], x[r]));
        if (r - 1 == 2) {
            double d1 = dist(x[l], x[l + 1]);
            double d2 = dist(x[l+1], x[r]);
            double d3 = dist(x[l], x[r]);
            if (d1 <= d2 && d1 <= d3) return new Pair(x[l], x[l + 1], d1);
            if (d2 <= d3) return new Pair(x[l+1], x[r], d2);
            else return new Pair(x[l], x[r], d3);
        }
        //多于三点采用分治法
        int m = (l + r) / 2;
        int f = l, g = m + 1;
        //按x坐标大小把点分到两边
        for (int i = l; i <= r; i++)
            if (y[i].p > m) z[g++] = y[i];
            else z[f++] = y[i];

        //递归求解
        Pair best = closedPair(x, z, y, l, m);
        Pair right = closedPair(x, z, y, m + 1, r);
        if (best.dist > right.dist) best = right;
        merge(z, y, l, m, r);

        //将d矩形条内的点至于z中
        int k = l;
        for (int i = l; i <= r; i++)
            if (Math.abs(x[m].x - y[i].x) < best.dist)
                z[k++] = y[i];
        //搜索z[l:k-1]
        for (int i = l; i < k; i++) {
            for (int j = i + 1; j < k && z[j].y - z[i].y < best.dist; j++) {
                double dp = dist(z[j], z[i]);
                if (dp < best.dist)
                    best = new Pair(x[z[i].p], x[z[j].p], dp);
            }
        }
        return best;
    }

    public static void main(String[] args) throws IOException, BiffException {
        Workbook workbook = Workbook.getWorkbook(new File("1033个基站数据.xls"));
        Sheet sheet = workbook.getSheet(0);
        int targetRow=sheet.getRows();
        int targetCol=sheet.getColumns();
        Point1[] points=new Point1[targetRow-1];//除了开头的标题，还有targetRow-1个基站数据
        for (int i = 1; i < targetRow; i++)//索引是0~targetRow-1，有效的是1~targetRow-1
        {
            Cell cell1=sheet.getCell(0,i);//依次获取id，longitude，latitude
            Cell cell2=sheet.getCell(1,i);
            Cell cell3=sheet.getCell(2,i);
            int id= Integer.parseInt(cell1.getContents());
            double longitude=Double.parseDouble(cell2.getContents());
            double latitude=Double.parseDouble(cell3.getContents());
            Point1 aPoint=new Point1(longitude,latitude,id);
            points[i-1]=aPoint;
        }
        Pair answer=cPair2(points);
        System.out.printf("The pair is %lf",answer.dist);
    }
}
