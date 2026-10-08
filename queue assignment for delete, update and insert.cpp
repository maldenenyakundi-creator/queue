#include <iostream>
using namespace std;

const int SIZE = 5;

class Queue {
public:
    int arr[SIZE];
    int front;
    int rear;
    int count;

    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    // INSERT (enqueue) - adds at the rear
    void insertElement(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert " << value << ".\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
        cout << value << " inserted into the queue.\n";
    }

    // DELETE (dequeue) - removes from the front
    void deleteElement() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to delete.\n";
            return;
        }
        cout << arr[front] << " deleted from the queue.\n";
        front = (front + 1) % SIZE;
        count--;
    }

    // UPDATE - replaces the element at a given position (1 = front)
    void updateElement(int position, int newValue) {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to update.\n";
            return;
        }
        if (position < 1 || position > count) {
            cout << "Invalid position. Enter a value from 1 to " << count << ".\n";
            return;
        }
        int index = (front + position - 1) % SIZE;
        cout << "Element at position " << position << " changed from "
             << arr[index] << " to " << newValue << ".\n";
        arr[index] = newValue;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front -> rear): ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % SIZE] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value, position;

    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Update element\n";
        cout << "4. Display queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.insertElement(value);
                break;
            case 2:
                q.deleteElement();
                break;
            case 3:
                cout << "Enter position to update (1 = front): ";
                cin >> position;
                cout << "Enter new value: ";
                cin >> value;
                q.updateElement(position, value);
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}