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

// OR
#include <iostream>
// #include <string>

// using namespace std;

// struct Member {
//     string prn;
//     string name;
//     Member* next;
// };

// class PinnacleClub {
// private:
//     Member* head;
//     Member* president;
//     Member* secretary;

// public:
//     PinnacleClub() {
//         head = nullptr;
//         president = new Member{"PRESIDENT_PRN", "President Name", nullptr};
//         secretary = new Member{"SECRETARY_PRN", "Secretary Name", nullptr};
//         head = president; // President is the first member
//         president->next = secretary; // Secretary is the last member
//     }

//     ~PinnacleClub() {
//         clearList();
//         delete president;
//         delete secretary;
//     }

//     void clearList() {
//         Member* current = head;
//         while (current != nullptr) {
//             Member* toDelete = current;
//             current = current->next;
//             delete toDelete;
//         }
//         head = nullptr;
//     }

//     void addMember(const string& prn, const string& name) {
//         Member* newMember = new Member{prn, name, nullptr};
//         // Insert new member before secretary
//         Member* current = head;
//         while (current->next != secretary) {
//             current = current->next;
//         }
//         current->next = newMember;
//         newMember->next = secretary; // New member points to secretary
//     }

//     void deleteMember(const string& prn) {
//         Member* current = head;
//         Member* previous = nullptr;

//         while (current != nullptr && current->prn != prn) {
//             previous = current;
//             current = current->next;
//         }

//         if (current == nullptr) {
//             cout << "Member not found!" << endl;
//             return;
//         }

//         if (previous != nullptr) {
//             previous->next = current->next;
//         } else {
//             // If the member to delete is the president or if the list only has them
//             head = current->next;
//         }
//         delete current;
//         cout << "Member deleted successfully!" << endl;
//     }

//     int totalMembers() {
//         int count = 0;
//         Member* current = head;

//         while (current != nullptr) {
//             count++;
//             current = current->next;
//         }
//         return count - 2; // Exclude president and secretary
//     }

//     void displayMembers() {
//         Member* current = head;
//         cout << "Club Members:" << endl;
//         while (current != nullptr) {
//             cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
//             current = current->next;
//         }
//     }

//     void concatenate(PinnacleClub& other) {
//         Member* current = head;
//         while (current->next != secretary) {
//             current = current->next;
//         }
//         current->next = other.head->next; // Skip president
//         other.head->next = nullptr; // Clear the other list
//     }
// };

// int main() {
//     PinnacleClub divisionA;
    
//     divisionA.addMember("123", "Alice");
//     divisionA.addMember("124", "Bob");

//     divisionA.displayMembers();
//     cout << "Total members: " << divisionA.totalMembers() << endl;

//     divisionA.deleteMember("123");
//     divisionA.displayMembers();
//     cout << "Total members: " << divisionA.totalMembers() << endl;

//     PinnacleClub divisionB;
//     divisionB.addMember("125", "Charlie");
//     divisionB.addMember("126", "David");

//     divisionA.concatenate(divisionB);
//     divisionA.displayMembers();
//     cout << "Total members: " << divisionA.totalMembers() << endl;

//     return 0;
// }

