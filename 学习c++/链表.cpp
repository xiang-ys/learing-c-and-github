#include<iostream>
#include<stdlib.h>
#define ElemType int
#define ok 1
#define no 0
using namespace std;

typedef struct ListNode {//��ʼ������
	ElemType data;
	ListNode* next;
}LNode,*LinkList;
//1����˵LNode������typede���÷������Ե�֪LNode����struct ListNode�ı�������ListNode == struct LNode��
//2����˵LinkList����һ��ָ��ýṹ��ĵ�ָ��ı�����

int InitList(LinkList& head);//��ʼ������
int input(LinkList& L,ElemType num);//�������
int GetData(LinkList& L);//��ȡԪ��

int main() {
	LinkList L1;
	InitList(L1);
	input(L1, 1);
	input(L1, 2);
	input(L1, 3);
	GetData(L1);
	return 0;
}

int InitList(LinkList& head) {//��ʼ������
	head = (LinkList)malloc(sizeof(LNode));
	if (!head)exit(0);
	head->next = NULL;
	return ok;
}

int input(LinkList& L, ElemType num) {//�������
	LinkList p,L1;
	p = (LinkList)malloc(sizeof(LNode));//1�������½ڵ�
	p = L;//2, ��pָ����head��������������p��nextָ������ head��nextҲָ������
	L1 = (LinkList)malloc(sizeof(LNode));//3��p��nextָ���½ڵ㣨L1����head��nextҲָ����L1
	L1->data = num;//��������
	p->next = L1;
	p = L1;//4��p�Ͽ���head�����ӣ���L1��������������p��nextָ�����L1��nextҲָ������
	p->next = NULL;//��ֹnext�������ָ�������ط�
	return ok;
}

int GetData(LinkList& L) {//���Ԫ��
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

void CreateListTail(LinkList& L, int m[], int n) {//β�巨
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

int GetElem(LinkList L, int i, ElemType* e) {//��ȡԪ��
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