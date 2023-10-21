//#include <iostream>
//#include <vector>
//using namespace std;
//
//template <typename T>
//class CircularQueue {
//private:
//    vector<T> data;         // 使用vector作为循环队列的底层容器
//    int frontIdx;           // 队首索引
//    int rearIdx;            // 队尾索引
//    int capacity;           // 循环队列的容量
//    int count;              // 当前队列中的元素数量
//
//public:
//    // 构造函数，初始化循环队列的容量和相关索引
//    CircularQueue(int size) : data(size), frontIdx(0), rearIdx(0), capacity(size), count(0) {}
//
//    // 入队操作
//    bool enqueue(const T& value) {
//        if (isFull()) {
//            cerr << "队列已满" << endl;
//            return false;
//        }
//        data[rearIdx] = value;              // 将值放到队尾
//        rearIdx = (rearIdx + 1) % capacity; // 更新队尾索引，通过模运算实现循环
//        count++;                            // 元素数量增加
//        return true;
//    }
//
//    // 出队操作
//    bool dequeue() {
//        if (isEmpty()) {
//            cerr << "队列为空" << endl;
//            return false;
//        }
//        frontIdx = (frontIdx + 1) % capacity; // 更新队首索引，通过模运算实现循环
//        count--;                              // 元素数量减少
//        return true;
//    }
//
//    // 获取队首元素
//    T front() const {
//        if (isEmpty()) {
//            cerr << "队列为空" << endl;
//            return T();  // 如果队列为空，则返回T的默认值
//        }
//        return data[frontIdx];
//    }
//
//    // 判断队列是否为空
//    bool isEmpty() const {
//        return count == 0;
//    }
//
//    // 判断队列是否已满
//    bool isFull() const {
//        return count == capacity;
//    }
//
//    // 获取队列大小（当前元素数量）
//    size_t size() const {
//        return count;
//    }
//};
//
//int main() {
//    CircularQueue<int> q(5);  // 创建一个容量为5的循环队列
//    q.enqueue(1);
//    q.enqueue(2);
//    q.enqueue(3);
//    cout << "打印队首元素: " << q.front() << endl; // 打印队首元素
//    q.dequeue();  // 出队操作
//    cout << "打印出队后的队首元素: " << q.front() << endl; // 打印出队后的队首元素
//    q.enqueue(4);
//    q.enqueue(5);
//    q.enqueue(6);
//    q.enqueue(7);  // 此操作会尝试入队，但由于队列已满，会打印错误信息
//    q.dequeue();   // 出队操作
//    q.enqueue(7);  //出队后可以入队，不会报错
//    return 0;
//}
