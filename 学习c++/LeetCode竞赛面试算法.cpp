#include<iostream>
using namespace std;

void swap(int a, int b);//ʹ����򽻻�a��bλ��(�������㷨)
int printOddTimeNum1();//��һ��������������������Σ�����������ż����,������
int printOddTimeNum2();//������������������������Σ�����������ż����,������
int main() {
	int a, b;
	cout << "����������������ʹ�������н���" << endl;
	cin >> a >> b;
	swap(a, b);
	cout << printOddTimeNum1()<<endl;
	printOddTimeNum2();
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