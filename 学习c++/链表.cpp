//#include<iostream>
//#include<stdlib.h>
//#define ElemType int
//#define ok 1
//#define no 0
//using namespace std;
//
//typedef struct ListNode {//初始化链表
//	ElemType data;
//	ListNode* next;
//}LNode, * LinkList;
////1、先说LNode，参照typede的用法，可以得知LNode就是struct ListNode的别名，即ListNode == struct LNode；
////2、再说LinkList，是一个指向该结构体的的指针的别名。
//
//int InitList(LinkList& head);//初始化链表
//int input(LinkList& L, int j);//添加数据(尾插法)
//int headinput(LinkList& L, int j);//添加数据(头插法)
//int GetData(LinkList& L);//获得元素同时计算有多少元素
//int InsertData(LinkList& L, int location, int num);//在location位置插入数据
//int DeleteData(LinkList& L, int location);//在location位置删除数据
//int GetData(LinkList& L, int location);//获得特定位置的数据
//int MegeList(LinkList& L1, LinkList& L2, LinkList& L3); //两个链表整合到L3 
//
//int main() {
//	int num, location;//定义数据和位置
//	LinkList L1, L2, L3;
//	InitList(L1); //初始化链表(创建空链表)
//	cout << "输入你想在链表添加多少数据" << endl;
//	cin >> num;
//	input(L1, num);//添加元素
//	num = GetData(L1);//获得元素
//	cout << "现在链表有" << num << "个元素" << endl;
//	cout << endl;//分割
//
//	cout << "现在执行插入操作，请输入你要插入的位置和数据" << endl;
//	cin >> location >> num;
//	InsertData(L1, location, num);
//	num = GetData(L1);//获得元素
//	cout << "现在链表有" << num << "个元素" << endl;
//	cout << endl;
//
//	cout << "现在执行删除操作，请输入你要删除的位置" << endl;
//	cin >> location;
//	DeleteData(L1, location);
//	num = GetData(L1);//获得元素
//	cout << "现在链表有" << num << "个元素" << endl;
//	cout << endl;
//
//	cout << "现在执行获得特定位置数据，请输入你要获取的位置" << endl;
//	cin >> location;
//	GetData(L1, location);
//	cout << "按下继续下一步操作" << endl;
//	cout << endl;//分割
//	system("pause");
//	system("cls");
//	InitList(L2); //初始化链表(创建空链表)
//	InitList(L3); //初始化链表(创建空链表)
//	cout << "现在创建L2链表，输入你想在链表添加多少数据" << endl;
//	cin >> num;
//	headinput(L2, num);//添加元素
//	num = GetData(L2);//获得元素
//	cout << "现在链表L2有" << num << "个元素" << endl;
//	cout << endl;//分割
//	num = GetData(L1);//获得元素
//	cout << "现在链表L1有" << num << "个元素" << endl;
//	cout << endl;//分割
//	cout << "现在执行将L1和L2拼接的操作" << endl;
//	MegeList(L1, L2, L3);//将L1和L2整合到L3
//	num = GetData(L3);//获得元素
//	cout << "现在链表L3有" << num << "个元素" << endl;
//	cout << endl;//分割
//	return 0;
//}
//
//int InitList(LinkList& head) {//初始化链表
//	head = (LinkList)malloc(sizeof(LNode));
//	if (!head)exit(0);
//	head->next = NULL;
//	return ok;
//}
//
//int input(LinkList& L, int j) {//添加数据
//	LinkList p, L1;//1，创建新节点
//	p = L;//2, 将p指针与head关联起来，这样p的next指向哪里 head的next也指向哪里
//	for (int i = 0; i < j; i++) {
//		L1 = (LinkList)malloc(sizeof(LNode));//3，p的next指向新节点（L1），head的next也指向了L1
//		cout << "输入" << j << "个数字" << endl;
//		cin >> L1->data;//存入数据
//		p->next = L1;//将p和L1连接起来
//		p = L1;//4，p断开与head的链接，与L1关联起来，这样p的next指向哪里，L1的next也指向哪里
//		p->next = NULL;//防止next不经意间指向其他地方
//	}
//	system("cls");//清屏
//	return ok;
//}
//
//int GetData(LinkList& L) {//获得元素同时计算有多少元素
//	int i = 0;
//	LinkList p;
//	p = L->next;//提前指向下一个地址的元素，不然指向的是空节点。
//	cout << "链表数据：";
//	while (p != NULL)
//	{
//		cout << p->data << '\t';//获取并且输出数据
//		p = p->next;//指向下一个
//		i++;//计算有多少元素
//	}
//	return i;
//}
//
//int InsertData(LinkList& L, int location, int num) {//在location位置插入数据
//	LinkList p, L1;
//	p = L;//将p指针与head关联起来
//	L1 = (LinkList)malloc(sizeof(LNode));//给新节点新空间
//	for (int i = 1; i < location; i++) {//p一直到所要新建节点的位置才停止
//		p = p->next;
//	}
//	L1->data = num;//将数据储存到新节点
//	L1->next = p->next;//第一步：将p指向下一个数据的指针给L1，让L1指向下一个数据，连接尾部
//	p->next = L1;//第二步：p指向的下一个数据为L1，连接头部
//	return ok;//至此，完成插入
//}
//
//int DeleteData(LinkList& L, int location) {//在location位置删除数据
//	LinkList p, L1;
//	p = L;//将p指针与head关联起来
//	L1 = p;
//	for (int i = 0; i < location; i++) {//p一直到所要删除的节点位置才停止
//		L1 = p;
//		p = p->next;
//	}
//	L1->next = p->next;//L1在p的上一个位置，这样可以直接让L1直接连接p后面一个，让p无处可去
//	free(p);//这一步可以不写，但是为了让p“死”得明白点，就写上了
//	return ok;
//}
//int GetData(LinkList& L, int location) {//获得特定位置的数据
//	LinkList p;
//	p = L;
//	for (int i = 0; i < location; i++) {//p一直到所要删除的节点位置才停止
//		p = p->next;
//	}
//	cout << "在第" << location << "位的数据为" << p->data << endl;
//	return ok;
//}
//
//int headinput(LinkList& L, int j) {//头插法 
//	LinkList L1;
//	for (int i = 0; i < j; i++) {
//		L1 = (LinkList)malloc(sizeof(LNode));
//		cout << "输入" << j << "个数字" << endl;
//		cin >> L1->data;
//		L1->next = L->next;
//		L->next = L1;
//	}
//	system("cls");//清屏
//	return ok;
//}
//
//int MegeList(LinkList& L1, LinkList& L2, LinkList& L3) {//将L1和L2整和到L3 
//	LinkList p1, p2, p3;//创建3个空节点，辅助整合 
//	p1 = L1->next;//p1指向L1的下一个 
//	p2 = L2->next;//p2指向L2的下一个 
//	p3 = L1;//p3和L1关联 
//	L3 = p3;//p3指向L3的下一个 
//	while (p1 && p2) {
//		if (p1->data <= p2->data) {//如果p1和数据比p2小，将p1的数据整合到p3 
//			p3->next = p1;//p3的下一个为p1的一个结点 
//			p3 = p1;//将p3指向这个节点，为了方便下一次操作在p3后面添加节点 
//			p1 = p1->next;//让p1指向下一个节点，让它参与下一次对比 
//		}
//		else {//如果p2和数据比p1小，将p2的数据整合到p3
//			p3->next = p2;//操作和上面是一个道理 
//			p3 = p2;
//			p2 = p2->next;
//		}
//	}
//	p3->next = p1 ? p1 : p2;
//	free(L2);
//	return ok;
//}