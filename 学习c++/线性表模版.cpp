#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define ElemType int
#define ListsizeMax 100//��ʼ�ռ������
#define Listtncrement 10//�ռ��������
using namespace std;
typedef struct {//���Ա�Ľṹ��
	ElemType* elem;//��ַ
	int lenght;//��ǰ�ĳ���
	int listsize;//��ǰ���洢����
}SqList;

int InitList(SqList& L) {//��ʼ�����Ա�
	L.elem = (ElemType*)malloc(ListsizeMax * sizeof(ElemType));//����100����λ�Ŀռ�
	if (!L.elem)exit(0);//����ʧ�ܽ�������
	L.lenght = 0;
	L.listsize = ListsizeMax;
	return 1;
}

void input(SqList& L, int num) {//������Ա��е�����
	L.lenght = num;
	for (int i = 0; i < num; i++) {
		printf("����������Ҫ�������Ա����\n");
		cin >> L.elem[i];
	}
}

void ClearList(SqList& L) {//�������Ա���Ԫ��Ϊ0
	for (int i = 0; i < L.listsize; i++) {
		L.elem[i] = 0;
	}
}

bool ListEmpty(SqList L) {//�ж��Ƿ�Ϊ�ձ�
	int count = 0;
	for (int i = 0; i < L.listsize; i++) {
		if (L.elem[i] != 0) count++;
		else continue;
	}
	if (count == 0) return true;
	else return false;
}

void ListTraverse(SqList L) {//�������Ա�
	for (int i = 0; i < L.lenght; i++) {
		std::cout << L.elem[i] << "   ";
	}
}

int ListLength(SqList L) {//�������Ա���Ԫ�ظ���
	int count = 0;
	for (int i = 0; i < L.lenght; i++) {
		if (L.elem[i] != 0)count++;
	}
	return count;
}

void GetElme(SqList L, int  i, int& e) {//��ȡ��i��Ԫ�ش����e��
	e = L.elem[i];
}

int PriorElem(SqList L, int cur_e, int& next_e) {//����ǰ��
	for (int i = 0; i < L.lenght; i++) {
		if (cur_e == L.elem[i]) {
			if (i == 0) {
				cout << "������󣡷���ʧ�ܣ�" << endl;
				return NULL;
				continue;
			}
			else {
				next_e = L.elem[i - 1];
				return next_e;
			}
		}
		else continue;
	}
}

int NextElem(SqList L, int cur_e, int& next_e) {//���غ��
	for (int i = 0; i < L.lenght; i++) {
		if (cur_e == L.elem[i]) {
			if (i == L.lenght - 1) {
				cout << "������󣡷���ʧ�ܣ�" << endl;
				return NULL;
				break;
			}
			else {
				next_e = L.elem[i + 1];
				return next_e;
			}
		}
		else continue;
	}
}

void ListInsert(SqList& L, int i, int e) {//�ڵ�i��λ��֮ǰ�����µ�Ԫ��,����+1
	L.lenght += 1;
	int j = L.lenght;
	for (j; j > i + 1; j--) {
		L.elem[j - 1] = L.elem[j - 2];
	}
	L.elem[i] = e;
}

void ListDelete(SqList& L, int i, int* num) {//ɾ����i��λ�õ�Ԫ�أ�����-1
	*num = L.elem[i];
	int k = L.lenght - i;
	for (i; i <= k; i++) {
		L.elem[i] = L.elem[i + 1];
	}
	L.lenght -= 1;
}

void DestroyList(SqList& L) {//�������Ա�
	L.lenght = 0;
}

int main() {
	int count = 0;//�������Ա�Ԫ�ظ���
	int length = 0;//��ʼ�����Ա�ռ䳤��
	int i = 0;//��i����
	int e = 0;//���յ�i����
	int next_e = 0;//���շ��ؼ�����
	SqList L;//����һ�����Ա����

	InitList(L);
	cout << "�������ĸ���" << endl;
	cin >> length;
	input(L, length);

	cout << "�ж����Ա��Ƿ�Ϊ�ձ�  ";
	if (ListEmpty(L)) {
		cout << "��" << endl;
	}
	else {
		cout << "��" << endl;
	}

	cout << "�������Ա�:  " << endl;
	ListTraverse(L);

	count = ListLength(L);
	cout << "���Ա���Ԫ�ظ���Ϊ��" << count << endl;
	cout << "������Ҫ�鿴�ĵ�i����" << endl;
	cin >> i;
	GetElme(L, i, e);
	cout << "��" << i << "����Ϊ" << e << endl;

	int cure;//������������
	cout << "����һ����Ҫ����ǰ������" << endl;
	cin >> cure;
	PriorElem(L, cure, next_e);
	cout << "�����Ϊ��" << next_e << endl;

	cout << "����һ����Ҫ���غ�̵���" << endl;
	cin >> cure;
	NextElem(L, cure, next_e);
	cout << "�����Ϊ��" << next_e << endl;

	int x, y;
	cout << "������Ҫ�������" << endl;
	cin >> y;
	cout << "������Ҫ�����λ��" << endl;
	cin >> x;
	ListInsert(L, x, y);
	cout << "�������Ա�:  " << endl;
	ListTraverse(L);

	int j;
	cout << "������Ҫɾ��������λ��" << endl;
	cin >> j;
	int num;
	ListDelete(L, j, &num);
	cout << "��" << num << "��ɾ��" << endl;
	cout << "�������Ա�:  " << endl;
	ListTraverse(L);

	ClearList(L);
	cout << endl;
	cout << "�������Ա��ж����Ա��Ƿ�Ϊ�ձ�  ";
	if (ListEmpty(L)) {
		cout << "��" << endl;
	}
	else {
		cout << "��" << endl;
	}
	DestroyList(L);
	cout << "ִ�н��������Ա��ѱ����٣�";
	return 0;
}