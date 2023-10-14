#include<iostream>
#include<random>   //����ʱ������
#include<chrono>  // ���ڸ߷ֱ���ʱ��
#include<vector>   //���飬���ǿ����Զ��峤��
#include<stdlib.h>
using namespace std;

// �ݹ���Ϊ��ʱ�临�Ӷȹ���(master��ʽ)
// T(N) = a*T(N/b) + O(N^d)  aΪ�Լ������Լ��Ĵ�����bΪ�Ӻ����Ĺ�ģ��Ҳ����n���Ӻ�������ɼ��루b���ӹ�ģ����һ�����ܵ��ô˹�ʽ��
// 1)log(b, a) > d -> ���Ӷ�ΪO(N^log(b, a))��bΪ��
// 2)log(b, a) = d -> ���Ӷ�ΪO(N^d * logN)
// 3)log(b, a) < d -> ���Ӷ�ΪO(N^d)

void swap(int& a, int &b);//ʹ����򽻻�a��bλ��(�������㷨) �����������ͬ�����ݻ��Ϊ0������
int printOddTimeNum1();//����:��һ��������������������Σ�����������ż����,������
int printOddTimeNum2();//����:������������������������Σ�����������ż����,������
int generateRandomArray(vector<int>& vec,int maxSize,int maxValue);//������,maxSize��󳤶ȣ�maxValue�������
int process(vector<int>& vec, int L, int R);//�õݹ���vec�����������ֵ,�������鲢����
int MergeSort(vector<int>& vec, int L, int R);//�鲢����T(n*logn) û���˷ѱȽ���Դ
void merge(vector<int>& vec,int L,int M,int R);//�鲢����ĺϲ�������������
void Bubble_Sort(vector<int>& vec);//ð������(n^2)
void Selection_Sort(vector<int>& vec);//ѡ������O(n^2)
int insertionSort(vector<int>& vec);//��������O(n^2)(��ð��ѡ���һ�㣬��һ���̶���O(n^2))
int smallSum(vector<int>& vec,int L,int R);//����:��һ�����飬�������ÿһ��С������������ۼ���������С�ͣ������������С�ͼ���������ֵ
int smallSum_merge(vector<int>& vec, int L, int M, int R); //�ù鲢�����㷨���smallSum����
template<typename T>
void generateRandomVector(std::vector<T>& vec, int maxSize, T minValue, T maxValue);//���еĶ�����

int main() {
	/*int a, b;
	cout << "����������������ʹ�������н���" << endl;
	cin >> a >> b;
	swap(a, b);
	cout << printOddTimeNum1()<<endl;
	printOddTimeNum2();*/
	vector<int> vec1,vec2,vec3;
	for (int i = 0; i < 5; i++) {
		generateRandomArray(vec1, 10, 20);
		vec2 = vector<int>(vec1.size(), -1);
		vec3 = vector<int>(vec1.size(), -1);
		cout << "ԭ����Ϊ��";
		for (int num : vec1) {//����vec1
			cout << num << " ";
		}
		cout << "\n";
		copy(vec1.begin(), vec1.end(), vec2.begin());//vec2����vec1
		copy(vec1.begin(), vec1.end(), vec3.begin());//vec3����vec1
		//MergeSort(vec1, 0, vec1.size()-1);//�鲢
		//Bubble_Sort(vec2);//ð��
		//Selection_Sort(vec2);//ѡ��
		//insertionSort(vec3);//����
		//cout << "�����Ϊ��";
		//for (int num : vec1) {//����
		//	cout << num << " ";
		//}
		/*cout << "���ֵΪ"<<process(vec1, 0, vec1.size()-1);*/
		cout<<"С��Ϊ��"<< smallSum(vec1, 0, vec1.size() - 1);
		cout << "\n";
	}
	return 0;
}

void swap(int& a, int& b) {//ʹ����򽻻�a��bλ��  �����������ͬ�����ݻ��Ϊ0������
	/*�������������
    a^a=0;0^a=a;*/
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
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
//vec[L..R]��Χ����,�鲢����
int MergeSort(vector<int>& vec, int L, int R) {
	if (L == R) return vec[L];
	int mid = L + ((R - L) >> 1);//�е㣬����һλ���ڳ���2
	MergeSort(vec, L, mid);// ������벿��
	MergeSort(vec, mid + 1, R);// �����Ұ벿��
	merge(vec, L, mid, R);// �ϲ�������������
}
// �������ܣ�����������������(vec[L...M] �� vec[M+1...R])�ϲ�Ϊһ����������
void merge(vector<int>& vec, int L, int M, int R) {
	vector<int> vecHelp;// ������ʱ��źϲ������������
	int p1 = L;// p1ָ��ָ������������������ʼλ��
	int p2 = M + 1;// p2ָ��ָ���Ҳ��������������ʼλ��
	// ���������������鶼����Ԫ��ʱ���Ƚ����ǵĵ�ǰԪ�أ�����С��Ԫ����ӵ�����������
	while (p1 <= M && p2 <= R) {
		if (vec[p1] <= vec[p2]) {
			vecHelp.push_back(vec[p1++]);
		} 
		else {
			vecHelp.push_back(vec[p2++]);
		}
	}
	// ������ҵ�һ���������鶼����Ԫ��ʱ����ʣ�µ�Ԫ����ӵ�����������
	while (p1 <= M){
		vecHelp.push_back(vec[p1++]);
	}
	while (p2 <= R) {
		vecHelp.push_back(vec[p2++]);
	}
	// �����������е�Ԫ�ظ��ƻ�ԭ���飬��ɺϲ�����
	for (size_t i = 0; i < vecHelp.size(); ++i) {//size_t = unsigned int ���޷���int
		vec[L + i] = vecHelp[i];
	}
	vecHelp.clear();
	vector<int>().swap(vecHelp);
}

void Bubble_Sort(vector<int>& vec) {//ð������
	for (size_t i = 0; i < vec.size() - 1; i++) {
		for (size_t j = 0; j < vec.size() - 1; j++) {
			if (vec[j] >= vec[j + 1]) {
				swap(vec[j], vec[j + 1]);
			}
		}
	}
}

void Selection_Sort(vector<int>& vec) {//ѡ������
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

int insertionSort(vector<int>& vec) {//��������(�������һ�㣬��һ���̶���O(N^2))
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
	vector<int> vecHelp;// ������ʱ��źϲ������������
	int p1 = L;// p1ָ��ָ������������������ʼλ��
	int p2 = M + 1;// p2ָ��ָ���Ҳ��������������ʼλ��
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
	// ������ҵ�һ���������鶼����Ԫ��ʱ����ʣ�µ�Ԫ����ӵ�����������
	while (p1 <= M) {
		vecHelp.push_back(vec[p1++]);
	}
	while (p2 <= R) {
		vecHelp.push_back(vec[p2++]);
	}
	// �����������е�Ԫ�ظ��ƻ�ԭ���飬��ɺϲ�����
	for (size_t i = 0; i < vecHelp.size(); ++i) {//size_t = unsigned int ���޷���int
		vec[L + i] = vecHelp[i];
	}
	vecHelp.clear();
	vector<int>().swap(vecHelp);
	return res;
}