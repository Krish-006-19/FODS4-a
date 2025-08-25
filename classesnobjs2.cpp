#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
    Node* top;  
public:
    Stack() : top(nullptr) {}

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "[";
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << ",";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    ~Stack() {
        while (!isEmpty()) pop();
    }
};
class Queue {
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void insert(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) { 
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int remove() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return val;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "[";
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << ",";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    ~Queue() {
        while (!isEmpty()) remove();
    }
};

int main() {
    Stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.display();

    cout << "Popped from Stack: " << s.pop() << endl;
    s.display();

    Queue q;
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.display();

    q.remove();
    q.display();

    q.insert(40);
    q.insert(50);
    q.display();

    return 0;
}

