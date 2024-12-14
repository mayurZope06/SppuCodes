// Write C++ program for storing binary number using doubly linked lists. Write 
// functions .
// a) to compute 1„s and 2„s complement .
// b) add two binary numbers .

#include <iostream>
#include <string>

using namespace std;

// Node structure for the doubly linked list
struct Node {
    char bit; // Binary bit (0 or 1)
    Node* next;
    Node* prev;
};

// Class for the doubly linked list representing a binary number
class BinaryNumber {
private:
    Node* head;
    Node* tail;

public:
    BinaryNumber() : head(nullptr), tail(nullptr) {}

    // Function to add a bit to the binary number
    void addBit(char bit) {
        Node* newNode = new Node{bit, nullptr, tail};
        if (!head) { // If the list is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to display the binary number
    void display() {
        Node* current = head;
        while (current) {
            cout << current->bit;
            current = current->next;
        }
        cout << endl;
    }

    // Function to compute 1's complement
    void onesComplement() {
        Node* current = head;
        while (current) {
            current->bit = (current->bit == '0') ? '1' : '0'; // Flip the bit
            current = current->next;
        }
    }

    // Function to compute 2's complement
    void twosComplement() {
        // First find the 1's complement
        onesComplement();

        // Now add 1 to the binary number
        Node* current = tail;
        bool carry = true;

        while (current && carry) {
            if (current->bit == '1') {
                current->bit = '0'; // Flip bit
            } else {
                current->bit = '1'; // Add 1
                carry = false; // No carry to the next bit
            }
            current = current->prev;
        }

        // If carry is still true, we need to add a new bit
        if (carry) {
            addBit('1');
        }
    }

    // Function to add two binary numbers
    static BinaryNumber add(BinaryNumber& num1, BinaryNumber& num2) {
        BinaryNumber result;
        Node* ptr1 = num1.tail;
        Node* ptr2 = num2.tail;
        bool carry = false;

        while (ptr1 || ptr2 || carry) {
            int sum = carry;
            if (ptr1) {
                sum += (ptr1->bit - '0');
                ptr1 = ptr1->prev;
            }
            if (ptr2) {
                sum += (ptr2->bit - '0');
                ptr2 = ptr2->prev;
            }

            carry = sum > 1; // Carry is 1 if sum is 2 or 3
            result.addBit((sum % 2) + '0'); // Add the current bit (0 or 1)
        }

        // The result is in reverse order, so we need to reverse it
        reverse(result);
        return result;
    }

    // Function to reverse the binary number
    static void reverse(BinaryNumber& binary) {
        Node* current = binary.head;
        Node* temp = nullptr;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = temp;
        }

        // Swap head and tail
        if (temp) {
            binary.tail = binary.head;
            binary.head = temp->prev; // New head
        }
    }

    // Destructor to free memory
    ~BinaryNumber() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Function to take user input for a binary number
BinaryNumber inputBinaryNumber() {
    BinaryNumber binary;
    string binaryStr;
    cout << "Enter a binary number: ";
    cin >> binaryStr;
    for (char bit : binaryStr) {
        binary.addBit(bit);
    }
    return binary;
}

int main() {
    cout << "Binary Number Operations using Doubly Linked List\n";

    // Input two binary numbers
    BinaryNumber num1 = inputBinaryNumber();
    BinaryNumber num2 = inputBinaryNumber();

    cout << "\nBinary Number 1: ";
    num1.display();
    cout << "1's Complement: ";
    num1.onesComplement();
    num1.display();
    cout << "2's Complement: ";
    num1.twosComplement();
    num1.display();

    cout << "\nBinary Number 2: ";
    num2.display();
    cout << "1's Complement: ";
    num2.onesComplement();
    num2.display();
    cout << "2's Complement: ";
    num2.twosComplement();
    num2.display();

    // Add two binary numbers
    BinaryNumber sum = BinaryNumber::add(num1, num2);
    cout << "\nSum of the two binary numbers: ";
    sum.display();

    return 0;
}
