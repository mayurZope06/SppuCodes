// Department of Computer Engineering has student's club named 'Pinnacle Club'. 
// Students of second, third and final year of department can be granted 
// membership on request. Similarly one may cancel the membership of club. First 
// node is reserved for president of club and last node is reserved for secretary of 
// club. Write C++ program to maintain club member‘s information using singly 
// linked list. Store student PRN and Name. Write functions to:  
// a) Add and delete the members as well as president or even secretary.  
// b) Compute total number of members of club 
// c) Display members  
// d) Two linked lists exists for two divisions. Concatenate two lists 

#include <iostream>
#include <string>

using namespace std;

// Node structure for the linked list
struct Member {
    string prn;
    string name;
    Member* next;
};

// Class for the Pinnacle Club
class PinnacleClub {
private:
    Member* head;
    Member* tail;

public:
    PinnacleClub() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to add a member
    void addMember(const string& prn, const string& name) {
        Member* newMember = new Member{prn, name, nullptr};

        // If the list is empty, set head and tail
        if (!head) {
            head = newMember; // First member (President)
            tail = newMember; // Also the tail
        } else {
            tail->next = newMember; // Add to the end
            tail = newMember; // Update tail
        }
    }

    // Function to delete a member by PRN
    void deleteMember(const string& prn) {
        if (!head) {
            cout << "No members to delete." << endl;
            return;
        }

        Member* current = head;
        Member* previous = nullptr;

        // Search for the member to delete
        while (current != nullptr && current->prn != prn) {
            previous = current;
            current = current->next;
        }

        // If the member was not found
        if (!current) {
            cout << "Member with PRN " << prn << " not found." << endl;
            return;
        }

        // If the member to delete is the head
        if (current == head) {
            head = head->next;
        } else {
            previous->next = current->next;
        }

        // If the member to delete is the tail
        if (current == tail) {
            tail = previous;
        }

        delete current; // Free memory
        cout << "Member with PRN " << prn << " deleted." << endl;
    }

    // Function to compute total number of members
    int totalMembers() {
        int count = 0;
        Member* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function to display members
    void displayMembers() {
        if (!head) {
            cout << "No members in the club." << endl;
            return;
        }

        Member* current = head;
        while (current != nullptr) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    // Function to concatenate two lists
    void concatenate(PinnacleClub& otherClub) {
        if (!head) {
            head = otherClub.head;
            tail = otherClub.tail;
        } else if (otherClub.head) {
            tail->next = otherClub.head;
            tail = otherClub.tail;
        }
        otherClub.head = nullptr; // Clear the other list
        otherClub.tail = nullptr;
    }

    // Destructor to free memory
    ~PinnacleClub() {
        while (head) {
            Member* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Function to take user input for member details
void addMemberInput(PinnacleClub& club) {
    string prn, name;
    cout << "Enter PRN: ";
    cin >> prn;
    cout << "Enter Name: ";
    cin.ignore(); // Clear the newline from the input buffer
    getline(cin, name);
    club.addMember(prn, name);
}

int main() {
    PinnacleClub divisionA;
    PinnacleClub divisionB;
    int choice;

    do {
        cout << "\nPinnacle Club Menu:\n";
        cout << "1. Add Member to Division A\n";
        cout << "2. Add Member to Division B\n";
        cout << "3. Delete Member from Division A\n";
        cout << "4. Delete Member from Division B\n";
        cout << "5. Display Members of Division A\n";
        cout << "6. Display Members of Division B\n";
        cout << "7. Compute Total Members in Division A\n";
        cout << "8. Compute Total Members in Division B\n";
        cout << "9. Concatenate Division B into Division A\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addMemberInput(divisionA);
                break;
            case 2:
                addMemberInput(divisionB);
                break;
            case 3: {
                string prn;
                cout << "Enter PRN of the member to delete from Division A: ";
                cin >> prn;
                divisionA.deleteMember(prn);
                break;
            }
            case 4: {
                string prn;
                cout << "Enter PRN of the member to delete from Division B: ";
                cin >> prn;
                divisionB.deleteMember(prn);
                break;
            }
            case 5:
                cout << "\nMembers of Division A:\n";
                divisionA.displayMembers();
                break;
            case 6:
                cout << "\nMembers of Division B:\n";
                divisionB.displayMembers();
                break;
            case 7:
                cout << "Total members in Division A: " << divisionA.totalMembers() << endl;
                break;
            case 8:
                cout << "Total members in Division B: " << divisionB.totalMembers() << endl;
                break;
            case 9:
                cout << "Concatenating Division B into Division A..." << endl;
                divisionA.concatenate(divisionB);
                cout << "Concatenation complete." << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

// OR

#include <iostream>
#include <string.h>
using namespace std;
struct node{
    int prn, rollno;
    char name[50];
    struct node *next;
};
class info{
    node *s = NULL, *head1 = NULL, *temp1 = NULL, *head2 = NULL, *temp2 = NULL, *head = NULL, *temp = NULL;
    int b, c, i, j, ct;
    char a[20];

public:
    node *create();
    void insertp();
    void insertm();
    void delm();
    void delp();
    void dels();
    void display();
    void count();
    void reverse();
    void rev(node *p);
    void concat();
};
node *info::create(){
    node *p = new (struct node);
    cout << "enter name of student ";
    cin >> a;
    strcpy(p->name, a);
    cout << "\n enter prn no. of student \n";
    cin >> b;
    p->prn = b;
    cout << "enter student rollno";
    cin >> c;
    p->rollno = c;
    p->next = NULL;
    return p;
}
void info::insertm(){
    node *p = create();
    if (head == NULL){
        head = p;
    }
    else{
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}
void info::insertp(){
    node *p = create();
    if (head == NULL){
        head = p;
    }
    else{
        temp = head;
        head = p;
        head->next = temp->next;
    }
}
void info::display(){
    if (head == NULL){
        cout << "linklist is empty";
    }
    else{
        temp = head;
        cout << " prn rolln0 NAME \n";
        while (temp->next != NULL){
            cout << " \n"
                 << temp->prn << " " << temp->rollno << " " << temp->name;
            temp = temp->next;
        }
        cout << " " << temp->prn << " " << temp->rollno << " " << temp->name;
    }
}

void info::delm()
{
    int m, f = 0;
    cout << "\n enter the prn no. of student whose data you want to delete";
    cin >> m;
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->prn == m)
        {
            s->next = temp->next;
            delete (temp);
            f = 1;
        }
        s = temp;
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "\n sorry memeber not deleted ";
    }
}
void info::delp()
{
    temp = head;
    head = head->next;
    delete (temp);
}
void info::dels()
{
    temp = head;
    while (temp->next != NULL)
    {
        s = temp;
        temp = temp->next;
    }
    s->next = NULL;
    delete (temp);
}

void info::count()
{
    temp = head;
    ct = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        ct++;
    }
    ct++;
    cout << " Count of members is:" << ct;
}
void info::reverse()
{
    rev(head);
}
void info::rev(node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    else
    {
        rev(temp->next);
    }

    cout << " " << temp->prn << " " << temp->rollno << " " << temp->name;
}
void info::concat()
{
    int k, j;
    cout << "enter no. of members in list1";
    cin >> k;
    head = NULL;
    for (i = 0; i < k; i++)
    {
        insertm();
        head1 = head;
    }
    head = NULL;
    cout << "enter no. of members in list2";
    cin >> j;
    for (i = 0; i < j; i++)
    {
        insertm();
        head2 = head;
    }
    head = NULL;
    temp1 = head1;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = head2;
    temp2 = head1;
    cout << " prn rolln0 NAME \n";
    while (temp2->next != NULL)
    {
        cout << "\n " << temp2->prn << " " << temp2->rollno << " " << temp2->name << "\n";
        ;
        temp2 = temp2->next;
        cout << "\n " << temp2->prn << " " << temp2->rollno << " " << temp2->name << "\n";
    }
}
int main()
{
    info s;
    int i;
    char ch;
    do
    {
        cout << "choice the options" << endl;
        cout << "1. To insert president " << endl;
        cout << "2. To insert member " << endl;
        cout << "3. To insert secretary " << endl;
        cout << "4. To delete president " << endl;
        cout << "5. To delete member " << endl;
        cout << "6. To delete secretary " << endl;
        cout << "7. To display data " << endl;
        cout << "8. Count of members" << endl;
        cout << "9. To display reverse of string " << endl;
        cout << "10.To concatenate two strings " << endl;
        cin >> i;
        switch (i)
        {
        case 1:
            s.insertp();
            break;
        case 2:
            s.insertm();
            break;
        case 3:
            s.insertm();
            break;
        case 4:
            s.delp();
            break;
        case 5:
            s.delm();
            break;
        case 6:
            s.dels();
            break;
        case 7:
            s.display();
            break;
        case 8:
            s.count();
            break;
        case 9:
            s.reverse();
            break;
        case 10:
            s.concat();
            break;
        default:
            cout << "\n unknown choice";
        }
        cout << "\n do you want to continue enter y/Y \n";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
