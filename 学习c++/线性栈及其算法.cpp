#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack;//����ջ���亯����ʼ��
void Conversion(Stack<int>& vec, int num, int n);//ʮ����ת����n����
bool CheckBracket(const string& s);//�ж������б��Ƿ�������ȷ



template<typename T>
class Stack {
private:
    vector<T> data;
public:
    // ��ջ����
    void push(const T& value) {
        data.push_back(value);
    }
    // ��ջͬʱ��ȡ����Ԫ��
    T pop() {
        if (!isEmpty()) {
            T n = data.back();
            data.pop_back();
            return n;
        }
        else {
            cout << "ջΪ�գ��޷���ջ��" << endl;
        }
    }
    // �ж�ջ�Ƿ�Ϊ��
    bool isEmpty() const {
        return data.empty();
    }
    // ��ȡջ�Ĵ�С
    size_t size() const {
        return data.size();
    }
};

int main() {
    int num, n;
    Stack<int> stack; //���� 
    string s;
    cout << "������ʮ������" << endl;
    cin >> num;
    cout << "��������Ҫת����n����" << endl;
    cin >> n;
    Conversion(stack, num, n);
    cout << "������һ�������б��ж��Ƿ���ȷ" << endl;
    cin >> s;
    if (CheckBracket(s)) {
        cout << "������ȷ��";
    }
    else {
        cout << "�������";
    }
    return 0;
}

void Conversion(Stack<int>& vec, int num, int n) {//��ʮ����ת����n���� 
    // ��������ʮ��������0��ֱ�����0
    if (num == 0) {
        cout << "ת�����Ϊ0" << endl;
        return;
    }
    // �����ֲ�Ϊ0ʱ����������ת������
    while (num != 0) {
        vec.push(num % n);
        num /= n;
    }
    cout << "ת�����Ϊ";
    while (!vec.isEmpty()) {
        cout << vec.pop();
    }
    cout << endl;
}

bool CheckBracket(const string& s) {//�ж������Ƿ�ʹ����ȷ
    Stack<char> stack;
    for (char a : s) {
        if (a == '(' || a == '[' || a == '{') {
            stack.push(a);
        }
        if (a == ')') {
            if (stack.isEmpty() || stack.pop() != '(') {
                return false;
            }
        }
        if (a == ']') {
            if (stack.isEmpty() || stack.pop() != '[') {
                return false;
            }
        }
        if (a == '}') {
            if (stack.isEmpty() || stack.pop() != '{') {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

