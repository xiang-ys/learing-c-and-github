//#include<iostream>
//#include<stdlib.h>
//#define ElemType int
//#define ok 1
//#define on 0
//using namespace std;
//
//typedef struct DoubleNode {//����˫����
//	ElemType data;
//	DoubleNode* next;
//	DoubleNode* prior;
//}DuLNode, * DuLinkList;
//
//int InitList(DuLinkList& L);//��ʼ��˫����
//int input(DuLinkList& L, int size);//�������
//int ListTraver(DuLinkList& L);//����˫����ͬʱ���㳤�� 
//int ListInsert(DuLinkList& L, int num, int data);//������� 
//int ListDelete(DuLinkList& L, int size);//ɾ������ 
//int GetData(DuLinkList& L, int num);//����ض�λ������
//int clearDuLinkList(DuLinkList& L);//���˫����(����ͷ���)
//
//int main() {
//	ElemType num, size;
//	DuLinkList L1;
//	InitList(L1);
//	cout << "�Ѿ�����˫������������Ҫ��������ݳ���" << endl;
//	cin >> size;
//	input(L1, size);
//	cout << "����Ϊ" << ListTraver(L1) << endl;//����������ͬʱ������� 
//
//	cout << "���ڽ��в����������������Ҫ��������ֺ�λ�ã���˳��" << endl;
//	cin >> num >> size;
//	ListInsert(L1, num, size);
//	cout << "����Ϊ" << ListTraver(L1) << endl;//����������ͬʱ������� 
//
//	cout << "���ڽ���ɾ����������������Ҫɾ����λ��" << endl;
//	cin >> size;
//	ListDelete(L1, size);
//	cout << "����Ϊ" << ListTraver(L1) << endl;//����������ͬʱ������� 
//
//	cout << "���ڽ��в����ض�λ�����ݲ�������������Ҫ���ҵ�λ��" << endl;
//	cin >> num;
//	GetData(L1, num);
//	cout << "����Ϊ" << ListTraver(L1) << endl;//����������ͬʱ������� 
//
//	system("pause");
//	cout << "���ڽ�������������ݲ���" << endl;
//	clearDuLinkList(L1);
//	cout << "����Ϊ" << ListTraver(L1) << endl;//����������ͬʱ�������
//	return 0;
//}
//
//int InitList(DuLinkList& L) {//��ʼ��˫����
//	L = (DuLinkList)malloc(sizeof(DuLNode));
//	if (!L)exit(0);
//	L->next = L;//ͷ������һ��ָ���Լ� 
//	L->prior = L;//ͷ������һ��ָ���Լ� 
//	return ok;
//}
//
//int input(DuLinkList& L, int size) {//�������
//	ElemType n;
//	DuLinkList p, L1;
//	p = L;
//	for (int i = 0; i < size; i++) {
//		L1 = (DuLinkList)malloc(sizeof(DuLNode));
//		cout << "����������" << endl;
//		cin >> n;
//		L1->data = n;//�Ƚ����ݴ���L1 
//		p->next = L1;//p����һ��ָ��L1 
//		L1->next = L1;//L1����һ��û��ָ�ˣ�ָ���Լ�Ҳ��.
//		L1->prior = p;//L1����һ��ָ��p 
//		p = p->next;//pָ����һ�����Լ��������һ�����������
//	}
//	return ok;
//}
//
//int ListTraver(DuLinkList& L) {//����˫����ͬʱ���㳤�� 
//	int size = 0;//���� 
//	DuLinkList p;
//	p = L;
//	if ((p->next) == p)cout << "������ͷ��㣬�����޽ڵ�";
//	while ((p->next) != p) {//ֱ��p����һ��ָ���Լ���ʱ����� 
//		p = p->next;
//		cout << p->data << " ";
//		size++;
//	}
//	return size;
//}
//
//int ListInsert(DuLinkList& L, int num, int data) {//������� 
//	DuLinkList p, L1;
//	p = L;
//	for (int i = 1; i < num; i++) {//��pѭ��������Ҫ����Ľڵ��ǰһ��λ�� 
//		p = p->next;
//	}
//	L1 = (DuLinkList)malloc(sizeof(DuLNode));
//	L1->data = data;//�������� 
//	L1->next = p->next;//L1����һ��ָ��p����һ�� 
//	p->next = L1;//p����һ��ָ��L1 
//	L1->prior = p;//L1����һ��ָ��p 
//	L1->next->prior = L1; //L1����һ������һ��ָ��L1,����˫������ 
//	return ok;
//}
//
//int ListDelete(DuLinkList& L, int size) {//ɾ������ 
//	DuLinkList Q, p;
//	p = L->next;
//	Q = p;
//	for (int i = 1; i < size; i++) {//��pѭ��������Ҫɾ���Ľڵ�λ�ã�QΪǰһ��qǰһ���ڵ� 
//		Q = p;
//		p = p->next;
//	}
//	Q->next = p->next; //Q����һ��ָ��p����һ�������ɾ����û��ָ��ָ��p 
//	Q->next->prior = Q; //��Q����һ������һ��ָ��Q�����˫���� 
//	delete(p);//ɾ���ڵ㣬����ռ�� 
//	return ok;
//}
//
//int GetData(DuLinkList& L, int num) {//����ض�λ�õ�����
//	DuLinkList p;
//	p = L;
//	for (int i = 0; i < num; i++) {//pһֱ����Ҫɾ���Ľڵ�λ�ò�ֹͣ
//		p = p->next;
//	}
//	cout << "�ڵ�" << num << "λ������Ϊ" << p->data << endl;
//	return ok;
//}
//int clearDuLinkList(DuLinkList& L) {
//	DuLinkList p,Q;
//	p = L->next;//���Ҫ����ͷ���L�ĳ�L->next;
//	while ((p->next) != p) {//��������Ӳ��ţ���һ�������Ľڵ� 
//		Q = p;
//		p = p->next;
//		free(Q);
//	}
//	free(p);//������һ���ڵ�
//	L->next = L;
//	return ok;
//}