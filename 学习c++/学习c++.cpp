// 学习c++.cpp
#include <iostream>
#include<stdio.h>

using namespace std;

/*int add(int x, int y) {
	return x + y;
}

int main()
{
	int a = 10;
	int b = 20;
	int sum = add(a, b);
	cout << a << "与" << b << "的和为" << sum;
	return 0;
}


void swap(int& a, int& b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void swap2(int* a, int* b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a, b, c, d;
	printf("输入两个数\n");
	scanf_s("%d %d", &a, &b);
	swap(a, b);
	printf("交换后的结果为%d, %d", a, b);
	printf("再输入两个数\n");
	scanf_s("%d %d",&c,&d);
	swap2(&c, &d);
	printf("交换后的结果为%d, %d", c, d);
}
*/

typedef struct fushu {
	float re;
	float mag;
};
fushu add(fushu a,fushu b) {
	fushu sum;
	sum.re = a.re + b.re;
	sum.mag = a.mag + b.mag;
	printf("相加后的复数为%.2f+%.2fi\n", sum.re, sum.mag);
	return sum;
}
fushu jian(fushu a, fushu b) {
	fushu sum;
	sum.re = a.re - b.re;
	sum.mag = a.mag - b.mag;
	printf("相减后的复数为%.2f+%.2fi\n", sum.re, sum.mag);
	return sum;
}
fushu cheng(fushu a, fushu b) {
	fushu sum;
	sum.re = (a.re * b.re) - (a.mag * b.mag);
	sum.mag = (a.mag * b.re) + (a.re * b.mag);
	printf("相乘后的复数为%.2f+%.2fi\n", sum.re, sum.mag);
	return sum;
}
fushu chu(fushu a, fushu b) {
	fushu sum;
	sum.re = ((a.re * b.re) + (a.mag * b.mag))
		/ ((b.re) * (b.re) + (b.mag) * (b.mag));
	sum.mag = ((a.mag * b.re) - (a.re) * (b.mag))
		/ ((b.re) * (b.re) + (b.mag) * (b.mag));
	printf("相除后的复数为%.2f+%.2fi\n", sum.re, sum.mag);
	return sum;
}
void printffushu(fushu a) {
	printf("%.2f+%.2fi\n", a.re, a.mag);
}
int main()
{
	fushu f1,f2;
	f1.re = 12.34;
	f1.mag = 45.23;
	f2.re = 25.36;
	f2.mag = 12.56;
	fushu sum;
	fushu shang;
	fushu ji;
	fushu cha;
	printffushu(f1);
	printffushu(f2);
	sum = add(f1, f2);
	cha = jian(f1, f2);
	ji = cheng(f1, f2);
	shang = chu(f1, f2);
	return 0;
}