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
int input(LinkList& L, int j);//�������
int GetData(LinkList& L);//��ȡԪ��

int main() {
	int num;
	LinkList L1;
	InitList(L1);
	cout << "����������������Ӷ�������" << endl;
	cin >> num;
	input(L1, num);
	GetData(L1);
	return 0;
}

int InitList(LinkList& head) {//��ʼ������
	head = (LinkList)malloc(sizeof(LNode));
	if (!head)exit(0);
	head->next = NULL;
	return ok;
}

int input(LinkList& L, int j) {//�������
	LinkList p,L1;//1�������½ڵ�
	p = L;//2, ��pָ����head��������������p��nextָ������ head��nextҲָ������
	for (int i = 0; i < j;i++) {
		L1 = (LinkList)malloc(sizeof(LNode));//3��p��nextָ���½ڵ㣨L1����head��nextҲָ����L1
		cout << "����" << j << "������" << endl;
		cin>>L1->data;//��������
		p->next = L1;//��p��L1��������
		p = L1;//4��p�Ͽ���head�����ӣ���L1��������������p��nextָ�����L1��nextҲָ������
		p->next = NULL;//��ֹnext�������ָ�������ط�
	}
	return ok;
}

int GetData(LinkList& L) {//���Ԫ��
	LinkList p;
	p = L->next;//ָ����һ����ַ��Ԫ��
	while (p!=NULL)
	{
		cout << p->data <<'\t';//��ȡ�����������
		p = p->next;//ָ����һ��
	}
	return ok;
}