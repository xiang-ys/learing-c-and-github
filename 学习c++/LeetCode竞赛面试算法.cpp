#include<iostream>
#include<random>
#include <chrono>  // ���ڸ߷ֱ���ʱ��
#include<vector>   //���飬���ǿ����Զ��峤��
#include<algorithm>
#include<time.h>
#include<stdlib.h>
using namespace std;

void swap(int a, int b);//ʹ����򽻻�a��bλ��(�������㷨)
int printOddTimeNum1();//��һ��������������������Σ�����������ż����,������
int printOddTimeNum2();//������������������������Σ�����������ż����,������
int generateRandomArray(vector<int>& vec,int maxSize,int maxValue);//������,maxSize��󳤶ȣ�maxValue�������
int process(vector<int>& vec, int L, int R);//�õݹ���vec�����������ֵ,�������鲢����
int process_super(vector<int>& vec, int L, int R);
void merge(vector<int>& vec,int L,int M,int R);
template<typename T>
void generateRandomVector(std::vector<T>& vec, int maxSize, T minValue, T maxValue);//���еĶ�����

int main() {
	/*int a, b;
	cout << "����������������ʹ�������н���" << endl;
	cin >> a >> b;
	swap(a, b);
	cout << printOddTimeNum1()<<endl;
	printOddTimeNum2();*/
	vector<int> vec1,vec2;
	for (int i = 0; i < 1000; i++) {
		generateRandomArray(vec1, 10, 20);
		vec2 = vector<int>(vec1.size(), -1);
		copy(vec1.begin(), vec1.end(), vec2.begin());//vec2����vec1
		process_super(vec1, 0, vec1.size() - 1);
		for (int num : vec1) {//����vec1
			cout << num << " ";
		}
		/*cout << "���ֵΪ"<<process(vec1, 0, vec1.size()-1);*/
		cout << "\n";
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
	static uniform_int_distribution<unsigned> u(1, maxValue);//�����������������������,���������ֵ
	static uniform_int_distribution<unsigned> n(1, maxSize); //������󳤶�
	int size = n(e);
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
//vec[L..R]��Χ�����ֵ
int process(vector<int>& vec, int L, int R) {
	if (L == R) return vec[L];
	int mid = L + ((R - L)>> 1);//�е㣬����һλ���ڳ���2
	int leftMax = process(vec, L, mid);
	int rightMax = process(vec, mid + 1, R);
	return leftMax < rightMax ? rightMax : leftMax;
}
//vec[L..R]��Χ����
int process_super(vector<int>& vec, int L, int R) {
	if (L == R) return vec[L];
	int mid = L + ((R - L) >> 1);//�е㣬����һλ���ڳ���2
	process(vec, L, mid);
	process(vec, mid + 1, R);
	merge(vec, L, mid, R);
}
//�鲢����������
void merge(vector<int>& vec, int L, int M, int R) {
	vector<int> vecHelp(vec.size(), -1);
	auto it = vecHelp.begin();
	int p1 = L;
	int p2 = M + 1;
	while (p1 <= M && p2 <= R){
		*(it++) = vec[p1++] <= vec[p2++] ? vec[p2++] : vec[p1++];
	}
	while (p1 <= M){
		*(it++) = vec[p2++];
	}
	while (p2 <= R) {
		*(it++) = vec[p1++];
	}
	copy(vecHelp.begin(), vecHelp.end(), vec.begin());
}