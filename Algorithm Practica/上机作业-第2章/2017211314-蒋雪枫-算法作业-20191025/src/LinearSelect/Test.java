package LinearSelect;
import jxl.*;
import jxl.read.biff.BiffException;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Test
{
    //从Excel里面读取数据然后测试
    public static void main(String[] args) throws IOException, BiffException {
        Workbook workbook = Workbook.getWorkbook(new File("1033个基站数据.xls"));
        Sheet sheet = workbook.getSheet(0);
        int targetRow=sheet.getRows();
        float[] Distances=new float[targetRow-1];
        int targetCol=sheet.getColumns();
        for (int i = 1; i < targetRow; i++)//开头是label，dont care
        {
            Cell cell=sheet.getCell(targetCol-1,i);
            Distances[i-1]= Float.parseFloat(cell.getContents());
        }
        Scanner in=new Scanner(System.in);
        System.out.println("想查询第几名？k=？");
        int k=in.nextInt();
        float ans=LinearSelect.RandomizedSelect(Distances,0,Distances.length-1,k);
        System.out.printf("使用快排思想，您查询的是第%d名(从小到大)，为%f\n",k,ans);
        float ans2=LinearSelect.select(Distances,0,Distances.length-1,k);
        System.out.printf("使用线性时间选择思想，您查询的是第%d名(从小到大)，为%f\n",k,ans);
    }
}
