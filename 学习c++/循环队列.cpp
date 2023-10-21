//#include <iostream>
//#include <vector>
//using namespace std;
//
//template <typename T>
//class CircularQueue {
//private:
//    vector<T> data;         // ʹ��vector��Ϊѭ�����еĵײ�����
//    int frontIdx;           // ��������
//    int rearIdx;            // ��β����
//    int capacity;           // ѭ�����е�����
//    int count;              // ��ǰ�����е�Ԫ������
//
//public:
//    // ���캯������ʼ��ѭ�����е��������������
//    CircularQueue(int size) : data(size), frontIdx(0), rearIdx(0), capacity(size), count(0) {}
//
//    // ��Ӳ���
//    bool enqueue(const T& value) {
//        if (isFull()) {
//            cerr << "��������" << endl;
//            return false;
//        }
//        data[rearIdx] = value;              // ��ֵ�ŵ���β
//        rearIdx = (rearIdx + 1) % capacity; // ���¶�β������ͨ��ģ����ʵ��ѭ��
//        count++;                            // Ԫ����������
//        return true;
//    }
//
//    // ���Ӳ���
//    bool dequeue() {
//        if (isEmpty()) {
//            cerr << "����Ϊ��" << endl;
//            return false;
//        }
//        frontIdx = (frontIdx + 1) % capacity; // ���¶���������ͨ��ģ����ʵ��ѭ��
//        count--;                              // Ԫ����������
//        return true;
//    }
//
//    // ��ȡ����Ԫ��
//    T front() const {
//        if (isEmpty()) {
//            cerr << "����Ϊ��" << endl;
//            return T();  // �������Ϊ�գ��򷵻�T��Ĭ��ֵ
//        }
//        return data[frontIdx];
//    }
//
//    // �ж϶����Ƿ�Ϊ��
//    bool isEmpty() const {
//        return count == 0;
//    }
//
//    // �ж϶����Ƿ�����
//    bool isFull() const {
//        return count == capacity;
//    }
//
//    // ��ȡ���д�С����ǰԪ��������
//    size_t size() const {
//        return count;
//    }
//};
//
//int main() {
//    CircularQueue<int> q(5);  // ����һ������Ϊ5��ѭ������
//    q.enqueue(1);
//    q.enqueue(2);
//    q.enqueue(3);
//    cout << "��ӡ����Ԫ��: " << q.front() << endl; // ��ӡ����Ԫ��
//    q.dequeue();  // ���Ӳ���
//    cout << "��ӡ���Ӻ�Ķ���Ԫ��: " << q.front() << endl; // ��ӡ���Ӻ�Ķ���Ԫ��
//    q.enqueue(4);
//    q.enqueue(5);
//    q.enqueue(6);
//    q.enqueue(7);  // �˲����᳢����ӣ������ڶ������������ӡ������Ϣ
//    q.dequeue();   // ���Ӳ���
//    q.enqueue(7);  //���Ӻ������ӣ����ᱨ��
//    return 0;
//}
