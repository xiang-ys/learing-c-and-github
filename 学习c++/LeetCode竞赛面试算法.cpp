#include<iostream>
#include<random>
#include <chrono>  // 用于高分辨率时钟
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

void swap(int a, int b);//使用异或交换a，b位置(抖机灵算法)
int printOddTimeNum1();//有一个数字在数组出现奇数次，其他都出现偶数次,求奇数
int printOddTimeNum2();//有两个数字在数组出现奇数次，其他都出现偶数次,求奇数
int generateRandomArray(vector<int>& vec,int maxSize,int maxValue);//对数器
template<typename T>
void generateRandomVector(std::vector<T>& vec, int maxSize, T minValue, T maxValue);//大佬的对数器

int main() {
	/*int a, b;
	cout << "请输入两个数，将使用异或进行交换" << endl;
	cin >> a >> b;
	swap(a, b);
	cout << printOddTimeNum1()<<endl;
	printOddTimeNum2();*/
	vector<int> vec1;
	for (int i = 0; i < 100; i++) {
		generateRandomArray(vec1, 10, 50);
		for (int num : vec1) {
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}

void swap(int a, int b) {//使用异或交换a，b位置
	/*异或语句基本规则
    a^a=0;0^a=a;*/
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << a << " " << b << endl;
}

//有一个数字出现奇数次，其他都出现偶数次
int printOddTimeNum1() {
	int arr[] = { 1,1,1,1,2,2,2,3,3,3,3 };
	int eor = 0;
	for (int pro : arr) {
		eor ^= pro;
	}
	return eor;
}
//有两个数字出现奇数次，其他都出现偶数次
int printOddTimeNum2() {
	/*提取出最右边一位是1，根据这一位把a和b区分为两组，因为这一位是a^b相同位得到的，
	必然不相同，
	所以可以通过与数组中的每一个相与=0或者与数组中的每一位异或=1来区分成两组*/
	int arr[] = { 1,1,1,1,2,2,2,3,3,3,3,4,4,4 };
	int eor = 0;
	for (int pro : arr) {
		eor ^= pro;
	}
	int rightOne = eor & (~eor + 1);//提取出eor在二进制最右边的1，~取反，&不相同的为0；
	cout << rightOne << endl;
	int onlyOne = 0;
	for (int cur : arr) {
		if ((cur &  rightOne) == 0) {
			onlyOne ^= cur;
		}
	}
	cout << onlyOne << " " << (eor ^ onlyOne);
	
	return eor;
}

int generateRandomArray(vector<int>& vec,int maxSize, int maxValue) {//我自个儿写的对数器，只不过是对大佬的拙劣模仿罢了
	unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> u(0, maxValue);//这个是随机数引擎生成随机数
	int size = u(e);
	vec = vector<int>(size, -1);//长度为size，所有位置赋值-1
	for (auto it = vec.begin(); it != vec.end(); ++it) {//it是一个迭代器，它在循环中移动，指向 vec 的每一个元素。
		*it = u(e);
		/* *it 用于访问 it 当前指向的元素的值。*/
	}
	return 0;
}

template<typename T>
void generateRandomVector(vector<T>& vec, int maxSize, T minValue, T maxValue) {//别的大佬写的对数器
	assert(maxValue > minValue);    // assert
	srand((unsigned int)time(nullptr)); // include<ctime>
	int size = rand() % maxSize + 1;  // [1, maxsize]
	vec = std::vector<T>(size, -1);   //initialization with -1
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		*it = rand() % (maxValue - minValue) + minValue + 1; // [minvalue + 1, maxValue]
	}
	return;
}