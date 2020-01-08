#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>  
#include <math.h> 
#include <ctime>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <windows.h>
#include <queue>
#define INF 999999
#define num1 15
#define num2 20
using namespace std;
double G1[num1][num1];
double G2[num2][num2];
double cost1 = 0;
double cost2 = 0;
int bestx1[num1], bestx2[num2];
double bestw1 = 999999, bestw2 = 999999;
double cw1 = 0, cw2 = 0;
int  near1[num1][num1], near2[num2][num2]; // 图中顶点邻接矩阵， a[k][j] = 1说明k与j相邻
int id1[num1], id2[num2];
int visit = 0;
int novisit1[num1], novisit2[num2];//贪心法，选择没有遍历过的城市中最近的，记录是否此城市是否遍历过
double zong = 0;
vector<int> craet_node;
struct node
{
	int k=-1;
	double lcost=INF;
	double rest = INF;
	double current = INF;
	int* path;

	bool operator<(const node& other)const
	{
		return other.lcost < lcost;
	}
};

priority_queue<struct node>NATlist;

int input()
{
	ifstream infile("problem1.csv", ios::in);
	if (!infile)
	{
		cout << "文件打开失败!" << endl;
		abort();
	}
	string line;
	vector<string> temp;
	int row = 0;
	while (!infile.eof())
	{
		int column = 0;
		getline(infile, line);
		string str;
		stringstream s(line);
		int count = 0;
		while (!s.eof())
		{
			if (row == 0)
			{
				getline(s, str, ',');
				if (column >= 2)
				{
					int d = atoi(str.c_str());
					id1[column - 2] = d;
				}
				column++;
			}
			else if (row >= 2)
			{
				getline(s, str, ',');
				if (column >= 2)
				{
					double d = strtod(str.c_str(), NULL);
					G1[row - 2][column - 2] = d;
					if (d != 99999)
						near1[row - 2][column - 2] = 1;
					else
						near1[row - 2][column - 2] = 0;
				}
				column++;
			}
			else
				break;
		}
		row++;
	}

	ifstream infile2("problem2.csv", ios::in);
	if (!infile2)
	{
		cout << "文件打开失败!" << endl;
		abort();
	}
	string line2;
	vector<string> temp2;
	int row2 = 0;
	while (!infile2.eof())
	{
		int column2 = 0;
		getline(infile2, line2);
		string str2;
		stringstream s2(line2);
		int count2 = 0;
		while (!s2.eof())
		{
			if (row2 == 0)
			{
				getline(s2, str2, ',');
				if (column2 >= 2)
				{
					int d = atoi(str2.c_str());
					id2[column2 - 2] = d;
				}
				column2++;
			}
			else if (row2 >= 2)
			{
				getline(s2, str2, ',');
				if (column2 >= 2)
				{
					double d = strtod(str2.c_str(), NULL);
					G2[row2 - 2][column2 - 2] = d;
					if (d != 99999)
						near2[row2 - 2][column2 - 2] = 1;
					else
						near2[row2 - 2][column2 - 2] = 0;
				}
				column2++;
			}
			else
				break;
		}
		row2++;
	}
}

int find(int id[], int k, int last)
{
	for (int i = 0; i <= last; i++)
	{
		if (id[i] == k)
			return i;
	}
}
double dfs(int u, int k, double sum,int choice)//当前节点，目标节点，已经消耗的路径
{
	if (choice == 1)
	{
		if (k == num1)
			return sum + G1[u][12];//如果已经检查了n个节点，则直接返回路径消耗+第n个节点回归起点的消耗
		else
		{
			double min = INF;
			int p=-1;
			for (int i = 0; i < num1; i++)
			{
				if (novisit1[i] == 1 && (min==INF || min > G1[u][i]))//取与所有点的连边中最小的边
				{
					min = G1[u][i];//找出对于每一个节点，其可达节点中最近的节点
					p = i;
				}
			}
			novisit1[p] = 0;//以p为下一个节点继续搜索
			return dfs(p, k + 1, sum + min, choice);
		}
		
	}
	else if (choice == 2)
	{
		if (k == num2)
		{
			return sum + G2[u][17];//如果已经检查了n个节点，则直接返回路径消耗+第n个节点回归起点的消耗
		}
			
		else
		{
			double min = INF;
			int p = -1;
			for (int i = 0; i < num2; i++)
			{
				if (novisit2[i] == 1 && (min == INF || min > G2[u][i]))//取与所有点的连边中最小的边
				{
					min = G2[u][i];//找出对于每一个节点，其可达节点中最近的节点
					p = i;				
				}
			}
			novisit2[p] = 0;//以p为下一个节点继续搜索
			return dfs(p, k + 1, sum + min, choice);
		}
	}
}
void TSP(int start, int choice)
{
	if (choice == 1)
	{
		double minCostOutEdge[num1];
		double sumOfMinCostOutEdges = 0;
		for (int i = 0; i < num1; ++i)
		{
			double minCost = -1;
			for (int j = 0; j < num1; ++j)
				if (near1[i][j] == 1 && (minCost == -1 || minCost > G1[i][j]))
					minCost = G1[i][j];
			minCostOutEdge[i] = minCost;
			sumOfMinCostOutEdges += minCost;
		}
		struct node temp;
		struct node e;
		e.lcost = sumOfMinCostOutEdges;
		e.current = 0;
		e.rest = sumOfMinCostOutEdges;
		e.k = 0;
		e.path = new int[num1];
		for (int i = 0; i < num1; i++)
		{
			e.path[i] = i;
		}
		swap(e.path[0], e.path[start]);

		double bestCostSoFar = dfs(start, 1, 0, choice);  //当前最佳旅行耗费
		int* currentTour = e.path;

		while (e.k < num1 - 1)
		{
			visit++;
			currentTour = e.path;
			if (e.k == num1 - 2)
			{
				if (near1[currentTour[num1 - 2]][currentTour[num1 - 1]] == 1 && near1[currentTour[num1 - 1]][currentTour[0]] == 1 &&
					(e.current + G1[currentTour[num1 - 2]][currentTour[num1 - 1]] + G1[currentTour[num1 - 1]][currentTour[0]] < bestCostSoFar))
				{//发现最优旅行，加入小根堆
					bestCostSoFar = e.current + G1[currentTour[num1 - 2]][currentTour[num1 - 1]] + G1[currentTour[num1 - 1]][currentTour[0]];	
					e.current = bestCostSoFar;
					e.lcost = bestCostSoFar;
					e.k++;
					NATlist.push(e);
				}
				else
				{
					delete[] e.path;  //舍弃非最优的叶结点的父节点，释放内存
					e.path = nullptr;
				}
			}
			else//选最优的节点进行扩展
			{
				for (int i = e.k + 1; i < num1; i++)
				{
					if (near1[currentTour[e.k]][currentTour[i]] == 1)
					{//子节点可行
						double current = e.current + G1[currentTour[e.k]][currentTour[i]];
						double rest = e.rest - minCostOutEdge[currentTour[e.k]];
						double lcostPossible = current + rest;

						if (lcostPossible < bestCostSoFar)
						{//子树可能有更优的叶结点，把当前子树的根放入小根堆
							struct node newe;
							newe.lcost = lcostPossible;
							newe.current = current;
							newe.rest = rest;
							newe.k = e.k + 1;
							newe.path = new int[num1];
							copy(currentTour, currentTour + num1, newe.path);
							swap(newe.path[newe.k], newe.path[i]);
							NATlist.push(newe);
						}
					}
				}
				//完成节点扩展，释放内存
				delete[] e.path;
				e.path = nullptr;
			}
			if (NATlist.size() == 1)
			{
				break;
			}

			//取下一个E-节点
			e = NATlist.top();

			NATlist.pop();
		}
		copy(e.path, e.path + num1, bestx1);

		//释放小根堆中剩余元素的currentTour数组内存***虽然小根堆析构，
		//但是currentTour是new的内存，依然存在，故必须手动释放
		while (true)
		{
			delete[] e.path;
			if (NATlist.size() == 0)
				break;
			//取下一个E-节点
			e = NATlist.top();
			NATlist.pop();
		}
		bestw1 = bestCostSoFar;
	}
	else if (choice == 2)
	{
		double minCostOutEdge[num2];
		double sumOfMinCostOutEdges = 0;
		for (int i = 0; i < num2; ++i)
		{
			double minCost = -1;
			for (int j = 0; j < num2; ++j)
				if (near2[i][j] == 1 && (minCost == -1 || minCost > G2[i][j]))
					minCost = G2[i][j];
			minCostOutEdge[i] = minCost;
			sumOfMinCostOutEdges += minCost;
		}
		struct node temp;
		struct node e;
		e.lcost = sumOfMinCostOutEdges;
		e.current = 0;
		e.rest = sumOfMinCostOutEdges;
		e.k = 0;
		e.path = new int[num2];
		for (int i = 0; i < num2; i++)
		{
			e.path[i] = i;
		}
		swap(e.path[0], e.path[start]);

		double bestCostSoFar = dfs(start, 1, 0, choice);  //当前最佳旅行耗费
		int* currentTour = e.path;

		while (e.k < num2 - 1)
		{
			visit++;
			currentTour = e.path;
			if (e.k == num2 - 2)
			{
				if (near2[currentTour[num2 - 2]][currentTour[num2 - 1]] == 1 && near2[currentTour[num2 - 1]][currentTour[0]] == 1 &&
					(e.current + G2[currentTour[num2 - 2]][currentTour[num2 - 1]] + G2[currentTour[num2 - 1]][currentTour[0]] < bestCostSoFar))
				{//发现最优旅行，加入小根堆
					bestCostSoFar = e.current + G2[currentTour[num2 - 2]][currentTour[num2 - 1]] + G2[currentTour[num2 - 1]][currentTour[0]];
					e.current = bestCostSoFar;
					e.lcost = bestCostSoFar;
					e.k++;
					NATlist.push(e);
				}
				else
				{
					delete[] e.path;  //舍弃非最优的叶结点的父节点，释放内存
					e.path = nullptr;
				}
			}
			else//选最优的节点进行扩展
			{
				for (int i = e.k + 1; i < num2; i++)
				{
					if (near2[currentTour[e.k]][currentTour[i]] == 1)
					{//子节点可行
						double current = e.current + G2[currentTour[e.k]][currentTour[i]];
						double rest = e.rest - minCostOutEdge[currentTour[e.k]];
						double lcostPossible = current + rest;

						if (lcostPossible < bestCostSoFar)
						{//子树可能有更优的叶结点，把当前子树的根放入小根堆
							struct node newe;
							newe.lcost = lcostPossible;
							newe.current = current;
							newe.rest = rest;
							newe.k = e.k + 1;
							newe.path = new int[num2];
							copy(currentTour, currentTour + num2, newe.path);
							swap(newe.path[newe.k], newe.path[i]);
							NATlist.push(newe);
						}
					}
				}
				//完成节点扩展，释放内存
				delete[] e.path;
				e.path = nullptr;
			}
			if (NATlist.size() == 1)
			{
				break;
			}

			//取下一个E-节点
			e = NATlist.top();

			NATlist.pop();
		}
		copy(e.path, e.path + num2, bestx2);

		//释放小根堆中剩余元素的currentTour数组内存***虽然小根堆析构，
		//但是currentTour是new的内存，依然存在，故必须手动释放
		while (true)
		{
			delete[] e.path;
			if (NATlist.size() == 0)
				break;
			//取下一个E-节点
			e = NATlist.top();
			NATlist.pop();
		}
		bestw2 = bestCostSoFar;
	}
}
int main()
{
	LARGE_INTEGER nFreq;
	LARGE_INTEGER t1;
	LARGE_INTEGER t2;
	input();
	for (int i = 0; i < num1; i++)
		novisit1[i] = 1;
	for (int i = 0; i < num2; i++)
		novisit2[i] = 1;
	double totalcost = 0;

	int start1 = find(id1, 20, 14);
	int start2 = find(id2, 20, 19);
	novisit1[start1] = 0;
	novisit2[start2] = 0;

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&t1);
	TSP(start1, 1);
	QueryPerformanceCounter(&t2);
	double duration = (t2.QuadPart - t1.QuadPart) / (double)nFreq.QuadPart;
	for (int i = 0; i < num1; i++)
		cout << id1[bestx1[i]] << "->";
	cout << id1[bestx1[0]] << endl;
	cout << "节点数:" << visit << endl;
	cout << "最小cost:" << bestw1 << "   duration:" << duration << endl;

	visit = 0;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&t1);
	TSP(start2, 2);
	QueryPerformanceCounter(&t2);
	double duration = (t2.QuadPart - t1.QuadPart) / (double)nFreq.QuadPart;
	for (int i = 0; i < num2; i++)
		cout << id2[bestx2[i]] << "->";
	cout << id2[bestx2[0]] << endl;
	cout << "节点数:" << visit << endl;
	cout << "最小cost:" << bestw2 << "   duration:" << duration << endl;
	system("pause");
}