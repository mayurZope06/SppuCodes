#include <iostream>
#define MAX 5 // Define maximum number of orders (M)
using namespace std;

class PizzaParlor {
private:
    int orders[MAX];  // Array to store the orders
    int front, rear;  // Pointers to track the front and rear of the queue

public:
    // Constructor to initialize the circular queue
    PizzaParlor() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add an order to the queue
    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "The parlor is at full capacity. Cannot accept more orders.\n";
            return;
        }

        if (front == -1) {  // If queue is empty
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;  // Circular wrap-around
        } else {
            rear++;  // Normal case
        }

        orders[rear] = orderID;
        cout << "Order " << orderID << " has been placed successfully.\n";
    }

    // Function to serve an order (remove from the queue)
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Serving order " << orders[front] << ".\n";

        if (front == rear) {
            // Only one order was in the queue
            front = -1;
            rear = -1;
        } else if (front == MAX - 1) {
            // Circular wrap-around
            front = 0;
        } else {
            front++;
        }
    }

    // Function to display the current orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return;
        }

        cout << "Current orders in the queue: ";
        if (rear >= front) {
            // If rear is ahead of or at front
            for (int i = front; i <= rear; i++) {
                std::cout << orders[i] << " ";
            }
        } else {
            // Circular queue case
            for (int i = front; i < MAX; i++) {
                cout << orders[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << orders[i] << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    PizzaParlor parlor;
    int choice, orderID;

    do {
        cout << "\nPizza Parlor Order Management System\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order ID: ";
                cin >> orderID;
                parlor.placeOrder(orderID);
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayOrders();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}



