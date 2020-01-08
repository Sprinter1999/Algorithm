#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//Huffman���Ľڵ���
typedef struct Node
{
    char value;               //�����ַ�ֵ   
    int weight;               //����ַ����ֵ�Ƶ��
    Node *lchild,*rchild;     //�������Һ���
}Node;

//�Զ���������򣬼���vector��node���weightֵ��������
bool ComNode(Node *p,Node *q)
{
    return p->weight<q->weight;
}

//����Huffman�������ظ����ָ��
Node* BuildHuffmanTree(vector<Node*> vctNode)
{
    while(vctNode.size()>1)                            //vctNodeɭ��������������1ʱѭ�����кϲ�
    {
        sort(vctNode.begin(),vctNode.end(),ComNode);   //��Ƶ�ȸߵͶ�ɭ���е���������������

        Node *first=vctNode[0];    //ȡ�������vctNodeɭ����Ƶ����С������
        Node *second=vctNode[1];   //ȡ�������vctNodeɭ����Ƶ�ȵڶ�С������
        Node *merge=new Node;      //�ϲ�����������
        merge->weight=first->weight+second->weight;
        merge->lchild=first;
        merge->rchild=second;

        vector<Node*>::iterator iter;
        iter=vctNode.erase(vctNode.begin(),vctNode.begin()+2);    //��vctNodeɭ����ɾ������Ƶ����С�������ڵ�first��second
        vctNode.push_back(merge);                                 //��vctNodeɭ������Ӻϲ����merge��
    }
    return vctNode[0];            //���ع���õĸ��ڵ�
}

//�û��ݷ�����ӡ����
void PrintHuffman(Node *node,vector<int> vctchar)
{
    if(node->lchild==NULL && node->rchild==NULL)
    {//���ߵ�Ҷ�ӽڵ㣬�������ӡvctchar�д�ı���
        cout<<node->value<<": ";
        for(vector<int>::iterator iter=vctchar.begin();iter!=vctchar.end();iter++)
            cout<<*iter;
        cout<<endl;
        return;
    }
    else
    {
        vctchar.push_back(1);     //����������ʱ��vctchar�м�һ��1
        PrintHuffman(node->lchild,vctchar);
        vctchar.pop_back();       //���ݣ�ɾ���ոռӽ�ȥ��1
        vctchar.push_back(0);     //����������ʱ��vctchar�м�һ��0
        PrintHuffman(node->rchild,vctchar);
        vctchar.pop_back();       //���ݣ�ɾ���ոռӽ�ȥ��0

    }
}

string readFileIntoString(char *filename)
{
	ifstream ifile(filename);
	//���ļ����뵽ostringstream����buf��
	stringstream buf;
	char ch;
	while(buf&&ifile.get(ch))
	{
		if(isalpha(ch))
			buf.put(tolower(ch));
		else
			buf.put('#');
	}
	//������������buf�������ַ���
	return buf.str();
}


 
int main(void){
	
	char *fn="a.txt";
	string str;
	str=readFileIntoString(fn);
	cout<<str<<endl;
	
	char chars[27]={};
	int freqs[27]={};
	map<char,int> ms;
	map<char,int>::iterator p,mEnd;
	string s=str;
	int len = s.length();
	for(int i=0;i<len;i++){
		p=ms.find(s[i]);
		if(p!=ms.end()){
			p->second++;
		}
		else{
			ms.insert(pair<char,int>(s[i],1));
		}
	}
	p=ms.begin();
	mEnd=ms.end();
	int counter=0;
	for(;p!=mEnd;p++){
		cout<<p->first<<":"<<p->second<<endl;
		chars[counter]=p->first;
		freqs[counter]=p->second;
		counter+=1;
		
	}
	
    vector<Node*> vctNode;        //���Node����vector����vctNode
    char ch;                      //��ʱ��ſ���̨������ַ�
    for(int i=0;i<27;i++)
    {
        ch=chars[i];
        Node *temp=new Node;
        temp->value=ch;
        temp->lchild=temp->rchild = NULL;
        vctNode.push_back(temp);  //���µĽڵ���뵽����vctNode��
    }

    for(int i=0;i<vctNode.size();i++)
        vctNode[i]->weight=freqs[i];

    Node *root = BuildHuffmanTree(vctNode);   //����Huffman���������ص���������root
    vector<int> vctchar;
    cout<<endl<<"��Ӧ��Huffman�������£�"<<endl;
    PrintHuffman(root,vctchar);

    system("pause");
}
