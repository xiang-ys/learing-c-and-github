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
		cout << "用户名正确";
	}break;
	default:
		cout << "用户名不正确";
		break;
	}
}