#include "stack.h"
#include "max_priority_queue.h"
#include <iostream>

using std::cout, std::cin;

template <class T>
class Queue {

public:
    explicit Queue(int size): arrays(new T[size + 1]) , size(size + 1), beg(0), end(0){}

private:
    int index(int i) const {
        return i % size;
    }

    void checkOver() {
        if (index(end + 1) == beg) {
            throw std::runtime_error("overflow");
        }
    }

    void checkUnder() const {
        if (empty()) {
            throw std::runtime_error("underflow");
        }
    }

public:
    void push_back(const T &t) {
        checkOver();
        arrays[end] = t;
        end = index(end + 1);
    }

    const T& front() {
        return arrays[beg];
    }

    bool empty() const {
        return beg == end;
    }

    T pop() {
        checkUnder();

        const auto &element = arrays[beg];
        beg = index(beg + 1);
        return element;
    }

    ~Queue() {
        delete[] arrays;
    }

private:
    T *arrays;
    int size;
    int beg;
    int end;
};


void cast() {

    Stack<int> stack;

    int base, num;

    cin >> num >> base;



    if (base < 2) {
        throw std::runtime_error("错误进制");
    }
    if (num == 0) {
        cout << 0;
        return;
    }

    while (num) {
        stack.push(num % base);
        num /= base;
    }

    while (stack.empty()) {
        cout << static_cast<char>(stack.top() > 10 ? (stack.pop() - 10 + 'A') : stack.pop() + '0');
    }
    cout << "\n";
}

void priority() {
    MaxPriorityQueue<char> queue;

    std::string str;
    std::cin >> str;

//     O(nlogn)
    for (const auto &item: str) {
        queue.push_back(item);
    }

    while (!queue.empty()) {
        cout << queue.pop();
    }
    cout << "\n";





}

void plain() {
    std::string str;
    std::cin >> str;

//    O(n)
    Queue<char> queueS(255);
    Queue<char> queueH(255);

    for (const auto &item: str) {
        if (item == 'S') {
            queueS.push_back(item);
        } else {
            queueH.push_back(item);
        }
    }

    while (!queueS.empty()) {
        cout << queueS.pop();
    }
    while (!queueH.empty()) {
        cout << queueH.pop();
    }
    cout << '\n';
}

void foolish() {
    std::string str;
    std::cin >> str;

    //    O(n)
    Queue<char> queue(255);

    for (const auto &item: str) {
        queue.push_back(item);
    }

    int countS = 0;
    int countH = 0;

    while (!queue.empty()) {
        if (queue.pop() == 'S') {
            countS++;
        } else {
            countH++;
        }
    }

    for (int i = 0; i < countS; ++i) {
        cout << "S";
    }
    for (int i = 0; i < countH; ++i) {
        cout << "H";
    }
    cout << '\n';
}

int main() {
//    cast();



    priority();
    plain();
    foolish();



    return 0;
}

