//#include<iostream>
//#include<stdlib.h>
//#define ElemType int
//#define ok 1
//#define on 0
//using namespace std;
//
//typedef struct DoubleNode {//定义双链表
//	ElemType data;
//	DoubleNode* next;
//	DoubleNode* prior;
//}DuLNode, * DuLinkList;
//
//int InitList(DuLinkList& L);//初始化双链表
//int input(DuLinkList& L, int size);//添加数据
//int ListTraver(DuLinkList& L);//遍历双链表同时计算长度 
//int ListInsert(DuLinkList& L, int num, int data);//插入操作 
//int ListDelete(DuLinkList& L, int size);//删除操作 
//int GetData(DuLinkList& L, int num);//获得特定位置数据
//int clearDuLinkList(DuLinkList& L);//清空双链表(保留头结点)
//
//int main() {
//	ElemType num, size;
//	DuLinkList L1;
//	InitList(L1);
//	cout << "已经创建双链表，请输入你要输入的数据长度" << endl;
//	cin >> size;
//	input(L1, size);
//	cout << "长度为" << ListTraver(L1) << endl;//遍历操作，同时输出长度 
//
//	cout << "现在进行插入操作，请输入你要插入的数字和位置，按顺序" << endl;
//	cin >> num >> size;
//	ListInsert(L1, num, size);
//	cout << "长度为" << ListTraver(L1) << endl;//遍历操作，同时输出长度 
//
//	cout << "现在进行删除操作，请输入你要删除的位置" << endl;
//	cin >> size;
//	ListDelete(L1, size);
//	cout << "长度为" << ListTraver(L1) << endl;//遍历操作，同时输出长度 
//
//	cout << "现在进行查找特定位置数据操作，请输入你要查找的位置" << endl;
//	cin >> num;
//	GetData(L1, num);
//	cout << "长度为" << ListTraver(L1) << endl;//遍历操作，同时输出长度 
//
//	system("pause");
//	cout << "现在进行清空所有数据操作" << endl;
//	clearDuLinkList(L1);
//	cout << "长度为" << ListTraver(L1) << endl;//遍历操作，同时输出长度
//	return 0;
//}
//
//int InitList(DuLinkList& L) {//初始化双链表
//	L = (DuLinkList)malloc(sizeof(DuLNode));
//	if (!L)exit(0);
//	L->next = L;//头结点的下一个指向自己 
//	L->prior = L;//头结点的上一个指向自己 
//	return ok;
//}
//
//int input(DuLinkList& L, int size) {//添加数据
//	ElemType n;
//	DuLinkList p, L1;
//	p = L;
//	for (int i = 0; i < size; i++) {
//		L1 = (DuLinkList)malloc(sizeof(DuLNode));
//		cout << "请输入数字" << endl;
//		cin >> n;
//		L1->data = n;//先将数据存入L1 
//		p->next = L1;//p的下一个指向L1 
//		L1->next = L1;//L1的下一个没得指了，指向自己也行.
//		L1->prior = p;//L1的上一个指向p 
//		p = p->next;//p指向下一个，以继续完成下一步的添加数据
//	}
//	return ok;
//}
//
//int ListTraver(DuLinkList& L) {//遍历双链表同时计算长度 
//	int size = 0;//计算 
//	DuLinkList p;
//	p = L;
//	if ((p->next) == p)cout << "保留了头结点，后续无节点";
//	while ((p->next) != p) {//直到p的下一个指向自己的时候结束 
//		p = p->next;
//		cout << p->data << " ";
//		size++;
//	}
//	return size;
//}
//
//int ListInsert(DuLinkList& L, int num, int data) {//插入操作 
//	DuLinkList p, L1;
//	p = L;
//	for (int i = 1; i < num; i++) {//让p循环到我们要插入的节点的前一个位置 
//		p = p->next;
//	}
//	L1 = (DuLinkList)malloc(sizeof(DuLNode));
//	L1->data = data;//存入数据 
//	L1->next = p->next;//L1的下一个指向p的下一个 
//	p->next = L1;//p的下一个指向L1 
//	L1->prior = p;//L1的上一个指向p 
//	L1->next->prior = L1; //L1的下一个的上一个指向L1,构成双向链表 
//	return ok;
//}
//
//int ListDelete(DuLinkList& L, int size) {//删除操作 
//	DuLinkList Q, p;
//	p = L->next;
//	Q = p;
//	for (int i = 1; i < size; i++) {//让p循环到我们要删除的节点位置，Q为前一个q前一个节点 
//		Q = p;
//		p = p->next;
//	}
//	Q->next = p->next; //Q的下一个指向p的下一个，完成删除，没有指针指向p 
//	Q->next->prior = Q; //让Q的下一个的上一个指向Q，完成双链表 
//	delete(p);//删除节点，减少占用 
//	return ok;
//}
//
//int GetData(DuLinkList& L, int num) {//获得特定位置的数据
//	DuLinkList p;
//	p = L;
//	for (int i = 0; i < num; i++) {//p一直到所要删除的节点位置才停止
//		p = p->next;
//	}
//	cout << "在第" << num << "位的数据为" << p->data << endl;
//	return ok;
//}
//int clearDuLinkList(DuLinkList& L) {
//	DuLinkList p,Q;
//	p = L->next;//如果要保留头结点L改成L->next;
//	while ((p->next) != p) {//类似与过河拆桥，走一步拆后面的节点 
//		Q = p;
//		p = p->next;
//		free(Q);
//	}
//	free(p);//清除最后一个节点
//	L->next = L;
//	return ok;
//}