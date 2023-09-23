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
int input(LinkList& L, int j);//添加数据
int GetData(LinkList& L);//获取元素

int main() {
	int num;
	LinkList L1;
	InitList(L1);
	cout << "输入你想在链表添加多少数据" << endl;
	cin >> num;
	input(L1, num);
	GetData(L1);
	return 0;
}

int InitList(LinkList& head) {//初始化链表
	head = (LinkList)malloc(sizeof(LNode));
	if (!head)exit(0);
	head->next = NULL;
	return ok;
}

int input(LinkList& L, int j) {//添加数据
	LinkList p,L1;//1，创建新节点
	p = L;//2, 将p指针与head关联起来，这样p的next指向哪里 head的next也指向哪里
	for (int i = 0; i < j;i++) {
		L1 = (LinkList)malloc(sizeof(LNode));//3，p的next指向新节点（L1），head的next也指向了L1
		cout << "输入" << j << "个数字" << endl;
		cin>>L1->data;//存入数据
		p->next = L1;//将p和L1连接起来
		p = L1;//4，p断开与head的链接，与L1关联起来，这样p的next指向哪里，L1的next也指向哪里
		p->next = NULL;//防止next不经意间指向其他地方
	}
	return ok;
}

int GetData(LinkList& L) {//获得元素
	LinkList p;
	p = L->next;//指向下一个地址的元素
	while (p!=NULL)
	{
		cout << p->data <<'\t';//获取并且输出数据
		p = p->next;//指向下一个
	}
	return ok;
}