//#include<iostream>
//#include<stdlib.h>
//#define MAXSIZE 100
//#define ElemType int
//
//using namespace std;
//
//struct StackNode //这是放入栈的结构体
//{
//	ElemType data;
//	StackNode* next;
//};
//
//struct Stack //将栈底指针和栈顶指针写入一个结构体
//{
//	StackNode* bottom;
//	StackNode* top;
//};
//
//int InitStack(Stack& S); //初始化栈
//bool IsEmpty(Stack& S);//判断为空
//int Push(Stack& S, ElemType x); //入栈
//int Pop(Stack& S, ElemType& x);//出栈
//int printStrck(Stack& S);//遍历栈
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
//	cout << "出栈数据" << x << endl;
//	printStrck(S1);
//	return 0;
//}
//
//int InitStack(Stack& S) {//初始化栈
//	S.top = S.bottom = NULL;
//	return 1;
//}
//
//bool IsEmpty(Stack& S) {
//	return S.top == NULL;
//}
//
//int Push(Stack& S, ElemType x) { //入栈
//	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
//	if (!newNode)exit(0);
//	newNode->data = x; //存入元素
//	newNode->next = S.top; //入栈的下一个节点指向栈顶，也就是指向之前的栈顶
//	S.top = newNode; //现在新入栈的节点为栈顶
//	return 1;
//}
//
//int Pop(Stack& S, ElemType& x) {//出栈
//	if (IsEmpty(S))exit(0);
//	StackNode* p;
//	p = S.top;
//	x = p->data;
//	S.top = p->next;
//	free(p);
//	if (S.top == NULL) {
//		S.bottom = NULL; // 如果栈为空，重置栈底
//	}
//	return 1;
//}
//
//int printStrck(Stack& S) {//遍历栈
//	StackNode* p;
//	p = S.top;
//	cout << "栈顶到栈底为：";
//	while (p != S.bottom){
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//	return 1;
//}