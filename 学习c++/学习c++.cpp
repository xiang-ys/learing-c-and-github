//// 学习c++.cpp
//#include <iostream>
//#include<stdio.h>
//
//using namespace std;
//
//int add(int x, int y) {
//	return x + y;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = add(a, b);
//	cout << a << "与" << b << "的和为" << sum;
//	return 0;
//}
//
//
//void swap(int& a, int& b) {
//	int temp = 0;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//void swap2(int* a, int* b) {
//	int temp = 0;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main() {
//	int a, b, c, d;
//	printf("输入两个数\n");
//	scanf_s("%d %d", &a, &b);
//	swap(a, b);
//	printf("交换后的结果为%d, %d", a, b);
//	printf("再输入两个数\n");
//	scanf_s("%d %d",&c,&d);
//	swap2(&c, &d);
//	printf("交换后的结果为%d, %d", c, d);
//}
//
//
//typedef struct fushu {
//	float re;
//	float mag;
//};
//fushu add(fushu a,fushu b) {
//	fushu sum;
//	sum.re = a.re + b.re;
//	sum.mag = a.mag + b.mag;
//	printf("相加后的复数为%.2f+%.2fi\n", sum.re, sum.mag);
//	return sum;
//}
//fushu jian(fushu a, fushu b) {
//	fushu sum;
//	sum.re = a.re - b.re;
//	sum.mag = a.mag - b.mag;
//	printf("相减后的复数为%.2f+%.2fi\n", sum.re, sum.mag);
//	return sum;
//}
//fushu cheng(fushu a, fushu b) {
//	fushu sum;
//	sum.re = (a.re * b.re) - (a.mag * b.mag);
//	sum.mag = (a.mag * b.re) + (a.re * b.mag);
//	printf("相乘后的复数为%.2f+%.2fi\n", sum.re, sum.mag);
//	return sum;
//}
//fushu chu(fushu a, fushu b) {
//	fushu sum;
//	sum.re = ((a.re * b.re) + (a.mag * b.mag))
//		/ ((b.re) * (b.re) + (b.mag) * (b.mag));
//	sum.mag = ((a.mag * b.re) - (a.re) * (b.mag))
//		/ ((b.re) * (b.re) + (b.mag) * (b.mag));
//	printf("相除后的复数为%.2f+%.2fi\n", sum.re, sum.mag);
//	return sum;
//}
//void printffushu(fushu a) {
//	printf("%.2f+%.2fi\n", a.re, a.mag);
//}
//int main()
//{
//	fushu f1,f2;
//	f1.re = 12.34;
//	f1.mag = 45.23;
//	f2.re = 25.36;
//	f2.mag = 12.56;
//	fushu sum;
//	fushu shang;
//	fushu ji;
//	fushu cha;
//	printffushu(f1);
//	printffushu(f2);
//	sum = add(f1, f2);
//	cha = jian(f1, f2);
//	ji = cheng(f1, f2);
//	shang = chu(f1, f2);
//	return 0;
//}

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

int InitList(SqList& L) {//线性表初始化 
	L.elem = (ElemType*)malloc(listsize_MAX * sizeof(ElemType));//malloc需要 #include<stdlid.h>
	if (!L.elem)exit(0);//指针为NULL相当于指针等于零，所以L.elem==NULL则!L.elem为真
	L.length = 0;
	L.listsize = listsize_MAX;
	return ok;
}

void add(SqList& L, int num) {//添加数据 ,添加次数为num 
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
}



int main() {
	int num;//定义添加多少个数据
	SqList L1;//定义线性表
	InitList(L1);//初始化
	cout << "请输入你要添加多少个数据进去，不得超过100" << endl;
	cin >> num;//你要添加多少个数据进去
	add(L1, num);//添加数据
	ListOutput(L1);//输出数据
	return 0;
}