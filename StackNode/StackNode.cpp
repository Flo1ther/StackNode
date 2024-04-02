#include <iostream>

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    ListNode<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(const T& val) {
        if (head == nullptr) {
            head = new ListNode<T>(val);
        }
        else {
            ListNode<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new ListNode<T>(val);
        }
    }

    LinkedList<T>* clone() const {
        LinkedList<T>* newList = new LinkedList<T>();
        ListNode<T>* current = head;
        while (current != nullptr) {
            newList->push_back(current->data);
            current = current->next;
        }
        return newList;
    }

    LinkedList<T>* operator+(const LinkedList<T>& other) const {
        LinkedList<T>* newList = clone();
        ListNode<T>* current = other.head;
        while (current != nullptr) {
            newList->push_back(current->data);
            current = current->next;
        }
        return newList;
    }

    LinkedList<T>* operator*(const LinkedList<T>& other) const {
        LinkedList<T>* newList = new LinkedList<T>();
        ListNode<T>* current = head;
        while (current != nullptr) {
            if (other.contains(current->data)) {
                newList->push_back(current->data);
            }
            current = current->next;
        }
        return newList;
    }

    bool contains(const T& val) const {
        ListNode<T>* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const {
        ListNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    LinkedList<int> list2;
    list2.push_back(3);
    list2.push_back(4);
    list2.push_back(5);

    LinkedList<int>* clonedList = list1.clone();
    std::cout << "Cloned list: ";
    clonedList->print();

    LinkedList<int>* mergedList = list1 + list2;
    std::cout << "Merged list: ";
    mergedList->print();

    LinkedList<int>* commonList = list1 * list2;
    std::cout << "Common elements list: ";
    commonList->print();

    delete clonedList;
    delete mergedList;
    delete commonList;

    return 0;
}
