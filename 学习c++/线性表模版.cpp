#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define ElemType int
#define ListsizeMax 100//初始空间分配量
#define Listtncrement 10//空间分配增量
using namespace std;
typedef struct {//线性表的结构体
	ElemType* elem;//地址
	int lenght;//当前的长度
	int listsize;//当前最大存储容量
}SqList;

int InitList(SqList& L) {//初始化线性表
	L.elem = (ElemType*)malloc(ListsizeMax * sizeof(ElemType));//分配100个单位的空间
	if (!L.elem)exit(0);//分配失败结束进程
	L.lenght = 0;
	L.listsize = ListsizeMax;
	return 1;
}

void input(SqList& L, int num) {//添加线性表中的数据
	L.lenght = num;
	for (int i = 0; i < num; i++) {
		printf("连续输入需要放入线性表的数\n");
		cin >> L.elem[i];
	}
}

void ClearList(SqList& L) {//重置线性表中元素为0
	for (int i = 0; i < L.listsize; i++) {
		L.elem[i] = 0;
	}
}

bool ListEmpty(SqList L) {//判断是否为空表
	int count = 0;
	for (int i = 0; i < L.listsize; i++) {
		if (L.elem[i] != 0) count++;
		else continue;
	}
	if (count == 0) return true;
	else return false;
}

void ListTraverse(SqList L) {//遍历线性表
	for (int i = 0; i < L.lenght; i++) {
		std::cout << L.elem[i] << "   ";
	}
}

int ListLength(SqList L) {//计算线性表中元素个数
	int count = 0;
	for (int i = 0; i < L.lenght; i++) {
		if (L.elem[i] != 0)count++;
	}
	return count;
}

void GetElme(SqList L, int  i, int& e) {//获取第i个元素存放在e中
	e = L.elem[i];
}

int PriorElem(SqList L, int cur_e, int& next_e) {//返回前驱
	for (int i = 0; i < L.lenght; i++) {
		if (cur_e == L.elem[i]) {
			if (i == 0) {
				cout << "输入错误！返回失败！" << endl;
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

int NextElem(SqList L, int cur_e, int& next_e) {//返回后继
	for (int i = 0; i < L.lenght; i++) {
		if (cur_e == L.elem[i]) {
			if (i == L.lenght - 1) {
				cout << "输入错误！返回失败！" << endl;
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

void ListInsert(SqList& L, int i, int e) {//在第i个位置之前插入新的元素,长度+1
	L.lenght += 1;
	int j = L.lenght;
	for (j; j > i + 1; j--) {
		L.elem[j - 1] = L.elem[j - 2];
	}
	L.elem[i] = e;
}

void ListDelete(SqList& L, int i, int* num) {//删除第i个位置的元素，长度-1
	*num = L.elem[i];
	int k = L.lenght - i;
	for (i; i <= k; i++) {
		L.elem[i] = L.elem[i + 1];
	}
	L.lenght -= 1;
}

void DestroyList(SqList& L) {//销毁线性表
	L.lenght = 0;
}

int main() {
	int count = 0;//接收线性表元素个数
	int length = 0;//初始化线性表空间长度
	int i = 0;//第i个数
	int e = 0;//接收第i个数
	int next_e = 0;//接收返回计算结果
	SqList L;//创建一个线性表对象

	InitList(L);
	cout << "输入数的个数" << endl;
	cin >> length;
	input(L, length);

	cout << "判断线性表是否为空表：  ";
	if (ListEmpty(L)) {
		cout << "是" << endl;
	}
	else {
		cout << "否" << endl;
	}

	cout << "遍历线性表:  " << endl;
	ListTraverse(L);

	count = ListLength(L);
	cout << "线性表中元素个数为：" << count << endl;
	cout << "输入需要查看的第i个数" << endl;
	cin >> i;
	GetElme(L, i, e);
	cout << "第" << i << "个数为" << e << endl;

	int cure;//输入数的载体
	cout << "输入一个需要返回前驱的数" << endl;
	cin >> cure;
	PriorElem(L, cure, next_e);
	cout << "这个数为：" << next_e << endl;

	cout << "输入一个需要返回后继的数" << endl;
	cin >> cure;
	NextElem(L, cure, next_e);
	cout << "这个数为：" << next_e << endl;

	int x, y;
	cout << "输入需要插入的数" << endl;
	cin >> y;
	cout << "输入需要插入的位置" << endl;
	cin >> x;
	ListInsert(L, x, y);
	cout << "遍历线性表:  " << endl;
	ListTraverse(L);

	int j;
	cout << "输入需要删除的数的位置" << endl;
	cin >> j;
	int num;
	ListDelete(L, j, &num);
	cout << "数" << num << "被删除" << endl;
	cout << "遍历线性表:  " << endl;
	ListTraverse(L);

	ClearList(L);
	cout << endl;
	cout << "重置线性表并判断线性表是否为空表：  ";
	if (ListEmpty(L)) {
		cout << "是" << endl;
	}
	else {
		cout << "否" << endl;
	}
	DestroyList(L);
	cout << "执行结束！线性表已被销毁！";
	return 0;
}