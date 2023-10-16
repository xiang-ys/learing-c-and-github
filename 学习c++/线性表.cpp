//// 学习数据库c++.cpp
///*运行结果：无算法bug，有设置输入边界，超出数据范围会强制结束程序。*/
//#include<stdlib.h>
//#include<iostream>
//#include<Windows.h>
//#define ElemType int    //初始化数据类型 
//#define listsize_MAX 100//初始空间分配量
//#define ok 1
//#define no 0
//using namespace std;
//
//typedef struct {
//	ElemType* elem;//地址 
//	int length;//长度 
//	int listsize; //最大长度 
//}SqList;
//
//int InitList(SqList& L);//线性表初始化
//void input(SqList& L, int num);//添加数据 ,添加次数为num
//void ListOutput(SqList& L);//输出数据
//void InsertData(SqList& L, int location, int num);//插入(Insert)数据
//int GetData(SqList& L, int location);//获得数据
//void DeleteData(SqList& L, int location);//删除数据
//int PreviousData(SqList& L, int location);//获得前驱（上一个数）
//int NextData(SqList& L, int location);//获得后驱（下一个数）
//int ListLength(SqList& L);//检查线性表有多少元素
//void DestroyList(SqList& L);//销毁线性表
//int badData(SqList& L,int num,int a);//输入错误数据
//
//int main() {
//	int num;//数字
//	int location;//位置
//	SqList L1;//定义线性表
//	InitList(L1);//初始化
//	cout << "请输入你要添加多少个数据进去，不得超过100" << endl;
//	cin >> num;//你要添加多少个数据进去
//	if (num > 100 || num<=1)exit(0);//防止溢出
//	input(L1, num);//添加数据
//	system("cls");
//	ListOutput(L1);//输出数据
//	cout << "现在输出线性表有" << ListLength(L1) << "元素" << endl;
//	cout << endl;//分割操作
//	cout << "现在执行插入数据处理，输入你要插入的位置和数据，空格隔开" << endl;
//	cin >> location >> num;
//	InsertData(L1, location, num);
//	badData(L1, location,2);//检查是否超范围
//	ListOutput(L1);//输出数据
//	cout << "现在输出线性表有" << ListLength(L1) << "元素" << endl;
//	cout << endl;//分割操作
//	cout << "现在执行获得特定位置的数据，请输入你想获得数据的位置" << endl;
//	cin >> num;
//	cout << "获得数据为：" << GetData(L1, num) << endl;
//	cout << endl;//分割操作
//	cout << "现在执行获得前驱操作，请输入你想获得的位置" << endl;
//	cin >> num;
//	badData(L1, num,num);
//	cout<<"位置"<< num << "的前驱是" << PreviousData(L1, num) << endl;
//	cout<<endl;//分割操作
//	cout << "现在执行获得后驱操作，请输入你想获得的位置" << endl;
//	cin >> num;
//	badData(L1, num,num);
//	cout << "位置" << num << "的后驱是" << NextData(L1, num) << endl;
//	cout << endl;//分割操作
//	cout << "现在执行删除数据处理，输入你要删除的位置" << endl;
//	cin >> num;
//	DeleteData(L1, num);
//	badData(L1, num,2);//检查是否超范围
//	ListOutput(L1);//输出数据
//	cout << "现在输出线性表有" << ListLength(L1) << "元素" << endl;
//	cout << endl;//分割操作
//	cout << "现在执行销毁线性表，按Enter键执行" << endl;
//	system("pause");
//	system("cls");
//	DestroyList(L1); 
//	cout << "销毁成功！" << endl;
//	ListOutput(L1);//输出数据
//	cout << "现在输出线性表有"<< ListLength(L1) <<"元素"<<endl;
//	return 0;
//}
//
//
//int InitList(SqList& L) {//线性表初始化 
//	L.elem = (ElemType*)malloc(listsize_MAX * sizeof(ElemType));//malloc需要 #include<stdlid.h>
//	if (!L.elem)exit(0);//指针为NULL相当于指针等于零，所以L.elem==NULL则!L.elem为真。exit(0)退出程序
//	L.length = 0;
//	L.listsize = listsize_MAX;
//	return ok;
//}
//
//void input(SqList& L, int num) {//添加数据 ,添加次数为num
//	L.length = num;
//	for (int i = 0; i < L.length; i++) {//一个一个添加
//		cout << "连续输入" << num << "个数字加入数据库,每次只输入一个" << endl;
//		cin >> L.elem[i];
//	}
//}
//
//void ListOutput(SqList& L) {//输出数据
//	cout << "输出数据：";
//	for (int i = 0; i < L.length; i++){//遍历线性表
//		cout << L.elem[i]<<'\t';
//	}
//	cout << endl;
//}
//
//void InsertData(SqList& L,int location,int num) {//插入(Insert)数据
//	L.length++;
//	for (int i = L.length - 1; i >= location; i--) {//在位置(location)后的数据全部往后移一位
//		L.elem[i] = L.elem[i - 1];
//	}
//	L.elem[location - 1] = num;//插入数据,减一是因为以位置开始数，不是索引
//}
//
//int GetData(SqList& L, int location) {//获得特定位置数据
//	while (1) {
//		if (L.length < location) {
//			cout << "获取失败，原因:超出范围！" << endl;
//		}
//		else
//		break;
//	}
//	return L.elem[location - 1];
//}
//
//int PreviousData(SqList& L, int location) {//获得前驱
//	return L.elem[location - 2];
//}
//
//int NextData(SqList& L, int location) {//获得后驱
//	return L.elem[location];
//}
//
//void DeleteData(SqList& L,int location) {//删除数据
//	for (int i = location; i < L.length; i++) {//在位置(location)后的数据全部往前移一位
//		L.elem[i - 1] = L.elem[i];
//	}
//	L.length--;
//}
//
//int ListLength(SqList& L) {//检查线性表有多少元素
//	int num = 0;
//	for (int i = 0; i < L.length; i++) {//遍历
//		if (L.elem[i] != NULL)
//			num++;
//	}
//	return num;
//}
//
//void DestroyList(SqList& L) {//销毁线性表
//	for (int i = 0; i < L.length; i++) {//遍历
//		if (L.elem[i] != NULL)L.elem[i] = NULL;
//	}
//	L.length = 0;
//}
//
//int badData(SqList& L,int num,int a) {//输入错误数据处理
//	if (num > L.length || num <= 0 || a==1 || a==L.length) {
//		system("cls");
//		cout << "你小子怎么能输入错误数据！！！！(▼ヘ▼#)" << endl;
//		Sleep(500);
//		cout << "倒计时5秒后自动爆炸(｡･ω･｡)" << endl;
//		for (int i = 1; i <= 5; i++) {
//			cout << i << "秒" << endl;
//			Sleep(1000);
//		}
//		exit(0);
//	}
//	return ok;
//}