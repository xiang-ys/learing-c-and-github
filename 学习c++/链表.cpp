#include<iostream>
#include<stdlib.h>
#define ElemType int
#define ok 1
#define no 0
using namespace std;

typedef struct ListNode {//初始化链表
	ElemType data;
	ListNode* next;
}LNode,*LinkList;
//1、先说LNode，参照typede的用法，可以得知LNode就是struct ListNode的别名，即ListNode == struct LNode；
//2、再说LinkList，是一个指向该结构体的的指针的别名。

int InitList(LinkList& head);//初始化链表
int input(LinkList& L,ElemType num);//添加数据
int GetData(LinkList& L);//获取元素

int main() {
	LinkList L1;
	InitList(L1);
	input(L1, 1);
	input(L1, 2);
	input(L1, 3);
	GetData(L1);
	return 0;
}

int InitList(LinkList& head) {//初始化链表
	head = (LinkList)malloc(sizeof(LNode));
	if (!head)exit(0);
	head->next = NULL;
	return ok;
}

int input(LinkList& L, ElemType num) {//添加数据
	LinkList p,L1;
	p = (LinkList)malloc(sizeof(LNode));//1，创建新节点
	p = L;//2, 将p指针与head关联起来，这样p的next指向哪里 head的next也指向哪里
	L1 = (LinkList)malloc(sizeof(LNode));//3，p的next指向新节点（L1），head的next也指向了L1
	L1->data = num;//存入数据
	p->next = L1;
	p = L1;//4，p断开与head的链接，与L1关联起来，这样p的next指向哪里，L1的next也指向哪里
	p->next = NULL;//防止next不经意间指向其他地方
	return ok;
}

int GetData(LinkList& L) {//获得元素
	int num;
	LinkList p;
	p = L->next;
	while (p->next!=NULL)
	{
		p = p->next;
		num = p->data;
		cout << num<<'\t';
	}
	return ok;
}

void CreateListTail(LinkList& L, int m[], int n) {//尾插法
	LinkList p, r;
	int i;
	L = (LinkList)malloc(sizeof(LNode));
	r = L;
	for (i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = m[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int GetElem(LinkList L, int i, ElemType* e) {//获取元素
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) {
		return no;
	}
	*e = p->data;
	return ok;
}