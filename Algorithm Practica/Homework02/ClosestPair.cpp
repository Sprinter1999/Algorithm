#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <utility>
#include <chrono>
#include <fstream>
#include <iomanip>
using namespace std;

//常量
#define M_PI 3.14159265358979323846
#define EARTH_RADIUS 6378.137

//点的表示：
struct point{
    string id;      //id
    double x;       //经度
    double y;       //纬度
    double kdist;   //kdist值
};

//划分(用于快速选择)
int Partition(vector<point> &arr, int left, int right){
    point guard = arr[left];
    int i = left, j = right + 1;
    while(true){
        while(i < right && arr[++i].kdist < guard.kdist);
        while(arr[--j].kdist > guard.kdist);
        if(i >= j) break;
        swap(arr[i], arr[j]);
    }
    arr[left] = arr[j];
    arr[j] = guard;
    return j;
}

//返回无序数组中第k小元素的下标
int QuickSelect(vector<point> &arr, int k, int left, int right){
    if(left <= right){
        //对数组进行划分
        int middle = Partition(arr, left, right);
        //找到范围[left,right]之间，middle所对应的数排在第几
        int thN = middle + 1 - left;
        /*
        如果N比k大，说明第k小的数在middle的左侧 
        如果N比k小，说明第k小的数在middle的右侧，这里需要注意更变k的值
        这是由于在自[middle+1,right]区间内，第k-thN的数即为原先区间里第k大的值
        */
        if(thN == k)
            return middle;
        else if(thN > k)
            return QuickSelect(arr, k, left, middle - 1);
        else
            return QuickSelect(arr, k - thN, middle + 1, right);
    }
    //范围错误时，返回-1
    return -1;
}

//把经度或纬度转换为弧度
double rad(double ang){
    return ang * M_PI / 180.0;
}

//两点之间的距离
double distance(point &a, point &b){
    if(a.id == b.id){
        //如果两点是同一个点，那么认为两点间距离为无穷大
        return 0x3f3f3f3f;
    }
    double ax = rad(a.x); //a的经度的弧度表示
    double ay = rad(a.y); //a的纬度的弧度表示
    double bx = rad(b.x); //b的经度的弧度表示
    double by = rad(b.y); //b的纬度的弧度表示
    long double s = EARTH_RADIUS * 1000;
    s *= acosl(cosl(ay) * cosl(by) * cosl(ax - bx) + sinl(ay) * sinl(by)); //计算球面两点间距
    return s;
}

//两点间根据勾股定理计算距离
double PythagorasDis(point &a, point &b){
    return sqrt((a.y-b.y)*(a.y-b.y) + (a.x - b.x)*(a.x-b.x));
}

//比较两组点对之间哪个为更近点对
pair<point, point> cmp2pointpairs(pair<point, point> &a, pair<point, point> &b){
    double disa = distance(a.first, a.second);
    double disb = distance(b.first, b.second);
    //避免选取自身
    if(a.first.id == a.second.id)
        return b;
    if(b.first.id == b.second.id)
        return a;
    if(disa < disb)
        return a;
    return b;
}

//打印点对信息
void print_pointpair(pair<point,point> &a){
    cout << "id1:" << a.first.id << " , id2:" << a.second.id << endl;
    //设置精度为小数点后11位
    cout << setprecision(11) << "< (" << a.first.x << "," << a.first.y << ") , (" << a.second.x << "," << a.second.y << ") >" << endl;
    cout << setprecision(11) << "distance  : " << distance(a.first, a.second) << "m" << endl;
    return;
}

//二维最近点对问题
pair<point, point> Cpair2(vector<point> &p, int left, int right){
    //n表示待搜寻的点个数
    int n = right - left + 1;
    if(n < 2){
        return {};
    }
    //两个点的情况
    if(n == 2){
        pair<point, point> p2 = {p[left], p[right]};
        return p2;
    }
    //三个点的情况
    if(n == 3){
        pair<point, point> p1 = {p[left], p[left + 1]};
        pair<point, point> p2 = {p[left], p[right]};
        pair<point, point> p3 = {p[left + 1], p[right]};
        pair<point, point> result = cmp2pointpairs(p1, p2);
        return cmp2pointpairs(result, p3);
    }
    //选出点集中经度的中位数
    int middle = left + (right - left) / 2;
    point mid = p[middle];
    //递归找到x = middle左右的最佳点对
    pair<point, point> d1 = Cpair2(p, left, middle);
    pair<point, point> d2 = Cpair2(p, middle + 1, right);
    //选出两个最佳点对中更好的一对
    pair<point, point> better = cmp2pointpairs(d1, d2);
    //点对的平面距离
    double dis = PythagorasDis(better.first, better.second);
    //但是实际上点与点之间是球面关系，这样子的话或许矩形内六个点的定理就不成立了
    //将x = p[middle].x 左右两侧距离小于 dis的点筛选出来，分别存放在两个点集中，并对这两个点集中的点按纵坐标排好序
    vector<point> P_left, P_right;
    for (int i = left; i <= right; i++){
        //这个点的横坐标区间为 [p[middle].x - dis, p[middle].x]
        if(mid.x >= p[i].x && mid.x - p[i].x <= dis)
            P_left.push_back(p[i]);
        //这个点的横坐标区间为 [p[middle].x, p[middle].x + dis] 注意 不能去掉等号，因为两个点可能在x = middle这一条经线上
        if(p[i].x >= mid.x && p[i].x - mid.x <= dis)
            P_right.push_back(p[i]);
    }
    sort(P_left.begin(), P_left.end(), [&](point &a, point &b) {
        return a.y < b.y;
    });
    sort(P_right.begin(), P_right.end(), [&](point &a, point &b) {
        return a.y < b.y;
    });
    //最终的答案点对
    pair<point,point> bestp = better;
    //根据推理：对于每个左侧点集中的点，右侧点集只有最多六个点值得比较 (本题中我觉得有问题)
    for (int i = 0; i < P_left.size();i++){
        int j;
        //找到右侧纵坐标最接近P_left[i]的点
        for (j = 0; j < P_right.size() && P_left[i].y - P_right[j].y >= 0;j++);
        int low = max(0, j - 3);
        int lenR = P_right.size() - 1;
        int high = min(j+3, lenR);
        while(low <= high){
            pair<point, point> tempp = {P_left[i], P_right[low]};
            bestp = cmp2pointpairs(bestp, tempp);
            low++;
        }
    }
    return bestp;
}

//打开名为filename的文件来获取数据
vector<point> fileread(string filename){
    fstream f;
    f.open(filename);
    if(!f.is_open()){
        cout << "error : file not exist!" << endl;
        return {};
    }
    vector<point> points;
    string id, x, y, kdist;
    point p;
    while(!f.eof() && f.peek() != EOF){
        f >> id >> x >> y >> kdist;
        p.id = id;
        p.x = stod(x);
        p.y = stod(y);
        p.kdist = stod(kdist);
        points.push_back(p);
        f.get();
    }
    f.close();
    return points;
}

//通过O(n^2)的基础算法验证结果正确性
pair<point,point> Verify(vector<point> &p){
    pair<point, point> bestp;
    double dis = 0x3f3f3f3f;
    for (int i = 0; i < p.size();i++){
        for (int j = i + 1; j < p.size();j++){
            double d = distance(p[i], p[j]);
            if(d < dis){
                dis = d;
                bestp = {p[i], p[j]};
            }
        }
    }
    return bestp;
}

//原本数据中 ID为568471和568849的两个基站经纬度一致，在数据中已经剔除
int main(){
    vector<point> points = fileread("data.txt");
    sort(points.begin(), points.end(), [&](point &a, point &b) {            //对点集进行经度上的预排序
        return a.x < b.x;
    });
    int i1 = QuickSelect(points, 1, 0, points.size() - 1);
    int i2 = QuickSelect(points, 5, 0, points.size() - 1);
    int i3 = QuickSelect(points, 50, 0, points.size() - 1);
    int i4 = QuickSelect(points, points.size(), 0, points.size() - 1);
    //寻找平面最近点对并打印
    pair<point,point> ans = Cpair2(points, 0, points.size() - 1);
    cout << "the cloest points are : " << endl;
    print_pointpair(ans);
    //寻找距离次最小值
    point a = ans.first;
    int posa = 0;
    //移除点a后，寻找最短距离
    for (int i = 0;i<points.size();i++){
        if(points[i].id == a.id){
            points.erase(points.begin() + i);
            posa = i;
            break;
        }
    }
    pair<point, point> cddans1 = Cpair2(points, 0, points.size() - 1);
    cout << "remove the first point of ans, the candidate ans is : " << endl;
    print_pointpair(cddans1);                                               //打印移除点a后的候选答案    
    //移除点b后，寻找最短距离
    points.insert(points.begin()+posa,a);                                   //把移除的点a加回来
    point b = ans.second;
    int posb = 0;
    for (int i = 0;i<points.size();i++){
        if(points[i].id == b.id){
            points.erase(points.begin() + i);
            posb = i;
            break;
        }
    }
    pair<point, point> cddans2 = Cpair2(points, 0, points.size() - 1);
    cout << "remove the second point of ans, the candidate ans is : " << endl;
    points.insert(points.begin()+posb,b);                                   //把移除的点b加回来
    print_pointpair(cddans2);                                               //打印移除点b后的候选答案
    cout << "the second cloest points are : " << endl;
    pair<point,point> ans2 = cmp2pointpairs(cddans1, cddans2);
    print_pointpair(ans2);                                                  //打印距离次小值
    return 0;
}
