#include<iostream>
#include<random>   //生成时间种子
#include<chrono>  // 用于高分辨率时钟
#include<vector>   //数组，但是可以自定义长度
#include<stdlib.h>
using namespace std;

// 递归行为的时间复杂度估算(master公式)
// T(N) = a*T(N/b) + O(N^d)  a为自己调用自己的次数，b为子函数的规模，也就是n在子函数被拆成几半（b的子规模必须一样才能调用此公式）
// 1)log(b, a) > d -> 复杂度为O(N^log(b, a))以b为底
// 2)log(b, a) = d -> 复杂度为O(N^d * logN)
// 3)log(b, a) < d -> 复杂度为O(N^d)

void swap(int& a, int &b);//使用异或交换a，b位置(抖机灵算法) “如果传入相同的数据会归为0！！”
int printOddTimeNum1();//问题:有一个数字在数组出现奇数次，其他都出现偶数次,求奇数
int printOddTimeNum2();//问题:有两个数字在数组出现奇数次，其他都出现偶数次,求奇数
int generateRandomArray(vector<int>& vec,int maxSize,int maxValue);//对数器,maxSize最大长度，maxValue最大数据
int process(vector<int>& vec, int L, int R);//用递归在vec数组上求最大值,用来理解归并排序
int MergeSort(vector<int>& vec, int L, int R);//归并排序T(n*logn) 没有浪费比较资源
void merge(vector<int>& vec,int L,int M,int R);//归并排序的合并左右两个数组
void Bubble_Sort(vector<int>& vec);//冒泡排序(n^2)
void Selection_Sort(vector<int>& vec);//选择排序O(n^2)
int insertionSort(vector<int>& vec);//插入排序O(n^2)(比冒泡选择好一点，不一定固定的O(n^2))
int smallSum(vector<int>& vec,int L,int R);//问题:有一个数组，其中左边每一个小于这个数的数累加起来叫做小和，求数组的所有小和加起来的数值
int smallSum_merge(vector<int>& vec, int L, int M, int R); //用归并排序算法解决smallSum问题
template<typename T>
void generateRandomVector(std::vector<T>& vec, int maxSize, T minValue, T maxValue);//大佬的对数器

int main() {
	/*int a, b;
	cout << "请输入两个数，将使用异或进行交换" << endl;
	cin >> a >> b;
	swap(a, b);
	cout << printOddTimeNum1()<<endl;
	printOddTimeNum2();*/
	vector<int> vec1,vec2,vec3;
	for (int i = 0; i < 5; i++) {
		generateRandomArray(vec1, 10, 20);
		vec2 = vector<int>(vec1.size(), -1);
		vec3 = vector<int>(vec1.size(), -1);
		cout << "原数组为：";
		for (int num : vec1) {//遍历vec1
			cout << num << " ";
		}
		cout << "\n";
		copy(vec1.begin(), vec1.end(), vec2.begin());//vec2复制vec1
		copy(vec1.begin(), vec1.end(), vec3.begin());//vec3复制vec1
		//MergeSort(vec1, 0, vec1.size()-1);//归并
		//Bubble_Sort(vec2);//冒泡
		//Selection_Sort(vec2);//选择
		//insertionSort(vec3);//插入
		//cout << "排序后为：";
		//for (int num : vec1) {//遍历
		//	cout << num << " ";
		//}
		/*cout << "最大值为"<<process(vec1, 0, vec1.size()-1);*/
		cout<<"小和为："<< smallSum(vec1, 0, vec1.size() - 1);
		cout << "\n";
	}
	return 0;
}

void swap(int& a, int& b) {//使用异或交换a，b位置  “如果传入相同的数据会归为0！！”
	/*异或语句基本规则
    a^a=0;0^a=a;*/
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
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
	static uniform_int_distribution<unsigned> u(1, maxValue);//这个是随机数引擎生成随机数,限制最大数值
	static uniform_int_distribution<unsigned> n(1, maxSize); //限制最大长度
	int size = n(e);
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
//vec[L..R]范围求最大值
int process(vector<int>& vec, int L, int R) {
	if (L == R) return vec[L];
	int mid = L + ((R - L)>> 1);//中点，右移一位等于除于2
	int leftMax = process(vec, L, mid);
	int rightMax = process(vec, mid + 1, R);
	return leftMax < rightMax ? rightMax : leftMax;
}
//vec[L..R]范围排序,归并排序
int MergeSort(vector<int>& vec, int L, int R) {
	if (L == R) return vec[L];
	int mid = L + ((R - L) >> 1);//中点，右移一位等于除于2
	MergeSort(vec, L, mid);// 排序左半部分
	MergeSort(vec, mid + 1, R);// 排序右半部分
	merge(vec, L, mid, R);// 合并两个有序数组
}
// 函数功能：将两个有序子数组(vec[L...M] 和 vec[M+1...R])合并为一个有序数组
void merge(vector<int>& vec, int L, int M, int R) {
	vector<int> vecHelp;// 用于临时存放合并后的有序数组
	int p1 = L;// p1指针指向左侧有序子数组的起始位置
	int p2 = M + 1;// p2指针指向右侧有序子数组的起始位置
	// 当左右两个子数组都还有元素时，比较它们的当前元素，将较小的元素添加到辅助向量中
	while (p1 <= M && p2 <= R) {
		if (vec[p1] <= vec[p2]) {
			vecHelp.push_back(vec[p1++]);
		} 
		else {
			vecHelp.push_back(vec[p2++]);
		}
	}
	// 当左或右的一个个子数组都还有元素时，将剩下的元素添加到辅助向量中
	while (p1 <= M){
		vecHelp.push_back(vec[p1++]);
	}
	while (p2 <= R) {
		vecHelp.push_back(vec[p2++]);
	}
	// 将辅助向量中的元素复制回原数组，完成合并操作
	for (size_t i = 0; i < vecHelp.size(); ++i) {//size_t = unsigned int 即无符号int
		vec[L + i] = vecHelp[i];
	}
	vecHelp.clear();
	vector<int>().swap(vecHelp);
}

void Bubble_Sort(vector<int>& vec) {//冒泡排序
	for (size_t i = 0; i < vec.size() - 1; i++) {
		for (size_t j = 0; j < vec.size() - 1; j++) {
			if (vec[j] >= vec[j + 1]) {
				swap(vec[j], vec[j + 1]);
			}
		}
	}
}

void Selection_Sort(vector<int>& vec) {//选择排序
	size_t i, j, min=0;
	for (i = 0; i < vec.size() - 1; i++) {
		min = i;
		for (j = i + 1; j < vec.size(); j++) {
			if (vec[j] < vec[min]) {
				min = j;
			}
		}
		if (vec[i] != vec[min]) swap(vec[i], vec[min]);
	}
}

int insertionSort(vector<int>& vec) {//插入排序(比上面好一点，不一定固定的O(N^2))
	if (vec.size() == 0)return 0;
	for (size_t i = 1; i < vec.size(); i++) {
		for (rsize_t j = i; j > 0 && vec[j] < vec[j - 1]; j--) {
			swap(vec[j], vec[j - 1]);
		}
	}
	return 1;
}

int smallSum(vector<int>& vec, int L, int R) {
	if(L == R) return 0;
	int mid = L + ((R - L) >> 1);
	return smallSum(vec, L, mid) + smallSum(vec, mid + 1, R) + smallSum_merge(vec, L, mid, R);
}

int smallSum_merge(vector<int>& vec, int L, int M, int R) {
	vector<int> vecHelp;// 用于临时存放合并后的有序数组
	int p1 = L;// p1指针指向左侧有序子数组的起始位置
	int p2 = M + 1;// p2指针指向右侧有序子数组的起始位置
	int res = 0;
	while (p1 <= M && p2 <= R) {
		res += vec[p1] < vec[p2] ? (R - p2 + 1) * vec[p1] : 0;
		if (vec[p1] <= vec[p2]) {
			vecHelp.push_back(vec[p1++]);
		}
		else {
			vecHelp.push_back(vec[p2++]);
		}
	}
	// 当左或右的一个个子数组都还有元素时，将剩下的元素添加到辅助向量中
	while (p1 <= M) {
		vecHelp.push_back(vec[p1++]);
	}
	while (p2 <= R) {
		vecHelp.push_back(vec[p2++]);
	}
	// 将辅助向量中的元素复制回原数组，完成合并操作
	for (size_t i = 0; i < vecHelp.size(); ++i) {//size_t = unsigned int 即无符号int
		vec[L + i] = vecHelp[i];
	}
	vecHelp.clear();
	vector<int>().swap(vecHelp);
	return res;
}