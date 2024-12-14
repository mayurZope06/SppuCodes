// A double-ended queue (deque) is a linear list in which additions and deletions may 
// be made at either end. Obtain a data representation mapping a deque into a 
// onedimensional array. Write C++ program to simulate deque with functions to add 
// and delete elements from either end of the deque.

#include <iostream>
using namespace std;
#define SIZE 5 // Maximum size of the deque

class Deque {
    int a[SIZE]; // Array to store deque elements
    int front, rear; // Indices for front and rear of deque

public:
    // Constructor to initialize the deque
    Deque() : front(-1), rear(-1) {}

    // Function to check if deque is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    // Function to check if deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add an element at the beginning
    void add_at_beg(int item) {
        if (isFull()) {
            cout << "\nDeque overflow! Cannot add element at the beginning.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1; // Wrap around to the end
        } else {
            front--;
        }
        a[front] = item;
        cout << "Inserted " << item << " at the beginning.\n";
    }

    // Function to add an element at the end
    void add_at_end(int item) {
        if (isFull()) {
            cout << "\nDeque overflow! Cannot add element at the end.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0; // Wrap around to the start
        } else {
            rear++;
        }
        a[rear] = item;
        cout << "Inserted " << item << " at the end.\n";
    }

    // Function to delete an element from the front
    void delete_fr_front() {
        if (isEmpty()) {
            cout << "\nDeque underflow! No elements to delete from the front.\n";
            return;
        }
        cout << "Deleted " << a[front] << " from the front.\n";
        if (front == rear) {
            // Only one element was in the deque
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0; // Wrap around to the start
        } else {
            front++;
        }
    }

    // Function to delete an element from the rear
    void delete_fr_rear() {
        if (isEmpty()) {
            cout << "\nDeque underflow! No elements to delete from the rear.\n";
            return;
        }
        cout << "Deleted " << a[rear] << " from the rear.\n";
        if (front == rear) {
            // Only one element was in the deque
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1; // Wrap around to the end
        } else {
            rear--;
        }
    }

    // Function to display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "\nDeque is empty.\n";
            return;
        }
        cout << "Deque elements: ";
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << a[i] << " ";
            }
        } else {
            for (int i = front; i < SIZE; i++) {
                cout << a[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << a[i] << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    Deque dq;
    int choice, item;

    do {
        cout << "\n**** DEQUE OPERATIONS ****\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from rear\n";
        cout << "5. Display deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to be inserted at the beginning: ";
                cin >> item;
                dq.add_at_beg(item);
                break;
            case 2:
                cout << "Enter the element to be inserted at the end: ";
                cin >> item;
                dq.add_at_end(item);
                break;
            case 3:
                dq.delete_fr_front();
                break;
            case 4:
                dq.delete_fr_rear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
