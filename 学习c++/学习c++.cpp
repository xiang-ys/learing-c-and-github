﻿//// 学习数据库c++.cpp
#include<stdlib.h>
#include<iostream>
#define ElemType int    //初始化数据类型 
#define listsize_MAX 100//初始空间分配量
#define ok 1
#define no 0
using namespace std;

typedef struct {
	ElemType* elem;//地址 
	int length;//长度 
	int listsize; //最大长度 
}SqList;

int InitList(SqList& L);//线性表初始化
void input(SqList& L, int num);//添加数据 ,添加次数为num
void ListOutput(SqList& L);//输出数据
void InsertData(SqList& L, int location, int num);//插入(Insert)数据
void DeleteData(SqList& L, int location);//删除数据

int main() {
	int num;//数字
	int location;//位置
	SqList L1;//定义线性表
	InitList(L1);//初始化
	cout << "请输入你要添加多少个数据进去，不得超过100" << endl;
	cin >> num;//你要添加多少个数据进去
	input(L1, num);//添加数据
	ListOutput(L1);//输出数据

	cout << "现在执行插入数据处理，输入你要插入的位置和数据，空格隔开" << endl;
	cin >> location >> num;
	InsertData(L1, location, num);
	ListOutput(L1);//输出数据

	cout << "现在执行删除数据处理，输入你要删除的位置" << endl;
	cin >> num;
	DeleteData(L1, num);
	ListOutput(L1);//输出数据
	return 0;
}


int InitList(SqList& L) {//线性表初始化 
	L.elem = (ElemType*)malloc(listsize_MAX * sizeof(ElemType));//malloc需要 #include<stdlid.h>
	if (!L.elem)exit(0);//指针为NULL相当于指针等于零，所以L.elem==NULL则!L.elem为真
	L.length = 0;
	L.listsize = listsize_MAX;
	return ok;
}

void input(SqList& L, int num) {//添加数据 ,添加次数为num
	L.length = num;
	for (int i = 0; i < L.length; i++) {//一个一个添加
		cout << "连续输入" << num << "个数字加入数据库,每次只输入一个" << endl;
		cin >> L.elem[i];
	}
}

void ListOutput(SqList& L) {//输出数据
	cout << "输出数据" << endl;
	for (int i = 0; i < L.length; i++){//遍历线性表
		cout << L.elem[i]<<'\t';
	}
	cout << endl;
}

void InsertData(SqList& L,int location,int num) {//插入(Insert)数据
	L.length++;
	for (int i = L.length - 1; i >= location; i--) {//在位置(location)后的数据全部往后移一位
		L.elem[i] = L.elem[i - 1];
	}
	L.elem[location - 1] = num;//插入数据,减一是因为以位置开始数，不是索引
}

void DeleteData(SqList& L,int location) {//删除数据
	L.length--;
	for (int i = location; i <=L.length; i++) {//在位置(location)后的数据全部往前移一位
		L.elem[i - 1] = L.elem[i];
	}
}