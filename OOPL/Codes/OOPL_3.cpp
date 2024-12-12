// Imagine a publishing company which does marketing for book and audio cassette versions. 
// Create a class publication that stores the title (a string) and price (type float) of publications. 
// From this class derive two classes: book which adds a page count (type int) and tape which adds a playing 
// time in minutes (type float). Write a program that instantiates the book and tape class, allows user to enter 
// and displays the data members. If an exception is caught, replace all the data member values with zero values.

// MARETTING COMPANY
#include <iostream>
using namespace std;
// base class publication
class Publication
{
    private:
        string title;
        float price;
    public:
        Publication()
        {
            title = "";
            price = 0.0;
        }
        void getData()
        {
            cout << "---------Enter Details---------"<<endl;
            cout << "Enter Title: "<<endl;
            cin.ignore(); // clear input buffer
            getline(cin, title);
            cout << "Enter Price: "<<endl;
            cin >>price;
        }
        void putData()
        {
            cout << "_________DISPLAY DATA_________"<<endl;
            cout << "Title is: "<<title<<endl;
            cout << "Price is: "<<price<<endl;
        }
};
class Book : public Publication
{
    private:
        int pageCount;
    public:
        Book()
        {
            pageCount = 0;
        }
        void getData()
        {
            Publication :: getData();
            cout << endl;
            cout << "Enter Page Count: "<<endl;
            cin >> pageCount;
        }
        void putData()
        {
            Publication :: putData();
            try
            {
                if (pageCount < 0)
                    throw pageCount;
            }
            catch (int f)
            {
                cout <<" error: page not vaild :"<< f;
                pageCount = 0;
            }
            cout << "Pages Are: "<<pageCount<<endl;
        }
};
class Tape : public Publication
{
    private: 
        float playtime;
    public:
        Tape()
        {
            playtime = 0.0;
        }
        void getData()
        {
            Publication :: getData();
            cout << "Enter play time of Cassette (in minutes): "<<endl;
            cin >> playtime;
        }
        void putData()
        {
            Publication :: putData();
            try
            {
                if (playtime < 0.0)
                    throw playtime;
            }
            catch (float R)
            {
                cout << "Error: Invalid Playtime: "<<playtime<<endl;
                playtime = 0.0;
            }
            cout << "Playtime is: "<< playtime<<endl;
        }
};
int main()  // main program
{
    Book b[10];  // arrray of objects
    Tape t[10];
    int choice = 0, bookCount = 0, tapeCount = 0;

    while (choice != 5)
    {
        cout << "---------MARKETING MENU---------"<<endl;
        cout << "1. Add Book ."<<endl;
        cout << "2. Add Tape ."<<endl;
        cout << "3. Display Book ."<<endl;
        cout << "4. Display Tape ."<<endl;
        cout << "5. Exit ."<<endl;
        
        cout<<"Enter Choice: "<<endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout<<"------ADDING BOOK DETAILS------"<<endl;
                b[bookCount].getData();
                bookCount++;
                break;
            }
            case 2:
            {
                cout<<"------ADDING TAPE DETAILS------"<<endl;
                t[tapeCount].getData();
                tapeCount++;
                break;
            }
            case 3:
            {
                cout<<"------BOOK DETAILS------"<<endl;
                for (int j = 0; j < bookCount; j++)
                    b[j].putData();
                break;
            }
            case 4:
            {
                cout<<"------TAPE DETAILS------"<<endl;
                for (int j = 0; j < bookCount; j++)
                    t[j].putData();
                break;
            }
            case 5:
            {
                cout<<"*********PROGRAM EXITED SUCCESSFULLY*********"<<endl;
                exit(0);
            }
            default:
            {
                cout<<"Invalid Choice !"<<endl;
            }

        }
    }
    return 0;
}

// OR

// MARETTING COMPANY
#include <iostream>
#include <string>
using namespace std;
// base class publication
class publication
{
private:
    string title;
    float prices;

public:
    publication()
    {
        title = "";
        prices = 0.0;
    }
    void get_data()
    {
        cout << "\n---------Enter Details-------";
        cout << "\nEnter Title :";
        cin.ignore(); // clear input buffer
        getline(cin, title);
        cout << "\nEnter Price : ";
        cin >> prices;
    }
    void put_data()
    {
        cout << "\n ________DSIPLAY DATA_________\n";
        cout << "\n Title is " << title;
        cout << "\n Price is " << prices << "/-";
    }
};
class book : public publication
{

private:
    int pages;

public:
    book()
    {
        pages = 0;
    }
    void get_data()
    {
        publication::get_data();
        cout << endl;
        cout << "Enter Page Count : \n";
        cin >> pages;
    }
    void put_data()
    {
        publication::put_data();
        try
        {
            if (pages < 0)
                throw pages;
        }
        catch (int f)
        {
            cout << "\n error: pages not valid :" << f;
            pages = 0;
        }
        cout << "\n Pages Are :" << pages;
    }
};
class tape : public publication
{
private:
    float playtime;

public:
    tape()
    {
        playtime = 0.0;
    }
    void get_data()
    {
        publication::get_data();
        cout << "Enter Play Time Of Cassette \n";
        cin >> playtime;
    }
    void put_data()
    {

        publication::put_data();
        try
        {
            if (playtime < 0.0)
                throw playtime;
        }
        catch (float r)
        {
            cout << "\n Error: Invalid Playtime : " << playtime;
            playtime = 0.0;
        }
        cout << "\n Playtime is : " << playtime;
    }
};
int main() // main program
{
    book b[10]; // arrray of objects
    tape t[10];
    int choice = 0, bookCount = 0, tapeCount = 0;
    do
    {
        cout << "\n-------------MARKETTING MENU-------------";
        cout << "\n 1. Add book ";
        cout << "\n 2. Add tape: ";
        cout << "\n 3. Display book ";
        cout << "\n 4. Display tape";
        cout << "\n 5. Exit:" << endl;
        cout << "\n Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n------ADDING BOOK DETAILS--------\n";
            b[bookCount].get_data();
            bookCount++;
            break;
        }
        case 2:
        {
            cout << "\n-------ADDING TAPE DETAILS-------\n";
            t[tapeCount].get_data();
            tapeCount++;
            break;
        }
        case 3:
        {
            cout << "\n------BOOK DETAILS------";
            for (int j = 0; j < bookCount; j++)
            {
                b[j].put_data();
            }
            break;
        }
        case 4:
        {
            cout << "\n-------TAPE DETAILS------";
            for (int j = 0; j < tapeCount; j++)
            {
                t[j].put_data();
            }
            break;
        }
        case 5:
        {
            cout << "**********Program Exited Successfully**********" << endl;
            exit(0);
        }
        default:
        {
            cout << "\n Invalid";
        }
        }
    } while (choice != 5);
    return 0;
}
