//#include <iostream>
//#include <vector>
//using namespace std;
//
//void Conversion(Stack<int>& vec, int num, int n);//十进制转换沉n进制
//bool CheckBracket(const string& s);//判断括号列表是否输入正确
//template<typename T>
//class Stack {
//private:
//    vector<T> data;
//public:
//    // 入栈操作
//    void push(const T& value) {
//        data.push_back(value);
//    }
//    // 出栈同时获取顶部元素
//    T pop() {
//        if (!isEmpty()) {
//            T n = data.back();
//            data.pop_back();
//            return n;
//        }
//        else {
//            cout << "栈为空，无法出栈。" << endl;
//        }
//    }
//    // 判断栈是否为空
//    bool isEmpty() const {
//        return data.empty();
//    }
//    // 获取栈的大小
//    size_t size() const {
//        return data.size();
//    }
//};
//
//int main() {
//    int num, n;
//    Stack<int> stack; //对象 
//    string s;
//    cout << "请输入十进制数" << endl;
//    cin >> num;
//    cout << "请输入你要转换的n进制" << endl;
//    cin >> n;
//    Conversion(stack, num, n);
//    cout << "请输入一个括号列表，判断是否正确" << endl;
//    cin >> s;
//    if (CheckBracket(s)) {
//        cout << "输入正确！";
//    }
//    else {
//        cout << "输入错误！";
//    }
//    return 0;
//}
//
//void Conversion(Stack<int>& vec, int num, int n) {//将十进制转换成n进制 
//    // 如果输入的十进制数是0，直接输出0
//    if (num == 0) {
//        cout << "转换结果为0" << endl;
//        return;
//    }
//    // 当数字不为0时，持续进行转换操作
//    while (num != 0) {
//        vec.push(num % n);
//        num /= n;
//    }
//    cout << "转换结果为";
//    while (!vec.isEmpty()) {
//        cout << vec.pop();
//    }
//    cout << endl;
//}
//
//// 函数名：CheckBracket
//// 功能：检查给定的字符串s中的括号是否正确配对
//// 参数：s - 待检查的字符串
//// 返回值：如果括号正确配对返回true，否则返回false
//bool CheckBracket(const string& s) {
//    // 使用字符堆栈来保存尚未配对的左括号
//    Stack<char> stack;
//    // 遍历给定的字符串中的每个字符
//    for (char a : s) {
//        // 如果当前字符是一个左括号，将其压入堆栈
//        if (a == '(' || a == '[' || a == '{') {
//            stack.push(a);
//        }
//
//        // 如果当前字符是右圆括号
//        if (a == ')') {
//            // 检查堆栈是否为空（表示没有匹配的左括号）
//            // 或堆栈的顶部元素不是对应的左圆括号
//            // 如果是这样，则返回false
//            if (stack.isEmpty() || stack.pop() != '(') {
//                return false;
//            }
//        }
//
//        // 如果当前字符是右方括号
//        if (a == ']') {
//            // 同样地，检查堆栈是否有匹配的左方括号
//            if (stack.isEmpty() || stack.pop() != '[') {
//                return false;
//            }
//        }
//
//        // 如果当前字符是右大括号
//        if (a == '}') {
//            // 检查堆栈是否有匹配的左大括号
//            if (stack.isEmpty() || stack.pop() != '{') {
//                return false;
//            }
//        }
//    }
//    // 在遍历完整个字符串后，确保堆栈是空的
//    // 这意味着所有的左括号都找到了它们的匹配右括号
//    return stack.isEmpty();
//}
//
