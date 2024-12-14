// Queues are frequently used in computer programming, and a typical example 
// is the creation of a job queue by an operating system. If the operating system 
// does not use priorities, then the jobs are processed in the order they enter the 
// system. Write C++ program for simulating job queue. Write functions to add 
// job and delete job from queue. 

#include <iostream>
using namespace std;
class Queue{
public:
    int front, rear, arr[5];
    void enqueue();
    int dequeue();
    int isfull();
    int isempty();
    void display();
} q;
void Queue::enqueue(){
    int n;
    cout << "\n Enter job to be inserted :" << endl;
    cin >> n;
    if (isfull() == 1){
        cout << "\n Overflow";
    }
    else{
        q.rear = q.rear + 1;
        q.arr[q.rear] = n;
    }
}
int Queue::isfull(){
    if (q.rear == 4){
        return 1;
    }
    else{
        return 0;
    }
}
int Queue::dequeue(){
    int n;
    if (isempty() == 1){
        cout << "\n Underflow";
        return 0;
    }
    else{
        q.front++;
        n = q.arr[q.front];
        q.arr[q.front] = 0;
        return n;
    }
}
int Queue::isempty(){
    if (q.front == q.rear){
        return 1;
    }
    else{
        return 0;
    }
}
void Queue::display(){
    if (q.front == q.rear){
        cout << "\n Queue is empty.";
    }
    else{
        cout << "\n The queue is : ";
        for (int i = q.front + 1; i <= q.rear; i++){
            cout << " " << q.arr[i];
        }
    }
}
int main(){
    Queue q;
    q.front = -1;
    q.rear = -1;
    int choice, ch;
    do{
        cout << "\n Enter 1 to display the job. \n Enter 2 to insert job. \n Enter 3 to delete job. \n Enter your choice."<<endl;
                cin >> choice;
        switch (choice){
        case 1:
            q.display();
            break;
        case 2:
            q.isfull();
            q.enqueue();
            break;
        case 3:
            q.isempty();
            q.dequeue();
            break;
        default:
            cout << "\n Invalid Input.";
            break;
        }
        cout << "\n Do you want to continue ? (0/1)" << endl;
        cin >> ch;
    } while (ch == 1);
    return 0;
}