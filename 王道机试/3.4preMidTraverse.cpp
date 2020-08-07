#include <stdio.h>
#include <string.h>

struct Node {
	Node *lchild;
	Node *rchild;
	char c;
} Tree[50]; //静态数组

int loc; //当前已经分配的节点数量

//申请一个节点空间返回其指向的指针
Node *create() {
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++]; //返回指针
}

char str1[30],str2[30]; //前序中序结果
void postOrder(Node *T) {
	if(T->lchild!=NULL) {
		postOrder(T->lchild);
	}
	if(T->rchild!=NULL) {
		postOrder(T->rchild);
	}
	printf("%c",T->c);
}

}
Node *Insert(Node *T,int x) { 
	if (T == NULL) { 
		T = creat();
		T -> c = x; 
		return T; 
	} else if (x < T->c) 
		T -> lchild = Insert(T -> lchild,x); 
	else if (x > T->c) 
		T -> rchild = Insert(T -> rchild,x);	
	return T;
}

Node *build(int s1,int e1,int s2,int e2)
//由前序和中序还原树，并且返回其根节点
{
	Node* ret=create();
	ret->c=str1[s1]; //前序遍历的第一个字符
	int rootIdx;
	for(int i=s2; i<=e2; i++) {
		if(str2[i]==str1[s1]) {
			rootIdx=i;
			break;
		}
	}
	if(rootIdx!=s2) {
		//左子树不为空
		ret->lchild=build(s1+1,s1+(rootIdx-s2),s2,rootIdx-1);
	}
	if(rootIdx!=e2) {
		//若右子树也不为空
		ret->rchild=build(s1+(rootIdx-s2)+1,e1,rootIdx+1,e2);
	}
	return ret;
}
int main() {
	while(scanf("%s",str1)!=EOF) {
		scanf("%s",str2);
		loc=0;
		int L1=strlen(str1);
		int L2=strlen(str2);
		Node* T=build(0,L1-1,0,L2-1);
		postOrder(T);
		printf("\n");
	}
	return 0;
}
