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
int GetData(LinkList& L);//���Ԫ��ͬʱ�����ж���Ԫ��
int InsertData(LinkList& L, int location, int num);//��locationλ�ò�������
int DeleteData(LinkList& L, int location);//��locationλ��ɾ������
int GetData(LinkList& L, int location);//����ض�λ�õ�����

int main() {
	int num,location;//�������ݺ�λ��
	LinkList L1;
	InitList(L1); //��ʼ������(����������)
	cout << "����������������Ӷ�������" << endl;
	cin >> num;
	input(L1, num);//���Ԫ��
	num = GetData(L1);//���Ԫ��
	cout << "����������" <<num << "��Ԫ��" << endl;
	cout << endl;//�ָ�

	cout << "����ִ�в����������������Ҫ�����λ�ú�����" << endl;
	cin >> location >> num;
	InsertData(L1, location, num);
	num = GetData(L1);//���Ԫ��
	cout << "����������" << num << "��Ԫ��" << endl;
	cout << endl;

	cout << "����ִ��ɾ����������������Ҫɾ����λ��" << endl;
	cin >> location;
	DeleteData(L1, location);
	num = GetData(L1);//���Ԫ��
	cout << "����������" << num << "��Ԫ��" << endl;
	cout << endl;

	cout << "����ִ�л���ض�λ�����ݣ���������Ҫ��ȡ��λ��" << endl;
	cin >> location;
	GetData(L1, location);
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
	system("cls");//����
	return ok;
}

int GetData(LinkList& L) {//���Ԫ��ͬʱ�����ж���Ԫ��
	int i = 0;
	LinkList p;
	p = L->next;//��ǰָ����һ����ַ��Ԫ�أ���Ȼָ����ǿսڵ㡣
	cout << "�������ݣ�";
	while (p!=NULL)
	{
		cout << p->data <<'\t';//��ȡ�����������
		p = p->next;//ָ����һ��
		i++;//�����ж���Ԫ��
	}
	return i;
}

int InsertData(LinkList& L, int location, int num) {//��locationλ�ò�������
	LinkList p,L1;
	p = L;//��pָ����head��������
	L1 = (LinkList)malloc(sizeof(LNode));//���½ڵ��¿ռ�
	for (int i = 1; i < location; i++) {//pһֱ����Ҫ�½��ڵ��λ�ò�ֹͣ
		p = p->next;
	}
	L1->data = num;//�����ݴ��浽�½ڵ�
	L1->next = p->next;//��һ������pָ����һ�����ݵ�ָ���L1����L1ָ����һ�����ݣ�����β��
	p->next = L1;//�ڶ�����pָ�����һ������ΪL1������ͷ��
	return ok;//���ˣ���ɲ���
}

int DeleteData(LinkList& L, int location) {//��locationλ��ɾ������
	LinkList p,L1;
	p = L;//��pָ����head��������
	L1 = p;
	for (int i = 0; i < location; i++) {//pһֱ����Ҫɾ���Ľڵ�λ�ò�ֹͣ
		L1 = p;
		p = p->next;
	}
	L1->next = p->next;//L1��p����һ��λ�ã���������ֱ����L1ֱ������p����һ������p�޴���ȥ
	p->next = NULL;//��һ�����Բ�д������Ϊ����p�����������׵㣬��д����
	return ok;
}
int GetData(LinkList& L, int location) {//����ض�λ�õ�����
	LinkList p;
	p = L;
	for (int i = 0; i < location; i++) {//pһֱ����Ҫɾ���Ľڵ�λ�ò�ֹͣ
		p = p->next;
	}
	cout << "�ڵ�" << location << "λ������Ϊ" << p->data << endl;
	return ok;
}