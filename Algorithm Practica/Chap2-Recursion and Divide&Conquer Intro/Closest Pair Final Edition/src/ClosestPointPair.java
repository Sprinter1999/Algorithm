import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;

import jxl.Cell;
import jxl.Sheet;
import jxl.Workbook;

public class ClosestPointPair {
    public static void main(String[] args) throws Exception {
        String fileName = "C:\\Users\\Qin\\Desktop\\1033个基站数据.xls";
        PointX[] pointx = new PointX[1033];
        pointx = ClosestPointPair.fileReadColumn(fileName);
        PointX[] ab = new PointX[4];
        double[] d = new double[2];
        px[0] = pointx[0];
        px[1] = pointx[1];
        d[1] = ClosestPointPair.getDistance(px);
        ClosestPointPair.cpair2(pointx, pointx.length, ab, d);
    }

    public static PointX[] fileReadColumn(String fileName) throws Exception {
        File file = new File(fileName);
        InputStream inputStream = new FileInputStream(file.getAbsoluteFile());
        Workbook workbook = Workbook.getWorkbook(inputStream);
        Sheet sheet = workbook.getSheet(0);
        int rows = sheet.getRows();
        int columns = sheet.getColumns();
        PointX[] point = new PointX[1033];
        int j = 0, id;
        double data1, data2;
        for (int i = 1; i < rows; i++) {
            Cell cell = sheet.getCell(0, i);
            id = Integer.parseInt(cell.getContents());
            cell = sheet.getCell(1, i);
            data1 = Double.parseDouble(cell.getContents());
            cell = sheet.getCell(2, i);
            data2 = Double.parseDouble(cell.getContents());
            point[j] = new PointX(id, data1, data2);
            j++;
        }
        return point;
    }

    public static double getDistance(Comparable[] Com) {
        double radLng1, radLng2, radLat1, radLat2;
        if(Com[0] instanceof PointX) {
            PointX C0 = (PointX)Com[0];
            radLng1 = rad(C0.longitude);
            radLat1 = rad(C0.latitude);
        }else {
            PointY C0 = (PointY)Com[0];
            radLng1 = rad(C0.longitude);
            radLat1 = rad(C0.latitude);
        }
        if(Com[1] instanceof PointX) {
            PointX C1 = (PointX)Com[1];
            radLng2 = rad(C1.longitude);
            radLat2 = rad(C1.latitude);
        }else {
            PointY C1 = (PointY)Com[1];
            radLng2 = rad(C1.longitude);
            radLat2 = rad(C1.latitude);
        }

        double distance = Math.acos(Math.cos(radLat1) * Math.cos(radLat2) * Math.cos(radLng1 - radLng2) + Math.sin(radLat1) * Math.sin(radLat2));
        //earth_radius = 6378.137   //赤道半径km
        distance = distance * 6378.137;
        distance = Math.round(distance * 1000);
        return distance;
    }

    public static double rad(double lngOrLat) {
        return lngOrLat * Math.PI / 180.0;
    }

    public static boolean cpair2(PointX[] X, int length, PointX[] ab, double[] d) {
        if(length < 2) {
            return false;
        }
        mergeSort(X);
        PointY[] Y = new PointY[length];
        for(int i = 0; i < length; i++) {
            Y[i] = new PointY();
            Y[i].xp = i;
            Y[i].latitude = X[i].latitude;
            Y[i].longitude = X[i].longitude;
        }
        mergeSort(Y);
        PointY[] Z = new PointY[length];
        closest(X, Y, Z, 0, length - 1, ab, d);
        System.out.printf("最近基站点对(%d, %d)", ab[0].enodebid, ab[1].enodebid);
        System.out.println("\t\t相距里程:" + d[0]);
        System.out.printf("次最近基站点对(%d, %d)", ab[2].enodebid, ab[3].enodebid);
        System.out.println("\t相距里程:" + d[1] + "\n");
        return true;
    }

    static PointX[] px = new PointX[2];
    static PointY[] py = new PointY[2];
    static PointX[] abr = new PointX[2];
    public static void closest(PointX[] X, PointY[] Y, PointY[] Z, int p, int r, PointX[] ab, double[] d) {
        if(r - p == 1) {
            ab[0] = X[p];
            ab[1] = X[r];
            px[0] = X[p];
            px[1] = X[r];
            d[0] = getDistance(px);
            return;
        }

        if(r - p == 2) {
            px[0] = X[p];
            px[1] = X[p + 1];
            double d1 = getDistance(px);
            px[0] = X[p + 1];
            px[1] = X[r];
            double d2 = getDistance(px);
            px[0] = X[p];
            px[1] = X[r];
            double d3 = getDistance(px);
            if((d1 <= d2) && (d1 <= d3)) {
                ab[0] = X[p];
                ab[1] = X[p + 1];
                d[0] = d1;
            }else if(d2 <= d3) {
                ab[0] = X[p + 1];
                ab[1] = X[r];
                d[0] = d2;
            }else {
                ab[0] = X[p];
                ab[1] = X[r];
                d[0] = d3;
            }
            return;
        }

        int m = (p + r) / 2;
        int f = p, g = m + 1;
        for(int i = p; i <= r; i++) {
            if(Y[i].xp > m) {
                Z[g++] = Y[i];
            }else {
                Z[f++] = Y[i];
            }
        }
        closest(X, Z, Y, p, m, ab, d);
        double[] dr = new double[2];
        closest(X, Z, Y, m + 1, r, abr, dr);
        if((dr[0] < d[0]) && (dr[0] != 0)) {
            ab[0] = abr[0];
            ab[1] = abr[1];
            d[0] = dr[0];
        }
        if((dr[0] > d[0]) && (dr[0] < d[1])) {
            ab[2] = abr[0];
            ab[3] = abr[1];
            d[1] = dr[0];
        }
        merge(Z, Y, p, m, r);
        int k = p;
        for(int i = p; i < r; i++) {
            if(Math.abs(Y[m].latitude - Y[i].latitude) < d[0]) {
                Z[k++] = Y[i];
            }
        }
        for(int i = p; i < k; i++) {
            for(int j = i + 1; ((j < k) && (Z[j].longitude - Z[i].longitude) < d[0]); j++) {
                py[0] = Z[i];
                py[1] = Z[j];
                double[] dp = new double[1];
                dp[0] = getDistance(py);
                if((dp[0] > d[0]) && (dp[0] < d[1])) {
                    ab[2] = X[Z[i].xp];
                    ab[3] = X[Z[j].xp];
                    d[1] = dp[0];
                }
                if((dp[0] < d[0]) && (dp[0] != 0)) {
                    d[0] = dp[0];
                    ab[0] = X[Z[i].xp];
                    ab[1] = X[Z[j].xp];
                }
            }
        }
    }

    public static void mergeSort(Comparable[] Com) {
        Comparable[] a = new Comparable[Com.length];
        int s = 1;
        while(s < Com.length) {
            mergePass(Com, a, s);
            s += s;
            mergePass(a, Com, s);
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
        int i = l, j = m + 1, k = l;

        while((i <= m) && (j <= r)) {
            if(c[i].compareTo(c[j]) <= 0) {
                d[k ++] = c[i ++];
            }else {
                d[k ++] = c[j ++];
            }
        }

        if(i > m) {//判断哪侧数组有剩余
            for(int q = j; q <= r; q++) {
                d[k ++] = c[q];
            }
        }else {
            for(int q = i; q <= m; q++) {
                d[k ++] = c[q];
            }
        }
    }
}
