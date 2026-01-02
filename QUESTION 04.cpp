#include <iostream>
#include <exception>
#include <stack>
using namespace std;

template <typename T>
class Stack {
private:
    stack<T> stack;

public:
    void push(T item) {
        stack.push(item);
    }

    T pop() {
        if (stack.empty()) {
            throw runtime_error("StackUnderflowException");
        }
        T item = stack.top();
        stack.pop();
        return item;
    }
};

int main() {
    try {
        Stack<int> s;
        s.push(10);
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;  
    } catch (const runtime_error& e) {
        cout << "Stack is empty. Cannot pop." << endl;
    }

    return 0;
}
