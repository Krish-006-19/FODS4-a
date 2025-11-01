#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class Stack {
    Node* head;
public:
    Stack() {
        head = nullptr;
    }
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        Node* temp = head;
        int val = head->val;
        head = head->next;
        delete temp;
        return val;
    }
    int peek() {
        if (isEmpty()) {
            cout << "No data available\n";
            return -1;
        }
        return head->val;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }
    void push(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        Node* temp = front;
        int val = front->val;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return val;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return front->val;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void display() {
        Node* temp = front;
        if (!temp) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    string choice, subchoice;
    Stack st;
    Queue q;
    int input;
    bool flag = false;

    while (!flag) {
        cout << "\nChoose:\n1. Stack\n2. Queue\n3. Exit\n";
        cin >> choice;

        if (choice.length() != 1 || choice[0] < '1' || choice[0] > '3') {
            cout << "Please Enter A Valid Number\n";
            continue;
        }

        switch (choice[0]) {
        case '1':
            while (true) {
                cout << "\nStack Menu:\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
                cin >> subchoice;

                if (subchoice.length() != 1 || subchoice[0] < '1' || subchoice[0] > '4') {
                    cout << "Please Enter A Valid Number\n";
                    continue;
                }

                if (subchoice[0] == '4') break;

                switch (subchoice[0]) {
                case '1':
                    cout << "Enter value: ";
                    cin >> input;
                    st.push(input);
                    break;
                case '2':
                    cout << "Popped: " << st.pop() << "\n";
                    break;
                case '3':
                    st.display();
                    break;
                }
            }
            break;

        case '2':
            while (true) {
                cout << "\nQueue Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
                cin >> subchoice;

                if (subchoice.length() != 1 || subchoice[0] < '1' || subchoice[0] > '4') {
                    cout << "Please Enter A Valid Number\n";
                    continue;
                }

                if (subchoice[0] == '4') break;

                switch (subchoice[0]) {
                case '1':
                    cout << "Enter value: ";
                    cin >> input;
                    q.push(input);
                    break;
                case '2':
                    cout << "Dequeued: " << q.pop() << "\n";
                    break;
                case '3':
                    q.display();
                    break;
                }
            }
            break;

        case '3':
            flag = true;
            break;
        }
    }

    return 0;
}
