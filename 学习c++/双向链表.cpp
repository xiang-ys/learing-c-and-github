#include<iostream>
#include<stdlib.h>
#define ElemType int
#define ok 1
#define on 0
using namespace std;

typedef struct DoubleNode {//定义双链表
	ElemType data;
	DoubleNode* next;
	DoubleNode* prior;
}DuLNode, * DuLinkList;

int InitList(DuLinkList& L);//初始化双链表
int input(DuLinkList &L,int j);//添加数据

int main() {
	DuLinkList L1;
	cout << InitList(L1);
	return 0;
}

int InitList(DuLinkList& L) {//初始化双链表
	L = (DuLinkList)malloc(sizeof(DuLNode));
	if (!L)exit(0);
	L->next = NULL;
	L->prior = NULL;
	return ok;
}

int input(DuLinkList& L, int j) {//添加数据
	DuLinkList p,L1;
	p = L;
	L1 = (DuLinkList)malloc(sizeof(DuLNode));
	return ok;

}