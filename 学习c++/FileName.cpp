#include<iostream>
#include<string>
using namespace std;
int main() {
	int i;
	string name;
	cin >> name;
	if (name == "xiang-ys") {
		i = 1;
	}
	else
		i = 0;
	switch (i) {
	case 1: {
		cout << "�û�����ȷ";
	}break;
	default:
		cout << "�û�������ȷ";
		break;
	}
}