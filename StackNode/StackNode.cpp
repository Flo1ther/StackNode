#include <iostream>

template <typename T>
class StackNode {
public:
    T data;
    StackNode* next;

    StackNode(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    StackNode<T>* topNode;
    size_t maxSize;
    size_t currentSize;

public:
    Stack() : topNode(nullptr), maxSize(10), currentSize(0) {}

    Stack(size_t size) : topNode(nullptr), maxSize(size), currentSize(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& val) {
        if (currentSize >= maxSize) {
            std::cout << "Stack overflow! Increasing stack size..." << std::endl;
            maxSize *= 2;
        }
        StackNode<T>* newNode = new StackNode<T>(val);
        newNode->next = topNode;
        topNode = newNode;
        currentSize++;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty! Cannot pop." << std::endl;
            return;
        }
        StackNode<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        currentSize--;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    T top() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty! Cannot get top element." << std::endl;
            exit(EXIT_FAILURE);
        }
        return topNode->data;
    }

    size_t size() const {
        return currentSize;
    }
};

int main() {
    Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    std::cout << "Top element: " << stack.top() << std::endl;
    std::cout << "Stack size: " << stack.size() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;

    return 0;
}
