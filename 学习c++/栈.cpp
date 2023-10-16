//#include<iostream>
//#include<stdlib.h>
//#define MAXSIZE 100
//#define ElemType int
//
//using namespace std;
//
//struct StackNode //���Ƿ���ջ�Ľṹ��
//{
//	ElemType data;
//	StackNode* next;
//};
//
//struct Stack //��ջ��ָ���ջ��ָ��д��һ���ṹ��
//{
//	StackNode* bottom;
//	StackNode* top;
//};
//
//int InitStack(Stack& S); //��ʼ��ջ
//bool IsEmpty(Stack& S);//�ж�Ϊ��
//int Push(Stack& S, ElemType x); //��ջ
//int Pop(Stack& S, ElemType& x);//��ջ
//int printStrck(Stack& S);//����ջ
//
//int main() {
//	ElemType x;
//	Stack S1;
//	InitStack(S1);
//	Push(S1, 1);
//	Push(S1, 12);
//	Push(S1, 133);
//	printStrck(S1);
//	Pop(S1,x);
//	cout << "��ջ����" << x << endl;
//	printStrck(S1);
//	return 0;
//}
//
//int InitStack(Stack& S) {//��ʼ��ջ
//	S.top = S.bottom = NULL;
//	return 1;
//}
//
//bool IsEmpty(Stack& S) {
//	return S.top == NULL;
//}
//
//int Push(Stack& S, ElemType x) { //��ջ
//	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
//	if (!newNode)exit(0);
//	newNode->data = x; //����Ԫ��
//	newNode->next = S.top; //��ջ����һ���ڵ�ָ��ջ����Ҳ����ָ��֮ǰ��ջ��
//	S.top = newNode; //��������ջ�Ľڵ�Ϊջ��
//	return 1;
//}
//
//int Pop(Stack& S, ElemType& x) {//��ջ
//	if (IsEmpty(S))exit(0);
//	StackNode* p;
//	p = S.top;
//	x = p->data;
//	S.top = p->next;
//	free(p);
//	if (S.top == NULL) {
//		S.bottom = NULL; // ���ջΪ�գ�����ջ��
//	}
//	return 1;
//}
//
//int printStrck(Stack& S) {//����ջ
//	StackNode* p;
//	p = S.top;
//	cout << "ջ����ջ��Ϊ��";
//	while (p != S.bottom){
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//	return 1;
//}