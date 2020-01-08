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

//����
#define M_PI 3.14159265358979323846
#define EARTH_RADIUS 6378.137

//��ı�ʾ��
struct point{
    string id;      //id
    double x;       //����
    double y;       //γ��
    double kdist;   //kdistֵ
};

//����(���ڿ���ѡ��)
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

//�������������е�kСԪ�ص��±�
int QuickSelect(vector<point> &arr, int k, int left, int right){
    if(left <= right){
        //��������л���
        int middle = Partition(arr, left, right);
        //�ҵ���Χ[left,right]֮�䣬middle����Ӧ�������ڵڼ�
        int thN = middle + 1 - left;
        /*
        ���N��k��˵����kС������middle����� 
        ���N��kС��˵����kС������middle���Ҳ࣬������Ҫע�����k��ֵ
        ������������[middle+1,right]�����ڣ���k-thN������Ϊԭ���������k���ֵ
        */
        if(thN == k)
            return middle;
        else if(thN > k)
            return QuickSelect(arr, k, left, middle - 1);
        else
            return QuickSelect(arr, k - thN, middle + 1, right);
    }
    //��Χ����ʱ������-1
    return -1;
}

//�Ѿ��Ȼ�γ��ת��Ϊ����
double rad(double ang){
    return ang * M_PI / 180.0;
}

//����֮��ľ���
double distance(point &a, point &b){
    if(a.id == b.id){
        //���������ͬһ���㣬��ô��Ϊ��������Ϊ�����
        return 0x3f3f3f3f;
    }
    double ax = rad(a.x); //a�ľ��ȵĻ��ȱ�ʾ
    double ay = rad(a.y); //a��γ�ȵĻ��ȱ�ʾ
    double bx = rad(b.x); //b�ľ��ȵĻ��ȱ�ʾ
    double by = rad(b.y); //b��γ�ȵĻ��ȱ�ʾ
    long double s = EARTH_RADIUS * 1000;
    s *= acosl(cosl(ay) * cosl(by) * cosl(ax - bx) + sinl(ay) * sinl(by)); //��������������
    return s;
}

//�������ݹ��ɶ���������
double PythagorasDis(point &a, point &b){
    return sqrt((a.y-b.y)*(a.y-b.y) + (a.x - b.x)*(a.x-b.x));
}

//�Ƚ�������֮���ĸ�Ϊ�������
pair<point, point> cmp2pointpairs(pair<point, point> &a, pair<point, point> &b){
    double disa = distance(a.first, a.second);
    double disb = distance(b.first, b.second);
    //����ѡȡ����
    if(a.first.id == a.second.id)
        return b;
    if(b.first.id == b.second.id)
        return a;
    if(disa < disb)
        return a;
    return b;
}

//��ӡ�����Ϣ
void print_pointpair(pair<point,point> &a){
    cout << "id1:" << a.first.id << " , id2:" << a.second.id << endl;
    //���þ���ΪС�����11λ
    cout << setprecision(11) << "< (" << a.first.x << "," << a.first.y << ") , (" << a.second.x << "," << a.second.y << ") >" << endl;
    cout << setprecision(11) << "distance  : " << distance(a.first, a.second) << "m" << endl;
    return;
}

//��ά����������
pair<point, point> Cpair2(vector<point> &p, int left, int right){
    //n��ʾ����Ѱ�ĵ����
    int n = right - left + 1;
    if(n < 2){
        return {};
    }
    //����������
    if(n == 2){
        pair<point, point> p2 = {p[left], p[right]};
        return p2;
    }
    //����������
    if(n == 3){
        pair<point, point> p1 = {p[left], p[left + 1]};
        pair<point, point> p2 = {p[left], p[right]};
        pair<point, point> p3 = {p[left + 1], p[right]};
        pair<point, point> result = cmp2pointpairs(p1, p2);
        return cmp2pointpairs(result, p3);
    }
    //ѡ���㼯�о��ȵ���λ��
    int middle = left + (right - left) / 2;
    point mid = p[middle];
    //�ݹ��ҵ�x = middle���ҵ���ѵ��
    pair<point, point> d1 = Cpair2(p, left, middle);
    pair<point, point> d2 = Cpair2(p, middle + 1, right);
    //ѡ��������ѵ���и��õ�һ��
    pair<point, point> better = cmp2pointpairs(d1, d2);
    //��Ե�ƽ�����
    double dis = PythagorasDis(better.first, better.second);
    //����ʵ���ϵ����֮���������ϵ�������ӵĻ����������������Ķ���Ͳ�������
    //��x = p[middle].x �����������С�� dis�ĵ�ɸѡ�������ֱ����������㼯�У������������㼯�еĵ㰴�������ź���
    vector<point> P_left, P_right;
    for (int i = left; i <= right; i++){
        //�����ĺ���������Ϊ [p[middle].x - dis, p[middle].x]
        if(mid.x >= p[i].x && mid.x - p[i].x <= dis)
            P_left.push_back(p[i]);
        //�����ĺ���������Ϊ [p[middle].x, p[middle].x + dis] ע�� ����ȥ���Ⱥţ���Ϊ�����������x = middle��һ��������
        if(p[i].x >= mid.x && p[i].x - mid.x <= dis)
            P_right.push_back(p[i]);
    }
    sort(P_left.begin(), P_left.end(), [&](point &a, point &b) {
        return a.y < b.y;
    });
    sort(P_right.begin(), P_right.end(), [&](point &a, point &b) {
        return a.y < b.y;
    });
    //���յĴ𰸵��
    pair<point,point> bestp = better;
    //������������ÿ�����㼯�еĵ㣬�Ҳ�㼯ֻ�����������ֵ�ñȽ� (�������Ҿ���������)
    for (int i = 0; i < P_left.size();i++){
        int j;
        //�ҵ��Ҳ���������ӽ�P_left[i]�ĵ�
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

//����Ϊfilename���ļ�����ȡ����
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

//ͨ��O(n^2)�Ļ����㷨��֤�����ȷ��
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

//ԭ�������� IDΪ568471��568849��������վ��γ��һ�£����������Ѿ��޳�
int main(){
    vector<point> points = fileread("data.txt");
    sort(points.begin(), points.end(), [&](point &a, point &b) {            //�Ե㼯���о����ϵ�Ԥ����
        return a.x < b.x;
    });
    int i1 = QuickSelect(points, 1, 0, points.size() - 1);
    int i2 = QuickSelect(points, 5, 0, points.size() - 1);
    int i3 = QuickSelect(points, 50, 0, points.size() - 1);
    int i4 = QuickSelect(points, points.size(), 0, points.size() - 1);
    //Ѱ��ƽ�������Բ���ӡ
    pair<point,point> ans = Cpair2(points, 0, points.size() - 1);
    cout << "the cloest points are : " << endl;
    print_pointpair(ans);
    //Ѱ�Ҿ������Сֵ
    point a = ans.first;
    int posa = 0;
    //�Ƴ���a��Ѱ����̾���
    for (int i = 0;i<points.size();i++){
        if(points[i].id == a.id){
            points.erase(points.begin() + i);
            posa = i;
            break;
        }
    }
    pair<point, point> cddans1 = Cpair2(points, 0, points.size() - 1);
    cout << "remove the first point of ans, the candidate ans is : " << endl;
    print_pointpair(cddans1);                                               //��ӡ�Ƴ���a��ĺ�ѡ��    
    //�Ƴ���b��Ѱ����̾���
    points.insert(points.begin()+posa,a);                                   //���Ƴ��ĵ�a�ӻ���
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
    points.insert(points.begin()+posb,b);                                   //���Ƴ��ĵ�b�ӻ���
    print_pointpair(cddans2);                                               //��ӡ�Ƴ���b��ĺ�ѡ��
    cout << "the second cloest points are : " << endl;
    pair<point,point> ans2 = cmp2pointpairs(cddans1, cddans2);
    print_pointpair(ans2);                                                  //��ӡ�����Сֵ
    return 0;
}
