// Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc) using vector container.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class PersonalRecord
{
	public:
		string name;
		string dob; // Date of Birth
		string phone;

		// Constructor
		PersonalRecord(string name, string dob, string phone)
		{
			this->name = name;
			this->dob = dob;
			this->phone = phone;
		}
		// Display method
		void display() const
		{
			cout<< "Name: "<<name<<", DOB: "<<dob<<", Phone: "<<phone<<endl;
		}
		// Comparison operator for sorting by name
		bool operator < (const PersonalRecord& other) const
		{
			return name < other.name;
		}
};

// Function to search for a record by name
PersonalRecord* searchByName (vector<PersonalRecord> &records, const string& name)
{
	for (auto& record : records)
	{
		if (record.name == name)
			return &record;
	}
	return nullptr;
}

// Function to search for a record by phone number
PersonalRecord* searchByPhone (vector<PersonalRecord> &records, const string& phone)
{
	for (auto& record : records)
	{
		if (record.phone == phone)
			return &record;
	}
	return nullptr;
}

// Function to search for a record by DOB
PersonalRecord* searchByDob (vector<PersonalRecord> &records, const string& dob)
{
	for (auto& record : records)
	{
		if (record.dob == dob)
			return &record;
	}
	return nullptr;
}

int main()
{
	vector <PersonalRecord> records;
	int choice;
	
	do {
		cout<<"\n1. Add Record\n2. Display Records\n3. Search by Name\n4. Search by DOB\n5. Search by Phone\n6. Sort Records\n7. Exit\n";
		cout<<"Enter your Choice: ";
		cin>>choice;
		cin.ignore();
		
		switch(choice)
		{
			case 1:
			{
				string name, dob, phone;
				cout<<"Enter Name: ";
				getline(cin, name);
				cout<<"Enter DOB (YYYYMMDD):";
				cin>>dob;
				cout<<"Enter Phone Number: ";
				cin>>phone;
				records.emplace_back(name, dob, phone);  // Add new record
				break;
			} 
			case 2:
			{
				cout<<"All Records:\n";
				for (const auto& record : records)
				{
					record.display();  // Display each record
				}
				break;
			}
			case 3:
			{
				string name;
				cout<<"Enter name to  search: ";
				//cin.ignore();
				getline(cin, name);
				PersonalRecord* foundRecord = searchByName(records, name);
				if (foundRecord)
				{
					cout<<"Record Found";
					foundRecord->display(); // Display the found record
				}
				else
					cout<<"Record  not found.\n";
				break;
			}
			case 4:
			{
				string dob;
				cout<<"Enter DOB to search (YYYYMMDD): ";
				cin>>dob;
				PersonalRecord* foundRecord = searchByDob(records, dob);
				if (foundRecord)
				{
					cout<<"Record Found";
					foundRecord->display(); // Display the found record
				}
				else
					cout<<"Record  not found.\n";
				break;
			
			}
			case 5:
			{
				string phone;
				cout<<"Enter phone number to  search: ";
				cin>>phone;
				PersonalRecord* foundRecord = searchByPhone(records, phone);
				if (foundRecord)
				{
					cout<<"Record Found";
					foundRecord->display();  // Display the found record
				}
				else
					cout<<"Record  not found.\n";
				break;
			}
			case 6:
			{
				sort(records.begin(), records.end());  // Sort records by name1
				cout<<"Records sorted by name.\n";
				break;
			}
			case 7:
			{
				cout<<"Exiting...\n";
				break;
			}
			default:
				cout<<"Invalid choice. Please try again.\n";
		}
	}
	while(choice != 7);
	
	return 0;
}		

// oR

// Using vector container
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class student
{
public:
    int rollno;
    string name;
    char dob[15];

    bool operator==(const student &student1)
    {
        return (rollno == student1.rollno);
    }
    bool operator<(const student &student1)
    {
        return (rollno < student1.rollno);
    }
    friend ostream &operator<<(ostream &out, const student &);
    friend istream &operator>>(istream &in, student &k);
};
ostream &operator<<(ostream &out, const student &k)
{
    out << "\n\t\t" << k.rollno << "\t\t" << k.name << "\t\t" << k.dob;
    return out;
}
istream &operator>>(istream &in, student &k)
{
    cout << "\nEnter Roll No : ";
    in >> k.rollno;

    cout << "\nEnter Name : ";
    in >> k.name;
    cout << "\nEnter DOB : ";
    in >> k.dob;
    return in;
}
bool myfunc(const student &k, const student &i2)
{
    return (k.rollno < i2.rollno);
}
vector<student> read()
{
    int n;
    student k;
    vector<student> j;
    cout << "\nEnter total no. of students : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        j.push_back(k);
    }
    return j;
}
void printfunction(const student &k)
{
    cout << k;
}
void print(const vector<student> &j)
{
    cout << "\n\t\tROLL NO\t\tNAME\t\tDATE OF BIRTH";
    for_each(j.begin(), j.end(), printfunction);
}

void insert(vector<student> &j)
{
    student k;
    cin >> k;
    j.push_back(k);
}
void delet(vector<student> &j)
{
    student k;
    cout << "\nEnter Student Roll No To Delete : ";
    cin >> k.rollno;
    vector<student>::iterator p;
    p = find(j.begin(), j.end(), k);
    if (p != j.end())
        j.erase(p);
    else
        cout << "\nNot found ";
}
void search(vector<student> &j)
{
    student k;
    cout << "\nEnter Student Roll No To Search : ";
    cin >> k.rollno;
    cout << "\n\n\t\tROLL NO\t\tNAME\t\tDATE OF BIRTH";
    vector<student>::iterator p;
    p = find(j.begin(), j.end(), k);
    if (p != j.end())
        cout << *p;
    else
        cout << "\nNot found ";
}
void sort(vector<student> &j)
{
    sort(j.begin(), j.end(), myfunc);
}

int main()
{
    vector<student> j;
    int op;
    do
    {

        cout << "\n\t\t1.Create ";
        cout << "\n\t\t2.Display ";
        cout << "\n\t\t3.Insert ";
        cout << "\n\t\t4.Delete ";
        cout << "\n\t\t5.Search ";
        cout << "\n\t\t6.Sort";
        cout << "\n\t\t7.Quit";
        cout << "\n\t\t--------------------------";
        cout << "\n\t\tEnter your choice : ";
        cin >> op;
        switch (op)
        {
        case 1:
            j = read();
            break;
        case 2:
            print(j);
            break;
        case 3:
            insert(j);
            break;
        case 4:
            delet(j);
            break;
        case 5:
            search(j);
            break;
        case 6:
            sort(j);
            print(j);
            break;
        }
    } while (op != 7);
}

// OR -------------------------------------------------------------------------------------------------------------------------------------------------------------+
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct PersonalRecord
{
    string name;
    string dob;
    string telno;

    void display()
    {
        cout << "Name: " << name << ", DOB: " << dob << ", Telephone: " << telno << endl;
    }
};

bool compareByName (PersonalRecord a, PersonalRecord B)
{
    return a.name < B.name;
}

void searchByName(vector<PersonalRecord> records, string name)
{
    bool found = false;

    for (int i = 0; i < records.size(); i++)
    {
        if (records[i].name == name)
        {
            cout << "Record found: " << endl;
            records[i].display();
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout << "Records not found." <<endl;
    }
}

int main()
{
    vector <PersonalRecord> records;
    int ch;

    do
    {
        cout << "-----------MENU---------------"<<endl;
        cout << "1. ADD Record. \n2. Display All Records. \n 3. Sort Records by Name. \n4. Search Records by Name. \n5. Exit. "<<endl;
        cout << "ENter your choice: "<<endl;
        cin >> ch;

        switch(ch)
        {
            case 1:
            {
                PersonalRecord record;
                cout << "ENter Name: " << endl;
                cin.get();
                getline(cin, record.name);

                cout << "Enter Date Of Birth (dd/mm/yyyy): " << endl;
                cin.get();
                getline(cin, record.dob);

                cout << "Enter Telephone Number: " <<endl;
                cin.get();
                getline(cin, record.telno);

                records.push_back(record);
                cout << "Record added Successfully." <<endl;
                break; 
            }
            case 2:
            {
                cout << "All Records: " <<endl;
                for (int i = 0; i < records.size(); i++)
                {
                    records[i].display();
                }
                break;
            }
            case 3:
            {
                sort(records.begin(), records.end(), compareByName);
                cout << "Records Sorted by Name." <<endl;

                cout << "Sorted RecordS: " <<endl;
                for (int i = 0; i< records.size(); i++)
                {
                    records[i].display();
                }
                break;
            }
            case 4:
            {
                string search;
                cout << "Enter Name to search: " <<endl;
                cin.get();
                getline(cin, search);

                searchByName(records, search);
                break;
            }
            case 5:
            {
                cout << "Exiting Program..." << endl;
                exit(0);
            }
            default:
            {
                cout <<"Invalid Choice, Please Try again!" << endl;

            }    
        }
    } while (ch != 5);

    return 0;
    
}
