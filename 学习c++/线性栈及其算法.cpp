//#include <iostream>
//#include <vector>
//using namespace std;
//
//void Conversion(Stack<int>& vec, int num, int n);//ʮ����ת����n����
//bool CheckBracket(const string& s);//�ж������б��Ƿ�������ȷ
//template<typename T>
//class Stack {
//private:
//    vector<T> data;
//public:
//    // ��ջ����
//    void push(const T& value) {
//        data.push_back(value);
//    }
//    // ��ջͬʱ��ȡ����Ԫ��
//    T pop() {
//        if (!isEmpty()) {
//            T n = data.back();
//            data.pop_back();
//            return n;
//        }
//        else {
//            cout << "ջΪ�գ��޷���ջ��" << endl;
//        }
//    }
//    // �ж�ջ�Ƿ�Ϊ��
//    bool isEmpty() const {
//        return data.empty();
//    }
//    // ��ȡջ�Ĵ�С
//    size_t size() const {
//        return data.size();
//    }
//};
//
//int main() {
//    int num, n;
//    Stack<int> stack; //���� 
//    string s;
//    cout << "������ʮ������" << endl;
//    cin >> num;
//    cout << "��������Ҫת����n����" << endl;
//    cin >> n;
//    Conversion(stack, num, n);
//    cout << "������һ�������б��ж��Ƿ���ȷ" << endl;
//    cin >> s;
//    if (CheckBracket(s)) {
//        cout << "������ȷ��";
//    }
//    else {
//        cout << "�������";
//    }
//    return 0;
//}
//
//void Conversion(Stack<int>& vec, int num, int n) {//��ʮ����ת����n���� 
//    // ��������ʮ��������0��ֱ�����0
//    if (num == 0) {
//        cout << "ת�����Ϊ0" << endl;
//        return;
//    }
//    // �����ֲ�Ϊ0ʱ����������ת������
//    while (num != 0) {
//        vec.push(num % n);
//        num /= n;
//    }
//    cout << "ת�����Ϊ";
//    while (!vec.isEmpty()) {
//        cout << vec.pop();
//    }
//    cout << endl;
//}
//
//// ��������CheckBracket
//// ���ܣ����������ַ���s�е������Ƿ���ȷ���
//// ������s - �������ַ���
//// ����ֵ�����������ȷ��Է���true�����򷵻�false
//bool CheckBracket(const string& s) {
//    // ʹ���ַ���ջ��������δ��Ե�������
//    Stack<char> stack;
//    // �����������ַ����е�ÿ���ַ�
//    for (char a : s) {
//        // �����ǰ�ַ���һ�������ţ�����ѹ���ջ
//        if (a == '(' || a == '[' || a == '{') {
//            stack.push(a);
//        }
//
//        // �����ǰ�ַ�����Բ����
//        if (a == ')') {
//            // ����ջ�Ƿ�Ϊ�գ���ʾû��ƥ��������ţ�
//            // ���ջ�Ķ���Ԫ�ز��Ƕ�Ӧ����Բ����
//            // ������������򷵻�false
//            if (stack.isEmpty() || stack.pop() != '(') {
//                return false;
//            }
//        }
//
//        // �����ǰ�ַ����ҷ�����
//        if (a == ']') {
//            // ͬ���أ�����ջ�Ƿ���ƥ���������
//            if (stack.isEmpty() || stack.pop() != '[') {
//                return false;
//            }
//        }
//
//        // �����ǰ�ַ����Ҵ�����
//        if (a == '}') {
//            // ����ջ�Ƿ���ƥ����������
//            if (stack.isEmpty() || stack.pop() != '{') {
//                return false;
//            }
//        }
//    }
//    // �ڱ����������ַ�����ȷ����ջ�ǿյ�
//    // ����ζ�����е������Ŷ��ҵ������ǵ�ƥ��������
//    return stack.isEmpty();
//}
//
