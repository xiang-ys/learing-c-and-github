#include<iostream>
using namespace std;

void swap(int a, int b);//使用异或交换a，b位置(抖机灵算法)
int printOddTimeNum1();//有一个数字在数组出现奇数次，其他都出现偶数次,求奇数
int printOddTimeNum2();//有两个数字在数组出现奇数次，其他都出现偶数次,求奇数
int main() {
	int a, b;
	cout << "请输入两个数，将使用异或进行交换" << endl;
	cin >> a >> b;
	swap(a, b);
	cout << printOddTimeNum1()<<endl;
	printOddTimeNum2();
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