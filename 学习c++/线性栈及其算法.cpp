#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

template<typename T>
class Stack {
private:
    vector<T> data;
public:
    // 入栈操作
    void push(const T& value) {
        data.push_back(value);
    }
    // 出栈操作
    T pop() {
        if (!isEmpty()) {
            T n = data.back();
            data.pop_back();
            return n;
        }
        else {
            std::cout << "栈为空，无法出栈。" << std::endl;
        }
    }
    // 获取栈顶元素
    T top() const {
        if (!isEmpty()) {
            return data.back();
        }
        else {
            std::cerr << "栈为空。" << std::endl;
            exit(0);  // 在实际应用中，你可能希望用其他方式处理这种情况，比如抛出一个异常。
        }
    }
    // 判断栈是否为空
    bool isEmpty() const {
        return data.empty();
    }
    // 获取栈的大小
    size_t size() const {
        return data.size();
    }
};

void Conversion(Stack<int>& vec, int num, int n) {//将十进制转换成n进制 
    // 如果输入的十进制数是0，直接输出0
    if (num == 0) {
        cout << "转换结果为0" << endl;
        return;
    }
    // 当数字不为0时，持续进行转换操作
    while (num != 0) {
        vec.push(num % n);
        num /= n;
    }
    cout << "转换结果为";
    while (!vec.isEmpty()) {
        cout << vec.pop();
    }
    cout << endl;
}

bool CheckBracket(const string& s) {
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

int main() {
    int num, n;
    Stack<int> stack; //对象 
    string s;
    cout << "请输入十进制数" << endl;
    cin >> num;
    cout << "请输入你要转换的n进制" << endl;
    cin >> n;
    Conversion(stack, num, n);
    cout << "请输入一个括号列表，判断是否正确" << endl;
    cin >> s;
    if (CheckBracket(s)) {
        cout << "输入正确！";
    }
    else{
        cout << "输入错误！";
    }
    return 0;
}