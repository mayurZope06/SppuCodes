//  Develop a program in C++ to create a database of student’s information system containing the following information: 
//  Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. 
//  and other. Construct the database with suitable member functions. Make use of constructor, default constructor,
//  copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory 
//  allocation operators-new and delete as well as exception handling.

#include <iostream>
#include <string>
using namespace std;
class StudData;
class Student
{
    string name;
    int rollNo;
    string cls;
    char *division;
    string dateOfBirth;
    char *bloodGroup;
    string caddress;
    long int *telno;
    long int *dlno;
    static int count;

    public:
        Student() // Default Constructor
        {
            name ="";
            rollNo = 0;
            cls = "";
            division = new char;
            dateOfBirth = "dd/mm/yy";
            bloodGroup = new char[4];
            caddress = "";
            telno = new long;
            dlno = new long;

        }
        ~Student () // Destructor
        {
            delete division;
            delete[] bloodGroup;
            delete telno;
            delete dlno;
        }
        Student (const Student& ref)
        {
            // Copy Constructor
        }

        static int getCount() //Static Member Function
        {
            return count;
        }
        void getData(StudData *);
        void dispData(StudData *);

        friend class StudData; // Friend Class Declaration
};
class StudData
{
    
    public:
       
        void getStudData(Student &s)
        {
            cout<<"Enter Contact Address: ";
            cin.get();
            getline(cin, s.caddress);
            cout<<"Enter Telephone Number: "<<endl;
            cin>>*(s.telno);
            cout<<"Enter Driving Licence Number: "<<endl;
            cin>>*(s.dlno);
        }
        void dispStudData(Student &s)
        {
            cout<<"Contact Address: "<<s.caddress<<endl;
            cout<<"Telephone Number: "<<*(s.telno)<<endl;
            cout<<"Driving Licence Number: "<<*(s.dlno)<<endl;
        }
};
inline void Student :: getData(StudData *st) // inline code
{
    cout<<"------Enter Details------"<<endl;
    cout<<"Enter Student Name: "<<endl;
    getline(cin, name);
    
    cout<<"Enter Roll Number: "<<endl;
    cin>>rollNo;
    cout<<"Enter Class: "<<endl;
    cin.get();
    getline(cin, cls);
    cout<<"Enter Division: ";
    cin>>division;
    cout<<"Enter Date of Birth: "<<endl;
    cin.get();
    getline(cin, dateOfBirth);
    cout<<"Enter Blood Group: "<<endl;
    cin>>bloodGroup;
    st->getStudData(*this); // this pointer
    count++;
}
inline void Student :: dispData(StudData *st1) // inline code
{
    cout<<"------Display Database Details------"<<endl;
    cout<<"Student Name: "<<name<<endl;
    cout<<"Roll Number: "<<rollNo<<endl;
    cout<<"Class: "<<cls<<endl;
    cout<<"Division: "<<division<<endl;
    cout<<"Date of Birth: "<<dateOfBirth<<endl;
    cout<<"Blood Group: "<<bloodGroup<<endl;
    st1->dispStudData(*this); //this pointer
}
int Student :: count;
int main()
{   
    // Execption Handling
    try
    {
        Student *stud1[100]; // Dynamic Memory Allocation
        StudData *stud2[100]; // Dynamic Memory Allocation

        int n = 0;
        char ch;
        do
        {
            stud1[n] = new Student; // Dynamic Memory Allocation Operator 'new'
            stud2[n] = new StudData; // Dynamic Memory Allocation Operator 'new'
            stud1[n]->getData(stud2[n]);
            
            n++;
            cout<<"Do yo want to add another student (y/n): "<<endl;
            cin>>ch;
            cin.get();
            
        } while (ch == 'y' || ch == 'Y');
            
        for (int i = 0; i < n ; i++)
        {            cout<<"------------------------------------"<<endl;
            stud1[i]->dispData(stud2[i]);
        }
        cout<<"----------------------------------------"<<endl;
        cout<<"Total Students: "<<Student::getCount();
        cout<<endl;
        cout<<"----------------------------------------"<<endl;

        for (int i = 0; i < n; i++)
        {
            delete stud1[i]; // Dynamic Memory Allocation Operator 'delete'
            delete stud2[i]; // Dynamic Memory Allocation Operator 'delete'
        }

    }
    catch(const exception& e)
    {
        cout<<"An error occured: "<<e.what() <<endl;
    }

    return 0;
    
}

// OR

// // Database for Personal Information System
// #include <iostream>
// #include <string.h>
// using namespace std;
// class StudData;
// class Student
// {
//     string name;
//     int roll_no;
//     string cls;
//     char *division;
//     string dob;
//     char *bloodgroup;
//     static int count;

// public:
//     Student() // Default Constructor
//     {
//         name = "";
//         roll_no = 0;
//         cls = "";
//         division = new char;
//         dob = "dd/mm/yyyy";
//         bloodgroup = new char[4];
//     }
//     ~Student()
//     {
//         delete division;
//         delete[] bloodgroup;
//     }

//     static int getCount()
//     {
//         return count;
//     }
//     void getData(StudData *);
//     void dispData(StudData *);
// };
// class StudData
// {
//     string caddress;
//     long int *telno;
//     long int *dlno;
//     friend class Student;

// public:
//     StudData()
//     {
//         caddress = "";
//         telno = new long;
//         dlno = new long;
//     }

//     ~StudData()
//     {
//         delete telno;
//         delete dlno;
//     }
//     void getStudData()
//     {
//         cout << "Enter Contact Address : ";
//         cin.get();
//         getline(cin, caddress);
//         cout << "Enter Telephone Number : ";
//         cin >> *telno;
//         cout << "Enter Driving License Number : ";
//         cin >> *dlno;
//     }
//     void dispStudData()
//     {

//         cout << "Contact Address : " << caddress << endl;
//         cout << "Telephone Number : " << *telno << endl;
//         cout << "Driving License Number : " << *dlno << endl;
//     }
// };
// inline void Student::getData(StudData *st)
// {
//     cout << "--------Enter Details--------";
//     cout << "\nEnter Student Name : ";
//     getline(cin, name);
//     cout << "Enter Roll Number : ";
//     cin >> roll_no;
//     cout << "Enter Class : ";
//     cin.get();
//     getline(cin, cls);
//     cout << "Enter Division : ";
//     cin >> division;
//     cout << "Enter Date of Birth : ";
//     cin.get();
//     getline(cin, dob);
//     cout << "Enter Blood Group : ";
//     cin >> bloodgroup;
//     st->getStudData();
//     count++;
// }
// inline void Student::dispData(StudData *st1)
// {
//     cout << "--------Display Database Details-------";
//     cout << "\nStudent Name : " << name << endl;
//     cout << "Roll Number : " << roll_no << endl;
//     cout << "Class : " << cls << endl;
//     cout << "Division : " << division << endl;
//     cout << "Date of Birth : " << dob << endl;
//     cout << "Blood Group : " << bloodgroup << endl;
//     st1->dispStudData();
// }
// int Student::count;
// int main()
// {
//     Student *stud1[100];

//     StudData *stud2[100];
//     int n = 0;
//     char ch;
//     do
//     {
//         stud1[n] = new Student;
//         stud2[n] = new StudData;
//         stud1[n]->getData(stud2[n]);
//         n++;
//         cout << "Do you want to add another student (y/n) : ";
//         cin >> ch;
//         cin.get();
//     } while (ch == 'y' || ch == 'Y');
//     for (int i = 0; i < n; i++)
//     {
//         cout << "---------------------------------------------------------------" << endl;
//         stud1[i]->dispData(stud2[i]);
//     }
//     cout << "---------------------------------------------------------------" << endl;
//     cout << "Total Students : " << Student::getCount();
//     cout << endl
//          << "---------------------------------------------------------------" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         delete stud1[i];
//         delete stud2[i];
//     }

//     return 0;
// }