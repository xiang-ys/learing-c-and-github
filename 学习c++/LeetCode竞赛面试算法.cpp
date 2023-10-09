#include<iostream>
#include<random>
#include <chrono>  // ���ڸ߷ֱ���ʱ��
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

void swap(int a, int b);//ʹ����򽻻�a��bλ��(�������㷨)
int printOddTimeNum1();//��һ��������������������Σ�����������ż����,������
int printOddTimeNum2();//������������������������Σ�����������ż����,������
int generateRandomArray(vector<int>& vec,int maxSize,int maxValue);//������
template<typename T>
void generateRandomVector(std::vector<T>& vec, int maxSize, T minValue, T maxValue);//���еĶ�����

int main() {
	/*int a, b;
	cout << "����������������ʹ�������н���" << endl;
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

void swap(int a, int b) {//ʹ����򽻻�a��bλ��
	/*�������������
    a^a=0;0^a=a;*/
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << a << " " << b << endl;
}

//��һ�����ֳ��������Σ�����������ż����
int printOddTimeNum1() {
	int arr[] = { 1,1,1,1,2,2,2,3,3,3,3 };
	int eor = 0;
	for (int pro : arr) {
		eor ^= pro;
	}
	return eor;
}
//���������ֳ��������Σ�����������ż����
int printOddTimeNum2() {
	/*��ȡ�����ұ�һλ��1��������һλ��a��b����Ϊ���飬��Ϊ��һλ��a^b��ͬλ�õ��ģ�
	��Ȼ����ͬ��
	���Կ���ͨ���������е�ÿһ������=0�����������е�ÿһλ���=1�����ֳ�����*/
	int arr[] = { 1,1,1,1,2,2,2,3,3,3,3,4,4,4 };
	int eor = 0;
	for (int pro : arr) {
		eor ^= pro;
	}
	int rightOne = eor & (~eor + 1);//��ȡ��eor�ڶ��������ұߵ�1��~ȡ����&����ͬ��Ϊ0��
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

int generateRandomArray(vector<int>& vec,int maxSize, int maxValue) {//���Ը���д�Ķ�������ֻ�����ǶԴ��е�׾��ģ�°���
	unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> u(0, maxValue);//�����������������������
	int size = u(e);
	vec = vector<int>(size, -1);//����Ϊsize������λ�ø�ֵ-1
	for (auto it = vec.begin(); it != vec.end(); ++it) {//it��һ��������������ѭ�����ƶ���ָ�� vec ��ÿһ��Ԫ�ء�
		*it = u(e);
		/* *it ���ڷ��� it ��ǰָ���Ԫ�ص�ֵ��*/
	}
	return 0;
}

template<typename T>
void generateRandomVector(vector<T>& vec, int maxSize, T minValue, T maxValue) {//��Ĵ���д�Ķ�����
	assert(maxValue > minValue);    // assert
	srand((unsigned int)time(nullptr)); // include<ctime>
	int size = rand() % maxSize + 1;  // [1, maxsize]
	vec = std::vector<T>(size, -1);   //initialization with -1
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		*it = rand() % (maxValue - minValue) + minValue + 1; // [minvalue + 1, maxValue]
	}
	return;
}